*** UID:0000SU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short g_screenWidth = 1024;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_APP_APPLICATION_H
#define NEXUSTK_APP_APPLICATION_H

extern short g_screenWidth;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_screenWidth

## 2026-08-14 B003 Signed Declaration Closure

- Final source definition/declaration are `short g_screenWidth = 1024;` and `extern short g_screenWidth;`. Target center arithmetic at `0x004fe0c0` uses `movsx`, and the Application constructor at `0x004633b7` sign-extends this global; those uses and the literal existing definition support signed `short`.
- A separate zero-extending consumer is use-site behavior, not a definition-type override. The dated IDA `unsigned __int16` display remains documentary; UID0000SU/UID0000HG stay `90/93`.
- Emitter position `0` and the opening guard lines make this independent payload the first half of the exact generated `Application.h`; UID0000ST closes the guard after the height declaration.

## Status

- Symbol kind: process-wide display-width global.
- IDA address: `0x0066da94` (`word_66DA94`).
- Storage range: [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md).
- Proposed type: `std::uint16_t` or signed `short` promoted at use sites.
- Initial value in IDA data: `0x0400` / `1024`.
- Confidence: strong for storage and display-width role; strong for `Application.cpp` as the best source-owner inference; medium for final source-level variable name and signedness.
- Rebuild handling: source-declared global data. The rebuilt source should declare the display-width word or compatible typed global; exact address placement is linker output.
- Autogen status: reconstructable and attached upward to [UID:0000HG][Application](by-file/Application.md) as a file-level default display-dimension global; first-draft C++ now emits signed `short g_screenWidth = 1024` based on current bytes and signed `movsx` use.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 90 | The page records exact storage, initial value, role, paired height global, neighboring byte/word boundaries, fresh live xref count/function spread, representative use families, adjacent-global identities, exact memory child evidence, source-declared rebuild handling, corrected coverage-error behavior, the Application source-owner decision, and first-draft signed-short declaration. It is not higher because exact original source-facing name remains inferred. |
| Confidence | 93 | Current IDA evidence strongly supports the address, size, initial value, paired-display-width interpretation, strict byte boundaries, exact memory-child ownership, no-write compile-time initializer behavior, and usage categories across application startup, config defaults, event/dialog layout, logo/media sizing, render packing, and screenshot paths. Confidence stays below final-audit level because IDA still labels the storage `word_66DA94` and the original declaration spelling is not recovered. |
| Reconstructable | TRUE | This is source-declared rebuild data, parallel to [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md), and now emits first-draft C++ through Application. |

## Role

`g_screenWidth` is the global screen/display width used by startup, pane positioning, and render-surface sizing paths. It is paired with [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) at `0x0066da98`.

The current documentation name is a source-level role label derived from the paired 1024x768 display-size use pattern. IDA still names the storage `word_66DA94`.

## Evidence

- `Application` startup and window creation paths read `word_66DA94` together with `word_66DA98`.
- Dialog and pane layout paths clamp right edges against `word_66DA94`.
- [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md) reads `word_66DA94` during its DirectDraw surface-packing decision.
- Live IDA MCP recheck on 2026-06-03 found IDB `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, storage name `word_66DA94`, initial word `0x0400` / `1024`, and 98 xrefs to `0x0066da94`.
- Representative live xrefs include `Application__Constructor` at `0x004633be`, application initialization at `0x00464421`, `RegistryConfig::InitializeDefaults` at `0x0048efae`, `LogoPane` construction at `0x004f4ca8`, event/dialog root rectangle setup at `0x004a8ba9`, screenshot capture at `0x00557bf7`, and alert-pane centering at `0x004a0458`.
- The adjacent bytes remain distinct globals: [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) / `byte_66DA96` starts at `0x0066da96`, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` starts at `0x0066da97`, and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) begins at `0x0066da98`.
- 2026-06-07 A004 IDA MCP `py_eval` reconfirmed bytes `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00` at `0x0066da90-0x0066daa8`, `word_66DA94` item size `2`, value `0x0400`, `98` xrefs across `48` functions, `byte_66DA96` and `byte_66DA97` as separate one-byte successors, and `word_66DA98 == 0x0300` as the paired height global.
- The exact storage child [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md) uses this page as its direct by-global parent after both child and parent reached the corrected `85/85` gate and this by-global page was rooted upward to [UID:0000HG][Application](by-file/Application.md).
- 2026-06-07 A002 Batch 069 revalidated this parent and the exact storage child after generated memory coverage reported `0001OG -> 0000SU` as `autogen_parent_unknown`. IDA MCP reconfirmed the same two-byte value, neighborhood boundaries, and xref spread. Because a full autogen pass still rejected the by-global parent, the memory child kept this page as evidence-only at that time; B001-007 later assigned this by-global page upward to [UID:0000HG][Application](by-file/Application.md), and A005 Batch230 later restored the memory-child route after the rooted by-global path cleared.
- 2026-06-08 A009 Batch 136 IDA MCP recheck reconfirmed the paired display words in place: `word_66DA94 = 1024` has 98 xrefs across 48 functions, `word_66DA98 = 768` has 96 xrefs across 47 functions, and local bytes at `0x0066da94` are `00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00 a6 02 00 00`. The first width consumers remain `Application__Constructor` at `0x004633be`, application initialization at `0x00464421`/`0x004645dd`, coordinate mapping helpers at `0x0046569d`/`0x0046573b`, layout helpers at `0x00465d7d`/`0x00465de4`, `GrafPort` render sizing at `0x004b92a2`, screenshot paths at `0x00557bf7`/`0x00557c44`, and late UI/weather consumers around `0x005c2b89`/`0x005c2bc5`. This strengthens the width/height interpretation but still proves consumers, not a declaration owner.
- 2026-06-10 B001-007 IDA MCP owner audit found `word_66DA94` is a `.data` two-byte item with value `1024`, `98` xrefs across `48` functions, and no write xrefs; the paired [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) has value `768`, `96` xrefs across `47` functions, and no write xrefs. `Application::Application` at `0x004633b7`/`0x004633be` reads height/width and stores them into Application fields `+0x0a60/+0x0a64`; `Application::Initialize` at `0x0046440a`/`0x00464421` uses the globals for fallback window creation and at `0x004645d6`/`0x004645dd` passes height/width into `ScreenPane::ScreenPane`. The same pass rejects `ScreenPane` as the declaration owner because its constructor receives the dimensions as parameters and stores instance fields, while `RegistryConfig::InitializeDefaults` uses the pair only to derive centered default rectangles.

## Neighboring Globals

The bytes between the width and height words are separate globals, not padding or high bytes of the display dimension pair:

- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) / `byte_66DA96` starts at `0x0066da96` and is used by movement-vector and timer-delay scaling.
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` starts at `0x0066da97` and selects the EPF/current-layout asset path.
- [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) starts at `0x0066da98` as the paired display-height word.

This page should remain the canonical display-width page only for `0x0066da94-0x0066da96`. Do not fold the adjacent movement or layout-mode bytes into the width declaration.

## Source Placement

Keep this global paired with [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) during reconstruction. B001-007 assigns both display-dimension globals upward to [UID:0000HG][Application](by-file/Application.md) as file-level default/base display-dimension declarations.

The inference is source-owner evidence, not recovered source spelling: `Application::Application` copies the initialized pair into its base-dimension fields, `Application::Initialize` uses the pair for fallback main-window creation and ScreenPane construction, and the Application coordinate helpers use the same pair as the base logical display size. `ScreenPane`, `RegistryConfig`, render setup, screenshot, and UI layout paths are important consumers, but IDA shows no write or declaration-side evidence making those files better owners.

First-draft C++ now emits as signed `short` in or near `Application.cpp` because the bytes and signed `movsx` consumers support that declaration. Exact original source spelling remains below the final-code gate.

## Assignment Gate

This page is the direct by-global parent for the exact storage child [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md), because it owns the source-level display-width global and is scored above `85/85`. Batch230 routes the memory child here after this page was rooted upward to [UID:0000HG][Application](by-file/Application.md), preserving the narrow semantic parent instead of assigning the storage directly to the broad file owner.

B001-007 assignment decision: attach this by-global page upward to [UID:0000HG][Application](by-file/Application.md). The child/global side is `88/91`, the file parent is `86/90`, and the IDA evidence supports `Application.cpp` as the narrowest existing source-owner reconstruction for the paired default display-size declarations.

## Alias/Operand Note

Some generated docs may expose a synthetic `g_maxSurfacePitch` reference around `GrafPort::UpdateRenderRegion`. IDA disassembly shows that operand is actually `word_66DA94`, this screen-width global, not a separate surface-pitch cap. Do not migrate `g_maxSurfacePitch` as a real source symbol without new live evidence.

## Cross-References

- [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md)
- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## 2026-06-29 B013 Application Empty-Emitter Implementation

- Formal C++ now emits FD-0000SU from the accepted B013 report.
- Current MCP bytes at `0x0066da94` begin `00 04`, and coordinate/window code uses sign-extending reads, supporting a signed `short` declaration rather than a 32-bit `int`.
- UID0001OG remains the exact by-memory storage child and should not duplicate this definition.
- Score becomes `90/93`; confidence remains below 95 only for exact original global spelling/linkage.

Implementation validator: run `python .\tools\validator.py --mode file --file by-global/g_screenWidth.md --apply --queue-timeout 240` from `source-3/project-documentation`.

## Changes

- 2026-06-11 A005 Batch230 memory-child routing refresh:
  - Kept score `88/91` and parent [UID:0000HG][Application](by-file/Application.md).
  - Updated the exact storage-child wording because [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md) now routes to this by-global page after the rooted parent path cleared.
- 2026-06-08 A009 Batch 136 source-owner audit:
  - Changed score from `86/90` to `87/90`.
  - Added current IDA MCP paired-width/height bytes and xref counts, representative width consumers, and documented the direct-owner check against [UID:0000HG][Application](by-file/Application.md) and [UID:0000NB][ScreenPane](by-file/ScreenPane.md).
  - Assignment remained blank at that time with status `reviewed-85-but-ownership-unknown` because the candidate source pages proved consumer/instance-dimension roles, not direct declaration ownership for the global. B001-007 supersedes this with an Application owner inference.
- 2026-06-10 B001-007 ownership inference:
  - Changed score from `87/90` to `88/91` and set `AUTOGEN_PARENT_UID:0000HG`.
  - Evidence: fresh IDA MCP confirmed `.data` item size/value, `98` xrefs across `48` functions, no write xrefs, constructor copies to Application fields `+0x0a60/+0x0a64`, initialization uses the pair for fallback window creation and `ScreenPane::ScreenPane`, and Application coordinate helpers treat the pair as the base logical display size.
  - Rejected alternatives: `ScreenPane` receives the dimensions as constructor parameters and owns instance fields only; `RegistryConfig` uses the pair to center default rectangles; render/screenshot/UI paths are consumers; a new `DisplayGlobals` file would contain only this pair with no stronger IDA-backed source boundary than the existing Application owner.
- 2026-06-07 A002 Batch 069:
  - What existed before: the source docs already showed `0001OG` as the exact memory child of this `86/90` by-global parent, but generated memory coverage reported `autogen_parent_unknown` for `0000SU`.
  - Changed to: kept scores unchanged and made this page an evidence anchor rather than an autogen parent for the memory child.
  - Summary/evidence: IDA MCP reconfirmed `word_66DA94` as two-byte `0x0400` storage with separate successor globals and 98 xrefs across 48 functions. Validator file mode reported `autogen_error_clear` for `0001OG`, but full autogen still rejected `0000SU` as a generated memory parent, so [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md) left `AUTOGEN_PARENT_UID` blank at that time.
- What existed before: completion/confidence were `0/0` and reconstructable state was blank.
- What it was changed to: completion `70`, confidence `84`, and `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remained blank at that time.
- Summary/evidence: the 2026-05-31 IDA MCP recheck reconfirmed the exact storage, initial value, and broad screen-width xref set. The global is source-declared rebuild data; B001-007 later assigned the by-global page upward to Application, while final source-level type/name and C++ emission remain open.
- 2026-06-03: Raised metadata from `70/84` to `78/88`.
  - Reason: live IDA MCP reconfirmed the exact `0x0066da94` two-byte storage, initial value `1024`, 98-xref count, neighboring byte/word boundaries, and representative use families across application startup, initialization, registry defaults, event/dialog layout, logo sizing, alert centering, and screenshot capture.
  - Boundary at that time: `AUTOGEN_PARENT_UID` and C++ remained blank because final owner file, original declaration spelling, and exact signedness/linkage were still below the `95/95` reconstruction threshold.
- 2026-06-06: Raised completion from `78` to `80`.
  - Reason: added the missing neighboring-global section to match the paired height page and explicitly linked [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) / `byte_66DA96` and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97`.
  - Boundary: confidence stays `88`; the storage/boundary evidence is strong, but final owner file, source spelling, signedness, and emitted declaration are still open.
- 2026-06-07 A008 alias cleanup:
  - Normalized the evidence summary so the adjacent EPF/layout selector is named as canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) while preserving the historical IDA alias `byte_66DA97`.
- 2026-06-07 A004 Batch 027:
  - Before: score `80/88`, with exact storage documented but below the parent-assignment completion gate.
  - Changed to: score `86/90`, added fresh IDA MCP neighborhood/xref/function-spread evidence, and recorded [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md) as the exact assigned memory child.
  - Boundary at that time: this by-global page remained unassigned upward because final source-file owner, original declaration spelling, signedness, and emitted declaration were still open.
