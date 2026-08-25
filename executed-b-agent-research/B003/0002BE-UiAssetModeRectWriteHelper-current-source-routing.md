** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BE UiAssetModeRectWriteHelper Current Source Routing Research

## Finalized Report / Current Recommendation

- Assignment id: `B003-goal2-ui-asset-mode-rect-write-current-source-routing-0002BE-20260618`.
- Target UID: `0002BE`.
- Target path: `source-3/project-documentation/by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`.
- Current target state: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal reconstruction C++.
- Current recommendation: keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; do not populate reconstruction C++; do not split, merge, reclassify, or route this helper to a candidate owner on current evidence.
- Final disposition: reconstructable source-authored raw UI helper, currently no-owner/non-emitting because no source-use route is proven.
- Confidence in no-owner/non-emitting recommendation: high. The behavior and range are well supported; the owner/emitter route is not.
- Score recommendation: keep `87/91`. Do not raise completion because source placement, live reachability, source-facing original names, and final C++ route remain unresolved. Do not lower confidence because the current negative route evidence is strong and was rechecked against the current PE.

Ranked current-source-routing outcome:

| Rank | Candidate | Recommendation | Rationale |
| ---: | --- | --- | --- |
| 1 | No-owner/non-emitting | Accept current state | Only outcome that preserves all evidence: real project helper, but no caller, table, vtable, pointer, branch, source breadcrumb, class field, singleton, or resource literal ties it to a source-use context. |
| 2 | `MapNamePane` / `MapNamePane.cpp` | Strongest forced positive hypothesis, reject for action | Width `0x00ad`/173 matches MapName clamp and sibling `0002BF` now has MapName ownership, but `0002BE` lacks `this`, `this+0x220`, MapName vtable, `g_pMapNamePane`, `MAPNAME.EPF`, caller, or table evidence. |
| 3 | New narrow UI asset-mode rectangle helper grouping | Plausible future grouping, reject creation now | `0002BD` and `0002BE` form a real shared pair, but no caller/table/source root proves a new source file. If future evidence appears, scope should be narrow and probably exclude `0002BF`. |
| 4 | `MapNameAndMiniMapButtonPanes` aggregate | Reject as owner/emitter | Adjacent physical boundary record only; current doc marks it `RECONSTRUCTABLE:FALSE` and mixed-owner. It cannot be a source-level direct owner or emitter. |
| 5 | `RectBounds` / `RectGeometryHelpers` | Reject as owner; dependency only | Target writes a `RectBounds`-layout record through `sub_4B7C50`, but the constants and asset-mode branch are caller-specific UI behavior, not geometry primitive ownership. |
| 6 | `MiniMapButtonPane` / `MiniMap.cpp` | Reject | Adjacent island contains MiniMapButtonPane, but no MiniMapButton vtable slot, constructor path, singleton, field, or `MMAPBUT.EPF` evidence touches `0x005030c0`. |
| 7 | `MainMenuLoginAndAccountDialogs` | Reject | Preceding broad aggregate is separated by modeled code and `0xcc` padding; behavior is UI asset-mode rectangle output, not login/account dialog packet/menu logic; no route or xref exists. |

## Supporting Research

### Target summary

`0002BE` covers `0x005030c0-0x00503104`, a `0x44`-byte / 68-byte raw helper body (Verified with `int_convert.py`). It is not modeled as an IDA function in the documented IDA passes, but the bytes form a coherent MSVC-style helper:

```asm
5030c0  push    ebp
5030c1  mov     ebp, esp
5030c3  sub     dword ptr [ebp+8], 1
5030c7  jnz     short loc_503100
5030c9  cmp     byte_66DA97, 1
5030d0  push    10h
5030d2  jnz     short loc_5030EC
5030d4  push    0A6h
5030d9  push    0
5030db  push    0
5030dd  push    dword ptr [ebp+0Ch]
5030e0  call    sub_4B7C50
5030e5  add     esp, 14h
5030e8  pop     ebp
5030e9  retn    8
5030ec  push    0ADh
5030f1  push    0
5030f3  push    0
5030f5  push    dword ptr [ebp+0Ch]
5030f8  call    sub_4B7C50
5030fd  add     esp, 14h
503100 pop     ebp
503101 retn    8
```

Behavior:

- Argument 1 is decremented and the helper writes only when the original value was exactly `1`.
- Argument 2 is a caller-supplied output pointer with the `RectBoundsLayout` shape documented by [UID:0001VP].
- If [UID:0000SW] `g_useEpfAssets` / `byte_66DA97` equals `1`, it writes `RectBounds(0, 0, 0x00a6, 0x10)`.
- Otherwise, in the writing path, it writes `RectBounds(0, 0, 0x00ad, 0x10)`.
- `0x00a6 = 166`, `0x00ad = 173`, `0x10 = 16`, and `0x44 = 68` were verified with `source-3/project-documentation/tools/int_convert.py`.
- If argument 1 is not `1`, the helper returns with `retn 8` without writing the output pointer. This output-preserving non-`1` path is real behavior and must be preserved if the helper is ever emitted.

### Current local validation run

IDA MCP could not be reached in this session: `Invoke-WebRequest` to `http://127.0.0.1:13337/mcp` failed with "Unable to connect to the remote server." Therefore, this report uses current local PE scans plus existing IDA-backed project docs. All IDA-only claims below are cited as documentation evidence from current by-* pages and executed B reports, not as newly queried MCP facts from this run.

Fresh read-only PE scan used:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5 `4247e04e20b65d6414c7238aa8ff5515`
- Image base `0x00400000`
- Parsed sections: `.text`, `.rdata`, `.data`, `.rsrc`
- Alternate local executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` has the same MD5 `4247e04e20b65d6414c7238aa8ff5515`.

Fresh PE scan results:

| Evidence check | Result |
| --- | --- |
| Exact target body `0x005030c0-0x00503104` | Appears exactly once, at file offset `0x1024c0`, VA `0x005030c0`. |
| Absolute VA literal `0x005030c0` | Zero hits. |
| RVA literal `0x001030c0` | Zero hits. |
| External `E8/E9` call/jump to target start or target range | Zero hits. |
| External `0F 8x` near conditional branch to target start or target range | Zero hits. |
| External short branch to target start or target range | Zero hits. |
| Any dword in `.text`, `.rdata`, `.data`, `.rsrc` pointing inside `0x005030c0-0x00503104` | Zero hits. |
| Any dword in `.text`, `.rdata`, `.data`, `.rsrc` pointing inside raw cluster `0x00503060-0x005031e1` | Zero hits. |
| Nearby vtable dwords `0x0061e5b4-0x0061e6c0` pointing into raw cluster | Zero hits. |

Positive controls from the same scan:

| Positive control | Current PE scan result |
| --- | --- |
| `MapNamePane` constructor `0x005031f0` | External calls at `0x004f8051` and `0x004f8695`. |
| `MiniMapButtonPane` constructor `0x00503580` | External call at `0x004f80c2`. |
| `MapNamePane::OnPaint` `0x00503350` | Absolute VA hit at vtable slot `0x0061e5f8`. |
| `MapNamePane` update handler `0x005034a0` | Absolute VA hit at vtable slot `0x0061e610`. |
| `MiniMapButtonPane::OnPaint` `0x00503650` | Absolute VA hit at vtable slot `0x0061e680`. |
| `MiniMapButtonPane` mouse handler `0x005036a0` | Absolute VA hit at vtable slot `0x0061e68c`. |

The positive controls matter because the scan can find ordinary class vtable slots and ordinary constructor calls in the same neighborhood. Its failure to find `0x005030c0` is therefore meaningful negative evidence, not just a broken scan.

### Existing IDA-backed documentation evidence

Current by-* docs and executed reports already record repeated IDA MCP passes:

- Target page [UID:0002BE] records no IDA function object, no `XrefsTo`, no raw pointer hits, unique exact-range signature, unique wildcarded entry signature, repeated no-reference PE scans, and exact dual-return behavior.
- Parent aggregate [UID:00022Z] records the three raw starts `0x00503060`, `0x005030c0`, and `0x00503110` as unmodeled raw helper bodies, separated by `0xcc` alignment, with no xrefs/pointers/branches to their starts.
- Sibling [UID:0002BD] has the same asset-mode rectangle extents but dispatches through `[this->vtable + 0x20]`; it also remains no-owner/non-emitting.
- Sibling [UID:0002BF] is now assigned to [UID:00007P] `MapNamePane`, but only because it has direct `this + 0x220` font-table field evidence that matches MapNamePane constructor/destructor lifecycle. That evidence is absent from `0002BE`.
- [UID:0001AL] `MapNameAndMiniMapButtonPanes` explicitly warns not to absorb the preceding raw helper cluster into `MapNamePane` or `MiniMapButtonPane` without caller/vtable evidence.
- [UID:0003BZ] and [UID:0003C0] document exact MapNamePane and MiniMapButtonPane vtable data; neither vtable child contains `0x005030c0`.

### Candidate source documents considered

| Candidate | UID / path | Gate state | Source-routing relevance |
| --- | --- | --- | --- |
| `MapNamePane` class | [UID:00007P] `by-class/MapNamePane.md` | `86/88`, emits through [UID:0000L2] | Strong adjacent class with `0x00ad` width association, but no target reference or field evidence. |
| `MapNamePane.cpp` file | [UID:0000L2] `by-file/MapNamePane.md` | `86/86`, valid path `NexusTK/map/` | Valid file root for MapNamePane children, not a proven route for this raw helper. |
| `MiniMapButtonPane` class | [UID:00008B] `by-class/MiniMapButtonPane.md` | `85/86`, emits through [UID:0000LE] | Adjacent class but target has no MiniMapButton-specific evidence. |
| `MiniMap.cpp` file | [UID:0000LE] `by-file/MiniMap.md` | `86/88`, valid path `NexusTK/map/` | Valid minimap root, but no direct relation to target body. |
| Mixed pane aggregate | [UID:0001AL] `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md` | `86/92`, `RECONSTRUCTABLE:FALSE` | Physical boundary/index only; exact children own source. |
| Main menu/login aggregate | [UID:00019I] `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` | `85/88`, `RECONSTRUCTABLE:FALSE` | Mixed container; no direct xref or behavior match. |
| `RectBounds` class/file | [UID:0000BU], [UID:0000N2] | class `88/85`, file `90/85` | Owns geometry primitive and `sub_4B7C50`, not caller-specific UI branch helper. |
| `g_useEpfAssets` global | [UID:0000SW] | `88/90`, emits through [UID:0000O5] | Broad mode selector dependency; not a helper owner. |

## Heuristic / Inference Reanalysis And Validation

### Heuristic issue: raw helper liveness and reachability

Best current inference: `0002BE` is a retained source-authored helper whose source-use route is missing from the stripped/static evidence currently available.

Evidence checked:

- Existing IDA docs: no function object, no xrefs, no raw pointer hits, no table/vtable slot.
- Fresh PE scan: zero absolute VA/RVA references, zero external direct calls/jumps/conditional branches into target range, zero dwords into target or raw cluster, zero nearby vtable slots into raw cluster.
- Positive controls: constructor calls and vtable entries for adjacent MapName/MiniMapButton functions are visible to the same scan.

Rejected alternatives:

- "It is padding": rejected because the body has a normal prologue, real control flow, two calls to `sub_4B7C50`, two `retn 8` exits, and coherent helper semantics.
- "It is compiler/runtime code": rejected because it reads a NexusTK global mode byte, writes UI rectangle data, and calls NexusTK geometry helper code.
- "It is safely live through MapName/MiniMap vtables": rejected because the nearby vtable data contains real slots but none to this helper.

Impact:

- Keep `RECONSTRUCTABLE:TRUE` because the code is source-shaped custom client behavior.
- Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because no source-use route is proven.

### Heuristic issue: `g_useEpfAssets` and rectangle extent semantics

Best current inference: `byte_66DA97` / [UID:0000SW] `g_useEpfAssets` selects current EPF/new-layout asset mode versus legacy layout/resource mode. In this helper, it chooses the rectangle right edge for a small UI output rectangle.

Evidence checked:

- [UID:0000SW] documents one-byte `.data` storage, initial value `1`, broad 366-xref / 248-function spread, and sole writer in `StartupWindow__Constructor`.
- Target body compares `byte_66DA97` to `1`.
- [UID:00015S] identifies `sub_4B7C50` as the four-field `InitRectBounds` / `left, top, right, bottom` setter.
- `0x00a6 = 166`, `0x00ad = 173`, `0x10 = 16` were verified with `int_convert.py`.

Rejected alternatives:

- `0x00a6` and `0x00ad` as resource IDs: rejected because they are passed as rectangle edge values into `sub_4B7C50`, not used as resource lookups.
- `g_useEpfAssets` as owner route to [UID:0000O5] `StartupWindow`: rejected because the global has hundreds of readers. A read dependency is not ownership.

Impact:

- Source-facing constants should be documented as inferred/descriptive rectangle extents, not resource IDs.
- The strongest semantic label is "asset-mode map-name-like bounds" rather than a proven original symbol.

### Heuristic issue: output-preserving non-`1` path

Best current inference: the helper intentionally or incidentally preserves the caller-provided output rectangle when the first argument is not `1`. No current evidence proves which callers, if any, rely on that preservation.

Evidence checked:

- Instruction sequence `sub [ebp+8], 1; jnz loc_503100` branches directly to `pop ebp; retn 8` without touching `[ebp+0Ch]`.
- Fresh PE scan and existing IDA docs still find no caller.

Rejected alternatives:

- "Compiler missed initialization but caller never observes it": possible but unproven.
- "We can initialize a default rectangle in reconstruction": rejected because it would change observable behavior if any caller relies on preserved output.

Impact:

- Any future source emission must preserve output on non-`1` input.
- This uncertainty does not lower behavior confidence; it blocks caller-contract confidence and final C++.

### Heuristic issue: relation to sibling UID `0002BD`

Best current inference: `0002BD` and `0002BE` are a meaningful raw rectangle-helper pair. If future evidence proves a new helper grouping, it should probably start with these two siblings.

Shared facts:

- Both are adjacent in the raw `00022Z` cluster.
- Both use `g_useEpfAssets`.
- Both select width `0x00a6` or `0x00ad` with height `0x10`.
- Both call [UID:00015S] `sub_4B7C50`.
- Both remain without direct caller/table/vtable route in current docs and scans.

Difference:

- `0002BD` receives `this` and dispatches through `[this->vtable + 0x20]` after optional local rectangle setup.
- `0002BE` is a stack-argument output writer returning with `retn 8`; it has no `this` or vtable dispatch.

Impact:

- The pair strengthens the "narrow UI asset-mode rectangle helper family" hypothesis.
- It does not prove MapNamePane, MiniMapButtonPane, or any emitter route.

### Heuristic issue: relation to sibling UID `0002BF`

Best current inference: `0002BF` should not be used to transfer MapNamePane ownership to `0002BE`.

Evidence checked:

- [UID:0002BF] reads `this + 0x220`, and current [UID:00007P] docs identify that field as `m_mapNameGlyphTable` initialized/freed by MapNamePane constructor/destructor.
- [UID:0002BF] is a `thiscall` wide glyph renderer with source/destination rectangle setup and `SurfaceRenderCallbackTable` use.
- `0002BE` has no `this`, no field access, no `9X11FONT.BIN`, no render callback, no MapName singleton/global, and no vtable slot.

Rejected alternative:

- "All three raw helpers belong to MapNamePane because `0002BF` does": rejected. `0002BF` has direct class-field evidence; `0002BE` has only adjacency and a width association.

Impact:

- Keep `0002BF`'s MapName route as sibling-specific.
- Keep `0002BE` no-owner/non-emitting until it has independent source-use evidence.

### Heuristic issue: source-facing helper/type names

Best descriptive names:

- Current page name `UiAssetModeRectWriteHelper` remains acceptable and conservative.
- If a future source route is found, a source-facing descriptive name such as `WriteAssetModeRectBoundsIfSelected`, `WriteMapNameAssetModeBounds`, or `GetAssetModeMapNameBounds` could be considered, but none is original-proof.
- The output type should be modeled as `RectBounds` or `RectBoundsLayout` because [UID:00015S] `sub_4B7C50` writes `left/top/right/bottom`.

Rejected names/directions:

- `ResourceDescriptor` wording: rejected because constants are extents, not resource IDs.
- `RectBounds` owner/method name: rejected because the helper includes caller-specific UI mode logic.
- `MapNamePane` method name: rejected because no receiver/class evidence exists.

Impact:

- Name uncertainty blocks final C++ quality but does not block preserving the behavior in documentation.

### Heuristic issue: new UI resource/layout helper grouping

Best future-only grouping if forced by future evidence:

- Proposed descriptive grouping: `UiAssetModeRectHelpers` or `UiResourceModeLayoutHelpers`.
- Scope if proven: [UID:0002BD] and [UID:0002BE], plus any future recovered caller/table/callback that references them.
- Exclusions: [UID:0002BF] unless future evidence supersedes its MapName field route; [UID:00015S] RectGeometry because it is generic; [UID:0000SW] `g_useEpfAssets` because it is global state; MapName/MiniMap vtable data because it lacks raw-helper entries.

Why not create now:

- No source file name, table, caller, vtable, static local, resource string, or debug/source metadata proves a source unit.
- Creating a new owner would convert an evidence gap into a false source root.

Impact:

- Record as a ranked hypothesis only.
- No new by-file/by-class/by-global owner should be created for this assignment.

### Target open questions rechecked

Open question: "Whether this helper shares a callback table with the `0x00503060` virtual-dispatch helper."

- Current answer: not proven. Existing IDA docs and fresh PE scan found no absolute/RVA/dword/table/vtable entry to `0x005030c0` or the raw cluster. `0002BD` and `0002BE` share behavior and adjacency, but no callback table is identified.
- Action impact: leave no-owner/non-emitting; if future table evidence appears, reanalyze `0002BD` and `0002BE` together.

Open question: "Exact source-facing rectangle/output type and semantic names for the EPF/legacy extents `0x00a6` and `0x00ad`."

- Current answer: output type is strongly inferred as `RectBounds` / `RectBoundsLayout`; source-facing extent names remain descriptive only. `0x00a6` is the current/EPF-mode right edge, `0x00ad` is the legacy/default right edge matching MapName's documented 173-pixel clamp. No original symbol names are recovered.
- Action impact: do not emit final C++; keep descriptive documentation names only.

Open question: "Whether real callers intentionally rely on the non-`1` state path preserving the output rectangle unchanged."

- Current answer: no caller is known, so caller intent cannot be proven. The raw behavior is confirmed: non-`1` returns without writing output.
- Action impact: any future source reconstruction must preserve the no-write path; do not synthesize default initialization.

## First-Draft C++ Recommendation or exact do-not-populate proof

Do not populate `RECONSTRUCTION_CPP CODE` for [UID:0002BE].

Exact proof under the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`: yes.
- Combined score `(87 + 91) / 2 = 89`: numerically above the current minimum.
- Confirmed nonblank `EMITTER_UIDS`: no. The field is blank, and this report recommends it stay blank.
- Route to a generated source root without a dead end: no route exists.
- Final source-facing owner/name/type certainty: not sufficient. The output type is inferred as `RectBounds`, but helper owner, source file, original helper name, and caller contract remain unresolved.

Therefore the target fails the nonblank-emitter/source-route requirement. A behavior sketch would be useful only as review material and should not be entered into the formal code block. If future caller/table evidence proves a route, the emitted body must preserve this semantic shape:

- Return type likely `void`.
- One state/index argument and one output `RectBounds*`-style argument.
- If state/index is not exactly `1`, return without writing output.
- If state/index is `1`, write `(0, 0, g_useEpfAssets == 1 ? 0x00a6 : 0x00ad, 0x10)` through the existing rectangle initializer or equivalent source-level `RectBounds` setter.

This is intentionally not a first-draft C++ block because entering code now would make generated output claim a source route that the evidence does not support.

## Exact Supervisor Changes Needed including coverage row text if any

### Target metadata

No metadata changes recommended:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Formal `RECONSTRUCTION_CPP CODE` should remain blank.

### `by-memory/-coverage-report.md`

The current manual coverage row is stale. It still says `82%` and "child is below `85` completion" even though the target page is `87/91`.

Placement context: replace the existing `0002BE` row under the `0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers` nested raw-helper block, currently matching:

```text
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 82% : strong : Optional EPF/legacy `RectBounds(0,0,0xa6/0xad,0x10)` write helper with `retn 8` exits at `0x005030e9` and `0x00503101`; no IDA function object, no xrefs, no raw pointer hits for the start, twelve `0xcc` bytes before `0x00503110`, and blank parent because child is below `85` completion and no direct source parent is evidence-supported.
```

Replacement row:

```text
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : Raw UI asset-mode rectangle output writer with unique `0x44`-byte body, two `retn 8` exits at `0x005030e9` and `0x00503101`, optional `RectBounds(0,0,0x00a6/0x00ad,0x10)` write through `sub_4B7C50`, `g_useEpfAssets` branch semantics, and output-preserving non-`1` path; repeated IDA-backed docs plus B003 2026-06-18 PE scan confirm no function object/xrefs/raw pointer hits/absolute VA or RVA literals/external branch or call targets/range dwords/nearby MapName or MiniMapButton vtable slots, so `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank C++ remain correct until a caller/table/source-use route is found.
```

### `auto-generated/-ag-memory-coverage.md`

No manual change. Current generated row is still semantically correct:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

### Optional target-page incorporation text

B003 did not edit the target page. If the supervisor or an A-agent incorporates this report into the target page, use this exact change-log entry under `## Changes`:

```text
- 2026-06-18 B003 current source-routing recheck:
  - Changed to: no metadata change; retained `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
  - Summary/evidence: IDA MCP was unavailable in the B003 session, so B003 rechecked current local PE evidence against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` and reviewed current by-* docs. The exact target body appears once at file offset `0x1024c0`; the scan found zero absolute-VA/RVA literals, zero external `E8/E9` calls or jumps, zero external near or short branch targets, zero dwords pointing into `0x005030c0-0x00503104`, zero dwords pointing into the raw helper cluster, and zero nearby MapName/MiniMapButton vtable slots to the raw cluster. Positive controls found MapName/MiniMapButton constructor calls and vtable entries, so the no-route result remains meaningful. `MapNamePane` stays the best forced semantic guess from the `0x00ad`/173 width association, but sibling `0002BF` has `this+0x220` MapName field evidence that this helper lacks. No owner/emitter/source C++ route is justified.
```

Optional replacement for the target `## Open Questions` section:

```text
## Open Questions / Current Closure

- Callback-table sharing with [UID:0002BD] remains unproven. Current IDA-backed docs and the 2026-06-18 B003 PE scan found no pointer/table/vtable/direct branch route to `0x005030c0` or the raw helper cluster. Revisit `0002BD` and `0002BE` together only if a future caller/table is found.
- The output type is strongly inferred as `RectBounds` / `RectBoundsLayout` from `sub_4B7C50`; original source-facing helper and constant names remain unrecovered. Use descriptive wording such as current/EPF right edge `0x00a6` and legacy/default right edge `0x00ad`, not resource-ID wording.
- The non-`1` path is confirmed to preserve the caller's output rectangle unchanged. No caller is known, so caller intent is not proven; any future emitted implementation must preserve the no-write behavior.
```

## Validation Performed / Evidence Gaps

Validation performed:

- Read and followed `Supervisor.md` and `Agent-B003/goal.md`.
- Read required rule references `by-structure.md` and `inference_research.md`.
- Read current target [UID:0002BE], sibling [UID:0002BD], sibling [UID:0002BF], parent aggregate [UID:00022Z], adjacent mixed island [UID:0001AL], candidate owners `MapNamePane`, `MiniMapButtonPane`, `MiniMap`, `MainMenuLoginAndAccountDialogs`, `RectBounds`, `RectGeometryHelpers`, `g_useEpfAssets`, and vtable data pages [UID:0003BZ]/[UID:0003C0].
- Read prior executed reports for `0002BE` as leads, especially B001 second-pass and B002 current-goal2 reports, and rechecked their conclusions against current docs and fresh PE evidence.
- Queried local IDA MCP endpoint; it was unavailable in this session.
- Ran read-only PE scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Confirmed alternate local executable MD5 matches the scanned PE.
- Verified numeric conversions with `source-3/project-documentation/tools/int_convert.py`.
- Checked current manual and generated coverage rows for `0002BE`.

Evidence gaps:

- No live IDA MCP data was obtained in this B003 session because the local endpoint was unreachable.
- No runtime trace or debugger watchpoint was available to discover computed/indirect/dynamic references.
- No debug symbols, source paths, PDB, linker map, or object-file records were available.
- A future non-standard callback table, generated registration structure, dynamically built pointer, or source artifact could change the route. Current static evidence does not justify acting as if such a route exists.

Changed files:

- Created this report only: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002BE-UiAssetModeRectWriteHelper-current-source-routing.md`.
- No by-* docs, generated reports, IDA DB, generated source, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BE-UiAssetModeRectWriteHelper-current-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
