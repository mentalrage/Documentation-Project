*** UID:0002S2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ItemWhoInputPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = NarrowKey(event->key);

    if ((event->modifierFlags & 0x03) != 0)
        return true;

    if (event->kind != kKeyPressed)
        return false;

    LivingObjectPane *current =
        g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);

    if (key == kKeyEnter) {
        if (current != NULL) {
            ClearItemWhoTarget();
            SendObjectActionPacket(m_itemSlot, current->ObjectId());
        }
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kKeyEscape) {
        if (current != NULL)
            ClearItemWhoTarget();
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kKeySelfTarget) {
        LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
        if (current != selfTarget) {
            if (current != NULL)
                current->SetTargetHighlight(false);
            selfTarget->SetTargetHighlight(true);
            s_itemWhoTargetId = selfTarget->ObjectId();
        }
        return true;
    }

    LivingObjectPane *nextTarget = NULL;
    const bool alternateTraversal = (event->modifierFlags & 0x04) != 0;

    if (IsPreviousTargetKey(key)) {
        if (current != NULL) {
            nextTarget = alternateTraversal
                ? g_activeMapPane->FindPreviousSelectableObjectAlternate(current)
                : g_activeMapPane->FindPreviousSelectableObject(current);
        } else {
            nextTarget = g_pUserPane->GetLocalPlayerObject();
        }
    } else if (IsNextTargetKey(key)) {
        if (current != NULL) {
            nextTarget = alternateTraversal
                ? g_activeMapPane->FindNextSelectableObjectAlternate(current)
                : g_activeMapPane->FindNextSelectableObject(current);
        } else {
            nextTarget = g_pUserPane->GetLocalPlayerObject();
        }
    } else {
        return false;
    }

    if (nextTarget == current)
        return true;

    if (current != NULL)
        current->SetTargetHighlight(false);

    if (nextTarget != NULL) {
        nextTarget->SetTargetHighlight(true);
        s_itemWhoTargetId = nextTarget->ObjectId();
    } else {
        s_itemWhoTargetId = 0;
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: IDA-confirmed key handler attached to `ItemWhoInputPane`, with vtable-only dispatch, `do_narrow` key gate, Enter/Escape/self/previous/next behavior, `dword_69BF24` updates, highlight toggles, object-action packet send, callee set, and switch-support boundary bytes documented. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x005aedd0-0x005aefaf - ItemWhoInputPane Key Input

## Status

- Entity kind: key-input virtual method.
- IDA function: `sub_5AEDD0`, size `0x1df`
- Canonical owner: [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md), under [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- Rebuild handling: source-authored.
- Disposition: reconstructable project key-input body.
- Confidence: strong for function boundary, vtable dispatch slot, key/event gates, saved-target updates, highlight effects, item/action dispatch, switch-support bytes, owner, and first-draft key-handler C++; final event field, key constant, and alternate traversal names remain descriptive.

## Covered Range

| Range | Current method or group | Notes |
| --- | --- | --- |
| `0x005aedd0-0x005aefaf` | `ItemWhoInputPane` key input | Handles Enter/Escape, self-target selection, target navigation, highlight updates, and use-on-target dispatch for the saved item target. |

## Reconstruction

First-draft C++ is present as `ItemWhoInputPane::OnKeyEvent`. The method name and constants are source-facing/descriptive rather than proven original spellings. The binary compares Enter `13`, Escape `27`, self-target signed `-111`, previous/up keys `104`, `107`, `-128`, `-127`, and next/down keys `106`, `108`, `-126`, `-125`; the draft wraps those groups as `kKey*` and `IsPreviousTargetKey` / `IsNextTargetKey`.

[UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) is formally covered by this key handler for emitted-source purposes: the raw island's self/previous/next ItemWho behavior matches the inline local-player selection and target-navigation paths here, while current MCP still finds no direct route to the raw helper starts.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-05 reports `0x005aedd0` as `sub_5AEDD0`, size `0x1df`, ending at `0x005aefaf`.
- IDA MCP `py_eval` on 2026-06-05 confirms five `0xcc` alignment bytes at `0x005aedcb-0x005aedd0`. The following `0x005aefaf-0x005af050` bytes are switch-support tables and trailing alignment before the mouse-input method at `0x005af050`.
- `xrefs_to 0x005aedd0` reports a single vtable data ref at `0x0062f2f4`; `callers 0x005aedd0` reports no direct static callers.
- Decompilation and disassembly narrow the key byte at event offset `+0x08` through `std::ctype<char>::do_narrow` at `0x005aede8-0x005aeded`, read event flags from `+0x10a` at `0x005aede0-0x005aedf2`, reject the switch body when `(flags & 3) != 0`, and use the narrowed key to enter the dispatch cases.
- Enter case `13` requires event state byte `+0x04` to equal `8`, looks up the saved object id `dword_69BF24` through `dword_67A764` and `sub_506970` at `0x005aee27-0x005aee38`, clears the existing highlight with [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md) at `0x005aee44`, sends [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md) at `0x005aee54`, and closes or forwards the input through `sub_4F25A0` at `0x005aee5f`.
- The item/action value sent in the Enter case is read from `[edi+0x68]` in the adjusted method view, matching the full object offset `+0x108` written by the constructor.
- Escape case `27` requires the same event state byte, looks up the saved target at `0x005aee73-0x005aee7f`, clears highlight when a target exists at `0x005aee8e`, closes or forwards through `sub_4F25A0` at `0x005aee96`, and returns consumed.
- Self-target case signed key `-111` requires event state byte `8`, loads local-player object `dword_67A748`, compares it with the current saved target looked up at `0x005aeeae-0x005aeec0`, clears the old highlight if needed at `0x005aeed5`, highlights the local player at `0x005aeede`, and stores `local+0xfc` into `dword_69BF24` at `0x005aeeeb`.
- Previous/up-style keys `104`, `107`, `-128`, and `-127` look up the current saved target at `0x005aef01-0x005aef16`, use flag bit `0x04` to choose `sub_506B80` or `sub_506AE0`, and fall back to `dword_67A748` when there is no current target.
- Next/down-style keys `106`, `108`, `-126`, and `-125` look up the current saved target at `0x005aef44-0x005aef59`, use flag bit `0x04` to choose `sub_506BD0` or `sub_506B30`, and fall back to `dword_67A748` when there is no current target.
- B002 2026-06-27 accepted implementation confirms this key handler is the formal covered-by target for [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md): the raw self-target helper corresponds to the local-player path, the previous/up raw body corresponds to the `sub_506B80` / `sub_506AE0` branch, and the next/down raw body corresponds to the `sub_506BD0` / `sub_506B30` branch. The raw helper starts remain unreferenced non-functions, so they do not become callable helper C++.
- B013 source-quality reanalysis resolves the normal traversal helpers as `MapPane::FindPreviousSelectableObject` / `FindNextSelectableObject` and the modifier-bit `0x04` paths as descriptive `FindPreviousSelectableObjectAlternate` / `FindNextSelectableObjectAlternate`. The exact original "alternate" meaning remains open, but the wrappers should no longer be left as raw `sub_506B80` / `sub_506BD0`.
- The common navigation update returns immediately when old and new targets match, clears the old target highlight through `sub_53B1B0` at `0x005aef93`, highlights a non-null new target through `sub_53B1B0` at `0x005aeede`, stores the new object id into `dword_69BF24`, or writes zero at `0x005aefa0` when no new target exists.
- `callees 0x005aedd0` reports `sub_53B1B0`, `sub_506B30`, `std::ctype<char>::do_narrow`, `sub_5AF390`, `sub_506B80`, `sub_506970`, `sub_506AE0`, `sub_4F25A0`, `sub_5AF580`, and `sub_506BD0`.
- `xrefs_to dword_69BF24` reports this key handler's reads and writes at `0x005aee27`, `0x005aee73`, `0x005aeeae`, `0x005aeeeb`, `0x005aef01`, `0x005aef44`, and `0x005aefa0`.

## Access And Control Sites

| Address or offset | Meaning | Evidence |
| --- | --- | --- |
| `0x005aede0` | event flags `+0x10a` read | Loads modifier and filtering bits before key dispatch. |
| `0x005aede8-0x005aeded` | event key `+0x08` narrow | Converts the key byte through the active character type helper. |
| `0x005aedf8` | `flags & 3` test | Skips the switch body when low flag bits are set. |
| `0x005aee27-0x005aee38` | saved-target lookup | Enter path resolves `dword_69BF24` through `dword_67A764` and `sub_506970`. |
| `0x005aee44` | `call sub_5AF390` | Clears the active item-target highlight before confirming. |
| `0x005aee54` | `call sub_5AF580` | Sends the stored item/action byte and target object id. |
| `0x005aee5f` | `call sub_4F25A0` | Closes or forwards the consumed Enter event. |
| `0x005aee8e` | `call sub_5AF390` | Clears the active highlight during Escape cancellation. |
| `0x005aeeeb` | `dword_69BF24` write | Saves a newly selected target object's `+0xfc` id. |
| `0x005aef10-0x005aef13` | flag bit extraction | Converts event flag bit `0x04` into the navigation-direction selector. |
| `0x005aef2c` / `0x005aef35` | previous/up traversal | Selects between `sub_506B80` and `sub_506AE0`. |
| `0x005aef6f` / `0x005aef78` | next/down traversal | Selects between `sub_506BD0` and `sub_506B30`. |
| `0x005aef93` | `call sub_53B1B0` with `0` | Clears the old target highlight after navigation. |
| `0x005aeede` | `call sub_53B1B0` with `1` | Highlights the newly selected target. |
| `0x005aefa0` | zero save | Clears `dword_69BF24` when navigation produces no target. |

## Ownership Decision

Attach this method to [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md). The class and [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) parent clear the attachment gate, and the live evidence ties this body to the `ItemWhoInputPane` vtable slot, saved item-target global, sibling constructor/destructor state, and mouse/object-list target-maintenance behavior.

## Cross-References

- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md)
- [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md)
- [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md)
- [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md)
- [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md)
- [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md)
- [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md)
- [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md)
- [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md)

## Changes

- 2026-06-27 B002 accepted `0002S5` covered-by relationship:
  - Score unchanged at `88/90`.
  - Summary/evidence: recorded this emitted key handler as the formal covered-by target for [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md). Current MCP confirms equivalent inline self/previous/next behavior here while the raw helper starts remain unmodeled and route-negative.
- 2026-06-05: Raised completion/confidence from `76/84` to `86/90`, attached it to [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md), kept the reconstruction block empty under the final-code threshold, and refreshed the page with live IDA evidence for exact function bounds, vtable-only dispatch, key narrowing, event-state gates, Enter/Escape/self/navigation behavior, saved-target updates, highlight effects, item/action dispatch, callee set, no direct static callers, and adjacent switch-support bytes.
- 2026-06-22 B013 Rule 26 source-quality incorporation:
  - Before: `86/90`, empty C++.
  - After: `88/90`, first-draft `ItemWhoInputPane::OnKeyEvent(KeyEvent *event)` C++.
  - Summary/evidence: B013 names the saved target as `s_itemWhoTargetId`, the stored item byte as `m_itemSlot`, the clear helper as `ClearItemWhoTarget`, and the MapPane traversal family with descriptive alternate wrappers. Remaining caveats are original event struct/key enum spellings, not behavior blockers.
