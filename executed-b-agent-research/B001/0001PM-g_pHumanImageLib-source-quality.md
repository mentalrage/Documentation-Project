** TARGET-REPORT-UID:0001PM **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001PM g_pHumanImageLib Ownership / One-Definition Research


## Finalized Report / Current Recommendation

- Current recommendation: implemented and validated. [UID:0001PM] `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md` now records the exact four-byte loader-zeroed slot at `92/94` and is non-reconstructable/non-emitting physical evidence with blank formal C++.
- Final disposition: implemented. [UID:0000R5] `by-global/g_pHumanImageLib.md` owns the sole source definition `HumanImageLib *g_pHumanImageLib = 0;` in [UID:0000JY] `NexusTK/render/HumanImageLib.cpp`; [UID:00006A] owns the complete source declaration and exact authored method children.
- Callback result: Destinations D1-D14 and claims C1PM-001 through C1PM-080 were applied claim by claim under short ordinary-file leases, every changed page passed its scoped validator, and final waited command `000000015935` refreshed the generated one-definition/source union.
- Confidence: very strong for storage bytes and PE mapping, exactly four write references, source/compiler lifetime split, direct RTTI bases, Singleton EBO, object size, member-family offsets, vtable slots, physical/semantic one-definition route, and old/new HumanImageLib separation; high for descriptive source field and helper spellings.
- Current lifecycle: the accepted B001 implementation callback is complete at the canonical research path. B001 edited and scoped-validated only D1-D14 and ran the authorized final waited refresh; B001 did not manually edit coverage/generated/tracker/IDA/supervisor/audit/validator-state/lifecycle files and did not run, probe, move, archive, or execute the report. Any later report path/count/execution/archive state remains external supervisor/validator-owned state and is neither asserted nor directed here.

## Supporting Research

- Mandatory live IDA evidence was collected from the sole active NexusTK database `9b0396a3`. Fresh `idb_list` returned one active worker; `server_health` returned `status:ok`, imagebase `0x00400000`, auto-analysis complete, Hex-Rays ready, and strings ready.
- The current executable is `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes. Read-only PE arithmetic and live MCP agree on the target's loader-zeroed value.
- Historical search terms included `UID0001PM`, `0001PM`, `0x0069b43c`, `69B43C`, `g_pHumanImageLib`, `dword_69B43C`, `HumanImageLib`, `HumanImageLibConstructor`, `HumanImageLibSingletonClearHelper`, `Singleton<HumanImageLib>`, `DRWORDER`, `XDRWORD`, and `ProtectedArray`.
- Active roots `tools/leaser/Agents/Agent-B001` through `Agent-B015` research folders had no direct UID0001PM report. Matching active items were incidental class/helper dependencies only.
- Central executed root `executed-b-agent-research/**` had 30 matching files. Direct support opened and classified:
  - `executed-b-agent-research/B005/0002TO-HumanImageLibConstructor-source-quality.md`, SHA256 `60DBB17AA20E6713DCF04963768855781C6FACA47ACFD178738D15C1E22842BC`: constructor/source-quality lead, independently rechecked and superseded where it retained blank source.
  - `executed-b-agent-research/B004/00006A-HumanImageLib-class-source-quality.md`, SHA256 `4F09E0DDDC0EE0C71B42B576E8DE35BD05C34333BEEDF2CE0C3C3F1B8172243D`: class/RTTI/source-route lead, independently rechecked and superseded where it retained a comment-only class.
  - `executed-b-agent-research/B001/00017X-HumanImageLibSingletonClearHelper-source-quality.md`, SHA256 `201D37152DD4F6D2242F1BB82E8713E4DCE55E4361DF7ABB844B9E8AA3F1F995`: direct clear-helper and zero-versus-`ff` lead; current PE arithmetic closes the old open contradiction.
  - `executed-b-agent-research/B001/0003M0-HumanImageLibScalarDeletingDestructor.md`, SHA256 `18B8275524EDD0DF353972102D1542803C61B1D251D76335FFCCB4DD296312EB`: direct wrapper/compiler-route support.
  - `executed-b-agent-research/B003/000178-00017G-00017I-00017W-00017X-00017Z-000180-0002J2-image-library-cleanup-source-quality.md`, SHA256 `0E4D809F4BD4E5E77EFA7A2846B8E97178CEBEF52E5AF4EB9C6FB61AFDE2CEC1`: adjacent singleton-cleanup family support.
- Other executed matches were incidental callers, adjacent image-library families, ProtectedArray support, or NewHumanImageLib dependencies. None was a direct UID0001PM report.
- `tools/leaser/Agents/Older-Research/**` contained three Markdown files and `tools/leaser/Agents/SpecialReports/**` contained five; neither root matched the target UID/address/name or HumanImageLib owner/source-family terms. Explicit conclusion: no prior direct UID0001PM report exists.
- Historical Wave2/Wave3 artifacts were not used as authority. Any old recovered-name or simroot claim was treated as a lead and accepted only when current bytes, xrefs, RTTI, current docs, and source routing agreed.

## Target

- Target UID: `0001PM`.
- Target path: `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md`.
- Historical source queue: before implementation, `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, carried UID0001PM at `86/90`, reconstructable true.
- Current callback classification: ordinary implementation and validation are complete; manual coverage and report lifecycle remain external supervisor-owned concerns.
- Current target hash: `E0C022E51F168BBEA2174ED83DB80F2E204ABA976B45222E837EA5C4EF1FDAB7`, 8,967 bytes, 84 lines.
- Current metadata: `92/94`, owner UID0000R5, reconstructable false, blank emitter/position/formal C++, `Nested:0`.

## Current Target State

- The page now correctly identifies the exact four-byte singleton slot, loader-zero storage, and all four lifecycle writes; the former raw-backed `ff ff ff ff` assertion is retained only as rejected history.
- Live MCP `get_bytes(0x0069b43c,16)`, `get_int`, and `get_global_value` all return zero. The exact four-byte target is `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- The executable `.data` section has RVA `0x0026d000`, virtual size `0x0002fe24`, raw pointer `0x0026ac00`, and raw size `0x0000d800`. Target RVA `0x0029b43c` is delta `0x0002e43c` into `.data`, beyond raw size but within virtual size. It has no raw file bytes and is zero-filled by the PE loader.
- Exactly four refs exist and all are writes: constructor publication `0x004d277b`, constructor adjusted-null clear `0x004d2782`, ordinary-destructor clear `0x004d4f44`, and EH/static cleanup clear `0x004e5b80`. No target read or direct consumer exists.
- The apparent publication/clear operations are the lowered direct `Singleton<HumanImageLib>` base lifetime. UID0000R5 now supplies the sole typed source definition; UID0001PM and all compiler/data support pages remain non-emitting, so no duplicate exists.
- Callback-final generated readback of `auto-generated/NexusTK/render/HumanImageLib.cpp` was validator command `000000015935`, refreshed `2026-07-21T14:52:46-04:00`, SHA256 `1C246725E3F8BF0DB173F26796C81981C9F2381E6672422099CC5A8D704B5894`, 11,404 bytes, 281 lines. It contains one UID00006A complete class, one UID0000R5 definition, one UID0002TO constructor, one UID00017B destructor, one UID0004DK head loader, and one UID0004DL weapon loader. It has zero UID0001PM/UID00017X/UID0003M0/UID0001XQ/UID00036H/UID00017A markers and zero `Empty Emitter Marker` text. Unrelated later validator header epochs are external and do not invalidate these command-15935 content assertions.
- The accepted emitter-position metadata is `10/20/30/40/50/60`. The generator's depth-first owner traversal places the UID00006A class subtree (constructor/destructor) before the separate file-owned UID0000R5 global, then emits UID0004DK/UID0004DL; this structural preorder is current validator behavior and preserves each formal position, class closure, and one-definition semantics without implying a global numeric sort across distinct owner subtrees.
- Evidence-time tracker snapshot captured during final self-review was validator-owned deferred-refresh command `000000015942`, refreshed `2026-07-21T15:07:23-04:00`, SHA256 `60A25400ACFC7FC0D90F6D64AAF1C7C4B492583A0F9721AFD2FF483177B3C7F0`, 1,548,242 bytes / 6,263 lines. Its UID0001PM row remained `92/94`, score `93.0`, reconstructable false, report count zero at that command-time snapshot; B001 did not edit it manually. Command 15935 remains the historical callback final-refresh tracker snapshot. This statement is deliberately time-bounded: unrelated later validator tracker epochs are external state and do not alter the durable D1-D14 or generated-source proof.

## Executive Recommendation

- Applied physical UID0001PM -> semantic UID0000R5 routing; the physical page is `92/94`, `CANONICAL_OWNER:0000R5`, `RECONSTRUCTABLE:FALSE`, with blank emitter/position/formal and `Nested:0`.
- Applied UID0000R5 as the sole typed definition at `92/94`, owner/emitter UID0000JY, position `20`.
- Replaced UID00006A's comment-only scaffold with the complete direct-base/member declaration at `92/93`, owner/emitter UID0000JY, position `10`.
- Applied UID0002TO at `91/92`, position `30`; UID00017B at `92/94`, position `40`; and UID0004DK/UID0004DL file-local helpers at `91/92`, positions `50/60`.
- Applied compiler/generated-binary, non-reconstructable, non-emitting, blank-formal dispositions to UID00017X, UID0003M0, UID0001XQ, and UID00036H while preserving exact bytes, xrefs, and causal source declarations.
- Synchronized UID0001UR to the complete `0x2b0` layout and source-facing late-field names without padding fields; UID00017A remains the non-emitting mixed/index container.

## Supervisor Active Recheck

- The supervisor assigned UID0001PM specifically to resolve the zero-versus-`0xffffffff` conflict, four-reference lifetime, physical/semantic ownership, one-definition route, and all associated HumanImageLib source/C++ blockers.
- No target split or new UID is required. The physical four-byte range is exact and indivisible.
- All source-bearing items in the bounded lifetime/declaration scope receive destination-ready managed blocks below. Compiler artifacts receive exact destination-specific blank blocks and no-code proof.

## Inference Research Guidance Check

- Binary fact: target bytes/value, PE virtual/raw mapping, xrefs, function boundaries, RTTI hierarchy/PMDs, vtable slots, object offsets, counts, resource strings, and compiler helper bodies.
- Documentation fact: current UIDs, source routes, existing accepted `ProtectedArray<T>` names, frame-table loader support, and generated/manual coverage state.
- Inference: project-canonical global/member/helper spellings and header grouping. Inferred names are semantic, not claimed original PDB symbols.
- Stale assumptions rejected: raw-backed `ff ff ff ff`, handwritten global publication/clear in constructor/destructor, comment-only class, generic cached-resource pointers, public singleton-clear method, handwritten scalar wrapper, duplicate physical definition, and collapse into NewHumanImageLib/ImageLib/DAT source.

## Heuristic / Inference Reanalysis And Validation

- Zero versus `0xffffffff`: direct MCP and PE section arithmetic independently prove loader zero. The old `ff` statement is false, not an alternate build interpretation.
- Four-reference lifecycle: operand search and `xrefs_to` return exactly four sites with no `more` set. All four write the slot; none reads it.
- Singleton source cause: RTTI class hierarchy contains `HumanImageLib`, `LObject`, and `Singleton<HumanImageLib>`. Singleton PMD `{mdisp=4,pdisp=-1,vdisp=0}` plus constructor `this+4`/`lea -4` publication proves direct empty-base lowering.
- EBO: the Singleton subobject conceptually begins at `+0x04` and overlaps the first `ProtectedArray<HeadInfo>` member. No explicit four-byte Singleton field or padding member belongs in source.
- Object closure: member offsets end with the eighteenth frame-table pointer at `+0x2ac`, giving exact size `0x2b0`; scalar-wrapper delete-size behavior corroborates this size.
- Late fields: `+0x240/+0x244/+0x248` are counts; `+0x24c/+0x250/+0x254` are owned draw-order table arrays, not generic cached resources. DRWORDER uses retained 4-byte rows; XDRWORD/XDRWORD2 use retained 12-byte rows with one discarded trailing input byte per 13-byte disk record.
- `+0x258/+0x25c/+0x260/+0x264` are four 16-bit frame-count values for HEAD, HEADSP, EMOTION, and EMOTIOSP validation. Natural layout is exact; no reserve member is needed.
- `+0x268..+0x2ac` are 18 old-human/equipment frame-table handles in literal load order HEAD, HEADSP, BODY, SWORD, SPEAR, BOW, FAN, SHIELD, ARROW, FACE, ACE1, HAIR, ACE2, HELMET, MANTLE, NECLACE, SHOES, COAT.
- Vtable: scalar deleting destructor `0x004e6460`, inherited `LObject::GetRuntimeClass` `0x004f4b10`, and inherited `LObject::VirtualNoop(int,int)` `0x0041b6c0`. Only the virtual destructor is declared by HumanImageLib.
- Constructor source: authored orchestration owns table reads, frame loads, validation, accessory draw flags, and hair colors. Compiler SEH/vptr/base publication is excluded.
- Destructor source: authored releases of 18 frame tables and three owned draw-order arrays remain visible. Member/template, Singleton, LObject, vptr, and scalar-delete mechanics remain implicit/compiler-generated.
- Helper source: UID0004DK and UID0004DL are constructor-only old-human table loaders, not generic VectorHelpers and not public class APIs.
- Original names: `g_pHumanImageLib` is accepted by project-wide peer singleton convention and current docs. Exact PDB spelling remains unavailable but does not prevent source-ready descriptive reconstruction.
- Rejected `Singleton<HumanImageLib>::s_instance` as an additional definition: the one observed slot and existing project external-global contract allow only one storage definition. A template-static spelling could have generated that slot historically, but adding both forms would violate one-definition behavior.
- Rejected no-code target/global: exact type, initializer, linkage, source route, owner, and generated uniqueness are resolved.
- Rejected broad constructor no-code carry-forward: the current pass closes direct bases, EBO, size, late fields, resource handles, helper signatures, source/compiler separation, and source-facing orchestration.

## Evidence Standards Used

- Direct evidence tier: live MCP `idb_list`, `server_health`, `get_bytes`, `get_int`, `get_global_value`, `lookup_funcs`, `xrefs_to`, `trace_data_flow`, `entity_query`, `disasm`, `decompile`, `callees`, string queries, and exact PE section arithmetic.
- Corroboration tier: current by-* pages, accepted executed reports opened as evidence-time leads, current generated C++, manual coverage, and tracker state.
- Negative-evidence tier: no slot reads, no constructor entry xref, no helper caller beyond EH jump, no scalar wrapper callers beyond vtable, no raw backing, no local IDA UDT, no competing owner, no direct target report, and no old/new image-library aliasing.
- The evidence is sufficient for `92/94` target closure. Original private identifiers and exact historical header basename cap class/helper confidence below 95 but do not block behavior-identical source.

## Evidence Checked

- MCP evidence-time database: `9b0396a3`; healthy analysis/Hex-Rays/string state.
- Exact slot: 16-byte read at `0x0069b43c` all zero; u32/global value zero; exact four-byte SHA256 above.
- Function anchors: constructor `0x004d2720-0x004d4aca` size `0x23aa`; destructor `0x004d4ad0-0x004d4f67` size `0x497`; clear helper `0x004e5b80-0x004e5b8b` size `0x0b`; scalar wrapper `0x004e6460-0x004e649b` size `0x3b`.
- Exact four slot refs: `0x004d277b`, `0x004d2782`, `0x004d4f44`, `0x004e5b80`; no read.
- Vtable dwords: `0x0061b6d0 -> 0x00648814`, `0x0061b6d4 -> 0x004e6460`, `0x0061b6d8 -> 0x004f4b10`, `0x0061b6dc -> 0x0041b6c0`.
- PE: `.data` RVA/virtual/raw figures and target delta above; target is virtual-only zero-fill.
- Current docs read after callback: D1-D14 plus ProtectedArray template/record pages, ImageFrameTable loader, EPF resources, DAT archive, Application startup/shutdown context, and old/new sibling singleton pages.
- Historical roots and exact direct reports are listed under Supporting Research.
- Current generated, tracker, and six applicable manual coverage files were read only after callback validation; generated remained command 15935 while unrelated deferred refreshes advanced the evidence-time tracker snapshot through command 15942 without changing the UID0001PM disposition.
- One initial local PowerShell wrapper used the reserved `$args` parameter name and produced malformed `database required` requests; valid schema-correct calls immediately succeeded. This was a client request-shape limitation, not MCP unavailability, and no evidence conclusion relies on the malformed calls.
- During the initial report-only evidence pass, ordinary edits, validators, and generated refresh were intentionally not performed. During the accepted implementation callback, D1-D14 ordinary edits, short leases, scoped validators, and the final generated refresh were performed as enumerated below. IDA mutation, manual coverage edits, direct generated/tracker edits, report lifecycle commands, report execution, movement, and archival remained unperformed by B001.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1PM-001 | Target range is exactly `[0x0069b43c,0x0069b440)`. | very high | MCP bytes; adjacent storage; PE mapping | D1 | incorporate | applied |
| C1PM-002 | Exact target bytes are four zero bytes with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. | very high | `get_bytes`, `get_int`, `get_global_value` | D1 | incorporate | applied |
| C1PM-003 | Target has no raw backing and is PE loader zero-fill. | very high | section arithmetic | D1 | incorporate | applied |
| C1PM-004 | Historical `ff ff ff ff` is false and must be historicalized. | very high | C1PM-002/003 | D1/D2 | reject-stale | applied |
| C1PM-005 | Exactly four target refs exist. | very high | `xrefs_to`, operand search | D1/D2 | incorporate | applied |
| C1PM-006 | Constructor publishes at `0x004d277b`. | very high | trace/disasm | D1/D2/D5 | incorporate | applied |
| C1PM-007 | Constructor adjusted-null path clears at `0x004d2782`. | very high | trace/disasm | D1/D2/D5 | incorporate | applied |
| C1PM-008 | Ordinary destruction clears at `0x004d4f44`. | very high | trace/disasm | D1/D2/D6 | incorporate | applied |
| C1PM-009 | EH/static cleanup helper clears at `0x004e5b80`. | very high | helper bytes/xref | D1/D2/D7 | incorporate | applied |
| C1PM-010 | No direct target read or consumer exists. | high | exhaustive four-ref set | D1/D2 | incorporate | applied |
| C1PM-011 | Target type is `HumanImageLib *`. | very high | ctor object/vtable/RTTI | D1/D2/D3 | incorporate | applied |
| C1PM-012 | Project source-facing name is `g_pHumanImageLib`. | high | current convention/docs/peers | D1/D2/D3 | incorporate | applied |
| C1PM-013 | UID0000R5 owns the sole external definition. | very high | one slot/source route | D1/D2/D4 | incorporate | applied |
| C1PM-014 | UID0001PM is physical evidence, not a second definition. | very high | one-definition analysis | D1 | incorporate | applied |
| C1PM-015 | UID0001PM becomes false/non-emitting with blank formal. | very high | duplicate prevention | D1 | incorporate | applied |
| C1PM-016 | UID0000R5 emits one zero initializer. | very high | PE zero/source contract | D2 | incorporate | applied |
| C1PM-017 | HumanImageLib directly derives from LObject. | very high | RTTI hierarchy/primary vptr | D3/D5/D6 | incorporate | applied |
| C1PM-018 | HumanImageLib directly derives from `Singleton<HumanImageLib>`. | very high | RTTI BCD/ctor lowering | D3/D5/D6 | incorporate | applied |
| C1PM-019 | Singleton PMD is `{4,-1,0}`. | very high | RTTI bytes | D1/D2/D3 | incorporate | applied |
| C1PM-020 | Singleton EBO overlaps first member at `+0x04`. | very high | ctor stores/layout | D3/D9 | incorporate | applied |
| C1PM-021 | No explicit Singleton storage/padding field belongs in source. | very high | EBO | D3/D9 | reject-invalid | applied |
| C1PM-022 | Complete object size is `0x2b0`. | very high | layout tail/wrapper | D3/D9 | incorporate | applied |
| C1PM-023 | Eighteen ProtectedArray members occupy `+0x004..+0x23f`. | very high | ctor vptrs/strides | D3/D9 | incorporate | applied |
| C1PM-024 | Six WeaponInfo arrays map sword/spear/bow/fan/shield/arrow in address order. | very high | helper calls/literals | D3/D5/D9 | incorporate | applied |
| C1PM-025 | HeadInfo record size is `0x0c`; WeaponInfo is `0x10`. | very high | template object sizes/helpers | D3/D12/D13 | incorporate | applied |
| C1PM-026 | Other record sizes follow exact ProtectedArray strides. | high | ctor/vtables/accessors | D3/D9 | incorporate | applied |
| C1PM-027 | `+0x240/+0x244/+0x248` are three draw-order counts. | very high | ctor file-size/division loops | D3/D5/D9 | incorporate | applied |
| C1PM-028 | `+0x24c/+0x250/+0x254` are three owned draw-order arrays. | very high | ctor alloc/read; dtor frees | D3/D5/D6/D9 | incorporate | applied |
| C1PM-029 | DRWORDER retains 4-byte rows. | very high | 5-byte disk loop | D3/D5 | incorporate | applied |
| C1PM-030 | XDRWORD and XDRWORD2 retain 12-byte rows from 13-byte disk records. | very high | ctor division/read loop | D3/D5 | incorporate | applied |
| C1PM-031 | `+0x258..+0x264` are four 16-bit validation counts. | high | disasm/resource lookup | D3/D5/D9 | incorporate | applied |
| C1PM-032 | No explicit alignment member is needed around those shorts. | very high | natural exact layout | D3/D9 | reject-invalid | applied |
| C1PM-033 | Eighteen frame-table pointers occupy `+0x268..+0x2ac`. | very high | ctor loads/dtor release | D3/D5/D6/D9 | incorporate | applied |
| C1PM-034 | Exact frame-family order is HEAD through COAT as listed. | very high | literals/calls/offsets | D3/D5/D6/D9 | incorporate | applied |
| C1PM-035 | NECLACE and EMOTIOSP spellings are binary literals. | very high | string reads | D3/D5 | incorporate | applied |
| C1PM-036 | Constructor range/size is exact. | very high | lookup/disasm | D5 | incorporate | applied |
| C1PM-037 | Constructor has no direct entry xref but is live static/startup lifetime code. | high | negative xref plus lifecycle | D5/D4 | incorporate | applied |
| C1PM-038 | Constructor's publish/null/vptr/SEH work is compiler/base lowering. | very high | RTTI/source-shape | D5 | historicalize | applied |
| C1PM-039 | Constructor authored source owns table/resource orchestration. | very high | 238-block body/callees | D5 | incorporate | applied |
| C1PM-040 | Constructor becomes source-ready at `91/92`. | high | blockers closed here | D5 | incorporate | applied |
| C1PM-041 | Destructor range/size is exact. | very high | lookup/disasm | D6 | incorporate | applied |
| C1PM-042 | Destructor explicitly releases 18 frame tables and three draw-order arrays. | very high | disasm/callees | D6 | incorporate | applied |
| C1PM-043 | ProtectedArray, Singleton, LObject, and vptr teardown remain implicit/compiler-generated. | very high | reverse destruction order | D6 | incorporate | applied |
| C1PM-044 | Destructor must not explicitly clear the global. | very high | Singleton base lowering | D6 | reject-stale | applied |
| C1PM-045 | Destructor becomes source-ready at `92/94`. | very high | exact cleanup/source split | D6 | incorporate | applied |
| C1PM-046 | UID00017X exact body is `mov [slot],0; ret`. | very high | bytes/disasm | D7 | incorporate | applied |
| C1PM-047 | UID00017X is EH-only Singleton base cleanup, not authored API. | very high | sole cleanup jump/no callees | D7 | incorporate | applied |
| C1PM-048 | UID00017X becomes false/non-emitting/blank. | very high | source cause D3 | D7 | incorporate | applied |
| C1PM-049 | UID0003M0 is vtable-only compiler scalar wrapper. | very high | vtable/callees/flags | D8 | incorporate | applied |
| C1PM-050 | UID0003M0 becomes false/non-emitting/blank. | very high | source virtual destructor cause | D8 | incorporate | applied |
| C1PM-051 | HumanImageLib vtable has three slots. | very high | four dword reads | D10/D11 | incorporate | applied |
| C1PM-052 | Slot zero is scalar deleting destructor `0x004e6460`. | very high | vtable dword | D10/D11 | incorporate | applied |
| C1PM-053 | Slots one/two are inherited LObject runtime/noop methods. | high | decompile/sibling docs | D3/D10/D11 | incorporate | applied |
| C1PM-054 | Vtable/RTTI data are generated and non-emitting. | very high | compiler artifact | D10/D11 | incorporate | applied |
| C1PM-055 | UID0004DK is the exact three-argument 12-byte HeadInfo loader: existing DATFile stream, narrow source name, `-1/-1/-255` fallback, positive-count resize, and three encoded integers per row. | very high | range/two callers/decompile/disasm | D12 | incorporate | applied |
| C1PM-056 | UID0004DL is the exact three-argument 16-byte WeaponInfo loader: existing DATFile stream, narrow source name, `-1/-1/0` three-field fallback with the fourth fallback field untouched, positive-count resize, four encoded integers per row, and 16-bit-half-swapped fourth value. | very high | range/six callers/decompile/disasm | D13 | incorporate | applied |
| C1PM-057 | Both helpers are file-local HumanImageLib source, not VectorHelpers. | very high | exclusive ctor callers | D12/D13/D4 | incorporate | applied |
| C1PM-058 | Both helpers latch shared image load error on failed reads. | very high | disasm/global refs | D12/D13 | incorporate | applied |
| C1PM-059 | Helper names are descriptive but source-quality. | high | exact roles/no symbols | D12/D13 | incorporate | applied |
| C1PM-060 | UID00017A remains non-emitting split/index. | very high | mixed child neighborhood | D14 | already-present | already-present |
| C1PM-061 | No target split/new UID/padding change is needed. | very high | exact four-byte slot | D1 | not-applicable | excluded-with-reason |
| C1PM-062 | HumanImageLib remains separate from NewHumanImageLib. | very high | storage/resources/RTTI | D3/D4 | incorporate | applied |
| C1PM-063 | HumanImageLib remains separate from ImageLib/EPF loader ownership. | very high | class-specific arrays/consumers | D4 | incorporate | applied |
| C1PM-064 | DATFile/ImageFrameTable/ProtectedArray are dependencies, not owners. | very high | call/source boundaries | D4 | incorporate | applied |
| C1PM-065 | Target score becomes `92/94`. | very high | exhaustive closure | D1 | incorporate | applied |
| C1PM-066 | Semantic global score becomes `92/94`. | very high | type/definition/lifetime closure | D2 | incorporate | applied |
| C1PM-067 | Class score becomes `92/93`. | high | complete declaration, inferred names cap | D3 | incorporate | applied |
| C1PM-068 | File score becomes `91/92`. | high | complete bounded source union | D4 | incorporate | applied |
| C1PM-069 | Layout score becomes `92/93`. | high | exact `0x2b0` closure | D9 | incorporate | applied |
| C1PM-070 | Vtable score becomes `92/94` but remains non-emitting. | very high | exact slots/source cause | D10 | incorporate | applied |
| C1PM-071 | Historical generated baseline command 15860 lacked class/global/method definitions; command 15935 supersedes that blank state. | very high | command 15860 and 15935 readbacks | report validator plan | historicalize | already-present |
| C1PM-072 | Final generation must contain one global definition. | very high | one-definition plan | generated assertion | incorporate | applied |
| C1PM-073 | Final generation must contain one complete class declaration. | very high | D3 | generated assertion | incorporate | applied |
| C1PM-074 | Final generation must contain constructor/destructor/helpers once. | very high | D5/D6/D12/D13 | generated assertion | incorporate | applied |
| C1PM-075 | Final generation must contain no physical/helper/wrapper/vtable duplicate. | very high | non-emitting dispositions | generated assertion | incorporate | applied |
| C1PM-076 | Manual coverage rows listed below require exact supervisor replacement. | very high | current row comparison | coverage handoff | incorporate | excluded-with-reason |
| C1PM-077 | Current tracker row is validator-owned and not manually edited. | very high | tracker policy | report only | not-applicable | excluded-with-reason |
| C1PM-078 | Executed reports are evidence-time leads, not current authority. | very high | workflow/current docs | report history | historicalize | already-present |
| C1PM-079 | Older-Research/SpecialReports contain no target coverage. | very high | explicit root search | report history | already-present | already-present |
| C1PM-080 | B001 performs no implementation/lifecycle action before Gate 1. | very high | assignment boundary | report/checklist | incorporate | applied |

### Callback Verification Notes

| Claim ID | Terminal state | Destination-specific proof |
| --- | --- | --- |
| C1PM-001 | applied | D1 records exact `[0x0069b43c,0x0069b440)` and passed scoped command `000000015903`; current D1 SHA is `E0C022E51F168BBEA2174ED83DB80F2E204ABA976B45222E837EA5C4EF1FDAB7`. |
| C1PM-002 | applied | D1 contains `00 00 00 00` and full byte SHA `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; command 15903 passed. |
| C1PM-003 | applied | D1's PE section arithmetic explicitly proves virtual-only loader zero-fill and no raw backing; command 15903 passed. |
| C1PM-004 | applied | D1 and D2 place `ff ff ff ff` only in Historical / Superseded Assumptions with the zero-fill rejection reason; commands 15903/15906 passed. |
| C1PM-005 | applied | D1/D2 contain the bounded four-site inventory and no-more/no-read result; commands 15903/15906 passed. |
| C1PM-006 | applied | D1/D2/D5 identify constructor publication at `0x004d277b`; validators 15903/15906/15915 passed. |
| C1PM-007 | applied | D1/D2/D5 identify adjusted-null clear at `0x004d2782`; validators 15903/15906/15915 passed. |
| C1PM-008 | applied | D1/D2/D6 identify ordinary-destruction clear at `0x004d4f44`; validators 15903/15906/15918 passed. |
| C1PM-009 | applied | D1/D2/D7 identify the EH/static cleanup clear at `0x004e5b80`; validators 15903/15906/15919 passed. |
| C1PM-010 | applied | D1/D2 explicitly record four writes, zero reads, and no direct consumer; validators 15903/15906 passed. |
| C1PM-011 | applied | D1/D2/D3 synchronize the `HumanImageLib *` type; D2's formal defines that exact pointer and D3 declares the class. |
| C1PM-012 | applied | D1/D2/D3 use `g_pHumanImageLib` as the project-canonical descriptive spelling and preserve the original-symbol confidence cap. |
| C1PM-013 | applied | D2 is `92/94`, owner/emitter UID0000JY, position 20, and carries the sole definition; command 15906 passed. |
| C1PM-014 | applied | D1 is physical evidence routed to UID0000R5, false/non-emitting, with no definition; command 15903 passed. |
| C1PM-015 | applied | D1 header is `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, `Nested:0`; command 15903 passed. |
| C1PM-016 | applied | D2 formal contains exactly `HumanImageLib *g_pHumanImageLib = 0;`; final generated command 15935 contains that definition once. |
| C1PM-017 | applied | D3 complete formal directly derives from `LObject`; D5/D6 source and compiler notes agree; commands 15910/15915/15918 passed. |
| C1PM-018 | applied | D3 complete formal directly derives from `Singleton<HumanImageLib>`; D5/D6 document generated base lifetime; commands 15910/15915/15918 passed. |
| C1PM-019 | applied | D1/D2/D3 retain exact Singleton PMD `{4,-1,0}` and its publication meaning; validators 15903/15906/15910 passed. |
| C1PM-020 | applied | D3/D9 document EBO at `+0x04` overlapping the first `ProtectedArray`; validators 15910/15923 passed. |
| C1PM-021 | applied | D3/D9 explicitly reject an authored Singleton storage or padding member; their accepted formals contain neither. |
| C1PM-022 | applied | D3/D9 state and structurally enumerate exact `sizeof(HumanImageLib)==0x2b0`; validators 15910/15923 passed. |
| C1PM-023 | applied | D3/D9 preserve all eighteen `ProtectedArray` members across `+0x004..+0x23f`; validators 15910/15923 passed. |
| C1PM-024 | applied | D3/D5/D9 map sword/spear/bow/fan/shield/arrow arrays in address order; validators 15910/15915/15923 passed. |
| C1PM-025 | applied | D3/D12/D13 specify 12-byte `HeadInfo` and 16-byte `WeaponInfo`; exact helper formals passed commands 15926/15928. |
| C1PM-026 | applied | D3/D9 retain the remaining record families and exact ProtectedArray strides without fabricated padding; validators 15910/15923 passed. |
| C1PM-027 | applied | D3/D5/D9 name the three `+0x240/+0x244/+0x248` draw-order counts; validators 15910/15915/15923 passed. |
| C1PM-028 | applied | D3/D5/D6/D9 name the three `+0x24c/+0x250/+0x254` owned arrays and pair constructor allocation with destructor deletion. |
| C1PM-029 | applied | D3/D5 retain DRWORDER's four-byte retained rows and five-byte disk-record behavior; commands 15910/15915 passed. |
| C1PM-030 | applied | D3/D5 retain XDRWORD/XDRWORD2 twelve-byte rows from thirteen-byte disk records; commands 15910/15915 passed. |
| C1PM-031 | applied | D3/D5/D9 identify four 16-bit validation counts at `+0x258..+0x264`; validators 15910/15915/15923 passed. |
| C1PM-032 | applied | D3/D9 use natural layout and contain no explicit alignment member around the four shorts; validators 15910/15923 passed. |
| C1PM-033 | applied | D3/D5/D6/D9 enumerate eighteen frame-table pointers through `+0x2ac`; validators 15910/15915/15918/15923 passed. |
| C1PM-034 | applied | D3/D5/D6/D9 preserve literal HEAD-through-COAT frame-family order; the constructor/destructor generated bodies agree once each. |
| C1PM-035 | applied | D3/D5 preserve binary spellings `NECLACE` and `EMOTIOSP`; command 15915 generated them without correction. |
| C1PM-036 | applied | D5 records exact constructor range `0x004d2720-0x004d4aca` and size `0x23aa`; command 15915 passed. |
| C1PM-037 | applied | D5/D4 retain zero direct entry xrefs and static/startup lifetime classification without calling the body dead; commands 15915/15912 passed. |
| C1PM-038 | applied | D5 places publish/null/vptr/SEH operations under compiler/base lowering and excludes them from the formal body; command 15915 passed. |
| C1PM-039 | applied | D5 formal contains the table/resource orchestration and preserves 238-block/callee/resource evidence; command 15915 passed. |
| C1PM-040 | applied | D5 is current `91/92`, reconstructable, owner/emitter UID00006A, position 30, with complete formal source; command 15915 passed. |
| C1PM-041 | applied | D6 records exact destructor range `0x004d4ad0-0x004d4f67` and size `0x497`; command 15918 passed. |
| C1PM-042 | applied | D6 formal has eighteen `ReleaseImageFrameTable` calls and three `delete[]` statements; final generation contains that body once. |
| C1PM-043 | applied | D6 excludes ProtectedArray, Singleton, LObject, and vptr teardown as implicit compiler/member work; command 15918 passed. |
| C1PM-044 | applied | D6 formal has no direct global clear and its current prose rejects one; command 15918 passed. |
| C1PM-045 | applied | D6 is current `92/94`, reconstructable, owner/emitter UID00006A, position 40; command 15918 passed. |
| C1PM-046 | applied | D7 preserves exact `mov [0x0069b43c],0; ret` bytes/disassembly in evidence while formal C++ stays blank; command 15919 passed. |
| C1PM-047 | applied | D7 current disposition identifies the sole cleanup jump and direct Singleton EH cause, not an authored API; command 15919 passed. |
| C1PM-048 | applied | D7 is `91/94`, owner NONE, false/non-emitting, blank emitter/position/formal; command 15919 passed. |
| C1PM-049 | applied | D8 documents vtable-only scalar-wrapper flags/callees and generated source cause; command 15921 passed. |
| C1PM-050 | applied | D8 is `91/94`, owner NONE, false/non-emitting, blank emitter/position/formal; command 15921 passed. |
| C1PM-051 | applied | D10/D11 enumerate exactly three function slots plus RTTI locator; commands 15924/15925 passed. |
| C1PM-052 | applied | D10/D11 identify slot zero as scalar deleting destructor `0x004e6460`; commands 15924/15925 passed. |
| C1PM-053 | applied | D3/D10/D11 identify slots one/two as inherited `LObject::GetRuntimeClass` and `LObject::VirtualNoop(int,int)`; validators passed. |
| C1PM-054 | applied | D10/D11 are `92/94`, owner NONE, false/non-emitting, blank formals, and document complete-class compiler generation; commands 15924/15925 passed. |
| C1PM-055 | applied | D12 exact formal and prose implement the two-call, three-argument 12-byte HeadInfo loader with `-1/-1/-255`, positive resize, and three reads; command 15926 passed. |
| C1PM-056 | applied | D13 exact formal and prose implement the six-call, three-argument 16-byte WeaponInfo loader, three-field fallback, four reads, and halfword swap; command 15928 passed. |
| C1PM-057 | applied | D4/D12/D13 route both helpers file-locally through UID0000JY and explicitly reject VectorHelpers; commands 15912/15926/15928 passed. |
| C1PM-058 | applied | D12/D13 formal bodies latch `g_imageLibraryLoadErrorFlag` on every failed count/field read; commands 15926/15928 passed. |
| C1PM-059 | applied | D12/D13 use `LoadHumanHeadInfoTable`/`LoadHumanWeaponInfoTable` and label the spellings descriptive rather than PDB-proven. |
| C1PM-060 | already-present | D14 retained `85/90`, owner NONE, false/non-emitting, blank route/formal and was synchronized as a mixed index; command 15933 passed. |
| C1PM-061 | excluded-with-reason | D1's indivisible four-byte slot required no split/new UID/padding change; no child or ignored-span file was created or edited. |
| C1PM-062 | applied | D3/D4 preserve HumanImageLib as separate from NewHumanImageLib by storage, RTTI, resources, source route, and sibling exclusions. |
| C1PM-063 | applied | D4 explicitly separates HumanImageLib ownership from ImageLib/EPF loader ownership; command 15912 passed. |
| C1PM-064 | applied | D4 classifies DATFile, ImageFrameTable, and ProtectedArray as dependencies/templates rather than source owners; command 15912 passed. |
| C1PM-065 | applied | D1 header/readback is `92/94`; command 15903 recorded both completion and confidence updates. |
| C1PM-066 | applied | D2 header/readback is `92/94`; command 15906 recorded the accepted metadata and formal route. |
| C1PM-067 | applied | D3 header/readback is `92/93`; command 15910 validated the complete declaration and retained inference cap. |
| C1PM-068 | applied | D4 header/readback is `91/92`; command 15912 validated the complete bounded source union. |
| C1PM-069 | applied | D9 header/readback is `92/93`; command 15923 validated exact `0x2b0` layout support. |
| C1PM-070 | applied | D10 header/readback is `92/94` and false/non-emitting; command 15924 passed. |
| C1PM-071 | already-present | Command 15860's blank generated baseline remains explicitly historical; final command 15935 supersedes it with the complete source union. |
| C1PM-072 | applied | Generated command 15935 contains exactly one `HumanImageLib *g_pHumanImageLib = 0;` and one UID0000R5 marker. |
| C1PM-073 | applied | Generated command 15935 contains exactly one UID00006A marker and one complete `class HumanImageLib :` declaration. |
| C1PM-074 | applied | Generated command 15935 contains UID0002TO/UID00017B/UID0004DK/UID0004DL once each and one constructor/destructor/helper definition each. |
| C1PM-075 | applied | Generated command 15935 contains zero UID0001PM/UID00017X/UID0003M0/UID0001XQ/UID00036H/UID00017A markers and zero empty-emitter text. |
| C1PM-076 | excluded-with-reason | B001 did not edit manual coverage; the current rows remain stale/absent and the exact no-loss supervisor replacements/additions remain verbatim below. |
| C1PM-077 | excluded-with-reason | B001 did not edit tracker state; evidence-time validator command 15942 records UID0001PM `92/94`, score 93.0, false, unchanged from callback command 15935. |
| C1PM-078 | already-present | Supporting Research keeps every executed-report hash as evidence-time lead and makes current ordinary/generated artifacts authoritative. |
| C1PM-079 | already-present | Supporting Research records explicit Older-Research/SpecialReports roots and the no-direct-target conclusion; no callback mutation was required. |
| C1PM-080 | applied | The initial phase performed research/report work only; the accepted callback performed ordinary edits/validation but no B001 lifecycle/execute/move/archive action. |

## Positive Evidence Summary

- Direct target evidence is unusually strong: exact zero value from three MCP routes plus independent PE virtual/raw arithmetic.
- The four-reference set is complete and semantically coherent with direct Singleton base construction/destruction.
- RTTI, vtable, constructor/destructor stores, helper xrefs, and scalar-wrapper behavior converge on one HumanImageLib lifetime model.
- The full late layout is closed through `0x2b0`, including concrete draw-order arrays, count widths, and all eighteen frame resources.
- Peer project singleton repairs independently support the typed by-global sole-definition plus false/non-emitting physical-slot pattern.

## IDA MCP Facts

- Database: `9b0396a3`; worker healthy and analysis-ready at evidence time.
- Target bytes/value: zero; target is data, not a function.
- Constructor: `sub_4D2720`, size `0x23aa`, 238 basic blocks, complexity 86.
- Destructor: `sub_4D4AD0`, size `0x497`; one scalar-wrapper caller.
- Clear helper: `sub_4E5B80`, size `0x0b`; one EH cleanup jump at `0x005ffaf2`; no callees.
- Scalar wrapper: `sub_4E6460`, size `0x3b`; vtable data xref; ordinary-destructor and delete support callees.
- HumanImageLib RTTI COL/CHD/base-array anchors: `0x00648814`, `0x00648828`, `0x00648838`; Singleton BCD PMD at `0x00648864` is `{4,-1,0}`.
- Target has four write refs and zero reads. Clear helper has no absolute helper-pointer hit.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069b43c-0x0069b440` | UID0001PM / D1 | physical slot | false | UID0000R5 | 92/94 | implemented/validated zero/non-emitting |
| semantic global | UID0000R5 / D2 | sole source definition | true | UID0000JY | 92/94 | implemented/validated source-ready |
| class | UID00006A / D3 | complete declaration | true | UID0000JY | 92/93 | implemented/validated source-ready |
| source file | UID0000JY / D4 | focused source root | n/a | FILE | 91/92 | implemented/validated synchronized |
| `0x004d2720-0x004d4aca` | UID0002TO / D5 | authored constructor | true | UID00006A | 91/92 | implemented/validated source-ready |
| `0x004d4ad0-0x004d4f67` | UID00017B / D6 | authored destructor | true | UID00006A | 92/94 | implemented/validated source-ready |
| `0x004e5b80-0x004e5b8b` | UID00017X / D7 | compiler/EH Singleton clear | false | none | 91/94 | implemented/validated blank/no-emission |
| `0x004e6460-0x004e649b` | UID0003M0 / D8 | compiler scalar wrapper | false | UID00006A evidence | 91/94 | implemented/validated blank/no-emission |
| layout | UID0001UR / D9 | class layout support | true | UID00006A | 92/93 | implemented/validated class-covered marker |
| vtable | UID0001XQ / D10 | generated vtable semantics | false | UID00006A evidence | 92/94 | implemented/validated blank/no-emission |
| `0x0061b6d0-0x0061b6e0` | UID00036H / D11 | physical RTTI/vtable data | false | none | 92/94 | implemented/validated blank/no-emission |
| `0x004e6ae0-0x004e6c4c` | UID0004DK / D12 | file-local 12-byte loader | true | UID0000JY | 91/92 | implemented/validated source-ready |
| `0x004e6c50-0x004e6de4` | UID0004DL / D13 | file-local 16-byte loader | true | UID0000JY | 91/92 | implemented/validated source-ready |
| `0x004d2720-0x004dac40` | UID00017A / D14 | non-emitting mixed index | false | none | 85/90 unchanged | validated prose/index synchronization |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004d277b` | constructor -> slot | Singleton base publishes complete object pointer |
| `0x004d2782` | constructor -> slot | adjusted-null publication fallback clears slot |
| `0x004d4f44` | destructor -> slot | Singleton base destruction clears slot |
| `0x004e5b80` | helper -> slot | EH/static cleanup clears slot |
| `0x005ffaf2` | constructor cleanup funclet -> helper | sole helper reachability |
| `0x0061b6d4` | vtable -> scalar wrapper | virtual destructor compiler entry |
| `0x004e6466` | scalar wrapper -> ordinary destructor | deleting wrapper delegates to source destructor |
| `0x004d2b0e`, `0x004d2b45` | constructor -> UID0004DK | head/head-special 12-byte row loads |
| six sites `0x004d2d74..0x004d2e96` | constructor -> UID0004DL | weapon/equipment 16-byte row loads |

## Documentation Evidence And IDA Status

- D1 target now carries exact loader-zero truth; only the supervisor-owned manual row retains the false historical `0xffffffff` wording and is covered by the exact handoff below.
- UID0000R5 now has the sole definition route and no empty marker.
- UID00006A and generated HumanImageLib.cpp now carry the complete declaration/source union.
- UID0002TO/UID00017B/UID0004DK/UID0004DL now carry complete accepted source bodies; their former stale blank-C++ conclusions are historicalized.
- UID00017X/UID0003M0/UID0001XQ/UID00036H preserve valid binary evidence and correctly emit no pseudo-source.
- Historical generated command 15860 is the pre-implementation evidence snapshot; current command 15935 supersedes its blank state with the validated source union.

## Ranked Ownership Analysis

### 1. UID0000R5 semantic global in UID0000JY HumanImageLib source

- Evidence for: exact typed slot, class-specific lifetime writes, focused old-human source, peer singleton convention, and one-definition requirement.
- Evidence against: exact original global identifier is stripped.
- Decision: accepted best source owner; original spelling uncertainty is a confidence cap only.

### 2. UID0001PM physical storage as definition owner

- Evidence for: exact address and bytes.
- Evidence against: emitting here duplicates UID0000R5, and the page is an address index rather than source declaration owner.
- Decision: retain as false/non-emitting physical evidence.

### 3. Singleton template static-member specialization

- Evidence for: direct Singleton base causes writes/clears and could historically have supplied storage.
- Evidence against: exact lexical static-member name/definition is unrecovered; adding it alongside the canonical external global duplicates storage.
- Decision: preserve as source-history possibility, reject as an additional emitter.

### 4. ImageLib, NewHumanImageLib, DAT, EPF, or consumer owner

- Evidence for: dependency and neighboring resource use only.
- Evidence against: distinct RTTI/storage/resource families and no target reads.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Not applicable. Existing focused `NexusTK/render/HumanImageLib.h/.cpp` route is sufficient.
- No new global, class, source file, target child, or generic VectorHelpers owner is warranted.

## Source Placement

- Header/declaration: `NexusTK/render/HumanImageLib.h`, represented by UID00006A.
- Sole global and bodies: `NexusTK/render/HumanImageLib.cpp`, represented by UID0000JY.
- Shared `ProtectedArray<T>`, DATFile, ImageFrameTable, and resource-layout APIs remain in their existing support modules.
- Rejected placement: NewHumanImageLib, ImageLib, DATArchive, EPFImageResources, Application, or any consumer file.

## Range / Split / Padding / Reclassification Analysis

- UID0001PM range is exact four-byte data. No split, merge, rename, or padding registration is needed.
- Reclassification is metadata/source disposition only: true/emitting physical page becomes false/non-emitting evidence.
- Constructor/destructor/helper/wrapper boundaries are already exact and separated by documented `0xcc` alignment.
- UID00017A remains a mixed non-emitting index; exact children own source or compiler dispositions.

## Negative Evidence Summary

- No target read, no general consumer, no target function, no raw file bytes, and no alternative initialized value.
- No constructor entry xref; this does not imply dead code because static lifetime, vtable installation, and paired cleanup are direct facts.
- No ordinary caller/callee for UID00017X beyond EH cleanup; it is not a public source helper.
- No ordinary caller for UID0003M0 beyond vtable dispatch; it is compiler ABI support.
- No fourth HumanImageLib virtual method, no separate singleton storage field, no explicit EBO padding field, and no need for raw address/decompiler names in source.
- No evidence that old HumanImageLib and NewHumanImageLib share a class/global/source owner.
- No direct prior UID0001PM report in active, executed, Older-Research, or SpecialReports roots.

## IDA Rename / Type / Comment Recommendations

- No IDA mutation is requested or permitted.
- Documentation/source-facing target type/name: `HumanImageLib *g_pHumanImageLib`.
- Descriptive late fields: `m_drawOrderCount`, `m_extendedDrawOrderCount`, `m_extendedDrawOrder2Count`, matching table pointers, four frame-count shorts, and eighteen named frame-table pointers.
- Historical aliases `dword_69B43C`, `unk_69B43C`, generic cached-resource names, and explicit address labels remain evidence aliases only.

## First-Draft C++ Recommendation

### Destination D1 - UID0001PM physical storage page

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: D1 is the address-indexed physical slot. D2 emits the only source definition; any D1 code duplicates storage.

### Destination D2 - UID0000R5 semantic global

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HumanImageLib;

HumanImageLib *g_pHumanImageLib = 0;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination D3 - UID00006A complete class declaration

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HumanImageLib : public LObject, public Singleton<HumanImageLib>
{
public:
    HumanImageLib();
    virtual ~HumanImageLib();

private:
    ProtectedArray<HeadInfo> m_headInfos;
    ProtectedArray<HeadInfo> m_specialHeadInfos;
    ProtectedArray<BodyInfo> m_bodyInfos;
    ProtectedArray<CoatInfo> m_coatInfos;
    ProtectedArray<WeaponInfo> m_swordInfos;
    ProtectedArray<WeaponInfo> m_spearInfos;
    ProtectedArray<WeaponInfo> m_bowInfos;
    ProtectedArray<WeaponInfo> m_fanInfos;
    ProtectedArray<WeaponInfo> m_shieldInfos;
    ProtectedArray<WeaponInfo> m_arrowInfos;
    ProtectedArray<FaceInfo> m_faceInfos;
    ProtectedArray<Acc1Info> m_accessory1Infos;
    ProtectedArray<HairInfo> m_hairInfos;
    ProtectedArray<Acc2Info> m_accessory2Infos;
    ProtectedArray<HelmetInfo> m_helmetInfos;
    ProtectedArray<MantleInfo> m_mantleInfos;
    ProtectedArray<NecklaceInfo> m_necklaceInfos;
    ProtectedArray<ShoeInfo> m_shoeInfos;

    int m_drawOrderCount;
    int m_extendedDrawOrderCount;
    int m_extendedDrawOrder2Count;
    unsigned int *m_drawOrderEntries;
    HumanDrawOrderEntry *m_extendedDrawOrderEntries;
    HumanDrawOrderEntry *m_extendedDrawOrder2Entries;
    unsigned short m_headFrameCount;
    unsigned short m_specialHeadFrameCount;
    unsigned short m_emotionFrameCount;
    unsigned short m_specialEmotionFrameCount;
    ImageFrameTable *m_headFrames;
    ImageFrameTable *m_specialHeadFrames;
    ImageFrameTable *m_bodyFrames;
    ImageFrameTable *m_swordFrames;
    ImageFrameTable *m_spearFrames;
    ImageFrameTable *m_bowFrames;
    ImageFrameTable *m_fanFrames;
    ImageFrameTable *m_shieldFrames;
    ImageFrameTable *m_arrowFrames;
    ImageFrameTable *m_faceFrames;
    ImageFrameTable *m_accessory1Frames;
    ImageFrameTable *m_hairFrames;
    ImageFrameTable *m_accessory2Frames;
    ImageFrameTable *m_helmetFrames;
    ImageFrameTable *m_mantleFrames;
    ImageFrameTable *m_necklaceFrames;
    ImageFrameTable *m_shoeFrames;
    ImageFrameTable *m_coatFrames;
};

extern HumanImageLib *g_pHumanImageLib;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The concrete old-human record declarations belong to the focused HumanImageLib header/source family; the shared ProtectedArray header owns only `ProtectedArray<T>`. RTTI/template names and exact container strides establish the declaration spellings and required size checks: `HeadInfo 0x0c`, `BodyInfo 0x10`, `CoatInfo 0x14`, `WeaponInfo 0x10`, `FaceInfo 0x0c`, `Acc1Info 0x10`, `HairInfo 0x10`, `Acc2Info 0x14`, and each remaining equipment row `0x10`. D12/D13 close the source-used fields of `HeadInfo` and `WeaponInfo`; the other records retain their focused HumanImageLib-owned declarations and exact sizes without moving them into ProtectedArray or inventing raw reserve members.

### Destination D5 - UID0002TO constructor

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void LoadHumanHeadInfoTable(ProtectedArray<HeadInfo> &rows,
                                   DATFile &file,
                                   const char *sourceName);
static void LoadHumanWeaponInfoTable(ProtectedArray<WeaponInfo> &rows,
                                     DATFile &file,
                                     const char *sourceName);

HumanImageLib::HumanImageLib()
    : LObject(),
      Singleton<HumanImageLib>(),
      m_headInfos(10),
      m_specialHeadInfos(10),
      m_bodyInfos(10),
      m_coatInfos(10),
      m_swordInfos(10),
      m_spearInfos(10),
      m_bowInfos(10),
      m_fanInfos(10),
      m_shieldInfos(10),
      m_arrowInfos(10),
      m_faceInfos(10),
      m_accessory1Infos(10),
      m_hairInfos(10),
      m_accessory2Infos(10),
      m_helmetInfos(10),
      m_mantleInfos(10),
      m_necklaceInfos(10),
      m_shoeInfos(10),
      m_drawOrderCount(0),
      m_extendedDrawOrderCount(0),
      m_extendedDrawOrder2Count(0),
      m_drawOrderEntries(0),
      m_extendedDrawOrderEntries(0),
      m_extendedDrawOrder2Entries(0),
      m_headFrameCount(0),
      m_specialHeadFrameCount(0),
      m_emotionFrameCount(0),
      m_specialEmotionFrameCount(0),
      m_headFrames(0), m_specialHeadFrames(0), m_bodyFrames(0),
      m_swordFrames(0), m_spearFrames(0), m_bowFrames(0),
      m_fanFrames(0), m_shieldFrames(0), m_arrowFrames(0),
      m_faceFrames(0), m_accessory1Frames(0), m_hairFrames(0),
      m_accessory2Frames(0), m_helmetFrames(0), m_mantleFrames(0),
      m_necklaceFrames(0), m_shoeFrames(0), m_coatFrames(0)
{
    DATFile headInfoFile;
    headInfoFile.Open(kHumanHeadTableArgs);
    LoadHumanHeadInfoTable(m_headInfos, headInfoFile, "headtable.txt");

    DATFile specialHeadInfoFile;
    specialHeadInfoFile.Open(kHumanSpecialHeadTableArgs);
    LoadHumanHeadInfoTable(m_specialHeadInfos,
                           specialHeadInfoFile,
                           "headsptable.txt");
    LoadHumanInfoTable(m_bodyInfos, L"BODY.TBL");
    LoadHumanInfoTable(m_coatInfos, L"COAT.TBL");
    DATFile swordInfoFile;
    swordInfoFile.Open(kHumanSwordTableArgs);
    LoadHumanWeaponInfoTable(m_swordInfos, swordInfoFile, "swordtable.txt");

    DATFile spearInfoFile;
    spearInfoFile.Open(kHumanSpearTableArgs);
    LoadHumanWeaponInfoTable(m_spearInfos, spearInfoFile, "speartable.txt");

    DATFile bowInfoFile;
    bowInfoFile.Open(kHumanBowTableArgs);
    LoadHumanWeaponInfoTable(m_bowInfos, bowInfoFile, "bowtable.txt");

    DATFile fanInfoFile;
    fanInfoFile.Open(kHumanFanTableArgs);
    LoadHumanWeaponInfoTable(m_fanInfos, fanInfoFile, "fantable.txt");

    DATFile shieldInfoFile;
    shieldInfoFile.Open(kHumanShieldTableArgs);
    LoadHumanWeaponInfoTable(m_shieldInfos, shieldInfoFile, "shieldtable.txt");

    DATFile arrowInfoFile;
    arrowInfoFile.Open(kHumanArrowTableArgs);
    LoadHumanWeaponInfoTable(m_arrowInfos, arrowInfoFile, "arrowtable.txt");
    LoadHumanInfoTable(m_faceInfos, L"FACE.TBL");
    LoadHumanInfoTable(m_accessory1Infos, L"ACE1.TBL");
    LoadHumanInfoTable(m_hairInfos, L"HAIR.TBL");
    LoadHumanInfoTable(m_accessory2Infos, L"ACE2.TBL");
    LoadHumanInfoTable(m_helmetInfos, L"HELMET.TBL");
    LoadHumanInfoTable(m_mantleInfos, L"MANTLE.TBL");
    LoadHumanInfoTable(m_necklaceInfos, L"NECLACE.TBL");
    LoadHumanInfoTable(m_shoeInfos, L"SHOES.TBL");
    LoadHumanDrawOrderTable(L"DRWORDER.TBL", &m_drawOrderEntries, &m_drawOrderCount);
    LoadHumanDrawOrderTable(L"XDRWORD.TBL", &m_extendedDrawOrderEntries, &m_extendedDrawOrderCount);
    LoadHumanDrawOrderTable(L"XDRWORD2.TBL", &m_extendedDrawOrder2Entries, &m_extendedDrawOrder2Count);

    m_headFrames = LoadImageFrameTable(L"HEAD.EPF", 0);
    m_specialHeadFrames = LoadImageFrameTable(L"HEADSP.EPF", 0);
    m_bodyFrames = LoadImageFrameTable(L"BODY.EPF", 0);
    m_swordFrames = LoadImageFrameTable(L"SWORD.EPF", 0);
    m_spearFrames = LoadImageFrameTable(L"SPEAR.EPF", 0);
    m_bowFrames = LoadImageFrameTable(L"BOW.EPF", 0);
    m_fanFrames = LoadImageFrameTable(L"FAN.EPF", 0);
    m_shieldFrames = LoadImageFrameTable(L"SHIELD.EPF", 0);
    m_arrowFrames = LoadImageFrameTable(L"ARROW.EPF", 0);
    m_faceFrames = LoadImageFrameTable(L"FACE.EPF", 0);
    m_accessory1Frames = LoadImageFrameTable(L"ACE1.EPF", 0);
    m_hairFrames = LoadImageFrameTable(L"HAIR.EPF", 0);
    m_accessory2Frames = LoadImageFrameTable(L"ACE2.EPF", 0);
    m_helmetFrames = LoadImageFrameTable(L"HELMET.EPF", 0);
    m_mantleFrames = LoadImageFrameTable(L"MANTLE.EPF", 0);
    m_necklaceFrames = LoadImageFrameTable(L"NECLACE.EPF", 0);
    m_shoeFrames = LoadImageFrameTable(L"SHOES.EPF", 0);
    m_coatFrames = LoadImageFrameTable(L"COAT.EPF", 0);

    ResolveHumanEmotionFrameCounts(L"EMOTION.EPF", L"EMOTIOSP.EPF",
        &m_headFrameCount, &m_specialHeadFrameCount,
        &m_emotionFrameCount, &m_specialEmotionFrameCount);
    ApplyHumanAccessoryDrawTable(m_accessory2Infos, L"ACC2DRW.TBL");
    ApplyHumanHairColorTable(m_hairInfos, L"HAIRCOL.TBL");
    ValidateHumanFrameCounts();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The recovered three-argument ABI is identical at all eight callsites: the destination `ProtectedArray` is first, an already opened local `DATFile` is second, and the narrow source-name literal is third. UID0004DK has two constructor calls and reads three encoded integers per 12-byte row after installing the exact `-1/-1/-255` fallback. UID0004DL has six constructor calls and reads four encoded integers per 16-byte row after installing only the exact first-three-field `-1/-1/0` fallback; the fourth fallback field is intentionally untouched, while each loaded fourth value has its 16-bit halves exchanged. Both helpers resize only for a positive changed count and latch `g_imageLibraryLoadErrorFlag` on every failed encoded-int read.

The named helper facade is the source-facing expression of the exact inlined DAT loops and existing file-local loader specializations. `kHuman*TableArgs` denotes the exact read-only `ArgList` objects passed to `DATFile::Open`; each literal source name is the observed narrow third argument to UID0004DK/UID0004DL. These names are descriptive source declarations, not raw addresses or decompiler temporaries.

### Destination D6 - UID00017B ordinary destructor

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HumanImageLib::~HumanImageLib()
{
    ReleaseImageFrameTable(m_headFrames);
    ReleaseImageFrameTable(m_specialHeadFrames);
    ReleaseImageFrameTable(m_bodyFrames);
    ReleaseImageFrameTable(m_swordFrames);
    ReleaseImageFrameTable(m_spearFrames);
    ReleaseImageFrameTable(m_bowFrames);
    ReleaseImageFrameTable(m_fanFrames);
    ReleaseImageFrameTable(m_shieldFrames);
    ReleaseImageFrameTable(m_arrowFrames);
    ReleaseImageFrameTable(m_faceFrames);
    ReleaseImageFrameTable(m_accessory1Frames);
    ReleaseImageFrameTable(m_hairFrames);
    ReleaseImageFrameTable(m_accessory2Frames);
    ReleaseImageFrameTable(m_helmetFrames);
    ReleaseImageFrameTable(m_mantleFrames);
    ReleaseImageFrameTable(m_necklaceFrames);
    ReleaseImageFrameTable(m_shoeFrames);
    ReleaseImageFrameTable(m_coatFrames);
    delete[] m_drawOrderEntries;
    delete[] m_extendedDrawOrderEntries;
    delete[] m_extendedDrawOrder2Entries;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination D7 - UID00017X Singleton cleanup helper

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: direct Singleton base lifetime causes this EH-only clear helper; no authored helper exists.

### Destination D8 - UID0003M0 scalar deleting destructor

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: D3's virtual destructor plus D6's ordinary body regenerate this ABI wrapper.

### Destination D9 - UID0001UR layout support

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete HumanImageLib declaration is emitted once by UID00006A.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination D10 - UID0001XQ semantic vtable

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination D11 - UID00036H physical vtable/RTTI data

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination D12 - UID0004DK 12-byte HeadInfo loader

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void LoadHumanHeadInfoTable(ProtectedArray<HeadInfo> &rows,
                                   DATFile &file,
                                   const char *sourceName)
{
    (void)sourceName;
    rows.GetDefaultEntry().frameIndex = -1;
    rows.GetDefaultEntry().offsetX = -1;
    rows.GetDefaultEntry().offsetY = -255;

    int count = -1;
    if (!file.ReadEncodedTableInt(&count))
        g_imageLibraryLoadErrorFlag = true;
    if (count > 0 && rows.GetCount() != count)
        rows.Resize(count);

    for (int index = 0; index < count; ++index)
    {
        HeadInfo &row = *rows.GetAtOrDefault(index);
        if (!file.ReadEncodedTableInt(&row.frameIndex))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetX))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetY))
            g_imageLibraryLoadErrorFlag = true;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination D13 - UID0004DL 16-byte WeaponInfo loader

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void LoadHumanWeaponInfoTable(ProtectedArray<WeaponInfo> &rows,
                                     DATFile &file,
                                     const char *sourceName)
{
    (void)sourceName;
    rows.GetDefaultEntry().frameIndex = -1;
    rows.GetDefaultEntry().offsetX = -1;
    rows.GetDefaultEntry().offsetY = 0;

    int count = -1;
    if (!file.ReadEncodedTableInt(&count))
        g_imageLibraryLoadErrorFlag = true;
    if (count > 0 && rows.GetCount() != count)
        rows.Resize(count);

    for (int index = 0; index < count; ++index)
    {
        WeaponInfo &row = *rows.GetAtOrDefault(index);
        int packedDrawOrder = 0;
        if (!file.ReadEncodedTableInt(&row.frameIndex))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetX))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetY))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&packedDrawOrder))
            g_imageLibraryLoadErrorFlag = true;
        row.packedDrawOrder =
            (static_cast<unsigned int>(packedDrawOrder) << 16) |
            (static_cast<unsigned int>(packedDrawOrder) >> 16);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination D14 - UID00017A aggregate

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: the aggregate is a mixed address/index container. Exact children own all source or compiler dispositions.

## Final Recommendation

- Applied physical/semantic chain: UID0001PM -> UID0000R5 -> UID0000JY, with one source definition and no physical duplicate.
- Applied complete class/source closure through UID00006A, UID0002TO, UID00017B, UID0004DK, and UID0004DL.
- Applied compiler/generated dispositions to UID00017X, UID0003M0, UID0001XQ, UID00036H, and the mixed UID00017A container.
- Preserve all exact bytes, PE facts, xrefs, RTTI, EBO, offsets, resource spellings, helper boundaries, negative evidence, and historical false assumptions.
- No new UID, split, range rename, ignored span, source file, or IDA mutation is required.

## Recommended Target Doc Changes

- Target: `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md`.
- Applied `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000R5`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank formal C++, `Nested:0`.
- Replaced active `ff ff ff ff`/raw `.data` wording with exact zero bytes, SHA, `.data` raw/virtual arithmetic, loader-zero classification, and historicalized rejection.
- Added all four writes, no-read proof, direct Singleton source cause, D2 sole definition, complete HumanImageLib source route, and generated one-definition readback.

## Recommended Support Doc Changes

- D2 `by-global/g_pHumanImageLib.md`: applied `92/94`, position 20, sole definition block, exact zero storage/four writes/no reads/Singleton cause, and original-spelling cap.
- D3 `by-class/HumanImageLib.md`: applied `92/93`, position 10, complete declaration block, direct bases/EBO, exact `0x2b0` layout, all named fields, method/source/compiler inventory, and preserved old/new split.
- D4 `by-file/HumanImageLib.md`: applied `91/92`, `HumanImageLib.h/.cpp`, exact emitter-position metadata `10/20/30/40/50/60`, complete source union, and dependencies/exclusions. Generated depth-first owner traversal is documented separately from cross-owner numeric positions.
- D5 constructor: applied `91/92`, position 30, accepted formal, exact lifetime/table/frame/resource/error/EH behavior, and historicalized blank-C++ proof.
- D6 destructor: applied `92/94`, position 40, accepted formal, exact explicit versus implicit cleanup, and no manual global clear.
- D7 helper: applied `91/94`, false/non-emitting/blank; bytes/xref and compiler EH Singleton support retained.
- D8 scalar wrapper: applied `91/94`, false/non-emitting/blank; ABI flags/delete behavior and virtual-destructor source cause retained.
- D9 layout: applied `92/93`, exact field names/types/size/EBO/no-padding; marker only avoids class duplication.
- D10/D11 vtable pages: applied `92/94`, false/non-emitting/blank; exact RTTI/slots/neighbor boundaries retained.
- D12/D13 helpers: applied `91/92`, positions 50/60, exact formal bodies, source route, caller sets, row sizes, error latching, and rejected generic ownership.
- D14 aggregate: preserved `85/90`, false/non-emitting/blank; current child/source closure and historical open-island limits synchronized without score inflation.

## Score And Metadata Recommendation

- Target is now `92/94` from historical `86/90`: exact bytes, raw mapping, all refs, type, source cause, one-definition route, and no-code physical disposition are closed. Not 95 because original global spelling is stripped.
- Global is now `92/94` from historical `89/86`: exact declaration/definition/initializer/linkage/owner/order and complete lifetime are closed.
- Class is now `92/93` from historical `88/88`: direct bases, EBO, complete layout, virtual surface, declaration, and source union are closed; inferred private spellings cap confidence.
- File is now `91/92` from historical `87/88`: focused source/header route and all bounded lifetime/declaration children are source-disposed; unrelated lower composition islands remain outside this target callback.
- Constructor is now `91/92` from historical `89/90`: exact phase behavior and destination source shape are complete; the huge optimized body and descriptive helper facade cap lexical confidence.
- Destructor is now `92/94` from historical `86/91`: exact explicit/implicit cleanup split and complete body are closed.
- Compiler/helper/vtable scores move only as listed because their binary identity is exact while their source disposition is intentionally blank/non-emitting.
- No metadata field is changed without an exact destination disposition above.

## Open Questions With Attempted Resolution

- Original global spelling: exhaustive symbols/docs/reports do not prove it. Resolution: project-canonical `g_pHumanImageLib`, confidence cap only.
- Original private field spellings: exact offsets/types/roles are proven; descriptive names are selected consistently with project style. No behavior/C++ blocker remains.
- Original template-static versus free-global lexical form: direct Singleton supports either historical mechanism, but current project one-definition contract requires one by-global definition. A second template specialization is rejected.
- Constructor no direct caller: static/EH lifetime and vtable/global writes prove liveness. No score or source blocker remains.
- Lower raw composition islands in UID00017A: not needed to close the global/class lifetime/declaration union and remain separately queued; they do not justify keeping the constructor/destructor/global blank.
- Exact historical header basename: `HumanImageLib.h` is the strongest project-consistent route. No alternative has positive evidence.
- Remaining unavailable evidence: original PDB/source. Its absence prevents 95-level lexical certainty only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Latest manual-file readback during callback finalization, performed without editing:
  - `by-memory/-coverage-report.md` SHA256 `1D95BA3D63840C56DE05AF8BFD9129BEB5F64D4CCAB8E524272F8F6C5AFE1EE1`, 1,906,708 bytes / 4,471 lines.
  - `by-global/-coverage-report.md` SHA256 `2F5A08437C721BD81F341556B786473CAB1E601388D09F67D4BDC5E22FC6F64B`, 94,263 / 214.
  - `by-class/-coverage-report.md` SHA256 `9C74E4C9C0E9BC0160290E8C7EE4A3511825EA0BD847C435713DE93520307E98`, 247,456 / 623.
  - `by-file/-coverage-report.md` SHA256 `3D3D4DEB9454144A4EEBAD87809AEFD2EC1935CCB0EA6A76FC6D36E3593C53CC`, 145,250 / 316.
  - `by-type/by-struct/-coverage-report.md` SHA256 `FE6F956B0F09178851B615A476910CF054AA6DA988A1D8688A8E91DE1F6BD5A0`, 56,777 / 137.
  - `by-type/by-vtable/-coverage-report.md` SHA256 `905DB13B93D3EBCEBC0BE71F1A2099B777C7655B6222F581C3AC416D6D966F06`, 64,768 / 142.
- Supervisor replacement in `by-memory/-coverage-report.md` at current UID0001PM row:

```text
    - [UID:0001PM][0x0069b43c-0x0069b440.g_pHumanImageLib](by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md) 0x0069b43c-0x0069b440 | global pointer storage | g_pHumanImageLib : ignored : 92% : very-strong : Exact four-byte loader-zeroed slot with bytes 00 00 00 00, virtual-only .data mapping beyond raw size, four write-only Singleton lifetime refs, zero direct reads, semantic UID0000R5 sole-definition route, and false/non-emitting physical-storage disposition.
```

- Supervisor replacement in `by-memory/-coverage-report.md` at current UID00017A row:

```text
    - [UID:00017A][0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster](by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md) 0x004d2720-0x004dac40 | class-method-cluster | HumanImageLib : ignored : 85% : strong : Non-emitting old-human method-neighborhood index with source-ready constructor/destructor children, exact compiler singleton/scalar support, complete class/global/layout/vtable route, two source-ready table-loader helpers, preserved lower composition-island inventory, and no aggregate duplicate source.
```

- Supervisor replacement in `by-memory/-coverage-report.md` at current UID0002TO row:

```text
        - [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md) 0x004d2720-0x004d4aca | constructor | HumanImageLib::HumanImageLib : reconstructable : 91% : very-strong : Exact 0x23aa source-authored constructor with direct LObject/Singleton bases, complete 0x2b0 member declaration, old-human table and 18-frame-resource loading, draw-order and validation fields, error/fatal behavior, compiler-lowering exclusions, and destination-ready formal source.
```

- Supervisor replacement in `by-memory/-coverage-report.md` at current UID00017B row:

```text
    - [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md) 0x004d4ad0-0x004d4f67 | destructor-body | HumanImageLib::~HumanImageLib : reconstructable : 92% : very-strong : Exact ordinary destructor with explicit release of 18 frame-table handles and three draw-order arrays, implicit ProtectedArray/Singleton/LObject cleanup, no duplicate manual singleton clear, scalar-wrapper parity, and destination-ready formal source.
```

- Supervisor replacement in `by-memory/-coverage-report.md` at current UID00017X row:

```text
    - [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) 0x004e5b80-0x004e5b8b | Singleton EH cleanup support | HumanImageLib Singleton base cleanup : ignored : 91% : very-strong : Exact two-instruction zero-store helper reached only from constructor EH cleanup; direct Singleton<HumanImageLib> base/PMD/EBO proves compiler-generated source-declared support, so the helper is false/non-emitting with blank formal C++.
```

- Supervisor replacement in `by-global/-coverage-report.md` at UID0000R5:

```text
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) : reconstructable : 92% : very-strong : Sole zero-initialized HumanImageLib pointer definition in NexusTK/render/HumanImageLib.cpp, backed by loader-zeroed UID0001PM, exactly four write-only direct-Singleton lifetime refs, complete class/layout/vtable/source route, and no duplicate physical/helper/compiler emission.
```

- Supervisor replacement in `by-class/-coverage-report.md` at UID00006A:

```text
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) : reconstructable : 92% : very-strong : Complete legacy human/equipment image-library declaration with direct LObject and Singleton<HumanImageLib> bases, +0x04 EBO, exact 0x2b0 layout, eighteen ProtectedArray members, three draw-order arrays, four frame counts, eighteen frame-table handles, virtual destructor, source-ready lifetime methods, and compiler-artifact exclusions.
```

- Supervisor replacement in `by-file/-coverage-report.md` at UID0000JY:

```text
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) : reconstructable : 91% : very-strong : Focused NexusTK/render/HumanImageLib.h/.cpp old-human source with complete class declaration, sole g_pHumanImageLib definition, source-ready constructor/destructor and two table loaders, exact positions 10-60, ProtectedArray/ImageFrameTable/DAT dependencies, and no compiler/vtable/physical duplicate source.
```

- Supervisor replacement in `by-type/by-struct/-coverage-report.md` at UID0001UR:

```text
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md) : reconstructable : 92% : very-strong : Exact 0x2b0 HumanImageLib layout with direct Singleton EBO at +0x04, eighteen typed ProtectedArray members through +0x23f, three draw-order counts/pointers, four natural-aligned 16-bit validation counts, eighteen frame-table pointers through +0x2ac, constructor/destructor agreement, and class-covered declaration route.
```

- Supervisor replacement in `by-type/by-vtable/-coverage-report.md` at UID0001XQ:

```text
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) : ignored : 92% : very-strong : Exact generated HumanImageLib vtable at 0x0061b6d4 with scalar deleting destructor and two inherited LObject slots, constructor/destructor stores, direct RTTI hierarchy, physical UID00036H support, and blank non-emitting disposition regenerated from the complete class virtual-destructor declaration.
```

- Supervisor addition in `by-memory/-coverage-report.md` inside UID00017A, immediately after UID0002HC and before UID0002Y4 in address order:

```text
    - [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md) 0x004e6460-0x004e649b | compiler scalar deleting destructor | HumanImageLib scalar deleting destructor : ignored : 91% : very-strong : Exact vtable-only MSVC deleting wrapper over UID00017B ordinary destruction, with flag-controlled optional object deletion and exact 0x2b0 object-size evidence; the virtual destructor declaration is the sole source cause, so this page is false/non-emitting with blank formal C++ and no duplicate authored wrapper body.
```

- Supervisor additions in `by-memory/-coverage-report.md` inside UID00022R in exact address order: UID0004DK immediately after the UID00022R parent and before the existing `[0x004e6c4c,0x004e6c50)` padding row; UID0004DL immediately after that padding row and before the existing `[0x004e6de4,0x004e6df0)` padding row:

```text
        - [UID:0004DK][0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable](by-memory/0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable.md) 0x004e6ae0-0x004e6c4c | file-local table loader | LoadHumanHeadInfoTable : reconstructable : 91% : very-strong : Exact constructor-only three-argument helper with two callsites, existing DATFile stream plus narrow source-name argument, 12-byte HeadInfo rows, -1/-1/-255 fallback, positive-count resize, three encoded-int reads per row, shared image-library error latch, focused HumanImageLib.cpp route, and destination-ready source.
        - [UID:0004DL][0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable](by-memory/0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable.md) 0x004e6c50-0x004e6de4 | file-local table loader | LoadHumanWeaponInfoTable : reconstructable : 91% : very-strong : Exact constructor-only three-argument helper with six equipment-family callsites, existing DATFile stream plus narrow source-name argument, 16-byte WeaponInfo rows, -1/-1/0 three-field fallback with fourth fallback field untouched, positive-count resize, four encoded-int reads per row, 16-bit-half-swapped fourth value, shared image-library error latch, focused HumanImageLib.cpp route, and destination-ready source.
```

- Supervisor addition in `by-memory/-coverage-report.md` inside UID00025I, immediately before successor UID0002MM in address order:

```text
        - [UID:00036H][0x0061b6d0-0x0061b6e0.HumanImageLibVtableData](by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md) 0x0061b6d0-0x0061b6e0 | compiler RTTI/vtable data | HumanImageLib vtable data : ignored : 92% : very-strong : Exact HumanImageLib RTTI locator plus scalar-deleting-destructor and two inherited LObject slots, direct LObject/Singleton hierarchy, constructor/destructor vptr xrefs, MapTile/Monster neighbor boundaries, and generated false/non-emitting blank-formal disposition caused by the complete UID00006A class declaration.
```

- Current row readback: UID0001PM, UID00017A, UID0002TO, UID00017B, UID00017X, UID0000R5, UID00006A, UID0000JY, UID0001UR, and UID0001XQ each occur once but retain the stale pre-callback text quoted by the replacement instructions above. UID0003M0, UID0004DK, UID0004DL, and UID00036H remain absent from the applicable manual files, so the four additions remain exact and no-loss at the literal placements above.
- No tracker text is supplied because tracker state is validator-owned. B001 did not apply any row; all exact replacement/addition text remains a supervisor-owned handoff after implementation verification.

## Follow-Up Actions

- External supervisor/validator-owned state: report validation, manual coverage application, report count/path, execution, move, and archive status are outside this artifact. The exact unapplied manual handoff above remains available without this report asserting or directing later lifecycle state.
- A-agent actions: none.
- B001 callback work remaining: none. Lower old-human composition islands remain independently queued and do not block this bounded global/lifetime/source closure.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: 94/100 for D1/D2; 92/100 for complete class/constructor helper spellings.
- Remaining uncertainty: exact original private identifiers/header basename and whether the original global was lexically a template static member. Neither affects bytes, ABI, one-definition behavior, source placement, or destination readiness.

## Validator Results

- Every scoped command ran from `source-3/project-documentation` with `--mode file --file <destination> --apply --queue-timeout 240`, exited 0, and returned `ok:1`. Each file lease was released immediately after its scoped result.

| Destination | Command | Timestamp | Result / warnings / side effects |
| --- | --- | --- | --- |
| D1 UID0001PM | `000000015903` | `2026-07-21T14:33:39-04:00` | exit 0, ok 1; target registry, completion/confidence, stats updated; generated deferred. |
| D2 UID0000R5 | `000000015906` | `2026-07-21T14:34:34-04:00` | exit 0, ok 1; registry, completion/confidence, formal route, stats updated; generated deferred. |
| D3 UID00006A | `000000015910` | `2026-07-21T14:36:05-04:00` | exit 0, ok 1; three then-pre-existing missing-UID0003M0 reference warnings before D8 registration; UID00029J reference synchronized; generated deferred. |
| D4 UID0000JY | `000000015912` | `2026-07-21T14:37:30-04:00` | exit 0, ok 1; three then-pre-existing UID0003M0 and one UID00036H missing-reference warnings before D8/D11 registration; UID00029J reference synchronized; generated deferred. |
| D5 UID0002TO | `000000015915` | `2026-07-21T14:39:37-04:00` | exit 0, ok 1; registry, scores, formal, position and UID00022R reference synchronized; generated deferred. |
| D6 UID00017B | `000000015918` | `2026-07-21T14:40:34-04:00` | exit 0, ok 1; one then-pre-existing UID0003M0 reference warning before D8 registration; generated deferred. |
| D7 UID00017X | `000000015919` | `2026-07-21T14:41:37-04:00` | exit 0, ok 1; owner/registry false/non-emitting route updated; generated deferred. |
| D8 UID0003M0 | `000000015921` | `2026-07-21T14:43:01-04:00` | exit 0, ok 1; blank metadata separator normalized, UID/path registered, registry and eight references updated; no warnings; generated deferred. |
| D9 UID0001UR | `000000015923` | `2026-07-21T14:44:21-04:00` | exit 0, ok 1; registry, scores, formal marker and stats updated; generated deferred. |
| D10 UID0001XQ | `000000015924` | `2026-07-21T14:45:21-04:00` | exit 0, ok 1; four then-pre-existing UID00036H reference warnings before D11 registration; owner/registry updated; generated deferred. |
| D11 UID00036H | `000000015925` | `2026-07-21T14:46:19-04:00` | exit 0, ok 1; blank metadata separator normalized, UID/path registered, registry and seven references updated; no warnings; generated deferred. |
| D12 UID0004DK | `000000015926` | `2026-07-21T14:49:23-04:00` | exit 0, ok 1; completion/confidence, position 50, formal hash and stats updated; no warnings; generated deferred. |
| D13 UID0004DL | `000000015928` | `2026-07-21T14:50:27-04:00` | exit 0, ok 1; completion/confidence, position 60, formal hash and stats updated; no warnings; generated deferred. |
| D14 UID00017A | `000000015933` | `2026-07-21T14:51:45-04:00` | exit 0, ok 1; UID0003M0/UID0004DK/UID0004DL references and stats updated; no warnings; generated deferred. |
| Final waited D1 | `000000015935` | `2026-07-21T14:52:46-04:00` | exit 0, ok 1; generated refresh completed after zero leases. Global rebuild reported pre-existing project-wide `children marker missing`, `children fallback`, and `emitter has no code` diagnostics outside the bounded target; no target failure. |

- Generated `auto-generated/NexusTK/render/HumanImageLib.cpp`: command/header `000000015935`, SHA256 `1C246725E3F8BF0DB173F26796C81981C9F2381E6672422099CC5A8D704B5894`, 11,404 bytes / 281 lines. UID00006A, UID0000R5, UID0002TO, UID00017B, UID0004DK, and UID0004DL each occur once. One class declaration, one global definition, one constructor definition, one destructor definition, and one body for each helper occur; helper names occur twice each only because one prototype and one definition are intentional. UID0001PM/UID00017X/UID0003M0/UID0001XQ/UID00036H/UID00017A and `Empty Emitter Marker` occur zero times. `NewHumanImageLib`, `RidingHumanImageLib`, `MonsterImageLib`, and `EPFImageLib` occur zero times, preserving the old/new/sibling source boundary.
- Generated structural order is UID00006A class -> class-owned UID0002TO constructor -> class-owned UID00017B destructor -> class-covered UID0001UR marker -> file-owned UID0000R5 definition -> UID0004DK -> UID0004DL. This is the validator's depth-first owner traversal; destination emitter positions remain exactly 10/20/30/40/50/60 and no source item or class-closing brace is displaced or duplicated.
- Evidence-time validator-owned tracker readback during final self-review: command/header `000000015942`, refreshed `2026-07-21T15:07:23-04:00`, SHA256 `60A25400ACFC7FC0D90F6D64AAF1C7C4B492583A0F9721AFD2FF483177B3C7F0`, 1,548,242 bytes / 6,263 lines; UID0001PM remained `92/94`, score 93.0, false. This unrelated deferred refresh superseded command 15935 only as tracker-header freshness; B001 made no direct tracker edit, and later unrelated epochs remain external.
- Lease readback at `2026-07-21T15:04:14-04:00`: validator-owned `tools/leaser/Agents/current_leases.md` contained zero B001 leases. Its one unrelated B004 lease does not overlap any D1-D14 destination.

## Changed Files

- Updated same report: `tools/leaser/Agents/Agent-B001/research/0001PM-g_pHumanImageLib-source-quality.md`.
- Modified ordinary files, with final SHA256 / bytes / lines:
  - D1 `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md`: `E0C022E51F168BBEA2174ED83DB80F2E204ABA976B45222E837EA5C4EF1FDAB7` / 8,967 / 84.
  - D2 `by-global/g_pHumanImageLib.md`: `7429A084CECAB4A3EABE270765C3895DD39148B774E9FD2F81F573CDE57C0C1A` / 8,291 / 85.
  - D3 `by-class/HumanImageLib.md`: `78612C7F09856040F0255D63959C31535DA927FE65AE41022BB9D117C8055D28` / 19,806 / 186.
  - D4 `by-file/HumanImageLib.md`: `B4B75EBFDF989490F188837A48E463996A472362772F1FB125A3C19F3547D4B3` / 19,733 / 158.
  - D5 `by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md`: `CA02689ED44DB4315FDB95B6D43123553EADADA53A52AE9120FCF7B50DB7B29E` / 33,600 / 392.
  - D6 `by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md`: `0D83A3436F4D0E9336C992BE7ECB15A523173774F19C97D4286CE75DD7174E01` / 13,353 / 166.
  - D7 `by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md`: `396DC6C9C5BA3F14A1C077D8CF8BE908308D9493D02B7FDE104D2AD643A5582D` / 11,927 / 87.
  - D8 `by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md`: `A71DBB7BA45FB4D848EC07AD03E0A4EDC495A361451B0027861A562AA54D3FA2` / 10,448 / 96.
  - D9 `by-type/by-struct/HumanImageLibLayout.md`: `9886B1F42E8001771221EF232CEF8E32290F0EC8B125CE5C57F156B8CFED2261` / 11,628 / 149.
  - D10 `by-type/by-vtable/HumanImageLibVtable.md`: `A8391D1085CBBD3F426F55C2E3F7A8815FD6E5202F19DD826168BE733238C0E4` / 10,034 / 126.
  - D11 `by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md`: `749B42A8F9D11653C6BB221AAD15D8010A3502FAC044098CBF4F6D5B23D74349` / 7,338 / 90.
  - D12 `by-memory/0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable.md`: `222E32EE64637E24BD8273272C06ABA8A6E96518B9897062277CE00EB645174A` / 7,569 / 95.
  - D13 `by-memory/0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable.md`: `00A5360C8F204D453669527C237DABE91651CBAA54FF4636AB888899D729B41D` / 8,353 / 101.
  - D14 `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`: `62563AAF91F500B9A42A146DE1489C484816E15B78B3C97D241CD6A205AA287A` / 21,779 / 163.
- Formal parity: all thirteen report-managed destination blocks match D1-D3 and D5-D14 exactly; six are intentionally blank under destination-specific physical/compiler/index no-code proof and seven contain the accepted declaration/definition/body/covered-by source.
- Renamed/created ordinary paths: none. Split/new UID/ignored-padding edits: none.
- Manual coverage files were read only and remain the exact supervisor handoff above. Generated command 15935 and unrelated tracker-only commands through evidence-time command 15942 are validator-owned side effects, not manual B001 edits. IDA/supervisor/audit/validator-state/lifecycle files were not edited by B001.
- Report execution: not run. B001 did not probe, execute, move, or archive the report.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] D1 target metadata, zero bytes, PE mapping, write-only xrefs, history, and blank physical formal applied.
- [x] D2 sole typed global definition and one-definition evidence applied.
- [x] D3 complete class declaration, bases, EBO, layout, source/compiler split, and `[[CHILDREN]]` applied.
- [x] D4 focused header/source route, order, dependencies, exclusions, and historical blockers applied.
- [x] D5 complete constructor source and no-loss binary/resource/EH evidence applied.
- [x] D6 complete destructor source and explicit/implicit cleanup split applied.
- [x] D7 Singleton cleanup compiler disposition and blank formal applied.
- [x] D8 scalar-wrapper compiler disposition and blank formal applied.
- [x] D9 complete `0x2b0` layout and no-padding proof applied.
- [x] D10/D11 semantic/physical vtable generated dispositions applied.
- [x] D12/D13 exact file-local loader formals and caller/row/error evidence applied.
- [x] D14 non-emitting index synchronized without score/formal loss.
- [x] C1PM-001 through C1PM-080 each accepted or rejected claim by claim.
- [x] Current target state and actual evidence checked recorded in destinations.
- [x] Metadata/score/owner/emitter/reconstructable changes applied exactly.
- [x] No split/rename/new-child/ignored-padding action confirmed.
- [x] Source-placement and old/new HumanImageLib separation synchronized.
- [x] All thirteen destination managed blocks applied exactly; no code remains prose-only.
- [x] Historical stale assumptions and negative evidence preserved with explicit rejection reasons.
- [x] Wave2/Wave3 artifacts remain non-authoritative.
- [x] Open questions closed to source-ready descriptive inference or exact confidence cap.
- [x] One scoped validator per changed ordinary page run under one-file lease discipline.
- [x] Final waited UID0001PM validation run after all ordinary leases clear.
- [x] Generated HumanImageLib.cpp uniqueness/order/no-duplicate assertions pass.
- [x] Exact manual supervisor-owned coverage rows remain unapplied by B001 and handed off verbatim.
- [x] Exact UID0003M0, UID0004DK, UID0004DL, and UID00036H manual additions remain unapplied by B001 and preserved as the literal supervisor-owned handoff above.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] Every accepted D1-D14 detail incorporated at report-level factual depth.
- [x] Every C1PM ledger row converted from `proposed` to a legal terminal callback state with claim-specific proof.
- [x] All metadata/score/owner/emitter/source/compiler/C++ changes applied or excluded with exact reason.
- [x] All historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] All open questions remain resolved after destination re-read.
- [x] Every changed ordinary page scoped-validated and command/timestamp/exit/ok/warnings recorded.
- [x] Every lease released immediately after scoped validation.
- [x] Final waited generated refresh and readback completed.
- [x] Exact changed-file hashes, sizes, lines, formals, generated header/hash/counts, and zero-lease proof recorded.
- [x] Manual coverage remained unedited by B001; exact handoff preserved for supervisor.
- [x] No B001 execute/probe/lifecycle/move/archive action occurred.

Checklist readback: 39 checked, 0 unchecked.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000015957","destination_path":"executed-b-agent-research/B001/0001PM-g_pHumanImageLib-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001PM-g_pHumanImageLib-source-quality.md","timestamp":"2026-07-21T15:20:28-04:00","uid":"0001PM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
