** TARGET-REPORT-UID:00010P **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00010P ClanWidItemDialog Empty-Emitter Source-Quality Report

Assignment: `B008-report-00010P-ClanWidItemDialog-empty-emitter-source-quality-20260628`

Target: [UID:00010P] `by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md`

Report mode: report-only. No by-* documentation was edited, no leases were taken, no generated files or validator/tool state were edited, and no IDA database/process management was performed.

## Disposition

This is active source code and should not remain a nonblank emitter with blank formal C++. The correct disposition is to keep the by-memory target routed to [UID:0000I9] `ClanBank` and insert nonblank formal C++ for the constructor, action handler, and withdraw packet sender. The vtable-reset/destructor-tail helper inside the binary range is generated class teardown support and should not be emitted as handwritten source.

The companion `by-class/ClanWidItemDialog.md` support page also currently creates an empty-emitter marker if it remains `EMITTER_UIDS:0000I9` with blank C++. The implementation pass should either clear that class page's `EMITTER_UIDS:` while leaving the by-memory target as the emitting code owner, or add a real class declaration/`[[CHILDREN]]` container if that pass is specifically prepared to own class declarations. For this implementation, clearing the support class emitter is the lower-risk repair because the exact method bodies emit directly from [UID:00010P].

## Current State

`by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md` currently has:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000I9`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000I9`
- blank formal C++

The covered binary range contains:

- `0x0048a810-0x0048ace5`: `ClanWidItemDialog` constructor.
- `0x0048acf0-0x0048ad0f`: vtable reset plus jump to shared base cleanup tail.
- `0x0048ad10-0x0048ade9`: dialog action handler.
- `0x0048adf0-0x0048ae65`: withdraw packet sender.
- `0x0048ae65-0x0048ae70`: padding before `ClanItemListPane`.

The empty-emitter blocker is therefore not a no-code case. The target has enough current evidence for a first formal source reconstruction.

## MCP Evidence

Current IDA MCP evidence was gathered from session `supervisor_20260628_resume`.

`idb_list` showed the active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health(database='supervisor_20260628_resume')` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, and ready auto-analysis, Hex-Rays, and strings cache.

Function boundary checks:

- `lookup_funcs 0x0048a810`: `sub_48A810`, size `0x4d5`.
- `lookup_funcs 0x0048acf0`: `sub_48ACF0`, size `0x1f`.
- `lookup_funcs 0x0048ad10`: `sub_48AD10`, size `0xd9`.
- `lookup_funcs 0x0048adf0`: `sub_48ADF0`, size `0x75`.
- `lookup_funcs 0x0048ae65`: no function.
- `lookup_funcs 0x0048ae70`: `sub_48AE70`, size `0x21c`.

Xref checks:

- `xrefs_to 0x0048a810`: code callers at `0x004853fa` and `0x0048857b`, matching the clan packet/open-dialog paths.
- `xrefs_to 0x0048acf0`: no direct xrefs to the helper start.
- `xrefs_to 0x0048ad10`: vtable data xref at `0x00616164`.
- `xrefs_to 0x0048adf0`: vtable data xref at `0x00616178`.
- `xrefs_to 0x0048ae70`: constructor call at `0x0048ab68` from `ClanWidItemDialog`.
- `xrefs_to 0x0049ec80`: includes `0x0048acbb`, proving this target calls shared horizontal slide-open logic.
- `xrefs_to 0x0049ed60`: includes `0x0048adcc`, proving this target calls shared horizontal slide-close logic.

Pointer and boundary checks:

- `find_bytes 10 AD 48 00`: vtable pointer at `0x00616164`.
- `find_bytes F0 AD 48 00`: vtable pointer at `0x00616178`.
- `find_bytes 10 A8 48 00`, `F0 AC 48 00`, and `70 AE 48 00`: no direct table pointers found for the constructor, reset helper, or child list pane constructor.
- `get_bytes 0x0048ae60`: `e5 5d c2 08 00` followed by `cc` padding through `0x0048ae6f`, then the next function begins at `0x0048ae70`.
- `get_bytes 0x0048acf0`: vtable writes to `0x00615fdc`, `0x00616040`, `0x00616070`, then a tail jump to shared cleanup.
- `get_bytes 0x00616468`: UTF-16 resource bytes decode as `DLGCLAN3.EPF` followed by `CLANBAN1...`, matching the dialog background and bank resource cluster.

Decompilation checks:

- `0x0048a810` constructs the dialog, parses two length-prefixed ANSI strings from the incoming packet, converts both to wide strings with `MultiByteToWideChar(CP_ACP, ...)`, creates `DLGCLAN3.EPF`, OK/cancel image buttons, two static labels, a `ClanItemListPane`, a scroll/list wrapper, a quantity text edit, then selects control `5`, focuses `1`, sets cancel `2`, sets the dialog rectangle `Rect(212, 12, 433, 300)`, shows the dialog, and calls the shared horizontal slide-open helper with direction/context `0`.
- Disassembly around `0x0048ab68` shows `operator new` size `0x1fd4c`, the remaining item-list payload pointer passed into `sub_48AE70`, and that returned pane passed into the scroll/list wrapper constructor.
- `0x0048ad10` handles control `1` by reading control `5` list selection and control `6` quantity text, validates the selected index against the list count, reads byte zero from the selected row, converts the quantity text with `_wtol`, and dispatches the vtable slot at `+0x5c`. It then closes via the shared horizontal slide-close helper and `CloseDialog`. Control `2` closes without sending. Other controls return.
- `0x0048adf0` writes packet bytes `0x4b`, `0x0c`, `1`, selected row byte, and a big-endian 16-bit quantity, stores a scratch terminator after the six transmitted bytes, and calls `QueueAndSendPacket(g_packetSender, packet, 6)`.

`make_signature_for_range(0x0048a810,0x0048ae65)` returned a unique range signature.

## Local Documentation Evidence

Relevant local docs were checked as support, not as a replacement for MCP:

- `by-file/ClanBank.md` already owns this target through [UID:0000I9] and identifies it as the withdraw-item dialog using opcode `0x4b`, subtype `12`.
- `by-file/Clan.md` treats related raw subtype 11-13 helpers as clan packet-helper remnants, while active bank/item dialogs remain `ClanBank.cpp` owned.
- `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md` shows the sibling deposit dialog shape and the same old blank-C++ blocker pattern.
- `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md` establishes the child list pane row layout and the first-byte selected slot index consumed by this target.
- `by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md` provides already-emitted source for shared control IDs: confirm button `1`, item/list control `5`, quantity edit `6`, `m_embeddedListPane`, `m_selectedIndex`, and `ReadText(..., 0x7f)`.
- `by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md` now owns the shared slide helpers, so this target should call `SlideOpenHorizontal` and `SlideCloseHorizontal` but should not duplicate their implementation.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md` supports the packet helper names and big-endian 16-bit quantity write.
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` and `by-global/g_packetSender.md` support the send route and global socket sender.
- Prior accepted research for the raw helper strip [UID:00021M] confirms that the raw subtype `12` action `1` helper mirrors this packet sender but is not the active source owner.

## Heuristic And Inference Reanalysis

Ownership: keep [UID:0000I9] `ClanBank`. The constructor is opened by clan dialog/packet paths, but the UI and packet semantics are clan-bank item withdraw behavior. The by-file ownership notes already route active deposit/withdraw item dialogs to `ClanBank.cpp`, and the raw clan packet-helper mirror is separately documented as a no-route retained strip.

Emitter disposition: keep `EMITTER_UIDS:0000I9` on the by-memory target and fill formal C++. Clearing the target emitter would hide active source code and leave the generated output missing a live UI class. Leaving the target emitter with blank C++ preserves the empty-emitter marker and should be rejected.

Class support disposition: `by-class/ClanWidItemDialog.md` should not keep a nonblank emitter with blank formal C++. Unless a class declaration pass is being performed, clear that support page's `EMITTER_UIDS:` and document it as a non-emitting class index whose exact method bodies currently emit from [UID:00010P].

Range disposition: no split is required for the implementation pass. The by-memory target range is coherent: constructor, action virtual, packet virtual, generated destructor support, and end padding. The generated destructor tail is covered by the class model and should be explained in notes, not emitted as manual C++.

Control IDs: ID `1` is the confirm/OK button, `2` is cancel, `5` is the embedded list control, and `6` is the quantity text edit. These IDs are independently supported by the shared confirm-validation formal source and by the constructor/action decompilation.

Selected-row byte: the sender parameter should be named `slotIndex`, not `itemType`. The active action handler reads the first byte of the selected `ClanItemListPane` row. The child pane report identifies that first byte as the clan-bank slot index.

Virtual slot naming: the action handler dispatches through the class vtable slot at `+0x5c`, and `0x0048adf0` is installed in the same class vtable. Naming the virtual as `SendWithdrawRequestPacket` is justified by packet opcode/subtype and sender behavior.

Slide helper placement: shared slide logic belongs to [UID:00012U] `DialogPaneSlideAnimation`. This target should contain calls only.

Source placement alternatives: a future `ClanItemDialogs.cpp` split is plausible, but current ownership and emitted source route use `social/ClanBank.cpp`. This report should not force a split/container repair to solve a local empty-emitter marker.

## Rejected Alternatives

Rejected: leave `EMITTER_UIDS:0000I9` with blank C++. That is the current empty-emitter defect.

Rejected: clear the by-memory target emitter as non-emitting metadata. Current MCP proves active constructor/action/sender code and live vtable entries.

Rejected: move the active code to `Clan.cpp` or the raw [UID:00021M] helper strip. The raw helper mirror is retained low-level packet material, while this target owns the active dialog UI and virtual sender path.

Rejected: duplicate `DialogPane` slide helper code inside this target. MCP xrefs show calls to the shared helpers, and the accepted slide report owns that implementation.

Rejected: emit the destructor reset helper as source-level manual vtable stores. The helper is generated teardown support and has no direct code xrefs.

Rejected: keep the old "item type byte" naming. The selected-row byte is the clan-bank slot index according to the child list-pane row layout and the active action path.

Rejected: split the target range before implementation. The action and sender are vtable members of the same class, and the constructor is the only live creator for the child list pane. The generated destructor helper can be handled with notes rather than a split.

## Formal C++ Insertion Text

Use this exact payload between the existing `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` markers in `by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md`:

```cpp
ClanWidItemDialog::ClanWidItemDialog(const unsigned char *packet)
    : ClanItemDialog()
{
    char textBytes[256];
    wchar_t titleText[256];
    wchar_t detailText[256];

    const unsigned int titleLength = packet[3];
    memmove(textBytes, packet + 4, titleLength);
    textBytes[titleLength] = '\0';

    int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        titleLength,
        titleText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    titleText[wideLength] = L'\0';

    const unsigned char *detailPacket = packet + 4 + titleLength;
    const unsigned int detailLength = detailPacket[0];
    memmove(textBytes, detailPacket + 1, detailLength);
    textBytes[detailLength] = '\0';

    wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        detailLength,
        detailText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    detailText[wideLength] = L'\0';

    const unsigned char *itemListPacket = detailPacket + 1 + detailLength;

    AddControl(new EPFImageControlPane(L"DLGCLAN3.EPF", Rect(0, 0, 221, 288), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(36, 230, 108, 246)));
    AddControl(new ImageButtonControlPane(22, Rect(113, 230, 185, 246)));
    AddControl(new StaticTextControlPane(titleText, true, 128, Rect(27, 50, 195, 70)));
    AddControl(new StaticTextControlPane(detailText, true, 128, Rect(27, 174, 195, 194)));

    ClanItemListPane *itemListPane = new ClanItemListPane(itemListPacket);
    AddControl(new ScrollableControlPane(Rect(27, 72, 195, 168), itemListPane, 0, 0, 0));
    AddControl(new TextEditControlPane(L"", true, 128, Rect(27, 196, 195, 209)));

    SelectControl(5);
    SetFocusedControl(1);
    SetCancelControl(2);
    SetBackgroundResource(L"DLGCLAN3.EPF", 0);
    SetDisplayRect(Rect(212, 12, 433, 300));
    ShowDialog(false);
    SlideOpenHorizontal(0);
}

void ClanWidItemDialog::OnDialogAction(int closeContext, int controlId)
{
    if (controlId == 1) {
        ControlPane *itemListControl = GetChildControl(5);
        TextEditControlPane *quantityEdit =
            static_cast<TextEditControlPane *>(GetChildControl(6));

        wchar_t quantityText[128];
        ListPane *itemList = itemListControl->m_embeddedListPane;
        const int selectedIndex = itemList->m_selectedIndex;

        quantityEdit->ReadText(quantityText, 0x7f);

        if (selectedIndex >= 0 && selectedIndex < itemList->GetEntryCount()) {
            const ClanItemListEntry *entry =
                static_cast<const ClanItemListEntry *>(itemList->GetSelectedEntry());

            SendWithdrawRequestPacket(
                entry->slotIndex,
                static_cast<unsigned short>(_wtol(quantityText)));
        }
    } else if (controlId != 2) {
        return;
    }

    SlideCloseHorizontal(closeContext);
    CloseDialog();
}

void ClanWidItemDialog::SendWithdrawRequestPacket(
    unsigned char slotIndex,
    unsigned short quantity)
{
    unsigned char packet[7];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x0c, packet + 1);
    PacketBufferWriteUInt8(1, packet + 2);
    PacketBufferWriteUInt8(slotIndex, packet + 3);
    PacketBufferWriteUInt16BE(quantity, packet + 4);
    packet[6] = 0;

    QueueAndSendPacket(g_packetSender, packet, 6);
}
```

The destructor-reset helper at `0x0048acf0` should be documented in prose/evidence as generated teardown support for the ordinary class hierarchy. It should not receive a separate source-level function body in this target.

## Metadata Recommendation

For `by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md`:

- Keep `CANONICAL_OWNER:0000I9`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000I9`.
- Raise to `COMPLETION:88`.
- Raise to `CONFIDENCE:91`.
- Update summary/evidence notes to state that current MCP resolved the previous blank-C++ blockers, the child list row byte is a slot index, and the destructor-reset helper is generated teardown support.

For `by-class/ClanWidItemDialog.md`:

- Preferred support repair: clear `EMITTER_UIDS:` while leaving ownership metadata intact, and add a note that the class page is a non-emitting index until a class declaration/`[[CHILDREN]]` container is deliberately authored.
- Alternate support repair only if the implementation pass is prepared to author declarations: keep `EMITTER_UIDS:0000I9` only with a nonblank class declaration/`[[CHILDREN]]` container. Do not keep class emitter plus blank formal C++.

For `by-file/ClanBank.md`:

- No required ownership change. Optional note only: [UID:00010P] now has first-draft formal source for the withdraw-item dialog and should remain the active source route.

## Implementation Tracking Checklist

- [x] Lease `by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md` immediately before editing it. Proof: `python .\tools\leaser\leaser.py B008 lease "by-memory\0x0048a810-0x0048ae65.ClanWidItemDialog.md" "by-class\ClanWidItemDialog.md"` returned `Success` for the by-memory target.
- [x] Insert the exact formal C++ payload above into the target formal block. Proof: the target `RECONSTRUCTION_CPP CODE` block now contains `ClanWidItemDialog::ClanWidItemDialog`, `ClanWidItemDialog::OnDialogAction`, and `ClanWidItemDialog::SendWithdrawRequestPacket` with the accepted `slotIndex` sender code.
- [x] Update target metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000I9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I9`. Proof: target header now has those exact values; validator command `000000005191` recorded completion/confidence/canonical owner/autogen registry updates for UID `00010P`.
- [x] Update target evidence notes for MCP session `supervisor_20260628_resume`, constructor/action/sender behavior, selected `slotIndex`, shared slide helper calls, and generated destructor-reset disposition. Proof: target `IDA MCP Evidence`, `Reconstruction Notes`, `Score Rationale`, and `Changes` sections now include the 2026-06-28 B008 implementation evidence pass, function ranges, behavior, `slotIndex`, [UID:00012U] slide dependency, and generated teardown disposition.
- [x] Lease `by-class/ClanWidItemDialog.md` only if applying the support-page empty-emitter repair. Proof: the same short edit lease command returned `Success` for `by-class\ClanWidItemDialog.md` immediately before edits.
- [x] Preferred support-page fix: clear `EMITTER_UIDS:` on `by-class/ClanWidItemDialog.md` and add a short note that the class page is currently a non-emitting class index while [UID:00010P] emits the method bodies. Proof: class header now has blank `EMITTER_UIDS:` and the `Status`, `Reconstruction Notes`, and `Changes` sections document the non-emitting class-index disposition.
- [x] Do not edit generated files, project-level files, coverage reports, validator/tool state, or IDA DB. Proof: no manual edits were made to those files; generated/project-level/tool side effects were only validator-produced during scoped `--wait-generated` validation, and no IDA MCP/DB write was performed in this implementation callback.
- [x] Run the required validators for the edited docs with generated freshness enabled, using the project workflow's normal validator command for changed files. Proof: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file "by-memory\0x0048a810-0x0048ae65.ClanWidItemDialog.md" --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000005191`, `command_timestamp: 2026-06-28T18:15:25-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`; ran `python .\tools\validator.py --mode file --file "by-class\ClanWidItemDialog.md" --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000005192`, `command_timestamp: 2026-06-28T18:15:58-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Verify generated `auto-generated/NexusTK/social/ClanBank.cpp` no longer contains the empty-emitter marker for [UID:00010P]. Proof: generated file header has `validator-command-id: 000000005192`; `rg -n "00010P|00002N|Empty Emitter Marker|ClanWidItemDialog" auto-generated\NexusTK\social\ClanBank.cpp` shows UID `00010P` method bodies at lines 32, 33, 96, and 125 and no UID `00010P` empty-emitter marker.
- [x] If the class support page was changed, verify generated output no longer contains an empty-emitter marker for `by-class/ClanWidItemDialog.md`. Proof: the same marker check against validator-current `ClanBank.cpp` reports no UID `00002N` line and no `by-class\ClanWidItemDialog.md` empty-emitter marker.
- [x] Release all leases immediately after the validator batch. Proof: `python .\tools\leaser\leaser.py B008 unlease "by-memory\0x0048a810-0x0048ae65.ClanWidItemDialog.md" "by-class\ClanWidItemDialog.md"` returned `Success` for both files; the current lease report contains no B008 rows.
- [x] Do not run `execute_report`; supervisor owns execution. Proof: no `execute_report` command was run; this report remains in `tools/leaser/Agents/Agent-B008/research/`.

Validator note: command `000000005191` reported nonfatal existing validator registry warnings including `missing_ref_uid 0003BB` for a resource page that exists on disk and broad `autogen_registry_stale`/`memory_coverage_metadata_missing_file` rows unrelated to the two edited docs. Per workflow, no validator registry/tool state was hand-edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00010P-ClanWidItemDialog-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/00010P-ClanWidItemDialog-empty-emitter-source-quality.md","timestamp":"2026-06-28T18:19:11","uid":"00010P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
