*** UID:0001RJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NumberInputDialog Resources

## Status

- Confidence: very strong for resource names, layout split, current package provenance, and resolved localized validation text; medium for the absent legacy `DLGEXC3.EPD` payload and complete shared-background inventory.
- Covered file/module: [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- Main code range: [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)

## Resource Map

| Asset mode | Background | Palette | Layout notes |
| --- | --- | --- | --- |
| EPF mode | `DLGEXC3.EPF` | `PAL01.PAL` | `239x283` background, OK image `14`, cancel image `22`, prompt label control `3`, edit control `4`. |
| EPD mode | `DLGEXC3.EPD` | `NPAL8.PAL` | `287x277` background, OK image `14`, cancel image `22`, prompt label control `3`, edit control `4`. |

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data`, checked for loose matching files, and extracted the shared string table from `baram.dat`. The EPF-mode background and both palette operands are present in the current package; the legacy `.EPD` background operand is not present in the audited tree.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `DLGEXC3.EPF` | `bint1.dat`, entry index `23`, offset `2,088,302`, size `44,137` bytes. | EPF header begins with one `0x00ee x 0x00b7` frame; this matches the shared dialog background role also used by employee quantity prompts. |
| `PAL01.PAL` | `bint2.dat`, entry index `56`, offset `9,276,430`, size `1,056` bytes. | Payload begins with the `DLPalette` header. |
| `NPAL8.PAL` | `bint2.dat`, entry index `50`, offset `9,161,935`, size `1,056` bytes. | Payload begins with the `DLPalette` header and remains a shared legacy-dialog palette. |
| `DLGEXC3.EPD` | No matching DAT entry or loose file found in the audited current tree. | Keep the legacy branch documented from IDA string/xref evidence, but treat the payload as absent from this distribution. |
| localized string id `217` | `baram.dat`, `STR.RES`, entry index `9`, offset `11,268,984`, size `7,058` bytes. | The 248-line text table resolves id `217` to `You have entered an incorrect number.` |

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned data |
| --- | --- | --- |
| Asset-mode branch | `NumberInputDialog` owns the runtime branch on the client asset-mode flag and the choice of EPF versus EPD layout geometry. | `DLGEXC3.EPF`/`DLGEXC3.EPD` own the background art payloads; `PAL01.PAL`/`NPAL8.PAL` own palette data. |
| Control layout | The constructor owns dialog size, prompt/edit rectangles, control IDs `1` through `4`, OK/cancel default behavior, focus assignment, and slide-open positioning. | Button image indexes `14` and `22` are resource-frame selections consumed by the source layout rather than separate dialog behaviors. |
| Validation and alerts | The action handler owns integer parsing, min/max checks, callback dispatch, and use of the shared alert path for localized error string id `217`. | The localized error text belongs to the language/string system and resolves from `STR.RES` as `You have entered an incorrect number.`; alert shell resources stay with shared alert docs. |
| Caller prompts | Item-mixing callers own the prompt text, min/max values, and callback object they pass into the dialog. | This resource page does not own item-specific quantity text or callback payloads. |

## 2026-06-17 Source-Quality Integration

B002's NumberInputDialog source-quality pass reuses this page as the resource authority for first-draft constructor/action-handler C++:

- EPF branch: `DLGEXC3.EPF`, `PAL01.PAL`, `239 x 283`.
- EPD branch: `DLGEXC3.EPD`, `NPAL8.PAL`, `287 x 277`.
- Control/action ids: OK/default `1`, cancel `2`, prompt label `3`, edit control `4`.
- Button image/frame ids: OK/default `14`, cancel `22`.
- Localized validation failure text: STR.RES id `217`, `You have entered an incorrect number.`.

The generated `L"NP"` EPD palette spelling is stale/truncated and must not be used in source-quality C++. Exact branch-specific button rectangles are below-final because this report was completed without a live IDA MCP session; current first-draft code should use descriptive layout helper calls rather than invent unproven rectangle constants.

## Shared Resource Boundaries

- `DLGEXC3.EPF` is shared by other dialog constructors according to the current IDA and package evidence. Keep this page scoped to the `NumberInputDialog` use of that background, palette, and geometry rather than claiming exclusive asset ownership.
- `PAL01.PAL` and `NPAL8.PAL` are current-package shared UI palettes. Rebuild code should retain ordinary source literals/resource lookups instead of creating number-dialog-private palette globals. [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md) is the central authority for PAL01's exact 23-operand/sixteen-function consumer inventory and pooling contract.
- The generated `L"NP"` EPD palette in active output is a string decoding defect. The resource contract for this dialog remains `NPAL8.PAL` unless future IDA evidence proves a different string path.
- The `AlertPane` shown for out-of-range input is a shared dialog dependency, not a number-input resource asset. Keep alert-frame/button-string ownership on [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md).

## IDA Evidence

Checked on 2026-05-25, 2026-05-26, and reverified through IDA MCP:

- The UTF-16 string `DLGEXC3.EPF` at `0x00619284` has xrefs at `0x00530711` and `0x00530889` inside `0x00530640-0x00530b00`; the same string is shared by other dialog constructors.
- The UTF-16 string `PAL01.PAL` at `0x00618cfc` is the EPF-mode palette operand used by `NumberInputDialog` at `0x00530704`. Exact physical child [UID:0004SU][0x00618cfc-0x00618d10.Pal01PaletteResourceString](by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md) proves the full literal, terminator, DLPalette package payload, shared no-owner storage, and zero-xref `L01.PAL` suffix rejection.
- The UTF-16 string symbol `aNp` at `0x0061484c` decodes to `NPAL8.PAL`; IDA reports a `NumberInputDialog` constructor xref at `0x005308eb`.
- The UTF-16 string symbol `aDlgexc3Epd` at `0x0062026c` decodes to `DLGEXC3.EPD`; IDA reports constructor xrefs at `0x005308f8` and `0x00530a79`.
- Active `source-3/simroot_v2/class_NumberInputDialog.cpp` currently renders the EPD palette argument as `L"NP"`, which truncates the actual `NPAL8.PAL` string.
- 2026-05-26 IDA `xrefs_to` still reports the constructor data xref at `0x005308eb` for `NPAL8.PAL` and `0x005308f8` / `0x00530a79` for `DLGEXC3.EPD`.
- IDA decompilation of `0x00530640-0x00530b00` confirms the EPF branch uses `239x283`, OK image `14`, cancel image `22`, prompt rect `(28,35)-(211,107)`, and edit rect `(28,111)-(211,123)`. The EPD branch uses `287x277`, OK image `14`, cancel image `22`, prompt rect `(37,36)-(249,119)`, and edit rect `(52,129)-(234,141)`.
- 2026-06-14 A003 IDA MCP refresh on database `a001_goal2_class_batch`: raw `get_bytes` confirms the byte-backed UTF-16 names `DLGEXC3.EPF` at `0x00619284`, `PAL01.PAL` at `0x00618cfc`, `NPAL8.PAL` at `0x0061484c`, and `DLGEXC3.EPD` at `0x0062026c`. This is important because `get_string` still truncates several of these heads as `DL`, `P`, or `NP`.
- The same refresh reports total/shared xref counts and the NumberInputDialog constructor hits: `DLGEXC3.EPF` has 10 total xrefs with constructor hits at `0x00530711` and `0x00530889`; `PAL01.PAL` has 23 total xrefs with constructor hit `0x00530704`; `NPAL8.PAL` has 60 total xrefs with constructor hit `0x005308eb`; `DLGEXC3.EPD` has two xrefs, both in `sub_530640` at `0x005308f8` and `0x00530a79`.
- `analyze_function 0x00530640` in the same session reports `sub_530640` size `0x4c0`, callers `sub_4AFCC0` and `sub_4B0120`, and decompile markers for `byte_66DA97`, `DLGEXC3`, `off_618CFC`, and `aNp`, matching the EPF/EPD branch documented above.

## Ownership Decision

Use `NPAL8.PAL` for the EPD branch unless later binary evidence proves a different runtime string path. Treat `L"NP"` in generated output as a data/string decoding issue.

The reusable number dialog owns the source behavior for building the prompt, edit field, buttons, validation path, and callback handoff. Item-mixing dialogs remain callers, not resource owners, and the resource page should not absorb their prompt text or stack-count business rules.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | Known EPF/EPD backgrounds, palettes, branch geometry, button/control IDs, string-decoding caveat, owner file/class/memory links, source/resource contract, shared palette/background boundaries, alert dependency, caller-owned prompt boundaries, current byte-backed names, shared xref counts, current package entries for `DLGEXC3.EPF`, `PAL01.PAL`, and `NPAL8.PAL`, a negative `DLGEXC3.EPD` package finding, and decoded localized id `217` are documented. It remains below high completion because original declarations/macros, complete shared `DLGEXC3` inventory, and the missing legacy `.EPD` payload are not fully resolved. |
| Confidence | 93 | Resource filenames, palette strings, xrefs, geometry, generated-data correction, palette headers, EPF header, and validation text are backed by current IDA MCP byte/xref/function evidence plus direct DAT/`STR.RES` parsing. Confidence remains below maximum because the exact original source representation, full shared-resource inventory, and legacy `DLGEXC3.EPD` payload provenance are not final. |

## Cross-References

- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md)
- [UID:0004SU][0x00618cfc-0x00618d10.Pal01PaletteResourceString](by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-07-16 B003 UID0003AX bounded support synchronization:
  - Scores `88/93`, owner state, and every NumberInputDialog/DLGEXC3-specific fact remain unchanged.
  - Added exact UID0004SY/UID0004SU links for the central PAL01 consumer inventory, package payload, pooled-storage source contract, and false interior suffix correction.
  - Preserved DLGEXC3 EPF/EPD geometry, control/action IDs, localized id 217, NPAL8 role, package provenance, and missing legacy DLGEXC3.EPD blocker.

- Before: page had concrete IDA notes but was still scored `0/0`.
- Changed to: `COMPLETION:78`, `CONFIDENCE:90`, with current IDA MCP verification of resource strings, xrefs, branch dimensions, and layout rectangles.
- Evidence: IDA MCP UTF-16 string/xref search and decompilation of `0x00530640-0x00530b00`.
- 2026-06-07 A002 source/resource contract pass:
  - Before: the page listed verified resource names and layout facts, but did not separate source-owned dialog behavior from shared asset and palette data.
  - After: raised to `COMPLETION:80` with source/resource contracts, shared `DLGEXC3`/palette boundaries, alert dependency scope, caller prompt ownership, and explicit score rationale.
- 2026-06-14 A003 score refresh:
  - Before: the page documented the resource set but did not record a current raw-byte refresh for IDA's truncated `get_string` heads or the shared xref counts.
  - After: raised to `COMPLETION:85`, `CONFIDENCE:91`, with current IDA MCP byte-backed names, constructor xrefs, and function markers.
  - Evidence: live IDA MCP `get_bytes`, `xrefs_to`, and `analyze_function 0x00530640` on `a001_goal2_class_batch`; DAT packaging and original declaration style remain below final gate.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:91`, with byte-backed IDA evidence but no DAT/package proof for the background/palette payloads or localized validation string.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:93`, with package entries for `DLGEXC3.EPF`, `PAL01.PAL`, and `NPAL8.PAL`, a negative current-package finding for `DLGEXC3.EPD`, and `STR.RES` id `217` decoded as `You have entered an incorrect number.`
  - Evidence: fixed-table DAT parsing of `bint1.dat`, `bint2.dat`, and `baram.dat` under `E:\2026\Resources\Read_Only\NexusTK\Data`; palette payloads begin with `DLPalette`, and `DLGEXC3.EPF` has a one-frame EPF header.
