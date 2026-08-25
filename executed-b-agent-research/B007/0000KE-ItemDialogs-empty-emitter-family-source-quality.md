** TARGET-REPORT-UID:0000KE **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000KE] ItemDialogs Empty-Emitter Family Source-Quality Report

Agent: Agent-B007  
Assignment: B007-implement-0000KE-ItemDialogs-empty-emitter-family-20260630  
Implementation callback scope: accepted same-report details applied to the target/support by-* pages only. Generated outputs were refreshed only through the validator.

## Status

Implementation callback complete and ready for supervisor validation.

This revision preserves the useful current MCP inventory from the rejected draft, removes the rejected marker-only rationale for source-authored method clusters, corrects the [UID:00033T] raw-helper contradiction, and converts the in-scope empty emitters into one of three dispositions:

- first-draft source-facing C++ ready for callback insertion,
- concrete same-callback split/support declaration plan that makes C++ insertion implementable, or
- rare no-code proof with exact evidence and rejected alternatives.

IDA MCP remained available during this revision. Current session evidence is from `supervisor_resume_20260629` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The direct MCP correction for [UID:00033T] is that `lookup_funcs 0x004af4f0` still reports no modeled IDA function, but `get_bytes 0x004af4f0 size 128` returns a complete prologue/cookie/packet-write/send/`ret 4` raw helper body. Therefore the earlier report's padding/no-code conclusion was invalid.

Implementation callback completed on 2026-06-30. The accepted split plan used the temporary-reference workflow; validators assigned child UIDs `0004BM` through `0004BV`. [UID:00033T] was preserved as retained raw helper code at current `86/90`, owner/emitter [UID:000008], reconstructable true, and blank formal C++.

## Required Empty-Emitter Inventory

Target page: `by-file/ItemDialogs.md`  
Root family UID: `[UID:0000KE]`

| UID | Symbol / range | Current issue | Revised disposition |
|---|---:|---|---|
| 0000KE | `ItemDialogs.md` root | root family has empty child emitters | Keep owner/root; add score rationale and route implementation through child updates below |
| 00033Q | `0x004ae4c0-0x004aea7d` AddItemDialog cluster | source-authored multi-function cluster | Split/support plan: parent emits `[[CHILDREN]]`; create exact child functions for ctor/dtor/action/update in same callback |
| 000317 | `0x004aea80-0x004aeaaf` AddItemDialog close packet handler | source-authored single method | Insert first-draft C++ |
| 00033S | `0x004af040-0x004af4b7` AddItemWithCountDialog cluster | source-authored multi-function cluster | Split/support plan: parent emits `[[CHILDREN]]`; create exact child functions for ctor/action/update in same callback |
| 000318 | `0x004af4c0-0x004af4ef` AddItemWithCountDialog close packet handler | source-authored single method | Insert first-draft C++ |
| 00033T | `0x004af4f0-0x004af570` AddItemWithCountDialogSubmitPacketHelper | raw helper not modeled as an IDA function | Treat as documented retained raw packet helper; keep current `86/90`, preserve blank formal C++ as source-integration disposition, and reject padding/no-code reclassification |
| 00033U | `0x004af570-0x004afb7f` MixItemDialog cluster | source-authored multi-function cluster plus switch-table tail | Split/support plan: parent emits `[[CHILDREN]]`; create exact child functions for ctor/action and document switch table tail |
| 000319 | `0x004afcc0-0x004afe37` MixItemDialog add-row helper | source-authored helper method | Insert first-draft C++ |
| 00031A | `0x004afe40-0x004afff6` MixItemDialog quantity callback | source-authored callback method | Insert first-draft C++ |
| 0002U1 | `0x004b0000-0x004b0117` AddMixingItemDialog constructor | source-authored method | Insert first-draft C++ |
| 0002U2 | `0x004b0120-0x004b0489` AddMixingItemDialog action handler | source-authored method | Insert first-draft C++ |
| 00033X | `0x004b0870-0x004b087a` active MixItemDialog clear helper | source-authored/file helper form was ambiguous | Choose one exact form: file-local `static void ClearActiveMixItemDialog()` |
| 0002AY | `0x0069b328-0x0069b32f` singleton globals | initializer proof stale | Insert zero-initialized globals; reject old `0xffffffff` assumption |

## Current MCP Evidence Used

Session and availability:

- `server_health` status `ok`.
- Active worker session: `supervisor_resume_20260629`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Module: `NexusTK.exe`, imagebase `0x400000`.
- Auto-analysis ready: true. Hex-Rays ready: true. Strings cache ready: true.

Function lookup evidence:

- `lookup_funcs 0x004ae4c0` -> function size `0x435`.
- `lookup_funcs 0x004ae900` -> function size `0x29`.
- `lookup_funcs 0x004ae930` -> function size `0x10a`.
- `lookup_funcs 0x004aea40` -> function size `0x3d`.
- `lookup_funcs 0x004aea80` -> function size `0x30`.
- `lookup_funcs 0x004aeab0` -> function size `0x6`.
- `lookup_funcs 0x004aeac0` -> no function.
- `lookup_funcs 0x004af040` -> function size `0x331`.
- `lookup_funcs 0x004af380` -> function size `0xfa`.
- `lookup_funcs 0x004af480` -> function size `0x37`.
- `lookup_funcs 0x004af4c0` -> function size `0x30`.
- `lookup_funcs 0x004af4f0` -> no modeled IDA function. This is negative route/modeling evidence only; it is not padding proof for raw-helper targets.
- `lookup_funcs 0x004af570` -> function size `0x33f`.
- `lookup_funcs 0x004af8b0` -> function size `0x2b5`.
- `lookup_funcs 0x004afb80` -> no function.
- `lookup_funcs 0x004afcc0` -> function size `0x178`.
- `lookup_funcs 0x004afe40` -> function size `0x1b7`.
- `lookup_funcs 0x004b0000` -> function size `0x118`.
- `lookup_funcs 0x004b0120` -> function size `0x36a`.
- `lookup_funcs 0x004b0870` -> function size `0xb`.
- `lookup_funcs 0x0069b328` and `0x0069b32c` -> no functions.

Xref evidence:

- `xrefs_to 0x004aea80` -> data xref at `0x00619efc`.
- `xrefs_to 0x004af4c0` -> data xref at `0x0061a05c`.
- `xrefs_to 0x004afe40` -> code xref at `0x004b02c4`, data/callback stores at `0x004afd68` and `0x004b0376`.
- `xrefs_to 0x004b0120` -> data xref at `0x0061a16c`.
- `xrefs_to 0x004b0870` -> code xref at `0x005fe593`; body clears `0x0069b32c`.
- `xrefs_to 0x0069b328` -> references from `0x004ad670`, `0x004ade32`, `0x004ae8d2`, `0x004ae91a`, `0x004aeab0`, `0x004b0930`, `0x004b0990`.
- `xrefs_to 0x0069b32c` -> references from `0x004af5c7`, `0x004af5ce`, `0x004b0870`, `0x004b0ad6`, `0x005a4e03`, `0x005a5fbb`.
- No ordinary xrefs found to `0x004afcc0`, `0x004b0000`, `0x004af4f0`, `0x004afb80`, `0x004aeab0`, or `0x004aeac0`. For `0x004af4f0`, this agrees with the current [UID:00033T] retained-helper/no-route docs, not with a padding conclusion.

Callee evidence:

- `0x004aea80` calls `0x0049eb90`.
- `0x004af4c0` calls `0x0049eb90` and `0x0049dad0`.
- `0x004afcc0` calls `0x005a3870`, `0x004f4aa0`, `0x004f4a80`, `0x004f0350`, `0x00530640`, `_wcscpy_s`, `0x004f3c50`, and security-cookie helpers.
- `0x004afe40` calls `0x005a3870`, `0x00582b20`, `0x00582d20`, `0x00583280`, `0x00584cf0`, `0x00584c40`, `0x00584540`, `0x00584990`, `0x00582b70`, `_wcscpy_s`, `0x004f3c50`, and security-cookie helpers.
- `0x004b0000` calls `0x004ae4c0`, `0x004f3bd0`, `0x004f3dc0`, and `0x004f3d60`.
- `0x004b0120` calls close helpers, selection/list helpers, packet helpers, `0x005a3870`, `0x004afe40`, allocation helpers, `0x004f0350`, `0x00530640`, `_wcscpy_s`, `0x004f3c50`, and security-cookie helpers.
- `0x004b0870` has no callees.

Decompiler evidence:

- `0x004ae930`: action id `1` iterates selected rows from child selector `3`, reads row byte `+0x00`, builds packet `0x4A/1`, writes owner/member value at `this+0x26c`, writes selected slot, sends 7 bytes through `dword_67A7EC`, then closes. Action id `2` closes.
- `0x004af380`: action id `1` reads selected row from child selector `4`, parses `"%hu"`, clamps count to `0xFF` / 255, builds packet `0x4A/2`, writes `this+0x26c`, `this+0x270`, selected slot, and count, sends 8 bytes, then closes. Action id `2` closes.
- `0x004af570`: constructor publishes `unk_69B32C` as `this`, or clears it on failure, installs MixItemDialog vtables, constructs UI and `MyItemListPane`, and clears rows.
- `0x004aea80`: checks packet bytes `0x42/0x04`, adjusts `this - 0xa0`, calls `sub_49EB90`, invokes primary vtable slot `+24`, returns 0.
- `0x004af4c0`: checks packet bytes `0x42/0x04`, adjusts `this - 0xa0`, calls `sub_49EB90`, calls `sub_49DAD0`, returns 0.
- `0x004afcc0`: helper takes `(char itemId, short itemSerial, wchar_t *name, char style)`, obtains mix list selector `5`, calls `sub_5A3870(dword_67A748, itemId)`, appends directly when the referenced count is <= 1, otherwise allocates a 24-byte `DoubleParamMemberFunctionObject` callback targeting `0x004afe40`, then constructs `NumberInputDialog` resource `218` with max count from offset `+488`.
- `0x004afe40`: callback obtains mix list selector `5`, resolves slot with `sub_5A3870(dword_67A748, itemId)`, formats quantity text, copies item name text, and appends a row containing item id/serial/style/count.
- `0x004b0000`: constructor calls AddItemDialog base with `(0,1)`, installs AddMixingItemDialog vtables, stores owner at `+624` / `0x270`, gets owner selector `5` list and this selector `3` list, and removes rows whose first byte already appears in the mix list.
- `0x004b0120`: action id `1` iterates selected rows from selector `3`; stackable rows route through `0x004afe40` directly or through a `NumberInputDialog` callback, non-stack rows append directly; action id `2` closes.

Disassembly evidence:

- `0x004b0870` is exactly `mov dword ptr unk_69B32C, 0; retn`.
- `0x004aeab0` is exactly `mov eax, dword ptr unk_69B328; retn`.
- `0x004af8b0` switch table at `0x004af8f3` has destinations `0x004af8fa`, `0x004af9f9`, `0x004afa3a`, and `0x004afb3b`; case 3 writes packet `0x6B`, count, item ids, optional quantities, sends through `dword_67A7EC`, then closes. No switch entry targets `0x004afb80`.

Current byte/value initializer evidence:

- `get_bytes 0x0069b328 size 8` -> `0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0`.
- Therefore `0x0069b328` and `0x0069b32c` are zero-initialized 32-bit globals in the current database.
- The earlier historical `0xff` / `0xffffffff` singleton initializer assumption is stale and rejected for this report.

[UID:00033T] current raw-helper evidence:

- Current by-memory page `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md` is `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000008`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000008`, and documents the range as a raw packet helper body, not padding.
- Current executed Rule 26 report `executed-b-agent-research/B011/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md` records raw PE/Capstone evidence for a contiguous `0x80` / 128-byte body with prologue, security cookie, packet writers, `g_packetSender`, `Socket::QueueAndSendPacket`, and `ret 4`.
- Current MCP `get_bytes 0x004af4f0 size 128` returns bytes beginning `55 8b ec 83 ec 24 ...` and ending `... 8b e5 5d c2 04 00`, matching the documented prologue and `ret 4` raw helper shape.
- Current MCP `xrefs_to 0x004af4f0` returns zero xrefs; `xrefs_to 0x004af380` returns the vtable data route at `0x0061a034`; this supports the documented no-route retained helper plus active inline action handler split.
- The helper serializes opcode `0x4A`, subtype `2`, `this+0x26c` as the exchange/session id, `this+0x270` as the selected item/type byte, and stack argument count as the final byte, sends exactly eight bytes, and writes a scratch zero at offset `8` outside the sent payload.

## Score And Metadata Recommendations

Scores are recommendations for the implementation callback. "Before" is the current by-* metadata read for this revision. "After" is the expected metadata after applying the exact dispositions below and scoped validators.

| UID | Before C/F | After C/F | Rationale |
|---|---:|---:|---|
| 0000KE | 90/87 | 90/88 | Current by-file root already has the correct `90/87` baseline and already incorporates [UID:00033T] as a raw helper. The callback should not raise completion merely for report cleanup, but confidence can move to `88` after all listed empty-emitter dispositions are reconciled and the stale padding contradiction is removed. |
| 00033Q | 85/89 | 86/90 | Before: current aggregate contains four real functions with blank formal C++. After: parent remains owner/range container with `[[CHILDREN]]` and exact child file/range metadata below; completion moves only one point because child files still carry the actual method bodies. |
| 000317 | 86/88 | 88/90 | Before: empty source-authored method with known vtable/event route. After: packet-close method has direct MCP-backed C++ from bytes `0x42/0x04`, close helper call, virtual close dispatch, and vtable xref. |
| 00033S | 85/89 | 86/90 | Before: current aggregate contains constructor/action/update functions and already documents [UID:00033T] inline duplication. After: parent gets `[[CHILDREN]]`, exact child split metadata, and explicit retained-helper relationship preservation. |
| 000318 | 86/88 | 88/90 | Before: empty source-authored method. After: packet-close method has direct MCP-backed C++ from bytes `0x42/0x04`, two close calls, and vtable xref. |
| 00033T | 86/90 | 86/90 | Current state is already correct after B011 Rule 26 execution: retained raw helper, owner [UID:000008], emitter [UID:000008], blank formal C++ due no static route plus active inline duplicate in [UID:00033S]. This report must preserve that state and reject the stale padding/no-code claim. |
| 00033U | 85/88 | 86/90 | Before: aggregate contains constructor/action handler plus switch-table tail. After: parent gets `[[CHILDREN]]`, exact child split metadata, and table-tail documentation. |
| 000319 | 86/88 | 88/90 | Before: empty source-authored helper. After: helper method has source-facing C++ for direct append and quantity prompt callback setup, with exact callee/xref support. |
| 00031A | 86/88 | 88/90 | Before: empty source-authored callback. After: callback has source-facing C++ for selected quantity row insertion and string copy/format behavior. |
| 0002U1 | 85/88 | 88/90 | Before: empty constructor. After: constructor has source-facing C++ for base construction, owner storage, and duplicate-removal list filtering. |
| 0002U2 | 85/88 | 88/90 | Before: empty action handler. After: action handler has source-facing C++ for selected-row iteration, direct append/prompt branch, and close path. |
| 00033X | 85/90 | 88/92 | Before: helper form is documented but formal helper body remains empty. After: exact file-local helper is chosen from zero-argument body and xref shape. |
| 0002AY | 88/90 | 89/92 | Before: current singleton page is strong but this report had stale initializer rationale. After: current bytes prove both singleton globals initialize to zero, so exact declarations can be inserted and the old `-1` assumption is rejected. |

Root metadata recommendation:

- `[UID:0000KE]` remains the owner/root family for ItemDialogs.
- Keep the family score at `90` after callback completion; do not claim higher because several first-draft C++ blocks still use source-facing helper declarations for external UI/list/packet APIs.
- No source-placement move is recommended outside `by-file/ItemDialogs.md`.

Support metadata recommendation:

- Mark split-parent pages (`00033Q`, `00033S`, `00033U`) as aggregate/container pages with explicit `[[CHILDREN]]` code blocks.
- Create child pages in the same implementation callback for each named real function below.
- Keep helper declarations local to `ItemDialogs.md` unless the supervisor chooses a broader UI support pass later; this callback can use forward declarations and source-facing helper names without moving ownership.

## Owner, Emitter, And Source Placement Decisions

Owner:

- `[UID:0000KE]` remains the correct ItemDialogs family owner.
- `[UID:0002AY]` owns the two ItemDialogs singleton globals because all current references are ItemDialogs dialog-family globals and the current bytes prove ordinary zero initialization.
- `[UID:00033X]` owns the file-local active MixItemDialog clear helper because the body only writes `g_pMixItemDialog` and has no `this` dependency.

Emitter:

- Class/aggregate marker blocks must include `[[CHILDREN]]`.
- Source-authored single methods must emit source-facing first-draft C++.
- `00033T` must not be reclassified as padding. It remains the current documented retained raw helper: `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:000008], formal C++ blank because no static route reaches the helper and [UID:00033S] contains the active inline send.

Source placement:

- All implementation text belongs in `by-file/ItemDialogs.md`.
- The exact helper names below are source-facing first-draft names; they are intentionally local to the ItemDialogs callback and do not require a separate support file.

## Required Formal Dispositions

### [UID:00033Q] AddItemDialog Cluster

Disposition: concrete same-callback split/support declaration plan.

Reasoning:

- Current MCP proves four real functions in the aggregate range: ctor `0x004ae4c0`, dtor `0x004ae900`, action handler `0x004ae930`, and update method `0x004aea40`.
- A single method-shaped C++ block would conflate constructor, destructor, action handler, and UI update code.
- This is not a no-code case. The functions are source-authored and implementable after splitting.

Exact parent formal insertion:

```cpp
[[CHILDREN]]
```

Exact child split plan for implementation callback:

| Proposed child file | Range | Metadata | Source-facing name | Required content |
|---|---:|---|---|---|
| `by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md` | `0x004ae4c0-0x004ae8f5` | new UID TBD by validator; `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000007`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000007`, `Nested:0` | `AddItemDialog::AddItemDialog(unsigned char packetType, unsigned char mode)` | Constructor C++ from decompile/list construction evidence. |
| `by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md` | `0x004ae900-0x004ae929` | new UID TBD by validator; `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000007`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000007`, `Nested:0` | `AddItemDialog::~AddItemDialog()` | Destructor C++ preserving global clear at `0x0069b328` where applicable. |
| `by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md` | `0x004ae930-0x004aea3a` | new UID TBD by validator; `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000007`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000007`, `Nested:0` | `AddItemDialog::OnAction(unsigned int actionId)` | Packet `0x4A/1` send path and cancel close path. |
| `by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md` | `0x004aea40-0x004aea7d` | new UID TBD by validator; `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000007`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000007`, `Nested:0` | `AddItemDialog::UpdateActionButton()` | Selection-driven button enable/update logic. |

Support declarations needed in same callback:

```cpp
struct ListPane;
struct DialogRow;
static ListPane *GetDialogListBySelector(void *dialog, int selector);
static int GetSelectedRows(ListPane *list, DialogRow **rows, int maxRows);
static void CloseDialogWindow(void *dialog);
static void SendClientPacket(const unsigned char *packet, unsigned int packetSize);
```

After-score rationale: `86/90`, because exact children and packet semantics are known; constructor/destructor details still depend on existing UI support names and child files carry the method bodies.

### [UID:000317] AddItemDialog Packet Close Handler

Disposition: first-draft source-facing C++.

Evidence:

- Function at `0x004aea80`, size `0x30`.
- Data xref at `0x00619efc` indicates vtable/event route.
- Decompile checks packet bytes `0x42` and `0x04`, adjusts `this - 0xa0`, calls `0x0049eb90`, invokes vtable slot `+24`, returns 0.

Exact formal insertion:

```cpp
int AddItemDialog::OnClosePacket(const unsigned char *packet)
{
    if (packet != 0 && packet[0] == 0x42 && packet[1] == 0x04)
    {
        CloseDialogWindow(this);
        CloseDialog();
    }

    return 0;
}
```

Support declarations:

```cpp
void AddItemDialog::CloseDialog();
static void CloseDialogWindow(void *dialog);
```

Rejected alternatives:

- Comment-only marker is rejected because this is a source-authored event method with direct vtable xref evidence.
- `void` return is rejected because decompile returns `0`.

After-score rationale: `88/90`, because all branch conditions and side effects are MCP-backed; helper names remain source-facing.

### [UID:00033S] AddItemWithCountDialog Cluster

Disposition: concrete same-callback split/support declaration plan.

Reasoning:

- Current MCP proves three real functions in the aggregate range: constructor `0x004af040`, action handler `0x004af380`, and update method `0x004af480`.
- The action handler packet fields are stable from decompile evidence, including `0x4A/2`, `this+0x26c`, `this+0x270`, selected row byte, parsed count, and 8-byte send.
- This is source-authored code and should not remain a marker-only block.

Exact parent formal insertion:

```cpp
[[CHILDREN]]
```

Exact child split plan for implementation callback:

| Proposed child file | Range | Metadata | Source-facing name | Required content |
|---|---:|---|---|---|
| `by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md` | `0x004af040-0x004af371` | new UID TBD by validator; `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000008`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000008`, `Nested:0` | `AddItemWithCountDialog::AddItemWithCountDialog(unsigned int exchangeSessionId, unsigned char selectedItemType)` | Constructor and input/list setup; stores `this+0x26c` and `this+0x270`. |
| `by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnAction.md` | `0x004af380-0x004af47a` | new UID TBD by validator; `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000008`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000008`, `Nested:0` | `AddItemWithCountDialog::OnAction(unsigned int actionId)` | Confirm/cancel action with count parse, clamp, inline packet send, and close path; preserve [UID:00033T] duplicate-helper relationship. |
| `by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md` | `0x004af480-0x004af4b7` | new UID TBD by validator; `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000008`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000008`, `Nested:0` | `AddItemWithCountDialog::UpdateActionButton()` | Selection/count-input button update logic. |

Support declarations needed in same callback:

```cpp
static bool ParseUnsignedShort(const wchar_t *text, unsigned short *outValue);
static ListPane *GetDialogListBySelector(void *dialog, int selector);
static int GetSelectedRows(ListPane *list, DialogRow **rows, int maxRows);
static void SendClientPacket(const unsigned char *packet, unsigned int packetSize);
```

After-score rationale: `86/90`, because split and action semantics are stable; constructor/update details still depend on existing UI widget support names.

### [UID:000318] AddItemWithCountDialog Packet Close Handler

Disposition: first-draft source-facing C++.

Evidence:

- Function at `0x004af4c0`, size `0x30`.
- Data xref at `0x0061a05c` indicates vtable/event route.
- Decompile checks packet bytes `0x42` and `0x04`, adjusts `this - 0xa0`, calls `0x0049eb90` and `0x0049dad0`, returns 0.

Exact formal insertion:

```cpp
int AddItemWithCountDialog::OnClosePacket(const unsigned char *packet)
{
    if (packet != 0 && packet[0] == 0x42 && packet[1] == 0x04)
    {
        CloseDialogWindow(this);
        CloseDialog();
    }

    return 0;
}
```

Support declarations:

```cpp
void AddItemWithCountDialog::CloseDialog();
static void CloseDialogWindow(void *dialog);
```

Rejected alternatives:

- Treating this as a class marker is rejected because it is a concrete vtable-routed method.
- Treating `0x0049dad0` as optional is rejected; MCP callee evidence shows it is part of this close path.

After-score rationale: `88/90`, because conditions and side effects are MCP-backed.

### [UID:00033T] AddItemWithCountDialog Submit Packet Helper

Disposition: documented retained raw helper with blank formal C++ preserved.

Contradiction resolved:

- The prior B007 report incorrectly reclassified `0x004af4f0-0x004af570` as a no-code padding/gap range by over-weighting `lookup_funcs 0x004af4f0 -> no function`.
- Current [UID:00033T] by-memory docs and executed B011 Rule 26 evidence prove that this is a raw packet helper body, not padding.
- Current MCP confirms both sides of that disposition: IDA still does not model a function at `0x004af4f0`, but `get_bytes 0x004af4f0 size 128` returns a complete helper-shaped byte sequence with prologue, security cookie, packet writer calls, packet send, and `ret 4`.

Evidence:

- Current page metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000008`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000008`.
- Current by-memory page: `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`.
- Executed report: `executed-b-agent-research/B011/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md`.
- Current MCP `lookup_funcs 0x004af4f0` -> no modeled IDA function, which is only route/modeling evidence.
- Current MCP `get_bytes 0x004af4f0 size 128` -> byte body starts `55 8b ec 83 ec 24` and ends `8b e5 5d c2 04 00`, matching prologue and `ret 4`.
- Current MCP `xrefs_to 0x004af4f0` -> zero xrefs.
- Current MCP `xrefs_to 0x004af380` -> vtable data route at `0x0061a034`, confirming the active AddItemWithCountDialog action handler route is [UID:00033S], not the retained helper start.
- Current by-memory/Rule 26 evidence documents opcode `0x4A`, subtype `2`, eight sent bytes, unsent scratch zero at offset `8`, `this+0x26c` exchange/session id, `this+0x270` selected item/type byte, packet buffer writers, `g_packetSender`, and `Socket::QueueAndSendPacket`.
- [UID:00033S] action handler `0x004af380-0x004af47a` actively duplicates the packet serialization inline after parsing `"%hu"` and clamping to `0xFF` / 255, then closes the dialog.

Exact formal insertion:

```cpp
```

Implementation callback action:

- Preserve [UID:00033T] as a retained raw helper page, not a padding/no-code gap.
- Keep the formal C++ block blank in [UID:00033T] because no static branch/table/vtable route reaches the helper start and the active source route is [UID:00033S]'s inline action handler.
- Preserve current metadata `86/90`, owner [UID:000008], reconstructable true, and emitter [UID:000008].
- Add this report's correction only where target/support docs still contain stale padding/no-code wording; the current by-memory page already contains the correct detailed raw-helper evidence.

If supervisor later chooses retained-helper emission instead of inline-action-only source shape, the source-facing helper form is:

```cpp
void AddItemWithCountDialog::SendSelectedItemWithCountPacket(unsigned char count)
{
    unsigned char packet[9];

    PacketBufferWriteUInt8(0x4a, packet);
    PacketBufferWriteUInt8(2, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    PacketBufferWriteUInt8(m_selectedItemType, packet + 6);
    PacketBufferWriteUInt8(count, packet + 7);
    packet[8] = 0;

    g_packetSender->QueueAndSendPacket(packet, 8);
}
```

This helper body is implementation-ready if retained-helper emission is selected, but this report's recommended formal disposition is to keep [UID:00033T] blank and emit the active count-submit behavior through the [UID:00033S] action child.

Rejected alternatives:

- Padding/alignment is rejected by current raw bytes, current by-memory documentation, and executed Rule 26 evidence.
- Fake "no function means no code" rationale is rejected because raw-helper targets can be reconstructable even without an IDA-modeled function.
- Socket/CashShop ownership is rejected because `g_packetSender` and `Socket::QueueAndSendPacket` are infrastructure dependencies, not feature owners.
- ExchangeDialog ownership is rejected because ExchangeDialog supplies constructor context; the helper reads AddItemWithCountDialog fields and serializes the later user-entered count.
- Emitting both [UID:00033S] inline send and [UID:00033T] as a called helper is rejected unless the callback also rewrites the action child to call the helper or explicitly selects retained unreferenced helper bodies for binary parity.

After-score rationale: unchanged `86/90`, because current docs are already correct after B011 Rule 26 execution. This report only corrects the B007 contradiction and preserves the existing evidence-backed raw-helper disposition.

### [UID:00033U] MixItemDialog Cluster

Disposition: concrete same-callback split/support declaration plan.

Reasoning:

- Current MCP proves constructor `0x004af570` and action handler `0x004af8b0`.
- Switch table evidence belongs with the action child; no switch entry targets `0x004afb80`.
- The constructor and action handler are source-authored and implementable after splitting.

Exact parent formal insertion:

```cpp
[[CHILDREN]]
```

Exact child split plan for implementation callback:

| Proposed child file | Range | Metadata | Source-facing name | Required content |
|---|---:|---|---|---|
| `by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md` | `0x004af570-0x004af8af` | new UID TBD by validator; `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00008J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008J`, `Nested:0` | `MixItemDialog::MixItemDialog()` | Constructor C++ including `g_pMixItemDialog` publish/clear, vtable installation intent, UI setup, list pane construction, row clear. |
| `by-memory/0x004af8b0-0x004afb65.MixItemDialogOnAction.md` | `0x004af8b0-0x004afb65` | new UID TBD by validator; `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00008J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008J`, `Nested:0` | `MixItemDialog::OnAction(unsigned int actionId)` | Switch action handler, including packet `0x6B` send path and close path. |
| `by-memory/0x004afb65-0x004afb80.MixItemDialogActionSwitchTable.md` | `0x004afb65-0x004afb80` | new UID TBD by validator; `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00008J`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank, `Nested:0` | no C++ body | Document as switch-table/tail data owned by action handler. |

Support declarations needed in same callback:

```cpp
static MixItemDialog *g_pMixItemDialog;
static void SendClientPacket(const unsigned char *packet, unsigned int packetSize);
static ListPane *GetDialogListBySelector(void *dialog, int selector);
static int GetSelectedRows(ListPane *list, DialogRow **rows, int maxRows);
```

After-score rationale: `86/90`, because constructor/action ownership and packet behavior are stable; UI construction calls still require source-facing names.

### [UID:000319] MixItemDialog Add-Row Helper

Disposition: first-draft source-facing C++.

Evidence:

- Function at `0x004afcc0`, size `0x178`.
- Args decompile as `(char itemId, short itemSerial, wchar_t *name, char style)`.
- Callees include inventory lookup `0x005a3870`, UI row helpers, `_wcscpy_s`, and callback allocation.
- Decompile appends directly when slot count at `+488` is <= 1; otherwise allocates a `DoubleParamMemberFunctionObject` targeting `0x004afe40` and constructs `NumberInputDialog` resource `218`.

Exact formal insertion:

```cpp
void MixItemDialog::AddMixItem(unsigned char itemId, unsigned short itemSerial, const wchar_t *itemName, unsigned char style)
{
    ListPane *mixList = GetDialogListBySelector(this, 5);
    InventorySlot *slot = GetInventorySlot(itemId);

    if (slot == 0 || slot->count <= 1)
    {
        MixItemRow row = {};
        row.itemId = itemId;
        row.itemSerial = itemSerial;
        row.style = style;
        row.count = 1;
        CopyWideString(row.name, itemName, sizeof(row.name) / sizeof(row.name[0]));
        mixList->AppendRow(&row);
        return;
    }

    DoubleParamMemberFunctionObject *callback =
        new DoubleParamMemberFunctionObject(this, &MixItemDialog::OnMixItemQuantity, itemId, style);

    NumberInputDialog *dialog =
        new NumberInputDialog(218, 1, slot->count, callback);

    dialog->Show();
}
```

Support declarations:

```cpp
struct InventorySlot
{
    unsigned char pad_0000[488];
    unsigned int count;
};

struct MixItemRow
{
    unsigned char itemId;
    unsigned char style;
    unsigned short itemSerial;
    unsigned int count;
    wchar_t countText[16];
    wchar_t name[64];
};

static InventorySlot *GetInventorySlot(unsigned char itemId);
static void CopyWideString(wchar_t *dst, const wchar_t *src, unsigned int dstCount);
```

Rejected alternatives:

- File-local free function is rejected because the function uses dialog selector `5` from `this` and callback binds the MixItemDialog instance.
- Comment-only marker is rejected because helper behavior is directly recoverable.

After-score rationale: `88/90`, because branch behavior, callback target, resource id, and row append intent are MCP-backed; exact row struct width remains first-draft.

### [UID:00031A] MixItemDialog Quantity Callback

Disposition: first-draft source-facing C++.

Evidence:

- Function at `0x004afe40`, size `0x1b7`.
- Code xref from `0x004b02c4`; callback stores at `0x004afd68` and `0x004b0376`.
- Decompile obtains selector `5`, resolves slot by item id, formats count text, copies name, and appends row.

Exact formal insertion:

```cpp
void MixItemDialog::OnMixItemQuantity(unsigned int count, unsigned char itemId, unsigned char style)
{
    ListPane *mixList = GetDialogListBySelector(this, 5);
    InventorySlot *slot = GetInventorySlot(itemId);

    if (slot == 0)
        return;

    MixItemRow row = {};
    row.itemId = itemId;
    row.itemSerial = GetInventorySlotSerial(slot);
    row.style = style;
    row.count = count;

    FormatWideString(row.countText, sizeof(row.countText) / sizeof(row.countText[0]), L"%d", count);
    CopyWideString(row.name, GetInventorySlotName(slot), sizeof(row.name) / sizeof(row.name[0]));

    mixList->AppendRow(&row);
}
```

Support declarations:

```cpp
// Use the shared InventorySlot and MixItemRow declarations from [UID:000319].
static unsigned short GetInventorySlotSerial(const InventorySlot *slot);
static const wchar_t *GetInventorySlotName(const InventorySlot *slot);
static void FormatWideString(wchar_t *dst, unsigned int dstCount, const wchar_t *format, unsigned int value);
```

Rejected alternatives:

- Treating this as only a generated callback stub is rejected because the body constructs the actual row payload.
- Omitting the helper is rejected because both `000319` and `0002U2` bind this callback target.

After-score rationale: `88/90`, because callback route and row insertion are stable; exact source struct field ordering remains first-draft.

### [UID:0002U1] AddMixingItemDialog Constructor

Disposition: first-draft source-facing C++.

Evidence:

- Function at `0x004b0000`, size `0x118`.
- Callees include `0x004ae4c0` base constructor and list row helpers.
- Decompile calls AddItemDialog base with `(0,1)`, installs AddMixingItemDialog vtables, stores owner at `+624` / `0x270`, compares owner selector `5` rows against this selector `3` rows, and removes duplicates by matching first byte.

Exact formal insertion:

```cpp
AddMixingItemDialog::AddMixingItemDialog(MixItemDialog *mixDialog)
    : AddItemDialog(0, 1),
      m_mixDialog(mixDialog)
{
    ListPane *mixList = GetDialogListBySelector(mixDialog, 5);
    ListPane *itemList = GetDialogListBySelector(this, 3);

    const int mixCount = mixList->GetRowCount();
    for (int mixIndex = 0; mixIndex < mixCount; ++mixIndex)
    {
        const MixItemRow *mixRow = static_cast<const MixItemRow *>(mixList->GetRow(mixIndex));
        if (mixRow == 0)
            continue;

        for (int itemIndex = itemList->GetRowCount() - 1; itemIndex >= 0; --itemIndex)
        {
            const ItemListRow *itemRow = static_cast<const ItemListRow *>(itemList->GetRow(itemIndex));
            if (itemRow != 0 && itemRow->itemId == mixRow->itemId)
            {
                itemList->RemoveRow(itemIndex);
                break;
            }
        }
    }
}
```

Support declarations:

```cpp
class AddMixingItemDialog : public AddItemDialog
{
    MixItemDialog *m_mixDialog; // offset 0x270 / 624
};

struct ItemListRow
{
    unsigned char itemId;
};
```

Rejected alternatives:

- No-code marker is rejected because the constructor is a real function with stable base-constructor and duplicate-removal behavior.
- Treating `mixDialog` as a global is rejected because decompile stores a constructor argument at offset `0x270`.

After-score rationale: `88/90`, because constructor ownership and list-filtering behavior are MCP-backed; exact class member declaration belongs in the same callback support block.

### [UID:0002U2] AddMixingItemDialog Action Handler

Disposition: first-draft source-facing C++.

Evidence:

- Function at `0x004b0120`, size `0x36a`.
- Data xref at `0x0061a16c`.
- Decompile action id `1` iterates selected rows from selector `3`; stackable rows either call `0x004afe40` directly or allocate `NumberInputDialog`; action id `2` closes.
- Callees include `0x004afe40`, inventory lookup, callback allocation, packet/list helpers, `_wcscpy_s`, and close helpers.

Exact formal insertion:

```cpp
int AddMixingItemDialog::OnAction(unsigned int actionId)
{
    if (actionId == 2)
    {
        CloseDialog();
        return 0;
    }

    if (actionId != 1)
        return 0;

    ListPane *itemList = GetDialogListBySelector(this, 3);
    DialogRow *selectedRows[256] = {};
    const int selectedCount = GetSelectedRows(itemList, selectedRows, 256);

    for (int i = 0; i < selectedCount; ++i)
    {
        const ItemListRow *itemRow = static_cast<const ItemListRow *>(selectedRows[i]);
        if (itemRow == 0)
            continue;

        InventorySlot *slot = GetInventorySlot(itemRow->itemId);
        if (slot == 0)
            continue;

        if (slot->count <= 1)
        {
            m_mixDialog->OnMixItemQuantity(1, itemRow->itemId, itemRow->style);
            continue;
        }

        DoubleParamMemberFunctionObject *callback =
            new DoubleParamMemberFunctionObject(m_mixDialog, &MixItemDialog::OnMixItemQuantity, itemRow->itemId, itemRow->style);

        NumberInputDialog *dialog =
            new NumberInputDialog(218, 1, slot->count, callback);

        dialog->Show();
    }

    CloseDialog();
    return 0;
}
```

Support declarations:

```cpp
void MixItemDialog::OnMixItemQuantity(unsigned int count, unsigned char itemId, unsigned char style);
static int GetSelectedRows(ListPane *list, DialogRow **rows, int maxRows);
```

Rejected alternatives:

- Comment-only marker is rejected because action behavior and callback binding are directly available from decompile evidence.
- Directly sending packet `0x6B` here is rejected; MCP evidence places the `0x6B` packet send in `MixItemDialog::OnAction`, not this add-dialog action.

After-score rationale: `88/90`, because callback and selection behavior are stable; exact selected-row struct remains first-draft.

### [UID:00033X] Active MixItemDialog Clear Helper

Disposition: first-draft source-facing C++ with one exact helper form.

Chosen form:

- File-local helper: `static void ClearActiveMixItemDialog()`.

Evidence:

- Function at `0x004b0870`, size `0xb`.
- Disassembly is exactly `mov dword ptr unk_69B32C, 0; retn`.
- `xrefs_to 0x004b0870` includes code xref at `0x005fe593`, which does not supply object context in this report's evidence.
- No callees and no `this` use.

Exact formal insertion:

```cpp
static void ClearActiveMixItemDialog()
{
    g_pMixItemDialog = 0;
}
```

Rejected alternatives:

- `MixItemDialog::ClearActive()` is rejected because the body has no `this` read/write and only writes the global.
- `MixItemDialog::~MixItemDialog()` is rejected because current MCP evidence only proves a global clear helper body, not destructor ownership.
- Multiple helper alternatives are rejected; the implementation callback should insert only the file-local helper.

After-score rationale: `88/92`, because the exact body and helper form are fully MCP-backed.

### [UID:0002AY] ItemDialog Singleton Globals

Disposition: first-draft source-facing C++ data declarations.

Evidence:

- `lookup_funcs 0x0069b328` and `0x0069b32c` -> no functions.
- `xrefs_to 0x0069b328` includes AddItemDialog-family reads/writes and getter `0x004aeab0`.
- `xrefs_to 0x0069b32c` includes MixItemDialog constructor/write and clear helper `0x004b0870`.
- `get_bytes 0x0069b328 size 8` -> all zero bytes.

Exact formal insertion:

```cpp
static AddItemDialog *g_pAddItemDialog = 0;
static MixItemDialog *g_pMixItemDialog = 0;
```

Rejected alternatives:

- `(AddItemDialog *)-1` and `(MixItemDialog *)-1` are rejected because current bytes are eight zero bytes, not `0xff`.
- Leaving initializers implicit is rejected because the callback now has current byte proof and should encode the zero initialization explicitly.

After-score rationale: `89/92`, because both addresses and initializer bytes are exact; only static-vs-external linkage remains a source-placement convention, and current placement favors file-local static globals.

## Class Marker Blocks Requiring `[[CHILDREN]]`

Any class or aggregate page in this family that exists only to group child source methods should receive an explicit child expansion marker. Exact formal insertion for those class/container blocks:

```cpp
[[CHILDREN]]
```

This applies to at least:

- `[UID:00033Q]` AddItemDialog aggregate parent after child split.
- `[UID:00033S]` AddItemWithCountDialog aggregate parent after child split.
- `[UID:00033U]` MixItemDialog aggregate parent after child split.

If the by-file page also has explicit class declaration pages for AddItemDialog, AddItemWithCountDialog, MixItemDialog, or AddMixingItemDialog, the same `[[CHILDREN]]` block should be used there rather than a comment-only marker.

Generated-output expectation:

- The generator should expand child blocks at `[[CHILDREN]]`.
- No source-authored method should be considered cleared by a comment-only block.

## Claim And Incorporation Ledger

| Claim | Destination | Action | Verification state |
|---|---|---|---|
| [UID:0000KE] current baseline is `COMPLETION:90`, `CONFIDENCE:87`; this report recommends `90/88` only after stale contradiction removal and child-disposition reconciliation. | `by-file/ItemDialogs.md` metadata/change note | incorporated | `COMPLETION:90`, `CONFIDENCE:88`; validator `000000002732`, exit 0, ok 1; generated freshness `000000002734`, exit 0, ok 1. |
| [UID:00033Q] should become a `[[CHILDREN]]` aggregate/container with four exact proposed child files, ranges, metadata, and method bodies. | `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md` plus new child files | incorporated | Parent validator `000000002708`, exit 0, ok 1. Child UIDs assigned: `0004BM`, `0004BN`, `0004BO`, `0004BP`; validators `000000002688`, `000000002690`, `000000002692`, `000000002694`, all exit 0, ok 1. |
| [UID:000317] should receive first-draft `AddItemDialog::OnClosePacket` formal C++. | `by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md` | incorporated | Validator `000000002711`, exit 0, ok 1. |
| [UID:00033S] should become a `[[CHILDREN]]` aggregate/container with three exact proposed child files and must preserve [UID:00033T] inline-duplicate relationship. | `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md` plus new child files | incorporated | Parent validator `000000002714`, exit 0, ok 1. Child UIDs assigned: `0004BQ`, `0004BR`, `0004BS`; validators `000000002696`, `000000002698`, `000000002700`, all exit 0, ok 1. [UID:00033T] retained-helper wording preserved. |
| [UID:000318] should receive first-draft `AddItemWithCountDialog::OnClosePacket` formal C++. | `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md` | incorporated | Validator `000000002716`, exit 0, ok 1. |
| [UID:00033T] is a retained raw packet helper, not padding; keep current `86/90`, owner/emitter [UID:000008], reconstructable true, and blank formal C++ due no static route plus active inline duplicate. | `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`, `by-file/ItemDialogs.md`, and [UID:00033S] support note | preserved | No stale contradictory edit applied to [UID:00033T]. `by-file/ItemDialogs.md` and [UID:00033S] record the retained raw-helper disposition; validators `000000002732` and `000000002714`, both exit 0, ok 1. |
| [UID:00033U] should become a `[[CHILDREN]]` aggregate/container with exact constructor/action children and switch-table child. | `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md` plus new child files | incorporated | Parent validator `000000002718`, exit 0, ok 1. Child UIDs assigned: `0004BT`, `0004BU`, `0004BV`; validators `000000002702`, `000000002704`, `000000002706`, all exit 0, ok 1. |
| [UID:000319], [UID:00031A], [UID:0002U1], and [UID:0002U2] should receive first-draft formal C++ from this report. | their existing by-memory pages | incorporated | Validators `000000002720`, `000000002722`, `000000002724`, `000000002726`, all exit 0, ok 1. Existing missing-ref warnings remain for `0003U9` on `000319`, `00031A`, and `0002U2`. |
| [UID:00033X] should use only file-local `static void ClearActiveMixItemDialog()`. | `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md` | incorporated | Validator `000000002728`, exit 0, ok 1. |
| [UID:0002AY] should use zero-initialized singleton declarations and reject stale `-1` initializer assumptions. | `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md` | incorporated | Validator `000000002730`, exit 0, ok 1. |

## Implementation Callback Validation Record

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`. Every changed/new by-* file exited 0 with ok 1.

| Command ID | Timestamp | File | Exit | Ok | Notes |
|---|---|---|---:|---:|---|
| `000000002688` | `2026-06-30T13:59:58-04:00` | `by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md` | 0 | 1 | Child UID `0004BM`. |
| `000000002690` | `2026-06-30T14:00:01-04:00` | `by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md` | 0 | 1 | Child UID `0004BN`. |
| `000000002692` | `2026-06-30T14:00:10-04:00` | `by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md` | 0 | 1 | Child UID `0004BO`. |
| `000000002694` | `2026-06-30T14:00:19-04:00` | `by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md` | 0 | 1 | Child UID `0004BP`. |
| `000000002696` | `2026-06-30T14:00:29-04:00` | `by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md` | 0 | 1 | Child UID `0004BQ`. |
| `000000002698` | `2026-06-30T14:00:38-04:00` | `by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnAction.md` | 0 | 1 | Child UID `0004BR`. |
| `000000002700` | `2026-06-30T14:00:47-04:00` | `by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md` | 0 | 1 | Child UID `0004BS`. |
| `000000002702` | `2026-06-30T14:00:56-04:00` | `by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md` | 0 | 1 | Child UID `0004BT`. |
| `000000002704` | `2026-06-30T14:01:04-04:00` | `by-memory/0x004af8b0-0x004afb65.MixItemDialogOnAction.md` | 0 | 1 | Child UID `0004BU`. |
| `000000002706` | `2026-06-30T14:01:14-04:00` | `by-memory/0x004afb65-0x004afb80.MixItemDialogActionSwitchTable.md` | 0 | 1 | Child UID `0004BV`; non-reconstructable table child. |
| `000000002708` | `2026-06-30T14:01:22-04:00` | `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md` | 0 | 1 | `[[CHILDREN]]` aggregate. |
| `000000002711` | `2026-06-30T14:01:31-04:00` | `by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md` | 0 | 1 | Formal close-packet C++. |
| `000000002714` | `2026-06-30T14:01:49-04:00` | `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md` | 0 | 1 | `[[CHILDREN]]` aggregate; [UID:00033T] retained-helper relationship preserved. |
| `000000002716` | `2026-06-30T14:02:08-04:00` | `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md` | 0 | 1 | Formal close-packet C++. |
| `000000002718` | `2026-06-30T14:02:20-04:00` | `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md` | 0 | 1 | `[[CHILDREN]]` aggregate. |
| `000000002720` | `2026-06-30T14:02:31-04:00` | `by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md` | 0 | 1 | Existing warning: missing ref UID `0003U9` x3. |
| `000000002722` | `2026-06-30T14:02:41-04:00` | `by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md` | 0 | 1 | Existing warning: missing ref UID `0003U9` x2. |
| `000000002724` | `2026-06-30T14:02:52-04:00` | `by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md` | 0 | 1 | Formal constructor C++. |
| `000000002726` | `2026-06-30T14:03:02-04:00` | `by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md` | 0 | 1 | Existing warning: missing ref UID `0003U9` x3. |
| `000000002728` | `2026-06-30T14:03:13-04:00` | `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md` | 0 | 1 | File-local helper form. |
| `000000002730` | `2026-06-30T14:03:23-04:00` | `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md` | 0 | 1 | Zero-initialized singleton declarations. |
| `000000002732` | `2026-06-30T14:03:34-04:00` | `by-file/ItemDialogs.md` | 0 | 1 | Existing warning: missing ref UIDs `0003ID`, `0003IE`, `0003IG`, `0003IF` repeated 20 total. |

Generated freshness was run after the scoped validators with `python .\tools\validator.py --mode file --file by-file/ItemDialogs.md --apply --wait-generated --queue-timeout 240`: command `000000002734`, timestamp `2026-06-30T14:03:51-04:00`, exit 0, ok 1, `generated_refresh: completed`. It reported the same existing ItemDialogs missing-ref warnings and unrelated existing `autogen_children_marker_missing` warnings on Error-family classes, then refreshed `auto-generated/NexusTK/util/Error.cpp` metadata.

Lease release proof: `python .\leaser.py Agent-B007 unlease` from `tools/leaser` returned `Agent-B007: No active leases`, exit 0. The generated `tools/leaser/Agents/current_leases.md` report showed no Agent-B007 rows after the command; remaining active rows were unrelated B009 TimerMgr leases.

## Implementation Callback Checklist

Required by-file edits after supervisor validation:

- [x] Keep work scoped to accepted `by-file/ItemDialogs.md` target/support by-* pages.
- [x] Take required leases only during the implementation callback.
- [x] Update `[UID:0000KE]` score/current-state rationale from current `90/87` to accepted `90/88`.
- [x] Insert `[[CHILDREN]]` for class/container blocks.
- [x] Split `[UID:00033Q]` into exact AddItemDialog child files listed above, with validator-assigned UIDs and formal C++ on the children.
- [x] Insert first-draft C++ for `[UID:000317]`.
- [x] Split `[UID:00033S]` into exact AddItemWithCountDialog child files listed above, preserving [UID:00033T] inline-duplicate support evidence.
- [x] Insert first-draft C++ for `[UID:000318]`.
- [x] Preserve `[UID:00033T]` as retained raw packet helper code, not padding; current `86/90`, owner/emitter [UID:000008], reconstructable true, and blank formal C++ remain unchanged.
- [x] Split `[UID:00033U]` into exact MixItemDialog child files listed above, including the non-reconstructable switch-table child.
- [x] Insert first-draft C++ for `[UID:000319]`.
- [x] Insert first-draft C++ for `[UID:00031A]`.
- [x] Insert first-draft C++ for `[UID:0002U1]`.
- [x] Insert first-draft C++ for `[UID:0002U2]`.
- [x] Insert file-local helper for `[UID:00033X]`.
- [x] Insert zero-initialized globals for `[UID:0002AY]`.
- [x] Run required docs validators after implementation.
- [x] Regenerate derived docs only through validator wait-generated freshness.
- [x] Verify empty source-authored emitters were cleared except documented retained raw helper blanks such as [UID:00033T], where blank formal C++ is evidence-backed.
- [x] Release/expire B007 leases and verify no active Agent-B007 lease rows remain.

Expected validators:

- Run the project documentation validator used for by-file reconstruction pages.
- Run any UID/marker integrity validator available for `by-file/ItemDialogs.md`.
- Run scoped file validators for each edited existing page:
  - `by-file/ItemDialogs.md`
  - `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md`
  - `by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md`
  - `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md`
  - `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md`
  - `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`
  - `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md`
  - `by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md`
  - `by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md`
  - `by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md`
  - `by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md`
  - `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md`
  - `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`
- If split child files are created, run the same scoped validator for every new child filename listed under [UID:00033Q], [UID:00033S], and [UID:00033U].
- Verify no empty `RECONSTRUCTION_CPP` emitter remains for source-authored methods in the revised family.
- Verify class/container pages with child content include `[[CHILDREN]]`.

## Stale, Negative, And Rejected Evidence Ledger

Stale evidence:

- Historical assumption that `0x0069b328-0x0069b32f` contains `0xff` bytes is stale. Current MCP bytes are all zero.

Negative evidence:

- No modeled IDA function at `0x004af4f0`; this is route/modeling evidence only and is stale/invalid if used as padding proof.
- No ordinary xrefs to `0x004af4f0`; this supports retained no-route helper disposition, not padding.
- No switch entry in `0x004af8b0` targets `0x004afb80`.
- No function at `0x0069b328` or `0x0069b32c`; these are data globals.

Rejected final rationales:

- "Layouts/signatures/APIs are not stable enough" is not accepted as a final rationale for source-authored methods in this family.
- "Deferred until class-layout pass" is not accepted as a final rationale for the required source-authored methods.
- Comment-only marker blocks are not accepted for source-authored methods.
- B007's previous `[UID:00033T]` padding/no-code conclusion is rejected as invalid because it contradicted current by-memory docs, executed B011 Rule 26 evidence, and current MCP bytes.
- Ambiguous `[UID:00033X]` alternatives are rejected; use the file-local helper.
- Old `(Type *)-1` singleton initializer declarations are rejected; use zero initialization.

## Blockers

No active blocker. MCP was available and current evidence is sufficient for supervisor validation of this report.

If MCP becomes unavailable before implementation, pause with `PAUSED_MCP_UNAVAILABLE`. If MCP becomes busy or repeatedly times out, pause with `PAUSED_MCP_BUSY` or `PAUSED_MCP_TIMEOUT` and do not complete fallback-only implementation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000KE-ItemDialogs-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000KE-ItemDialogs-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T14:11:01","uid":"0000KE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
