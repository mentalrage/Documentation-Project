*** UID:0000ST | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short g_screenHeight = 768;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern short g_screenHeight;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_screenHeight

## 2026-08-14 B003 Signed Declaration Closure

- Final source definition/declaration are `short g_screenHeight = 768;` and `extern short g_screenHeight;`. Target center arithmetic at `0x004fe0d1` uses `movsx`, and the Application constructor at `0x004633be` sign-extends this global; those uses and the literal existing definition support signed `short`.
- A separate zero-extending consumer is use-site behavior, not a definition-type override. The dated IDA `unsigned __int16` display remains documentary; UID0000ST/UID0000HG stay `90/93`.
- Emitter position `10` places this declaration after UID0000SU. The complete Application class emitter now closes the shared guard after the class/global declaration package; the historical height-owned early `#endif` is superseded because it left the class outside the guard.

## Status

- Symbol kind: process-wide display-height global.
- IDA address: `0x0066da98` (`word_66DA98`).
- Storage range: [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md).
- Proposed type: `std::uint16_t` or signed `short` promoted at use sites.
- Initial value in IDA data: `0x0300` / `768`.
- Confidence: strong for storage and display-height role; strong for `Application.cpp` as the best source-owner inference; medium for final source-level variable name and signedness.
- Rebuild handling: source-declared global data. The rebuilt source should declare the display-height word or compatible typed global; exact address placement is linker output.
- Autogen status: reconstructable and attached upward to [UID:0000HG][Application](by-file/Application.md) as a file-level default display-dimension global; first-draft C++ now emits signed `short g_screenHeight = 768` based on current bytes and signed `movsx` use.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 90 | The page records exact storage, item size, initial value, role, paired width global, neighboring byte/word boundaries, live xref count/function spread, representative use families, adjacent-global identities, map-tile boundary, source-declared rebuild handling, direct memory-child evidence, corrected coverage-error behavior, the Application source-owner decision, and first-draft signed-short declaration. It is not higher because exact original source-facing name remains inferred. |
| Confidence | 93 | Current IDA evidence strongly supports the address, size, initial value, paired-display-height interpretation, no-write compile-time initializer behavior, and usage categories across application startup, config defaults, event/dialog layout, logo/media sizing, and screenshot paths. Confidence stays below final-audit level because IDA still labels the storage `word_66DA98` and the original declaration spelling is not recovered. |
| Reconstructable | TRUE | This is source-declared rebuild data, parallel to [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), and now emits first-draft C++ through Application. |

## Role

`g_screenHeight` is the global screen/display height used by startup, pane positioning, and screen-size dependent UI/render paths. It is paired with [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) at `0x0066da94`.

The current documentation name is a source-level role label derived from the paired 1024x768 display-size use pattern. IDA still names the storage `word_66DA98`.

## Evidence

- `Application` startup and window creation paths read `word_66DA98` together with `word_66DA94`.
- Dialog and pane layout paths clamp lower edges against `word_66DA98`.
- Screen-pane construction passes the width/height pair into the screen backing setup path.
- Live IDA MCP recheck on 2026-06-03 found IDB `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, storage name `word_66DA98`, initial word `0x0300` / `768`, and 96 xrefs to `0x0066da98`.
- Representative live xrefs include `Application__Constructor` at `0x004633b7`, application initialization at `0x0046440a`, `RegistryConfig::InitializeDefaults` at `0x0048efbb`, `LogoPane` construction at `0x004f4ca0`, event/dialog root rectangle setup at `0x004a8bb9`, screenshot capture at `0x00557c03`, and alert-pane centering at `0x004a0449`.
- The exact [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md) memory page records the two-byte data item, initial value `0x0300`, and boundaries against the separate movement/layout bytes before it and map-tile dimension globals after it.
- The 2026-06-06 initialized-data neighborhood audit records bytes `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00` for `0x0066da90-0x0066daa2`; interpreted at documented boundaries, `word_66DA98` remains `0x0300` / `768`, preceded by separate [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) slots.
- The 2026-06-07 A005 Batch 028 live IDA MCP audit reconfirmed `word_66DA98` in `.data` with item head `0x0066da98`, item size `2`, word value `0x0300` / `768`, dword view `768`, and local bytes `00 03 00 00 30 00 00 00`. The same pass counted 96 xrefs to `0x0066da98`; representative consumers include `Application__Constructor` at `0x004633b7`, application initialization at `0x0046440a` and `0x004645d6`, layout helpers around `0x00465d30`/`0x00465f20`, UI/render paths such as `0x004f7d10`, screenshot/proof paths around `0x00557aa0`, and late UI helpers near `0x005c2ac0`.
- Related capture/output code such as [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md) consumes the same width/height pair for active screen dimensions.
- 2026-06-07 A005 Batch 071 revalidated this parent and the exact storage child after generated memory coverage reported `0001OI -> 0000ST` as `autogen_parent_unknown`. The by-global relationship remained documented as direct evidence, but the child left `AUTOGEN_PARENT_UID` blank at that time because generated memory coverage rejected by-global parents. B001-007 later assigned this by-global page upward to [UID:0000HG][Application](by-file/Application.md), and A005 Batch230 later restored the memory-child route after the rooted by-global path cleared.
- 2026-06-08 A009 Batch 125 IDA MCP recheck reconfirmed the paired display words in place: `word_66DA94 = 1024` has 98 xrefs, `word_66DA98 = 768` has 96 xrefs, and local bytes at `0x0066da94` are `00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00`. The first height consumers remain `Application__Constructor` at `0x004633b7`, application initialization at `0x0046440a`/`0x004645d6`, and broad UI/layout/render helpers. This strengthens the width/height interpretation but still proves consumers, not a declaration owner.
- 2026-06-10 B001-007 IDA MCP owner audit found `word_66DA98` is a `.data` two-byte item with value `768`, `96` xrefs across `47` functions, and no write xrefs; the paired [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) has value `1024`, `98` xrefs across `48` functions, and no write xrefs. `Application::Application` at `0x004633b7`/`0x004633be` reads height/width and stores them into Application fields `+0x0a60/+0x0a64`; `Application::Initialize` at `0x0046440a`/`0x00464421` uses the globals for fallback window creation and at `0x004645d6`/`0x004645dd` passes height/width into `ScreenPane::ScreenPane`. The same pass rejects `ScreenPane` as the declaration owner because its constructor receives the dimensions as parameters and stores instance fields, while `RegistryConfig::InitializeDefaults` uses the pair only to derive centered default rectangles.

## Neighboring Globals

The bytes before the height word are separate globals, not padding or high bytes of the display dimension pair:

- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) / `word_66DA94` starts at `0x0066da94` and records the paired display width.
- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) / `byte_66DA96` starts at `0x0066da96` and is used by movement-vector and timer-delay scaling.
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` starts at `0x0066da97` and selects the EPF/current-layout asset path.
- `g_screenHeight` starts at `0x0066da98` as the paired display-height word.

The nearby [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) pair begins at `0x0066da9c`, but it describes the `48x48` map-tile pixel span, not the process display height.

[UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md) also records the `0x0066da9a-0x0066da9c` zero padding before the map-tile width word. Do not widen this declaration past the two-byte height slot.

## Source Placement

Keep this global paired with [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) during reconstruction. B001-007 assigns both display-dimension globals upward to [UID:0000HG][Application](by-file/Application.md) as file-level default/base display-dimension declarations.

The inference is source-owner evidence, not recovered source spelling: `Application::Application` copies the initialized pair into its base-dimension fields, `Application::Initialize` uses the pair for fallback main-window creation and ScreenPane construction, and the Application coordinate helpers use the same pair as the base logical display size. `ScreenPane`, `RegistryConfig`, render setup, screenshot, and UI layout paths are important consumers, but IDA shows no write or declaration-side evidence making those files better owners.

First-draft C++ now emits as signed `short` in or near `Application.cpp` because the bytes and signed `movsx` consumers support that declaration. Exact original source spelling remains below the final-code gate.

## Assignment Gate

This page is the direct by-global parent for the exact storage child [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md), because it owns the source-level display-height global and is scored above `85/85`. Batch230 routes the memory child here after this page was rooted upward to [UID:0000HG][Application](by-file/Application.md), preserving the narrow semantic parent instead of assigning the storage directly to the broad file owner.

B001-007 assignment decision: attach this by-global page upward to [UID:0000HG][Application](by-file/Application.md). The child/global side is `88/91`, the file parent is `86/90`, and the IDA evidence supports `Application.cpp` as the narrowest existing source-owner reconstruction for the paired default display-size declarations.

## Cross-References

- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md)
- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)

## 2026-06-29 B013 Application Empty-Emitter Implementation

- Formal C++ now emits FD-0000ST from the accepted B013 report.
- Current MCP bytes at `0x0066da98` begin `00 03`, and coordinate/window code uses sign-extending reads, supporting a signed `short` declaration rather than a 32-bit `int`.
- UID0001OI remains the exact by-memory storage child and should not duplicate this definition.
- Score becomes `90/93`; confidence remains below 95 only for exact original global spelling/linkage.

Implementation validator: run `python .\tools\validator.py --mode file --file by-global/g_screenHeight.md --apply --queue-timeout 240` from `source-3/project-documentation`.

## Changes

- 2026-06-11 A005 Batch230 memory-child routing refresh:
  - Kept score `88/91` and parent [UID:0000HG][Application](by-file/Application.md).
  - Updated the exact storage-child wording because [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md) now routes to this by-global page after the rooted parent path cleared.
- Before: this page described `byte_66DA96` as a separate unresolved byte between the width and height words.
- After: the byte is identified as [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), a movement interpolation/timer scale separate from `g_screenHeight`.
- Evidence: IDA MCP xrefs show `byte_66DA96` used in movement/vector division and timer-delay scaling, not display-height storage.
- 2026-06-02: Raised metadata from `55/80` to `70/84` and marked reconstructable.
  - Before: the page had exact storage and role evidence but no explicit rebuild handling, score rationale, or source-placement note.
  - After: it matched the paired [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) documentation style, recorded source-declared global handling, and kept parent/C++ blank at that time; B001-007 later set the Application parent while leaving C++ blank.
  - Evidence: the exact memory page [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md) confirms storage/value/boundaries, and prior IDA MCP checks recorded 96 xrefs to the height word.
- 2026-06-03: Raised metadata from `70/84` to `78/88`.
  - Reason: live IDA MCP reconfirmed the exact `0x0066da98` two-byte storage, initial value `768`, 96-xref count, neighboring byte/word boundaries, and representative use families across application startup, initialization, registry defaults, event/dialog layout, logo sizing, alert centering, and screenshot capture.
  - Boundary at that time: `AUTOGEN_PARENT_UID` and C++ remained blank because final owner file, original declaration spelling, and exact signedness/linkage were still below the `95/95` reconstruction threshold.
- 2026-06-06: Raised completion from `78` to `80`.
  - Reason: added the missing neighboring-global section to match the paired width page and explicitly linked [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and the map-tile/padding boundary after the height word.
  - Boundary: confidence stays `88`; the storage/boundary evidence is strong, but final owner file, source spelling, signedness, and emitted declaration are still open.
- 2026-06-07 A008 alias cleanup:
  - Normalized the initialized-data neighborhood summary so the EPF/layout selector is named as canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) instead of only as a loose neighbor label.
- 2026-06-07 A005 parent-gate follow-up:
  - Changed score from `80/88` to `85/90`.
  - Added the Batch 028 live IDA MCP item-size/value/local-byte and 96-xref evidence from the exact storage child.
  - Clarified that this by-global page directly parents [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md), while the by-global page itself remained unattached to a file-level owner at that time.
- 2026-06-07 A005 Batch 071 coverage-error repair:
  - Kept score `85/90` and changed the parent-gate wording from active autogen parent to direct by-global evidence anchor.
  - Validation rechecks still reported generated memory coverage error `autogen_parent_unknown` for `0001OI -> 0000ST`; matching the paired [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) repair, the exact memory child left `AUTOGEN_PARENT_UID` blank at that time. B001-007 later assigned this by-global page upward to Application, and A005 Batch230 later restored the memory-child route.
- 2026-06-08 A009 Batch 125 source-owner audit:
  - Changed score from `85/90` to `86/90`.
  - Added current IDA MCP paired-width/height bytes and xref counts, and documented the direct-owner check against [UID:0000HG][Application](by-file/Application.md) and [UID:0000NB][ScreenPane](by-file/ScreenPane.md).
  - Assignment remained blank at that time with status `reviewed-85-but-ownership-unknown` because the candidate source pages proved consumer/instance-dimension roles, not direct declaration ownership for the global. B001-007 supersedes this with an Application owner inference.
- 2026-06-10 B001-007 ownership inference:
  - Changed score from `86/90` to `88/91` and set `AUTOGEN_PARENT_UID:0000HG`.
  - Evidence: fresh IDA MCP confirmed `.data` item size/value, `96` xrefs across `47` functions, no write xrefs, constructor copies to Application fields `+0x0a60/+0x0a64`, initialization uses the pair for fallback window creation and `ScreenPane::ScreenPane`, and Application coordinate helpers treat the pair as the base logical display size.
  - Rejected alternatives: `ScreenPane` receives the dimensions as constructor parameters and owns instance fields only; `RegistryConfig` uses the pair to center default rectangles; render/screenshot/UI paths are consumers; a new `DisplayGlobals` file would contain only this pair with no stronger IDA-backed source boundary than the existing Application owner.
