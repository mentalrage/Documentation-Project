*** UID:0001LI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ED | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ED | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TargetObjectWithKeyboardPane::TargetObjectWithKeyboardPane()
    : LineInputPane(NULL)
{
    s_activeTargetObjectWithKeyboardPane = this;

    SetPromptText(L"Use arrow key to select target then press 'v'.");

    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
    if (target == NULL ||
        target->ObjectType() != kLivingObjectType ||
        target->IsTargetingDisabled()) {
        target = g_pUserPane->GetLocalPlayerObject();
    }

    target->SetTargetHighlight(true);
    s_targetObjectTargetId = target->ObjectId();

    SetPaneOrder(NULL, g_pBackPane);
    s_targetObjectTargetModeActive = false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: IDA-confirmed constructor attached to `TargetObjectWithKeyboardPane`, with exact `0xee` boundary, neighboring padding, LineInputPane base setup, singleton publish/guard clear, three vtable stores, prompt setup, saved-target validation/fallback, highlight and saved-id updates, capture-pane registration, mode-byte clear, callee/global refs, and parent attachment documented. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x005afef0-0x005affde - TargetObjectWithKeyboardPane Constructor

## Status

- Confidence: strong for the contiguous constructor body, class ownership, singleton/global side effects, vtable stores, and neighboring padding.
- Related class: [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- Related file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- IDA function: `sub_5AFEF0`, contiguous body `0x005afef0-0x005affde`, size `0xee`.
- Reconstructable: true; this is source-authored game UI constructor logic and now has formal first-draft C++.
- Autogen parent: [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md). The class parent is `86/80`, and its file parent [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) is `88/80`, so the parent-attachment gate is satisfied.

## Covered Range

| Range | Owner | Role |
| --- | --- | --- |
| `0x005afef0-0x005affde` | `TargetObjectWithKeyboardPane::TargetObjectWithKeyboardPane` | Builds the `LineInputPane` base, publishes the active singleton, installs the three class vtable views, initializes the visible prompt, resolves and validates the saved target object, highlights the selected object, records the selected target id, attaches to the capture pane, and clears the target-selection mode byte. |

## Behavior

- Calls the line-input base constructor helper `sub_4F1C00(this, 0)` at `0x005aff1c`.
- Publishes the active `TargetObjectWithKeyboardPane` singleton through `dword_69BF64`. The normal path stores `this` at `0x005aff37`; the compiler cleanup/null path stores `0` at `0x005aff3e`.
- Installs the primary vtable at `this+0x0`, the secondary line-input view at `this+0xa0`, and the tertiary view at `this+0xa4`.
- Sets the prompt text through `sub_4F20A0` with `Use arrow key to select target then press 'v'.`.
- Looks up the previous target object by calling `sub_506970(dword_67A764, dword_69BF2C)`.
- Accepts that object only when it exists, its state byte at `+0xf8` is `3`, and its byte at `+0x1d0` is clear; otherwise it falls back to the local player object at `dword_67A748`.
- Calls `sub_53B1B0(selectedObject, 1)` to highlight/select the object.
- Stores the selected object's id from offset `+0xfc` back into `dword_69BF2C`.
- Calls `sub_544D30(this, 0, dword_67A740)` to attach/register the pane with the active capture/input owner, then clears `byte_69BEDA` to `0`.

## Boundary Evidence

- IDA MCP `lookup_funcs` on 2026-06-05 reports `sub_5AFEF0` at `0x005afef0` with size `0xee`; `0x005affde` is not a function, and the next function is [UID:0001LJ][0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor](by-memory/0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor.md).
- The constructor body ends with `retn` at `0x005affdd`, followed by two `0xcc` bytes at `0x005affde-0x005affe0`.
- The previous neighboring body ends before this constructor and has two `0xcc` bytes at `0x005afeee-0x005afef0`, so the constructor start is closed from both sides.
- The destructor after this constructor ends at `0x005b0009` and is followed by seven `0xcc` bytes before [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md).
- IDA disassembly associates compiler SEH cleanup chunks at `0x0060b0f0` and `0x0060b0f8` with this function. Those chunks perform exception-unwind cleanup calls outside this contiguous by-memory range and are compiler support evidence, not additional source body bytes owned by `0x005afef0-0x005affde`.

## Call and Xref Evidence

- IDA `callers` reports no ordinary direct static callers to `0x005afef0`.
- IDA `callees` reports calls to `0x004f1c00`, `0x004f20a0`, `0x00506970`, `0x0053b1b0`, and `0x00544d30`, matching base construction, prompt setup, map-object lookup, highlight toggle, and pane registration.
- `dword_69BF64` has constructor writes at `0x005aff37` and `0x005aff3e`, destructor clear at `0x005afffa`, helper clear at `0x005b7630`, and scalar-deleting destructor clear at `0x005b81f0`; this matches [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md).
- `dword_69BF2C` is read at `0x005aff72` and written at `0x005affba`; IDA reports broader xrefs from the target-object keyboard and mouse handlers, target-dispatch helper functions, and neighboring target-selection flows, matching [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md).
- `byte_69BEDA` is cleared by this constructor at `0x005affc4` and is also referenced by target-flow functions at `0x005a5bd0`, `0x005ad450`, `0x005ad500`, [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md), and `0x005b06f0`.

## Vtable Evidence

| Address | IDA name | Constructor write | Other matching refs |
| --- | --- | --- | --- |
| `0x0062f3b4` | `??_7TargetObjectWithKeyboardPane@@6B@` | `0x005aff53` writes to `this+0x0` | Destructor restore at `0x005affe0`; scalar deleting destructor restore at `0x005b81d6`; first slot points to `0x005b81d0`. |
| `0x0062f404` | `??_7TargetObjectWithKeyboardPane@@6B@_0` | `0x005aff59` writes to `this+0xa0` | Destructor restore at `0x005affe6`; scalar deleting destructor restore at `0x005b81dc`; first slot points to adjustor thunk `0x005b7912`. |
| `0x0062f434` | `??_7TargetObjectWithKeyboardPane@@6B@_1` | `0x005aff63` writes to `this+0xa4` | Destructor restore at `0x005afff0`; scalar deleting destructor restore at `0x005b81e6`; first slot points to adjustor thunk `0x005b791d`. |

## Reconstruction Notes

- This range should rebuild as the `TargetObjectWithKeyboardPane` constructor in the target-selection input pane source family, not as a free helper.
- The constructor relies on module-scope target-selection globals for the active singleton and saved target id. Those globals should rebuild as source-level static/module globals, not fixed-address storage.
- The body is well understood and now emits first-draft C++. Exact original identifiers and the final original `.cpp` split remain confidence caps only; the accepted source shape mirrors the sibling SelectObject constructor and the binary data flow.

## Cross-References

- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:0001LJ][0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor](by-memory/0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor.md)
- [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md)
- [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md)
- [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md)
- [UID:0001NL][0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor](by-memory/0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md)
- [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md)

## Changes

- 2026-06-29 B005 UID0000OH direct empty-emitter callback:
  - Score unchanged at `88/92`; formal first-draft C++ now emits `TargetObjectWithKeyboardPane::TargetObjectWithKeyboardPane()`.
  - Summary/evidence: current MCP confirms the constructor range `0x005afef0-0x005affde`, LineInputPane base setup, active singleton publish to `s_activeTargetObjectWithKeyboardPane`, exact prompt literal, saved target lookup/validation/fallback, target highlight, saved-id store, pane-order registration, and `s_targetObjectTargetModeActive=false`. Vtable stores, SEH cleanup, and raw global names remain documentation evidence, not source statements.
- Before: the page was a short `70/85` summary with blank reconstructable and parent metadata.
- Changed to: `COMPLETION:88`, `CONFIDENCE:92`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000ED`.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the constructor boundary, neighboring `0xcc` padding, no direct function xrefs, exact vtable stores, singleton writes, saved-target read/write, mode-byte clear, callees, and sibling destructor/handler relationships. Existing class/file docs meet the 80/80 parent gate. No final C++ was emitted because the page remains below the 95/95 final-code bar.
