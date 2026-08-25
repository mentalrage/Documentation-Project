*** UID:0001R9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Employee Dialog Resources

## Status

- Scope: strings and resource/data constants currently tied to the employee shop dialog family.
- Confidence: very strong for the inline strings, byte-backed ASCII resource names, vtable/data island ownership, consuming dialog methods, source/resource boundary, current DAT payload provenance, and resolved string-table id `247`; medium for mixed codepage text fragments and final per-string child splitting.
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks already recorded in the linked by-memory, by-file, and issue-tracker pages.

## Resource Family

| Resource/data item | Evidence owner | Observed role | Rebuild handling | Notes |
| --- | --- | --- | --- | --- |
| `Employee` | [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md) | Employee dialog resource/name literal. | Source-declared/generated-binary string literal or resource key. Preserve in employee dialog source/read-only string data; not a resource payload by itself. | Byte-backed at `0x0061916c`; older uppercase `EMPLOYEE` wording was a normalized description, not the exact bytes. |
| `SELLER.EPF`, `SELLER.PAL` | [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) | Main employee/seller dialog art resources. | Resource-derived main employee/seller dialog art and palette payloads. Source owns the filename constants and loader calls. | Byte-backed at `0x00619180` and `0x00619198`; older `LLER.*` wording was an IDA interior-label artifact. |
| `Property` | [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) | Property editor label/resource marker. | Source-declared/generated-binary string or resource key consumed by the property dialog path. Keep with employee property UI until DAT evidence proves an asset payload. | Byte-backed at `0x00619224`; owned by the employee item property dialog path, not by generic item exchange dialogs. |
| `SELLITEM.EPF`, `SELLITEM.PAL` | [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) | Employee item-list/art resources. | Resource-derived employee item-list art and palette payloads. Do not merge with generic item dialogs before a DAT asset audit. | Byte-backed at `0x00619238` and `0x00619254`; older `LLITEM.*` wording was an IDA interior-label artifact. |
| `Quantity` | [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) | Quantity prompt/control label family. | Source-declared/generated-binary label/resource key. It is distinct from localized string id `247`, which is runtime text-table data. | Distinct from localized string id `247`, now decoded from `STR.RES` as `Add how many?`. |
| `DLGEXC3.EPF` | [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) | Quantity/input dialog art resource used by the employee quantity prompt. | Resource-derived dialog background payload shared with other number/input dialogs; keep this page scoped to the employee quantity-dialog use. | Byte-backed at `0x00619284`; older `3.EPF` wording was an IDA interior-label artifact. |

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data`, checked for loose matching files, and extracted `STR.RES` from `baram.dat`. The employee art payloads are present in the current package, and localized string id `247` resolves in the shipped string table.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `SELLER.EPF` | `bint2.dat`, entry index `78`, offset `10,142,925`, size `108,884` bytes. | EPF header begins with one frame and dimensions `0x0133 x 0x015e`; matches the main seller dialog art role. |
| `SELLER.PAL` | `bint2.dat`, entry index `79`, offset `10,251,809`, size `1,056` bytes. | Payload begins with the `DLPalette` header. |
| `SELLITEM.EPF` | `bint2.dat`, entry index `80`, offset `10,252,865`, size `38,598` bytes. | EPF header begins with one frame and dimensions `0x0133 x 0x007c`; matches the employee item-list/art role. |
| `SELLITEM.PAL` | `bint2.dat`, entry index `81`, offset `10,291,463`, size `1,056` bytes. | Payload begins with the `DLPalette` header. |
| `DLGEXC3.EPF` | `bint1.dat`, entry index `23`, offset `2,088,302`, size `44,137` bytes. | EPF header begins with one `0x00ee x 0x00b7` frame; this is shared dialog background art, not employee-exclusive data. |
| localized string id `247` | `baram.dat`, `STR.RES`, entry index `9`, offset `11,268,984`, size `7,058` bytes. | The 248-line text table resolves id `247` to `Add how many?`; id `246` is `Buy how many?` and remains separate. |

## Resource Strings

| Address | Value | Observed use | Notes |
| --- | --- | --- | --- |
| `0x0061929c-0x006192c6` | `한번에 여러개를 추가할 수 없습니다.` | [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) multi-selection warning. | Only observed xref is `0x004a4bc1` inside `0x004a4b20-0x004a4cb1`. Meaning: cannot add multiple items at once. Formal source declaration now lives on [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) as `kCannotAddMultipleEmployeeItemsText`; this resource page remains non-emitting/index-only. |
| `0x00613a18-0x00613a1e` | `OK` | Primary button label for the warning alert and many other dialogs. | Shared dialog string with many IDA xrefs; current generated alias `g_addEmployeeAlertCallbacks` is incorrect. |
| localized string id `247` | `Add how many?` | Quantity prompt text passed to `EmployeeQuantityInputDialogPane`. | Loaded through `GetLocalizedString`/string table at `0x004f0350` before constructing the quantity prompt; resolved from shipped `baram.dat` `STR.RES`. |

## Byte-Backed Tail Inventory

IDA MCP `get_bytes` on 2026-06-14 rechecked the `0x0061916c-0x0061929c` tail directly. The ASCII/wide resource starts are exact; the mixed Korean/format fragments are noted as source-owned strings but still need a separate codepage/string-type audit before final literal spelling.

| Address | Byte-backed value or role | Xref summary | Notes |
| --- | --- | --- | --- |
| `0x0061916c` | `Employee` | `0x004a1da9` in `sub_4A1D70` | Main employee dialog key/name literal. |
| `0x00619180` | `SELLER.EPF` | `0x004a25b8` in `sub_4A2560` | Main seller art/background resource. |
| `0x00619198` | `SELLER.PAL` | `0x004a25c4` in `sub_4A2560` | Main seller palette resource. |
| `0x006191b0` | `%u` | 15 total xrefs, including employee hits in `sub_4A2560`, `sub_4A2A60`, and `sub_4A41C0` | Shared unsigned-number format string; not employee-private by itself. |
| `0x006191b8` | Korean removal-time format string | `0x004a2a0c` in `sub_4A2560` | UTF-16LE text includes `%d`; final source spelling should be rechecked with the client codepage path. |
| `0x006191e4` | Korean `before/ago` suffix fragment | `0x004a2c01` in `sub_4A2A60` | Source string fragment in the employee paint/status path. |
| `0x006191ec` | `%s [ %d ] : ` | `0x004a2c3c` in `sub_4A2A60` | Employee item/status format fragment. |
| `0x00619208` | CP949-decoded narrow fragment `의고용상인` | `0x004a3193` in `sub_4A2F60`, plus raw helper hit `0x004a40b3` | Mixed string typing; keep under the tail until exact child/string-type pages exist. |
| `0x00619214` | `(%d%%)` | Four total xrefs, including `sub_4A34D0` and `sub_4A3E10` | Percent format shared with employee record/update helpers. |
| `0x00619224` | `Property` | `0x004a41f8` in `sub_4A41C0` | Property dialog key/name literal. |
| `0x00619238` | `SELLITEM.EPF` | `0x004a45c1` in `sub_4A4570` | Employee item art resource. |
| `0x00619254` | `SELLITEM.PAL` | `0x004a45cd` in `sub_4A4570` | Employee item palette resource. |
| `0x00619270` | `Quantity` | `0x004a47a6` in `sub_4A4770` | Employee quantity prompt key/name literal. |
| `0x00619284` | `DLGEXC3.EPF` | 10 total xrefs; employee quantity hits at `0x004a4810` and `0x004a4988` | Shared dialog background name also used outside the employee module. |

## Consumer Map

| Consumer | Resource use | Evidence |
| --- | --- | --- |
| [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) | Owns the employee shop dialog family, employee records, item-slot rendering, quantity/property child panes, and opcode `0x54` employee command paths. | File page records the `0x004a1d70-0x004a4e6a` boundary and the exact employee dialog vtable-data children. |
| [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) | Uses the static Korean warning and shared `OK` label when confirm is pressed with multiple selected items. | [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) records the `OnButtonClick` behavior. |
| [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) | Consumes localized string id `247` for the stack/count prompt after a single selected stack-like item. | The AddEmployee method page records the item flag `+0x1ec` branch and dynamic string lookup. |
| [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) | Consumes the employee property dialog/resource literals in the same `.rdata` family. | The employee file page and read-only-data page keep it as a feature-private employee dialog, not a generic exchange dialog. |

## Ownership Notes

- The Korean warning string belongs with the employee dialog feature or a shared UI string table, not with generic [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- B014 2026-06-27 resolves the source declaration route for the Korean warning: [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) now emits the feature-local static `kCannotAddMultipleEmployeeItemsText` through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). Keep this page as the resource/index view and do not emit C++ here.
- The `OK` string belongs to shared alert/dialog resources and should not be emitted as an employee callback table.
- The quantity prompt text is not an inline literal in the checked method; keep it as localized string id `247`, now decoded from shipped `STR.RES` as `Add how many?`.
- Treat this page as the resource index for the employee dialog feature. Reconstructed source declarations belong on the consuming file/class/memory pages, because `by-resource` pages are not emitted as standalone C++.
- Keep `AddEmployeeItemDialog` feature ownership with [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), even though it reuses generic item dialog behavior; the employee-specific alert, quantity, and command-dispatch paths all depend on the employee owner object.

## Resource-Island Contract

| Area | Source-owned declaration or behavior | Resource/string-table-owned data |
| --- | --- | --- |
| Employee `.rdata` tail | [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md) owns the source-declared/generated-binary constants beside the employee vtables. | The physical bytes should be regenerated from class declarations and static resource-name constants; this page indexes the resource/key meaning but does not replace exact by-memory tail splitting. |
| Main employee/seller art | `EmployeeDialogPane` owns when the main employee dialog art and palette are loaded and how employee records/item slots are rendered over it. | `SELLER.EPF`/`SELLER.PAL` are resource-derived art/palette payloads pending DAT archive audit. |
| Item/property/quantity child dialogs | `EmployeeItemPropertyDialogPane` and `EmployeeQuantityInputDialogPane` own property editing, quantity validation, command dispatch, and child-dialog layout behavior. | `Property`, `Quantity`, `SELLITEM.EPF`/`.PAL`, and the employee use of shared `DLGEXC3.EPF` remain employee-family keys/assets until DAT evidence proves a broader owner. |
| Add-employee alert flow | `AddEmployeeItemDialog` owns the multi-select rejection and stack-count branch; the shared alert shell owns modal display mechanics. | The Korean warning string is employee-feature text; shared `OK` stays with [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md), and localized id `247` stays with the language/string table until decoded. |

## Collision And Exclusion Rules

- Do not merge employee `SELLITEM.EPF` / `SELLITEM.PAL` with generic item dialog resources solely because generic item picker controls are reused. Employee command routing and owner-pointer state keep this resource family under [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Do not treat `Quantity` and localized string id `247` as the same resource. `Quantity` is an observed employee read-only literal/key, while id `247` is dynamically looked up text decoded from `STR.RES` as `Add how many?`.
- Do not model shared `OK` as `g_addEmployeeAlertCallbacks`; linked alert resources and the broad xref count make it a shared dialog label.
- Keep the `0x0061916c-0x0061929c` resource-literal tail as part of [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md) until exact per-string child pages are created. This resource page may summarize the literals, but it should not claim byte-level child splits that do not exist yet.
- Treat `DLGEXC3.EPF` as a shared dialog background name with an employee quantity-dialog use. The `0x00619284` string is not employee-exclusive, and older `3.EPF` labels are interior-label artifacts.

## Rebuild Notes

For source reconstruction, keep the employee resources in [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) and its feature-private child dialogs. The generic item picker remains in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), but the employee add-item variant consumes employee-only warning, quantity, and command-dispatch behavior.

The current resource boundary is:

- source-owned: `Employee`, `Property`, `Quantity`, resource filename constants, localized string id `247`, feature-private command routing, and the shared `OK` label reference;
- source-declared on exact memory child: `kCannotAddMultipleEmployeeItemsText` for the warning at `0x0061929c-0x006192c6`, now emitted by [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) rather than by this resource index;
- resource-owned: `SELLER.EPF`, `SELLER.PAL`, `SELLITEM.EPF`, `SELLITEM.PAL`, the employee quantity-dialog use of `DLGEXC3.EPF`, and any DAT/archive metadata needed to load them;
- shared-source/string-table: the `OK` literal and localized id `247`, which should remain shared references rather than employee-private payloads.

Current asset extraction proves the `SELLER.*`, `SELLITEM.*`, and shared `DLGEXC3.EPF` package entries, and `STR.RES` resolves localized id `247`. Final string audit still needs to decide whether the mixed non-ASCII fragments in the tail are original wide literals, narrow CP949 literals, or IDA string-typing artifacts.

## Open Questions

- Are `Property`, `Quantity`, and `Employee` pure source literals/resource keys, or do any correspond to DAT-side payload names?
- Which tail fragments should be modeled as wide literals versus narrow CP949 strings once the exact per-string children are split?

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page now indexes the byte-backed employee dialog resource literals, exact inline strings, xref-backed tail starts, consuming classes, memory evidence, source/resource boundaries, rebuild handling, resource-island contract, shared-string/localized-string collision rules, current DAT entries for `SELLER.*`, `SELLITEM.*`, and shared `DLGEXC3.EPF`, plus decoded `STR.RES` id `247`. It remains below high completion because original resource macro/literal strategy, exact per-string child pages, and mixed tail string typing are still unresolved. |
| Confidence | 93 | The string addresses, byte-backed resource names, warning xref, shared `OK` caveat, employee `.rdata` family, consuming dialog methods, package entries, palette headers, EPF headers, and localized id `247` are backed by current IDA MCP byte/xref evidence plus direct DAT payload parsing. Confidence is capped below final-audit range by unresolved mixed wide/narrow text typing and source declaration style in the tail. |

## IDA MCP Evidence

- `0x0061929c` decodes as UTF-16 `한번에 여러개를 추가할 수 없습니다.`; IDA xref `0x004a4bc1` lands in `0x004a4b20-0x004a4cb1`.
- 2026-06-27 B014 live MCP session/database `b001_000241_20260627` reconfirmed the warning bytes, unique byte-pattern hit at `0x61929c`, no xrefs to the predecessor/terminator/padding/successor addresses, and the `sub_49FEB0` alert call push order. This supports [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) as the source declaration owner while preserving this page's non-emitting resource-index role.
- `0x00613a18` decodes as UTF-16 `OK` and has many dialog xrefs, confirming it is shared UI string data rather than employee-only state.
- 2026-06-14 A003 IDA MCP byte/xref refresh on `a001_goal2_class_batch`: `get_bytes` over `0x0061916c-0x0061929c` confirms exact ASCII/wide starts for `Employee`, `SELLER.EPF`, `SELLER.PAL`, `Property`, `SELLITEM.EPF`, `SELLITEM.PAL`, `Quantity`, and `DLGEXC3.EPF`; `xrefs_to` ties those starts to the expected employee constructor/paint/property/quantity methods while showing `DLGEXC3.EPF` is shared beyond the employee module.
- [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md) records the surrounding employee dialog RTTI/vtable and resource literal island.
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) records the 2026-05-26 action-method recheck tying `AddEmployeeItemDialog::OnButtonClick` to the warning string, shared `OK`, and localized string id `247`.
- Localized string id `247` is resolved from shipped `baram.dat` `STR.RES` as `Add how many?`; do not merge it with source literal `Quantity` or neighboring id `246`.

## Cross-References

- File: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Classes: [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md), [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md), [UID:00000B][AlertPane](by-class/AlertPane.md)
- Memory: [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md), [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md), [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md), [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md)
- Related resources: [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)

## Changes

- 2026-06-27 B014 AddEmployee warning declaration sync:
  - Score unchanged at `88/93`.
  - Summary/evidence: preserved the Korean Resource Strings row and added that [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) now owns the formal `kCannotAddMultipleEmployeeItemsText` static declaration through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). This page remains a by-resource index and does not emit C++.
- Before: the Korean warning string was mojibake in the page and the page was scored `0/0`.
- Changed to: decoded UTF-16 Korean text, `COMPLETION:60`, and `CONFIDENCE:85`.
- Evidence: IDA MCP direct UTF-16 decode of `0x0061929c` and xref from `0x004a4bc1`.
- 2026-06-02 resource-family pass:
  - What existed before: the page listed only the two inline strings plus unresolved localized id `247`.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:88`, with employee resource-family literals, consumer map, ownership boundaries, and score rationale.
  - Summary/evidence: linked employee `.rdata`, EmployeeDialogPane, AddEmployee method, AddEmployee alert text, and shared OK pages already establish the resource island and caller behavior; DAT payload and string-table text remain open.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page had employee resource-family ownership and consumer maps but did not classify each resource/key by rebuild handling.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:90`, with per-item rebuild handling, explicit source/resource boundaries, and DAT/localized-string open questions.
  - Summary/evidence: EmployeeDialogPane and AddEmployeeItemDialog owner docs establish employee-specific source ownership while linked memory pages anchor the read-only string/resource island; DAT payload provenance and localized string id `247` remain open.
- 2026-06-07 A002 resource-island contract pass:
  - Before: the page linked the employee `.rdata` island, but did not state how the resource-literal tail, shared `OK`, localized id `247`, and generic item-dialog reuse should be kept separate.
  - After: raised to `COMPLETION:80` with a resource-island contract, collision/exclusion rules, exact read-only-data link in cross-references, and score rationale that preserves the DAT/localization/per-string split blockers.
- 2026-06-14 A003 byte-backed score refresh:
  - Before: the page still used several IDA interior-label artifacts (`LLER.*`, `LLITEM.*`, and `3.EPF`) for byte-backed employee resource literals.
  - After: raised to `COMPLETION:85`, `CONFIDENCE:91`, corrected the resource names to `Employee`, `SELLER.*`, `Property`, `SELLITEM.*`, `Quantity`, and shared `DLGEXC3.EPF`, and added a tail inventory with xrefs.
  - Evidence: live IDA MCP `get_bytes`, `xrefs_to`, and `analyze_function` on database `a001_goal2_class_batch`; DAT packaging, localized string id `247`, and exact mixed string-type child splits remain below the gate.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:91`, with strong IDA byte/xref evidence but unresolved DAT packaging and localized string id `247`.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:93`, with current package entries for `SELLER.EPF`, `SELLER.PAL`, `SELLITEM.EPF`, `SELLITEM.PAL`, shared `DLGEXC3.EPF`, and `baram.dat` `STR.RES` id `247` decoded as `Add how many?`.
  - Evidence: fixed-table DAT parsing of `bint2.dat`, `bint1.dat`, and `baram.dat` under `E:\2026\Resources\Read_Only\NexusTK\Data`; palette payloads begin with `DLPalette`, and the EPF headers match the documented art roles.
