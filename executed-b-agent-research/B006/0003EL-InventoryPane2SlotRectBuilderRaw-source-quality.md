# 0003EL InventoryPane2 Slot Rectangle Builder Raw Source-Quality Research
** TARGET-REPORT-UID:0003EL **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

Project context: this report supports local preservation and behaviorally faithful source reconstruction of the unsupported NexusTK client.

## Finalized Report / Current Recommendation

- [UID:0003EL] is now `92/94` with `CANONICAL_OWNER:00006S`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006S`, and source position `310` preserved.
- The accepted ordinary callback retained `InventoryPane2::GetSlotRect`, corrected the logical slot parameter from `int` to `short`, and replaced the mixed `InitRectBounds`/`RectBounds::SetLTRB` draft with a single final `InitRectBounds` call after all paths converge.
- The raw body is a retained source-authored member helper whose direct calls were optimized away. The live `InventoryPane2::HitTestSlot` body inlines the complete list/grid/invalid geometry and is reached at three mouse-handler call sites.
- The target H channel remains blank because [UID:00006S] owns the complete class declaration, now containing `void GetSlotRect(short slot, RectBounds *rect) const;`. The target CPP intentionally retains local output name `bounds`, as does the legacy UID00006R declaration.
- The same ABI/call-shape correction is applied to the byte-family legacy helper [UID:00051B] and its [UID:00006R] declaration. This is a directly evidenced support correction, not an additional report-coverage claim.
- Supervisor Gate 2B applied and durably saved exactly one deterministic repeatable address comment at raw entry `0x004ef720`; the raw item was not defined, renamed, or typed.
- Ordinary documentation, scoped validation, generated CPP/H readback, supervisor manual coverage, and supervisor Gate 2B are complete. Report execution and archive authority remain external and supervisor-owned.

## Supporting Research

- Dated live evidence was collected on 2026-08-15 from canonical IDA MCP session `supervisor_uid0000li_i13rollback_20260815` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Public schema-1 `runtime_attestation` returned `ok:true`, `errors:[]`, listener `127.0.0.1:13337`, worker `127.0.0.1:50640`, listener PID `14320`, worker PID `12492`, and exact matching database/path. This is read-only evidence and confers no future mutation authority.
- `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, string cache ready with 2,068 entries, and `auto_analysis_ready:false`. Bounded live IDB queries succeeded, so the analysis-ready flag is context rather than an availability failure.
- Historical assignment-time target snapshot: SHA256 `01C095DFA3C7DF69C89781CB792F4D53CDF2B895E49973DDC644D499ADAD6DBA`, 5,065 bytes, 77 physical lines. Current post-callback target snapshot: SHA256 `47607646C48B492D8FF323532BDF109A78A970990D1592E0C24707A19ABC1366`, 11,886 bytes, 128 physical lines.
- Historical pre-callback generated snapshot: command `000000024453`, refreshed `2026-08-15T21:52:19-04:00`, CPP SHA256 `23EC72347D29D6D851786F11567AB6E0F99553036325B7D07DAF437897543423`, and H SHA256 `B20C6A548B70DF82BE8833C5F62FE91BB5CF92A14FDF52B5D23C5C18F818D5BB`; it has no continuing current-state authority. Dated callback receipt command `000000024539`, refreshed `2026-08-15T23:29:39-04:00`, produced CPP SHA256 `B6958B728FCDA8E466D1C9AA31833716CC8A08919346A60508673EB3A2C46164`, 23,537 bytes / 774 lines, and H SHA256 `A86BD59FBA7A2B8974E593D920F412F147BDCBB9E107367BCBE5B221B96DEE1F`, 2,412 bytes / 76 lines; it is implementation history, not continuing current-state authority. The dated `2026-08-15T23:45:44-04:00` supervisor-provided snapshot/receipt recorded UID00006S SHA256 `0998E1EB1FAF43131984B81B3E5EE0C6981A782F7BC99E738EDF79A8DD140CA4`, 32,815 bytes / 201 lines, with generated command `000000024549`: CPP SHA256 `BEEC5FB4E57A28954413395C9B35D13720C5A56A288FFA0947B33FC434AF0AF0`, 23,537 bytes / 774 lines, and H SHA256 `BCC31E654A8BA2B1DABD8249A07182498F92CDD01FB1BCAFAC93CFB866289217`, 2,410 bytes / 76 lines. That dated receipt has no continuing current-state authority. Fresh supervisor Gate readback observed semantic CPP/H agreement; authoritative generated command/hash identity is always dynamic and must come from that fresh readback rather than any frozen report snapshot.
- At assignment time the research tracker listed UID0003EL at `85/88`, reconstructable, with zero direct and zero additional reports. Tracker state is validator-owned and is not used as current lifecycle authority in this implemented artifact.
- An earlier active B001 whole-file InventoryPane report was used only as an unverified lead while present; it disappeared during the final report search, so no claim relies on its lifecycle or continued path. Current by-* pages, generated output, and fresh IDA evidence independently establish every recommendation below.

## Target

- Primary target: [UID:0003EL] `by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md`.
- Additional target UIDs: none.
- Exact body: half-open `[0x004ef720,0x004ef794)`, `0x74` / 116 bytes, 45 instruction heads.
- Assignment-time metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00006S`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006S`, position `310`.
- Assignment question: resolve the raw/no-route confidence cap, ABI, slot type, geometry helper identity, `this+0xfc`, callers/inlined equivalents, source owner/order, formal CPP/H, affected family supports, score, coverage, and safe IDA disposition.

## Current Target State

- The target now emits the accepted source with logical `short slot`; invalid/list/grid paths select edges and converge on one final free `InitRectBounds` call.
- The binary reads only the low word of the first stack slot, zero-extends it for the unsigned range test, sign-extends it for arithmetic after the test, ends in `retn 8`, and unconditionally calls free helper `InitRectBounds` once after selecting all four edges.
- The historical `int`/early-return/`SetLTRB` draft is preserved as superseded history only; current formal CPP and owner H now preserve the source ABI and observed helper call graph.
- The raw entry is code but not a modeled function. Name, type, and regular address comment remain absent; the final repeatable address comment is exactly `Retained InventoryPane2::GetSlotRect(short, RectBounds *) const source helper. Uses m_viewMode at +0xFC for nine-row list or 3x3 grid geometry; every path calls InitRectBounds. Direct calls to this raw copy are absent because live consumers inline the geometry.` Function comment channels remain not applicable.
- Zero direct raw-start xrefs are real. They no longer block source reconstruction because live modeled `InventoryPane2::HitTestSlot` independently inlines the exact geometry and has three callers from the mouse/event handler.
- Owner/emitter/source position remain correct. No split, merge, new UID, new source file, or target-owned H block was required.
- Supervisor coverage closure established exactly one corrected UID0002SV row and exactly one UID0003EL row in `by-memory/-coverage-report.md`; the existing UID00006S and UID0000KA manual rows were verified unchanged.
- The report now records an implemented ordinary callback. Execution/archive authority still comes only from its current path plus validator-owned status/history metadata.

## Executive Recommendation

- Preserve direct class ownership by [UID:00006S] `InventoryPane2` and source routing through [UID:0000KA] `InventoryPane.cpp` at child position `310`.
- Replace the target CPP body with the exact formal source in Section 22 and update the class declaration to a `short` slot argument.
- Preserve `m_viewMode` as a dword-sized integer field: zero selects list geometry and every nonzero value selects grid geometry. Keep the established `kListView`, `kGridView`, and `kCompactPageSize` source constants rather than inventing an enum-backed field.
- Apply the same corrected slot ABI and one-call `InitRectBounds` shape to the exact legacy family helper UID00051B/UID00006R.
- Raise UID0003EL to `92/94`; keep all owner/emitter/reconstructable metadata unchanged.
- Use comment-only IDA enrichment. Current evidence proves source role but does not require changing IDA's retained raw-item model.

## Supervisor Active Recheck

- The supervisor assigned UID0003EL from current `by-memory -> Not-Covered Files - Reconstructable`, at `85/88`, with zero direct/additional reports.
- The target remained unique and unleased during research. No other goal declared UID0003EL.
- Exact target, parent, class, file, adjacent helper, legacy analog, NewInventoryPane analog, generated CPP/H, manual coverage, tracker, and matching-report evidence were re-read.
- Every identified target blocker has an evidence-backed resolution: raw body role, liveness, signature, field semantics, callee identity, source shape, CPP/H placement, score, support propagation, and IDA disposition.
- The exact pre-callback artifact passed supervisor Gate 1, and B006 completed the accepted ordinary callback without IDA, manual coverage, generated-file, or lifecycle mutation. The supervisor subsequently passed manual coverage closure and Gate 2B with exact durable-save/readback evidence recorded below; execution/archive authority remains external to this report body.

## Inference Research Guidance Check

- Direct facts are addresses, bytes, hashes, instruction heads, item/function state, xrefs, call targets, field offsets, ABI cleanup, generated text, metadata, and documented ranges.
- `GetSlotRect`, `slot`, `bounds`, and `m_viewMode` are source-facing inferences, not recovered symbols. They are selected from behavior, existing class vocabulary, neighboring `GetButtonRect`/`HitTestSlot`, and multiple independent slot-rectangle families.
- The source reconstruction prioritizes exact execution first, human developer source shape second, and project style consistency third. It does not retain raw names such as `sub_4B7C50` or decompiler temporaries.
- Existing assumptions were rechecked rather than copied. The current `int`/`SetLTRB` draft is explicitly rejected where binary evidence contradicts it.
- No stale Wave2/Wave3 evidence was used. Any such historical language is non-authoritative under the current skill.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Resolution |
| --- | --- | --- |
| Is the raw body source-authored? | Complete prologue/body/epilogue, `retn 8`, one ordinary geometry call, clean CC fences, unique signature, exact legacy family body, and live inlined consumer geometry. | Yes: retained private member helper, not padding or compiler glue. |
| Does zero start-xref mean dead/unreconstructable? | Target has zero direct xrefs/pointers/branches, but live UID0003EO repeats all list/grid/invalid stages and is called three times by UID0002SU mouse handling. | No. Calls to the retained copy were optimized away; its source contract remains recoverable. |
| Calling convention? | ECX supplies receiver; two four-byte stack slots are cleaned by `retn 8`; second slot is the `RectBounds *`. | Nonstatic const `__thiscall` member at binary level. |
| Logical slot type? | `[ebp+8]` is read only as a 16-bit word, zero-extended for `>8`, then sign-extended for division/multiplication. NewInventoryPane analog `0x004ee0a0` is currently typed with `__int16`; SelfLook slot helpers also use `short`. | `short slot`, with `static_cast<unsigned short>(slot) >= 9` preserving the combined negative/high rejection. Current `int` is rejected. |
| Geometry helper identity? | The sole call is `0x004b7c50`, currently typed `void __cdecl InitRectBounds(RectBounds *, int, int, int, int)`. `RectBounds::SetLTRB` is a distinct real member at `0x004b78d0`. | Every path must converge on one `InitRectBounds` call. Current valid-path `SetLTRB` calls are rejected. |
| `this+0xfc` meaning/type? | Target and UID0003EO test the dword at `+0xfc`; constructor and mouse paths use zero/list and one/grid semantics; class layout fixes the offset. | Keep `int m_viewMode`; zero list, nonzero grid. Do not invent a typed enum field. |
| Constant names? | Current file uses `kCompactPageSize`, `kListView`, and `kGridView` consistently. Class prose's isolated `kInventoryViewList` spelling conflicts with emitted/current source. | Keep current shared constants and correct stale prose to the same spelling. |
| Method name/access/constness? | Neighbor family names `GetButtonRect`, `HitTestButton`, `HitTestSlot`; target writes only caller output and never writes receiver state; no vtable route. | Private nonvirtual `void InventoryPane2::GetSlotRect(short, RectBounds *) const`. |
| Exact source order? | Physical helper order is GetButtonRect, target, HitTestButton, HitTestSlot, VisibleOrdinalToInventorySlot; current child positions are 300/310/320/330/340. | Keep UID0003EL at position 310 in InventoryPane.cpp. |
| Legacy family effect? | UID00051B has the same 116-byte template, low-word slot ABI, one final `InitRectBounds` call, and zero start xrefs, differing only in limits/geometry constants. | Correct legacy formal CPP and UID00006R H declaration in the same callback; do not claim extra report coverage. |
| IDA function creation? | Exact body boundaries are strong, but current project practice preserves no-route retained copies as raw items and no target-specific mutation/readback cycle is necessary for source closure. | Add exact repeatable address comment only; no function/name/type/frame action. |

Rejected alternatives:

- Keep `int slot`: rejected because the binary ignores the high 16 bits and the nearest modeled slot-rectangle analog has `__int16`.
- Use `unsigned short slot`: weaker than `short` because arithmetic is explicitly sign-extended after the unsigned guard and related source-facing slot APIs use `short` with `-1` conventions.
- Use `RectBounds::SetLTRB`: rejected because the binary calls the distinct free helper `InitRectBounds` on every path.
- Require `m_viewMode == kGridView`: rejected because any nonzero dword selects grid behavior in the binary.
- Leave code unchanged because values match for slots `0..8`: rejected because exact ABI and helper-call behavior are project goals.
- Create a separate source file/header or attach to RectBounds: rejected by receiver field, physical InventoryPane2 helper island, class route, and existing file order.

## Evidence Standards Used

- Direct binary evidence: current public MCP runtime attestation, health, items, functions, bytes, disassembly, function analyses, xrefs, comments, byte-pattern searches, and wildcarded range signature.
- Independent local executable evidence: PE section mapping (`.text` RVA `0x1000`, raw base `0x400`) and a bounded direct-branch scan over `.text`.
- Direct documentation evidence: current target/parent/class/file/sibling/geometry pages, generated CPP/H, manual coverage, research tracker, and current goal.
- Corroborating evidence: exact legacy raw family, modeled NewInventoryPane short-argument geometry helper, and live InventoryPane2 HitTestSlot inlining.
- Negative evidence: no function, symbol, direct start xref, VA/RVA/raw-offset pointer, or external direct branch to the retained body.
- Evidence is strong enough for `92/94`: behavior, ABI, owner, source placement, and code shape are independently corroborated. Missing original symbols/direct retained-copy calls keep the target below 95.

## Evidence Checked

### Live IDA MCP

- `idb_list`, `runtime_attestation`, and `server_health` for exact canonical session/path/process identity.
- `get_bytes` for `[0x004ef702,0x004ef720)`, target `[0x004ef720,0x004ef794)`, successor padding `[0x004ef794,0x004ef7a0)`, legacy `[0x004eb140,0x004eb1b4)`, and adjacent raw hit-test body.
- `inspect_items` at `0x004ef718`, `0x004ef720`, `0x004ef721`, `0x004ef786`, `0x004ef791`, `0x004ef794`, and `0x004ef7a0`.
- `lookup_funcs` across target boundaries and surrounding modeled helpers; target and adjacent raw starts are not functions.
- `insn_query` for all 45 target instructions and all 45 legacy instructions.
- `xref_query` to/from target, target call site, padding, and legacy start.
- `get_comments` at target, padding, and legacy boundaries.
- `analyze_function` for target failure state, UID0003EO `0x004ef890`, mouse handler `0x004eeee0`, paint `0x004ee6f0`, legacy UID0003EO analog `0x004eb2b0`, NewInventoryPane analog `0x004ee0a0`, `InitRectBounds`, and `PointInRect`.
- `find_bytes` for target full prefix, list core, grid core, target VA `20 F7 4E 00`, RVA `20 F7 0E 00`, and raw offset `20 EB 0E 00`.
- `make_signature_for_range` for `[0x004ef720,0x004ef794)`; result is unique in the current IDB.

### Documents and artifacts

- Primary target, UID0002SV parent, UID00006S class, UID0000KA file, UID0003EO live inline consumer, UID00051B legacy family, UID00006R legacy class, RectBounds/RectGeometryHelpers, and NewInventoryPane support.
- Current generated InventoryPane.cpp/.h and their command metadata.
- Current by-memory, by-class, and by-file manual coverage rows.
- Current research tracker row and current B-agent goals/report searches.
- Matching historical reports were searched by UID, address, target name, `GetSlotRect`, and source-family terms. No executed direct UID0003EL report exists.

### Negative and unavailable checks

- No original PDB/source repository or lexical symbol survives.
- The target cannot be decompiled because IDA has no function object at the raw entry.
- VA, RVA, and raw-offset pointer searches each returned zero; the independent `.text` scan found zero external direct branch targets into the body.
- No mutation, validator, lifecycle command, or fallback-only report completion was used.

## Claim And Incorporation Ledger

This reconciled implemented-callback ledger contains 46 claims: 45 ordinary, coverage, IDA, and verification rows are applied, already present, or excluded with reason, while only C3EL-046 remains proposed under exclusive supervisor lifecycle authority. The checklist remains the exact eight-field twin.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3EL-001 | 0003EL | Preserve exact body `[0x004ef720,0x004ef794)`, 116 bytes, 45 instruction heads, SHA256 `BCB9123318AD0FC11AFA976059BAEAB5D0D1433AE892F5E5203BD57A18E8EF3D`. | Certain | MCP bytes/insn query; local hash. | UID0003EL Exact Binary Identity | incorporate | applied |
| C3EL-002 | 0003EL | Preserve predecessor table/padding `[0x004ef702,0x004ef720)`, 30 bytes, SHA256 `B208FB2A4D2C468D15945CDF9B3D1A18F4381B10CDB5B6302CB47B365F4763F8`. | Certain | MCP bytes/items. | UID0003EL Boundaries; UID0002SV | incorporate | applied |
| C3EL-003 | 0003EL | Preserve successor CC padding `[0x004ef794,0x004ef7a0)`, 12 bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`. | Certain | MCP bytes/items. | UID0003EL Boundaries; UID0002SV | incorporate | applied |
| C3EL-004 | 0003EL | Record ECX receiver, two stack slots, and `retn 8` as nonstatic member ABI. | Certain | Complete target disassembly. | UID0003EL ABI | incorporate | applied |
| C3EL-005 | 0003EL | Use logical `short slot`; preserve unsigned low-word range guard before signed arithmetic. | Very strong | `mov dx`/`movzx`/`movsx`; modeled short analog. | UID0003EL Signature/formal CPP; UID00006S H | incorporate | applied |
| C3EL-006 | 0003EL | Invalid logical indices produce `(-1,-1,-1,-1)`. | Certain | Target branches/instructions. | UID0003EL Behavior/formal CPP | incorporate | applied |
| C3EL-007 | 0003EL | List mode maps slots 0..8 to `(2, 23+23*slot, 160, 46+23*slot)`. | Certain | Target list instruction sequence. | UID0003EL Behavior/formal CPP | incorporate | applied |
| C3EL-008 | 0003EL | Nonzero/grid mode maps 3x3 slots with 51-pixel pitch to `(9+51*column,18+51*row,57+51*column,66+51*row)`. | Certain | Target grid instruction sequence. | UID0003EL Behavior/formal CPP | incorporate | applied |
| C3EL-009 | 0003EL | All paths converge on exactly one free `InitRectBounds` call at `0x004ef786`. | Certain | Target disassembly/xref to `0x004b7c50`. | UID0003EL Call Shape/formal CPP | incorporate | applied |
| C3EL-010 | 0003EL | Reject valid-path `RectBounds::SetLTRB`; it is a distinct real method not called by the target. | Certain | `0x004b78d0` vs target call target. | UID0003EL stale-source correction | reject-stale | applied |
| C3EL-011 | 0003EL | Keep `int m_viewMode` at `+0xfc`; zero is list and any nonzero is grid. | Very strong | Target, UID0003EO, constructor/mouse evidence. | UID0003EL Fields; UID00006S | incorporate | applied |
| C3EL-012 | 0003EL | Method is const with no receiver writes; only caller-provided bounds are written. | Certain | Full instruction/touched-state audit. | UID0003EL Signature/Touched State | incorporate | applied |
| C3EL-013 | 0003EL | Retain human source name `InventoryPane2::GetSlotRect`. | Very strong | Neighbor names, role, class/file family. | UID0003EL title/status/formal CPP | already-present | already-present |
| C3EL-014 | 0003EL | Preserve zero inbound xrefs at raw start as liveness evidence, not a source-emission blocker. | Certain | Current `xref_query`. | UID0003EL Negative Evidence/Score | incorporate | applied |
| C3EL-015 | 0003EL | Preserve zero VA/RVA/raw-offset pointer hits and zero external direct branches into the body. | Certain | MCP `find_bytes`; independent `.text` scan. | UID0003EL Negative Evidence | incorporate | applied |
| C3EL-016 | 0003EL | Record the current wildcarded target range signature as unique. | Certain | `make_signature_for_range`. | UID0003EL Exact Binary Identity | incorporate | applied |
| C3EL-017 | 00051B | Record the legacy 116-byte low-word/one-call raw helper as the closest source-family analog. | Certain | Fresh legacy bytes/insns/xrefs. | UID0003EL Family Evidence; UID00051B | incorporate | applied |
| C3EL-018 | 0003EL | Record modeled NewInventoryPane `0x004ee0a0` as an independent `__int16` slot-rectangle analog with shared 3x3 geometry. | Very strong | Current analyze_function. | UID0003EL Type/Family Evidence | incorporate | applied |
| C3EL-019 | 0003EO | Record complete target geometry inlined in live HitTestSlot and callers `{0x004ef09a,0x004ef165,0x004ef1a4}`. | Certain | Current UID0003EO decompile/xrefs. | UID0003EL Liveness; UID0003EO Evidence | incorporate | applied |
| C3EL-020 | 0003EL | Record paint/mouse paths as behavior consumers while distinguishing them from direct calls to the retained raw copy. | Very strong | UID0002SU analyses and generated/current source. | UID0003EL Relationships; UID0000KA | incorporate | applied |
| C3EL-021 | 0003EL | Keep canonical owner/emitter UID00006S InventoryPane2. | Certain | Receiver offset, physical island, class map. | UID0003EL metadata/Ownership | already-present | already-present |
| C3EL-022 | 0003EL | Keep UID0000KA InventoryPane.cpp placement at position 310 between GetButtonRect and HitTestButton. | Certain | Physical/source order and emitter route. | UID0003EL Source Placement; UID0000KA | already-present | already-present |
| C3EL-023 | 0003EL | No split, merge, new UID, new source file, or target-owned header is required. | Certain | Exact boundaries/current source tree. | UID0003EL Range/Source Placement | not-applicable | excluded-with-reason |
| C3EL-024 | 0003EL | Replace target CPP with the exact short-slot/single-InitRectBounds formal block. | Very strong | Exact behavior/ABI/call shape. | UID0003EL RECONSTRUCTION_CPP CODE | incorporate | applied |
| C3EL-025 | 00006S | Keep target H blank and use owner declaration `void GetSlotRect(short slot, RectBounds *rect) const;`; target CPP local `bounds` and legacy UID00006R `bounds` remain unchanged. | Very strong | Current UID00006S identity and dynamic generated-H readback distinguish owner-H `rect` from target/legacy `bounds`. | UID0003EL H; UID00006S RECONSTRUCTION_H CODE | incorporate | applied |
| C3EL-026 | 0003EL | Raise score from 85/88 to 92/94; keep owner/emitter/reconstructable/position. | Strong | All source blockers resolved; lexical/direct-route cap remains. | UID0003EL metadata/Score Rationale | incorporate | applied |
| C3EL-027 | 0003EL | Populate Item Summary with exact behavior/source-quality disposition without duplicating generated metadata. | Certain | Current blank summary and generated-report rules. | UID0003EL Item Summary | incorporate | applied |
| C3EL-028 | 0002SV | Update child row/evidence to current 116-byte identity, short ABI, one-call shape, inline liveness, and 92/94 target state. | Very strong | Current target and parent split. | UID0002SV child inventory/evidence | incorporate | applied |
| C3EL-029 | 00006S | Update method row, owner signature with output name `rect`, constants prose, target evidence, and history; retain 94/94 while target CPP local remains `bounds`. | Very strong | Current UID00006S SHA256 `0998E1EB1FAF43131984B81B3E5EE0C6981A782F7BC99E738EDF79A8DD140CA4`, 32,815 bytes / 201 lines, plus dynamic generated-H readback. | UID00006S H/Method Map/Evidence | incorporate | applied |
| C3EL-030 | 0000KA | Update A25/file evidence, source-order text, generated expectations, and history; retain 94/94. | Very strong | Complete file route and dynamically read generated semantics. | UID0000KA InventoryPane2 sections | incorporate | applied |
| C3EL-031 | 0003EO | Clarify that binary inlines geometry while formal human source may call GetSlotRect; retain 85/91 and current CPP. | Very strong | Live decompile and plausible source factoring. | UID0003EO Behavior/IDA Evidence/Changes | incorporate | applied |
| C3EL-032 | 00051B | Replace legacy CPP with short-slot/single-InitRectBounds block; retain 90/92 and route. | Very strong | Fresh exact legacy body. | UID00051B RECONSTRUCTION_CPP CODE/Signature | incorporate | applied |
| C3EL-033 | 00006R | Replace legacy class declaration with short slot and update family evidence; retain 93/94. | Very strong | UID00051B ABI and class ownership. | UID00006R RECONSTRUCTION_H CODE/Evidence | incorporate | applied |
| C3EL-034 | 00015S | Keep canonical `InitRectBounds(RectBounds *,int,int,int,int)` helper ownership/signature unchanged. | Certain | Current IDA type/body and support docs. | UID00015S verify-only | already-present | already-present |
| C3EL-035 | 0003EL | Expected generated CPP has one corrected UID0003EL definition and one corrected UID00051B definition, with no valid-path SetLTRB call. | Certain | Formal emitter route. | Generated InventoryPane.cpp readback checklist | incorporate | applied |
| C3EL-036 | 00006S | Generated H inventory must contain exactly one legacy `GetSlotRect(short slot, RectBounds *bounds) const;` and exactly one InventoryPane2 `GetSlotRect(short slot, RectBounds *rect) const;`. | Certain | Dated `2026-08-15T23:45:44-04:00` command `000000024549` H receipt with no continuing authority; fresh supervisor Gate readback observed semantic agreement, while generated command/hash identity remains dynamic. | Generated InventoryPane.h readback checklist | incorporate | applied |
| C3EL-037 | 0002SV | Replace stale by-memory manual parent row with current 89% non-reconstructable split-container text. | Certain | Supervisor coverage command `000000024588` verified exactly one corrected UID0002SV row; coverage SHA256 `76B9038A30DC8191BC0D5945D58FBF9D21964C83F751E54B560738B4EF4F1982`. | by-memory/-coverage-report.md | incorporate | applied |
| C3EL-038 | 0003EL | Insert exact 92% very-strong target row under UID0002SV in address order. | Certain | Supervisor coverage command `000000024588` verified exactly one UID0003EL row; exit `0`, `ok: 1`. | by-memory/-coverage-report.md | incorporate | applied |
| C3EL-039 | 00006S | Keep current by-class InventoryPane2 and by-file InventoryPane manual rows unchanged. | Certain | Supervisor coverage closure verified the existing 94% class/file rows required no write. | by-class/by-file coverage verify-only | already-present | already-present |
| C3EL-040 | 0003EL | Supervisor replaced the exact former AP with A01's accepted AP at `0x004ef720`; final AP is exactly `Retained InventoryPane2::GetSlotRect(short, RectBounds *) const source helper. Uses m_viewMode at +0xFC for nine-row list or 3x3 grid geometry; every path calls InitRectBounds. Direct calls to this raw copy are absent because live consumers inline the geometry.` | Very strong | Dated attested Gate 2B session `supervisor_uid0003d9_rollback_20260815`; exact post-save AP readback and `GATE2B_PASSED`. | Supervisor Gate 2B IDA A01 | incorporate | applied |
| C3EL-041 | 0003EL | Supervisor verified A01 as the sole delta, preserved raw/function/name/type/xref/byte/boundary state and all three protected hashes, saved once, and passed fresh post-save health/readback. | Certain | Exact backup SHA256 `5C50BAB9C97BB1C2D8AAE27F132E6E18CB68C9F3EFCB7EBF21FE61E95A514024`; saved canonical SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`. | Supervisor Gate 2B protected state/save readback | not-applicable | applied |
| C3EL-042 | 0003EL | Keep source constants `kCompactPageSize`, `kListView`, and `kGridView`; remove isolated `kInventoryViewList` prose drift. | Strong | Current file-wide emitted naming. | UID0003EL/UID00006S/UID0000KA naming | incorporate | applied |
| C3EL-043 | 00006S | Do not convert m_viewMode to an enum-backed field; preserve dword-sized int and exact nonzero behavior. | Very strong | Current binary comparisons/assignments. | UID00006S layout/type rationale | already-present | already-present |
| C3EL-044 | 0003EL | State exact original lexical names remain unavailable, but best-supported human names are final enough for source and do not justify raw labels. | Strong | No PDB/symbol; family consistency. | UID0003EL inference/score/open questions | incorporate | applied |
| C3EL-045 | 0003EL | After callback, scoped-validate every changed ordinary page, then validate owning file with generated wait and physically reread InventoryPane.cpp/.h. | Certain | Workflow and emitter route. | Validator/generated checklist | incorporate | applied |
| C3EL-046 | 0003EL | Supervisor coverage and Gate 2B are complete; report execution and archive movement remain exclusively supervisor-owned and authoritative only from current path plus validator-owned metadata. | Certain | Coverage and Gate 2B closure receipts in this report; skill lifecycle boundaries. | Coverage/IDA/lifecycle checklist | incorporate | proposed |

## Positive Evidence Summary

- The target is a complete 116-byte member-shaped routine with clean boundaries, ordinary stack cleanup, exact output semantics, and a unique current signature.
- The closest legacy family helper has the same byte template, same low-word slot ABI, same `this+0xfc` branch, same one-call output shape, and the same zero-start-xref condition.
- NewInventoryPane's modeled rectangle helper independently uses a `__int16` logical slot and the same 3x3 51-pixel geometry.
- Live UID0003EO inlines the complete target algorithm and is reached from three event-handler call sites, resolving liveness/source-existence despite the retained copy's zero direct routes.
- Existing class/file ownership, method order, generated emitter route, and field layout all converge on InventoryPane2/InventoryPane.cpp.

## IDA MCP Facts

- Target `[0x004ef720,0x004ef794)`: 116 bytes, 45 instruction heads, SHA256 `BCB9123318AD0FC11AFA976059BAEAB5D0D1433AE892F5E5203BD57A18E8EF3D`.
- Post-save entry item `[0x004ef720,0x004ef721)`: code, size 1, byte `55`, name absent, type absent, AR absent, AP exactly `Retained InventoryPane2::GetSlotRect(short, RectBounds *) const source helper. Uses m_viewMode at +0xFC for nine-row list or 3x3 grid geometry; every path calls InitRectBounds. Direct calls to this raw copy are absent because live consumers inline the geometry.`; no function, so FR/FP are not applicable.
- Target start inbound xrefs: `0/{}`. Entry outgoing xrefs: `1/{0x004ef721 code}`.
- The sole nonlocal target call is `0x004ef786 -> 0x004b7c50 InitRectBounds`.
- Predecessor `[0x004ef702,0x004ef720)` is switch-table/data plus eight CC bytes; successor `[0x004ef794,0x004ef7a0)` is twelve CC bytes.
- Target wildcard signature is unique. Target prefix and list core are unique; the grid core also occurs in NewInventoryPane at `0x004ee10a`.
- `find_bytes` returned zero for target VA, RVA, and raw-offset encodings. Independent `.text` scan returned zero external direct branches into the target range.
- UID0003EO `sub_4EF890` is size `0xd2`, currently typed `unsigned __int16 __thiscall(_DWORD *this,int row,int column)`, inlines target geometry, calls `InitRectBounds` and `PointInRect`, and has call sites `0x004ef09a`, `0x004ef165`, `0x004ef1a4`.
- `InitRectBounds` is exactly `void __cdecl(RectBounds *bounds,int left,int top,int right,int bottom)`, size `0x1f`; `PointInRect` is exactly `bool __cdecl(int y,int x,const RectBounds *bounds)`, size `0x27`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004ef702,0x004ef720)` | UID0003EK | GetButtonRect switch table plus padding | false | none | 100/100 | compiler/data support; unchanged |
| `[0x004ef720,0x004ef794)` | UID0003EL / target | retained InventoryPane2 GetSlotRect body | true | UID00006S | 85/88 -> 92/94 | source correction required |
| `[0x004ef794,0x004ef7a0)` | covered in UID0002SV | CC alignment | false | none | n/a | padding; unchanged |
| `[0x004ef7a0,0x004ef86d)` | UID0003EM | retained raw InventoryPane2 HitTestButton | true | UID00006S | current | adjacent source helper; unchanged |
| `[0x004ef86d,0x004ef890)` | UID0003EN | switch table plus padding | false | none | current | compiler/data support; unchanged |
| `[0x004ef890,0x004ef962)` | UID0003EO | live InventoryPane2 HitTestSlot with inlined target geometry | true | UID00006S | 85/91 | prose support update; CPP retained |
| `[0x004eb140,0x004eb1b4)` | UID00051B | retained legacy InventoryPane GetSlotRect analog | true | UID00006R | 90/92 | directly evidenced ABI/call-shape support correction |
| `0x004ee0a0` modeled function | by-file NewInventoryPane support | short-slot rectangle analog with shared grid constants | true | NewInventoryPane family | 82 file score | evidence only; no direct change under this report |
| `0x004b7c50` | UID00015S support | free InitRectBounds helper | true | UID0000BU/UID0000N2 route | 92/93 aggregate | verified unchanged |

- Inventory count: one primary source-bearing target, two direct source-family corroborators, one live inlined consumer, two adjacent compiler/data ranges, one adjacent raw helper, and one shared geometry dependency. Every row has an explicit source/no-code/support disposition.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ef720` | inbound `0/{}` | retained raw copy has no direct route |
| `0x004ef720` | outgoing `0x004ef721` internal code flow | entry item continues into body |
| `0x004ef786` | callee `InitRectBounds` | all selected edges are written by one free helper call |
| `0x004ef794` | inbound `0/{}` | padding boundary is not an entry |
| UID0003EO | callers `0x004ef09a`, `0x004ef165`, `0x004ef1a4` | live event paths consume the inlined geometry contract |
| UID0003EO | callees `InitRectBounds`, `PointInRect`, security cookie | exact hit-test stage map |
| `0x004eb140` legacy | inbound `0/{}` | same retained-copy optimization pattern |
| `0x004ee0a0` NewInventoryPane | no external caller in current model; internally typed `__int16` | independent type/geometry corroboration, not target liveness |

## Documentation Evidence And IDA Status

- UID0003EL now records exact owner, range, formulas, source position, short ABI, one-call helper shape, corrected formal CPP, and `92/94` score rationale.
- UID00006S retains `m_viewMode` at `+0xfc`, target position 310, dword-sized integer/nonzero semantics, normalized `kListView`/`kGridView` prose, and the exact accepted owner-H declaration `void GetSlotRect(short slot, RectBounds *rect) const;`. The target CPP local and legacy UID00006R declaration retain `bounds`.
- UID0003EO now distinguishes complete binary inlining from the cleaner source-level `GetSlotRect` call retained in its formal CPP.
- UID00051B/UID00006R now carry the same evidenced low-word ABI and one-final-free-helper correction as the target family.
- UID0002SV remains a correct `89/92` non-emitting split container and now carries the target's exact identity, ABI, call shape, inlined liveness, and score. Supervisor coverage closure verified its corrected manual row and the new UID0003EL row.
- Validator-generated InventoryPane.cpp/.h now reflect the accepted source corrections; generated files remain validator-owned and were only physically reread.
- Supervisor Gate 2B applied the one accepted semantic AP comment, durably saved it, and verified the complete protected poststate. The target remains intentionally not modeled as a function.

## Ranked Ownership Analysis

### 1. UID00006S InventoryPane2

- Evidence for: ECX receiver, `+0xfc` class field, exact physical helper island, neighboring methods, identical live UID0003EO inlining, class method map, and current emitter route.
- Evidence against: no direct xref or original symbol reaches the retained copy.
- Decision: certain direct class owner and emitter.

### 2. UID0000KA InventoryPane.cpp

- Evidence for: both InventoryPane families, physical/source order, current class child route, and generated module placement.
- Evidence against: broader compilation-unit owner rather than direct semantic owner.
- Decision: final source file through UID00006S at position 310.

### 3. UID00015S RectGeometryHelpers / UID0000BU RectBounds

- Evidence for: owns `InitRectBounds`, `RectBounds`, and related geometry vocabulary.
- Evidence against: target reads InventoryPane2 state and selects inventory-specific slot geometry; geometry helper merely receives edges.
- Decision: dependency only, rejected as target owner.

### 4. NewInventoryPane or a new standalone file

- Evidence for: NewInventoryPane has a short-slot rectangle analog with shared grid constants.
- Evidence against: different receiver layout/list limits and separate source family; target is embedded in the InventoryPane2 physical run.
- Decision: evidence analog only; reject source ownership and reject new grouping.

## Source Placement

- CPP definition: UID0003EL, emitted through UID00006S into `NexusTK/ui/inventory/InventoryPane.cpp` at position 310.
- H declaration: replace the one private declaration in UID00006S's complete class H block; target H stays blank.
- Physical/source order remains GetButtonRect 300, GetSlotRect 310, HitTestButton 320, HitTestSlot 330, VisibleOrdinalToInventorySlot 340.
- Legacy support correction remains in the same InventoryPane.cpp unit at UID00051B position 100 and UID00006R H declaration.
- RectBounds.cpp, NewInventoryPane.cpp, a new helper file, and a target-owned header are rejected.

## Range / Split / Padding / Reclassification Analysis

- Exact source body is `[0x004ef720,0x004ef794)`. The `retn 8` instruction begins at `0x004ef791` and ends exactly at `0x004ef794`.
- `[0x004ef702,0x004ef718)` is the prior GetButtonRect switch table; `[0x004ef718,0x004ef720)` is eight-byte CC alignment.
- `[0x004ef794,0x004ef7a0)` is twelve-byte CC alignment before UID0003EM.
- No interior xref, alternate entry, embedded data, exception tail, or shared byte exists in the target body.
- No split/merge/reclassification is needed. The page remains a reconstructable raw retained source helper; only source-quality and score change.
- Parent UID0002SV remains non-reconstructable/non-emitting because it mixes authored children, compiler tables, padding, adjustor thunks, and destructor support.

## Negative Evidence Summary

- No modeled target function, decompilation, original symbol, direct call/jump/data xref, vtable cell, VA pointer, RVA pointer, raw-offset pointer, or external direct branch reaches the target.
- No source artifact proves the exact original spellings `GetSlotRect`, `slot`, `bounds`, `m_viewMode`, or constants.
- No evidence supports an enum-backed `m_viewMode`, explicit `kGridView` equality test, `int` slot ABI, or valid-path SetLTRB calls.
- No evidence supports a separate source file/header or RectBounds ownership.
- These negatives cap score below 95 and constrain IDA mutation. They do not block the best-supported human source because behavior, ABI, owner, source order, and inlined use are independently recovered.

## IDA Rename / Type / Comment Recommendations

This is the accepted structured, non-executable supervisor handoff preserved as pre-action history. `AR` means regular address comment, `AP` repeatable address comment, `FR` regular function comment, and `FP` repeatable function comment. The supervisor used a fresh public schema-1 runtime attestation before Gate 2B; the exact dated session below is evidence only and confers no future authority.

| Action ID | Classification | Entity and complete literal prestate | Exact public endpoint delta and complete expected poststate | Evidence and hard safety constraints |
| --- | --- | --- | --- | --- |
| A01 | apply | Raw code item `[0x004ef720,0x004ef721)`, size `1`, byte `55`, name absent, type absent, AR absent, AP exactly `Source-authored InventoryPane2 slot-rectangle builder retained as raw code; list mode maps nine rows and grid mode maps 3x3 slots.`, FR not applicable, FP not applicable; no function; inbound xref count/set `0/{}`; outgoing xref count/set `1/{0x004ef721 code}`. Enclosing body `[0x004ef720,0x004ef794)`, 116 bytes, SHA256 `BCB9123318AD0FC11AFA976059BAEAB5D0D1433AE892F5E5203BD57A18E8EF3D`; predecessor `[0x004ef702,0x004ef720)` and successor `[0x004ef794,0x004ef7a0)` have the exact hashes in C3EL-002/003. | Existing-to-proposed branch: only when fresh readback matches that complete prestate, call public `set_address_repeatable_comments(database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004ef720",comment:"Retained InventoryPane2::GetSlotRect(short, RectBounds *) const source helper. Uses m_viewMode at +0xFC for nine-row list or 3x3 grid geometry; every path calls InitRectBounds. Direct calls to this raw copy are absent because live consumers inline the geometry."})`. Already-present/no-write branch: if fresh readback instead has that exact proposed AP and every other complete prestate field matches, issue no mutation and proceed directly to full readback. Complete terminal poststate for either branch: all item/body/padding/name/type/function/xref/byte/range/hash facts remain exact; AR absent; AP equals the proposed literal; FR/FP remain not applicable. | Only AP may differ between the exact existing and proposed literals. Stop on any third AP value, any other prestate mismatch, endpoint failure, new function/name/type, byte/range/xref drift, or any other comment-channel delta. The mutation branch requires durable save and saved-state readback; the no-write branch requires no save. |

Protected no-change state:

- P01 passed: the target remains raw code rather than a function; no function creation, rename, `set_type`, frame action, UDT action, byte patch, or boundary change occurred. The supervisor took the exact existing-to-proposed A01 branch, durably saved only the accepted AP delta, and verified the complete saved poststate.
- P02 passed: all 116 target bytes, 45 instruction heads, predecessor table/padding, successor padding, and their exact hashes were preserved.
- P03 passed: all xref sets, UID0003EO function/type/frame/comments, shared helper identities, and InventoryPane class/type state were preserved.
- P04 passed: no IDA action was applied to the legacy analog or NewInventoryPane analog under this report.
- P05: report text does not contain an operational transaction, rollback program, process command, or lifecycle command.

Supervisor Gate 2B closure receipt:

- The fresh runtime was attested for dated session `supervisor_uid0003d9_rollback_20260815` and canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; session and process identities are dated evidence only.
- Backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0003EL-gate2b-20260816_001133435` was 143,207,942 bytes with SHA256 `5C50BAB9C97BB1C2D8AAE27F132E6E18CB68C9F3EFCB7EBF21FE61E95A514024`.
- A01 applied only the accepted AP replacement. Final AR is absent; final AP is exactly `Retained InventoryPane2::GetSlotRect(short, RectBounds *) const source helper. Uses m_viewMode at +0xFC for nine-row list or 3x3 grid geometry; every path calls InitRectBounds. Direct calls to this raw copy are absent because live consumers inline the geometry.`
- P01-P04 passed: the target remains an unnamed/untyped one-byte raw code head with no function at `0x004ef720` or `0x004ef793`; inbound xrefs remain `0/{}` and outgoing xrefs remain `1/{0x004ef721 code}`. Predecessor/body/successor hashes remain `B208FB2A4D2C468D15945CDF9B3D1A18F4381B10CDB5B6302CB47B365F4763F8`, `BCB9123318AD0FC11AFA976059BAEAB5D0D1433AE892F5E5203BD57A18E8EF3D`, and `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`.
- `idb_save` returned `ok:true`. Saved canonical identity was SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`, 143,208,000 bytes, last-write `2026-08-16 00:11:53 -04:00`; fresh post-save health/readback passed. Audit decision: `GATE2B_PASSED` for A01/P01-P04.

## First-Draft C++ Recommendation

- Eligible for draft/finalizing source: yes. Behavior, owner, ABI, call shape, source placement, and names are sufficiently resolved.
- Exact UID0003EL `RECONSTRUCTION_CPP CODE` replacement:

~~~cpp
void InventoryPane2::GetSlotRect(short slot, RectBounds *bounds) const
{
    int left;
    int top;
    int right;
    int bottom;

    if (static_cast<unsigned short>(slot) >= kCompactPageSize)
    {
        left = -1;
        top = -1;
        right = -1;
        bottom = -1;
    }
    else if (m_viewMode == kListView)
    {
        left = 2;
        top = 23 + 23 * slot;
        right = 160;
        bottom = 46 + 23 * slot;
    }
    else
    {
        const int row = slot / 3;
        const int column = slot % 3;
        left = 9 + 51 * column;
        top = 18 + 51 * row;
        right = 57 + 51 * column;
        bottom = 66 + 51 * row;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}
~~~

- Exact UID0003EL H disposition: keep blank. Replace only the matching line inside UID00006S's formal H class block:

~~~cpp
    void GetSlotRect(short slot, RectBounds *rect) const;
~~~

- Exact directly affected UID00051B `RECONSTRUCTION_CPP CODE` replacement:

~~~cpp
void InventoryPane::GetSlotRect(short slot, RectBounds *bounds) const
{
    int left;
    int top;
    int right;
    int bottom;

    if (static_cast<unsigned short>(slot) >= kLegacyPageSize)
    {
        left = -1;
        top = -1;
        right = -1;
        bottom = -1;
    }
    else if (m_viewMode == kListView)
    {
        left = 30;
        top = 46 + 13 * slot;
        right = 160;
        bottom = 59 + 13 * slot;
    }
    else
    {
        const int row = slot / 3;
        const int column = slot % 3;
        left = 40 + 45 * column;
        top = 40 + 41 * row;
        right = 75 + 45 * column;
        bottom = 75 + 41 * row;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}
~~~

- Replace the matching line in UID00006R's formal H class block:

~~~cpp
    void GetSlotRect(short slot, RectBounds *bounds) const;
~~~

- Runtime fidelity: the unsigned short guard rejects every negative short and every value above the page limit exactly; list/grid edge formulas are exact; every path makes the observed single `InitRectBounds` call; any nonzero view mode selects grid; output pointer null behavior remains the same unguarded dereference path.
- Human-source fidelity: descriptive class/member/local names follow the surrounding InventoryPane family, code is ordinary C++03-compatible source, and no raw address, decompiler temporary, compiler cookie, or reverse-engineering label remains.
- `SetLTRB` is intentionally absent because it would call or inline a different helper than the observed binary.
- No third-party import directive applies.

## Final Recommendation

- UID0003EL is `92/94` with unchanged owner/emitter/reconstructable/position.
- The exact target CPP and UID00006S owner-H declaration correction are applied. Command `000000024539` is a dated callback readback receipt, and command `000000024549` is a dated `2026-08-15T23:45:44-04:00` supervisor-provided snapshot/receipt with no continuing authority. Fresh supervisor Gate readback observed semantic agreement; authoritative generated command/hash identity remains dynamic.
- The exact analogous UID00051B CPP and UID00006R H correction are applied because the same fresh evidence proves the same defect.
- UID0002SV, UID00006S, UID0000KA, and UID0003EO contain the accepted report-level detail; shared geometry/NewInventoryPane supports were inspected without ownership changes.
- Supervisor applied and verified the two exact by-memory coverage edits and the one accepted IDA AP action.
- Keep zero-route/original-symbol negatives as evidence, not as a reason to leave source inaccurate or incomplete.

## Recommended Target Doc Changes

Target: `by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md`. The eight accepted target changes below are applied and scoped-validated.

1. Set `COMPLETION:92`, `CONFIDENCE:94`; keep owner `00006S`, reconstructable true, emitter `00006S`, position 310, and blank H.
2. Replace formal CPP with the exact Section 22 target block.
3. Set Item Summary to: `Retained InventoryPane2 slot-rectangle helper with exact 116-byte identity, short slot ABI, nine-row list and 3x3 grid geometry, one final InitRectBounds call, live inlined HitTestSlot consumers, class/file route, and source-ready C++.`
4. Add exact body/hash/instruction count, predecessor table/padding hash, successor padding hash, unique signature, and literal IDA item/comment/xref state.
5. Add member ABI, logical short/unsigned guard, touched-state, all four edge formulas, one-call contract, and explicit no-null-guard behavior.
6. Add UID0003EO inlined-stage liveness and three call sites; distinguish no direct retained-copy calls from source absence.
7. Add legacy/NewInventoryPane family evidence, ownership/source-order reasoning, alternatives, formal CPP/H rationale, IDA safe subset, and score rationale.
8. Historicalize current `int`/SetLTRB draft as superseded source, while preserving prior no-function/no-xref discovery as valid historical evidence.

## Recommended Support Doc Changes

- `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md`: UID0003EL child row/evidence, 116-byte identity, exact padding, short ABI, one-call contract, inlined liveness, score, and source correction are applied; parent remains `89/92`, NONE/FALSE/blank emitter.
- `by-class/InventoryPane2.md`: exact H declaration, method map, `+0xfc` semantics, `kListView`/`kGridView` spelling, short ABI/one-call shape, and UID0003EO relation are applied; `94/94` ownership/layout remain.
- `by-file/InventoryPane.md`: A25/evidence/source-order/generated expectations/history now carry corrected UID0003EL and coordinated legacy detail; file remains `94/94`.
- `by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md`: binary inlining, three callers, exact inline formulas, and the clean source-level GetSlotRect relation are applied; formal CPP and `85/91` remain.
- `by-memory/0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw.md`: exact Section 22 legacy CPP and signature/call-shape detail are applied; `90/92`, owner/emitter, range/hash, and zero-route evidence remain.
- `by-class/InventoryPane.md`: exact short/bounds H declaration and family ABI/call-shape evidence are applied; `93/94` remains.
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` and RectBounds supports: verify-only; no metadata/source change.
- `by-file/NewInventoryPane.md`: verify-only evidence analog; do not claim or apply completion for its unresolved broader file under this report.
- Generated InventoryPane.cpp/.h: never edit directly. Validate through owning by-file route and physically compare with Section 22/claims C3EL-035/036.

## Score And Metadata Recommendation

- Historical assignment-time UID0003EL: `85/88`, owner/emitter UID00006S, reconstructable true, position 310.
- Applied/current UID0003EL: `92/94`, same owner/emitter/reconstructable/position.
- Reason not higher: no original symbols, no direct route to the retained copy, and no modeled IDA function preserve lexical/liveness uncertainty. These prevent crossing the 95 final-audit barrier.
- Reason not lower: exact bytes/bounds/CFG/callee/ABI/geometry, a unique signature, two independent source-family analogs, live complete inlining with three callers, exact class field/owner/order, and source-ready CPP/H resolve every practical reconstruction blocker.
- Score-improvement work performed: exhaustive target bytes/instructions/items/comments/xrefs, VA/RVA/raw pointer search, independent external-branch scan, exact signature, helper/caller analyses, legacy/NewInventory analogs, generated-source audit, ownership/range/support/coverage review, and formal source correction.
- UID0002SV stays 89/92 and non-reconstructable; UID00006S stays 94/94; UID0000KA stays 94/94; UID0003EO stays 85/91; UID00051B stays 90/92; UID00006R stays 93/94.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best supported resolution | Remaining impact |
| --- | --- | --- | --- |
| Was the exact original name `GetSlotRect`? | No PDB; neighboring names; multiple class families; output role. | Use `GetSlotRect` as high-probability human source name. | Lexical uncertainty only; caps below 95. |
| Was slot signed or unsigned? | Low-word load, unsigned guard, signed arithmetic, modeled `__int16` analog, related short APIs. | Signed `short` plus unsigned guard is strongest. | Closed for source; original typedef spelling unavailable. |
| Was view mode an enum? | Dword storage, zero/nonzero tests, 0/1 assignments, current file constants. | Keep `int` plus constants; do not invent enum field. | Closed without behavior loss. |
| Did source call SetLTRB? | Target call resolves to free InitRectBounds; SetLTRB is a separate real function. | No. Use one final InitRectBounds call. | Closed. |
| Is retained copy dead? | Zero direct routes plus exact live inline copy/callers and retained legacy family. | Retained out-of-line source body with calls optimized away. | Closed; negative route remains confidence evidence. |
| Does target need its own header/file? | Current class/file emitter route and physical order. | No; class H declaration only, target H blank. | Closed. |

No remaining open question blocks source, owner, score, support propagation, or IDA safe-subset disposition.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following accepted supervisor-owned coverage payload was applied and verified. The corrected UID0002SV row is:

`        - [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) 0x004ef630-0x004efa95 | method/helper-group | InventoryPane2TailHelpersAndDestructor : not_reconstructable : 89% : very-strong : Final non-emitting InventoryPane2 tail split container with exact authored helper children at positions 300-340, corrected raw GetSlotRect short ABI and one-call InitRectBounds shape, live inlined HitTestSlot geometry, exact switch-table/padding boundaries, compiler adjustor/scalar exclusions, class/file routing, and no duplicate aggregate C++.`

Immediately after that parent row, the supervisor inserted:

`            - [UID:0003EL][0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw](by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md) 0x004ef720-0x004ef794 | raw helper | InventoryPane2SlotRectBuilderRaw : reconstructable : 92% : very-strong : Retained InventoryPane2::GetSlotRect(short, RectBounds *) helper with exact 116-byte identity, zero direct retained-copy routes, nine-row list and 3x3 grid formulas, one final InitRectBounds call, live inlined HitTestSlot consumers, class-owned position 310, corrected formal C++, and comment-only IDA disposition.`

- `by-class/-coverage-report.md` UID00006S already reads 94% and describes exact nine-slot geometry/class completion; no replacement is required.
- `by-file/-coverage-report.md` UID0000KA already reads 94% and describes the complete InventoryPane family; no replacement is required.
- B006 did not edit any coverage/tracker file. The supervisor applied and validated the manual coverage payload: exactly one corrected UID0002SV row and exactly one UID0003EL row are present. Validator-owned research tracker state remains external and dynamic.

## Follow-Up Actions

- B006 ordinary implementation is complete for C3EL-001..036 and C3EL-042..045, including scoped validation and exact generated CPP/H physical readback.
- Supervisor coverage and Gate 2B closure are complete for C3EL-037..041 with exact receipts recorded here. C3EL-046 remains the external supervisor-only execution/archive control row.
- No A-agent or new B-agent research is required for UID0003EL. Broader NewInventoryPane whole-file completion remains outside this target.

## Confidence

- Recommendation confidence: very strong (`94`).
- Score confidence: strong; `92/94` is justified by exact behavioral/source closure while respecting the no-symbol/no-direct-route cap.
- Remaining uncertainty: exact original lexical spelling and whether the original source used a project typedef for `short`; neither affects runtime behavior, ownership, source placement, or formal-code readiness.

## Validator Results

- Scoped validations, each exit `0` with `ok: 1`: UID0003EL command `000000024519` at `2026-08-15T23:19:29-04:00`; UID0002SV current-artifact revalidation command `000000024533` at `2026-08-15T23:26:00-04:00`; UID00006S final merged-artifact command `000000024538` at `2026-08-15T23:29:31-04:00`; UID0003EO command `000000024523` at `2026-08-15T23:20:17-04:00`; UID00051B command `000000024524` at `2026-08-15T23:20:29-04:00`; UID00006R command `000000024526` at `2026-08-15T23:20:41-04:00`.
- Dated callback owning-route receipt: `python .\\tools\\validator.py --mode file --file 'by-file/InventoryPane.md' --apply --queue-timeout 240 --wait-generated`, command `000000024539`, timestamp `2026-08-15T23:29:39-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`. This proves callback-time validation only and has no continuing current-state authority.
- UID0002SV validation retained eight known `missing_ref_uid` warnings for absent UIDs `0003EK`, `0003EQ`, `0003ES`, and `0003ET` (each referenced twice); the scoped target itself passed. The owning-file run reported only project-wide generator advisory counts and completed normally.
- Dated callback physical readback: CPP SHA256 `B6958B728FCDA8E466D1C9AA31833716CC8A08919346A60508673EB3A2C46164`, 23,537 bytes / 774 lines; H SHA256 `A86BD59FBA7A2B8974E593D920F412F147BDCBB9E107367BCBE5B221B96DEE1F`, 2,412 bytes / 76 lines. Both headers identified command `000000024539` and refresh `2026-08-15T23:29:39-04:00`; these are historical implementation receipts only.
- Dated `2026-08-15T23:45:44-04:00` supervisor-provided snapshot/receipt: UID00006S SHA256 `0998E1EB1FAF43131984B81B3E5EE0C6981A782F7BC99E738EDF79A8DD140CA4`, 32,815 bytes / 201 lines; command `000000024549` CPP SHA256 `BEEC5FB4E57A28954413395C9B35D13720C5A56A288FFA0947B33FC434AF0AF0`, 23,537 bytes / 774 lines; H SHA256 `BCC31E654A8BA2B1DABD8249A07182498F92CDD01FB1BCAFAC93CFB866289217`, 2,410 bytes / 76 lines. Expected inventory is two CPP definitions using local `bounds`, one legacy H declaration using `bounds`, one UID00006S H declaration using `rect`, zero `GetSlotRect(int` signatures, zero target-family `SetLTRB` calls, and two final `InitRectBounds(bounds, left, top, right, bottom)` calls. This dated receipt has no continuing current-state authority. Fresh supervisor Gate readback observed semantic agreement; authoritative generated command/hash identity is always dynamic.
- Supervisor coverage receipt: `by-memory/-coverage-report.md` SHA256 `76B9038A30DC8191BC0D5945D58FBF9D21964C83F751E54B560738B4EF4F1982`, 2,273,673 bytes / 5,065 lines. Command `000000024588` exited `0` with `ok: 1`; only pre-existing `missing_ref_uid` warnings for UIDs `00039L` and `0003T6` remained. Exact one-row UID0002SV/UID0003EL readback passed and the coverage lease was released. Audit decision: `SUPERVISOR_COVERAGE_PASSED` for C3EL-037..039.
- Supervisor Gate 2B is not a validator receipt: dated attested session `supervisor_uid0003d9_rollback_20260815`, exact backup SHA256 `5C50BAB9C97BB1C2D8AAE27F132E6E18CB68C9F3EFCB7EBF21FE61E95A514024`, `idb_save ok:true`, saved canonical SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`, and fresh health/readback establish `GATE2B_PASSED` for A01/P01-P04.

## Changed Files

- Modified ordinary docs, with dated callback identities unless explicitly refreshed below; frozen identities are implementation receipts and final authority requires fresh supervisor readback:
  - `by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md`: SHA256 `47607646C48B492D8FF323532BDF109A78A970990D1592E0C24707A19ABC1366`, 11,886 bytes / 128 lines.
  - `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md`: SHA256 `A4B8C4501797652E47B905A7417190093047A49DA6EA0DC71F2DB27409637187`, 37,178 bytes / 217 lines.
  - `by-class/InventoryPane2.md`: current supervisor-provided SHA256 `0998E1EB1FAF43131984B81B3E5EE0C6981A782F7BC99E738EDF79A8DD140CA4`, 32,815 bytes / 201 lines.
  - `by-file/InventoryPane.md`: SHA256 `FEF7F7F7D63C7C367929E36F2E1B938A46A6A5847C75D66487B3CED48CF095EA`, 78,648 bytes / 482 lines.
  - `by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md`: SHA256 `B13598F6C0BF97994CEEAD5A97B10E03FD724CCBF07B4F3B2A9AF63F37746CE4`, 5,876 bytes / 70 lines.
  - `by-memory/0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw.md`: SHA256 `0C40AB83ECCC431DF215D2160C93C50E145C49EE60283B43ADD6687746F21E24`, 7,516 bytes / 107 lines.
  - `by-class/InventoryPane.md`: SHA256 `0018E7DC596593AA3C76F55EF2817ABBD2799E5E277DAC533057627D077E1BB9`, 24,925 bytes / 497 lines.
- Verify-only `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` remained unchanged at SHA256 `AED48241905D3E5C7053C721163515D509BD3489D68F5D8FC4D9C0268ACB97AA`, 31,082 bytes / 304 lines.
- Generated InventoryPane.cpp/.h changed only through validator operation and were not manually edited. Command `000000024539` remains a dated callback receipt; command `000000024549` is a dated `2026-08-15T23:45:44-04:00` supervisor-provided snapshot/receipt with no continuing authority. Fresh supervisor Gate readback observed semantic agreement, while authoritative generated command/hash identity remains dynamic. IDA, manual coverage, tracker, audit, catalog, lifecycle, goal, and notes files were not edited by B006.
- Supervisor coverage closure changed `by-memory/-coverage-report.md` to SHA256 `76B9038A30DC8191BC0D5945D58FBF9D21964C83F751E54B560738B4EF4F1982`, 2,273,673 bytes / 5,065 lines; command `000000024588` passed, exact row readback passed, and its lease was released.
- Supervisor Gate 2B created backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0003EL-gate2b-20260816_001133435` (143,207,942 bytes; SHA256 `5C50BAB9C97BB1C2D8AAE27F132E6E18CB68C9F3EFCB7EBF21FE61E95A514024`) and durably saved canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` (143,208,000 bytes; SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`; last-write `2026-08-16 00:11:53 -04:00`). B006 did not mutate IDA or edit coverage.
- All ordinary-document leases were released immediately after their edits. The report-reconciliation lease was released immediately after this stable write; no B006 lease remains.
- Execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Reconciled callback allocation: 45 checked / 1 unchecked. Only C3EL-046 remains unchecked under exclusive supervisor lifecycle authority; row order and all eight fields are exact ledger twins after removing `Done`.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C3EL-001 | 0003EL | Preserve exact body `[0x004ef720,0x004ef794)`, 116 bytes, 45 instruction heads, SHA256 `BCB9123318AD0FC11AFA976059BAEAB5D0D1433AE892F5E5203BD57A18E8EF3D`. | Certain | MCP bytes/insn query; local hash. | UID0003EL Exact Binary Identity | incorporate | applied |
| [x] | C3EL-002 | 0003EL | Preserve predecessor table/padding `[0x004ef702,0x004ef720)`, 30 bytes, SHA256 `B208FB2A4D2C468D15945CDF9B3D1A18F4381B10CDB5B6302CB47B365F4763F8`. | Certain | MCP bytes/items. | UID0003EL Boundaries; UID0002SV | incorporate | applied |
| [x] | C3EL-003 | 0003EL | Preserve successor CC padding `[0x004ef794,0x004ef7a0)`, 12 bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`. | Certain | MCP bytes/items. | UID0003EL Boundaries; UID0002SV | incorporate | applied |
| [x] | C3EL-004 | 0003EL | Record ECX receiver, two stack slots, and `retn 8` as nonstatic member ABI. | Certain | Complete target disassembly. | UID0003EL ABI | incorporate | applied |
| [x] | C3EL-005 | 0003EL | Use logical `short slot`; preserve unsigned low-word range guard before signed arithmetic. | Very strong | `mov dx`/`movzx`/`movsx`; modeled short analog. | UID0003EL Signature/formal CPP; UID00006S H | incorporate | applied |
| [x] | C3EL-006 | 0003EL | Invalid logical indices produce `(-1,-1,-1,-1)`. | Certain | Target branches/instructions. | UID0003EL Behavior/formal CPP | incorporate | applied |
| [x] | C3EL-007 | 0003EL | List mode maps slots 0..8 to `(2, 23+23*slot, 160, 46+23*slot)`. | Certain | Target list instruction sequence. | UID0003EL Behavior/formal CPP | incorporate | applied |
| [x] | C3EL-008 | 0003EL | Nonzero/grid mode maps 3x3 slots with 51-pixel pitch to `(9+51*column,18+51*row,57+51*column,66+51*row)`. | Certain | Target grid instruction sequence. | UID0003EL Behavior/formal CPP | incorporate | applied |
| [x] | C3EL-009 | 0003EL | All paths converge on exactly one free `InitRectBounds` call at `0x004ef786`. | Certain | Target disassembly/xref to `0x004b7c50`. | UID0003EL Call Shape/formal CPP | incorporate | applied |
| [x] | C3EL-010 | 0003EL | Reject valid-path `RectBounds::SetLTRB`; it is a distinct real method not called by the target. | Certain | `0x004b78d0` vs target call target. | UID0003EL stale-source correction | reject-stale | applied |
| [x] | C3EL-011 | 0003EL | Keep `int m_viewMode` at `+0xfc`; zero is list and any nonzero is grid. | Very strong | Target, UID0003EO, constructor/mouse evidence. | UID0003EL Fields; UID00006S | incorporate | applied |
| [x] | C3EL-012 | 0003EL | Method is const with no receiver writes; only caller-provided bounds are written. | Certain | Full instruction/touched-state audit. | UID0003EL Signature/Touched State | incorporate | applied |
| [x] | C3EL-013 | 0003EL | Retain human source name `InventoryPane2::GetSlotRect`. | Very strong | Neighbor names, role, class/file family. | UID0003EL title/status/formal CPP | already-present | already-present |
| [x] | C3EL-014 | 0003EL | Preserve zero inbound xrefs at raw start as liveness evidence, not a source-emission blocker. | Certain | Current `xref_query`. | UID0003EL Negative Evidence/Score | incorporate | applied |
| [x] | C3EL-015 | 0003EL | Preserve zero VA/RVA/raw-offset pointer hits and zero external direct branches into the body. | Certain | MCP `find_bytes`; independent `.text` scan. | UID0003EL Negative Evidence | incorporate | applied |
| [x] | C3EL-016 | 0003EL | Record the current wildcarded target range signature as unique. | Certain | `make_signature_for_range`. | UID0003EL Exact Binary Identity | incorporate | applied |
| [x] | C3EL-017 | 00051B | Record the legacy 116-byte low-word/one-call raw helper as the closest source-family analog. | Certain | Fresh legacy bytes/insns/xrefs. | UID0003EL Family Evidence; UID00051B | incorporate | applied |
| [x] | C3EL-018 | 0003EL | Record modeled NewInventoryPane `0x004ee0a0` as an independent `__int16` slot-rectangle analog with shared 3x3 geometry. | Very strong | Current analyze_function. | UID0003EL Type/Family Evidence | incorporate | applied |
| [x] | C3EL-019 | 0003EO | Record complete target geometry inlined in live HitTestSlot and callers `{0x004ef09a,0x004ef165,0x004ef1a4}`. | Certain | Current UID0003EO decompile/xrefs. | UID0003EL Liveness; UID0003EO Evidence | incorporate | applied |
| [x] | C3EL-020 | 0003EL | Record paint/mouse paths as behavior consumers while distinguishing them from direct calls to the retained raw copy. | Very strong | UID0002SU analyses and generated/current source. | UID0003EL Relationships; UID0000KA | incorporate | applied |
| [x] | C3EL-021 | 0003EL | Keep canonical owner/emitter UID00006S InventoryPane2. | Certain | Receiver offset, physical island, class map. | UID0003EL metadata/Ownership | already-present | already-present |
| [x] | C3EL-022 | 0003EL | Keep UID0000KA InventoryPane.cpp placement at position 310 between GetButtonRect and HitTestButton. | Certain | Physical/source order and emitter route. | UID0003EL Source Placement; UID0000KA | already-present | already-present |
| [x] | C3EL-023 | 0003EL | No split, merge, new UID, new source file, or target-owned header is required. | Certain | Exact boundaries/current source tree. | UID0003EL Range/Source Placement | not-applicable | excluded-with-reason |
| [x] | C3EL-024 | 0003EL | Replace target CPP with the exact short-slot/single-InitRectBounds formal block. | Very strong | Exact behavior/ABI/call shape. | UID0003EL RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C3EL-025 | 00006S | Keep target H blank and use owner declaration `void GetSlotRect(short slot, RectBounds *rect) const;`; target CPP local `bounds` and legacy UID00006R `bounds` remain unchanged. | Very strong | Current UID00006S identity and dynamic generated-H readback distinguish owner-H `rect` from target/legacy `bounds`. | UID0003EL H; UID00006S RECONSTRUCTION_H CODE | incorporate | applied |
| [x] | C3EL-026 | 0003EL | Raise score from 85/88 to 92/94; keep owner/emitter/reconstructable/position. | Strong | All source blockers resolved; lexical/direct-route cap remains. | UID0003EL metadata/Score Rationale | incorporate | applied |
| [x] | C3EL-027 | 0003EL | Populate Item Summary with exact behavior/source-quality disposition without duplicating generated metadata. | Certain | Current blank summary and generated-report rules. | UID0003EL Item Summary | incorporate | applied |
| [x] | C3EL-028 | 0002SV | Update child row/evidence to current 116-byte identity, short ABI, one-call shape, inline liveness, and 92/94 target state. | Very strong | Current target and parent split. | UID0002SV child inventory/evidence | incorporate | applied |
| [x] | C3EL-029 | 00006S | Update method row, owner signature with output name `rect`, constants prose, target evidence, and history; retain 94/94 while target CPP local remains `bounds`. | Very strong | Current UID00006S SHA256 `0998E1EB1FAF43131984B81B3E5EE0C6981A782F7BC99E738EDF79A8DD140CA4`, 32,815 bytes / 201 lines, plus dynamic generated-H readback. | UID00006S H/Method Map/Evidence | incorporate | applied |
| [x] | C3EL-030 | 0000KA | Update A25/file evidence, source-order text, generated expectations, and history; retain 94/94. | Very strong | Complete file route and dynamically read generated semantics. | UID0000KA InventoryPane2 sections | incorporate | applied |
| [x] | C3EL-031 | 0003EO | Clarify that binary inlines geometry while formal human source may call GetSlotRect; retain 85/91 and current CPP. | Very strong | Live decompile and plausible source factoring. | UID0003EO Behavior/IDA Evidence/Changes | incorporate | applied |
| [x] | C3EL-032 | 00051B | Replace legacy CPP with short-slot/single-InitRectBounds block; retain 90/92 and route. | Very strong | Fresh exact legacy body. | UID00051B RECONSTRUCTION_CPP CODE/Signature | incorporate | applied |
| [x] | C3EL-033 | 00006R | Replace legacy class declaration with short slot and update family evidence; retain 93/94. | Very strong | UID00051B ABI and class ownership. | UID00006R RECONSTRUCTION_H CODE/Evidence | incorporate | applied |
| [x] | C3EL-034 | 00015S | Keep canonical `InitRectBounds(RectBounds *,int,int,int,int)` helper ownership/signature unchanged. | Certain | Current IDA type/body and support docs. | UID00015S verify-only | already-present | already-present |
| [x] | C3EL-035 | 0003EL | Expected generated CPP has one corrected UID0003EL definition and one corrected UID00051B definition, with no valid-path SetLTRB call. | Certain | Formal emitter route. | Generated InventoryPane.cpp readback checklist | incorporate | applied |
| [x] | C3EL-036 | 00006S | Generated H inventory must contain exactly one legacy `GetSlotRect(short slot, RectBounds *bounds) const;` and exactly one InventoryPane2 `GetSlotRect(short slot, RectBounds *rect) const;`. | Certain | Dated `2026-08-15T23:45:44-04:00` command `000000024549` H receipt with no continuing authority; fresh supervisor Gate readback observed semantic agreement, while generated command/hash identity remains dynamic. | Generated InventoryPane.h readback checklist | incorporate | applied |
| [x] | C3EL-037 | 0002SV | Replace stale by-memory manual parent row with current 89% non-reconstructable split-container text. | Certain | Supervisor coverage command `000000024588` verified exactly one corrected UID0002SV row; coverage SHA256 `76B9038A30DC8191BC0D5945D58FBF9D21964C83F751E54B560738B4EF4F1982`. | by-memory/-coverage-report.md | incorporate | applied |
| [x] | C3EL-038 | 0003EL | Insert exact 92% very-strong target row under UID0002SV in address order. | Certain | Supervisor coverage command `000000024588` verified exactly one UID0003EL row; exit `0`, `ok: 1`. | by-memory/-coverage-report.md | incorporate | applied |
| [x] | C3EL-039 | 00006S | Keep current by-class InventoryPane2 and by-file InventoryPane manual rows unchanged. | Certain | Supervisor coverage closure verified the existing 94% class/file rows required no write. | by-class/by-file coverage verify-only | already-present | already-present |
| [x] | C3EL-040 | 0003EL | Supervisor replaced the exact former AP with A01's accepted AP at `0x004ef720`; final AP is exactly `Retained InventoryPane2::GetSlotRect(short, RectBounds *) const source helper. Uses m_viewMode at +0xFC for nine-row list or 3x3 grid geometry; every path calls InitRectBounds. Direct calls to this raw copy are absent because live consumers inline the geometry.` | Very strong | Dated attested Gate 2B session `supervisor_uid0003d9_rollback_20260815`; exact post-save AP readback and `GATE2B_PASSED`. | Supervisor Gate 2B IDA A01 | incorporate | applied |
| [x] | C3EL-041 | 0003EL | Supervisor verified A01 as the sole delta, preserved raw/function/name/type/xref/byte/boundary state and all three protected hashes, saved once, and passed fresh post-save health/readback. | Certain | Exact backup SHA256 `5C50BAB9C97BB1C2D8AAE27F132E6E18CB68C9F3EFCB7EBF21FE61E95A514024`; saved canonical SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`. | Supervisor Gate 2B protected state/save readback | not-applicable | applied |
| [x] | C3EL-042 | 0003EL | Keep source constants `kCompactPageSize`, `kListView`, and `kGridView`; remove isolated `kInventoryViewList` prose drift. | Strong | Current file-wide emitted naming. | UID0003EL/UID00006S/UID0000KA naming | incorporate | applied |
| [x] | C3EL-043 | 00006S | Do not convert m_viewMode to an enum-backed field; preserve dword-sized int and exact nonzero behavior. | Very strong | Current binary comparisons/assignments. | UID00006S layout/type rationale | already-present | already-present |
| [x] | C3EL-044 | 0003EL | State exact original lexical names remain unavailable, but best-supported human names are final enough for source and do not justify raw labels. | Strong | No PDB/symbol; family consistency. | UID0003EL inference/score/open questions | incorporate | applied |
| [x] | C3EL-045 | 0003EL | After callback, scoped-validate every changed ordinary page, then validate owning file with generated wait and physically reread InventoryPane.cpp/.h. | Certain | Workflow and emitter route. | Validator/generated checklist | incorporate | applied |
| [ ] | C3EL-046 | 0003EL | Supervisor coverage and Gate 2B are complete; report execution and archive movement remain exclusively supervisor-owned and authoritative only from current path plus validator-owned metadata. | Certain | Coverage and Gate 2B closure receipts in this report; skill lifecycle boundaries. | Coverage/IDA/lifecycle checklist | incorporate | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000024622","destination_path":"executed-b-agent-research/B006/0003EL-InventoryPane2SlotRectBuilderRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0003EL-InventoryPane2SlotRectBuilderRaw-source-quality.md","timestamp":"2026-08-16T00:24:08-04:00","uid":"0003EL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
