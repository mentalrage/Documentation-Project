# 000275 DisplayStartupAndPasswordGuardGlobals Ownership / Split Research

## Final Report

- Assignment: `B001-040`
- Target UID/path: [UID:000275] `by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md`
- Final disposition: executed as a mixed non-emitting split inventory.
- Final aggregate score: `88/93`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID` blank.
- Final children:
  - [UID:00035N] `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md`: `86/90`, reconstructable, direct parent [UID:0000HG] `by-file/Application.md`.
  - [UID:00035L] `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md`: `87/90`, reconstructable, direct parent [UID:0000MG] `by-file/PasswordGuard.md`.
  - [UID:00035O] `by-memory/0x0066d412-0x0066d414.PaddingBeforeBalloonObjectPaneMasks.md`: `85/88`, non-reconstructable padding, parent blank.

## Recommendation

The original [UID:000275] page should not be treated as one source-level object. It spans three different meanings inside a compact writable `.data` island:

| Range | Final handling |
| --- | --- |
| `0x0066d408-0x0066d410` | Application/display startup initialized globals. Keep as the exact reconstructable child [UID:00035N] attached to [UID:0000HG] `Application`. |
| `0x0066d410-0x0066d412` | PasswordGuard initial XOR seed. Keep as the exact reconstructable child [UID:00035L] attached to [UID:0000MG] `PasswordGuard`. |
| `0x0066d412-0x0066d414` | Two zero padding bytes before the BalloonObjectPane mask table. Keep as [UID:00035O], non-reconstructable and parent blank. |

Keep [UID:000275] itself as a parent-blank, non-emitting split inventory. Assigning the aggregate to `Application`, `PasswordGuard`, `SurfacePresentation`, or `BalloonObjectPane` would hide real ownership boundaries. The exact source-bearing children now carry the assignments that clear the strict child/direct-parent `85/85` gate.

## Executed Changes

- Created and validated [UID:00035N] `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md`.
- Created and validated [UID:00035L] `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md`.
- Created and validated [UID:00035O] `by-memory/0x0066d412-0x0066d414.PaddingBeforeBalloonObjectPaneMasks.md`.
- Reclassified [UID:000275] as `RECONSTRUCTABLE:FALSE`, parent blank, and documented its exact children.
- Added the padding rationale for `0x0066d412-0x0066d414` to `by-memory/-ignored.md`.
- Updated `by-memory/-coverage-report.md` so the manual coverage tree mirrors the executed split.
- Removed the stale temporary split filenames `ApplicationDisplayStartupGlobals` and `DisplayPasswordGuardPadding` from the working tree; `validator.py --mode documented --remove-missing --apply` then cleared their stale registry references.

## Evidence Basis

- Prior IDA-backed documentation records the bytes at `0x0066d408-0x0066d414` as `00 04 00 00 01 00 00 00 44 d5 00 00`.
- Prior documented xrefs place `xRight` reads/writes in `Application::Initialize`, including clamped/aligned startup display width handling.
- Prior documented xrefs place `dword_66D40C` in `Application::Initialize` startup validation and `SurfacePresentation` blit/presentation-mode consumption. The consumer read does not make `SurfacePresentation` the source declaration owner.
- Prior documented xrefs place `word_66D410` in `SetProtectedPasswordToken` and `ValidateChatInputOrThrowPasswordError`, where the value acts as the initial incrementing XOR seed for protected-token encode/decode.
- Prior documented successor evidence places the next xrefed item at `0x0066d414`, the BalloonObjectPane static mask table, so `0x0066d412-0x0066d414` is padding rather than a standalone declaration.
- Current-session IDA MCP was available at the tool-list level, but IDB-backed calls timed out. This report does not claim new live IDA facts from the 2026-06-10 session.

## Parent Analysis

### Application child, [UID:00035N]

[UID:0000HG] `Application` is the best direct parent because the documented writer/validator is `Application::Initialize`, and the values are startup display policy rather than surface-object state. `SurfacePresentation` reads the presentation mode later, but it is a consumer and remains a mixed aggregate below the direct parent gate. `PasswordGuard` and `BalloonObjectPane` only own neighboring bytes.

### PasswordGuard child, [UID:00035L]

[UID:0000MG] `PasswordGuard` is the best direct parent because the documented uses are the token setter and validator paths. The seed is paired with PasswordGuard's protected-token buffer and encode/decode logic. Treating the value as an Application display global, Unicode character, or BalloonObjectPane neighbor would be adjacency-based rather than behavior-based.

### Padding child, [UID:00035O]

The `0x0066d412-0x0066d414` child has no source owner. It exists to preserve exact coverage and to keep the aggregate split honest. Rebuilt source should regenerate equivalent bytes through adjacent declarations and linker alignment.

## Quality Gate Review

The source-bearing children and their direct parents clear the required `85/85` gate:

| Child | Child score | Direct parent | Parent score | Gate |
| --- | --- | --- | --- | --- |
| [UID:00035N] DisplayStartupPresentationGlobals | `86/90` | [UID:0000HG] Application | `86/90` | pass |
| [UID:00035L] PasswordGuardXorSeed | `87/90` | [UID:0000MG] PasswordGuard | `86/90` | pass |
| [UID:00035O] PaddingBeforeBalloonObjectPaneMasks | `85/88` | none, non-source padding | n/a | source-parent gate not applicable |

The aggregate [UID:000275] also clears documentation quality at `88/93`, but remains unassigned because it is a mixed binary coverage container, not a source-level declaration.

## Remaining Caveats

- Final emitted C++ remains intentionally blank for both source-bearing children until final source spelling/linkage is audited.
- `dword_66D40C` still needs a final source-level name, but its parent placement is strong enough for the current split.
- Stale validator records for deleted temporary UIDs were removed by `validator.py --mode documented --remove-missing --apply`.

## Research Log

### Active Checkpoint - 2026-06-10 20:08:13 -04:00

- Assignment: `B001-040`, UID `000275`, target `by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md`.
- Scope: audit the compact initialized `.data` range for exact boundaries, mixed Application/display startup and PasswordGuard ownership, required split children, strict child/direct-parent `85/85` gates, and coverage consistency.
- Lease state at start: `Agent-B001/current_leases.md` read; no active leases.
- Files read at start: current lease report, target page, generated memory coverage rows, manual memory coverage row. The target was `82/92`, `RECONSTRUCTABLE:TRUE`, parent blank, and documented `xRight`, `dword_66D40C`, `word_66D410`, and padding.
- Initial hypothesis: the existing aggregate is mixed and should remain parent blank/non-emitting after exact split children are created or repaired. Likely split candidates are `0x0066d408-0x0066d410` for Application/display startup state, `0x0066d410-0x0066d412` for PasswordGuard seed, and `0x0066d412-0x0066d414` padding/ignored alignment.

### Progress Update - 2026-06-10 20:38 -04:00

- By-structure and `by-memory/-guidance.md` require mixed-source memory aggregates to keep real source ownership on exact children and keep the mixed aggregate blank/non-emitting when it is not itself a source-level object.
- Gate recheck from current docs: [UID:0000HG] `Application` is `86/90`, [UID:0000MG] `PasswordGuard` is `86/90`, and [UID:0001G6] `SurfacePresentation` remains below child completion gate at `82/88` and is a consumer/aggregate rather than the declaration owner.
- Current best split decision: exact children are required before the aggregate can be raised/reclassified. The source-bearing children should be an Application/display startup initialized-global child at `0x0066d408-0x0066d410` and a PasswordGuard seed child at `0x0066d410-0x0066d412`; the remaining `0x0066d412-0x0066d414` bytes should be documented as non-source padding.

### MCP Checkpoint - 2026-06-10 20:12

- `tools/list` returned quickly with 71 tools.
- Tiny IDB-backed calls failed: `get_bytes 0x0066d408 size 12` timed out after 10s; `get_bytes 0x0066d408 size 4` timed out after 15s; `xrefs_to 0x0066d410` timed out after 15s; `lookup_funcs 0x004639d0` timed out after 15s.
- Current pass did not claim new live IDA facts. Evidence is labeled as prior documented IDA facts from the target/parent/neighbor pages, existing validator/autogen state, and B001 reasoning from those sources.
