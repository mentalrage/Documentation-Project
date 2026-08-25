** TARGET-REPORT-UID:00007J **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00007J MailDeleteReplyAlert Class Source-Quality Reanalysis

Agent: B009  
Date: 2026-06-19  
Target: [UID:00007J] `by-class/MailDeleteReplyAlert.md`  
Report-only scope: no by-* documentation files and no coverage report files were edited.

## Executive Decision

- Recommended target metadata: `COMPLETION:88`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000HW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HW`.
- Keep the class-page formal `RECONSTRUCTION_CPP` block blank for this pass. The class hub is source-reconstructable as a route and ownership container, but method-body C++ belongs on exact child by-memory pages. Adding class-page code now would either duplicate child method coverage or require a class declaration whose source-file split, base API names, and generated destructor policy are not fully closed.
- Keep source placement under [UID:0000HW] `BulletinReplyAlerts`. `MailDialogs` is the best alternate private-source placement, but the strongest current evidence still favors the existing shared mail/bulletin alert companion bucket because the mail alert vtables, singleton/global route, constructor-shaped companion bodies, and sibling alert wrappers are interleaved in the `BulletinReplyAlerts` route rather than isolated in the `MailDialogs` method range.
- Best class role: `MailDeleteReplyAlert` is a mail-reply deletion confirmation alert. It has one derived tail byte at `this+0x270`, best source-facing name `m_deleteAllReplies`, which distinguishes "delete selected replies from the current reply list" from "delete one reply id from the previous mail dialog and pop the current dialog".
- Best singleton name: `g_pMailDeleteReplyAlert` at `0x0067adbc`, type `MailDeleteReplyAlert *`.
- Best singleton getter name: `GetMailDeleteReplyAlertSingleton()` as a descriptive documentation name. The exact source spelling is not recovered, but a typed singleton getter is strongly supported by `0x0047e720: mov eax, [0x0067adbc]; ret`.
- Best constructor relationship: `0x0047e6a0-0x0047e6ee` is a real out-of-line constructor-shaped body, but there is no static call, branch, pointer, vtable, or interior-entry route to its start in the checked PE. Live construction is instead visible in inline constructor sequences in `MailListDialog`/`MailDialog` paths. Therefore the raw constructor page should be documented as retained constructor-shaped code with no recovered entry route, not as padding or a confirmed live call target.
- First-draft C++ eligibility:
  - Target class page: no formal C++.
  - `OnConfirmDelete` child page [UID:0002T9] is the strongest method-body candidate for later first-draft C++ once helper names are incorporated on support docs.
  - Raw constructor [UID:0002T7] can receive a reference source shape, but formal child C++ should still be gated by the no-route policy unless the project explicitly accepts constructor-shaped no-entry bodies.
  - Non-deleting destructor/getter [UID:0002T8] is source-explainable, but getter/destructor split and base destructor spelling should be documented before formal emission.
  - Scalar deleting destructor [UID:0002TA] should remain compiler-generated/no formal C++.

## Evidence Checked

Documentation reviewed:

- `by-class/MailDeleteReplyAlert.md`
- `by-file/BulletinReplyAlerts.md`
- `by-file/MailDialogs.md`
- `by-class/MailDialog.md`
- `by-class/DeleteReplyAlert.md`
- `by-class/ListPane.md`
- `by-class/MailListPane.md`
- `by-file/ListPane.md`
- `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md`
- `by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md`
- `by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md`
- `by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md`
- `by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md`
- `by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md`
- `by-memory/0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert.md`
- `by-global/g_pMailDeleteReplyAlert.md`
- `by-type/by-vtable/MailDialogVtableFamily.md`
- `by-type/by-vtable/MailAlertCompanionVtables.md`
- `by-type/by-struct/AlertPaneLayout.md`
- `by-type/by-struct/DialogPaneLayout.md`
- `by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md`
- `by-class/AlertPane.md`
- `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
- `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`
- prior source-split/vtable/destructor reports under `tools/leaser/Agents/*/research` that mention mail dialog alert companions.

Binary evidence checked against `E:\NTK\Resources\NexusTK\NexusTK.exe`:

- MD5 recorded in existing docs: `4247e04e20b65d6414c7238aa8ff5515`.
- Image base: `0x00400000`.
- Relevant sections:
  - `.text`: `0x00401000-0x0060c600`
  - `.rdata`: `0x0060d000-0x0066c200`
  - `.data`: `0x0066d000-0x0069ce24`
  - `.rsrc`: `0x0069d000-0x006b2e00`
- Capstone disassembly of the child ranges.
- Section-mapped scans for `rel32` calls/jumps, immediate VA dword occurrences, and vtable/global pointer references.
- `int_convert.py` checks for offsets and counts: `0x274 = 628`, `0x270 = 624`, `0x26c = 620`, `0x1fc = 508`, `0x108 = 264`, `0x100 = 256`, `0xa0 = 160`, `0xa4 = 164`, `0x10 = 16`, `0x4c = 76`, `0x40c = 1036`, `0x404 = 1028`, and `0x408 = 1032`.

Prior report evidence revalidated:

- B001 `0000ZO-maildialogs-source-split-audit.md` correctly noted no direct route to raw constructor starts including `0x0047e6a0`.
- B001 `0001Y2-MailDialogVtableFamily.md` correctly split core mail dialog vtables from `MailAlertCompanionVtables`.
- B006 `0000ZP-DialogAndAlertDestructorAdjustorThunks-source-routing.md` correctly treated `0x0047e90b` and `0x0047e916` as adjustor thunk jumps to [UID:0002TA].

## Exact Range And Route Findings

### Raw constructor, [UID:0002T7] `0x0047e6a0-0x0047e6ee`

Exact body is 78 bytes. Predecessor padding is `0x0047e694-0x0047e6a0` as twelve `0xcc` bytes. Successor padding is `0x0047e6ee-0x0047e6f0` as two `0xcc` bytes before [UID:0002T8].

Instruction-level behavior:

- Calls `AlertPane::AlertPane` at `0x0049feb0`.
- Pushes arguments `0`, `0x00613a18`, `[ebp+0x10]`, `[ebp+0x0c]` before the base constructor call.
- Stores the fifth argument byte `[ebp+0x14]` into `[esi+0x270]`.
- Installs the three `MailDeleteReplyAlert` vtables:
  - `[esi+0x00] = 0x0061476c`
  - `[esi+0xa0] = 0x006147d4`
  - `[esi+0xa4] = 0x00614804`
- Stores `esi` to `0x0067adbc`.
- Returns with `ret 0x10` at `0x0047e6eb-0x0047e6ed`.

Route evidence:

- No direct `E8`/`E9` `rel32` call or jump target to `0x0047e6a0`.
- No absolute dword occurrence of `0x0047e6a0`.
- No recovered vtable entry or jump-table pointer to `0x0047e6a0`.
- No confirmed static entry into the interior of this body.
- Existing inline construction sites mirror the same source constructor body and are the live use evidence:
  - `0x0047a4bf/0x0047a4c5/0x0047a4cf` in the mail-list delete-reply path install the same vtables, set `[esi+0x270] = 1`, and store `0x0067adbc`.
  - `0x0047a84d/0x0047a853/0x0047a85d` in a second mail-list path install the same vtables, set `[esi+0x270] = 1`, and store `0x0067adbc`.
  - `0x0047caf7/0x0047cafd/0x0047cb07` in `MailDialog::OnMailDeleteReply` install the same vtables, set `[esi+0x270] = 0`, and store `0x0067adbc`.
  - `0x0047cc2d/0x0047cc33/0x0047cc3d` in `MailDialog::ShowDeleteReplyAlert` install the same vtables, set `[esi+0x270] = 0`, and store `0x0067adbc`.

Conclusion: this is not padding and not a random artifact. It is constructor-shaped source code for `MailDeleteReplyAlert`, but the binary currently exposes no direct route to its start. Documentation should say "raw constructor-shaped body with no recovered direct entry route; behavior is corroborated by inline construction sequences".

### Destructor/getter, [UID:0002T8] `0x0047e6f0-0x0047e726`

Subranges:

- `0x0047e6f0-0x0047e719`: non-deleting destructor-shaped body.
- `0x0047e719-0x0047e720`: seven `0xcc` alignment bytes.
- `0x0047e720-0x0047e726`: singleton getter.
- `0x0047e726-0x0047e730`: ten `0xcc` alignment bytes before [UID:0002T9].

Destructor behavior:

- Reinstalls primary/secondary/tertiary vtables at `0x0061476c`, `0x006147d4`, and `0x00614804`.
- Clears `g_pMailDeleteReplyAlert` at `0x0067adbc`.
- Tail-jumps to `0x0049d9f0`, the inherited alert/dialog cleanup route.

Getter behavior:

- `0x0047e720: mov eax, [0x0067adbc]`
- `0x0047e725: ret`

Name conclusion:

- Best documentation name for the getter is `GetMailDeleteReplyAlertSingleton()` or `GetMailDeleteReplyAlert()`. I recommend the longer `GetMailDeleteReplyAlertSingleton()` in support docs because it describes the observed global singleton access without implying recovered source spelling.

### Confirm handler, [UID:0002T9] `0x0047e730-0x0047e836`

Exact body is `0x106` bytes. Successor padding is `0x0047e836-0x0047e840` as ten `0xcc` bytes.

Route evidence:

- No direct `rel32` calls to `0x0047e730`.
- One data reference to `0x0047e730`: vtable slot at `0x006147c8`.
- Therefore this is reached as a virtual alert action/confirm handler, not as a named direct helper call in the checked binary.

Behavior:

- Builds a stack frame with `sub esp, 0x40c` and a stack cookie from `0x00672f24`.
- Reads `AlertPane`/owner reference from `[this+0x26c]` into `edi`.
- Tests byte `[this+0x270]`.

Delete-all/selected-replies branch (`[this+0x270] != 0`):

- Uses the owner/current mail dialog from `[this+0x26c]`.
- Reads the dialog control manager/list at `[owner+0x1fc]`.
- Requests child/control id `7` through a virtual call at control-manager slot `+0x10`.
- Reads the child pane/list object through the returned object and its `+0x108` field.
- Calls `ListPane::GetSelectedIndices` at `0x004f3e80` with a stack buffer at `[ebp-0x404]` and maximum `0x100` entries.
- Loops over the returned selection indices.
- Calls `ListPane::RemoveItems` at `0x004f3d60` with `(selectedIndex - alreadyRemovedCount, 1)` so later indices stay valid after earlier deletions.
- Calls the owner dialog virtual slot `+0x4c` after removal. Best role: refresh/repopulate dialog contents after local reply-list mutation. Exact source spelling not recovered.
- Returns without popping a dialog/session frame.

Single-reply branch (`[this+0x270] == 0`):

- Reads the current dialog's session/context pointer from `[owner+0x270]`.
- Calls `DialogSession::FindPreviousDialog` at `0x004a1250` with the current dialog as the search marker.
- Reads a target reply id word from `[owner+0x274]`.
- Uses the previous dialog returned by `FindPreviousDialog`.
- Requests child/control id `7` on the previous dialog through `[previous+0x1fc]` and virtual slot `+0x10`.
- Reads the reply list object through `+0x108`.
- Calls `0x0047acd0`, currently documented as `MailListPane::FindMailIdIndex`, with the target reply id.
- If the index is not `-1`, calls `ListPane::RemoveItems(index, 1)`.
- Calls the previous dialog virtual slot `+0x4c` after removal.
- Calls `DialogSession::PopCurrentDialog(false)` at `0x004a10e0` through `[owner+0x270]` with argument `0`, closing/popping the transient current reply dialog/session view.
- Finishes with stack cookie check at `0x005c772f`.

Conclusion: the mode byte is not a generic "delete mode" without interpretation. It specifically distinguishes bulk selected reply deletion in the current reply list from single reply-id deletion routed back to the previous mail dialog and followed by a session pop.

### Scalar deleting destructor, [UID:0002TA] `0x0047eb90-0x0047ebef`

Exact behavior:

- Reinstalls the `MailDeleteReplyAlert` vtables.
- Clears `0x0067adbc`.
- Calls inherited cleanup at `0x0049d9f0`.
- If flag bit 1 is clear, returns `this`.
- If flag bit 1 is set and bit 4 is clear, calls `0x004f4ac0(this)`.
- If flag bit 4 is set, calls `0x0041b6a0(this, 0x274)`.
- Returns `this`.

Route evidence:

- Direct `rel32` branch hits to `0x0047eb90` are only from adjustor thunks at `0x0047e90b` and `0x0047e916`.
- One `.rdata` data hit for `0x0047eb90` is the primary vtable slot at `0x0061476c`.

Conclusion: this is compiler-generated deleting destructor support. It should be documented for vtable/layout completeness but should not receive hand-written formal C++.

## Field, Type, Global, And Helper Naming Recommendations

### `MailDeleteReplyAlert` fields

`this+0x26c`:

- Existing `AlertPane`/layout research identifies `+0x26c` as the inherited `AlertPane` layout/reference tail, not a separately allocated `MailDeleteReplyAlert` field.
- In this class, it is semantically the owning/current `MailDialog *` because the constructor and inline construction paths pass the dialog/layout pointer to `AlertPane::AlertPane`, and `OnConfirmDelete` immediately uses it as a mail-dialog object.
- Best documentation wording: "the inherited `AlertPane::m_layoutReference` at `+0x26c` is used here as the owning/current `MailDialog *`; local source variable name `ownerDialog` or `currentDialog` is appropriate, but do not declare a second derived field at `+0x26c` without a class-layout proof."

`this+0x270`:

- Confirmed derived tail byte, written by raw constructor and inline construction sites, read by `OnConfirmDelete`.
- Best source-facing name: `m_deleteAllReplies`.
- Alternate acceptable name: `m_deleteSelectedReplies`.
- Rejected names: `m_isMailDelete`, `m_deleteAllMail`, `m_replyMode`, and generic `m_flag270`. These do not encode the actual selected-reply versus single-reply behavior.
- `DeleteReplyAlert` has additional sibling mode bytes in its own layout, but no evidence supports a second `MailDeleteReplyAlert` mode byte at `+0x271` or a derived field at `+0x274`.

Object size:

- Allocation/deleting-destructor size is `0x274` (628, verified with `int_convert.py`).
- Only the byte at `+0x270` is class-specific evidence in this target. Do not infer a `+0x271` field just because the object size rounds up to `0x274`.

### Related `MailDialog` fields used by this class

`MailDialog+0x270`:

- Used as a `DialogSession *` or equivalent session/context object in the single-reply branch.
- It receives calls to `DialogSession::FindPreviousDialog` and `DialogSession::PopCurrentDialog`.
- Best source-facing name for MailDialog docs: `m_dialogSession` or existing project-preferred session field name. Do not name it as a `MailDeleteReplyAlert` field.

`MailDialog+0x274`:

- Read as a 16-bit target reply id in the single-reply branch.
- Best source-facing name: `m_currentReplyId` or `m_selectedReplyId`.
- Evidence is specific to the single-reply deletion route: the value is passed into `MailListPane::FindMailIdIndex` on the previous dialog's reply list.

`DialogPane/MailDialog+0x1fc`:

- Existing dialog layout docs identify this as a control/list manager pointer.
- `OnConfirmDelete` uses it to request child/control id `7`.
- Best local constant name for child id `7`: `kReplyListControlId`.

Returned child object `+0x108`:

- The child returned by the control manager exposes a pane/list pointer at `+0x108`.
- The object behind `+0x108` supports `ListPane::GetSelectedIndices`, `ListPane::RemoveItems`, and `MailListPane::FindMailIdIndex`/row id search behavior.

### Globals

`0x0067adbc`:

- Best name: `g_pMailDeleteReplyAlert`.
- Best type: `MailDeleteReplyAlert *`.
- Direct refs found in `.text`: approximately at `0x0047a483`, `0x0047a4e2`, `0x0047a811`, `0x0047a870`, `0x0047cb1a`, `0x0047cc50`, `0x0047e6e3`, `0x0047e70c`, `0x0047e721`, and `0x0047ebb2`.
- Current zero-filled `.data` evidence from prior live IDA work supersedes older "static image value `0xffffffff`" wording. Implementation should update stale support docs to avoid reporting the old value as current truth.

`0x00613a18`:

- Raw constructor passes this value as the primary button/label/layout argument to `AlertPane::AlertPane`, followed by a null secondary argument.
- Existing docs sometimes call this `g_alertPaneButtonLayout`; `AlertPane` signature docs describe the corresponding arguments as button text pointers.
- Best current wording: "shared alert OK/primary-button resource pointer at `0x00613a18`."
- Exact source symbol is not recovered. Do not hard-freeze a final name until the resource/string data is verified.

### Helpers

`0x0049feb0`:

- Best name: `AlertPane::AlertPane`.
- Used by raw constructor and inline construction paths.

`0x004f3e80`:

- Best name: `ListPane::GetSelectedIndices(int *outIndices, int maxCount)`.
- Behavior: exports selected indices, using multi-select flags at `ListPane+0x138` when multi-select byte `+0x13c` is set, otherwise exports the single selected index at `+0x134` if valid.

`0x004f3d60`:

- Best name: `ListPane::RemoveItems(int startIndex, int count)`.
- Behavior: removes rows from list storage at `+0x130` and selection-flag storage at `+0x138`, clears selected index `+0x134` to `-1`, syncs scrollbars, invalidates UI, and emits a selection-change virtual callback.

`0x0047acd0`:

- Existing best documented name: `MailListPane::FindMailIdIndex`.
- In this alert's single-reply branch, the searched id is a reply id from `MailDialog+0x274`.
- Best future-proof wording: "row-id search currently documented as `MailListPane::FindMailIdIndex`; in this callsite it is used as reply-id lookup on the reply list."
- Rejected final rename for now: `FindReplyById`. It is semantically attractive, but unsafe as a global rename because the helper also has existing mail-list semantics.

`0x004a1250`:

- Best name: `DialogSession::FindPreviousDialog`.
- Evidence: called with the current dialog and returns the dialog used for reply-list deletion in the single-reply route.

`0x004a10e0`:

- Best name: `DialogSession::PopCurrentDialog`.
- Evidence: called with flag `0` only in the single-reply branch after the previous dialog has been refreshed.

Virtual slot `+0x4c` on the mail dialog:

- Best role: refresh/repopulate mail dialog contents after local reply-list mutation.
- Best tentative name: `RefreshContents()` or `RefreshMailDialog()`.
- Exact source spelling is not recovered. Documentation should call it "the mail dialog refresh virtual at vtable slot `+0x4c`" unless the corresponding owner method has been named elsewhere.

## Heuristic / Inference Reanalysis And Validation

### Raw constructor reachability

Best-supported conclusion: `0x0047e6a0` is a retained out-of-line constructor-shaped body with no recovered direct entry route.

Evidence checked:

- No `rel32` call/jump to `0x0047e6a0`.
- No absolute dword pointer to `0x0047e6a0`.
- No vtable slot or jump-table pointer to `0x0047e6a0`.
- No confirmed interior entry.
- Body exactly performs base construction, mode-byte initialization, vtable installation, singleton publication, and `ret 0x10`.
- Four inline construction sites perform the same work around live mail dialog/list paths.

Rejected alternatives:

- "Padding": rejected because the range is valid executable constructor-shaped code with calls, stores, and `ret 0x10`.
- "Dead random artifact": rejected as too weak because the body exactly matches live inline construction semantics and class vtable/global addresses.
- "Confirmed live constructor call": rejected because no static call/branch/pointer route was recovered.

Open question closure: route remains intentionally classified as no-safe-inference. The safe documentation wording is "raw constructor-shaped body with no recovered direct route, corroborated by inline construction sites".

### Singleton naming

Best-supported conclusion: use `g_pMailDeleteReplyAlert`.

Evidence checked:

- Constructor-shaped and inline construction paths store alert `this` to `0x0067adbc`.
- Destructor and deleting destructor clear `0x0067adbc`.
- Getter returns `0x0067adbc`.
- Existing global page already uses `g_pMailDeleteReplyAlert`.
- Neighbor `0x0067adb8` is the board/article `g_pDeleteReplyAlert`, making the mail-specific suffix necessary and consistent.

Rejected alternatives:

- `dword_67ADBC`: generated placeholder only.
- `g_mailDeleteReplyAlert`: loses pointer/singleton semantics.
- `g_pMailDialogDeleteAlert`: less exact than current class name and not supported by existing docs.

Open question closure: final documentation name should be `g_pMailDeleteReplyAlert`; exact source spelling is still inferred but high-confidence.

### Class/source ownership

Best-supported conclusion: keep [UID:0000HW] `BulletinReplyAlerts` as canonical owner/emitter.

Evidence checked:

- Current class page, global page, vtable companion page, and `BulletinReplyAlerts` file route all agree on `0000HW`.
- Mail alert companion vtables are grouped under `MailAlertCompanionVtables`, a child of the shared alert wrapper route.
- The mail delete reply alert sits in an interleaved companion strip with `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, `DeleteReplyAlert`, and other board/mail alert helpers.
- `MailDialogs` owns the consumer methods and inline construction sites, but those are call/use evidence, not enough by themselves to move the companion class source owner.

Rejected alternatives:

- Move to `MailDialogs`: serious alternate, but rejected because it would split the alert companion class from the vtable/global owner and from sibling mail/bulletin alert wrappers without direct source-path proof.
- New `MailAlertCompanions.cpp`: rejected because the project already has `BulletinReplyAlerts` as the source-facing bucket and no stronger file-boundary evidence supports a new file.
- Move to `BoardDialogs`: rejected for this mail-specific class. Board/article sibling classes inform layout and naming but do not own this class.

Open question closure: source placement remains inferred, but the implementation should keep `0000HW` and document `MailDialogs` as the strongest alternate only.

### Field layout

Best-supported conclusion:

- `AlertPane+0x26c` is inherited layout/reference storage and is used here as an owning/current `MailDialog *`.
- `MailDeleteReplyAlert+0x270` is the only confirmed derived mode byte, best named `m_deleteAllReplies`.
- No separate confirmed derived field at `+0x271`, `+0x272`, or `+0x274`.

Evidence checked:

- Raw constructor writes `[esi+0x270]`.
- Inline construction sites write `[esi+0x270] = 1` or `0`.
- Confirm handler reads `[ecx+0x270]`.
- No child method in this class reads or writes `MailDeleteReplyAlert+0x271`.
- Deleting destructor uses object size `0x274`, but size alone does not prove additional semantic fields.
- `AlertPaneLayout` identifies `+0x26c` as base/inherited tail context.

Rejected alternatives:

- Model `+0x26c` as a new `MailDeleteReplyAlert::m_dialog`: rejected as a declaration-level field because the storage belongs to the base alert layout. It can be locally documented as owner/current dialog.
- Copy `DeleteReplyAlert` multi-byte mode fields into `MailDeleteReplyAlert`: rejected because the mail class only shows one byte.
- Keep `field_270`: rejected because behavior now supports a better source-facing name.

Open question closure: final docs should name the role and inference status, not leave `field_270` unresolved.

### Delete-all versus single-reply behavior

Best-supported conclusion:

- `m_deleteAllReplies != 0`: remove all currently selected reply rows from the current owner dialog's reply list, then refresh that dialog.
- `m_deleteAllReplies == 0`: find the previous mail dialog, delete the reply id stored on the current dialog from the previous dialog's reply list, refresh the previous dialog, then pop/close the current dialog session view.

Evidence checked:

- The branch condition is exactly `cmp byte ptr [ecx+0x270], 0`.
- The nonzero branch calls `ListPane::GetSelectedIndices` and iterates with `selectedIndex - removedCount`.
- The zero branch calls `DialogSession::FindPreviousDialog`, reads a word at `MailDialog+0x274`, calls row-id lookup, and then calls `DialogSession::PopCurrentDialog(false)`.

Rejected alternatives:

- "Delete all mail": rejected; this path operates on reply-list rows, not the mailbox as a whole.
- "Delete current message": rejected; the zero branch deletes one reply id from a previous dialog's child list and pops the current session.
- "Server-side delete request": not supported by this handler; observed behavior is local list/session update. Packet handling that leads to showing the alert lives in caller/owner methods.

Open question closure: branch behavior is now specific enough for by-* docs and source-facing field names.

### Reply-list and helper names

Best-supported conclusion:

- Use existing `ListPane::GetSelectedIndices`, `ListPane::RemoveItems`, `MailListPane::FindMailIdIndex`, `DialogSession::FindPreviousDialog`, and `DialogSession::PopCurrentDialog` names.
- Treat child/control id `7` as the reply-list control id in this context.
- Document the vtable `+0x4c` call as a mail dialog refresh virtual until the exact source spelling is recovered.

Evidence checked:

- `ListPaneItemSelectionStorageHelpers` documents and disassembles the selection/remove helpers.
- `MailListPane` documents `0x0047acd0` as a row id search.
- `BulletinSessionDialogStack` documents `0x004a1250` and `0x004a10e0`.
- Both confirm-handler branches resolve child id `7` before touching the list object.

Rejected alternatives:

- Rename `0x0047acd0` globally to `FindReplyById`: rejected because existing support docs call it `FindMailIdIndex` and the helper is not proven reply-only.
- Treat virtual `+0x4c` as `OnInit` or destructor: rejected because it is called after list mutation and before/after session pop, matching refresh/repopulate behavior.

Open question closure: exact slot `+0x4c` spelling remains no-safe-inference, but its role is resolved enough for support docs.

### Vtable, thunk, and destructor policy

Best-supported conclusion:

- Primary vtable `0x0061476c`, secondary vtable `0x006147d4`, and tertiary vtable `0x00614804` belong to `MailDeleteReplyAlert`.
- Vtable slot at `0x006147c8` dispatches `OnConfirmDelete`.
- Primary vtable slot at `0x0061476c` references scalar deleting destructor `0x0047eb90`.
- Adjustor thunks at `0x0047e90b` and `0x0047e916` are compiler support and should not become source methods.
- Scalar deleting destructor [UID:0002TA] should remain non-source/formal-blank.

Evidence checked:

- Constructor and destructor bodies install the three table addresses.
- `.rdata` dword scan finds `0x0047e730` at `0x006147c8`.
- `.rdata` dword scan finds `0x0047eb90` at `0x0061476c`.
- `rel32` scan finds only adjustor-thunk jumps to `0x0047eb90`.

Rejected alternatives:

- Treat adjustor thunks as class methods: rejected as compiler-generated.
- Emit scalar deleting destructor C++ as source: rejected as compiler-generated object model support.
- Route the action handler as a direct helper: rejected because route is virtual only.

Open question closure: vtable policy is clear enough for implementation docs.

### First-draft C++ decision

Best-supported conclusion: do not add formal C++ to the target class page. Method-level C++ should be considered only on exact child pages after support docs incorporate the helper names and route caveats.

Evidence checked:

- Current target is `by-class/MailDeleteReplyAlert.md`, not a single exact memory range.
- Child pages own the exact constructor/destructor/action-handler/deleting-destructor ranges.
- The raw constructor has no recovered route.
- The scalar deleting destructor is generated.
- The class declaration would require inferred base API names, source-file placement, global declaration ownership, and refresh/control-manager names that are not all recovered as exact source symbols.
- `by-structure.md` allows high-scored reconstructable entries to emit C++, but also requires that output be target-scoped and source-ready.

Rejected alternatives:

- Add a class declaration and all methods to the class page: rejected because it exceeds the class hub's exact coverage and can duplicate child method emission.
- Add constructor formal C++ on the class page: rejected because raw constructor route remains no-safe-inference.
- Add scalar deleting destructor C++: rejected as compiler-generated.

Open question closure: the target's no-code decision is exact and target-specific. Later implementation may add non-formal reference shapes to docs and may separately evaluate [UID:0002T9] for child-page first-draft C++.

## Source-Style Reference Shapes For Later Child Pages

These are not recommended as formal class-page C++ in this report. They are included so a later implementation callback has a consistent source-facing shape to compare against exact child ranges.

Constructor-shaped reference:

```cpp
MailDeleteReplyAlert::MailDeleteReplyAlert(
    const wchar_t *messageText,
    MailDialog *ownerDialog,
    bool deleteAllReplies)
    : AlertPane(messageText, ownerDialog, kAlertOkButtonText, 0),
      m_deleteAllReplies(deleteAllReplies)
{
    g_pMailDeleteReplyAlert = this;
}
```

Notes:

- `kAlertOkButtonText` is a placeholder for the shared primary alert button resource at `0x00613a18`; exact source symbol is not recovered.
- `ownerDialog` is stored through inherited `AlertPane::m_layoutReference`, so the declaration may not literally contain a `MailDeleteReplyAlert::m_ownerDialog` member.
- The raw constructor has no recovered direct route; use this as documentation/reference only unless the project accepts no-entry constructor-shaped code emission.

Confirm-handler reference:

```cpp
void MailDeleteReplyAlert::OnConfirmDelete()
{
    MailDialog *currentDialog = static_cast<MailDialog *>(m_layoutReference);

    if (m_deleteAllReplies) {
        ListPane *replyList = currentDialog->GetReplyListPane();

        int selectedIndices[256];
        int selectedCount = replyList->GetSelectedIndices(selectedIndices, 256);

        for (int i = 0; i < selectedCount; ++i) {
            replyList->RemoveItems(selectedIndices[i] - i, 1);
        }

        currentDialog->RefreshContents();
        return;
    }

    DialogSession *session = currentDialog->GetDialogSession();
    MailDialog *previousDialog =
        static_cast<MailDialog *>(session->FindPreviousDialog(currentDialog));
    unsigned short replyId = currentDialog->GetCurrentReplyId();
    ListPane *replyList = previousDialog->GetReplyListPane();

    int row = replyList->FindMailIdIndex(replyId);
    if (row != -1) {
        replyList->RemoveItems(row, 1);
    }

    previousDialog->RefreshContents();
    session->PopCurrentDialog(false);
}
```

Notes:

- `GetReplyListPane`, `RefreshContents`, `GetDialogSession`, and `GetCurrentReplyId` are source-facing role names, not recovered exact spellings.
- `FindMailIdIndex` is the existing support-doc name for `0x0047acd0`; in this context it searches a reply id row.
- A formal child-page C++ version should avoid declaring unrecovered methods unless those names are first accepted in support docs.

## Rejected Alternatives

- Move ownership to `MailDialogs`: rejected for this pass. Mail dialog methods inline-construct/use the alert, but the alert companion class, singleton, and vtables remain better placed in `BulletinReplyAlerts`.
- Split `MailDeleteReplyAlert` into a new source file: rejected. No independent file-boundary evidence currently beats the existing shared route.
- Treat raw constructor [UID:0002T7] as live-called source entry: rejected because scans found no route to the start or interior.
- Treat raw constructor as padding/artifact: rejected because behavior exactly matches the class constructor shape and live inline construction sites.
- Add class-level formal C++ now: rejected because class hub output would exceed exact target coverage and duplicate child method ownership.
- Emit scalar deleting destructor source: rejected as compiler-generated vtable/deletion support.
- Rename `MailListPane::FindMailIdIndex` globally to reply-specific wording: rejected because the helper is shared/name-stable in existing mail-list docs.
- Copy `DeleteReplyAlert` field layout directly into `MailDeleteReplyAlert`: rejected because the mail class only proves `+0x270` as a derived mode byte.
- Keep stale `dword_67ADBC` or old static `0xffffffff` wording as primary global documentation: rejected. Current best name is `g_pMailDeleteReplyAlert`, and current zero-filled `.data` evidence should be reflected in support docs.

## Open-Question Closure

- Raw constructor route: closed as "no recovered static route"; not future work unless new dynamic or linker evidence appears.
- Singleton name: closed as `g_pMailDeleteReplyAlert` with inferred source spelling.
- Source owner: closed for implementation as `BulletinReplyAlerts`, with `MailDialogs` recorded as strongest alternate.
- Tail field name: closed as inferred `m_deleteAllReplies`; exact spelling not recovered, but `field_270` should no longer be the only source-facing name.
- Owner/current dialog field: closed as inherited `AlertPane::m_layoutReference` used as `MailDialog *`; do not add a second derived field at `+0x26c`.
- Delete-all versus single-reply mode: closed by branch behavior.
- Reply-list helper names: mostly closed through existing support docs; exact method spelling for the mail dialog refresh virtual remains no-safe-inference and should be documented as a role.
- `0x00613a18`: no safe final symbol yet; document as shared primary alert button/OK resource pointer.
- Class C++: closed as no formal target C++; child-page C++ can be evaluated separately.

## Proposed Metadata

Target [UID:00007J] `by-class/MailDeleteReplyAlert.md`:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000HW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000HW`
- Status note: `MailDeleteReplyAlert source-quality reanalysis: raw constructor-shaped body has no recovered direct route but is corroborated by inline construction sites; class remains under BulletinReplyAlerts; mode byte +0x270 is inferred m_deleteAllReplies; class-page C++ remains blank while child method pages own exact bodies.`

Suggested child/support scoring direction for later implementation:

- [UID:0002T7] raw constructor: consider `87/89` if report details are incorporated, but keep formal C++ blank unless the no-entry constructor policy changes.
- [UID:0002T8] destructor/getter: keep around `85/90` or raise only if getter/destructor split and naming are incorporated; getter is exact, destructor is compiler/base cleanup oriented.
- [UID:0002T9] confirm handler: consider `88/91` after helper names, branch behavior, field roles, and source-style reference are incorporated; this is the best child candidate for formal method C++.
- [UID:0002TA] scalar deleting destructor: keep formal C++ blank; generated support only.
- [UID:0002AI]/[UID:0002W5] singleton storage pages: update stale global-name/static-init wording, but keep non-reconstructable/split-map disposition where applicable.

## Exact Supervisor-Owned Coverage Row

For supervisor application to the appropriate class coverage report if this source-quality pass is accepted:

```text
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) : reconstructable : 88% : very strong : B009 2026-06-19 source-quality reanalysis keeps owner/emitter [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md); PE/Capstone audit confirms exact child ranges, raw constructor-shaped body `0x0047e6a0-0x0047e6ee` has no direct rel32, absolute-pointer, vtable, jump-table, or interior-entry route but is corroborated by inline construction sites at `0x0047a4bf`/`0x0047a84d` setting `this+0x270=1` for selected-reply deletion and `0x0047caf7`/`0x0047cc2d` setting `this+0x270=0` for single-reply mail-dialog deletion; `0x0067adbc` is best named `g_pMailDeleteReplyAlert`, vtable slot `0x006147c8` dispatches `OnConfirmDelete`, scalar deleting destructor `0x0047eb90` remains compiler-generated, and helper ownership resolves to `ListPane::GetSelectedIndices`, `ListPane::RemoveItems`, `MailListPane::FindMailIdIndex`, `DialogSession::FindPreviousDialog`, and `DialogSession::PopCurrentDialog`; class-page C++ stays blank while exact child by-memory pages own any future method-body C++.
```

No direct edit to `by-memory/-coverage-report.md` is recommended from this report-only pass. If child by-memory scores are changed during implementation, the implementation callback should prepare separate supervisor-owned rows for those child pages.

## Exact Implementation Checklist

Target doc:

- `by-class/MailDeleteReplyAlert.md`
  - Update score to `88/90`.
  - Keep owner/emitter/reconstructable metadata unchanged.
  - Add the status note above.
  - Replace stale shallow raw-constructor/source-split/open-question wording with the route proof and inline construction relationship.
  - Add a field layout section:
    - inherited `AlertPane::m_layoutReference` at `+0x26c` used as `MailDialog *`.
    - derived byte `+0x270` best name `m_deleteAllReplies`.
    - no proven additional derived fields despite `0x274` allocation size.
  - Add behavior section for delete-all versus single-reply branch.
  - Add helper/global name recommendations and rejected alternatives.
  - Keep formal class-page `RECONSTRUCTION_CPP` blank and include the exact no-code proof.

Child by-memory docs to update:

- `by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md`
  - Add exact padding/range proof.
  - Add no direct route/no interior route proof.
  - Add inline construction site cross-references at `0x0047a4bf`, `0x0047a84d`, `0x0047caf7`, and `0x0047cc2d`.
  - Rename `field_270` role to inferred `m_deleteAllReplies`.
  - Document `0x00613a18` as shared primary alert button/OK resource pointer with source-name caveat.
  - Keep or explicitly justify blank formal C++ unless no-entry constructor emission is accepted.

- `by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md`
  - Split destructor, padding, and getter subranges clearly.
  - Name `0x0047e720` as `GetMailDeleteReplyAlertSingleton()` or a documented equivalent.
  - Clarify destructor clears `g_pMailDeleteReplyAlert` and tail-jumps inherited alert cleanup.

- `by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md`
  - Add full branch behavior from this report.
  - Add helper names and field roles.
  - Add child/control id `7` as reply-list control id.
  - Add virtual slot `+0x4c` as mail-dialog refresh role with unrecovered exact spelling.
  - Decide whether to add formal first-draft method C++ only after support docs accept helper names.

- `by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md`
  - Preserve generated/deleting-destructor policy.
  - Add adjustor thunk route proof from `0x0047e90b` and `0x0047e916`.
  - Keep formal C++ blank.

Support docs to update:

- `by-file/BulletinReplyAlerts.md`
  - Keep `MailDeleteReplyAlert` under the shared alert wrapper source route.
  - Add B009 source-quality note with raw constructor no-route proof, inline construction relationship, singleton/global/vtable ownership, and `MailDialogs` as alternate but rejected source owner.

- `by-file/MailDialogs.md`
  - Add consumer/caller note that mail dialog and mail-list paths inline-construct `MailDeleteReplyAlert` and set mode byte `+0x270`, but current canonical source route remains `BulletinReplyAlerts`.

- `by-class/MailDialog.md`
  - Update `OnMailDeleteReply` and `ShowDeleteReplyAlert` notes to say they inline-construct `MailDeleteReplyAlert` with `m_deleteAllReplies=false`, publish `g_pMailDeleteReplyAlert`, and rely on the alert's single-reply branch to update the previous dialog and pop the current session.
  - Add or refine notes for mail-list delete-reply paths if those are represented on the class page.
  - Document `MailDialog+0x270` as session/context and `MailDialog+0x274` as current/target reply id if not already present.

- `by-class/DeleteReplyAlert.md`
  - Add a comparison caveat if needed: sibling class informs naming but its additional mode bytes should not be copied to `MailDeleteReplyAlert`.

- `by-class/ListPane.md`, `by-file/ListPane.md`, and `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
  - Usually no score change required.
  - If touched, add cross-reference that `MailDeleteReplyAlert::OnConfirmDelete` uses `GetSelectedIndices` and `RemoveItems` for local reply-list mutation.

- `by-class/MailListPane.md`
  - Add cross-reference that `0x0047acd0` is also used on the reply-list child in the mail delete-reply alert single-delete path; avoid renaming globally to reply-only wording unless accepted.

- `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`
  - Add cross-reference to `MailDeleteReplyAlert` single-reply branch using `FindPreviousDialog` and `PopCurrentDialog(false)`.

- `by-global/g_pMailDeleteReplyAlert.md`
  - Confirm type/name `MailDeleteReplyAlert *`.
  - Add ten direct refs and current source-owner decision.
  - Remove or qualify stale generated/global placeholder wording.

- `by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md`
  - Update the mail slot from `dword_67ADBC` wording to `g_pMailDeleteReplyAlert`.
  - Preserve split-map/non-reconstructable policy.
  - Clarify current zero-filled `.data` versus any old static-image wording.

- `by-memory/0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert.md`
  - Update stale `0xffffffff` static-image statement if still present.
  - Keep exact singleton slot ownership and non-code policy.

- `by-type/by-vtable/MailAlertCompanionVtables.md`
  - Add B009-confirmed vtable details:
    - primary `0x0061476c`
    - secondary `0x006147d4`
    - tertiary `0x00614804`
    - action slot `0x006147c8 -> 0x0047e730`
    - primary deleting destructor slot `0x0061476c -> 0x0047eb90`
  - Preserve `BulletinReplyAlerts` ownership and `MailDialogs` alternate.

- `by-type/by-vtable/MailDialogVtableFamily.md`
  - Ensure split-child wording still routes mail alert companion tables to `MailAlertCompanionVtables`, not the core `MailDialog` vtable family.

- `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md`
  - Update child summary rows for [UID:0002T7], [UID:0002T8], [UID:0002T9], and [UID:0002TA] if target/child docs are updated.

- `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
  - Add or confirm split-index wording that `MailDialogs` contains consumer/inline construction paths but exact mail alert companion child pages keep their current source route.

- `by-type/by-struct/AlertPaneLayout.md`
  - Add optional cross-reference that `MailDeleteReplyAlert` uses inherited `AlertPane+0x26c` as its owning/current mail dialog and starts derived state at `+0x270`.

Generated/autogen checklist for implementation callback:

- If no formal C++ is added, run scoped validators for every changed by-* file with `--apply --queue-timeout 240`; no generated source body should change for [UID:00007J].
- If [UID:0002T9] formal child C++ is added later, run the normal scoped/autogen refresh path used by this project and inspect generated `NexusTK` output for duplicate class-page emission.
- Do not edit `by-memory/-coverage-report.md` directly from the B-agent callback. Put supervisor-owned rows in notes/final response.

Exact validator commands to run after implementation changes:

> Executable block R001 was removed from this report and preserved verbatim in [00007J-MailDeleteReplyAlert-class-source-quality-removed.md](00007J-MailDeleteReplyAlert-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Skip any support-doc validator command only if the corresponding file is not edited, and record the skip reason in the implementation final response.

## Scoped Validator Baseline

Baseline command run from `E:\NTK\GhidraBridge\source-3\project-documentation` before report edits:

> Executable block R002 was removed from this report and preserved verbatim in [00007J-MailDeleteReplyAlert-class-source-quality-removed.md](00007J-MailDeleteReplyAlert-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- Validator summary: `ok: 1`.
- Dry run only (`apply: False`).
- Key messages included:
  - `ok 00007J by-class/MailDeleteReplyAlert.md UID header exists`
  - `autogen_emitter_has_no_code 00007J by-class/MailDeleteReplyAlert.md emitting children only`
  - `autogen_cpp_noop 0000HW auto-generated/NexusTK/ui/dialogs/BulletinReplyAlerts.cpp unchanged`
  - `dry run only; pass --apply to write changes`

No by-* files and no coverage files were edited for this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00007J-MailDeleteReplyAlert-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00007J"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00007J-MailDeleteReplyAlert-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00007J-MailDeleteReplyAlert-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00007J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
