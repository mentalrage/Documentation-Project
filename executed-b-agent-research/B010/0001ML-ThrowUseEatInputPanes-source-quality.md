** TARGET-REPORT-UID:0001ML **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001ML] ThrowUseEatInputPanes source-quality report

Report-only pass for [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](../../../../../by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md).

## Status

- Assignment: `B010-report-0001ML-throw-use-eat-input-panes-20260625`
- Result: implementation-ready report-only research.
- IDA MCP requirement: satisfied. Live MCP was used against database session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Scope discipline: no by-* docs, generated files, project-level files, validator state/cache, lock files, IDA DB, or coverage reports were edited. No leases were taken.
- Recommendation summary: reclassify [UID:0001ML] as a non-emitting split/container aggregate with a target-specific no-code proof. Keep [UID:0000KC] `ItemActionInputPanes` as the semantic owner, blank `EMITTER_UIDS`, and move source-bearing C++ decisions to the related class pages and exact raw child pages.

## Live MCP Evidence

Live MCP health before this pass reported module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

`lookup_funcs` and `entity_query` confirm ten modeled IDA functions inside the aggregate range:

| Range | IDA function | Size | Source-facing role |
| --- | --- | ---: | --- |
| `0x005b5890-0x005b5957` | `sub_5B5890` | `0xc7` | `ThrowInputPane` constructor |
| `0x005b5960-0x005b59cc` | `sub_5B5960` | `0x6c` | `ThrowInputPane` char/key input |
| `0x005b59d0-0x005b5aac` | `sub_5B59D0` | `0xdc` | `ThrowInputPane` submit |
| `0x005b5b80-0x005b5c20` | `sub_5B5B80` | `0xa0` | `ThrowReallyInputPane` accept |
| `0x005b5ca0-0x005b5d67` | `sub_5B5CA0` | `0xc7` | `UseInputPane` constructor |
| `0x005b5d70-0x005b5ddc` | `sub_5B5D70` | `0x6c` | `UseInputPane` char/key input |
| `0x005b5de0-0x005b5e5c` | `sub_5B5DE0` | `0x7c` | `UseInputPane` submit |
| `0x005b5ec0-0x005b5f87` | `sub_5B5EC0` | `0xc7` | `EatInputPane` constructor |
| `0x005b5f90-0x005b5ffc` | `sub_5B5F90` | `0x6c` | `EatInputPane` key input |
| `0x005b6000-0x005b60c0` | `sub_5B6000` | `0xc0` | `EatInputPane` confirm |

The raw child starts remain non-IDA-modeled starts:

| Range | `lookup_funcs` result | Live instruction evidence |
| --- | --- | --- |
| `0x005b5ab0-0x005b5b2c` | `Not a function` | normal prologue, checks `g_pUserPane + 0x3ec0`, writes `0x17`, mode `0`, stack slot byte, sends 3 bytes, `retn 4` |
| `0x005b5b30-0x005b5b7e` | `Not a function` | `ThrowReallyInputPane` raw constructor, localized string id `0xa5`, base `CharInputPane` constructor, stores `[ecx+0x108]`, installs three vtables, `retn 4` |
| `0x005b5c20-0x005b5c93` | `Not a function` | thiscall-shaped raw helper, writes `0x17`, mode `1`, slot from `this+0x108`, sends 3 bytes, plain `retn` |
| `0x005b5e60-0x005b5ebe` | `Not a function` | raw helper writes opcode `0x1c`, stack slot byte, sends 2 bytes, plain `retn` |

`get_bytes` confirms every internal gap recorded by [UID:0001ML] is alignment/padding made only of `0xcc`, including `0x005b5957-0x005b5960`, `0x005b59cc-0x005b59d0`, `0x005b5aac-0x005b5ab0`, `0x005b5b2c-0x005b5b30`, `0x005b5b7e-0x005b5b80`, `0x005b5c93-0x005b5ca0`, `0x005b5d67-0x005b5d70`, `0x005b5ddc-0x005b5de0`, `0x005b5e5c-0x005b5e60`, `0x005b5ebe-0x005b5ec0`, `0x005b5f87-0x005b5f90`, and `0x005b5ffc-0x005b6000`.

`xrefs_to` confirms the dispatch split:

- `0x005b5960`, `0x005b59d0`, `0x005b5b80`, `0x005b5d70`, `0x005b5de0`, `0x005b5f90`, and `0x005b6000` are reached by vtable data references.
- `0x005b5890`, `0x005b5ca0`, and `0x005b5ec0` have no direct function-start xrefs; their class vtable stores also appear in inline allocation sites.
- `0x005b5ab0`, `0x005b5b30`, `0x005b5c20`, and `0x005b5e60` have no direct xrefs to the raw starts.
- `ThrowReallyInputPane` vtable xrefs appear at the raw constructor body and at allocation/inlining contexts `0x005a7b87/0x005a7b8d/0x005a7b97` and `0x005abae5/0x005abaeb/0x005abaf5`.

Decompilation confirms the high-level behavior:

- `ThrowInputPane::ThrowInputPane` constructs the `CharInputPane` base with a zero/empty initial argument, installs the three `ThrowInputPane` vtables, obtains local-player name text through `g_pUserPane`, formats localized string id `35`, and sets the prompt text.
- `ThrowInputPane::OnCharInput`, `UseInputPane::OnCharInput`, and `EatInputPane::OnKeyInput` share the same non-text control-key branch: on the narrow/control key combination they call the general-purpose panel helper and play sound/effect id `0x198`, otherwise they forward to the base input handler.
- `ThrowInputPane::OnSubmitInput` converts one typed letter to inventory slot `1..52`, validates against `g_activeUserStatusPane + 0x284`, checks `g_pUserPane + 0x3ec0`, and sends opcode `0x17`, mode `0`, slot, length `3`.
- `ThrowReallyInputPane::OnAccept` accepts `y` or `Y` and sends opcode `0x17`, mode `1`, slot from `this+0x108`, length `3`.
- `UseInputPane::OnSubmitInput` converts one typed letter to slot `1..52`, validates against `g_activeUserStatusPane + 0x284`, and calls [UID:0001KN][UseInventorySlotDispatch](../../../../../by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md) with `g_pUserPane` and the slot.
- `EatInputPane::OnConfirmInput` converts one typed letter to slot `1..52`, validates against `g_activeUserStatusPane + 0x284`, and sends opcode decimal `26` / `0x1a`, slot, length `2`.

## Source-Quality Decision

[UID:0001ML] should not emit C++ as a single by-memory target. The page is a broad executable island that inventories four UI classes, ten modeled methods, four raw retained child ranges, and padding. Any single reconstruction block on [UID:0001ML] would either duplicate child/class code or conflate unrelated class methods and raw helpers. That violates the by-memory source-scope rule that C++ belongs to the exact source-bearing entity.

Recommended metadata for [UID:0001ML]:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `88` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `0000KC` | `0000KC` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000KC` | blank |
| `RECONSTRUCTION_CPP CODE` | blank | blank |

No formal `RECONSTRUCTION_CPP CODE` should be inserted for [UID:0001ML]. This is a target-specific no-code proof, not a deferred-code blocker: [UID:0001ML] is an index/split container, while source-bearing work belongs to [UID:0000EY] `ThrowInputPane`, [UID:0000EZ] `ThrowReallyInputPane`, [UID:0000FG] `UseInputPane`, [UID:000047] `EatInputPane`, and the exact raw child pages [UID:0003NX], [UID:0001MM], [UID:0003NY], and [UID:0003NZ].

Update the item summary to remove the stale "blank under 95+ gate" wording and state that live 2026-06-25 IDA MCP reconfirmed the ten modeled function boundaries, four raw non-function children, exact `0xcc` padding spans, vtable-only dispatch for the input handlers, no direct xrefs to raw helper starts, and the non-emitting split/container disposition.

## Raw Helper And Ownership Findings

[UID:0003NX] `0x005b5ab0-0x005b5b2c` is still a source-authored retained raw helper with no direct xrefs. Its live behavior matches a file-scope throw packet helper under [UID:0000KC]: guard `g_pUserPane + 0x3ec0`, opcode `0x17`, mode `0`, selected slot byte, send length `3`, `retn 4`.

[UID:0001MM] `0x005b5b30-0x005b5b7e` is a `ThrowReallyInputPane` constructor body, not aggregate-owned code. Its class owner [UID:0000EZ] is correct. The active B004 report for this child should remain the primary incorporation vehicle for constructor C++; [UID:0001ML] only needs to point to it as an exact child.

[UID:0003NY] `0x005b5c20-0x005b5c93` is thiscall-shaped and reads `this+0x108`; it should be class-owned by [UID:0000EZ] rather than treated as only file-owned support. Recommended support edit: change `CANONICAL_OWNER` and `EMITTER_UIDS` from `0000KC` to `0000EZ`, or at minimum document it as a private `ThrowReallyInputPane` packet helper routed through the class. Its no-xref state is a retained-helper caveat, not a reason to attach it to the aggregate.

[UID:0003NZ] `0x005b5e60-0x005b5ebe` has a live documentation error. Current docs and [UID:0001ML] describe it as `SendEatItemPacketRaw` and say it sends opcode `0x1a`; live IDA shows `push 1Ch` at `0x005b5e7a` and a two-byte send. `EatInputPane::OnConfirmInput` at `0x005b6000` is the path that sends opcode `0x1a`. Recommended support edit: rename/re-describe [UID:0003NZ] to a neutral retained use/action slot packet helper, for example `SendUseItemSlotPacketRaw`, and update its packet layout to opcode `0x1c`, selected slot byte, length `2`. Do not continue calling it an eat helper.

## Support Doc Changes To Apply After Acceptance

1. [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](../../../../../by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
   - Set `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
   - Replace the reconstruction section with the no-code proof from this report.
   - Correct all [UID:0003NZ] mentions from opcode `0x1a`/eat helper to opcode `0x1c` retained use/action-slot helper.
   - Keep [UID:0000KC] as semantic owner and keep the exact child range table.

2. [UID:0000KC][ItemActionInputPanes](../../../../../by-file/ItemActionInputPanes.md)
   - Update the [UID:0001ML] row/notes to say the page is a non-emitting split/container, not a blank-C++ aggregate waiting on a score gate.
   - Keep the file as semantic parent for the item-action input pane family.
   - Route actual C++ work through the class docs and exact raw child pages.

3. [UID:0001XU][ItemActionInputPaneVtableFamily](../../../../../by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
   - Preserve the vtable slot facts.
   - Add that [UID:0001ML] is non-emitting and only inventories the executable island; vtable-referenced handlers are class-owned.

4. [UID:0000EY][ThrowInputPane](../../../../../by-class/ThrowInputPane.md), [UID:0000EZ][ThrowReallyInputPane](../../../../../by-class/ThrowReallyInputPane.md), [UID:0000FG][UseInputPane](../../../../../by-class/UseInputPane.md), and [UID:000047][EatInputPane](../../../../../by-class/EatInputPane.md)
   - Remove old "95/95 gate" language.
   - Add the live method facts from this report where not already present.
   - Do not point class C++ status at [UID:0001ML] as a blocker; [UID:0001ML] is only the range inventory.

5. [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](../../../../../by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md)
   - Reclassify as [UID:0000EZ] class-owned or explicitly document why the file owner is retained despite the thiscall shape.
   - Keep the opcode `0x17`, mode `1`, `this+0x108`, length `3` evidence.

6. [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](../../../../../by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md)
   - Correct the title, summary, range table, packet layout, IDA evidence, and cross-references so they no longer call the helper an eat packet helper.
   - Use opcode `0x1c` and send length `2`.
   - Cross-reference [UID:0001KN] and [UID:0001LA] only as related item/action packet context, not as proof of a direct caller.

7. Generated/report files
   - Do not hand-edit generated outputs. After accepted source docs are updated and validated, regenerate so the stale [UID:0001ML] generated row no longer shows `76/84`, `RECONSTRUCTABLE:TRUE`, or an empty code marker.

## First-Draft C++ Disposition

No first-draft C++ is recommended for [UID:0001ML] itself.

Reason: this aggregate covers multiple independent C++ entities and raw retained children. The correct implementation action is metadata/no-code reclassification plus support-doc routing. Class-method C++ and raw-helper C++ can be emitted from their class/exact child pages after supervisor acceptance without using [UID:0001ML] as an emitter.

This report does not block on raw helper reachability. The no-xref raw starts are documented as retained raw source bodies; they are separate exact children. Their reachability caveat affects the child page's function/name confidence, not [UID:0001ML]'s no-code aggregate decision.

## Implementation Callback Status

- Result: accepted changes implemented on 2026-06-25 by Agent-B010.
- Leased edit set: [UID:0001ML], [UID:0000KC], [UID:0001XU], [UID:0000EY], [UID:0000EZ], [UID:0000FG], [UID:000047], [UID:0003NY], and [UID:0003NZ].
- IDA MCP proof used: live session `80de0a67`, already recorded above and copied into the edited by-* docs.
- Generated-output policy: no manual generated/project-level/tool-state/coverage edits were made. The requested validator `--apply` runs reported `generated_refresh: deferred`; full generated regeneration was explicitly excluded because the supervisor instruction for this callback forbids generated/project-level edits outside validator operation.
- Validator caveat: scoped validators returned `ok: 1`, but the validator registry still maps [UID:0001MM] to stale target `by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md`. The edited source docs all link the repaired [UID:0001MM] target `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md`. The by-file validator also attempted unrelated `00041L`/`00041M` MidiPlayer link rewrites through stale registry data; those validator-applied rewrites were restored to the TakeOff exact child paths inside the leased file.

## Implementation Checklist

- [x] Edit [UID:0001ML] metadata to `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++. Proof: [UID:0001ML] header now has those exact values; validator `000000001700` at `2026-06-25T15:07:29-04:00` returned `ok: 1`.
- [x] Replace [UID:0001ML]'s reconstruction notes with the non-emitting split/container no-code proof. Proof: [UID:0001ML] Reconstruction Notes now state no C++ should be inserted because the range is a split/container inventory over four classes, ten modeled methods, four raw children, and padding.
- [x] Correct [UID:0001ML] references to [UID:0003NZ] so the raw helper is opcode `0x1c`, not opcode `0x1a`, and is not called an eat helper. Proof: [UID:0001ML] now links [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](../../../../../by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) and keeps `EatInputPane::OnConfirmInput` as the opcode `0x1a` path.
- [x] Update [UID:0000KC] to describe [UID:0001ML] as a non-emitting range inventory and keep class/raw children as source-bearing targets. Proof: [UID:0000KC][ItemActionInputPanes](../../../../../by-file/ItemActionInputPanes.md) now has the B010 boundary/change notes and the corrected [UID:0003NY]/[UID:0003NZ] rows; validator `000000001705` at `2026-06-25T15:08:03-04:00` returned `ok: 1`.
- [x] Update [UID:0001XU] to reflect that [UID:0001ML] does not emit code and that vtable handlers are class-owned. Proof: [UID:0001XU][ItemActionInputPaneVtableFamily](../../../../../by-type/by-vtable/ItemActionInputPaneVtableFamily.md) now has the non-emitting [UID:0001ML] reconstruction note and B010 change entry; validator `000000001710` at `2026-06-25T15:09:09-04:00` returned `ok: 1`.
- [x] Update class pages [UID:0000EY], [UID:0000EZ], [UID:0000FG], and [UID:000047] to remove stale gate wording and stop treating [UID:0001ML] as their code blocker. Proof: class pages now state [UID:0001ML] is a non-emitting range inventory; validators `000000001711`, `000000001712`, `000000001713`, and `000000001714` at `2026-06-25T15:09:16-04:00` through `2026-06-25T15:09:35-04:00` returned `ok: 1`.
- [x] Reclassify or explicitly caveat [UID:0003NY] as `ThrowReallyInputPane`-owned thiscall raw helper using `this+0x108`. Proof: [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](../../../../../by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) now has `CANONICAL_OWNER:0000EZ`, `EMITTER_UIDS:0000EZ`, and B010 evidence for opcode `0x17`, mode `1`, `this+0x108`, length `3`; validator `000000001715` at `2026-06-25T15:09:42-04:00` returned `ok: 1`.
- [x] Rename/re-describe [UID:0003NZ] away from `SendEatItemPacketRaw`; document opcode `0x1c`, slot byte, send length `2`, no direct xrefs. Proof: [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](../../../../../by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) now carries the neutral helper title and opcode `0x1c` evidence; validator `000000001716` at `2026-06-25T15:09:50-04:00` returned `ok: 1`.
- [x] Run only scoped validators required by the supervisor after the accepted edits. Proof: scoped validator command IDs `000000001700`, `000000001705`, `000000001710`, `000000001711`, `000000001712`, `000000001713`, `000000001714`, `000000001715`, and `000000001716` all returned `ok: 1`.
- [x] Regenerate generated outputs only through the project workflow after source docs validate; do not hand-edit generated rows. Proof: no manual generated regeneration was run. Full generation remains excluded for this callback; each validator reported `generated_refresh: deferred`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0001ML-ThrowUseEatInputPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0001ML-ThrowUseEatInputPanes-source-quality.md","timestamp":"2026-06-25T16:19:17","uid":"0001ML"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
