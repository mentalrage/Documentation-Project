** TARGET-REPORT-UID:00002P **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B013 Research Report: [UID:00002P] ClientItemMenuDialog

Status: FINISHED

## Target Paths

- Target by-class doc: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ClientItemMenuDialog.md`
- Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B013\research\00002P-ClientItemMenuDialog-class-source-quality.md`
- Related owner/source doc: `source-3/project-documentation/by-file/ItemMenuDialogs.md`
- Primary executable aggregate: `source-3/project-documentation/by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`
- Direct list companion: `source-3/project-documentation/by-class/ClientItemMenuItemList.md`
- Direct list companion memory page: `source-3/project-documentation/by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md`

## Scope And Current State

`ClientItemMenuDialog.md` is currently `COMPLETION:85`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KF`, `EMITTER_UIDS:0000KF`. The class is source-routed to [UID:0000KF] `ItemMenuDialogs`, with source placement currently best represented as `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`. The possible legacy fold into a broader `ItemDialogs.cpp` should remain documented as a physical-source caveat, but it is no longer a source-routing blocker.

This pass rechecked action/menu command semantics, packet construction, payload parsing, layout branches, fields, vtable slices, relation to `ClientItemMenuItemList`, relation to `ServerItemMenuDialog`, dependency ownership, and C++ emission policy.

## Evidence Checked

- `by-class/ClientItemMenuDialog.md`
- `by-file/ItemMenuDialogs.md`
- `by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`
- `by-class/ClientItemMenuItemList.md`
- `by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md`
- `by-class/ServerItemMenuDialog.md`
- `by-type/by-vtable/ItemMenuDialogVtables.md`
- `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`
- `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`
- `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-class/ListPane.md`
- `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`
- `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`
- `by-class/ImageButtonControlPane.md`
- `by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md`
- `by-global/g_packetSender.md`
- `by-global/g_useEpfAssets.md`
- `by-global/g_pCollectionData.md`
- `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`
- `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`
- Prior lead report: `tools/leaser/Agents/Agent-B002/research/0001BO-ItemMenuDialogs-source-quality.md`
- Local PE bytes from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, manually mapped with image base `0x00400000`; `.text`, `.rdata`, `.data`, and `.rsrc` sections were checked. Capstone disassembly was used for constructor, action handler, update helper, and related list helpers.

## Method Boundaries And Vtable Evidence

- Constructor: `0x0051b880-0x0051c309`
- Action handler: `0x0051c310-0x0051c421`
- Action button/list-selection state helper: `0x0051c430-0x0051c46d`
- Clean boundary after helper: `0x0051c46d-0x0051c470` padding, followed by `ClientItemMenuItemList` constructor at `0x0051c470`.
- Factory route: `MenuDialogFactoryHelpers` subtype `5` allocates `0x278` bytes and constructs `ClientItemMenuDialog` from payload `packet + 2`.
- Wrapper route: factory/wrapper references include `0x00517677` and `0x00517ae7`.
- Vtable stores in constructor: `0x0051b8e9`, `0x0051b8ef`, `0x0051b8f9`.
- Client vtable slices:
  - Primary: `0x0061f008`
  - Secondary: `0x0061f068`
  - Tertiary: `0x0061f098`
- Virtual row refs:
  - `0x0061f050 -> 0x0051c310` action handler
  - `0x0061f054 -> 0x0051c430` state update helper
  - `0x0061f078 -> 0x00517d80` inherited `MerchantDialogPaneActionStringVirtual`; this is present in the vtable family but is not the command-id-2 path.

The method range is source-shaped and reconstructable. The current class page can emit declaration-level C++, but exact method bodies should be emitted from an exact method child page or split constructor/action/update children.

## Source-Facing Names And Signatures

Recommended high-confidence class method names:

```cpp
ClientItemMenuDialog::ClientItemMenuDialog(const Rect &bounds,
                                           const unsigned char *payload,
                                           unsigned char menuMode);

void ClientItemMenuDialog::HandleMenuCommand(int commandId, void *context);

void ClientItemMenuDialog::UpdateActionButtonState();
```

Notes:

- The action handler uses `thiscall` and returns with `ret 8`; the second stack argument is not semantically used by the observed command paths. Keep it as `void *context` or the project's existing menu-command context type until a stronger type is found.
- The constructor third argument is stored into inherited `MerchantDialogPane` state at `this + 0x26c`; factory subtype `5` passes `0`. Source-facing name is best `menuMode` or `modeFlags`, not a client-dialog-owned field.
- The constructor payload argument is byte-addressed packet/dialog payload data. The exact project typedef may be `const unsigned char *`, `const BYTE *`, or a packet reader pointer. Use `const unsigned char *` until a packet-payload typedef is proven.

Recommended related private list names from direct companion evidence:

```cpp
ClientItemMenuItemList::ClientItemMenuItemList(unsigned char packetSubtype,
                                               unsigned int menuObjectId,
                                               unsigned short menuOptionId,
                                               ClientItemMenuDialog *owner);

void ClientItemMenuItemList::AppendAction(unsigned char actionId,
                                          unsigned short itemId,
                                          unsigned char itemStyle,
                                          const wchar_t *name);

void ClientItemMenuItemList::SendSelectedAction();

void ClientItemMenuItemList::SendAction(unsigned char actionId);

void ClientItemMenuItemList::NotifyOwnerItemActivated();
```

## Field And Layout Recommendations

Recommended `ClientItemMenuDialog` field names:

```cpp
// inherited from MerchantDialogPane or parent dialog layout:
// +0x26c: m_menuMode or inherited mode flag, set from constructor arg 3.

// ClientItemMenuDialog-owned:
unsigned int  m_menuObjectId;       // +0x270
unsigned char m_packetSubtype;      // +0x274
unsigned char m_padding275[3];      // +0x275..+0x277
```

Evidence:

- `this + 0x270` is populated from payload bytes 1..4 through the big-endian dword reader. It is used by command id `2` through `TextMenuDialog::SendMenuRequestPacket` and is passed into `ClientItemMenuItemList` as the object/dialog id.
- `this + 0x274` is populated from payload byte 0 and forwarded to `ClientItemMenuItemList` as its packet subtype/menu type byte.
- No additional client-dialog-owned anchor/layout fields were found in this method range. The input bounds/anchor pointer is forwarded through base/dialog placement helpers and stack rect construction.

Recommended `ClientItemMenuItemList` context fields:

```cpp
unsigned char m_packetSubtype;      // +0x14c
unsigned int  m_menuObjectId;       // +0x150
unsigned short m_menuOptionId;      // +0x154
ClientItemMenuDialog *m_owner;      // +0x158
```

Recommended client row layout:

```cpp
struct ClientItemMenuEntry {
    unsigned char actionId;      // +0x000, byte sent back in opcode 0x39
    unsigned char reserved;      // +0x001
    unsigned short itemId;       // +0x002
    unsigned char itemStyle;     // +0x004
    unsigned char reserved2;     // +0x005
    wchar_t name[256];           // +0x006
}; // sizeof 0x206
```

`actionId` is the safest source-facing name for the row byte because command id `1` and the list packet helpers send it back as the selected action byte. A narrower name such as `slotIndex` is tempting because population uses `LivingObjectPaneGetInventorySlotAddress`, but the server packet semantics make `actionId`/`itemActionId` the better source-facing field.

## Constructor Behavior

The constructor creates a merchant/item menu dialog with two asset/layout branches selected by `g_useEpfAssets` at `0x0066da97`.

Common payload parse:

1. Read payload byte `0` into `m_packetSubtype` at `this + 0x274`.
2. Read payload bytes `1..4` through `PacketBufferReadUInt32BE` into `m_menuObjectId` at `this + 0x270`.
3. Parse an object-status/image blob beginning at `payload + 6` with `ObjectStatusBlob::ParseTaggedStatus`.
4. After the object-status blob and fixed trailer bytes, read a big-endian UTF-8/ANSI byte length, copy that many bytes into a temporary buffer, and convert to UTF-16 with `MultiByteToWideChar`.
5. Read a big-endian `menuOptionId` and construct `ClientItemMenuItemList(m_packetSubtype, m_menuObjectId, menuOptionId, this)`.
6. Read an entry count byte and loop entries. Each entry byte is resolved through `LivingObjectPaneGetInventorySlotAddress(g_pCollectionData, entryByte)`. If the returned inventory record is populated, copy item id, item style, and display name into a `ClientItemMenuEntry` and append it through `ListPane::AppendEntry`.

Current EPF branch:

- Uses `DLGMERC1.EPF` and `PAL01.PAL`.
- Background rect is approximately `(0,0,315,353)`.
- Action/cancel/close image buttons are created around `(44,310,107,334)`, `(121,310,184,334)`, and `(198,310,261,334)`.
- Object image rect is approximately `(20,20,94,128)`.
- Text rect is approximately `(105,40,276,128)`.
- List host/control rect is approximately `(36,144,294,288)`.
- Final background/mode setup uses `DLGMERC1.EPF` and pane mode `1`.

Legacy EPD branch:

- Uses `DLGMERC1.EPD` and `NPAL8.PAL`.
- Background rect is approximately `(0,0,314,356)`.
- Action/cancel/close image buttons are created around `(44,306,116,322)`, `(121,306,193,322)`, and `(198,306,270,322)`.
- Object image rect is approximately `(35,37,72,92)`.
- Text rect is approximately `(122,37,266,133)`.
- List host/control rect is approximately `(36,141,278,285)`.
- Final background setup uses `DLGMERC1.EPD`.

Control ids:

- Control id `1` is the primary action button. `UpdateActionButtonState` enables/disables or activates/deactivates this control according to list selection count.
- Control id `6` is the list host/control used by action and update paths; the embedded `ClientItemMenuItemList` pointer is read through the host/control at `+0x108`.
- Control id `3` is used as the pending/default close/cancel control in the constructor setup.

The branch constants are valid by-* details because they explain why source has two layout tables rather than two different dialog classes.

## Menu Command Semantics

`ClientItemMenuDialog::HandleMenuCommand` switches on command id:

- Command id `1`: send selected client item-menu action.
  - Fetch control id `6` through the dialog control manager at `this + 0x1fc`.
  - Read embedded list pointer at control/list host `+0x108`.
  - If selected index at list `+0x134` is nonnegative, call `ListPane::GetSelectedEntry`.
  - Use selected row byte `ClientItemMenuEntry::actionId`.
  - Build opcode `0x39` packet:
    - byte `0`: `0x39`
    - byte `1`: `ClientItemMenuItemList::m_packetSubtype`
    - bytes `2..5`: `m_menuObjectId`, big-endian
    - bytes `6..7`: `m_menuOptionId`, big-endian
    - byte `8`: selected `actionId`
  - Send length `9` through `Socket::QueueAndSendPacket(g_packetSender, packet, 9)`.
  - Close the dialog through the inherited/dialog close helper at `0x0049dad0`.

- Command id `2`: send shared request/cancel packet through `TextMenuDialog::SendMenuRequestPacket`.
  - Direct call target is `0x00517ec0`, not `0x00517d80`.
  - The helper builds opcode `0x43`, subtype byte `1`, and `UInt32BE(this + 0x270)`, sends length `6`, then closes.
  - This is a shared text/menu request helper reused by text/input/item/spell/argumented dialog action handlers. It should not be renamed as client-item-specific code.

- Command id `3`: close the dialog only.

- Other command ids: no action.

Rejected stale alternative:

- `0x00517d80` is not the command id `2` helper. It is the inherited `MerchantDialogPaneActionStringVirtual` present in the vtable family at `0x0061f078`. Keep it documented as inherited vtable glue or a separate inherited virtual, but do not route command id `2` to it.

## Packet And Helper Ownership

The following dependencies should remain owned by their existing classes/files and should not be attributed to `ClientItemMenuDialog` or `ItemMenuDialogs`:

- `TextMenuDialog::SendMenuRequestPacket` at `0x00517ec0`: shared `TextMenuDialogs` helper for opcode `0x43`.
- `MerchantDialogPaneActionStringVirtual` at `0x00517d80`: inherited virtual, not command id `2`.
- `Socket::QueueAndSendPacket` at `0x00574bb0`: `Socket`/network queue helper.
- `g_packetSender`: global socket pointer; current best type is `Socket *`.
- `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `PacketBufferWriteUInt32BE`: scalar packet writers.
- `PacketBufferReadUInt16BE`, `PacketBufferReadUInt32BE`, and the byte/char read helper around `0x00575470`: packet scalar readers.
- `ListPane::AppendEntry`, `ListPane::GetSelectedEntry`, `ListPane::GetSelectionCount`: generic `ListPane` methods.
- `ObjectImageControlPane`, `ImageButtonControlPane`, `StaticTextControlPane`, and scroll/list-host control constructors: UI control dependencies.
- `ObjectStatusBlob::ParseTaggedStatus`: object image/status parser.
- `LivingObjectPaneGetInventorySlotAddress`: inventory-slot lookup used to materialize client menu rows from payload bytes.
- `g_useEpfAssets`: current/new EPF asset selector.
- `g_pCollectionData`: local player/UserPane/collection state used by inventory lookup.

These exclusions are important because the existing docs mention stale uncertainty around packet/send helper fields and action table semantics. The command/list code is item-menu-specific, but the packet writers, socket sender, object image parser, and text-menu cancel/request helper are shared infrastructure.

## Relationship To ServerItemMenuDialog

`ClientItemMenuDialog` and `ServerItemMenuDialog` share the `ItemMenuDialogs` source family, factory/subtype pattern, DLGMERC layout assets, object image/text/list construction shape, and command ids `1`, `2`, and `3`.

The key semantic split:

- Server item-menu command id `1` serializes selected row text/string data for opcode `0x39`.
- Client item-menu command id `1` serializes a selected one-byte `ClientItemMenuEntry::actionId` for opcode `0x39`.
- Both use command id `2` for the shared opcode `0x43` request/cancel helper and command id `3` for close-only behavior.

This supports keeping both classes in `ItemMenuDialogs.cpp`, with separate private row/list types and exact child method pages.

## Heuristic / Inference Reanalysis And Validation

Resolved:

- Source owner/emitter: [UID:0000KF] `ItemMenuDialogs` remains correct. Factory subtype `5`, vtable slices, exact method range, and exclusive `ClientItemMenuItemList` coupling all point to the item-menu source family.
- Source file route: `NexusTK/ui/dialogs/ItemMenuDialogs.cpp` is the best current source route. A physical fold into `ItemDialogs.cpp` should remain only as a historical/source-packaging caveat.
- No separate static "item action table" was found in the constructor. The server payload supplies a list of one-byte entries, and the client resolves each byte through local inventory state before appending visible rows.
- Packet helper fields are resolved: `this + 0x270` is the menu object/dialog id, `this + 0x274` is the packet subtype/menu type byte, list `+0x154` is the menu option id, and selected row `+0` is the client action byte.
- Command id `2` helper is resolved as `TextMenuDialog::SendMenuRequestPacket` at `0x00517ec0`, not `MerchantDialogPaneActionStringVirtual`.
- Layout/anchor fields: no new client-dialog-owned anchor fields were found; layout is stack/local rect construction plus inherited dialog/base placement.
- Constructor mode flag: stored to inherited state at `+0x26c`; factory passes `0`.
- Vtable slices are already stable through `ItemMenuDialogVtables` and support source routing.

Remaining open questions and best directions:

- Exact original method spellings are not recoverable from the checked evidence. The recommended names above are high-probability source-facing names, but original code may have used names like `Action`, `OnCommand`, `UpdateButtonState`, or `EnableOkButton`.
- The project-specific rectangle type name was not recovered in this pass. Use the existing docs' canonical rectangle type if one exists; otherwise keep a conservative `Rect`/`RECT` placeholder in draft C++ until implementation validation.
- The byte reader helper around `0x00575470` is still less cleanly named than the big-endian word/dword helpers. It behaves as a one-byte/char load in constructor payload parsing. Avoid inventing a strong global name unless support docs already settle it.
- Exact inherited button vtable method names for slots `+0x4c` and `+0x50` were not resolved here. The behavior is selected-list enable/disable or active/inactive button state; source docs should phrase it as enabling/disabling the action button unless the control class docs provide exact names.

None of these remaining points block declaration-level C++ on the class page or first-draft method C++ on an exact child page.

## C++ Readiness Recommendation

`ClientItemMenuDialog` should remain `RECONSTRUCTABLE:TRUE` with owner/emitter [UID:0000KF] `ItemMenuDialogs`.

Class-page emission should be declaration-level only. Full constructor/action/update method bodies should be emitted by a new exact child page, preferably:

- `by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md`

Alternative split if the supervisor wants smaller exact children:

- `0x0051b880-0x0051c309.ClientItemMenuDialogConstructor.md`
- `0x0051c310-0x0051c421.ClientItemMenuDialogHandleMenuCommand.md`
- `0x0051c430-0x0051c46d.ClientItemMenuDialogUpdateActionButtonState.md`

Class-level first-draft C++:

```cpp
class ClientItemMenuDialog : public MerchantDialogPane
{
public:
    ClientItemMenuDialog(const Rect &bounds,
                         const unsigned char *payload,
                         unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    unsigned int m_menuObjectId;      // +0x270
    unsigned char m_packetSubtype;    // +0x274
    unsigned char m_padding275[3];    // +0x275..+0x277

    [[CHILDREN]]
};
```

No-code/defer proof for method bodies on the class page:

- The class page is not an exact executable range and currently represents class-level structure. The exact constructor/action/update executable body range is `0x0051b880-0x0051c46d` inside the broader [UID:0001BO] aggregate. Emitting full method bodies from both the class page and a later exact method child would duplicate source. Therefore, the class page should emit declarations and field/source-shape notes only; exact method bodies should wait for a child page or split child pages.

First-draft method C++ readiness:

- The method range is now ready for first-draft C++ after child creation. Remaining uncertainties are minor source spelling and control-method name issues, not behavioral blockers.

## Score And Metadata Recommendation

Target `ClientItemMenuDialog.md`:

- Recommend `COMPLETION:88`
- Recommend `CONFIDENCE:89`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `CANONICAL_OWNER:0000KF`
- Keep `EMITTER_UIDS:0000KF`
- Keep source route under `ItemMenuDialogs.cpp`

Justification:

- The previous blockers around command semantics, packet helper fields, action table behavior, layout branches, class/list coupling, and inherited helper confusion are now resolved or reduced to explicit nonblocking caveats.
- The score should remain below `95` because original symbol spellings, exact control vtable method names, and exact method-body child routing still require implementation/validator work.

## Recommended Target Doc Changes

Apply these changes to `by-class/ClientItemMenuDialog.md` during a supervisor-approved implementation callback:

1. Update status metadata to `88/89`, still reconstructable, owner/emitter [UID:0000KF].
2. Replace stale action-table language with packet-payload/list-row wording:
   - The constructor does not use a static item action table.
   - It reads one-byte entries from the packet, resolves each through `LivingObjectPaneGetInventorySlotAddress(g_pCollectionData, entryByte)`, and appends visible rows with item id/style/name plus the original action byte.
3. Add a field table:
   - inherited `+0x26c`: menu/mode flag from constructor arg 3
   - `+0x270`: `m_menuObjectId`
   - `+0x274`: `m_packetSubtype`
   - `+0x275..+0x277`: padding
4. Add method table:
   - `0x0051b880-0x0051c309`: `ClientItemMenuDialog::ClientItemMenuDialog`
   - `0x0051c310-0x0051c421`: `ClientItemMenuDialog::HandleMenuCommand`
   - `0x0051c430-0x0051c46d`: `ClientItemMenuDialog::UpdateActionButtonState`
5. Add command semantics:
   - id `1`: selected row action send, opcode `0x39`, length `9`, then close
   - id `2`: `TextMenuDialog::SendMenuRequestPacket`, opcode `0x43`, length `6`, then close
   - id `3`: close only
6. Explicitly reject the stale `0x00517d80` command-id-2 interpretation:
   - `0x00517d80` is inherited `MerchantDialogPaneActionStringVirtual` vtable glue, not the command id `2` path.
7. Add current/legacy layout notes:
   - EPF branch: `DLGMERC1.EPF`/`PAL01.PAL`
   - EPD branch: `DLGMERC1.EPD`/`NPAL8.PAL`
   - Include approximate rects for background, object image, text, list, and three buttons.
8. Add source placement:
   - Preferred: `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`
   - Caveat: possible legacy fold into `ItemDialogs.cpp`, not a blocker.
9. Add class-page C++ policy:
   - Emit declaration-level C++ only.
   - Exact method bodies should emit from `0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md` or smaller exact children.

## Recommended Support Doc Updates

`by-file/ItemMenuDialogs.md`:

- Add B013 evidence that `ClientItemMenuDialog` action semantics are now resolved.
- Document client command id `1` as selected action-byte opcode `0x39`; server command id `1` remains selected string/text opcode `0x39`.
- Document shared command id `2` helper as `TextMenuDialog::SendMenuRequestPacket` at `0x00517ec0`.
- Document dependency exclusions for `Socket`, `PacketBuffer`, `ObjectStatusBlob`, `ListPane`, and UI controls.
- Mention exact child need for `0x0051b880-0x0051c46d`.

`by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`:

- Reclassify as a split/index over server-dialog methods, server-list methods, client-dialog methods, and the adjacent client-list sibling after exact children are created.
- Do not emit broad aggregate C++ from this page once exact children exist.
- Incorporate factory subtype `4/5`, vtable families, DLGMERC layout branches, opcode semantics, and dependency exclusions.

`by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md`:

- Add or confirm row layout `ClientItemMenuEntry`.
- Add or confirm context fields `+0x14c`, `+0x150`, `+0x154`, `+0x158`.
- Rename raw helper roles to `AppendAction`, `SendSelectedAction`, `SendAction`, and `NotifyOwnerItemActivated`.
- Cross-link to `ClientItemMenuDialog` command id `1`.

`by-class/ClientItemMenuItemList.md`:

- Mirror the private list/row details above and mark it as an `ItemMenuDialogs.cpp` private companion class.

`by-type/by-vtable/ItemMenuDialogVtables.md`:

- Add note that client vtable row `0x0061f078 -> 0x00517d80` is inherited `MerchantDialogPaneActionStringVirtual` and should not be confused with command id `2`.

`by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`:

- If not already present, add cross-reference that `ClientItemMenuDialog::HandleMenuCommand(2)` calls `TextMenuDialog::SendMenuRequestPacket`.

## Exact Coverage Row Text

Do not edit coverage files during the report pass. Suggested supervisor-owned replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md) : reconstructable : 88% : strong : B013 source-quality pass resolves client item-menu class source shape under [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md): factory subtype `5` route, `0x278` object size, constructor mode byte stored at inherited `+0x26c`, client fields `m_menuObjectId` at `+0x270` and `m_packetSubtype` at `+0x274`, current/legacy `DLGMERC1.EPF`/`DLGMERC1.EPD` layout branches via `g_useEpfAssets`, object-status/text/list payload parsing, `ClientItemMenuItemList` construction and row population through `LivingObjectPaneGetInventorySlotAddress`, command ids `1` selected opcode `0x39` action send, `2` shared `TextMenuDialog::SendMenuRequestPacket` opcode `0x43` cancel/request, `3` close, control ids `1` and `6` update behavior, vtable slices, dependency ownership exclusions, and declaration-level C++ readiness; exact method bodies should emit from an exact `0x0051b880-0x0051c46d` child rather than from the class page.
```

Suggested supervisor-owned replacement row for `by-file/-coverage-report.md`:

```markdown
- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) : reconstructable : 88% : strong : Server/client item menu dialogs and private list classes with vtable/layout anchors, factory subtype routes, current/legacy DLGMERC asset branches, server-string versus client-action opcode `0x39` semantics, shared `TextMenuDialog::SendMenuRequestPacket` cancel/request helper, object-image/ListPane/PacketBuffer/Socket dependency exclusions, B002 server/client row-layout corrections, and B013 ClientItemMenuDialog source-shape resolution. Standalone `ItemMenuDialogs.cpp` remains the preferred route with a documented possible fold into `ItemDialogs.cpp`; exact method bodies should live on source-bearing child pages rather than broad aggregates.
```

Suggested supervisor-owned replacement row for `by-memory/-coverage-report.md` if updating the aggregate route:

```markdown
    - [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) 0x0051a520-0x0051c46d | split-index | ItemMenuDialogs executable split index : ignored/non-emitting : 88% : very-strong : B002/B013 source-quality passes reclassify the aggregate as a non-emitting split/index over ServerItemMenuDialog methods, existing ServerItemMenuItemList child [UID:0001BP], ClientItemMenuDialog methods, and adjacent ClientItemMenuItemList sibling [UID:0001BQ]. Evidence verifies factory subtype 4/5 routes, vtable families, current/legacy DLGMERC asset branches, object-status/text/list packet parsing, opcode `0x39` server-string/client-action semantics, shared `TextMenuDialog::SendMenuRequestPacket` opcode `0x43` cancel/request path, control ids `1`/`6`/`7`, object-image/ListPane/PacketBuffer/Socket dependency exclusions, padding boundaries, and row-layout corrections; source C++ should be emitted by exact child pages under [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), not by this aggregate.
```

Suggested supervisor-owned replacement row for `by-memory/-coverage-report.md` if updating the client list companion:

```markdown
    - [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) 0x0051c470-0x0051ca3c | class-method/raw-helper cluster | ClientItemMenuItemList : reconstructable : 88% : strong : B002/B013 source-quality evidence resolves the private client item-menu row/list companion under ItemMenuDialogs: constructor refs only from ClientItemMenuDialog, context fields `m_packetSubtype` `+0x14c`, `m_menuObjectId` `+0x150`, `m_menuOptionId` `+0x154`, and `m_owner` `+0x158`, raw append helper `ClientItemMenuItemList::AppendAction`, selected/explicit opcode `0x39` action packet helpers, `0x206` row layout with `actionId` `+0x000`, `itemId` `+0x002`, `itemStyle` `+0x004`, and `name[256]` `+0x006`, activation thunk to owner item-state logic, current/legacy draw paths, vtable stores/slots, shared destructor glue exclusion, padding boundaries, and first-draft C++ readiness; raw helper starts remain non-IDA-functions/no-direct-xref caveat.
```

Suggested supervisor-owned replacement row for `by-class/-coverage-report.md` if updating the list class:

```markdown
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) : reconstructable : 88% : strong : Client item-menu row list attached to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md); B002/B013 source-quality evidence resolves constructor-only coupling from ClientItemMenuDialog, context fields `+0x14c/+0x150/+0x154/+0x158`, `0x206` `ClientItemMenuEntry` layout, raw append and selected/explicit opcode `0x39` packet helper names, activation/draw virtuals, vtable stores/slots, shared destructor glue exclusion, current/legacy draw dependencies, and first-draft C++ readiness while keeping raw helper no-function/no-direct-xref caveat.
```

## Validator Needs

Expected validation commands after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00002P-ClientItemMenuDialog-class-source-quality-removed.md](00002P-ClientItemMenuDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result:

- Validator should report success for edited files, with no unresolved metadata or broken UID references.
- Generated `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp` should include declaration-level class coverage for [UID:00002P] without duplicating the broad [UID:0001BO] aggregate method bodies.
- Once an exact `0x0051b880-0x0051c46d` child exists, generated C++ should place constructor/action/update bodies under the child rather than the class page.

## IDA Rename / Type / Comment Recommendations

High confidence:

- `sub_51B880` -> `ClientItemMenuDialog::ClientItemMenuDialog`
- `sub_51C310` -> `ClientItemMenuDialog::HandleMenuCommand`
- `sub_51C430` -> `ClientItemMenuDialog::UpdateActionButtonState`
- `sub_51C4E0` -> `ClientItemMenuItemList::AppendAction`
- `sub_51C550` -> `ClientItemMenuItemList::SendSelectedAction`
- `sub_51C610` -> `ClientItemMenuItemList::SendAction`
- `sub_517EC0` -> `TextMenuDialog::SendMenuRequestPacket`
- `sub_5A3870` -> `LivingObjectPaneGetInventorySlotAddress`

Type recommendations:

- Add `ClientItemMenuDialog` field types:
  - `+0x270 unsigned int m_menuObjectId`
  - `+0x274 unsigned char m_packetSubtype`
- Add `ClientItemMenuItemList` field types:
  - `+0x14c unsigned char m_packetSubtype`
  - `+0x150 unsigned int m_menuObjectId`
  - `+0x154 unsigned short m_menuOptionId`
  - `+0x158 ClientItemMenuDialog *m_owner`
- Add `ClientItemMenuEntry` struct:
  - `+0x000 unsigned char actionId`
  - `+0x002 unsigned short itemId`
  - `+0x004 unsigned char itemStyle`
  - `+0x006 wchar_t name[256]`

Comment recommendations:

- At `0x0051c310`: "Client item-menu command handler: command 1 sends selected action byte in opcode 0x39, command 2 calls shared opcode 0x43 request helper, command 3 closes."
- At `0x0051c34d`: "Calls TextMenuDialog::SendMenuRequestPacket; not MerchantDialogPaneActionStringVirtual."
- At `0x0051c363`: "Selected client action path; reads ClientItemMenuItemList from control id 6 host +0x108."
- At `0x0051b880`: "Ctor parses item-menu payload, builds current/legacy DLGMERC layout, resolves action bytes through local inventory state."
- At vtable entry `0x0061f078`: "Inherited MerchantDialogPaneActionStringVirtual slot; not the command id 2 path."

## Exact Implementation Checklist

For a later supervisor-approved implementation callback:

1. Edit `by-class/ClientItemMenuDialog.md`.
2. Set recommended score metadata to `88/89`, keeping reconstructable owner/emitter [UID:0000KF].
3. Add the method table, field table, command semantics, payload parse, current/legacy layout branches, source-placement note, dependency exclusions, and class-page C++ policy from this report.
4. Add declaration-level C++ only; do not paste full constructor/action/update bodies into the class page.
5. Add or update support notes in `by-file/ItemMenuDialogs.md`.
6. Add or update support notes in [UID:0001BO] and [UID:0001BQ] if supervisor wants support docs updated in the same callback.
7. Apply supervisor-owned coverage rows exactly as needed; do not let B-agent report work directly edit coverage files.
8. Run validators listed above.
9. If implementation includes child creation, create exact `ClientItemMenuDialogMethods` child or split child pages before emitting method bodies.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00002P-ClientItemMenuDialog-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00002P"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00002P-ClientItemMenuDialog-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00002P-ClientItemMenuDialog-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00002P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
