*** UID:0001ZO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Item Guidance

Use `by-item` for small focused entities that are not worth a full class, file, type, global, resource, or memory-range page.

Good candidates include narrow helper concepts, local algorithms, small reconstruction decisions, high-value constants before they become enums/macros, or temporary notes that need UID references while a larger owner is still uncertain.

Temporary `by-item` notes may cover function/method questions, vtable ownership questions, global-symbol questions, packet behavior, resource ownership, field-layout questions, or naming/layout decisions while the stronger canonical home is still unknown.

Promote an item into the more specific `by-*` folder once ownership is clear. When promoting or renaming, run the validator file scan so UID references remain stable.

Prefer `../by-global`, `../by-type`, or `../by-resource` when the item fits one of those categories and needs a durable page. Keep `by-item` for one-off questions, narrow behavior notes, packets, temporary triage, or small unresolved findings that do not yet justify a stronger category.

## Page Contents

Each item page should include:

- exact current entity id, address, or symbol;
- owner class/file hypothesis;
- concise behavior summary;
- evidence and unresolved questions;
- links back to `../by-class`, `../by-file`, and `../by-memory`.

## Scoring Discipline

Do not rate an item page at `95+` completion or confidence lightly. Those values mean the item has already been audited as a near-final documented fact: its exact identity, owner, behavior, boundaries, dependencies, generated-name replacements, related memory evidence, and promotion decision have been verified and recorded in the page. If the item is still temporary, owner-uncertain, dependent on generated Wave3/Wave2/simroot evidence, or waiting to be promoted into a stronger canonical folder, keep the score below `95`.

## Coverage Report Rows

Use the current item name as the row key in `-coverage-report.md`, sorted alphabetically. Keep uncovered rows limited to focused questions that still need a temporary item page. Once an item's owner is clear, promote it into the more specific folder and update or remove the `by-item` coverage row instead of leaving duplicate tracking.

## Reconstruction Autogen

Singular item pages are eligible for validator autogen metadata, but use this sparingly. Prefer moving stable code/declaration reconstruction into `by-memory`, `by-class`, `by-function`, `by-global`, or `by-type` once the owner is known. If an item page remains the best temporary owner for C++ code, use `CANONICAL_OWNER` for the nearest real semantic owner and `EMITTER_UIDS` for the generated-output route. Do not use emitter routing as a shortcut for unresolved ownership. Add emitted C++ only when the active `90/90+` reconstruction-code gate in `../by-structure.md` is satisfied; `95+` remains a rare final-audit score and is not required merely to begin final-quality code entry.
