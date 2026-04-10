#!/usr/bin/env bash
# sample.sh — Synthetic Bash script for parser and syntax testing.
# Demonstrates: variables, functions, loops, conditionals, error handling.

set -euo pipefail

# ── Configuration ─────────────────────────────────────────────────────────────

readonly APP_NAME="sample-service"
readonly LOG_DIR="/var/log/${APP_NAME}"
readonly DATA_DIR="/var/data/${APP_NAME}"
readonly ARCHIVE_DAYS=30

# ── Helpers ───────────────────────────────────────────────────────────────────

log() {
    local level="$1"; shift
    echo "$(date '+%Y-%m-%d %H:%M:%S') [${level}] $*"
}

info()  { log "INFO " "$@"; }
warn()  { log "WARN " "$@" >&2; }
error() { log "ERROR" "$@" >&2; }

require_command() {
    if ! command -v "$1" &>/dev/null; then
        error "Required command not found: $1"
        exit 1
    fi
}

# ── Functions ─────────────────────────────────────────────────────────────────

check_dependencies() {
    info "Checking dependencies..."
    for cmd in curl jq gzip; do
        require_command "$cmd"
    done
    info "All dependencies satisfied."
}

ensure_directories() {
    for dir in "$LOG_DIR" "$DATA_DIR"; do
        if [[ ! -d "$dir" ]]; then
            mkdir -p "$dir"
            info "Created directory: $dir"
        fi
    done
}

archive_old_logs() {
    info "Archiving log files older than ${ARCHIVE_DAYS} days..."
    local count=0
    while IFS= read -r -d '' file; do
        gzip "$file"
        (( count++ )) || true
    done < <(find "$LOG_DIR" -name "*.log" -mtime "+${ARCHIVE_DAYS}" -print0)
    info "Archived ${count} file(s)."
}

fetch_status() {
    local endpoint="${1:-http://localhost:8080/health}"
    info "Fetching status from ${endpoint}..."
    local response
    response=$(curl --silent --fail --max-time 5 "$endpoint") || {
        error "Failed to reach ${endpoint}"
        return 1
    }
    echo "$response" | jq '.'
}

# ── Main ──────────────────────────────────────────────────────────────────────

main() {
    info "Starting ${APP_NAME} maintenance script"
    check_dependencies
    ensure_directories
    archive_old_logs
    fetch_status
    info "Done."
}

main "$@"
