** TARGET-REPORT-UID:00040V **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 00040V LanguageManParserLimitConstants Source Quality Report

## Finalized Report / Current Recommendation

UID00040V remains a reconstructable, source-emitting `LanguageMan.cpp` file-local constant pair. The implementation callback has been applied: the target page is now `COMPLETION:88` / `CONFIDENCE:90`, current MCP session `e63ee655` evidence has been incorporated, and the formal C++ shape remains the same two source-like file-local constants.

Repair-cycle history: supervisor command `000000005490` executed the report, and validator command `000000005495` returned it for report-text repair at `2026-07-03T14:19:07-04:00` after stale wording still described pre-implementation target state. The by-* implementation itself remains applied. This repaired report records the implemented by-* state after report-text repair; supervisor audit and lifecycle state are tracked externally in the validation audit and validator history.

The target should keep:

| Field | Recommendation |
| --- | --- |
| `CANONICAL_OWNER` | `0000KK` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000KK` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | retain the two file-local `const int` declarations under an anonymous namespace |

The score remains capped at `88/90`. Fresh MCP confirms the bytes, adjacency, generated output route, and constructor immediate semantics, but the two dwords at `0x0061c9d4` and `0x0061c9d8` still have zero direct address xrefs. That leaves a real retained-or-pooled-constant caveat: the executable uses immediate `0x400` values in the constructor, while the stored dwords are best modeled as source-local constants from the same `LanguageMan.cpp` object-file context rather than as address-loaded runtime data.

## Supporting Research

Current implemented target page:

- `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md` currently records `88/90`, owner/emitter `0000KK`, reconstructable `TRUE`, and unchanged formal C++ for `kMaxStringResourceLineBytes` and `kMaxLocalizedStringCount`.
- The page now incorporates current MCP session `e63ee655` evidence for bytes, xrefs, adjacent island boundaries, constructor immediate semantics, generated-output presence, rejected alternatives, and the no-address-xref confidence cap.

Direct support docs reviewed:

- `by-file/LanguageMan.md` routes UID00040V into `NexusTK/localization/LanguageMan.cpp` and lists it as two source-order-inferred `0x400` parser limits.
- `by-class/LanguageMan.md` correctly treats UID00040V as file-level `LanguageMan.cpp` data, not class fields.
- `by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md` records the mixed KeySpeedMgr/LanguageMan `.rdata` island and exact child inventory.
- `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md` consumes the names `kMaxStringResourceLineBytes` and `kMaxLocalizedStringCount` in formal constructor C++.
- `by-resource/str-res-localized-strings.md` independently documents the 1024-record and 1024-byte line limits for the `str.res` loader contract.
- `by-memory/0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md`, `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md`, and `by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md` provide the immediate predecessor and successor child boundaries.

Generated/read-only context reviewed:

- Historical assignment baseline: `auto-generated/-ag-research-tracker.md` listed UID00040V as `86/87`, combined `86.5`, reconstructable `true`, reports `0` before B007's callback.
- Post-callback generated context: `auto-generated/-ag-memory-coverage.md` lists UID00040V as `coded`, owner/emitter `0000KK`, generated output `auto-generated/NexusTK/localization/LanguageMan.cpp`.
- Post-callback generated `LanguageMan.cpp` header records `validator-command-id: 000000005479`, `validator-refreshed-at: 2026-07-03T14:12:08-04:00`, and contains UID00040V as `Completion:88 | Confidence:90` with the unchanged anonymous-namespace constants.

Prior report leads checked:

- Executed B013 report `executed-b-agent-research/B013/00025M-KeySpeedStringResourceReadOnlyData-source-routing.md` originally recommended creating UID00040V as the exact LanguageMan parser-limit child with `86/87`, owner/emitter `0000KK`, and the same first-draft constant C++.
- Executed B012 report `executed-b-agent-research/B012/00018R-LanguageManLocalization-source-quality.md` later linked UID00040V to the exact constructor child and formal constructor C++ using these names.
- These reports were used as historical leads only; the current implemented source-quality state below is based on current by-* docs, scoped validator results, generated output from command `000000005479`, and MCP session `e63ee655`.

## Target

- UID: `00040V`.
- Target path: `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md`.
- Exact range: `0x0061c9d4-0x0061c9dc`, an 8-byte `.rdata` child.
- Historical assignment queue row at start: `86/87`, combined `86.5`, reconstructable `true`, reports `0`.
- Report artifact path named for this repair cycle: `tools/leaser/Agents/Agent-B007/research/00040V-LanguageManParserLimitConstants-source-quality.md`.
- Repair-cycle history: implementation was applied, then supervisor execution was invalidated/de-executed for report-text repair by validator command `000000005495` after a stale wording defect. This repaired report stands on the implemented by-* state. During this repair pass, no by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were edited.

## Current Target State

Current implemented metadata in the target page:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `0000KK` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000KK` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| `RECONSTRUCTION_CPP CODE:[[[]]]` | blank inline value |
| Multiline formal C++ | anonymous namespace with two `const int` declarations |

Current formal C++:

```cpp
namespace {
const int kMaxStringResourceLineBytes = 1024;
const int kMaxLocalizedStringCount = 1024;
}
```

Current generated output state:

- `auto-generated/NexusTK/localization/LanguageMan.cpp` includes UID00040V as emitted code at `88/90`, not an empty marker; the header records validator command `000000005479`, refreshed `2026-07-03T14:12:08-04:00`.
- The generated file places the constants after constructor/destructor/lookup/helper emitted code and before the UID00040X source literals.

Current blocker:

- No current or historical direct address xrefs target `0x0061c9d4` or `0x0061c9d8`. This is still a confidence cap and should remain explicit in the target.

## Heuristic / Inference Reanalysis And Validation

The current source model is better than a generic data-retention note because three independent evidence classes converge on the same interpretation:

1. The bytes are exactly two little-endian dwords of value `0x00000400`.
2. The adjacent `.rdata` island transitions from KeySpeedMgr vtable data into LanguageMan vtable and string-resource literals at the exact documented boundaries.
3. The LanguageMan constructor uses the same `0x400` value in all places needed by the source-level parser constants: input-line byte cap, wide conversion buffer capacity, and loaded-string count cap.

The dwords are not credible KeySpeedMgr data:

- `0x0061c9c4-0x0061c9d4` is the exact KeySpeedMgr RTTI/vtable child.
- `0x0061c9d4` and `0x0061c9d8` are not function pointers and have zero xrefs.
- Current MCP xrefs to the KeySpeedMgr vtable base `0x0061c9c8` land in KeySpeedMgr constructor/destructor/scalar-deleting-destructor functions, while the two `0x400` dwords have no such ownership refs.

The dwords are also not strong enough for final-audit confidence:

- Current MCP found no direct xrefs to either target dword.
- Current constructor evidence uses immediates, not memory loads from these addresses.
- The strongest source-shape explanation is retained/pool/file-local constants emitted into the same object-file island while optimized constructor code uses immediate operands.

Naming validation:

- Keep `kMaxStringResourceLineBytes` for the line-length/conversion capacity constant. MCP disassembly ties `0x004f011f` to the byte-line cap and `0x004f0167` to the `MultiByteToWideChar` destination cap; the constructor source uses the same limit for both, so this name is preferable to a generic `kMaxLineLength` or raw `kBufferSize`.
- Keep `kMaxLocalizedStringCount` for the string-record cap. MCP disassembly ties `0x004f01d1` to the post-store count check before the `Too many strings` path; this is more source-like than `kMaxStrings`, `kMaxResourceCount`, or a raw `0x400`.
- Reject `kMaxStringResourceWideChars` as a separate second constant because the target contains two dwords, while the constructor uses the same `0x400` for both line/conversion capacity and count semantics. Splitting into three declarations would invent an extra stored source item not represented by the target range.

## Evidence Standards Used

Evidence classification used in this report:

- Direct MCP fact: current IDA MCP session `e63ee655` output from `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `get_int`, `xrefs_to`, `xref_query`, `insn_query`, `disasm`, `decompile`, `get_string`, and `entity_query`.
- Current documentation fact: current by-* and generated docs read from disk during the report-only pass and then updated/checked after the implementation callback.
- Historical lead: executed B013/B012 reports, used only after fresh recheck.
- Inference: source-local constant naming and source-placement conclusion where the binary gives no direct address xrefs to the two dwords.

Numeric conversions:

- `0x400` equals decimal 1024 (Verified with `int_convert.py` and MCP `int_convert`).
- `0x8` equals decimal 8 (Verified with `int_convert.py` and MCP `int_convert`).

## Evidence Checked

MCP session and health:

- `idb_list` returned one active session: `e63ee655`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID/worker PID `1848`, active `true`, analyzing `false`.
- `server_health` for `e63ee655` returned `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready `true`, Hex-Rays ready `true`, strings cache ready `true`, strings cache size `2067`.
- `lookup_funcs` found `0x004f0010` as `sub_4F0010`, size `0x27c`; `0x004efea0` as `sub_4EFEA0`, size `0x3d`; `0x004effc0` as `sub_4EFFC0`, size `0x48`; supervisor's checked address `0x00505430` as `sub_505430`, size `0x19a`.

Target bytes and boundaries:

- `get_bytes 0x0061c9c4 size 128` returned the full mixed island bytes:
  - `0x0061c9c4`: `20 98 64 00`
  - `0x0061c9c8`: `c0 ff 4e 00`
  - `0x0061c9cc`: `10 4b 4f 00`
  - `0x0061c9d0`: `c0 b6 41 00`
  - `0x0061c9d4`: `00 04 00 00`
  - `0x0061c9d8`: `00 04 00 00`
  - `0x0061c9dc`: `c0 98 64 00`
  - `0x0061c9e0`: `d0 03 4f 00`
  - then inherited LanguageMan slots and UTF-16 strings `str.res`, `Too many strings`, and `Invalid String ID`.
- `get_bytes 0x0061c9d4 size 8` returned exactly `00 04 00 00 00 04 00 00`.
- `get_int` read `0x0061c9d4` as `1024`, `0x0061c9d8` as `1024`, `0x0061c9dc` as `6592704` / `0x006498c0`, `0x0061c9e0` as `5178320` / `0x004f03d0`, and `0x0061ca44` as `6592864` / `0x00649960`.
- `get_bytes 0x004f028c size 4` returned `cc cc cc cc`, matching the constructor child boundary before the cleanup destructor.

Xrefs and names:

- `xrefs_to 0x0061c9d4` returned `xref_count:0`.
- `xrefs_to 0x0061c9d8` returned `xref_count:0`.
- `xrefs_to 0x0061c9e0` returned three data refs: `0x004f007b` in `sub_4F0010`, `0x004f02b7` in `0x004f0290`, and `0x004f03fe` in `sub_4F03D0`.
- `xrefs_to 0x0061c9ec` returned one constructor ref at `0x004f0099`.
- `xrefs_to 0x0061c9fc` returned one constructor ref at `0x004f0261`.
- `xrefs_to 0x0061ca20` returned two lookup/copy refs at `0x004f0369` and `0x004f03a9`.
- `xref_query` to `0x0061c9c8` returned KeySpeedMgr vtable refs at `0x004efecb`, `0x004efee0`, and `0x004effc6`.
- `entity_query names 0x0061c9c0-0x0061ca50` returned `??_7KeySpeedMgr@@6B@` at `0x0061c9c8`, `aStrRes` at `0x0061c9ec`, `aTooManyStrings` at `0x0061c9fc`, `aInvalidStringI` at `0x0061ca20`, and `??_7Layer@@6B@` at `0x0061ca48`. It returned no separate name for the two UID00040V dwords.
- `get_string` returned `str.res`, `Too many strings`, and `Invalid String ID` at the expected LanguageMan literal addresses.

Constructor evidence:

- `insn_query` scoped to `func=0x004f0010`, `op_any=1024`, `max_scan_insns=250`, `count=20` found exactly three matches and scanned 176 instructions without truncation:
  - `0x004f011f`: `cmp esi, 400h`
  - `0x004f0167`: `push 400h; cchWideChar`
  - `0x004f01d1`: `cmp eax, 400h`
- `disasm` offset windows around those matches show byte reading into `MultiByteStr`, CR/LF checks, `cmp esi, 400h`, byte `0x11` remapping to `0x0d`, `MultiByteToWideChar` with `cchWideChar` `400h`, and the post-store count compare `cmp eax, 400h`.
- `decompile 0x004f0010` confirms the same source behavior: opens `L"str.res"`, allocates `sub_516050(0x1000u)` for a 1024-entry pointer table, reads lines until CR/LF or 1024 bytes, rewrites byte `17` to `13`, calls `MultiByteToWideChar(..., WideCharStr, 1024)`, stores each wide string pointer, increments `this[2]`, throws with `L"Too many strings"` if the old index is `>= 1024`, copies the temporary table into `this[1]`, and returns.

Local/doc searches:

- `rg` over by-* docs, generated reports, executed reports, and B-agent folders used terms `00040V`, `LanguageManParserLimitConstants`, `0x0061c9d4`, `0061c9d4`, `kMaxStringResourceLineBytes`, `kMaxLocalizedStringCount`, and `0x400`.
- Relevant matches were the current target/support docs, the B013 split report, the B012 constructor report, B012 validation log entries, generated tracker/coverage rows, and unrelated reports containing generic `0x400` matches.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00040V-01 | UID00040V is exactly two little-endian dwords at `0x0061c9d4-0x0061c9dc`, both `0x00000400` / 1024. | High | MCP `get_bytes`, `get_int`; `int_convert.py` and MCP `int_convert`. | Target `Byte Inventory` / `Evidence`. | incorporate | applied: target byte inventory/evidence now records exact bytes and conversions; validator `000000005477` returned `ok:1`. |
| C-00040V-02 | The two dwords still have zero direct address xrefs and must keep a confidence cap. | High | MCP `xrefs_to` returned `xref_count:0` for both `0x0061c9d4` and `0x0061c9d8`. | Target `Evidence`, `Source Model`, `Score Rationale`. | incorporate | applied: target evidence/source model/score rationale preserve the zero-xref retained/pool cap; validator `000000005477` returned `ok:1`. |
| C-00040V-03 | Adjacent island evidence supports the LanguageMan route: predecessor KeySpeedMgr vtable ends at `0x0061c9d4`; LanguageMan locator/vtable begins at `0x0061c9dc`; LanguageMan literals begin at `0x0061c9ec`. | High | MCP `get_bytes`, `get_int`, `xrefs_to`, `xref_query`, `entity_query`; support docs UID00025M/00031P/00040W/00040X. | Target `Evidence`; parent UID00025M child row if stale. | incorporate | applied: target evidence and UID00025M child row/status now carry the current boundary/xref summary; validators `000000005477` and `000000005478` returned `ok:1`. |
| C-00040V-04 | Constructor `sub_4F0010` uses immediate `0x400` for line-byte cap, `MultiByteToWideChar` destination cap, and string-count cap. | High | MCP `lookup_funcs`, `insn_query`, `disasm`, `decompile`; constructor child UID00041V. | Target `Evidence`; constructor support note already present. | applied / already-present | applied to target; constructor UID00041V already had the accepted consumer/source C++ detail at same-or-greater detail, so it was not edited. |
| C-00040V-05 | `kMaxStringResourceLineBytes` and `kMaxLocalizedStringCount` remain the best source-facing names; generic `0x400` constants and KeySpeedMgr ownership should be rejected. | Medium-high | Constructor semantics, resource contract UID0001RP, negative xrefs/KeySpeedMgr vtable evidence. Exact original names are not proven. | Target `Source Model`, `Rejected Alternatives`; support file/class docs if stale. | incorporate | applied: target source model/rejected alternatives and `by-file/LanguageMan.md` now preserve accepted names, KeySpeedMgr rejection, generic-name rejection, and no third-constant invention; validators `000000005477` and `000000005479` returned `ok:1`. |
| C-00040V-06 | Owner/emitter should remain `0000KK` through `LanguageMan.cpp`, not the resource page or class page. | High for route, medium-high for original declaration shape | Current by-file route, generated output, resource/source split, class doc file-level data caveat. | Target metadata; `by-file/LanguageMan.md`; `by-class/LanguageMan.md`. | already-present / incorporate | applied to target/file page where refreshed; class/resource docs already stated UID00040V is file-level LanguageMan.cpp data/resource support only, so they were not edited. |
| C-00040V-07 | Formal C++ should be retained unchanged as two file-local `const int` declarations under an anonymous namespace. | Medium-high | Existing target formal block, generated `LanguageMan.cpp`, constructor source usage, no evidence for extra source object or third constant. | Target formal `RECONSTRUCTION_CPP CODE` block. | already-present | applied by preservation: target formal C++ remains unchanged; generated `LanguageMan.cpp` refreshed at command `000000005479` and shows UID00040V `88/90` with the same two constants. |
| C-00040V-08 | Recommended score is `88/90`, not final-audit level, because current MCP removes stale-evidence risk but cannot remove the no-address-xref caveat. | Medium-high | Fresh MCP session `e63ee655` plus same unresolved zero-xref result. | Target metadata and score rationale. | incorporate | applied: target metadata is `88/90`; validator `000000005477` recorded completion/confidence updates and returned `ok:1`. |

## Positive Evidence Summary

- MCP session `e63ee655` is live, healthy, and points to the expected NexusTK IDB.
- Exact target bytes are two `0x400` dwords.
- The target range is an exact 8-byte child bounded by KeySpeedMgr vtable data before it and LanguageMan RTTI/vtable data after it.
- The LanguageMan string-resource literal island begins immediately after the LanguageMan vtable child and has direct constructor/lookup xrefs.
- The LanguageMan constructor has exactly the expected three `0x400` immediate uses and no truncated MCP scan result.
- The `str.res` resource page independently documents 1024 records and 1024-byte lines.
- Generated `LanguageMan.cpp` currently emits UID00040V at `88/90` with the accepted names and values.

## Negative Evidence Summary

- No direct xrefs target `0x0061c9d4` or `0x0061c9d8`.
- No IDA name exists at the two dwords; `entity_query` names skip from KeySpeedMgr vtable naming to LanguageMan string names.
- The constructor uses immediate operands rather than memory loads from UID00040V addresses.
- The exact original variable names are not proven by symbols, string names, RTTI, or references.
- The dwords are not virtual slots: they do not resolve to executable addresses, have no vtable xrefs, and sit between two distinct source-owner islands.
- KeySpeedMgr ownership has only obsolete physical-adjacency support and no behavioral support.
- The resource page owns the external DAT payload/format, not these `.rdata` bytes.

## Ranked Ownership Analysis

1. [UID:0000KK] `LanguageMan.cpp` file-local data.
   - Evidence for: constructor immediate semantics, `str.res` resource contract, adjacent LanguageMan vtable/literal island, current generated file route, existing by-file support.
   - Evidence against: no direct address xrefs to the dwords and no original names.
   - Decision: keep as direct owner/emitter with confidence cap.

2. [UID:000071] `LanguageMan` class.
   - Evidence for: constructor and lookup helpers are class-owned, and the parser constants support class construction.
   - Evidence against: the constants are file-level implementation details, not object fields or class static data proved by source declarations. `by-class/LanguageMan.md` already says UID00040V is file-level data.
   - Decision: use as support context only, not canonical owner.

3. [UID:0001RP] `str-res-localized-strings` resource page.
   - Evidence for: documents the same 1024 parser contract and owns the external payload.
   - Evidence against: does not own C++ `.rdata` constants or generated `LanguageMan.cpp` source output.
   - Decision: support evidence only.

4. [UID:00006Z]/[UID:0000KJ] `KeySpeedMgr`.
   - Evidence for: physical predecessor range.
   - Evidence against: exact KeySpeedMgr vtable child ends before the target; KeySpeedMgr vtable base has its own xrefs; target dwords are non-pointers with no xrefs and no KeySpeedMgr behavior match.
   - Decision: reject.

5. `CANONICAL_OWNER:NONE` retained/pooled constants.
   - Evidence for: no direct address xrefs can support a pure retained-data interpretation.
   - Evidence against: the values and source-order context map cleanly to LanguageMan parser limits, and the generated source route is coherent.
   - Decision: reject as too conservative for ownership, but preserve retained/pool caveat as a confidence cap.

## Source Placement

Recommended source placement remains `NexusTK/localization/LanguageMan.cpp`, through by-file UID0000KK.

The source shape should be file-local constants near the LanguageMan parser implementation and related file-local literals, not public header declarations, not class fields, and not resource-owned generated data. The anonymous namespace already used by UID00040V and UID00040X is appropriate mid-2000s C++ source shape for implementation-local constants and literals.

No new by-file or by-class page is needed. No split, rename, range expansion, or new child page is recommended.

## First-Draft C++ Recommendation

Retain the target's existing formal C++ block unchanged. Because this report recommends UID00040V remain source-emitting, the exact formal insertion text for the target is:

```text
*** EMITTER_UIDS:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kMaxStringResourceLineBytes = 1024;
const int kMaxLocalizedStringCount = 1024;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale:

- This block represents exactly the two dwords in the target range.
- It is plausible human-written late-1990s/early-2000s C++ for file-local implementation constants.
- It avoids decompiler names, raw addresses, and raw `0x400` magic numbers in source.
- It does not invent a third declaration for the wide conversion capacity.
- It matches current constructor source, resource contract, and generated output.

## Final Recommendation

Final disposition: UID00040V has completed the narrow source-quality refresh and does not need a rewrite. It remains owned/emitted by [UID:0000KK] `LanguageMan`, remains reconstructable, keeps the formal C++ unchanged, and now records the accepted evidence/score from fresh MCP session `e63ee655`.

Exact target changes applied:

- Changed historical `COMPLETION:86` to current `COMPLETION:88`.
- Changed historical `CONFIDENCE:87` to current `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000KK`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000KK`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep the current formal C++ block unchanged.
- Add current MCP evidence for bytes, zero xrefs, adjacent vtable/literal xrefs, `sub_4F0010` constructor immediate use, session health, and generated-output presence.
- Preserve the confidence cap: no direct address xrefs prove the stored dwords are loaded at runtime; they remain best modeled as retained/file-local constants from the LanguageMan source context.

Parent/support disposition:

- Parent UID00025M remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++, because it is a mixed KeySpeedMgr/LanguageMan `.rdata` index. No parent metadata change is recommended.
- `by-file/LanguageMan.md`, `by-class/LanguageMan.md`, `by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md`, and `by-resource/str-res-localized-strings.md` are already broadly correct. Only narrow evidence/status wording should be updated if the supervisor wants support sync after callback.
- No no-owner or non-emitting disposition applies to UID00040V.

Future work outside this UID00040V assignment:

- Full final-audit confidence would require stronger proof of why the two dwords are retained despite immediate use, such as compiler/linker/source-build comparison or broader object-file constant-pool analysis.
- Broader LanguageMan header/API polishing belongs to the LanguageMan class/source family, not to this exact 8-byte constant target.

## Recommended Target Doc Changes

Accepted target changes applied to `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md`:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:90`.
- Keep owner/emitter/reconstructable/formal C++ unchanged.
- Added evidence for current MCP session `e63ee655`:
  - `idb_list` active session path, PID/worker PID `1848`, analyzing `false`.
  - `server_health` ok, IDB path, module, imagebase, auto-analysis/Hex-Rays/string-cache ready.
  - `get_bytes` and `get_int` confirm two dwords `00 04 00 00 00 04 00 00`.
  - `xrefs_to` confirms zero xrefs to both target addresses.
  - `xrefs_to` confirms neighboring LanguageMan vtable and literal refs.
  - `insn_query` confirms the three constructor `0x400` immediates at `0x004f011f`, `0x004f0167`, and `0x004f01d1`.
  - `disasm`/`decompile` tie those immediates to line cap, conversion cap, and count cap semantics.
- Replaced/extended the score rationale with `88/90`: evidence is now current/live-session backed, but the no-address-xref caveat remains.
- Preserved rejected alternatives: KeySpeedMgr ownership, virtual-slot interpretation, resource-page canonical ownership, generic raw `0x400` naming, three-constant invention, and ownerless retained-only handling.

## Recommended Support Doc Changes

Support sync was narrow and did not churn unrelated LanguageMan pages.

- `by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md`: applied the UID00040V child row change from `86/87` to `88/90` and added current-MCP refresh detail. Parent metadata remained unchanged.
- `by-file/LanguageMan.md`: applied the UID00040V likely-content/source-output refresh so the constants now cite fresh `e63ee655` evidence, remain emitted through UID0000KK, and keep the no-address-xref cap. No projected path or owner change was made.
- `by-class/LanguageMan.md`: already correctly says UID00040V is file-level `LanguageMan.cpp` data, not class fields. No edit was required.
- `by-resource/str-res-localized-strings.md`: already links UID00040V as source-side support for 1024 limits. No edit was required.
- `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md`: already consumes the constants by accepted names and documents the same parser limit semantics. No edit was required.
- `by-memory/0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md`, `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md`, and `by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md`: already preserve the boundary model. No edit was required.

Generated files and manual/generated `-coverage-report.md` files were not edited by hand. Generated tracker/coverage rows refreshed only through scoped validator execution during the callback.

## Score And Metadata Recommendation

Implemented metadata:

| Field | Current | Implemented | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `88` | `88` | The page now has code, route, caveats, current byte/xref/immediate proof, and generated-output confirmation. Historical pre-callback value was `86`. |
| `CONFIDENCE` | `90` | `90` | Ownership/source shape is stronger after live `e63ee655` recheck, but direct address xrefs remain absent. Historical pre-callback value was `87`. |
| `CANONICAL_OWNER` | `0000KK` | `0000KK` | Best direct semantic owner is the LanguageMan source file. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | These source-level constants should be recreated in generated source. |
| `EMITTER_UIDS` | `0000KK` | `0000KK` | The generated route is valid and current generated output contains UID00040V. |
| Formal C++ | two constants | unchanged | The source declarations are source-like and match current constructor/resource usage. |

Why not higher:

- Original names are inferred.
- Stored dwords have no direct address xrefs.
- The compiler/object-file retention reason is not proven.

Why the implemented score improved from the historical baseline:

- Current MCP removes stale-evidence risk from the B013 local-PE era.
- Current generated output and support docs confirm that the source route is already active and coherent.
- The score-blocker investigation is complete for the current assignment: no stronger proof route was found, and the remaining blocker is explicitly score-capping rather than unresolved.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Outcome / score impact |
| --- | --- | --- |
| Are the two dwords actually loaded by runtime code? | MCP `xrefs_to` on both exact addresses. | No xrefs. Confidence capped at `90`. |
| Are these KeySpeedMgr tail constants? | Checked predecessor vtable bytes/xrefs and KeySpeedMgr function boundaries; reviewed UID00031P; current MCP found vtable refs to `0x0061c9c8` but none to the target dwords. | Rejected. |
| Should there be three constants because constructor uses `0x400` three times? | Compared target range size and constructor source use. | No. Target has two dwords; first constant can serve both line-byte and conversion-cap roles, second is count cap. |
| Should the constants be resource-owned? | Reviewed `str-res-localized-strings.md` and source/resource contract. | No. Resource owns DAT payload/format; constants are C++ implementation data. |
| Can score be final-audit level? | Rechecked current MCP bytes/xrefs/decompile and generated output. | No. Stored dwords still lack direct xrefs and original names. |

## Validator Results

Implementation-callback scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after editing only the accepted by-* files.

No validators were run during the 2026-07-03 report-text repair after validator invalidation command `000000005495`, because no by-* documentation gap was found and no by-* docs were edited in that repair pass.

| Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md --apply --queue-timeout 240` | `000000005477` | `2026-07-03T14:11:52-04:00` | 0 | 1 | Recorded UID00040V completion/confidence updates to `88/90`; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md --apply --queue-timeout 240` | `000000005478` | `2026-07-03T14:11:59-04:00` | 0 | 1 | Parent support page accepted; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-file/LanguageMan.md --apply --queue-timeout 240 --wait-generated` | `000000005479` | `2026-07-03T14:12:08-04:00` | 0 | 1 | Generated refresh completed; `auto-generated/NexusTK/localization/LanguageMan.cpp` header now records command `000000005479`, refreshed `2026-07-03T14:12:08-04:00`. |

Generated freshness:

- `auto-generated/NexusTK/localization/LanguageMan.cpp` now records `validator-command-id: 000000005479`, `validator-refreshed-at: 2026-07-03T14:12:08-04:00`.
- The generated file contains UID00040V as `Completion:88 | Confidence:90` with the same two anonymous-namespace `const int` declarations, not an empty marker.
- `auto-generated/-ag-memory-coverage.md` still lists UID00040V as `coded`, owner `0000KK`, emitter `0000KK`, generated output `auto-generated/NexusTK/localization/LanguageMan.cpp`.

Validator warnings/side effects:

- `000000005479` reported existing `missing_ref_uid 0003O5` warnings on `by-file/LanguageMan.md`; these are pre-existing LanguageMan support-reference warnings unrelated to UID00040V.
- `000000005479` reported broad generated child-marker/no-code autogen warnings and updated validator-owned generated metadata/reports; those are validator-owned side effects, not manual edits.
- Validator-owned side effects included `project-level/-auto-completion-stats.md` projected stats updates, `validator.ini` autogen registry rebuild, generated report metadata refresh, and `auto-generated/NexusTK/map/MapPane.cpp` update. No generated or project-level file was edited by hand.

## Changed Files

Manual B007 edits in this implementation callback:

- `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md`
- `by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md`
- `by-file/LanguageMan.md`
- `tools/leaser/Agents/Agent-B007/research/00040V-LanguageManParserLimitConstants-source-quality.md`

Report-text repair after invalidation:

- Repaired only `tools/leaser/Agents/Agent-B007/research/00040V-LanguageManParserLimitConstants-source-quality.md` to normalize current-state/lifecycle wording after supervisor invalidation command `000000005495`.
- No by-* docs were edited in this repair pass; no real missed accepted claim was found.

Scoped validator/generated side effects observed:

- `auto-generated/NexusTK/localization/LanguageMan.cpp` refreshed by validator command `000000005479` and now shows UID00040V `88/90`.
- `auto-generated/-ag-memory-coverage.md` refreshed by validator-owned generated metadata refresh.
- `project-level/-auto-completion-stats.md`, `tools/validator.ini`, generated metadata reports, and `auto-generated/NexusTK/map/MapPane.cpp` had validator-owned side effects during `--wait-generated`; B007 did not edit those manually.

No coverage reports were edited by hand. B007 did not edit supervisor ledgers, report lifecycle/archive files, or report execution state. B007 did not run `execute_report`, dry-run/probing variants, lifecycle commands, manual report moves, or archive commands. The lifecycle history footer records supervisor/validator-owned execution and de-execution events from commands `000000005490` and `000000005495`.

Leases:

- Leased as `B007`: `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md`, `by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md`, and `by-file/LanguageMan.md`.
- Released immediately after the edit/validator batch; `leaser.py B007 unlease ...` returned `Success` for all three files.

## Implementation Tracking Checklist

Implementation callback checklist:

- [x] Update `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md` metadata to `COMPLETION:88`, `CONFIDENCE:90`, preserving owner `0000KK`, reconstructable `TRUE`, emitter `0000KK`, blank position, and unchanged formal C++. Proof: target metadata is `88/90`; formal block remains the two anonymous-namespace `const int` declarations; validator `000000005477` returned `ok:1`.
- [x] Insert current MCP session `e63ee655` evidence into the target at report-level detail: session/health state, bytes/integers, zero xrefs, adjacent vtable/literal refs, constructor `0x400` immediate matches, decompile/disasm semantics, generated-output presence, and no-address-xref confidence cap. Proof: target `Evidence`, `Source Model`, and `Score Rationale` include these facts; validator `000000005477` returned `ok:1`.
- [x] Preserve rejected alternatives in the target: not KeySpeedMgr-owned, not a virtual-slot child, not resource-page-owned, not generic raw `0x400` constants, no three-constant invention, and not ownerless retained-only treatment. Proof: target `Rejected Alternatives` includes all accepted rejections.
- [x] Update `by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md` UID00040V child row/status to `88/90` and fresh MCP-backed summary; keep parent metadata and non-reconstructable aggregate disposition unchanged. Proof: child row is `88/90`; parent metadata unchanged; validator `000000005478` returned `ok:1`.
- [x] Update `by-file/LanguageMan.md` UID00040V likely-content/source-output note, preserving `LanguageMan.cpp` owner/emitter route and no-address-xref caveat. Proof: file page likely contents/evidence/change log now cite B007 session `e63ee655`; validator `000000005479` returned `ok:1`.
- [x] Treat `by-class/LanguageMan.md` as already sufficient. Proof: current class page already states UID00040V is file-level `LanguageMan.cpp` data, not a class field, and no stale UID00040V `86/87` row required editing.
- [x] Treat `by-resource/str-res-localized-strings.md` as already sufficient. Proof: current resource page already links UID00040V as source-side support for 1024 line/count limits and correctly keeps resource ownership limited to DAT payload/format.
- [x] Treat constructor UID00041V as already sufficient. Proof: current constructor page already consumes `kMaxStringResourceLineBytes` and `kMaxLocalizedStringCount` in formal constructor C++ and documents the same parser limit semantics.
- [x] Treat UID00031P, UID00040W, and UID00040X as already sufficient. Proof: current pages already preserve the KeySpeedMgr boundary, LanguageMan vtable boundary, and literal island source route; no stale UID00040V-specific implementation item remained outside the edited parent/file/target docs.
- [x] Run scoped validators only for changed by-* files from `source-3/project-documentation`. Proof: validators `000000005477`, `000000005478`, and `000000005479` all exited 0 with `ok:1`; final command used `--wait-generated`.
- [x] After callback implementation, update this report's Claim And Incorporation Ledger verification states. Proof: ledger rows now end as `applied`, `already-present`, or combined applied/already-present with proof.
- [x] After callback implementation, report validator command IDs/timestamps/exit codes/ok counts, generated freshness, changed files, leases used/released, and any unapplied accepted items. Proof: this report and final response contain those details; no accepted checklist item remains unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000005490","destination_path":"executed-b-agent-research/B007/00040V-LanguageManParserLimitConstants-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00040V-LanguageManParserLimitConstants-source-quality.md","timestamp":"2026-07-03T14:18:27-04:00","uid":"00040V"} -->
<!-- {"agent":"B007","command_id":"000000005495","destination_path":"tools/leaser/Agents/Agent-B007/research/00040V-LanguageManParserLimitConstants-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B007/00040V-LanguageManParserLimitConstants-source-quality.md","timestamp":"2026-07-03T14:19:07-04:00","uid":"00040V"} -->
<!-- {"agent":"B007","command_id":"000000005523","destination_path":"executed-b-agent-research/B007/00040V-LanguageManParserLimitConstants-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00040V-LanguageManParserLimitConstants-source-quality.md","timestamp":"2026-07-03T14:45:48-04:00","uid":"00040V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
