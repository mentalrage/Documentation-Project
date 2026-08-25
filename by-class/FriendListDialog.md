*** UID:00005J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FriendListDialog : public DialogPane
{
public:
    FriendListDialog();
    virtual ~FriendListDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FriendListDialog

## Status

- Confidence: strong for inheritance, zero derived storage, source-visible virtual surface, access, vtable structure, and source-file ownership.
- Likely source file: [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- Address range: [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md), with destructor/thunk ranges listed on that page.
- Current recovered file: `source-3/simroot_v2/class_FriendListDialog.cpp`

## Class Purpose

`FriendListDialog` is the friend-list editor dialog. It creates twenty text edit controls in two columns, preloads friend names from config storage, and writes the edited names back when OK is pressed.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FriendListDialog` | `0x0053f2c0-0x0053f801` | Builds dialog controls, chooses EPF/EPD asset layout, loads saved friend names, and opens the dialog. |
| non-deleting destructor helper | `0x0053f810-0x0053f82f` | Resets the `FriendListDialog` vtable triplet before base teardown. |
| `OnControlCommand` | `0x0053f830-0x0053f921` | Primary-vtable `+0x48` override; reads all 20 text fields, trims/stores them in config, checks the friend-name sync flag, optionally calls the opcode `0x77` name-list upload helper, unconditionally calls [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md), then closes/removes the pane. Historical `OnOkButton` / `OnOkCommand` labels were behavior descriptions rather than the class interface name. |
| `SetHoverControl` | `0x0053f930-0x0053f939` | Protected primary-vtable `+0x58` override forwarding the control id to `DialogPane::SetHoverControl`. Historical `OnSetFocus` / `OnFocusStateChanged` labels were superseded by slot and caller evidence. |
| adjustor thunks | `0x005425b5`, `0x005425c0` | Destructor adjustor thunks. |
| scalar deleting destructor | `0x005426e0-0x00542735` | Resets vtables, destroys `DialogPane`, and conditionally frees memory. |

## Evidence Notes

- Live IDA MCP on 2026-06-12 confirms every listed function start and the corrected half-open ends: constructor `0x0053f801`, non-deleting destructor helper `0x0053f82f`, OK handler `0x0053f921`, focus helper `0x0053f939`, and scalar deleting destructor `0x00542735`.
- B001 2026-06-27 recheck resolves the old OK-handler endpoint dispute at byte level: `lookup_funcs` reports `0x0053f830` size `0xf1`, `0x0053f920` inside `sub_53F830`, and `0x0053f921` as not a function; the `ret 8` epilogue ends at the half-open endpoint `0x0053f921`, where `0xcc` padding begins.
- `OnControlCommand` stores rows at `g_pConfig + 2691552`, one config string per friend slot.
- IDA MCP callers show [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) is called from `OnControlCommand` after checking [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md); that helper reads the same config slots and serializes opcode `0x77` for [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md). The generated `g_isCashShopEnabled` name for this read is misleading.
- The accepted caller body preserves exact ordering: trim/store all 20 rows, optionally perform the opcode `0x77` friend-name sync, unconditionally call `SaveUserSettings`, then close/remove. The profile save is not conditional on the sync flag and is not a generic `SaveConfig()` method call.
- The dialog is feature-specific by assets `FRIEND.EPF`, `FRIEND.EPD`, `FRIEND.PAL`, and fixed 20-slot friend list layout.
- Allocation size is `620` bytes (`0x26c`), exactly the established `DialogPane` size. Constructor writes affect inherited facets and controls only; no derived field survives as storage. The source declaration therefore adds no data members and naturally preserves the inherited layout.
- The class owns a primary vtable at `0x00620ee4`, secondary vtable at `0x00620f44`, and tertiary vtable at `0x00620f74`. Primary slots `+0x48` and `+0x58`, direct constructor call sites, and base-forwarding behavior establish `OnControlCommand(int, int)` and protected `SetHoverControl(int)` as the source-visible overrides.
- The non-deleting destructor helper, scalar-deleting wrapper, two adjustor thunks, vptr stores, RTTI structures, and EH/cookie machinery are compiler output and are not handwritten in the class declaration or method source.
- The complete class declaration is emitted before `[[CHILDREN]]`; qualified method definitions therefore remain at namespace scope. The declaration adds no speculative fields, raw offsets, table arrays, or compiler artifacts.

## Cross-References

- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled`
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00038A][0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor](by-memory/0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor.md)

## Changes

- 2026-07-20 B003 source-closure implementation:
  - Raised the page from `85/90` to `90/93`, retained UID0000JN ownership/emission, set class position `10`, and installed the complete no-field `DialogPane`-derived declaration before `[[CHILDREN]]`.
  - Reconciled primary-vtable slots `+0x48` and `+0x58` to `OnControlCommand(int, int)` and protected `SetHoverControl(int)`, preserving the exact save/sync/close behavior while historicalizing the older behavior-only labels.
  - Added exact `0x26c` allocation/layout proof, three-vtable evidence, source access rationale, and explicit compiler destructor/thunk/RTTI/EH exclusions. Completion remains capped by inferred lexical spellings and unavailable original headers; confidence reflects convergent slot, allocation, caller, and body evidence.

- 2026-07-14 B005 [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) implementation callback support sync:
  - Score, metadata, ownership, and blank class formal remain unchanged. Added the exact optional opcode `0x77` sync -> unconditional `SaveUserSettings` -> close/remove order and rejected the stale generic `SaveConfig()` interpretation.

- 2026-06-12 A004 Batch 243 strict-gate repair:
  - Before: `COMPLETION:80`, `CONFIDENCE:88`, the OK-handler endpoint still used `0x0053f920`, and the direct scalar deleting destructor child could not be attached under the current `85/85` rule.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`; kept parent [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md), which now clears `85/86`.
  - Evidence: live IDA MCP confirmed `sub_53F2C0` size `0x541`, the non-deleting destructor helper at `0x0053f810-0x0053f82f`, `OnOkButton` size `0xf1`, `OnSetFocus`, the scalar deleting destructor wrapper, primary/secondary/tertiary vtable refs, constructor callers, and the friend-name config/opcode `0x77` save path.
- 2026-06-27 B001 implementation callback:
  - Added source-facing method-name reconciliation and endpoint/order details from the accepted [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md) report.
  - Target [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md) now carries formal first-draft FriendListDialog C++; this class page remains a class index/ownership page with blank C++.
  - Evidence: B001 MCP evidence confirmed `0x0053f830` size `0xf1`, `0x0053f920` inside the handler, `0x0053f921` as padding start, and accepted support routing for the thunk/destructor pages.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: friend-list upload evidence used only the historical `byte_66DEE0` label.
  - After: the page records resolved name `g_friendNameListSyncEnabled` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_66DEE0` to `g_friendNameListSyncEnabled`; existing IDA-backed evidence already ties the flag to the friend-name-list opcode `0x77` upload path.
- 2026-05-28: Changed `OnSetFocus` from `0x0053f930-0x0053f938` to `0x0053f930-0x0053f939`.
  - Before: the method map omitted the final byte of the function.
  - After: the method map matches IDA's full function boundary.
  - Evidence: IDA MCP reports `sub_53F930` as `0x0053f930-0x0053f939`.
- Completion/confidence score update: existed before as `0/0`; changed to `80/88`. Summary: dialog role, 20-slot control layout, OK behavior, config storage, packet upload linkage, assets, method ranges, destructor support, and corrected boundary are documented with strong confidence. Evidence: main range `0x0053f2c0-0x0053f939`, the `BuildAndSendFriendNameListSync` cross-reference, `byte_66DEE0` / `g_friendNameListSyncEnabled`, and friend-name opcode documentation.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) because the class is `80/88` and the parent is `84/82`, satisfying the then-current 80/80 parent gate. Live IDA MCP `lookup_funcs` confirmed exact starts at `0x0053f2c0`, `0x0053f830`, `0x0053f930`, `0x005425b5`, `0x005425c0`, and `0x005426e0`; current `callers` confirmed constructor references from dialog/menu flows at `0x0053e115`, `0x005a7112`, and `0x005bd151`.
