# Test Assets for Processing

<!-- BADGES -->
<p align="center">
  <!-- License -->
  <a href="https://github.com/GuglielmoCerri/test-assets/blob/main/LICENSE">
    <img src="https://img.shields.io/badge/License-MIT-yellow.svg" alt="License: MIT">
  </a>
  <!-- Repo Status -->
  <a href="#">
    <img src="https://img.shields.io/badge/Status-Active-brightgreen" alt="Repo Status: Active">
  </a>
  <!-- Repo Size -->
  <a href="#">
    <img src="https://img.shields.io/github/repo-size/GuglielmoCerri/test-assets" alt="Repo Size">
  </a>
</p>

This repository stores a collection of stable, version-controlled assets used for integration and end-to-end testing of document processing pipelines.

Using these local assets instead of relying on external URLs makes our tests faster, more reliable, and completely independent of third-party services.

## Repository Structure

| Folder | File types |
|---|---|
| `/archives` | `.zip` |
| `/code` | `.bat`, `.c`, `.cpp`, `.css`, `.java`, `.js`, `.py`, `.sh` |
| `/config` | `.cfg`, `.conf`, `.ini` |
| `/data` | `.csv`, `.json`, `.parquet`, `.xml`, `.yaml`, `.yml` |
| `/documents` | `.doc`, `.docx`, `.eml`, `.htm`, `.html`, `.md`, `.msg`, `.pdf`, `.txt` |
| `/images` | `.gif`, `.jpg`, `.png`, `.svg`, `.tiff`, `.webp` |
| `/logs` | `.log` |
| `/presentations` | `.ppt`, `.pptx` |
| `/spreadsheets` | `.xls`, `.xlsx` |

## How to Use

To use these assets in tests, you can either:

- Clone this repository and access the files directly via their local path.
- Use the "raw" URL provided by GitHub to download the files in your test setup.

### Example Raw URLs

- **ZIP**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/archives/sample.zip`
- **Batch**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.bat`
- **C**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.c`
- **C++**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.cpp`
- **CSS**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.css`
- **Java**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.java`
- **JavaScript**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.js`
- **Python**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.py`
- **Shell**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/code/sample.sh`
- **CFG**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/config/sample.cfg`
- **CONF**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/config/sample.conf`
- **INI**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/config/sample.ini`
- **CSV**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/data/sample.csv`
- **JSON**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/data/sample.json`
- **Parquet**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/data/sample.parquet`
- **XML**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/data/sample.xml`
- **YAML**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/data/sample.yaml`
- **YML**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/data/sample.yml`
- **DOCX**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/documents/sample.docx`
- **HTM**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/documents/sample.htm`
- **HTML**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/documents/sample.html`
- **MSG**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/documents/sample.msg`
- **PDF**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/documents/sample_3_pages.pdf`
- **GIF**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/images/sample.gif`
- **JPG**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/images/sample.jpg`
- **PNG**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/images/sample.png`
- **SVG**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/images/sample.svg`
- **TIFF**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/images/sample.tiff`
- **WEBP**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/images/sample.webp`
- **LOG**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/logs/sample.log`
- **PPTX**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/presentations/sample.pptx`
- **XLSX**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/spreadsheets/sample_small.xlsx`

## Contributing

Contributions are welcome and essential for keeping this collection of assets useful and up-to-date. If you wish to add a new test file or suggest an improvement, please follow the guidelines below.

### Contribution Process

1. **Open an Issue First:** Before submitting a pull request, please open a GitHub issue to discuss the proposed change. This allows us to align on the new asset's purpose and prevent duplicate work.
    - For new files, describe the asset and its use case (e.g., "Add a multi-page TIFF to test asynchronous processing").
    - For problems with existing files, describe the issue in detail.

2. **Fork and Create a Branch:** Fork the repository and create a new branch for your contribution. Name the branch descriptively.

    ```bash
    git checkout -b feature/add-protected-pdf-sample
    ```

3. **Submit a Pull Request:** Once your changes are ready, open a pull request against the `main` branch. Provide a clear title and description, and link to the issue you opened in step one.

### Asset Guidelines

To ensure the quality and integrity of the repository, all contributed assets must adhere to the following rules:

- **No Sensitive Data:** Files must not contain any personally identifiable information (PII), confidential data, or copyrighted material. All content should be synthetic or properly anonymized.
- **Keep File Sizes Small:** Assets should be as small as possible to keep the repository lightweight. The goal is to test structure and parsing, not to handle large volumes.
- **Use Descriptive Filenames:** Name files clearly and descriptively (e.g., `invoice_with_tables.xlsx` is preferred over `test1.xlsx`).
- **Place Files in the Correct Directory:** Add new files to the appropriate subdirectory (`/archives`, `/code`, `/config`, `/data`, `/documents`, `/images`, `/logs`, `/presentations`, `/spreadsheets`).

Thank you for your interest in contributing to this project.
