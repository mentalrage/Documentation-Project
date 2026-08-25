** TARGET-REPORT-UID:0001M7 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001M7 ChangeSpellSlotInputPane Raw Constructor Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: refresh [UID:0001M7][0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor](../../../../../by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md) with current B006 live MCP provenance, raise source-page metadata from `87/90` to `88/91`, and keep the existing owner/emitter and formal constructor C++.
- Final disposition: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00001M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001M`.
- Required action after supervisor acceptance: update the target page's score/evidence/rationale, run a scoped validator with generated refresh, and confirm the generated tracker/coverage/source comments no longer show stale `74/84` or stale Not-Covered state.
- C++ policy: preserve the target's existing formal constructor block. The no-IDA-function/no-start-xref fact is a confidence cap, not a blank-C++ blocker.
- Confidence: high for constructor bytes, class identity, source route, behavior, and first-draft C++ readiness; capped below final audit by the retained raw-start/no-direct-route question and project-wide localization method spelling drift (`GetString` versus `GetLocalizedString`).

## Supporting Research

## Target

- Target UID: [UID:0001M7]
- Target path: `by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md`
- Assignment id: `B006-report-0001M7-change-spell-slot-input-pane-raw-constructor-20260625`
- Queue source in `goal.md`: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Current source-header scores: `COMPLETION:87`, `CONFIDENCE:90`.
- Current source-header metadata: `CANONICAL_OWNER:00001M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001M`.
- Current target formal C++: nonblank constructor body is already present.
- Generated state observed during this report: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` still show stale `74/84` comments/rows for [UID:0001M7] even though the source page header is `87/90`. This is generated state to refresh by validator, not a manual-edit target.

## Current Target State

The target page already carries the B002 accepted direction:

- Exact range `0x005b3220-0x005b3260`.
- Raw constructor-shaped body with no IDA function object at `0x005b3220`.
- Prompt id `0x2d` / 45 (Verified with `int_convert.py` in this pass).
- `g_pLanguageMan` read at `0x005b3227` and localized string lookup call at `0x005b3232`.
- [UID:00001O][CharArgsInputPane](../../../../../by-class/CharArgsInputPane.md) base constructor call at `0x005b323a`.
- Vtable stores to `0x0062fad0`, `0x0062fb20`, and `0x0062fb50`.
- Factory/open-helper equivalence at `0x005a9430` and dispatcher equivalence in `sub_5A5BD0`.
- Direct class parent [UID:00001M][ChangeSpellSlotInputPane](../../../../../by-class/ChangeSpellSlotInputPane.md) and file route [UID:0000O0][SpellInputPanes](../../../../../by-file/SpellInputPanes.md).
- Formal constructor C++:

```cpp
ChangeSpellSlotInputPane::ChangeSpellSlotInputPane()
    : CharArgsInputPane(g_pLanguageMan->GetString(45))
{
}
```

The page's remaining caveat is not missing behavior. It is the binary-modeling fact that `0x005b3220` remains a raw constructor-shaped byte island with no direct start xref, while live construction paths inline the same sequence.

## Supervisor Active Recheck

- Current user instruction required report-only research for [UID:0001M7] and explicitly required IDA MCP. I did not take leases and did not edit target/support by-* docs, generated files, coverage reports, validator state/cache, or the IDA DB.
- The assignment did not authorize split execution. No new child page is needed: the target is already the exact 64-byte raw constructor child.
- Every score-limiting blocker named in `goal.md` was rechecked in this pass: raw bytes, no-function status, no direct route, prompt/config data, base construction, vtable stores, factory/dispatcher equivalence, source-facing names, owner/emitter route, and formal C++ readiness.

## Inference Research Guidance Check

- Direct IDA/MCP facts: live session `80de0a67` reports the current IDB and function/xref/byte/disassembly facts below.
- Documentation evidence: current by-* pages already preserve B002/B003/LanguageMan/CharArgs/SpellInputPanes findings; generated tracker/coverage comments are stale relative to source headers and are not treated as authority.
- Inference: the source role is an out-of-line `ChangeSpellSlotInputPane` constructor retained in the binary while reachable creation sites inline the same construction. This is a high-confidence source-shape inference because the raw body and both live construction paths agree on object size, prompt id, base constructor, and vtable triplet.
- Wave2/Wave3/simroot material was used only as lead context where existing docs referenced it; current conclusions come from live MCP and current by-* docs.

## Evidence Checked

### IDA MCP Provenance

- Endpoint: `http://127.0.0.1:13337/mcp`
- Initialize/tool schema checked: JSON-RPC ids `1-4`.
- Active IDB: MCP `idb_list` JSON-RPC id `10` returned session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker pid `26892`, `is_analyzing:false`.
- Health: MCP `server_health` JSON-RPC id `11` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Evidence calls: JSON-RPC ids `20-34` ran `lookup_funcs`, `get_bytes`, `insn_query`, `xrefs_to`, `find`, `find_bytes`, `decompile`, and `get_int`.
- Local timestamp for this pass: `2026-06-25T01:42:55-04:00`.

### Current MCP Facts

- `lookup_funcs` id `20`:
  - `0x005b3220` and `0x005b325f` are `Not a function`.
  - `0x005b3260` is `sub_5B3260`, size `0x6c`.
  - `0x005b32d0` is `sub_5B32D0`, size `0x13e`.
  - `0x005a9430` is `sub_5A9430`, size `0x80`.
  - `0x005a5bd0` is `sub_5A5BD0`, size `0x1852`; address `0x005a61d7` belongs to this function.
  - `0x004f0350` is `sub_4F0350`, size `0x22`.
  - `0x004f2a60` is `sub_4F2A60`, size `0x73`.
  - Sibling raw item-slot constructor `0x005b2fd0` is also `Not a function`.
- `get_bytes` id `21`:
  - `0x005b3210` read shows previous epilogue bytes ending with `c2 08 00`, eleven `0xcc` alignment bytes from `0x005b3215-0x005b321f`, then the constructor prologue at `0x005b3220`.
  - `0x005b3220` size 64 returns the full body ending in `5e 8b e5 5d c3`.
- `insn_query` id `22` over `0x005b3220-0x005b3260` decoded 20 instructions, all with `fn:null`: thiscall prologue, `mov ecx, dword_67A750`, `push 2Dh`, `call sub_4F0350`, `call sub_4F2A60`, vtable stores to the three `ChangeSpellSlotInputPane` views, and `retn`.
- `xrefs_to` id `23`:
  - `0x005b3220`: zero cross-references.
  - `0x005b3260`: one data xref `0x0062fb28 -> 0x005b3260`.
  - `0x005b32d0`: one data xref `0x0062fb18 -> 0x005b32d0`.
  - `0x0062fad0`: stores from `0x005a61d7`, `0x005a9486`, and raw constructor store `0x005b323f`.
  - `0x0062fb20`: stores from `0x005a61df`, `0x005a948c`, and raw constructor store `0x005b3247`.
  - `0x0062fb50`: stores from `0x005a61e9`, `0x005a9496`, and raw constructor store `0x005b3251`.
  - `0x004f2a60`: code xrefs include dispatcher/factory calls `0x005a61d2`, `0x005a9481`, sibling item factory `0x005a9401`, and raw constructor call `0x005b323a`.
- Negative route checks:
  - `find data_ref` id `24` for `0x005b3220`: zero matches.
  - `find code_ref` id `25` for `0x005b3220`: zero matches.
  - `find immediate` id `26` for decimal `5976608` / `0x005b3220`: zero matches.
  - `find_bytes` id `27` for VA bytes `20 32 5B 00` and RVA bytes `20 32 1B 00`: zero matches.
- Factory/open-helper equivalence:
  - `decompile 0x005a9430` id `30` shows allocation `sub_4F4AA0(264)`, `sub_4F0350(dword_67A750, 45)`, `sub_4F2A60`, and stores to the three `ChangeSpellSlotInputPane` vtables at `0x005a9486/0x005a948c/0x005a9496`.
  - `insn_query` id `31` over `0x005a9460-0x005a94a0` confirms the same instruction sequence, including `push 2Dh`, base constructor call, and three vtable stores.
- Dispatcher equivalence:
  - `insn_query` id `31` over `0x005a61b0-0x005a61f0` confirms jump-table case 42 inside `sub_5A5BD0`: `push 2Dh`, `call sub_4F0350`, `call sub_4F2A60`, then stores to `0x0062fad0`, `0x0062fb20`, and `0x0062fb50`.
- Sibling comparison:
  - `insn_query` id `31` over `0x005a93e0-0x005a9420` confirms the item-slot factory uses the same sequence with prompt id `0x2e` / 46 and `ChangeItemSlotInputPane` vtables. This supports the constructor-family pattern rather than compiler glue.
- Vtable slot read:
  - `get_int` id `32` confirms `0x0062fb18 -> 0x005b32d0`, `0x0062fb28 -> 0x005b3260`, and table-head entries consistent with the documented class vtable views.
- Support decompilation:
  - `decompile 0x004f2a60` id `33` confirms `CharArgsInputPane` constructor behavior: base `LineInputPane` construction, `CharArgsInputPane` vtable installs, and active edit input disable call.
  - `decompile 0x004f0350` id `34` confirms the localization lookup returns `m_strings[stringId]` when `0 <= stringId < m_stringCount`, otherwise the fallback literal.

### Numeric Verification

`tools/int_convert.py` was used in this pass. The first malformed PowerShell call was discarded. The corrected JSON-input call verified:

- `0x40` = 64
- `0x2d` = 45
- `0x108` = 264
- `0xa0` = 160
- `0xa4` = 164
- `0x6c` = 108
- `0x13e` = 318
- `0x198` = 408
- `0x88` = 136

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor Role

Best decision: [UID:0001M7] is source-authored `ChangeSpellSlotInputPane::ChangeSpellSlotInputPane`, ready for formal first-draft C++ and modest score uplift after current live MCP proof.

Evidence:

- Complete thiscall constructor byte shape, including `this` preserved in `esi`, base constructor call, three vtable stores, and return of `this`.
- The raw start is preceded by alignment and followed by the modeled key handler at `0x005b3260`.
- Reachable creation sites at `0x005a9430` and dispatcher case `0x005a61b0` inline the same construction semantics.
- Sibling item-slot constructor/factory pair follows the same pattern with only prompt id and vtables changed.

Rejected alternatives:

- Compiler thunk/EH cleanup: rejected because the body performs full object construction, not `this` adjustment, cleanup, or destructor unwinding.
- Padding/data: rejected because MCP decodes a coherent 20-instruction body ending in `retn`.
- Packet/helper code: rejected because there are no packet writes, stack args, or sender calls; the body only constructs the object.
- Non-reconstructable dead code: rejected because the source class is live and reachable construction sites exist, even if they inline rather than call the retained out-of-line body.

### No-Route Caveat

Best decision: keep no-direct-route as a confidence cap, not an implementation blocker.

Evidence checked:

- `xrefs_to`, `find data_ref`, `find code_ref`, `find immediate`, and VA/RVA byte-pattern searches all found no route to `0x005b3220`.
- Positive controls worked: vtable xrefs and base-constructor xrefs are found, and modeled handlers have vtable data xrefs.
- Factory/dispatcher inline construction explains how the class is built without requiring a direct call to the raw start.

Impact:

- The no-route caveat should remain visible in the target page.
- It does not justify blank formal C++ because the target has a valid owner/emitter route and exact source constructor shape.
- It caps confidence below final-source audit because the original retention/linkage reason is not proven.

### Source-Facing Names

- Class and constructor name: `ChangeSpellSlotInputPane::ChangeSpellSlotInputPane` is strongly supported by vtable names, class page, and child method family.
- Base class: `CharArgsInputPane` is directly supported by `0x004f2a60` and the base class support page.
- Global: `g_pLanguageMan` is current canonical singleton name from [UID:0000RC].
- Localization method: [UID:00040P] now prefers `LanguageMan::GetLocalizedString(int) const`, while the existing target and nearby `SpellInputPanes.cpp` generated output use `g_pLanguageMan->GetString(...)` for several first-draft prompt constructors. I recommend preserving the current target formal block for this callback rather than changing only one call spelling. The behavior evidence is the id-45 lookup through `0x004f0350`; source-wide naming should be normalized consistently when the localization call style is updated across emitted UI prompt code.
- Do not emit compiler vtable stores in source. The class declaration/base initializer regenerate those binary effects.

## Evidence Standards Used

- Direct IDA facts: live function lookup, byte reads, instruction decoding, xrefs, decompilation, integer reads, and negative searches.
- Documentation evidence: current target, aggregate, class, file, vtable, CharArgsInputPane, and LanguageMan support pages.
- Generated evidence: generated C++ confirms the constructor currently surfaces to `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`, but generated score comments/tracker rows are stale and must be refreshed by validator.
- Inference ladder: the source role is inferred from exact instruction semantics plus two independent inline construction routes and sibling comparison; the confidence cap is maintained because original symbols/source map are unavailable and the raw start has no static route.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x005b3220-0x005b3260` is `ChangeSpellSlotInputPane::ChangeSpellSlotInputPane` | High | Raw constructor bytes, vtable names/stores, base constructor call, factory/dispatcher equivalence | Compiler glue, padding/data, packet helper, unrelated class rejected | Why the out-of-line copy is retained without direct xrefs |
| Owner/emitter should remain [UID:00001M] | High | Class page clears gate, vtables and handlers belong to this class, file route clears through `SpellInputPanes` | `InputPanes`, `ItemActionInputPanes`, `CommandInputPanes`, `PacketBuffer`, `Socket`, `SayInputPanes` rejected in current docs and rechecked context | None affecting owner |
| Formal constructor C++ is source-ready | High | Exact source initializer behavior, valid owner/emitter, combined score gate met, current generated output surfaces the method | Raw no-route and localization method spelling reviewed | Original localization method spelling is not final project-wide |
| Generated tracker/coverage rows are stale | High | Source header is `87/90`; generated tracker/coverage/source comments still show `74/84` | Source page reread shows current header; generated file header command id is current but score comments stale | Validator/generated metadata path should be refreshed after implementation acceptance |

## Positive Evidence Summary

- Exact 64-byte constructor body is live MCP-decoded and boundary-confirmed.
- The body loads `g_pLanguageMan`, pushes id `45`, calls localized lookup, calls `CharArgsInputPane` constructor, writes all three `ChangeSpellSlotInputPane` vtable views, and returns `this`.
- Two reachable construction paths duplicate the same source constructor semantics.
- The class page, file page, vtable pages, key/submit child pages, and base-class pages all agree on source family and route.
- Existing formal C++ is behavior-preserving because it models the source initializer rather than compiler-emitted vtable stores.

## Negative Evidence Summary

- No IDA function object exists at `0x005b3220`.
- No `xrefs_to`, `data_ref`, `code_ref`, `immediate`, VA pointer, or RVA pointer route to the raw start was found in the current live MCP pass.
- The no-route fact was not used as a generic blocker: factory/dispatcher equivalence and sibling comparison were checked and resolve source role while preserving the confidence cap.
- No support evidence moves this constructor to `InputPanes`, `ItemActionInputPanes`, `CommandInputPanes`, `PacketBuffer`, `Socket`, protocol send helpers, or `SayInputPanes`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Current State | B006 Recommendation |
| --- | --- | --- | --- | --- |
| `0x005b3220-0x005b3260` | [UID:0001M7](../../../../../by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md) | Raw constructor-shaped body | `87/90`, owner/emitter `00001M`, C++ populated | Raise to `88/91`; preserve owner/emitter/C++ |
| `0x005b3220-0x005b340e` | [UID:0001M8](../../../../../by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md) | Non-emitting index | `87/88`, no owner/emitter | Already carries B002 aggregate policy; no required metadata change |
| `0x005b3260-0x005b32cc` | [UID:0001M9](../../../../../by-memory/0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md) | Key handler | `86/90`, C++ populated | Support context already present |
| `0x005b32d0-0x005b340e` | [UID:0001MA](../../../../../by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md) | Submit handler | `88/91`, C++ populated | Support context already present |
| `0x005b3410-0x005b3485` | [UID:0002S6](../../../../../by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md) | Retained no-route packet sender | `86/90`, C++ blank | No target change for this report |

## Ranked Ownership Analysis

### 1. [UID:00001M] ChangeSpellSlotInputPane

Evidence for:

- Vtable names and slots identify the class.
- Key/submit child methods route through the same class vtable family.
- Raw constructor and two reachable construction paths store the same vtable triplet.
- Class page routes through [UID:0000O0] `SpellInputPanes` and clears the gate.

Evidence against:

- The raw constructor start has no direct xref. This affects reachability confidence, not class ownership.

Decision:

- Keep as canonical owner and emitter.

### 2. [UID:0000O0] SpellInputPanes as file route

Evidence for:

- File page owns the spell prompt family.
- Generated output already emits this constructor into `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- ChangeSpellSlot key/submit/packet behavior is spell-dialog domain behavior.

Evidence against:

- Base constructor belongs to `InputPanes`; sender helpers belong to network/PacketBuffer/Socket; backing spell state belongs to `UserPane`. Those are dependencies, not this constructor owner.

Decision:

- Keep as source file route, not direct owner.

### Rejected Owners

- `InputPanes`: owns `CharArgsInputPane`, not this feature constructor.
- `ItemActionInputPanes`: sibling item-slot constructor family, different prompt id and vtables.
- `CommandInputPanes`: address-neighborhood/inherited context only.
- `UserPane`: backing spell state owner, not constructor owner.
- `PacketBuffer`, `Socket`, `ProtocolSend`: no packet behavior in the constructor.
- `SayInputPanes`: starts later after clean padding and unrelated vtable family.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Recommended formal block: preserve the current exact target `RECONSTRUCTION_CPP CODE` content:

```cpp
ChangeSpellSlotInputPane::ChangeSpellSlotInputPane()
    : CharArgsInputPane(g_pLanguageMan->GetString(45))
{
}
```

Reason it preserves behavior:

- It expresses the source constructor effect: call the `CharArgsInputPane` base with localized prompt id `45`.
- It intentionally omits vtable stores because those are compiler-generated from the class declaration.
- It stays within the target's own memory range and does not duplicate sibling method or packet-helper bodies.

Reason it matches plausible original source:

- Mid-2000s C++ source would represent this as a normal derived-class constructor with a base initializer, not as explicit vtable assignments.
- The constructor name, base class, and global prompt lookup all match current source-family conventions.
- The exact method spelling `GetString` remains locally accepted by current `SpellInputPanes` generated output and target notes. `GetLocalizedString` is the stronger LanguageMan child spelling, but changing only this target would be a style normalization rather than a behavior fix.

## Recommended Target Doc Changes

Target path:

- `by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md`

Apply after supervisor acceptance:

- Change `COMPLETION:87` to `COMPLETION:88`.
- Change `CONFIDENCE:90` to `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:00001M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001M`, and the existing formal constructor C++ block.
- Add a `2026-06-25 B006 Current MCP Recheck` evidence section with:
  - MCP session `80de0a67`, health status, Hex-Rays ready, imagebase `0x400000`.
  - `lookup_funcs` proof that `0x005b3220` is still not a function and `0x005b3260` is the next modeled method.
  - `get_bytes` proof for predecessor alignment and exact 64-byte body.
  - `insn_query` proof for the 20 instruction raw constructor sequence.
  - `xrefs_to` and `find`/`find_bytes` negative route proof for `0x005b3220`.
  - vtable xrefs from dispatcher/open/raw constructor stores.
  - `decompile 0x005a9430` and dispatcher `insn_query` proof of inline construction equivalence.
  - `decompile 0x004f0350` / [UID:00040P] support note that exact lookup method is `LanguageMan::GetLocalizedString`, while current local formal C++ keeps `GetString`.
- Add or refresh a score rationale:
  - `88` completion because the target now has current MCP-backed bytes, boundary, no-route proof, vtable refs, factory/dispatcher equivalence, base/localization support, owner/emitter route, and formal constructor C++.
  - `91` confidence because live MCP, target docs, class/file/vtable support, and sibling comparison agree.
  - Reason not higher: raw start remains no-function/no-direct-route; exact original reason for retained out-of-line body is not proven; localization method spelling is a project-wide source-style caveat; final `95+` audit for the wider class/file is not complete.

## Recommended Support Doc Changes

Support docs to check during implementation callback:

- `by-class/ChangeSpellSlotInputPane.md`: no metadata change required. Either add one short B006 note that the raw constructor child now has current live MCP proof and `88/91` recommended metadata, or mark the B002-level constructor evidence already present at same detail.
- `by-file/SpellInputPanes.md`: no metadata change required. Either add one B006 source-ready constructor refresh note for [UID:0001M7], or mark existing B002 child C++ readiness and placement text already present at same detail.
- `by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md`: no metadata change required. Existing non-emitting index policy and child inventory are sufficient; implementation may add a one-line B006 current-MCP child score note only if the supervisor wants support-level provenance.
- `by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md` and `by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md`: no metadata change required. Existing slot/xref evidence is already at same or greater detail; no edit is required unless target implementation wants to cross-link the B006 score refresh.
- `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md`, `by-global/g_pLanguageMan.md`, `by-class/CharArgsInputPane.md`, and `by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md`: no implementation edit required for this target. They were checked as support evidence.

## Score And Metadata Recommendation

- Current target metadata: `87/90`, owner `00001M`, reconstructable `TRUE`, emitter `00001M`.
- Recommended metadata: `88/91`, owner `00001M`, reconstructable `TRUE`, emitter `00001M`.
- Owner/emitter changes: none.
- C++ changes: none; preserve existing formal block.
- Split/rename/new child changes: none.

Score-improvement attempt:

- Raw/no-function start: rechecked with live `lookup_funcs`, bytes, and instruction query. Result: still raw, but exact body and boundaries are current.
- Missing direct route: rechecked with `xrefs_to`, `find data_ref`, `find code_ref`, `find immediate`, and VA/RVA `find_bytes`. Result: still no direct route; now documented as current negative evidence.
- Factory/dispatcher proof: rechecked with `decompile` and `insn_query`. Result: two reachable construction sites inline the same source constructor.
- Source-facing names: rechecked LanguageMan, CharArgsInputPane, class/file/vtable support. Result: constructor source shape remains safe; localization method spelling remains a style caveat, not a behavior blocker.
- Generated stale state: checked tracker, coverage, and generated source. Result: stale comments/rows must be refreshed by validator after accepted implementation, not manually edited.

## Open Questions With Attempted Resolution

1. Why does `0x005b3220` have no direct xref?
   - Evidence checked: current MCP no-function/no-xref/no-immediate/no-pointer scans, factory/open helper, dispatcher case, sibling item-slot constructor.
   - Best supported resolution: the binary retains an out-of-line constructor-shaped body while reachable creation paths inline the construction. This remains a confidence cap but does not block formal C++.

2. Should the formal C++ use `GetString` or `GetLocalizedString`?
   - Evidence checked: exact [UID:00040P] LanguageMan child prefers `GetLocalizedString`; current [UID:0001M7] and `SpellInputPanes.cpp` use `GetString` in nearby first-draft prompt constructors; support docs state both spellings are acceptable descriptive aliases for `0x004f0350`.
   - Best supported resolution for this callback: preserve the current formal block and document the alias caveat. The behavior-critical fact is the id-45 lookup through `g_pLanguageMan`.

3. Is this constructor blocked from C++ by no-route status?
   - Evidence checked: active by-structure C++ gate, owner/emitter route, current generated output, factory equivalence.
   - Resolution: no. The target is reconstructable, has an emitter route, average score is above the current code gate, and exact source constructor shape is supported.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit is recommended or allowed for B006 in this report.

Generated reports to refresh by validator after accepted target implementation:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`

The by-memory auto coverage row should be refreshed from the source page header and `Item Summary`. The current item summary is concise and does not need wording change for this report.

## Validator / Generated Refresh Expectations

No validators were run during this report-only pass.

Expected implementation validator from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001M7-ChangeSpellSlotInputPaneRawConstructor-source-quality-removed.md](0001M7-ChangeSpellSlotInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation edits support docs, also run scoped validators for each changed support file.

After validator completion, re-read:

- source target header for `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter unchanged, C++ preserved;
- `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` header/comments to confirm the generated refresh is at or newer than the validator command and no longer carries stale target metadata for [UID:0001M7];
- generated tracker/coverage rows if supervisor verification relies on them.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/0001M7-ChangeSpellSlotInputPaneRawConstructor-source-quality.md`
- Implementation callback modified: `by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md`.
- Implementation callback checklist updated in this report.
- Support docs checked but not edited: `by-class/ChangeSpellSlotInputPane.md`, `by-file/SpellInputPanes.md`, `by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md`, `by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md`, `by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md`, `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md`, `by-global/g_pLanguageMan.md`, `by-class/CharArgsInputPane.md`, and `by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md`.
- Generated files were refreshed only by validator-owned commands after B006's scoped validators. Final post-validator readback showed `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` and `auto-generated/-ag-coverage-report-by-memory.md` at `validator-command-id: 000000000902`, plus `auto-generated/-ag-research-tracker.md` at `validator-command-id: 000000000903`; no generated/project-level/manual coverage/validator state/IDA DB file was manually edited by B006.

## Leases

- Report-only research and writing in the Agent-B006 research folder did not require a lease.
- Implementation callback lease: `python .\tools\leaser\leaser.py B006 lease by-memory\0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md` returned `Success`.
- Release: `python .\tools\leaser\leaser.py B006 unlease by-memory\0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md` returned `Success`.
- Post-release lease report readback showed no active B006 lease for the target; only old Supervisor leases from `2026-06-18T04:43:02Z` expiring `2026-06-18T04:48:02Z` remained listed.

## Blockers

- No MCP blocker: MCP was available and responsive.
- No source-quality blocker remains that prevents target-page implementation.
- Remaining non-final caps are evidence-backed: no IDA function object/start route for `0x005b3220`, no proven original retention reason, and localization call-spelling convention not globally normalized.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report for [UID:0001M7] and updated `goal.md` to implementation callback mode.
- [x] Target doc to update: `by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md`. Proof: header now reads `COMPLETION:88`, `CONFIDENCE:91`; `CANONICAL_OWNER:00001M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001M`, blank optional emitter position, and the formal constructor C++ were preserved. Sections touched: header scores, `## 2026-06-25 B006 Current MCP Recheck`, `## Score Rationale`, `## Direct Parent Gate`, `## Changes`, and the stale parent-score sentence in `## Status`.
- [x] Support docs checked or updated if accepted: `by-class/ChangeSpellSlotInputPane.md`, `by-file/SpellInputPanes.md`, `by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md`, `by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md`, and `by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md`. Proof: checked by header/read/`rg` before implementation; existing source docs already carry constructor child, no-function/no-xref caveat, prompt id `45`, `CharArgsInputPane` base, vtable stores/slots, factory/dispatcher equivalence, and first-draft child C++ readiness at same-or-greater support detail. No support edit was needed.
- [x] Support docs checked as already sufficient unless supervisor requests normalization: `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md`, `by-global/g_pLanguageMan.md`, `by-class/CharArgsInputPane.md`, and `by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md`. Proof: checked before implementation; LanguageMan documents the `GetLocalizedString` source-facing preference while allowing alias uncertainty, `g_pLanguageMan` documents complete `LanguageMan*` singleton consumers, `CharArgsInputPane` lists UID `0001M7` as a raw constructor caller, and the constructor child documents the `LineInputPane` base/vtable/disabled-edit behavior. No contradiction required support edits.
- [x] Current target state and actual evidence checked recorded: source header before implementation `87/90`, current formal C++ nonblank, stale generated `74/84` rows/comments, MCP session `80de0a67`, JSON-RPC ids `10-34`, and `int_convert.py` conversion proof. Proof: all are recorded in the report and the target page now carries the B006 current MCP recheck section.
- [x] Metadata/score changes to apply: target only, `87/90 -> 88/91`; no owner/emitter/reconstructable changes. Proof: post-validator source header and generated output both show UID `0001M7` at `Completion:88 | Confidence:91`.
- [x] Score-limiting blockers researched: no-function raw start, no direct route, factory/dispatcher equivalence, sibling pattern, localization/base constructor names, generated stale state. Proof: target `## 2026-06-25 B006 Current MCP Recheck` records live MCP route negatives and positive equivalence; `## Score Rationale` records remaining caps as confidence/final-audit caps.
- [x] Owner/emitter/reconstructable changes to apply: none; preserve `CANONICAL_OWNER:00001M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001M`. Proof: post-validator source header retains those values unchanged.
- [x] Split/rename/new-child changes to apply: none. Proof: no new by-* pages, splits, range changes, or renames were performed.
- [x] Source-placement and IDA rename/type/comment changes: no IDA DB edits requested; source placement remains `SpellInputPanes.cpp` through `ChangeSpellSlotInputPane`. Proof: target still references `SpellInputPanes.cpp`, generated `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` refreshed, and no IDA DB edit command was run.
- [x] First-draft C++ to apply: preserve exact existing formal block shown in this report; do not add vtable stores; do not change `GetString` spelling unless supervisor explicitly chooses broader localization normalization. Proof: post-validator source and generated output both show `ChangeSpellSlotInputPane::ChangeSpellSlotInputPane() : CharArgsInputPane(g_pLanguageMan->GetString(45)) {}` with no vtable stores.
- [x] Historical/stale assumptions and negative evidence to preserve: no direct xrefs/pointer/immediate/VA/RVA route to `0x005b3220`; generated tracker/coverage/source comments are stale and must refresh through validator rather than manual edits. Proof: target current MCP section records `xrefs_to`, `find data_ref`, `find code_ref`, `find immediate`, and `find_bytes` negative evidence; generated refresh was validator-owned.
- [x] Wave2/Wave3 artifacts: treated only as leads; current recommendation is live-MCP backed. Proof: target B006 section cites live MCP session `80de0a67`; no Wave2/Wave3 material was incorporated as authority.
- [x] Open questions to close/document: raw constructor retained without direct route remains confidence cap; localization method spelling remains non-blocking style caveat. Proof: target `## Score Rationale` and current MCP section state those as remaining caps, not C++ blockers.
- [x] Validators to run after implementation: final target validator run from `E:\NTK\GhidraBridge\source-3\project-documentation` was `python .\tools\validator.py --mode file --file by-memory\0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md --apply --queue-timeout 240 --wait-generated`. Proof: command_id `000000000900`, command_timestamp `2026-06-25T01:51:33-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, `generated_refresh_command_id: 000000000900`, `generated_refresh_timestamp: 2026-06-25T01:51:33-04:00`. Earlier validator command `000000000899` at `2026-06-25T01:50:41-04:00` also exited `0` with `ok: 1` and generated refresh completed, but was superseded by the final prose correction and command `000000000900`.
- [x] Generated report refresh expected: yes, through validator only. Proof: final generated readback showed `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` and `auto-generated/-ag-coverage-report-by-memory.md` at `validator-command-id: 000000000902`, `validator-refreshed-at: 2026-06-25T01:52:17-04:00`, with UID `0001M7` at `Completion:88 | Confidence:91`; `auto-generated/-ag-research-tracker.md` was newer at `validator-command-id: 000000000903`, `validator-refreshed-at: 2026-06-25T01:52:17-04:00`, with UID `0001M7` row `88/91`. B006 did not manually edit `auto-generated/*`, project-level files, manual `-coverage-report.md`, validator state/cache, or IDA DB.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: active `goal.md` is `B006-implement-0001M7-change-spell-slot-input-pane-raw-constructor-20260625`.
- [x] All accepted target/support doc details incorporated at report-level detail or marked already present/superseded/not applicable. Proof: target page now carries accepted B006 current MCP evidence/rationale; support docs were checked and left unchanged because they already contained same-or-greater constructor/source placement evidence without contradiction.
- [x] Metadata/score changes applied or explicitly not applied with reason. Proof: target source and generated output are `88/91`; owner/emitter/reconstructable metadata unchanged by design.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target current MCP section preserves no-route negatives; `## Score Rationale` keeps no-function/no-direct-route and localization spelling as caps, not blockers.
- [x] Open questions documented with evidence-backed unresolved rationale. Proof: target `## Score Rationale` documents retained raw-body/no-route and localization method spelling as remaining non-final caps.
- [x] Scoped validators run and command id/timestamp/exit/ok/generated-refresh state recorded. Proof: final command `000000000900`, timestamp `2026-06-25T01:51:33-04:00`, exit `0`, `ok: 1`, generated refresh completed. Validator warnings noted: pre-existing `missing_ref_uid 0003HJ` and broad stale/missing registry/coverage rows; no warning blocked UID `0001M7` source/generation.
- [x] Leases taken only for immediate edited files and released immediately after edit/validator batch. Proof: B006 leased only `by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md`; release command returned `Success`; post-release current lease report showed no active B006 target lease.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: none remain unapplied; support edits were intentionally excluded as already present/sufficient, and no manual coverage/generated/project/IDA edit was allowed or performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001M7-ChangeSpellSlotInputPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001M7-ChangeSpellSlotInputPaneRawConstructor-source-quality.md","timestamp":"2026-06-25T01:59:17","uid":"0001M7"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001M7-ChangeSpellSlotInputPaneRawConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001M7-ChangeSpellSlotInputPaneRawConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001M7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
