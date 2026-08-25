** TARGET-REPORT-UID:0001LL **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001LL] TargetObjectWithKeyboardPaneMouseEvent Source-Quality Report

Agent: B005  
Target: `by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md`  
Assignment type: report-only B-preferred source-quality / heuristic-inference pass  
Date: 2026-06-18

## Final Recommendation

Move [UID:0001LL] from `84/88` to `88/90`, keep `CANONICAL_OWNER:0000ED`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000ED`, and populate first-draft method C++ for `bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)`.

The prior blank-C++ reason is stale. The old page says the block is blank because subtype/config/player/chat names were below a `95/95` threshold. Under the active gate and after the accepted SelectObject handler pass, this target now has enough target-specific proof: exact function boundary, vtable-only reachability, event structure layout, subtype roles, saved-target state, MapPane dependency names, UserPane/chat cleanup names, and owner/source route are all defensible. The method remains below final-source quality only because exact original spellings for some globals and shared event constants are inferred, not symbol-proven; that should not block a first-draft body.

Add one missing ignored coverage/support row for the preceding compiler-generated `TargetObjectWithKeyboardPane` key-handler switch support span `0x005b01da-0x005b0290`. Do not merge that span into either event method.

No by-memory, by-class, by-file, by-global, generated, or coverage file was edited by this pass.

## Evidence Checked

- Required guidance: `goal.md`, `notes.md`, `Supervisor.md`, `by-structure.md`, and `inference_research.md`.
- Target and support docs: [UID:0001LL], [UID:0000ED] `TargetObjectWithKeyboardPane`, [UID:0000OH] `TargetSelectionInputPanes`, [UID:0001L8] aggregate, [UID:0001LK], [UID:0001LI], [UID:0001LJ], [UID:00036R], [UID:00036S], [UID:00036T], [UID:00036U], [UID:0001NB], [UID:0001NL], [UID:0002AB], [UID:0002A9], [UID:0001OW], [UID:0001AU], [UID:00037Q], [UID:00037X], [UID:00028Q], [UID:0001OR], [UID:00028K], [UID:0002B5], `g_pChattingHandlePane`, `g_pChattingVarietyPane`, `UserPane`, `ChattingVarietyPane`, and the accepted B005 SelectObject report.
- Local IDA/Ghidra export artifacts:
  - `hooks-generation/tests/function_data/ida/0x005b0290.json`
  - `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x005b0290.json`
  - `resources/exported_data/functions/0x005b0290.json`
  - `re-agent/reports/code/0x005b0290_TargetObjectWithKeyboardPane_virt_meth_0x5b0290.cpp`
  - `hooks-generation/tests/function_data/ida/0x0050b1b0.json`
  - `C:/Users/admin/Desktop/CTools/Output/ida/memory/memory.bin`
- Active MCP resources were not exposed in this session and HTTP probes for a local bridge timed out. I therefore used checked-in/local IDA export data plus current by-* docs. I do not claim a new live-IDB label change.

## Boundary, Bytes, And Reachability

The local IDA export confirms `sub_5B0290` at `0x005b0290`, size `637` / `0x27d`, ending half-open at `0x005b050d`. IDA and Ghidra agree on the size. The only incoming xref in the export is the data offset at `0x0062f408`; there are no ordinary code callers. This matches the `TargetObjectWithKeyboardPane` secondary vtable slot, not a raw helper or dead island.

The IDA memory dump maps correctly with base `0x00401000`. Byte checks:

- `0x005b0290`: `55 8B EC 83 EC 3C ...`, the function prologue.
- `0x005b050d-0x005b0510`: `CC CC CC`, three-byte alignment before sibling `sub_5B0510`.
- `0x005b0510`: `55 8B EC ...`, the object-list helper prologue.
- `0x005b01da-0x005b0290`: not part of this method. It is `66 90` at `0x005b01da-0x005b01dc`, compiler switch support data at `0x005b01dc-0x005b0281`, then fifteen `0xcc` bytes at `0x005b0281-0x005b0290`.

The target's callee set remains exactly the exported IDA set: `sub_4B8E00`, `sub_506970`, `sub_4B7E80`, `sub_53B1B0`, `sub_50B1B0`, `sub_506CE0`, `sub_5B05B0`, `sub_469180`, and `@__security_check_cookie@4`.

## Source-Facing Interpretation

Recommended method signature:

```cpp
bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)
```

The `HandleTargetMouseEvent` label is descriptive but less source-facing than `OnMouseEvent`. The accepted SelectObject sibling uses `OnMouseEvent`, and this target is the same secondary-vtable event surface with the same event layout and coordinate normalization shape. The incoming `ecx` is the secondary/base view in the decompiler; source should describe the owner class method, not the adjusted subobject.

Recommended event structure fields:

- `event+0x04`: `kind` / mouse target-selection subtype.
- subtype `1`: `kMouseTargetChange`, the target-change/hover/click-selection path. It hit-tests the map point, updates highlight and saved target id, and may confirm immediately when `Config::DoubleClick` is disabled and a previous target existed.
- subtype `2`: `kMouseTargetConfirm`, the confirm/click path. It requires the translated point to be inside the active map rectangle and a saved target to resolve.
- `event+0x08`: `x`.
- `event+0x0c`: `y`.
- return `true`: event consumed or target confirmed.
- return `false`: ignored subtype, outside map, no confirmable target, or non-consuming first target change.

Recommended static/global names:

- `dword_69BF2C`: `s_targetObjectTargetId`, with `s_targetObjectSavedTargetId` as an acceptable longer descriptive alias. It is the target-object pane's saved/current object id, parallel to accepted `s_selectObjectTargetId` at `dword_69BF28`.
- `byte_69BEDA`: `s_targetObjectTargetModeActive`, with `s_targetObjectMapSelectionActive` as the semantic alias. It is not touched by this mouse method, but the paired class/keyboard/forward-helper docs should use it for the TargetObject target-dispatch mode flag.
- `dword_67A7C8 + 0x28de5a`: `Config::DoubleClick` / `g_pConfig->doubleClick`. In this target, nonzero means consume target-change events without immediate single-click confirmation; zero permits single-click confirmation when a previous target exists.
- `dword_67A74C`: `g_pApplicationCleanupQueue`, with `BlackHole::QueuePaneForDeferredDeletion(Pane *)` as the source-facing helper dependency.
- `dword_67A748`: use `g_pUserPane` in source-facing text, while retaining the `g_pCollectionData` alias in storage/global docs. `+0x210` is best expressed as `UserPane::ClearPendingTargetObject()` or `m_pendingTargetObject` cleanup state. `+0x3eb4` is already resolved by Chatting docs as `currentChatMode` / `currentChatVarietyMode`, so the source helper name `UserPane::ClearChatTargetState()` is defensible for this cleanup call.
- `dword_67ADE0`: `g_pChattingHandlePane`; `+0x111` is a pending chat-command/chat-target-state test. Exact member spelling is still not proven, but `IsCommandPending()` / `HasPendingChatTargetState()` is a high-probability descriptive method.
- `dword_67ADD8`: `g_pChattingVarietyPane`; virtual slot `+0x48` is best expressed as `RefreshAfterTargetSelection()` / `RefreshCurrentMode()`. The exact original name is not proven, but this is clearly a chat UI refresh dependency, not target-selection ownership of chat globals.

Recommended helper names:

- `sub_506970`: `MapPane::FindObjectPaneById(int objectId)`.
- `sub_506CE0`: `MapPane::HitTestObjectAtPoint(int x, int y)` / `FindObjectAtMapPoint`.
- `sub_50B1B0`: `MapPane::InteractWithObject(LivingObjectPane *target)` / `RequestObjectInteraction`. The IDA body sends opcode `0x43` with the target id at `+0xfc`, matching object interaction rather than highlight.
- `sub_53B1B0`: `LivingObjectPane::SetTargetHighlight(bool)`.
- `sub_4B8E00`: `MapPane::GetBoundsRect(Rect *)`.
- `sub_4B7E80`: `PointInRect(int x, int y, const Rect &)`.
- `sub_5B05B0`: `TargetObjectWithKeyboardPane::ClearCurrentTarget()`.
- `sub_469180`: `BlackHole::QueuePaneForDeferredDeletion(Pane *)`.

## Owner And Source Placement Ranking

1. `TargetObjectWithKeyboardPane` [UID:0000ED], under `TargetSelectionInputPanes.cpp` [UID:0000OH] - accepted. The method is reached through this class's secondary vtable at `0x0062f408`, consumes the class-specific saved target `dword_69BF2C`, calls the class-local clear helper `0x005b05b0`, and is paired with the constructor/destructor/keyboard/object-list/navigation/forward helpers already attached to this class.
2. `TargetSelectionInputPanes.cpp` as the file-level source family - accepted as emitter route via the class. The method belongs with the target-selection line-input pane family rather than one generated class file per pane.
3. `MapPane` - rejected as owner. It owns lookup, hit-test, coordinate, rectangle, and interaction helpers, but this body updates target-pane state and dismisses the target-selection pane.
4. `UserPane` / `Chatting` - rejected as owner. They provide cleanup/refresh dependencies for local-player and chat state after target confirmation. The only ownership evidence is dependency use.
5. `LineInputPane` - rejected as owner. This is a derived event override; base key/mouse infrastructure does not own the target-specific saved id, highlight, or dispatch behavior.
6. Generic UI/core or BlackHole - rejected. `BlackHole` owns the deferred deletion helper only; this target decides when to queue itself.
7. No-owner/non-emitting fallback - rejected. The function is vtable-reached, source-shaped, paired with an emitting class, and has a stable owner/emitter path.

## First-Draft C++ Recommendation

Recommended formal C++ block for [UID:0001LL]:

```cpp
bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)
{
    Point paneOrigin;
    Point mapOrigin;
    Rect mapRect;

    GetOrigin(&paneOrigin);
    g_activeMapPane->GetOrigin(&mapOrigin);

    const int mapX = event->x + paneOrigin.x - mapOrigin.x;
    const int mapY = event->y + paneOrigin.y - mapOrigin.y;

    LivingObjectPane *targetToConfirm = NULL;

    if (event->kind == kMouseTargetConfirm) {
        g_activeMapPane->GetBoundsRect(&mapRect);
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);

        if (!PointInRect(mapX, mapY, mapRect) || target == NULL)
            return false;

        targetToConfirm = target;
    } else if (event->kind == kMouseTargetChange) {
        LivingObjectPane *oldTarget =
            g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
        LivingObjectPane *hitTarget = g_activeMapPane->HitTestObjectAtPoint(mapX, mapY);

        if (hitTarget != NULL) {
            if (hitTarget != oldTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                hitTarget->SetTargetHighlight(true);
                s_targetObjectTargetId = hitTarget->GetObjectId();

                if (g_pConfig->doubleClick)
                    return true;
                if (oldTarget == NULL)
                    return false;

                targetToConfirm = hitTarget;
            } else {
                if (g_pConfig->doubleClick)
                    return true;
                if (oldTarget == NULL)
                    return false;

                targetToConfirm = oldTarget;
            }
        } else {
            g_activeMapPane->GetBoundsRect(&mapRect);
            if (!PointInRect(mapX, mapY, mapRect))
                return false;

            if (g_pConfig->doubleClick || oldTarget == NULL)
                return true;

            targetToConfirm = oldTarget;
        }
    } else {
        return false;
    }

    ClearCurrentTarget();
    g_pUserPane->ClearPendingTargetObject();
    g_activeMapPane->InteractWithObject(targetToConfirm);
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    g_pUserPane->ClearPendingTargetObject();

    if (g_pChattingHandlePane != NULL && g_pChattingHandlePane->IsCommandPending()) {
        g_pUserPane->ClearChatTargetState();
        if (g_pChattingVarietyPane != NULL)
            g_pChattingVarietyPane->RefreshAfterTargetSelection();
    }

    return true;
}
```

This intentionally uses a shared local `targetToConfirm` instead of copying the raw decompiler label structure. It preserves all binary-observed effects: subtype `2` confirm, subtype `1` hit/no-hit same-target/change-target behavior, `DoubleClick` gating, target-highlight clear/set, saved id update from `LivingObjectPane+0xfc`, `ClearCurrentTarget()` before interaction, two `+0x210` clears, selector dismissal through BlackHole, and the optional chat-mode cleanup/refresh epilogue.

## Heuristic / Inference Reanalysis And Validation

### Exact range and split

Checked local IDA export size `0x27d`, current target page notes, sibling `0x005b0510` page, coverage row, and direct bytes in `memory.bin`. Rejected extending the method backward into `0x005b01da-0x005b0290` because that span starts with `66 90`, contains switch metadata, and ends with fifteen `0xcc` bytes. Rejected extending forward because `0x005b050d-0x005b0510` is three `cc` bytes and `0x005b0510` is a new prologue. Score impact: raises confidence; adds missing ignored row. Source/C++ impact: no range split inside the method.

### Reachability

Checked IDA `xrefs_to` export and vtable bytes around `0x0062f404`: `0x0062f408` stores `90 02 5B 00`, exactly the target start. Rejected no-route/dead-code classification because the secondary vtable slot is a valid virtual dispatch route. Rejected ordinary-call expectations because event handlers are vtable-dispatched. Score impact: owner/emitter remains source-authored class method.

### Event subtype names

Checked target decompilation and accepted SelectObject C++. Subtype `1` and subtype `2` match the same mouse-handler structure in SelectObject, with `event+8`/`event+0xc` coordinates and `event+4` kind byte. Rejected generic `mouse down`/`mouse up` final names because no UI event enum definition was inspected. Best defensible names are `kMouseTargetChange` and `kMouseTargetConfirm`. Score impact: enough for first-draft C++; exact enum spelling remains a final-source polish issue.

### Saved-target global

Checked [UID:0002AB], constructor [UID:0001LI], keyboard [UID:0001LK], clear helper [UID:00036S], navigation [UID:00036T], dispatch-forward [UID:00036U], and the target mouse body. `dword_69BF2C` is read to resolve old/current target and written from `LivingObjectPane+0xfc`. Rejected a generic shared `currentTargetId` because adjacent dwords hold spell/item/select/target variants. Rejected `s_selectObjectTargetId` because that is already `dword_69BF28`. Best inference: `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`. Score impact: resolves a main source-quality blocker.

### TargetObject mode flag

Checked [UID:0002A9], constructor clear, keyboard cancel, forward helper set, and UserPane clears. The mouse handler does not touch `byte_69BEDA`, but the assignment requires naming it. Rejected a mouse-specific flag and a generic UI mode byte; the xrefs are specifically target-object/target-dispatch map-selection state. Best inference: `s_targetObjectTargetModeActive`, semantic alias `s_targetObjectMapSelectionActive`. Score impact: support-doc sync, no direct target C++ dependency.

### Config byte

Checked [UID:00028Q] and SelectObject accepted report. `g_pConfig+0x28de5a` has a registry-backed `DoubleClick` literal and both mouse handlers use it as the single-click versus double-click confirmation policy. Rejected `allowSingleClick` as an original field name because the backing literal is `DoubleClick` and the branch sense is inverse in the source logic. Score impact: final C++ should use `g_pConfig->doubleClick`.

### UserPane fields

Checked accepted SelectObject report, target decompilation, [UID:0001OR], `UserPane` class/file, `ChattingVarietyPane`, and member-layout cache. `+0x210` is cleared by spell/item/select/target confirmation paths before dispatch/interact; best source-facing expression remains `UserPane::ClearPendingTargetObject()` / pending target object state. `+0x3eb4` is already documented as `currentChatMode` / `currentChatVarietyMode`; in this cleanup path the pane clears chat target/mode state before refreshing the chat variety pane. Rejected leaving both as raw offsets because support docs now resolve one and the other has repeated target-selection cleanup semantics. Score impact: removes target-page "unresolved source-level reason" blocker enough for draft C++; exact member names still cap confidence below final.

### Chat singleton cleanup

Checked [UID:0002B5], `g_pChattingHandlePane`, `g_pChattingVarietyPane`, `ChattingVarietyPane`, and target decompilation. `dword_67ADE0+0x111` gates clearing `g_pUserPane+0x3eb4`; `dword_67ADD8` virtual slot `+0x48` refreshes UI. Rejected target-selection ownership of chat globals because constructors/destructors and singleton docs assign them to `Chatting`. Best inference: post-confirm chat UI refresh dependency, same as SelectObject. Score impact: support-doc change; no source-route change.

### MapPane helper names

Checked [UID:00037Q], [UID:0001AU], [UID:00037X], and `0x0050b1b0` IDA export. `0x0050b1b0` sends opcode `0x43` with target id, and its only current target-selection callers are SelectObject/TargetObject confirm paths. Rejected naming it a highlight/focus helper; highlight is `0x0053b1b0`. Best inference: `MapPane::InteractWithObject` / `RequestObjectInteraction`. Score impact: source C++ can use accepted names.

### Owner and source placement

Checked vtable slot, target class page, file page, aggregate, sibling helpers, and rejected dependency owners. `TargetObjectWithKeyboardPane` is the only direct owner that explains the vtable route, saved-target global, local clear helper, prompt/constructor, and dismissal behavior. `TargetSelectionInputPanes.cpp` is the file-level emitter route. Rejected `MapPane`, `UserPane`, `Chatting`, `LineInputPane`, `BlackHole`, and generic UI-core as owners. Score impact: no metadata owner change.

### First-draft C++ readiness

Checked active gate in supervisor guidance, target score/owner/emitter, accepted SelectObject first-draft C++ precedent, and resolved names above. Rejected the old `95/95` no-code gate. Rejected no-code proof because the remaining unknowns are exact original spellings, not control-flow or source-route blockers. Best inference: populate first-draft method C++ now; keep class-level declarations for a broader target-selection header pass.

## Exact Target Metadata And Text Recommendations

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ED | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ED | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended target title/covered-range owner text:

```text
# 0x005b0290-0x005b050d - TargetObjectWithKeyboardPane OnMouseEvent
```

```text
| `0x005b0290-0x005b050d` | `TargetObjectWithKeyboardPane::OnMouseEvent` | Converts mouse coordinates to map space, updates selected living-object highlights, confirms target-object interaction, dismisses the selector, and refreshes target-dispatch/chat cleanup state. |
```

Replace the stale Ownership Decision final sentence with:

```text
Populate first-draft C++ for `bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)`. The old `95/95` blank-code threshold is superseded by the active gate, and the remaining uncertainty is limited to final original spellings for shared event/config/UserPane/chat helper names rather than behavior, ownership, or emitter route.
```

Add source-facing names after the existing global/callee evidence:

```text
Source-facing names from B005 reanalysis: `dword_69BF2C` is `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`; subtype `1` is `kMouseTargetChange`; subtype `2` is `kMouseTargetConfirm`; `dword_67A7C8+0x28de5a` is `Config::DoubleClick`; `dword_67A74C` is the BlackHole/application cleanup queue; `dword_67ADE0` is `g_pChattingHandlePane`; `dword_67ADD8` is `g_pChattingVarietyPane`; `dword_67A748+0x210` is the UserPane pending-target cleanup state; and `dword_67A748+0x3eb4` is the current chat variety/mode state cleared before refreshing the chat variety pane.
```

## Support-Doc Recommendations

Apply these as support-doc sync, with no direct B005 edits:

1. [UID:0000ED] `TargetObjectWithKeyboardPane`

Replace method labels:

```text
| `bool TargetObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)` | [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md) | Source-authored secondary-vtable key handler; handles cancel, previous/next target keys, self target, and `v`/Tab dispatch behavior. |
| `bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)` | [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) | Source-authored secondary-vtable mouse handler with first-draft C++; converts mouse coordinates to map space, highlights selected living objects, confirms object interaction, and dismisses the selector. |
```

Add evidence note:

```text
B005 2026-06-18 target-object mouse reanalysis resolves `dword_69BF2C` as `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`, `byte_69BEDA` as `s_targetObjectTargetModeActive`, and [UID:0001LL] as `bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)` with first-draft C++ under the active supervisor gate. MapPane/UserPane/Chatting/BlackHole references in that body are dependency routes, not owner routes.
```

Recommended class score if this support text is incorporated: `COMPLETION:87`, `CONFIDENCE:88`. If the supervisor wants to defer class score until [UID:0001LK] also receives first-draft C++, leave class score unchanged but still apply method-name/source-name text.

2. [UID:0000OH] `TargetSelectionInputPanes`

Replace the B005 source-facing state bullet with:

```text
- B005 2026-06-18 source-facing state names: `dword_69BF28` is `s_selectObjectTargetId` / `s_selectObjectSavedTargetId`; `byte_69BED9` is `s_selectObjectTargetModeActive`; `dword_69BF2C` is `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`; and `byte_69BEDA` is `s_targetObjectTargetModeActive` / `s_targetObjectMapSelectionActive`.
```

Add boundary note after the SelectObject switch-support note:

```text
- B005 2026-06-18 local IDA memory-dump reanalysis isolates `0x005b01da-0x005b0290` as `TargetObjectWithKeyboardPane` key-handler compiler switch support and alignment: `0x005b01da-0x005b01dc` is `66 90`, `0x005b01dc-0x005b0281` is switch metadata, and `0x005b0281-0x005b0290` is fifteen `0xcc` bytes before [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md).
```

3. [UID:0002AB] `TargetSelectionSavedTargetGlobals`

Update the `0x0069bf2c` row/note:

```text
| `0x0069bf2c` | `dword_69BF2C` | `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`; current saved object id for `TargetObjectWithKeyboardPane` target-dispatch selection. |
```

Optionally update `0x0069bf30`:

```text
| `0x0069bf30` | `dword_69BF30` | `s_targetObjectPreviousTargetId` / `s_targetDispatchPreviousTargetId`; prior/alternate target id copied by target-dispatch navigation and forward helpers. |
```

4. [UID:0002A9] `TargetSelectionModeFlags`

Update the `byte_69BEDA` role:

```text
| `byte_69BEDA` | `s_targetObjectTargetModeActive` / `s_targetObjectMapSelectionActive`; target-object target-dispatch map-selection mode flag set by the dispatch-forward path and cleared by constructor/cancel/UserPane cleanup. |
```

5. [UID:0002B5] `UiChatClanSingletonSlots`, `g_pChattingHandlePane`, and `g_pChattingVarietyPane`

Append a support note:

```text
B005 2026-06-18 TargetObject mouse-handler reanalysis confirms the same target-selection cleanup consumer pattern as SelectObject: [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) checks `g_pChattingHandlePane+0x111`, clears `g_pUserPane+0x3eb4` current chat mode/target state, and calls virtual slot `+0x48` on `g_pChattingVarietyPane` after confirmed object interaction. This remains a Chatting UI refresh dependency, not target-selection ownership of the chat singletons.
```

6. [UID:00037X] `MapPaneInteractionMapChangeCore`

Update the B005 source-name note:

```text
B005 SelectObject/TargetObject input-handler reanalysis confirms `0x0050b1b0` is a MapPane interaction/request helper consumed by target-selection panes after a target is confirmed. It sends opcode `0x43` with the target object's `+0xfc` id and is best named `MapPane::InteractWithObject(LivingObjectPane *target)` / `RequestObjectInteraction`.
```

7. [UID:0000VN] `by-memory/-ignored.md`

Insert immediately after the existing `0x005af955-0x005afa10` SelectObject switch-support entry:

```text
- `0x005b01da-0x005b0290` - `TargetObjectWithKeyboardPane` key-handler switch support table and alignment.
  - Why ignored: compiler-generated switch/jump-table support bytes for [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md), followed by alignment before [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md).
  - Evidence: B005 local IDA memory-dump recheck found `sub_5B0010` ending at `0x005b01da`; bytes `0x005b01da-0x005b01dc` are `66 90`, bytes `0x005b01dc-0x005b0281` are compiler switch metadata with dword/code-offset and byte-index table content, and bytes `0x005b0281-0x005b0290` are fifteen `0xcc` alignment bytes before `sub_5B0290`.
  - Replacement/procurement: compiler-generated table from the key-handler switch plus compiler/linker alignment.
  - Owner/source: compiler-generated support for [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md) in [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md); no hand-authored C++ declaration is needed for the table.
```

## Coverage Row Recommendations

Do not edit `by-memory/-coverage-report.md` directly. Placement context: insert the ignored row between the existing [UID:0001LK] row and the [UID:0001LL] row, then replace the [UID:0001LL] row.

New row to insert:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b01da-0x005b0290 | switch-support/padding | TargetObjectWithKeyboardPane key-handler switch support and alignment : ignored : 100% : strong : B005 local IDA memory-dump recheck confirmed `sub_5B0010` ends at `0x005b01da`; `0x005b01da-0x005b01dc` is `66 90`, `0x005b01dc-0x005b0281` is compiler-generated key-switch support data, and `0x005b0281-0x005b0290` is fifteen `0xcc` alignment bytes before `sub_5B0290`.
```

Replacement row for [UID:0001LL]:

```text
        - [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) 0x005b0290-0x005b050d | method | TargetObjectWithKeyboardPaneMouseEvent : reconstructable : 88% : strong : B005 source-quality reanalysis confirms exact `sub_5B0290` size `0x27d`, vtable-only data xref at `0x0062f408`, no direct code callers, three-byte `0xcc` successor padding, and preceding key-switch support split; resolves the source-facing method as `bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)`, subtype `1` as target-change/hit-test and subtype `2` as confirm, `dword_69BF2C` as `s_targetObjectTargetId`, `Config::DoubleClick` gating, MapPane lookup/hit-test/interaction dependencies, `ClearCurrentTarget`, UserPane pending-target/chat-mode cleanup, Chatting handle/variety refresh dependency, rejected non-owner routes, and first-draft C++ readiness under the active gate.
```

If class coverage is updated, use this replacement for [UID:0000ED] in `by-class/-coverage-report.md`:

```text
- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md) : reconstructable : 87% : strong : Target-dispatch selector class under `TargetSelectionInputPanes`; B005 resolves the mouse handler as `bool TargetObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)` with first-draft C++, names `s_targetObjectTargetId` and `s_targetObjectTargetModeActive`, keeps MapPane/UserPane/Chatting/BlackHole as dependencies rather than owners, and retains class-level C++/header work for a broader target-selection declaration pass.
```

## Score And Metadata Summary

| Page | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| [UID:0001LL] target | `84/88` | `88/90` | Source names, event layout, owner route, support cleanup, and first-draft C++ are now sufficient. |
| [UID:0000ED] class | `86/85` | `87/88` optional | Apply if supervisor incorporates method/source-name support; otherwise defer until [UID:0001LK] keyboard C++ pass. |
| [UID:0000OH] file | `89/85` | no score change | Support-name sync only; source path already clears gate. |
| [UID:0002AB] saved globals | `86/88` | no score change | Source-facing names update only. |
| [UID:0002A9] mode flags | `86/88` | no score change | Source-facing TargetObject flag name update only. |
| [UID:0002B5] chat slots | `86/92` | no score change | Add TargetObject consumer note; ownership unchanged. |
| [UID:00037X] MapPane interaction | `85/89` | no score change | Add TargetObject evidence to existing helper-name note. |

## Changed Files

Report file only:

- `tools/leaser/Agents/Agent-B005/research/0001LL-TargetObjectWithKeyboardPaneMouseEvent-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001LL-TargetObjectWithKeyboardPaneMouseEvent-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0001LL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
