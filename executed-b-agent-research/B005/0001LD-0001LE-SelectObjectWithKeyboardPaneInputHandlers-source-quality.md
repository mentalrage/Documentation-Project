** TARGET-REPORT-UID:0001LD **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001LD] / [UID:0001LE] SelectObjectWithKeyboardPane Input Handlers Source-Quality Report

Agent: B005  
Date: 2026-06-18  
Assignment: paired B-preferred source-quality / heuristic-inference pass  
Targets:
- [UID:0001LD] `by-memory/0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent.md`
- [UID:0001LE] `by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md`

## Executive Recommendation

Both targets should remain reconstructable, source-authored virtual methods owned by [UID:0000CT] `SelectObjectWithKeyboardPane` and emitted through [UID:0000OH] `TargetSelectionInputPanes`. The stale "formal C++ blank because below 95/95" blocker should be removed. Under the current code-entry gate, both handlers have enough owner, source-route, event-layout, helper-name, and behavior evidence to populate first-draft C++.

Recommended target metadata:
- [UID:0001LD] `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:[UID:0000CT]`, `SOURCE_EMITTER:[UID:0000CT]`.
- [UID:0001LE] `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:[UID:0000CT]`, `SOURCE_EMITTER:[UID:0000CT]`.

The only coverage/range change I recommend is not to expand either target body. Instead, add an ignored/support coverage entry for the compiler-generated switch data and alignment between the two modeled functions: `0x005af955-0x005afa10`. Local IDA export evidence shows `sub_5AF710` ends at `0x005af955`; `0x005af955-0x005afa01` is keyboard switch support data referenced from inside the function, and `0x005afa01-0x005afa10` is alignment padding before `sub_5AFA10`.

## Evidence Base And Tool Status

I re-read the required B005 guidance and supervisor policy documents, then validated the target claims against:
- The two target pages, [UID:0000CT] `SelectObjectWithKeyboardPane`, [UID:0000OH] `TargetSelectionInputPanes`, [UID:0001LB], [UID:0001LF], [UID:0001LG], [UID:0001LH], [UID:0002AB], [UID:0002A9], `g_activeMapPane`, `g_pApplicationCleanupQueue`, `g_pConfig`, `UiChatClanSingletonSlots`, and current coverage/ignored rows.
- Existing sibling target-selection docs for `SpellWho` and `ItemWho` mouse/key handlers, especially their use of mouse subtype `1`/`2`, `DoubleClick`, pane/map coordinate translation, and target highlight behavior.
- Local IDA export files under `C:\Users\admin\Desktop\CTools\Output\ida`, including `memory.bin`, `functions.json`, `xrefs.json`, and decompile JSON for all helper addresses in scope.

Live IDA MCP was unavailable during this pass. A direct JSON-RPC connection to `http://127.0.0.1:13337/mcp` failed with connection refused. I therefore treated current docs as leads and pushed local IDA export evidence for bytes, functions, xrefs, decompiles, and neighboring callback/virtual contexts.

No wave2/wave3 source data was used.

## Exact Range, Boundary, And Reachability

### [UID:0001LD] `0x005af710-0x005af955`

Modeled function evidence:
- IDA function: `sub_5AF710`.
- Half-open body range: `0x005af710-0x005af955`.
- ABI view: `char __thiscall sub_5AF710(_DWORD *this, _BYTE *event)`.
- Source-facing view: `bool SelectObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)` on the secondary/base handler subobject. The decompiler `this` is adjusted by `+0xa0` bytes from the owning `SelectObjectWithKeyboardPane`; owner-body uses `this - 0xa0` / `this - 40` dwords when dismissing the pane.

Boundary evidence:
- Previous modeled function: `0x005af6e0-0x005af709`.
- Padding before target: `0x005af709-0x005af710`, seven `0xcc` bytes.
- Function entry bytes at `0x005af710`: `55 8b ec ...`.
- Function epilogue bytes at `0x005af94d-0x005af954`: `5f 5e b0 01 5b 5d c2 04 00`; the half-open end is `0x005af955`.

Post-body support data:
- `0x005af955-0x005afa01` is not ordinary padding. It begins `0f 1f 00` and contains dword targets such as `0x005af846`, `0x005af75f`, `0x005af7bc`, `0x005af8cd`, `0x005af8fa`, `0x005af812`, `0x005af87a`, and `0x005af94c`, followed by byte index data.
- `xrefs.json` records a data reference from `0x005af758` inside `sub_5AF710` to `0x005af958`, matching the switch/jump-table implementation for the key dispatch.
- `0x005afa01-0x005afa10` is fifteen `0xcc` bytes before the mouse handler.

Reachability:
- No direct code callers were found in function/caller metadata.
- The only meaningful entry xref is the vtable data reference from `0x0062f380`.
- Secondary vtable `0x0062f378` contains `0x005afa10` at slot `+0x04`, `0x005af710` at slot `+0x08`, inherited/base key handler `0x004f2580` at slot `+0x0c`, and object-list handler `0x005afc90` at slot `+0x10`.
- Constructor/destructor/scalar-deleting-destructor evidence writes or restores this secondary vtable at `0x005af659`, `0x005af6e6`, and `0x005b7bcc`.

### [UID:0001LE] `0x005afa10-0x005afc8d`

Modeled function evidence:
- IDA function: `sub_5AFA10`.
- Half-open body range: `0x005afa10-0x005afc8d`.
- ABI view: `char __thiscall sub_5AFA10(_DWORD *this, int event)`.
- Source-facing view: `bool SelectObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)` on the same secondary/base handler subobject.

Boundary evidence:
- Entry bytes at `0x005afa10`: `55 8b ec ...`.
- Epilogue ends with security-cookie validation and `c2 04 00`; body ends at `0x005afc8d`.
- Post-body padding: `0x005afc8d-0x005afc90`, three `0xcc` bytes.
- Next modeled function: [UID:0001LF] at `0x005afc90-0x005afd23`.

Reachability:
- No direct code callers were found.
- The only meaningful entry xref is the vtable data reference from `0x0062f37c`.
- This is expected for a virtual mouse-handler slot. The no-direct-caller status supports virtual dispatch, not non-reconstructability.

## Handler Behavior And Source-Facing Semantics

### Keyboard handler

Recommended source-facing method name: `SelectObjectWithKeyboardPane::OnKeyEvent`. `HandleKeyEvent` is plausible, but `OnKeyEvent` matches current target naming, sibling virtual-handler wording, and the inherited `LineInputPane::OnKeyEvent` forwarding target.

Recommended signature:

```cpp
bool SelectObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event);
```

Return semantics:
- The ABI returns `char`; source should use `bool`.
- `true` means the key was consumed or deliberately ignored by the selector.
- The Escape/space cancel path returns `false` after forwarding a temporary Escape key to the base `LineInputPane`.
- Enter forwards the original event to `LineInputPane::OnKeyEvent` after optional target interaction and still returns `true`.

Event fields:
- `event + 0x04`: event kind/subtype. Value `8` is the target-selection key mode required for side effects.
- `event + 0x08`: key byte. The decompiler's `std::ctype<char>::do_narrow(event[8], event[266])` lowering should not be carried into source; the source-facing field is the normalized key byte.
- `event + 0x10a`: modifier/state flags. Low two bits gate selector-specific processing; when either bit is set the handler returns `true` without target movement. I do not have enough evidence to name the individual bits as Shift/Ctrl/Alt, so `modifierFlags` or `stateFlags` is the safest source declaration.

Key behavior:
- Enter (`13`): if event kind is `8`, resolve saved target id through `g_activeMapPane`, clear the current target highlight, interact with the target through MapPane, clear the select-object mode flag, queue this pane for deferred deletion, then call the base key handler and return `true`.
- Escape (`27`) and space (`32`): if event kind is `8`, clear the current highlight if present, clear the mode flag, dismiss the pane; rewrite `event->key` to Escape only while forwarding to `LineInputPane::OnKeyEvent`, restore the original key, and return `false`.
- `v` (`118`): if `TabVSwap` is enabled or the runtime target-selection suppression byte is set, consume without forwarding; otherwise dispatch to the forward-tab helper.
- Tab (`9`): if `TabVSwap` is disabled or the runtime target-selection suppression byte is set, consume without forwarding; otherwise dispatch to the forward-tab helper.
- Self-target key (`0x91` / signed `-111` in the decompiler): if event kind is `8`, switch saved target to the local player object, clearing the previous highlight if necessary and storing the local player's object id.
- Previous-target keys: `h`, `k`, `0x80`, `0x81`. Resolve the current target if present; otherwise start from the local-player object. Use the MapPane previous-selectable helper. Update highlight and saved id if the resolved target changes.
- Next-target keys: `j`, `l`, `0x82`, `0x83`. Same model, using the MapPane next-selectable helper.

### Mouse handler

Recommended source-facing method name: `SelectObjectWithKeyboardPane::OnMouseEvent`.

Recommended signature:

```cpp
bool SelectObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event);
```

Return semantics:
- The ABI returns `char`; source should use `bool`.
- `true` means the mouse event was consumed, target selection was updated, or the event was intentionally absorbed because it was inside the map while waiting for a confirming click.
- `false` means no target-selection handling occurred or the event was outside the active map/without a resolvable target.

Event fields:
- `event + 0x04`: mouse subtype.
  - Subtype `1` is the target-change/select/hover path. Sibling `SpellWho` and `ItemWho` handlers use the same subtype for target update with `DoubleClick` gating.
  - Subtype `2` is the confirm/click path. It validates the saved target and active-map bounds before interacting.
- `event + 0x08`: mouse x coordinate in pane-local coordinates.
- `event + 0x0c`: mouse y coordinate in pane-local coordinates.

Coordinate behavior:
- The handler obtains the selector pane origin through its pane virtual at slot `+0x28`.
- It obtains the active map origin through the active MapPane pane virtual at slot `+0x28`.
- It converts event x/y from selector-pane space to active-map-local space by adding the selector origin and subtracting the MapPane origin.
- It calls the MapPane bounds helper (`sub_4B8E00`) and point-in-rect helper (`sub_4B7E80`) for confirm/outside-map decisions.
- It calls the MapPane object hit-test helper (`sub_506CE0`) for subtype `1`.

Mouse behavior:
- Subtype `2`: if the translated point is inside the active map and the saved target id resolves, clear the highlight, clear the local-player/UserPane pending-target field at `+0x210`, interact with the target, dismiss the pane, run the shared chat cleanup branch, and return `true`. If the saved target is missing or the point is outside the active map, return `false`.
- Subtype `1`: hit-test the translated point.
  - If a new object is hit and differs from the old saved target, clear old highlight, highlight the new object, save its object id, and return `true` when `DoubleClick` is enabled. If `DoubleClick` is disabled and there was an old target, immediately confirm/interact with the new target; if there was no old target, return `false` after the selection update.
  - If the hit object is the same as the old target, `DoubleClick` enabled consumes and waits. With `DoubleClick` disabled, a resolvable old target is immediately confirmed; no old target returns `false`.
  - If no object is hit and the point is outside the map, return `false`.
  - If no object is hit but the point is inside the map, consume when `DoubleClick` is enabled or no old target exists. With `DoubleClick` disabled and an old target exists, clear and confirm the old target.
- Other mouse subtypes return `false`.

## Helper, Global, And Field Naming

Recommended names below are source-facing reconstruction names. Exact original spellings are not provable, but the roles are no longer unresolved blockers.

| Address / item | Best source-facing name | Evidence and rejected alternatives |
|---|---|---|
| `sub_506970` | `MapPane::FindObjectPaneById(int objectId)` or `LookupObjectPaneById` | Body returns `sub_532370(this[265], objectId)`, using the MapPane object-list member at byte `+0x424`. It is not a selector helper; selector code only consumes it. |
| `sub_506AE0` | `MapPane::FindPreviousSelectableObject(LivingObjectPane *current)` | Traverses the same object list with iterator helpers and is used by previous keys in SelectObject/targeting context. Not a generic list helper because it is a MapPane method over MapPane's object list. |
| `sub_506B30` | `MapPane::FindNextSelectableObject(LivingObjectPane *current)` | Sibling traversal to `sub_506AE0`, used by next keys. |
| `sub_506CE0` | `MapPane::HitTestObjectAtPoint(int x, int y)` or `FindObjectAtMapPoint` | Checks MapPane bounds then calls `sub_50C470(this, x, y)`. Existing BackPane/GeneratedBackPane wording is stale for this target; MapPane ownership is stronger. |
| `sub_50B1B0` | `MapPane::InteractWithObject(LivingObjectPane *target)` or `RequestObjectInteraction` | Builds/sends object interaction packet opcode `0x43` through packet sender and optional timing state. It is neither a selector method nor a pure UI highlight operation. |
| `sub_53B1B0` | `LivingObjectPane::SetTargetHighlight(bool enabled)` | Writes highlight byte around offset `+0x1e8`, starts/stops visual state, and repaints. Existing target-selection docs use it as the target highlight operation. |
| `sub_469180` | `BlackHole::QueuePaneForDeferredDeletion(Pane *pane)` | It calls pane cleanup virtuals, removes timers, de-duplicates queue entries, and inserts into the deferred cleanup queue global. The old application-cleanup-queue global name is adequate; source should not call this a direct delete. |
| `sub_4F25A0` | `LineInputPane::OnKeyEvent(KeyEvent *event)` | Base input-pane key handler reached on Enter/Escape/forward paths. The selector temporarily rewrites the key byte before forwarding cancel/Tab paths. |
| `sub_4B8E00` | `Pane::GetBoundsRect(Rect *out)` / `GetRect` | Copies the pane rectangle from the object at byte `+0x44`. It is a pane geometry helper, not target-selection-specific. |
| `sub_4B7E80` | `PointInRect(int x, int y, const Rect &rect)` | Comparison order validates a point-in-rect helper used by multiple panes. Exact rect field names remain dependent on the wider pane geometry type, but that does not block these handlers. |
| `dword_69BF28` | `s_selectObjectTargetId` or `s_selectObjectSavedTargetId` | Saved object id for SelectObjectWithKeyboardPane. Constructor/object-list/key/mouse/clear helper all read/write it. It is not a pointer. |
| `byte_69BED9` | `s_selectObjectTargetModeActive` | Set by the forward-tab helper, cleared by constructor/key cancel/enter/UserPane paths. It is the SelectObject map-target mode flag, not the TargetObject flag (`byte_69BEDA`). |
| `dword_67A764` | `g_activeMapPane` | Existing MapPane singleton docs are correct. These handlers are consumers only. |
| `dword_67A748` | `g_pUserPane` / local-player state owner | Used here for local-player object pointer at `+0x210` and player object id at `+0xfc`; also chat state at `+0x3eb4`. Existing `g_pCollectionData` naming is too broad for source-facing selector code. |
| `dword_67A74C` | `g_pApplicationCleanupQueue` / `g_pBlackHole` | Existing doc source role is deferred pane cleanup queue. Source should express queueing, not immediate destruction. |
| `g_pConfig + 0x28de5a` | `m_doubleClick` / `DoubleClick` | Registry loader maps the literal `DoubleClick` to byte offset `2678362`. Mouse handler uses it exactly as single-click versus double-click confirmation policy. |
| `g_pConfig + 0x28de62` | `m_targetSelectionSuppressed` / runtime target-selection disable byte | Set from packet/runtime paths, checked by UserPane map-selection code and this keyboard handler. No registry literal was found, so a descriptive runtime-state name is safer than pretending an original config-string name is known. |
| `g_pConfig + 0x28de63` | `m_tabVSwap` / `TabVSwap` | Registry literal `TabVSwap` loads to byte offset `2678371`. It swaps whether `v` or Tab enters target mode. |
| `dword_67ADE0` | `g_pChattingHandlePane` | Mouse shared cleanup checks byte `+0x111` on this pane before clearing chat/user state. Existing `UiChatClanSingletonSlots` doc supports this role. |
| `dword_67ADD8` | `g_pChattingVarietyPane` | Mouse shared cleanup calls virtual slot `+0x48` on this pane after chat state clearing. |

## Owner And Source Placement Ranking

1. Accepted: [UID:0000CT] `SelectObjectWithKeyboardPane` in [UID:0000OH] `TargetSelectionInputPanes`. The two functions are secondary-vtable virtual slots for the class, reached only by the class vtable, with constructor/destructor/scalar-deleting destructor vptr evidence and tight coupling to sibling [UID:0001LB]/[UID:0001LF]/[UID:0001LG]/[UID:0001LH]. The saved-target id and mode flag belong to the same target-selection file group.

2. Accepted as file/emitter context, not direct function owner: [UID:0000OH] `TargetSelectionInputPanes`. This is the right translation-unit/source-file placement for the class and related SpellWho/ItemWho/TargetObject selector code. Method pages should still name [UID:0000CT] as canonical owner/emitter.

3. Rejected as owner: `MapPane`. MapPane supplies lookup, traversal, hit-test, bounds, and interaction helpers. The methods themselves are selector-pane virtual handlers and dismiss selector panes through the cleanup queue. MapPane should receive helper-name/support-doc updates, not ownership of the handlers.

4. Rejected as owner: `UserPane` / local-player state. UserPane supplies the local player object and is affected by cleanup fields at `+0x210` and `+0x3eb4`, but no vtable or caller evidence routes the handler bodies to UserPane ownership.

5. Rejected as owner: `LineInputPane`. The keyboard handler forwards selected keys to `LineInputPane::OnKeyEvent`; it is not an inherited base body because `0x005af710` is installed in `SelectObjectWithKeyboardPane`'s secondary vtable and has selector-specific target logic.

6. Rejected as owner: `Config`, `Chatting`, `BlackHole`, `ScreenPane`, `Surface`, `ParcelPane`, generic UI-core, and no-owner fallback. These are dependencies, stale pollution, or infrastructure consumers. None explains the vtable slots, saved-target globals, constructor/destructor vptr writes, or sibling target-selection helper family.

## First-Draft C++ Recommendation

The formal `RECONSTRUCTION_CPP CODE` blocks for [UID:0001LD] and [UID:0001LE] should be populated. Remaining names are descriptive reconstruction names, but they are source-quality inferences with concrete evidence, not blockers. The draft below intentionally avoids carrying compiler artifacts such as `std::ctype<char>::do_narrow`, raw adjusted `this` arithmetic, and generated switch table names into source.

Recommended declarations shared by the two handlers:

```cpp
enum TargetSelectionKey {
    kKeyTab = 9,
    kKeyEnter = 13,
    kKeyEscape = 27,
    kKeySpace = 32,
    kKeySelfTarget = 0x91,
    kKeyPrevA = 0x80,
    kKeyPrevB = 0x81,
    kKeyNextA = 0x82,
    kKeyNextB = 0x83
};

enum {
    kTargetSelectionKeyEvent = 8,
    kMouseTargetChange = 1,
    kMouseTargetConfirm = 2
};

struct KeyEvent {
    int message;              // event + 0x00, shared event header
    int kind;                 // event + 0x04
    unsigned char key;        // event + 0x08
    unsigned char reserved09[0x101];
    unsigned char modifierFlags; // event + 0x10a
};

struct MouseEvent {
    int message; // event + 0x00, shared event header
    int kind;    // event + 0x04
    int x;       // event + 0x08
    int y;       // event + 0x0c
};
```

The real event base type is probably shared across pane input handlers; the above layout names should be adapted to the support doc's common event declaration rather than duplicated as final class-local structs.

Recommended [UID:0001LD] first draft:

```cpp
bool SelectObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = event->key;

    if ((event->modifierFlags & 0x03) != 0)
        return true;

    switch (key) {
    case kKeyEnter:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *target =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            if (target != NULL) {
                ClearCurrentTarget();
                g_activeMapPane->InteractWithObject(target);
            }
            s_selectObjectTargetModeActive = false;
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        }
        LineInputPane::OnKeyEvent(event);
        return true;

    case kKeyEscape:
    case kKeySpace:
        if (event->kind == kTargetSelectionKeyEvent) {
            if (g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId) != NULL)
                ClearCurrentTarget();
            s_selectObjectTargetModeActive = false;
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        }
        event->key = kKeyEscape;
        LineInputPane::OnKeyEvent(event);
        event->key = key;
        return false;

    case 'v':
        if (g_pConfig->tabVSwap || g_pConfig->targetSelectionSuppressed)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeyTab:
        if (!g_pConfig->tabVSwap || g_pConfig->targetSelectionSuppressed)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeySelfTarget:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
            if (oldTarget != selfTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                selfTarget->SetTargetHighlight(true);
                s_selectObjectTargetId = selfTarget->GetObjectId();
            }
        }
        return true;

    case 'h':
    case 'k':
    case kKeyPrevA:
    case kKeyPrevB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *start = oldTarget;
            if (start == NULL)
                start = g_pUserPane->GetLocalPlayerObject();

            LivingObjectPane *newTarget =
                g_activeMapPane->FindPreviousSelectableObject(start);
            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_selectObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_selectObjectTargetId = 0;
                }
            }
        }
        return true;

    case 'j':
    case 'l':
    case kKeyNextA:
    case kKeyNextB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *start = oldTarget;
            if (start == NULL)
                start = g_pUserPane->GetLocalPlayerObject();

            LivingObjectPane *newTarget =
                g_activeMapPane->FindNextSelectableObject(start);
            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_selectObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_selectObjectTargetId = 0;
                }
            }
        }
        return true;
    }

    return true;
}
```

Recommended [UID:0001LE] first draft:

```cpp
bool SelectObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)
{
    Point paneOrigin;
    Point mapOrigin;
    Rect mapRect;

    GetOrigin(&paneOrigin);
    g_activeMapPane->GetOrigin(&mapOrigin);

    const int mapX = event->x + paneOrigin.x - mapOrigin.x;
    const int mapY = event->y + paneOrigin.y - mapOrigin.y;

    if (event->kind == kMouseTargetConfirm) {
        g_activeMapPane->GetBoundsRect(&mapRect);
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);

        if (!PointInRect(mapX, mapY, mapRect) || target == NULL)
            return false;

        ClearCurrentTarget();
        g_pUserPane->ClearPendingTargetObject();
        g_activeMapPane->InteractWithObject(target);
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        g_pUserPane->ClearPendingTargetObject();

        if (g_pChattingHandlePane != NULL && g_pChattingHandlePane->IsCommandPending()) {
            g_pUserPane->ClearChatTargetState();
            if (g_pChattingVarietyPane != NULL)
                g_pChattingVarietyPane->RefreshAfterTargetSelection();
        }
        return true;
    }

    if (event->kind != kMouseTargetChange)
        return false;

    LivingObjectPane *oldTarget =
        g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
    LivingObjectPane *hitTarget = g_activeMapPane->HitTestObjectAtPoint(mapX, mapY);

    if (hitTarget != NULL) {
        if (hitTarget != oldTarget) {
            if (oldTarget != NULL)
                oldTarget->SetTargetHighlight(false);
            hitTarget->SetTargetHighlight(true);
            s_selectObjectTargetId = hitTarget->GetObjectId();

            if (g_pConfig->doubleClick)
                return true;
            if (oldTarget == NULL)
                return false;

            ClearCurrentTarget();
            g_pUserPane->ClearPendingTargetObject();
            g_activeMapPane->InteractWithObject(hitTarget);
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
            g_pUserPane->ClearPendingTargetObject();
            return true;
        }

        if (g_pConfig->doubleClick)
            return true;
        if (oldTarget == NULL)
            return false;

        ClearCurrentTarget();
        g_pUserPane->ClearPendingTargetObject();
        g_activeMapPane->InteractWithObject(oldTarget);
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        g_pUserPane->ClearPendingTargetObject();
        return true;
    }

    g_activeMapPane->GetBoundsRect(&mapRect);
    if (!PointInRect(mapX, mapY, mapRect))
        return false;

    if (g_pConfig->doubleClick || oldTarget == NULL)
        return true;

    ClearCurrentTarget();
    g_pUserPane->ClearPendingTargetObject();
    g_activeMapPane->InteractWithObject(oldTarget);
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    g_pUserPane->ClearPendingTargetObject();
    return true;
}
```

Notes for incorporation:
- The shipped binary repeats the confirm/cleanup sequence inline. A real source cleanup helper is plausible but not required by this evidence pass; the formal draft can stay inline as above.
- `GetOrigin`, `GetBoundsRect`, `PointInRect`, `ClearPendingTargetObject`, `ClearChatTargetState`, and chat refresh names should be harmonized with existing pane/UserPane support docs. Their source roles are clear enough that raw `sub_` names should not remain in the target formal C++.
- The keyboard `KeyEvent` declaration above shows the raw offset problem; a support-level common event declaration should replace the array placeholder when the shared event struct is reconstructed.

## Heuristic / Inference Reanalysis And Validation

This section records each meaningful source-quality issue, the evidence checked, rejected alternatives, and the final effect on score/source readiness.

### 1. Are the functions source-authored virtual handlers or non-emitting raw islands?

Evidence checked:
- Vtable slots at `0x0062f37c` and `0x0062f380`.
- Constructor/destructor/scalar deleting destructor vptr writes at `0x005af659`, `0x005af6e6`, and `0x005b7bcc`.
- No direct callers in local IDA metadata.
- Sibling selector methods [UID:0001LB], [UID:0001LF], [UID:0001LG], [UID:0001LH].

Rejected alternatives:
- Non-emitting raw island: rejected because the bodies are class virtual callbacks with coherent source-level event behavior.
- Generated/base-only handlers: rejected because both contain selector-specific saved-target, MapPane, config, and cleanup logic.

Best inference:
- Both are source-authored virtual methods on `SelectObjectWithKeyboardPane`.

Effect:
- Owner/emitter should stay [UID:0000CT].
- First-draft C++ should be populated.
- Score can move above the 85 gate.

### 2. Does the keyboard range include the data after `0x005af955`?

Evidence checked:
- `functions.json` function end `0x005af955`.
- Raw memory bytes after `0x005af955`.
- Data xref from `0x005af758` to `0x005af958`.
- Existing ignored rows for SpellWho and ItemWho key-handler switch support tables.

Rejected alternatives:
- Treat `0x005af955-0x005afa10` as padding: rejected because bytes include non-`cc` dword/byte switch data.
- Extend [UID:0001LD] target range to include the support table: not recommended because existing coverage convention keeps sibling key switch tables in ignored/support documentation and the function model ends at `0x005af955`.

Best inference:
- Keep [UID:0001LD] half-open function range unchanged and add a separate ignored/support row for `0x005af955-0x005afa10`.

Effect:
- No target split/rename required.
- Coverage should gain an ignored row for the inter-function compiler table and alignment.
- This does not cap C++ readiness.

### 3. What are the keyboard event fields and modifiers?

Evidence checked:
- Decompile reads at `event+0x04`, `event+0x08`, and `event+0x10a`.
- `std::ctype<char>::do_narrow(event[8], event[266])` lowering.
- Base `LineInputPane::OnKeyEvent` and sibling selector key handlers.

Rejected alternatives:
- Source-level `std::ctype` call: rejected as compiler/library lowering around key normalization.
- Exact names for individual modifier bits: not safe. The code only proves low two bits gate selector handling.

Best inference:
- Event has `kind/subtype`, `key`, and `modifierFlags/stateFlags`; low two bits mean "modified or not selector-owned" for this handler.

Effect:
- C++ can use a common `KeyEvent` structure with descriptive fields.
- Exact individual bit names should remain support-doc future work but not a blocker.

### 4. What are mouse subtype `1` and `2`?

Evidence checked:
- [UID:0001LE] decompile.
- `SpellWho` and `ItemWho` mouse handler docs and behavior.
- `DoubleClick` config offset and registry literal.

Rejected alternatives:
- Subtype `1` equals final confirmation: rejected because with `DoubleClick` enabled it only updates highlight and returns.
- Subtype `2` equals hover: rejected because it requires an existing target and immediately interacts/dismisses.

Best inference:
- Subtype `1` is target-change/select/hover.
- Subtype `2` is confirm/click, likely double-click-confirm in the `DoubleClick` policy.

Effect:
- Mouse C++ can be drafted with `kMouseTargetChange` and `kMouseTargetConfirm`.
- Exact original enum spellings remain unknown but do not block source placement.

### 5. Are `dword_69BF28` and `byte_69BED9` class fields or file-scope state?

Evidence checked:
- Constructor [UID:0001LB], object-list callback [UID:0001LF], clear helper [UID:0001LG], forward-tab helper [UID:0001LH], key/mouse handlers, global pages [UID:0002AB]/[UID:0002A9].
- Address class: both are `.data`/global slots, not object-relative fields.

Rejected alternatives:
- Class member fields: rejected by absolute-address access.
- Generic target-object state: rejected because TargetObject sibling uses adjacent but distinct slots (`dword_69BF2C`, `byte_69BEDA`).

Best inference:
- `dword_69BF28` is file-scope saved object id for SelectObjectWithKeyboardPane.
- `byte_69BED9` is file-scope SelectObject map-target mode flag.

Effect:
- Support docs should name them as TargetSelectionInputPanes file-scope state.
- No score cap remains.

### 6. What are the Config bytes?

Evidence checked:
- Registry loader and default initializer for `DoubleClick`, `TabVSwap`, and adjacent config options.
- Packet/runtime writer around `0x005104d0` for `+0x28de62`.
- UserPane target-selection helper `0x005ad500`.
- Keyboard checks in SelectObject and TargetObject key handlers.

Rejected alternatives:
- `+0x28de62` is a registry-backed option with a literal name: rejected because I found packet/runtime writes and no registry literal.
- `+0x28de63` is generic Tab handling: rejected because registry literal `TabVSwap` directly maps to the offset and code swaps `v`/Tab behavior.

Best inference:
- `+0x28de5a` is `DoubleClick`.
- `+0x28de63` is `TabVSwap`.
- `+0x28de62` is a runtime target-selection suppression/disable byte. Exact original name remains unknown.

Effect:
- `+0x28de62` exact spelling uncertainty should cap confidence below final-perfect, but not below C++ readiness.
- Config support docs need an explicit target-selection cluster note.

### 7. Does MapPane own the target-selection helpers?

Evidence checked:
- Decompile for `sub_506970`, `sub_506AE0`, `sub_506B30`, `sub_506CE0`, and `sub_50B1B0`.
- MapPane object-list offset usage and active MapPane singleton docs.
- Target-selection handler call sites.

Rejected alternatives:
- Make these helpers methods on SelectObjectWithKeyboardPane: rejected because the `this` pointer is `g_activeMapPane`.
- Treat them as generic free functions: weaker than MapPane method evidence.

Best inference:
- They are MapPane methods. TargetSelectionInputPanes should refer to them by source-facing MapPane names.

Effect:
- Support-doc updates should go to MapPane/helper pages, but target ownership remains SelectObjectWithKeyboardPane.

### 8. What is `sub_53B1B0`?

Evidence checked:
- Body writes target pane visual/highlight byte and triggers visual start/stop/repaint.
- Used consistently when selection moves or clears.

Rejected alternatives:
- Object activation/interact: rejected because `sub_50B1B0` performs interaction/packet work, while `sub_53B1B0` only changes visual state.

Best inference:
- `LivingObjectPane::SetTargetHighlight(bool)` or equivalent.

Effect:
- Formal C++ can call `SetTargetHighlight`.

### 9. What are the local-player and chat cleanup fields?

Evidence checked:
- Mouse handler writes `dword_67A748 + 0x210` to zero before and after interaction.
- Mouse handler checks `dword_67ADE0 + 0x111`, clears `dword_67A748 + 0x3eb4`, and calls virtual `+0x48` on `dword_67ADD8`.
- Existing `UiChatClanSingletonSlots` doc names the chatting pane globals.

Rejected alternatives:
- Treat these as selector-owned fields: rejected by global owner and offset evidence.
- Assign exact UserPane field names beyond role: not safe without wider UserPane layout proof.

Best inference:
- `+0x210` is UserPane/local-player pending target/current target object state cleared around interaction.
- `+0x3eb4` is chat input/target state cleared when a chat handle pane flag is active.

Effect:
- Mouse formal C++ can use descriptive UserPane cleanup calls.
- Exact field spelling uncertainty modestly caps confidence but does not block source readiness.

### 10. Is the old blank-C++ blocker still valid?

Evidence checked:
- Current target pages cite a stale `95/95` threshold.
- Current supervisor assignment explicitly asks to reanalyze under the active code-entry gate.
- The new evidence resolves owner, event fields, helper roles, globals, and return behavior.

Rejected alternatives:
- Withhold code solely because helper names are inferred: rejected under B-agent rules. Inferred source-facing names are evidence-backed and adequate for first-draft C++.

Best inference:
- Both pages should receive formal first-draft C++.

Effect:
- Raise both targets to `88/90`.
- Remove stale final-C++ blocker language and replace with a note that exact original helper/event spellings remain descriptive but non-blocking.

## Support-Doc Incorporation Plan

Recommended target-page updates for [UID:0001LD]:
- Replace the stale final C++ blocker with: "Formal C++ is now ready for a first draft under the current code-entry gate. Remaining event/helper names are descriptive reconstruction names, not no-code blockers."
- Add range note: "`0x005af955-0x005afa01` is compiler-generated switch support data referenced from `0x005af758`; keep the function range `0x005af710-0x005af955` and account for the support data through `by-memory/-ignored.md`."
- Add source-facing method signature: `bool SelectObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)`.
- Add field/return note: `event+0x04` kind, `event+0x08` key, `event+0x10a` modifier flags, `bool` consumed return, temporary key rewrite on Escape/Tab-forward paths.
- Add helper-name note for `ClearCurrentTarget`, `ForwardTabKey`, MapPane lookup/traversal/interaction, `LivingObjectPane::SetTargetHighlight`, and `LineInputPane::OnKeyEvent`.

Recommended target-page updates for [UID:0001LE]:
- Replace the stale final C++ blocker with: "Formal C++ is now ready for a first draft under the current code-entry gate. Remaining event/helper names are descriptive reconstruction names, not no-code blockers."
- Add source-facing method signature: `bool SelectObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)`.
- Add event note: `event+0x04` subtype (`1` target-change/select, `2` confirm), `event+0x08` x, `event+0x0c` y, boolean consumed return.
- Add coordinate note: selector pane origin plus event point minus active MapPane origin yields map-local coordinates; `sub_4B8E00`/`sub_4B7E80` validate map bounds and `sub_506CE0` hit-tests target object panes.
- Add cleanup note for `g_pUserPane + 0x210`, chat globals `dword_67ADE0`/`dword_67ADD8`, and `g_pApplicationCleanupQueue`.

Recommended [UID:0000CT] `SelectObjectWithKeyboardPane` support update:
- In the child-method/source-shape section, mark [UID:0001LD] and [UID:0001LE] as source-authored virtual handlers with first-draft C++ available.
- Record method names:
  - `bool SelectObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)`
  - `bool SelectObjectWithKeyboardPane::OnMouseEvent(MouseEvent *event)`
  - `void SelectObjectWithKeyboardPane::ClearCurrentTarget()` for [UID:0001LG]
  - `bool SelectObjectWithKeyboardPane::ForwardTabKey(KeyEvent *event)` for [UID:0001LH]
- Record that the `this` value in the decompiles is the secondary/base subobject and the owner object is recovered by subtracting `0xa0`.

Recommended [UID:0000OH] `TargetSelectionInputPanes` support update:
- Add a file-scope state note:
  - `s_selectObjectTargetId` at `dword_69BF28`.
  - `s_selectObjectTargetModeActive` at `byte_69BED9`.
  - The adjacent TargetObject state remains separate.
- Add a source-route note that SelectObject key/mouse/object-list/clear/forward-tab bodies belong in `ui/dialogs/TargetSelectionInputPanes.cpp`, not MapPane/UserPane/LineInputPane.

Recommended MapPane helper support updates:
- Rename or annotate `sub_506970` as `MapPane::FindObjectPaneById`.
- Rename or annotate `sub_506AE0` as `MapPane::FindPreviousSelectableObject`.
- Rename or annotate `sub_506B30` as `MapPane::FindNextSelectableObject`.
- Rename or annotate `sub_506CE0` as `MapPane::HitTestObjectAtPoint` / `FindObjectAtMapPoint`; remove stale BackPane/source-owner ambiguity for selector consumers.
- Rename or annotate `sub_50B1B0` as `MapPane::InteractWithObject` / `RequestObjectInteraction`.

Recommended global/support updates:
- [UID:0002AB] should prefer `s_selectObjectTargetId` or `s_selectObjectSavedTargetId` for `dword_69BF28`.
- [UID:0002A9] should prefer `s_selectObjectTargetModeActive` for `byte_69BED9`.
- `g_pConfig` support should add:
  - `+0x28de5a`: registry-backed `DoubleClick`.
  - `+0x28de62`: runtime/server-controlled target-selection suppression byte; no proven registry literal.
  - `+0x28de63`: registry-backed `TabVSwap`.
- `UiChatClanSingletonSlots` support should cross-reference that [UID:0001LE] clears UserPane chat state and calls the chatting variety pane refresh virtual after target interaction when the chatting handle pane flag at `+0x111` is set.

Recommended ignored/support entry placement:
- In `by-memory/-ignored.md`, near the existing SpellWho/ItemWho key-handler switch-support entries, add the SelectObjectWithKeyboardPane switch-support entry below.

Exact recommended `by-memory/-ignored.md` text:

```md
- `0x005af955-0x005afa10` - `SelectObjectWithKeyboardPane` key-handler switch support table and alignment.
  - Why ignored: compiler-generated switch/jump-table support bytes for [UID:0001LD] `SelectObjectWithKeyboardPaneOnKeyEvent`, followed by alignment before [UID:0001LE] `SelectObjectWithKeyboardPaneOnMouseEvent`.
  - Evidence: B005 local IDA export recheck found modeled `sub_5AF710` at `0x005af710-0x005af955`; bytes `0x005af955-0x005afa01` are non-`cc` switch metadata, with a data xref from `0x005af758` to the dword jump table at `0x005af958`; bytes `0x005afa01-0x005afa10` are fifteen `0xcc` alignment bytes.
  - Owner/source: compiler-generated support for [UID:0001LD] in [UID:0000CT] `SelectObjectWithKeyboardPane`; no hand-authored C++ declaration is needed for the table.
```

## Coverage Row Recommendations

Do not edit `by-memory/-coverage-report.md` directly from this report. Recommended placement: replace the existing [UID:0001LD] and [UID:0001LE] rows in the `0x005af...` target-selection section, and insert the ignored/support row between them.

Exact replacement row for [UID:0001LD]:

```md
        - [UID:0001LD][0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent](by-memory/0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent.md) 0x005af710-0x005af955 | virtual method | SelectObjectWithKeyboardPaneOnKeyEvent : reconstructable : 88% : strong : B005 source-quality reanalysis confirms vtable-only secondary handler at `0x0062f380`, no direct callers, exact modeled body after `0x005af709-0x005af710` padding, generated switch-support bytes continuing separately at `0x005af955-0x005afa01`, source-facing `SelectObjectWithKeyboardPane::OnKeyEvent` boolean consume semantics, event fields `kind/key/modifierFlags`, temporary Escape/Tab rewrites, `DoubleClick`/`TabVSwap`/target-selection-suppression config roles, saved target `s_selectObjectTargetId`, mode flag `s_selectObjectTargetModeActive`, MapPane lookup/traversal/interaction helpers, clear/forward helper names, base `LineInputPane` forwarding, and first-draft C++ readiness under the current combined-score gate.
```

Exact inserted ignored/support row:

```md
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005af955-0x005afa10 | switch-support/padding | SelectObjectWithKeyboardPane key-handler switch support and alignment : ignored : 100% : strong : B005 local IDA export recheck confirmed `sub_5AF710` ends at `0x005af955`; `0x005af955-0x005afa01` contains the compiler-generated jump/index table for the key switch (data xref from `0x005af758` to `0x005af958`), and `0x005afa01-0x005afa10` is fifteen `0xcc` alignment bytes before `sub_5AFA10`.
```

Exact replacement row for [UID:0001LE]:

```md
        - [UID:0001LE][0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent](by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md) 0x005afa10-0x005afc8d | virtual method | SelectObjectWithKeyboardPaneOnMouseEvent : reconstructable : 88% : strong : B005 source-quality reanalysis confirms vtable-only secondary handler at `0x0062f37c`, no direct callers, exact body and `0x005afc8d-0x005afc90` `cc cc cc` alignment, source-facing `SelectObjectWithKeyboardPane::OnMouseEvent` boolean consume semantics, mouse subtype `1` target-change and subtype `2` confirm/double-click paths, event x/y fields and pane-to-map coordinate translation, MapPane rect/hit-test helpers, `DoubleClick` config gating, saved target/highlight updates, local-player/chat cleanup fields, BlackHole dismissal, and first-draft C++ readiness under the current combined-score gate.
```

If supervisor policy requires a new UID rather than reusing the generic ignored UID shown above, the content and placement should remain the same with the supervisor-assigned ignored/support UID.

## Metadata Recommendations

Target metadata:
- [UID:0001LD]: `COMPLETION:88`, `CONFIDENCE:90`. Remove no-code blocker. Keep owner/emitter [UID:0000CT]. Add formal first-draft C++.
- [UID:0001LE]: `COMPLETION:88`, `CONFIDENCE:90`. Remove no-code blocker. Keep owner/emitter [UID:0000CT]. Add formal first-draft C++.

Support metadata:
- [UID:0000CT] can remain at its current score, but after incorporating the two handler drafts and helper names, `COMPLETION:87`, `CONFIDENCE:88` is defensible. This parent score change is optional; it is not required for the two target pages to clear the gate.
- [UID:0000OH] does not require a score/metadata change; add the file-scope state/source-route notes.
- MapPane helper pages should receive name/source-role notes. I do not recommend changing MapPane ownership metadata for the selector handler pages.
- Config/global support docs should receive field-name notes. The exact source spelling for `+0x28de62` remains descriptive, so I would not use this report alone to claim final-perfect Config naming.

## Validation Notes And Changed Files

Report-only work performed. I did not edit target by-* docs, support docs, generated files, or `by-memory/-coverage-report.md`.

Changed file:
- `tools/leaser/Agents/Agent-B005/research/0001LD-0001LE-SelectObjectWithKeyboardPaneInputHandlers-source-quality.md`

Validation performed:
- Re-read required guidance and target/support docs.
- Verified exact function boundaries, padding, function starts/ends, and switch-support bytes from local `memory.bin`.
- Verified direct no-caller/vtable-only status and vtable references from local `xrefs.json` and decompile metadata.
- Verified helper bodies and source roles from local decompile JSON for all addresses requested in the assignment.

Open items after this pass:
- Exact original spellings for common event struct fields and the runtime config byte at `+0x28de62` are not proven. The best defensible source-facing names above are strong enough for first-draft C++ and only cap confidence below final-perfect.
- The shared UserPane field names at `+0x210` and `+0x3eb4` should be harmonized with broader UserPane layout work. Their roles in these handlers are clear enough for source reconstruction.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001LD-0001LE-SelectObjectWithKeyboardPaneInputHandlers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0001LD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
