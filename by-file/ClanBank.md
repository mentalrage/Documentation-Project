*** UID:0000I9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ClanBank

## Status

- Confidence: strong for local bank/item dialog classes, packet senders, `g_pClanBankPane` lifecycle ownership, vtable/resource separation, and current raw-start reachability checks; medium-high for exact original file split between bank pane, item deposit/withdraw dialogs, and shared text helpers.
- Proposed module folder: `social/`
- Proposed source file: `social/ClanBank.cpp`
- Possible split file: `social/ClanItemDialogs.cpp`
- Evidence basis: current documentation plus live IDA MCP and PE reachability checks. Historical generated/imported source names are retained only as provenance; current ownership confidence is based on IDA boundaries, xrefs, resources, globals, and byte-level reachability.

## Hypothesis

The clan bank and item deposit/withdraw dialogs are probably a companion Clan feature translation unit, not independent one-class files. The cluster is physically compact from raw constructor-shaped bytes at `0x0048a0c0` through `0x0048c251`, shares opcode `0x4b`/`0x36` clan-bank packet shapes, uses the same `DL`/`DL_15`/`cl` dialog resources, and is tied together by `ClanItemDialog`, `ClanItemListPane`, `ClanBankPane`, and `ClanBankItemListPane`.

Keep this as a likely `ClanBank.cpp` split from [UID:0000I8][Clan](by-file/Clan.md) unless later xref evidence shows the original source kept every clan dialog in one larger `Clan.cpp`.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ClanItemDialog` | raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md), vtable reset [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md), confirm-button state updater [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md), destructor `0x0048c470` | `class_ClanItemDialog.cpp` | Shared item-selection dialog base; validates selected item plus quantity/text before enabling confirmation. |
| `ClanDepItemDialog` | `0x0048a1c0-0x0048a805`, animation `0x0049ec80` | `class_ClanDepItemDialog.cpp` | Deposit-item dialog; parses packet text, builds item/amount UI, sends opcode `0x4b` subtype `5`. |
| `ClanWidItemDialog` | `0x0048a810-0x0048ae65` | `class_ClanWidItemDialog.cpp` | Withdraw-item dialog; parses title/detail/list payload, builds item/quantity UI, sends opcode `0x4b` subtype `12`. |
| `ClanItemListPane` | `0x0048ae70-0x0048b1b1`, destructor `0x0048c510`; uses shared text helpers [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) as dependencies | `class_ClanItemListPane.cpp` | Scrollable item list for clan item dialogs, including icon rendering and width-limited item names. |
| `ClanBankPane` | `0x0048b1c0-0x0048b7dc`, raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md), destructor `0x0048c410`, animation `0x0049ed60` | `class_ClanBankPane.cpp` | Main clan bank dialog, mode switch between item/gold bank, close/submit packet handling, singleton `g_pClanBankPane`. |
| `ClanBankItemListPane` | `0x0048b8c0-0x0048c251`, destructor `0x0048c3d0` | `class_ClanBankItemListPane.cpp` | Parses full/update/remove bank inventory packets, sorts display names, draws bank item rows with counts. |

## Boundary And Data Notes

- B014 2026-06-22 direct PE recheck corrects [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md): `0x0048c260-0x0048c26b` is compiler cleanup support that clears `g_pClanBankPane`, while the actual generated destructor adjustor thunks begin at `0x0048c27b`. The `0x0048c4d0-0x0048c50b` scalar-deleting destructor wrapper is shared compact/TextEdit/ListPane support, not a ClanBank item/dialog destructor, so keep it out of ClanBank ownership until a dedicated source-quality pass proves otherwise.
- IDA reports no function at Wave3's projected `ClanItemDialog::ClanItemDialog` start `0x0048a0c0`, but 2026-05-27 IDA byte audit bounded the raw constructor-shaped body as [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md). Use real IDA starts `0x0048a100` and `0x0048a120` for confirmed function anchors, and keep the constructor as a raw byte-range record until reachability is understood.
- Batch 308 routes source-local [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md) here after that child reached `87/92` and this direct parent remained `86/85`. Batch 211 routes [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md), [UID:0003BB][0x00616468-0x00616484.ClanItemDialogResourceString](by-memory/0x00616468-0x00616484.ClanItemDialogResourceString.md), and [UID:0003BA][0x00616484-0x006164f0.ClanBankResourceStrings](by-memory/0x00616484-0x006164f0.ClanBankResourceStrings.md) here after the strict `85/85` parent gate.
- IDA confirms real helper starts at `0x0048a690`, `0x0048acf0`, and `0x0048b600`, but Wave3 does not currently give those small vtable-reset/destructor helper functions clean memory owners.
- `ClanBankItemListPane::AppendEntryString` at `0x00430041` starts one byte after IDA's real [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) and behaves like support code. Do not migrate it into `ClanBank.cpp` from current owner data alone.
- `ClanBankItemListPane::virt_meth_0x4c0043` is excluded in Wave3 and resolves inside IDA function `sub_4BEE40`, a large SIMD bit-manipulation helper with no clan-bank behavior. Treat it as owner pollution, not as a clan method.
- `ClanItemListPane` uses the shared [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) pair at `0x004ba820-0x004ba991` while drawing row names. B001's [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) source-quality recheck and later GrafPort text-helper review keep those helpers GrafPort/shared-text owned because of broad caller fan-in, receiver font/style state, and FontImageLib-backed measurement; do not migrate them into `ClanBank.cpp` or `ClanItemListPane.cpp` from caller evidence alone.
- `ClanDepItemDialog` constructs [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) at `0x0048a50d` to choose a player-owned item for deposit. Do not move `MyItemListPane` into `ClanBank.cpp`; current caller fanout also includes `AddItemDialog` and `MixItemDialog`.
- The `MyItemListPane` dependency consumes [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) for item icon drawing. That is a render-library dependency, not clan-owned image state.
- 2026-06-16 A001 live IDA refresh: `lookup_funcs` still reports no function at raw `0x0048a0c0` or `0x0048b7e0`, while confirmed clan-bank starts remain `0x0048a100` size `0x1f`, `0x0048a120` size `0x9e`, `0x0048a1c0` size `0x4ca`, `0x0048a690` size `0x1f`, `0x0048a810` size `0x4d5`, `0x0048acf0` size `0x1f`, `0x0048ae70` size `0x21c`, `0x0048b1c0` size `0x433`, `0x0048b600` size `0x29`, `0x0048b8c0` size `0x774`, and destructor-band starts through `0x0048c510`.
- The same pass reconfirmed `g_pClanBankPane` at `0x0067ade8` has seven xrefs: constructor writes at `0x0048b224`/`0x0048b22b`, clears at `0x0048b61a`, `0x0048c260`, and `0x0048c430`, and action/open reads at `0x00508706` and `0x00513b07`.
- 2026-07-07 B007 UID0002XK support sync reconfirmed the source/global-storage split for `g_pClanBankPane`: [UID:0002XJ][g_pClanBankPane](by-global/g_pClanBankPane.md) emits the single `ClanBankPane *g_pClanBankPane;` definition through this `ClanBank.cpp` route, while [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md) remains marker-only zero-filled storage evidence. Generated `ClanBank.cpp` should not contain a standalone UID0002XK block or source `dword_67ADE8` symbol.
- Resource evidence still separates the bank/item-dialog resource ownership: `0x00616468` has four xrefs from `ClanDepItemDialog` and `ClanWidItemDialog`, while `0x00616484` is referenced from `ClanBankPane` construction at `0x0048b2ac`.
- Raw-helper reachability was checked beyond IDA xrefs. A section-mapped PE scan found no absolute VA pointers and no direct rel32 call/jump references to `0x0048a0c0`, `0x0048b7e0`, or the internal raw target `0x0048b850`. `xrefs_to 0x0048b850` still only reports the internal raw-code edge at `0x0048b84d`, so the retained packet-helper/raw-constructor caveat is real.
- 2026-06-26 B010 [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) source-quality implementation keeps the ClanBankPane raw opcode `0x36` helper island in this `ClanBank.cpp` source cluster with no split, no owner/emitter change, and blank formal C++. Live MCP session `819053f8-f934-49a3-8cef-6cd17f369ff2` / database `80de0a67` reconfirmed no IDA functions at `0x0048b7e0` or `0x0048b870`, zero xrefs to both starts, no incoming data-flow, only successor `0x0048b8c0` in the local function query, and a unique concrete signature for `0x0048b7e0-0x0048b8bc`. The companion PE scan found no absolute VA, RVA, raw-file-offset, or direct `E8/E9` rel32 route to `0x0048b7e0`, `0x0048b870`, or internal point `0x0048b850`. Packet-layout correction: constructor action `10` writes the `ClanBankPane +0x26c` mode as `0` and yields submit subtype `0x0d`; action `16` writes mode `1` and yields subtype `0x0c`; the selected slot is serialized as a zero-extended `PacketBufferWriteUInt16BE` field, followed by the multi-count flag and UInt32BE amount from the low 16 bits; close remains `0x36/0x0b`. Socket, PacketBuffer, and `g_packetSender` remain support dependencies only, not owners of the feature sender.
- 2026-06-16 B001 Clan opcode helper recheck: [UID:00021J][0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md) mirrors the active `ClanDepItemDialog` subtype `5` action `1` sender, including the `selectedSlotIndex` and amount payload, but remains [UID:0000I8][Clan](by-file/Clan.md)-owned because the raw helper pair is no-route retained code in the contiguous Clan opcode `0x4b` helper strip. Keep the active dialog sender and ClanBank class ownership here; do not move the raw strip to `ClanBank.cpp` without new route/source evidence.
- 2026-06-28 B013 [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md) cross-note: the raw subtype `12` action `1` body mirrors the active `ClanWidItemDialog` withdraw sender, including opcode `0x4b`, subtype `0x0c`, action `1`, item byte, UInt16BE quantity, and send length `6`. The raw helper strip remains [UID:0000I8][Clan](by-file/Clan.md)-owned retained/no-route code with marker-only formal C++; the active [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md) / [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md) behavior remains ClanBank-owned.
- 2026-06-16 B001 [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) source-quality placement note: keep [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) under ClanBank/source UID `0000I9` for now. A later `ClanItemDialogs.cpp` split remains plausible, but current evidence ties the pane to the bank withdraw dialog and auto-generated route `NexusTK/social/ClanBank.cpp`; do not move it to [UID:0000I8][Clan](by-file/Clan.md) without new source-route evidence.
- 2026-06-17 B002 source-quality pass corrects [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md) to `ClanItemDialog::UpdateConfirmButtonState()`. The method is a ClanBank-owned UI state updater, not a Clan opcode submitter; actual deposit/withdraw packet actions stay in derived ClanBank item-dialog paths.
- 2026-06-30 B009 empty-emitter implementation callback: accepted report `0000I9-ClanBank-empty-emitter-family-source-quality.md` resolves the generated ClanBank empty-emitter family at report-level detail. Pre-callback generated output was `17` emitters, `2` filled (`0002OB`, `00010P`), and `15` empty (`000025`, `000026`, `000029`, `00002F`, `00021X`, `0002OC`, `00002G`, `00010Q`, `0002XJ`, `0002XK`, `00010O`, `00010R`, `00021Y`, `00010S`, `0002MO`). The accepted callback adds declaration-level class shells with `[[CHILDREN]]` for the five class pages, first-draft formal C++ for the four source-authored method clusters, a real `ClanBankPane *g_pClanBankPane;` declaration, marker-only no-code proof for raw/destructor/helper/storage/vtable pages, and a zero-filled virtual `.data` correction for [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md). MCP provenance remains `supervisor_resume_20260629` with current function/raw/data checks: modeled method starts at `0x0048a1c0`, `0x0048ae70`, `0x0048b1c0`, and `0x0048b8c0`; no function/xref/pointer route for raw starts `0x0048a0c0`, `0x0048b090`, `0x0048b7e0`, or `0x0048b870`; seven singleton xrefs at `0x0067ade8`; and vtable compiler-layout evidence at `0x00615fd8-0x006163dc`. This raises the file score to `90/89`; path `"NexusTK/social/"` and file owner state remain unchanged. Generated files and coverage/tracker rows were not manually edited; validators with `--wait-generated` are expected to refresh `auto-generated/NexusTK/social/ClanBank.cpp` to `17/17/0` with zero ClanBank empty markers.

## Migration Notes

Recommended migration order:

```powershell
python source-3\wave3.py create file ClanBank.cpp --kind source --simpath social/ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanBankPane --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanBankItemListPane --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanItemDialog --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanItemListPane --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanDepItemDialog --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanWidItemDialog --to-file ClanBank.cpp --dry-run
```

Before non-dry-run ownership changes, exclude or re-own the outlier `0x00430041` and `0x004c0043` records and decide whether text fitting at `0x004ba820-0x004ba991` stays with clan item lists or moves to a shared text helper file.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md)
- [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:000026][ClanBankPane](by-class/ClanBankPane.md)
- [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md)
- [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md)
- [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md)
- [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md)
- [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md)
- [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md)
- [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md)
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)
- [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:00012V][0x0049ec80-0x0049ee42.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee42.ClanDialogSlideAnimation.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md)
- [UID:0003BB][0x00616468-0x00616484.ClanItemDialogResourceString](by-memory/0x00616468-0x00616484.ClanItemDialogResourceString.md)
- [UID:0003BA][0x00616484-0x006164f0.ClanBankResourceStrings](by-memory/0x00616484-0x006164f0.ClanBankResourceStrings.md)

## Changes

- 2026-06-30 B009 empty-emitter implementation callback:
  - Scores raised from `87/87` to `90/89` after accepted report implementation resolved all 15 current empty emitters without changing `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"` or `CANONICAL_OWNER:FILE`.
  - Preserved rejected alternatives: no broad monolithic by-file C++, no route-comment-only class shells, no marker-only method aggregate deferral for modeled source-authored functions, no new child split in this callback, no callable raw-helper bodies, no duplicate global definition, no hand-written raw vtable arrays, no source split to `ClanItemDialogs.cpp`, and no manual generated/coverage/tracker edits.
  - Score cap remains the unresolved final `ClanBank.cpp` versus possible `ClanItemDialogs.cpp` split plus best-current inferred field/control/ListPane/helper names; these are now confidence caps, not implementation blockers.
- 2026-06-28 B013 [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md) cross-note:
  - Recorded that raw subtype `12` action `1` mirrors the active ClanBank-owned `ClanWidItemDialog` withdraw sender but stays [UID:0000I8][Clan](by-file/Clan.md)-owned because current MCP finds no route to the raw helper strip.
  - Scope: no score, path, owner, or emitter change for this ClanBank page.
- 2026-06-26 B010 [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) support sync:
  - Preserved `ClanBank.cpp` ownership for the raw ClanBankPane opcode `0x36` helper island and recorded the accepted no-split/no-C++ decision.
  - Added live MCP and PE no-route proof for `0x0048b7e0`, `0x0048b870`, and internal `0x0048b850`.
  - Corrected packet layout to selected-slot UInt16BE, multi-count flag, UInt32BE amount, mode `10 -> 0 -> 0x0d`, mode `16 -> 1 -> 0x0c`, and close `0x36/0x0b`.
- 2026-06-22 B014 ClanDestructorBand source-routing support sync:
  - Added the corrected cleanup/thunk/wrapper routing for the physical destructor band. `0x0048c260` clears `g_pClanBankPane` as cleanup support, not a source method; `0x0048c4d0-0x0048c50b` is no longer treated as ClanBank-owned.
  - Evidence: direct PE byte review in [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md). Scores and owner/emitter remain unchanged.
- 2026-07-07 B007 UID0002XK implementation support sync:
  - Added the accepted source/global-storage split note for `g_pClanBankPane`, including parent-only `ClanBankPane *g_pClanBankPane;` emission, marker-only [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md) storage, and no generated/source `dword_67ADE8`. Metadata and formal C++ unchanged.
- 2026-06-16 A001 low-confidence file refresh:
  - Scores raised from `86/85` to `87/87`.
  - Evidence: live IDA MCP reconfirmed the clan-bank/item-dialog function sizes, raw constructor and raw packet-helper non-function status, `g_pClanBankPane` seven-ref lifecycle/action set, resource string xrefs, and PE no-pointer/no-rel32 reachability for the raw starts.
  - Remaining blockers: final `ClanBank.cpp` versus `ClanItemDialogs.cpp` source split and the shared text-fitting helper placement remain source-facing questions, so no final C++ or path/owner metadata change was made.
- 2026-06-16 B001 Clan opcode helper source-quality cross-note:
  - [UID:00021J][0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md) was raised to `85/89` as a Clan-owned retained/no-route helper strip, not moved here.
  - Evidence: the active [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md) sender remains ClanBank-owned, while the raw helper has no IDA function/xref route or PE exact-start pointer/rel32 route and is physically inside the Clan opcode helper strip.
- 2026-06-16 B001 [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) source-quality placement note:
  - [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) remains in the ClanBank/item-dialog cluster after row-layout and selected-slot reanalysis; no file score or path change.
- 2026-06-12 A004 Batch 308 source-local vtable split:
  - Scores remain `86/85`; [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md) now routes here after the strict child/parent `85/85` gate.
  - Evidence: live IDA MCP reconfirmed the clan-bank/item-dialog vtable names, the `0x00615fd8-0x006163dc` boundary, representative stores for `ClanItemDialog`, `ClanBankPane`, and `ClanBankItemListPane`, and the UTF-16 `CLAN1.EPF` successor at `0x006163dc`.
- 2026-06-11 A002 Batch 211 vtable/resource parent refresh:
  - Scores remain `86/85`; [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md), [UID:0003BB][0x00616468-0x00616484.ClanItemDialogResourceString](by-memory/0x00616468-0x00616484.ClanItemDialogResourceString.md), and [UID:0003BA][0x00616484-0x006164f0.ClanBankResourceStrings](by-memory/0x00616484-0x006164f0.ClanBankResourceStrings.md) are now assigned here after the strict child/parent `85/85` gate.
  - Evidence: live IDA MCP reconfirmed the `0x00615fd8-0x006163dc` bank/item-dialog vtable block, `DLGCLAN3.EPF` xrefs from item-dialog code, and `CLANBAN1.*` plus display-format xrefs from `ClanBankPane`/`ClanBankItemListPane`.
- 2026-05-27: Changed the `ClanItemDialog` constructor note from an unresolved projected start to bounded raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md), and moved the bank/item cluster's lower evidence boundary from `0x0048a100` to `0x0048a0c0`. Evidence: IDA MCP reports no function at `0x0048a0c0`, but byte audit shows constructor-shaped code that calls `0x0049d8a0`, installs `ClanItemDialog` vtables, and ends before padding at `0x0048a0fb-0x0048a100`.
- 2026-05-27: Corrected `ClanItemListPane` range from `0x0048ae70-0x0048b1b0` to `0x0048ae70-0x0048b1b1`. Evidence: IDA MCP reports `sub_48B0A0` at `0x0048b0a0-0x0048b1b1`, with `0x0048b1b1-0x0048b1c0` padding before `ClanBankPane`.
- 2026-05-27: Corrected `ClanBankPane` range from `0x0048b1c0-0x0048b7db` to `0x0048b1c0-0x0048b7dc` and added raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md). Evidence: IDA MCP reports `sub_48B630` ending at `0x0048b7dc`, followed by two helper-shaped opcode `0x36` packet bodies and padding before `ClanBankItemListPane`.
- 2026-05-27: Corrected `ClanBankItemListPane` from `0x0048b8c0-0x0048c250` to `0x0048b8c0-0x0048c251`. Evidence: IDA MCP reports `sub_48C040` through `0x0048c251`, then alignment padding before the destructor band.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: clan bank pane, item dialogs, item lists, packet helpers, outlier records, dependencies, migration order, and boundary corrections are documented; confidence is held at 80 because the final split between `ClanBank.cpp`, item-dialog code, and shared text helpers is still provisional.
- 2026-05-31: Updated `ClanItemDialog` contents after the core-method split.
  - What existed before: the proposed contents table listed real helpers only as raw addresses `0x0048a100` and `0x0048a120`.
  - Changed to: linked exact child pages [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md) and [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md).
  - Summary/evidence: IDA MCP verified both ranges and showed the confirm path calls reusable [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md), so the bank source owns the dialog behavior but not the text-control helper.
- 2026-06-02: Filled the validator projected path from the page's own source-layout evidence.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the status and hypothesis sections already place the likely source as `social/ClanBank.cpp`.
  - After: projected path is `NexusTK/social/`, matching sibling [UID:0000I8][Clan](by-file/Clan.md) and the documented `social/ClanBank.cpp` split.
  - Evidence: the proposed contents and migration notes keep `ClanBankPane`, `ClanBankItemListPane`, clan item dialogs, and raw bank packet helpers together under the clan-bank social module.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Raised confidence from `80` to `85`.
  - Evidence: the `0x0067ade8` slot has been isolated from [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) as `g_pClanBankPane`; constructor writes, destructor-family clears, and clan-bank UI action reads all stay inside the documented `ClanBankPane`/`ClanBank.cpp` owner family, clearing the direct-parent gate for the exact singleton global.
