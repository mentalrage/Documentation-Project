*** UID:0000D2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ServerSelectPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"

struct ServerSelectDirectory;
class ServerSelectMenuItemList;

class ServerSelectPane : public DialogPane,
                         public Singleton<ServerSelectPane>
{
public:
    ServerSelectPane(ServerSelectDirectory *serverDirectory);

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

private:
    friend class ServerSelectMenuItemList;

    ServerSelectDirectory *m_serverDirectory;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Source-ready pre-login server-selection dialog declaration with direct DialogPane and empty Singleton<ServerSelectPane> bases, exact 0x270 layout, directory member at +0x26c, corrected OnControlCommand/UpdateActionButton overrides, implicit virtual destruction, complete three-view RTTI/vtable closure, seven-reference singleton lifecycle, and UID0000NO source/header routing. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ServerSelectPane

## Status

- Confidence: very strong for class role, direct bases, `0x270` allocation, `+0x26c` layout, constructor/control/update/destructor-family boundaries, all three vtable views, Singleton/global lifecycle, declaration shape, and source owner. Residual uncertainty is limited to stripped original lexical/access style.
- Likely source file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Current recovered file: `source-3/simroot_v2/class_ServerSelectPane.cpp`
- Address range: [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- Direct bases: `DialogPane` followed by empty `Singleton<ServerSelectPane>`.
- Complete allocation size: `0x270` bytes.
- Singleton source route: [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md) emits the sole external definition/header declaration; exact physical storage [UID:0002XN][0x0069b4ac-0x0069b4b0.g_pServerSelectPane](by-memory/0x0069b4ac-0x0069b4b0.g_pServerSelectPane.md) is false/non-emitting evidence.

## Class Purpose

`ServerSelectPane` is the pre-login dialog for selecting a game server. It builds the `DLGSERV` background, OK/cancel image buttons, a scrollable `ServerSelectMenuItemList`, and selects the previously configured server when high-resolution layout is enabled.

## Direct Inheritance And RTTI

The source-quality class relationship is:

```cpp
class ServerSelectPane : public DialogPane,
                         public Singleton<ServerSelectPane>
```

This relationship is now installed in the formal H channel together with the complete period-compatible declaration. The CPP channel owns the header include and `[[CHILDREN]]` route; method children continue to own individual bodies.

- MSVC RTTI names `ServerSelectPane` at type descriptor `0x006791a4` and `Singleton<ServerSelectPane>` at `0x006791c4`.
- The ServerSelectPane class hierarchy/base array is rooted at `0x00650298`/`0x006502a8`.
- Self base-class descriptor `0x006502cc` points to the ServerSelectPane type descriptor, contains seven bases, and has PMD `0/-1/0`, attributes `0x40`.
- Direct Singleton descriptor `0x006502e8` points to the Singleton type descriptor, contains zero sub-bases, and has PMD `620/-1/0`, i.e. `+0x26c/-1/0`, attributes `0x40`.
- Current IDA `DialogPane` UDT size is 620 bytes (`0x26c`) with its existing seven members. No local `ServerSelectPane` UDT currently exists; a global-only IDA action should use an opaque forward type rather than guessing this complete UDT.

The direct Singleton relationship explains the adjusted-pointer publication and all teardown/EH clears as template/compiler lowering. Final human source should express inheritance, not decompiler-shaped manual registration helpers.

## Field Notes

| Offset | Best current field name | Evidence |
| --- | --- | --- |
| `+0x26c` | `ServerSelectDirectory *m_serverDirectory` | Constructor caller at `0x004f70db` passes `g_pConfig + 0x28db10`; the constructor stores the argument here, iterates 32 stride-`0x18` server entries, and reads entry count at directory `+0x300`. |

`ServerSelectDirectory` is the canonical private source-facing type for the embedded Config server directory. It is exactly 0x308 bytes: 32 natural-aligned 0x18-byte `ServerSelectEntry` rows, `int entryCount` at `+0x300`, and `unsigned char version` at `+0x304`. Each entry contains `unsigned char serverId` at `+0x00`; owned `wchar_t *name`, `*description`, and `*agreementText` at `+0x04/+0x08/+0x0c`; `unsigned char address[4]` at `+0x10`; and `unsigned short port` at `+0x14`. The pane/list consume name, description, id, address, and port; registry/packet/cleanup paths independently prove agreement text and version. No explicit padding members are required.

The empty Singleton base has PMD `+0x26c`, the same address as `m_serverDirectory`. Empty-base optimization permits that empty base subobject to share the address with the unrelated first derived member. The constructor allocation size `0x270` is therefore consistent with a `0x26c` DialogPane base plus one four-byte pointer member, not evidence for an extra hidden four-byte Singleton field.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ServerSelectPane(ServerSelectDirectory *serverDirectory)` | `0x00573d20-0x00574300` | Builds the classic or EPF server-select dialog, stores `serverDirectory` at `+0x26c`, creates the list pane, adds `ServerSelectEntry *` rows from server data, selects the configured server, and opens the dialog. |
| Non-deleting destructor-like helper | `0x00574310-0x00574338` | Resets vtables, clears [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md), and jumps to base teardown. Older Wave3 coverage omitted this body; that stale tooling fact is historical only. |
| `OnControlCommand(int controlIndex, int notifyCode)` | `0x00574340-0x00574430` | Primary vtable slot `+0x48`; the two-argument `retn 8` contract matches the base virtual. Handles OK/cancel; OK gets child id `3`, unwraps the list from child storage `+0x108`, calls `ServerSelectMenuItemList::ApplySelectedServer()` from both layout branches, and creates a screen-dimmer transition before closing. |
| `UpdateActionButton()` | `0x00574440-0x00574496` | Primary vtable slot `+0x4c`; enables/disables scroll/action controls based on child id `3` list enabled-entry count. |
| Adjustor thunks | `0x0057475b-0x00574770` | Compiler-generated thunks forwarding to the scalar deleting destructor. |
| Singleton clear helper | `0x00574750-0x0057475a` | Clears [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md) without running the full destructor. |
| `ScalarDeletingDestructor` | `0x00574780-0x005747df` | Clears [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md), destroys the base dialog pane, and conditionally frees memory. |

## Evidence Notes

- Historical Wave3 grade/omission notes are retained only as provenance and are ignored for current source-quality decisions.
- IDA MCP confirms the listed function starts and ends.
- Constructor has a direct caller at `0x004f70db`, in the pre-login/main-menu region.
- B013 source-quality recheck resolves the constructor argument shape: the caller passes `g_pConfig + 0x28db10`, the constructor stores it at `this + 0x26c`, and active server count is read at the argument `+0x300`.
- `OnControlCommand` calls the server-selection helper historically modeled as `ChattingColorListPane::ApplySelectedColor`; that old label is owner pollution, not current source identity.
- 2026-05-24 IDA MCP decompilation confirms `0x00574510` copies the selected server name into the config/current-server buffer and calls `0x005745b0`; `0x005745b0` sends the `0x57` select-server packet and stores selected endpoint/session state.
- Current source-facing helper names are `ServerSelectMenuItemList::ApplySelectedServer()` and private member `ServerSelectMenuItemList::SendServerSelectPacket(unsigned int selectedServerId, const ServerSelectEntry *entry)`. The second helper is not file-local: both callers establish the list instance in ECX, and packet sending dispatches through `g_packetSender->QueueAndSendPacket(packet, 3)`. Older chat-color ownership is rejected because both callers are `ServerSelectPane::OnControlCommand` and the data flow is server-selection-specific.
- `xrefs_to 0x0069b4ac` ties the active-pane singleton to main-menu cleanup/startup and the `ServerSelectPane` constructor/destructor family.
- 2026-06-01 live IDA MCP recheck confirms `0x00574750` as a tiny singleton-clear helper and the scalar deleting destructor as `0x00574780-0x005747df`, with `0x005747df-0x005747e0` as one-byte `0xcc` padding before the next socket lifecycle function.

## Singleton Global Lifecycle And Linkage

Exactly seven references touch physical storage `0x0069b4ac`:

| Address | Class/source relationship |
| --- | --- |
| `0x004f69fb` | External main-menu cleanup reads and closes the active pane. |
| `0x004f70a8` | External main-menu/server-list handling guards allocation/construction. |
| `0x00573d7e` | Constructor/Singleton lowering publishes the adjusted active pointer. |
| `0x00573d85` | Constructor fallback clears it. |
| `0x0057432a` | Ordinary destructor body clears before base teardown. |
| `0x00574750` | Constructor EH/unwind helper clears partially published state. |
| `0x005747a0` | Scalar deleting wrapper includes the ordinary clear side effect. |

The main-menu reads are outside this class implementation cluster, so the source pointer requires external linkage. UID0000S8 provides exactly one position-0 CPP definition and one H `extern` declaration. This class page must not emit a second global, a class-static replacement, or compiler cleanup wrappers as authored methods.

## Static Storage, Boundaries, And Historical Correction

- Exact physical slot `[0x0069b4ac,0x0069b4b0)` is loader-zeroed. Current live IDA reads `00 00 00 00` and integer/global value zero.
- Target RVA `0x29b4ac` is `0x2e4ac` bytes into `.data`, beyond raw size `0xd800`; no file initializer bytes exist.
- Historical `0xffffffff` wording is disproved and must remain only as correction history.
- Lower neighbor is `g_pNewCreateUserDialogPane`; upper neighbor is `g_pTransferServerDialog` with 20 independent refs. The slot is one exact pointer, not part of a source-level aggregate.

## Source And Formal-Code Policy

- UID0000S8 owns the sole `ServerSelectPane *g_pServerSelectPane = NULL;` definition and matching header `extern` declaration under UID0000NO.
- UID0002XN is false/non-emitting physical evidence; UID00029W is a false/non-emitting mixed-owner index.
- This class page formally emits `#include "ServerSelectPane.h"` followed by `[[CHILDREN]]` in CPP and the complete source-ready declaration in H.
- The H declaration uses period-compatible `virtual` syntax rather than C++11 `override`, forward-declares `ServerSelectDirectory`, and includes the owning base headers.
- Exact method/helper children emit class and file-local bodies through `[[CHILDREN]]`. Compiler RTTI/vtables, vptr stores, construction-failure cleanup, adjustor thunks, and scalar deleting wrappers remain non-source support.
- No explicit derived destructor is emitted. The virtual base hierarchy and ordinary implicit destruction reproduce the observed cleanup family; no derived resource teardown warrants a hand-authored body.
- The H declaration forward-declares and friends `ServerSelectMenuItemList`. This compile-only access bridge permits that list class's exact `m_owner->ActivateFocusedControl()` source expression to call the inherited protected `DialogPane` helper. It adds no field, vtable slot, function body, object-size change, or runtime state.
- The friendship is narrower and more source-plausible than inventing a public wrapper or widening the inherited base API. UID0000D1 remains a separate class emitter at position 30; its declaration and definitions are not duplicated here.

## Three-View ABI Closure

- Exact child [UID:0003D7][0x00624d24-0x00624dc0.ServerSelectPaneVtableData](by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md) classifies all 156 bytes and 39 four-byte cells: one primary 23-slot view, one 11-slot `EventHandler` view, and one two-slot `TimerHandler` view.
- The three COLs share type descriptor `0x6791a4` and hierarchy descriptor `0x650298`; their complete-object offsets are `0`, `0xa0`, and `0xa4`.
- The eight-base hierarchy is `ServerSelectPane`, `DialogPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`, and `Singleton<ServerSelectPane>`. Direct Singleton PMD `+0x26c` agrees with empty-base optimization and the sole derived pointer member.
- Constructor `0x573d20`, ordinary cleanup `0x574310`, and scalar deleting wrapper `0x574780` each store all three view heads at offsets `0`, `0xa0`, and `0xa4`. The two base-adjusting wrappers at `0x57475b/0x574766` are compiler-generated table glue.
- Primary slots `+0x48/+0x4c`, the base declaration, body behavior, and calling conventions independently converge on `OnControlCommand(int,int)` and `UpdateActionButton()`.

## Negative Evidence And Rejected Alternatives

- MainMenuPane is a consumer/coordinator, not the class/global owner.
- Physical adjacency with create-user and transfer singleton slots does not imply common class inheritance or source-file ownership.
- `g_serverSelectPane`, `dword_69B4AC`, and `unk_69B4AC` are historical/tool aliases, not separate source variables.
- A full guessed IDA UDT, class-static singleton, file-local static pointer, manual registration wrapper, smart pointer, or `0xffffffff` sentinel is unsupported.
- A separate raw-vtable source file/page, manual vptr stores, authored deleting wrappers, and an explicit empty destructor are rejected because they would reproduce compiler lowering as human source.

## Historical Method-Name Correction

- `OnDialogAction(int actionId)` was a descriptive pre-slot-analysis label. The primary `+0x48` slot is the inherited two-argument control-command virtual, and `retn 8` proves two stack arguments; current source uses `OnControlCommand(int controlIndex, int notifyCode)`.
- `UpdateScrollButtons()` over-described one observed effect. The primary `+0x4c` base contract and complete body support the broader `UpdateActionButton()` identity.
- The old names remain documented here only to explain their rejection and must not reappear as current declarations or generated definitions.

## Score Rationale

- Completion `93`: class purpose, complete formal CPP/H, direct bases, three-view RTTI/vtables, EBO layout, exact allocation, server-directory member, corrected constructor/control/update/destructor map, global lifecycle/linkage, source route, compiler/source split, boundaries, history, and rejected alternatives are documented.
- Confidence `95`: current RTTI, all table cells, vptr stores, live xrefs/bytes, base slot contracts, allocation/member use, and source-tree evidence agree. Remaining uncertainty is original lexical/access style rather than class behavior or emitted ABI ownership.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- 2026-08-15 B010 UID0003D9 accepted implementation callback:
  - Score, owner/emitter, position, inheritance, layout, methods, singleton route, and existing formal source remain `93/95` and otherwise unchanged.
  - Added the exact `ServerSelectMenuItemList` forward declaration and class friendship required by the accepted UID0000D1 activation thunk.
  - The change is compile-time access only and creates no binary state; the rejected alternative is an invented wrapper or public access broadening.

- 2026-08-10 B010 UID0002PA accepted implementation callback:
  - Score, owner/emitter, class range, inheritance, singleton lifecycle, and blank class CPP/H policy remain unchanged.
  - Synchronized the `m_serverDirectory` dependency to the complete canonical entry/directory layout, including `agreementText`, unsigned-short `port`, `entryCount`, and `version`.
  - Historical incomplete field lists, generic port/suffix wording, reserved placeholders, and missing-version assumptions remain in dated history only.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NO`.
  - Before: The pre-login server-selection dialog remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ServerSelectPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor/action/update/destructor-family starts at `0x00573d20`, `0x00574310`, `0x00574340`, `0x00574440`, `0x00574750`, `0x0057475b`, `0x00574766`, and `0x00574780`; parent [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) owns the pre-login server-selection module.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents the pre-login dialog role, file ownership, main range, constructor/destructor/action/update/destructor-thunk map, caller/xref evidence, singleton, and helper-pollution caveat; remaining completion gap is source-ready reconstruction detail.
- 2026-06-22 B013 Rule 26 support sync:
  - Score unchanged at `86/88`.
  - Added `m_serverDirectory` at `+0x26c`, the `ServerSelectPane(ServerSelectDirectory *)` constructor direction, child id `3` / child storage `+0x108` action-handler behavior, selected-server helper naming, and the reason the old chat-color route is owner pollution rather than an alternate class owner.
- 2026-07-26 B005 UID0002XN implementation callback:
  - Raised `86/88` to `90/93` while retaining UID0000NO owner/emitter and blank formal class CPP/H.
  - Added direct `DialogPane` plus `Singleton<ServerSelectPane>` inheritance, exact RTTI descriptors and PMD `+0x26c`, EBO overlap with `m_serverDirectory`, `0x270` allocation, the complete seven-reference singleton lifecycle, external UID0000S8 definition/header route, loader-zero/boundary evidence, historical `0xffffffff` correction, negative evidence, and explicit exact-child/file source policy.

## 2026-07-15 UID0003UP Server-Endpoint Synchronization

- Class score, inheritance, fields, methods, children, complete formal, and all server-list/selection behavior remain unchanged.
- Current Config dependency is `m_serverEndpointText[64]` at `+0x291230` for formatted endpoint text. ANSI `m_loginServerAddress`, startup port/mode, and tail `m_musicFolderPath` are separate fields with separate consumers.
- Any earlier present-tense MP3Dir/music-folder claim for `+0x291230` is historical and superseded by constructor, ServerSelect formatting, persistence, and music-consumer evidence. No class member or source-route delta is added.
