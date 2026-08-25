*** UID:0000N0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ReconnectDialog

## UID0003ZT Header Consumer Synchronization - 2026-07-23

- The canonical source pair remains `NexusTK/network/ReconnectDialog.h` and `NexusTK/network/ReconnectDialog.cpp`.
- ReconnectDialog.h exports the complete [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) declaration, including its AlertPane and Singleton bases, constructors, callbacks, and private initialization helper.
- MapPane.cpp now includes ReconnectDialog.h before [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) performs `new ConnectionClosedDialog`. This is a complete-type dependency only.
- ReconnectDialog.cpp retains all existing class bodies, singleton/compiler lifecycle, global definitions, parser/reconnect behavior, and mixed-aggregate exclusions. It also owns the private file-local CopyWindow class required by `ConnectionClosedDialog::InitializeConnectionState`; nothing is moved or duplicated in MapPane.cpp.
- The by-file root remains blank formal at its current `92/94` metadata with `NexusTK/network/` ownership unchanged; the complete source assembly continues through its ordered class/global children.

## Status

- Disposition: reconstructable source-file root.
- Confidence: very strong for the shared `ReconnectDialog.cpp` grouping, complete source-ready `ConnectionClosedDialog` declaration and ordered children, exact method/destructor children, and singleton globals; medium-high for final historical folder spelling because `network/` is the active reconstruction path while `login/` remains a plausible historical alternative.
- Proposed module folder: `network/`
- Proposed source file: `network/ReconnectDialog.cpp`
- Current generated source root: `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- Historical generated names `class_ReconnectDialog.cpp` and `class_ConnectionClosedDialog.cpp` are search leads only. Current ownership is based on IDA-backed by-memory/by-class/by-global documentation, especially [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md), [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md), the attached class pages, and separate by-global singleton definitions.

## Hypothesis

`ReconnectDialog` and `ConnectionClosedDialog` are network-session UI alerts. They should be kept together because both are thin `AlertPane` specializations over the same reconnect/leave/cancel flow and share singleton globals such as `g_pReconnectDialog` and `g_pConnectionClosedDialog`.

The likely source placement is near networking/session recovery rather than generic alert UI:

```text
network/ReconnectDialog.cpp
network/ReconnectDialog.h
```

If the original tree grouped all login-screen UI together, `login/ReconnectDialog.cpp` is also plausible, but the packet send/disconnect/reconnect behavior makes `network/` the stronger current hypothesis.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) | `0x00553c10`, `0x00553cc0-0x00553f36`, destructor family at `0x0055456b+` | `class_ConnectionClosedDialog.cpp` historical search lead | `92/94` source-ready connection-loss alert with default and explicit `Pane *` constructors, direct `AlertPane` plus `Singleton<ConnectionClosedDialog>` inheritance, protected packet/primary/secondary callbacks, private init helper, implicit virtual destructor, `0x270` size guard, typed global route, and ordered child emission. |
| [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) | `0x00553f40-0x005544b8`, destructor family at `0x00554581+` and `0x005545f0` | `class_ReconnectDialog.cpp` historical search lead | `88/92` reconnect alert with direct `Singleton<ReconnectDialog>` inheritance, reconnect/cancel/timeout behavior, typed global route, EBO state-byte evidence, and blank complete-class formal. |
| [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md) | [UID:0004SQ][0x0067ab54-0x0067ab58.g_pConnectionClosedDialog](by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md) | sole source definition plus covered storage | External `ConnectionClosedDialog *g_pConnectionClosedDialog = NULL;`, with ten refs and direct `Singleton<ConnectionClosedDialog>` PMD `+0x270` source cause. |
| [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md) | [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md) | sole source definition plus covered storage | External `ReconnectDialog *g_pReconnectDialog = NULL;`, with ten refs and direct `Singleton<ReconnectDialog>` PMD `+0x270` source cause. |
| [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md) | `[0x0067ab54,0x0067ab5c)` | non-emitting exact-range container | Preserves the historical two-slot range and split/nesting evidence without owning or emitting either definition. |

## Current Exact Children

| UID | Range / page | Current handling |
| --- | --- | --- |
| [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) | `ConnectionClosedDialog()` | Source-ready `92/94` child through UID000036 at position `10`: localized id `154`, `g_pBackPane`, Reconnect/Leave labels, private helper call, and compiler-lowered Singleton/facet setup. |
| [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | Alternate constructor and callbacks | Source-ready `92/94` child through UID000036 at position `20`: explicit `Pane *` constructor, `HandlePacketEvent(Event *)`, inherited `OnPrimaryButton()`, and `OnSecondaryButton()` definitions. |
| [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) | Private `ConnectionClosedDialog::InitializeConnectionState()` | Retains exact formal at its current `92/94`; emits directly through UID000036 at position `30`. The third machine-code call site is an inlined default-constructor mirror, preserving private access. |
| [UID:0003CT][0x00622d30-0x00622dd4.ConnectionClosedDialogVtableData](by-memory/0x00622d30-0x00622dd4.ConnectionClosedDialogVtableData.md) | ConnectionClosedDialog RTTI/vtable ABI evidence | `90/94` compiler-regenerated child through UID000036 at position `40`; emits only a covered-by marker after documenting complete/AlertPane, EventHandler, and TimerHandler slots/stores. |
| [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Reconnect constructors/handlers | Attached through [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md); records constructors, reconnect initiation, parser/state helper, button handler, and timeout handler. |
| [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) | Broader method-neighborhood aggregate | Kept unassigned and non-emitting as a physical research map. Exact semantic children carry class/file source ownership and compiler/no-code dispositions. |
| [UID:000039][CopyWindow](by-class/CopyWindow.md) and [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) | Private file-local class and interleaved retained constructor/callback island | The complete class emits through this file at position `20`; the executable child emits through UID000039 at position `10`. [UID:0000IH][CopyWindow](by-file/CopyWindow.md) is the non-emitting historical index. |
| [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md) | Compiler destructor support | Canonically grouped with this source family but non-reconstructable/non-emitting: two EH-only Singleton base destructor instantiations, four adjustors, and two scalar deleting wrappers. No handwritten clear/helper/wrapper body is emitted. |

## Singleton Definitions And Compiler Lifecycle

- [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md) and [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md) emit the only two definitions, at positions `10` and `20`.
- Exact storage children [UID:0004SQ][0x0067ab54-0x0067ab58.g_pConnectionClosedDialog](by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md) and [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md) emit only covered-storage comments through their by-global parents.
- Both slots are loader-zero-filled in the virtual-only `.data` tail. The stale all-ones reading is historical and does not represent a source sentinel or initializer.
- RTTI proves direct `Singleton<ConnectionClosedDialog>` and `Singleton<ReconnectDialog>` bases at PMD `+0x270`. Constructor stores, adjusted-null clears, EH-only tiny destructors, ordinary destruction, and scalar-wrapper clears are compiler lowering of those direct bases.
- Human source should contain direct class inheritance and the two external pointer definitions. It should not contain explicit publication/clear assignments, explicit template specializations, vptr stores, vtable/RTTI arrays, scalar flags, delete wrappers, or EH code.
- Application heartbeat code is a cross-module read-only consumer. It proves external linkage and requires both pointers null before sending, but it does not own either definition.

## ConnectionClosedDialog Source Order

The accepted source root remains the single `NexusTK/network/ReconnectDialog.cpp` module. Its compile-visible ConnectionClosedDialog order is:

1. [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md) and [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md) external definitions at file positions `10` and `20`.
2. [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) complete class declaration at file position `30`, with `[[CHILDREN]]` after the closing class and `0x270` size guard.
3. UID000036 child position `10`: no-argument constructor UID00023O.
4. UID000036 child position `20`: `Pane *` constructor and callback cluster UID00038J.
5. UID000036 child position `30`: private `InitializeConnectionState()` UID0001FU.
6. UID000036 child position `40`: covered-by RTTI/vtable evidence UID0003CT.

Before the existing ConnectionClosedDialog declaration/order, UID000039 now emits a private file-local `CopyWindow` class at file position `20`; its child marker orders UID0001FV/UID0003CV/UID0003G5/UID0003G6 at class positions `10/20/30/40`. This makes the class complete before the init helper's `new CopyWindow` expression.

The existing ConnectionClosedDialog order keeps method definitions after a complete declaration and lets MSVC regenerate the direct Singleton publication, inherited facet vptr stores, implicit destructor, adjustor/deleting wrappers, RTTI, and vtable bytes. The broad mixed aggregate UID0001FT and compiler-only UID00038K remain non-emitting.

The complete ConnectionClosedDialog declaration/order does not imply that the separate [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) class and [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) family are now source-ready. Their independent declaration/parser/member debt remains preserved and must not be hidden by this callback.

## Key Behavior

- `ConnectionClosedDialog::OnPrimaryButton()` (historically described as `OnReconnectClicked`) deletes an existing reconnect dialog and constructs `ReconnectDialog(m_layoutReference)`. The observed reconnect initiation is inlined constructor behavior, so source does not call it twice.
- `ConnectionClosedDialog::OnSecondaryButton()` (historically described as `OnLeaveClicked`) calls `g_pApplication->RequestExit()`.
- `ConnectionClosedDialog::HandlePacketEvent(Event *)` is the exact EventHandler slot and returns `true` unconditionally.
- Both out-of-line ConnectionClosedDialog constructors call private [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md). Its third call site is inside an inlined default-constructor mirror. The helper may create a `CopyWindow` side dialog, then posts socket mode byte `1`, drains the queue, and optionally dims the screen.
- `ReconnectDialog::InitiateReconnect` marks reconnecting state, sends a connect request using the saved server address/port, and arms a 10 second timer.
- `ReconnectDialog::OnButtonClick` handles cancel/reconnect branches, closes related UI panes, sends packet cleanup/reconnect messages, and calls [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md) on the confirmed IDA caller path.
- The same `ReconnectDialog::OnButtonClick` path is one of the two proven source-use sites for [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md): IDA shows the branch pushes `aBaram_0` at `0x00554276`, formats it at `0x00554287`, sends five bytes through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) at `0x0055429e`, then calls [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md) at `0x005542a9`. This file should emit the local packet text in final C++, but it must not claim canonical ownership of the pooled physical literal because [UID:0000OI][TerminalPane](by-file/TerminalPane.md) owns the other direct source-use site.
- `ReconnectDialog::OnReconnectTimeout` cancels reconnect, disconnects, and recreates the connection-closed dialog.
- The observed constructor publication pairs and teardown clears are binary evidence for direct Singleton base lifetime. They are not additional source-level global assignments or named clear helpers.
- The connection-closed constructor paths and `ReconnectDialog::OnButtonClick` are three of the four semantic source-use sites for the pooled reconnect prompt labels [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) `L"Leave"` and [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) `L"Reconnect"`. B001 post-migration evidence maps the ReconnectDialog-family source-use sites to `0x00553c44` in `sub_553C10`, `0x00553cf4` in `sub_553CC0`, and `0x0055435e` in `sub_554210`: the two `ConnectionClosedDialog` constructor paths call the alert initializer with the `Reconnect`/`Leave` label pair, and `ReconnectDialog::OnButtonClick` can build a replacement connection-closed prompt using the same pair. This file should spell those literals naturally at its prompt-construction sites during final C++ reconstruction, but it must not claim canonical ownership of the physical pooled `.rdata` cells because [UID:0000OI][TerminalPane](by-file/TerminalPane.md) owns an independent fourth source-use site.

## Boundary Notes

- The broader `0x00553c10-0x00554635` address neighborhood includes the retained `CopyWindow` constructor/callback island at `0x005544c0-0x0055454b`. Keep its exact semantic owner [UID:000039][CopyWindow](by-class/CopyWindow.md), while the class itself emits in this translation unit before the helper that constructs it.

## UID0000IH Private CopyWindow Closure - 2026-08-18

- [UID:000039][CopyWindow](by-class/CopyWindow.md) is a file-local `AlertPane` subclass emitted here at position `20`, before any helper use. It has no external complete-type consumer and therefore no standalone header.
- Its constructor uses `g_pLanguageMan->GetLocalizedString(0xf1)`, `g_pBackPane`, `L"Yes"`, and `L"No"`. `OnPrimaryButton()` unconditionally calls `g_pActiveTextEditPane->CopyAllToClipboard()` and then clears the pointer; `OnSecondaryButton()` only clears it.
- The retained executable island UID0001FV is covered by the inline class rather than duplicated. Exact constructor/callback SHA256 values are `F60A271C1E5608BA4A23E356AC4EC665E197F58198F960E6EF18E45DAE51B5A`, `0F320B7C42E472261185E1CCB80D5367E478714179AB71BB43D1A0258B88642F`, and `6C4EE44F24614EB481044283CB6DFB6FC686F039BBF263DED1FB65E8E93FC6AF`.
- UID0003CV vtables/RTTI and UID0003G5/UID0003G6 pooled labels are compiler/source-use children, not handwritten tables or standalone constants. Exact source order is class child positions `10`, `20`, `30`, and `40`.
- The helper remains a private ConnectionClosedDialog method. Its same-unit `new CopyWindow` use is the live source route; its packet mode byte `1`, queue drain, and optional screen dimmer behavior remain unchanged.
- The historical exclusion of CopyWindow from this file and the standalone `ui/dialogs/CopyWindow.cpp` interpretation are superseded. They remain recorded as plausible earlier inferences based on the retained body, own vtables, and older generated/source-tree leads.
- The stale IDA symbol on `0x00553e60` should not be used as naming evidence.
- Historical 2026-07-04 B013 callback: [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) first became formal helper-ready as `ConnectionClosedDialog::InitializeConnectionState()` at the then-current `89/91`; the helper is now `92/94`, and older generated views that only had an empty marker or call-site-only name are stale.
- 2026-06-06 A007 update: [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) was initially attached directly to this file, while [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) remained unassigned as a mixed non-emitting map.
- 2026-06-16 A001 update: [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) now routes through [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md), matching the alternate constructor child [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md). The file remains the generated source root for the class.
- 2026-06-11 A002 Batch178 update: exact child pages now cover the prior unsplit alternate `ConnectionClosedDialog` methods, `ReconnectDialog` methods, and cleanup/destructor tail; live IDA MCP reconfirmed function boundaries, singleton writes/clears, packet/timer behavior, and the interleaved CopyWindow exception.

## Remaining File-Level Work

- ConnectionClosedDialog source readiness is complete at the current `92/94` class/child gate. Keep the inferred private helper spelling unless stronger original-source evidence appears; bounded lexical uncertainty is not an empty-emitter blocker.
- Continue the independent method-name/member/header/parser audit for the ReconnectDialog class and UID00038L family. Optional finer per-method splits may still be useful for that separate family.
- Continue method-body splits for the unsplit constructor/handler ranges. The singleton source route is complete: UID0002VT is the non-emitting container, UID0004SQ/UID0004SR are exact storage, and UID0004SO/UID0004SP emit the sole definitions.
- Do not regress the now-formal ConnectionClosedDialog children to blank output. Keep only the independent ReconnectDialog class/method children blank until their own source-quality blockers are resolved.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The file page records the active reconstruction path, source-ready ConnectionClosedDialog declaration/order, private CopyWindow class and exact covered-by children, separate globals, direct Singleton compiler lifecycle, mixed aggregate distinctions, packet/resource history, and clearly separated remaining ReconnectDialog debt. |
| Confidence `94` | Grouping, exact definitions/zero storage, RTTI/PMD lifetime, constructor ABIs, method/vtable/helper maps, CopyWindow inline construction, no-external-type route, compiler boundary, and consumers independently agree. Historical `network/` versus `login/` spelling and separate ReconnectDialog declaration/parser debt remain bounded caps. |

## Historical / Superseded Assumptions

- Historical generated `class_ConnectionClosedDialog.cpp` and a separate ConnectionClosedDialog source file remain search leads only. Current evidence favors one shared ReconnectDialog.cpp root with class-child ordering.
- The prior blank ConnectionClosedDialog class/constructor markers and broad statement that all final child C++ must remain blank are superseded for UID000036/00023O/00038J/0001FU/0003CT. Independent UID0000BR/00038L empty-emitter debt remains current.
- Earlier `OnReconnectClicked`/`OnLeaveClicked` labels are preserved as behavior aliases; inherited source declarations are `OnPrimaryButton()`/`OnSecondaryButton()`.
- The third init-helper call site is retained as exact machine-code evidence but refined from an external direct call to an inlined default-constructor mirror.
- The former CopyWindow separation/dedicated-file conclusion is superseded by the complete same-unit private class route. UID0000IH remains as a non-emitting historical index rather than a generated source root.

## Cross-References

- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md)
- [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md)
- [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md)
- [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md)
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md)
- [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md)
- [UID:0004SQ][0x0067ab54-0x0067ab58.g_pConnectionClosedDialog](by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md)
- [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md)

## Changes

- 2026-07-22 B001 accepted UID00023O implementation callback:
  - Raised `89/91 -> 90/93`, retaining `CANONICAL_OWNER:FILE` and `NexusTK/network/`.
  - Added the complete UID000036 declaration/source order, positions for UID00023O/00038J/0001FU/0003CT, inherited callback names and behavior, private helper/inlined-mirror interpretation, covered-by vtable route, compiler/source boundary, and explicit preservation of unrelated ReconnectDialog/CopyWindow/aggregate debt.
  - Preserved both singleton definitions/storage routes, packet/resource evidence, folder alternative, destructor-support disposition, and all earlier file-family history.

- 2026-07-16 B003 UID0002VT implementation callback:
  - Raised `87/88 -> 89/91` while retaining `NexusTK/network/`, `CANONICAL_OWNER:FILE`, both dialog classes, all exact method children, CopyWindow exclusion, packet/resource history, and unrelated content.
  - Added source-emitting globals UID0004SO/UID0004SP, exact storage UID0004SQ/UID0004SR, retained non-emitting container UID0002VT, external Application consumer linkage, and one-definition policy.
  - Replaced source-authored clear-helper/global-assignment wording with direct Singleton RTTI/PMD compiler-lifecycle evidence. UID00038K remains source-family documentation but is non-emitting compiler support.
- 2026-05-28:
  - Before: the connection/reconnect neighborhood was cited as `0x00553cc0-0x00554634`.
  - After: corrected it to `0x00553c10-0x00554635` and kept the interleaved `CopyWindow` ownership note unchanged.
  - Evidence: IDA MCP confirms an earlier `ConnectionClosedDialog` constructor variant at `0x00553c10-0x00553cbf` and the final byte of the trailing destructor/helper range at `0x00554634`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `80`.
- Summary/evidence: the page documents reconnect/closed dialog grouping, key behavior, boundaries, IDA evidence, range correction, globals, and cross-references; confidence is strong but still capped by final `network/` versus `login/` source placement.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/network/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` places `ReconnectDialog.cpp` under `network/`, and the refreshed IDA MCP pass on the `0x00553e60` helper confirms the flow is connection/reconnect session UI with a conditional `CopyWindow` side path rather than generic alert or copy-window ownership.
- 2026-06-06 A007 file-owner refresh:
  - Before: score `84/80`, with high-level generated-source and IDA boundary evidence plus broad proposed contents.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:82`, direct references to attached `ConnectionClosedDialog`, `ReconnectDialog`, constructor variant, init helper, mixed aggregate, CopyWindow exception, singleton global-data support, and remaining split targets.
  - Summary/evidence: the exact constructor variant now attaches to this source root, `ConnectionClosedDialog` and `ReconnectDialog` class pages are parented here, and the aggregate page now documents why its mixed CopyWindow island keeps the aggregate unassigned. Final C++ remains deferred pending exact child splits and class/header audit.
- 2026-06-07 A006 singleton split refresh:
  - Before: score `86/82`, and dialog singleton storage still pointed at the mixed `0x0067ab54-0x0067ab84` aggregate.
  - Changed to: confidence `86`, with exact singleton-storage child [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md) attached to this file.
  - Summary/evidence: live IDA-backed split evidence confirms `g_pConnectionClosedDialog` and `g_pReconnectDialog` are published and cleared by the reconnect-dialog method family, while application timing code only reads them as heartbeat gates.
- 2026-06-11 A002 Batch178 exact-child refresh:
  - Changed completion/confidence from `86/86` to `87/88`.
  - Added exact method children [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md), [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md), and [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md); kept [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) unassigned as a mixed non-emitting map.
  - Evidence: live IDA MCP reconfirmed method boundaries, decompiled constructor/handler/reconnect/destructor behavior, singleton writes/clears, packet/timer calls, and the CopyWindow island exclusion.
- 2026-06-16 A001 constructor-route refresh:
  - Score unchanged at `87/88`.
  - Updated the [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) route from direct file attachment to [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) class attachment. This keeps source output in `ReconnectDialog.cpp` through the class route while preserving the narrowest semantic owner.
  - Evidence: live IDA confirms [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) is a `ConnectionClosedDialog` constructor with a single MapPane caller at `0x00508ffc`; caller reachability does not supersede class ownership.
- 2026-07-04 B013 helper implementation callback:
  - Updated [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) from unresolved marker-only helper wording to formal helper-ready `89/91` status.
  - The direct semantic owner is [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md), while emission remains through this [UID:0000N0][ReconnectDialog.cpp](by-file/ReconnectDialog.md) source root.
  - Evidence incorporated from MCP session `nexustk_supervisor_20260704`: caller xrefs `0x00553ca8`, `0x00553d55`, and `0x005543bb`, conditional CopyWindow path, packet-sender mode byte `1`, queue drain, optional screen-dimmer call, and stale debug-symbol rejection.
