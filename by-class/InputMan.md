*** UID:00006J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_INPUT_INPUTMAN_H
#define NEXUSTK_INPUT_INPUTMAN_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include <windows.h>
#include <imm.h>

class List;

class InputMan : public LObject, public Singleton<InputMan>
{
public:
    InputMan();
    virtual ~InputMan();

    void TrackInputTarget(int targetId, bool active);
    unsigned char GetImeStateByte() const;
    bool HandleWindowMessage(HWND window, UINT message, WPARAM wParam,
                             LPARAM lParam, LRESULT *result);
    bool HandleDefaultWindowMessage(HWND window, UINT message,
                                    WPARAM wParam, LPARAM lParam,
                                    LRESULT *result);
    int GetInputMode() const;
    BOOL SetInputMode(int mode);

private:
    HWND m_defaultImeWindow;
    HIMC m_ownedImeContext;
    HIMC m_restoreImeContext;
    DWORD m_imePropertyFlags;
    WORD m_imeStateWord;
    int m_inputMode;
    List *m_inputTargetList;
};

BOOL __stdcall CompleteImeComposition();
int __stdcall GetCompositionCursorPosition();

extern InputMan *g_pInputMan;

typedef char InputManSizeMustBe32[sizeof(InputMan) == 0x20 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InputMan

## Summary

`InputMan` is the global keyboard/mouse/IME manager. It derives directly from `LObject` and the storage-free `Singleton<InputMan>` base, creates and owns an IME context, tracks active input targets, and converts Win32 input and IME window messages into higher-level client events.

## Likely Original Placement

- Source: [UID:0000K6][InputMan](by-file/InputMan.md)
- Proposed path: `input/InputMan.cpp`
- Confidence: strong
- Parent attachment: attached to [UID:0000K6][InputMan](by-file/InputMan.md); the current file root and class page both clear the strict owner/emitter gate.

## Observed State

| Offset | Recommended source-facing name | Type | Evidence |
| --- | --- | --- | --- |
| `+0x00` | vptr | `InputMan` vtable | Constructor and destructors store the `0x0061c5a4` vtable. |
| `+0x04` | `m_defaultImeWindow` | `HWND` | Constructor stores `ImmGetDefaultIMEWnd(appWindow)`. |
| `+0x08` | `m_ownedImeContext` | `HIMC` | Constructor stores `ImmCreateContext`; destructor destroys it; custom `0x401` associates/disassociates it. |
| `+0x0c` | `m_restoreImeContext` / `m_previousImeContext` | `HIMC` | Destructor re-associates this field if nonzero. No positive constructor write is currently proven, so keep this as a destructor-supported inference. |
| `+0x10` | `m_imePropertyFlags` | `DWORD` | Constructor stores `ImmGetProperty(GetKeyboardLayout(0), IGP_PROPERTY)`; `WM_IME_SETCONTEXT` checks bit `0x20000`. |
| `+0x14` | `m_imeStateWord` | `WORD` | Constructor clears the word; `0x004e8dd0` reads the high byte at `+0x15`. No stronger semantic name is proven. |
| `+0x18` | `m_inputMode` | `int` | Constructor initializes `2`; `GetInputMode` returns it; `SetInputMode` writes it. |
| `+0x1c` | `m_inputTargetList` | `List<int> *` | Constructor allocates a list with element size `4`; `TrackInputTarget` stores integer target ids and posts `0x401` on empty/non-empty transitions. |

The constructor, ordinary destructor, scalar deleting destructor, mode getter/setter, and target-tracking method all support this layout. `m_restoreImeContext`, `m_imeStateWord`, and the `GetImeStateByte` spelling remain descriptive/inferred names, not proven original symbols.

## Methods

| Range | Role |
| --- | --- |
| [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) | Aggregate page for the exact executable island. |
| `0x004e8af0-0x004e8c11` | Constructor; creates IME context, associates it with the app window, disables IME open status, reads IME properties, and allocates the input-target list. Compiler lowering of the explicit `Singleton<InputMan>::Singleton()` specialization publishes the complete object; the derived body has no manual assignment. |
| `0x004e8c20-0x004e8ca1` | Ordinary destructor; restores the saved app IME context, destroys the owned context, and releases list state. Reverse-base lowering of `Singleton<InputMan>::~Singleton()` clears the global before `LObject` teardown; the derived body has no manual clear. |
| `0x004e8cf0-0x004e8dcb` | `TrackInputTarget`; adds/removes target ids and sends message `0x401` when the tracked set changes empty/non-empty state. |
| `0x004e8dd0-0x004e8dd5` | No-route accessor returning byte `this+0x15`; document as `GetImeStateByte` / `GetImeStateFlags` over the high byte of `m_imeStateWord`. |
| `0x004e8de0-0x004e9319` | `HandleWindowMessage`; handles IME composition, candidates, open status, character dispatch, owned-context replacement, custom `0x401` context toggling, and fallback dispatch. |
| `0x004e9430-0x004e9434` | `GetInputMode`; returns `+0x18`. |
| `0x004e9440-0x004e9485` | `SetInputMode`; changes mode and finalizes active composition when switching into mode `2`. |
| `0x004e9490-0x004e95ab` | IME helper group used by this class and IME pane code: composition finalization, `GCS_CURSORPOS` composition cursor-position query at `0x004e94d0`, composition-string copy, and current-context release. |
| `0x004e9650-0x004e965b` | Compiler-retained constructor-unwind action for `Singleton<InputMan>::~Singleton()`; one EH xref, no ordinary caller, and no standalone source body. |
| `0x004e9660-0x004e970d` | Scalar deleting destructor; mirrors ordinary cleanup and conditionally deletes `this`. |

## Evidence

- IDA MCP confirms the complete 26-start aggregate: 24 source-authored bodies plus compiler-only Singleton unwind at `0x004e9650` and scalar deleting destruction at `0x004e9660`; the source inventory also includes the raw current-context getter and ten retained IMM/PlatformApi wrappers through `0x004e964a`.
- RTTI independently proves both bases: COL `0x00649444`; CHD `0x00649458`, attributes `1`, base count `3`; InputMan and LObject PMD `0`; `Singleton<InputMan>` PMD `+4`; Singleton descriptor `0x00676dac`. Preserved executable offset `0x2749B8` contains `?$Singleton@VInputMan@@@@`.
- IDA MCP shows the constructor caller at `Application::Initialize` address `0x00464572`.
- IDA MCP shows `HandleWindowMessage` called from application message handling at `0x00465fad`.
- IDA MCP xrefs tie `g_pInputMan` at `0x0067ab44` to constructor/destructor paths, application message-loop users, IME pane code, and UI focus paths.
- IDA MCP xrefs tie the `InputMan` vtable at `0x0061c5a4` to constructor, ordinary destructor, and scalar deleting destructor stores.
- Decompilation shows direct calls to `ImmGetDefaultIMEWnd`, `ImmCreateContext`, `ImmAssociateContext`, `ImmGetContext`, `ImmSetOpenStatus`, `ImmNotifyIME`, `ImmReleaseContext`, `ImmDestroyContext`, `ImmGetOpenStatus`, and `ImmGetCompositionStringW`.
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms constructor `sub_4E8AF0` size `0x121`, ordinary destructor `sub_4E8C20` size `0x81`, target-tracking method `sub_4E8CF0` size `0xdb`, window-message dispatcher `sub_4E8DE0` size `0x539`, `GetInputMode` size `0x4`, `SetInputMode` size `0x45`, IME helper group `sub_4E9490` size `0x34`, singleton clear helper `sub_4E9650` size `0xb`, and scalar deleting destructor `sub_4E9660` size `0xad`; `0x004e8cc0` still reports `Not a function`.
- Current component evidence ties the `InputMan` vtable `0x0061c5a4` to the constructor, ordinary destructor, and scalar deleting destructor, and reports the main interface functions `0x004e8de0`, `0x004e9440`, `0x004e8af0`, `0x004e8cf0`, `0x004e9430`, and `0x004e9490` in the same class island. `make_signature_for_range(0x004e8af0,0x004e970d)` returns a unique wildcarded signature for the documented span.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The page records both direct bases, exact `0x20` EBO layout, complete API/header dependencies, 24 source bodies and two compiler-generated starts, explicit Singleton specialization ownership, full RTTI/vtable regeneration, raw wrapper inventory, candidate behavior/defects, and CPP-only child routing. |
| Confidence | 95 | Live IDA, preserved executable RTTI bytes, constructor/destructor lowering, file/aggregate/global/template docs, and generated routing agree. Exact original spellings for several fields/no-route wrappers remain inferred, which prevents a higher score. |

## Open Questions

- Exact original spellings for `m_restoreImeContext`, `m_imeStateWord`, `GetImeStateByte`, and `GetKeyboardLayoutLanguageName` remain unproven; the current names are source-facing descriptive names backed by behavior.
- The candidate-list producer transfers a heap `std::deque<std::wstring>` pointer through Event type `15`; checked EventMan, EventDispatcher, Event destructor, and IMECandidatePane paths do not delete it. Preserve this original leak rather than inventing ownership cleanup.
- These remaining caveats do not block formal C++ for [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md).

## UID000090 Complete Header Dependency Closure - 2026-07-31

- `InputMan.h` now owns the complete source declaration required by `Pane.cpp`: the Win32 scalar/handle types come from `<windows.h>`, `List` remains a legal pointer-only forward declaration, and `TrackInputTarget(int,bool)` is visible at the Pane call site.
- The accepted `0x20` layout is emitted explicitly. The vptr is compiler-generated; the seven source fields occupy `+0x04..+0x1f`, with the two-byte `m_imeStateWord` followed by natural two-byte alignment before `m_inputMode`.
- `g_pInputMan` is declared in the same header because Pane focus registration consumes the process-wide manager. The aggregate method bodies remain children of this class through [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md); the class page does not duplicate them.
- Historical blank-H/PCH-only consumption is superseded. Exact original spellings for the few behavior-derived field/accessor names remain documented confidence qualifications, but they no longer prevent a complete, compilable source-facing declaration.

## g_pInputMan Definition And Physical Backing Contract - 2026-08-06

- [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) is now the narrow semantic owner for the process-wide singleton pointer and emits the sole source definition `InputMan *g_pInputMan = 0;` through [UID:0000K6][InputMan](by-file/InputMan.md).
- [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) remains the exact physical backing page. It is non-reconstructable/non-emitting after the semantic split so the rebuilt source receives one definition rather than a duplicate address-page definition.
- This class page remains the sole declaration owner. Its formal H block continues to emit exactly one `extern InputMan *g_pInputMan;` beside the complete `InputMan` declaration; the global page's formal H channel is intentionally blank.
- PE mapping resolves the historical initializer conflict. VA `0x0067ab44` is RVA `0x0027ab44` in `.data`, at section offset `0x0000db44`, beyond raw size `0x0000d800`; the Windows loader supplies `00 00 00 00`. Dated current IDB bytes agree. The older `ff ff ff ff` / `0xffffffff` interpretation is retained only as disproved history and must not be treated as the live initializer.
- Five lifecycle writes close the singleton contract, but they are compiler lowering of the two explicit specializations on the direct `Singleton<InputMan>` base: constructor publication at `0x004e8b33`, constructor-unwind clear at `0x004e8b3a`, ordinary-destructor clear at `0x004e8c81`, EH-only unwind action at `0x004e9650`, and scalar-path clear at `0x004e96c8`. None is a manual `InputMan` body assignment or standalone helper source.
- The remaining thirteen of the exact 18 direct xrefs are consumers in Application (`0x00464bff`, `0x00464d94`, `0x00465f84`, `0x004661c7`), IME composition (`0x004e7600`), MainMenu (`0x004f6796`, `0x004f8ae4`), Pane (`0x005445cc`, `0x00544ebb`, `0x00544ecd`, `0x00544fa3`), TextEditPane (`0x00590f65`), and UserPane (`0x005a25e0`). Consumers do not own the source symbol; the InputMan constructor/destructor island and header contract establish the InputMan.cpp/InputMan.h route.
- The exact source-facing type/name are `InputMan *` and `g_pInputMan`. Raw `unk_67AB44`/`dword_67AB44` labels are IDA artifacts, not plausible original symbols. The accepted `= 0` initializer is high-probability C++03-era spelling for the proven null runtime state; implicit zero or `NULL` cannot be distinguished from the binary.
- Class completion/confidence are now `94/95`; the global definition/backing route, direct Singleton base, class-specific specializations, complete RTTI, API/header route, and candidate ownership defect are resolved, while only exact source spellings remain a cap.

## UID0000K6 Dual-Base And Complete API Closure - 2026-08-24

- Formal H is complete and ends at its guard: `LObject.h`, `Singleton.h`, `<windows.h>`, and `<imm.h>`; pointer-only `class List;`; `class InputMan : public LObject, public Singleton<InputMan>`; all seven fields in exact order; constructor/virtual destructor; `void TrackInputTarget`; primary and five-argument fallback handlers; state/mode API; free composition helpers; one global extern; and the `0x20` size guard. The H channel contains no `[[CHILDREN]]` marker.
- Formal CPP is exactly `[[CHILDREN]]`, making the class the sole child route for the complete aggregate while leaving declarations in H. Direct-file emitter position `1` places this route after UID00050J position `0`, so the definition/specializations precede `InputMan::InputMan`. Shared [UID:0004ZK][Singleton](by-file/Singleton.md) and [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md) own the complete storage-free primary template; InputMan includes it and does not duplicate it.
- The dual-base layout is ABI-consistent: `LObject` begins at PMD `0`; empty `Singleton<InputMan>` has PMD `+4`; source fields remain at `+0x04..+0x1f`; total x86 size is `0x20`. The constructor's adjusted `this+4` publication and reverse teardown are explicit-specialization lowering under empty-base optimization.
- The compiler RTTI hierarchy is complete: COL `0x00649444`; InputMan descriptor `0x00676d94`; CHD `0x00649458` with attributes `1` and three bases; base array `0x00649468`; InputMan/LObject/Singleton descriptors `0x00649478`/`0x00640348`/`0x00649494`; Singleton type descriptor `0x00676dac`; PMDs `0`, `0`, and `+4`. The three vtable slots remain compiler-generated from the virtual declaration and inheritance.
- All known source behavior is routed through the 24-body UID00018E aggregate. `0x004e9650` and scalar deleting destruction are compiler-covered/no-code; UID0003BR is compiler RTTI/vtable data; UID000299 is loader-zero physical backing; UID00018F/UID0001WO are adjacent STL deque support. No InputMan-owned string or resource exists.
- Preserved original defects remain explicit: `m_restoreImeContext` has no proven constructor write; special packed-DBCS candidate handling can use uninitialized `pageStart`; the dispatched candidate deque has no proven deleter. These are behavior fidelity constraints, not open implementation placeholders.

## Cross-References

- File: [UID:0000K6][InputMan](by-file/InputMan.md)
- Global: [UID:00050J][g_pInputMan](by-global/g_pInputMan.md)
- Global backing data: [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md)
- Memory: [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md)

## Changes

- 2026-08-24 B008 UID0000K6 six-claim implementation callback: inserted the sole formal CPP `[[CHILDREN]]` route between the managed markers. UID00006J remains direct emitter UID0000K6 at position `1`, after UID00050J at position `0`, and expands UID00018E exactly once without changing the complete formal H channel.

- 2026-08-24 B008 UID0000K6 accepted implementation callback: changed `88/90 -> 94/95`; set direct-file emitter position `1`; replaced the partial single-base H with the complete guarded dual-base declaration and Singleton dependency, moved child expansion to CPP only, documented explicit specialization lowering and compiler-only unwind/scalar paths, added full RTTI/PMD evidence and complete API/wrapper inventory, and closed candidate ownership/pageStart issues as preserved original behavior.

- 2026-08-06 B002 UID000299 accepted callback: retained `88/90` and the formal H block byte-for-byte; added [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) as the semantic definition owner, [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) as non-emitting physical backing evidence, exact PE loader-zero-fill correction, all five lifecycle writes and thirteen consumers, one-definition CPP/H routing, and historicalized the disproved `0xffffffff` initializer claim.
- 2026-07-31 B002 UID000090 dependency callback: populated the formal H block with the complete `InputMan` declaration, exact `0x20` fields, accepted API, singleton declaration, size guard, and child route so `Pane.cpp` can legally call `TrackInputTarget`; preserved the aggregate body owner and all spelling caveats.

- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: global input/IME manager purpose, original placement, six major methods, Win32 IMM API use, Application call sites, and open event-helper/global typing questions are documented; completion is capped because helper event-class naming and function-pointer globals remain unresolved. Evidence: `0x004e8af0-0x004e970c.InputMan`, Application initialization/message-handling xrefs, and IMM API calls.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the global input/IME manager unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/82`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e8af0`, `0x004e8cf0`, `0x004e8de0`, `0x004e9430`, `0x004e9440`, and `0x004e9660`; constructor and window-message callers remain the application paths at `0x00464572` and `0x00465fad`.
- 2026-06-06 A005 InputMan refresh:
  - Before: the class remained `74/82`, unparented, omitted the ordinary destructor/helper group/singleton clear helper, and linked the aggregate with stale `0x004e970c` end.
  - After: raised to `82/86`, attached to [UID:0000K6][InputMan](by-file/InputMan.md), linked the corrected [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) aggregate, and added state layout plus the full IDA-backed method/helper inventory.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, and targeted decompilation on 2026-06-06 confirmed the missing functions, corrected end boundary, constructor/window-message callers, singleton/vtable xrefs, IME API use, and remaining callback/function-pointer naming caveats.
- 2026-06-15 A002 Goal 2 by-class refresh:
  - Changed to: scores `86/89`, with no owner/emitter changes.
  - Summary/evidence: live IDA reconfirmed current method/helper sizes, `0x004e8cc0` raw non-function status, vtable lifecycle ties, main interface island membership, corrected class-span boundary, and unique signature. C++ remains blank because event-helper names, platform function-pointer globals, the keyboard-layout stub, and final field names are not source-quality.
- 2026-06-17 B003 support update:
  - Changed support wording without changing score.
  - Summary/evidence: [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) validates `0x004e94d0` as `InputMan::GetCompositionCursorPosition` / `GCS_CURSORPOS`, not a composition-length helper; the composition pane uses it to measure the caret x position inside the copied composition string.
- 2026-06-18 B001 InputMan source-quality reanalysis:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Summary/evidence: [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) reanalysis resolves Event helper names, PlatformApi dispatch slot names/signatures, raw no-route helper roles for `0x004e8cc0` and `0x004e8dd0`, source-facing field names, `TrackInputTarget` list semantics, IME message/event payload structures, and formal C++ readiness. `InputMan.cpp` remains under [UID:0000K6][InputMan](by-file/InputMan.md); Event factories stay in [UID:0000J6][Event](by-file/Event.md), pane-side IME UI stays in [UID:0000K5][IMEPanes](by-file/IMEPanes.md), and API dispatch storage stays in [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
[[CHILDREN]]
