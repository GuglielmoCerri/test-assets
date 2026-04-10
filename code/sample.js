/**
 * sample.js — Synthetic JavaScript module for parser testing.
 * Contains common patterns: classes, async/await, error handling, exports.
 */

"use strict";

// ── Constants ────────────────────────────────────────────────────────────────

const DEFAULT_TIMEOUT_MS = 5000;
const MAX_RETRIES = 3;

// ── Utility functions ─────────────────────────────────────────────────────────

/**
 * Pauses execution for the given number of milliseconds.
 * @param {number} ms
 * @returns {Promise<void>}
 */
const sleep = (ms) => new Promise((resolve) => setTimeout(resolve, ms));

/**
 * Formats a date as an ISO 8601 string (date part only).
 * @param {Date} date
 * @returns {string}
 */
function formatDate(date) {
  return date.toISOString().split("T")[0];
}

// ── ApiClient class ───────────────────────────────────────────────────────────

class ApiClient {
  /**
   * @param {string} baseUrl
   * @param {object} [options]
   * @param {number} [options.timeout]
   * @param {number} [options.retries]
   */
  constructor(baseUrl, options = {}) {
    this.baseUrl = baseUrl.replace(/\/$/, "");
    this.timeout = options.timeout ?? DEFAULT_TIMEOUT_MS;
    this.retries = options.retries ?? MAX_RETRIES;
  }

  /**
   * Performs a GET request with automatic retries.
   * @param {string} path
   * @returns {Promise<object>}
   */
  async get(path) {
    const url = `${this.baseUrl}${path}`;
    let lastError;

    for (let attempt = 1; attempt <= this.retries; attempt++) {
      try {
        const controller = new AbortController();
        const timer = setTimeout(() => controller.abort(), this.timeout);

        const response = await fetch(url, { signal: controller.signal });
        clearTimeout(timer);

        if (!response.ok) {
          throw new Error(`HTTP ${response.status}: ${response.statusText}`);
        }

        return await response.json();
      } catch (err) {
        lastError = err;
        if (attempt < this.retries) {
          await sleep(200 * attempt);
        }
      }
    }

    throw new Error(`GET ${url} failed after ${this.retries} retries: ${lastError.message}`);
  }
}

// ── Data helpers ──────────────────────────────────────────────────────────────

/**
 * Groups an array of objects by a given key.
 * @template T
 * @param {T[]} items
 * @param {keyof T} key
 * @returns {Record<string, T[]>}
 */
function groupBy(items, key) {
  return items.reduce((acc, item) => {
    const group = String(item[key]);
    acc[group] = acc[group] ?? [];
    acc[group].push(item);
    return acc;
  }, {});
}

// ── Exports ───────────────────────────────────────────────────────────────────

module.exports = { ApiClient, groupBy, formatDate, sleep };
