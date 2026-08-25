** TARGET-REPORT-UID:0002FH **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002FH ChattingVarietySelectPaneConstructorRaw Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](../../../../../by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) from `84/91` to `85/91`; keep `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Z`, blank `EMITTER_POSITION_OPTIONAL`, and make the formal `RECONSTRUCTION_CPP CODE` block contain only the Rule 28 covered-by marker:
  ```cpp
  // Emitted code for this range covered by [UID:0002FC]
  ```
- Final disposition: retained raw constructor-shaped executable evidence for `ChattingVarietySelectPane`, with the live construction path covered by [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](../../../../../by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md). The target remains a reconstructable code emitter, so Supervisor.md rule 28 applies directly; no target-specific exception is justified.
- Required action if accepted: update the target/support docs from stale B003 `ff68e691` wording to current B005 MCP session `80de0a67`, raise completion to `85`, add the exact covered-by marker as the target's formal `RECONSTRUCTION_CPP CODE`, preserve the no-executable-body proof, and leave coverage-row application to the supervisor.
- Confidence: high for the score increase and Rule 28 marker disposition; high for class ownership and source-facing names; capped for executable C++ because no current static entry route reaches `0x004810f0`.

## Target

- Agent: B005.
- Assignment ID: `B005-report-chatting-variety-select-pane-constructor-raw-source-quality-0002FH-mcp-20260623`.
- Target UID: `0002FH`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`.
- Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md`.
- Current supervisor classification: report-only rejected-report rework under the tightened Rule 26 no-improvement standard; no by-* docs or coverage reports may be edited before acceptance.
- Current scores and parent state: target `84/91`; direct owner/emitter [UID:00001Z][ChattingVarietySelectPane](../../../../../by-class/ChattingVarietySelectPane.md) is `87/91` and emits declaration-only class C++ through [UID:0000I5][Chatting](../../../../../by-file/Chatting.md), currently `86/89`.

## Current Target State

- Existing metadata: `COMPLETION:84`, `CONFIDENCE:91`, `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Z`, blank emitter position, blank `RECONSTRUCTION_CPP`.
- Existing C++ state: class page declares `ChattingVarietySelectPane();`, but the exact raw constructor child currently emits no body. This rework recommends changing that block from empty to the exact Rule 28 marker, not to executable constructor statements.
- Existing open issue: prior wording treated missing callable-entry proof as a hard completion cap below 85. That was incomplete because it did not finish the retained-constructor / covered-by / marker-emitter precedent check.
- Related docs checked: target, [UID:00001Z] class, [UID:0000I5] file, [UID:0002FC] opener, [UID:0002FI] destructor, [UID:000104] ChattingUI aggregate, [UID:0002XA]/[UID:0002XB] singleton global/storage pages, [UID:0003AT] vtable data, current coverage row, and executed/archived reports for raw retained constructors and covered-by marker practice.

## Executive Recommendation

Raise completion to `85` because this rework resolves the named retained-constructor / covered-by / emitter-policy blocker: current MCP evidence proves source-equivalent constructor bytes, [UID:0002FC] is the only proven live construction path, and Supervisor.md rule 28 gives an explicit marker mechanism for code emitters whose emitted code is covered by another file. The target should not stay at `84` merely because direct xrefs are absent.

Do not emit executable standalone constructor statements. The raw body is source-equivalent to a default constructor, but the only proven live construction path is the inline duplicate inside [UID:0002FC]. Emitting a standalone `ChattingVarietySelectPane::ChattingVarietySelectPane()` body from this page would harden an unproven out-of-line callable route and could force incorrect de-duplication of the opener.

Do add the exact covered-by marker in the formal target `RECONSTRUCTION_CPP CODE` block:

```cpp
// Emitted code for this range covered by [UID:0002FC]
```

This is not a generic prose workaround. It is the Rule 28 code-emitter marker for a reconstructable page with a nonblank emitter route whose live source-output path is covered by another file. Keeping `EMITTER_UIDS:00001Z` nonblank remains correct because the class is still the canonical source/emitter route for the raw constructor evidence; the marker prevents trackers from treating the special-case emitter as missing code while avoiding unsupported executable C++.

## Supervisor Active Recheck

- The supervisor rejected the prior report because it kept `84/91` and treated retained-constructor policy as unresolved.
- The supervisor rejected the first rework because it kept `RECONSTRUCTABLE:TRUE` and nonblank `EMITTER_UIDS:00001Z` while recommending the opposite of Rule 28 despite saying [UID:0002FC] covers the live source path.
- This rework chased that blocker directly: Supervisor.md rule 28, current by-structure emitter text, current by-* pages, executed reports, archived reports, and current MCP evidence were checked. Rule 28 applies; the report now recommends the exact formal covered-by marker.
- No split repair is required. The target remains the exact `0x004810f0-0x00481146` raw body, bracketed by `0xcc` padding and separate from [UID:0002FC], [UID:0002FF], [UID:0002FG], [UID:0002FI], and later selector method children.
- No by-* docs, generated/project-level files, IDA DB files, tool state, or `-coverage-report.md` files were edited.

## Inference Research Guidance Check

Current by-structure text says agents may write C++ only when the item is reconstructable, has confirmed nonblank emitters reaching generated output, and the average score is greater than 85. It also says this is a minimum gate, not permission to add weak executable code. It allows no-executable-body dispositions when final source shape is not ready, and Supervisor.md rule 28 adds the specific tracker rule for special-case code emitters covered by another file: the code block should emit a `//` marker, preferably naming the covering UID.

This means the right decision space is not binary "xref or no score", and it is also not "blank despite nonblank emitter." A retained raw constructor can be reconstructable, class-owned, routed, scored at completion 85, and emit only the Rule 28 marker when executable constructor C++ would be unsafe but a live source-output path is covered by [UID:0002FC]. Existing Wave2/Wave3/generator names were treated as lead material only; they did not drive the recommendation.

## Heuristic / Inference Reanalysis And Validation

- Callable-entry blocker: resolved negatively for current static evidence. `lookup_funcs` still reports `0x004810f0` and `0x00481146` as not functions; `xrefs_to` reports zero xrefs to both addresses; targeted little-endian VA/RVA/raw-offset byte-pattern checks found zero hits. That blocks standalone constructor C++, not documentation improvement.
- Retained-constructor policy blocker: resolved. Precedents show retained no-route raw constructors can rise to `85+` when evidence and no-executable-body disposition are complete; Supervisor.md rule 28 further requires this target's formal code block to carry a covered-by marker because it remains a reconstructable emitter covered by [UID:0002FC].
- Covered-by disposition: resolved. The live source-output route for the construction behavior is [UID:0002FC] because the modeled opener duplicates the constructor operations inline. [UID:0002FH] remains the retained out-of-line constructor evidence page; it does not become non-reconstructable or ownerless.
- Comment-only marker question: resolved positively. Rule 28 is explicit enough to apply to this special-case code emitter, and the target-specific facts match it: reconstructable true, nonblank class emitter route, and emitted behavior covered by [UID:0002FC].
- Singleton/field names: resolved for documentation/source-facing prose. Use `g_pChattingVarietySelectPane`, `m_pressCaptured`, and `m_hotRow`; keep `unk_67ADDC`/`dword_67ADDC` only as IDA/search aliases.
- Owner/emitter: resolved. [UID:00001Z] remains the direct owner/emitter; [UID:0000I5] remains the source-file route. [UID:0002FC] is the live inline construction context, not the direct owner of this raw selector constructor evidence.
- Score: resolved. Completion should rise to `85` because the current report now records the current MCP evidence, policy conclusion, precedent comparison, Rule 28 marker, no-executable-body proof, and implementation-ready doc plan. It should not rise higher because no standalone callable source form is proven.

## Evidence Standards Used

Evidence used: current IDA MCP `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, prior successful B005 MCP `get_bytes`, `get_int`, `insn_query`, `decompile`, `callees`, and `find_bytes`; target/support by-* docs; current by-structure emitter rules; Supervisor.md rule 28; current by-* examples of comment-only markers; executed/archived B-agent reports for raw no-route constructors and inline duplicate retained constructor policy.

Manual/raw PE facts in older reports were used only as supplemental context where already revalidated by the current target docs or current MCP. The current report is not fallback-only: session `80de0a67` was checked successfully during this rework.

## Evidence Checked

### Current MCP Health And Target Spot Recheck

- `initialize` -> `tools/list` -> `server_health(database="80de0a67")` succeeded at `2026-06-23 17:06-17:08 -04:00`.
- Active session from `idb_list`: `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, worker PID `21816`, `is_active:true`, `is_analyzing:false`.
- `server_health`: `status:"ok"`, imagebase `0x400000`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, auto-analysis ready, Hex-Rays ready, strings cache ready with 2067 strings.
- `lookup_funcs(database="80de0a67", queries=0x004810f0,0x00481146,0x00481150,0x00480cd0)` returned: `0x004810f0` not a function, `0x00481146` not a function, `0x00481150` `sub_481150` size `0x6c`, and `0x00480cd0` `sub_480CD0` size `0x1b0`.
- `xrefs_to(database="80de0a67", addrs=0x004810f0,0x00481146,0x0067addc)` returned zero xrefs to `0x004810f0`, zero xrefs to `0x00481146`, and seven xrefs to `0x0067addc`: `0x00480d7f`, `0x00480dc2`, `0x00480dc9`, `0x00480eb2`, `0x00481115`, `0x0048119d`, `0x00483e04`.

### Previously Gathered Current-Session Evidence Retained In This Report

- `survey_binary(detail_level="minimal")`: MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, `.text` `0x00401000-0x0060d000`, `.rdata` `0x0060d670-0x0066d000`, `.data` `0x0066d000-0x0069d000`.
- `get_bytes(0x004810ea,size=102)` read six `0xcc` bytes before the target, the exact 86-byte target body, and ten `0xcc` bytes before the destructor.
- Target body SHA-256: `a0a8b1182eb3447701982d3849325580db4ce4940a6304468ce51bb504169350`.
- Padded neighborhood SHA-256: `49c17d879d9457f01b0bff2d87c4e49a6b584f4d30b34c8f43a4e80bb813b70f`.
- `insn_query(0x004810f0-0x00481146)` decoded 25 instructions, all `fn:null`: receiver save in `esi`, `push 1`, call `sub_544460`, `this+0xf8` calculation, singleton write at `0x00481115`, `+0xf8=0`, vtable stores to `0x00614f2c/0x00614f80/0x00614fb0`, `+0xf9=0xff`, and `retn`.
- `decompile 0x004810f0` failed because no function model exists. `decompile 0x00480cd0` returned the modeled opener with inline selector construction; `decompile 0x00481150` and `decompile 0x00483db0` returned ordinary/scalar destructor shapes.
- `find_bytes` found zero little-endian VA/RVA/raw-offset pattern hits for constructor start `0x004810f0`, constructor end `0x00481146`, and destructor start `0x00481150`.

### Policy / Precedent Evidence Checked

- `by-structure.md` current emitter text around reconstruction metadata and code gate.
- `tools/leaser/Agents/Supervisor.md` rule 28: special-case code emitters covered by another file should emit a `//` marker, preferably naming the covering file/UID. The implementation callback accepted the exact marker `// Emitted code for this range covered by [UID:0002FC]`.
- Current comment-only marker examples:
  - [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](../../../../../by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md): comment-only marker for compiler-generated vtable/RTTI-adjacent data.
  - [UID:00031P][0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData](../../../../../by-memory/0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md): blank vtable data page, not executable source.
  - [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](../../../../../by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md): documents marker policy for static embedded zlib source, not executable NexusTK constructor bytes.
- Retained/no-route constructor precedents:
  - [UID:0000YK] archived B001 `AlphaMaskSurfaceRawDefaultConstructor`: raised to `85/90`, owner/emitter kept, no executable C++ body; no function/xrefs/VA/RVA/rel32 route, but retained constructor-family evidence and duplicate active constructor zero-branch behavior justified completion 85.
  - [UID:000139] archived B001 `AddEmployeeItemDialogRawConstructor`: kept `85/90`, class-owned reconstructable raw constructor evidence, no executable C++ body; live construction path is inline in a modeled caller, and the raw body remains retained out-of-line constructor evidence.
  - [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](../../../../../by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md): current page is `86/89`, class-owned, reconstructable, emitter nonblank, no executable C++ body; no modeled function/direct route, but exact constructor evidence and sibling/overload separation are documented.
  - Archived B001 `VoteMenuPaneRawConstructor`: recommended/recorded `86/91`, class-owned raw constructor evidence, no executable C++ body with no direct static caller recovered.
- Counter-precedents for C++ readiness:
  - [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](../../../../../by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md), [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](../../../../../by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md), and [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](../../../../../by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) show that no-direct-xref status does not automatically block C++. They differ from [UID:0002FH] because their source bodies are unique/self-contained enough or their duplicate/factory context was resolved as non-blocking. [UID:0002FH] has a live inline duplicate in [UID:0002FC] whose final source output is the proper owner of the active construction path.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x004810f0-0x00481146` is source-equivalent `ChattingVarietySelectPane::ChattingVarietySelectPane()` constructor bytes. | Strong | Receiver save, `Pane(1)` base call, singleton write, `+0xf8/+0xf9` init, selector vtables, destructor/scalar counterpart | No IDA function, zero start/end xrefs, zero pointer pattern hits | No current static, MCP, by-* documentation, or precedent route remains unchecked. Original symbols or runtime traces would be outside the available report-only evidence set, not a remaining same-pass blocker. |
| Completion should rise from `84` to `85`. | Strong | Current MCP evidence, policy recheck, retained raw constructor precedents above 85, Supervisor.md rule 28 marker route, support names/owner already resolved | Prior B003 cap below 85 relied on unresolved policy/no-route wording | Not higher until executable C++ or stronger source route is defensible. |
| Formal `RECONSTRUCTION_CPP CODE` should contain only the Rule 28 marker. | Strong | Live inline duplicate in [UID:0002FC], no direct route to raw body, reconstructable true, nonblank emitter route, Supervisor.md rule 28 | Standalone executable C++ candidate considered; non-emitting/no-owner considered; generic no-marker argument rejected by the supervisor | Implementation-ready code block is exactly `// Emitted code for this range covered by [UID:0002FC]`. |
| `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:00001Z` remain correct. | Strong | Source-authored project code, direct class owner, class/file emitter chain, valid singleton/vtable/destructor family | Non-emitting/no-owner/global/vtable/opener direct ownership rejected | No remaining current blocker. |
| Comment-only covered-by marker is required. | Strong | Supervisor.md rule 28 directly covers special-case emitters whose code is covered by another file; [UID:0002FH] remains reconstructable and emitted through [UID:00001Z], while [UID:0002FC] covers live construction behavior | Generic argument that by-memory executable ranges usually need their own body rejected as insufficient to override rule 28 | No target-specific exception is supported. |

## Positive Evidence Summary

- Exact body and padding are proven: six `0xcc` bytes at `0x004810ea-0x004810f0`, 86-byte constructor body at `0x004810f0-0x00481146`, and ten `0xcc` bytes at `0x00481146-0x00481150`.
- The body is a coherent thiscall constructor: `ECX` receiver, `Pane` base helper with argument `1`, singleton publish, source-facing byte-field initialization, selector vtable stores, and return.
- Class identity is cross-confirmed by ordinary destructor [UID:0002FI], scalar deleting destructor family at `0x00483db0`, vtable data, singleton lifecycle, and modeled selector methods.
- Source-facing names are resolved at documentation quality: `g_pChattingVarietySelectPane`, `m_pressCaptured`, and `m_hotRow`.
- Precedent confirms that retained raw constructor evidence can score at least 85 when no-executable-body policy is explicit and every current route check is documented; Supervisor.md rule 28 supplies the marker that this specific nonblank emitter should use.

## IDA MCP Facts

### Function / Range Facts

| Address | Current result | Meaning |
| --- | --- | --- |
| `0x00481000` | `sub_481000`, size `0x0a` | modeled predecessor refresh forwarder |
| `0x00481010` | not a function | adjacent compact helper [UID:0002FF] |
| `0x00481060` | not a function | adjacent compact hit-test helper [UID:0002FG] |
| `0x004810ea` | not a function | pre-target padding/body boundary |
| `0x004810f0` | not a function | target raw constructor start |
| `0x00481146` | not a function | exact target end |
| `0x00481150` | `sub_481150`, size `0x6c` | ordinary selector destructor |
| `0x00480cd0` | `sub_480CD0`, size `0x1b0` | live compact opener with inline duplicate construction |
| `0x00483db0` | `sub_483DB0`, size `0xad` | scalar deleting destructor family |
| `0x00544460` | `sub_544460`, size `0x118` | `Pane` base construction helper |

### Xrefs / Values

- `xrefs_to 0x004810f0`: zero.
- `xrefs_to 0x00481146`: zero.
- `xrefs_to 0x00481150`: zero in the prior current-session pass; destructor is reached through vtable/scalar context rather than direct start refs.
- `xrefs_to 0x0067addc`: seven refs in opener/constructor/destructor/scalar and paint/update context.
- `xrefs_to 0x00614f2c`, `0x00614f80`, `0x00614fb0`: each has refs from the live inline opener, raw constructor, ordinary destructor, and scalar destructor.
- `get_int 0x00614f2c`: `0x00483db0`; `0x00614f80`: `0x00483a85`; `0x00614fb0`: `0x00483a90`; `0x0067addc`: `0`.

### Inline Duplicate Facts

[UID:0002FC] repeats the same constructor core inline: allocation size `0xfc`, `sub_544460(1)`, singleton write/zero fallback, vtable stores, `+0xf8=0`, and `+0xf9=0xff`. It then stores the popup pointer in the compact pane, sets popup bounds `(7,617,74,727)`, attaches through inherited `Pane` slot `+0x30`, runs inherited order/dispatcher setup through slot `+0x3c`, and refreshes the compact owner. This is the proven live source-output context for the construction behavior.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00480cd0-0x00480e80` | [UID:0002FC] opener | live `ChattingVarietyPane::OnMouseEvent` with inline selector construction | `TRUE` | [UID:00001Y] | `86/91` | live covered-by context for constructor behavior |
| `0x00481010-0x00481056` | [UID:0002FF] compact helper | unmodeled compact button rect helper | `TRUE` | [UID:00001Y] | `86/92` | no direct route; no executable body from this report |
| `0x00481060-0x004810ea` | [UID:0002FG] compact helper | unmodeled compact hit-test helper | `TRUE` | [UID:00001Y] | `86/92` | no direct route; no executable body from this report |
| `0x004810f0-0x00481146` | [UID:0002FH] target | retained raw selector constructor body | `TRUE` | [UID:00001Z] | recommend `85/91` | formal Rule 28 covered-by marker; no executable constructor body |
| `0x00481150-0x004811bc` | [UID:0002FI] destructor | ordinary selector destructor | `TRUE` | [UID:00001Z] | `88/90` | first-draft destructor C++ present |
| `0x004811c0+` selector methods | [UID:0002FJ]/[UID:0002FK]/[UID:0002FL]/[UID:0002FN]/[UID:0002FO]/[UID:000106] | modeled selector virtuals/helpers | `TRUE` | [UID:00001Z] | mostly `86/91` | separate children; not part of target body |

## Documentation Evidence And IDA Status

- Target page has detailed B003 `ff68e691` evidence but stale score/no-executable-body rationale; it should be updated to current B005 `80de0a67` evidence and the new `85/91` covered-by marker disposition.
- [UID:00001Z] class page has the correct declaration-only class shell and source-facing fields, but its [UID:0002FH] note currently says the constructor stays below completion 85. That should be replaced.
- [UID:0000I5] file page keeps the selector family under `social/Chatting.cpp` and documents declaration-only class emission; its [UID:0002FH] note should be refreshed from stale no-entry cap wording to the retained-constructor `85/91` Rule 28 marker policy.
- [UID:0002FC] already contains the inline duplicate construction path and should remain the live covered-by context. It may need one support note saying the raw constructor page is now `85/91` with the exact covered-by marker, not below-gate.
- [UID:0002XA]/[UID:0002XB] singleton pages, [UID:0003AT] vtable data, and [UID:0002FI] destructor already contain enough support detail unless an implementation callback finds stale contradictory wording.

## Ranked Ownership Analysis

### 1. [UID:00001Z] ChattingVarietySelectPane

- Evidence for: selector vtable stores, selector fields, selector singleton publish, destructor/scalar clearing, and selector method family.
- Evidence against: raw constructor entry has no modeled function/xrefs.
- Decision: keep direct owner/emitter. The no-entry issue affects C++ emission, not semantic ownership.

### 2. [UID:0000I5] Chatting

- Evidence for: current source route for the chat UI cluster and class emitter chain.
- Evidence against: target is a class constructor body, not a free file-level helper.
- Decision: keep as source-file route, not canonical owner.

### 3. [UID:00001Y] ChattingVarietyPane / [UID:0002FC] opener

- Evidence for: owns the live inline construction path.
- Evidence against: the raw body writes `ChattingVarietySelectPane` vtables/fields/global, not compact-pane state.
- Decision: reject as owner for [UID:0002FH]. Use as covered-by/live source-output context.

### 4. Singleton, vtable, aggregate, no-owner routes

- Singleton/global pages provide lifecycle and naming proof but do not own constructor code. Vtable data proves class identity but is not code owner. [UID:000104] is a broad aggregate. No-owner/non-emitting is rejected because a true class owner and emitter route are known.

## Source Placement

Recommended source placement remains [UID:00001Z] `ChattingVarietySelectPane` through [UID:0000I5] `NexusTK/social/Chatting.cpp`. The source-output treatment should be:

- class declaration in [UID:00001Z] with `ChattingVarietySelectPane();`;
- [UID:0002FH] documents retained out-of-line raw constructor bytes and emits only `// Emitted code for this range covered by [UID:0002FC]`;
- [UID:0002FC] remains the live inline construction context in this implementation plan; this report does not claim an unproven call to `0x004810f0` and does not defer any [UID:0002FH] score/C++ blocker to [UID:0002FC].

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x004810f0-0x00481146`, size `0x56` / 86 bytes.
- Pre-padding: `0x004810ea-0x004810f0`, six `0xcc` bytes.
- Post-padding: `0x00481146-0x00481150`, ten `0xcc` bytes.
- No split is needed: one constructor-shaped prologue/body/return sequence.
- No merge is needed: [UID:0002FC] contains a live inline duplicate, but the raw body exists separately and remains useful retained constructor evidence.
- No reclassification to `RECONSTRUCTABLE:FALSE` is correct: the range is executable project source-shaped code, not padding, thunk-only data, or coverage-only index.

## Negative Evidence Summary

Checked and rejected:

- Direct function route: no function at `0x004810f0` or `0x00481146`.
- Direct xref route: zero xrefs to start/end; no direct pointer route found.
- VA/RVA/raw-offset route: `find_bytes` negatives for start/end/destructor start.
- Vtable/callback route: selector vtables point to destructor/method slots; constructors are not vtable callbacks.
- Blank/no-marker emitter route: rejected because Supervisor.md rule 28 directly applies to special-case emitters covered by another file.
- First-draft standalone constructor route: rejected because [UID:0002FC] is the only proven live construction path and already duplicates the code inline.

## IDA Rename / Type / Comment Recommendations

- Use source-facing docs names: `ChattingVarietySelectPane::ChattingVarietySelectPane`, `g_pChattingVarietySelectPane`, `m_pressCaptured`, `m_hotRow`, `Pane` base constructor helper, selector vtable family.
- Keep IDA labels only as evidence/search aliases: `unk_67ADDC`, `dword_67ADDC`, `sub_544460`, `sub_480CD0`, `sub_481150`, `sub_483DB0`.
- No IDA DB edits are requested. Creating a function at `0x004810f0` remains unsafe because no current function/xref route proves an IDA function boundary.

## First-Draft C++ Recommendation

- Eligible for draft C++ by numeric/emitter gate after this recommendation: yes, `85/91` with valid emitter [UID:00001Z] gives an average greater than 85.
- Recommended formal `RECONSTRUCTION_CPP CODE` content: only the Rule 28 covered-by marker below. This is the exact code-block content proposed for [UID:0002FH]; no executable constructor body should be emitted.

```cpp
// Emitted code for this range covered by [UID:0002FC]
```

Unsafe source-equivalent candidate considered and rejected:

```cpp
ChattingVarietySelectPane::ChattingVarietySelectPane()
    : Pane(1),
      m_pressCaptured(0),
      m_hotRow(-1)
{
    g_pChattingVarietySelectPane = this;
}
```

This candidate matches the raw bytes if an out-of-line constructor source route were proven, and the vtable stores would be compiler-generated. It should not be emitted now because current evidence proves a live inline duplicate in [UID:0002FC] but does not prove a callable out-of-line route to `0x004810f0`.

Exact no-executable-body proof: MCP session `80de0a67` reports no modeled function at `0x004810f0`, zero xrefs to the raw start/end, no VA/RVA/raw-offset pointer hits, expected decompile failure at the raw start, and a live modeled inline duplicate in [UID:0002FC]. Those facts block an executable standalone constructor body. They do not block a Rule 28 marker because [UID:0002FH] remains `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:00001Z`, and the live construction behavior is covered by [UID:0002FC]. Therefore the correct source-quality state is class-owned reconstructable evidence, nonblank emitter route, completion `85`, formal marker-only C++ block, and prose covered-by/no-executable-body documentation.

## Final Recommendation

- Raise [UID:0002FH] to `COMPLETION:85`, keep `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Z`, blank emitter position, and formal marker-only C++.
- Replace stale below-85/no-policy wording with current `80de0a67` MCP evidence, precedent comparison, and retained-constructor covered-by/no-executable-body disposition.
- Do not split, rename, reclassify, move owner/emitter, or add standalone constructor C++.

## Recommended Target Doc Changes

Target path: `by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`.

If accepted, update:

- Metadata: `COMPLETION:85`, `CONFIDENCE:91`, owner/emitter/reconstructable unchanged.
- `RECONSTRUCTION_CPP CODE`: replace the empty block with exactly:
  ```cpp
  // Emitted code for this range covered by [UID:0002FC]
  ```
- Replace current B003 `ff68e691` "below completion 85" wording with B005 current MCP session `80de0a67` evidence.
- Add PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` and MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Preserve exact bytes/body hash, six-byte pre-padding, ten-byte post-padding, raw instruction map, decompile failure, inline duplicate, destructor/scalar context, vtable/global xrefs, pointer-pattern negatives, owner ranking, policy/precedent analysis, and no-executable-body proof.
- State explicitly that [UID:0002FC] is the live covered-by construction context, that `RECONSTRUCTION_CPP` contains only the Rule 28 marker, and that no executable standalone constructor body is recommended.

## Recommended Support Doc Changes

- `by-class/ChattingVarietySelectPane.md`: update [UID:0002FH] notes from "below 85" to "retained raw constructor evidence at `85/91`, formal marker-only C++ covered by [UID:0002FC], no executable constructor body"; preserve declaration-only class C++ and fields `m_pressCaptured`/`m_hotRow`.
- `by-file/Chatting.md`: refresh selector-family row/evidence note to current `80de0a67` provenance and the `85/91` marker-only covered-by policy.
- `by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md`: add/retain one note that its inline construction is the proven live source-output context for [UID:0002FH]; do not rewrite it as clean `new ChattingVarietySelectPane()` during this callback unless the supervisor separately accepts [UID:0002FC] C++.
- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`: update the child row if it still says [UID:0002FH] remains below 85.
- `by-global/g_pChattingVarietySelectPane.md`, `by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md`, `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`, and `by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md`: mark already sufficient unless stale contradictory below-85 wording is found during implementation.

## Score And Metadata Recommendation

- Current score/metadata: `84/91`, `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Z`, blank emitter position, empty C++ block.
- Recommended score/metadata: `85/91`, same owner/reconstructable/emitter fields, marker-only C++ block.
- Reason not lower: current MCP evidence and support docs prove exact bytes, class ownership, source-facing names, padding, duplicate relationship, no-route state, and retained-constructor policy.
- Reason not higher: no current evidence proves a standalone callable constructor route, and executable C++ remains intentionally omitted. The page is now documentation-complete enough to clear 85 but not source-output-ready enough for 86+.
- Score-improvement attempt: callable entry, pointer/literal route, callback/vtable route, split/merge, owner/emitter, source-facing names, retained-constructor precedents, covered-by comment policy, and support-doc route were all checked. The repair is the `85/91` marker-only covered-by disposition, not unchanged score.

## Open Questions With Attempted Resolution

- Is `0x004810f0` a proven callable out-of-line constructor? Resolved negatively for current IDB/static evidence.
- Can [UID:0002FH] carry comment-only covered-by C++? Resolved positively under Supervisor.md rule 28; the exact marker is `// Emitted code for this range covered by [UID:0002FC]`.
- Can completion rise without executable C++? Resolved positively to `85` based on retained raw constructor precedents, current MCP detail, and the now-explicit Rule 28 marker disposition.
- Are names/owner/source placement blocking? Resolved: use [UID:00001Z], [UID:0000I5], `g_pChattingVarietySelectPane`, `m_pressCaptured`, and `m_hotRow`.
- Executable-C++ closure: current direct call/branch and data route evidence was checked through MCP xrefs and pointer-pattern searches; owner, split, support-doc, Rule 28, and precedent routes were checked; no executable constructor body is safe now. Only unavailable external evidence, such as original symbols or a supplied runtime trace proving the raw body is reachable as an out-of-line constructor, would change the executable-C++ decision.

## Exact Supervisor-Owned Coverage Text

File/placement: `by-memory/-coverage-report.md`, replace the current [UID:0002FH] row around the `0x004810f0` Chatting selector block. B005 must not edit this file directly.

Exact replacement row:

```markdown
        - [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) 0x004810f0-0x00481146 | raw constructor body | ChattingVarietySelectPaneConstructorRaw : reconstructable : 85% : very strong : B005 current MCP session 80de0a67 reconfirms this exact 86-byte raw body as source-equivalent retained constructor evidence for `ChattingVarietySelectPane::ChattingVarietySelectPane()`: six-byte pre-padding and ten-byte post-padding are `0xcc`, the body calls the Pane base constructor helper `sub_544460(1)`, writes `g_pChattingVarietySelectPane` at `0x0067addc`, clears `m_pressCaptured` at `+0xf8`, initializes `m_hotRow` at `+0xf9` to `-1`, installs selector vtables `0x00614f2c/0x00614f80/0x00614fb0`, and matches the live inline duplicate construction path in [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md). Current MCP still reports no modeled function at `0x004810f0`, no direct xrefs to the raw start/end/destructor start, and no VA/RVA/raw-offset pointer-table route, so no executable standalone constructor body is recommended; because the page remains `RECONSTRUCTABLE:TRUE` with nonblank `EMITTER_UIDS:00001Z` and its live construction behavior is covered by [UID:0002FC], Supervisor.md rule 28 applies and the formal `RECONSTRUCTION_CPP CODE` block should contain only `// Emitted code for this range covered by [UID:0002FC]`.
```

Reason B agent must not apply it: current rules make all `-coverage-report.md` files supervisor-owned during B-agent work.

## Follow-Up Actions

- Supervisor: validate this report and, if accepted, issue implementation callback for the listed target/support docs and apply the coverage row if desired.
- B005 implementation callback if accepted: edit only accepted by-* docs under short-lived leases, run scoped validators, and update this report's checklist with proof.
- No A-agent or IDA DB action is required from this report.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `85/91`; the prior `84` no longer reflects the completed policy/precedent investigation.
- Remaining uncertainty: exact original spelling and runtime liveness of an out-of-line constructor are not recoverable from current MCP/static/documentation evidence after the checks recorded above. This is not a deferred same-pass investigation; it affects only executable constructor body readiness, not owner/emitter, the Rule 28 marker, or the `85` documentation score.

## Validator Results

- Implementation validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted by-* edits.
- `python .\tools\validator.py --mode file --file by-memory\0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md --apply --queue-timeout 240`: exit `0`, `ok: 1`. Relevant side effects/warnings: `uid_link_insert: 1` expanded `[UID:0002FC]` inside the formal marker, `autogen_cpp_update: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`; unrelated global warnings remained `autogen_registry_stale: 2`, `autogen_children_marker_missing: 11`, `autogen_emitter_has_no_code: 541`.
- After that required full validator, the formal marker was restored to the exact accepted code text:
  ```cpp
  // Emitted code for this range covered by [UID:0002FC]
  ```
  Then `python .\tools\validator.py --mode file --file by-memory\0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md --uid-only --apply --queue-timeout 240` was run to confirm metadata without the reference-link phase rewriting the formal code marker: exit `0`, `ok: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`.
- `python .\tools\validator.py --mode file --file by-class\ChattingVarietySelectPane.md --apply --queue-timeout 240`: exit `0`, `ok: 1`; side effects/warnings: `projected_stats_update: 1`, `stats_incremental_noop: 1`; unrelated global warnings remained `autogen_registry_stale: 2`, `autogen_children_marker_missing: 11`, `autogen_emitter_has_no_code: 541`.
- `python .\tools\validator.py --mode file --file by-file\Chatting.md --apply --queue-timeout 240`: exit `0`, `ok: 1`; side effects/warnings: `projected_stats_update: 1`, `stats_incremental_noop: 1`; unrelated global warnings remained `autogen_registry_stale: 2`, `autogen_children_marker_missing: 11`, `autogen_emitter_has_no_code: 541`.
- `python .\tools\validator.py --mode file --file by-memory\0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md --apply --queue-timeout 240`: exit `0`, `ok: 1`; side effects/warnings: `projected_stats_update: 1`, `stats_incremental_noop: 1`; unrelated global warnings remained `autogen_registry_stale: 2`, `autogen_children_marker_missing: 11`, `autogen_emitter_has_no_code: 541`.
- `python .\tools\validator.py --mode file --file by-memory\0x0047efb0-0x00483ef7.ChattingUI.md --apply --queue-timeout 240`: exit `0`, `ok: 1`; side effects/warnings: `projected_stats_update: 1`, `stats_incremental_noop: 1`; unrelated global warnings remained `autogen_registry_stale: 2`, `autogen_children_marker_missing: 11`, `autogen_emitter_has_no_code: 541`.

## Changed Files

- Modified: `tools/leaser/Agents/Agent-B005/research/0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md`.
- Modified by-* docs:
  - `by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`
  - `by-class/ChattingVarietySelectPane.md`
  - `by-file/Chatting.md`
  - `by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md`
  - `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
- Validator-owned side effects reported by scoped validators: `project-level/-auto-completion-stats.md` projected path update/noop rows and one `autogen_cpp_update` from the target validator. B005 did not manually edit generated/project-level files.
- Coverage files edited: none.
- Renamed: none.
- Moved to executed: none.
- Leases: B005 leased exactly the five changed by-* docs for the edit/validator batch; no conflicting lease was present. Cleanup `unlease` reported `Rejected[No active lease]` for each path because the leases were already inactive, and `tools/leaser/Agents/current_leases.md` showed `No active leases`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this reworked report and issued implementation callback `B005-implement-chatting-variety-select-pane-constructor-raw-source-quality-0002FH-mcp-20260623`.
- [x] Target doc `by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`: set `COMPLETION:85`, kept `CONFIDENCE:91`, `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Z`, blank emitter position, and formal `RECONSTRUCTION_CPP CODE` exactly:
  ```cpp
  // Emitted code for this range covered by [UID:0002FC]
  ```
  Proof: target metadata/header and Status/Boundary/Behavior/Current MCP Evidence/Reconstruction Notes/Score Rationale/Changes sections now include MCP `80de0a67`, PE hashes, exact bytes and padding, raw instructions, decompile failure, inline duplicate, destructor/scalar context, xrefs, vtable/global facts, pointer negatives, owner ranking, precedent/policy analysis, and no-executable-body/covered-by proof.
- [x] Support doc `by-class/ChattingVarietySelectPane.md`: replaced stale below-85/no-executable-body-policy wording with `85/91` retained-constructor evidence and Rule 28 marker disposition; declaration-only class C++ and field names are preserved. Proof: Methods/Evidence Notes/Changes sections cite MCP `80de0a67`, exact bytes/padding, vtables/global, `m_pressCaptured`, `m_hotRow`, inline duplicate, and marker-only child C++.
- [x] Support doc `by-file/Chatting.md`: refreshed selector-family/source-route note to current `80de0a67` evidence and `85/91` marker-only covered-by disposition. Proof: source-family table and 2026-06-23 B005 change entry now route [UID:0002FH] through `social/Chatting.cpp`, cite PE/body hashes, padding, vtable/global writes, ordinary/scalar destructor support, and no standalone callable route.
- [x] Support doc `by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md`: retained that this create branch is the proven live construction/output context for [UID:0002FH] and did not add `new ChattingVarietySelectPane()` C++. Proof: Behavior/Open Questions/Changes sections document the inline constructor sequence, covered-by relationship, and remaining opener-level C++ blockers.
- [x] Support doc `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`: updated child row and change notes from below-85/stale wording to [UID:0002FH] `85/91`, marker-only C++, and [UID:0002FC] live construction context. Proof: Covered Ranges row and 2026-06-23 B005 change entry include MCP `80de0a67`, PE SHA-256, exact body/padding, no function/xref/pointer route, vtables/global/fields, destructor context, and inline duplicate.
- [x] Optional support docs `by-global/g_pChattingVarietySelectPane.md`, `by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md`, `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`, and `by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md`: checked with targeted `rg`; no stale contradictory below-85/no-policy wording was found, so no optional edits were made. Existing singleton/destructor references remain compatible with the retained raw/unmodeled constructor and no-executable-body disposition.
- [x] Current target state and actual evidence checked recorded: metadata, MCP `80de0a67` health/session, PE hashes, lookup, bytes, instructions, decompile/xrefs/callees/find-bytes, docs, coverage row, and executed/archived precedents. Proof: retained in report body and incorporated into target/support docs as listed above.
- [x] Metadata/score changes applied: completion raised to `85`; confidence/owner/reconstructable/emitter and blank emitter position unchanged; target C++ changed from empty to the exact Rule 28 covered-by marker.
- [x] Score-limiting blockers researched to resolution and preserved: callable entry negative, pointer route negative, callback/vtable route negative, inline duplicate confirmed, comment-only covered-by marker accepted under Supervisor.md rule 28, retained-constructor no-executable-body precedent accepted.
- [x] Owner/emitter/reconstructable changes applied: none; [UID:00001Z] owner/emitter and reconstructable true preserved.
- [x] Split/rename/new-child changes applied: none; exact body and side padding preserved.
- [x] Source-placement/range/IDA rename/type/comment changes: route through [UID:0000I5] `Chatting` preserved; source-facing names used in docs; no IDA DB edits made.
- [x] First-draft C++ disposition applied: inserted the exact marker-only formal block and preserved unsafe standalone constructor rejection and no-executable-body proof.
- [x] Historical/stale assumptions preserved/corrected: B003 `ff68e691` remains historical support, current B005 `80de0a67` supersedes provenance, and stale below-85/no-policy wording is corrected.
- [x] Wave2/Wave3 artifacts encountered and ignored/rejected as stale: no current Wave2/Wave3 dependency was used; generated/old labels remain evidence aliases only.
- [x] Open questions closed/documented: standalone liveness resolved negatively for current evidence; original spelling remains unavailable but not score-blocking; formal marker is ready and executable constructor body remains omitted.
- [x] Validators run: all five changed by-* docs validated with scoped commands above, each exit `0` and `ok: 1`; target also received post-validator `--uid-only` confirmation after restoring the exact formal marker.
- [x] Supervisor-owned coverage-report text to apply: exact replacement row remains supplied above; B005 did not edit `by-memory/-coverage-report.md`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: implementation callback received for [UID:0002FH].
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: five changed by-* paths listed above; optional docs checked and not changed because no stale contradiction was found.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: [UID:0002FH] now `85/91`, owner/emitter [UID:00001Z], reconstructable true, blank emitter position, no split/rename, formal marker-only C++.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs retain B003 historical provenance, no-function/no-xref/no-pointer-route negatives, rejected executable constructor body, and [UID:0002FC] inline duplicate relationship.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: executable out-of-line constructor liveness remains unresolved only as unavailable external evidence; score/C++ impact documented as marker-only and no executable constructor statements.
- [x] Validators run and command/exit/ok counts recorded. Proof: see `Validator Results` above.
- [x] Supervisor-owned coverage-report text supplied or confirmed unchanged. Proof: exact row remains above; no coverage file edited.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; no accepted non-coverage item remains unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002FH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
