** TARGET-REPORT-UID:0002VT **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002VT ConnectionReconnectDialogSingletonGlobals Ownership / Split Research


## Finalized Report / Current Recommendation

- Current implemented disposition:
  - UID0002VT remains at exact range `[0x0067ab54,0x0067ab5c)` and is now a `92/94`, `RECONSTRUCTABLE:FALSE` non-emitting container with blank owner, emitters, optional position, and formal C++; `Nested:4` is preserved.
  - UID0004SQ covers `[0x0067ab54,0x0067ab58)` as exact storage for `g_pConnectionClosedDialog`, is `92/94`, and is owned/emitted by UID0004SO.
  - UID0004SR covers `[0x0067ab58,0x0067ab5c)` as exact storage for `g_pReconnectDialog`, is `92/94`, and is owned/emitted by UID0004SP.
  - UID0004SO is `by-global/g_pConnectionClosedDialog.md`, is `91/93`, and emits the sole source definition through UID0000N0.
  - UID0004SP is `by-global/g_pReconnectDialog.md`, is `91/93`, and emits the sole source definition through UID0000N0.
  - UID0002VU now has the required relative `Nested:-4` exit while preserving its score, route, formal, range, and timing facts.
- Callback completion: the two by-global pages were registered first, the two exact by-memory children were then registered with their real validator-issued UIDs, all placeholders were replaced, the bounded ReconnectDialog support family was synchronized, every changed ordinary destination was scoped-validated, and B003 waited generated command `000000014152` passed the accepted one-definition/no-target-marker assertions. Latest observed read-only external header command `000000014173` preserves the same generated body/counts; later unrelated header epochs remain external state.
- Confidence: very strong for bytes, range, types, lifecycle, external linkage, source file, split, direct `Singleton<T>` base source cause, and one-definition routing; strong for the exact source-facing `g_p...` spellings and use of `NULL`, which remain lexical inferences because no original PDB/source symbol survives.

## Supporting Research

- Assignment source: canonical `tools/leaser/Agents/Agent-B003/goal.md` new-report override for UID0002VT.
- Evidence-time queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, row 2189, with target score `88/90`, reconstructable true, and direct B-report count zero before callback implementation.
- Evidence-time tracker snapshot:
  - SHA256 `9C3AE933CA0C8BA3194D488C0DE448ED929A0B80E3951A8F92075B72DA9FDC24`.
  - `1,502,573` bytes.
  - `6,108` lines.
- Healthy live IDA MCP evidence pass:
  - Endpoint: `http://127.0.0.1:13337/mcp`.
  - Fresh `idb_list` returned the single active NexusTK session `64c11373`.
  - `server_health` returned `status=ok`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and strings cache with 2,067 strings.
  - The bounded target read returned eight zero bytes at `0x0067ab54`.
  - These are evidence-collection facts from 2026-07-16, not an indefinite assertion that the same worker/session must remain current later.
- Input image used by the healthy IDB:
  - `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
  - SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
  - Size `2,679,296` bytes.
- Historical report search terms:
  - `0002VT`
  - `0x0067ab54`
  - `ConnectionReconnectDialogSingletonGlobals`
  - `g_pConnectionClosedDialog`
  - `g_pReconnectDialog`
  - `unk_67AB54`
  - `unk_67AB58`
- Historical report roots checked:
  - `tools/leaser/Agents/Agent-B001/research/**`: no match.
  - `tools/leaser/Agents/Agent-B002/research/**`: no match.
  - `tools/leaser/Agents/Agent-B003/research/**`: no prior target report.
  - `tools/leaser/Agents/Agent-B004/research/**`: no match.
  - `tools/leaser/Agents/Agent-B005/research/**`: no match.
  - `executed-b-agent-research/**`: five lead-only matches classified below.
  - `archived/**`: no match.
  - `tools/leaser/Agents/Older-Research/**`: no match.
  - `tools/leaser/Agents/SpecialReports/**`: no match.
- Executed-report match classification:
  - B007 `0002H2-ApplicationRunMessageLoop-empty-emitter-source-quality.md`: support-only reference to UID00029B and Application counters; no target value, type, source, split, or formal decision.
  - B008 `0000LG-MiscWorkThread-empty-emitter-family-source-quality.md`: direct predecessor comparator proving stale all-ones documentation can be corrected to zero and routed through one by-global definition plus a no-duplicate exact storage child.
  - B001 `0001CJ-MiscWorkThreadAndNotifications-source-quality.md`: predecessor/support lead only; no target-specific conclusion.
  - B014 `000039-CopyWindow-class-source-quality.md`: boundary support proving `0x00554550` is outside CopyWindow and clears target slot `0x0067ab54`.
  - B001 `00029T-MainMenuTextUrlStaticString.md`: predecessor link only; no target-specific source decision.
- Lifecycle/status wording: research, implementation, scoped validation, and waited generated verification are complete in this artifact. B003 performed no `execute_report`, report execution/probe/count, move, archive, or lifecycle command. Exact report path, execution state, count, archive state, and later validator epochs remain external supervisor/validator-owned state and are neither asserted nor directed here.

## Target

- Target UID: `0002VT`.
- Target path: `by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md`.
- Exact range: `[0x0067ab54,0x0067ab5c)`.
- Exact size: `0x8` / 8 bytes (Verified with `int_convert.py`).
- Historical pre-callback source queue row: `88/90`, reconstructable true, no direct B report.
- Implemented target classification: exact non-emitting two-slot container with separate source-emitting by-global concepts and exact storage children.
- Implemented scores and parent state:
  - Target `92/94`.
  - Current owner/emitter blank.
  - Current `RECONSTRUCTABLE:FALSE`.
  - Current `Nested:4`.
  - Parent UID00029B is a `90/92`, ownerless, non-reconstructable aggregate map with `Nested:0`.
  - Successor UID0002VU remains `88/91` and reconstructable, with current `Nested:-4`.

## Current Target State

- Current target SHA256: `3EE34BC07080D87FE3C519AEAC8A5AC26FA800426CF0CE9EEC9B77AF000E5EC0`.
- Current target metrics: `12,150` bytes / `143` lines.
- Implemented metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - blank canonical owner
  - `RECONSTRUCTABLE:FALSE`
  - blank emitters
  - blank optional position
  - blank formal C++
  - `Nested:4`
- Implemented owner/emitter/reconstructable state: UID0002VT is the exact non-emitting containment page; UID0004SO/UID0004SP own and emit the source definitions, and UID0004SQ/UID0004SR record the exact storage.
- Current C++/emitter state: the blank UID0002VT formal is correctly non-emitting; B003 waited command `000000014152` established zero UID0002VT Empty Emitter Markers and latest observed external header command `000000014173` preserves that result.
- Historical pre-callback stale assumptions, now explicitly superseded in the ordinary documentation:
  - Both dwords are documented as `ff ff ff ff`.
  - The page says the 2026-06-07 live recheck saw `0xffffffff`.
  - Both slots are treated as one semantic item directly owned by the file root.
  - Constructor publication and tiny clears are described as ordinary global/helper behavior instead of direct `Singleton<T>` base lowering.
  - The page has no direct by-global owner pages and no exact one-dword child pages.
- Applied corrective evidence:
  - Healthy MCP reads `00 00 00 00 00 00 00 00`.
  - Both target RVAs are in the virtual-only tail of `.data`, beyond the section's raw-backed bytes.
  - The PE has no base relocation directory.
  - RTTI proves two distinct `Singleton<T>` direct bases and two distinct type identities.
  - The slot lifecycles never cross: ConnectionClosedDialog writes/clears only `0x0067ab54`; ReconnectDialog writes/clears only `0x0067ab58`.
- Related target/support docs checked:
  - UID00029B mixed parent.
  - UID0001P8 predecessor.
  - UID0002VU successor.
  - UID0000N0 file owner.
  - UID000036 and UID0000BR classes.
  - UID0001FT mixed executable aggregate.
  - UID00038J, UID00038L, and UID00038K method/cleanup support.
  - UID0000YT heartbeat consumer.
  - UID0003CT and UID0003CU vtable-data pages.
  - Singleton/global comparators `g_frameRegistry`, `g_pRankingDialog`, `g_pScreenDimmer`, `g_pUserListDialogPane`, `g_pSimpleHelpPane2`, and `g_pHourPane`.
- Historical pre-callback generated evidence:
  - `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
  - Evidence-time external validator header command: `000000014094`.
  - Refreshed `2026-07-16T13:41:34-04:00`.
  - SHA256 `C79B61C9D16FCCEF5526DE0313F02E48E7C406A54721FBC29A28A1DE42EC0ED7`.
  - `1,272` bytes / `26` lines.
  - It contained one UID0002VT Empty Emitter Marker and zero definitions for either target pointer.
- B003 waited generated callback evidence:
  - Waited validator command/header `000000014152`, refreshed `2026-07-16T14:18:33-04:00`.
  - Historical callback SHA256 `52367E6C25257A75BE5CAF65347CE7F34DC70A0012F4B2A1A129B240C2B64274`.
- Latest read-only external generated checkpoint:
  - Header command `000000014173`, refreshed `2026-07-16T14:29:37-04:00`.
  - SHA256 `4F84D0ACD76893201D259460FFB2AE4F0FB94451292601E9EABA0494864D75D0`.
  - `2,335` bytes / `49` lines.
  - Exactly one `ConnectionClosedDialog *g_pConnectionClosedDialog = NULL;` definition and one `ReconnectDialog *g_pReconnectDialog = NULL;` definition.
  - Exactly one UID0004SQ covered-storage comment and one UID0004SR covered-storage comment.
  - Zero UID0002VT and UID00038K Empty Emitter Markers.
  - Zero explicit template-specialization, handwritten Singleton lifecycle, vtable/RTTI-array, scalar-delete-wrapper, or EH-support source.
  - Zero raw address literals in emitted C++/formal content. Twelve address strings occur only in validator provenance path comments for existing by-memory entries.
  - Independent current Empty Emitter Markers for UID000036, UID00023O, UID00038J, UID0000BR, and UID00038L remain separate class/method declaration debt and are not falsely claimed solved by this target.
- Current artifact/lifecycle status: accepted callback implementation and validation are complete. B003 did not edit generated output directly, manual coverage, tracker/audit/supervisor/validator state, or IDA and did not run any report lifecycle command.

## Executive Recommendation

- The physical target is implemented as two exact one-dword storage children because the slots have different types, direct Singleton specializations, constructor/destructor families, and global concept pages.
- UID0002VT is retained as the exact two-slot containment map so historical range references remain stable, and is now non-reconstructable and non-emitting.
- Dedicated by-global pages UID0004SO `g_pConnectionClosedDialog` and UID0004SP `g_pReconnectDialog` now carry the source definitions.
- Both definitions emit in `NexusTK/network/ReconnectDialog.cpp` through UID0000N0.
- Use external linkage. Application heartbeat code reads both slots from a distinct source module, so file-local `static` is not source-safe without an unobserved accessor or same-TU merge.
- Use the project-canonical source-facing types:
  - `ConnectionClosedDialog *`
  - `ReconnectDialog *`
- Use `NULL` as the formal initializer. Zero initialization is binary-proven; `NULL` is the best era/project style choice. The exact original token could have been `0` or omitted, so token-level certainty remains confidence-capped.
- Do not emit explicit constructor assignments, destructor clears, EH cleanup calls, scalar flags, vptr stores, or template static-member specializations. Direct Singleton base construction/destruction explains those binary copies.
- The validator issued UID0004SO, UID0004SP, UID0004SQ, and UID0004SR in the required order; all dependent ordinary pages and formal references use those real UIDs.

## Supervisor Active Recheck

- The exact pre-callback report SHA `EA72D17BD8EACA70C3594AD80A68D338E238A548A2149641F38E82C1B1A0E93B` passed supervisor Gate 1 and authorized the bounded callback.
- The split repair is now applied: the former two-slot source emitter is a retained container with two direct semantic globals and two exact storage children.
- Every source-bearing item in the target range has a validated current destination:
  - UID0004SO and UID0004SP by-global definitions;
  - UID0004SQ and UID0004SR exact by-memory covered-storage children;
  - UID0002VT retained non-emitting container.
- No source-bearing target byte remains without a recommended route.
- No fallback-only evidence was used. The mandatory live MCP pass succeeded.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest semantic owner and separates canonical ownership from emitter routing. That rule rejects direct file ownership for the exact one-dword children once dedicated global concepts exist.
- `by-memory/-guidance.md` requires exact children for understood source-bearing subranges and real nesting under aggregate parents. That rule favors two exact dword children under UID0002VT.
- `by-global/-guidance.md` explicitly includes singleton pointers and exact static-member/global lifetime storage. That is the correct durable home for each source-facing pointer concept.
- Existing documentation assumptions treated as uncertain:
  - all-ones bytes;
  - source initializer/sentinel;
  - one combined source object;
  - handwritten clear helpers;
  - direct file owner as the narrowest owner;
  - local/static versus external linkage.
- Evidence separation:
  - Direct IDA/PE fact: bytes, xrefs, instruction sequences, RTTI descriptors, PMD values, function bounds, `.data` virtual/raw boundaries, and absent relocation directory.
  - Documentation evidence: current UID routes, source folder, prior names, generated markers, and accepted Singleton comparator conventions.
  - Inference: exact lexical `g_p...` spelling, `NULL` rather than `0`, and whether the original template used a named external variable or static specialization spelling.
- Wave2/Wave3 mentions were encountered only in general guidance/current historical docs. They were ignored as stale authority and were not used to prove this report.

## Heuristic / Inference Reanalysis And Validation

### Static value and initializer

- Best defensible conclusion: both slots are zero-initialized static storage.
- Direct evidence:
  - Live MCP reads eight zero bytes.
  - `get_global_value` reads `0x0` for each dword.
  - The target lies `0x354` / 852 bytes and `0x358` / 856 bytes past the `.data` raw-backed end (Verified with `int_convert.py`).
  - The target lies inside `.data` virtual size and therefore receives loader zero-fill.
  - The executable has relocation RVA/size `0/0`; neither target RVA has a relocation.
- Rejected alternatives:
  - Real `0xffffffff` source initializer: contradicted by virtual-only storage and current zero bytes.
  - Loader relocation artifact: contradicted by no relocation directory and virtual-only target storage.
  - Pre-runtime poison: no startup writer or xref exists.
  - Sentinel reset before use: no xref writes `-1`, compares against `-1`, or runs before the first constructor/consumer path.
  - Stale IDB cache as current truth: the healthy live session and PE mapping agree on zero.

### Type identity

- `ConnectionClosedDialog *` for slot `0x0067ab54`:
  - constructors install `ConnectionClosedDialog` vtables;
  - allocations are `0x270` / 624 bytes (Verified with `int_convert.py`);
  - RTTI string `.?AVConnectionClosedDialog@@`;
  - direct `Singleton<ConnectionClosedDialog>` RTTI string and BCD.
- `ReconnectDialog *` for slot `0x0067ab58`:
  - constructors install `ReconnectDialog` vtables;
  - allocations are `0x274` / 628 bytes (Verified with `int_convert.py`);
  - RTTI string `.?AVReconnectDialog@@`;
  - direct `Singleton<ReconnectDialog>` RTTI string and BCD.
- Rejected types:
  - `AlertPane *`: loses the exact derived identity proved by constructors/vtables/RTTI.
  - `Pane *`, `void *`, or integer dword: weaker than direct type evidence.
  - one union or generic dialog pointer array: contradicted by distinct non-indexed xref families and separate types.

### Singleton source cause

- Both class hierarchies have nine RTTI entries and multiple-inheritance attribute `1`.
- ConnectionClosedDialog Singleton BCD:
  - descriptor `0x0064e9d8`;
  - type descriptor `0x00678b54`;
  - PMD `mdisp=0x270`, `pdisp=-1`, `vdisp=0`;
  - attributes `0x40`.
- ReconnectDialog Singleton BCD:
  - descriptor `0x0064eab8`;
  - type descriptor `0x00678ba8`;
  - PMD `mdisp=0x270`, `pdisp=-1`, `vdisp=0`;
  - attributes `0x40`.
- The source inheritance direction is therefore:
  - `ConnectionClosedDialog : public AlertPane, public Singleton<ConnectionClosedDialog>`
  - `ReconnectDialog : public AlertPane, public Singleton<ReconnectDialog>`
- ConnectionClosedDialog's empty Singleton base is at one-past the `0x270` complete allocation.
- ReconnectDialog's empty Singleton base overlaps derived storage beginning at `+0x270` through EBO; `InitiateReconnect` writes one byte there and the complete allocation is `0x274`.
- Constructor sequence:
  - build AlertPane/base state;
  - derive `this+0x270`;
  - null-check the adjusted base pointer;
  - subtract `0x270`;
  - store the complete derived pointer.
- That sequence is characteristic compiler lowering of a direct Singleton base constructor, not a plausible handwritten `g_p... = this` expression.

### Cleanup/helper identity

- `0x00554550-0x0055455b` has exactly three code xrefs, all from constructor EH actions that add `0x270` and tail-jump to the target.
- `0x00554560-0x0055456b` has exactly three code xrefs, all from Reconnect constructor/replacement EH actions with the same base adjustment.
- Best source identities:
  - compiler-instantiated `Singleton<ConnectionClosedDialog>::~Singleton()`
  - compiler-instantiated `Singleton<ReconnectDialog>::~Singleton()`
- Rejected names:
  - `ClearConnectionClosedDialogSingleton`
  - `ClearReconnectDialogSingleton`
  - startup/static cleanup helper
  - public class method
- The four 11-byte vtable adjustors and two scalar deleting destructor bodies are also compiler-generated ABI consequences, not independent human source bodies.
- UID00038K should therefore be `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal C++.

### Source-facing names

- `g_pConnectionClosedDialog` and `g_pReconnectDialog` are not current IDA names; `entity_query` found no matching global/name entities at the target.
- They remain the strongest source-facing names because:
  - both exact class names are RTTI-proven;
  - the project consistently uses `g_p<ClassOrRole>` for active singleton pointers;
  - current by-file/by-class/by-memory docs already use these spellings consistently;
  - no competing source-quality name has evidence.
- Names are inferred/project-canonical, not original-symbol proof.
- Rejected aliases:
  - `dword_67AB54`, `unk_67AB54`, `dword_67AB58`, `unk_67AB58`: raw binary provenance.
  - `g_pConnectionDialog`: too broad.
  - `g_pConnectionLostDialog`: less consistent with exact RTTI class name.
  - `g_pActiveReconnectPane`: loses class identity and uses pane terminology not supported by RTTI.

### Linkage and source placement

- External linkage is behaviorally required under the documented source split:
  - definitions belong to ReconnectDialog source;
  - Application heartbeat code reads both pointers.
- File-local `static` would require either:
  - Application and ReconnectDialog to have been one translation unit, contradicted by the accepted source map; or
  - an accessor/inlined header variable mechanism, for which no call or wrapper evidence exists.
- Best source placement: `NexusTK/network/ReconnectDialog.cpp` through UID0000N0.
- `login/ReconnectDialog.cpp` remains a historical folder alternative only; network packet/reconnect/disconnect behavior and the current reconstruction route make `network/` stronger.

### Split and container decision

- Retaining one two-slot source emitter is rejected because:
  - two different types;
  - two different by-global concepts;
  - two distinct direct Singleton specializations;
  - independent lifecycle writers/clearers;
  - no source array/indexing or shared struct access.
- Deleting UID0002VT is rejected because it is a useful historical exact-range container and existing references use it.
- Correct disposition:
  - keep UID0002VT as non-emitting container;
  - create two exact children;
  - create two by-global pages;
  - preserve the broad UID00029B parent.

### Generated-output blocker

- Historical pre-callback UID0002VT Empty Emitter Marker could not be solved by adding both definitions to the parent container because that would preserve the structural collapse.
- The implemented solution is:
  - making the container non-emitting;
  - emitting one definition from each by-global page;
  - emitting one covered-storage comment from each exact dword child.
- Waited command `14152` confirms zero UID0002VT and UID00038K markers. Existing UID000036/UID00023O/UID00038J/UID0000BR/UID00038L markers are independent and are not misreported as target failure after this split.

## Evidence Standards Used

- IDA MCP evidence:
  - fresh `idb_list`;
  - `server_health`;
  - bounded `get_bytes`;
  - `get_global_value`;
  - `xref_query`;
  - `lookup_funcs`;
  - bounded `disasm`;
  - `find_regex`;
  - `entity_query`.
- Binary/manual evidence:
  - PE32 header parsing;
  - section raw/virtual extent mapping;
  - relocation directory inspection;
  - target VA/RVA byte-pattern search;
  - target eight-byte SHA256.
- Documentation evidence:
  - current target/parent/neighbors;
  - direct class/file/method/cleanup/heartbeat pages;
  - current generated `ReconnectDialog.cpp`;
  - current manual coverage rows;
  - current tracker;
  - project Singleton/global comparators;
  - search-gated executed reports.
- Evidence ladder:
  - live bytes/instructions/RTTI/PE mapping are primary;
  - current by-* docs and generated output are support/current-state evidence;
  - old reports are leads only;
  - source spelling and initializer token are inference.
- Strength:
  - byte/storage/lifecycle/type/split conclusions are independently corroborated by MCP and PE evidence.
  - exact lexical names and `NULL` token remain below original-proof confidence.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks:
  - target bytes at `0x0067ab54` and surrounding `0x0067ab50-0x0067ab83`;
  - target values at both dwords;
  - all ten data xrefs to each slot;
  - function lookup for all constructor, handler, cleanup, scalar-wrapper, and heartbeat functions;
  - constructor adjustment/store instructions;
  - cleanup function code xrefs;
  - scalar wrapper clear/delete sizes;
  - heartbeat branch order;
  - RTTI class and Singleton strings;
  - COL/CHD/base-array/BCD bytes for both classes;
  - current target data-name/global-name absence.
- PE/image checks:
  - PE32 machine `0x014c`;
  - image base `0x00400000`;
  - `.data` RVA `0x0026d000`;
  - `.data` raw size `0x0d800`;
  - `.data` virtual size `0x2fe24`;
  - raw-mapped end RVA `0x0027a800`;
  - target RVAs `0x0027ab54` and `0x0027ab58`;
  - no relocation directory;
  - no target relocation;
  - exact target hash;
  - ten occurrences each of absolute VA operands `54 AB 67 00` and `58 AB 67 00`;
  - zero occurrences each of RVA byte patterns `54 AB 27 00` and `58 AB 27 00`.
- Current documentation checked:
  - target UID0002VT;
  - parent UID00029B;
  - predecessor UID0001P8;
  - successor UID0002VU;
  - file UID0000N0;
  - classes UID000036/UID0000BR;
  - executable aggregate UID0001FT;
  - method/cleanup UID00038J/UID00038L/UID00038K;
  - heartbeat UID0000YT;
  - vtable data UID0003CT/UID0003CU;
  - current by-memory/by-class/by-file/by-global manual coverage;
  - current generated ReconnectDialog source;
  - current tracker and lease report.

### Current ordinary support snapshot

| Path | SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md` | `3EE34BC07080D87FE3C519AEAC8A5AC26FA800426CF0CE9EEC9B77AF000E5EC0` | `12,150 / 143` |
| `by-global/g_pConnectionClosedDialog.md` | `AB58873E3ECF7E855269F4F776FD3381BE8878CA2717CDEF71090AB0C79EC869` | `7,024 / 95` |
| `by-global/g_pReconnectDialog.md` | `D6E1BF11581754C2081D911145EE22FC87132A311783CB785D3B0C0B623F0446` | `6,952 / 95` |
| `by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md` | `EC8B01085232CDFBEA08CEE5B194436BA107CDAA11E774474ECF221064A541D8` | `6,948 / 87` |
| `by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md` | `4AE31C3FA070CF84A061DF2E81E78148B44919EB6EBFDEA53561963115A8E350` | `7,018 / 89` |
| `by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md` | `2DDB930E7D864987DCFE8C47C1EEA487307D047238CA6612ACB0988DF05A4455` | `18,290 / 127` |
| `by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md` | `E3F9911D8FEBC5C8AD3FD255F8C15A06DB872329B60C4E6EC3856B08273D0259` | `6,561 / 77` |
| `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md` | `3046522FDEC7CACB8BDB8E2F53CCF8DBCE9090376871D5FB4144ED8CBA46EDCE` | `8,088 / 73` |
| `by-file/ReconnectDialog.md` | `840113D078756788A03AC16D44616BD625DC152CC94F9DCA57A7C5C416F56E72` | `23,354 / 154` |
| `by-class/ConnectionClosedDialog.md` | `2C19351D1938CC665042A57D57FFC64B1782071B3530E89258340FCAD9031ED8` | `17,725 / 128` |
| `by-class/ReconnectDialog.md` | `371D93ED23E1F17B1267D6781459A77F5951922451785341826EA22974A4D36E` | `13,331 / 111` |
| `by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md` | `D08E37B19A80009351F04BD74084600F5A587C5E9F5876A3200B380111685918` | `19,573 / 132` |
| `by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md` | `F113DD10F051BE8D9F95910AD3270DC77C9C34D55B54FD09616F6528542FC2F3` | `9,643 / 91` |
| `by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md` | `411B103FD8FABE7FE8746B08F05868A360CE06F7BACD34D1E68C999E46B08321` | `10,691 / 98` |
| `by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md` | `1148CD739DACA8835AAD44544B850C8599AC4665B7592B0BC3CAEB2F299453AA` | `11,605 / 101` |
| `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md` | `B516067F3B76F22436796D56539B47E6FE7A3F0B23F49257A711842D32418232` | `17,724 / 126` |
| `by-memory/0x00622d30-0x00622dd4.ConnectionClosedDialogVtableData.md` | `CED5B6794FEE6338D3DF96E8EF30293CD6C9260C19C8FD2B140764898820D78D` | `2,244 / 35` |
| `by-memory/0x00622dd4-0x00622e78.ReconnectDialogVtableData.md` | `ECBAC16F516F806AFC19F9149A8FBEF82275250E0D47B46ADA33A62EDF4E52EC` | `2,186 / 35` |

- Negative checks:
  - no `-1` compare/write xref;
  - no startup/static-init target writer;
  - no relocation;
  - no file-backed initializer;
  - no target global/name entity;
  - no string/resource or pointer-array access;
  - no ordinary call to the tiny Singleton destructor support functions;
  - no prior direct B report.
- Intentionally skipped:
  - IDA mutation, rename, type application, and comments, because both the initial research phase and callback prohibit IDA mutation.
  - Wave2/Wave3/simroot evidence as authority, because current workflow marks it stale lead material.
- Callback update:
  - ordinary scoped validators and one waited generated refresh were subsequently authorized and completed as recorded under `Validator Results`;
  - B003 still made no manual generated, coverage, tracker, audit, supervisor, validator-state, or lifecycle edit.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Healthy evidence-time MCP session `64c11373` returned `status=ok` and real target bytes. | original-proof | fresh `idb_list`, `server_health`, bounded `get_bytes` | UID0002VT Evidence; affected support evidence notes | incorporate | applied | The captured evidence-time session/health/read facts are incorporated in UID0002VT and the four new global/storage pages. UID0002VT passed scoped validator `14119` at `2026-07-16T14:03:53-04:00`, exit `0`, `ok:1`. |
| C02 | `[0x0067ab54,0x0067ab5c)` is eight loader-zero-filled `.data` bytes with SHA256 `AF5570...83DFC`, not `0xffffffff`. | original-proof | MCP bytes/value plus PE raw/virtual mapping | UID0002VT; UID00029B; manual rows | reject-stale | applied | UID0002VT and UID00029B now document current zero-fill/PE mapping and historicalize all-ones text. Validators `14119` and `14122` both exited `0`, `ok:1`; exact manual replacement text remains supervisor-owned. |
| C03 | The exact target has two adjacent four-byte slots, no internal padding, predecessor UID0001P8, and successor UID0002VU. | original-proof | range arithmetic, current pages, bounded bytes | UID0002VT; UID0004SQ/UID0004SR; UID00029B | incorporate | applied | UID0004SQ and UID0004SR were registered at exact adjacent ranges; UID0002VT/UID00029B carry the complete boundary inventory. Final child rescans `14148` and `14149` and target/parent validators `14119`/`14122` exited `0`, `ok:1`. |
| C04 | Slot `0x0067ab54` has exactly ten refs covering heartbeat read, three construction/publication pairs, replacement read, EH clear, and scalar clear. | original-proof | `xref_query` and disassembly | UID0004SQ; UID0004SO; UID00038J/UID00038L/UID00038K; UID0000YT | incorporate | applied | The ten-reference inventory is incorporated in UID0004SO/UID0004SQ and synchronized into UID00038J/UID00038L/UID00038K/UID0000YT. Final effective validators `14143`, `14148`, `14132`, `14134`, `14145`, and `14142` exited `0`, `ok:1`. |
| C05 | Slot `0x0067ab58` has exactly ten refs covering heartbeat read, replacement read, three construction/publication pairs, EH clear, and scalar clear. | original-proof | `xref_query` and disassembly | UID0004SR; UID0004SP; UID00038J/UID00038L/UID00038K; UID0000YT | incorporate | applied | The ten-reference inventory is incorporated in UID0004SP/UID0004SR and synchronized into UID00038J/UID00038L/UID00038K/UID0000YT. Final effective validators `14144`, `14149`, `14132`, `14134`, `14145`, and `14142` exited `0`, `ok:1`. |
| C06 | RTTI proves direct `Singleton<ConnectionClosedDialog>` and `Singleton<ReconnectDialog>` bases at PMD `+0x270`. | original-proof | strings, COL/CHD/BCA/BCD bytes | UID000036; UID0000BR; UID00038K; globals/children | incorporate | applied | Exact direct-base, PMD, allocation/EBO, and storage-route evidence is present in both class pages, UID00038K, and all four new pages. Clean final class rescans `14150`/`14151`, UID00038K validator `14145`, global validators `14143`/`14144`, and child validators `14148`/`14149` all exited `0`, `ok:1`. |
| C07 | Constructor writes are compiler-inlined Singleton base publication, not source-authored explicit assignments. | very strong inference | adjusted-base `lea/test/sub/store` pattern, RTTI | UID00038J; UID00038L; class/global pages | historicalize | applied | UID00038J/UID00038L and both class/global families now state the compiler-lowered publication source cause and preserve the older direct-assignment wording only as history. Validators `14132`, `14134`, `14150`, `14151`, `14143`, and `14144` passed. |
| C08 | `0x00554550` and `0x00554560` are EH-only Singleton base destructor instantiations, not handwritten clear helpers. | original-proof | exact three EH xrefs each, PMD adjustment, 11-byte zero-store bodies | UID00038K; UID0001FT; class/file pages | reject-stale | applied | UID00038K and UID0001FT now use exact EH-only Singleton/compiler terminology; stale helper wording is explicitly historical. Final validators `14145` and `14146` exited `0`, `ok:1`; class rescans and final by-file validator also passed. |
| C09 | UID00038K is entirely compiler-generated destructor support and should be false/non-emitting with blank formal C++. | very strong inference | wrapper/thunk roles, vtable refs, scalar flags/delete, EH-only helpers | UID00038K | incorporate | applied | UID00038K is current `90/94`, owner UID0000N0 as documentation grouping, reconstructable false, blank emitter/position/formal, with complete no-code proof. Validator `14145` exited `0`, `ok:1`; generated command `14152` has zero UID00038K Empty Emitter Markers and emits no wrapper/EH source. |
| C10 | Heartbeat reads are consumer gates only: send proceeds only when both dialog pointers are null. | original-proof | `0x00466f22`, `0x00466f2f`, branch at `0x00466f36` | UID0000YT; global pages | incorporate | applied | UID0000YT now records the exact typed null gate and consumer-only ownership, while UID0004SO/UID0004SP link the consumer without assigning ownership to Application. Validators `14142`, `14143`, and `14144` exited `0`, `ok:1`. |
| C11 | Best source-facing names/types are external `ConnectionClosedDialog *g_pConnectionClosedDialog` and `ReconnectDialog *g_pReconnectDialog`. | strong inference | exact RTTI types, project naming convention, cross-module consumer | UID0004SO; UID0004SP | incorporate | applied | UID0004SO and UID0004SP carry exact R1/R2 definitions, inferred-name/access confidence caps, and external linkage. Registration validators `14109`/`14111` issued the real UIDs; final validators `14143`/`14144` exited `0`, `ok:1`; generated command `14152` emits each definition once. |
| C12 | Both definitions belong to `NexusTK/network/ReconnectDialog.cpp` through UID0000N0; `login/` remains weaker historical placement. | very strong inference | constructor/handler family, packet/reconnect behavior, current file route | UID0000N0; UID0004SO; UID0004SP | incorporate | applied | UID0000N0 is current `89/91` and routes both definitions/storage children through `network/ReconnectDialog.cpp`, preserving the weaker historical placement. Final by-file validator `14152` exited `0`, `ok:1`; generated header/source route is `NexusTK/network/ReconnectDialog.cpp`. |
| C13 | UID0002VT must become a non-emitting container and split into two exact storage children. | very strong inference | distinct types, separate Singleton bases, independent xrefs, by-structure rules | UID0002VT; UID0004SQ/UID0004SR; UID00029B | incorporate | applied | UID0002VT is current `92/94`, owner/emitter blank, false, blank formal, `Nested:4`; UID0004SQ/UID0004SR are registered exact children and UID00029B preserves the full mixed parent inventory. Validators `14119`, `14148`, `14149`, and `14122` passed. |
| C14 | Dedicated by-global pages are missing and should emit the only two `NULL` definitions. | strong inference | cross-TU use, accepted Singleton/global comparators, no existing pages | UID0004SO/UID0004SP | incorporate | applied | UID0004SO and UID0004SP were registered before their storage children and now emit the only two definitions. Registration commands `14109`/`14111` and final validators `14143`/`14144` succeeded; generated command `14152` counts each definition exactly once. |
| C15 | Relative nesting is parent UID0002VT `+4`, first child `+4`, second child `0`, and successor UID0002VU `-4`; cumulative following level is preserved. | original-proof | current address order/indentation and relative-delta semantics | UID0002VT; UID0004SQ/UID0004SR; UID0002VU | incorporate | applied | Current metadata is UID0002VT `Nested:4`, UID0004SQ `Nested:4`, UID0004SR `Nested:0`, UID0002VU `Nested:-4`; all following levels remain unchanged. Validators `14119`, `14148`, `14149`, and `14120` passed. |
| C16 | UID000036/UID0000BR should record exact direct Singleton inheritance, allocation/EBO facts, typed globals, and external-linkage route while preserving blank class formals. | very strong inference | RTTI/allocations/current class debt | UID000036; UID0000BR | incorporate | applied | UID000036 and UID0000BR are current `88/92`, preserve owner/emitter UID0000N0 and blank formals, and contain the accepted inheritance/PMD/EBO/global evidence. Clean final validators `14150` and `14151` exited `0`, `ok:1`. |
| C17 | UID00038J/UID00038L/UID0001FT should replace explicit-global/helper language with compiler-lowered publication and exact split/source facts. | very strong inference | disassembly, RTTI, current docs | UID00038J; UID00038L; UID0001FT | incorporate | applied | UID00038J/UID00038L are current `88/92`; UID0001FT is current `90/93`; compiler/source distinctions and exact routes are synchronized without losing existing method/CopyWindow facts. Validators `14132`, `14134`, and final `14146` passed. |
| C18 | UID00029B, UID0000N0, and UID0000YT should preserve current unrelated content while historicalizing all-ones and helper/source-placement errors. | very strong inference | current support docs plus target evidence | UID00029B; UID0000N0; UID0000YT | incorporate | applied | The three support pages preserve unrelated children, packet/timing, resource, source-family, and counter facts while correcting only bounded stale statements. Validators `14122`, final `14152`, and `14142` exited `0`, `ok:1`. |
| C19 | Generated callback result should have two definitions and two covered-storage comments once each, no UID0002VT/UID00038K marker, and no duplicate/raw/template-specialization source. | implementation-ready | formal R0-R4 and current generated baseline | final waited ReconnectDialog generated readback | incorporate | applied | B003 waited command `14152` produced historical callback SHA `52367E6C...2B64274`; latest observed read-only external header command `14173` produces SHA `4F84D0AC...64D75D0`, 2,335 bytes/49 lines, with the same R1/R2 definitions once each, R3/R4 comments once each, zero UID0002VT/UID00038K markers, and zero forbidden source constructs. Twelve address strings occur only in provenance path comments, not emitted C++/formal content. |
| C20 | Manual coverage requires exact by-memory/by-global inserts/replacements and stale class/file/support row synchronization; B003 must not edit those files. | original-proof | current manual snapshots/rows | supervisor-owned coverage handoff | incorporate | applied | Current read-only manual hashes/anchors were reread after callback; the exact no-loss replacement/insertion text below uses UID0004SO/UID0004SP/UID0004SQ/UID0004SR. B003 made zero manual coverage edits. Application/execution of those rows remains supervisor-owned external state. |

## Positive Evidence Summary

- Eight current target bytes are zero.
- Target is virtual-only `.data`, not file-backed initialized data.
- No relocation directory exists.
- Exactly ten refs exist for each slot and every ref has a coherent role.
- Each slot's writers/clearers belong to only one exact class specialization.
- RTTI directly names both `Singleton<T>` specializations.
- Both Singleton base descriptors use PMD `+0x270`.
- Constructor EH actions adjust to `+0x270` before tail-jumping to the tiny clear bodies.
- The tiny clear bodies have no ordinary calls.
- Scalar deleting wrappers clear the same respective slots and use exact class allocation sizes.
- Heartbeat is a read-only cross-module consumer.
- Current documentation already converges on `g_pConnectionClosedDialog`, `g_pReconnectDialog`, and ReconnectDialog source placement.
- Accepted project comparators use one source definition plus exact no-duplicate storage evidence.
- The evidence is sufficient to close bytes, type, owner, emitter, split, linkage, source placement, no-code, and generated-marker blockers.

## IDA MCP Facts

- Database/session at evidence collection: `64c11373`.
- Module: `NexusTK.exe`.
- Image base: `0x00400000`.
- Target bytes: `00 00 00 00 00 00 00 00`.
- Target eight-byte SHA256: `AF5570F5A1810B7AF78CAF4BC70A660F0DF51E42BAF91D4DE5B2328DE0E83DFC`.
- Slot values:
  - `0x0067ab54 = 0x00000000`
  - `0x0067ab58 = 0x00000000`
- Current target IDA aliases in instructions: `unk_67AB54`, `unk_67AB58`.
- Current `entity_query` names/globals filter around `67AB5`: zero rows.
- Exact RTTI strings:
  - `0x00678b34`: `.?AVConnectionClosedDialog@@`
  - `0x00678b5c`: `.?AV?$Singleton@VConnectionClosedDialog@@@@`
  - `0x00678b90`: `.?AVReconnectDialog@@`
  - `0x00678bb0`: `.?AV?$Singleton@VReconnectDialog@@@@`
- ConnectionClosedDialog primary COL pointer at `0x00622d30` -> `0x0064e970`; CHD `0x0064e984`; nine-base array `0x0064e994`; Singleton BCD `0x0064e9d8`.
- ReconnectDialog primary COL pointer at `0x00622dd4` -> `0x0064ea50`; CHD `0x0064ea64`; nine-base array `0x0064ea74`; Singleton BCD `0x0064eab8`.
- Both Singleton BCDs: direct/non-virtual PMD `+0x270`, `pdisp=-1`, `vdisp=0`, attributes `0x40`.
- `.data` facts:
  - RVA start `0x0026d000`
  - raw size `0x0d800`
  - virtual size `0x2fe24`
  - raw-mapped end `0x0027a800`
  - virtual end `0x0029ce24`
  - target RVAs `0x0027ab54` and `0x0027ab58`
- Relocation directory: absent (`RVA 0`, size `0`).
- Negative IDA facts:
  - no `-1` value/write/compare;
  - no static initializer target writer;
  - no combined array access;
  - no target string/resource;
  - no ordinary calls to `0x00554550/560`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067ab54-0x0067ab5c` | UID0002VT current path | Two-slot containment map | false | UID00029B containment only | `92/94` | implemented non-emitting container |
| `0x0067ab54-0x0067ab58` | UID0004SQ `by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md` | Exact source-declared/generated-binary storage | true | UID0004SO | `92/94` | implemented/registered |
| `0x0067ab58-0x0067ab5c` | UID0004SR `by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md` | Exact source-declared/generated-binary storage | true | UID0004SP | `92/94` | implemented/registered |
| `g_pConnectionClosedDialog` | UID0004SO `by-global/g_pConnectionClosedDialog.md` | Sole external source definition and lifetime concept | true | UID0000N0 | `91/93` | implemented/registered |
| `g_pReconnectDialog` | UID0004SP `by-global/g_pReconnectDialog.md` | Sole external source definition and lifetime concept | true | UID0000N0 | `91/93` | implemented/registered |
| `0x00553c10-0x00553cbf` | UID00023O | ConnectionClosed constructor variant | true | UID000036 | preserve score/formal; support link update only |
| `0x00553cc0-0x00553e5b` | UID00038J | ConnectionClosed constructor/handlers | true | UID000036 | `88/92` | implemented evidence/score refresh |
| `0x00553f40-0x005544b8` | UID00038L | Reconnect constructors/handlers | true | UID0000BR | `88/92` | implemented evidence/score refresh |
| `0x00554550-0x00554635` | UID00038K | Singleton EH destructors, adjustors, scalar wrappers | false | UID0000N0 documentation grouping | `90/94` | implemented compiler no-code reclassification |
| `0x00553c10-0x00554635` | UID0001FT | Mixed executable neighborhood map | false | none | `90/93` | implemented non-emitting index refresh |
| `0x00466ca0-0x004670ad` | UID0000YT | Heartbeat/timer-skew helper and consumer gate | true | UID0000HG | unchanged `88/91` | implemented bounded prose/link sync |

## Direct Xref / Caller Inventory

### Slot `0x0067ab54`

| Address | Function | Meaning |
| --- | --- | --- |
| `0x00466f2f` | `0x00466ca0` heartbeat helper | Read/compare null; send is blocked if connection-closed dialog exists. |
| `0x00553c77` | `0x00553c10` constructor | Publish complete ConnectionClosedDialog from Singleton base adjustment. |
| `0x00553c7e` | `0x00553c10` constructor | Compiler adjusted-null fallback clear. |
| `0x00553d24` | `0x00553cc0` constructor | Publish complete ConnectionClosedDialog. |
| `0x00553d2b` | `0x00553cc0` constructor | Compiler adjusted-null fallback clear. |
| `0x0055438a` | `0x00554210` replacement construction | Publish replacement ConnectionClosedDialog. |
| `0x00554391` | `0x00554210` replacement construction | Compiler adjusted-null fallback clear. |
| `0x0055446f` | `0x00554410` timeout handler | Read/delete existing ConnectionClosedDialog before replacement. |
| `0x00554550` | Singleton base destructor support | EH-only zero store. |
| `0x005545a6` | scalar deleting wrapper | Inlined Singleton base clear during wrapper lowering. |

### Slot `0x0067ab58`

| Address | Function | Meaning |
| --- | --- | --- |
| `0x00466f22` | `0x00466ca0` heartbeat helper | Read/compare null; send is blocked if reconnect dialog exists. |
| `0x00553da7` | `0x00553d80` reconnect click handler | Read/delete existing ReconnectDialog before replacement. |
| `0x00553e08` | `0x00553d80` reconnect click handler | Publish new ReconnectDialog. |
| `0x00553e0f` | `0x00553d80` reconnect click handler | Compiler adjusted-null fallback clear. |
| `0x00553fa4` | `0x00553f40` constructor | Publish complete ReconnectDialog. |
| `0x00553fab` | `0x00553f40` constructor | Compiler adjusted-null fallback clear. |
| `0x00554051` | `0x00553ff0` constructor | Publish complete ReconnectDialog. |
| `0x00554058` | `0x00553ff0` constructor | Compiler adjusted-null fallback clear. |
| `0x00554560` | Singleton base destructor support | EH-only zero store. |
| `0x005545f6` | scalar deleting wrapper | Inlined Singleton base clear during wrapper lowering. |

## Documentation Evidence And IDA Status

- Historical pre-callback documentation state:
  - UID0002VT and UID00029B were stale about `0xffffffff`; live MCP and PE mapping proved loader-zero storage.
  - UID0002VU already recorded zero bytes and a compiler/local-static no-standalone-definition disposition but had `Nested:0`.
  - UID000036/UID0000BR omitted direct Singleton RTTI/PMD/EBO evidence and typed by-global routes.
  - UID00038J/UID00038L phrased publication as direct global behavior without distinguishing compiler-inlined Singleton base construction.
  - UID00038K called the two EH-only template destructor instantiations clear helpers and remained reconstructable/empty-emitting.
  - UID0001FT's Item Summary used stale below-gate/clear-helper wording.
  - UID0000N0 lacked dedicated by-global pages and pointed both names to one combined by-memory page.
- Current ordinary documentation state:
  - UID0002VT/UID00029B record zero-fill and the exact container/two-child split.
  - UID0002VU has only the accepted `Nested:-4` exit and predecessor synchronization; its score, route, formal, range, and timing facts are unchanged.
  - UID000036/UID0000BR record direct Singleton inheritance, RTTI/PMD/EBO, typed globals, and preserved blank complete-class formals.
  - UID00038J/UID00038L record compiler-inlined Singleton publication and retain all methods/behavior.
  - UID00038K is `90/94`, false/non-emitting, with exact EH-only/compiler-wrapper no-code proof.
  - UID0001FT is `90/93`, false/non-emitting, with exact child/source/compiler inventory and preserved CopyWindow facts.
  - UID0000N0 is `89/91` and routes UID0004SO/UID0004SP plus UID0004SQ/UID0004SR through `network/ReconnectDialog.cpp`.
  - UID0000YT preserves `88/91` and records the typed consumer-only null gate.
  - UID0001P8 ordinary page remains byte-for-byte unchanged at SHA `3046522FDEC7CACB8BDB8E2F53CCF8DBCE9090376871D5FB4144ED8CBA46EDCE`, 8,088 bytes/73 lines; its manual coverage row remains supervisor-owned stale state.
- Historical read-only external generated checkpoint 14094:
  - one UID0002VT Empty Emitter Marker;
  - zero target pointer definitions;
  - zero target covered-storage comments;
  - independent UID000036/UID00023O/UID0000BR markers.
- Current generated semantics, confirmed by B003 waited command 14152 and unchanged at latest observed external header command 14173:
  - one `ConnectionClosedDialog *g_pConnectionClosedDialog = NULL;`;
  - one `ReconnectDialog *g_pReconnectDialog = NULL;`;
  - one exact storage comment per dword;
  - zero UID0002VT marker;
  - zero UID00038K marker;
  - no duplicate source definition;
  - no raw address literal in emitted C++/formal content and no vtable, RTTI, scalar-flag, EH, or template-specialization body;
  - independent UID000036/UID00023O/UID00038J/UID0000BR/UID00038L markers remain accurately classified as separate declaration debt.

## Ranked Ownership Analysis

### 1. Separate by-global concepts under UID0000N0

- Evidence for:
  - exact types and names;
  - external cross-module heartbeat consumer;
  - independent lifecycles;
  - current source-file grouping;
  - by-global guidance;
  - accepted project singleton definition/storage pattern.
- Evidence against:
  - exact original lexical names and static-template-member spelling are stripped.
- Decision: selected. This is the narrowest source-quality semantic ownership model.

### 2. Direct class static-member ownership

- Evidence for:
  - direct `Singleton<T>` bases imply per-specialization backing storage.
  - original template may have represented the storage as a static member.
- Evidence against:
  - no source/PDB symbol proves member spelling or an explicit specialization;
  - project reconstruction convention exposes typed `g_p...` singleton definitions;
  - heartbeat cross-module consumption is naturally modeled as extern globals;
  - attaching physical storage directly to class pages would force incomplete class formals or unproved static member syntax.
- Decision: rejected as the final documentation route; retained as a lexical/source-template caveat.

### 3. One combined UID0000N0 file-owned two-slot declaration

- Evidence for:
  - both definitions belong in one source file.
- Evidence against:
  - file ownership is emitter placement, not narrow semantic ownership;
  - distinct types and lifecycles require separate global concepts;
  - combined page cannot express one canonical direct owner.
- Decision: rejected; UID0002VT remains a container only.

### 4. Application ownership

- Evidence for:
  - heartbeat reads both pointers.
- Evidence against:
  - no Application write;
  - all construction/destruction writers are in the dialog family;
  - consumer reads do not establish ownership.
- Decision: rejected.

### 5. No-owner/non-emitting pair

- Evidence for:
  - exact original symbol spelling is stripped.
- Evidence against:
  - type, lifecycle, source file, linkage, and stable source-facing names are strong enough for implementation.
- Decision: rejected as overly conservative.

### Proposed new file/grouping, if applicable

- No new source `.cpp` file is recommended.
- New documentation grouping:
  - `by-global/g_pConnectionClosedDialog.md`
  - `by-global/g_pReconnectDialog.md`
- Both emit through existing `NexusTK/network/ReconnectDialog.cpp`.
- Related items that belong:
  - each exact one-dword child;
  - respective class/constructor/destructor lifecycle links;
  - heartbeat consumer.
- Rejected contents:
  - Application timing globals;
  - CopyWindow;
  - raw vtables/RTTI;
  - compiler destructor support bodies;
  - a generic Singleton registry.

## Source Placement

- Recommended source file: `NexusTK/network/ReconnectDialog.cpp`.
- Recommended header/declaration context: the existing ReconnectDialog/ConnectionClosedDialog source family, with external declarations available to Application code.
- Why:
  - constructors, replacement handlers, reconnect initiation, timeout, and teardown all cluster in the same source family;
  - both class pages already route to UID0000N0;
  - heartbeat is a consumer only;
  - network session recovery is stronger than generic UI or Application placement.
- Rejected placements:
  - `Application.cpp`: read-only consumer.
  - `AlertPanes.cpp`: generic base/UI behavior does not own lifecycle.
  - `Singleton.cpp`: no evidence for a centralized registry/definition TU.
  - `login/ReconnectDialog.cpp`: plausible historical folder, weaker than current packet/session route.
  - separate source file for globals: two dwords do not justify a standalone module.
- Remaining uncertainty:
  - original header filename and exact extern location;
  - exact original token `NULL`, `0`, or omitted initializer;
  - internal Singleton static-member spelling.
- Impact: none of those lexical uncertainties blocks the recommended source-quality first draft.

## Range / Split / Padding / Reclassification Analysis

- Exact parent range: UID00029B `[0x0067ab54,0x0067ab84)`.
- Exact target container: UID0002VT `[0x0067ab54,0x0067ab5c)`.
- Exact child 1: `[0x0067ab54,0x0067ab58)`.
- Exact child 2: `[0x0067ab58,0x0067ab5c)`.
- No internal padding exists in UID0002VT.
- Predecessor:
  - UID0001P8 `[0x0067ab50,0x0067ab54)`.
  - Separate MiscWorkThread singleton.
  - Current ordinary page reads zero.
- Successor:
  - UID0002VU starts exactly at `0x0067ab5c`.
  - Separate Application function-local static/guard state.
  - Current ordinary page reads zero.
- Parent effect:
  - UID00029B stays a non-emitting mixed aggregate and keeps `Nested:0`.
  - Update its stale all-ones statement and child table.
- Target effect:
  - UID0002VT keeps `Nested:4`; cumulative level becomes one child under UID00029B.
- New child deltas:
  - first child `Nested:4`, entering one level below UID0002VT;
  - second child `Nested:0`, remaining at the same level.
- Successor correction:
  - UID0002VU changes `Nested:0 -> -4` to exit the UID0002VT child level and return to UID00029B's child level.
- Following rows:
  - cumulative nesting after UID0002VU remains exactly what it was before the split.
- Reclassification:
  - UID0002VT true -> false.
  - UID00038K true -> false.
  - new exact storage children true with comment-only formal C++.
- Padding dispositions:
  - predecessor/successor boundaries remain exact;
  - no new ignored padding is created;
  - the existing executable padding around method/cleanup children is preserved unchanged.

## Negative Evidence Summary

- No file-backed target initializer.
- No relocation entry or relocation directory.
- No `0xffffffff` live bytes.
- No `-1` writer or comparison.
- No startup/CRT static initializer target mutation.
- No target global/name symbol in the current IDB.
- No array indexing or shared-struct access across both dwords.
- No cross-write from one class family to the other slot.
- No Application write.
- No ordinary caller to either tiny clear body.
- No evidence that clear bodies are public/private source helpers.
- No evidence for explicit template specialization spelling.
- No evidence for file-local static linkage.
- No evidence for a separate source module.
- No reason to emit vptr stores, RTTI arrays, base destructor calls, scalar flags, delete logic, EH tables, or raw addresses.
- No prior B report resolves this target.

## IDA Rename / Type / Comment Recommendations

- No IDA mutation was performed or requested; both the evidence pass and callback remained read-only with respect to IDA.
- Future safe source-facing names if an authorized IDA pass occurs:
  - `g_pConnectionClosedDialog` at `0x0067ab54`
  - `g_pReconnectDialog` at `0x0067ab58`
- Future safe types:
  - `ConnectionClosedDialog *`
  - `ReconnectDialog *`
- Future safe function comments:
  - `0x00554550`: compiler-instantiated `Singleton<ConnectionClosedDialog>` base destructor support, EH-only.
  - `0x00554560`: compiler-instantiated `Singleton<ReconnectDialog>` base destructor support, EH-only.
- Function renames are not requested because IDA mutation is prohibited and exact decorated/template spellings are not needed for this documentation callback.
- Intentionally unchanged:
  - constructor/handler names;
  - class prototypes;
  - raw decompiler types;
  - vtable/RTTI symbols.

## First-Draft C++ Recommendation

### R0 - UID0002VT retained container

Eligible for draft C++: no. The retained range is an index/container after exact child split.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof:

- The container is not one source declaration.
- Its two exact children and two by-global pages carry all source semantics.
- Any definition on UID0002VT would duplicate or collapse the child-owned source.

### R1 - UID0004SO `by-global/g_pConnectionClosedDialog.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ConnectionClosedDialog;

ConnectionClosedDialog *g_pConnectionClosedDialog = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R2 - UID0004SP `by-global/g_pReconnectDialog.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ReconnectDialog;

ReconnectDialog *g_pReconnectDialog = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R3 - UID0004SQ exact storage child

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact storage for g_pConnectionClosedDialog is represented by [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md); this range is source-declared/generated-binary storage evidence.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R4 - UID0004SR exact storage child

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact storage for g_pReconnectDialog is represented by [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md); this range is source-declared/generated-binary storage evidence.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason the definitions preserve behavior:
  - each is a zero-initialized pointer;
  - direct Singleton base construction/destruction supplies runtime publication/clear;
  - external consumers see the same process-wide storage.
- Reason the source shape is plausible:
  - VC-era forward declaration;
  - ordinary external pointer definition;
  - `NULL` initializer;
  - no decompiler labels or raw addresses;
  - one definition per source concept.
- Inferred source-facing names/types:
  - exact class types are original-proof;
  - `g_p...` names are project-canonical inference.
- Naming convention:
  - matches current NexusTK global pointer pages and UI singleton source.
- Code intentionally excluded:
  - direct assignments in constructors/destructors;
  - explicit Singleton template specializations;
  - class shells;
  - cleanup helpers;
  - raw storage arrays;
  - vtable/RTTI data.

## Final Recommendation

- UID0002VT is implemented at `92/94`, owner `NONE`, reconstructable false, blank emitter/position/formal, `Nested:4`.
- UID0004SO and UID0004SP are registered source-emitting by-global pages under UID0000N0.
- UID0004SQ and UID0004SR are registered exact storage children under the corresponding by-global pages.
- R0-R4 are installed exactly with real validator-issued UIDs.
- UID0002VU is current `Nested:-4`; score/owner/emitter/formal/range/timing facts are unchanged.
- UID00029B records current zero-byte/split wording and preserves its score, ownerless false state, blank formal, and all unrelated children.
- UID0000N0 is current `89/91` with resolved singleton definitions, source linkage, split, and compiler/source lifecycle.
- UID000036 and UID0000BR are current `88/92`; their owner/emitter and blank class formals are preserved with direct Singleton/PMD/EBO/type/global evidence added.
- UID00038J and UID00038L are current `88/92`; formal blocks and method facts are preserved while publication source cause is corrected.
- UID00038K is current `90/94`, false, blank emitter/position/formal, with owner UID0000N0 retained only as documentation grouping.
- UID0001FT is current `90/93`, owner none/false/blank formal, with stale below-gate/helper terminology corrected.
- UID0000YT remains `88/91` with its formal unchanged and typed global links/consumer-only gate wording applied.
- UID0001P8 ordinary page remains unchanged; its stale manual coverage row is retained only in the exact supervisor-owned handoff.
- No future B003 research item is required for UID0002VT after callback. Broad class/method body completion remains independent work and must not be represented as a target blocker.

## Recommended Target Doc Changes

### UID0002VT

- Target path: `by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md`.
- Implemented metadata:
  - `92/94`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - blank emitters/position/formal
  - `Nested:4`
- Exact Item Summary:

```text
Non-emitting exact two-slot container for zero-filled ConnectionClosedDialog and ReconnectDialog Singleton backing pointers, with complete 20-xref lifecycle/consumer evidence, source definitions routed through separate by-global pages, and exact one-dword storage children nested below this range.
```

- Incorporated:
  - exact zero bytes/hash;
  - PE virtual-only `.data` proof;
  - all 20 xrefs;
  - two RTTI types and Singleton BCDs;
  - source/compiler lifecycle split;
  - split/nesting/owner/emitter decision;
  - source-facing names/types;
  - one-definition policy;
  - predecessor/successor.
- Preserved:
  - exact range;
  - historical 2026-06-07 all-ones assumption as explicitly superseded history;
  - current source-family links.
- Rejected:
  - combined source definition;
  - direct file owner as narrow owner;
  - explicit assignments/specializations/raw arrays.

### UID0004SQ

- Path: `by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md`.
- Implemented metadata:
  - `92/94`
  - owner/emitter UID0004SO
  - reconstructable true
  - blank position
  - `Nested:4`
  - R3 exact.
- Exact Item Summary:

```text
Exact loader-zero-filled four-byte ConnectionClosedDialog singleton storage with ten heartbeat/publication/replacement/unwind/scalar refs, direct Singleton<ConnectionClosedDialog> PMD +0x270 source cause, external one-definition route, and covered-storage formal marker.
```

### UID0004SR

- Path: `by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md`.
- Implemented metadata:
  - `92/94`
  - owner/emitter UID0004SP
  - reconstructable true
  - blank position
  - `Nested:0`
  - R4 exact.
- Exact Item Summary:

```text
Exact loader-zero-filled four-byte ReconnectDialog singleton storage with ten heartbeat/replacement/publication/unwind/scalar refs, direct Singleton<ReconnectDialog> PMD +0x270 source cause, external one-definition route, and covered-storage formal marker.
```

## Recommended Support Doc Changes

### UID0004SO `by-global/g_pConnectionClosedDialog.md`

- Registered first as required.
- Current metadata: `91/93`, owner/emitter UID0000N0, reconstructable true, position `10`.
- R1 is installed exactly.
- Documented:
  - exact storage child;
  - ten refs;
  - external linkage;
  - direct Singleton source cause;
  - no explicit lifecycle source;
  - inferred name/token cap;
  - one-definition policy.

### UID0004SP `by-global/g_pReconnectDialog.md`

- Registered second as required.
- Current metadata: `91/93`, owner/emitter UID0000N0, reconstructable true, position `20`.
- R2 and the parallel slot-specific facts are installed exactly.

### UID00029B

- Preserve `90/92`, owner none, false, blank formal, `Nested:0`, all unrelated child facts.
- Twelve-all-ones present-tense evidence is replaced with current zero-window evidence.
- The single UID0002VT source child statement is replaced with retained container plus two exact children.
- Preserve all Application counters, BackGroundPane, TimerMgr, and range facts.

### UID0002VU

- Changed only `Nested:0 -> -4`.
- Preserve `88/91`, owner/emitter UID0000HG, true, blank position, formal marker, range, timing/guard behavior.
- Predecessor wording now names UID0004SR exact child.

### UID0000N0

- Current score is `89/91`.
- Preserve `NexusTK/network/`, both classes, methods, CopyWindow exclusion, packet/resource history, and unrelated content.
- Both by-global pages and exact storage children are added.
- External definitions and Application consumer linkage are recorded.
- Cleanup helper language is corrected to Singleton base destructor/compiler-wrapper language.
- Do not add class or method bodies beyond R1-R4 routing.

### UID000036

- Current score is `88/92`.
- Preserve owner/emitter UID0000N0 and blank formal.
- Added:
  - direct `AlertPane, Singleton<ConnectionClosedDialog>` source inheritance;
  - exact nine-entry RTTI family;
  - Singleton PMD `+0x270`;
  - `0x270` allocation/EBO endpoint;
  - global type/link;
  - implicit publication/cleanup;
  - class formal remains blank because complete class method signatures are broader independent debt and an incomplete shell is prohibited.

### UID0000BR

- Current score is `88/92`.
- Preserve owner/emitter UID0000N0 and blank formal.
- Added:
  - direct `AlertPane, Singleton<ReconnectDialog>` inheritance;
  - PMD `+0x270`;
  - `0x274` allocation;
  - EBO overlap with the byte at `+0x270`;
  - global type/link and implicit lifecycle;
  - same complete-class no-incomplete-shell proof.

### UID00038J

- Current score is `88/92`.
- Preserve owner/emitter UID000036, true, blank formal, exact range/functions.
- Publication pairs are recast as direct Singleton base construction.
- Exact global/storage pages are linked.
- Preserve unresolved tiny slot/method naming and all handler behavior.

### UID00038L

- Current score is `88/92`.
- Preserve owner/emitter UID0000BR, true, blank formal, exact method behavior.
- Publication pairs are recast as Singleton lowering.
- Preserve parser/member-name blockers and all packet/timer behavior.

### UID00038K

- Current score is `90/94`.
- Keep canonical owner UID0000N0 for source-family documentation grouping.
- Reconstructable is false.
- Emitters and position are blank.
- Formal remains exactly blank.
- Roles now read:
  - two EH-only Singleton base destructor instantiations;
  - four compiler adjustors;
  - two scalar deleting wrappers.
- Preserve exact bytes, ranges, vtable refs, delete sizes, following padding, and misleading Boost-name history.

### UID0001FT

- Current score is `90/93`.
- Preserve owner none, false, blank emitters/formal, range, CopyWindow island, and all children.
- Item Summary wording is corrected from below-gate/reconstructable/clear-helper statements to the current non-emitting exact-child index and Singleton/compiler terminology.

### UID0000YT

- Preserve `88/91`, owner/emitter/formal/range.
- Exact typed links and condition are present:
  - `g_pReconnectDialog == NULL`
  - `g_pConnectionClosedDialog == NULL`
- Preserve consumer-only ownership and all packet/timing behavior.

### UID0001P8

- Verify-only ordinary page remained unchanged.
- Manual coverage row remains stale relative to current `87/91` zero-filled/no-duplicate ordinary state and is addressed only in the supervisor-owned handoff.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Implemented | Metadata summary |
| --- | --- | --- | --- |
| UID0002VT | `88/90` | `92/94` | owner NONE, false, blank emitter/formal, Nested 4 |
| UID0004SO | absent | `91/93` | owner/emitter UID0000N0, true, position 10 |
| UID0004SP | absent | `91/93` | owner/emitter UID0000N0, true, position 20 |
| UID0004SQ | absent | `92/94` | owner/emitter UID0004SO, true, Nested 4 |
| UID0004SR | absent | `92/94` | owner/emitter UID0004SP, true, Nested 0 |
| UID0002VU | `88/91`, Nested 0 | `88/91`, Nested -4 | nesting/link only |
| UID00029B | `90/92` | `90/92` | wording/child inventory only |
| UID0000N0 | `87/88` | `89/91` | route unchanged |
| UID000036 | `86/88` | `88/92` | route/formal unchanged |
| UID0000BR | `86/88` | `88/92` | route/formal unchanged |
| UID00038J | `86/89` | `88/92` | route/formal unchanged |
| UID00038L | `86/89` | `88/92` | route/formal unchanged |
| UID00038K | `85/89` | `90/94` | false, blank emitter/formal |
| UID0001FT | `88/90` | `90/93` | false/owner none unchanged |
| UID0000YT | `88/91` | `88/91` | prose/link sync only |

Score-improvement attempt:

- Initializer blocker removed by live bytes and PE virtual-tail proof.
- Relocation blocker removed by absent relocation directory.
- Type blocker removed by class RTTI/vtables/allocations.
- Source-cause blocker removed by direct Singleton BCD/constructor/EH evidence.
- Helper blocker removed by exact EH-only xrefs.
- Owner blocker removed by separate by-global pages.
- Emitter blocker removed by one-definition/covered-storage route.
- Split blocker removed by exact dword boundaries.
- Linkage blocker removed by Application cross-module consumer.
- Source-file blocker resolved to current network route.
- Name blocker reduced to lexical confidence only.
- Initializer-token blocker reduced to lexical confidence only.
- Scores remain below 95 because original symbol/header/template-static spelling and exact `NULL` versus `0` token are not original-proof.

## Open Questions With Attempted Resolution

### Was `0xffffffff` a real source sentinel?

- Checked: live bytes, values, PE section backing, relocations, every xref, constructor/consumer order.
- Resolution: no. It is stale documentation/analysis state.

### Were the pointers file-scope globals or template static members?

- Checked: RTTI, compiler-lowered constructors/destructors, project comparators, cross-TU consumer, current source map.
- Resolution: binary proves per-specialization static storage but not lexical source spelling. The implementation-ready project model is two external named pointer definitions plus direct Singleton class inheritance. Do not add an explicit template specialization.

### Should the target remain one page?

- Checked: types, lifecycles, xrefs, ownership rules, nesting.
- Resolution: retain as container only; split exact children.

### Are dedicated by-global pages required?

- Checked: by-global guidance, current absence, accepted project patterns.
- Resolution: yes.

### Is `network/ReconnectDialog.cpp` certain?

- Checked: current file page, packet/session behavior, class grouping, historical `login/` alternative.
- Resolution: strongest available placement and implementation-ready; exact original folder remains a confidence cap.

### Are `g_pConnectionClosedDialog` and `g_pReconnectDialog` exact original names?

- Checked: IDA names, strings, current docs, naming convention, alternatives.
- Resolution: inferred/project-canonical, not original-proof; no better source-facing names exist.

### Is `NULL` exact?

- Checked: binary zero, project era/style, comparator pages.
- Resolution: behaviorally exact and source-plausible. Exact original token remains unavailable.

### Must class formals be completed now?

- Checked: target source requirements, current method/signature debt, one-definition route.
- Resolution: no. The target definitions and storage can be represented without an incomplete class shell. Class pages should gain inheritance/global evidence but retain blank formal C++ until their complete method declarations are independently ready.

### Are any questions still blocking target implementation?

- Resolution: no. Remaining lexical uncertainties cap scores but do not block R0-R4 or the split/owner/emitter route.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current read-only callback snapshots:

- `by-memory/-coverage-report.md`
  - SHA256 `8448E762CF0639F2873DC2861F10A8D57C42A900A1AA690F5E0C13D906F07114`
  - `1,774,499` bytes
  - `4,253` lines
- `by-class/-coverage-report.md`
  - SHA256 `9710D23ADFD1CAF806CAE8DEDE327C69420C38BEF0CDCAD1C181621A9B9B6BFA`
  - `229,370` bytes
  - `622` lines
- `by-file/-coverage-report.md`
  - SHA256 `0EBB76739F9FBC1AB22D9C04D1E4A070118F9079808E99B6EDFF477FE990D82E`
  - `131,915` bytes
  - `316` lines
- `by-global/-coverage-report.md`
  - SHA256 `61D81E3B76C64C37FDE94942FEC3399940E7793C493EE09E1FB0D28C02EDAE09`
  - `89,137` bytes
  - `210` lines
- No by-struct row is affected.
- The four manual snapshots and exact anchors were reread twice more than three seconds apart during final callback reconciliation and were stable across both reads; unrelated generated-header refreshes did not alter any manual row or hash.
- Current exact anchors are UID0000YT line 542, UID0001FT line 2868, UID0001P8/UID00029B/UID0002VT/UID0002VU lines 4078-4081, UID000036 line 139, UID0000BR line 445, and UID0000N0 line 225.
- Current by-global insertion anchors are `g_pCollectionDialogPane`/`g_pCrasher` lines 74/75 and `g_pRankingRewardInfoDialog`/`g_pRidingImageLib` lines 134/135; UID0004SO and UID0004SP have no current manual rows.
- The exact text below is supervisor-owned. B003 must not apply it directly.
- All rows below use the real validator-issued UIDs UID0004SO, UID0004SP, UID0004SQ, and UID0004SR.

### by-memory replacement/insertion text

Placement 1: replace current UID0000YT row at line 542.

```text
    - [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) 0x00466ca0-0x004670ad | function | CheckTimerSkewAndSendHeartbeat : reconstructable : 88% : very-strong : Application timer-skew/heartbeat helper with exact 0x40d range, sole message-loop caller, function-local static guards, diagnostic and opcode-0x60 packet paths, and a typed consumer-only gate requiring both g_pReconnectDialog and g_pConnectionClosedDialog to be null; the dialog globals remain ReconnectDialog-owned.
```

Placement 2: replace UID0001FT row at line 2868; insert missing exact children in address order under it while preserving every existing padding/CopyWindow row.

```text
    - [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) 0x00553c10-0x00554635 | class method cluster index | ConnectionClosedReconnectDialogs : ignored : 90% : very-strong : Non-emitting mixed executable index for ConnectionClosedDialog/ReconnectDialog source children plus the interleaved CopyWindow island; current evidence resolves direct Singleton publication, EH-only base destructors, scalar wrappers, exact globals, compiler/source distinctions, and child ownership without treating the aggregate as one source body.
```

Insert after the existing `0x00553cbf-0x00553cc0` padding row:

```text
        - [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) 0x00553cc0-0x00553e5b | class method cluster | ConnectionClosedDialogMethods : reconstructable : 88% : very-strong : Parent-taking constructor plus tiny virtual slot and reconnect/leave handlers, with exact function bounds, callers/vtable refs, resource text, replacement ReconnectDialog flow, and compiler-inlined Singleton<ConnectionClosedDialog> publication to exact storage UID0004SQ.
```

Replace the existing UID0001FU row:

```text
    - [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) 0x00553e60-0x00553f36 | method | ConnectionClosedDialogInitHelper : reconstructable : 89% : very-strong : Formal-ready inferred ConnectionClosedDialog::InitializeConnectionState helper with exact 0xd6 range, three callers, conditional CopyWindow construction, packet-sender mode byte 1, queue drain, optional ScreenDimmer action, and stale debug-symbol rejection.
```

Insert after existing `0x00553f36-0x00553f40` padding:

```text
        - [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) 0x00553f40-0x005544b8 | class method cluster | ReconnectDialogMethods : reconstructable : 88% : very-strong : Two constructors, reconnect initiation, parser/state helper, button handler, and timeout handler with exact bounds, packet/timer behavior, replacement ConnectionClosedDialog flow, and compiler-inlined Singleton<ReconnectDialog> publication to exact storage UID0004SR.
```

Insert after the existing CopyWindow child/padding rows and before the `0x00554635-0x00554640` padding row:

```text
        - [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md) 0x00554550-0x00554635 | compiler destructor support | ConnectionReconnectDialogCleanupAndDestructorThunks : ignored : 90% : very-strong : Exact two EH-only Singleton base destructor instantiations, four vtable adjustors, and two scalar deleting wrappers for ConnectionClosedDialog/ReconnectDialog; all zero stores, PMD +0x270 adjustments, vtable refs, delete sizes, padding, and no-code proof are documented, with no handwritten clear helper or wrapper source emitted.
```

Placement 3: replace the current block beginning with UID0001P8 at line 4078 through UID0002VU at line 4081. Preserve later UID0002VX/UID0002VV/UID0002VW rows unchanged.

```text
    - [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md) 0x0067ab50-0x0067ab54 | global pointer | g_pMiscWorkThread : reconstructable : 87% : very-strong : Exact loader-zero-filled four-byte MiscWorkThread singleton slot with eight constructor/destructor/consumer refs, source definition owned by UID0000RQ, and a no-duplicate covered-storage formal marker; historical 0xffffffff wording is stale.
    - [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md) 0x0067ab54-0x0067ab84 | global data cluster | ApplicationDialogTimerAndBackgroundGlobals : ignored : 90% : very-strong : Non-emitting mixed .data index with current zero-filled bytes and exact child ownership for the two reconnect-dialog Singleton slots, Application heartbeat/timer-skew state, message-loop counters, g_pBackGroundPane, and g_pTimerMgr; no all-ones source initializer remains.
        - [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md) 0x0067ab54-0x0067ab5c | global data container | ConnectionReconnectDialogSingletonGlobals : ignored : 92% : very-strong : Non-emitting exact two-slot container for zero-filled ConnectionClosedDialog and ReconnectDialog Singleton backing pointers, with complete 20-ref evidence, separate by-global source definitions, and exact one-dword storage children.
            - [UID:0004SQ][0x0067ab54-0x0067ab58.g_pConnectionClosedDialog](by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md) 0x0067ab54-0x0067ab58 | global pointer storage | g_pConnectionClosedDialog : reconstructable : 92% : very-strong : Exact loader-zero-filled four-byte ConnectionClosedDialog singleton storage with ten heartbeat/publication/replacement/unwind/scalar refs, direct Singleton<ConnectionClosedDialog> PMD +0x270 source cause, external one-definition route, and covered-storage marker.
            - [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md) 0x0067ab58-0x0067ab5c | global pointer storage | g_pReconnectDialog : reconstructable : 92% : very-strong : Exact loader-zero-filled four-byte ReconnectDialog singleton storage with ten heartbeat/replacement/publication/unwind/scalar refs, direct Singleton<ReconnectDialog> PMD +0x270 source cause, external one-definition route, and covered-storage marker.
        - [UID:0002VU][0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals](by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md) 0x0067ab5c-0x0067ab70 | global data | ApplicationHeartbeatTimerSkewGlobals : reconstructable : 88% : very-strong : Exact zero-filled heartbeat/timer-skew local-static state and MSVC guard storage assigned to Application, with all refs confined to CheckTimerSkewAndSendHeartbeat and a compiler/local-static no-standalone-definition marker.
```

### by-global insertion text

Insert alphabetically after current `g_pCollectionDialogPane` and before `g_pCrasher`:

```text
- [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md) : reconstructable : 91% : very-strong : External ConnectionClosedDialog *g_pConnectionClosedDialog = NULL definition in ReconnectDialog.cpp with exact zero-filled storage UID0004SQ, ten heartbeat/publication/replacement/unwind/scalar refs, direct Singleton<ConnectionClosedDialog> PMD +0x270 source cause, external linkage, one-definition handling, and rejected all-ones/helper/explicit-lifecycle alternatives.
```

Insert alphabetically after current `g_pRankingRewardInfoDialog` and before `g_pRidingImageLib`:

```text
- [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md) : reconstructable : 91% : very-strong : External ReconnectDialog *g_pReconnectDialog = NULL definition in ReconnectDialog.cpp with exact zero-filled storage UID0004SR, ten heartbeat/replacement/publication/unwind/scalar refs, direct Singleton<ReconnectDialog> PMD +0x270 source cause, external linkage, one-definition handling, and rejected all-ones/helper/explicit-lifecycle alternatives.
```

### by-class replacement text

Replace UID000036 at current line 139:

```text
- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) : reconstructable : 88% : very-strong : Connection-loss alert class in ReconnectDialog.cpp with constructor/reconnect/leave/init-helper children, exact AlertPane plus Singleton<ConnectionClosedDialog> direct inheritance, nine-entry RTTI, PMD +0x270 EBO at the 0x270 allocation endpoint, typed g_pConnectionClosedDialog route, implicit publication/cleanup, CopyWindow side-path exclusion, and preserved complete-class formal blocker.
```

Replace UID0000BR at current line 445:

```text
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) : reconstructable : 88% : very-strong : Active reconnect alert class in ReconnectDialog.cpp with constructor/initiate/parser/button/timeout children, exact AlertPane plus Singleton<ReconnectDialog> direct inheritance, nine-entry RTTI, PMD +0x270 EBO overlapping the derived byte in the 0x274 allocation, typed g_pReconnectDialog route, implicit publication/cleanup, and preserved complete-class formal blocker.
```

### by-file replacement text

Replace UID0000N0 at current line 225:

```text
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) : reconstructable : 89% : very-strong : NexusTK/network/ReconnectDialog.cpp source root for ConnectionClosedDialog and ReconnectDialog, exact constructor/method/init-helper children, separate external g_pConnectionClosedDialog and g_pReconnectDialog definitions plus exact storage routes, direct Singleton source/compiler lifecycle, mixed aggregate and CopyWindow exclusions, packet/reconnect behavior, and preserved broader class/method declaration debt.
```

Reason B003 must not apply this text directly:

- Manual coverage is supervisor-owned.
- Callback scope explicitly prohibits coverage edits.
- All four new UIDs are now validator-issued and present in the exact rows above.
- Concurrent unrelated coverage additions must be preserved by the supervisor's no-loss application.

## Follow-Up Actions

- Current callback state:
  - all accepted ordinary implementation items are complete;
  - all changed/new ordinary pages passed scoped validation;
  - B003 waited generated command `000000014152` passed the accepted UID0002VT assertions, and latest observed external header command `000000014173` preserves the same body/counts;
  - all real UIDs are present in ordinary pages, formal blocks, ledger proof, and manual handoff;
  - no B003 implementation item remains blocked or unapplied.
- External supervisor/validator-owned state:
  - exact report validation/execution/count/path/move/archive state is not asserted or directed by this artifact;
  - the exact manual coverage text remains available for no-loss supervisor-owned application;
  - independent UID000036/UID00023O/UID00038J/UID0000BR/UID00038L declaration-marker debt remains outside this target's implementation claim.
- A-agent actions: none required by this report.
- Durable lifecycle boundary:
  - this artifact neither asserts nor directs report execution, move, archive, count, or final path state;
  - B003 does not run those commands.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong to very strong.
- Original-proof:
  - range;
  - bytes;
  - section/storage;
  - no relocation;
  - xrefs;
  - RTTI types;
  - Singleton PMDs;
  - constructor/EH/scalar source cause;
  - external consumer;
  - split.
- Inferred:
  - exact `g_p...` lexical names;
  - `NULL` token;
  - exact header declaration location;
  - exact original folder between network/login.
- Remaining uncertainty is lexical/source-tree detail only and does not block the first-draft definitions or no-code dispositions.

## Validator Results

- Validator working directory: canonical `source-3/project-documentation`.
- Scoped command shape: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`.
- Every command below exited `0`. Where the validator emitted an `ok` field it was `ok:1`; the four initial new-file registration commands completed UID insertion successfully but did not print a separate `ok` field.

| Command ID | Timestamp | Destination / purpose | Result and side effects |
| --- | --- | --- | --- |
| `000000014109` | `2026-07-16T14:00:04-04:00` | register `by-global/g_pConnectionClosedDialog.md` | Issued UID0004SO; generated refresh deferred. Initial missing UID00038J/UID00038K references were resolved by later registrations and final command `14143`. |
| `000000014111` | `2026-07-16T14:00:50-04:00` | register `by-global/g_pReconnectDialog.md` | Issued UID0004SP; generated refresh deferred. Initial missing UID00038L/UID00038K references were resolved by later registrations and final command `14144`. |
| `000000014113` | `2026-07-16T14:01:37-04:00` | register `by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md` | Issued UID0004SQ; generated refresh deferred; validator normalized one link. Initial UID00038J/UID00038K reference warnings were cleared by final command `14148`. |
| `000000014116` | `2026-07-16T14:02:16-04:00` | register `by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md` | Issued UID0004SR; generated refresh deferred; validator normalized one link. Initial UID00038L/UID00038K reference warnings were cleared by final command `14149`. |
| `000000014119` | `2026-07-16T14:03:53-04:00` | UID0002VT target | `ok:1`; applied `92/94`, false/non-emitting container metadata and complete split evidence. |
| `000000014120` | `2026-07-16T14:04:21-04:00` | UID0002VU successor | `ok:1`; applied only `Nested:-4` and exact predecessor wording. |
| `000000014122` | `2026-07-16T14:05:18-04:00` | UID00029B parent | `ok:1`; applied zero-fill/two-child inventory while preserving unrelated children. |
| `000000014125` | `2026-07-16T14:06:10-04:00` | UID0000N0 initial by-file validation | `ok:1`; applied source route/global/compiler lifecycle. Initial current-registry warnings included UID00038J/UID00038L/UID00038K and unrelated UID0003G3/UID0003G4/UID0003G7. |
| `000000014127` | `2026-07-16T14:07:08-04:00` | UID000036 initial class validation | `ok:1`; applied score/inheritance/PMD/EBO/global evidence. Initial UID00038J/UID00038K registry references were resolved later. |
| `000000014129` | `2026-07-16T14:07:51-04:00` | UID0000BR initial class validation | `ok:1`; applied score/inheritance/PMD/EBO/global evidence. Initial UID00038L/UID00038K registry references were resolved later. |
| `000000014132` | `2026-07-16T14:08:49-04:00` | UID00038J | `ok:1`; current UID/path registered and compiler-inlined publication evidence validated. |
| `000000014134` | `2026-07-16T14:09:31-04:00` | UID00038L | `ok:1`; current UID/path registered and compiler-inlined publication evidence validated. |
| `000000014138` | `2026-07-16T14:11:14-04:00` | UID00038K initial validation | `ok:1`; current UID/path registered and compiler-only false/non-emitting disposition validated. |
| `000000014141` | `2026-07-16T14:12:47-04:00` | UID0001FT initial validation | `ok:1`; applied score/index/source/compiler synchronization. |
| `000000014142` | `2026-07-16T14:13:54-04:00` | UID0000YT | `ok:1`; applied typed consumer-only gate links while preserving score/formal/packet/timing behavior. |
| `000000014143` | `2026-07-16T14:14:19-04:00` | UID0004SO final child-link sync | `ok:1`; no missing references. |
| `000000014144` | `2026-07-16T14:14:43-04:00` | UID0004SP final child-link sync | `ok:1`; no missing references. |
| `000000014145` | `2026-07-16T14:15:54-04:00` | UID00038K final historical wording repair | `ok:1`; historical helper/Boost labels retained only as superseded provenance. |
| `000000014146` | `2026-07-16T14:16:29-04:00` | UID0001FT final historical wording repair | `ok:1`; stale below-gate/helper wording historicalized without loss. |
| `000000014148` | `2026-07-16T14:17:01-04:00` | UID0004SQ final reference rescan | `ok:1`; clean after UID00038J/UID00038K registry insertion. |
| `000000014149` | `2026-07-16T14:17:16-04:00` | UID0004SR final reference rescan | `ok:1`; clean after UID00038L/UID00038K registry insertion. |
| `000000014150` | `2026-07-16T14:17:36-04:00` | UID000036 final reference rescan | `ok:1`; clean current references. |
| `000000014151` | `2026-07-16T14:17:51-04:00` | UID0000BR final reference rescan | `ok:1`; clean current references. |
| `000000014152` | `2026-07-16T14:18:33-04:00` | final `by-file/ReconnectDialog.md --wait-generated` | `ok:1`; waited generated refresh completed. Current target-family refs are resolved. Unrelated pre-existing UID0003G3/UID0003G4/UID0003G7 literal-page reference warnings remain outside this callback. Validator-owned metadata/projected-stat/generated-header side effects occurred; B003 made no manual generated/state edit. |

- B003 final waited generated output:
  - path `auto-generated/NexusTK/network/ReconnectDialog.cpp`;
  - command/header `000000014152`;
  - refreshed `2026-07-16T14:18:33-04:00`;
  - SHA256 `52367E6C25257A75BE5CAF65347CE7F34DC70A0012F4B2A1A129B240C2B64274`;
- Latest read-only external generated output:
  - command/header `000000014173`;
  - refreshed `2026-07-16T14:29:37-04:00`;
  - SHA256 `4F84D0ACD76893201D259460FFB2AE4F0FB94451292601E9EABA0494864D75D0`;
  - `2,335` bytes / `49` lines;
  - R1 definition count `1`;
  - R2 definition count `1`;
  - R3 covered-storage comment count `1`;
  - R4 covered-storage comment count `1`;
  - UID0002VT Empty Emitter Marker count `0`;
  - UID00038K Empty Emitter Marker count `0`;
  - explicit template specialization/vtable/RTTI/scalar-delete/EH source count `0`;
  - raw address literals in emitted C++/formal content `0`; the twelve `0x...` strings in the file are validator provenance path comments only;
  - independent Empty Emitter Markers: UID000036 `1`, UID00023O `1`, UID00038J `1`, UID0000BR `1`, UID00038L `1`.
- Destination-specific formal parity after real-UID replacement:
  - R0 vs UID0002VT destination: exact, 221 normalized characters.
  - R1 vs UID0004SO destination: exact, 324 normalized characters.
  - R2 vs UID0004SP destination: exact, 303 normalized characters.
  - R3 vs UID0004SQ destination: exact, 432 normalized characters.
  - R4 vs UID0004SR destination: exact, 411 normalized characters.

## Changed Files

- Created ordinary pages:
  - `by-global/g_pConnectionClosedDialog.md` - UID0004SO - SHA `AB58873E3ECF7E855269F4F776FD3381BE8878CA2717CDEF71090AB0C79EC869` - 7,024 bytes/95 lines.
  - `by-global/g_pReconnectDialog.md` - UID0004SP - SHA `D6E1BF11581754C2081D911145EE22FC87132A311783CB785D3B0C0B623F0446` - 6,952 bytes/95 lines.
  - `by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md` - UID0004SQ - SHA `EC8B01085232CDFBEA08CEE5B194436BA107CDAA11E774474ECF221064A541D8` - 6,948 bytes/87 lines.
  - `by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md` - UID0004SR - SHA `4AE31C3FA070CF84A061DF2E81E78148B44919EB6EBFDEA53561963115A8E350` - 7,018 bytes/89 lines.
- Modified ordinary pages:
  - `by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md` - UID0002VT - SHA `3EE34BC07080D87FE3C519AEAC8A5AC26FA800426CF0CE9EEC9B77AF000E5EC0` - 12,150 bytes/143 lines.
  - `by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md` - UID0002VU - SHA `E3F9911D8FEBC5C8AD3FD255F8C15A06DB872329B60C4E6EC3856B08273D0259` - 6,561 bytes/77 lines.
  - `by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md` - UID00029B - SHA `2DDB930E7D864987DCFE8C47C1EEA487307D047238CA6612ACB0988DF05A4455` - 18,290 bytes/127 lines.
  - `by-file/ReconnectDialog.md` - UID0000N0 - SHA `840113D078756788A03AC16D44616BD625DC152CC94F9DCA57A7C5C416F56E72` - 23,354 bytes/154 lines.
  - `by-class/ConnectionClosedDialog.md` - UID000036 - SHA `2C19351D1938CC665042A57D57FFC64B1782071B3530E89258340FCAD9031ED8` - 17,725 bytes/128 lines.
  - `by-class/ReconnectDialog.md` - UID0000BR - SHA `371D93ED23E1F17B1267D6781459A77F5951922451785341826EA22974A4D36E` - 13,331 bytes/111 lines.
  - `by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md` - UID00038J - SHA `F113DD10F051BE8D9F95910AD3270DC77C9C34D55B54FD09616F6528542FC2F3` - 9,643 bytes/91 lines.
  - `by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md` - UID00038L - SHA `411B103FD8FABE7FE8746B08F05868A360CE06F7BACD34D1E68C999E46B08321` - 10,691 bytes/98 lines.
  - `by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md` - UID00038K - SHA `1148CD739DACA8835AAD44544B850C8599AC4665B7592B0BC3CAEB2F299453AA` - 11,605 bytes/101 lines.
  - `by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md` - UID0001FT - SHA `D08E37B19A80009351F04BD74084600F5A587C5E9F5876A3200B380111685918` - 19,573 bytes/132 lines.
  - `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md` - UID0000YT - SHA `B516067F3B76F22436796D56539B47E6FE7A3F0B23F49257A711842D32418232` - 17,724 bytes/126 lines.
- Verify-only unchanged:
  - `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md` - UID0001P8 - SHA `3046522FDEC7CACB8BDB8E2F53CCF8DBCE9090376871D5FB4144ED8CBA46EDCE` - 8,088 bytes/73 lines.
- Modified report:
  - `tools/leaser/Agents/Agent-B003/research/0002VT-ConnectionReconnectDialogSingletonGlobals-source-quality.md`.
- Renamed ordinary pages: none.
- Manual coverage edits: zero.
- Generated/tracker/audit/supervisor/validator-state manual edits: zero. Validator-owned generated and metadata side effects are recorded above.
- IDA mutations: zero.
- Leases: short ordinary leases were released immediately after their scoped edit/validation. Latest read-only `tools/leaser/Agents/current_leases.md` SHA is `EA2FA43FFE5ADAEE941CD801C5EA2E206A3D9B9D7FFC692F685134199392AAC4`, 166 bytes/8 lines, with zero B003 rows and zero B003 leases.
- Report execution/lifecycle command: none run by B003; exact external lifecycle state is not asserted here.

## Implementation Tracking Checklist

Report and implementation callback completion:

- [x] Exact pre-callback report SHA `EA72D17BD8EACA70C3594AD80A68D338E238A548A2149641F38E82C1B1A0E93B` passed supervisor Gate 1.
- [x] Register UID0004SO `by-global/g_pConnectionClosedDialog.md` and capture the real UID.
- [x] Register UID0004SP `by-global/g_pReconnectDialog.md` and capture the real UID.
- [x] Register UID0004SQ `by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md` after UID0004SO exists.
- [x] Register UID0004SR `by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md` after UID0004SP exists.
- [x] Replace all four pre-callback placeholders with UID0004SO/UID0004SP/UID0004SQ/UID0004SR before dependent validation.
- [x] Apply UID0002VT `92/94`, owner NONE, false, blank emitter/position/formal, `Nested:4`, exact Item Summary, and complete container evidence.
- [x] Apply UID0004SO `91/93`, owner/emitter UID0000N0, true, position 10, R1, and complete source/linkage/lifecycle evidence.
- [x] Apply UID0004SP `91/93`, owner/emitter UID0000N0, true, position 20, R2, and complete source/linkage/lifecycle evidence.
- [x] Apply UID0004SQ `92/94`, owner/emitter UID0004SO, true, blank position, `Nested:4`, R3, exact bytes/xrefs/PE/RTTI evidence.
- [x] Apply UID0004SR `92/94`, owner/emitter UID0004SP, true, blank position, `Nested:0`, R4, exact bytes/xrefs/PE/RTTI evidence.
- [x] Change UID0002VU only from `Nested:0` to `Nested:-4` plus predecessor link; preserve all other metadata/formal/timing facts.
- [x] Update UID00029B current zero bytes, target container/two-child inventory, and stale all-ones history without losing unrelated children.
- [x] Update UID0000N0 to `89/91` with both by-global definitions, exact storage routes, external linkage, Singleton/compiler lifecycle, and preserved unrelated content.
- [x] Update UID000036 to `88/92` with direct Singleton inheritance/PMD/EBO/global evidence while preserving blank complete-class formal and unrelated class facts.
- [x] Update UID0000BR to `88/92` with direct Singleton inheritance/PMD/EBO/global evidence while preserving blank complete-class formal and unrelated class facts.
- [x] Update UID00038J to `88/92` with compiler-inlined publication and exact storage/global links while preserving all methods and blank formal.
- [x] Update UID00038L to `88/92` with compiler-inlined publication and exact storage/global links while preserving all methods and blank formal.
- [x] Reclassify UID00038K to `90/94`, false, blank emitter/position/formal, exact EH-only Singleton destructor/adjustor/scalar-wrapper no-code proof.
- [x] Update UID0001FT to `90/93`, preserve false/owner none/blank formal, and correct stale below-gate/helper/source wording without losing CopyWindow or child facts.
- [x] Update UID0000YT typed gate links/condition and consumer-only wording; preserve `88/91`, formal, and all packet/timing behavior.
- [x] Verify UID0001P8 ordinary page remains unchanged/current and retain its exact supervisor-owned manual row correction without editing coverage.
- [x] Preserve all historical assumptions, rejected alternatives, negative evidence, exact hashes/ranges/xrefs, source/compiler distinctions, and source-placement rationale at report-level detail.
- [x] Apply R0-R4 byte-for-byte after placeholder replacement.
- [x] Keep all class/method formal blocks outside R0-R4 unchanged.
- [x] Run one scoped validator per changed/new ordinary by-* page from canonical project-documentation.
- [x] Release each short ordinary-file lease immediately after its edit/validator.
- [x] Run one final authorized `--wait-generated` ReconnectDialog refresh.
- [x] Verify generated ReconnectDialog.cpp contains R1 and R2 definitions exactly once each.
- [x] Verify generated ReconnectDialog.cpp contains R3 and R4 covered-storage comments exactly once each.
- [x] Verify generated ReconnectDialog.cpp contains zero UID0002VT Empty Emitter Markers.
- [x] Verify generated ReconnectDialog.cpp contains zero UID00038K Empty Emitter Markers.
- [x] Verify no duplicate/wrong-range target definition, raw address, explicit template specialization, handwritten Singleton lifecycle, vtable/RTTI array, scalar flag, delete wrapper, or EH source is emitted.
- [x] Describe independent UID000036/UID00023O/UID00038J/UID0000BR/UID00038L marker state accurately rather than claiming this target solves it.
- [x] Reread current manual coverage files and retain exact supervisor-owned no-loss rows with real UIDs; B003 made no coverage edit.
- [x] Update every C01-C20 ledger row to an allowed terminal callback state with destination and validator/generated proof.
- [x] Update Validator Results, Changed Files, Finalized/Current State, manual handoff, and this checklist to callback-complete archive-neutral truth.
- [x] Confirm all B003 leases are released and zero remain.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger terminalized C01-C20 with exact proof.
- [x] Metadata/score/owner/emitter/split/new-page/nesting/C++ changes applied or excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or retained only as evidence-backed lexical confidence caps.
- [x] Scoped validators run and exact command metadata recorded.
- [x] Final waited generated assertions pass.
- [x] Exact manual supervisor-owned coverage text remains current and supervisor-owned.
- [x] Confirm no accepted implementation item remains unapplied or blocked.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000014200","destination_path":"executed-b-agent-research/B003/0002VT-ConnectionReconnectDialogSingletonGlobals-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002VT-ConnectionReconnectDialogSingletonGlobals-source-quality.md","timestamp":"2026-07-16T14:43:32-04:00","uid":"0002VT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
