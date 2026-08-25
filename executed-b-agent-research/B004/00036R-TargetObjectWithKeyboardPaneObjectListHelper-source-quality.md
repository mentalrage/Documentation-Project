** TARGET-REPORT-UID:00036R **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B004 Report - [UID:00036R] TargetObjectWithKeyboardPaneObjectListHelper

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md`

Target path: `source-3/project-documentation/by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md`

Required mode: B-agent source-quality research only. I did not edit by-* documentation, generated files, IDA DB files, or `by-memory/-coverage-report.md`.

## Summary Recommendation

Keep [UID:00036R] as reconstructable source-authored `TargetObjectWithKeyboardPane` code:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000ED`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000ED`
- Source route remains through [UID:0000ED][TargetObjectWithKeyboardPane] under [UID:0000OH][TargetSelectionInputPanes] and generated path `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- Recommended source-facing method name/signature: `bool TargetObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)`.
- Formal C++ should be populated now as first-draft C++. The body is exact enough, the direct class owner and file route clear the current 85/85 gate, the range is one modeled function with no split needed, and remaining uncertainty is original spelling/type names rather than source shape.

Important wording correction: the current target says the helper falls back when the saved target "no longer appears" in the incoming list. The binary does not prove that. The control flow falls back when the decoded payload id equals `s_targetObjectTargetId` / `dword_69BF2C`. This can still be consistent with a server "removed/invalidated object list" protocol, but the documentation should not describe the list as an active-object list unless the upstream protocol route proves that interpretation.

## Evidence Checked

Instructions and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/notes.md`
- `.codex/AGENTS.md`

Target and support docs:

- `source-3/project-documentation/by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md`
- `source-3/project-documentation/by-class/TargetObjectWithKeyboardPane.md`
- `source-3/project-documentation/by-file/TargetSelectionInputPanes.md`
- `source-3/project-documentation/by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md`
- `source-3/project-documentation/by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md`
- `source-3/project-documentation/by-memory/0x005b05b0-0x005b05cf.TargetObjectWithKeyboardPaneClearCurrentTarget.md`
- `source-3/project-documentation/by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`
- `source-3/project-documentation/by-memory/0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper.md`
- `source-3/project-documentation/by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`
- `source-3/project-documentation/by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`
- `source-3/project-documentation/by-class/SelectObjectWithKeyboardPane.md`
- `source-3/project-documentation/by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md`
- `source-3/project-documentation/by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md`
- `source-3/project-documentation/by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md`
- `source-3/project-documentation/by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`
- `source-3/project-documentation/by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`
- `source-3/project-documentation/by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
- `source-3/project-documentation/by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`
- `source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`

Local exported analysis:

- `resources/exported_data/functions/0x005b0510.json`
- `resources/exported_data/functions/0x005afc90.json`
- `resources/exported_data/functions/0x005af2f0.json`
- `resources/exported_data/functions/0x005aea60.json`
- `resources/exported_data/functions/0x00575470.json`
- `resources/exported_data/functions/0x005754c0.json`
- `resources/exported_data/master_vtables.json`
- `resources/exported_data/master_names.json`
- `resources/suspect-classes.md`

Search checks:

- Searched for `005b0510`, `0062f414`, `TargetObjectWithKeyboardPane`, `SelectObjectWithKeyboardPane`, `ItemWho`, `ObjectListVirtual`, `dword_69BF2C`, `69BF28`, `00575470`, `005754c0`, `FindObjectPaneById`, `SetTargetHighlight`, and coverage references across `source-3/project-documentation` and `resources`.
- Confirmed `by-memory/-coverage-report.md` currently shows neighboring TargetObject rows but no [UID:00036R] row, while `auto-generated/-ag-memory-coverage.md` includes [UID:00036R].

## Heuristic / Inference Reanalysis And Validation

### Boundary, split, and padding

The target is one exact modeled function:

- IDA name: `sub_5B0510`
- Ghidra name: `FUN_005b0510`
- Half-open range: `0x005b0510-0x005b05a3`
- Size: `0x93`
- Predecessor padding: `0x005b050d-0x005b0510`, three `0xcc` bytes after [UID:0001LL] `TargetObjectWithKeyboardPane::OnMouseEvent`.
- Successor padding: `0x005b05a3-0x005b05b0`, thirteen `0xcc` bytes before [UID:00036S] `TargetObjectWithKeyboardPaneClearCurrentTarget`.

No split is needed. The body starts at a real modeled function, ends before confirmed padding, and contains one coherent object-list virtual helper. It is not part of the predecessor mouse handler and not part of the successor clear helper. It is also not compiler switch support or vtable data.

### Route and liveness

The function has no ordinary direct code callers in the local exported caller list. It is reached through the `TargetObjectWithKeyboardPane` secondary vtable:

- `xrefs_to 0x005b0510`: data ref at `0x0062f414`
- `master_vtables.json`: `vftable_0062f404`, entry index `4`, offset `+0x10`, address `0x005b0510`
- Same vtable view has:
  - index `1`, offset `+0x04`, `0x005b0290` (`OnMouseEvent`)
  - index `2`, offset `+0x08`, `0x005b0010` (`OnKeyEvent`)
  - index `3`, offset `+0x0c`, inherited `0x004f2580`
  - index `4`, offset `+0x10`, this object-list virtual

This is the same slot pattern as the sibling selectors:

- `SelectObjectWithKeyboardPane`: `vftable_0062f378`, index `4`, offset `+0x10`, address `0x005afc90`
- `ItemWhoInputPane`: `vftable_0062f2ec`, index `4`, offset `+0x10`, address `0x005af2f0`
- `SpellWhoInputPane`: vtable data ref at `0x0062f270`, same object-list pattern

The IDA exported JSON reports `num_callers.ida = 1`, but the only listed `xrefs_to` item is the data ref at `0x0062f414`. Treat this as vtable-only reachability, not as a hidden direct callsite.

### Source ownership

Keep direct owner [UID:0000ED] `TargetObjectWithKeyboardPane`.

Evidence:

- The constructor page [UID:0001LI] installs `TargetObjectWithKeyboardPane` vtable views including the secondary vtable family that contains the `0x0062f414` entry.
- The class page already routes the target-object suffix children [UID:00036R], [UID:00036S], [UID:00036T], and [UID:00036U] through [UID:0000ED].
- The helper reads and writes `dword_69BF2C`, the target-object saved target id, not `dword_69BF28` for `SelectObjectWithKeyboardPane`, `dword_69BF24` for `ItemWhoInputPane`, or `dword_69BF20` for `SpellWhoInputPane`.
- It uses the same MapPane lookup and LivingObjectPane highlight dependencies as TargetObject keyboard/mouse handlers.
- It has the same post-mouse suffix position as the `SelectObjectWithKeyboardPane` object-list virtual at `0x005afc90`.

Rejected owner/source alternatives:

- `MapPane`: rejected. `MapPane` provides `FindObjectPaneById` and traversal helpers, but this body is a vtable slot in a `TargetObjectWithKeyboardPane` table and updates target-selection static state.
- `LivingObjectPane`: rejected. `LivingObjectPane::SetTargetHighlight` is a dependency only.
- `PacketBuffer`: rejected. `PacketBufferReadUInt32BE` is a scalar decode helper only.
- `UserPane` / `g_pUserPane`: rejected. The local-player fallback is consumed here, but the selector state and vtable route are target-selection owned.
- `TargetSelectionInputPanes` file as direct canonical owner: rejected for the memory child. The file [UID:0000OH] is the source module route, but the direct child owner should remain the class [UID:0000ED] under current documentation policy.
- no-owner/non-emitting: rejected. The vtable data ref proves active virtual dispatch reachability, and the body is a source-authored virtual method rather than padding, thunk, or retained dead code.

### Signature and calling convention

Exported signatures:

- Ghidra: `uint __stdcall FUN_005b0510(uint param_1)`
- IDA: `char __stdcall sub_5B0510(int a1)`

Source-facing interpretation:

- Best source signature: `bool TargetObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)`.
- The stack argument is an event/packet object whose payload pointer is read from `event + 0x0c`.
- The apparent `__stdcall` shape is a decompiler artifact of an unused `this` register. The function is a member virtual because the only reachability is the class vtable slot. MSVC thiscall methods with stack parameters also end in `retn 4`, so this ABI shape does not block a source member-method signature.
- Return value is effectively `false` on all paths. Source should use `bool` and `return false;`.

Exact original type name remains unresolved. I recommend `PacketEvent` as a local documentation placeholder because `event+0x0c` is the only field used and no stronger named packet/event struct exists in current docs. This is not a no-code blocker; the generated first draft can use the same provisional type style already used for `KeyEvent` and `MouseEvent` in neighboring drafts.

### Payload parsing and packet helper names

IDA decompilation:

```c
v1 = *(_BYTE **)(a1 + 12);
if (*v1 == 95) {
    v2 = std::_Narrow_char_traits<char,int>::to_char_type(v1 + 1);
    v3 = 0;
    v4 = 2;
    if (v2) {
        while (1) {
            v5 = sub_5754C0(&v1[v4]);
            v4 += 4;
            if (v5 == dword_69BF2C)
                break;
            if (v2 <= (unsigned __int8)++v3)
                return 0;
        }
        v7 = (_BYTE *)sub_506970((_WORD **)dword_67A764, dword_69BF2C);
        v8 = (_BYTE *)dword_67A748;
        dword_69BF2C = *(_DWORD *)(dword_67A748 + 252);
        sub_53B1B0(v7, 0);
        sub_53B1B0(v8, 1);
    }
}
return 0;
```

Access map:

| Address | Operation | Source-quality role |
| --- | --- | --- |
| `0x005b0517` | read `[event + 0x0c]` | Loads object-list payload pointer. |
| `0x005b051a` | compare first byte with `0x5f` | Requires leading underscore `_`. |
| `0x005b0525` | call `0x00575470` | Reads the count byte at `payload + 1`; this is `std::_Narrow_char_traits<char,int>::to_char_type`, not project source logic. |
| `0x005b0531` | initialize scan offset `2` | Object ids begin at `payload + 2`. |
| `0x005b0546` | call `0x005754c0` | Reads one four-byte big-endian object id. Source name: `PacketBufferReadUInt32BE`. |
| `0x005b054b-0x005b0557` | compare decoded id with `dword_69BF2C` | Checks the target-object saved id. |
| `0x005b055b-0x005b0567` | increment loop index and early return | Stops without changing state when all entries are exhausted without a match. |
| `0x005b056a-0x005b0571` | call `0x00506970` | `MapPane::FindObjectPaneById(g_activeMapPane, s_targetObjectTargetId)`. |
| `0x005b0576` | read `dword_67A748` | Loads local-player object fallback. |
| `0x005b0580-0x005b0586` | write `dword_69BF2C = localPlayer + 0xfc` | Replaces saved target id with local-player object id. |
| `0x005b058c` | call `0x0053b1b0(old, 0)` | Clears old target highlight. |
| `0x005b0595` | call `0x0053b1b0(localPlayer, 1)` | Highlights/selects local player. |

Helper names:

- `0x00575470`: do not document as a project helper. It is `std::_Narrow_char_traits<char,int>::to_char_type`, a Dinkumware/runtime byte dereference. Source should read `payload[1]`.
- `0x005754c0`: `PacketBufferReadUInt32BE`. The PacketBuffer child [UID:0003YK] documents this exact function as the four-byte big-endian scalar reader.
- `0x00506970`: `MapPane::FindObjectPaneById(int objectId)` / `LookupObjectPaneById`. Use `FindObjectPaneById` because the current generated TargetSelection draft already uses that spelling.
- `0x0053b1b0`: `LivingObjectPane::SetTargetHighlight(bool highlighted)`.

### Correcting object-list semantics

The current target and support docs say or imply "fallback when the saved target no longer appears in the incoming list." The binary flow says:

1. Decode each listed id.
2. If the listed id equals `s_targetObjectTargetId`, branch to fallback.
3. If the loop exhausts without equality, return `false` without changing the target.

Therefore the safest documentation is:

- "Parses an underscore-prefixed object-list/invalidation payload; when the payload contains the current saved target id, the selector resets selection to the local player, clears the old target highlight, and highlights the local player."

Why this does not contradict the historical "disappears" idea entirely:

- The protocol message might be a removal/invalid-target list rather than an active-object list.
- The method name "object-list" in current docs is a behavioral label, not a proved protocol name.
- No upstream packet dispatch route or opcode name was found in this pass that proves the payload is an active live-object set.

Best supported direction:

- Use neutral `object-list payload` or `object-list invalidation payload` wording.
- Do not say "absent from list" unless a separate packet-protocol pass proves the list represents active objects and the decompile has been explained by an inverted helper meaning. Current local decompilation does not support that.

### State/global names

Use these names in target/support docs:

| Raw name | Recommended source-facing name | Evidence |
| --- | --- | --- |
| `dword_69BF2C` | `s_targetObjectTargetId`; alias `s_targetObjectSavedTargetId` | [UID:0002AB] and B005 TargetObject pass identify this as the file-scope TargetObject saved/current id. This helper reads it for compare and lookup, then writes the fallback id. |
| `dword_67A764` | `g_activeMapPane` | Existing MapPane and TargetSelection drafts use it for object id lookup, hit test, interaction, and traversal. |
| `dword_67A748` | `g_pUserPane->GetLocalPlayerObject()` in source drafts; possible lower-level alias `g_localPlayerObjectPane` | In this body it is passed directly to `LivingObjectPane::SetTargetHighlight` and its `+0xfc` object-id field is read. The existing generated target-selection drafts prefer `g_pUserPane->GetLocalPlayerObject()` for source style. |
| object `+0xfc` | `LivingObjectPane::GetObjectId()` / inherited object id | Neighboring key/mouse drafts use `GetObjectId()` and docs consistently identify `+0xfc` as object id. |

Do not document `dword_69BF2C` as a class field. It is absolute static storage in the target-selection source family.

### Relationship to keyboard and mouse handlers

This helper is not called by [UID:0001LK] or [UID:0001LL]. It is a separate virtual handler in the same secondary vtable family.

The relationship is state and behavior parity:

- Constructor [UID:0001LI] selects and highlights the initial target and writes `s_targetObjectTargetId`.
- Keyboard handler [UID:0001LK] updates `s_targetObjectTargetId` on self/previous/next traversal, calls [UID:00036S] on cancel, and calls [UID:00036U] for Tab/`v` dispatch forwarding.
- Mouse handler [UID:0001LL] updates `s_targetObjectTargetId` on hit-test target changes and calls [UID:00036S] before confirming interactions.
- This object-list virtual watches server/client payload ids and restores the selector to the local-player fallback when the payload contains the current target id.
- Saved-target globals [UID:0002AB] are the shared static data that ties these methods together.

### Sibling comparison

The four object-list virtuals are near-identical bodies, differing only in saved-target slot:

| Class | Range | Saved id |
| --- | --- | --- |
| `SpellWhoInputPane` | `0x005aea60-0x005aeaf3` | `dword_69BF20` |
| `ItemWhoInputPane` | `0x005af2f0-0x005af383` | `dword_69BF24` |
| `SelectObjectWithKeyboardPane` | `0x005afc90-0x005afd23` | `dword_69BF28` |
| `TargetObjectWithKeyboardPane` | `0x005b0510-0x005b05a3` | `dword_69BF2C` |

The SpellWho and ItemWho pages currently describe the equality/fallback behavior correctly: no change when the id is not present, fallback when it is found. The SelectObject page and `TargetSelectionInputPanes.md` have stale wording that says the fallback happens when the current target "disappears" from the list. That should be corrected with the same neutral wording recommended for [UID:00036R].

### First-draft C++ readiness

First-draft C++ is now appropriate.

Reasons:

- The function is source-authored, not compiler glue.
- The route is active through a class vtable slot.
- The direct class owner [UID:0000ED] and file route [UID:0000OH] clear the current gate.
- The method body is one exact 0x93-byte function with confirmed padding before and after.
- Helper names are now strong enough: `PacketBufferReadUInt32BE`, `MapPane::FindObjectPaneById`, `LivingObjectPane::SetTargetHighlight`.
- Static/global names are strong enough for draft source: `s_targetObjectTargetId`, `g_activeMapPane`, local player object access.

Confidence remains below final-perfect because the exact original virtual method name, exact packet/event struct name, and exact protocol meaning of the underscore payload are still inferred. These are source-quality caveats, not no-code blockers.

Recommended first-draft C++:

```cpp
bool TargetObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;
    if (payload[0] != '_')
        return false;

    const unsigned char count = payload[1];
    for (unsigned char i = 0; i < count; ++i) {
        const unsigned int objectId =
            PacketBufferReadUInt32BE(payload + 2 + i * 4);

        if (objectId == s_targetObjectTargetId) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *localPlayer = g_pUserPane->GetLocalPlayerObject();

            s_targetObjectTargetId = localPlayer->GetObjectId();
            oldTarget->SetTargetHighlight(false);
            localPlayer->SetTargetHighlight(true);
            break;
        }
    }

    return false;
}
```

Notes on draft choices:

- `payload[1]` is preferred over a named project helper because `0x00575470` is a character-traits byte load.
- `PacketBufferReadUInt32BE` is preferred for `0x005754c0`.
- The draft intentionally omits a null check around `oldTarget`, matching the binary. The lookup is expected to succeed on the equality/fallback path.
- If implementation reviewers prefer direct global naming for `dword_67A748`, replace `g_pUserPane->GetLocalPlayerObject()` with the existing project spelling for the local-player `LivingObjectPane *` global. The semantics should remain local player object, `+0xfc` object id, and target highlight set.

## Recommended Target Doc Changes

For `by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md`:

1. Change metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ED | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ED | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace the current purpose with:

```text
This source-authored secondary-vtable helper handles underscore-prefixed object-list payloads for `TargetObjectWithKeyboardPane`. It reads the payload pointer from `event+0x0c`, requires leading `_`, treats `payload[1]` as an entry count, scans four-byte big-endian object ids from `payload+2`, and compares each id with `s_targetObjectTargetId` / `dword_69BF2C`. When the payload contains the current saved target id, the helper resolves the old target through `MapPane::FindObjectPaneById`, switches the saved id to the local player object's `+0xfc` id, clears the old target highlight, highlights the local player, and returns `false`.
```

3. Add or replace evidence with these details:

- Exact half-open range `0x005b0510-0x005b05a3`; no split/merge needed.
- Predecessor `0x005b050d-0x005b0510` is three bytes of `0xcc` padding after [UID:0001LL].
- Successor `0x005b05a3-0x005b05b0` is thirteen bytes of `0xcc` padding before [UID:00036S].
- `xrefs_to` reports vtable data ref at `0x0062f414`; no ordinary direct code callers.
- `master_vtables.json` places the function in `vftable_0062f404`, index `4`, offset `+0x10`, sibling to `OnMouseEvent` and `OnKeyEvent`.
- `arg+0x0c` payload pointer, leading `_` gate, count byte at `payload+1`, scan offset `2`, `PacketBufferReadUInt32BE` four-byte ids, compare against `dword_69BF2C`, fallback on equality, no state change when no id matches.
- `0x00575470` is runtime `std::_Narrow_char_traits<char,int>::to_char_type` / direct byte load, not a project helper.
- `0x005754c0` is `PacketBufferReadUInt32BE`.
- `0x00506970` is `MapPane::FindObjectPaneById`.
- `0x0053b1b0` is `LivingObjectPane::SetTargetHighlight`.
- `dword_69BF2C` is source-facing `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`.
- `dword_67A748` is local-player object fallback in this context; use the existing source spelling from current generated docs, currently `g_pUserPane->GetLocalPlayerObject()`.

4. Add a signature/calling-shape note:

```text
Best source-facing signature: `bool TargetObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)`. IDA/Ghidra show a one-argument `__stdcall` because the hidden `this` register is unused, but the vtable slot at `0x0062f414` proves this is a class virtual. The low byte of the return value is always zero, so source should return `false`.
```

5. Add the first-draft C++ block from this report.

6. Add a score rationale:

```text
Completion 88: exact boundary/padding, vtable reachability, payload parser, helper/global names, owner route, sibling comparison, source semantics, and draft C++ are documented.
Confidence 90: vtable and decompile evidence are strong. Confidence is capped by exact original method name, exact packet/event struct spelling, and unresolved active-list versus invalidation-list protocol naming.
```

## Recommended Support Doc Changes

### `by-class/TargetObjectWithKeyboardPane.md`

Update the method row:

```text
| `bool TargetObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)` | [UID:00036R][0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper](by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md) | Secondary-vtable object-list virtual at `0x0062f414`/slot `+0x10`; parses underscore-prefixed payloads, scans big-endian object ids against `s_targetObjectTargetId`, and when the payload contains the current target id, resets selection to the local player and toggles old/new highlights. First-draft C++ ready. |
```

In evidence notes, add:

- `0x005b0510` is the TargetObject sibling of the SpellWho/ItemWho/SelectObject object-list virtuals.
- `dword_69BF2C` is static file state, not a class field.
- The helper falls back on a matched id in the payload. Do not say "no longer appears" unless a protocol pass proves the payload is an active-object set.

### `by-file/TargetSelectionInputPanes.md`

Update the stale boundary note that currently says:

```text
0x005afc90 is a SelectObjectWithKeyboardPane vtable helper that parses underscore-prefixed object lists and falls back to the local player if the current target disappears from the list.
```

Recommended replacement:

```text
`0x005afc90` and `0x005b0510` are SelectObject/TargetObject object-list virtuals in the secondary selector vtables. Both parse underscore-prefixed payloads, read a count byte at payload+1, scan four-byte big-endian object ids from payload+2, and reset the saved selection to the local player when the payload contains the current saved target id. The exact upstream protocol name is still unresolved; avoid describing the payload as an active-object list unless a later packet-route pass proves that.
```

Add:

- [UID:00036R] is now first-draft C++ ready.
- Use `s_targetObjectTargetId` for `dword_69BF2C`.
- Use `PacketBufferReadUInt32BE`, `MapPane::FindObjectPaneById`, and `LivingObjectPane::SetTargetHighlight` as source-facing dependencies.

### `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`

Add to the `dword_69BF2C` evidence:

```text
[UID:00036R] reads `s_targetObjectTargetId` while scanning an underscore-prefixed object-list payload and writes it to the local-player object id when the payload contains the previous saved target id. This confirms the slot is file-scope TargetObject selection state and not a class member.
```

### `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md`

Optional but recommended because it shares the stale semantic assumption:

- Correct the Role section to say the fallback path occurs when the payload contains `dword_69BF28`, not when the id is absent from the decoded list.
- Keep the exact protocol meaning unresolved unless a packet dispatcher route proves the list is active/present objects.
- Consider first-draft C++ parity later using the same shape as [UID:00036R] with `s_selectObjectTargetId`.

### `by-class/SelectObjectWithKeyboardPane.md`

Optional but recommended after the sibling page is fixed:

- Change "if the current target disappears, it switches selection to the local player object" to neutral wording: "when the object-list payload contains the current saved id, it switches selection to the local player object; exact protocol meaning remains unresolved."

### `by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md` and `by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md`

No target-blocking changes are required. These pages already state the equality/fallback behavior in their evidence notes. A later consistency pass could give them the same source-facing `OnObjectList` signature language and draft C++.

### `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`

No required edit. The current page already names `0x005754c0` as `PacketBufferReadUInt32BE`.

### `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`

No required edit. It already names `0x00506970` as `MapPane::FindObjectPaneById` / `LookupObjectPaneById`.

### `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`

No required edit. It already identifies `0x0053b1b0-0x0053b1f7` as `SetHighlightState`; TargetSelection docs prefer `LivingObjectPane::SetTargetHighlight`. If a later naming sweep chooses one canonical spelling, preserve `SetTargetHighlight` as the target-selection-facing alias.

## Exact Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` during the B report pass. The current manual coverage file appears to be missing the [UID:00036R] row between [UID:0001LL] and the next aggregate, while `auto-generated/-ag-memory-coverage.md` has the autogenerated row.

Pending insertion row for `by-memory/-coverage-report.md`, under the `TargetObjectWithKeyboardPane` group after the [UID:0001LL] mouse-event row:

```text
        - [UID:00036R][0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper](by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md) 0x005b0510-0x005b05a3 | virtual helper | TargetObjectWithKeyboardPaneObjectListHelper : reconstructable : 88% : strong : IDA-confirmed `TargetObjectWithKeyboardPane` secondary-vtable object-list virtual at `0x0062f414`/slot `+0x10`, exact `0x93` boundary with predecessor/successor padding, no direct code callers, payload pointer at `event+0x0c`, leading `_` gate, count byte at payload+1, `PacketBufferReadUInt32BE` four-byte id scan from payload+2, `s_targetObjectTargetId` compare, local-player fallback through `dword_67A748`, old/new highlight toggles via `LivingObjectPane::SetTargetHighlight`, helper/global names, rejected owner alternatives, and first-draft C++ readiness documented.
```

If the supervisor instead treats the row as replacing an unseen/generated row, use the same text as the exact replacement.

## Validation Commands For Implementation Callback

From `source-3/project-documentation`, after implementing target/support docs:

> Executable block R001 was removed from this report and preserved verbatim in [00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md](00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-class/TargetObjectWithKeyboardPane.md` is touched:

> Executable block R002 was removed from this report and preserved verbatim in [00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md](00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-file/TargetSelectionInputPanes.md` is touched:

> Executable block R003 was removed from this report and preserved verbatim in [00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md](00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md` is touched:

> Executable block R004 was removed from this report and preserved verbatim in [00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md](00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional SelectObject semantic fix is implemented:

> Executable block R005 was removed from this report and preserved verbatim in [00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md](00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because the target C++ block would change generated output, the implementer should check whether validator/autogen updates:

- `source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`

Do not hand-edit generated output unless the repository workflow requires it. Report any generated/stat files changed by validator/autogen.

## IDA Rename, Type, And Comment Recommendations

Function:

- Rename `sub_5B0510` / `FUN_005b0510` to `TargetObjectWithKeyboardPane::OnObjectList` or IDA-safe `TargetObjectWithKeyboardPane_OnObjectList`.
- Type as a class virtual with an unused `this` register and one stack argument:

```c
bool __thiscall TargetObjectWithKeyboardPane_OnObjectList(
    TargetObjectWithKeyboardPane *this,
    const PacketEvent *event);
```

If IDA cannot comfortably model the unused `this`, keep the raw ABI as a comment and type the stack argument:

```c
bool __stdcall TargetObjectWithKeyboardPane_OnObjectList_abi(const PacketEvent *event);
```

Struct/type:

- Define or comment `PacketEvent` / object-list packet event with `payload` pointer at offset `+0x0c`. Other fields are not recovered from this function.

Data and helper names:

- `dword_69BF2C`: `s_targetObjectTargetId` primary, alias `s_targetObjectSavedTargetId`.
- `dword_67A764`: `g_activeMapPane`.
- `dword_67A748`: in this context, local-player `LivingObjectPane *`; use the project canonical spelling if one exists, otherwise comment "local player object pane / source draft `g_pUserPane->GetLocalPlayerObject()`".
- `sub_5754C0`: `PacketBufferReadUInt32BE`.
- `0x00575470`: leave as `std::_Narrow_char_traits<char,int>::to_char_type`; add comment "payload count byte load" if useful, but do not rename as a project helper.
- `sub_506970`: `MapPane::FindObjectPaneById`.
- `sub_53B1B0`: `LivingObjectPane::SetTargetHighlight` / `SetHighlightState`.

Vtable comments:

- At `0x0062f414`: `TargetObjectWithKeyboardPane secondary vtable slot +0x10: OnObjectList(PacketEvent*)`.
- At `vftable_0062f404`: entry index `4` is the object-list virtual sibling to `OnMouseEvent` and `OnKeyEvent`.

Inline comments:

- At compare branch around `0x005b054b`: "If payload contains current target id, reset target selection to local player."
- At early return around `0x005b055b-0x005b0567`: "No matched id in payload; leave selection unchanged."
- At fallback stores/calls `0x005b0580-0x005b0595`: "Save local player id, clear previous highlight, set local-player highlight."

## Implementation Checklist For Callback

1. Edit only the accepted target/support docs under normal lease rules; do not edit `by-memory/-coverage-report.md`.
2. Update [UID:00036R] metadata to `88/90`, keep owner/emitter/reconstructable unchanged.
3. Replace stale no-C++ wording with the current 85/85 gate analysis and first-draft readiness.
4. Add source-facing method/signature `bool TargetObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)`.
5. Add the first-draft C++ block from this report, adapting only names to existing project spelling if current docs prefer different canonical aliases.
6. Correct object-list semantics: fallback is triggered by a matched id in the decoded payload. Avoid unsupported "saved target no longer appears" wording.
7. Add evidence details for range, padding, vtable slot `0x0062f414`, no direct code callers, payload layout, helper identities, state globals, local-player fallback, and highlight calls.
8. Update `TargetObjectWithKeyboardPane.md` method inventory and evidence.
9. Update `TargetSelectionInputPanes.md` stale object-list wording and [UID:00036R] readiness.
10. Update `TargetSelectionSavedTargetGlobals.md` if the [UID:00036R] write/use detail is missing.
11. Optionally fix the sibling SelectObject object-list semantic wording if the implementation callback permits broader support edits.
12. Run scoped validators for every touched by-* doc with `--apply --queue-timeout 240`.
13. Check whether generated `TargetSelectionInputPanes.cpp` and autogen coverage changed.
14. Return changed files, validation commands/results, generated/stat changes, and the exact pending coverage row.

## Remaining Issues And Impact

Open issue: exact original method name.

- Evidence checked: vtable slot, sibling docs, target-selection generated output, class/file summaries.
- Best inference: `OnObjectList`.
- Impact: caps confidence below final-perfect but does not block C++ because behavior and route are strong.

Open issue: exact packet/event struct name.

- Evidence checked: function reads only `event+0x0c`; no broader packet dispatch route was found in the docs/exported data pass.
- Best inference: `PacketEvent` with payload pointer at `+0x0c`.
- Impact: first-draft type placeholder needed. Not a no-code blocker.

Open issue: exact protocol semantics of the underscore object-list payload.

- Evidence checked: target and sibling decompilations, sibling docs, TargetSelectionInputPanes notes.
- Best inference: neutral "object-list payload" or "object-list invalidation payload." The branch proves fallback on matched id, not on absence from the decoded list.
- Impact: support docs should correct stale active-list wording. Confidence remains capped because the upstream opcode/dispatcher was not proven in this pass.

Open issue: local-player global spelling.

- Evidence checked: existing target-selection drafts, `dword_67A748` uses in keyboard/mouse docs, local-player `+0xfc` object-id reads, highlight helper calls.
- Best inference: source draft should use `g_pUserPane->GetLocalPlayerObject()` for consistency with current generated C++; if a direct `g_localPlayerObjectPane` canonical name is accepted elsewhere, implementation can substitute that spelling.
- Impact: affects C++ spelling only, not behavior/ownership.

Final assessment: implementation is ready once supervisor sends a callback. The target should no longer remain a low-confidence blank-C++ helper.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00036R"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00036R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
