*** UID:0001ZP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Meta Guidance

Use `by-meta` for broad project research and cross-cutting client behavior that supports reconstruction but is not itself a direct binary entity.

Examples include subsystem summaries, DAT format research, networking notes, third-party library tracking, rendering/audio overviews, and other topic-level pages that collect evidence from many files or memory ranges.

Because these pages are supporting research rather than direct binary reconstruction units, they should normally be scored `COMPLETION:-1` and `CONFIDENCE:-1`.

## Examples

```text
client_dat_specifications.md
client_network.md
client_anticheat.md
client_libraries.md
client_new_rendering_mode.md
client_old_rendering_mode.md
```

## Page Contents

Each meta page should include:

- topic scope and confidence;
- concise format/protocol/behavior specifications backed by source evidence;
- involved classes, files, globals, resources, strings, and memory ranges;
- open questions and exact next research targets;
- cross-references to `../by-file`, `../by-class`, `../by-item`, and `../by-memory`.

Keep broad observations here, but put original-source ownership decisions in `../by-file` and exact address evidence in `../by-memory`. When a new uncovered client-level topic appears, update the nearest existing `by-meta` page or create a new `by-meta` document so cross-cutting behavior, formats, and subsystem findings do not remain buried in isolated class/file/memory notes.

## Coverage Report Rows

Meta pages are supporting research rather than direct binary reconstruction units, so rows should normally be scored `-1`. Use topic names as row keys in `-coverage-report.md` and keep uncovered rows for broad client-level subjects that need a meta page because the evidence spans multiple classes, files, globals, resources, or memory ranges.
