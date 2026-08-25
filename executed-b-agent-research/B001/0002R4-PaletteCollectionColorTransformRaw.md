** TARGET-REPORT-UID:0002R4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002R4 PaletteCollectionColorTransformRaw Ownership Research

Revision: B001-046 final, 2026-06-11

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0002R4] `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md`.
- Final ownership recommendation: attach [UID:0002R4] to existing [UID:0000MA] `by-file/Palette.md` / `NexusTK/render/Palette.cpp`.
- Recommendation class: source-authored retained/dormant palette transform helper. This is a source-ownership recommendation, not proof that the helper is live-reachable in the current binary.
- Parent metadata recommendation: set `AUTOGEN_PARENT_UID:0000MA`; leave `AUTOGEN_PARENT_POSITION_OPTIONAL` blank; leave final C++ blank.
- Score recommendation: keep the target at `85/88` unless the target page is updated with this report's extra raw-sibling evidence, in which case `86/88` or `86/89` is defensible. Do not raise to final-code quality because the entrypoint still has no caller, no IDA function object, and no source-facing type names.
- Confidence: `93/100` for exact bytes/body/boundary; `88/100` for Palette source-family ownership; `40/100` for live reachability. The owner confidence crosses the action threshold because exhaustive reference scans found no competing dispatch/table/source-owner path, while live IDA proves this body is a collection-level sibling of both an unmodeled single-palette transform at `0x00542d90` and the live `PaletteLib::UpdatePaletteFilterTables` transform loops at `0x00543f80`.
- New file/split recommendation: do not create a standalone `PaletteTransformHelpers.cpp`. If the supervisor wants a narrower documentation parent later, create a Palette-owned helper grouping under `Palette.cpp` / possible `PaletteLib.cpp`, not an independent source file. Likely contents: raw `0x00542d90-0x00542de3` single-palette color transform, [UID:0002R4] `0x00543670-0x005436f4` collection transform, existing [UID:0001E9] `0x00543f80` live filter-table transform logic, and adjacent clone/move helpers [UID:0001E7].
- Scope note: I did not create the `0x00542d00` / `0x00542d90` helper pages because they are outside this assigned target and would require separate by-memory leases. Their exact IDA evidence is included below as a supervisor follow-up because current DLPalette documentation/coverage appears to treat that area as padding even though it contains real raw helper bodies.

## Supervisor Actions

1. Update [UID:0002R4] target metadata:

```text
*** AUTOGEN_PARENT_UID:0000MA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace the target page's "Corrected Assignment Gate" paragraph with:

```text
This helper should attach to [UID:0000MA][Palette](by-file/Palette.md). The child is `85/88` and the direct parent is `90/86`, so both sides clear the corrected `85/85` gate. Live IDA still finds no function object, no direct caller, no absolute/RVA pointer, and no relative call/jump to `0x00543670`; therefore this assignment does not claim live reachability. The source-owner inference now rests on the stronger Palette source-island evidence: the raw body is bounded by Palette-family padding, uses the same `dword_69B408` / `32.0f` / `0.5f` / `+0x2e` / 255-entry transform kernel as raw `0x00542d90` and live `PaletteLib::UpdatePaletteFilterTables` at `0x00543f80`, and no ScreenPane, Surface, callback-table, vtable, EH, pointer-table, or alternate source owner path was found. Treat it as a retained/dormant file-static Palette helper until a caller is recovered.
```

3. Replace the current [UID:0002R4] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0002R4][0x00543670-0x005436f4.PaletteCollectionColorTransformRaw](by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md) 0x00543670-0x005436f4 | raw-function | PaletteCollectionColorTransformRaw : reconstructable : 85% : strong : B001-046 live IDA ownership research reconfirms raw non-IDA-modeled helper bounds, no xrefs/callers, no direct `E8`/`E9` relative calls, no absolute VA/RVA/immediate entry-address uses, exact surrounding `0xcc` padding, `0xff`/255 palette-entry loop, `+0x2e`/46 native-color table offset, `32.0f` and `0.5f` strength constants, `dword_69B408` callback call, destination writes, and `retn 0x0c`. Source owner is now inferred as [UID:0000MA][Palette](by-file/Palette.md) because the body is the collection-level sibling of raw `0x00542d90` and live `0x00543f80` PaletteLib transform loops; assignment to Palette is source-family ownership only and does not prove live reachability.
```

4. Separate follow-up, not required before assigning [UID:0002R4]: audit/split the currently hidden raw helper bodies in the `0x00542cf3-0x00542df0` DLPalette gap. Exact proposed split text:

```text
0x00542cf3-0x00542d00 | padding | FreePaletteData to raw DLPalette copy helper alignment | Confirmed `0xcc`.
0x00542d00-0x00542d81 | raw-function | DLPaletteRawCopyHelper candidate | Copies DLPalette header/remap/native table from source object to destination object, including optional remap allocation and `_memmove`; no xrefs or pointer hits found.
0x00542d81-0x00542d90 | padding | raw copy helper to single-palette transform helper alignment | Confirmed `0xcc`.
0x00542d90-0x00542de3 | raw-function | DLPaletteColorTransformRaw candidate | Transforms one destination DLPalette's 255 native entries from a source palette through `dword_69B408` using `(weight * 32.0f) + 0.5f`; no xrefs or pointer hits found.
0x00542de3-0x00542df0 | padding | raw transform helper to DLPalette::LoadFromFile alignment | Confirmed `0xcc`.
```

## Supporting Research

## Target Summary

`0x00543670-0x005436f4` is a raw function-shaped body between palette helper padding and `PaletteLib::PaletteLib`. It accepts two collection-like objects plus a float weight. It exits if the first collection count at `+0x0c` is non-positive, derives an 8-bit strength from `(weight * 32.0f) + 0.5f`, retrieves paired items through each collection's vtable slot `+0x10`, then transforms 255 16-bit native color entries at item offset `+0x2e` through the `dword_69B408` callback and writes the destination table.

Existing documentation already made the likely source-family call as Palette but left the parent blank because caller/liveness was missing. This pass rechecked the direct evidence and broadened the search to raw sibling helpers, PE-level references, callback dispatch, ScreenPane paths, Surface callback initialization, and source-metadata breadcrumbs.

## Live IDA Evidence

IDA identity:

- IDB input: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Segments: `.text 0x00401000-0x0060d000`, `.idata 0x0060d000-0x0060d670`, `.rdata 0x0060d670-0x0066d000`, `.data 0x0066d000-0x0069d000`.

Target body and boundaries:

- `lookup_funcs` reports `0x00543670`, `0x00543680`, `0x005436c8`, `0x005436f1`, and `0x005436f4` as `Not a function`.
- The preceding IDA function is `sub_5435B0`, `0x005435b0-0x00543665`.
- The next IDA function is `sub_543700`, `0x00543700-0x00543ae2`.
- Bytes `0x00543665-0x00543670` are eleven `0xcc` bytes.
- Bytes `0x005436f4-0x00543700` are twelve `0xcc` bytes.
- The target bytes begin `55 8b ec 51 ...` and end with `5f 5b 5e 8b e5 5d c2 0c 00`, a complete `retn 0x0c`.

Key raw disassembly:

```asm
0x00543670  push    ebp
0x00543674  mov     ecx, [ebp+8]
0x0054367d  cmp     [ecx+0Ch], esi
0x00543680  jle     short loc_5436ED
0x00543682  movss   xmm0, dword ptr [ebp+10h]
0x00543687  mulss   xmm0, ds:dword_6104CC
0x00543691  addss   xmm0, ds:dword_6104B0
0x00543699  cvttss2si eax, xmm0
0x005436a3  call    dword ptr [eax+10h]
0x005436ae  call    dword ptr [eax+10h]
0x005436b1  mov     edi, 0FFh
0x005436ba  lea     esi, [eax+2Eh]
0x005436c8  call    dword_69B408
0x005436d1  mov     [esi], ax
0x005436e6  cmp     esi, [ecx+0Ch]
0x005436f1  retn    0Ch
```

Reference/liveness scan results:

- `xrefs_to(0x00543670)` is empty.
- `callers(0x00543670)` is empty.
- Internal xrefs only: `0x0054367d -> 0x00543680`, `0x005436c7 -> 0x005436c8`, and `0x005436f0 -> 0x005436f1`.
- Full loaded-segment byte scan found zero occurrences of the absolute VA bytes for `0x00543670`.
- Full loaded-segment byte scan found zero occurrences of the RVA bytes for `0x00143670`.
- `.text` scan found zero `E8` or `E9` rel32 instructions targeting `0x00543670`.
- Instruction operand scan found no decoded operand equal to `0x00543670` or `0x00143670`.

Callback/global evidence:

- `xrefs_to(0x0069b408)` returns exactly eight direct references: `0x00542dc8`, `0x005436c8`, `0x00543fdd`, `0x00544020`, `0x005440a8`, `0x00558780`, `0x00558bd0`, and `0x00558eec`.
- The target's callback call at `0x005436c8` is one of three Palette-family transform call clusters, plus Surface initializer writes.
- `dword_69B408` is initialized by Surface render setup, not by Palette. IDA disassembly shows raw `0x00558780` writes `dword_69B408 = sub_4BEDE0`, modeled `0x00558bd0` writes the compat target, and modeled `0x00558eec` writes the RGB565 target.
- This makes Surface the declaration owner for the callback table, not a source owner for the target helper.

Source metadata breadcrumbs:

- IDA string scan found no `RSDS`, `NB10`, `.pdb`, `.cpp`, or `.cxx` strings.
- It found RTTI/resource strings for `PaletteLib`, `DLPalette`, `ScreenPane`, and `IntAlphaSurface`, but no compilation-unit/source-path strings.
- Therefore the report does not claim recovered original source-file proof from debug metadata.

## Transform-Family Evidence

The strongest new evidence is that [UID:0002R4] is not an isolated one-off. IDA shows three Palette-family transform forms using the same constants, callback, native-color offset, and 255-entry loop.

### Raw single-palette transform at `0x00542d90`

Current DLPalette docs treat `0x00542cf3-0x00542df0` as alignment before `DLPalette::LoadFromFile`, but live IDA disassembly proves real raw helper bodies there.

`0x00542d90-0x00542de3`:

- Begins `push ebp; mov ebp, esp`.
- Takes a destination palette through `ecx`, a source/base pointer at `[ebp+8]`, and a float at `[ebp+0x0c]`.
- Computes `(weight * dword_6104CC) + dword_6104B0`, where `dword_6104CC` is `32.0f` and `dword_6104B0` is `0.5f`.
- Uses `lea esi, [ecx+0x2e]`, subtracts destination base from source base, loops `0xff` entries, calls `dword_69B408`, and stores each transformed word to the destination.
- Ends with `retn 8` at `0x00542de0-0x00542de2`; padding starts at `0x00542de3`.
- It has no xrefs, no absolute/RVA pointer hits, and no rel32 call hits, matching [UID:0002R4]'s dormant/raw-helper status.

This is essentially the single-`DLPalette` form of [UID:0002R4]'s collection-pair transform.

### Live PaletteLib transform loops at `0x00543f80`

IDA decompilation of `sub_543F80` shows a live `PaletteLib` method:

- Callers load `dword_67A7E0` / `g_pPaletteLib` into `ecx` before calling:
  - `0x0050958a` then `call sub_543F80` at `0x00509595`.
  - `0x0050a90d` then `call sub_543F80` at `0x0050a918`.
- It caches the float at object offset `+0x75c` and returns early if unchanged.
- It transforms base/super palette entries through `dword_69B408`.
- It walks 25 runtime slot lists, skips slot `11`, uses each list's count at `+0x0c`, retrieves source/destination items through vtable slot `+0x10`, walks 255 entries from offset `+0x2e`, and calls `dword_69B408`.

This live method contains the in-method version of the exact collection-pair loop that [UID:0002R4] implements as a standalone helper.

### Adjacent live reset/move helpers

`ScreenPanePaletteState_543D30::ResetSlots` at `0x00543ee0` is live and has direct callers through `g_pPaletteLib`. It calls `0x00542fa0` and `0x005435b0`, but not [UID:0002R4].

Representative IDA snippets:

- `0x00556dc9 mov ecx, edi; 0x00556dcb call sub_543D30; 0x00556dd2 call sub_543EE0`
- Raw redraw path `0x005593b1 mov esi, dword_67A7E0; 0x005593c0 call sub_543D30; 0x005593c7 call sub_543EE0`

This proves ScreenPane is a consumer trigger for palette reset work, but it does not route to [UID:0002R4].

## Documentation Evidence Checked

Existing docs treated as leads and checked against IDA:

- [UID:0000MA] `Palette` is `90/86`, proposes `NexusTK/render/Palette.cpp`, and already includes DLPalette, PaletteLib, screen-palette facet, entry-move helpers, palette-filter helpers, and the raw transform candidate in its source inventory. Live IDA supports this source-family grouping.
- [UID:0000MB] `PaletteLib` is `88/85` and could mechanically serve as a narrower parent, but the target has no confirmed `this == g_pPaletteLib` caller/context. Palette remains the safer direct parent for an orphan file-static helper.
- [UID:0001E9] `PaletteLibPaletteFilterHelpers` documents the live `0x00543f80` transform method. IDA confirms its live callers and transform loops.
- [UID:0000NC] `ScreenPanePaletteState` and [UID:0001E8] document `SetMode`/`ResetSlots` as `g_pPaletteLib` calls. IDA confirms this, but those helpers do not call [UID:0002R4].
- [UID:0000TN] `SurfaceRenderCallbackTable` and [UID:0000OC] `Surface` own `dword_69B408` initialization/targets. IDA confirms the table writes, but this is callback-provider evidence, not target source ownership.
- Current `by-memory/-coverage-report.md` row for [UID:0002R4] accurately records no direct caller/liveness; it should now be updated to distinguish source ownership from live reachability.

## Ranked Ownership Analysis

### 1. Existing [UID:0000MA] `Palette` / `NexusTK/render/Palette.cpp`

Recommendation rank: accepted, final recommended parent.

Evidence for:

- The target is physically embedded inside the contiguous Palette/DLPalette/PaletteLib code island, after [UID:0001E7] and before `PaletteLib::PaletteLib`, with `0xcc` padding on both sides.
- The body uses only palette-specific state: collection count `+0x0c`, collection vtable slot `+0x10`, palette native table `+0x2e`, 255-entry loops, and the color-transform callback used by PaletteLib filter code.
- Live IDA identifies a raw single-palette transform sibling at `0x00542d90` with the same constants/callback/table-offset shape.
- Live `0x00543f80` contains the same collection-pair loop inside an actively called `PaletteLib` filter-table rebuild method.
- No bytes, xrefs, pointer tables, vtables, EH metadata, relative calls, or decoded operands point to any non-Palette owner or dispatch path.
- Existing `Palette.md` is explicitly the umbrella for DLPalette, PaletteLib, screen-palette facet, clone/move helpers, and raw lower-only helpers; it clears the strict parent gate at `90/86`.

Evidence against:

- No direct caller or entrypoint reference proves live reachability.
- No source metadata recovers the literal original source file name.
- Final original split between `Palette.cpp`, `PaletteLib.cpp`, and `DLPalette.cpp` remains unresolved.

Conclusion: best owner. Attach as Palette source-family retained/dormant helper, not as proven live code.

Confidence: `88/100`.

### 2. Existing [UID:0000MB] `PaletteLib` / possible `PaletteLib.cpp`

Recommendation rank: plausible secondary, not preferred direct parent.

Evidence for:

- The live `0x00543f80` method is definitely `PaletteLib` behavior and contains the same collection-pair transform loop.
- The target sits immediately before `PaletteLib::PaletteLib`.
- `PaletteLib` clears the strict gate at `88/85`.

Evidence against:

- The target does not load or use `g_pPaletteLib`, has no `this` context, and has no caller to prove it was a `PaletteLib` method/helper.
- Existing project convention puts unresolved lower-only palette helpers under the broader [UID:0000MA] `Palette` umbrella when the exact `Palette.cpp` versus `PaletteLib.cpp` split is not proven.
- Assigning directly to `PaletteLib` would imply a narrower source split than IDA currently proves.

Conclusion: keep as likely sub-scope within Palette, not direct parent.

Confidence: `78/100`.

### 3. `DLPalette` class/file

Recommendation rank: contextual sibling, rejected as direct parent.

Evidence for:

- Raw `0x00542d90` is a single-`DLPalette` transform sibling.
- The target transforms objects with native 16-bit tables and `+0x2e` offsets close to the DLPalette layout.

Evidence against:

- [UID:0002R4] operates on two collection-like objects and calls collection vtable slot `+0x10`; it is not a method on one `DLPalette`.
- The active collection transform in `0x00543f80` is `PaletteLib` filter-table behavior, not a DLPalette class method.
- [UID:00003Z] `DLPalette` remains a class parent, not the right file-level owner for a free collection helper.

Conclusion: sibling evidence only.

Confidence: `55/100`.

### 4. Existing [UID:0000NC] `ScreenPanePaletteState` / ScreenPane

Recommendation rank: rejected.

Evidence for:

- ScreenPane paths trigger palette-state refresh through `g_pPaletteLib`.
- `ResetSlots` calls the adjacent `0x005435b0` collection move helper.

Evidence against:

- IDA callers for `ResetSlots` call `0x00542fa0` and `0x005435b0`, not `0x00543670`.
- The target has no `g_pScreenPane`, ScreenPane object, active pane, redraw, or UI state refs.
- Existing docs already corrected ScreenPanePaletteState into a PaletteLib-resident facet, not a ScreenPane source owner.

Conclusion: ScreenPane is a trigger/consumer for other palette helpers, not the target owner.

Confidence: `20/100`.

### 5. Existing [UID:0000OC] `Surface` / [UID:0000TN] `SurfaceRenderCallbackTable`

Recommendation rank: rejected as target owner; accepted as callback provider.

Evidence for:

- Surface setup initializes `dword_69B408` to `sub_4BEDE0` or `sub_4C4730`.
- The transform callback implementations are Surface/render callback-table children.

Evidence against:

- [UID:0002R4] consumes `dword_69B408`; it does not initialize or declare the callback table.
- The helper's list/palette object semantics are PaletteLib/Palette semantics, not generic Surface presentation/blit behavior.
- Surface docs correctly own the callback table but do not own every caller that uses a callback slot.

Conclusion: dependency only.

Confidence: `18/100`.

### 6. New standalone `PaletteTransformHelpers.cpp` or `RenderPaletteTransform.cpp`

Recommendation rank: rejected as a source-file recommendation; acceptable only as a documentation helper grouping under Palette if the supervisor wants a narrower gate.

Evidence for:

- There is a recognizable transform-helper family: raw `0x00542d90`, raw `0x00543670`, and live `0x00543f80`.

Evidence against:

- No source metadata, string, table, object-file boundary, or independent caller cluster suggests a separate compilation unit.
- The helpers are embedded among DLPalette/PaletteLib functions and use PaletteLib state/layout.
- Creating a new top-level source file would overstate current evidence and duplicate the existing Palette umbrella.

Conclusion: do not create a standalone source file. Use [UID:0000MA] now; optionally make a Palette-owned helper subdocument later.

Confidence: `35/100` as a source file, `82/100` as a documentation grouping.

### 7. Leave owner unresolved

Recommendation rank: rejected as the final outcome.

Evidence for:

- Direct live-caller proof remains absent.
- The entrypoint is raw and not an IDA function.

Evidence against:

- Exhaustive reference scans found no alternate owner path.
- The target's exact transform kernel is repeated in nearby raw and live Palette-family code.
- Existing project patterns already allow source-family assignment for source-authored retained helpers when liveness is absent but source ownership is otherwise strong.
- Keeping the parent blank now conflates two different facts: live reachability is unknown, but source family is strongly inferred.

Conclusion: parent blank is no longer the best available inference. Attach to Palette with a liveness caveat.

Confidence: `72/100` that unresolved would be overly conservative.

## Low-Confidence Facts

- Literal original helper name: unknown.
- Exact original source split: unresolved between one broad `Palette.cpp` and a smaller `PaletteLib.cpp` / `DLPalette.cpp` pair. The recommended direct parent uses the broad existing Palette page because it is the proven source-family owner.
- Liveness: unresolved. No caller, pointer, rel32, RVA, absolute address, or decoded operand reference to `0x00543670` was found.
- Type names: the collection wrapper and palette item types are not final-source quality.
- IDA function modeling: the target is raw function-shaped code, not an IDA function object.

## Validation / Scope Notes

- Read B001 instructions, current leases, inference guidance, by-structure guidance, target page, Palette/DLPalette/PaletteLib/ScreenPane/ScreenPanePaletteState/Surface callback docs, and current coverage rows.
- Used live IDA MCP read-only evidence only; no IDA mutation tools were used.
- No project documentation pages or coverage reports were edited in this task, so no by-memory/by-file lease was taken. The only created file is this B001 research report under `tools/leaser/Agents/Agent-B001/research`.
- Did not run coverage validation because this is report-only and no project documentation metadata was changed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002R4-PaletteCollectionColorTransformRaw.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002R4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
