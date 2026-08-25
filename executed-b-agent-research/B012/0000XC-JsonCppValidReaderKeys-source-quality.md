** TARGET-REPORT-UID:0000XC **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000XC] JsonCppValidReaderKeys Source-Quality Report

Agent: Agent-B012  
Assignment: `B012-report-0000XC-jsoncpp-valid-reader-keys-source-quality-20260626`  
Target: [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](../../../../../by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md)  
Report mode: report-only research. No target/support by-* docs were edited, no generated/project-level/coverage files were edited, no leases were taken, no subagents were spawned, and no IDA DB mutation tools were used.

## Recommendation

Implement a narrow source-quality cleanup on [UID:0000XC].

Recommended target metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0000KI`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000KI`
- Keep `EMITTER_POSITION_OPTIONAL` blank

Recommended `Item Summary` replacement:

JsonCpp `getValidReaderKeys` helper from staged static embed `json_reader.cpp`; live IDA reconfirms `0x004417e0-0x00441d24`, direct `CharReaderBuilder::validate` caller at `0x0042d86c`, ten reader-key strings/xrefs, clear/insert set population, padding to the writer-key helper, and formal static-embed marker readiness.

Recommended formal C++:

```cpp
// Static embed: third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp
```

Do not paste upstream JsonCpp source or Hex-Rays output into the formal C++ block. This helper is source-bearing third-party JsonCpp code, and the project convention is the one-line static-embed marker that points the generated reconstruction output at the staged source payload.

## Current State Read

Current target page as read during this report:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000KI`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KI`
- formal `RECONSTRUCTION_CPP CODE` block is empty
- current `Item Summary`: `Static JsonCpp valid-reader-key table/helper code attached to JsonCpp; live IDA confirms `sub_4417E0` size `0x544`.`

The owner/emitter route is already correct: [UID:0000KI][JsonCpp](../../../../../by-file/JsonCpp.md) owns the vendored JsonCpp static library. The stale pieces are source-quality detail and final-C++ disposition. The target still says the vendored source route is why the block is blank, but current project convention for source-bearing static-library children is the formal static-embed marker.

Generated state observed but not edited:

- `auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp` still emits [UID:0000XC] as `Completion:80 | Confidence:85 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` still queues [UID:0000XC] at `80/85`, average `82.5`, reconstructable `true`, C++ size `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` still reports [UID:0000XC] as `reconstructable : 80% : strong : updated 2026-06-23`, `emits_code:false`.

Those generated files should refresh through normal validation/execution after an accepted implementation callback. They must not be manually edited.

## Live IDA MCP Proof

MCP availability and IDB status:

- Listener check reached `127.0.0.1:13337`; `initialize` returned `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- Process/listener context observed before target calls: `idalib-mcp.exe` was running as PID `17084`; active worker/session PID was `26892`.
- `idb_list` returned active session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, `is_analyzing:false`, `owned:true`, `adopted:true`.
- `server_health(database=80de0a67)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.

Read-only MCP tools used for final evidence: `server_health`, `lookup_funcs`, `analyze_function`, `callees`, `xrefs_to`, `get_bytes`, `entity_query`, `find_regex`, `decompile`, and `disasm`. The current live tool list did not expose a usable `callers` method, so caller proof below uses `xrefs_to`, `analyze_function`, and caller decompilation.

No fallback-only evidence was used. The only initial MCP error was a local PowerShell wrapper mistake that sent empty tool arguments and received `database is required`; the corrected calls immediately succeeded and are the evidence used below.

### Boundary And Function Inventory

`lookup_funcs` confirms:

- `0x004417e0` is `sub_4417E0`, size `0x544`.
- `0x00441d24` is not a function.
- `0x00441d30` is `sub_441D30`, size `0x354`, the adjacent valid-writer-key helper.
- `0x0042d7f0` is `sub_42D7F0`, size `0x2d5`.
- `0x0042d86c` resolves inside `sub_42D7F0`.
- `0x0043e250` is `sub_43E250`, the predecessor support-island start.
- `0x004417dd` is not a function.

`entity_query(kind=functions, min_addr=0x004417d0, max_addr=0x00441d40)` found only two function starts in the local window:

- `0x004417e0` `sub_4417E0`, size `0x544`
- `0x00441d30` `sub_441D30`, size `0x354`

Boundary bytes:

- `get_bytes 0x004417d0 size 32` shows the previous body ending in a call through `0x004417dc`, then `cc cc cc` padding at `0x004417dd-0x004417df`, then `sub_4417E0` prologue at `0x004417e0`.
- `get_bytes 0x00441d20 size 32` shows the final call bytes through `0x00441d23`, then twelve `cc` bytes at `0x00441d24-0x00441d2f`, then `sub_441D30` prologue at `0x00441d30`.
- `lookup_funcs` confirms `0x00441d20` and `0x00441d23` are still inside `sub_4417E0`, while `0x00441d24` and `0x00441d2f` are not functions.

This supports keeping the exact half-open range `0x004417e0-0x00441d24` and not merging it with the predecessor STL/string-support island or successor writer-key helper.

### Function Semantics

`analyze_function 0x004417e0` reports:

- name `sub_4417E0`
- prototype `void __cdecl(_DWORD *)`
- size `1348` bytes
- strings: `collectComments`, `allowComments`, `strictRoot`, `allowDroppedNullPlaceholders`, `allowNumericKeys`, `allowSingleQuotes`, `stackLimit`, `failIfExtra`, `rejectDupKeys`, `allowSpecialFloats`
- callees: `sub_43B980`, `sub_41B8B0`, `sub_438400`, `sub_5C7526`, `@__security_check_cookie@4`, and `__invalid_parameter_noinfo_noreturn`
- one code xref to the target from `0x42d86c`
- 66 basic blocks, cyclomatic complexity 18

The decompiler and disassembly show a `std::set`-style clear followed by repeated temporary `JSONCPP_STRING` construction and insertion:

- The opening block walks/clears the tree rooted at the argument set, resets the sentinel links, and sets the node count to zero.
- Each reader-key string is constructed with `sub_41B8B0`.
- Each constructed key is inserted with `sub_438400`.
- Temporary heap-backed strings are freed with `sub_5C7526` when needed.
- The body ends with security-cookie cleanup and `retn` at `0x00441cf1`, with exception cleanup thunks after the return still part of the function object.

`disasm 0x004417e0` explicitly shows the key insertion anchors:

- `0x00441827` `collectComments`
- `0x004418b5` `allowComments`
- `0x0044192c` `strictRoot`
- `0x004419a3` `allowDroppedNullPlaceholders`
- `0x00441a1a` `allowNumericKeys`
- `0x00441a91` `allowSingleQuotes`
- `0x00441b08` `stackLimit`
- `0x00441b7f` `failIfExtra`
- `0x00441bf6` `rejectDupKeys`
- `0x00441c6d` `allowSpecialFloats`

This is the upstream source helper `static void getValidReaderKeys(std::set<JSONCPP_STRING>* valid_keys)`: clear the valid-key set and insert the allowed reader-builder setting names. It does not install default values; `CharReaderBuilder::setDefaults` does that separately.

### Caller Route

`xrefs_to 0x004417e0` returned exactly one code xref:

- `0x0042d86c` inside `sub_42D7F0`, size `0x2d5`

`decompile 0x0042d7f0` confirms the source-level role:

- The function allocates a local set with `sub_43B700`.
- It calls `sub_4417E0(&Block)` at `0x0042d86c`.
- It calls `settings_.getMemberNames()`-style code through `sub_4280F0`.
- It walks each setting key, compares it against the valid-key set through `sub_438880`, and writes invalid settings into the supplied invalid-value object through JsonCpp value/reference helpers.
- It returns whether the invalid object size is zero.

This is `Json::CharReaderBuilder::validate(Json::Value*) const` calling `getValidReaderKeys`. Product modules may call builder APIs or parse JSON, but they do not own this helper body.

### String And Xref Facts

`entity_query(kind=strings, min_addr=0x0060e75c, max_addr=0x0060e800)` returns exactly the ten reader-builder key strings in order:

- `0x0060e75c` `collectComments`
- `0x0060e76c` `allowComments`
- `0x0060e77c` `strictRoot`
- `0x0060e788` `allowDroppedNullPlaceholders`
- `0x0060e7a8` `allowNumericKeys`
- `0x0060e7bc` `allowSingleQuotes`
- `0x0060e7d0` `stackLimit`
- `0x0060e7dc` `failIfExtra`
- `0x0060e7e8` `rejectDupKeys`
- `0x0060e7f8` `allowSpecialFloats`

`find_regex` for those names found the same ten strings plus `Exceeded stackLimit in readValue().` at `0x0060e384`, which is adjacent parser diagnostic context rather than a valid-key string.

`xrefs_to` for the ten key strings confirms every key has a data xref from `sub_4417E0`, and most also have setting/default xrefs in builder helpers:

- `collectComments`: `0x42d3b6`, `0x42dbe4`, `0x441827`
- `allowComments`: `0x42d3dd`, `0x42dc31`, `0x42df44`, `0x4418b5`
- `strictRoot`: `0x42d40a`, `0x42dc80`, `0x42df91`, `0x44192c`
- `allowDroppedNullPlaceholders`: `0x42d42e`, `0x42dccf`, `0x42dfe0`, `0x4419a3`
- `allowNumericKeys`: `0x42d452`, `0x42dd25`, `0x42e02f`, `0x441a1a`
- `allowSingleQuotes`: `0x42d476`, `0x42dd6d`, `0x42e085`, `0x441a91`
- `stackLimit`: `0x42d49a`, `0x42ddc6`, `0x42e0d7`, `0x441b08`
- `failIfExtra`: `0x42d528`, `0x42de15`, `0x42e126`, `0x441b7f`
- `rejectDupKeys`: `0x42d549`, `0x42de64`, `0x42e175`, `0x441bf6`
- `allowSpecialFloats`: `0x42d56d`, `0x42deb3`, `0x42e1c4`, `0x441c6d`

The non-target xrefs match the builder settings/default/normalization helpers already documented by [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](../../../../../by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md).

## Static Source Proof

The staged source path for the formal marker is:

- `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`

Working embed and obtained-candidate hashes:

- `source-3/third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`: SHA-256 `89074ED5550883E9EA7D300ED24292BB3238A18F76103C1219ADB4D08F8899D2`
- `source-3/project-documentation/by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/src/lib_json/json_reader.cpp`: SHA-256 `89074ED5550883E9EA7D300ED24292BB3238A18F76103C1219ADB4D08F8899D2`

Source anchors from the staged file:

- `json_reader.cpp:1927-1938` reads the same ten settings in `CharReaderBuilder::newCharReader()`.
- `json_reader.cpp:1940` defines `static void getValidReaderKeys(std::set<JSONCPP_STRING>* valid_keys)`.
- `json_reader.cpp:1942` clears the set.
- `json_reader.cpp:1943-1952` inserts the same ten reader keys in the same source order.
- `json_reader.cpp:1954-1968` defines `CharReaderBuilder::validate`, creates `valid_keys`, calls `getValidReaderKeys(&valid_keys)`, loops over `settings_.getMemberNames()`, and copies invalid settings into the invalid output object.
- `json_reader.cpp:1991-2003` contains `CharReaderBuilder::setDefaults`, proving default values are a separate source helper and not part of this target.

The source snapshot remains the official JsonCpp commit `b299d3581f4dc670734f1fe1a34fce1282337802`, after tag `1.7.4` and before `1.7.5`. This phrasing should be preserved. Do not rewrite it as an exact released-tag claim.

## Positive Evidence Summary

- Live MCP confirms the exact function start, size, end padding, and writer-key successor boundary.
- Live MCP confirms the single direct caller at `0x0042d86c` inside `CharReaderBuilder::validate`-style `sub_42D7F0`.
- Live MCP decompilation/disassembly confirm clear-then-insert behavior for all ten reader keys.
- Live MCP string queries and xrefs confirm the contiguous reader-key block and every target xref.
- Staged source contains the exact helper, caller, and key list in `json_reader.cpp`.
- Staged working and obtained third-party source copies hash-match.
- Existing [UID:0000KI] and [UID:0001QE] docs already establish JsonCpp as a statically embedded library under `third_party/jsoncpp/`, with product modules as consumers.

## Negative Evidence Summary

- The target is not NexusTK product code. Cash-shop, fitting-room, downloader, profile, and map code consume JsonCpp APIs; they do not own this static helper.
- The target is not `CharReaderBuilder::setDefaults`; it validates setting names only, while default values are installed by a separate source function.
- The target is not the reader parse method [UID:0000X7] or the reader/builder island [UID:0000X2]; those are callers/nearby source context, not replacement owners.
- The target is not [UID:0000XD] `getValidWriterKeys`; that successor starts at `0x00441d30` after padding and belongs to `json_writer.cpp`.
- The target is not MSVC/STL/CRT-authored source despite calls to string, set, allocator, security-cookie, and invalid-parameter helpers. Those calls are compiler/runtime support around JsonCpp source.
- The target should not remain a blank-code source-bearing child. Blank formal C++ is appropriate for non-emitting split indexes and mixed pages, but source-bearing static-embed children now use explicit marker comments.

## Ranked Ownership And Source Placement Analysis

### 1. [UID:0000KI] JsonCpp

Evidence for: exact staged source helper, exact reader-key strings, direct `CharReaderBuilder::validate` caller, JsonCpp builder/source context, staged source hash, static embed policy, and existing parent route.  
Evidence against: helper is compiler-placed after MSVC/STL/string-support bytes rather than contiguous with the main reader builder island. This is only a linker/source-placement fact and does not change ownership.  
Decision: keep `CANONICAL_OWNER:0000KI` and `EMITTER_UIDS:0000KI`.

### 2. [UID:0000X2] JsonCppReaderAndBuilderPreludeIsland

Evidence for: direct caller lives inside [UID:0000X2], and its builder helper consumes the valid-key set.  
Evidence against: [UID:0000XC] has its own exact function object, range, source helper, and static-embed route after the STL/string support island. Absorbing it into [UID:0000X2] would make both ranges less exact.  
Decision: keep [UID:0000X2] as a support/caller reference only.

### 3. [UID:0000XD] JsonCppValidWriterKeys

Evidence for: adjacent valid-key helper and symmetric source role.  
Evidence against: [UID:0000XD] starts at `0x00441d30` after padding, uses `json_writer.cpp`, and validates writer settings. [UID:0000XC] uses `json_reader.cpp` and validates reader settings.  
Decision: do not merge or edit [UID:0000XD] in this callback. It is a likely parallel future cleanup, but not the assigned target.

### 4. Product modules

Evidence for: product code consumes JSON configuration, catalog, and request data elsewhere.  
Evidence against: no product caller owns this helper; the direct caller is a JsonCpp builder validator, and all source evidence is vendored JsonCpp.  
Decision: reject product ownership/emission.

### 5. MSVC/STL/CRT/runtime support

Evidence for: set/string operations, security-cookie handling, invalid-parameter paths, and allocator calls dominate the compiled helper shape.  
Evidence against: strings, source helper, caller, and staged file all identify JsonCpp source. Runtime helpers remain dependencies, not owners.  
Decision: reject as canonical owner.

### 6. No-owner/non-emitting

Evidence for: the target previously kept a blank formal block because vendored source was the true route.  
Evidence against: current project convention resolves that exact condition with a static-embed marker for source-bearing third-party children. Neighboring accepted JsonCpp children [UID:000380] and [UID:0000X7] emit `// Static embed: third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`.  
Decision: reject no-owner/non-emitting. Keep reconstructable and insert the static-embed marker.

## Range / Split / Reclassification Analysis

- Keep exact range `0x004417e0-0x00441d24`.
- Do not extend left into [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](../../../../../by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md). Live bytes show predecessor padding at `0x004417dd-0x004417df`.
- Do not extend right into [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](../../../../../by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md). Live bytes show padding at `0x00441d24-0x00441d2f`, and `lookup_funcs 0x00441d30` starts `sub_441D30`.
- Do not split [UID:0000XC]. It is one cohesive source helper and maps to one static source function.
- Do not merge [UID:0000XC] into [UID:0000X2]. The caller relationship is enough; source placement and exact function range are better preserved as a separate source-bearing child.
- Do not reclassify as ignored or non-reconstructable. The helper is part of the statically linked JsonCpp source payload needed in the rebuilt executable.

## First-Draft C++ Recommendation / Static-Embed Marker

- Eligible for formal C++ by score/emitter gate after the recommended `90/92` score: yes.
- Recommended formal block content is exactly the `cpp` block in this report's recommendation section.
- Reason: this target is statically embedded third-party JsonCpp. The correct final source comes from the staged `json_reader.cpp` payload under [UID:0000KI], not a handwritten or decompiler-shaped by-memory method body.
- Rule reconciliation: [UID:0000XC] is not covered by another by-memory UID's emitted code, so the covered-by UID marker rule does not apply. It is a source-bearing static-embed child, like accepted [UID:000380] and [UID:0000X7]. Those pages use `json_reader.cpp` static-embed markers, and this helper should do the same.
- No-handwritten/decompiler-C++ proof: MCP and staged source prove the source body, but copying the helper into the by-memory page would duplicate third-party source outside its file context and risk divergence from the staged snapshot. The static-embed marker provides generated source output without creating a local reimplementation.

## Score Rationale

Recommended score is `COMPLETION:90`, `CONFIDENCE:92`.

Completion improves from `86` to `90` because this report resolves the current source-quality blockers:

- current MCP rechecked the exact function range and padding boundaries;
- current MCP identified the exact caller route through `CharReaderBuilder::validate`;
- current MCP proved every reader-key string and target xref;
- current MCP disassembly/decompilation confirmed the clear/insert set semantics;
- staged source and obtained third-party source copies hash-match;
- formal C++ disposition is now exact: static-embed marker to `json_reader.cpp`.

Confidence improves from `89` to `92` because independent evidence routes agree: live binary range/caller/string facts, decompiled behavior, staged source lines, static source hash, and established JsonCpp parent/support docs.

Score should not go higher yet because this remains a static third-party embed rather than original NexusTK source, the exact original release label remains a best commit snapshot rather than a released tag, and the marker points to a whole source file rather than proving byte-identical compiler settings for this single helper.

## Recommended Target Doc Changes

Target: `by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md`

If accepted:

1. Update header scores to `COMPLETION:90` and `CONFIDENCE:92`.
2. Preserve `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`, and blank `EMITTER_POSITION_OPTIONAL`.
3. Replace the `Item Summary` with the recommended text from this report.
4. Insert the formal static-embed marker in the target `RECONSTRUCTION_CPP CODE` block.
5. Refresh the body with current MCP session `80de0a67` proof: range, boundaries, direct caller at `0x0042d86c`, ten string/xref anchors, clear/insert behavior, staged source hash, and generated-stale note.
6. Replace the stale rationale that the block is blank because vendored source is correct. The correct current disposition is the marker-only static-embed formal block.
7. Preserve rejected alternatives: product modules, [UID:0000X2] caller island as owner, [UID:0000XD] writer helper merge, MSVC/STL/CRT ownership, and no-owner/non-emitting.
8. Add a change entry noting this B012 report and the reason for `90/92` plus static marker.

## Recommended Support Doc Changes

Required support update if accepted: [UID:0000KI][JsonCpp](../../../../../by-file/JsonCpp.md)

- Add a concise [UID:0000XC] evidence/change bullet near the existing builder/settings and [UID:0000X7] JsonCpp source-quality notes.
- Required facts to preserve: `sub_4417E0`, exact range `0x004417e0-0x00441d24`, direct caller `0x0042d86c` inside `sub_42D7F0` / `CharReaderBuilder::validate`, ten reader keys from `collectComments` through `allowSpecialFloats`, staged `json_reader.cpp` SHA-256 `89074ED5550883E9EA7D300ED24292BB3238A18F76103C1219ADB4D08F8899D2`, and formal marker `// Static embed: third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`.
- Keep [UID:0000KI] scores unchanged unless the supervisor explicitly requests a broader parent score refresh.

Optional support update if current implementation callback scope allows it: [UID:0001QE][client_libraries](../../../../../by-meta/client_libraries.md)

- Current detail already identifies [UID:0000XC] as a builder/settings-string helper and preserves the broader JsonCpp static embed route. If the supervisor wants report-level detail mirrored there, add one concise JsonCpp-section note with the same marker/range/caller/key-list facts. This is useful but not required for the narrow target fix.

Do not edit [UID:0000XD] in this callback unless the supervisor separately assigns it. It has the same blank-marker issue for `json_writer.cpp`, but it is outside this report's target.

## Implementation Tracking Checklist

Implementation callback proof, 2026-06-27:

- [x] Lease [UID:0000XC] `by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md` only immediately before editing. Proof: shared `current_leases.md` showed no active leases before edit; `python .\tools\leaser\leaser.py B012 lease by-memory\0x004417e0-0x00441d24.JsonCppValidReaderKeys.md by-file\JsonCpp.md` returned `Success` for the target.
- [x] If editing support, lease [UID:0000KI] `by-file/JsonCpp.md` only immediately before editing; lease [UID:0001QE] `by-meta/client_libraries.md` only if the supervisor accepts the optional support update and its current detail is below this report. Proof: [UID:0000KI] was leased in the same immediate edit batch and returned `Success`; [UID:0001QE] was explicitly excluded by `goal.md`, so it was not leased or edited.
- [x] Confirm no live lease conflict exists before editing any target/support file; if a needed support file is leased by another agent, wait/recheck or report `PAUSED_LEASE_CONFLICT`. Proof: `current_leases.md` reported `No active leases` before B012 leased the two edited by-* docs.
- [x] Update [UID:0000XC] `COMPLETION` to `90` and `CONFIDENCE` to `92`. Proof: `by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md` header now has `COMPLETION:90` and `CONFIDENCE:92`.
- [x] Preserve [UID:0000XC] `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: target header still has `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`, and `EMITTER_POSITION_OPTIONAL:` with no value.
- [x] Replace [UID:0000XC] `Item Summary` with the exact recommendation text in this report. Proof: target `Item Summary` now exactly reads `JsonCpp `getValidReaderKeys` helper from staged static embed `json_reader.cpp`; live IDA reconfirms `0x004417e0-0x00441d24`, direct `CharReaderBuilder::validate` caller at `0x0042d86c`, ten reader-key strings/xrefs, clear/insert set population, padding to the writer-key helper, and formal static-embed marker readiness.`
- [x] Add the formal static-embed marker `// Static embed: third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp` and no pasted upstream/Hex-Rays body. Proof: target formal `RECONSTRUCTION_CPP CODE` block contains only that marker line.
- [x] Refresh [UID:0000XC] evidence with current MCP range/caller/string/xref/source-hash proof from this report. Proof: target body now records MCP session `80de0a67`, exact boundaries and padding, function inventory, direct caller `0x0042d86c`, ten string addresses and xrefs, clear/insert semantics, staged source anchors, SHA-256 `89074ED5550883E9EA7D300ED24292BB3238A18F76103C1219ADB4D08F8899D2`, rejected alternatives, score rationale, and stale generated-state note.
- [x] Update [UID:0000KI] with the accepted [UID:0000XC] support facts, preserving parent/source route and scores unless instructed otherwise. Proof: `by-file/JsonCpp.md` scores remain `COMPLETION:92` and `CONFIDENCE:88`; a B012 evidence bullet near the builder/settings notes records `sub_4417E0`, range `0x004417e0-0x00441d24`, caller `0x0042d86c` inside `sub_42D7F0` / `CharReaderBuilder::validate`, ten keys from `collectComments` through `allowSpecialFloats`, the staged `json_reader.cpp` SHA-256, and the formal marker.
- [x] Optionally update [UID:0001QE] only if supervisor scope includes it and current detail is still below this report. Proof: explicitly excluded by callback `goal.md`; not edited.
- [x] Do not edit [UID:0000XD], generated/project-level files, tool state, IDA DB, or any `-coverage-report.md`. Proof: [UID:0000XD], [UID:0001QE], IDA DB, and manual coverage reports were not edited. Validator, not manual edits, refreshed generated output and project-level generated state as part of scoped validation.
- [x] Run scoped validator for every changed by-* file. Proof:
  - Target command rerun for auditable metadata and generated freshness: `python .\tools\validator.py --mode file --file by-memory\0x004417e0-0x00441d24.JsonCppValidReaderKeys.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000003712`; `command_timestamp: 2026-06-27T02:48:09-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`; `generated_refresh_command_id: 000000003712`; known unrelated warnings included stale/missing registry entries and missing [UID:0000X2] target path from existing validator state. The initial exact target command without `--wait-generated` also exited `0` but emitted no captured stdout, so this rerun is the reported validator result for the target.
  - Support command: `python .\tools\validator.py --mode file --file by-file\JsonCpp.md --apply --queue-timeout 240`; `command_id: 000000003711`; `command_timestamp: 2026-06-27T02:47:46-04:00`; exit code `0`; `ok: 1`; `generated_refresh: deferred`; known pre-existing warnings included missing UID references `0003WI`, `0003WJ`, `0003WK`, `0003WL`, `0003WM`, `0003WN`, `0003WO`, stale [UID:0000X2] target path, and `stats_incremental_noop` for [UID:0000KI].
- [x] Capture validator command id, timestamp, exit code, warnings, and generated-refresh status in this checklist. Proof: recorded in the validator item above.
- [x] Generated JsonCpp output freshness checked. Proof: `auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp` header now shows `validator-command-id: 000000003712` and `validator-refreshed-at: 2026-06-27T02:48:09-04:00`, equal to the target validator rerun; [UID:0000XC] now appears as `Completion:90 | Confidence:92` followed by `// Static embed: third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`, replacing the stale [UID:0000XC] empty-emitter output. Other unrelated JsonCpp children still show empty markers.
- [x] Release every lease immediately after the edit/validator batch. Proof: `python .\tools\leaser\leaser.py B012 unlease by-memory\0x004417e0-0x00441d24.JsonCppValidReaderKeys.md by-file\JsonCpp.md` returned `Success` for both paths; immediate post-release `current_leases.md` read reported `No active leases`, and the final lease read showed only later B014 leases, with no active B012 leases remaining.
- [x] Update this checklist with proof before returning `FINISHED_IMPLEMENTATION`. Proof: this implementation callback proof section is the checklist update.

## Report-Only Proof

- Read and followed `tools/leaser/Agents/Agent-B012/goal.md`.
- Used project-level `ntk-b-agent-workflow` instructions.
- Used live IDA MCP session `80de0a67`; no fallback-only report was produced.
- Took no leases.
- Edited only this report under the assigned Agent-B012 research folder.
- Did not edit target/support by-* docs, generated files, project-level generated files, tool state, IDA DB, or any `-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0000XC-JsonCppValidReaderKeys-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0000XC-JsonCppValidReaderKeys-source-quality.md","timestamp":"2026-06-27T02:52:41","uid":"0000XC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
