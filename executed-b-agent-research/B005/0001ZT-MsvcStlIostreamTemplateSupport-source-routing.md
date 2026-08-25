** TARGET-REPORT-UID:0001ZT **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001ZT MsvcStlIostreamTemplateSupport Source-Routing Report

Agent: B005  
Assignment: report-only source-routing/source-quality pass  
Target UID: `0001ZT`  
Target path: `source-3/project-documentation/by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md`  
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0001ZT-MsvcStlIostreamTemplateSupport-source-routing.md`

## Final Recommendation

Keep [UID:0001ZT] non-reconstructable and non-emitting. Change the target score from `84/90` to `87/92` after implementation, keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:FALSE`, keep `EMITTER_UIDS:` blank, and keep the formal C++ block blank.

This range is best documented as a closed MSVC/Dinkumware STL, iostream, locale, exception, string, map/set, and template-support island. It is heavily called by JsonCpp, and later runtime/product code also calls it, but the code is not JsonCpp-authored source and is not NexusTK product logic. The rebuild source should keep normal C++ standard-library and JsonCpp calls at their source sites and let the selected MSVC-era compiler/runtime/template model generate equivalent helper code.

Do not split the range for source emission. The subfamilies are useful for documentation and IDA comments, but every checked subfamily has the same runtime/compiler-template source policy.

## Evidence Checked

Repository docs checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- target [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](../../../../../by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md)
- preceding [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](../../../../../by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md)
- following [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](../../../../../by-memory/0x00439e00-0x00439ea3.DequeDestroy.md)
- later [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](../../../../../by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md)
- later [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](../../../../../by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md)
- [UID:0000KI][JsonCpp](../../../../../by-file/JsonCpp.md)
- [UID:0001QE][client_libraries](../../../../../by-meta/client_libraries.md)
- `by-memory/-coverage-report.md` target row area, read only
- `by-memory/-ignored.md`
- `auto-generated/by-memory-tool-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- prior B002 executed report `tools/leaser/Agents/Agent-B002/research/executed/older/0000WZ-jsoncpp-value-path-crt-source-inference.md`

Local binary evidence:

- Read-only PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Sections observed by manual PE parser:
  - `.text` `0x00401000-0x0060c4ac`
  - `.rdata` `0x0060d000-0x0066c0be`
  - `.data` `0x0066d000-0x0069ce24`
  - `.rsrc` `0x0069d000-0x006b2c38`
- Capstone/local byte checks were used for current-session boundary and caller/string evidence. Live IDA MCP was not exposed through the current tool surface during this pass; the target doc's existing 2026-06-04 live IDA MCP evidence remains controlling for IDA-modeled function counts and exact start inventory.

## Boundary Recheck

The target's half-open byte range remains `0x004361b0-0x00439df9`.

Start boundary:

- [UID:0001ZS] ends with raw JsonCpp `BuiltStyledStreamWriter::hasCommentForValue` at `0x00436180-0x004361ae`.
- Bytes `0x004361ae-0x004361b0` are `cc cc`.
- The first target function starts at `0x004361b0`.

```asm
004361b0: push    ebp
004361b1: mov     ebp, esp
004361b3: push    -1
004361b5: push    0x5f8cc8
004361ba: mov     eax, dword ptr fs:[0]
004361c0: push    eax
004361c1: push    ecx
004361c2: push    esi
004361c3: push    edi
```

End boundary:

- The final target function is the existing IDA-modeled `sub_439CF0`.
- Local disassembly confirms the tail reaches `ret` at `0x00439df3`, followed by a cleanup-call instruction at `0x00439df4`, then the function/range ends at `0x00439df9`.
- Bytes `0x00439df9-0x00439e00` are seven `0xcc` bytes.
- [UID:0000XA] begins at `0x00439e00` and is project `Deque` code, not part of this runtime-support island.

```asm
00439dd9: push    8
00439ddb: push    esi
00439ddc: call    0x5c7526
00439de1: add     esp, 8
00439de4: mov     ecx, dword ptr [ebp - 0xc]
00439de7: mov     dword ptr fs:[0], ecx
00439dee: pop     ecx
00439def: pop     esi
00439df0: mov     esp, ebp
00439df2: pop     ebp
00439df3: ret
00439df4: call    0x5cd607
00439df9: int3
00439dfa: int3
00439dfb: int3
00439dfc: int3
00439dfd: int3
00439dfe: int3
00439dff: int3
00439e00: push    esi
00439e01: mov     esi, ecx
```

Conclusion: the island boundaries are exact. The range should not absorb the JsonCpp helper before it, the `DequeDestroy` function after it, or the later JsonCpp EH cleanup chunk at `0x00439eb0-0x00439ed5`.

## Function-Family Classification

Existing live IDA evidence in the target doc reports 63 modeled functions from `sub_4361B0` through `sub_439CF0`. Current local evidence supports the same source-routing policy for all documented families:

| Range | Representative functions | Classification | Source-routing conclusion |
| --- | --- | --- | --- |
| `0x004361b0-0x0043633e` | `sub_4361B0`, `sub_436260` | `std::string` / `std::map` copy and construction support | Compiler/runtime template support. Called from JsonCpp value-core style code, but not JsonCpp-owned source. |
| `0x00436340-0x0043691d` | `sub_436340`, `sub_436630` | iostream output state/sentry helpers | Dinkumware iostream support. Diagnostic strings and throw behavior identify `std::ios_base` support. |
| `0x00436920-0x00437e17` | `sub_436920` through `sub_437A90` | STL string/container helper templates | Shared allocation, append, compare, and container support used by JsonCpp and other callers. |
| `0x00437e40-0x004380f4` | `sub_437E40`, `sub_437FA0` | map/set insertion and growth guards | Dinkumware container support. `map/set<T> too long` confirms standard-library helper role. |
| `0x00438100-0x004385be` | `sub_438100`, `sub_4382B0`, `sub_438400` | tree/map copy and set construction support | Shared tree/container template support. |
| `0x004385c0-0x00439174` | `sub_4385C0` through `sub_438FE0` | iostream, locale, and string support | More Dinkumware stream-state and locale-facing helpers. |
| `0x00439180-0x00439703` | `sub_439180` through `sub_439650` | locale and formatting support | Includes the `bad locale name` path; compiler/runtime source, not product code. |
| `0x00439710-0x00439df9` | `sub_439710` through `sub_439CF0` | exception/string helper tail | Exception-message and small runtime helper fragments before the project-code boundary. |

No checked subrange has product state, NexusTK protocol semantics, GUI ownership, resource ownership, or a unique project source owner. The right documentation granularity is the current island plus family notes, not source-bearing per-helper docs.

## Standard-Library Diagnostic Strings

Current local PE string checks support the existing live IDA string-xref evidence:

| String | Address | Target refs observed locally | Outside refs observed locally | Conclusion |
| --- | --- | --- | --- | --- |
| `ios_base::badbit set` | `0x0060e264` | `0x4365f1`, `0x4368e2`, `0x43703d`, `0x438836`, `0x438c98` | later support refs including `0x43a952`, `0x43abe5`, `0x43e7d2`, `0x43e814`, `0x43ee60`, `0x43f595`, `0x4417a1`, `0x4421dd` | Dinkumware stream-state support shared across runtime islands. |
| `ios_base::failbit set` | `0x0060e27c` | `0x4365fa`, `0x4368eb`, `0x437046`, `0x43883f`, `0x438ca1` | later support refs including `0x43a95b`, `0x43abee`, `0x43e7dc`, `0x43e81e`, `0x43ee6a`, `0x43f59f`, `0x4417ab`, `0x4421e7` | Same iostream failure family as above. |
| `ios_base::eofbit set` | `0x0060e294` | `0x4365ff`, `0x4368f0`, `0x43704b`, `0x438844`, `0x438ca6` | later support refs including `0x43a960`, `0x43abf3`, `0x43e7e1`, `0x43e823`, `0x43ee6f`, `0x43f5a4`, `0x4417b0`, `0x4421ec` | Same iostream failure family as above. |
| `map/set<T> too long` | `0x0060f15c` | `0x437f94`, `0x4380eb` | `0x4532db`, `0x523f44`, `0x525114`, `0x57913b`, `0x5c0c8b` | Dinkumware container growth guard used beyond this island. |
| `bad locale name` | `0x0060e194` | `0x4396e9` | none found in the local string-ref pass | Locale exception helper inside the island. |

The diagnostics are standard-library/vendor diagnostics. They are strong evidence against a NexusTK source-owner assignment and against treating the island as JsonCpp implementation source.

## Caller Spread And Liveness

The target is live shared support code, not dead code. Existing live IDA evidence reports 371 external code references into function starts in the island.

Current local opcode-limited call/jump scanning found 383 external likely call/jump refs into the target range. The small difference from IDA's 371 count is expected because a raw scan can classify instructions differently from IDA's function/xref model. The result still supports the same conclusion: broad shared support rather than one source file.

Representative caller spread from the local scan:

| Caller range | Local likely refs | Examples | Interpretation |
| --- | ---: | --- | --- |
| JsonCpp value/core/exceptions `0x00424600-0x00428b4b` | 99 | `0x424aff->0x439460`, `0x4250eb->0x436260`, `0x425a97->0x436630` | JsonCpp value and exception paths instantiate or call STL helpers. |
| JsonCpp path/iterator area `0x00428b4b-0x004298f0` | 13 | `0x428bfb->0x439460`, `0x428dde->0x437710` | JsonCpp path/iterator code consumes shared string/container support. |
| JsonCpp parse front ends `0x004298f0-0x0042acdf` | 2 | `0x429e13->0x438ae0`, `0x42a504->0x437290` | Parser/front-end spillover into iostream/string support. |
| JsonCpp reader/builder islands `0x0042acdf-0x0042e850` | 18 | `0x42b0da->0x439460`, `0x42b70d->0x436630`, `0x42c53b->0x438fe0` | More JsonCpp consumer evidence, not ownership evidence. |
| JsonCpp writer/builder/legacy writer `0x0042e850-0x00431d50` | 57 | `0x42e9e5->0x4369c0`, `0x43071e->0x436340`, `0x430734->0x4385c0` | Writer/output routines call iostream and string helpers. |
| JsonCpp OurReader/error/unicode/writer tail `0x00431d50-0x004361b0` | 36 | `0x432564->0x437290`, `0x435500->0x436340`, `0x4357f8->0x436630` | Immediate predecessor JsonCpp code calls into the support island. |
| Later MSVC numeric/string support `0x00439ee0-0x00443a60` | 117 | `0x439f7e->0x437140`, `0x43a824->0x439650`, `0x43a97a->0x439970` | Runtime/support islands call each other. |
| LodePNG, MiniMap, and later product/runtime callers `0x00443a60-0x0060c4ac` | 41 | `0x452749->0x437710`, `0x49c8f0->0x437710`, `0x50b3a8->0x437710`, `0x5c5d1a->0x4398f0`, `0x5f7fc5->0x439bf0` | Calls extend outside JsonCpp, proving the island is shared standard-library support. |

This caller spread is the key liveness and ownership proof. JsonCpp is the heaviest visible source consumer near the island, but the helper code belongs to compiler/runtime/template support.

## Source-Owner Policy

Ranked alternatives:

1. `CANONICAL_OWNER:NONE` with `RECONSTRUCTABLE:FALSE` - accepted. The target is a runtime/compiler-template support island, not a project source unit. The target should be documented and ignored for NexusTK source reconstruction.
2. `client_libraries` meta/procurement context - useful cross-reference only. [UID:0001QE] is the right place to explain that the rebuild must choose a compatible MSVC-era CRT/STL/Dinkumware model, but it should not be a canonical emitter for this by-memory page.
3. [UID:0000KI] `JsonCpp` owner - rejected. JsonCpp source calls many helpers in the island, but the diagnostic strings, broad runtime caller spread, and standard-library helper shapes prove the range is not JsonCpp-authored source. Prior B002 executed research also rejected pure Dinkumware/MSVC STL runtime ranges as JsonCpp source.
4. [UID:0000XA] `Deque` or adjacent project owner - rejected. `DequeDestroy` begins only after seven bytes of `0xcc` padding at `0x00439e00`. The preceding runtime island has no Deque-specific state.
5. Product modules such as MiniMap/LodePNG-facing callers - rejected. Later product and library callers use shared helpers, but no later caller owns the helper source.
6. Per-family source splits - rejected for current reconstruction. Splitting would produce more non-emitting runtime helper pages without improving the source tree. Keep family detail in this page unless a later audit finds a product-authored helper inside the island; current evidence does not.

## Exact No-Code Proof

This target should not receive first-draft C++ because:

- The range is filled with standard-library/vendor helper families: iostream state/sentry handling, locale exception handling, `std::string` helpers, `std::map`/`std::set` guards, tree/copy helpers, and exception/string support.
- Standard diagnostics inside the range are compiler/runtime strings: `ios_base::badbit set`, `ios_base::failbit set`, `ios_base::eofbit set`, `map/set<T> too long`, and `bad locale name`.
- The island has broad shared caller spread from JsonCpp, later MSVC support islands, and product/library code. It is not scoped to one NexusTK class, file, protocol path, GUI method, or source-authored helper.
- The source-level rebuild action is at caller sites: use `std::string`, `std::map`, `std::set`, streams, exceptions, and the staged JsonCpp source normally. Equivalent helper code should be emitted by the selected compiler/runtime and template instantiation model.
- Hand-porting decompiler output would create non-source library implementation code and would risk pinning the project to raw compiler helper shapes instead of source-facing semantics.

Formal `RECONSTRUCTION_CPP` should therefore remain blank. No no-op stub, wrapper, or pseudo-C++ should be emitted for this target.

## Open Questions And Resolutions

- Exact island boundaries: resolved. Local byte/disassembly checks confirm `0x004361ae-0x004361b0` start padding, target start at `0x004361b0`, final target bytes through `0x00439df9`, and `0x00439df9-0x00439e00` padding before `DequeDestroy`.
- Function-family classification: resolved enough for source routing. Existing live IDA reports 63 functions and the target's family table remains consistent with current string/caller evidence.
- JsonCpp ownership: rejected. JsonCpp is a major consumer, not the helper source owner.
- Runtime caller spread: resolved. Existing IDA 371 external xrefs plus local 383 likely external call/jump refs show shared helper liveness across JsonCpp, later support islands, and product/library users.
- Standard-library diagnostics: resolved. Local string address/ref checks confirm Dinkumware/MSVC-style diagnostics inside this range and nearby runtime support.
- Exact Dinkumware decorated names/version: not safely recoverable in this pass. This does not block implementation because exact per-helper decorated names are not needed for source emission. Keep raw `sub_` names in by-memory evidence unless IDA type work later recovers reliable vendor symbols.
- Score cap: keep below 90 completion. The no-code/source-routing decision is strong, but the page still does not enumerate all 63 function starts with exact vendor names, and current-session live IDA MCP was unavailable.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Rationale:

- Raise completion from 84 to 87 because this pass adds an explicit current source-routing decision, local boundary proof, diagnostic-string table, caller-spread grouping, owner-alternative ranking, and exact no-code proof.
- Raise confidence from 90 to 92 because current local PE evidence independently confirms the existing live IDA boundary/string/caller classification.
- Cap completion below 90 because exact Dinkumware version/decorated names and full 63-function per-helper naming remain intentionally unresolved and unnecessary for source rebuild.

## Recommended Target Doc Changes

Implement these changes in `by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md` if accepted:

- Update metadata to `COMPLETION:87` and `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
- Add a short "B005 Source-Routing Recheck" or expand `Evidence` with:
  - local PE recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`;
  - `.text`, `.rdata`, `.data`, and `.rsrc` section ranges if the target doc wants reproducibility;
  - exact start/end padding: `0x004361ae-0x004361b0` is `cc cc`, `0x00439df9-0x00439e00` is seven `0xcc` bytes;
  - first instruction bytes at `0x004361b0` and final tail ending at `0x00439df9`;
  - diagnostic strings with addresses and in-target refs listed in this report;
  - caller-spread summary: IDA 371 external refs, local opcode-limited scan 383 likely external refs, spanning JsonCpp, later runtime support, and later product/library code.
- Add a "Source-owner policy" paragraph:
  - `JsonCpp` is a heavy consumer, not the owner.
  - `client_libraries` is procurement/context, not an emitter.
  - `Deque`, MiniMap, LodePNG/product callers, and per-family split ownership are rejected.
- Add an exact no-code proof and state that the rebuild should use source-level `std::`/JsonCpp code and the selected MSVC-era toolchain/runtime, not hand-ported decompiler C++.
- Preserve the existing helper-family table, but clarify that the families are documentation groups with a shared non-emitting runtime/compiler-template disposition.

## Recommended Support-Doc Changes

Support docs to update if accepted:

- `by-memory/-ignored.md`: add the B005 current recheck detail to the existing `0x004361b0-0x00439df9` ignored entry. Include the exact padding boundaries, diagnostic strings, broad caller spread, and procurement rule: regenerate through compatible MSVC-era CRT/STL/Dinkumware and source-level `std::` use.
- `by-meta/client_libraries.md`: enrich the MSVC CRT/STL/Dinkumware row to say that `0001ZT` is JsonCpp-heavy but not JsonCpp-authored, and that static standard-library helpers are not source emitters. The rebuild requirement is compatible compiler/runtime selection, not handwritten helper source.
- `by-file/JsonCpp.md`: optional one-sentence reinforcement that [UID:0001ZT] remains a compiler/runtime support island despite many JsonCpp calls. The current doc already mostly says this, so this is only needed if implementation wants the new B005 evidence mirrored there.
- `by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md`: no required change. Optional cross-reference that `ios_base::*bit set` diagnostics also occur across the later Dinkumware support island.
- No required changes to [UID:0001ZS], [UID:0000XA], or [UID:0001ZU]; their boundary descriptions already align with this report.

Do not edit `by-memory/-coverage-report.md` directly under this B-agent task.

## Exact Pending Coverage Replacement Row

If the supervisor accepts the score/metadata recommendation, replace only the [UID:0001ZT] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md) 0x004361b0-0x00439df9 | runtime/compiler support | MsvcStlIostreamTemplateSupport : ignored : 87% : very strong : B005 source-routing recheck keeps this as non-reconstructable MSVC/Dinkumware STL, iostream, locale, exception, string, map/set, and template support, not JsonCpp or NexusTK source. Existing live IDA documents 63 modeled functions; local PE/Capstone reconfirms `0x004361ae-0x004361b0` and `0x00439df9-0x00439e00` `0xcc` padding boundaries, standard diagnostics at `0x0060e264`, `0x0060e27c`, `0x0060e294`, `0x0060f15c`, and `0x0060e194`, and broad caller spread from JsonCpp, later runtime islands, and later product/library users. Rebuild through compatible MSVC-era CRT/STL/Dinkumware and source-level `std::`/JsonCpp use; keep `CANONICAL_OWNER:NONE`, no emitter, and blank C++.
```

Nearby coverage rows for [UID:0001ZS] and [UID:0000XA] appear stale relative to their by-memory metadata, but those rows are outside this assignment unless the supervisor requests a separate coverage cleanup.

## Validation Commands Needed After Implementation

Run the scoped validator from `source-3/project-documentation` for every target/support doc touched. Expected commands if the checklist above is implemented:

> Executable block R001 was removed from this report and preserved verbatim in [0001ZT-MsvcStlIostreamTemplateSupport-source-routing-removed.md](0001ZT-MsvcStlIostreamTemplateSupport-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Only run the `JsonCpp.md` validator if that optional support edit is made. Only validate coverage if the supervisor separately applies the coverage row.

## IDA Rename, Type, And Comment Recommendations

Do not apply NexusTK-style source names to the functions in this island. Exact Dinkumware decorated names are not proven, and misleading source-like names would create owner confusion.

Recommended IDA comments or non-source labels if the team wants better navigation:

- `0x004361b0`: comment as Dinkumware `std::string`/container copy or construction support.
- `0x00436340`, `0x00436630`, `0x00436dd0`, `0x004385c0`, `0x00438ae0`: comment as iostream stream-state/failure helpers referencing `ios_base::*bit set`.
- `0x00437e40` and `0x00437fa0`: comment as Dinkumware `map/set<T> too long` growth/throw helpers.
- `0x00439180-0x00439703`: comment as locale/formatting support; `0x00439650` includes `bad locale name`.
- `0x00439710-0x00439df9`: comment as exception/string helper tail before `DequeDestroy`.
- Preserve raw `sub_` names unless reliable vendor signatures are recovered. The docs should state roles, not invent source-facing names.

Data comments:

- `0x0060e264`: `ios_base::badbit set`
- `0x0060e27c`: `ios_base::failbit set`
- `0x0060e294`: `ios_base::eofbit set`
- `0x0060f15c`: `map/set<T> too long`
- `0x0060e194`: `bad locale name`

Confidence: high for comments and range classification; medium for any exact vendor helper name beyond the string-proven roles.

## Implementation Readiness

Ready for supervisor implementation callback.

The implementation should be documentation-only and should not generate C++ for this target. No target/support by-* docs were edited during this report-only pass, and `by-memory/-coverage-report.md` was not edited.

Changed file for this pass:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0001ZT-MsvcStlIostreamTemplateSupport-source-routing.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001ZT-MsvcStlIostreamTemplateSupport-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0001ZT"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001ZT-MsvcStlIostreamTemplateSupport-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0001ZT-MsvcStlIostreamTemplateSupport-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001ZT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
