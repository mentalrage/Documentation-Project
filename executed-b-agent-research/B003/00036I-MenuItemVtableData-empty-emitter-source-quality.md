** TARGET-REPORT-UID:00036I **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00036I MenuItem Vtable Data Empty-Emitter Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep the exact `0x0061eb94-0x0061ebf0` range intact, but route it through semantic vtable owner/emitter [UID:0001Y4] `MenuItemVtables` rather than directly through file UID0000MN.
- Final disposition: reconstructable compiler-generated RTTI/vtable data. The source cause is the `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` declarations plus their virtual method implementations; no fixed-address RTTI object, vtable array, or scalar-deleting-wrapper body belongs in handwritten source.
- Ordinary callback state: the accepted target action is physically applied and read back at `94/95`, `CANONICAL_OWNER:0001Y4`, `EMITTER_UIDS:0001Y4`, blank position, exact formal CPP no-raw-data marker, blank H, and complete RTTI/slot/type/source-cause documentation.
- Ordinary support state: UID0001Y4 is documented as the semantic parent; support/class declarations are in H while child definitions remain routed through CPP; `SeparatorMenuItem` is explicitly abstract with no extra fields; unsupported explicit derived destructors are removed; and the current IDA `MenuItemVtbl` collision is documented without mutating IDA.
- Confidence: very strong. The physical data, class names, single-inheritance chains, slot order, wrapper sizes, vptr stores, and source/compiler boundary are direct live IDA facts. Human-facing lexical spellings remain inferred where stripped, but no final recommendation retains an IDA-generated label.

## Supporting Research

- This report began as the report-first artifact for the sole observed `Empty Emitter Marker` in generated `NexusTK/ui/menu/PopupMenuControls.cpp`; the accepted ordinary callback has now repaired the documentary/formal source cause, while generated verification remains supervisor-owned.
- Live read-only MCP session: IDB session `b3b2bf88`, `NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, MCP health `status=ok`, Hex-Rays ready, IDB list `is_analyzing=false`. `server_health` reported `auto_analysis_ready=false`; that flag did not prevent exact bytes, integer reads, decompilation, type inspection, comments, or xrefs from returning coherent current results.
- The exact target artifact SHA256 before any callback edit is `550484A238972EC6613B3819DE9C2C706F9B41005B2F28CEAE3E79808A6B4C02`, size `15481` bytes, last write `2026-07-24 19:57:29` local.
- Historical callback-time generated checkpoint only: `PopupMenuControls.cpp` had SHA256 `B0509C4D42D69AE08A8586ADC7F5CDC131650BEA0E3CB26C9DDADE80B91F8F8D`, size `14791` bytes, under validator command `000000020546`, refreshed `2026-08-01T06:02:15-04:00`; this is not asserted as the current generated-file state, and C36I-098-C36I-101 remain supervisor-owned and unchecked.
- Relevant executed reports were searched by `00036I`, `0x0061eb94`, `MenuItemVtableData`, `MenuItemVtables`, `SeparatorMenuItem`, `purecall`, and `PopupMenuControls`. Directly useful validated history was found in B008 `0000MN-PopupMenuControls-empty-emitter-family-source-quality.md`, B015 `0002JB-SeparatorMenuItemConstructor-source-quality.md`, B013 `0002J8-StringMenuItemMeasureText-source-quality.md`, B009 `0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md`, B005 `0002JJ-MenuItemCopyBoundsRect-source-quality.md`, and B003 popup-menu family reports.
- Previous reports were treated as leads and historical corroboration. Current MCP reads and current by-* artifacts control every recommendation below.

## Target

- Target UID: `00036I`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:00036I] `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`, exact three-class COL/vtable run and sole current PopupMenuControls empty emitter.
- Target path: `source-3/project-documentation/by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` line 1726, `86/91`, reconstructable, zero direct/additional reports before this assignment.
- Current supervisor classification: exact repaired report SHA256 `E5F92BCCC8137D077946B5926473E29E2281DE6BD598FAF42114C8939A03F1F7` passed supervisor Gate 1 and received the same-agent ordinary implementation callback. B003 then reread all accepted ordinary destinations, confirmed C36I-001-C36I-055 and C36I-102-C36I-105 already present at the exact accepted hashes and report-level detail, and freshly revalidated C36I-091-C36I-097. C36I-056-C36I-090 and C36I-098-C36I-101 remain explicitly supervisor-owned and unchecked.
- Current scores and parent state: target `94/95` with direct semantic owner/emitter UID0001Y4; file root UID0000MN is `88/88`; semantic vtable page UID0001Y4 is `93/95` and continues to emit through UID0000MN at position `13` with `[[CHILDREN]]`.

## Current Target State

- Current metadata: `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:0001Y4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001Y4`, blank position, exact formal CPP compiler-regeneration marker, blank formal H.
- Current owner/emitter/reconstructable state: reconstructability and the semantic UID00036I -> UID0001Y4 -> UID0000MN route are physically documented; UID0000MN remains the source root.
- Current ordinary C++/emitter state: support and class declarations are in H channels; class CPP channels contain only `[[CHILDREN]]`; UID00036I carries the exact no-code marker. This callback did not refresh or verify generated output, and the four generated obligations remain supervisor-owned.
- Supervisor-owned state: C36I-056-C36I-083 define the reconciled Gate 2B UDT/function/data/protection transaction; C36I-084-C36I-090 define manual coverage work; C36I-098-C36I-101 define generated verification. Their authoritative completion comes only from external supervisor readbacks and validator lifecycle state, so they remain unchecked here.
- Resolved ordinary contradictions: Separator is documented as abstract; all three class formals omit unsupported explicit derived destructors; shared wrapper behavior is historicalized as compiler output. The existing IDA `MenuItem.lpVtbl` collision remains documented and unchanged. Live read-only session `b3b2bf88` at `2026-08-01T09:20:46-04:00` confirmed only four pre-mutation prototype drifts: `0x5172e0` and `0x517400` are both `LObject *__thiscall(LObject *Block, char)`, `0x517090` is `_DWORD *__thiscall(char *this, _DWORD *, GrafPort *)`, and `0x517250` is `void __thiscall(_DWORD *this, GrafPort *)`.
- Related target/support docs checked: UID0000MN, UID00007V, UID0000E8, UID0000CY, UID0001Y4, UID0001V5, UID0001BK, UID00025T, exact constructors UID0002J3/0002J6/0002JB, exact virtuals UID0002J8/0002J9/0002JA/0002JC/0002JD/0002JE, wrappers UID0002JF/0002JG, and nonvirtual bounds UID0002JJ/0002JK.
- Current artifact/lifecycle status: authoritative current report state is the physical report path named by the assignment; execution/archive state remains supervisor-owned and validator-owned.

## Executive Recommendation

- Best direct semantic owner/emitter: [UID:0001Y4] `by-type/by-vtable/MenuItemVtables.md`. It represents the same three-class table family, already has a compiler-regeneration formal marker and child hook, clears the strict gate, and emits through source file UID0000MN.
- Canonical source file: retain [UID:0000MN] `NexusTK/ui/menu/PopupMenuControls.cpp` as current file root. A historical `MenuItem.cpp` split is plausible but not supported strongly enough to override the coherent current family grouping.
- Target disposition: no split, merge, rename, or non-reconstructable downgrade. Preserve the exact half-open range and make it a child of UID0001Y4.
- Source disposition: emit only the exact target formal CPP comment; leave target H blank. Put actual declarations in the support pages' H channels and actual method bodies in their exact by-memory CPP channels.
- IDA disposition: after a fresh Gate 1 pass, supervisor Gate 2B should use the `2026-08-01T09:20:46-04:00` reconciliation matrix below, repair the vtable-type collision, add the six still-absent project UDTs, apply exact slot types/source-quality names/comments, and preserve decorated MSVC RTTI/vtable symbols. The four current-prototype drifts change only literal prestates; they do not change the accepted semantic actions or expected readbacks.
- Assignment condition and lifecycle order: Gate 1 passed for exact pre-callback SHA256 `E5F92BCCC8137D077946B5926473E29E2281DE6BD598FAF42114C8939A03F1F7`, after which the same-agent ordinary callback reconfirmed and revalidated all authorized ordinary claims. The invariant order remains Gate 1 -> same-agent ordinary callback -> supervisor Gate 2A -> supervisor Gate 2B -> combined Gate 2 -> supervisor-only report execution/archive and post-move verification; authoritative stage state remains external to ordinary report prose.

## Supervisor Active Recheck

- The assignment requires complete research of hierarchy, slot attribution, RTTI, wrappers, layout, source cause, and every target-affecting open question before any implementation.
- No split repair is required. The range contains exactly three complete COL-pointer-plus-vtable records with no interior padding and terminates at the first UTF-16 resource string dword.
- Every source-bearing dependency in scope already has an exact documentation page. This report supplies implementation-ready repairs rather than creating duplicate children.
- The sole empty-emitter cause is formal-channel/routing state, not missing binary analysis: target formal CPP is empty and the target bypasses the semantic vtable parent whose child hook is already present.
- Historical report-first phase: before Gate 1 acceptance, no by-* files, manual coverage files, generated files, trackers, goal/notes, lifecycle state, or IDA database state were changed. The later authorized ordinary callback is recorded under Changed Files and Validator Results.

## Inference Research Guidance Check

- `by-structure.md` requires direct semantic ownership and permits compiler-generated data to emit a minimal formal covered-by/no-code comment. That rule rejects both a blank formal emitter and handwritten raw vtable arrays.
- Existing assumptions were rechecked rather than inherited: direct file ownership, partly unresolved hierarchy, explicit derived destructors, separator concreteness, and the safety of the current IDA UDT were all treated as uncertain.
- Direct IDA facts are identified as bytes, dwords, decorated RTTI names, CHD/base arrays, types, comments, xrefs, constructors, wrappers, and function bodies. Documentation evidence is identified by UID/path. Human-source choices are identified as high-probability inference.
- Wave2/Wave3 mentions occur in historical documents. They were ignored as stale process labels and were not used as evidence or workflow authority.
- Source reconstruction follows the dual standard: runtime semantics and ABI-visible layout must match the binary, while authored code must look like plausible late-1999 through mid-2000s human C++, with realistic inferred names instead of `sub_`, `dword_`, or decompiler-shaped source.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best supported resolution | Direct evidence | Rejected alternatives | Classification / impact |
| --- | --- | --- | --- | --- |
| Exact family hierarchy | `MenuItem : LObject`; `StringMenuItem : MenuItem`; `SeparatorMenuItem : MenuItem`; all are single, nonvirtual inheritance. | Menu CHD has two bases; String and Separator CHDs each have three; arrays are self/MenuItem/LObject as applicable; CHD attributes are zero and all PMDs are `0,-1,0`. | Multiple inheritance, sibling-only classes, composition. | Original class names/hierarchy are RTTI-proven. |
| Base slot identities | `+0x00` deleting destructor, `+0x04 GetRuntimeClass`, `+0x08 OnChangeMessage`, `+0x0c GetItemSize`, `+0x10 GetText`, `+0x14 DrawItem`. | Exact dwords; current typed functions `LObject__GetRuntimeClass` and `LObject__OnChangeMessage`; String implementations at the three pure slots. | Treating `+0x04/+0x08` as anonymous support; including GetBounds/SetBounds. | Source-facing names are behavior/contract-backed. |
| MenuItem abstractness | `MenuItem` is abstract with three pure virtual application slots. | Three consecutive `__purecall` cells at `0x61eba4/8/c`. | Concrete base with null methods; raw function placeholders. | Exact source declaration uses three `= 0` members. |
| Separator abstractness | `SeparatorMenuItem` remains abstract: it overrides DrawItem but leaves GetItemSize and GetText pure, then adds GetDefaultDimensions and GetStyleFlags. | Separator slots `+0x0c/+0x10` are `__purecall`; `+0x14/+0x18/+0x1c` are exact separator functions; RTTI excludes a secondary facet. | Claiming fixed dimensions occupies base `+0x0c`; multiple vtables; inventing GetText implementation. | Closes a prior caveat; no concrete instantiation is claimed. |
| Separator liveness | Retained abstract source class with compiled out-of-line constructor/methods but no surviving direct constructor route. | Zero xrefs to `0x5171b0`; no literal VA bytes; only vtable immediate `0x61ebd0` occurs in its constructor. | Calling the class compiler-only; claiming active instantiation without evidence. | Lack of callers caps usage claims, not hierarchy/source shape. |
| Destructor source shape | Rely on implicit derived destructors inherited as virtual from `LObject`; do not declare or handwrite separate MenuItem-family destructors unless future source proof appears. | `LObject` declares virtual destructor; Menu/Separator share one `0x18` wrapper; String has a `0x118` wrapper; wrappers are vtable-only and perform compiler delete lowering. | Handwritten scalar wrapper; explicit unsupported Separator destructor; separate String cleanup for inline wchar array. | Removes undefined/unproven declarations while preserving compiler generation. |
| String size/layout | `StringMenuItem` is `0x118`: `MenuItem` base `0x18` plus inline `wchar_t m_text[0x80]` (`0x100`). | Constructor/copy/measure/draw offsets; wrapper delete-size immediate `0x118`. | Pointer/string-object label; heap-owned label. | Exact layout, inferred human member name. |
| Separator size/layout | `SeparatorMenuItem` is `0x18` with no new fields. | Base wrapper size `0x18` reused; constructor only touches inherited state/bounds/vptr. | Hidden separator fields; separate state word. | Exact minimum/full observed size. |
| Metric return type | `MenuItemMetrics { int height; int width; }`, returned by value via hidden result pointer. | String writer stores `14` then width+24; separator writer stores `6` then `20`; binary returns result pointer. | Win32 `SIZE`; two unrelated outputs; primitive return. | High-probability descriptive source type. |
| Style return type | `MenuItemStyleFlags { unsigned short bits; }`, returned by value via hidden result pointer. | `0x517240` writes a 16-bit zero through caller result and `retn 4`; primitive 16-bit return would use AX. | Primitive `unsigned short` return; raw out parameter as original source. | ABI resolves UDT-vs-primitive; lexical type name inferred. |
| Bounds methods | `GetBounds`/`SetBounds` are retained nonvirtual members and not part of this data. | Finite six-slot base table excludes `0x516fb0/0x516fd0`; exact method pages show whole RectBounds copies. | Adding virtual slots; treating methods as dead padding. | Existing no-slot proof remains valid. |
| Direct owner | UID0001Y4, not UID0000MN directly. | Same three-class semantic scope, gate `86/91`, child hook, established vtable-data-to-vtable-page project patterns. | One class owner; mixed memory parent; direct file bypass. | Owner/emitter change recommended. |
| Source placement | Current `ui/menu/PopupMenuControls` grouping. | All class/method/type pages route there; generated source is coherent; no competing exact original path evidence. | Forced `MenuItem.cpp`, `SeparatorMenuItem.cpp`, feature-dialog ownership. | Current placement accepted; possible historical split is nonblocking. |
| Empty-emitter cause | Empty formal target CPP plus wrong direct sibling route. | Current metadata and generated line 432; UID0001Y4 says `[[No Children Attached]]`. | Missing method body; validator defect; non-reconstructable data. | Exact formal comment and semantic child route close it. |
| IDA type state | Preserve imported COM `MenuItemVtbl`; introduce collision-free NexusTK vtable UDTs and repair custom `MenuItem::lpVtbl`. | `MenuItem` is 24 bytes with custom fields; current `MenuItemVtbl` is unrelated 52-byte 13-slot COM interface; derived/type UDTs are absent. | Overwriting/renaming SDK COM type; accepting wrong 52-byte layout. | High-confidence Gate 2B repair. |

No open question is deferred as "needs investigation." Residual lexical/file-split uncertainty is resolved to the best consistent source model and used only as a below-final-perfect score cap.

## Evidence Standards Used

- Primary evidence: live MCP exact bytes, little-endian dword reads, current names/types/comments, RTTI COL/CHD/base-array decoding, xrefs, bounded pointer patterns, decompilation, function sizes, and wrapper delete-size constants.
- Secondary evidence: current by-memory, by-class, by-type, and by-file docs; current generated source; manual coverage rows; matching executed B reports.
- Negative evidence: no xrefs to COL-pointer cells, no direct MenuItem/Separator constructor xrefs, no literal separator-constructor VA, vtable-only wrapper references, and finite table boundaries excluding nonvirtual helpers.
- Evidence ladder application: decorated RTTI and exact table bytes establish identity/hierarchy; constructors/wrappers establish object sizes and vptr use; method bodies establish source contracts; documentation/generated output establish routing and formal-channel state; heuristic inference supplies only lost lexical spellings/source grouping.
- Tool limitation: MCP health exposed `auto_analysis_ready=false`, but the adopted IDB was idle and every required narrow read succeeded. No inference rests on a failed decompile or unavailable target byte.

## Evidence Checked

- IDA MCP: `initialize`, `tools/list`, `idb_list`, `server_health`, `get_bytes`, `get_int`, `inspect_items`, `get_comments`, `type_query`, `type_inspect`, `xrefs_to`, `find_bytes`, and `analyze_batch` against session `b3b2bf88`.
- Exact binary ranges: `0x61eb90-0x61ebf8`; COLs `0x64b604`, `0x64b6d4`, `0x64b724`; CHDs `0x64b618`, `0x64b6e8`, `0x64b738`; base arrays `0x64b628`, `0x64b6f8`, `0x64b748`; base descriptors `0x64b634`, `0x640348`, `0x64b708`, `0x64b758`.
- Exact functions: constructors `0x516f00`, `0x516ff0`, `0x5171b0`; wrappers `0x5172e0`, `0x517400`; inherited slots `0x4f4b10`, `0x41b6c0`; purecall `0x5ca28c`; application slots `0x517090`, `0x5170d0`, `0x5170f0`, `0x517220`, `0x517240`, `0x517250`.
- Pointer patterns: vtable VAs `98 EB 61 00`, `B4 EB 61 00`, `D0 EB 61 00`; constructor VA `B0 71 51 00`; wrapper VAs `E0 72 51 00`, `00 74 51 00`.
- Documentation: all target-affecting pages listed in Current Target State, generated `PopupMenuControls.cpp`, the research tracker, and all five relevant manual coverage reports.
- Existing reports: matching executed B008/B015/B013/B009/B005/B003 reports. Nonmatching reports were not opened.
- Failed/unavailable checks: no stable original source archive or symbol file exists. This does not prevent a human-source recommendation because exact RTTI class names, virtual order, object layout, and behavior are present; only lexical member/type spelling remains inferential.

## Claim And Incorporation Ledger

Ledger verification cells preserve atomic obligation wording across callback cycles. For C36I-001-C36I-055 and C36I-102-C36I-105, `callback-applied/readback-verified` or `callback unchanged-readback-verified` now means the current callback found the claim already present at same-or-greater report-level detail and at the exact destination hashes recorded under Changed Files. The literal `supervisor Gate 2A unchecked` suffix is historical callback-time bookkeeping, not a claim about external supervisor state. C36I-091-C36I-097 are superseded by the fresh validator identities recorded below. Supervisor-owned C36I-056-C36I-090 and C36I-098-C36I-101 remain unchecked without scope change.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C36I-001 | 00036I | Preserve exact `0x0061eb94-0x0061ebf0` range, its three record boundaries, no-padding proof, predecessor, and `MENUBACK.EPF` successor. | Direct | bytes, dwords, finite boundaries | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Range and Boundaries | replace/refine section only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-002 | 00036I | Record MenuItem -> LObject, StringMenuItem -> MenuItem -> LObject, SeparatorMenuItem -> MenuItem -> LObject, CHD attrs zero, and PMD `0,-1,0`. | Direct | COL/CHD/base arrays | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / RTTI Hierarchy | add exact table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-003 | 00036I | Record exact 6/6/8 slot tables at `0x61eb98`, `0x61ebb4`, and `0x61ebd0`, including inherited LObject slots and purecalls. | Direct | dwords, names, function bodies | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Slot Map | replace/refine table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-004 | 00036I | Explain abstract MenuItem, concrete StringMenuItem, abstract SeparatorMenuItem, and nonvirtual GetBounds/SetBounds. | Direct/strong inference | finite tables and concrete bodies | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Source Class Shape | add exact prose/table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-005 | 00036I | Record object sizes `0x18`, `0x118`, `0x18` and inline String text `wchar_t[0x80]` at `+0x18`. | Direct/strong | wrappers, constructors, accessors | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Object Layout | add exact table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-006 | 00036I | Record folded Menu/Separator wrapper `0x5172e0`, String wrapper `0x517400`, and implicit derived-destructor source disposition. | Direct/structural | vtable refs, wrapper sizes/bodies | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Wrapper And Destructor Disposition | add exact rationale | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-007 | 00036I | Preserve 54 String constructor xrefs, zero Menu/Separator constructor-start xrefs, zero Separator VA hits, and retained-source interpretation. | Direct/negative/inference | xrefs and byte search | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Reachability And Negative Evidence | add exact evidence | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-008 | 00036I | Route direct owner/emitter from UID0000MN to semantic parent UID0001Y4 while retaining UID0000MN as source-file root. | Strong inference | current route and narrower semantic scope | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Ownership And Emission | change route | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-009 | 00036I | Set target metadata to completion 94, confidence 95, canonical owner/emitter 0001Y4, reconstructable true, blank position. | Analytical | all target blockers resolved | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / metadata header | replace exact fields | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-010 | 00036I | Insert the exact compiler-regenerated no-raw-vtable formal comment. | Rule/direct | compiler data and current empty marker | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / `RECONSTRUCTION_CPP` | replace blank CPP block | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-011 | 00036I | Keep formal header block blank because this range is compiler `.rdata`, not declaration source. | Source distinction | compiler/source boundary | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / `RECONSTRUCTION_H` | verify blank | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-012 | 00036I | Replace Item Summary with the exact three-class RTTI/vtable/source-cause summary in Recommended Target Doc Changes. | Direct/synthesized | complete report evidence | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Item Summary | replace exact text | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-013 | 0001Y4 | Add exact CHD/base arrays and single-inheritance hierarchy. | Direct | RTTI decode | `by-type/by-vtable/MenuItemVtables.md` / RTTI Hierarchy | add exact table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-014 | 0001Y4 | Replace/refine complete Menu/String/Separator 6/6/8 slot contract and abstractness. | Direct/strong | dwords and bodies | `by-type/by-vtable/MenuItemVtables.md` / Slot Contract | replace/refine table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-015 | 0001Y4 | Add wrapper sizes, fold, implicit-destructor source shape, and no-handwritten-wrapper rule. | Direct/structural | wrappers and vtable refs | `by-type/by-vtable/MenuItemVtables.md` / Destructor Wrapper Disposition | add exact evidence | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-016 | 0001Y4 | Attach UID00036I through `[[CHILDREN]]` and retain UID0000MN owner/emitter position 13. | Documentation/routing | semantic parent gate | `by-type/by-vtable/MenuItemVtables.md` / metadata and formal CPP | change child route only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-017 | 0001Y4 | Record current custom/COM IDA type collision and collision-free proposed project vtable types. | Direct | live `type_inspect` | `by-type/by-vtable/MenuItemVtables.md` / IDA Type State | add exact prestate | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-018 | 0001Y4 | Set completion/confidence to 93/95; retain owner/emitter 0000MN, position 13, CPP marker/children, blank H. | Analytical | complete hierarchy/slots/route | `by-type/by-vtable/MenuItemVtables.md` / metadata header | replace exact scores only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-019 | 0001V5 | Record exact MenuItem/String/Separator layouts and natural tail padding. | Direct/strong | constructors, fields, wrappers | `by-type/by-struct/MenuItemLayouts.md` / Layouts | replace/refine table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-020 | 0001V5 | Define source-facing `MenuItemMetrics` as height/width `int` fields, size 8. | Direct/strong naming | hidden-result writers | `by-type/by-struct/MenuItemLayouts.md` / `RECONSTRUCTION_H` | insert exact declaration | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-021 | 0001V5 | Define source-facing `MenuItemStyleFlags` as 2-byte UDT with `unsigned short bits`. | Direct ABI/strong naming | hidden-result pointer and `retn 4` | `by-type/by-struct/MenuItemLayouts.md` / `RECONSTRUCTION_H` | insert exact declaration | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-022 | 0001V5 | Move all support declarations to H and add one `#include "PopupMenuControls.h"` to CPP. | Compile/source shape | declaration/body split | `by-type/by-struct/MenuItemLayouts.md` / formal CPP and H | replace both exact blocks | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-023 | 0001V5 | Add current IDA type presence/absence and collision state. | Direct | live `type_inspect`/`type_query` | `by-type/by-struct/MenuItemLayouts.md` / IDA Type State | add exact table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-024 | 0001V5 | Set completion/confidence to 92/94; retain current owner/emitter/reconstructable route. | Analytical | exact layouts/ABI/H channel | `by-type/by-struct/MenuItemLayouts.md` / metadata header | replace exact scores only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-025 | 00007V | Add exact two-class RTTI chain, six-slot abstract contract, `0x18` layout, and nonvirtual bounds pair. | Direct/strong | RTTI/table/wrapper | `by-class/MenuItem.md` / Hierarchy And Virtual Contract | replace/refine section | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-026 | 00007V | Preserve compiler-wrapper evidence but remove unsupported explicit derived-destructor declaration. | Structural | virtual base destructor and folded wrapper | `by-class/MenuItem.md` / Destructor Source Shape | replace stale claim | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-027 | 00007V | Move class declaration to H; leave CPP as `[[CHILDREN]]` only. | Source-quality rule | declaration/body ownership | `by-class/MenuItem.md` / formal CPP and H | replace both exact blocks | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-028 | 00007V | Set completion/confidence to 93/94; retain owner/emitter UID0000MN. | Analytical | hierarchy/slots/layout resolved | `by-class/MenuItem.md` / metadata header | replace exact scores only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-029 | 00007V | Add UID0001Y4 -> UID00036I semantic-data route and preserve UID0000MN source root. | Strong inference | parent/file evidence | `by-class/MenuItem.md` / Ownership And Emission | add exact route | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-030 | 00007V | Preserve historical raw-wrapper/destructor and no-slot alternatives with rejection reasons. | Historical/negative | prior docs plus current proof | `by-class/MenuItem.md` / Historical Assumptions | retain and annotate | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-031 | 0000E8 | Add exact three-class RTTI chain, concrete six-slot contract, inline text, and `0x118` size. | Direct/strong | RTTI/table/wrapper | `by-class/StringMenuItem.md` / Hierarchy And Virtual Contract | replace/refine section | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-032 | 0000E8 | Add 54 constructor callers and String-only deleting-wrapper proof. | Direct | live xrefs and wrapper | `by-class/StringMenuItem.md` / Reachability And Destruction | add exact evidence | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-033 | 0000E8 | Remove unsupported explicit derived destructor and explain implicit source shape. | Structural | virtual base destructor and trivial inline text | `by-class/StringMenuItem.md` / Destructor Source Shape | replace stale claim | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-034 | 0000E8 | Move class declaration to H; leave CPP as `[[CHILDREN]]` only. | Source-quality rule | declaration/body ownership | `by-class/StringMenuItem.md` / formal CPP and H | replace both exact blocks | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-035 | 0000E8 | Set completion/confidence to 92/94; retain owner/emitter UID0000MN. | Analytical | contract/layout/reachability resolved | `by-class/StringMenuItem.md` / metadata header | replace exact scores only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-036 | 0000E8 | Add UID0001Y4 -> UID00036I semantic-data route and preserve historical naming caveats. | Strong inference/historical | parent/file evidence | `by-class/StringMenuItem.md` / Ownership And History | add route; retain rejected aliases | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-037 | 0000CY | Add exact three-class RTTI chain and state that Separator remains abstract at GetItemSize/GetText. | Direct | RTTI and purecall slots | `by-class/SeparatorMenuItem.md` / Hierarchy And Virtual Contract | replace/refine section | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-038 | 0000CY | Record DrawItem plus GetDefaultDimensions/GetStyleFlags slots and reject conflating the latter with base size. | Direct/strong | table and bodies | `by-class/SeparatorMenuItem.md` / Virtual Methods | replace/refine table | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-039 | 0000CY | Record no derived fields, size `0x18`, folded Menu wrapper, and implicit derived destructor. | Direct/structural | wrapper/table/layout | `by-class/SeparatorMenuItem.md` / Layout And Destruction | replace stale claim | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-040 | 0000CY | Preserve disabled constructor body and zero caller/VA-hit negative evidence as retained abstract source. | Direct/negative/inference | body/xrefs/find_bytes | `by-class/SeparatorMenuItem.md` / Reachability And Liveness | add exact evidence | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-041 | 0000CY | Move class declaration to H; leave CPP as `[[CHILDREN]]` only. | Source-quality rule | declaration/body ownership | `by-class/SeparatorMenuItem.md` / formal CPP and H | replace both exact blocks | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-042 | 0000CY | Set completion/confidence to 92/94; retain owner/emitter UID0000MN. | Analytical | abstractness/layout/wrapper resolved | `by-class/SeparatorMenuItem.md` / metadata header | replace exact scores only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-043 | 0000CY | Add UID0001Y4 -> UID00036I semantic-data route and preserve rejected concrete/separate-destructor assumptions. | Strong inference/historical | parent/file evidence | `by-class/SeparatorMenuItem.md` / Ownership And History | add route; annotate history | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-044 | 0000MN | Document `PopupMenuControls.h/.cpp` as current coherent source root and the UID0001Y4 -> UID00036I semantic route. | Strong inference | current family grouping | `by-file/PopupMenuControls.md` / Source Placement And Routing | replace/refine section | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-045 | 0000MN | Document generated H declarations, generated CPP include, child method ownership, and no raw RTTI/wrapper output. | Source-quality rule | formal-channel plan | `by-file/PopupMenuControls.md` / Header And Source Contract | add exact contract | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-046 | 0000MN | Preserve a possible historical physical split only as a below-perfect caveat, not an implementation blocker. | Inference/negative | no discriminating filename evidence | `by-file/PopupMenuControls.md` / Historical Source Split | add bounded caveat | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-047 | 0000MN | Set completion/confidence to 88/88; retain current reconstructable source-root role. | Analytical | sole-empty closure and header route | `by-file/PopupMenuControls.md` / metadata header | replace exact scores only | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-048 | 0002J8 | Retain the method page and use it as exact body/xref evidence; no metadata/body change is recommended by this report. | Direct | exact `0x517090-0x5170d0` body | `by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-049 | 0002J9 | Retain the method page and use it as exact body/xref evidence; no metadata/body change is recommended by this report. | Direct | exact `0x5170d0-0x5170e9` body | `by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-050 | 0002JA | Retain the method page and use it as exact body/xref evidence; no metadata/body change is recommended by this report. | Direct | exact `0x5170f0-0x5171a2` body | `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-051 | 0002JC | Retain the method page and use it as exact body/xref evidence; no metadata/body change is recommended by this report. | Direct | exact `0x517220-0x517237` body | `by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-052 | 0002JD | Retain the method page and use it as exact body/xref evidence; no metadata/body change is recommended by this report. | Direct | exact `0x517240-0x51724f` body | `by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-053 | 0002JE | Retain the method page and use it as exact body/xref evidence; no metadata/body change is recommended by this report. | Direct | exact `0x517250-0x5172be` body | `by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-054 | 0002JF | Retain compiler-wrapper no-code page; never emit wrapper C++. | Direct/compiler | exact `0x5172e0-0x51731e` wrapper | `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-055 | 0002JG | Retain compiler-wrapper no-code page; never emit wrapper C++. | Direct/compiler | exact `0x517400-0x517441` wrapper | `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md` / current content | verify unchanged; link from support prose only | callback unchanged-readback-verified; supervisor Gate 2A unchecked |
| C36I-056 | 00036I | Repair only current 24-byte `MenuItem.lpVtbl` from `MenuItemVtbl *` to `NexusTKMenuItemVtable *`; preserve all five members/offsets and every other type. | Direct | live `type_inspect`: size 24, five members, `lpVtbl +0 MenuItemVtbl *` | `IDA/b3b2bf88` / UDT `MenuItem` | supervisor Gate 2B type edit under exact stop/rollback matrix | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor action unchecked |
| C36I-057 | 00036I | Create currently absent six-slot `NexusTKMenuItemVtable` UDT exactly as specified. | Direct/strong typing | `type_inspect` not found and exact `type_query` total 0; dependencies itemized below | `IDA/b3b2bf88` / UDT `NexusTKMenuItemVtable` | supervisor Gate 2B type add under exact stop/rollback matrix | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor action unchecked |
| C36I-058 | 00036I | Create currently absent eight-slot `NexusTKSeparatorMenuItemVtable` UDT exactly as specified. | Direct/strong typing | `type_inspect` not found and exact `type_query` total 0; dependencies itemized below | `IDA/b3b2bf88` / UDT `NexusTKSeparatorMenuItemVtable` | supervisor Gate 2B type add under exact stop/rollback matrix | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor action unchecked |
| C36I-059 | 00036I | Create currently absent `StringMenuItem` UDT with base at 0 and text at `+0x18`, size `0x118`. | Direct/strong | `type_inspect` not found and exact `type_query` total 0; existing `MenuItem` dependency read back | `IDA/b3b2bf88` / UDT `StringMenuItem` | supervisor Gate 2B type add under exact stop/rollback matrix | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor action unchecked |
| C36I-060 | 00036I | Create currently absent `SeparatorMenuItem` UDT as flattened MenuItem base, size `0x18`. | Direct/strong | `type_inspect` not found and exact `type_query` total 0; existing `MenuItem` dependency read back | `IDA/b3b2bf88` / UDT `SeparatorMenuItem` | supervisor Gate 2B type add under exact stop/rollback matrix | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor action unchecked |
| C36I-061 | 00036I | Create currently absent `MenuItemMetrics` UDT with `height/width` at 0/4, size 8. | Direct/strong | hidden-result writes plus `type_inspect` not found and exact `type_query` total 0 | `IDA/b3b2bf88` / UDT `MenuItemMetrics` | supervisor Gate 2B type add under exact stop/rollback matrix | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor action unchecked |
| C36I-062 | 00036I | Create currently absent `MenuItemStyleFlags` UDT with `unsigned short bits` at 0, size 2. | Direct ABI/strong naming | hidden-result write plus `type_inspect` not found and exact `type_query` total 0 | `IDA/b3b2bf88` / UDT `MenuItemStyleFlags` | supervisor Gate 2B type add under exact stop/rollback matrix | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor action unchecked |
| C36I-063 | 00036I | Preserve current imported 52-byte, 13-member COM `MenuItemVtbl` unchanged. | Direct/protection | live `type_inspect`: `QueryInterface +0` through `get_Enabled +0x30` | `IDA/b3b2bf88` / UDT `MenuItemVtbl` | supervisor no-change readback; stop on any drift | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor readback unchecked |
| C36I-064 | 00036I | Preserve current 16-byte `RectBounds` with four `int` members at 0/4/8/c unchanged. | Direct/protection | live `type_inspect`: `left/top/right/bottom` | `IDA/b3b2bf88` / UDT `RectBounds` | supervisor no-change readback; stop on any drift | fresh read-only `2026-08-01T09:20:46-04:00`; supervisor readback unchecked |
| C36I-065 | 00036I | From current `sub_5172E0`, `LObject *__thiscall(LObject *Block, char)`, rename/type/comment exact wrapper `0x5172e0-0x51731e`. | Direct/strong | live prototype, decompile, frame, four absent comment channels, two table refs | `IDA/b3b2bf88` / function `0x5172e0` | supervisor Gate 2B function action under exact stop/rollback matrix | wrapper prototype drift reconciled; supervisor action unchecked |
| C36I-066 | 00036I | From current `sub_517400`, `LObject *__thiscall(LObject *Block, char)`, rename/type/comment exact wrapper `0x517400-0x517441`. | Direct/strong | live prototype, decompile, frame, four absent comment channels, one table ref | `IDA/b3b2bf88` / function `0x517400` | supervisor Gate 2B function action under exact stop/rollback matrix | wrapper prototype drift reconciled; supervisor action unchecked |
| C36I-067 | 00036I | From current `sub_517090`, `_DWORD *__thiscall(char *this, _DWORD *, GrafPort *)`, rename/type/comment exact String size method `0x517090-0x5170d0`. | Direct/strong | live prototype, decompile, frame, four absent comment channels, slot ref | `IDA/b3b2bf88` / function `0x517090` | supervisor Gate 2B function action under exact stop/rollback matrix | third-argument prototype drift reconciled; supervisor action unchecked |
| C36I-068 | 00036I | From current `sub_5170D0`, `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)`, rename/type/comment exact String text method `0x5170d0-0x5170e9`. | Direct/strong | live prototype, decompile, frame, four absent comment channels, slot ref | `IDA/b3b2bf88` / function `0x5170d0` | supervisor Gate 2B function action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-069 | 00036I | From current `sub_5170F0`, `void __thiscall(int this, GrafPort *)`, rename/type/comment exact String draw method `0x5170f0-0x5171a2`. | Direct/strong | live prototype, decompile, frame, four absent comment channels, slot ref | `IDA/b3b2bf88` / function `0x5170f0` | supervisor Gate 2B function action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-070 | 00036I | From current `sub_517220`, `_DWORD *__stdcall(_DWORD *)`, rename/type/comment exact Separator dimensions method `0x517220-0x517237`. | Direct/strong | live prototype, decompile, frame, four absent comment channels, slot ref | `IDA/b3b2bf88` / function `0x517220` | supervisor Gate 2B function action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-071 | 00036I | From current `sub_517240`, `_WORD *__stdcall(_WORD *)`, rename/type/comment exact Separator style method `0x517240-0x51724f`. | Direct/strong | live prototype, decompile, frame, four absent comment channels, slot ref | `IDA/b3b2bf88` / function `0x517240` | supervisor Gate 2B function action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-072 | 00036I | From current `sub_517250`, `void __thiscall(_DWORD *this, GrafPort *)`, rename/type/comment exact Separator draw method `0x517250-0x5172be`. | Direct/strong | live prototype, decompile, frame with `RectBounds`, four absent comments, slot ref | `IDA/b3b2bf88` / function `0x517250` | supervisor Gate 2B function action under exact stop/rollback matrix | return/argument prototype drift reconciled; supervisor action unchecked |
| C36I-073 | 00036I | From current `LObject__GetRuntimeClass`, `RuntimeClass *__thiscall(LObject *this)`, replace only the exact regular function comment at `0x4f4b10`; preserve name/type and three absent channels. | Direct | live comment/type/frame and 489 xrefs | `IDA/b3b2bf88` / function `0x4f4b10` | supervisor Gate 2B comment-only action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-074 | 00036I | From current `LObject__OnChangeMessage`, `void __thiscall(LObject *this, LObject *owner, Message *message)`, replace only the exact three-line regular function comment at `0x41b6c0`; preserve folded identity/type and three absent channels. | Direct | live comment/type/frame and 517 xrefs | `IDA/b3b2bf88` / function `0x41b6c0` | supervisor Gate 2B comment-only action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-075 | 00036I | From current unnamed/untyped/commentless 4-byte item with zero xrefs at `0x61eb94`, add exact repeatable COL-pointer comment only. | Direct | live item/comment/xrefs and pointer value `0x64b604` | `IDA/b3b2bf88` / data `0x61eb94` | supervisor Gate 2B comment action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-076 | 00036I | From current 4-byte head `??_7MenuItem@@6B@`, absent type/comments, five xrefs, apply six-slot UDT/comment to `0x61eb98-0x61ebb0`. | Direct | live item/comment/xrefs; decorated name protected | `IDA/b3b2bf88` / data `0x61eb98` | supervisor Gate 2B type/comment action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-077 | 00036I | From current unnamed/untyped/commentless 4-byte item with zero xrefs at `0x61ebb0`, add exact repeatable COL-pointer comment only. | Direct | live item/comment/xrefs and pointer value `0x64b6d4` | `IDA/b3b2bf88` / data `0x61ebb0` | supervisor Gate 2B comment action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-078 | 00036I | From current 4-byte head `??_7StringMenuItem@@6B@`, absent type/comments, one xref, apply six-slot UDT/comment to `0x61ebb4-0x61ebcc`. | Direct | live item/comment/xrefs; decorated name protected | `IDA/b3b2bf88` / data `0x61ebb4` | supervisor Gate 2B type/comment action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-079 | 00036I | From current unnamed/untyped/commentless 4-byte item with zero xrefs at `0x61ebcc`, add exact repeatable COL-pointer comment only. | Direct | live item/comment/xrefs and pointer value `0x64b724` | `IDA/b3b2bf88` / data `0x61ebcc` | supervisor Gate 2B comment action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-080 | 00036I | From current 4-byte head `??_7SeparatorMenuItem@@6B@`, absent type/comments, one xref, apply eight-slot UDT/comment to `0x61ebd0-0x61ebf0`. | Direct | live item/comment/xrefs; decorated name protected | `IDA/b3b2bf88` / data `0x61ebd0` | supervisor Gate 2B type/comment action under exact stop/rollback matrix | fresh read-only prestate unchanged; supervisor action unchecked |
| C36I-081 | 00036I | Preserve current 4-byte `??_R4MenuItem@@6B@`, absent type, regular `signature`, absent repeatable, and one xref at `0x64b604-0x64b608`. | Direct/protection | live item/comment/xref | `IDA/b3b2bf88` / RTTI item `0x64b604` | supervisor no-change readback; stop on any drift | fresh read-only prestate unchanged; supervisor readback unchecked |
| C36I-082 | 00036I | Preserve current 4-byte `??_R4StringMenuItem@@6B@`, absent type, regular `signature`, absent repeatable, and one xref at `0x64b6d4-0x64b6d8`. | Direct/protection | live item/comment/xref | `IDA/b3b2bf88` / RTTI item `0x64b6d4` | supervisor no-change readback; stop on any drift | fresh read-only prestate unchanged; supervisor readback unchecked |
| C36I-083 | 00036I | Preserve current 4-byte `??_R4SeparatorMenuItem@@6B@`, absent type, regular `signature`, absent repeatable, and one xref at `0x64b724-0x64b728`. | Direct/protection | live item/comment/xref | `IDA/b3b2bf88` / RTTI item `0x64b724` | supervisor no-change readback; stop on any drift | fresh read-only prestate unchanged; supervisor readback unchecked |
| C36I-084 | 00036I | Insert exact UID00036I row under UID00025T and before UID00025U. | Direct/manual | current row absent | `by-memory/-coverage-report.md` / UID00025T children | supervisor insert exact supplied text | research-verified; supervisor action unchecked |
| C36I-085 | 0001Y4 | Replace exact UID0001Y4 row. | Direct/manual | current row stale | `by-type/by-vtable/-coverage-report.md` / UID0001Y4 row | supervisor replace exact supplied text | research-verified; supervisor action unchecked |
| C36I-086 | 0001V5 | Replace exact UID0001V5 row. | Direct/manual | current row stale | `by-type/by-struct/-coverage-report.md` / UID0001V5 row | supervisor replace exact supplied text | research-verified; supervisor action unchecked |
| C36I-087 | 00007V | Replace exact UID00007V row. | Direct/manual | current row stale | `by-class/-coverage-report.md` / UID00007V row | supervisor replace exact supplied text | research-verified; supervisor action unchecked |
| C36I-088 | 0000E8 | Replace exact UID0000E8 row. | Direct/manual | current row stale | `by-class/-coverage-report.md` / UID0000E8 row | supervisor replace exact supplied text | research-verified; supervisor action unchecked |
| C36I-089 | 0000CY | Replace exact UID0000CY row. | Direct/manual | current row stale | `by-class/-coverage-report.md` / UID0000CY row | supervisor replace exact supplied text | research-verified; supervisor action unchecked |
| C36I-090 | 0000MN | Replace exact UID0000MN row. | Direct/manual | current row stale | `by-file/-coverage-report.md` / UID0000MN row | supervisor replace exact supplied text | research-verified; supervisor action unchecked |
| C36I-091 | 00036I | Run scoped file validator after callback edit. | Workflow | validator plan | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / whole file | run exact listed command | current callback validator `000000020670` passed, exit 0, ok 1; generated refresh skipped |
| C36I-092 | 0001Y4 | Run scoped file validator after callback edit. | Workflow | validator plan | `by-type/by-vtable/MenuItemVtables.md` / whole file | run exact listed command | current callback validator `000000020672` passed, exit 0, ok 1; generated refresh skipped |
| C36I-093 | 0001V5 | Run scoped file validator after callback edit. | Workflow | validator plan | `by-type/by-struct/MenuItemLayouts.md` / whole file | run exact listed command | current callback validator `000000020673` passed, exit 0, ok 1; generated refresh skipped |
| C36I-094 | 00007V | Run scoped file validator after callback edit. | Workflow | validator plan | `by-class/MenuItem.md` / whole file | run exact listed command | current callback validator `000000020674` passed, exit 0, ok 1; generated refresh skipped |
| C36I-095 | 0000E8 | Run scoped file validator after callback edit. | Workflow | validator plan | `by-class/StringMenuItem.md` / whole file | run exact listed command | current callback validator `000000020676` passed, exit 0, ok 1; generated refresh skipped |
| C36I-096 | 0000CY | Run scoped file validator after callback edit. | Workflow | validator plan | `by-class/SeparatorMenuItem.md` / whole file | run exact listed command | current callback validator `000000020677` passed, exit 0, ok 1; generated refresh skipped |
| C36I-097 | 0000MN | Run scoped file validator after callback edit. | Workflow | validator plan | `by-file/PopupMenuControls.md` / whole file | run exact listed command | current callback validator `000000020678` passed, exit 0, ok 1, with four preserved missing-ref warnings; generated refresh skipped |
| C36I-098 | 0001V5 | Verify generated header contains support UDTs and three class declarations exactly once. | Compile/generated | expected H channel | `auto-generated/NexusTK/ui/menu/PopupMenuControls.h` / generated declarations | supervisor read-only generated verification | research-verified; supervisor verification unchecked |
| C36I-099 | 0001V5 | Verify generated CPP includes `PopupMenuControls.h` before exact child method definitions. | Compile/generated | expected CPP channel | `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` / include and definitions | supervisor read-only generated verification | research-verified; supervisor verification unchecked |
| C36I-100 | 00036I | Verify generated CPP has no UID00036I empty marker and UID0001Y4 has attached children. | Generated routing | sole-empty source cause | `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` / UID00036I and UID0001Y4 markers | supervisor read-only generated verification | research-verified; supervisor verification unchecked |
| C36I-101 | 00036I | Verify generated H/CPP contain no raw RTTI/vtable arrays, wrapper bodies, duplicate declarations, or missing destructor definitions. | Compile/source quality | compiler/source disposition | `auto-generated/NexusTK/ui/menu/PopupMenuControls.h` and `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` / full generated pair | supervisor compile/content verification | research-verified; supervisor verification unchecked |
| C36I-102 | 00036I | Third-party import is inapplicable; no `third_party_embeds/...` source participates. | Scope/direct | project source family | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Third-Party Import Disposition | record no-import proof | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-103 | 00036I | Preserve rejected raw arrays, raw wrapper source, concrete Separator, multiple inheritance, virtual bounds, and stale Wave2/Wave3 alternatives as historical/negative evidence. | Historical/negative | complete reanalysis | `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Historical Assumptions And Negative Evidence | retain and annotate | callback-applied/readback-verified; supervisor Gate 2A unchecked |
| C36I-104 | 00036I | No additional target UID is declared; support UIDs remain support-only. | Scope fact | assignment header | `tools/leaser/Agents/Agent-B003/research/00036I-MenuItemVtableData-empty-emitter-source-quality.md` / Target | retain exact scope | callback scope/readback verified; supervisor Gate 2A unchecked |
| C36I-105 | 00036I | IDA, manual coverage, generated verification, and report execution/archive remain supervisor-owned; B003 performs only an accepted ordinary-doc callback. | Workflow | goal and skill | `tools/leaser/Agents/Agent-B003/research/00036I-MenuItemVtableData-empty-emitter-source-quality.md` / Changed Files And Checklist | preserve lifecycle boundary | callback scope/readback verified; supervisor Gate 2A unchecked |

## Positive Evidence Summary

- Exact class identity is not heuristic: all three vtable bases and all three COLs carry decorated MSVC names.
- Exact inheritance is not heuristic: the CHD/base arrays enumerate the complete class chains and reject multiple/virtual inheritance.
- Exact slot order is not heuristic: every dword is read, every function target is bounded, and constructor/destructor vptr stores identify each table base.
- Exact sizes are strong: the base/String scalar wrappers carry `0x18` and `0x118` delete-size constants, and Separator reuses the base wrapper while adding no fields.
- Exact abstractness is strong: MenuItem has three purecall slots; Separator retains two of them while adding/overriding three later slots.
- Exact source cause is strong: the compiler regenerates COLs, RTTI records, scalar wrappers, and vtables from normal classes/virtuals. A formal comment is therefore the correct emitted representation.
- The semantic ownership route is strong: UID0001Y4 already models precisely this family and has a child hook; other project vtable-data pages route through by-vtable semantic owners.

## IDA MCP Facts

- Function/range facts: constructors are `0x516f00-0x516f67`, `0x516ff0-0x517070`, `0x5171b0-0x51721d`; wrappers are `0x5172e0-0x51731e` and `0x517400-0x517441`; virtual bodies match exact target slot addresses.
- Data/table facts: raw target dwords are exactly the 23 entries already listed in the target; predecessor `0x61eb90=0x00544e90`; successor `0x61ebf0=0x0045004d` begins UTF-16 `ME`.
- RTTI facts: COL type/CHD pointers are Menu `0x6778f4/0x64b618`, String `0x677924/0x64b6e8`, Separator `0x677944/0x64b738`; base counts are `2/3/3`.
- Xref facts: Menu vtable base has five vptr-store refs; String and Separator each have one final constructor store; wrappers and application methods are referenced only from their expected vtable cells; COLs have one data ref from their preceding cells.
- Constructor liveness facts: String constructor has 54 direct xrefs; MenuItem and Separator constructors have zero direct xrefs. The separator constructor address has zero literal VA pattern hits.
- Vtable/global/type facts, fresh at `2026-08-01T09:20:46-04:00`: `MenuItem` exists at size 24 with five members and the still-colliding `MenuItemVtbl *lpVtbl`; `RectBounds` exists at size 16 with four `int` members; imported `MenuItemVtbl` exists at size 52 with 13 COM methods; all six proposed project UDTs `NexusTKMenuItemVtable`, `NexusTKSeparatorMenuItemVtable`, `StringMenuItem`, `SeparatorMenuItem`, `MenuItemMetrics`, and `MenuItemStyleFlags` remain absent by both `type_inspect` and exact-name `type_query`.
- Function-type facts, fresh at `2026-08-01T09:20:46-04:00`: `0x5172e0` and `0x517400` are currently `LObject *__thiscall(LObject *Block, char)`; `0x517090` is `_DWORD *__thiscall(char *this, _DWORD *, GrafPort *)`; `0x5170d0` is `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)`; `0x5170f0` is `void __thiscall(int this, GrafPort *)`; `0x517220` is `_DWORD *__stdcall(_DWORD *)`; `0x517240` is `_WORD *__stdcall(_WORD *)`; `0x517250` is `void __thiscall(_DWORD *this, GrafPort *)`; the protected functions remain `RuntimeClass *__thiscall(LObject *this)` and `void __thiscall(LObject *this, LObject *owner, Message *message)`.
- Comment facts: all target data cells and application/wrapper functions have empty regular/repeatable comments; `0x4f4b10` and `0x41b6c0` have existing shared comments recorded exactly in the IDA recommendation table.
- Negative IDA facts: no xrefs to the three COL-pointer cells; no extra vtable cell after `0x61ebec`; no GetBounds/SetBounds cell; no derived Separator data or second vtable facet.
- Fresh full-row audit fact: live `server_health`, `func_profile`, `lookup_funcs`, `decompile`, `get_comments`, `stack_frame`, `inspect_items`, `xrefs_to`, `get_bytes`, `type_inspect`, and `type_query` reread every C36I-056-C36I-083 action/protection entity. Gate 2B stopped before mutation on the four prototype differences above. Names, ranges, frames/locals, all comment channels, xref counts, UDT existence/collisions, data-item boundaries/types, decorated names, and protected RTTI states otherwise matched the prior report.

## Function / Child Inventory

The score arrows and repair descriptions below are explicitly historical pre-callback facts. The `Current post-callback state` and `Current destination identity / validator` columns are authoritative for the physical ordinary-document callback state.

| Range / Item | UID / Path | Role | Reconstructable | Current Direct Parent | Historical pre-callback state | Current post-callback state | Current destination identity / validator |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x61eb94-0x61ebf0` | UID00036I `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` | exact compiler RTTI/vtables | true | UID0001Y4 | `86/91`; direct-file routing and blank CPP/H required formal marker/route repair | `94/95`; owner/emitter UID0001Y4, accepted exact no-code CPP marker, blank H, and detailed RTTI/vtable evidence are physically present | SHA256 `5228A8DCF22FC35EDA6EFB890C06D44542B8B1EBF11B581DC9395341024D7023`; current command `000000020670`, `2026-08-01T09:52:34-04:00`, exit `0`, `ok: 1`, generated refresh skipped; historical callback command `000000020610` preserved under validator history |
| semantic vtable family | UID0001Y4 `by-type/by-vtable/MenuItemVtables.md` | slot/hierarchy owner | true | UID0000MN | `86/91`; completion rationale and child route required repair | `93/95`; UID00036I is attached as the exact semantic child and hierarchy/slot/source-cause evidence is present | SHA256 `4E50D9CCE58F14A990403B443C49FC5CA55E0CA6BE71DB591E6518A64DBE60B3`; current command `000000020672`, `2026-08-01T09:53:00-04:00`, exit `0`, `ok: 1`, generated refresh skipped; historical callback command `000000020611` retained |
| shared layouts | UID0001V5 `by-type/by-struct/MenuItemLayouts.md` | support UDT/layout owner | true | UID0000MN | `89/92`; support declarations were in CPP and the style result remained open | `92/94`; exact support declarations are in H, CPP carries the include directive, and the 2-byte style result is documented as a UDT | SHA256 `98D305A5E37974B8DFCD291BE238A71CD7B107B4F5EF04D670A4BD080536B9DA`; current command `000000020673`, `2026-08-01T09:53:10-04:00`, exit `0`, `ok: 1`, generated refresh skipped; historical callback command `000000020612` retained |
| MenuItem class | UID00007V `by-class/MenuItem.md` | abstract base declaration/router | true | UID0000MN | `91/93`; declaration was in CPP and an explicit destructor was inferred | `93/94`; declaration is in H, CPP is child-routed, the unproven explicit destructor is absent, and the two-base/six-slot contract is documented | SHA256 `53D2BD5E5B835CF9DB64E61F6015B44A2E0AE5D580898E4DE31F2CAD08A8806C`; current command `000000020674`, `2026-08-01T09:53:20-04:00`, exit `0`, `ok: 1`, generated refresh skipped; historical callback command `000000020613` retained |
| StringMenuItem class | UID0000E8 `by-class/StringMenuItem.md` | concrete text item declaration/router | true | UID0000MN | `89/91`; declaration was in CPP and an explicit destructor was inferred | `92/94`; declaration is in H, CPP is child-routed, the unproven explicit destructor is absent, and the three-base/six-slot/54-caller/`0x118` evidence is documented | SHA256 `8078193F2C7488E857EADF3CAF0AB2C563399267DE47BA90FE050F45D59A1F80`; current command `000000020676`, `2026-08-01T09:53:29-04:00`, exit `0`, `ok: 1`, generated refresh skipped; historical callback command `000000020614` retained |
| SeparatorMenuItem class | UID0000CY `by-class/SeparatorMenuItem.md` | abstract separator declaration/router | true | UID0000MN | `88/91`; abstractness was caveated and an explicit destructor contradicted the evidence | `92/94`; declaration is in H, CPP is child-routed, abstractness is direct, the unproven destructor is absent, and no-field/disabled-constructor/`0x18` wrapper evidence is documented | SHA256 `A19CD1FE72A0872104E9E596F117C58C5A29C734874EC50680E93C9EB7F5B7CE`; current command `000000020677`, `2026-08-01T09:53:40-04:00`, exit `0`, `ok: 1`, generated refresh skipped; historical callback command `000000020615` retained |
| source root | UID0000MN `by-file/PopupMenuControls.md` | PopupMenuControls source family | true | FILE | `86/85`; CPP-only grouping and the sole empty child required header/source-route closure | `88/88`; the H/CPP contract, UID0001Y4-to-UID00036I route, sole-empty cause, retained grouping, and historical split caveat are documented | SHA256 `04C00A40488A6C5A64E0CDDCD6A2C0A4F6504EC504CE628AE9932DB163266ED0`; current command `000000020678`, `2026-08-01T09:53:50-04:00`, exit `0`, `ok: 1`, generated refresh skipped; historical callback command `000000020616` retained; four pre-existing missing-reference warnings remain UID000376-UID000379 |
| constructors | UID0002J3/0002J6/0002JB | vptr/layout evidence | true | respective classes | no body change was proposed | Existing constructor-body emitters remain unchanged; they are supporting evidence, not callback destinations | Outside the seven callback destinations; no scoped validator was required by C36I-091-C36I-097 |
| virtuals | UID0002J8/J9/JA/JC/JD/JE | concrete slot bodies | true | respective classes | preserve exact body emitters | Existing exact body emitters remain unchanged | Outside the seven callback destinations; no scoped validator was required by C36I-091-C36I-097 |
| wrappers | UID0002JF/0002JG | compiler deleting support | true | respective classes | no handwritten body was proposed | Existing compiler-wrapper evidence remains unchanged and no scalar-wrapper C++ was added | Outside the seven callback destinations; no scoped validator was required by C36I-091-C36I-097 |
| bounds pair | UID0002JJ/0002JK | retained nonvirtual methods | true | UID00007V | excluded from vtable slots | Existing nonvirtual bounds evidence remains unchanged and excluded from the table | Outside the seven callback destinations; no scoped validator was required by C36I-091-C36I-097 |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x61eb98` Menu vtable | stores at `0x516f41`, `0x517031`, `0x5171f1`, `0x5172e6`, `0x517406` | base construction and teardown table |
| `0x61ebb4` String vtable | store at `0x51704e` | final String constructor table |
| `0x61ebd0` Separator vtable | store at `0x517205` | final Separator constructor table |
| `0x64b604/b6d4/b724` COLs | one data ref each from `0x61eb94/b0/cc` | exact vtable[-1] relationship |
| `0x5172e0` Menu wrapper | cells `0x61eb98`, `0x61ebd0` | base and separator shared/folded wrapper |
| `0x517400` String wrapper | cell `0x61ebb4` | string-specific delete-size wrapper |
| `0x517090/d0/f0` | cells `0x61ebc0/c4/c8` | String application virtuals |
| `0x517250/220/240` | cells `0x61ebe4/e8/ec` | Separator draw/new virtuals |
| `0x516ff0` String ctor | 54 direct code xrefs | live concrete String construction |
| `0x516f00`, `0x5171b0` | zero direct xrefs | retained/inlined base and retained abstract separator source |
| `0x4f4b10`, `0x41b6c0` | many vtable data refs | shared inherited LObject slots, not menu-local implementations |

## Documentation Evidence And IDA Status

- Historical pre-callback documentation state: the docs already preserved the exact dword run, `MENUBACK.EPF` boundary, constructors, method pages, nonvirtual bounds proof, class fields, and compiler-regeneration policy, but UID0001Y4 lacked the UID00036I child and had stale completion rationale; UID0000CY contained an explicit-destructor/abstractness contradiction; UID0001V5 had not resolved the 2-byte style result as a UDT; declarations occupied CPP rather than H; and the then-current generated output had one empty UID00036I marker and no `PopupMenuControls.h`.
- Current post-callback target state: `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` is SHA256 `5228A8DCF22FC35EDA6EFB890C06D44542B8B1EBF11B581DC9395341024D7023`, carries `94/95`, owner/emitter UID0001Y4, the exact no-code CPP marker, blank H, and the accepted detailed hierarchy/slot/wrapper/layout/source-cause evidence. Current scoped command `000000020670` at `2026-08-01T09:52:34-04:00` returned exit `0`, `ok: 1`, with generated refresh skipped; historical command `000000020610` remains preserved in the inventory.
- Current post-callback support state: UID0001Y4 SHA256 `4E50D9CCE58F14A990403B443C49FC5CA55E0CA6BE71DB591E6518A64DBE60B3` is `93/95` and validated by `000000020672`; UID0001V5 SHA256 `98D305A5E37974B8DFCD291BE238A71CD7B107B4F5EF04D670A4BD080536B9DA` is `92/94` and validated by `000000020673`; UID00007V SHA256 `53D2BD5E5B835CF9DB64E61F6015B44A2E0AE5D580898E4DE31F2CAD08A8806C` is `93/94` and validated by `000000020674`; UID0000E8 SHA256 `8078193F2C7488E857EADF3CAF0AB2C563399267DE47BA90FE050F45D59A1F80` is `92/94` and validated by `000000020676`; UID0000CY SHA256 `A19CD1FE72A0872104E9E596F117C58C5A29C734874EC50680E93C9EB7F5B7CE` is `92/94` and validated by `000000020677`; UID0000MN SHA256 `04C00A40488A6C5A64E0CDDCD6A2C0A4F6504EC504CE628AE9932DB163266ED0` is `88/88` and validated by `000000020678`. All six returned exit `0`, `ok: 1`, at the timestamps under Validator Results with generated refresh skipped; `000000020678` retained only the four pre-existing UID000376-UID000379 missing-reference warnings. Historical commands `000000020611`-`000000020616` remain preserved in the inventory.
- Current IDA status remains unmutated. Supervisor Gate 2B failed closed before any action because its literal prestate comparison found four prototype drifts. B003 then reread every C36I-056-C36I-083 entity through live session `b3b2bf88` at `2026-08-01T09:20:46-04:00`; the reconciled current prestates, per-row stop/rollback conditions, and deterministic readbacks below now supersede only the stale prestate text, not the accepted action scope.
- Current manual coverage status remains supervisor-owned. The historical plan to add/replace UID00036I, UID0001Y4, UID0001V5, UID00007V, UID0000E8, UID0000CY, and UID0000MN rows is recorded exactly in C36I-084-C36I-090 and was not performed by the ordinary callback.
- Current generated status is not inferred from the historical pre-callback artifact. C36I-098-C36I-101 remain supervisor-owned generated refresh/readback obligations; the seven scoped callback validators deliberately used `--no-generated-refresh`.

## Ranked Ownership Analysis

### 1. UID0001Y4 MenuItemVtables

- Evidence for: exact same three-class semantic scope; compiler-vtable formal marker; existing `[[CHILDREN]]`; score clears gate; routes through UID0000MN; project precedent routes exact by-memory vtable data through by-vtable pages.
- Evidence against: it is a semantic index rather than a physical memory page. That is the desired distinction, not a blocker.
- Decision: canonical owner and sole emitter.

### 2. UID0000MN PopupMenuControls

- Evidence for: narrowest file root spanning all three classes; current owner/emitter; valid `86/85`; coherent generated file.
- Evidence against: bypasses the semantic vtable page and makes UID00036I an unpositioned sibling at file end.
- Decision: retain as ultimate file root through UID0001Y4, not direct target owner/emitter.

### 3. One class page or UID00025T memory aggregate

- Evidence for: each class owns part of the table; UID00025T physically contains the range.
- Evidence against: no one class owns all three records; UID00025T mixes MemoryMan/MenuPane/menu strings and source owners and is only `80` completion.
- Decision: reject both.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new by-file or by-memory split. Generate `NexusTK/ui/menu/PopupMenuControls.h` through existing H channels.
- Likely full contents: menu support types and MenuItem/StringMenuItem/SeparatorMenuItem declarations.
- Candidate related items that belong: exact class declarations and forward/include dependencies only.
- Candidate related items rejected: raw RTTI records, raw vtable arrays, scalar-wrapper bodies, unrelated PopupMenuControlPane/MenuPane layout declarations not audited here.
- Source-file inference: one current reusable menu source/header pair remains best; original physical subdivision is not proven.

## Source Placement

- Recommended placement: target -> UID0001Y4 -> UID0000MN -> `NexusTK/ui/menu/PopupMenuControls.cpp`; menu declarations/support types -> generated `PopupMenuControls.h` in the same folder.
- This fits the source tree because all exact MenuItem-family method emitters already converge on UID0000MN, and current generated code is coherent when treated as one module.
- Rejected placements: direct class ownership for the three-class table, mixed UID00025T ownership, feature-dialog ownership, raw ABI source files, and forced per-class `.cpp` files.
- Remaining uncertainty: the original project may have used `MenuItem.cpp/.h`. No current binary or documentation evidence selects that spelling over the accepted current grouping. This affects historical file naming only, not behavior, hierarchy, ownership, or code readiness.

## Range / Split / Padding / Reclassification Analysis

- Exact range: 92 bytes (`0x5c`) from `0x61eb94` inclusive to `0x61ebf0` exclusive.
- Record 1: MenuItem COL pointer plus six slots, `0x61eb94-0x61ebb0`.
- Record 2: StringMenuItem COL pointer plus six slots, `0x61ebb0-0x61ebcc`.
- Record 3: SeparatorMenuItem COL pointer plus eight slots, `0x61ebcc-0x61ebf0`.
- There is no interior padding. The predecessor at `0x61eb90` belongs to MenuPane data; the successor begins UTF-16 source literal data.
- Do not split into three by-memory children: the existing target and UID0001Y4 already model the deliberately shared family, and a split would create redundant records without improving source placement.
- Do not reclassify to non-reconstructable: source declarations directly regenerate the bytes, and a formal marker is required to account for the reconstructable range.
- Parent impact: change semantic route only; do not alter UID00025T physical containment.

## Negative Evidence Summary

- No COL-pointer cell has a code xref; that is normal compiler RTTI adjacency and does not weaken class identity.
- No MenuItem/Separator constructor start xrefs survive; exact bodies, RTTI, vptr stores, and methods still prove retained source. Missing callers do not justify "compiler generated" for constructors or classes.
- No literal separator-constructor VA appears in the IDB byte search; do not invent a function-pointer table.
- No GetBounds/SetBounds address occurs in the finite tables; do not add virtual declarations for them.
- No separator-specific fields or second vtable facet exist; do not invent multiple inheritance, an interface facet, or hidden layout.
- No separate Separator deleting wrapper exists; do not invent one or require an explicit source destructor.
- The String wrapper has no label cleanup because the label is inline trivial storage; do not infer heap ownership.
- The current imported COM `MenuItemVtbl` is not NexusTK evidence despite its matching unqualified name; its 13 COM slots and size 52 directly contradict the six-slot NexusTK table.
- Adjacent MemoryMan/MenuPane/resource data proves physical neighborhood only, not source ownership.

## IDA Rename / Type / Comment Recommendations

All actions below are supervisor-owned Gate 2B operations. B003 performed no mutation or save.

The authoritative read-only prestate was recaptured from live IDB session `b3b2bf88` at `2026-08-01T09:20:46-04:00` after supervisor Gate 2B failed closed before mutation. `server_health` was `status=ok`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays ready; `auto_analysis_ready=false` did not prevent any bounded query. `func_profile`, `lookup_funcs`, `decompile`, `get_comments`, `stack_frame`, `inspect_items`, `xrefs_to`, `get_bytes`, `type_inspect`, and `type_query` all returned coherently for every action/protected row. Every proposed function name returned `Not found`; all six proposed new UDT names returned `Type not found` and exact-name query total zero. No declaration was parsed because this is a read-only repair. Gate 2B must parse types in dependency order before dependent function/data types, reread the literal row immediately before each action, and obey the row-level stop/rollback matrix.

The four reconciled drifts are current prototypes only: `0x5172e0` and `0x517400` now read `LObject *__thiscall(LObject *Block, char)` instead of the report's stale `_DWORD *` forms; `0x517090` reads `_DWORD *__thiscall(char *this, _DWORD *, GrafPort *)` instead of a stale `__int16 *` third argument; `0x517250` reads `void __thiscall(_DWORD *this, GrafPort *)` instead of stale `int __thiscall(_DWORD *this, int)`. The accepted source-quality actions remain unchanged because the current decompilation, frame, xrefs, vtable slots, object layouts, and semantic dependencies still support the deterministic proposed types. All other literal prestates matched.

### No-Action Type Dependencies And Collision Protections

These dependencies are not padded into the action table because they require no mutation.

| Entity | Exact current declaration/type state | Comment state | Collision/dependency state | Protection/readback |
| --- | --- | --- | --- | --- |
| `MenuItemVtbl` | Existing named UDT, size `0x34`; 13 imported COM slots `QueryInterface` at `+0x00` through `get_Enabled` at `+0x30`, with the literal function-pointer types returned by `type_inspect`. | MCP type inspection exposes no type/member-comment field; no type/member comment action is proposed. | This exact unqualified name collides with the game class's current `MenuItem.lpVtbl` field type. | Preserve name, size, all 13 members, and all SDK dependencies unchanged; readback must still show size `0x34` and 13 members. |
| `RectBounds` | Existing named UDT, size `0x10`: `int left +0`, `int top +4`, `int right +8`, `int bottom +0xc`. | MCP type inspection exposes no type/member-comment field; no type/member comment action is proposed. | Parsed and already used by current MenuItem and stack-frame state; no collision. | Preserve exact size/members and do not recreate it. |
| `RuntimeClass`, `LObject`, `Message`, `GrafPort` | `RuntimeClass`, `LObject`, and `Message` exist as named incomplete dependency types; `GrafPort` is a current size-`0xa0` UDT with 23 members. Current protected function declarations parse these names exactly. | No comment action. | Dependency state is already parsed; `GrafPort *` is now also the literal current third argument at `0x517090` and second argument at `0x517250`. | Preserve every dependency. Stop Gate 2B before mutation if any name no longer parses or `GrafPort` size/member state drifts; no rollback is needed because this row permits no mutation. |

### Current Type Pre-State And Required UDT Actions

| Entity / exact width | Literal current declaration/type/comment state | Collision/dependency/parse state | Exact proposed action and protection | Deterministic expected readback | Classification |
| --- | --- | --- | --- | --- | --- |
| `MenuItem`, `0x18` | Existing declaration token `MenuItem`; members: `MenuItemVtbl *lpVtbl +0x0`, `RectBounds m_bounds +0x4`, `bool m_enabled +0x14`, `bool m_selected +0x15`, `unsigned __int8 _menuItemTailPadding[2] +0x16`. MCP type inspection exposes no comment field; no comment action. | Current `lpVtbl` resolves to the protected COM collision. `RectBounds` parses. New vtable type is currently absent and was not parsed in this read-only phase. | After `NexusTKMenuItemVtable` parses, change only `lpVtbl` to `NexusTKMenuItemVtable *`; preserve UDT name, size, all offsets, field names, field types other than `lpVtbl`, and any unexposed type/member comments. | `type_inspect(MenuItem)` returns size 24 and the same five members/offsets, with only `lpVtbl` changed to `NexusTKMenuItemVtable *`. | apply |
| `NexusTKMenuItemVtable`, proposed `0x18` | Type absent: `type_inspect` returned `Type not found`; exact-name `type_query` returned zero; declaration/type/comments therefore absent. | Name collision check is clear. Dependencies `MenuItem`, `RuntimeClass`, `LObject`, `Message`, `GrafPort`, `MenuItemMetrics`, and CRT types must parse; `MenuItemMetrics` is currently absent. No parse attempted. | Create only after `MenuItemMetrics`; six ordered pointer members exactly as the member contract below. Do not reuse/rename the imported COM `MenuItemVtbl`. | Exact name exists, size 24, six members at `0,4,8,c,10,14` with exact pointer types below. | apply |
| `NexusTKSeparatorMenuItemVtable`, proposed `0x20` | Type absent: `type_inspect` returned `Type not found`; exact-name `type_query` returned zero; declaration/type/comments absent. | Name collision check is clear. Depends on `SeparatorMenuItem`, `MenuItemMetrics`, `MenuItemStyleFlags`, existing LObject-support types, and the common prefix; all three new source UDTs are currently absent. No parse attempted. | Create after all dependent source UDTs; eight ordered pointer members exactly as the member contract below. | Exact name exists, size 32, eight members at `0..1c` with exact pointer types below. | apply |
| `StringMenuItem`, proposed `0x118` | Type absent: `type_inspect` returned `Type not found`; exact-name `type_query` returned zero; declaration/type/comments absent. | Name collision check is clear. Depends only on existing `MenuItem` plus built-in `wchar_t`; no parse attempted. | Create flattened `MenuItem base; wchar_t m_text[128];`; preserve base offset 0 and text offset `0x18`; do not invent extra fields or an explicit destructor field. | Exact name exists, size 280, `base +0 size 24`, `m_text +0x18 size 256`. | apply |
| `SeparatorMenuItem`, proposed `0x18` | Type absent: `type_inspect` returned `Type not found`; exact-name `type_query` returned zero; declaration/type/comments absent. | Name collision check is clear. Depends on existing `MenuItem`; no parse attempted. | Create flattened `MenuItem base;` only; no new field, secondary vptr, or padding member. | Exact name exists, size 24, sole `base +0 size 24`. | apply |
| `MenuItemMetrics`, proposed `0x08` | Type absent: `type_inspect` returned `Type not found`; exact-name `type_query` returned zero; declaration/type/comments absent. | Name collision check is clear; built-in `int` dependency only; no parse attempted. | Create `int height; int width;` at offsets 0 and 4. | Exact name exists, size 8, two `int` members `height +0`, `width +4`. | apply first |
| `MenuItemStyleFlags`, proposed `0x02` | Type absent: `type_inspect` returned `Type not found`; exact-name `type_query` returned zero; declaration/type/comments absent. | Name collision check is clear; built-in `unsigned short` dependency only; no parse attempted. | Create `unsigned short bits;` at offset 0; do not invent enum bits. | Exact name exists, size 2, sole `bits +0` member. | apply first |

Exact `NexusTKMenuItemVtable` member contract for IDA declaration:

| Offset | Member | Exact pointer type |
| --- | --- | --- |
| `+0x00` | `ScalarDeletingDestructor` | `MenuItem *(__thiscall *)(MenuItem *this, unsigned int flags)` |
| `+0x04` | `GetRuntimeClass` | `RuntimeClass *(__thiscall *)(MenuItem *this)` |
| `+0x08` | `OnChangeMessage` | `void (__thiscall *)(MenuItem *this, LObject *owner, Message *message)` |
| `+0x0c` | `GetItemSize` | `MenuItemMetrics *(__thiscall *)(MenuItem *this, MenuItemMetrics *result, GrafPort *port)` |
| `+0x10` | `GetText` | `errno_t (__thiscall *)(const MenuItem *this, wchar_t *destination, rsize_t sizeInWords)` |
| `+0x14` | `DrawItem` | `void (__thiscall *)(MenuItem *this, GrafPort *port)` |

Exact `NexusTKSeparatorMenuItemVtable` member contract for IDA declaration:

| Offset | Member | Exact pointer type |
| --- | --- | --- |
| `+0x00` | `ScalarDeletingDestructor` | `SeparatorMenuItem *(__thiscall *)(SeparatorMenuItem *this, unsigned int flags)` |
| `+0x04` | `GetRuntimeClass` | `RuntimeClass *(__thiscall *)(SeparatorMenuItem *this)` |
| `+0x08` | `OnChangeMessage` | `void (__thiscall *)(SeparatorMenuItem *this, LObject *owner, Message *message)` |
| `+0x0c` | `GetItemSize` | `MenuItemMetrics *(__thiscall *)(SeparatorMenuItem *this, MenuItemMetrics *result, GrafPort *port)`; current cell is `__purecall` |
| `+0x10` | `GetText` | `errno_t (__thiscall *)(const SeparatorMenuItem *this, wchar_t *destination, rsize_t sizeInWords)`; current cell is `__purecall` |
| `+0x14` | `DrawItem` | `void (__thiscall *)(SeparatorMenuItem *this, GrafPort *port)` |
| `+0x18` | `GetDefaultDimensions` | `MenuItemMetrics *(__thiscall *)(SeparatorMenuItem *this, MenuItemMetrics *result)` |
| `+0x1c` | `GetStyleFlags` | `MenuItemStyleFlags *(__thiscall *)(SeparatorMenuItem *this, MenuItemStyleFlags *result)` |

### Function And Data Action Rows

`absent` below means the fresh `get_comments` field was the empty string. Each row is independently replayable and includes the exact current function range, declaration, all four function/address comment channels, stack-frame/local state, relevant xrefs, name/type dependency state, action/protection, and readback.

| Exact function range / width | Literal current name, declaration, and comments | Exact current frame/local state | Relevant xrefs | Collision/dependency parse state | Exact action, protection, and deterministic readback | Classification |
| --- | --- | --- | --- | --- | --- | --- |
| `0x5172e0-0x51731e`, `0x3e` | `sub_5172E0`; `LObject *__thiscall(LObject *Block, char)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent. This replaces the stale `_DWORD *` prestate and is authoritative at `2026-08-01T09:20:46-04:00`. | `__saved_registers +0x4`, return address `+0x8`, `arg_0 int +0xc`; decompiler parameters `Block LObject *`, `a2 char`; no local declaration or local UDT. | Exactly two data refs: `0x61eb98`, `0x61ebd0`; zero direct code callers. | Proposed `MenuItem__ScalarDeletingDestructor` returned `Not found`. Existing `MenuItem` still parses at size `0x18`; semantic `unsigned int flags` is the source-quality replacement for current `char`. | Rename and type `MenuItem *__thiscall MenuItem__ScalarDeletingDestructor(MenuItem *this, unsigned int flags)`; set function repeatable comment `MSVC scalar deleting destructor generated for MenuItem; also folded into SeparatorMenuItem slot 0. Source uses implicit virtual destruction.` Preserve bytes/frame/chunks/address comments. Readback exact name/type, only function-repeatable populated, two xrefs unchanged. | apply |
| `0x517400-0x517441`, `0x41` | `sub_517400`; `LObject *__thiscall(LObject *Block, char)`; all four comment channels absent. This replaces the stale `_DWORD *` prestate and is authoritative at `2026-08-01T09:20:46-04:00`. | `__saved_registers +0x4`, return address `+0x8`, `arg_0 int +0xc`; decompiler parameters `Block LObject *`, `a2 char`; no local declaration or local UDT. | Exactly one data ref `0x61ebb4`; zero direct code callers. | Proposed `StringMenuItem__ScalarDeletingDestructor` returned `Not found`. `StringMenuItem` remains absent and must parse first; semantic `unsigned int flags` replaces current `char`. | Rename/type `StringMenuItem *__thiscall StringMenuItem__ScalarDeletingDestructor(StringMenuItem *this, unsigned int flags)`; set exact function-repeatable comment `MSVC scalar deleting destructor generated for StringMenuItem; 0x118 delete size and inline text require no authored cleanup body.` Preserve frame/bytes/address comments. Readback exact name/type/comment and one xref. | apply |
| `0x517090-0x5170d0`, `0x40` | `sub_517090`; `_DWORD *__thiscall(char *this, _DWORD *, GrafPort *)`; all four comment channels absent. The literal current third argument is `GrafPort *`, not the stale `__int16 *`. | `__saved_registers +0x4`, return `+0x8`, `arg_0 _DWORD +0xc`, `arg_4 GrafPort * +0x10`; decompiler locals `v3 const wchar_t *`, `v4/v5 char *`, `v6 __int16`, `TextWidth int`, `result _DWORD *`; no named stack local/UDT. | Exactly one data ref `0x61ebc0`; zero direct code callers. | Proposed `StringMenuItem__GetItemSize` returned `Not found`. `StringMenuItem` and `MenuItemMetrics` remain absent; existing `GrafPort` is size `0xa0`. Parse the two new UDTs first. | Rename/type `MenuItemMetrics *__thiscall StringMenuItem__GetItemSize(StringMenuItem *this, MenuItemMetrics *result, GrafPort *port)`; set function-repeatable comment `StringMenuItem virtual GetItemSize; hidden result is {height=14,width=textWidth+24}.` Preserve frame/bytes/address comments. Readback exact name/type/comment, locals/frame, and xref. | apply |
| `0x5170d0-0x5170e9`, `0x19` | `sub_5170D0`; `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)`; all four comment channels absent. | `__saved_registers +0`, return `+4`, `Destination wchar_t * +8`, `SizeInWords rsize_t +0xc`; decompiler has no local declarations. | Exactly one data ref `0x61ebc4`; zero direct code callers. | Proposed `StringMenuItem__GetText` returned `Not found`. Depends on new `StringMenuItem` and existing CRT types; parse UDT first. | Rename/type `errno_t __thiscall StringMenuItem__GetText(const StringMenuItem *this, wchar_t *destination, rsize_t sizeInWords)`; set function-repeatable comment `StringMenuItem virtual GetText copies inline m_text[128] with wcscpy_s.` Preserve bytes/frame/address comments. Readback exact name/type/comment and xref. | apply |
| `0x5170f0-0x5171a2`, `0xb2` | `sub_5170F0`; `void __thiscall(int this, GrafPort *)`; all four comment channels absent. | `__saved_registers +0xc`, return `+0x10`, `arg_0 GrafPort * +0x14`; no allocated stack local/UDT; decompiler register temporaries `v3 _WORD *`, `v5 _WORD *`. | Exactly one data ref `0x61ebc8`; zero direct code callers. | Proposed `StringMenuItem__DrawItem` returned `Not found`. Depends on new `StringMenuItem` and existing `GrafPort`; parse UDT first. | Rename/type `void __thiscall StringMenuItem__DrawItem(StringMenuItem *this, GrafPort *port)`; set function-repeatable comment `StringMenuItem virtual DrawItem; selected state and inherited bounds choose highlighted/normal text rendering.` Preserve bytes/frame/address comments. Readback exact name/type/comment/frame/locals and xref. | apply |
| `0x517220-0x517237`, `0x17` | `sub_517220`; `_DWORD *__stdcall(_DWORD *)`; all four comment channels absent. | `__saved_registers +0`, return `+4`, `arg_0 _DWORD +8`; decompiler local `result _DWORD *`; ECX/object state optimized unused. | Exactly one data ref `0x61ebe8`; zero direct code callers. | Proposed `SeparatorMenuItem__GetDefaultDimensions` returned `Not found`. Depends on new `SeparatorMenuItem` and `MenuItemMetrics`; parse both first. | Rename/type `MenuItemMetrics *__thiscall SeparatorMenuItem__GetDefaultDimensions(SeparatorMenuItem *this, MenuItemMetrics *result)`; set function-repeatable comment `SeparatorMenuItem virtual hidden-result method returning {height=6,width=20}; this is optimized unused.` Preserve bytes/frame/address comments. Readback must use thiscall semantic type despite unused ECX and preserve frame/local state. | apply |
| `0x517240-0x51724f`, `0x0f` | `sub_517240`; `_WORD *__stdcall(_WORD *)`; all four comment channels absent. | `__saved_registers +0`, return `+4`, `arg_0 _DWORD +8`; decompiler local `result _WORD *`; ECX/object state optimized unused. | Exactly one data ref `0x61ebec`; zero direct code callers. | Proposed `SeparatorMenuItem__GetStyleFlags` returned `Not found`. Depends on new `SeparatorMenuItem` and `MenuItemStyleFlags`; parse both first. | Rename/type `MenuItemStyleFlags *__thiscall SeparatorMenuItem__GetStyleFlags(SeparatorMenuItem *this, MenuItemStyleFlags *result)`; set function-repeatable comment `SeparatorMenuItem virtual hidden-result method returning zero 16-bit style flags; this is optimized unused.` Preserve bytes/frame/address comments. Readback exact semantic type/comment/frame/local state. | apply |
| `0x517250-0x5172be`, `0x6e` | `sub_517250`; `void __thiscall(_DWORD *this, GrafPort *)`; all four comment channels absent. The literal current return and second argument replace stale `int` forms. | `var_14 +0x8 size 0x10 struct RectBounds`, `var_4 +0x18 _DWORD` stack cookie, saved registers `+0x1c`, return `+0x20`, `arg_0 GrafPort * +0x24`; decompiler locals `v3/v4 int`, `v5 RectBounds`. | Exactly one data ref `0x61ebe4`; zero direct code callers. | Proposed `SeparatorMenuItem__DrawItem` returned `Not found`. `SeparatorMenuItem` remains absent; existing `GrafPort` size `0xa0` and `RectBounds` size `0x10` still parse. Parse the new UDT first. | Rename/type `void __thiscall SeparatorMenuItem__DrawItem(SeparatorMenuItem *this, GrafPort *port)`; set function-repeatable comment `SeparatorMenuItem DrawItem override draws a centered three-pixel separator band inside inherited bounds.` Preserve `var_14`/cookie/frame/bytes/address comments. Readback exact name/type/comment/local layout/xref. | apply |
| `0x4f4b10-0x4f4b16`, `0x06` | `LObject__GetRuntimeClass`; `RuntimeClass *__thiscall(LObject *this)`; address regular absent; address repeatable absent; function regular exactly `Inherited LObject::GetRuntimeClass virtual accessor. Shared vtable use is inheritance, not FontImageLib ownership.`; function repeatable absent. | Return-address entry only; no stack args or named locals. | 489 incoming refs total; target-relevant cells `0x61eb9c`, `0x61ebb8`, `0x61ebd4`. | Existing name/type already parse; no rename/type dependency or collision. | Keep name/type and three absent channels; replace only function regular with `Inherited LObject::GetRuntimeClass virtual accessor returning the LObject runtime-class record; shared vtable use reflects inheritance.` Readback exact comment, 489 refs, unchanged function. | apply comment |
| `0x41b6c0-0x41b6c3`, `0x03` | `LObject__OnChangeMessage`; `void __thiscall(LObject *this, LObject *owner, Message *message)`; address regular absent; address repeatable absent; function regular exactly `Identical-function-folded empty ObjectPane defaults for source virtuals RenderFrame(GrafPort *, const RectBounds *) and DrawSpriteFrame(GrafPort *, const RectBounds *); do not collapse the two source declarations.`<br>`Existing inherited LObject no-op change-message hook. Retain this shared identity; it is not an AUTOBUF-specific source function.`<br>`Inherited LObject::OnChangeMessage(LObject *owner, Message *message) default no-op. The retn 8 ABI and ChangeMan dispatch establish both arguments; historical nullsub_18 is rejected.`; function repeatable absent. | Return `+0`, `owner LObject * +4`, `message Message * +8`; no named local. | 517 incoming refs total; target-relevant cells `0x61eba0`, `0x61ebbc`, `0x61ebd8`. | Existing name/type already parse; folded function has multiple source identities, so renaming is protected. | Keep name/type and three absent channels; replace only function regular with `Identical-function-folded no-op used by LObject::OnChangeMessage and other source-level virtual defaults; preserve separate source declarations and use the LObject slot identity for this vtable.` Readback exact comment, 517 refs, unchanged folded function. | apply comment |

The exact superseded three-line `0x41b6c0` current function-regular comment is preserved here for mutation comparison: `Identical-function-folded empty ObjectPane defaults for source virtuals RenderFrame(GrafPort *, const RectBounds *) and DrawSpriteFrame(GrafPort *, const RectBounds *); do not collapse the two source declarations.` / `Existing inherited LObject no-op change-message hook. Retain this shared identity; it is not an AUTOBUF-specific source function.` / `Inherited LObject::OnChangeMessage(LObject *owner, Message *message) default no-op. The retn 8 ABI and ChangeMan dispatch establish both arguments; historical nullsub_18 is rejected.`

| Exact data range / current item width | Literal current name/type/comments | Relevant xrefs | Collision/dependency parse state | Exact action, protection, and deterministic readback | Classification |
| --- | --- | --- | --- | --- | --- |
| `0x61eb94-0x61eb98`, width 4 | name absent; type absent; regular absent; repeatable absent; function comments not applicable. | Zero xrefs; value points to `0x64b604`. | No name/type action and no dependency parse. | Keep unnamed/untyped; set repeatable `MenuItem vtable[-1] complete-object-locator pointer -> ??_R4MenuItem@@6B@.` Preserve regular absent. Readback exact 4-byte item/comment/zero xrefs. | apply comment |
| current head `0x61eb98-0x61eb9c`, width 4; proposed typed span `0x61eb98-0x61ebb0`, width `0x18` | name `??_7MenuItem@@6B@`; type absent; regular absent; repeatable absent; function comments not applicable. | Five refs: `0x516f41`, `0x517031`, `0x5171f1`, `0x5172e6`, `0x517406`. | Decorated name protected. Depends on absent `NexusTKMenuItemVtable`; parse it first. | Apply `NexusTKMenuItemVtable` across exact six-cell span; preserve name; set repeatable `MenuItem primary vtable: deleting destructor, LObject slots, then three pure virtual application slots.` Readback decorated name, type width `0x18`, exact comment, five refs. | apply type/comment |
| `0x61ebb0-0x61ebb4`, width 4 | name absent; type absent; regular absent; repeatable absent; function comments not applicable. | Zero xrefs; value points to `0x64b6d4`. | No name/type action and no dependency parse. | Keep unnamed/untyped; set repeatable `StringMenuItem vtable[-1] complete-object-locator pointer -> ??_R4StringMenuItem@@6B@.` Preserve regular absent. Readback exact 4-byte item/comment/zero xrefs. | apply comment |
| current head `0x61ebb4-0x61ebb8`, width 4; proposed typed span `0x61ebb4-0x61ebcc`, width `0x18` | name `??_7StringMenuItem@@6B@`; type absent; regular absent; repeatable absent; function comments not applicable. | One ref `0x51704e`. | Decorated name protected. Depends on absent `NexusTKMenuItemVtable`; parse it first. | Apply `NexusTKMenuItemVtable` across exact six-cell span; preserve name; set repeatable `StringMenuItem primary vtable: deleting destructor, inherited LObject slots, GetItemSize, GetText, DrawItem.` Readback decorated name/type/comment/one ref. | apply type/comment |
| `0x61ebcc-0x61ebd0`, width 4 | name absent; type absent; regular absent; repeatable absent; function comments not applicable. | Zero xrefs; value points to `0x64b724`. | No name/type action and no dependency parse. | Keep unnamed/untyped; set repeatable `SeparatorMenuItem vtable[-1] complete-object-locator pointer -> ??_R4SeparatorMenuItem@@6B@.` Preserve regular absent. Readback exact 4-byte item/comment/zero xrefs. | apply comment |
| current head `0x61ebd0-0x61ebd4`, width 4; proposed typed span `0x61ebd0-0x61ebf0`, width `0x20` | name `??_7SeparatorMenuItem@@6B@`; type absent; regular absent; repeatable absent; function comments not applicable. | One ref `0x517205`. | Decorated name protected. Depends on absent `NexusTKSeparatorMenuItemVtable`; parse it first. | Apply `NexusTKSeparatorMenuItemVtable` across exact eight-cell span; preserve name; set repeatable `Abstract SeparatorMenuItem vtable: shared destructor/LObject slots, pure GetItemSize/GetText, DrawItem, GetDefaultDimensions, GetStyleFlags.` Readback decorated name/type/comment/one ref. | apply type/comment |

### Itemized Protected RTTI Entities

These exact current IDA items are compiler RTTI identities and require deterministic no-change readback, not action-table mutations.

| Exact item range / width | Literal current name/type/comments | Relevant xrefs | Collision/dependency state | Protection and expected readback |
| --- | --- | --- | --- | --- |
| `0x64b604-0x64b608`, width 4 | `??_R4MenuItem@@6B@`; type absent; regular exactly `signature`; repeatable absent; function comments not applicable. | One data ref `0x61eb94`. | Decorated compiler name; no source-UDT dependency. | Preserve exact item boundary, name, absent type, regular `signature`, absent repeatable, and one xref. |
| `0x64b6d4-0x64b6d8`, width 4 | `??_R4StringMenuItem@@6B@`; type absent; regular exactly `signature`; repeatable absent; function comments not applicable. | One data ref `0x61ebb0`. | Decorated compiler name; no source-UDT dependency. | Preserve exact item boundary, name, absent type, regular `signature`, absent repeatable, and one xref. |
| `0x64b724-0x64b728`, width 4 | `??_R4SeparatorMenuItem@@6B@`; type absent; regular exactly `signature`; repeatable absent; function comments not applicable. | One data ref `0x61ebcc`. | Decorated compiler name; no source-UDT dependency. | Preserve exact item boundary, name, absent type, regular `signature`, absent repeatable, and one xref. |

### Authoritative Gate 2B Per-Claim Stop / Rollback Matrix

This matrix is the one-to-one transaction guard for the fresh `2026-08-01T09:20:46-04:00` live readback. The detailed declarations, comments, frames/locals, xrefs, actions, and expected values remain literal in the tables above; this matrix binds each claim to its current state and failure behavior. For every mutation row, the supervisor must reread the full literal row immediately before acting. Any pre-action difference stops Gate 2B without mutation. Any post-action mismatch requires restoring that row's recorded current name/type/comment state, rereading bytes/frame/xrefs, and halting without saving. A dependent failure also rolls back later-created dependent UDTs in reverse order. Protected rows permit no mutation and fail closed on any difference.

| Claim | Authoritative current prestate | Accepted action / no-action | Exact stop or rollback condition | Deterministic required readback |
| --- | --- | --- | --- | --- |
| C36I-056 | `MenuItem`, size `0x18`, five members; `lpVtbl +0 MenuItemVtbl *`; `RectBounds +4`; booleans `+0x14/+0x15`; padding `+0x16`. | After C36I-057 parses, replace only `lpVtbl` type with `NexusTKMenuItemVtable *`. | Stop if size/member count/name/offset/type differs, C36I-057 is absent, or any non-`lpVtbl` member would change. On mismatch after edit, restore exact current `MenuItem` declaration and halt. | Size 24, same five names/offsets/types except `lpVtbl` exactly `NexusTKMenuItemVtable *`. |
| C36I-057 | `NexusTKMenuItemVtable` absent by `type_inspect`; exact query total 0. | After C36I-061, create exact six-member `0x18` UDT from the contract above. | Stop if name now exists, any dependency fails to parse, or declaration does not yield exact size/offsets/types. Delete only the newly created UDT on rollback. | Exact name, size 24, six members at `0,4,8,c,10,14` with the stated pointer types. |
| C36I-058 | `NexusTKSeparatorMenuItemVtable` absent by `type_inspect`; exact query total 0. | After C36I-057/C36I-060/C36I-061/C36I-062, create exact eight-member `0x20` UDT. | Stop if name now exists, dependency parse fails, or declaration differs; delete only the newly created UDT on rollback. | Exact name, size 32, eight members at `0..1c` with the stated pointer types. |
| C36I-059 | `StringMenuItem` absent by `type_inspect`; exact query total 0; `MenuItem` remains `0x18`. | Create flattened `MenuItem base; wchar_t m_text[128];`. | Stop if name now exists, `MenuItem` drifts, `wchar_t` does not size to 2, or layout differs; delete newly created UDT on rollback. | Size `0x118`; `base +0 size 0x18`; `m_text +0x18 size 0x100`; no other member. |
| C36I-060 | `SeparatorMenuItem` absent by `type_inspect`; exact query total 0; `MenuItem` remains `0x18`. | Create flattened `MenuItem base;` only. | Stop if name now exists, `MenuItem` drifts, or layout adds any member/padding; delete newly created UDT on rollback. | Size `0x18`; sole `base +0 size 0x18`. |
| C36I-061 | `MenuItemMetrics` absent by `type_inspect`; exact query total 0. | Create `int height; int width;` first. | Stop if name now exists or `int`/layout differs; delete newly created UDT on rollback. | Size 8; `height +0 int`; `width +4 int`. |
| C36I-062 | `MenuItemStyleFlags` absent by `type_inspect`; exact query total 0. | Create `unsigned short bits;` first. | Stop if name now exists or `unsigned short`/layout differs; delete newly created UDT on rollback. | Size 2; sole `bits +0 unsigned short`. |
| C36I-063 | Imported COM `MenuItemVtbl`, size `0x34`, 13 members from `QueryInterface +0` through `get_Enabled +0x30`. | No action; protected dependency. | Stop the entire transaction if any name/size/member/type differs. Never rename, overwrite, or roll this type back. | Exact same name, size 52, 13 members and literal pointer types. |
| C36I-064 | `RectBounds`, size `0x10`, four `int` members `left/top/right/bottom` at `0/4/8/c`. | No action; protected dependency. | Stop if any name/size/member/type differs. Never recreate or mutate it. | Exact same size and four members. |
| C36I-065 | `0x5172e0-0x51731e`, `sub_5172E0`, `LObject *__thiscall(LObject *Block, char)`; four comments absent; frame `saved +4/return +8/arg_0 int +c`; parameters `Block/a2`; two refs. | Apply exact MenuItem scalar-deleting-destructor name/type/repeatable comment above. | Stop if range/name/current prototype/comments/frame/parameters/two refs or proposed-name absence differs. Roll back original name/prototype and four absent comments on failed readback. | Exact proposed name/type/repeatable comment; address and function-regular comments absent; frame/parameters/bytes and refs `0x61eb98,0x61ebd0` unchanged. |
| C36I-066 | `0x517400-0x517441`, `sub_517400`, `LObject *__thiscall(LObject *Block, char)`; four comments absent; same three frame entries; parameters `Block/a2`; one ref. | Apply exact String scalar-deleting-destructor name/type/repeatable comment above after C36I-059. | Stop if any literal state, one ref, proposed-name absence, or C36I-059 differs. Roll back original name/prototype/comments on failure. | Exact proposed name/type/repeatable comment; other comments absent; frame/parameters/bytes and sole ref `0x61ebb4` unchanged. |
| C36I-067 | `0x517090-0x5170d0`, `sub_517090`, `_DWORD *__thiscall(char *this, _DWORD *, GrafPort *)`; four comments absent; frame and six decompiler locals as recorded; one ref. | Apply exact `StringMenuItem__GetItemSize` name/type/repeatable comment after C36I-059/C36I-061. | Stop if prototype reverts/drifts, frame/locals/comments/ref/name collision/dependencies differ. Roll back original name/prototype/comments on failure. | Exact semantic name/type/comment; frame/locals/bytes and sole ref `0x61ebc0` unchanged. |
| C36I-068 | `0x5170d0-0x5170e9`, `sub_5170D0`, exact current CRT prototype; four comments absent; frame arguments `Destination/SizeInWords`; no locals; one ref. | Apply exact `StringMenuItem__GetText` name/type/repeatable comment after C36I-059. | Stop if any literal state, CRT dependency, proposed-name absence, or ref differs. Roll back original name/prototype/comments on failure. | Exact semantic name/type/comment; frame/bytes and sole ref `0x61ebc4` unchanged. |
| C36I-069 | `0x5170f0-0x5171a2`, `sub_5170F0`, `void __thiscall(int this, GrafPort *)`; four comments absent; frame plus `v3/v5 _WORD *`; one ref. | Apply exact `StringMenuItem__DrawItem` name/type/repeatable comment after C36I-059. | Stop if any literal state, `GrafPort`, proposed-name absence, or ref differs. Roll back original name/prototype/comments on failure. | Exact semantic name/type/comment; frame/locals/bytes and sole ref `0x61ebc8` unchanged. |
| C36I-070 | `0x517220-0x517237`, `sub_517220`, `_DWORD *__stdcall(_DWORD *)`; four comments absent; frame plus `result _DWORD *`; one ref. | Apply exact thiscall hidden-result dimensions name/type/repeatable comment after C36I-060/C36I-061. | Stop if current stdcall lowering, frame/local/comments/ref/dependencies/name collision differs. Roll back original state on failure. | Exact semantic name/type/comment; current frame/local/bytes and sole ref `0x61ebe8` unchanged. |
| C36I-071 | `0x517240-0x51724f`, `sub_517240`, `_WORD *__stdcall(_WORD *)`; four comments absent; frame plus `result _WORD *`; one ref. | Apply exact thiscall hidden-result style name/type/repeatable comment after C36I-060/C36I-062. | Stop if current lowering, frame/local/comments/ref/dependencies/name collision differs. Roll back original state on failure. | Exact semantic name/type/comment; current frame/local/bytes and sole ref `0x61ebec` unchanged. |
| C36I-072 | `0x517250-0x5172be`, `sub_517250`, `void __thiscall(_DWORD *this, GrafPort *)`; four comments absent; `RectBounds` local/cookie frame and `v3/v4/v5`; one ref. | Apply exact `SeparatorMenuItem__DrawItem` name/type/repeatable comment after C36I-060. | Stop if prototype/frame/locals/comments/ref/dependencies/name collision differs. Roll back original name/prototype/comments on failure. | Exact semantic name/type/comment; `RectBounds`/cookie frame, locals, bytes, and sole ref `0x61ebe4` unchanged. |
| C36I-073 | `0x4f4b10-0x4f4b16`, `LObject__GetRuntimeClass`, exact current type; address comments/repeatable absent; current regular sentence; return-only frame; 489 refs. | Replace only function-regular comment with the exact accepted sentence above. | Stop if range/name/type/three absent channels/current regular/frame/489 refs differs. Roll back only the old regular comment on failure. | New exact regular comment; name/type/three absent channels/frame/bytes and 489 refs unchanged. |
| C36I-074 | `0x41b6c0-0x41b6c3`, `LObject__OnChangeMessage`, exact current type; three absent channels; exact three-line regular; owner/message frame; 517 refs. | Replace only function-regular comment with the exact accepted folded-no-op sentence above. | Stop if range/name/type/three absent channels/current three-line regular/frame/517 refs differs. Roll back only the old three-line regular comment on failure. | New exact regular comment; name/type/three absent channels/frame/bytes and 517 refs unchanged. |
| C36I-075 | `0x61eb94-0x61eb98`, 4 bytes, unnamed/untyped, both comments absent, zero xrefs, value `0x64b604`. | Set only exact repeatable MenuItem COL-pointer comment. | Stop if boundary/name/type/comments/xrefs/value differs. Roll back repeatable to absent on failure. | Same item/name/type/value/zero xrefs; regular absent; repeatable exact. |
| C36I-076 | `0x61eb98` current 4-byte head, `??_7MenuItem@@6B@`, type/comments absent, five refs. | After C36I-057, type exact `0x18` span and set exact repeatable comment. | Stop if head/name/type/comments/five refs/cells or C36I-057 differs. Roll back span to six original dwords, absent type/comment, preserved name on failure. | Decorated name; exact UDT width `0x18`; exact repeatable; regular absent; five refs unchanged. |
| C36I-077 | `0x61ebb0-0x61ebb4`, 4 bytes, unnamed/untyped, both comments absent, zero xrefs, value `0x64b6d4`. | Set only exact repeatable String COL-pointer comment. | Stop if boundary/name/type/comments/xrefs/value differs. Roll back repeatable to absent on failure. | Same item/name/type/value/zero xrefs; regular absent; repeatable exact. |
| C36I-078 | `0x61ebb4` current 4-byte head, `??_7StringMenuItem@@6B@`, type/comments absent, one ref. | After C36I-057, type exact `0x18` span and set exact repeatable comment. | Stop if head/name/type/comments/ref/cells or C36I-057 differs. Roll back span to six original dwords, absent type/comment, preserved name on failure. | Decorated name; exact UDT width `0x18`; exact repeatable; regular absent; sole ref `0x51704e`. |
| C36I-079 | `0x61ebcc-0x61ebd0`, 4 bytes, unnamed/untyped, both comments absent, zero xrefs, value `0x64b724`. | Set only exact repeatable Separator COL-pointer comment. | Stop if boundary/name/type/comments/xrefs/value differs. Roll back repeatable to absent on failure. | Same item/name/type/value/zero xrefs; regular absent; repeatable exact. |
| C36I-080 | `0x61ebd0` current 4-byte head, `??_7SeparatorMenuItem@@6B@`, type/comments absent, one ref. | After C36I-058, type exact `0x20` span and set exact repeatable comment. | Stop if head/name/type/comments/ref/cells or C36I-058 differs. Roll back span to eight original dwords, absent type/comment, preserved name on failure. | Decorated name; exact UDT width `0x20`; exact repeatable; regular absent; sole ref `0x517205`. |
| C36I-081 | `0x64b604-0x64b608`, 4 bytes, `??_R4MenuItem@@6B@`, type absent, regular `signature`, repeatable absent, one ref `0x61eb94`. | No action; protected RTTI. | Any difference stops Gate 2B; never mutate or roll back this row. | Exact current boundary/name/type/comments/xref unchanged. |
| C36I-082 | `0x64b6d4-0x64b6d8`, 4 bytes, `??_R4StringMenuItem@@6B@`, type absent, regular `signature`, repeatable absent, one ref `0x61ebb0`. | No action; protected RTTI. | Any difference stops Gate 2B; never mutate or roll back this row. | Exact current boundary/name/type/comments/xref unchanged. |
| C36I-083 | `0x64b724-0x64b728`, 4 bytes, `??_R4SeparatorMenuItem@@6B@`, type absent, regular `signature`, repeatable absent, one ref `0x61ebcc`. | No action; protected RTTI. | Any difference stops Gate 2B; never mutate or roll back this row. | Exact current boundary/name/type/comments/xref unchanged. |

Negative constraints: do not rename decorated `??_R*`/`??_7*` entities; do not overwrite imported COM `MenuItemVtbl`; do not define fixed-address vtable arrays; do not rename `__purecall`; do not create a Separator destructor wrapper; do not change function boundaries, chunks, stack frames, locals, bytes, or unrelated comments; do not apply source UDTs outside the exact target/family without checking current uses. Supervisor must reread every row immediately before mutation, stop on any drift/collision/parse error, apply actions in dependency order, perform every exact readback, and save only after all accepted rows are coherent.

## First-Draft C++ Recommendation

- Eligible for draft C++: target compiler-data marker and directly affected support declarations/channel routing.
- Runtime behavior: class inheritance, pure virtual positions, concrete virtual ordering, object fields, and compiler-generated destructors reproduce the observed ABI-visible behavior without handwritten compiler artifacts.
- Human source shape: normal C++03-era classes, implicit virtual derived destructors, fixed inline text storage, simple POD return structs, and a `.h/.cpp` split replace decompiler labels and raw tables.
- Style: existing NexusTK PascalCase types/methods and `m_` member prefix; no `override`, `nullptr`, modern attributes, or reverse-engineering identifiers.

Exact target `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// [UID:00036I] Compiler-generated MenuItem, StringMenuItem, and
// SeparatorMenuItem RTTI complete-object-locator and vtable data.
// The class declarations and virtual method implementations regenerate this
// range; no fixed-address RTTI object, vtable array, or deleting wrapper is
// handwritten.
```

Exact target `RECONSTRUCTION_H CODE` insertion: blank. This memory range is generated `.rdata`, not authored header text.

Exact UID0001V5 CPP insertion:

```cpp
#include "PopupMenuControls.h"
```

Exact UID0001V5 H insertion:

```cpp
#pragma once

#include <errno.h>
#include <stddef.h>

#include "../../util/LObject.h"
#include "../core/RectBounds.h"

class GrafPort;

struct MenuItemMetrics
{
    int height;
    int width;
};

struct MenuItemStyleFlags
{
    unsigned short bits;
};
```

Exact UID00007V CPP insertion:

```cpp
[[CHILDREN]]
```

Exact UID00007V H insertion:

```cpp
class MenuItem : public LObject
{
public:
    MenuItem();

    bool IsEnabled() const;
    void SetEnabled(bool enabled);
    bool IsSelected() const;
    void SetSelected(bool selected);

    RectBounds *GetBounds(RectBounds *outBounds) const;
    void SetBounds(const RectBounds *bounds);

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const = 0;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const = 0;
    virtual void DrawItem(GrafPort *port) = 0;

protected:
    RectBounds m_bounds;
    bool m_enabled;
    bool m_selected;
};
```

Exact UID0000E8 CPP insertion:

```cpp
[[CHILDREN]]
```

Exact UID0000E8 H insertion:

```cpp
class StringMenuItem : public MenuItem
{
public:
    explicit StringMenuItem(const wchar_t *text);

    errno_t CopyText(wchar_t *destination, size_t sizeInWords) const;

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const;
    virtual void DrawItem(GrafPort *port);

protected:
    wchar_t m_text[0x80];
};
```

Exact UID0000CY CPP insertion:

```cpp
[[CHILDREN]]
```

Exact UID0000CY H insertion:

```cpp
class SeparatorMenuItem : public MenuItem
{
public:
    SeparatorMenuItem();

    virtual void DrawItem(GrafPort *port);
    virtual MenuItemMetrics GetDefaultDimensions() const;
    virtual MenuItemStyleFlags GetStyleFlags() const;
};
```

UID0001Y4 CPP remains its current compiler-generation marker plus `[[CHILDREN]]`; H remains blank. No third-party import applies.

## Final Recommendation

- UID00036I ordinary-document recommendation is applied with complete current evidence, `94/95`, semantic owner/emitter UID0001Y4, formal CPP marker, blank H, and no range split.
- UID0001Y4 ordinary-document recommendation is applied at `93/95`, with owner/emitter UID0000MN and position 13 preserved, exact RTTI hierarchy/abstractness/source route incorporated, and UID00036I documented through the child hook.
- UID0001V5/UID00007V/UID0000E8/UID0000CY declarations are migrated to H using the exact blocks above; child bodies remain in CPP; unsupported explicit derived destructor declarations are removed and historicalized.
- UID0000MN is updated at `88/88` with `PopupMenuControls.h`, the semantic vtable child route, sole-empty source-cause closure, and the bounded historical split caveat.
- The exact supervisor-owned IDA recommendations use the authoritative `2026-08-01T09:20:46-04:00` reconciliation matrix and require a literal row-by-row prestate/action/readback comparison. The four corrected current prototypes are prestates, not proposed end types. Preserve all decorated RTTI/vtable symbols, imported COM types, frames/locals, bytes, xrefs, and unrelated comment channels; obey each stop/rollback condition before saving.
- No target or support page should emit raw vtable/RTTI dwords or scalar-deleting-wrapper code.
- Future work outside this assignment: an original project/source archive could refine physical file spelling, but no current implementation or score is blocked on it.

## Recommended Target Doc Changes

- Historical accepted callback plan: update target `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` to `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:0001Y4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001Y4`, blank position, the exact First-Draft C++ no-code CPP marker, and blank H.
- Current post-callback state: that exact metadata and formal-channel state is physically present. Its Item Summary is `Exact three-class compiler RTTI/vtable run for MenuItem, StringMenuItem, and abstract SeparatorMenuItem, with single-inheritance RTTI chains, every slot/boundary, wrapper-size/source disposition, nonvirtual bounds exclusion, and semantic emission through MenuItemVtables.`
- Historical accepted detail plan, now completed: add the RTTI hierarchy, source class shape, wrapper/size proof, current IDA type state, semantic-owner route, empty-emitter source cause, and no-code proof while preserving every existing exact dword, xref, range boundary, predecessor/successor fact, bounds no-slot proof, old executed-report evidence, and changes history.
- Current preservation state: the former direct-file ownership is retained only as an explicitly superseded historical routing assumption, with UID0001Y4 documented as the narrower semantic parent; the accepted evidence and negative/history material remain present.
- Current destination identity and validator: SHA256 `5228A8DCF22FC35EDA6EFB890C06D44542B8B1EBF11B581DC9395341024D7023`; current callback scoped command `000000020670` at `2026-08-01T09:52:34-04:00` returned exit `0`, `ok: 1`, with generated refresh skipped.

## Recommended Support Doc Changes

- Historical accepted plan for `by-type/by-vtable/MenuItemVtables.md`: raise `86/91 -> 93/95`, add exact CHD/base arrays, class abstractness, wrapper sizes/folding, UID00036I child routing, the current IDA type collision, and source-cause closure while retaining owner/emitter UID0000MN, position 13, current CPP marker/children, and blank H. Current callback readback: already present at `93/95`, SHA256 `4E50D9CCE58F14A990403B443C49FC5CA55E0CA6BE71DB591E6518A64DBE60B3`; command `000000020672` at `2026-08-01T09:53:00-04:00` returned exit `0`, `ok: 1`, generated refresh skipped.
- Historical accepted plan for `by-type/by-struct/MenuItemLayouts.md`: raise `89/92 -> 92/94`, migrate support types to exact H, add the CPP include directive, resolve the 2-byte style result as a UDT, and record current/missing IDA UDT state. Current callback readback: already present at `92/94`, SHA256 `98D305A5E37974B8DFCD291BE238A71CD7B107B4F5EF04D670A4BD080536B9DA`; command `000000020673` at `2026-08-01T09:53:10-04:00` returned exit `0`, `ok: 1`, generated refresh skipped.
- Historical accepted plan for `by-class/MenuItem.md`: raise `91/93 -> 93/94`, migrate the declaration to H, leave CPP to children, remove the unproven explicit destructor declaration, and add the RTTI two-base/six-slot contract. Current callback readback: already present at `93/94`, SHA256 `53D2BD5E5B835CF9DB64E61F6015B44A2E0AE5D580898E4DE31F2CAD08A8806C`; command `000000020674` at `2026-08-01T09:53:20-04:00` returned exit `0`, `ok: 1`, generated refresh skipped.
- Historical accepted plan for `by-class/StringMenuItem.md`: raise `89/91 -> 92/94`, migrate the declaration to H, leave CPP to children, remove the unproven explicit destructor declaration, and add the RTTI three-base chain, six-slot concrete contract, 54 constructor callers, and `0x118` implicit-wrapper proof. Current callback readback: already present at `92/94`, SHA256 `8078193F2C7488E857EADF3CAF0AB2C563399267DE47BA90FE050F45D59A1F80`; command `000000020676` at `2026-08-01T09:53:29-04:00` returned exit `0`, `ok: 1`, generated refresh skipped.
- Historical accepted plan for `by-class/SeparatorMenuItem.md`: raise `88/91 -> 92/94`, migrate the declaration to H, leave CPP to children, remove the unproven explicit destructor declaration, state abstractness directly, preserve no fields/disabled constructor, and add the reused `0x18` wrapper/no-live-constructor proof. Current callback readback: already present at `92/94`, SHA256 `A19CD1FE72A0872104E9E596F117C58C5A29C734874EC50680E93C9EB7F5B7CE`; command `000000020677` at `2026-08-01T09:53:40-04:00` returned exit `0`, `ok: 1`, generated refresh skipped.
- Historical accepted plan for `by-file/PopupMenuControls.md`: raise `86/85 -> 88/88` and document the `PopupMenuControls.h` contract, UID0001Y4-to-UID00036I semantic route, sole empty-emitter closure, retained grouping, and historical split caveat. Current callback readback: already present at `88/88`, SHA256 `04C00A40488A6C5A64E0CDDCD6A2C0A4F6504EC504CE628AE9932DB163266ED0`; command `000000020678` at `2026-08-01T09:53:50-04:00` returned exit `0`, `ok: 1`, generated refresh skipped, with only the four pre-existing UID000376-UID000379 missing-reference warnings.
- Historical and current method/wrapper scope: no metadata/body changes were required for the exact method/wrapper pages. Links were added only where the accepted target/support prose required the source-cause chain, and no scalar-wrapper C++ was placed in UID0002JF/UID0002JG.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/91`, owner/emitter UID0000MN, blank position/CPP/H.
- Current ordinary-document target: `94/95`, owner/emitter UID0001Y4, blank position, formal CPP no-code marker, blank H.
- Reason not lower: every byte/dword/boundary, all decorated identities, all CHD/base arrays, every slot, all relevant vptr stores, wrapper sizes, object layouts, abstractness, nonvirtual exclusions, source cause, semantic owner, and IDA action/protection prestate are resolved. The live full-row reread corrected four prototype strings and confirmed every other C36I-056-C36I-083 literal state.
- Reason not higher: no original source archive proves exact lost lexical spellings or original physical source filename. The `94/95` target score is evidence-based documentation confidence and does not assume completion of supervisor-owned IDA, generated, manual-coverage, or lifecycle operations.
- Score-improvement attempt: hierarchy blocker resolved by CHD/base arrays; slot-name blocker resolved through typed LObject functions plus concrete String/Separator bodies; separator-interface blocker resolved by exact purecall positions; wrapper blocker resolved by implicit virtual destruction and size/folding; layout blocker resolved by wrappers/UDTs; owner blocker resolved through UID0001Y4; empty-emitter blocker resolved with exact formal marker/route; IDA blocker is now an exact current transaction with per-row stop/rollback/readback rather than a deferred or stale prestate.
- Support scores: UID0001Y4 `93/95`; UID0001V5 `92/94`; UID00007V `93/94`; UID0000E8 `92/94`; UID0000CY `92/94`; UID0000MN `88/88`.
- All support owner/emitter/reconstructable states remain unchanged except UID00036I's direct route.

## Open Questions With Attempted Resolution

- Is SeparatorMenuItem concrete? Resolved no: exact purecall slots at `+0x0c/+0x10` preserve abstractness. Its constructor/methods are retained out-of-line source despite no surviving instantiation route.
- Does Separator implement the base size method through `GetDefaultDimensions`? Resolved no: `GetDefaultDimensions` is a new `+0x18` slot; base `+0x0c` remains pure.
- Are GetBounds/SetBounds virtual? Resolved no by complete finite table enumeration and address exclusion.
- Do MenuItem-family classes require explicit source destructors? Best supported resolution is no for these derived declarations: LObject already has a virtual destructor, implicit derived destructors generate the observed wrappers, String's unique wrapper reflects delete size, and Separator's wrapper folds with the identical base-size path.
- Is MenuItemStyleFlags primitive? Resolved no: observed hidden-result pointer and `retn 4` conflict with primitive AX return. A 2-byte UDT is required; its source-facing name remains high-probability inference.
- Should the target split by class? Resolved no: contiguous exact family plus existing UID0001Y4 semantic owner avoids redundant pages and preserves one coherent table contract.
- Should the target remain direct file-owned? Resolved no: UID0001Y4 is the narrower semantic owner/emitter and already supports children.
- Was the empty emitter caused by insufficient binary knowledge? Resolved no: it is caused by blank formal CPP and semantic-route bypass.
- What is the original physical filename? Best supported current answer is `PopupMenuControls.h/.cpp`; a separate `MenuItem.h/.cpp` remains historically plausible but has no discriminating evidence. This uncertainty does not alter current source semantics and caps scores below perfect.
- Did Gate 2B drift invalidate the accepted semantic actions? Resolved no after a full live reread: four current function prototypes had improved/different IDA types, while bytes, ranges, decompilation, frames/locals, comments, xrefs, table slots, UDT dependencies, and protected entities remained coherent. The report now uses those exact current prototypes as prestates and retains the same evidence-backed source-quality end types under fail-closed per-row guards.
- No question remains without a best defensible resolution. No item is deferred merely for later investigation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The current manual rows were inspected for UID00036I, UID0001Y4, UID0001V5, UID00007V, UID0000E8, UID0000CY, and UID0000MN. UID00036I is absent; the six support rows are stale under the recommendation. B003 must not edit these files.

- File/placement: `by-memory/-coverage-report.md`, insert immediately under parent UID00025T `MemoryMenuReadOnlyData` and before UID00025U.

```text
        - [UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md) 0x0061eb94-0x0061ebf0 | compiler-generated RTTI/vtable data | MenuItemVtableData : reconstructable : 94% : very-strong : Exact 92-byte MenuItem/StringMenuItem/SeparatorMenuItem COL-and-vtable run with three decorated identities, complete single-inheritance RTTI chains, exact 6/6/8 slot maps, abstract MenuItem and Separator pure slots, inherited LObject slots, 0x18/0x118 wrapper-size evidence, constructor/destructor vptr refs, nonvirtual GetBounds/SetBounds exclusion, MENUBACK.EPF successor boundary, semantic owner/emitter UID0001Y4, and formal compiler-regenerated no-raw-data marker.
```

- File/placement: replace the exact UID0001Y4 row in `by-type/by-vtable/-coverage-report.md`.

```text
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md) : reconstructable : 93% : very-strong : Complete MenuItem/StringMenuItem/SeparatorMenuItem vtable contract with exact COL pointers, single-inheritance RTTI base arrays, 6/6/8 slots, inherited LObject identities, abstract base/separator pure slots, concrete String and separator methods, 0x18/0x118 deleting-wrapper size/folding proof, constructor/destructor stores, nonvirtual bounds exclusion, MENUBACK.EPF boundary, UID00036I semantic child route, and compiler-regenerated no-raw-vtable output.
```

- File/placement: replace UID0001V5 in `by-type/by-struct/-coverage-report.md`.

```text
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md) : reconstructable : 92% : very-strong : Exact MenuItem 0x18 layout, RectBounds +0x04, bool m_enabled/m_selected +0x14/+0x15, natural tail padding, StringMenuItem inline wchar_t[0x80] and 0x118 size, SeparatorMenuItem no-field 0x18 layout, height-first 8-byte MenuItemMetrics, ABI-proven 2-byte MenuItemStyleFlags UDT, constructor/accessor/navigation/draw/wrapper evidence, and source-ready PopupMenuControls.h declarations.
```

- File/placement: replace UID00007V, UID0000E8, and UID0000CY in `by-class/-coverage-report.md`.

```text
- [UID:00007V][MenuItem](by-class/MenuItem.md) : reconstructable : 93% : very-strong : Source-ready abstract LObject-derived MenuItem header declaration with exact two-base RTTI chain, six-slot virtual contract, implicit virtual destruction, 0x18 RectBounds/bool layout, exact constructor/state/bounds/wrapper children, nonvirtual bounds pair, compiler-generated RTTI/wrapper separation, UID0001Y4 data route, and UID0000MN file root.
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) : reconstructable : 92% : very-strong : Source-ready concrete StringMenuItem header declaration with exact StringMenuItem/MenuItem/LObject RTTI chain, six-slot concrete table, 54 constructor callers, inline wchar_t[0x80] at +0x18, 0x118 wrapper-size proof, exact copy/measure/text/draw children, implicit virtual destruction, UID0001Y4 data route, and UID0000MN file root.
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) : reconstructable : 92% : very-strong : Source-ready abstract SeparatorMenuItem header declaration with exact SeparatorMenuItem/MenuItem/LObject RTTI chain, no derived fields and 0x18 size, disabled constructor, inherited pure GetItemSize/GetText slots, DrawItem plus GetDefaultDimensions/GetStyleFlags slots, folded MenuItem deleting wrapper, zero direct constructor route preserved as negative evidence, UID0001Y4 data route, and UID0000MN file root.
```

- File/placement: replace UID0000MN in `by-file/-coverage-report.md`.

```text
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) : reconstructable : 88% : very-strong : Coherent NexusTK/ui/menu/PopupMenuControls.h/.cpp source root for PopupMenuControlPane, MenuPane, and MenuItem families; menu support types/classes now occupy the formal header channel, exact child methods remain in CPP, UID0001Y4 owns UID00036I compiler RTTI/vtable data, the sole empty emitter is closed without raw tables/wrappers, and a possible original physical source split remains only a below-perfect placement cap.
```

- Reason B agent must not apply directly: all manual `-coverage-report.md` files are supervisor-owned collision points; generated tracker content is validator-owned and receives no hand-written row.

## Follow-Up Actions

- Historical first Gate 1/callback transaction: Gate 1 passed `33/33` for report SHA256 `D64444E59F6CBA15B139F5CDEC50368A15B7CCBE8065005DABCFC55953A40730`; the same-agent B003 ordinary callback then incorporated accepted ordinary claims into the seven authorized destinations. The callback did not edit manual coverage/generated/lifecycle files or mutate IDA.
- Current callback transaction: Gate 1 passed for exact SHA256 `E5F92BCCC8137D077946B5926473E29E2281DE6BD598FAF42114C8939A03F1F7`. B003 compared every ordinary C36I-001-C36I-055 and C36I-102-C36I-105 obligation against its literal destination, found all already present at same-or-greater report-level detail and the exact accepted hashes, confirmed C36I-048-C36I-055 unchanged, and reran C36I-091-C36I-097 successfully. No ordinary destination needed a content rewrite.
- Current ordinary-document identity: target SHA256 `5228A8DCF22FC35EDA6EFB890C06D44542B8B1EBF11B581DC9395341024D7023`; support hashes `4E50D9CCE58F14A990403B443C49FC5CA55E0CA6BE71DB591E6518A64DBE60B3`, `98D305A5E37974B8DFCD291BE238A71CD7B107B4F5EF04D670A4BD080536B9DA`, `53D2BD5E5B835CF9DB64E61F6015B44A2E0AE5D580898E4DE31F2CAD08A8806C`, `8078193F2C7488E857EADF3CAF0AB2C563399267DE47BA90FE050F45D59A1F80`, `A19CD1FE72A0872104E9E596F117C58C5A29C734874EC50680E93C9EB7F5B7CE`, and `04C00A40488A6C5A64E0CDDCD6A2C0A4F6504EC504CE628AE9932DB163266ED0`. Current scoped commands `000000020670`, `000000020672`, `000000020673`, `000000020674`, `000000020676`, `000000020677`, and `000000020678` all returned exit `0`, `ok: 1`, with generated refresh skipped; historical command identities remain explicitly preserved in the Function / Child Inventory.
- Historical supervisor verification: exact report SHA256 `6DFFC63AE4B033A549778C71C1B9E72D2A8AFD4F6997DD7EE18B990393CF1BF9` passed Gate 1 and Gate 2A. Gate 2B then failed closed before mutation when its literal prestate check found four prototype differences. No ordinary documentation or validator result was invalidated.
- Supervisor-owned verification contract: Gate 2A compares the current report and destination hashes claim by claim; Gate 2B rereads and applies only C36I-056-C36I-083 under the exact stop/rollback matrix; combined Gate 2 requires both; report execution/archive and post-move verification remain supervisor-only. This describes the invariant workflow rather than embedding a transient current lifecycle state.
- No A-agent or future B-agent research action is required for this target. Original-source discovery could refine file spelling but is not an open blocker.

## Confidence

- Recommendation confidence: 95/100 for hierarchy, slots, range, compiler/source disposition, semantic vtable ownership, and formal marker; 92/100 for exact lost lexical method/type names and current physical source filename.
- Current post-callback score confidence: high. The accepted scores are physically present, not proposed: UID00036I `94/95`, UID0001Y4 `93/95`, UID0001V5 `92/94`, UID00007V `93/94`, UID0000E8 `92/94`, UID0000CY `92/94`, and UID0000MN `88/88` at destination hashes `5228A8DCF22FC35EDA6EFB890C06D44542B8B1EBF11B581DC9395341024D7023`, `4E50D9CCE58F14A990403B443C49FC5CA55E0CA6BE71DB591E6518A64DBE60B3`, `98D305A5E37974B8DFCD291BE238A71CD7B107B4F5EF04D670A4BD080536B9DA`, `53D2BD5E5B835CF9DB64E61F6015B44A2E0AE5D580898E4DE31F2CAD08A8806C`, `8078193F2C7488E857EADF3CAF0AB2C563399267DE47BA90FE050F45D59A1F80`, `A19CD1FE72A0872104E9E596F117C58C5A29C734874EC50680E93C9EB7F5B7CE`, and `04C00A40488A6C5A64E0CDDCD6A2C0A4F6504EC504CE628AE9932DB163266ED0` respectively.
- Current validator confidence: commands `000000020670`, `000000020672`, `000000020673`, `000000020674`, `000000020676`, `000000020677`, and `000000020678` each returned exit `0`, `ok: 1`, with generated refresh skipped. Gate 2B, manual coverage, generated verification, combined Gate 2, and lifecycle state remain supervisor-owned and authoritative from external readbacks/status.
- Remaining uncertainty: exact original lexical spellings and historical file subdivision only. No uncertainty remains that would justify an IDA label in final code, blank formal emitter, unresolved owner, or postponed heuristic investigation.

## Validator Results

- All commands ran from `source-3/project-documentation` with the destination leased only for that validator call. Every command used `--no-generated-refresh`; no report lifecycle command was run.
- C36I-091: `python .\tools\validator.py --mode file --file by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020670`, timestamp `2026-08-01T09:52:34-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- C36I-092: `python .\tools\validator.py --mode file --file by-type/by-vtable/MenuItemVtables.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020672`, timestamp `2026-08-01T09:53:00-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- C36I-093: `python .\tools\validator.py --mode file --file by-type/by-struct/MenuItemLayouts.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020673`, timestamp `2026-08-01T09:53:10-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- C36I-094: `python .\tools\validator.py --mode file --file by-class/MenuItem.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020674`, timestamp `2026-08-01T09:53:20-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- C36I-095: `python .\tools\validator.py --mode file --file by-class/StringMenuItem.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020676`, timestamp `2026-08-01T09:53:29-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- C36I-096: `python .\tools\validator.py --mode file --file by-class/SeparatorMenuItem.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020677`, timestamp `2026-08-01T09:53:40-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- C36I-097: `python .\tools\validator.py --mode file --file by-file/PopupMenuControls.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020678`, timestamp `2026-08-01T09:53:50-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- C36I-097 preserved four pre-existing registry warnings: referenced UIDs `000376`, `000377`, `000378`, and `000379` are absent from `validator.ini`. They predate this callback, do not invalidate `ok: 1`, and remain outside the authorized document/lifecycle scope.
- Validator-owned incremental registry/projected-stat updates occurred as normal command side effects. Generated source/report refresh was disabled and is still supervisor-owned under C36I-098-C36I-101.

## Changed Files

- Current ordinary destinations and post-validator SHA256 identities; all accepted content was already present at same-or-greater detail, so this callback performed readback plus scoped validation without a content rewrite:
  - `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`: `5228A8DCF22FC35EDA6EFB890C06D44542B8B1EBF11B581DC9395341024D7023`, 24609 bytes, 209 physical lines.
  - `by-type/by-vtable/MenuItemVtables.md`: `4E50D9CCE58F14A990403B443C49FC5CA55E0CA6BE71DB591E6518A64DBE60B3`, 23400 bytes, 170 physical lines.
  - `by-type/by-struct/MenuItemLayouts.md`: `98D305A5E37974B8DFCD291BE238A71CD7B107B4F5EF04D670A4BD080536B9DA`, 24342 bytes, 202 physical lines.
  - `by-class/MenuItem.md`: `53D2BD5E5B835CF9DB64E61F6015B44A2E0AE5D580898E4DE31F2CAD08A8806C`, 25175 bytes, 191 physical lines.
  - `by-class/StringMenuItem.md`: `8078193F2C7488E857EADF3CAF0AB2C563399267DE47BA90FE050F45D59A1F80`, 21868 bytes, 172 physical lines.
  - `by-class/SeparatorMenuItem.md`: `A19CD1FE72A0872104E9E596F117C58C5A29C734874EC50680E93C9EB7F5B7CE`, 15415 bytes, 139 physical lines.
  - `by-file/PopupMenuControls.md`: `04C00A40488A6C5A64E0CDDCD6A2C0A4F6504EC504CE628AE9932DB163266ED0`, 42630 bytes, 252 physical lines.
- Verified unchanged support pages C36I-048-C36I-055: UID0002J8 `EE088FD61A710E2A51F880F0CD0BE878FA7C573730873494C937258713916AEB`; UID0002J9 `625CB4E6573ECD18E33F6B4E2A83391001D47D156F12FE1214F7B84C3DD2B1F2`; UID0002JA `62C78032D4EDB1F1B46F1DAE39B937674C7A0BFC9AD45827D7A9B58299D9EB66`; UID0002JC `B3A96ABD89B95EE8553565CEE5721E2DFDBF8DBDCE7644280529EC6087BBE711`; UID0002JD `2F9E8F2CC50977AF847F0FF04A70742451E339CE321ADEE347409A560F33783F`; UID0002JE `BA9B72CCB39E948A35041DB0A7FD49E951515B8FF75CB96935B39A75030EEC78`; UID0002JF `57D98CBA83179B721B81CFB75715934CDA98E28DDB69636E1E28DE45E0165354`; UID0002JG `FF394A4B2B8913B4A10C36BA54B7DE69D81B4F59FC106617B03862DD3A637402`.
- Modified this same report for current callback authorization, current already-present/readback status, fresh validator evidence, destination hashes, and final handoff marker. No report was created, renamed, moved, archived, executed, probed, or dry-run through lifecycle commands.
- Current callback leases: each of the seven authorized ordinary destinations was leased only for its fresh scoped validator and released immediately afterward. No by-* content edit was needed. This same report received one short reconciliation lease for the present update and is released immediately after the edit/readback. Historical callback lease facts remain in prior report history and are not restated as current actions.
- IDA changes: none. Historical ordinary callback performed no IDA access or mutation. During this report repair B003 used mandatory live read-only MCP session `b3b2bf88` and reread every C36I-056-C36I-083 entity at `2026-08-01T09:20:46-04:00`; no IDA type/name/comment/frame/local/data change, save, or rollback was attempted. Gate 2B remains supervisor-owned.
- Manual/generated/lifecycle changes: none by B003. C36I-084-C36I-090 and C36I-098-C36I-101 remain unchecked and supervisor-owned; generated refresh was explicitly disabled.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the physical report path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Gate 1 and ordinary callback handoff:

- Historical supervisor Gate 1 passed 33/33 for exact pre-callback SHA256 `D64444E59F6CBA15B139F5CDEC50368A15B7CCBE8065005DABCFC55953A40730` and led to the first ordinary callback.
- Supervisor Gate 1 passed exact repaired pre-callback SHA256 `E5F92BCCC8137D077946B5926473E29E2281DE6BD598FAF42114C8939A03F1F7`.
- That exact report received the current same-agent ordinary implementation callback.

Atomic callback and supervisor verification matrix: B003 checks only physically applied/read-back ordinary and validator obligations. Imperative wording in checked C36I-001-C36I-055 and C36I-102-C36I-105 rows names the accepted obligation; the check means the current callback found it already present at same-or-greater detail at the exact recorded destination hash. C36I-091-C36I-097 refer to the fresh commands recorded under Validator Results. C36I-056-C36I-090 and C36I-098-C36I-101 remain unchecked and supervisor-owned.

- [x] C36I-001: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Range and Boundaries with the exact range, three records, no padding, predecessor, and successor.
- [x] C36I-002: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / RTTI Hierarchy with all three exact inheritance chains, CHD attributes, and PMDs.
- [x] C36I-003: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Slot Map with exact 6/6/8 cells.
- [x] C36I-004: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Source Class Shape with abstract/concrete and nonvirtual-bounds results.
- [x] C36I-005: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Object Layout with exact `0x18/0x118/0x18` sizes and text field.
- [x] C36I-006: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Wrapper And Destructor Disposition with exact folding and implicit-destructor rationale.
- [x] C36I-007: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Reachability And Negative Evidence with 54/zero xrefs and zero VA hits.
- [x] C36I-008: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` / Ownership And Emission to UID0001Y4 direct owner/emitter and UID0000MN source root.
- [x] C36I-009: update `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` metadata to 94/95, owner/emitter 0001Y4, reconstructable true, blank position.
- [x] C36I-010: insert exact formal CPP no-raw-data comment in `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`.
- [x] C36I-011: verify formal H remains blank in `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`.
- [x] C36I-012: replace Item Summary in `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` with the exact recommended text.
- [x] C36I-013: add RTTI hierarchy to `by-type/by-vtable/MenuItemVtables.md` / RTTI Hierarchy.
- [x] C36I-014: replace/refine `by-type/by-vtable/MenuItemVtables.md` / Slot Contract with exact 6/6/8 tables and abstractness.
- [x] C36I-015: add exact wrapper/destructor disposition to `by-type/by-vtable/MenuItemVtables.md`.
- [x] C36I-016: attach UID00036I through `[[CHILDREN]]` in `by-type/by-vtable/MenuItemVtables.md`; retain owner/emitter 0000MN and position 13.
- [x] C36I-017: add exact live IDA type collision state to `by-type/by-vtable/MenuItemVtables.md`.
- [x] C36I-018: update `by-type/by-vtable/MenuItemVtables.md` scores to 93/95 only.
- [x] C36I-019: update `by-type/by-struct/MenuItemLayouts.md` / Layouts with exact class layouts and padding.
- [x] C36I-020: insert exact `MenuItemMetrics` declaration into `by-type/by-struct/MenuItemLayouts.md` formal H.
- [x] C36I-021: insert exact `MenuItemStyleFlags` declaration into `by-type/by-struct/MenuItemLayouts.md` formal H.
- [x] C36I-022: replace formal channels in `by-type/by-struct/MenuItemLayouts.md`: declarations in H and one `PopupMenuControls.h` include in CPP.
- [x] C36I-023: add exact live IDA type presence/absence state to `by-type/by-struct/MenuItemLayouts.md`.
- [x] C36I-024: update `by-type/by-struct/MenuItemLayouts.md` scores to 92/94 only.
- [x] C36I-025: update `by-class/MenuItem.md` / Hierarchy And Virtual Contract with exact chain, six slots, layout, and nonvirtual bounds.
- [x] C36I-026: replace stale destructor source-shape claim in `by-class/MenuItem.md` with implicit-derived-destructor evidence.
- [x] C36I-027: move `by-class/MenuItem.md` declaration to formal H and leave formal CPP as `[[CHILDREN]]` only.
- [x] C36I-028: update `by-class/MenuItem.md` scores to 93/94 only.
- [x] C36I-029: add UID0001Y4 -> UID00036I route and UID0000MN source root to `by-class/MenuItem.md`.
- [x] C36I-030: preserve/annotate rejected raw-wrapper/destructor/no-slot history in `by-class/MenuItem.md`.
- [x] C36I-031: update `by-class/StringMenuItem.md` hierarchy, concrete slots, inline text, and `0x118` size.
- [x] C36I-032: add 54 constructor callers and String wrapper proof to `by-class/StringMenuItem.md`.
- [x] C36I-033: remove unsupported explicit derived destructor from `by-class/StringMenuItem.md` and add implicit source-shape rationale.
- [x] C36I-034: move `by-class/StringMenuItem.md` declaration to formal H and leave formal CPP as `[[CHILDREN]]` only.
- [x] C36I-035: update `by-class/StringMenuItem.md` scores to 92/94 only.
- [x] C36I-036: add semantic route and preserve rejected aliases/history in `by-class/StringMenuItem.md`.
- [x] C36I-037: update `by-class/SeparatorMenuItem.md` hierarchy and explicit abstract GetItemSize/GetText state.
- [x] C36I-038: update `by-class/SeparatorMenuItem.md` virtual-method table with DrawItem, GetDefaultDimensions, and GetStyleFlags.
- [x] C36I-039: update `by-class/SeparatorMenuItem.md` layout/destruction with no fields, `0x18`, folded wrapper, implicit destructor.
- [x] C36I-040: add disabled-constructor and zero-route retained-source evidence to `by-class/SeparatorMenuItem.md`.
- [x] C36I-041: move `by-class/SeparatorMenuItem.md` declaration to formal H and leave formal CPP as `[[CHILDREN]]` only.
- [x] C36I-042: update `by-class/SeparatorMenuItem.md` scores to 92/94 only.
- [x] C36I-043: add semantic route and preserve rejected concrete/separate-destructor history in `by-class/SeparatorMenuItem.md`.
- [x] C36I-044: update `by-file/PopupMenuControls.md` / Source Placement And Routing with current H/CPP root and UID0001Y4 -> UID00036I route.
- [x] C36I-045: add exact header/source/no-raw-output contract to `by-file/PopupMenuControls.md`.
- [x] C36I-046: add bounded historical physical-split caveat to `by-file/PopupMenuControls.md`.
- [x] C36I-047: update `by-file/PopupMenuControls.md` scores to 88/88 only.
- [x] C36I-048: verify `by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md` unchanged; add support links only where required.
- [x] C36I-049: verify `by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md` unchanged; add support links only where required.
- [x] C36I-050: verify `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md` unchanged; add support links only where required.
- [x] C36I-051: verify `by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md` unchanged; add support links only where required.
- [x] C36I-052: verify `by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md` unchanged; add support links only where required.
- [x] C36I-053: verify `by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md` unchanged; add support links only where required.
- [x] C36I-054: verify `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md` unchanged and non-emitting.
- [x] C36I-055: verify `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md` unchanged and non-emitting.
- [ ] C36I-056: reread current `MenuItem` size `0x18`/five members/`lpVtbl MenuItemVtbl *`; after C36I-057 replace only `lpVtbl`, stop on any drift, roll back exact original declaration on mismatch, and require the same layout with `NexusTKMenuItemVtable *`.
- [ ] C36I-057: confirm `NexusTKMenuItemVtable` remains absent with no collision; after C36I-061 create exact six-slot size-`0x18` UDT, stop on dependency/layout failure, delete only the new UDT on rollback, and read back all six exact members.
- [ ] C36I-058: confirm `NexusTKSeparatorMenuItemVtable` remains absent; after C36I-057/060/061/062 create exact eight-slot size-`0x20` UDT, stop/rollback on collision or dependency/layout failure, and read back all eight exact members.
- [ ] C36I-059: confirm `StringMenuItem` remains absent and `MenuItem` remains `0x18`; create base plus `wchar_t[128]`, stop on collision/layout drift, delete the new UDT on rollback, and require size `0x118` with members at `0/+0x18` only.
- [ ] C36I-060: confirm `SeparatorMenuItem` remains absent and `MenuItem` remains `0x18`; create sole flattened base, stop on collision/layout drift, delete the new UDT on rollback, and require size `0x18`/one member.
- [ ] C36I-061: confirm `MenuItemMetrics` remains absent; create two `int` members, stop/rollback on collision/layout drift, and require size 8 with `height +0`, `width +4`.
- [ ] C36I-062: confirm `MenuItemStyleFlags` remains absent; create sole `unsigned short bits`, stop/rollback on collision/layout drift, and require size 2/member `+0`.
- [ ] C36I-063: verify protected COM `MenuItemVtbl` remains exact size `0x34` with 13 members; any difference stops Gate 2B and no mutation is permitted.
- [ ] C36I-064: verify protected `RectBounds` remains size `0x10` with four `int` members at `0/4/8/c`; any difference stops Gate 2B and no mutation is permitted.
- [ ] C36I-065: reread `0x5172e0-0x51731e` as `sub_5172E0`, `LObject *__thiscall(LObject *Block, char)`, four absent comments, exact frame/parameters/two refs; apply accepted MenuItem wrapper action, stop/restore original name/type/comments on mismatch, and read back all protected state.
- [ ] C36I-066: reread `0x517400-0x517441` as `sub_517400`, `LObject *__thiscall(LObject *Block, char)`, four absent comments, exact frame/parameters/one ref; apply accepted String wrapper action after C36I-059, stop/restore on mismatch, and read back all protected state.
- [ ] C36I-067: reread `0x517090-0x5170d0` as `_DWORD *__thiscall(char *this, _DWORD *, GrafPort *)` with exact comments/frame/locals/one ref; apply accepted size-method action after C36I-059/061, stop/restore on mismatch, and require exact semantic type/comment with protected state unchanged.
- [ ] C36I-068: reread `0x5170d0-0x5170e9` exact CRT prototype/comments/frame/no-locals/one ref; apply accepted text-method action after C36I-059, stop/restore on mismatch, and require exact semantic type/comment with protected state unchanged.
- [ ] C36I-069: reread `0x5170f0-0x5171a2` current `void __thiscall(int this, GrafPort *)`/comments/frame/register locals/one ref; apply accepted draw action after C36I-059, stop/restore on mismatch, and require exact semantic type/comment with protected state unchanged.
- [ ] C36I-070: reread `0x517220-0x517237` current `_DWORD *__stdcall(_DWORD *)`/comments/frame/result local/one ref; apply accepted hidden-result action after C36I-060/061, stop/restore on mismatch, and require exact thiscall semantic readback with protected state unchanged.
- [ ] C36I-071: reread `0x517240-0x51724f` current `_WORD *__stdcall(_WORD *)`/comments/frame/result local/one ref; apply accepted hidden-result action after C36I-060/062, stop/restore on mismatch, and require exact thiscall semantic readback with protected state unchanged.
- [ ] C36I-072: reread `0x517250-0x5172be` as `void __thiscall(_DWORD *this, GrafPort *)` with four absent comments, exact `RectBounds`/cookie frame, locals, and one ref; apply accepted Separator draw action after C36I-060, stop/restore on mismatch, and require all protected state unchanged.
- [ ] C36I-073: reread `0x4f4b10` exact name/type/current regular/three absent channels/return-only frame/489 refs; replace only regular comment, stop and restore old sentence on mismatch, and require every other field unchanged.
- [ ] C36I-074: reread `0x41b6c0` exact folded name/type/current three-line regular/three absent channels/owner-message frame/517 refs; replace only regular comment, stop and restore old three-line text on mismatch, and require every other field unchanged.
- [ ] C36I-075: reread `0x61eb94-0x61eb98` unnamed/untyped/commentless/zero-xref/value `0x64b604`; set only exact repeatable comment, stop/clear it on mismatch, and preserve every other field.
- [ ] C36I-076: reread `0x61eb98` 4-byte `??_7MenuItem@@6B@` head with absent type/comments and five refs; after C36I-057 type/comment exact `0x18` span, stop and restore original six dwords/absence state on mismatch, and preserve decorated name/five refs.
- [ ] C36I-077: reread `0x61ebb0-0x61ebb4` unnamed/untyped/commentless/zero-xref/value `0x64b6d4`; set only exact repeatable comment, stop/clear it on mismatch, and preserve every other field.
- [ ] C36I-078: reread `0x61ebb4` 4-byte `??_7StringMenuItem@@6B@` head with absent type/comments and one ref; after C36I-057 type/comment exact `0x18` span, stop and restore original six dwords/absence state on mismatch, and preserve decorated name/ref.
- [ ] C36I-079: reread `0x61ebcc-0x61ebd0` unnamed/untyped/commentless/zero-xref/value `0x64b724`; set only exact repeatable comment, stop/clear it on mismatch, and preserve every other field.
- [ ] C36I-080: reread `0x61ebd0` 4-byte `??_7SeparatorMenuItem@@6B@` head with absent type/comments and one ref; after C36I-058 type/comment exact `0x20` span, stop and restore original eight dwords/absence state on mismatch, and preserve decorated name/ref.
- [ ] C36I-081: verify protected `0x64b604-0x64b608` remains 4-byte `??_R4MenuItem@@6B@`, type absent, regular `signature`, repeatable absent, one ref; any difference stops Gate 2B and no mutation is permitted.
- [ ] C36I-082: verify protected `0x64b6d4-0x64b6d8` remains 4-byte `??_R4StringMenuItem@@6B@`, type absent, regular `signature`, repeatable absent, one ref; any difference stops Gate 2B and no mutation is permitted.
- [ ] C36I-083: verify protected `0x64b724-0x64b728` remains 4-byte `??_R4SeparatorMenuItem@@6B@`, type absent, regular `signature`, repeatable absent, one ref; any difference stops Gate 2B and no mutation is permitted.
- [ ] C36I-084: supervisor inserts the exact UID00036I text in `by-memory/-coverage-report.md` under UID00025T and before UID00025U.
- [ ] C36I-085: supervisor replaces UID0001Y4 in `by-type/by-vtable/-coverage-report.md` with the exact supplied row.
- [ ] C36I-086: supervisor replaces UID0001V5 in `by-type/by-struct/-coverage-report.md` with the exact supplied row.
- [ ] C36I-087: supervisor replaces UID00007V in `by-class/-coverage-report.md` with the exact supplied row.
- [ ] C36I-088: supervisor replaces UID0000E8 in `by-class/-coverage-report.md` with the exact supplied row.
- [ ] C36I-089: supervisor replaces UID0000CY in `by-class/-coverage-report.md` with the exact supplied row.
- [ ] C36I-090: supervisor replaces UID0000MN in `by-file/-coverage-report.md` with the exact supplied row.
- [x] C36I-091: run the listed scoped validator for `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md` and record result.
- [x] C36I-092: run the listed scoped validator for `by-type/by-vtable/MenuItemVtables.md` and record result.
- [x] C36I-093: run the listed scoped validator for `by-type/by-struct/MenuItemLayouts.md` and record result.
- [x] C36I-094: run the listed scoped validator for `by-class/MenuItem.md` and record result.
- [x] C36I-095: run the listed scoped validator for `by-class/StringMenuItem.md` and record result.
- [x] C36I-096: run the listed scoped validator for `by-class/SeparatorMenuItem.md` and record result.
- [x] C36I-097: run the listed scoped validator for `by-file/PopupMenuControls.md` and record result.
- [ ] C36I-098: supervisor verifies `auto-generated/NexusTK/ui/menu/PopupMenuControls.h` has support UDTs and three class declarations exactly once.
- [ ] C36I-099: supervisor verifies `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` includes its header before exact child method definitions.
- [ ] C36I-100: supervisor verifies UID00036I has no empty marker and UID0001Y4 has attached children in `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.
- [ ] C36I-101: supervisor verifies the generated `PopupMenuControls.h/.cpp` pair has no raw RTTI/vtable/wrapper source, duplicate declarations, or missing destructor definitions.
- [x] C36I-102: record no-third-party-import proof in `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`; no `third_party_embeds/...` directive.
- [x] C36I-103: preserve/annotate historical and negative alternatives in `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`; ignore Wave2/Wave3.
- [x] C36I-104: retain no-additional-target scope in this physical report; support UIDs remain support-only.
- [x] C36I-105: retain supervisor ownership of IDA/manual/generated/lifecycle work and B003 ownership only of an accepted ordinary-doc callback.

Callback closeout:

- All ordinary C36I-001-C36I-055, validator C36I-091-C36I-097, and scope/history C36I-102-C36I-105 obligations were compared individually against their literal destinations/readbacks; all were already present or freshly passed, with no ordinary deviation.
- Supervisor-owned C36I-056-C36I-090 and C36I-098-C36I-101 require their separate IDA/manual/generated readbacks and remain deliberately unchecked.
- All ordinary-document leases were taken only immediately before edits and released immediately afterward.
- Report body remains lifecycle-neutral; execution/archive truth stays external and supervisor/validator-owned.
- Report returns with all authorized ordinary claims physically verified and fresh scoped validators recorded; supervisor-owned IDA/manual/generated/combined-gate/lifecycle state remains external.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000020745","destination_path":"executed-b-agent-research/B003/00036I-MenuItemVtableData-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00036I-MenuItemVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-02T21:14:33-04:00","uid":"00036I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
