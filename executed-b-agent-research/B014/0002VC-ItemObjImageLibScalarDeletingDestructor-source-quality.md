** TARGET-REPORT-UID:0002VC **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002VC ItemObjImageLibScalarDeletingDestructor Source-Quality Research

## Finalized Report / Current Recommendation

- Target: [UID:0002VC] `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md`.
- Current recommendation: keep the target reconstructable and routed, but treat it as source-declared/generated-binary MSVC scalar deleting destructor glue. Do not hand-port the wrapper body as C++.
- Required target action if accepted: raise from `85/89` to `87/92`; change direct owner/emitter from file [UID:0000KH] to class [UID:00006W], which already routes to [UID:0000KH]; replace the blank formal C++ block with the exact comment-only formal block below.
- Final disposition: class-specific deleting destructor wrapper for `ItemObjImageLib`; source cleanup is covered by the ordinary destructor body [UID:00017O], while this wrapper is regenerated from the class declaration/virtual destructor and compiler ABI.
- Confidence: very strong for range, behavior, vtable route, cleanup semantics, and no-code policy; remaining uncertainty is final original header/destructor declaration spelling and broader ItemObjImageLib draw/class source readiness, not this wrapper's identity.

## Target

- Target UID: `0002VC`.
- Target path: `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md`.
- Required report path: `tools/leaser/Agents/Agent-B014/research/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md`.
- Assignment id: `B014-report-0002VC-itemobjimagelib-scalar-deleting-destructor-source-quality-20260626`.
- Current metadata in target page: `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, blank `RECONSTRUCTION_CPP CODE`.
- Current support state: class [UID:00006W] is `88/89`, reconstructable, emitter [UID:0000KH]; file [UID:0000KH] is `89/86` with projected path `NexusTK/render/`; local cluster [UID:00017N] is a non-emitting `86/90` container; ordinary destructor [UID:00017O] is `86/92`, file-routed, and blank by target-specific no-code proof.
- Current generated state observed before this report: `auto-generated/-ag-memory-coverage.md` already shows [UID:0002VC] as routed/emitting through [UID:0000KH] but `no` code; `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still show stale `76/88` target score data. Do not edit generated files manually; validator/executed-report refresh should update them from source metadata.

## Current Target State

The page already records the important behavior: the wrapper restores the `ItemObjImageLib` and embedded `ProtectedArray<ItemInfo>` vtables, frees the protected-array entry buffer at object `+0x0c`, clears [UID:0000RA] `g_pItemObjImageLib`, runs `LObject` cleanup, then conditionally calls the delete helper according to deleting-destructor flags.

The remaining source-quality blocker is not behavior. It is policy and routing:

- The target clears the active code-entry gate because it is reconstructable, routed, and `(85 + 89) / 2 = 87`, which is greater than 85.
- Leaving the formal C++ block blank keeps it in "not covered/no code" generated status even though hand-writing the wrapper would be wrong.
- The correct resolution is a comment-only no-code marker in the formal block, not a decompiler-shaped `ScalarDeletingDestructor` implementation.
- The direct owner should be [UID:00006W] because this exact function is the first vtable slot of the `ItemObjImageLib` class. [UID:0000KH] remains the file/source root through the class emitter route.

## Evidence Checked

Project/workflow files read:

- `tools/leaser/Agents/Agent-B014/goal.md`.
- Project-level `ntk-b-agent-workflow` skill.
- `tools/leaser/Agents/Supervisor.md`.
- `by-structure.md`.
- `tools/validator_README.txt`.
- `tools/int_convert_readme.md`.
- `ntk-b-agent-workflow` references for B-agent research/implementation and Rule 26 incorporation.

Target/support docs checked:

- [UID:0002VC] `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md`.
- [UID:00017N] `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`.
- [UID:00017O] `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md`.
- [UID:00017Y] `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`.
- [UID:00006W] `by-class/ItemObjImageLib.md`.
- [UID:0000KH] `by-file/ItemObjImageLib.md`.
- [UID:0000RA] `by-global/g_pItemObjImageLib.md`.
- [UID:0001OT] `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`.
- [UID:0001UU] `by-type/by-struct/ItemObjImageLibLayout.md`.
- [UID:0001XW] `by-type/by-vtable/ItemObjImageLibVtable.md`.

Generated/current-state files checked read-only:

- `auto-generated/-ag-memory-coverage.md`.
- `auto-generated/-ag-research-tracker.md`.
- `auto-generated/-ag-coverage-report-by-memory.md`.
- `project-level/-auto-completion-stats.md`.

Prior reports used as leads and rechecked against current docs/MCP:

- Executed B002 report [UID:00017O] `executed-b-agent-research/B002/00017O-ItemObjImageLibDestructor-source-quality.md`.
- Executed B008 report [UID:00006W] `executed-b-agent-research/B008/00006W-ItemObjImageLib-class-source-quality.md`.
- Executed B005 report [UID:00017N] `executed-b-agent-research/B005/00017N-ItemObjImageLibLocalMethodCluster-source-quality.md`.
- Comparable scalar-deleting-destructor policy reports for [UID:0002PY], [UID:0002IT], [UID:0003MA], and [UID:0003M1].

IDA MCP evidence:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- JSON-RPC session used for focused pass: `3a2e701c-e352-4870-be62-a7e9b25fdc8f`.
- IDB session: `80de0a67`.
- Worker PID: `26892`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Evidence collection time: 2026-06-26T06:13:50-04:00 local pass window.

Integer conversions checked with `tools/int_convert.py`:

- `0x5c = 92` bytes (Verified with `tools/int_convert.py`).
- `0x28 = 40` bytes (Verified with `tools/int_convert.py`).
- `0x04 = 4` bytes (Verified with `tools/int_convert.py`).
- `0x0c = 12` bytes (Verified with `tools/int_convert.py`).

## IDA MCP Facts

### Function and boundary facts

| Query | Current MCP result | Meaning |
| --- | --- | --- |
| `lookup_funcs 0x004e6580` | `sub_4E6580`, size `0x5c` | Exact target function `0x004e6580-0x004e65dc`, size 92 bytes (Verified with `tools/int_convert.py`). |
| `lookup_funcs 0x004e65dc` | not a function | Confirms end-exclusive boundary. |
| `lookup_funcs 0x004e65e0` | `sub_4E65E0`, size `0xbd` | LightObjImageLib scalar deleting destructor successor starts after padding. |
| `lookup_funcs 0x004dee20` | not a function | Ordinary destructor page remains raw/unmodeled. |
| `lookup_funcs 0x004e5ba0` | `sub_4E5BA0`, size `0xb` | Separate singleton clear helper. |
| `entity_query functions 0x004e6400-0x004e66c0` | functions at `0x004e6460`, `0x004e64a0`, `0x004e6580`, `0x004e65e0`, `0x004e66a0` | Places target in the adjacent ImageLib-family destructor island without overlap. |
| `get_bytes 0x004e65d8 size 16` | `5d c2 04 00 cc cc cc cc 55 8b ec 56 8b f1 57 33` | Target returns with `ret 4`, then four `0xcc` bytes at `0x004e65dc-0x004e65e0`, then successor prologue. |

### Behavior facts

`analyze_function 0x004e6580` reports:

- Prototype-like decompiler shape: `_DWORD *__thiscall(_DWORD *Block, char)`.
- Size: 92 bytes.
- Five basic blocks, cyclomatic complexity `2`.
- No strings.
- Callees: `j_j_j___free_base`, `sub_4F4A90`, `sub_4F4AC0`, and `_guard_check_icall_nop@4`.
- No ordinary callers.
- One incoming data xref from `0x0061b73c`.

Current decompilation:

```text
*Block = &ItemObjImageLib::`vftable';
v4 = (void *)Block[3];
Block[1] = &ProtectedArray<ItemInfo>::`vftable';
j_j_j___free_base(v4);
dword_67A758 = 0;
sub_4F4A90(Block);
if ((a2 & 1) == 0 || (a2 & 4) != 0)
    return Block;
sub_4F4AC0(Block);
return Block;
```

Current disassembly confirms:

- `0x004e6586`: stores `??_7ItemObjImageLib@@6B@` to `[esi]`.
- `0x004e658c`: pushes `[esi+0x0c]`, the protected-array entry pointer.
- `0x004e658f`: stores `??_7?$ProtectedArray@UItemInfo@@@@6B@` to `[esi+4]`.
- `0x004e6596`: calls `j_j_j___free_base`.
- `0x004e659e`: clears `dword_67A758`, source-facing [UID:0000RA] `g_pItemObjImageLib`.
- `0x004e65aa`: calls `sub_4F4A90`, the `LObject` cleanup helper used by sibling docs.
- `0x004e65b2-0x004e65bb`: if `(flags & 1) != 0 && (flags & 4) == 0`, calls `sub_4F4AC0(this)`.
- `0x004e65ca-0x004e65d2`: flag-4 guarded path pushes `0x28` / 40 (Verified with `tools/int_convert.py`) and calls `_guard_check_icall_nop@4`.
- `0x004e65c7` and `0x004e65d9`: both return with `ret 4`.

### Xref and route facts

| Address | Current MCP result | Meaning |
| --- | --- | --- |
| `xrefs_to 0x004e6580` | count `1`: data xref at `0x0061b73c` | The target start is reached by the `ItemObjImageLib` vtable slot only. |
| `xrefs_to 0x0061b73c` | count `3`: `0x004dec8c`, `0x004dee23`, `0x004e6586` | Constructor, ordinary destructor raw bytes, and scalar wrapper store the same class vtable. |
| `xrefs_to 0x0061b734` | count `5`: `0x004dec92`, `0x004dee2c`, `0x004e5b13`, `0x004e6189`, `0x004e658f` | Constructor, ordinary destructor, `ProtectedArray<ItemInfo>` cleanup helpers, and scalar wrapper use the same embedded protected-array vtable. |
| `xrefs_to 0x0067a758` | count `65`; lifecycle refs at `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, `0x004e659e` | Singleton publish/clear lifecycle remains ItemObjImageLib-owned. |
| `find_bytes 80 65 4e 00` | one match at `0x0061b73c` | Direct VA pointer to the scalar deleting destructor is the class vtable slot. |
| `find_bytes 20 ee 4d 00` | zero matches | No VA pointer route to the raw ordinary destructor start [UID:00017O]. |
| `find_bytes 20 ee 0d 00` | zero matches | No RVA pointer route to the raw ordinary destructor start [UID:00017O]. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Recommended disposition |
| --- | --- | --- | --- |
| `0x004dee20-0x004dee4d` | [UID:00017O] `ItemObjImageLibDestructor` | Raw ordinary destructor body | Keep separate; source cleanup proof target; no pointer route to raw start. |
| `0x004e5ba0-0x004e5bab` | [UID:00017Y] `ItemObjImageLibSingletonClearHelper` | Static cleanup-table singleton clear helper | Keep separate; no target metadata change required. |
| `0x004e6580-0x004e65dc` | [UID:0002VC] `ItemObjImageLibScalarDeletingDestructor` | Vtable-backed scalar deleting destructor wrapper | Reconstructable/generated-binary no-code marker; direct class owner/emitter [UID:00006W]. |
| `0x004e65dc-0x004e65e0` | no page needed | four-byte `0xcc` alignment | Padding before LightObjImageLib successor. |

## Heuristic / Inference Reanalysis And Validation

### 1. Is this source-authored destructor code or ABI wrapper glue?

Decision: it is ABI wrapper glue around source-owned cleanup.

Evidence:

- The only direct route to `0x004e6580` is the vtable pointer at `0x0061b73c`; no ordinary call path exists.
- The function consumes a stack `flags` argument and returns with `ret 4`, matching MSVC scalar deleting destructor ABI.
- It returns `this` in `eax` on all exits.
- It duplicates the ordinary destructor cleanup sequence from [UID:00017O] and then applies deleting-destructor flag logic.
- It calls allocator/delete support helpers and `_guard_check_icall_nop@4`, which are compiler/runtime lowering, not plausible handwritten `ItemObjImageLib` source.

Rejected alternatives:

- Handwrite a `ItemObjImageLib::ScalarDeletingDestructor` source method. Rejected because no such source method is expected; it would encode compiler ABI flags and delete helper mechanics as project source.
- Put the full cleanup body here as `ItemObjImageLib::~ItemObjImageLib()`. Rejected because [UID:00017O] is the ordinary destructor body, while this exact target adds wrapper-only flag/delete behavior.
- Reclassify as pure ignored/non-reconstructable thunk. Rejected because this is a class-specific vtable entry with real destructor cleanup and must be regenerated from the class declaration/virtual destructor, not discarded as unrelated runtime glue.

### 2. Should this remain emitting/reconstructable?

Decision: yes, but with a comment-only formal no-code marker.

Evidence:

- The wrapper is class-specific and tied to `ItemObjImageLib` vtable data, object layout, singleton lifecycle, and destructor cleanup.
- Rebuilt source must declare/define the class and destructor shape that regenerates this deleting destructor in the binary.
- Current by-structure Rule 28 allows comment markers for special emitting ranges whose emitted code is covered by another source representation.
- The target is currently routed and above the active code-entry gate, so a blank block is no longer the best generated-state representation.

Rejected alternatives:

- Leave routed/blank forever. Rejected because it remains a stale not-covered/no-code state despite having a target-specific no-code proof.
- Set `RECONSTRUCTABLE:FALSE`. Rejected for this target because the exact class wrapper should be regenerated as a binary artifact of reconstructing `ItemObjImageLib`; false is better reserved for pure adjustor thunks or ownerless ABI fragments where no source declaration owned by this project should account for the bytes.

### 3. Direct owner and emitter route

Decision: change direct owner and emitter from [UID:0000KH] to [UID:00006W].

Evidence:

- The target is the first vtable slot of [UID:00006W] `ItemObjImageLib`.
- The body writes the `ItemObjImageLib` vtable and operates on one `ItemObjImageLib` object.
- Current by-structure guidance prefers the narrowest true semantic owner; a virtual class destructor wrapper is class-owned.
- [UID:00006W] already clears the parent gate and emits through [UID:0000KH], so the source root remains `NexusTK/render/ItemObjImageLib.cpp`.
- The vtable page [UID:0001XW] and newer draw-method children already use the class as direct owner/emitter.

Rejected alternative:

- Keep direct owner/emitter [UID:0000KH] only for historical consistency with the constructor/ordinary destructor pages. Rejected for this target because the assignment is specifically about this vtable-backed deleting wrapper, and class ownership is stronger and already supported. This report does not require a broad normalization of [UID:00017O] or [UID:0002SD]; those can remain unchanged until a coherent ItemObjImageLib method-owner pass is assigned.

## Ranked Ownership Analysis

### 1. [UID:00006W] ItemObjImageLib class

- Evidence for: vtable slot `0x0061b73c -> 0x004e6580`, class vtable stores at constructor/ordinary destructor/scalar wrapper, embedded `ProtectedArray<ItemInfo>` cleanup, singleton clear, object-size/flag path, and current class score `88/89`.
- Evidence against: final class declaration/formal C++ remains blank at class level.
- Decision: accepted as direct owner/emitter. Class-level C++ can remain blank; the exact child emits only a comment marker.

### 2. [UID:0000KH] ItemObjImageLib file

- Evidence for: established source root `NexusTK/render/ItemObjImageLib.cpp`; owns the item sprite library module, singleton, constructor, ordinary destructor, helpers, draw methods, and generated output path.
- Evidence against: less narrow than the class for a virtual deleting destructor.
- Decision: keep as downstream file/source root through [UID:00006W], not as direct target owner.

### 3. [UID:00017N] ItemObjImageLibLocalMethodCluster

- Evidence for: source-family container and cross-reference page for constructor/destructor/draw/glyph relationships.
- Evidence against: explicitly non-reconstructable/non-emitting container; target is an exact tail outside the local cluster.
- Decision: support/index only, not owner/emitter.

### 4. [UID:0000RA] g_pItemObjImageLib

- Evidence for: wrapper clears this singleton.
- Evidence against: singleton is state mutated by the destructor, not the owner of the method.
- Decision: rejected as owner; keep as support/global lifecycle evidence.

### 5. [UID:0000MU] ProtectedArray or `LObject`

- Evidence for: wrapper frees protected-array entries and calls base cleanup.
- Evidence against: both are member/base cleanup dependencies; the wrapper writes `ItemObjImageLib` vtable and clears `g_pItemObjImageLib`.
- Decision: rejected as owner.

## Source Placement

Recommended source placement remains the `ItemObjImageLib` render module:

- Direct semantic owner: [UID:00006W] `ItemObjImageLib`.
- Source root: [UID:0000KH] `ItemObjImageLib`, projected path `NexusTK/render/`.
- Source-facing destructor semantics: `ItemObjImageLib::~ItemObjImageLib()` represented by [UID:00017O] and class/header reconstruction.
- This target's C++ representation: comment-only no-code marker in the exact by-memory block.

This placement matches the singleton global, item metadata layout, vtable page, draw-method children, constructor first-draft C++ route, legacy remap constants, and `ItemInfo`/`ProtectedArray<ItemInfo>` layout docs.

## Range / Split / Padding / Reclassification Analysis

No split is needed.

- Current MCP reports one modeled function at `0x004e6580` with size `0x5c`, ending at `0x004e65dc`.
- `0x004e65dc` is not a function.
- `0x004e65dc-0x004e65e0` is four `0xcc` bytes (Verified with `tools/int_convert.py` for `0x04 = 4`).
- `0x004e65e0` starts the LightObjImageLib scalar deleting destructor successor.
- The ordinary raw destructor [UID:00017O] is not to be merged into this target because it has separate exact bytes and no direct pointer route.

Reclassification is limited to rebuild handling text and generated-code policy: source-declared/generated-binary wrapper with a formal comment marker, not a handwritten source method.

## First-Draft C++ Recommendation

- Eligible for formal block content: yes. The target is `RECONSTRUCTABLE:TRUE`, has a confirmed emitter route, and the current score average is over 85.
- Recommended formal content: comment-only no-code marker. Do not emit a wrapper body.
- Reason it preserves behavior: the rebuilt compiler should regenerate the deleting destructor from the class declaration and ordinary destructor; hand-writing the flag/delete wrapper would duplicate compiler output and risk source-shape pollution.
- Reason it matches plausible original source: late-1990s/early-2000s MSVC C++ source would declare/define `ItemObjImageLib::~ItemObjImageLib()` and let the compiler emit the scalar deleting destructor. Developers would not write a `ScalarDeletingDestructor` method that takes delete flags.
- Inferred source names: use `ItemObjImageLib`, `ItemObjImageLib::~ItemObjImageLib()`, and [UID:00017O] for the source cleanup proof; keep raw names such as `sub_4E6580`, `dword_67A758`, and `Block` only in evidence.

Exact formal block to insert into [UID:0002VC]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for ItemObjImageLib; source cleanup is covered by ItemObjImageLib::~ItemObjImageLib() [UID:00017O].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not use a body such as:

```text
ItemObjImageLib *ItemObjImageLib::ScalarDeletingDestructor(unsigned int flags)
```

That is decompiler/ABI-shaped, not original source-shaped.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md`.

Recommended metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended summary/rebuild status:

- Replace "source-authored destructor semantics plus compiler-emitted deleting-destructor wrapper" with "source-declared/generated-binary scalar deleting destructor wrapper; source cleanup is covered by [UID:00017O] and the `ItemObjImageLib` class declaration/destructor."
- Replace "attached to [UID:0000KH]" with "direct class owner/emitter [UID:00006W], routing through [UID:0000KH] `NexusTK/render/ItemObjImageLib.cpp`."
- Record current MCP session `80de0a67` / JSON-RPC session `3a2e701c-e352-4870-be62-a7e9b25fdc8f`, worker PID `26892`, `server_health` ok, Hex-Rays ready.
- Add current MCP facts: modeled `sub_4E6580` size `0x5c` / 92 bytes (Verified with `tools/int_convert.py`), vtable-only xref `0x0061b73c -> 0x004e6580`, no ordinary callers, callees `j_j_j___free_base`, `sub_4F4A90`, `sub_4F4AC0`, `_guard_check_icall_nop@4`, class/protected-array/singleton xref counts, pointer-route negatives to `0x004dee20`, and four-byte padding before `0x004e65e0`.
- Preserve cleanup behavior in target prose: vtable restore, `this+0x0c` entry free, singleton clear at `0x004e659e`, `LObject` cleanup, scalar-delete branch `(flags & 1) != 0 && (flags & 4) == 0`, guarded flag-4 size `0x28` / 40 path.
- Preserve rejected alternatives: no merge with [UID:00017O], no global/template/base ownership, no handwritten wrapper implementation, no `RECONSTRUCTABLE:FALSE`.
- Insert the exact formal comment-only block above.

Recommended `Item Summary` replacement:

```text
Compiler-generated ItemObjImageLib scalar deleting destructor wrapper with vtable-only route, protected-array entry free, singleton clear, base cleanup, delete-flag handling, padding boundary, and formal no-code marker pointing to the ordinary destructor source cleanup.
```

## Recommended Support Doc Changes

### `by-class/ItemObjImageLib.md`

Add a narrow support sync:

- The scalar deleting destructor child [UID:0002VC] is now treated as class-owned source-declared/generated-binary ABI glue with a comment-only formal marker.
- Source cleanup remains [UID:00017O] / `ItemObjImageLib::~ItemObjImageLib()`.
- Class-level C++ remains blank because method bodies and declarations live on exact children; do not duplicate the comment marker or constructor/draw child C++ in the class page.

No score change is required.

### `by-file/ItemObjImageLib.md`

Add a narrow source-root sync:

- [UID:0002VC] now routes through class [UID:00006W] to this file root instead of directly attaching to the file.
- The file remains the generated output root `NexusTK/render/ItemObjImageLib.cpp`.
- The formal marker on [UID:0002VC] is a no-code proof for compiler scalar deleting destructor glue, not source-authored wrapper code.

No score/path change is required.

### `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`

Add a narrow tail-page sync:

- Keep [UID:0002VC] separate from this non-emitting cluster and from [UID:00017O].
- Record that [UID:0002VC] is the vtable-backed class scalar deleting destructor wrapper, now class-routed with a formal comment-only no-code marker.

No score change is required.

### Support pages checked and no edit required unless supervisor wants extra cross-reference wording

- [UID:00017O] ordinary destructor already records scalar-wrapper parity, no pointer route to the raw start, and blank-C++ proof at same-or-greater detail.
- [UID:00017Y] singleton-clear helper already records its separate cleanup-table helper role.
- [UID:0000RA] and [UID:0001OT] already record lifecycle write `0x004e659e`.
- [UID:0001UU] layout already records destructor free of `m_itemInfos.m_entries` and the inline default-entry layout.
- [UID:0001XW] vtable page already records `0x0061b73c -> 0x004e6580`, constructor/ordinary/scalar vptr refs, and no pointer route to `0x004dee20`.

## Score And Metadata Recommendation

Current target state:

- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000KH`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KH`
- formal C++ blank

Recommended target state:

- `COMPLETION:87`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00006W`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006W`
- formal C++ comment-only no-code marker

Rationale:

- Completion rises because the target will no longer have a stale blank C++ gate; it will record current MCP session facts, direct class routing, generated-binary/no-code policy, pointer-route negatives, and exact formal marker content.
- Confidence rises because current MCP independently confirms the decompile/disasm/xrefs/bytes/callees and no-ordinary-caller state, and because support docs already agree on the ordinary destructor/source cleanup relationship.
- Scores stay below `95` because final class/header spelling, final ordinary destructor formal source, and broader ItemObjImageLib draw/class source readiness are not final-audit complete.
- Owner/emitter should change to class [UID:00006W] for direct semantic ownership. The source root remains [UID:0000KH] through the class emitter chain.

## Open Questions With Attempted Resolution

Resolved in this pass:

- Blank-C++ blocker: resolved with a formal comment-only no-code marker.
- Source wrapper versus source destructor: resolved; wrapper is compiler-generated, source cleanup belongs to [UID:00017O] / class destructor.
- Owner route: resolved for this target as class direct owner/emitter [UID:00006W], file root [UID:0000KH].
- Range/split: resolved; no split, merge, or padding child needed.
- `g_pItemObjImageLib` ownership: resolved; singleton is support state, not function owner.

Remaining and score impact:

- Exact original header/destructor declaration spelling is still not symbol-proven. This prevents final-audit scoring, but it does not block the comment-only formal marker.
- [UID:00017O] ordinary destructor still has no live pointer route to its raw start and keeps formal C++ blank. That remains a separate target-specific policy and does not justify hand-writing this wrapper.
- Broader ItemObjImageLib draw helper signatures and class declaration are still not final-source quality. This affects class/file final C++ readiness, not this wrapper no-code proof.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit is requested or permitted for B014.

Generated observations for supervisor/validator only:

- `auto-generated/-ag-memory-coverage.md` currently shows [UID:0002VC] routed but with no code.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still show stale `76/88` data even though the live by-memory page is `85/89`.
- After implementation, run scoped validators on changed source by-* pages. If generated refresh is deferred, compare generated headers or use queue status; do not edit generated Markdown manually.
- Supervisor execution of this report should refresh the research tracker lifecycle state.

## Validator Plan For Implementation Callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality-removed.md](0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run validators only for support files that are actually changed. Do not run validators for generated/project-level files, coverage reports, or validator/tool state. Record `command_id`, `command_timestamp`, exit code, `ok` count, warnings, and generated-refresh state during implementation.

## Changed Files In Report-Only Pass

- Created/modified: `tools/leaser/Agents/Agent-B014/research/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md`.
- No by-* docs edited.
- No generated files edited.
- No project-level files edited.
- No validator/tool state edited.
- No IDA DB edits made.
- No leases taken.
- Stale/orphan `tools/leaser/Agents/Agent-B014/research/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md` was not read for evidence and was not edited.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report for implementation callback for [UID:0002VC] in `Agent-B014/goal.md` assignment `B014-implement-0002VC-itemobjimagelib-scalar-deleting-destructor-source-quality-20260626`.
- [x] Target doc `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md`: set `COMPLETION:87`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006W`, kept `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00006W`, and left emitter position blank. Proof: target metadata header after validation has those exact values; validator command `000000002511` recorded `completion_update 87`, `confidence_update 92`, and `canonical_owner_update 00006W`.
- [x] Target formal C++: replaced the blank `RECONSTRUCTION_CPP CODE` block with the three-marker comment-only no-code marker for compiler-generated `ItemObjImageLib` scalar deleting destructor glue. Proof: target formal block now contains only the comment marker; validator command `000000002511` normalized the `[UID:00017O]` reference in that comment to a UID link, but the block remains comment-only and contains no handwritten wrapper body.
- [x] Target prose: updated rebuild handling/status from mixed "source-authored destructor semantics plus compiler wrapper" wording to source-declared/generated-binary wrapper; stated that source cleanup is covered by [UID:00017O] / `ItemObjImageLib::~ItemObjImageLib()`. Proof: target `## Status`, `## Behavior`, `## Caveats`, and `## 2026-06-26 B014 Source-Quality Callback Evidence`.
- [x] Target MCP evidence: incorporated current live MCP proof from session `80de0a67` / JSON-RPC session `3a2e701c-e352-4870-be62-a7e9b25fdc8f`, including function size `0x5c` / 92 bytes, vtable-only start xref, no ordinary callers, callee list, vtable/protected-array/singleton xrefs, pointer-route negatives to `0x004dee20`, and `0x004e65dc-0x004e65e0` padding. Proof: target `## 2026-06-26 B014 Source-Quality Callback Evidence`.
- [x] Target behavior: preserved cleanup sequence details for vtable restore, protected-array `this+0x0c` entry free, singleton clear at `0x004e659e`, `LObject` cleanup, scalar-delete branch, flag-4 guarded path with `0x28` / 40 size, and `ret 4` ABI return. Proof: target `## Behavior`, existing `## IDA Evidence`, and new 2026-06-26 evidence section.
- [x] Target rejected alternatives: preserved no merge with [UID:00017O], no global/template/base ownership, no handwritten wrapper body, no `RECONSTRUCTABLE:FALSE`, and no stale blank-C++ gate rationale. Proof: target `## Caveats`, `## Score Rationale`, and `## Changes` 2026-06-26 entry.
- [x] Target `Item Summary`: updated to the concise summary recommended in this report, without repeating UID/range/score/owner fields. Proof: target metadata `Item Summary` now reads "Compiler-generated ItemObjImageLib scalar deleting destructor wrapper with vtable-only route, protected-array entry free, singleton clear, base cleanup, delete-flag handling, padding boundary, and formal no-code marker pointing to the ordinary destructor source cleanup."
- [x] Support doc `by-class/ItemObjImageLib.md`: added narrow sync that [UID:0002VC] is class-owned source-declared/generated-binary ABI glue with formal comment-only marker; source cleanup is [UID:00017O]; class-level C++ remains blank. No score change made. Proof: class `## Status`, method row for `ItemObjImageLib::ScalarDeletingDestructor`, B014 paragraph after the B002 destructor paragraph, `## Source-Quality Notes`, and `## Changes` 2026-06-26 entry.
- [x] Support doc `by-file/ItemObjImageLib.md`: added narrow sync that [UID:0002VC] routes through [UID:00006W] to this file root and that the formal marker is no-code ABI proof, not source-authored wrapper code. No score/path change made. Proof: file `## Owned And Nearby Helpers`, source-quality paragraph before draw API table, and `## Changes` 2026-06-26 entry.
- [x] Support doc `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`: added narrow tail-page sync keeping [UID:0002VC] separate from the non-emitting cluster and [UID:00017O], with class-routed comment-only no-code disposition. No score change made. Proof: cluster `Related exact tail pages`, `Split Coverage Status`, `Evidence Notes`, and `## Changes` 2026-06-26 entry.
- [x] Support pages checked with no edit required unless supervisor widens scope: [UID:00017O], [UID:00017Y], [UID:0000RA], [UID:0001OT], [UID:0001UU], and [UID:0001XW] already contain same-or-greater scalar-wrapper/global/layout/vtable evidence. Proof: [UID:00017O] `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md` already records scalar-wrapper parity, no VA/RVA pointer route to `0x004dee20`, and blank-C++ proof; [UID:00017Y] `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md` already records separate cleanup-table helper role and singleton lifecycle refs; [UID:0000RA] `by-global/g_pItemObjImageLib.md` and [UID:0001OT] `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md` already record lifecycle write `0x004e659e`; [UID:0001UU] `by-type/by-struct/ItemObjImageLibLayout.md` already records destructor free of `m_itemInfos.m_entries` at `+0x0c` and untouched inline default row; [UID:0001XW] `by-type/by-vtable/ItemObjImageLibVtable.md` already records slot `0x0061b73c -> 0x004e6580` and no pointer route to `0x004dee20`.
- [x] Generated/project-level/coverage files: did not edit manually; recorded generated-refresh observations from validator output only. Proof: scoped validators reported `generated_refresh: deferred`; validator-owned side effects included `projected_stats_update` and registry/reference normalization. No `by-memory/-coverage-report.md` or other `-coverage-report.md` file was edited by B014.
- [x] Validators to run after implementation: scoped file validators ran for each changed by-* file listed in the validator plan; did not validate or edit the stale/orphan `0001GY` report and did not run unrelated validators. Proof: validator table below.
- [x] Implementation callback updated this checklist with checked items, proof locations, validator command IDs/timestamps/exit status/ok counts, generated-refresh state, and lease release proof.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: `Agent-B014/goal.md` is in accepted implementation callback mode for report `tools/leaser/Agents/Agent-B014/research/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md`.
- [x] Leases acquired only immediately before editing target/support by-* docs and released immediately after edit/validator batch. Proof: B014 lease command succeeded for all four changed by-* files; B014 refreshed the same four leases immediately before validation; final unlease returned `Success` for all four files after validators.
- [x] All accepted target/support details incorporated at report-level detail, already present at same-or-greater detail, or explicitly excluded with concrete reason. Proof: target and three required support docs updated; no-edit support pages recorded above; [UID:00017O], [UID:00017Y], [UID:0000RA], [UID:0001OT], [UID:0001UU], and [UID:0001XW] excluded from editing because they already contain equal-or-greater evidence; stale/orphan `0001GY` not edited.
- [x] Scoped validators run and recorded.
- [x] No active B014 leases remain. Proof: post-release `tools/leaser/Agents/current_leases.md` check for `B014`, `ItemObjImageLib`, `0x004e6580`, and `0x004dec30` returned no rows.

Validator results:

| File | Command | Timestamp | Exit | `ok` | Warnings / observations | Generated refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md --apply --queue-timeout 240` | `2026-06-26T06:25:29-04:00`, command_id `000000002511` | `0` | `1` | No target failure; validator applied `completion_update`, `confidence_update`, `canonical_owner_update`, `autogen_registry_update`, `insert_header_blank`, and UID-link normalization inside the formal comment marker. | `generated_refresh: deferred`, generated command id/timestamp `000000002511` / `2026-06-26T06:25:29-04:00`. |
| `by-class/ItemObjImageLib.md` | `python .\tools\validator.py --mode file --file by-class\ItemObjImageLib.md --apply --queue-timeout 240` | `2026-06-26T06:25:38-04:00`, command_id `000000002513` | `0` | `1` | Existing registry warnings: `missing_ref_uid: 8` for repeated `0003LZ` / `0003ND`; validator inserted two [UID:00017O] links. | `generated_refresh: deferred`, generated command id/timestamp `000000002513` / `2026-06-26T06:25:38-04:00`. |
| `by-file/ItemObjImageLib.md` | `python .\tools\validator.py --mode file --file by-file\ItemObjImageLib.md --apply --queue-timeout 240` | `2026-06-26T06:25:51-04:00`, command_id `000000002514` | `0` | `1` | Existing registry/path warnings: `missing_ref_uid: 9` for repeated `0003LZ` / `0003ND` / `0003ZN`; `missing_ref_target: 2` for stale `00027I` target path; validator inserted [UID:00017O] and [UID:0002VC] links and added a reference index entry. | `generated_refresh: deferred`, generated command id/timestamp `000000002514` / `2026-06-26T06:25:51-04:00`. |
| `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` | `python .\tools\validator.py --mode file --file by-memory\0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md --apply --queue-timeout 240` | `2026-06-26T06:26:03-04:00`, command_id `000000002515` | `0` | `1` | Existing registry warnings: `missing_ref_uid: 13` for repeated `0003LZ` / `0003ND` / `0003ZN`; validator inserted one [UID:00017O] link. | `generated_refresh: deferred`, generated command id/timestamp `000000002515` / `2026-06-26T06:26:03-04:00`. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md","timestamp":"2026-06-26T06:32:57","uid":"0002VC"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002VC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
