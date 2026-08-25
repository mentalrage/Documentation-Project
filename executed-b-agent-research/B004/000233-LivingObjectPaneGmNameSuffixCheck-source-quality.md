** TARGET-REPORT-UID:000233 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000233 LivingObjectPaneGmNameSuffixCheck Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:000233] from `84/92` to `88/92`, keep owner/emitter routing through [UID:0000KU] `by-file/LivingObjectPane.md`, and add first-draft method C++ as `bool LivingObjectPane::HasGMNameSuffix() const`.
- Final disposition: implementation-ready if accepted. This target is a real IDA function, has a proven direct caller route, has exact `_wcsicmp(L"GM")` behavior, and is narrow enough for exact child C++. Keep the score capped below final because original method spelling and the exact class member name for the UTF-16 name buffer remain inferred.
- Required action: update the target page and synchronize the LivingObjectPane file/class support docs. Do not edit coverage reports directly; the exact supervisor-owned replacement row is supplied below.
- Confidence: high for range, behavior, direct route, owner/emitter, and source-shaped C++; medium for original source spelling of the method and name-buffer field.

## Supporting Research

## Target

- Target UID: `000233`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\000233-LivingObjectPaneGmNameSuffixCheck-source-quality.md`
- Source queue/report row: `project-level/-auto-completion-stats.md` lists `000233 | 84 | 92 | 88.0`; `auto-generated/-ag-memory-coverage.md` routes it as emitting through `auto-generated/NexusTK/map/LivingObjectPane.cpp`; `by-memory/-coverage-report.md` has the current `84% : strong` row.
- Current supervisor classification: report-only MCP-backed source-quality recheck for `B004-report-living-object-pane-gm-name-suffix-check-source-quality-000233-mcp-20260623`.
- Current scores and parent state: target is `COMPLETION:84`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, blank emitter position, blank C++.

## Current Target State

- Existing metadata: [UID:000233] is attached to [UID:0000KU] `LivingObjectPane`, reconstructable, and emitted by the same file owner.
- Existing owner/emitter/reconstructable state: correct and should stay unchanged. The direct receiver is the living object, while the only known caller in `MapPane` consumes the result and does not own the method body.
- Existing C++/emitter state: blank C++. The page says C++ was blank because final method name and field names were not final-source quality and older text referenced a stale `95/95` code-entry gate.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:
  - The exact original method spelling is unresolved.
  - The exact `LivingObjectPane` field name for the UTF-16 name buffer at `this+0x126` is unresolved.
  - The stale `95/95` gate wording is no longer the active code-entry rule. Current `by-structure.md` says code entry requires reconstructable state, a nonblank emitter route, and average score greater than `85`, with source-quality readiness still required.
  - Current documentation has enough behavior and route evidence for first-draft C++, but the target page has not yet recorded the fresh MCP session `b880584f` evidence.
- Related target/support docs checked:
  - `by-file/LivingObjectPane.md`
  - `by-class/LivingObjectPane.md`
  - `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`
  - `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
  - `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
  - `by-memory/-coverage-report.md`
  - `project-level/-auto-completion-stats.md`
  - `auto-generated/-ag-memory-coverage.md`
  - archived/executed LivingObjectPane class and SharedGmWideString reports as lead material only.

## Executive Recommendation

[UID:000233] should remain a `LivingObjectPane` method in `map/LivingObjectPane.cpp`. The current evidence supports raising completion above the old blocker and adding first-draft C++:

```cpp
bool LivingObjectPane::HasGMNameSuffix() const
{
    const wchar_t *end = m_nameBuffer + 2;
    while (*end != L'\0')
        ++end;

    return _wcsicmp(end - 2, L"GM") == 0;
}
```

`HasGMNameSuffix()` and `m_nameBuffer` are source-facing inferred names, not original-symbol proof. The code is still appropriate for the target page because it avoids IDA labels, decompiler temporaries, manual pointer arithmetic on `char *this`, generated aliases, and a standalone literal/global declaration. It preserves the exact behavior: the binary starts searching at the third UTF-16 code unit, assumes the name has enough text, compares the final two UTF-16 code units before the terminator, and returns `_wcsicmp(..., L"GM") == 0`.

## Supervisor Active Recheck

- Supervisor instruction required a report-only MCP-backed redo/update using endpoint `http://127.0.0.1:13337/mcp` and active session `b880584f`.
- The assignment specifically asked whether this target should remain `84/92` or rise above the completion/code-entry gate, and required rechecking function boundary, padding, caller, literal/string refs, `_wcsicmp(L"GM")`, owner/emitter route through `LivingObjectPane`, parent/support docs, and C++ readiness.
- MCP responded and was used successfully. No fallback-only finalization occurred. No by-* docs, coverage reports, IDA DB, tool state, or generated/project-level files were edited.

## Inference Research Guidance Check

- IDA fact, documentation evidence, and inference are separated below. IDA MCP proves the function object, direct caller, callee, disassembly, decompile, literal xrefs, and padding. Documentation proves the current owner/emitter context and existing support-doc state. Inference supplies the source-facing method/member names.
- Existing documentation assumptions treated as uncertain: exact original method spelling, exact `m_nameBuffer` field spelling, and old `95/95` C++ gate wording.
- Wave2/Wave3 material encountered: current generated coverage routes the target to `auto-generated/NexusTK/map/LivingObjectPane.cpp`, and support docs mention old generated output as historical context. These were used only as route/source-family leads and rejected as authority for final names.
- The active code-entry rule does not force C++ emission by score alone. The reason this target is now C++-ready is the combination of exact function body, direct route, stable owner/emitter, and a source-shaped body that can preserve behavior while marking names inferred.

## Heuristic / Inference Reanalysis And Validation

- Method name: best current source-facing name is `LivingObjectPane::HasGMNameSuffix() const`. It is descriptive and precise: the function checks a suffix, not a full staff/GM permission state. Rejected names:
  - `IsGM()` overstates behavior because the function only compares the last two wide characters of a name.
  - `IsGameMaster()` overstates behavior and expands an acronym not proven in source.
  - `LivingObjectPaneGmNameSuffixCheck()` is a documentation title, not a plausible human method name.
  - `sub_514EA0`, `a1`, `v2`, and `String1` are IDA/decompiler artifacts.
- Field name: best current source-facing direction is `m_nameBuffer` at `this+0x126`. Existing docs call it an actor-owned UTF-16 name buffer. `m_name`, `m_displayName`, or a base-class name field remain plausible, but no constructor/struct evidence in this pass proves an exact original spelling. The target/support docs should call the name inferred/provisional.
- C++ behavior: do not add a short-name guard or null check. The binary starts the scan at `this+0x12a` and computes `end - 2` relative to base `this+0x126`; adding guard code would change behavior.
- Source placement: keep with `LivingObjectPane.cpp` as a scattered accessor. The direct call from `MapPane` is a consumer cleanup path and does not move method ownership to `MapPane`.
- Literal handling: use local `L"GM"` in the method body. [UID:0003IO] owns no canonical global declaration for the pooled `.rdata` bytes and already treats the literal as emitted at MapPane, LivingObjectPane, and ObjectList use sites.
- Score gate: current average is already `88.0`, but completion is below `85`. Since first-draft C++ is now ready and stale gate wording can be retired, raise completion to `88`; keep confidence at `92` because the remaining uncertainties are naming/layout, not behavior.

## Evidence Standards Used

- MCP evidence types: `idb_list`, `server_health`, `lookup_funcs`, `callees`, `xrefs_to`, `get_bytes`, `get_string`, `int_convert`, `find_bytes`, `decompile`, and `disasm`.
- Manual/local supplement: raw PE SHA-256, section map, target raw offset, range hash, rel32 control-transfer scan, absolute VA/RVA/raw-offset pointer scans, and literal positive controls.
- Documentation evidence: current by-memory target page, LivingObjectPane file/class/core pages, SharedGmWideString no-owner page, generated memory coverage, auto-completion stats, and coverage row.
- Evidence ladder application: direct IDA function/caller/callee/literal facts are primary; PE route scan corroborates route/pointer claims; support docs are used for owner/source-family context; source-facing names are inference and stay capped.
- Tool limitations: MCP/Hex-Rays cannot prove original method names, exact local variable names, exact class member spelling, or source file layout without debug symbols. Decompiler output was checked against disassembly for pointer arithmetic and behavior.

## Evidence Checked

IDA MCP evidence:

- `initialize` returned server `ida-pro-mcp`, protocol `2025-06-18`; `tools/list` returned `65` tools.
- `idb_list` returned one active session `b880584f`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, backend `worker`, worker PID `27504`.
- `server_health(database=b880584f)` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- PowerShell `Invoke-RestMethod` did not pass the database argument correctly for this server, returning the schema-level message `database is required`; the same lightweight call through Python `urllib` succeeded. This was a transport-wrapper issue, not MCP unavailability or stale session evidence.

by-* docs, support docs, old reports, generated reports, and trackers checked:

- Target page [UID:000233] current metadata and existing evidence.
- `by-file/LivingObjectPane.md` scattered-accessor row and `SharedGmWideString` source-use note.
- `by-class/LivingObjectPane.md` field table and scattered-accessor/method-family rows.
- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md` scattered-accessor exclusion/field notes.
- `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` current no-owner/multi-emitter literal treatment and [UID:000233] literal route.
- `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, and `by-memory/-coverage-report.md`.

Negative checks performed:

- MCP `xrefs_to` on the target found exactly one incoming xref, the direct code call at `0x0050a552`; no additional code/data xrefs were reported.
- MCP `find_bytes` found zero direct dword matches for target VA `a0 4e 51 00`, target RVA `a0 4e 11 00`, and target raw offset `a0 42 11 00`.
- PE route scan found one direct `E8` rel32 call to `0x00514ea0` at `0x0050a552` and zero absolute VA/RVA/raw-offset dword pointer hits.
- MCP `xrefs_to` found no refs to pre-padding `0x00514e98` or post-end `0x00514edd`.
- No evidence found for `MapPane`, `SharedGmWideString`, `ObjectList`, or a new common GM/name helper as canonical owner.

Failed, unavailable, or intentionally skipped checks:

- No MCP availability failures occurred. No broad `insn_query` or whole-image heavy scan was needed because `xrefs_to`, `find_bytes`, disassembly, and the local PE route scan answer the direct route questions.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:000233] is exactly `0x00514ea0-0x00514edd` | High | MCP `lookup_funcs` reports `sub_514EA0` at `0x00514ea0`, size `0x3d`; bytes show eight `0xcc` before and three `0xcc` after; successor `0x00514ee0` is `sub_514EE0` | `xrefs_to` on padding starts returned zero; predecessor [UID:0001B5] ends before padding | None for range |
| Method belongs to `LivingObjectPane` | High | Thiscall receiver in `ecx`; caller loads `ecx=[edi+0x104]`; support docs treat `0x00514ea0` as LivingObjectPane scattered accessor; class/file owner is [UID:0000KU] | MapPane caller checked and rejected as owner; literal page checked and rejected as declaration owner | Original class member names remain unresolved |
| Behavior is final-two-wide-char case-insensitive compare to `L"GM"` | High | MCP decompile and disassembly: scan from `this+0x12a`, base `this+0x126`, `push offset aGm`, `call __wcsicmp`, `setz al`; `get_string(0x0061e6f8)` returns `GM` | Disassembly checked against decompile; no alternate callee | None for behavior |
| Source-facing name should be `HasGMNameSuffix() const` | Medium-high | Exact behavior is a boolean suffix predicate, not a state setter; method has no writes; `GM` is acronym in literal | Original symbols absent; no support doc proves exact spelling | Future source/PDB/map evidence could replace spelling |
| Name buffer field should be represented as inferred `m_nameBuffer` | Medium | Binary computes suffix from `this+0x126`; docs call it actor-owned UTF-16 name buffer | Constructor/field declaration not proven in this pass; `m_name`/`m_displayName` also plausible | Broader class layout/source pass could finalize field spelling |
| First-draft C++ is ready | High for body, medium-high for names | Exact function body, route, owner, callee, literal, and padding; active code gate average already `88.0`; source-shaped C++ can preserve exact behavior | No exact original name proof; broad class declaration still blank | Accepted implementation should document inferred names and cap |

## Positive Evidence Summary

- Direct facts supporting the recommendation:
  - `sub_514EA0` is a real modeled function, not a raw island.
  - The function is a compact thiscall predicate with no stores and one callee, `__wcsicmp`.
  - The only incoming xref is a direct call from `sub_50A500` at `0x0050a552`.
  - The direct caller passes a `LivingObjectPane` pointer from `[edi+0x104]` as `ecx`.
  - The body pushes `aGm` / `L"GM"` and returns `setz al` from `_wcsicmp` equality.
  - Bytes and padding confirm the exact target range and no merge/split pressure.
- Corroborating documentation/generated-report evidence:
  - LivingObjectPane file/class docs already list [UID:000233] as a scattered accessor.
  - SharedGmWideString page identifies [UID:000233] as the LivingObjectPane source-use route for the pooled literal, while keeping the literal page no-owner/multi-emitter.
  - Generated memory coverage routes the target through `LivingObjectPane.cpp`.
- Strongest inference chain: receiver/caller setup + support docs + LivingObjectPane field offsets + no stronger owner candidate makes `LivingObjectPane::HasGMNameSuffix() const` the best source-shaped representation.

## IDA MCP Facts

Function/range facts:

| Address | MCP result |
| --- | --- |
| `0x00514e60` | `sub_514E60`, size `0x38` |
| `0x00514e98` | not a function |
| `0x00514ea0` | `sub_514EA0`, size `0x3d` |
| `0x00514edd` | not a function |
| `0x00514ee0` | `sub_514EE0`, size `0x8b` |
| `0x0050a500` | `sub_50A500`, size `0x337` |
| `0x0050a552` | resolves inside `sub_50A500`, size `0x337` |
| `0x0061e6f8` | not a function; string data |

Data/table/padding facts:

- `get_bytes(0x00514e98, 8)` returned `cc cc cc cc cc cc cc cc`.
- `get_bytes(0x00514ea0, 61)` returned the body bytes beginning `8b d1 56 8d 82 2a 01 00 00 ...` and ending `0f 94 c0 5e c3`.
- `get_bytes(0x00514edd, 3)` returned `cc cc cc`.
- `get_bytes(0x0061e6f8, 8)` returned `47 00 4d 00 00 00 00 00`.
- `get_string(0x0061e6f8)` returned `GM`.
- `int_convert` reconfirmed `0x3d` = 61, `0x126` = 294, `0x12a` = 298, `0x1d0` = 464, `0x1d1` = 465, `0x19a` = 410, `0x178` = 376, and `0x104` = 260.

Xref facts:

- `xrefs_to(0x00514ea0)` returned exactly one xref: code ref `0x0050a552` in `sub_50A500`.
- `xrefs_to(0x0061e6f8)` returned 20 data refs: `0x00505505`, `0x00514ec5`, and eighteen ObjectList refs from `0x0053321a` through `0x00533f19`.
- `xrefs_to(0x00514e98)` returned zero xrefs.
- `xrefs_to(0x00514edd)` returned zero xrefs.
- `xrefs_to(0x00514ee0)` returned one code xref at `0x00503d4f`, confirming the successor is independently reached.

Disassembly facts:

```asm
0x514ea0 mov edx, ecx
0x514ea2 push esi
0x514ea3 lea eax, [edx+12Ah]
0x514ea9 lea esi, [eax+2]
0x514eac nop dword ptr [eax+00h]
0x514eb0 mov cx, [eax]
0x514eb3 add eax, 2
0x514eb6 test cx, cx
0x514eb9 jnz short loc_514EB0
0x514ebb sub eax, esi
0x514ebd add edx, 126h
0x514ec3 sar eax, 1
0x514ec5 push offset aGm; "GM"
0x514eca lea eax, [edx+eax*2]
0x514ecd push eax
0x514ece call __wcsicmp
0x514ed3 add esp, 8
0x514ed6 test eax, eax
0x514ed8 setz al
0x514edb pop esi
0x514edc retn
```

Decompile facts:

```c
bool __thiscall sub_514EA0(char *this)
{
  char *v2;
  char *v3;
  __int16 v4;

  v2 = this + 298;
  v3 = this + 300;
  do
  {
    v4 = *(_WORD *)v2;
    v2 += 2;
  }
  while ( v4 );
  return _wcsicmp((const wchar_t *)&this[2 * ((v2 - v3) >> 1) + 294], L"GM") == 0;
}
```

Caller facts:

```asm
0x50a52d mov ecx, [edi+104h]
0x50a533 test ecx, ecx
0x50a535 jz short loc_50A572
0x50a537 cmp byte ptr [ecx+1D0h], 0
0x50a53e jnz short loc_50A55B
0x50a540 cmp dword ptr [ecx+178h], 0
0x50a547 jnz short loc_50A572
0x50a549 cmp byte ptr [ecx+19Ah], 5
0x50a550 jnz short loc_50A572
0x50a552 call sub_514EA0
0x50a557 test al, al
0x50a559 jz short loc_50A572
0x50a55b mov ecx, [edi+104h]
0x50a561 push 0
0x50a563 call sub_53B1B0
0x50a568 mov dword ptr [edi+104h], 0
```

Hex-Rays caller snippet:

```c
v2 = *(_DWORD *)(this + 260);
if ( v2 && (*(_BYTE *)(v2 + 464) || !*(_DWORD *)(v2 + 376) && *(_BYTE *)(v2 + 410) == 5 && sub_514EA0((char *)v2)) )
{
  sub_53B1B0(*(_BYTE **)(this + 260), 0);
  *(_DWORD *)(this + 260) = 0;
}
```

Negative IDA facts:

- `find_bytes` found zero matches for target VA, target RVA, and target raw-offset dword encodings.
- `callees(0x00514ea0)` returned only `__wcsicmp`.
- No MCP result gave an original symbol name for `sub_514EA0`, the method, or the `+0x126` member.

## PE Route Scan Supplement

Local PE supplement used `E:\NTK\Resources\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, imagebase `0x400000`.

Section map:

| Section | VA range / size | Raw range |
| --- | --- | --- |
| `.text` | `0x00401000`, virtual size `0x20b4ac` | raw `0x00000400+0x20b600` |
| `.rdata` | `0x0060d000`, virtual size `0x5f0be` | raw `0x0020ba00+0x5f200` |
| `.data` | `0x0066d000`, virtual size `0x2fe24` | raw `0x0026ac00+0xd800` |

Target accounting:

- Target VA `0x00514ea0`, RVA `0x00114ea0`, raw offset `0x001142a0`, section `.text`.
- Target bytes SHA-256 over `0x3d` bytes: `b196fb012c0e582e313c7f91ff7ef05c56111beb8870e94c9f5cf37e25b6f9b3`.
- Pre-padding bytes at `0x00514e98-0x00514ea0`: `cc cc cc cc cc cc cc cc`.
- Post-padding bytes at `0x00514edd-0x00514ee0`: `cc cc cc`.

Route scan:

- One rel32 control-transfer route to `0x00514ea0`: `E8` direct call at `0x0050a552`.
- Zero file-wide dword matches for target VA `0x00514ea0`, target RVA `0x00114ea0`, and target raw offset `0x001142a0`.
- Positive controls: literal VA `0x0061e6f8` has 20 dword operand hits matching the MCP xref distribution; UTF-16 bytes `47 00 4d 00 00 00 00 00` occur once at `0x0061e6f8` / raw `0x0021d0f8`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00514e60-0x00514e98` | [UID:0001B5] Shared LObject scalar deleting destructor | compiler-generated destructor wrapper | ignored | none | `90` historical | Predecessor ends before eight-byte padding |
| `0x00514e98-0x00514ea0` | ignored padding | eight bytes `0xcc` | no | none | n/a | Keep ignored padding |
| `0x00514ea0-0x00514edd` | [UID:000233] target | `LivingObjectPane` GM suffix predicate | yes | [UID:0000KU] | recommend `88/92` | Add first-draft C++ |
| `0x00514edd-0x00514ee0` | ignored padding | three bytes `0xcc` | no | none | n/a | Keep ignored padding |
| `0x00514ee0-0x00514f6b` | successor `sub_514EE0` / [UID:000234] | independent function | yes | separate target | not reviewed here | Do not merge |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050a552` | direct code xref/call to `0x00514ea0` | Live route from `MapPane` update/render helper into the LivingObjectPane method |
| `0x00514ec5` | data xref to `0x0061e6f8` / `aGm` | Local `L"GM"` source-use route for the LivingObjectPane method |
| `0x00514ece` | call to `__wcsicmp` | Case-insensitive wide suffix compare |
| `0x0050a563` | caller calls `sub_53B1B0(..., 0)` after true return or terminal-animation byte | Caller-side cleanup/removal path; consumer evidence only |
| `0x00505505` and ObjectList refs | other refs to `0x0061e6f8` | Shared pooled literal has multiple source-use emitters; not canonical owner evidence for target |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target page already says `ecx` is the receiver, loop starts near `this+0x12a`, suffix base is `this+0x126`, only callee is `__wcsicmp`, literal is `aGm` / `L"GM"`, only direct caller is `0x0050a552`, and MapPane is a consumer.
  - `by-file/LivingObjectPane.md` lists [UID:000233] as a scattered accessor and states it walks the actor-owned UTF-16 name buffer and returns `_wcsicmp(..., L"GM") == 0`.
  - `by-class/LivingObjectPane.md` lists [UID:000233] in scattered accessors and records related field roles such as `+0x178..+0x1bc` sprite config, `+0x1d0` terminal/death animation state, and `+0x1d1` name visibility.
  - `SharedGmWideString` documents [UID:000233] as one of three local literal source-use routes and rejects a standalone literal owner.
- Existing docs that are stale, incomplete, or contradicted:
  - Target page has stale final-code gate wording and blank C++ despite current MCP/PE evidence supporting source-shaped child C++.
  - Support docs do not yet record the fresh `b880584f` evidence or the recommended `HasGMNameSuffix()` first-draft name.
  - `project-level/-unresolved.md` still flags IDA labels in the target page; accepted implementation should reduce generated/IDA-shaped unresolved noise when it incorporates the new evidence.
- Generated/coverage report state:
  - `project-level/-auto-completion-stats.md` still lists `84/92`.
  - `auto-generated/-ag-memory-coverage.md` routes the item through `LivingObjectPane.cpp`.
  - `by-memory/-coverage-report.md` still has the old `84%` row and should be supervisor-updated only if this report is accepted.

## Ranked Ownership Analysis

### 1. [UID:0000KU] LivingObjectPane / `map/LivingObjectPane.cpp`

- Evidence for:
  - Receiver is the living object pointer loaded into `ecx`.
  - Caller passes `[edi+0x104]` to the method, then clears the same field after true result.
  - Target reads `LivingObjectPane` name buffer and related caller-side state fields (`+0x178`, `+0x19a`, `+0x1d0`) match LivingObjectPane class docs.
  - File/class support docs already classify [UID:000233] as a scattered LivingObjectPane accessor.
  - Generated memory coverage routes it to `LivingObjectPane.cpp`.
- Evidence against:
  - No original source symbol proves `HasGMNameSuffix()` or `m_nameBuffer`.
- Decision: keep as canonical owner/emitter and raise completion with inferred-name caveat.

### 2. [UID:0000L3] MapPane / `map/MapPane.cpp`

- Evidence for:
  - Sole direct caller is in `sub_50A500`, a MapPane update/render helper.
  - Caller uses the boolean result to remove/clear a visual/effect state through `sub_53B1B0(..., 0)` and `[edi+0x104]=0`.
- Evidence against:
  - Caller loads the receiver from `[edi+0x104]` and calls a method on that object; target body uses `ecx` as the object, not the MapPane.
  - MapPane owns the cleanup decision and active pointer field, not the suffix helper body or actor name buffer.
- Decision: reject as canonical owner. Document MapPane as consumer/caller.

### 3. [UID:0003IO] SharedGmWideString / pooled literal owner

- Evidence for:
  - Target uses the pooled `.rdata` wide string at `0x0061e6f8`.
- Evidence against:
  - The literal has 20 refs across MapPane, LivingObjectPane, and ObjectList.
  - SharedGmWideString page already rejects a canonical owner and instructs source reconstruction to emit local `L"GM"` at use sites.
  - Literal ownership does not imply executable method ownership.
- Decision: reject as method owner. Keep [UID:000233] as the LivingObjectPane source-use emitter for the literal.

### 4. ObjectList / common GM-name helper / no-owner

- Evidence for:
  - ObjectList has many `L"GM"` comparisons in related object-name lookup helpers.
  - A common helper could be imagined from semantic similarity.
- Evidence against:
  - `sub_514EA0` is not called by ObjectList helpers or MapPane `sub_505430`.
  - There is no common function, table, pointer route, vtable route, or source declaration tying all GM suffix checks together.
  - [UID:000233] has a live direct route and a stable owner/emitter, so no-owner/non-emitting is unnecessary.
- Decision: reject.

## Source Placement

- Recommended placement: `map/LivingObjectPane.cpp`, as an exact method child on [UID:000233], with support documentation in `by-file/LivingObjectPane.md` and `by-class/LivingObjectPane.md`.
- Why this placement fits: LivingObjectPane owns actor state, name buffer, sprite/config state, name visibility, and linked object/effect behavior. The target is a small predicate on actor state and is only consumed by MapPane.
- Rejected placements: `MapPane.cpp` as caller/consumer only, `ObjectList.cpp` as separate use-site family, `SharedGmWideString` as no-owner pooled literal, and a new common `GM` helper/constants file because no direct common route exists.
- Remaining placement uncertainty: exact header declaration and class field spelling are not final enough for a broad class declaration. Only the exact child method C++ is recommended.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - `0x00514ea0-0x00514edd`, size `0x3d` / 61 bytes.
  - Pre-padding `0x00514e98-0x00514ea0` is eight `0xcc` bytes and has zero MCP xrefs.
  - Post-padding `0x00514edd-0x00514ee0` is three `0xcc` bytes and has zero MCP xrefs.
  - Successor `0x00514ee0` is `sub_514EE0`, size `0x8b`, and has an independent xref from `0x00503d4f`.
- Children/subranges: no split, merge, new child, or reclassification is needed.
- Padding/table/data/code distinctions: target is `.text` code; adjacent bytes are ignored padding; `L"GM"` is pooled `.rdata` string data owned as no-owner/multi-emitter by [UID:0003IO].
- Parent/container impact: no parent range change. LivingObjectPane file/class support docs should update role/name/C++ readiness.

## Negative Evidence Summary

- MapPane rejected as owner despite the sole call because the method receiver is a LivingObjectPane pointer and the target reads actor state.
- SharedGmWideString rejected as owner because it is pooled data with three source-use families and no single canonical source owner.
- ObjectList/common helper rejected because ObjectList helpers duplicate the literal use but do not call this function.
- New source file rejected because there is no common declaration object, constructor route, pointer table, or clustered source group beyond existing LivingObjectPane.
- Exact original names remain unproven: no PDB/source/map symbol, no IDA type, and no support doc proves the method/member spelling.
- No pointer/table route beyond the direct call: MCP and PE found no target VA/RVA/raw-offset dword hits.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names:
  - Method: `LivingObjectPane::HasGMNameSuffix() const`.
  - Field direction: `m_nameBuffer` for the UTF-16 buffer at `this+0x126`; document as inferred/provisional.
  - Literal: use local `L"GM"` in source, not a standalone global.
- Evidence:
  - The method returns a `bool`, performs no stores, and exactly tests a final two-character suffix.
  - `GM` is a direct literal string; acronym casing is source-readable.
  - The buffer is actor-owned and already described as a UTF-16 name buffer in docs.
- Items intentionally left unchanged:
  - Do not request an IDA DB rename/type/comment edit in this report-only pass.
  - Do not finalize broad class field declaration or header layout.
  - Keep target filename/title unless a separate naming pass wants to rename docs; the proposed C++ name is enough.
- IDA DB edits: not requested. This assignment forbids IDA DB edits.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Recommended code:

```cpp
bool LivingObjectPane::HasGMNameSuffix() const
{
    const wchar_t *end = m_nameBuffer + 2;
    while (*end != L'\0')
        ++end;

    return _wcsicmp(end - 2, L"GM") == 0;
}
```

- Reason it preserves exact original behavior:
  - Starts scanning at the third UTF-16 code unit, matching `lea eax, [edx+12Ah]`.
  - Computes the suffix pointer as the final two UTF-16 code units before the terminator, matching the `sub/sar/lea` sequence against base `this+0x126`.
  - Calls `_wcsicmp` with local `L"GM"` and returns equality as `bool`.
  - Does not add a bounds guard, null check, alternate case normalization, or generated literal/global declaration.
- Reason it matches plausible original source shape:
  - This is ordinary concise C++ for a private/nearby actor predicate.
  - It avoids decompiler temporaries, manual `char *this` arithmetic, IDA labels, raw offsets in the code body, and generated names.
  - It emits the pooled literal as a normal local string literal at the consuming site, matching [UID:0003IO] source-use policy.
- Inferred source-facing names/types/fields:
  - `HasGMNameSuffix()` is descriptive and source-facing; original spelling not proven.
  - `m_nameBuffer` is an inferred UTF-16 field at `+0x126`; original spelling not proven.
- Reason code should not remain blank:
  - The method is modeled, live-routed, exact, and above the active gate when raised.
  - The remaining uncertainty affects names and score cap, not executable behavior.

## Final Recommendation

- Apply target metadata update to `COMPLETION:88`, keep `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, and blank emitter position unchanged.
- Add the first-draft C++ block above.
- Incorporate MCP session `b880584f` and PE route-scan evidence at report-level detail.
- Preserve MapPane consumer rejection, SharedGmWideString no-owner literal treatment, no common helper evidence, and original-name/field-name cap rationale.
- No split, merge, ignored-range, IDA DB, tool-state, generated file, or coverage file edit should be made by B004 during implementation unless supervisor explicitly overrides coverage.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md`
- Exact report facts to incorporate:
  - 2026-06-23 MCP evidence with endpoint/session/IDB health, `sub_514EA0` size `0x3d`, predecessor/successor lookups, `callees` to `__wcsicmp`, `xrefs_to` one caller at `0x0050a552`, `xrefs_to` 20 literal refs and [UID:000233] literal xref at `0x00514ec5`, `get_bytes` body/padding/literal bytes, `get_string` `GM`, `find_bytes` no target pointer hits and positive literal controls, decompile/disassembly facts, and PE route scan.
  - Exact name-buffer arithmetic: scan starts at `this+0x12a`, suffix base is `this+0x126`, final pointer is last two UTF-16 code units before terminator.
  - Caller relationship: `sub_50A500` loads `[edi+0x104]`, checks `+0x1d0`, `+0x178`, `+0x19a == 5`, calls target, and clears `[edi+0x104]` after `sub_53B1B0(..., 0)`.
  - Rejected alternatives: MapPane caller/consumer, SharedGmWideString pooled literal owner, ObjectList/common helper, no-owner/non-emitting.
  - C++ readiness and exact source-shaped code block.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `COMPLETION:84` to `COMPLETION:88`.
  - Leave `CONFIDENCE:92`.
  - Leave owner/emitter/reconstructable fields unchanged.
  - Populate C++ with `HasGMNameSuffix() const`.
- Historical/stale assumptions and negative evidence to preserve:
  - Old `95/95` gate is stale; active code gate is average >85 plus source readiness.
  - Method/field spelling remains inferred.
  - No pointer/table route beyond the direct rel32 call.

## Recommended Support Doc Changes

Support path: `by-file/LivingObjectPane.md`

- Update scattered-accessor and boundary/ownership notes to state that [UID:000233] is now first-draft C++ ready as inferred `LivingObjectPane::HasGMNameSuffix() const`.
- Preserve the exact `this+0x126` / `this+0x12a` UTF-16 name-buffer suffix behavior, direct caller at `0x0050a552`, and `L"GM"` source-use route.
- Preserve that MapPane is the caller/consumer and not the owner.
- No metadata change expected.

Support path: `by-class/LivingObjectPane.md`

- Add or update method-family/scattered-accessor detail so [UID:000233] is listed as `HasGMNameSuffix() const` with inferred `m_nameBuffer` field naming.
- Preserve the score cap/class declaration caveat: this child can emit exact method C++, but broad class C++ remains blank because class layout and many raw/local-player helpers are not fully source-quality.
- No metadata change expected.

Support path: `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`

- Optional support edit if accepted implementation finds current wording stale: record that [UID:000233] remains a scattered method outside the contiguous core and is now first-draft child C++ ready. If current scattered-accessor wording is considered enough, mark already present with proof.

Support path: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`

- Likely no edit required. It already records [UID:000233] as the LivingObjectPane source-use route, direct `aGm` xref, local `L"GM"` use, no-owner/multi-emitter policy, and rejection of a shared helper. If implementation finds stale wording that says [UID:000233] C++ must remain blank, update only that stale wording; otherwise mark already present.

Support path: `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`

- Optional only if the target implementation needs a caller-side support note. The accepted target should be enough unless this page contains stale owner wording. If edited, preserve that the MapPane helper is the caller/consumer and not the owner.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:84`, `CONFIDENCE:92`, owner/emitter `0000KU`, reconstructable true, blank C++.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:92`, owner/emitter unchanged, reconstructable unchanged, C++ populated.
- Score rationale:
  - Raise completion because current MCP/PE evidence validates the function, range, padding, direct caller, callee, literal, no pointer/table alternatives, source placement, and first-draft source-shaped C++.
  - Keep confidence at `92` because behavior/route/range confidence is high.
  - Do not raise higher because original method spelling, original field spelling, header placement, and broader class field layout remain inferred.
  - Do not leave completion at `84` because that now reflects stale C++-gate caution rather than an actual behavior/source-shape blocker.
- Metadata fields:
  - `CANONICAL_OWNER:0000KU` unchanged.
  - `RECONSTRUCTABLE:TRUE` unchanged.
  - `EMITTER_UIDS:0000KU` unchanged.
  - `EMITTER_POSITION_OPTIONAL:` unchanged/blank.

## Open Questions With Attempted Resolution

- Exact method name:
  - Evidence checked: MCP had no original symbol; support docs use descriptive title; behavior is exact suffix predicate.
  - Best supported resolution: use inferred `HasGMNameSuffix() const`.
  - Remaining uncertainty: original source might have used `IsGM`, `IsGameMaster`, `HasGMSuffix`, or similar. Cap score.
- Exact field name:
  - Evidence checked: disassembly/decompile use offsets `+0x126` and `+0x12a`; docs call it actor-owned UTF-16 name buffer; class field table has no exact name entry.
  - Best supported resolution: use inferred `m_nameBuffer` for child C++ and document caveat.
  - Remaining uncertainty: original class header may use `m_name`, `m_displayName`, an inherited field, or a packed record member. Cap score.
- MapPane relationship:
  - Evidence checked: sole caller and caller decompile/disassembly.
  - Resolution: MapPane is consumer/cleanup owner, not method owner.
- Shared literal relationship:
  - Evidence checked: SharedGmWideString page, MCP xrefs, PE literal controls.
  - Resolution: emit local `L"GM"` at this source use; do not create/move a global literal declaration.

## Exact Supervisor-Owned Coverage Text

File/placement: `by-memory/-coverage-report.md`, replace the current [UID:000233] row.

Exact replacement text:

```markdown
- [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md) 0x00514ea0-0x00514edd | class method | LivingObjectPaneGmNameSuffixCheck : reconstructable : 88% : very strong : B004 2026-06-23 MCP session `b880584f` and PE scan confirm `sub_514EA0` is a `0x3d` LivingObjectPane method with one direct caller at `0x0050a552` in `sub_50A500`, one callee `__wcsicmp`, exact `L"GM"` literal xref at `0x00514ec5`, UTF-16 name-buffer suffix math from `this+0x126`/`this+0x12a`, eight-byte and three-byte `0xcc` padding boundaries, zero target VA/RVA/raw-offset pointer hits beyond the direct rel32 call route, and MapPane as consumer not owner. First-draft `HasGMNameSuffix() const` C++ is ready; cap remains for inferred original method/field spelling and broader class layout caveats.
```

Reason B004 did not apply it directly: the implementation callback still forbids editing any `-coverage-report.md` file; coverage application is supervisor-owned.

## Follow-Up Actions

- Supervisor actions:
  - Review/accept or reject the `88/92` and first-draft C++ recommendation.
  - Apply coverage row only if accepted.
- B004 implementation actions if callback accepted:
  - Update target and support docs at report-level detail.
  - Run scoped validators for every changed by-* doc from `source-3/project-documentation`.
- A-agent actions: none required by this report.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/92` as a capped source-quality score.
- Remaining uncertainty: original names and field spelling only. No behavior, range, owner, or direct-route blocker remains.

## Validator Results

- Implementation validator commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. First run applied target metadata/autogen C++/registry/link/stat updates; rerun was idempotent except projected stats refresh.
  - `python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Validator recorded `stats_row_update 0000KU ... Low_Confidence_Not_Reconstructable` and projected stats refresh.
  - `python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Rerun was idempotent except projected stats refresh.
- Optional validators not run because optional docs were not edited:
  - `by-memory\0x0053a110-0x0053d818.LivingObjectPaneCore.md`: already records [UID:000233] as a scattered method outside the contiguous core and has no stale ownership conflict.
  - `by-memory\0x0061e6f8-0x0061e700.SharedGmWideString.md`: already records [UID:000233] as the LivingObjectPane source-use route, local `L"GM"` treatment, and no-owner/multi-emitter literal policy.
  - `by-memory\0x0050e4c0-0x00514920.MapPanePacketHandlers.md`: no stale owner wording found; the required MapPane-as-consumer/not-owner evidence is now in the target and LivingObjectPane support pages.
- Any unresolved validator warnings/errors: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B004/research/000233-LivingObjectPaneGmNameSuffixCheck-source-quality.md`
- Modified by B004 content edits:
  - `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md`
  - `by-file/LivingObjectPane.md`
  - `by-class/LivingObjectPane.md`
  - `tools/leaser/Agents/Agent-B004/research/000233-LivingObjectPaneGmNameSuffixCheck-source-quality.md`
- Modified by required tooling:
  - `tools/leaser/Agents/current_leases.md` was updated by `leaser.py`; B004 leases for the three edited docs were released, and the ledger now reports no active leases.
  - Validator-driven generated/project updates occurred through `--apply` (projected stats, autogen C++/registry/link/stat updates). No `-coverage-report.md` file was manually edited by B004.
- Renamed: none.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and issued implementation callback `B004-implement-living-object-pane-gm-name-suffix-check-source-quality-000233-mcp-20260623`.
- [x] Target/support docs to update: target `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md`; required support `by-file/LivingObjectPane.md` and `by-class/LivingObjectPane.md`; optional support `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`, `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`, and `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` only if stale wording is present. Proof: required three docs edited; optional docs checked and left unchanged for reasons in `Validator Results`.
- [x] Current target state and actual evidence checked recorded: target metadata, blank C++, MCP session `b880584f`, PE route scan, support docs, generated coverage, and current coverage row are recorded in this report.
- [x] Metadata/score changes to apply: changed target `COMPLETION:84` to `COMPLETION:88`; kept `CONFIDENCE:92`.
- [x] Owner/emitter/reconstructable changes to apply: kept `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, and blank emitter position unchanged.
- [x] Split/rename/new-child changes to apply: no split, rename, merge, new child, ignored-range change, or reclassification was applied.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: kept source placement in `map/LivingObjectPane.cpp`; preserved exact range `0x00514ea0-0x00514edd`; preserved adjacent ignored padding; no IDA DB edits.
- [x] First-draft C++ or no-code proof to apply: inserted source-shaped `bool LivingObjectPane::HasGMNameSuffix() const` using inferred `m_nameBuffer`, local `L"GM"`, scan from `m_nameBuffer + 2`, and `_wcsicmp(end - 2, L"GM") == 0`.
- [x] Exact target/support doc facts to incorporate at report-level detail: target now records MCP health/session, lookup, xrefs, caller/callee, bytes, disassembly/decompile, literal refs, PE SHA/section/route scan, no target pointer hits, source-shaped name/field rationale, and score cap; `by-file` and `by-class` summarize the same facts at support-doc level without losing owner/name/cap caveats.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: target/support docs preserve stale `95/95` gate correction, MapPane consumer rejection, SharedGmWideString no-owner literal treatment, ObjectList/common-helper rejection, no target VA/RVA/raw pointer route, and original method/field spelling caveat.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated coverage/source routes were used only as source-family leads; no Wave2/Wave3 naming accepted as proof.
- [x] Open questions to close or document as evidence-backed unresolved: original method spelling and `m_nameBuffer` field spelling remain unresolved and cap score; no behavior/route/range blocker remains.
- [x] Validators to run: scoped validators for all changed by-* files were run from `E:\NTK\GhidraBridge\source-3\project-documentation`; see `Validator Results` for commands, exit codes, and `ok` counts.
- [x] Supervisor-owned coverage-report/tracker text to apply: exact [UID:000233] replacement row remains supplied above; B004 did not edit any `-coverage-report.md` file.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: callback received for `B004-implement-living-object-pane-gm-name-suffix-check-source-quality-000233-mcp-20260623`.
- [x] Leases taken/released: `leaser.py B004 lease` succeeded for the target, `by-file/LivingObjectPane.md`, and `by-class/LivingObjectPane.md`; `leaser.py B004 unlease` succeeded for the same three files after edits/validators; `current_leases.md` now reports no active leases.
- [x] All accepted target/support doc details incorporated at report-level detail: target contains the full 2026-06-23 B004 MCP/PE evidence, exact range/padding/caller/callee/literal behavior, source-shaped C++, rejected alternatives, and score cap; file/class support pages contain the retained helper role, no-pointer/no-table caveats, MapPane rejection, `m_nameBuffer` inference, and local `L"GM"` rationale.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target is `COMPLETION:88`, `CONFIDENCE:92`, owner/emitter [UID:0000KU] unchanged, reconstructable true, blank emitter position unchanged, no split/rename/new-child, first-draft C++ added.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old blank-C++/gate rationale is marked superseded; MapPane, SharedGmWideString, ObjectList/common-helper, and no-owner alternatives are rejected; zero target VA/RVA/raw pointer evidence is retained.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original method spelling, original field spelling, header placement, and broader class layout remain unresolved and cap the score; behavior/route/range are resolved.
- [x] Validators run and results recorded: all three changed by-* docs validate with exit code `0` and `ok: 1`.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact replacement row remains above; no `-coverage-report.md` file was edited.
- [x] Remaining unapplied accepted items listed with exact blocker: none. Optional support docs were not edited because their current text already has the needed facts or no stale owner conflict.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/000233-LivingObjectPaneGmNameSuffixCheck-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"000233"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
