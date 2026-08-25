** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Current Source Routing

Assignment: `B002-goal2-ui-asset-mode-rect-virtual-dispatch-current-source-routing-0002BD-20260618`

Target: [UID:0002BD] `source-3/project-documentation/by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`

Worker: Agent-B002

Date: 2026-06-18

## Finalized Report / Current Recommendation

Keep [UID:0002BD] `0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper` as a source-shaped but unowned, non-emitting raw helper:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | keep `87` |
| `CONFIDENCE` | keep `91` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `CANONICAL_OWNER` | keep `NONE` |
| `EMITTER_UIDS` | keep blank |
| `EMITTER_POSITION_OPTIONAL` | keep blank |
| Formal C++ reconstruction | keep blank |
| Split/merge/reclassify | no split, no merge, no new child, no reclassification |
| IDA DB/generated-source edit | none |

Current evidence still does not prove a source owner or emitter route. The helper is real code and has source-like behavior, but all route-defining evidence is negative: no live function object/xref route in the accepted prior IDA passes, no fresh PE VA/RVA pointer route, no external direct branch/call route, no MapName/MiniMapButton vtable entry to the helper, no table slot, no source-output route, no singleton/global caller, and no class-private field access.

The candidate ranking for this specific helper is:

1. `no-owner/non-emitting`: accepted current disposition. The helper should remain documented as reconstructable behavior with no source emission because it clears the score portion of the gate but fails the nonblank confirmed-emitter/source-route gate.
2. `MapNamePane`: strongest rejected owner hypothesis. It has the best semantic lead because `0x00ad` matches MapName text-width evidence and the later sibling [UID:0002BF] is now MapName-owned through `this+0x220` glyph-table lifecycle evidence. That evidence does not transfer to [UID:0002BD], which does not touch the glyph table, text buffer, singleton, constructor state, or any MapName-specific vtable slot.
3. `new UI resource/layout helper grouping`: plausible future grouping only if a caller/table/source route is found, especially for [UID:0002BD] plus sibling [UID:0002BE]. It is rejected now because creating a new source grouping would invent an emitter for an otherwise orphaned helper with no caller, table, or object-file evidence.
4. `MapNameAndMiniMapButtonPanes`: rejected as an emitter. It is a non-emitting physical split index, not a source file/class owner. Its page already warns not to absorb the preceding raw helper cluster into MapNamePane or MiniMapButtonPane until caller/vtable evidence appears.
5. `MiniMapButtonPane`: rejected. It is physically near the later interleaved map UI island, but the target has no `MMAPBUT` resource evidence, no MiniMapButton constructor/destructor/paint/mouse route, no class field, and no MiniMapButton-specific vtable slot.
6. `RectBounds`: rejected as owner. [UID:0002BD] uses `InitRectBounds` as a dependency, but then dispatches into a Pane virtual. `RectBounds` is a geometry/value-type dependency, not a source owner for a Pane invalidation helper.
7. `MainMenuLoginAndAccountDialogs`: weakest rejected owner. The only relationship is left-neighbor address adjacency through [UID:00022Y] and `0xcc` padding. There is no main-menu caller, literal, singleton, resource, dialog field, or table route.

Source-facing naming recommendation: keep the neutral research name `UiAssetModeRectVirtualDispatchHelper`. If a future route proves a caller and receiver type, the behavior-level name should mention Pane invalidation and asset-mode rectangle selection, not MapName/MiniMap ownership by default. Suggested non-final alias for discussion only: `InvalidatePaneWithAssetModeRectStateRaw`. Stable type/dependency names are `Pane`, `RectBounds`, `InitRectBounds`, `Pane::InvalidateRect`, and [UID:0000SW] `g_useEpfAssets` / historical IDA alias `byte_66DA97`.

## Supporting Research

The target body is a `thiscall`-shaped raw helper at `0x00503060-0x005030bc`. The raw bytes for the function body from the current PE scan are:

```text
55 8b ec 83 ec 14 a1 24 2f 67 00 33 c5 89 45 fc 83 6d 08 01 56 8b f1 75 27 80 3d 97 da 66 00 01 8d 45 ec 6a 10 75 07 68 a6 00 00 00 eb 05 68 ad 00 00 00 6a 00 6a 00 50 e8 b3 4b fb ff 83 c4 14 8b 06 8d 4d ec 51 8b ce ff 50 20 8b 4d fc 33 cd 5e e8 79 46 0c 00 8b e5 5d c2 04 00
```

Instruction-level behavior revalidated from those bytes:

| Address | Evidence | Meaning |
| ---: | --- | --- |
| `0x00503060` | prologue, `sub esp,0x14`, security-cookie setup | raw function body with stack local storage and cookie check |
| `0x00503070` | `sub dword ptr [ebp+8],1` | decrements the single stack argument in place |
| `0x00503077` | `jnz 0x005030a0` | if original argument is not `1`, skip local rectangle initialization |
| `0x00503079` | compare `byte_66DA97` with `1` | branches on canonical `g_useEpfAssets` |
| `0x00503083-0x00503097` | pushes `0x10`, then `0x00a6` if EPF/current mode, else `0x00ad`, then `0`, `0`, and local rect pointer | builds `RectBounds(0,0,0xa6/0xad,0x10)` |
| `0x00503098` | call target resolves to `0x004b7c50` | calls [UID:00015S] `InitRectBounds` / [UID:0000N2] `RectBounds` helper |
| `0x005030a0-0x005030a8` | load `[esi]`, push local rect pointer, set `ecx=esi`, `call [eax+0x20]` | dispatches through receiver primary vtable slot `+0x20` with the local rect pointer |
| `0x005030ab-0x005030bb` | cookie check and `retn 4` | callee pops one argument |

The `g_useEpfAssets` semantics are not owner evidence. [UID:0000SW] documents the byte at `0x0066da97` as a broad startup-selected asset/layout mode byte with hundreds of consumers. Here it only selects the rectangle right edge/extent:

| `g_useEpfAssets` value | Rect initialized before dispatch when original state arg is `1` |
| ---: | --- |
| `1` | `RectBounds(0, 0, 0x00a6, 0x0010)` = right/extent `166`, bottom/extent `16` |
| not `1` | `RectBounds(0, 0, 0x00ad, 0x0010)` = right/extent `173`, bottom/extent `16` |

The constants look UI layout/text-width related, and `0x00ad` has MapName resonance through the known MapName clamp width. That is semantic support only. It does not prove MapName ownership because no direct MapName field, string, global, constructor path, vtable entry, or caller route reaches [UID:0002BD].

Fresh section-aware PE scan was run against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

PE sections used by the scan:

| Section | VA range | Raw range |
| --- | ---: | ---: |
| `.text` | `0x00401000-0x0060c600` | `0x400-0x20ba00` |
| `.rdata` | `0x0060d000-0x0066c200` | `0x20ba00-0x26ac00` |
| `.data` | `0x0066d000-0x0069ce24` | `0x26ac00-0x278400` |
| `.rsrc` | `0x0069d000-0x006b2e00` | `0x278400-0x28e200` |

VA/RVA pointer scan results for target, interiors, end, and sibling starts:

| Address | VA dword hits | RVA dword hits |
| ---: | ---: | ---: |
| `0x00503060` | `0` | `0` |
| `0x00503070` | `0` | `0` |
| `0x00503079` | `0` | `0` |
| `0x00503098` | `0` | `0` |
| `0x005030a0` | `0` | `0` |
| `0x005030a8` | `0` | `0` |
| `0x005030bc` | `0` | `0` |
| `0x005030c0` | `0` | `0` |
| `0x00503104` | `0` | `0` |
| `0x00503110` | `0` | `0` |
| `0x005031e1` | `0` | `0` |

Direct `.text` branch/call target scan:

| Target | Direct branch/call hits |
| ---: | --- |
| `0x00503060` | none |
| `0x00503070` | none |
| `0x00503079` | none |
| `0x00503098` | none |
| `0x005030a0` | one internal short branch from `0x00503077` (`75 rel8`) |
| `0x005030a8` | none |
| `0x005030bc` | none |
| `0x005030c0` | none |
| `0x00503104` | one internal short branch from sibling [UID:0002BE] at `0x005030f6` (`75 rel8`) |
| `0x00503110` | none |
| `0x005031e1` | none |

Positive controls from the same scanner found expected MapName/MiniMapButton pointer routes:

| Control target | Hit |
| ---: | --- |
| `0x00503350` MapName paint | `0x0061e5f8` in `.rdata` |
| `0x005034a0` MapName update handler | `0x0061e610` in `.rdata` |
| `0x00503650` MiniMapButton paint | `0x0061e680` in `.rdata` |
| `0x005036a0` MiniMapButton mouse handler | `0x0061e68c` in `.rdata` |
| `0x00503840` MapName scalar deleting destructor | `0x0061e5b4` in `.rdata` |
| `0x00503900` MiniMapButton scalar deleting destructor | `0x0061e63c` in `.rdata` |

The positive controls matter because the same scan would have found an ordinary vtable/table pointer to `0x00503060` if one existed in the PE image.

The `+0x20` virtual slot was rechecked. It is not a MapNamePane or MiniMapButtonPane-specific slot. Current Pane vtable documentation records primary slot `0x00621a08` (`+0x20`) as `0x00544800` `Pane::InvalidateRect`. The fresh PE dword reads agree:

| Vtable base | Slot | Value |
| ---: | ---: | ---: |
| `0x0061e5b4` MapName primary | `0x0061e5d4` (`+0x20`) | `0x00544800` |
| `0x0061e63c` MiniMapButton primary | `0x0061e65c` (`+0x20`) | `0x00544800` |
| `0x006219e8` Pane primary | `0x00621a08` (`+0x20`) | `0x00544800` |

Therefore the target's virtual call is best described as a generic inherited Pane invalidation/dirty-rect dispatch with a `RectBounds *` argument. It cannot identify a concrete owner class by itself.

Relevant current documentation relationships rechecked:

| UID/page | Current impact on [UID:0002BD] |
| --- | --- |
| [UID:00022Z] `UnreferencedUiResourceTextHelpers` | non-emitting split inventory over [UID:0002BD], [UID:0002BE], and [UID:0002BF]; not a source owner |
| [UID:0002BE] `UiAssetModeRectWriteHelper` | sibling with same `g_useEpfAssets` and `0xa6/0xad/0x10` rectangle constants; no owner/emitter route; supports a shared orphan-helper hypothesis but not a source route |
| [UID:0002BF] `WideGlyphResourceTextRendererRaw` | sibling now assigned to MapNamePane because it reads `this+0x220`, which MapNamePane constructor/destructor own as the `9X11FONT.BIN` glyph table; this field evidence is absent from [UID:0002BD] |
| [UID:0001AL] `MapNameAndMiniMapButtonPanes` | explicitly non-emitting mixed split index and explicitly warns not to absorb the preceding raw helper cluster without caller/vtable proof |
| [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane` file | provides best semantic lead through text-width and sibling glyph evidence; no direct route to [UID:0002BD] |
| [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap` file | nearby later class island; no target-specific evidence |
| [UID:00019I] `MainMenuLoginAndAccountDialogs` | left-neighbor page only; target starts after `0xcc` padding and no main-menu route exists |
| [UID:0000N2] `RectBounds` / [UID:00015S] `RectGeometryHelpers` | owns `InitRectBounds`, a dependency called by the target; not the target owner |
| [UID:0000SW] `g_useEpfAssets` | broad global dependency; not an owner |

The generated source search found no source route for `0x00503060` or `UiAssetModeRectVirtualDispatchHelper` under `source-3/simroot_v2`. References to `g_useEpfAssets` are broad and expected; they do not route this helper.

The MCP endpoint at `http://127.0.0.1:13337/mcp` was unavailable during this pass with `Unable to connect to the remote server`. This report therefore uses the accepted prior MCP/IDA findings already recorded on the target/support pages plus the fresh local PE validation above.

## Heuristic / Inference Reanalysis And Validation

Ownership and emitter routing remain separate. [UID:0002BD] has source-like behavior and a good behavior score, but it lacks a source owner and lacks a nonblank valid emitter UID. That distinction is decisive.

MapNamePane inference was revalidated and rejected as an assignment. The strongest MapName evidence is semantic: `0x00ad` matches the known MapName text clamp width, [UID:0002BF] is MapName-routed through a private `this+0x220` glyph table, and the whole raw helper cluster sits just before the MapName/MiniMapButton executable island. Against that, [UID:0002BD] has no MapName text buffer access (`this+0xf8`), no MapName resource context access (`this+0x1f8`), no MapName glyph table access (`this+0x220`), no `g_pMapNamePane` route, no MapName constructor caller, no MapName paint/update slot, and no pointer/table reference from the MapName vtable data. The `+0x20` virtual call is inherited `Pane::InvalidateRect`, shared by MapName, MiniMapButton, base Pane, and many other Pane-derived classes. MapNamePane remains the best rejected lead, not an owner.

MiniMapButtonPane inference was revalidated and rejected. Its own methods and vtable entries are visible in `.rdata`, and positive controls find them. None point to `0x00503060`. The target has no button image resource literal, mouse/input handler evidence, singleton route, constructor route, or MiniMapButton-specific field. Sharing the same inherited `+0x20` invalidation slot proves nothing about MiniMapButton ownership.

MapNameAndMiniMapButtonPanes aggregate inference was revalidated and rejected. The page is a physical mixed index for the later island, not an emitter. Assigning [UID:0002BD] to that aggregate would blur the distinction between address-neighborhood inventory and source ownership. The parent explicitly says the preceding raw helper cluster should not be absorbed into MapNamePane or MiniMapButtonPane without caller/vtable evidence.

MainMenuLoginAndAccountDialogs inference was revalidated and rejected. The only connection is address order: [UID:00022Y] ends before `0x0050305c-0x00503060` padding, then [UID:0002BD] starts at `0x00503060`. There is no direct branch/call, no pointer, no table, no main-menu literal, no dialog singleton, no constructor path, and no resource dependency connecting the target to main-menu/login/account code. Padding plus address adjacency is weaker than the MapName semantic lead and still not assignment-grade.

RectBounds inference was revalidated and rejected. The helper clearly calls `InitRectBounds`, and the rectangle constants are central to the behavior. But `RectBounds` ownership would put a Pane virtual dispatch helper into the geometry/value-type source layer. The callee dependency is already covered by [UID:00015S] and [UID:0000N2]. It does not own this caller.

New UI resource/layout helper grouping was revalidated and rejected for current source routing. A future route might group [UID:0002BD] and [UID:0002BE] as asset-mode rectangle helpers if a caller table or original source file context appears. Current evidence is not enough: there is no callsite, table pointer, object file boundary, symbol, source string, generated source output, or repeated use site. Creating a new helper grouping now would create an emitter based on behavior similarity alone. The existing parent [UID:00022Z] already covers the address inventory without pretending to be source.

No-owner/non-emitting was revalidated and remains the only defensible current routing. This accounts for the target being real code while avoiding invented source placement. The helper could be stale retained code from a removed call path, an orphaned helper retained by object-file/linker behavior, or a hidden computed-call target. The fresh PE scan rules out ordinary hidden reachability through direct calls, branch targets, VA/RVA pointers, and visible table/vtable entries. It cannot prove that no arithmetic/computed address path ever existed, but there is no affirmative evidence for such a path. The current documentation should therefore say "no proven owner/emitter route", not "impossible to execute".

The non-initializing state path remains real and unresolved. The instruction at `0x00503070` decrements the stack argument, and the branch at `0x00503077` skips `InitRectBounds` whenever the original argument is not `1`. The function still pushes the local rectangle address into `Pane::InvalidateRect`. Since no caller is known, there is no proof whether all real calls passed `1`, whether the non-`1` path was unreachable by contract, whether a surrounding caller initialized compatible stack contents, or whether this is stale/unexercised code. This uncertainty is another reason to avoid formal C++ emission: a source-level `if`, `switch`, or parameter name would overstate the state semantics.

Rectangle extent semantics are best phrased as right/bottom coordinates or extents, not resource IDs. With left/top both zero, `0x00a6` and `0x00ad` may also read as widths in an exclusive/right-edge rectangle convention, but the stable observation is the exact call to `InitRectBounds(local,0,0,0xa6 or 0xad,0x10)`.

The vtable slot `+0x20` question is now stronger than in earlier target notes: it is documented as `Pane::InvalidateRect` in the base Pane vtable and freshly observed as the same target in MapNamePane and MiniMapButtonPane primary vtables. That resolves the slot identity but weakens class ownership, because the slot is inherited/shared rather than class-specific.

## First-Draft C++ Recommendation or exact do-not-populate proof

Do not populate formal C++ for [UID:0002BD].

Exact gate proof:

| Gate | Result |
| --- | --- |
| `RECONSTRUCTABLE:TRUE` | passes |
| Average score `(COMPLETION + CONFIDENCE) / 2` | `(87 + 91) / 2 = 89`, passes the score portion of the current gate |
| One or more confirmed nonblank `EMITTER_UIDS` | fails; current `EMITTER_UIDS` is blank |
| Valid generated source route | fails; no source file/class/global route is proven |
| Source-level signature and state contract | fails; no caller proves receiver type, helper name, parameter meaning, or whether non-`1` state is reachable |

Because the nonblank emitter/source-route gate fails, no C++ body should be added even though the behavior is well understood. Any formal source would have to invent at least one of the following: an owning file/class, a helper function name, the receiver type beyond generic Pane-compatible behavior, a parameter name/contract for the decremented state argument, and whether the uninitialized-rect path is unreachable by design.

Keep `RECONSTRUCTION_CPP` blank. Do not add a MapNamePane helper, MiniMapButtonPane helper, RectBounds helper, StartupWindow/global helper, or new generated source file for this target based on the current evidence.

## Exact Supervisor Changes Needed including coverage row text if any

Target page metadata changes: none required. Keep [UID:0002BD] at `87/91`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++.

Generated source changes: none.

IDA DB changes: none.

Split/merge/reclassification changes: none.

Assignment/tracker changes after acceptance: normal lease completion only. No special B-agent support text is required beyond moving/recording this report according to the supervisor workflow.

Coverage/support-doc change recommended: `source-3/project-documentation/by-memory/-coverage-report.md` has a stale block at current lines `2030-2033`. It still marks parent [UID:00022Z] as `reconstructable : 82%`, marks [UID:0002BD]/[UID:0002BE]/[UID:0002BF] as `82%`, and describes [UID:0002BF] as blank-parent even though current pages and supervisor history changed those states. Because this assignment is report-only, I did not edit the file. If the supervisor updates coverage support text, replace the contiguous [UID:00022Z] block under the `0x0050305c-0x00503060` padding row and before the `0x005030bc-0x005030c0` padding row with:

```markdown
    - [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) 0x00503060-0x005031e1 | raw UI helper split inventory | UnreferencedUiResourceTextHelpers : not_reconstructable : 86% : very-strong : Non-emitting split inventory over three source-authored raw helper children; current docs classify the aggregate itself as RECONSTRUCTABLE:FALSE while child pages carry their own reconstruction and routing state. Repeated accepted IDA/MCP passes plus the 2026-06-18 B002 section-aware PE scan find no modeled function objects, no direct xrefs/known pointer routes, no VA/RVA references, no external E8/E9/0F8x/short-branch target routes, and no MapName/MiniMapButton vtable slots for `0x00503060`, `0x005030c0`, or `0x00503110`; exact padding around the children remains `0xcc`.
        - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : very-strong : B002 2026-06-18 current-source-routing recheck keeps CANONICAL_OWNER:NONE and blank EMITTER_UIDS. Source-shaped thiscall helper optionally initializes `RectBounds(0,0,0xa6/0xad,0x10)` through `InitRectBounds` when the decremented state argument is zero, then calls inherited `Pane::InvalidateRect` through vtable slot `+0x20`; the non-initializing state path remains real and caller-unproven. Fresh PE scan found no VA/RVA pointer hits for the entry/interiors/end/sibling starts, no external direct branch/call target to `0x00503060`, and no MapName/MiniMapButton class-specific vtable route, while positive controls found known MapName/MiniMap vtable routes. MapName width and sibling glyph associations remain insufficient for ownership or an emitter route.
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : very-strong : Current child page keeps CANONICAL_OWNER:NONE and blank EMITTER_UIDS. Optional EPF/legacy `RectBounds(0,0,0xa6/0xad,0x10)` write helper mirrors [UID:0002BD]'s asset-mode constants but writes a caller-supplied output rectangle and returns without a Pane dispatch; current PE evidence still finds no VA/RVA pointer hits, external direct branch/call target, vtable slot, table route, class-field evidence, or source-use route for `0x005030c0`.
        - [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) 0x00503110-0x005031e1 | raw function | WideGlyphResourceTextRendererRaw : reconstructable : 87% : very-strong : Current child page routes to [UID:00007P] MapNamePane based on private `this+0x220` 9X11 glyph-table lifecycle evidence from the MapNamePane constructor/destructor; it remains final-C++ blank pending source signature/caller proof. This MapName ownership evidence is specific to [UID:0002BF] and must not be transferred to siblings [UID:0002BD] or [UID:0002BE].
```

If the supervisor wants a shorter target-only coverage edit instead of the contiguous block, the minimum required replacement is the [UID:0002BD] row above plus a parent [UID:00022Z] status correction to `not_reconstructable : 86% : very-strong`. Replacing all four rows is cleaner because the existing sibling rows are also visibly stale support context in the same block.

No `auto-generated/-ag-memory-coverage.md` file was present in this checkout for direct verification or replacement text. This report therefore only provides exact text for the verified local support file `source-3/project-documentation/by-memory/-coverage-report.md`.

## Validation Performed / Evidence Gaps

Validation performed:

| Check | Result |
| --- | --- |
| Supervisor and Agent-B002 instructions | Read and followed; report-only constraints observed |
| Target page [UID:0002BD] | Rechecked current metadata, behavior description, open questions, and prior B-pass notes |
| Parent/sibling pages [UID:00022Z], [UID:0002BE], [UID:0002BF] | Rechecked split inventory, same-constant sibling behavior, and MapName-specific sibling evidence |
| Candidate owner pages | Rechecked MapNamePane, MiniMapButtonPane, MapNameAndMiniMapButtonPanes, MainMenuLoginAndAccountDialogs, RectBounds/RectGeometryHelpers, `g_useEpfAssets`, and MapName/MiniMap vtable data |
| Base Pane slot evidence | Rechecked `PaneVtableData`; `+0x20` is documented as `Pane::InvalidateRect` |
| Current PE pointer scan | No VA/RVA dword hits for `0x00503060`, target interiors/end, or sibling starts |
| Current PE direct control-flow scan | No external direct branch/call to `0x00503060`; only internal branches inside [UID:0002BD]/[UID:0002BE] were found for interior addresses |
| Current PE vtable/control positives | Found known MapName/MiniMapButton vtable pointers and primary `+0x20` shared `0x00544800` slots |
| Generated source search | No `0x00503060` or `UiAssetModeRectVirtualDispatchHelper` source route under `source-3/simroot_v2` |
| Coverage support check | Found stale by-memory coverage block and provided exact replacement text in this report |
| File edits | Created only this required research report |

Evidence gaps that remain after this pass:

| Gap | Impact |
| --- | --- |
| MCP endpoint unavailable during this session | No fresh live IDA xref/function query could be run by this worker; report relies on accepted prior MCP/IDA results plus fresh PE validation |
| No caller found | Cannot prove receiver concrete type, helper source name, or original state argument contract |
| No table/pointer/vtable route found | Cannot assign a source owner or emitter UID |
| Non-`1` state path unresolved | Raw code passes an uninitialized local rect address to `Pane::InvalidateRect` if original state arg is not `1`; without callers, the source-level invariant remains unknown |
| No object-file/source-map/PDB evidence | Cannot decide between stale retained helper, removed source callsite, original static helper in an unknown file, or hidden computed-call route |
| Rectangle constants remain semantic only | `0x00ad` is compatible with MapName width evidence and `0x00a6` looks like an EPF/current variant, but neither constant proves owner route |

Final evidence interpretation: [UID:0002BD] is a real raw helper with understandable behavior, but current evidence supports documentation-only reconstruction rather than source emission. The current unresolved state is not lack of behavior knowledge; it is lack of owner/emitter route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002BD-UiAssetModeRectVirtualDispatchHelper-current-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
