** TARGET-REPORT-UID:0001FI **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-head-select-dialog-core-source-quality-0001FI-20260618

Primary target: [UID:0001FI] `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`

Required output path: `tools/leaser/Agents/Agent-B001/research/0001FI-HeadSelectDialogCore-source-quality.md`

## Finalized Report / Current Recommendation

Supervisor should populate formal C++ for [UID:0001FI]. The target clears the source-entry gate after this pass because the previous blockers are now either resolved from local binary/exported evidence or reduced to high-probability source-name inferences that do not block a first draft.

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:000062
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000062
```

Recommended source placement remains [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md), emitted through [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) under `NexusTK/ui/dialogs/HeadSelectDialog.cpp`. Do not move the shared category-switch helper `0x0049dd00` into HeadSelect ownership; HeadSelect should call the inherited/shared dialog category switch.

Main correction beyond the existing page: the current `Functions` table omits two real function starts inside the covered range:

- `0x00551250-0x005512c7`: next-page helper; best source-facing name `HeadSelectDialog::NextHeadPage()` or `HeadSelectDialog::NextPage()`.
- `0x005512d0-0x00551340`: previous-page helper; best source-facing name `HeadSelectDialog::PreviousHeadPage()` or `HeadSelectDialog::PreviousPage()`.

These helpers have no proven exported caller or address-taken data reference in the local exports, vtable data, or OOAnalyzer data, and `OnAction` contains equivalent page-change logic inline. They should still be documented in [UID:0001FI] because they are real starts inside the primary range and are behaviorally complete private page-navigation helpers.

Formal C++ should be populated with the draft in this report, with normal supervisor polish for local type names. The draft intentionally models the ordinary destructor only; the adjustor thunks and scalar deleting destructor stay documented by [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md).

## Evidence Checked

- Supervisor and Agent-B001 rules:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B001/goal.md`
  - `tools/leaser/Agents/Agent-B001/notes.md`
  - `tools/leaser/Agents/Agent-B001/inference_research.md`
- Target and ownership docs:
  - [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md)
  - [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md)
  - [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)
  - `by-memory/-coverage-report.md` row for [UID:0001FI]
  - `auto-generated/-ag-memory-coverage.md` route for [UID:0001FI] to `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp`
- Direct local function exports checked:
  - `resources/exported_data/functions/0x00551030.json`: `sub_551030`, preview refresh.
  - `resources/exported_data/functions/0x00551200.json`: `sub_551200`, page button enable/disable helper.
  - `resources/exported_data/functions/0x00551250.json`: real Ghidra start, next-page helper, no exported callers.
  - `resources/exported_data/functions/0x005512d0.json`: real Ghidra start, previous-page helper, no exported callers.
  - `resources/exported_data/functions/0x00551350.json`: `sub_551350`, head-button population.
  - `resources/exported_data/functions/0x00551520.json`: constructor, one exported caller from `0x0054ca50`.
  - `resources/exported_data/functions/0x00551f30.json`: ordinary destructor.
  - `resources/exported_data/functions/0x00551fa0.json`: virtual action handler, IDA xref at `0x00622904`, `RET 0x8`.
  - `resources/exported_data/functions/0x0054ca50.json`: allocation wrapper, allocates `0x304` bytes and calls the constructor.
- Address-reference and preexisting-report checks:
  - `rg` over Agent-B001 research confirmed no preexisting direct `0001FI-HeadSelectDialogCore-source-quality.md` report at the required path.
  - `rg` over exported data found `0x00551250` and `0x005512d0` only in master function/name/difference exports and as callers recorded by `0x00551350`; no vtable or OOAnalyzer data references.
  - `rg` over `resources/exported_data/master_vtables.json`, `resources/ooAnalyzerData.json`, and `hooks-generation/generator_sources/ooAnalyzerData.json` found no `0x00551250` or `0x005512d0` pointer hits.
- Support docs checked:
  - [UID:0001FL][HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md)
  - [UID:00012T][DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md)
  - [UID:00027Z][HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md)
  - [UID:000281][HeadSelectDialogLayoutTableSecondary](by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md)
  - [UID:0003DA][HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md)
  - [UID:0003DG][HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md)
  - [UID:00023M][MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
  - [UID:000179][ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)
  - [UID:0003YK][PacketBufferScalarBigEndianReadHelpers](by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md)
  - [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
  - [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md)
  - [UID:0001BU][ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
  - [UID:0001BV][ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md)
  - [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
  - [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
  - [UID:0001FH][NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), as a sibling packet-layout cross-check.
- Live IDA MCP endpoint check:
  - Attempted connection to `http://127.0.0.1:13337/mcp` failed with connection refusal, so this report uses the repository's exported function JSON, support docs, and existing IDA-backed notes rather than adding new live-session facts.
- Legacy unrefined source checked only as a lead:
  - `unrefined-source-backup/source/HeadSelectDialog.cpp` mirrors the core behavior but is not used as proof. Its omission of the two `0x00551250`/`0x005512d0` starts reinforces that current generated/source-lead material is incomplete for the target range.

## Heuristic / Inference Reanalysis And Validation

### Function Starts, Source-Facing Names, And Signatures

Validated current documented starts:

| Range | Recommended source-facing signature | Evidence and validation |
| --- | --- | --- |
| `0x00551030-0x005511fd` | `void HeadSelectDialog::RefreshHeadPreview()` | Rebuilds the `ObjectImageControlPane` preview, writes selected head into the object-status blob, recomputes the head draw offset from the selected layout table, installs the new preview in control category/slot `5`, destroys the old preview, invalidates, and repaints `(0,0,374,316)`. |
| `0x00551200-0x0055124d` | `void HeadSelectDialog::UpdatePageButtonStates()` | Reads `m_currentPage` at `+0x2c4`, `m_headCount` at `+0x2bc`, previous page button at `+0x300`, and next page button at `+0x2fc`. Vtable slot `+0x4c` is enable/show and slot `+0x50` is disable/hide for these button controls. |
| `0x00551350-0x00551510` | `void HeadSelectDialog::PopulateHeadButtons(int page, bool forceCategorySwitch)` | Deletes old head buttons, optionally switches the dialog/control-manager category to `7`, builds up to ten `ObjectImageButtonPane` controls, highlights the selected head, invalidates, and repaints. The `char` third argument is a boolean force-category flag. |
| `0x00551520-0x00551f25` | `HeadSelectDialog::HeadSelectDialog(const unsigned char *packet)` | Constructor reached from `0x0054ca50`, which allocates `0x304` bytes. It parses packet fields, patches table tail slots, creates background/buttons/preview/text, initializes page state, and populates the current page. |
| `0x00551f30-0x00551f91` | `HeadSelectDialog::~HeadSelectDialog()` | Ordinary destructor; reinstalls the three vtable bases and chains through dialog unregister/cleanup. It should not be represented as source-authored adjustor/scalar-deleting thunk code. |
| `0x00551fa0-0x005520e5` | `void HeadSelectDialog::OnAction(int actionId, int unused)` | IDA decompilation shows two stack parameters and the disassembly ends in `RET 0x8`; only `actionId` is used. Handles close IDs `1`/`4`, previous/next IDs `2`/`3`, and head slot IDs `7` through `16`. |

New starts that the target should add:

| Range | Recommended source-facing signature | Evidence and validation |
| --- | --- | --- |
| `0x00551250-0x005512c7` | `void HeadSelectDialog::NextHeadPage()` or `void HeadSelectDialog::NextPage()` | Ghidra export reports a real non-thunk function of size `0x78`. It increments `+0x2c4`, clamps when `10 * page >= +0x2bc`, calls `PopulateHeadButtons(page, true)`, then repeats the page-button enable/disable logic. No exported callers or vtable/data refs were found. |
| `0x005512d0-0x00551340` | `void HeadSelectDialog::PreviousHeadPage()` or `void HeadSelectDialog::PreviousPage()` | Ghidra export reports a real non-thunk function of size `0x71`. It decrements `+0x2c4`, clamps to zero, calls `PopulateHeadButtons(page, true)`, then repeats the page-button enable/disable logic. No exported callers or vtable/data refs were found. |

Rejected alternative: treat `0x00551250` and `0x005512d0` as padding, switch-table artifacts, or decompiler false positives. The bodies are complete method-shaped page-navigation implementations, call `0x00551350`, and sit between two documented HeadSelect methods. They are not switch-table bytes; the actual `OnAction` switch data is separately documented after `0x005520e5`.

Rejected alternative: model the two helpers as public/vtable methods. No exported caller, vtable pointer, OOAnalyzer method pointer, or documentation reference supports public dispatch. They are best modeled as private retained helpers or addressable callbacks whose references were not preserved in the current exports.

### Packet Field Inference

The constructor packet layout is now defensible enough for formal source:

| Packet offset | Target field/use | Recommended name/type | Evidence |
| --- | --- | --- | --- |
| `+0x00` | Stored at object offset `+0x26c` | `uint8_t m_dialogSubtype` or `m_packetDialogType` | Constructor reads one byte and stores it; no in-range later reads. This is a retained dialog/request subtype byte, not UI text. |
| `+0x01..+0x04` | Stored at `+0x270` | `uint32_t m_headPrice` | Read by `PacketBufferReadUInt32BE`. The file/class docs already describe NPC/object/price/text packet data, and the dialog is a transactional in-game head selection dialog. Exact original member name is not recoverable from local reads, but `m_headPrice` is the best source-facing name; `m_priceOrRequestId` can be used in a stricter-neutral header if supervisor wants to avoid overnaming. |
| `+0x05` | Read as a single byte; if `2`, constructor writes `packet[6] = 2` before object-status parsing | local `objectMode` or `statusMode` | Sibling message-dialog docs show this byte controls the object-status parse shape. The write to `packet[6]` forces the first object-status byte/tag to mode `2`. |
| `+0x06..` | Parsed by `ObjectStatusBlob::ParseTaggedStatus` into object offset `+0x278` | `ObjectStatusBlob m_previewObject` | [UID:000179] documents `ParseTaggedStatus`, full/compact modes, and the 68-byte object-status blob consumed by object-image controls. HeadSelect passes `this+0x278` to both preview and button controls. |
| `parsedBytes + 0x06..+0x09` | Skipped between object status and the two words | reserved/common object-dialog packet bytes | The constructor sets `pos = parsedBytes + 10`, so four bytes after the object-status descriptor end are not named in this target. Sibling docs describe a common object-dialog packet shape; no local HeadSelect read supports a precise name for the skipped bytes. |
| `parsedBytes + 0x0a` | Stored at `+0x274` | `uint16_t m_npcId` | First of two big-endian words after the object-status block. The class/file docs call this NPC/object/price/text packet data; source-facing `m_npcId` is high-probability. |
| `parsedBytes + 0x0c` | Stored at `+0x276` | `uint16_t m_objectId` or `m_dialogObjectId` | Second big-endian word. High-probability role is the object/dialog id paired with the NPC id for later response handling. |
| `parsedBytes + 0x0e` | Read and discarded | `bool`/flag byte, local only | Sibling docs identify two boolean flags in this position; HeadSelect reads both but does not store them. |
| `parsedBytes + 0x0f` | Read and discarded | `bool`/flag byte, local only | Same as above. |
| `parsedBytes + 0x10` | Message length | `uint16_t messageLength` | Big-endian length checked against `0x8000`. |
| `parsedBytes + 0x12` | Message bytes | ANSI dialog message text | Copied to a 32768-byte local buffer, null-terminated, converted with `MultiByteToWideChar(0,0,...)`, then used to construct `StaticTextControlPane`. |

Rejected alternative: `+0x270` is only a request id and not price. It is possible that the exact original member was neutral, but the target's own file/class docs identify price in this packet family, the field is a 32-bit big-endian scalar immediately after the subtype byte, and no stronger local evidence names it otherwise. `m_headPrice` is therefore acceptable as a high-probability source-facing name, with a note that no in-range method consumes it after construction.

Rejected alternative: `+0x274`/`+0x276` are page/head counters. Page/head counters are independently stored at `+0x2bc`, `+0x2c0`, and `+0x2c4` after the object-status parse and head-count lookup. The two words are packet-derived NPC/object dialog identifiers, not UI pagination state.

### Member Field Names And Child-Control Roles

Recommended HeadSelect member map for target incorporation:

| Offset | Recommended field | Evidence |
| --- | --- | --- |
| `+0x1fc` | inherited `DialogPane::m_controlManager` | [UID:0001U4] identifies the inherited dialog control manager/list pointer. `PopulateHeadButtons` reads `m_controlManager->currentCategory` at manager `+0x0c`; `RefreshHeadPreview` uses manager vslot `+0x10` to get/install category slot `5`. |
| `+0x26c` | `uint8_t m_dialogSubtype` | Packet byte `0`. |
| `+0x270` | `uint32_t m_headPrice` | Packet dword `1..4`, high-probability price scalar. |
| `+0x274` | `uint16_t m_npcId` | First packet word after object-status block and skipped common bytes. |
| `+0x276` | `uint16_t m_objectId` | Second packet word after object-status block and skipped common bytes. |
| `+0x278..+0x2bb` | `ObjectStatusBlob m_previewObject` | Parsed by `ObjectStatusBlob::ParseTaggedStatus`; passed to `ObjectImageControlPane` and `ObjectImageButtonPane`. |
| `+0x27c` | `m_previewObject.headIndex` or equivalent 16-bit selected-head field inside the object blob | Written before preview/button object construction from selected/global head id. |
| `+0x2a0` | object-status default byte initialized to `0x50` | Constructor sets byte `+0x2a0 = 80` before parse. Existing object-status parser docs should own exact subfield naming. |
| `+0x2aa` | object-status head draw/Y offset byte | Updated as `m_baseHeadDrawOffset + lowByte(layoutTable[head])`; object-image controls consume it through the blob. |
| `+0x2bc` | `int m_headCount` | Constructor stores `NewHumanImageLib::GetHeadCount()`, page helpers divide/compare against it. |
| `+0x2c0` | `int m_selectedHead` | Constructor initializes from object blob head id and clamps; `OnAction` updates for action IDs `7..16`; `RefreshHeadPreview` writes it into the object blob. |
| `+0x2c4` | `int m_currentPage` | Constructor sets `selectedHead / 10`; page helpers and `OnAction` increment/decrement. |
| `+0x2c8` | `int m_baseHeadDrawOffset` | Constructor computes current blob offset minus full dword table entry for the current head; refresh/populate add low-byte table values to this base. |
| `+0x2cc` | `ObjectImageControlPane *m_previewPane` | Constructor and `RefreshHeadPreview` create/replace the live preview control. |
| `+0x2d0..+0x2f4` | `ObjectImageButtonPane *m_headButtons[10]` | `PopulateHeadButtons` deletes/creates ten slots; `OnAction` indexes by `m_selectedHead % 10` and selected action id. |
| `+0x2f8` | `ImageButtonControlPane *m_confirmButton` or `m_okButton` | Constructor stores image-button resource id `14`; no later target read. Because focus is set to action id `1`, this is probably the accept/confirm button. |
| `+0x2fc` | `ImageButtonControlPane *m_nextPageButton` | `UpdatePageButtonStates` and `OnAction` use this as the next-page button. Constructor resource id `19`. |
| `+0x300` | `ImageButtonControlPane *m_prevPageButton` | `UpdatePageButtonStates` and `OnAction` use this as the previous-page button. Constructor resource id `18`. |

The fourth image button built with resource id `15` is added to the dialog but not retained in a HeadSelect member. It is high-probability cancel/close/dismiss because action ids `1` and `4` both close the dialog and `DialogPaneSetPendingControl(this,4)` follows construction.

### Layout Tables And `byte_66DA97`

`byte_66DA97` should be named through its current global page as `g_useEpfAssets`. In this target, `g_useEpfAssets == 1` selects the high/current EPF layout branch; any other value selects the normal/legacy layout branch.

Recommended static table names:

```cpp
static int s_normalHeadVerticalOffsets[904];  // 0x0066df00-0x0066ed20
static int s_highResHeadVerticalOffsets[913]; // 0x0066eea0-0x0066fce4
```

The tables should remain dword/int arrays, not byte arrays. Evidence:

- Constructor patches full dwords in the tail slots.
- Constructor computes `m_baseHeadDrawOffset` by subtracting the full dword entry for the current head.
- Refresh/populate add only the low byte of the selected dword to the object-status draw-offset byte, which is a use-site detail rather than proof of byte-table storage.

Normal table tail patch:

```text
index 900 = -5
index 901 = -8
index 902 = -2
index 903 remains table storage but has no observed constructor patch/use in this target
```

High/current EPF table tail patch:

```text
index 900 = -5
index 901 = -8
index 902 = -2
index 903 = -7
index 904 = -8
index 905 = -9
index 906 = -3
index 907 = -2
index 908 = -9
index 909 = -2
index 910 = -10
index 911 = -3
index 912 = -3
```

Preview rectangle evidence:

- High/current branch: `(36,40,73,95)`.
- Normal/legacy branch: `(36,40,71,88)`.

Bottom image-button rectangle evidence:

- High/current branch: `(40,266,103,290)`, `(114,266,177,290)`, `(188,266,251,290)`, `(262,266,325,290)`.
- Normal/legacy branch: `(40,266,112,282)`, `(114,266,186,282)`, `(188,266,260,282)`, `(262,266,334,282)`.

Resource literal evidence:

- The background/control resource string is `DLGMSGH.EPF`, documented by [UID:0003DG].
- The EPF image control constructor receives palette/string argument `aNp` in the decompile; unrefined generated source resolves it as `NPAL8.PAL`, but this report does not require supervisor to hard-name the palette unless the resource-string page already owns that literal.

### Row-Table Versus Direct-Tier Taxonomy

This target uses direct class members and static offset tables, not a row-table-driven dialog factory. The 5-by-2 button grid is generated algorithmically from:

- `x = 54 * (slot % 5) + 58`
- `y = ((slot / 5) << 6) + 113`
- `right = x + 41`
- `bottom = y + 54`

The large layout/offset data islands are head-offset lookup tables used for object-image vertical adjustment, not per-control row tables. They should stay as HeadSelect static data children [UID:00027Z] and [UID:000281], not be reclassified as a generic table-driven dialog layout row island.

### List/Control Virtual Slots

The target's open button/control virtual-slot question is resolved to source-level enable/disable and repaint/invalidate operations:

- Dialog virtual slot `+0x38`: invalidates/refreshes the dialog after preview/button rebuilding.
- Dialog virtual slot `+0x30`: repaints/restores a supplied rectangle; this target uses `(0,0,374,316)` and `dword_69B36C`.
- Control-manager virtual slot `+0x10`: returns a writable control slot/list entry for a category id; `RefreshHeadPreview` uses category/slot `5` to replace the preview pane pointer.
- Button/control virtual slot `+0x4c`: enable/show/activate page button.
- Button/control virtual slot `+0x50`: disable/hide/deactivate page button.

Exact original method names for the button slots are not recoverable from this target alone. `Enable()`/`Disable()` or `SetEnabled(bool)` are acceptable in source-facing C++; the current docs' "enables/disables previous and next page buttons" is validated.

### Shared `DialogCategorySwitch` Ownership Caveat

`PopulateHeadButtons` calls `0x0049dd00` only when `forceCategorySwitch` is true and the inherited control manager category is not `7`. [UID:00012T] shows direct callers outside HeadSelect, including fitting-room and another dialog rebuild path. Therefore:

- Do not emit `0x0049dd00` as a private HeadSelect method in final source.
- Source-facing HeadSelect code should call an inherited/shared helper such as `DialogPane::SwitchControlCategory(7)` or `SwitchCategory(7)`.
- The current target caveat that `0x0049dd00` is provisional/shared is validated; it no longer blocks [UID:0001FI] formal C++ because the helper can be referenced as a dependency.

### Constructor/Destructor/Thunk Representation

Constructor representation is source-authored class code:

- Base constructor call: `DialogPane(L"", true, true)` shape from `sub_49D8A0(this, &word_60DB20, 1, 1)`.
- Class size: `0x304` bytes from the wrapper allocation.
- Three HeadSelect vtable bases are installed at object offsets `+0`, `+0xa0`, and `+0xa4`.
- The constructor returns early if `ObjectStatusBlob::ParseTaggedStatus` returns negative, leaving base construction completed but no full dialog controls built.
- Range-check failure is only for oversized message buffers or converted wide length; no ordinary source path returns after that failure.

Destructor representation:

- Source-facing code should declare/define `HeadSelectDialog::~HeadSelectDialog()`.
- The body may be empty or only call local unregister cleanup depending on surrounding source style, because C++ destructors and base destructors account for the visible vtable resets and base cleanup.
- Do not hand-write `this -= 0xa0`, `this -= 0xa4`, or scalar deleting destructor wrappers in [UID:0001FI]. Those remain compiler/vtable support under [UID:0001FL].

### Current Docs Validated

Validated current [UID:0001FI] claims:

- Range endpoint `0x005520e5` and ignored switch/padding data after the range are correct.
- Canonical owner [UID:000062] and emitter [UID:000062] are correct.
- Source file remains [UID:0000JT] `HeadSelectDialog.cpp`.
- Constructor-wrapper path through `0x0054ca50` is correct in the exported function data.
- `ObjectImageControlPane`, `ObjectImageButtonPane`, `EPFImageControlPane`, `ImageButtonControlPane`, `StaticTextControlPane`, `NewHumanImageLib`, and packet-reader dependencies are correct.
- Layout-table ownership by `HeadSelectDialog` is correct.
- Shared category-switch caveat is correct.
- Destructor thunk/scalar-wrapper split is correct.

### Current Docs Contradicted Or Superseded

The current [UID:0001FI], [UID:000062], and [UID:0000JT] function tables are incomplete because they omit real starts `0x00551250` and `0x005512d0`.

The current [UID:0001FI] final-C++ gate is superseded. Packet field names, child-control roles, layout-table shape, and destructor/thunk representation now have enough evidence or high-probability inference for formal C++.

One support doc outside this target, [UID:0001FI] mentions in [UID:0001SO]/MapPane-related context via [UID:0001FI] references, includes a stale-looking statement that [UID:0001FI] documents constructor calls from `0x0050ff65`, `0x0050ffce`, and `0x0051012e` inside `MapPaneHandleMapTransitionPacket`. The current local export for `0x00551520` reports only caller `0x0054ca50`, and `0x0050feb0` decompilation checked in this pass does not show calls to `0x00551520`. Do not rely on those MapPane callsite claims for HeadSelect constructor reachability unless supervisor rechecks them live.

### Remaining Limits And Impact

Remaining exact-name uncertainty:

- Exact original member names for `+0x26c`, `+0x270`, `+0x274`, and `+0x276` are not directly recoverable from local reads because this target stores but does not later consume those fields.
- Exact original source names for the button virtual slots `+0x4c` and `+0x50` are not recoverable from this target alone.
- Exact original names for `0x00551250` and `0x005512d0` are not recoverable; `NextHeadPage`/`PreviousHeadPage` or `NextPage`/`PreviousPage` are behaviorally accurate private-helper names.

These limits cap confidence below final-perfect naming, but they do not block formal C++. Recommended target score `87/89` reflects strong behavior/boundary evidence with limited exact-symbol uncertainty.

## Open Questions Resolved Or Remaining

Resolved:

- `RefreshHeadPreview` name/signature: `void HeadSelectDialog::RefreshHeadPreview()`.
- `UpdatePageButtonStates` name/signature: `void HeadSelectDialog::UpdatePageButtonStates()`.
- `PopulateHeadButtons` name/signature: `void HeadSelectDialog::PopulateHeadButtons(int page, bool forceCategorySwitch)`.
- Constructor signature: `HeadSelectDialog::HeadSelectDialog(const unsigned char *packet)`; wrapper owns allocation and calls this constructor after allocating `0x304`.
- Destructor signature: `HeadSelectDialog::~HeadSelectDialog()`; no source-authored thunk/scalar-deleting body in this target.
- `OnAction` signature: `void HeadSelectDialog::OnAction(int actionId, int unused)`. The second argument is present by `RET 0x8` but unused.
- New omitted helpers: `void HeadSelectDialog::NextHeadPage()` at `0x00551250`; `void HeadSelectDialog::PreviousHeadPage()` at `0x005512d0`.
- Packet payload: one-byte subtype, big-endian 32-bit price, object-status parse at `packet+6`, two big-endian words best named `m_npcId` and `m_objectId`, two discarded flag bytes, 16-bit message length, ANSI message bytes converted to wide text.
- Object/status ownership: `+0x278` is a 68-byte `ObjectStatusBlob` owned by HeadSelect as the preview/button source descriptor; exact subfield names remain owned by the object-status parser/layout docs.
- Layout tables: normal table `s_normalHeadVerticalOffsets[904]`, high/current table `s_highResHeadVerticalOffsets[913]`, dword/int storage, low-byte use for object draw offset, constructor tail patches as listed above.
- `byte_66DA97`: use canonical `g_useEpfAssets`; `==1` selects high/current EPF branch, `!=1` selects normal/legacy branch.
- Shared category switch: call inherited/shared `DialogPane::SwitchControlCategory(7)`; do not claim private HeadSelect ownership for `0x0049dd00`.
- Child-control roles: `+0x2f8` confirm/OK image button, `+0x2fc` next page button, `+0x300` previous page button, unretained resource id `15` cancel/close button.
- Coverage row: current `84%` row should be replaced with the `87%` row in this report.

Remaining but non-blocking:

- Exact original names for `m_dialogSubtype`, `m_headPrice`, `m_npcId`, and `m_objectId` are inferred rather than proven by downstream use. Use the recommended names with a note, or use neutral `m_priceOrRequestId` if supervisor wants a stricter field-name caveat.
- Exact original names for `NextHeadPage`/`PreviousHeadPage` are unknown. The function bodies and placement are proven; the names are behavior-based.
- Live IDA was unavailable during this pass. If supervisor has a live IDA session, rechecking xrefs to `0x00551250` and `0x005512d0` would be useful, but the absence of those xrefs in the local exports is already recorded and does not block documentation.

## First-Draft C++ Recommendation

Supervisor should populate formal C++ for [UID:0001FI]. The following is source-facing C++ suitable for `NexusTK/ui/dialogs/HeadSelectDialog.cpp` after local type-name normalization. It intentionally uses readable source calls for external helper APIs rather than decompiler register scaffolding.

If the supervisor wants the draft to mirror the emitted `OnAction` body more closely, inline the bodies of `PreviousHeadPage()` and `NextHeadPage()` into action cases `2` and `3`; the binary has the page-change logic duplicated in `OnAction` while also retaining the two out-of-line helpers.

```cpp
namespace {

const int kHeadsPerPage = 10;
const int kHeadButtonCount = 10;
const int kHeadButtonCategory = 7;
const int kPreviewCategorySlot = 5;

int LowSignedByte(int value)
{
    return static_cast<signed char>(value & 0xff);
}

void PatchNormalHeadOffsets()
{
    s_normalHeadVerticalOffsets[900] = -5;
    s_normalHeadVerticalOffsets[901] = -8;
    s_normalHeadVerticalOffsets[902] = -2;
}

void PatchHighResHeadOffsets()
{
    static const int kTail[] = {
        -5, -8, -2, -7, -8, -9, -3, -2, -9, -2, -10, -3, -3
    };

    for (int i = 0; i < static_cast<int>(sizeof(kTail) / sizeof(kTail[0])); ++i) {
        s_highResHeadVerticalOffsets[900 + i] = kTail[i];
    }
}

const int *CurrentHeadOffsetTable()
{
    return (g_useEpfAssets == 1)
        ? s_highResHeadVerticalOffsets
        : s_normalHeadVerticalOffsets;
}

RectBounds PreviewRect()
{
    return (g_useEpfAssets == 1)
        ? RectBounds(36, 40, 73, 95)
        : RectBounds(36, 40, 71, 88);
}

RectBounds BottomButtonRect(int slot)
{
    static const RectBounds kHighRes[] = {
        RectBounds(40, 266, 103, 290),
        RectBounds(114, 266, 177, 290),
        RectBounds(188, 266, 251, 290),
        RectBounds(262, 266, 325, 290),
    };

    static const RectBounds kNormal[] = {
        RectBounds(40, 266, 112, 282),
        RectBounds(114, 266, 186, 282),
        RectBounds(188, 266, 260, 282),
        RectBounds(262, 266, 334, 282),
    };

    return (g_useEpfAssets == 1) ? kHighRes[slot] : kNormal[slot];
}

RectBounds HeadButtonRect(int slot)
{
    const int x = 54 * (slot % 5) + 58;
    const int y = ((slot / 5) << 6) + 113;
    return RectBounds(x, y, x + 41, y + 54);
}

} // namespace

HeadSelectDialog::HeadSelectDialog(const unsigned char *packet)
    : DialogPane(L"", true, true),
      m_dialogSubtype(0),
      m_headPrice(0),
      m_npcId(0),
      m_objectId(0),
      m_headCount(0),
      m_selectedHead(0),
      m_currentPage(0),
      m_baseHeadDrawOffset(0),
      m_previewPane(0),
      m_confirmButton(0),
      m_nextPageButton(0),
      m_prevPageButton(0)
{
    m_previewObject.defaultByte = 0x50;

    if (g_useEpfAssets == 1) {
        PatchHighResHeadOffsets();
    } else {
        PatchNormalHeadOffsets();
    }

    m_dialogSubtype = packet[0];
    m_headPrice = PacketBufferReadUInt32BE(packet + 1);

    if (packet[5] == 2) {
        const_cast<unsigned char *>(packet)[6] = 2;
    }

    const int objectBytes = ObjectStatusBlob::ParseTaggedStatus(&m_previewObject, packet + 6);
    if (objectBytes < 0) {
        return;
    }

    const int *offsetTable = CurrentHeadOffsetTable();
    m_baseHeadDrawOffset =
        static_cast<unsigned char>(m_previewObject.headDrawOffset) -
        offsetTable[m_previewObject.headIndex];

    int pos = objectBytes + 10;
    m_npcId = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    m_objectId = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    packet[pos++];
    packet[pos++];

    const unsigned int messageLength = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    char messageText[32768];
    wchar_t wideMessageText[32768];

    CopyBytes(messageText, packet + pos, messageLength);
    if (messageLength >= sizeof(messageText)) {
        ReportRangeCheckFailure();
    }
    messageText[messageLength] = 0;

    const unsigned int wideLength = MultiByteToWideChar(
        0,
        0,
        messageText,
        messageLength,
        wideMessageText,
        32768);
    if (wideLength >= 32768) {
        ReportRangeCheckFailure();
    }
    wideMessageText[wideLength] = 0;

    m_headCount = g_pNewHumanImageLib->GetHeadCount();
    m_selectedHead = m_previewObject.headIndex;
    if (m_selectedHead >= m_headCount) {
        m_selectedHead = m_headCount - 1;
    }
    if (m_selectedHead < 0) {
        m_selectedHead = 0;
    }

    m_currentPage = m_selectedHead / kHeadsPerPage;

    AddControl(new EPFImageControlPane(
        L"DLGMSGH.EPF",
        0,
        true,
        RectBounds(0, 0, 374, 316),
        L"NPAL8.PAL"));

    m_confirmButton = new ImageButtonControlPane(14, BottomButtonRect(0));
    AddControl(m_confirmButton);

    m_prevPageButton = new ImageButtonControlPane(18, BottomButtonRect(1));
    AddControl(m_prevPageButton);

    m_nextPageButton = new ImageButtonControlPane(19, BottomButtonRect(2));
    AddControl(m_nextPageButton);

    AddControl(new ImageButtonControlPane(15, BottomButtonRect(3)));

    UpdatePageButtonStates();

    m_previewPane = new ObjectImageControlPane(&m_previewObject, PreviewRect());
    AddControl(m_previewPane);

    AddControl(new StaticTextControlPane(
        wideMessageText,
        true,
        128,
        143,
        RectBounds(86, 29, 336, 92),
        false,
        0));

    for (int i = 0; i < kHeadButtonCount; ++i) {
        m_headButtons[i] = 0;
    }

    SetFocusedControl(1);
    SetPendingControl(4);
    SetBackgroundResource(L"DLGMSGH.EPF", 0);
    OnShow(0, 0);

    PopulateHeadButtons(m_currentPage, false);
}

HeadSelectDialog::~HeadSelectDialog()
{
    OnDialogDestroying();
    RemoveDialogControls();
}

void HeadSelectDialog::RefreshHeadPreview()
{
    ObjectImageControlPane *oldPreview = m_previewPane;
    const int *offsetTable = CurrentHeadOffsetTable();

    m_previewObject.headIndex = static_cast<unsigned short>(m_selectedHead);
    m_previewObject.headDrawOffset = static_cast<unsigned char>(
        m_baseHeadDrawOffset + LowSignedByte(offsetTable[m_selectedHead]));

    m_previewPane = new ObjectImageControlPane(&m_previewObject, PreviewRect());
    m_controlManager->SlotForCategory(kPreviewCategorySlot) = m_previewPane;

    DestroyPane(oldPreview);
    Invalidate();
    Repaint(RectBounds(0, 0, 374, 316), 0, 0, g_transparentColor);
}

void HeadSelectDialog::UpdatePageButtonStates()
{
    if (m_currentPage < 1) {
        m_prevPageButton->Disable();
    } else {
        m_prevPageButton->Enable();
    }

    if (m_currentPage >= m_headCount / kHeadsPerPage) {
        m_nextPageButton->Disable();
    } else {
        m_nextPageButton->Enable();
    }
}

void HeadSelectDialog::NextHeadPage()
{
    ++m_currentPage;
    if (m_currentPage * kHeadsPerPage >= m_headCount) {
        --m_currentPage;
    }

    PopulateHeadButtons(m_currentPage, true);
    UpdatePageButtonStates();
}

void HeadSelectDialog::PreviousHeadPage()
{
    --m_currentPage;
    if (m_currentPage < 0) {
        m_currentPage = 0;
    }

    PopulateHeadButtons(m_currentPage, true);
    UpdatePageButtonStates();
}

void HeadSelectDialog::PopulateHeadButtons(int page, bool forceCategorySwitch)
{
    if (forceCategorySwitch && m_controlManager->CurrentCategory() != kHeadButtonCategory) {
        do {
            SwitchControlCategory(kHeadButtonCategory);
        } while (m_controlManager->CurrentCategory() != kHeadButtonCategory);
    }

    const int firstHead = page * kHeadsPerPage;
    const int *offsetTable = CurrentHeadOffsetTable();

    for (int slot = 0; slot < kHeadButtonCount; ++slot) {
        if (m_headButtons[slot] != 0) {
            DestroyPane(m_headButtons[slot]);
            m_headButtons[slot] = 0;
        }

        const int head = firstHead + slot;
        m_previewObject.headIndex = static_cast<unsigned short>(head);
        m_previewObject.headDrawOffset = static_cast<unsigned char>(
            m_baseHeadDrawOffset + LowSignedByte(offsetTable[head]));

        if (head >= m_headCount) {
            break;
        }

        ObjectImageButtonPane *button =
            new ObjectImageButtonPane(&m_previewObject, HeadButtonRect(slot));
        m_headButtons[slot] = button;

        if (head == m_selectedHead) {
            button->SetButtonHighlight(true);
        }

        AddControl(button);
    }

    Invalidate();
    Repaint(RectBounds(0, 0, 374, 316), 0, 0, g_transparentColor);
}

void HeadSelectDialog::OnAction(int actionId, int /*unused*/)
{
    switch (actionId) {
    case 1:
    case 4:
        CloseDialog();
        break;

    case 2:
        PreviousHeadPage();
        break;

    case 3:
        NextHeadPage();
        break;

    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        ObjectImageButtonPane *oldButton =
            m_headButtons[m_selectedHead % kHeadsPerPage];
        if (oldButton != 0) {
            oldButton->SetButtonHighlight(false);
        }

        m_selectedHead = actionId + (m_currentPage * kHeadsPerPage) - 7;

        ObjectImageButtonPane *newButton =
            m_headButtons[m_selectedHead % kHeadsPerPage];
        if (newButton != 0) {
            newButton->SetButtonHighlight(true);
        }

        RefreshHeadPreview();
        PopulateHeadButtons(m_currentPage, true);
        break;
    }

    default:
        break;
    }
}
```

## Exact Supervisor Changes Required

Apply these changes only in supervisor-owned docs; Agent-B001 did not edit the by-* docs or coverage report.

1. In [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md), replace metadata values:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. In [UID:0001FI], populate `RECONSTRUCTION_CPP CODE` with the first-draft C++ from this report, adjusted only for local project type names. Keep `CANONICAL_OWNER:000062`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000062`.

3. In [UID:0001FI] `## Status`, replace the current confidence/final-C++ gate bullets:

```text
- Confidence: strong for boundaries, class owner, constructor entry path, vtable relationships, and high-level dialog behavior; medium-high for final packet field names and static layout-table structure.
- Autogen parent: [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md), which is `86/87` and satisfies the strict parent gate for this `84/86` memory page.
- Final C++ gate: keep `RECONSTRUCTION_CPP CODE` blank until packet field names, layout-table struct shape, child control member names, and destructor/thunk representation are final-source quality.
```

with:

```text
- Confidence: strong for boundaries, class owner, constructor wrapper path, vtable relationships, packet parsing, child-control roles, layout-table shape, destructor/thunk split, and source-ready behavior; exact original names for several retained packet fields remain high-probability inferences.
- Autogen parent: [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md), which is `86/87` and satisfies the strict parent gate for this `87/89` memory page.
- Final C++ gate: cleared. Populate formal C++ with source-facing `HeadSelectDialog` constructor/destructor, preview refresh, page-state helpers, private previous/next page helpers, button population, and `OnAction`; keep compiler adjustor/scalar deleting destructor support in [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md).
```

4. In [UID:0001FI] `## Functions`, replace the entire table with:

```text
| Range | Function | Notes |
| --- | --- | --- |
| `0x00551030-0x005511fd` | `HeadSelectDialog::RefreshHeadPreview()` | Recomputes the selected head object-status fields, rebuilds the object-image preview pane, replaces category slot `5`, deletes the previous preview, invalidates, and repaints the dialog. |
| `0x00551200-0x0055124d` | `HeadSelectDialog::UpdatePageButtonStates()` | Enables/disables previous and next page buttons from `m_currentPage` and `m_headCount`. |
| `0x00551250-0x005512c7` | `HeadSelectDialog::NextHeadPage()` | Private retained helper: increments current page, clamps against `m_headCount`, repopulates buttons with category switch forced, and refreshes page-button state. No exported caller/vtable ref found in local exports. |
| `0x005512d0-0x00551340` | `HeadSelectDialog::PreviousHeadPage()` | Private retained helper: decrements current page, clamps to zero, repopulates buttons with category switch forced, and refreshes page-button state. No exported caller/vtable ref found in local exports. |
| `0x00551350-0x00551510` | `HeadSelectDialog::PopulateHeadButtons(int page, bool forceCategorySwitch)` | Optionally switches to dialog/control category `7`, deletes old head buttons, creates up to ten object-image buttons, highlights the selected head, invalidates, and repaints. |
| `0x00551520-0x00551f25` | `HeadSelectDialog::HeadSelectDialog(const unsigned char *packet)` | Parses packet subtype/price/object-status/NPC/object/message data, patches normal/high EPF head-offset table tails, creates background/image-button/preview/static-text controls, initializes page state, and populates the initial head page. |
| `0x00551f30-0x00551f91` | `HeadSelectDialog::~HeadSelectDialog()` | Ordinary destructor body; dialog unregister/cleanup. Adjustor thunks and scalar deleting destructor are covered by [UID:0001FL]. |
| `0x00551fa0-0x005520e5` | `HeadSelectDialog::OnAction(int actionId, int unused)` | `RET 0x8` virtual action handler. Closes on action ids `1`/`4`, pages on `2`/`3`, and selects head slots on `7..16`, then refreshes preview/buttons. |
```

5. In [UID:0001FI] `## Evidence Notes`, add these bullets after the existing function-start evidence:

```text
- 2026-06-18 Agent-B001 source-quality pass: local function exports also identify real non-thunk starts at `0x00551250` and `0x005512d0`. Their bodies are private next/previous page helpers that call `PopulateHeadButtons(page, true)` and refresh previous/next button enable state. `rg` over exported vtable/OOAnalyzer data found no address references to those helper starts, while `OnAction` contains equivalent page-change logic inline.
- `OnAction` disassembly uses `RET 0x8`, so the source-facing virtual signature has two stack arguments even though only the action id is used.
- Constructor packet field inference is now source-ready: byte `0` is a retained dialog subtype, bytes `1..4` are a big-endian `m_headPrice` scalar, byte `5` can force object-status tag byte `6` to mode `2`, `packet+6` is parsed into the 68-byte `ObjectStatusBlob` at `+0x278`, two big-endian words after the object-status block are best named `m_npcId` and `m_objectId`, two following flag bytes are read/discarded, and the remaining length-prefixed ANSI message is converted to wide text for `StaticTextControlPane`.
- The normal table at `0x0066df00` should be documented as `s_normalHeadVerticalOffsets[904]`; the high/current EPF table at `0x0066eea0` should be documented as `s_highResHeadVerticalOffsets[913]`. Both are dword/int tables; refresh/populate use the low byte for the object-status draw-offset byte, while the constructor subtracts the full dword entry to compute `m_baseHeadDrawOffset`.
```

6. In [UID:0001FI] `## Dialog And Data Dependencies`, append this paragraph:

```text
Use `g_useEpfAssets` as the source-facing name for `byte_66DA97`: `g_useEpfAssets == 1` selects the high/current EPF branch, taller preview rectangle `(36,40,73,95)`, high-resolution bottom button rectangles, and `s_highResHeadVerticalOffsets`; any other value selects the normal/legacy branch, preview rectangle `(36,40,71,88)`, normal bottom button rectangles, and `s_normalHeadVerticalOffsets`.
```

7. In [UID:0001FI] `## Score Rationale`, replace the current paragraph:

```text
The page is scored `84/86` because it now documents the exact executable range, method map, class/file ownership, constructor dispatch path, destructor-thunk relationship, vtable/read-only-data ties, static layout-table dependencies, neighboring switch-table boundary, and final-C++ caveats. It remains below final-audit quality because the constructor packet layout, member names, static table struct/index names, and source-level cleanup representation still need a focused rewrite pass.
```

with:

```text
The page is scored `87/89` because the focused source-quality pass resolves the constructor packet layout, source-facing member/control roles, normal/high head-offset table structure, `g_useEpfAssets` branch semantics, shared category-switch dependency, omitted private page-helper starts at `0x00551250` and `0x005512d0`, destructor/thunk representation, and formal C++ readiness. Confidence remains below final-perfect naming because exact original names for the retained packet fields and private page helpers are inferred from behavior rather than proven by symbols or downstream reads.
```

8. In [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md), update the method-family table by inserting these rows after `UpdatePageButtonStates`:

```text
| `0x00551250-0x005512c7` | `NextHeadPage` | Private retained helper for next-page navigation; no exported caller/vtable ref found, while `OnAction` duplicates equivalent logic inline. |
| `0x005512d0-0x00551340` | `PreviousHeadPage` | Private retained helper for previous-page navigation; no exported caller/vtable ref found, while `OnAction` duplicates equivalent logic inline. |
```

Also replace the class status confidence bullet:

```text
- Confidence: strong for class responsibility, vtable/read-only data, core boundaries, constructor-wrapper path, and resource/layout ownership; medium-high for final member names and static layout-table structure.
```

with:

```text
- Confidence: strong for class responsibility, vtable/read-only data, core boundaries, constructor-wrapper path, resource/layout ownership, source-ready method behavior, and destructor/thunk split; exact original names for retained packet fields and private page helpers remain behavior-based inferences.
```

Optional class metadata update if supervisor wants aggregate scores to reflect this target:

```text
COMPLETION:87
CONFIDENCE:88
```

9. In [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md), update the function map by inserting the same two rows after `UpdatePageButtonStates`:

```text
| `0x00551250-0x005512c7` | `NextHeadPage` | Private retained next-page helper; increments/clamps page, repopulates head buttons, and refreshes page-button state. |
| `0x005512d0-0x00551340` | `PreviousHeadPage` | Private retained previous-page helper; decrements/clamps page, repopulates head buttons, and refreshes page-button state. |
```

Optional file metadata update if supervisor wants aggregate scores to reflect the resolved C++ gate:

```text
COMPLETION:88
CONFIDENCE:88
```

10. Do not change [UID:00012T][DialogCategorySwitch] ownership from the evidence in this pass. It remains a shared dialog/control-list helper. If text is added to [UID:00012T], add only:

```text
2026-06-18 Agent-B001 HeadSelect review validates the shared-helper caveat: `HeadSelectDialog::PopulateHeadButtons` uses this helper only to force category `7` before rebuilding the head-button grid, while direct callers outside HeadSelect still prevent private HeadSelect ownership.
```

11. Do not create a separate by-memory page for `0x00551250` or `0x005512d0`. They sit inside the existing [UID:0001FI] range and should be added to that page's function table.

## Coverage Report Replacement Text

Do not edit `by-memory/-coverage-report.md` directly from Agent-B001. Supervisor should replace the current [UID:0001FI] row at `by-memory/-coverage-report.md` line 2643, between the `0x00551021-0x00551030` padding row and the `0x005520e5-0x00552110` switch/padding row.

Current row:

```text
    - [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md) 0x00551030-0x005520e5 | class method cluster | HeadSelectDialogCore : reconstructable : 84% : strong : HeadSelectDialog main method cluster attached to class parent; documents source-authored preview/page/action/constructor/destructor methods, dispatcher allocation path, layout-table and read-only-data dependencies, switch-table boundary, and final-C++ deferral.
```

Replacement row:

```text
    - [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md) 0x00551030-0x005520e5 | class method cluster | HeadSelectDialogCore : reconstructable : 87% : strong : HeadSelectDialog main method cluster attached to class parent; resolves source-authored preview/page/action/constructor/destructor behavior, private next/previous page helper starts at `0x00551250` and `0x005512d0`, packet-derived price/NPC/object/message fields, object-status preview payload ownership, high/normal head-offset tables selected by `g_useEpfAssets`, shared DialogPane category-switch dependency, destructor/thunk split, and formal C++ readiness.
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001FI-HeadSelectDialogCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001FI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
