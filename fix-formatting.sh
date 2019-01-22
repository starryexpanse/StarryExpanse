#!/usr/bin/env bash

set -e

find . -type f -name '*.cpp' -o -name '*.h' -exec clang-format -i {} \;
