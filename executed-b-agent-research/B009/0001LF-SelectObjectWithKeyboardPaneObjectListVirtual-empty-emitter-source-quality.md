** TARGET-REPORT-UID:0001LF **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0001LF SelectObjectWithKeyboardPaneObjectListVirtual Empty-Emitter Source-Quality Report

Agent: Agent-B009
Assignment ID: B009-empty-emitter-report-0001LF-SelectObjectWithKeyboardPaneObjectListVirtual-20260629
Mode: Report-only research first
Target: `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md`

## Final Recommendation

UID0001LF should be changed from an empty-emitter marker to a formal first-draft C++ method. The current owner/emitter route is already valid: canonical owner stays `0000CT` (`SelectObjectWithKeyboardPane`) and source emission stays routed through the `TargetSelectionInputPanes` source family. The empty generated output is caused by the target's blank formal C++ block, not by a missing owner, missing emitter, bad range, or no-owner condition.

Recommended metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000CT`
- `EMITTER_UIDS:0000CT`
- `EMITTER_POSITION_OPTIONAL:` unchanged/blank

The target is source-ready under the current formal C++ gate. Existing score `86/90` already averages 88, and the current MCP pass confirms the missing details needed to justify source code: exact range, vtable-only reachability, payload layout, object-id decoding loop, saved-target/global behavior, local-player fallback, highlight toggles, and sibling parity with existing object-list handlers.

## Current Target State

The target file currently records UID0001LF as a reconstructable `SelectObjectWithKeyboardPane` virtual at `0x005afc90-0x005afd23`, with `COMPLETION:86`, `CONFIDENCE:90`, owner/emitter `0000CT`, and blank formal `RECONSTRUCTION_CPP CODE`.

The target narrative already contains many correct facts: payload pointer at argument offset `0x0c`, leading underscore gate, count byte, four-byte object-id entries, saved select-object target global `dword_69BF28`, active map lookup through `dword_67A764`, local-player fallback through `dword_67A748`, old/new highlight toggles through `sub_53B1B0`, and exact 13-byte post-function `int3` padding. The source-quality blocker is the remaining blank C++ state and stale caution text saying final code is withheld until a higher evidence threshold.

Current generated output confirms the practical problem:

- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` contains UID0001LF as an Empty Emitter Marker.
- `auto-generated/-ag-memory-coverage.md` lists UID0001LF as routed/emitting through owner/emitter `0000CT`, but coded `no`.

Therefore the generated marker is a C++-blank marker, not a route failure.

## Evidence Checked

Current IDA MCP evidence was collected from active session `c9671f69` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `19076`. `server_health` reported status `ok`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`. The stale session `d4d50b81` was not used.

MCP facts checked:

- `lookup_funcs` at `0x005afc90`, boundaries around `0x005afc80`, `0x005afd23`, and `0x005afd30`.
- `analyze_function` and `decompile` for `0x005afc90`.
- `disasm` for `0x005afc90`.
- `xrefs_to` for `0x005afc90`, `0x0062f388`, `0x0062f378`, `0x0069bf28`, `0x0067a764`, and `0x0067a748`.
- `get_bytes` around `0x005afc80-0x005afd40`, `0x005afd23`, and vtable bytes at `0x0062f378`.
- `find_bytes` for the target function pointer, vtable slot address, and global pointer constants.
- `get_int` and `int_convert` for vtable entries and constants `0x93`, `0x0c`, `0xfc`, `0x5f`, `0x04`, and `0x0d`.
- Sibling object-list functions `0x005af2f0` and `0x005b0510`.

Project documentation checked:

- Target: `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md`.
- Class support: `by-class/SelectObjectWithKeyboardPane.md`.
- File support: `by-file/TargetSelectionInputPanes.md`.
- Singleton support: `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`.
- Saved target globals: `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`.
- Active map singleton: `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`.
- Local player/user pane global: `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`.
- Sibling object-list docs: `0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md` and `0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md`.
- Generated output and tracker state were inspected read-only.
- Archived reports were searched by UID/address/name/source family/global terms. The B004 TargetObject object-list report is directly relevant and corrects the same stale "absence/disappeared" interpretation: the branch fires when a decoded payload id equals the saved target id.

## Positive Evidence

### Range and Padding

MCP `lookup_funcs` identifies `0x005afc90` as `sub_5AFC90`, size `0x93` bytes. `int_convert` verifies `0x93` as decimal 147.

The exact target range remains `0x005afc90-0x005afd23`. The predecessor `sub_5AFA10` ends before the target and is followed by three `int3` bytes at `0x005afc8d-0x005afc90`. The successor `sub_5AFD30` begins at `0x005afd30`, and `get_bytes` verifies thirteen `int3` bytes at `0x005afd23-0x005afd30`. `int_convert` verifies `0x0d` as decimal 13.

No split, merge, or range correction is recommended.

### Vtable Slot and Reachability

`xrefs_to 0x005afc90` returns exactly one xref: a data xref at `0x0062f388`. `find_bytes` for little-endian `90 FC 5A 00` also matches only `0x0062f388`. `find_bytes` for the slot address bytes `88 F3 62 00` returns no matches, so there is no observed stored pointer to the slot itself.

The vtable block at `0x0062f378` decodes as:

- `0x0062f378 -> 0x005b7862`
- `0x0062f37c -> 0x005afa10`
- `0x0062f380 -> 0x005af710`
- `0x0062f384 -> 0x004f2580`
- `0x0062f388 -> 0x005afc90`
- `0x0062f38c -> 0x00544df0`
- `0x0062f390 -> 0x00544e00`
- `0x0062f394 -> 0x004a89f0`

The vtable base `0x0062f378` is referenced by constructor/destructor-family code at `0x005af659`, `0x005af6e6`, and `0x005b7bcc`. This is sufficient to keep UID0001LF as a `SelectObjectWithKeyboardPane` virtual method even though it has no direct code callers.

### Payload and Loop Behavior

The decompiler and disassembly agree on the payload shape:

- The single stack argument is treated as an event/message object.
- The payload pointer is read from offset `+0x0c` of that argument.
- The first payload byte must be `0x5f`, ASCII `_`; `int_convert` verifies `0x5f` as decimal 95 and `_`.
- The count byte is read from payload offset `+1` through the standard character traits helper at `0x00575470`.
- The loop starts at payload offset `+2`.
- Each entry advances by `4` bytes; `int_convert` verifies `0x04` as decimal 4.
- Each entry is decoded by `sub_5754C0`, the same scalar packet-buffer read helper used by sibling object-list handlers.

The source-facing payload model should be an object-list packet/event payload:

```cpp
const unsigned char *payload = event->payload;
if (payload[0] != '_')
    return false;

const unsigned char count = payload[1];
for (unsigned char i = 0; i < count; ++i) {
    const unsigned int objectId =
        PacketBufferReadUInt32BE(payload + 2 + i * 4);
    ...
}
```

The exact event class name is not recovered, but sibling source drafts already use `PacketEvent *event`. That is adequate first-draft naming for the formal block.

### Saved Target, Fallback, and Highlight Behavior

The branch condition is equality with the saved select-object target id:

- It decodes one payload object id.
- It compares the decoded id against `unk_69BF28` / `dword_69BF28`.
- On equality, it calls the active map lookup helper with `dword_67A764` and the saved id.
- It loads `dword_67A748`, reads offset `0xfc`, and writes that value back into `dword_69BF28`.
- It calls `sub_53B1B0(oldTarget, 0)`.
- It calls `sub_53B1B0(localPlayer, 1)`.
- It returns false/zero.

`int_convert` verifies `0x0c` as decimal 12 for the payload pointer offset and `0xfc` as decimal 252 for the local-player object-id field offset.

This is not evidence for the older "saved target disappeared from the active-object list" wording. The only local branch in this body fires when the decoded payload contains the saved id. The upstream protocol may still be a removal/invalidation/object-list message, but the function-local proof is "payload entry matches current saved select-object target id, so select falls back to local player."

### Helper and Global Names

Recommended source-facing names:

- `dword_69BF28`: `s_selectObjectTargetId`, with `s_selectObjectSavedTargetId` acceptable as an explanatory alias in prose.
- `dword_67A764`: `g_activeMapPane`.
- `dword_67A748`: `g_pUserPane` / local player source. Existing source drafts use `g_pUserPane->GetLocalPlayerObject()`.
- `sub_5754C0`: `PacketBufferReadUInt32BE`.
- `sub_506970`: `MapPane::FindObjectPaneById`.
- `sub_53B1B0`: `LivingObjectPane::SetTargetHighlight`.
- `0x00575470`: character traits byte load, not project logic.

These names match current support docs and the accepted sibling object-list source shape. The raw names should not remain in the first-draft C++ except in evidence prose.

### Sibling Parity

Two sibling object-list handlers prove this target is not a special no-code case:

- `0x005af2f0` (`ItemWhoInputPaneObjectListVirtual`) has the same object-list/payload-loop family shape, uses `unk_69BF24`, and has a formal first-draft source body.
- `0x005b0510` (`TargetObjectWithKeyboardPaneObjectListHelper`) has the same size and helper set, uses `unk_69BF2C`, has vtable data ref `0x0062f414`, and already has a formal first-draft `TargetObjectWithKeyboardPane::OnObjectList` method.

UID0001LF is the select-object sibling of the target-object object-list method. Its blank formal C++ block is inconsistent with sibling treatment and current evidence.

## Negative Evidence

- No direct code caller was found for `0x005afc90`. This is expected for a vtable-only virtual and is not a no-code reason.
- No string literals or resource literals are present in the body.
- No direct evidence recovers the exact original source method name. `OnObjectList` is the best source-facing first-draft name by sibling parity, while the target doc should record that the exact original name remains unresolved.
- No current evidence supports moving ownership to `MapPane`, `LivingObjectPane`, `PacketBuffer`, `UserPane`, or a no-owner bucket. Those components are dependencies, not the method owner.
- No evidence supports a split inside `0x005afc90-0x005afd23`; the padding before and after the function confirms the current boundaries.
- No null guard appears in the binary before `oldTarget->SetTargetHighlight(false)` or `localPlayer->SetTargetHighlight(true)`. The first-draft C++ should not invent one for this method.
- No target-specific no-code proof remains after current MCP confirmation. The blank formal C++ block is the source-quality defect.

## Heuristic and Source-Quality Reanalysis

The earlier blank state was defensible while the object-list protocol and branch meaning were still under review. It is no longer defensible as a report-level recommendation.

Code-entry gate result:

- `RECONSTRUCTABLE:TRUE` is already present.
- `EMITTER_UIDS:0000CT` is nonblank and routes to the `TargetSelectionInputPanes` source family.
- Current score average is `(86 + 90) / 2 = 88`, already above the greater-than-85 gate.
- Current evidence improves source readiness rather than reducing it.

The correct repair is a formal first-draft C++ block and a small completion increase to `88`, not a no-code exemption. Confidence should remain `90`, not higher, because the exact source method name and exact packet-event type name are inferred by sibling/source-family convention rather than recovered from symbols.

## Ranked Ownership and Source Placement

1. `0000CT` / `SelectObjectWithKeyboardPane`: primary owner. The target is installed in the SelectObjectWithKeyboardPane vtable at `0x0062f388`, uses the select-object saved-target global `dword_69BF28`, and is grouped with SelectObject constructor/destructor/input handlers.
2. `0000OH` / `TargetSelectionInputPanes` source family: file/source route. The class belongs in the target-selection input panes source file, and generated output already routes UID0001LF there.
3. `MapPane`: dependency only. It supplies lookup by object id through `g_activeMapPane`, but does not own this virtual.
4. `UserPane` / local-player pane: dependency only. It supplies the fallback local player and local id at offset `0xfc`.
5. `LivingObjectPane`: dependency only. It supplies target-highlight toggling.
6. `PacketBuffer` / packet read helper: dependency only. It decodes four-byte ids.
7. No-owner/non-emitting: rejected. Vtable owner, route, generated file, and coverage row are all present.

## Formal C++ Recommendation

Insert the following exact formal `RECONSTRUCTION_CPP CODE` content for UID0001LF:

```cpp
bool SelectObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;
    if (payload[0] != '_')
        return false;

    const unsigned char count = payload[1];
    for (unsigned char i = 0; i < count; ++i) {
        const unsigned int objectId =
            PacketBufferReadUInt32BE(payload + 2 + i * 4);

        if (objectId == s_selectObjectTargetId) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
            LivingObjectPane *localPlayer = g_pUserPane->GetLocalPlayerObject();

            s_selectObjectTargetId = localPlayer->GetObjectId();
            oldTarget->SetTargetHighlight(false);
            localPlayer->SetTargetHighlight(true);
            break;
        }
    }

    return false;
}
```

Notes for incorporation:

- This is intentionally parallel to the accepted `TargetObjectWithKeyboardPane::OnObjectList` first-draft body.
- Do not add a null check unless a later target proves one exists in source; the binary does not contain one here.
- Keep a prose caveat that `OnObjectList` and `PacketEvent` are source-facing first-draft names, not recovered original symbols.
- Keep a prose caveat that the payload protocol's upstream meaning remains unresolved; the function-local branch condition is equality with the current saved target id.

## Recommended Target Doc Changes

For `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md`:

- Raise `COMPLETION` to `88`; keep `CONFIDENCE:90`.
- Keep owner/emitter/reconstructable metadata unchanged.
- Replace the blank formal C++ block with the exact `SelectObjectWithKeyboardPane::OnObjectList` block above.
- Add current MCP session `c9671f69` evidence for range, size, vtable slot, no direct callers, vtable-only route, decoded payload layout, global reads/writes, helper calls, and padding.
- Correct or constrain any stale "target disappeared from active-object list" wording. The local proof is that fallback occurs when a decoded payload id equals `s_selectObjectTargetId`.
- Record that generated empty-emitter output is caused by blank formal C++ even though generated coverage routes the target as emitting.
- Add sibling parity with UID00036R (`TargetObjectWithKeyboardPane::OnObjectList`) and UID0001L6 (`ItemWhoInputPane` object-list virtual).

## Recommended Support Doc Changes

For `by-class/SelectObjectWithKeyboardPane.md`:

- Update the UID0001LF row/evidence to say the object-list virtual is source-ready as `bool SelectObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)`.
- Preserve the existing correction that fallback is triggered by a decoded payload id matching `s_selectObjectTargetId`, not by a locally proven absence test.
- Add or confirm source-facing names `s_selectObjectTargetId`, `g_activeMapPane`, `g_pUserPane`, `PacketBufferReadUInt32BE`, `FindObjectPaneById`, and `SetTargetHighlight`.

For `by-file/TargetSelectionInputPanes.md`:

- Add a B009 sync note that UID0001LF should emit formal first-draft C++ through the SelectObjectWithKeyboardPane route.
- Record the generated empty marker cause: generated C++ currently shows an empty marker because UID0001LF's formal C++ block is blank, while coverage already routes it as emitting.
- Include the current score recommendation `88/90` and no owner/emitter change.

For `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`:

- Add UID0001LF evidence for `dword_69BF28`: this method reads the saved select-object target id during payload comparison and overwrites it with the local-player object id from `g_pUserPane` offset `0xfc` on match.
- Keep `s_selectObjectTargetId` as the preferred source name; mention `s_selectObjectSavedTargetId` only as a clarifying alias if needed.

For `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`:

- No required edit was identified for this callback unless the supervisor wants a class-route cross-reference. The existing singleton-slot doc is sufficient for UID0001LF's source route.

For direct map/user/highlight helper support docs:

- No mandatory support edit was identified. Existing docs already provide the needed source-facing names and roles. Only edit them if the supervisor wants cross-reference enrichment during callback.

## Claim And Incorporation Ledger

| ID | Claim | Evidence / Proof | Incorporation Target |
| --- | --- | --- | --- |
| C01 | UID0001LF exact range remains `0x005afc90-0x005afd23`, size `0x93` / 147. | MCP `lookup_funcs`, `get_bytes`, `int_convert 0x93`. | Target doc evidence/range sections. |
| C02 | Three `int3` bytes precede the target and thirteen `int3` bytes follow before `0x005afd30`. | MCP `get_bytes`; `int_convert 0x0d`. | Target doc padding/range evidence. |
| C03 | Function pointer appears in vtable slot `0x0062f388`, with unique pointer bytes `90 FC 5A 00`. | MCP `xrefs_to`, `find_bytes`, `get_int` on `0x0062f378` block. | Target doc and class doc vtable evidence. |
| C04 | No direct code callers were found; vtable-only reachability is expected. | MCP `analyze_function` callers empty; `xrefs_to 0x005afc90` only data xref. | Target doc caller/reachability evidence. |
| C05 | Payload pointer is read from event argument offset `+0x0c`; first byte must be `_`; count is at payload `+1`; entries start at `+2` and stride by 4. | MCP `decompile`, `disasm`, `int_convert 0x0c`, `0x5f`, `0x04`. | Target doc behavior and C++ block. |
| C06 | Each payload entry is decoded by `sub_5754C0`, source-facing `PacketBufferReadUInt32BE`. | MCP callees/disassembly; sibling docs and B004 report. | Target doc, class doc, C++ block. |
| C07 | Match condition is decoded `objectId == dword_69BF28`; fallback then writes local-player id back to `dword_69BF28`. | MCP decompile/disasm reads/writes `unk_69BF28`, local id offset `0xfc`. | Target doc, saved-global support doc, C++ block. |
| C08 | On match, old target highlight is cleared and local-player highlight is set. | MCP calls `sub_53B1B0(v7, 0)` and `sub_53B1B0(v8, 1)`. | Target doc, class doc, C++ block. |
| C09 | Older "disappeared/absent" wording is over-specific. The function-local proof is equality with an id contained in the payload. | MCP branch condition and B004 sibling correction. | Target doc and class support correction. |
| C10 | Owner remains `0000CT`; emitter route remains `0000CT` through `TargetSelectionInputPanes`; dependencies are not owners. | Vtable slot, generated coverage route, class/file docs. | Target metadata, class/file support docs. |
| C11 | Empty generated marker is caused by blank formal C++, not missing route. | Generated C++ marker plus coverage row showing routed/emitting but coded `no`. | Target doc, file support doc. |
| C12 | Formal first-draft C++ is warranted; no target-specific no-code proof remains. | Code-entry gate, current avg score 88, MCP evidence, sibling parity. | Target metadata and formal C++ block. |
| C13 | Recommended metadata is `COMPLETION:88`, `CONFIDENCE:90`; confidence stays 90 due unresolved exact original method/event names. | Score-blocker audit and source-quality reanalysis. | Target metadata and support notes. |

Implementation callback proof, 2026-06-29:

- C01 incorporated into `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md` Evidence Notes and Changes; validator `000000000682` passed with `ok: 1`.
- C02 incorporated into the same target Evidence Notes with predecessor and successor padding details; validator `000000000682` passed with `ok: 1`.
- C03 incorporated into target Evidence Notes and `by-class/SelectObjectWithKeyboardPane.md` B009 evidence; validators `000000000682` and `000000000685` passed with `ok: 1`.
- C04 incorporated into target Evidence Notes and class support evidence as vtable-only/no-direct-caller proof; validators `000000000682` and `000000000685` passed with `ok: 1`.
- C05 incorporated into target Evidence Notes and exact formal C++ block; validator `000000000682` passed with `ok: 1`.
- C06 incorporated into target/class/file support docs and exact formal C++ block as `PacketBufferReadUInt32BE`; validators `000000000682`, `000000000685`, and `000000000687` passed with `ok: 1`.
- C07 incorporated into target doc, saved-global support doc, class/file support docs, and exact C++ block as `s_selectObjectTargetId`; validators `000000000682`, `000000000685`, `000000000687`, and `000000000689` passed with `ok: 1`.
- C08 incorporated into target/class/file support docs and exact C++ block as `LivingObjectPane::SetTargetHighlight(false/true)`; validators `000000000682`, `000000000685`, and `000000000687` passed with `ok: 1`.
- C09 incorporated into target Reconstruction Notes, class B009 evidence, and file-route B009 note with the protocol caveat; validators `000000000682`, `000000000685`, and `000000000687` passed with `ok: 1`.
- C10 incorporated into target metadata and support docs: owner/emitter remain `0000CT`, file route remains `TargetSelectionInputPanes`, and dependencies remain non-owners; validators `000000000682`, `000000000685`, and `000000000687` passed with `ok: 1`.
- C11 incorporated into target Evidence Notes and file-route B009 sync note. Generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` refreshed with header `validator-command-id: 000000000690`, `validator-refreshed-at: 2026-06-29T12:12:07-04:00`; UID0001LF emits code at lines 473-498 and no longer has an Empty Emitter Marker.
- C12 incorporated into target formal C++ block and metadata; validator `000000000682` passed with `ok: 1`.
- C13 incorporated into target metadata as `COMPLETION:88`, `CONFIDENCE:90`; validator `000000000682` passed with `ok: 1`.

## Open Questions With Attempted Resolution

- Exact original method name: unresolved. Recommended source-facing first-draft name is `OnObjectList` by direct sibling parity with `TargetObjectWithKeyboardPane::OnObjectList`.
- Exact event type name: unresolved. Recommended first-draft type is `PacketEvent`, matching sibling source drafts and the observed payload pointer at argument offset `+0x0c`.
- Upstream protocol semantics of the underscore object-list payload: unresolved. This should not block code. The local behavior is fully known: if the payload contains the saved select-object target id, the method falls back to the local player.
- Whether `s_selectObjectSavedTargetId` or `s_selectObjectTargetId` is the final static name: use `s_selectObjectTargetId` in code for parity with sibling source; mention saved-target wording in prose.

## Validation and Generated Refresh Expectations

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after editing the accepted by-* docs:

- `python .\tools\validator.py --mode file --file by-memory\0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md --apply --queue-timeout 240 --wait-generated`
  - Result: exit code 0, `command_id: 000000000682`, `command_timestamp: 2026-06-29T12:11:11-04:00`, `ok: 1`, `generated_refresh: completed`.
- `python .\tools\validator.py --mode file --file by-class\SelectObjectWithKeyboardPane.md --apply --queue-timeout 240`
  - Result: exit code 0, `command_id: 000000000685`, `command_timestamp: 2026-06-29T12:11:29-04:00`, `ok: 1`, `generated_refresh: deferred`; validator also reported pre-existing `missing_ref_uid 00035Q`.
- `python .\tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240 --wait-generated`
  - Result: exit code 0, `command_id: 000000000687`, `command_timestamp: 2026-06-29T12:11:47-04:00`, `ok: 1`, `generated_refresh: completed`.
- `python .\tools\validator.py --mode file --file by-memory\0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md --apply --queue-timeout 240`
  - Result: exit code 0, `command_id: 000000000689`, `command_timestamp: 2026-06-29T12:12:03-04:00`, `ok: 1`, `generated_refresh: deferred`.

Read-only generated output check:

- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` header after refresh: `validator-command-id: 000000000690`, `validator-refreshed-at: 2026-06-29T12:12:07-04:00`, foreground generated refresh.
- UID0001LF appears as `// UID:0001LF | by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md | Completion:88 | Confidence:90`, followed by the accepted `bool SelectObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)` body at lines 473-498.
- UID0001LF no longer appears as an Empty Emitter Marker. Other unrelated empty markers remain in the file.
- Validator-owned generated/project-level side effects were produced by the validator commands; no generated reports, generated C++, project-level generated files, tool state, manual coverage reports, IDA DB, or executed archives were manually edited.

## Implementation Tracking Checklist

- [x] Supervisor validates and accepts this report before any target/support by-* edits.
  - Proof: supervisor sent accepted implementation callback for UID0001LF.
- [x] Acquire short edit leases for the immediate callback batch only, then release them immediately after edit/validator work.
  - Proof: initial partial lease was released; full B009 lease batch succeeded for target, class, file, and saved-globals docs at `2026-06-29T16:08:41Z`, expiring `2026-06-29T16:13:41Z`; `python .\leaser.py B009 unlease` released all four with `Success`.
- [x] Update `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md` metadata to `COMPLETION:88`, `CONFIDENCE:90`, with owner/emitter unchanged.
  - Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CT`, blank optional emitter position; validator `000000000682`, exit code 0, `ok: 1`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block for `bool SelectObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)`.
  - Proof: exact accepted method inserted between target `RECONSTRUCTION_CPP CODE:BEGIN/END`; generated C++ emits the same body at lines 473-498.
- [x] Add current MCP evidence to the target doc: session `c9671f69`, exact range/size, vtable slot `0x0062f388`, unique pointer bytes, no direct callers, payload layout, globals, helper calls, highlight toggles, and padding.
  - Proof: target Evidence Notes and Changes include session `c9671f69`, range `0x005afc90-0x005afd23`, size `0x93` / 147, vtable slot `0x0062f388`, unique bytes `90 FC 5A 00`, no direct callers, payload/event layout, `dword_69BF28`, `dword_67A764`, `dword_67A748`, helper names, old/new highlight toggles, and three/thirteen `int3` padding evidence; validator `000000000682`, exit code 0, `ok: 1`.
- [x] Correct target-doc wording so the local branch condition is equality with the saved target id in the payload, not locally proven absence/disappearance.
  - Proof: target Historical Assumptions/Reconstruction Notes and support docs preserve the equality-with-payload-id caveat; validator `000000000682`, exit code 0, `ok: 1`.
- [x] Update `by-class/SelectObjectWithKeyboardPane.md` with source-ready UID0001LF method wording, source-facing names, and the same protocol caveat.
  - Proof: method table now lists `bool SelectObjectWithKeyboardPane::OnObjectList(const PacketEvent *event)`; B009 evidence names `s_selectObjectTargetId`, `g_activeMapPane`, `g_pUserPane`, `PacketBufferReadUInt32BE`, `MapPane::FindObjectPaneById`, and `LivingObjectPane::SetTargetHighlight`; validator `000000000685`, exit code 0, `ok: 1`.
- [x] Update `by-file/TargetSelectionInputPanes.md` with B009 sync note, generated empty-marker cause, source-ready C++ recommendation, and unchanged owner/emitter route.
  - Proof: B009 source-route sync note and Changes entry record UID0001LF source-ready `OnObjectList`, generated Empty Emitter Marker cause, unchanged owner/emitter `0000CT`, and dependency/non-owner disposition; validator `000000000687`, exit code 0, `ok: 1`.
- [x] Update `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md` with UID0001LF evidence for `dword_69BF28` read/overwrite and preferred name `s_selectObjectTargetId`.
  - Proof: Evidence and Changes include UID0001LF read/compare/write evidence for `dword_69BF28`, local-player fallback overwrite from `g_pUserPane + 0xfc`, and preferred name `s_selectObjectTargetId`; validator `000000000689`, exit code 0, `ok: 1`.
- [x] Confirm `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md` needs no edit, or add only a narrow class-route cross-reference if supervisor acceptance requires it.
  - Proof: read-only review found existing singleton-slot doc already sufficient for this callback; no edit was made, so no singleton validator was required.
- [x] Do not edit generated files, project-level generated reports, validator/tool state, manual `-coverage-report.md` files, IDA DB, or executed archives.
  - Proof: only four by-* docs and this B009 report were manually edited; validator-owned generated/project-level files refreshed through validator commands only.
- [x] Run scoped validator for `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md` with `--apply --queue-timeout 240 --wait-generated`.
  - Proof: command `000000000682`, timestamp `2026-06-29T12:11:11-04:00`, exit code 0, `ok: 1`, generated refresh completed.
- [x] Run scoped validator for `by-class/SelectObjectWithKeyboardPane.md` with `--apply --queue-timeout 240`.
  - Proof: command `000000000685`, timestamp `2026-06-29T12:11:29-04:00`, exit code 0, `ok: 1`; pre-existing `missing_ref_uid 00035Q` noted.
- [x] Run scoped validator for `by-file/TargetSelectionInputPanes.md` with `--apply --queue-timeout 240 --wait-generated`.
  - Proof: command `000000000687`, timestamp `2026-06-29T12:11:47-04:00`, exit code 0, `ok: 1`, generated refresh completed.
- [x] Run scoped validator for `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md` with `--apply --queue-timeout 240`.
  - Proof: command `000000000689`, timestamp `2026-06-29T12:12:03-04:00`, exit code 0, `ok: 1`.
- [x] If the singleton-slot support doc is edited, run its scoped validator too.
  - Proof: singleton-slot support doc was not edited; validator not applicable.
- [x] Inspect `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` read-only after validator refresh and prove UID0001LF no longer emits an Empty Emitter Marker.
  - Proof: generated header `validator-command-id: 000000000690`, `validator-refreshed-at: 2026-06-29T12:12:07-04:00`; UID0001LF emits accepted `OnObjectList` body at lines 473-498 and is not an Empty Emitter Marker.
- [x] Record validator command ids, timestamps, exit codes, and ok counts in this checklist after callback implementation.
  - Proof: recorded above for `000000000682`, `000000000685`, `000000000687`, and `000000000689`.
- [x] Release/confirm expiry of all callback leases immediately after the edit/validator batch.
  - Proof: `python .\leaser.py B009 unlease` returned `Success` for all four leased docs; current lease report has no B009 rows.
- [x] Report `FINISHED_IMPLEMENTATION` only after accepted callback edits, validators, generated-output checks, checklist proof updates, and lease release are complete.
  - Proof: all accepted details are applied/already-present/not-applicable with proof above; ready to return `FINISHED_IMPLEMENTATION`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001LF-SelectObjectWithKeyboardPaneObjectListVirtual-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001LF-SelectObjectWithKeyboardPaneObjectListVirtual-empty-emitter-source-quality.md","timestamp":"2026-06-29T12:16:21","uid":"0001LF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
