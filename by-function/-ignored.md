*** UID:0001Z3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Ignored Function Index Entries

Use this ledger for function-index entries that should not receive durable `by-function` pages.

Ignored entries should usually still be represented elsewhere when they matter:

- third-party, CRT, STL, compiler, or Windows runtime functions belong in the relevant `by-memory` ignored range and dependency documentation;
- free/helper function ownership belongs in `by-global` or `by-file` when source placement is the main issue;
- exact function-body evidence belongs in `by-memory`.

