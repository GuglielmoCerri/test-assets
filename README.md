# Test Assets for Processing

This repository stores a collection of stable, version-controlled assets used for integration and end-to-end testing of document processing pipelines.

Using these local assets instead of relying on external URLs makes our tests faster, more reliable, and completely independent of third-party services.

## Repository Structure

- `/documents`: Contains document files like `.xlsx`, `.msg`, `.pdf`, etc.
- `/images`: Contains image files like `.jpg`, `.png`, etc.

## How to Use

To use these assets in tests, you can either:

1. Clone this repository and access the files directly via their local path.
2. Use the "raw" URL provided by GitHub to download the files in your test setup.

### Example Raw URLs

- **Excel File**: `https://github.com/GuglielmoCerri/test-assets/blob/main/documents/sample_small.xlsx`
- **MSG File**: `https://github.com/GuglielmoCerri/test-assets/blob/main/documents/sample.msg`
- **PNG File**: `https://github.com/GuglielmoCerri/test-assets/blob/main/images/sample.png`
