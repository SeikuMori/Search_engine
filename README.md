# Search Engine

A simple search engine implementation that performs document indexing and searching using an inverted index data structure.

## Features

- Document indexing using inverted index
- Search functionality with relevance ranking
- Support for multiple search queries
- Top-K results retrieval
- Relevance score normalization

## Build

To build the project:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Testing

Run the tests:

```bash
./build/tests/search_engine_tests
```

## Usage

1. Prepare your configuration in `config.json`
2. Run the search engine:
```bash
./build/src/search_engine
```
3. Results will be saved to `answers.json`
