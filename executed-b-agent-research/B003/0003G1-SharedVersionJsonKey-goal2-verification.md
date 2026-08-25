** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
**FINAL RECOMMENDATION: Keep [UID:0003G1] unchanged as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`.**

This is a pooled literal/source-use case, not a non-emitting orphan. Current IDA evidence shows one physical narrow ASCII `version` key at `0x0060d94c`, three live source-use references from FileDownloader, FittingRoom, and StartupWindow contexts, no interior or alignment-tail references, and a separate successor URL literal at `0x0060d958`. No single source declaration owner is defensible. The correct model is `CANONICAL_OWNER:NONE` plus the three proven output routes.

Recommended metadata remains:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000JE,0000O5
RECONSTRUCTION_CPP: blank
```

No split, merge, reclassification, IDA repair, child page, by-memory edit, or `by-memory/-coverage-report.md` replacement row is recommended.

## Target

- Target: [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Coverage source checked: `auto-generated/-ag-memory-coverage.md`
- Current generated state checked: reconstructable no-owner memory row, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, no C++ code block content.
- Prior report treated as evidence only: `Agent-B003/research/executed/0003G1-SharedVersionJsonKey-live-goal2-no-owner-pass.md`
- This report path: `Agent-B003/research/0003G1-SharedVersionJsonKey-goal2-verification.md`

## Current Documentation Evidence

- The current target page records `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JC,0000JE,0000O5`.
- The page already describes the range as narrow ASCII `version` plus four alignment zeros before the next named wide literal at `0x0060d958`.
- `auto-generated/-ag-memory-coverage.md` lists [UID:0003G1] as no-owner with emitters `0000JC`, `0000JE`, and `0000O5`. The summary links all three emitting file roots.
- The current `by-memory/-coverage-report.md` row already describes this as a reconstructable shared `version` JSON key with live refs from FileDownloader item-shop version parsing, FittingRoomDialogItemState catalog-state parsing, and StartupWindow update metadata parsing. I do not recommend replacing that row.
- The active tracker row for `0003G1` assigns this verification to Agent-B003 and points at the prior executed report only as prior evidence.

## IDA Evidence

Live IDA MCP was checked against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` with imagebase `0x400000`; server health reported ready analysis and Hex-Rays availability.

Byte and name checks:

- `0x0060d94c` is named `aVersion` in `.rdata`.
- Bytes at `0x0060d94c-0x0060d954` decode as `76 65 72 73 69 6f 6e 00`, the narrow ASCII string `version\0`.
- Bytes at `0x0060d954-0x0060d958` are four zero alignment bytes.
- `0x0060d958` is named `aHttpsSecureKru_0` and begins the next UTF-16LE URL literal, not part of this key.

Xrefs to the target:

| Address | Referencing function | Use |
| --- | --- | --- |
| `0x0041ad2e` | `sub_41AA00` | FileDownloader item-shop version parse uses `aVersion`. |
| `0x004227c6` | `sub_422740` | FittingRoomDialogItemState catalog-state parse uses `aVersion`. |
| `0x00580cab` | `sub_580870` | StartupWindow update metadata parse uses `aVersion`. |

Boundary checks:

- `xrefs_to 0x0060d950`: none.
- `xrefs_to 0x0060d954`: none.
- `xrefs_to 0x0060d958`: one reference, `0x0041ae84` in `sub_41AE20`, for the separate item-shop catalog URL.
- A byte search for `version\0` found additional physical byte matches at `0x0060fcd4` and `0x00671b25`, but both had no xrefs. They do not add emitters or challenge this page.

Consumer decompile checks:

- `sub_41AA00` opens the item-shop version URL, parses the response with JsonCpp helpers, and reads the `version` key via the literal at `0x0060d94c`. The function has one caller from `sub_41B110`, the FileDownloader message dispatcher, and current documentation routes [UID:0002TS] through [UID:0000JC] `FileDownloader`.
- `sub_422740` parses an encoded item-shop/catalog state buffer and reads the same `version` key before loading category data. Its callers stay inside fitting-room item-state/catalog handling plus the fitting-room action path, and current documentation routes this work through [UID:0000JE] `FittingRoom`.
- `sub_580870` performs StartupWindow update metadata handling and reads `version` before handling `minimap` metadata. It has one direct caller from `_WinMain@16`, and current documentation routes [UID:0001IO] through [UID:0000O5] `StartupWindow`.
- `sub_41AE20`, the sole successor-literal ref at `0x0060d958`, opens the item-shop catalog URL and does not use this `version` key. It confirms the right boundary instead of adding ownership evidence for [UID:0003G1].

## Owner And Emitter Analysis

### Canonical Owner

`CANONICAL_OWNER:NONE` remains correct.

The IDA evidence proves direct source-use contexts, not a shared source declaration. Each consumer pushes or passes the same physical pooled literal. There is no IDA-visible global object, named project constant, class member, vtable-adjacent declaration, or source-owned string table that can be assigned as the narrow semantic owner.

Rejected canonical owners:

- [UID:0000JC] `FileDownloader`: valid emitter, but not a canonical owner. It accounts for the item-shop version parser reference at `0x0041ad2e` and nearby URL literals, but it does not cover the FittingRoom or StartupWindow use sites without overclaiming.
- [UID:0000JE] `FittingRoom`: valid emitter, but not a canonical owner. It accounts for the catalog-state parser reference at `0x004227c6`, but it does not own the FileDownloader or StartupWindow update parser uses.
- [UID:0000O5] `StartupWindow`: valid emitter, but not a canonical owner. It accounts for the update metadata parser reference at `0x00580cab`, but the same physical literal is also used by cash-shop/fitting-room code.
- [UID:0000KI] `JsonCpp`: rejected. JsonCpp owns parser/value machinery, not product JSON member names supplied by NexusTK call sites.
- [UID:0000I0] `CashShopRequest` and [UID:0000I1] `CashShopVersionRequest`: rejected. Their docs support cash-shop request/payload boundaries, but the literal is consumed outside those request classes and by StartupWindow.
- [UID:0003AL] `CashShopDownloaderLiterals` or another physical `.rdata` container: rejected as canonical owner. The container is a mixed literal pool and records child assignment decisions; it is not an original source declaration owner for this shared key.

Under the current by-structure rules, this is exactly the strange-but-valid split case: no defensible canonical declaration owner, but proven source-use emitters.

### Emitters

The current emitter set remains exact.

| Emitter UID | Route | Evidence | Decision |
| --- | --- | --- | --- |
| `0000JC` | `NexusTK/network/FileDownloader.cpp` | `0x0041ad2e` in `sub_41AA00` reads `version` while downloading/parsing `itemshop.ver`; `sub_41AA00` is dispatched by FileDownloader message handling. | Keep. |
| `0000JE` | `NexusTK/cashshop/FittingRoom.cpp` | `0x004227c6` in `sub_422740` reads `version` while loading fitting-room item-shop catalog state. | Keep. |
| `0000O5` | `NexusTK/app/StartupWindow.cpp` | `0x00580cab` in `sub_580870` reads `version` while parsing startup update metadata. | Keep. |

No additional emitter is justified:

- The successor URL reference at `0x0041ae84` belongs to [UID:0003G2], not this target.
- The other raw `version\0` byte matches have no xrefs.
- JsonCpp helpers are callees that receive product keys; they should not emit this product literal.

The blank `RECONSTRUCTION_CPP` block is also correct. This page represents a literal range, and the final source should spell the literal at the three consuming parse sites unless later source/debug evidence proves a named shared constant. Adding standalone C++ here would either invent a source declaration or duplicate code that belongs in the consuming emitters.

## Split, Merge, And Repair Review

- No split needed: the key is exactly `version\0` followed by unreferenced zero alignment. Splitting the four alignment bytes would create a nonsemantic child page.
- No merge needed: the successor URL at `0x0060d958` has a separate name and separate xref set, and current child [UID:0003G2] already owns that adjacent URL range.
- No reclassification needed: `string-data` / source-declared generated-binary literal data remains accurate.
- No IDA repair needed: current names, xrefs, function starts, and decompilations are coherent with the documentation.
- No by-memory documentation edit needed: the current target page already captures the material owner/emitter decision.
- No `by-memory/-coverage-report.md` change needed: the current row already records the no-owner plus three-emitter rationale with the exact live xref contexts.

## Exact Recommended Changes

No project documentation changes are recommended beyond this report.

If the supervisor chooses to annotate the current coverage row with this verification, that would be a discretionary provenance refresh, not a required semantic repair. I recommend leaving the row unchanged.

## Validation Notes

- Read and followed `Agent-B003/goal.md`, `Supervisor.md`, `by-structure.md`, and the tracker context.
- Rechecked current target page, current generated coverage, current coverage-report row, relevant file-root pages, and nearby mixed literal container documentation.
- Rechecked live IDA MCP bytes, names, xrefs, function identities, decompilations, successor boundary, and alternate physical `version\0` byte matches.
- Used no dry runs.
- Did not edit `by-memory/-coverage-report.md`.
- Did not edit any non-agent-folder `by-*` file, so no lease was required.

## Confidence

Confidence: high, `94/100`.

The canonical owner decision is limited only by the normal absence of original source/debug metadata. Given the current system rules and live IDA evidence, the no-owner plus three-emitter route is the strongest reconstructable output model.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B003/0003G1-SharedVersionJsonKey-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
