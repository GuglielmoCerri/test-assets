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

- `/documents`: Contains document files like `.xlsx`, `.msg`, `.pdf`, etc.
- `/images`: Contains image files like `.jpg`, `.png`, etc.

## How to Use

To use these assets in tests, you can either:

- Clone this repository and access the files directly via their local path.
- Use the "raw" URL provided by GitHub to download the files in your test setup.

### Example Raw URLs

- **Excel File**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/documents/sample_small.xlsx`
- **MSG File**: `"https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/documents/sample.msg"`
- **PNG File**: `https://raw.githubusercontent.com/GuglielmoCerri/test-assets/main/images/sample.png`

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
- **Place Files in the Correct Directory:** Add new files to the appropriate subdirectory (`/documents`, `/images`, etc.).

Thank you for your interest in contributing to this project.
