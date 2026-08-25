** TARGET-REPORT-UID:000286 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000286 PacketTransformAlternateSizeAndLut Source-Quality MCP Redo

## Finalized Report / Current Recommendation

- Assignment ID: `B004-redo-packettransform-alt-size-lut-source-quality-000286-mcp-20260623`.
- Current recommendation: keep [UID:000286] assigned to [UID:0000TG] `PacketTransformGlobals` and emitted through [UID:0000TG] -> [UID:0000M9] `PacketTransform`.
- Score recommendation: keep the current target metadata at `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000TG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TG`, and blank emitter position.
- C++ recommendation: keep the existing first-draft declaration block unchanged. The current target block is source-shaped and justified by live MCP evidence: `int g_packetXorAlternateSize = 9`, private `static int s_packetTransformReserved = 0`, and `unsigned int g_packetTransformLut[256]` initialized through `PACKET_TRANSFORM_LUT_ENTRY(0x00)` through `PACKET_TRANSFORM_LUT_ENTRY(0xff)` followed by `#undef`.
- Required implementation if this redo is accepted: do not change the score or C++ block; replace stale offline-only wording in the target/support/coverage text with the current MCP-backed evidence below.

## Target

- Target UID: `000286`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\000286-PacketTransformAlternateSizeAndLut-source-quality.md`.
- Current target score and route: `88/89`, owner [UID:0000TG] `PacketTransformGlobals`, reconstructable, emitted through [UID:0000TG] to [UID:0000M9] `PacketTransform`.
- Current target C++ state: first-draft C++ is already present from the prior implementation callback.
- Report-only restriction observed: this pass edits only this active report. No by-* docs, generated/project-level files, IDA DB, tool state, or `-coverage-report.md` files were edited.

## Current Target State

- The prior offline report was already implemented into the target/support docs and supervisor-applied coverage. The docs now contain the source declaration shape, score `88/89`, and the first-draft C++ block.
- The implemented docs still carry stale B004 wording that says the B004 source-quality report inherited a live IDA/MCP outage and relied on previously recorded IDA facts. That is now superseded by this MCP-backed redo.
- The current target facts that remain valid are the exact range, initialized `.data` role, `0x408` / decimal `1032` byte size, two leading dwords, `0x400` / decimal `1024` byte LUT payload, `0x100` / decimal `256` dword entries, the [UID:000287] boundary at `0x00670258`, PacketTransform ownership, Socket writer/consumer rejection, and the source-shaped C++ declaration block.
- The current target facts that need wording repair are the B004 "live IDA unavailable" caveat and the score rationale sentence that currently uses MCP outage as one reason for the confidence cap.

## Live MCP Session / Tool Facts

- Endpoint used: `http://127.0.0.1:13337/mcp`.
- Active session used explicitly in every analysis call: `b880584f`.
- `initialize`/`tools/list` at `2026-06-23T06:11:42-04:00` succeeded; server name `ida-pro-mcp`; tool count `65`.
- `server_health` at `2026-06-23T06:12:11-04:00` and again at `2026-06-23T06:18:58-04:00` returned `status:"ok"`, `idb_path:"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"`, `module:"NexusTK.exe"`, `input_path:"C:\\Users\\admin\\Desktop\\Clone\\NexusTK\\NexusTK.exe"`, `imagebase:"0x400000"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- `idb_list` returned exactly one active session, `b880584f`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `27504`, `is_active:true`, `is_analyzing:false`.
- Operational note: one broad `.text` `insn_query` operand sweep for `0x0066fe50`, `0x0066fe54`, and `0x0066fe58` returned MCP-internal `Tool timed out after 60.00s` results. The server remained healthy immediately afterward, targeted MCP calls succeeded, and those broad-sweep timeout rows are not used as negative evidence. All target conclusions below rely on `xrefs_to`, targeted range disassembly, decompilation/function summaries, `get_int`, `get_bytes`, `entity_query`, and supplemental PE byte scans.

## Evidence Checked

- MCP `xrefs_to` for `0x0066fe50`, `0x0066fe54`, `0x0066fe58`, and `0x00670258`.
- MCP `get_int` for `0x0066fe50`, `0x0066fe54`, `0x0066fe58`, `0x0066fe5c`, `0x00670054`, `0x00670058`, `0x00670250`, `0x00670254`, and `0x00670258`.
- MCP `get_bytes` for `0x0066fe50` head bytes and `0x00670240` tail/boundary bytes.
- MCP `lookup_funcs` for `0x00575b90`, `0x00575c30`, `0x00575cb0`, `0x00575e60`, `0x0057615f`, `0x00576fee`, `0x00577030`, `0x00577890`, `0x00578b20`, `0x00578c40`, and `0x00578e00`.
- MCP `entity_query` for globals/names in `0x0066fe40-0x00670270`.
- MCP targeted `insn_query` for raw `0x00575b90-0x00575c30`, raw `0x00576f80-0x00577010`, Socket command-13 range `0x00576060-0x00576190`, and XOR helper range `0x00578e00-0x00578e94`.
- MCP `analyze_function` for `0x00575c30`, `0x00575cb0`, `0x00575e60`, `0x00577030`, `0x00578b20`, `0x00578c40`, and `0x00578e00`.
- Local PE supplement for `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`: SHA-256, section map, target VA/RVA/raw mapping, and direct byte-pattern hits for `0x0066fe50`, `0x0066fe54`, `0x0066fe58`, and `0x00670258`.
- `int_convert.py` conversions: `0x408` = decimal `1032`, `0x400` = decimal `1024`, `0x100` = decimal `256`, `0x9` = decimal `9`, and `0xc` = decimal `12` (Verified with `int_convert.py`).
- Current docs checked as evidence/support context: target [UID:000286], [UID:0000TG] `PacketTransformGlobals`, [UID:0000M9] `PacketTransform`, [UID:0000V3] `PacketTransformHelpers`, [UID:000287], and current [UID:000286] coverage row in `by-memory/-coverage-report.md`.

## Live MCP Facts

- `xrefs_to 0x0066fe50` returned 11 data xrefs: raw/no-function references at `0x00575bab`, `0x00575bbc`, `0x00575bd3`, `0x00575bec`, and `0x00575c06`; `sub_575CB0` references at `0x00575cbb`, `0x00575d28`, `0x00575d41`, and `0x00575d5b`; `sub_578B20` reference at `0x00578c0e`; and `sub_578C40` reference at `0x00578d0b`.
- `xrefs_to 0x0066fe54` returned zero xrefs. This reconfirms the reserved/unused slot has no current direct references.
- `xrefs_to 0x0066fe58` returned two data xrefs: `0x0057615f` inside `sub_575E60` and raw/no-function `0x00576fee`.
- `xrefs_to 0x00670258` returned one data xref at `0x005778cf` inside `sub_577890`, confirming the next Socket connection-string parse range begins at the target's half-open end.
- `get_int` returned `0x0066fe50 = 9`, `0x0066fe54 = 0`, `0x0066fe58 = 0`, `0x0066fe5c = 16843009` (`0x01010101`), `0x00670054 = 2139062143` (`0x7f7f7f7f`), `0x00670058 = 2155905152` (`0x80808080`), `0x00670250 = 4278124286` (`0xfefefefe`), and `0x00670254 = 4294967295` (`0xffffffff`).
- `get_int 0x00670258` returned `6442920`, the next pointer value, not a LUT element.
- `get_bytes 0x0066fe50 size 80` returned the expected initialized head: size dword `09 00 00 00`, reserved zero dword, then repeated-byte dwords `00 00 00 00`, `01 01 01 01`, `02 02 02 02`, and onward.
- `get_bytes 0x00670240 size 48` returned tail dwords `fa fa fa fa`, `fb fb fb fb`, `fc fc fc fc`, `fd fd fd fd`, `fe fe fe fe`, `ff ff ff ff`, then pointer data beginning at `0x00670258`.
- `entity_query` globals/names in `0x0066fe40-0x00670270` returned only `Size` at `0x0066fe50` and later `lpClassName`/`lpWindowName` at `0x00670260`/`0x00670264`; it did not return a named global at `0x0066fe54` or `0x0066fe58`. That supports treating `g_packetXorAlternateSize`, `s_packetTransformReserved`, and `g_packetTransformLut` as inferred source-facing documentation names, not recovered symbol proof.

## Function / Route Facts

| Address | MCP result | Meaning for [UID:000286] |
| --- | --- | --- |
| `0x00575b90` | `lookup_funcs`: not a function; targeted disassembly decodes a complete raw stack-frame helper ending in `retn 4`. | Raw string-key setup reads `Size` five times and copies four alternate-table windows through `0x0069ba94`; still no modeled function start. |
| `0x00575c30` | `sub_575C30`, size `0x7a`; decompiled prototype `void __stdcall(char *Src)`. | Login/process text expansion helper; support context only, does not directly touch the LUT block. |
| `0x00575cb0` | `sub_575CB0`, size `0xd3`; decompiled prototype `void *__stdcall(unsigned __int16, unsigned __int8)`. | `InitializePacketNonce` reads `Size`, fills `unk_69BA4C`, range-checks against `0x0c`, and copies four alternate windows into `unk_69BA94`. |
| `0x00575e60` | `sub_575E60`, size `0x344`; decompiled Socket command handler. | Command `13` is the live writer to `dword_66FE58[ebx*4]`; command `14` calls `BuildHandshakeBlock`. |
| `0x0057615f` | inside `sub_575E60`. | Targeted disassembly shows `mov dword_66FE58[ebx*4], ecx`, after constructing a repeated-byte dword in `ecx`. |
| `0x00576fee` | `lookup_funcs`: not a function. | Raw duplicate/unmodeled writer site also stores `mov dword_66FE58[ebx*4], ecx`; still belongs to the socket transport/command cluster evidence, not declaration ownership. |
| `0x00577030` | `sub_577030`, size `0x10d`; decompiled `BuildHandshakeBlock`. | Builds primary table/stride at mutable transform state; supports PacketTransform helper grouping. |
| `0x00578b20` | `sub_578B20`, size `0x120`; decompiled transform-frame payload helper. | Calls `InitializePacketNonce`, calls `XorTransformBuffer` with key pointer `4 * sequence + 0x0066fe58`, and uses `Size` for alternate-table stride. |
| `0x00578c40` | `sub_578C40`, size `0x1b1`; decompiled encrypted-packet builder. | Calls `InitializePacketNonce`, conditionally uses `Size`, calls `XorTransformBuffer` with key pointer `4 * sequence + 0x0066fe58`, and then calls the MD5 packet digest helper. |
| `0x00578e00` | `sub_578E00`, size `0x94`; decompiled `XorTransformBuffer`. | Reads dword key material as `*(_DWORD *)(a4 + 4 * (index % stride))`, then handles trailing bytes from the next key word. This directly supports `unsigned int g_packetTransformLut[256]`. |

## PE Provenance / Route Scan Supplement

- PE path from MCP health and local scan: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Image base: `0x00400000`; section map:
  - `.text` RVA `0x1000`, VA `0x00401000-0x0060c4ac`, raw `0x400-0x20ba00`.
  - `.rdata` RVA `0x20d000`, VA `0x0060d000-0x0066c0be`, raw `0x20ba00-0x26ac00`.
  - `.data` RVA `0x26d000`, VA `0x0066d000-0x0069ce24`, raw `0x26ac00-0x278400`.
  - `.rsrc` RVA `0x29d000`, VA `0x0069d000-0x006b2c38`, raw `0x278400-0x28e200`.
- `0x0066fe50` maps to `.data` RVA `0x26fe50`, raw `0x26da50`. Absolute-VA pattern `50 fe 66 00` has 11 `.text` hits with instruction VAs `0x00575bad`, `0x00575bbe`, `0x00575bd4`, `0x00575bed`, `0x00575c07`, `0x00575cbd`, `0x00575d29`, `0x00575d42`, `0x00575d5c`, `0x00578c10`, and `0x00578d0d`; RVA and raw-offset dword patterns have zero hits.
- `0x0066fe54` maps to `.data` RVA `0x26fe54`, raw `0x26da54`. Absolute-VA, RVA, and raw-offset dword patterns all have zero file and `.text` hits.
- `0x0066fe58` maps to `.data` RVA `0x26fe58`, raw `0x26da58`. Absolute-VA pattern `58 fe 66 00` has six `.text` hits with instruction VAs `0x00576162`, `0x00576ff1`, `0x00578ba2`, `0x00578be5`, `0x00578d5f`, and `0x00578d8e`; RVA and raw-offset dword patterns have zero hits.
- `0x00670258` maps to `.data` RVA `0x270258`, raw `0x26de58`. Absolute-VA pattern `58 02 67 00` has one `.text` hit at instruction VA `0x005778d1`; RVA and raw-offset dword patterns have zero hits.
- The PE route scan corroborates MCP xrefs: exact absolute VA uses exist for `Size`, the LUT base, and the next Socket boundary, while the reserved dword has no direct route evidence.

## Heuristic / Inference Reanalysis And Validation

- Generated name issue: `Size` is the only current IDB name returned in the range. It is too generic for final source, so `g_packetXorAlternateSize` remains the best descriptive source-facing name, marked inferred.
- LUT name/type issue: `g_packetTransformLut` remains the best source-facing name because command `13` writes the table as repeated-byte dwords and the transform helpers consume dword key words indexed by packet sequence/block indexes. `dword_66FE58` remains a search alias only.
- Reserved dword issue: `0x0066fe54` has no MCP xrefs and no PE absolute/RVA/raw pattern hits. It is still best represented as private reserved source data instead of deleted padding because it sits between dword declarations, has a meaningful initialized zero value in the declaration block, and no dword-to-dword alignment filler is needed.
- Initializer issue: the table should remain an initialized `.data` declaration, not a runtime startup fill loop. The initial repeated-byte values exist in the image before Socket command `13` can overwrite them.
- Source placement issue: PacketTransform remains the best reconstruction parent. Socket writes and consumes the data, but the data is reusable transform helper/global state, not Socket object state and not PacketBuffer scalar serialization storage.
- Existing first-draft C++ is justified. The target's current block is source-shaped rather than generated/IDA-shaped: plain `int`/`unsigned int`, a private `static` reserved dword, and a repeated-byte initializer macro with `#undef`.

## Positive Evidence Summary

- Live MCP confirms the exact initialized values, the no-xref reserved dword, the LUT dword shape, and the clean boundary before [UID:000287].
- Live MCP confirms the writer path: Socket command `13` stores dwords into `dword_66FE58[ebx*4]`.
- Live MCP confirms the consumer path: inbound/outbound Socket transform helpers pass `4 * sequence + 0x0066fe58` into `XorTransformBuffer`, which reads `*(_DWORD *)(key + 4 * (index % stride))`.
- PE route scanning independently matches the MCP xrefs for `0x0066fe50`, `0x0066fe58`, and `0x00670258`, and remains negative for `0x0066fe54`.
- Current target/support docs already contain most prior source-quality detail; the main corrective work is replacing stale offline-only B004 caveats with current session-backed evidence.

## Negative Evidence Summary

- No xrefs or PE direct patterns target `0x0066fe54`; do not invent active behavior for the reserved dword.
- `entity_query` did not return recovered IDB names for `0x0066fe54` or `0x0066fe58`; source names remain inferred/descriptive.
- Generated/simroot byte-array declarations and IDA undersized `int[130]` typing remain rejected as stale/tool-shaped evidence.
- Socket writer/consumer evidence is not enough to make Socket the declaration owner.
- PacketBuffer is rejected because this is transform key material, not scalar packet read/write cursor storage.
- The original source filename/private-section split is still unproven, and helper prototypes/raw helper liveness remain broader PacketTransform blockers.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x0066fe50-0x00670258` is one initialized PacketTransform global-data range. | Strong | MCP bytes/ints, `.data` PE mapping, [UID:000287] boundary, PacketTransform global docs. | Socket ownership, PacketBuffer ownership, and raw data-island ownership rejected. | Original source file spelling/private section remains inferred. |
| `0x0066fe58-0x00670258` is 256 dword entries, not a byte array. | Strong | MCP `get_int` samples, command-13 dword stores, `XorTransformBuffer` dword key reads, PE `.text` hits to absolute VA. | Generated byte-array output and IDA undersized type rejected. | IDA DB type/name cleanup remains future optional work. |
| `0x0066fe54` should remain explicit reserved source data. | Medium-high | Zero initial value, zero MCP xrefs, zero PE VA/RVA/raw hits, no needed alignment between dwords. | Could be compiler/linker filler or a lost original global. | Exact original name and intent are unrecovered; score stays capped. |
| PacketTransform owns declarations; Socket is writer/consumer. | Strong | Helper/global family, source-root routing, B006 Socket split, writer/consumer relationship. | Socket command `13` and encode/decode consumers checked. | Original source may have used a private Socket helper section. |
| Existing first-draft C++ is justified. | Strong for this range, not final-audit | Exact bytes and access pattern support `int`, reserved `static int`, and `unsigned int[256]` initializer. | Helper prototypes and raw `0x00575b90` remain unresolved but outside this exact data declaration. | Keep below `90+` because names/source split/reserved intent are inferred. |

## Ranked Ownership Analysis

### 1. [UID:0000TG] PacketTransformGlobals -> [UID:0000M9] PacketTransform

- Evidence for: current route already owns both initialized and mutable packet-transform state; live MCP links `Size`, the LUT writer, and transform consumers to the packet-transform helper family; PacketTransform file-level docs explicitly keep free transform helpers/globals out of Socket method bodies and PacketBuffer scalar helpers.
- Evidence against: Socket command `13` writes the LUT, Socket encode/decode paths consume it, and the exact original source could have been a private `Socket.cpp` helper section.
- Decision: keep. This remains the best direct semantic owner and emitter route.

### 2. [UID:0000NS] Socket

- Evidence for: `sub_575E60` command `13` writes `dword_66FE58[ebx*4]`; `sub_578B20` and `sub_578C40` use the table during Socket frame transforms.
- Evidence against: those are runtime writer/consumer facts, not declaration ownership; the table is global transform key material; Socket should own stateful transport methods, not the reusable transform declaration block.
- Decision: reject as direct owner; preserve Socket as writer/consumer context.

### 3. [UID:0000M8] PacketBuffer

- Evidence for: the functions operate on packet bytes and live near packet-buffer helper code in address space.
- Evidence against: PacketBuffer owns scalar cursor/endian/string serialization, while this range is key-table state consumed by XOR/nonce/handshake transform helpers.
- Decision: reject.

### 4. Generic raw data island / no-owner

- Evidence for: IDB exposes only generic `Size` and no named LUT global through `entity_query`; original symbol spellings are not recovered.
- Evidence against: xrefs, bytes, writer/consumer behavior, and support docs all tie the data to a coherent PacketTransform declaration block with a valid emitter route.
- Decision: reject.

## Source Placement

- Recommended placement: keep `network/PacketTransform.cpp` through [UID:0000M9].
- Why this placement fits: the declarations serve reusable transform helpers and global key material. Socket sequences connection commands and frame transforms but should not own every helper/global it touches.
- Rejected placements: direct `Socket.cpp` ownership is weaker and would conflate declaration ownership with runtime use; `PacketBuffer.cpp` is the wrong subsystem; a raw generated data file would be tool-shaped and source-implausible.
- Remaining source-placement caveat: exact original filename versus private Socket helper section remains unproven and should stay in support docs as a score cap.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x0066fe50-0x00670258`, half-open.
- Total size: `0x408` / decimal `1032` bytes (Verified with `int_convert.py`).
- Layout: `0x0066fe50-0x0066fe54` size dword, `0x0066fe54-0x0066fe58` reserved zero dword, `0x0066fe58-0x00670258` LUT payload.
- LUT payload: `0x400` / decimal `1024` bytes, or `0x100` / decimal `256` dword entries (Verified with `int_convert.py`).
- Start boundary: follows the documented SpelledPane-to-PacketTransform padding ending at `0x0066fe50`.
- End boundary: `0x00670258` starts [UID:000287] Socket connection-string pointer data; MCP and PE both show the next absolute reference route belongs to the Socket boundary.
- Split recommendation: no split. The declaration sequence is physically adjacent and semantically coherent.
- Padding/reclassification: keep `0x0066fe54` inside the reconstructable target as private reserved initialized source data; do not split it to ignored alignment without stronger evidence.

## First-Draft C++ Recommendation

- Recommendation: keep the current target C++ block unchanged.
- Required source shape: the target should keep its current `PACKET_TRANSFORM_LUT_ENTRY(n)` macro, `int g_packetXorAlternateSize = 9;`, `static int s_packetTransformReserved = 0;`, exact `unsigned int g_packetTransformLut[256]` initializer entries from `PACKET_TRANSFORM_LUT_ENTRY(0x00)` through `PACKET_TRANSFORM_LUT_ENTRY(0xff)`, and final `#undef`.
- The target currently contains that exact expanded initializer list from `0x00` through `0xff`; no C++ edit is needed in this report-only redo.
- This source shape preserves every byte in the range, keeps the no-xref dword explicit, and avoids stale generated `std::uint8_t[]`/byte-array output.
- Broader PacketTransform helper pages should remain no-code/blank until raw `0x00575b90` liveness and final helper prototypes are resolved.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md`.
- Metadata: keep `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000TG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TG`, and blank emitter position unchanged.
- C++: keep the existing first-draft C++ block unchanged.
- Add a dated `2026-06-23 B004 MCP redo` evidence section or equivalent detail preserving:
  - Endpoint `http://127.0.0.1:13337/mcp`, session `b880584f`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path from MCP health, and PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - MCP xrefs: 11 to `0x0066fe50`, zero to `0x0066fe54`, two to `0x0066fe58`, one boundary xref to `0x00670258`.
  - MCP value/byte samples proving `9`, reserved zero, repeated-byte dwords, and the boundary pointer after `0xffffffff`.
  - Function evidence for raw `0x00575b90`, `sub_575CB0`, `sub_575E60` command `13`, raw `0x00576fee`, `sub_578B20`, `sub_578C40`, and `sub_578E00`.
  - PE section map and route scan evidence, including zero direct route hits for `0x0066fe54`.
- Replace stale target wording that says the B004 pass had live IDA/MCP unavailable. The correct cap rationale is now original source spelling/private-section uncertainty, no-xref reserved-dword intent, IDB type/name cleanup still pending, raw/helper prototype uncertainty, and not being a final-audit pass.
- Preserve rejected alternatives and negative evidence: generated/simroot byte-array output, IDA undersized `int[130]` typing, Socket as consumer/writer but rejected owner, PacketBuffer rejection, raw data island/no-owner rejection, and no behavior claimed for `0x0066fe54`.

## Recommended Support Doc Changes

- `by-global/PacketTransformGlobals.md`: replace the stale 2026-06-23 B004 live-IDA-unavailable sentence with the current MCP redo evidence. Keep score `86/88`, owner/emitter [UID:0000M9], and blank global-parent C++ unchanged. Preserve the existing source-ready declaration decision, dword LUT type, generated-output caveats, Socket writer/consumer context, and helper-prototype caveats.
- `by-file/PacketTransform.md`: no required edit if supervisor accepts target/global-only synchronization. The page already records the resolved `g_packetTransformLut` capacity, PacketTransform placement, generated-output caveats, and original-file/private Socket-section open question at same-or-greater detail. Optional support sync could add one sentence that the B004 MCP redo on session `b880584f` reconfirmed the initialized LUT declaration and did not change score/source placement.
- `by-item/PacketTransformHelpers.md`: no required edit. It already preserves the helper-level no-code decision, raw `0x00575b90` liveness blocker, unresolved helper prototypes, and the fact that [UID:000286] removes only the initialized LUT declaration blocker.
- `by-memory/-coverage-report.md`: supervisor-owned replacement row supplied below; B004 must not edit it directly.

## Score And Metadata Recommendation

- Current score/metadata: target `88/89`; `CANONICAL_OWNER:0000TG`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000TG`; blank emitter position; first-draft C++ present.
- Recommended score/metadata: keep `88/89` and all routing/C++ metadata unchanged.
- Reason not higher: live MCP now removes the earlier outage caveat, but `90+` is still too high because the original symbol spellings are inferred, `0x0066fe54` remains no-xref reserved storage with unrecovered intent, IDA DB type/name cleanup is still pending, exact original source file versus private Socket section is unresolved, and broader PacketTransform helper prototypes/raw helper liveness remain open.
- Reason not lower: live MCP and PE evidence confirm the prior implementation's range, bytes, route, dword LUT type, boundary, and C++ declaration shape.

## Open Questions With Attempted Resolution

- Exact LUT type/capacity: resolved as `unsigned int[256]`, `0x400` / decimal `1024` bytes, 256 repeated-byte dword entries.
- Reserved dword meaning: best current source-facing interpretation remains private `static int s_packetTransformReserved = 0`; no active behavior should be claimed.
- PacketTransform versus Socket placement: resolved for reconstruction routing as PacketTransform; original file/private Socket section remains an open source-history caveat.
- First-draft C++ readiness: resolved for this data range; existing code should remain.
- Remaining unresolved and score impact: original symbol spellings, exact original source file/private section, IDA database type/name cleanup, raw helper liveness, and final helper prototypes keep the target below `90+`/final-audit.

## Exact Supervisor-Owned Coverage Text

- File/placement: `by-memory/-coverage-report.md`, replace the current [UID:000286] row under the `0x0066d000-0x0069d000` data-section nesting.
- Exact replacement text:

```text
    - [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) 0x0066fe50-0x00670258 | packet transform globals | PacketTransformAlternateSizeAndLut : reconstructable : 88% : strong : PacketTransform-owned initialized global-data block for inferred `int g_packetXorAlternateSize = 9`, private zero reserved dword at `0x0066fe54`, and 256-entry `unsigned int g_packetTransformLut[256]` repeated-byte dword LUT; B004 MCP-backed redo on 2026-06-23 using IDA MCP session `b880584f` reconfirms the `.data` range bytes, 11 xrefs/direct PE VA hits to `0x0066fe50`, zero MCP/PE route hits to the reserved `0x0066fe54` dword, dword writer routes to `0x0066fe58`, `XorTransformBuffer` dword key reads, and the [UID:000287][0x00670258-0x00670260.SocketConnectionStringParsePointers](by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md) boundary; keep owner/emitter [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md), keep first-draft C++ declarations, reject generated byte-array/undersized IDA typing, and cap confidence below final-audit because original spellings, reserved-dword intent, source-file/private-section placement, and broader helper prototypes remain unresolved.
```

- Reason B agent must not apply it directly: active B-agent report-only rules and the supervisor-owned coverage-report rule reserve `-coverage-report.md` edits for the supervisor.

## Validator Results

- Report-only redo validators: none; no by-* docs were edited during the MCP-backed report pass.
- Implementation callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits:
  - `python .\tools\validator.py --mode file --file by-memory\0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md --apply --queue-timeout 240`: exit code `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-global\PacketTransformGlobals.md --apply --queue-timeout 240`: exit code `0`, `ok: 1`; validator also inserted the missing `[UID:000286]` link on the global page.
- Optional support validators not run: `by-file/PacketTransform.md` and `by-item/PacketTransformHelpers.md` were not edited because stale offline-only/MCP-outage wording was not present there and existing support detail already met the accepted report direction.

## Changed Files

- Modified by B004 implementation callback:
  - `by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md`
  - `by-global/PacketTransformGlobals.md`
  - `tools/leaser/Agents/Agent-B004/research/000286-PacketTransformAlternateSizeAndLut-source-quality.md`
- Optional support docs checked but not modified: `by-file/PacketTransform.md`, `by-item/PacketTransformHelpers.md`.
- Validator-applied side effects from required `--apply` runs: `project-level/-auto-completion-stats.md` and `tools/validator.ini` were updated by the validator, not manually edited as evidence/support docs.
- Created: none.
- Modified `-coverage-report.md` files: none.
- IDA DB/tool state edits: none.

## Confidence

- Recommendation confidence: strong for keeping owner/emitter, range, first-draft C++ declarations, and support-document direction.
- Score confidence: medium-high for keeping `88/89`.
- Main remaining uncertainty: source spellings, reserved dword intent, exact original source layout, and helper prototypes.
- Blockers: none for this implementation callback. The broad report-pass `insn_query` timeout was avoided by targeted MCP evidence and confirmed live server health; it is not used as a negative proof.

## Follow-Up Actions

- Supervisor: apply the exact [UID:000286] `by-memory/-coverage-report.md` replacement row if desired; B004 left coverage files untouched as required.
- No B004 implementation blockers remain for the accepted target/global evidence sync.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this MCP-backed redo and issued the implementation callback for target/global evidence sync.
- [x] Target/support docs to update identified. Proof: callback required target `by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md` and support `by-global/PacketTransformGlobals.md`; optional/no-op checks were `by-file/PacketTransform.md` and `by-item/PacketTransformHelpers.md`.
- [x] Current target state and actual evidence checked recorded. Proof: report records target already `88/89` with C++ present and adds live MCP session `b880584f`, tool facts, xrefs, bytes, function-route evidence, and PE route-scan supplement.
- [x] Metadata/score changes to apply documented. Proof: target remains `88/89`; no owner/emitter/reconstructable/C++ metadata change was recommended or applied.
- [x] Owner/emitter/reconstructable changes documented. Proof: target remains `CANONICAL_OWNER:0000TG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TG`, and blank emitter position.
- [x] Split/rename/new-child changes documented. Proof: no split/rename/new child; exact half-open range `0x0066fe50-0x00670258` and [UID:000287] boundary retained.
- [x] Source-placement/range/padding/reclassification and IDA DB action documented. Proof: PacketTransform placement retained; `0x0066fe54` remains private reserved source dword; no IDA DB edits were recommended or performed.
- [x] First-draft C++ decision documented. Proof: existing source-shaped declaration block retained unchanged; generated/IDA-shaped byte data remains rejected.
- [x] Exact target/support doc facts to incorporate listed. Proof: report sections list MCP endpoint/session/provenance, xrefs, value samples, raw bytes, command-13 writer, transform consumers, `XorTransformBuffer` dword reads, PE hash/section map/route scan, rejected alternatives, generated-output caveats, and revised score-cap rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence documented. Proof: report supersedes prior live-IDA-outage wording and preserves generated byte-array and undersized IDA typing rejection, Socket consumer-only ownership rejection, PacketBuffer rejection, raw data-island rejection, no xrefs/direct routes to `0x0066fe54`, and inferred original names.
- [x] Wave2/Wave3 handling documented. Proof: stale generated/simroot byte-array/global declarations are rejected as non-authoritative generated-output caveats; no current Wave2/Wave3 instruction changed scope.
- [x] Open questions documented as evidence-backed unresolved. Proof: original symbol spelling, reserved-dword original intent, exact original source file/private section, IDA DB cleanup, raw helper liveness, and helper prototypes remain score caps.
- [x] Validators to run after accepted implementation identified. Proof: exact scoped validator commands are recorded above.
- [x] Supervisor-owned coverage-report/tracker text supplied. Proof: exact [UID:000286] replacement row remains in `Exact Supervisor-Owned Coverage Text`; B004 did not edit any `-coverage-report.md`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: implementation callback accepted `tools/leaser/Agents/Agent-B004/research/000286-PacketTransformAlternateSizeAndLut-source-quality.md` and required target/global evidence sync only.
- [x] Leases taken and released for edited by-* docs. Proof: `python .\tools\leaser\leaser.py B004 lease by-memory\0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md by-global\PacketTransformGlobals.md` succeeded for both paths; `python .\tools\leaser\leaser.py B004 unlease ...` returned `Success` for both; `tools/leaser/Agents/current_leases.md` reports `No active leases.`
- [x] Target doc details incorporated at report-level detail. Proof: `by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md` now records the `b880584f` MCP endpoint/session/IDB/health facts, PE SHA-256 and section map, exact `.data` bytes/range, xrefs/direct PE route hits to `0x0066fe50`, zero MCP/PE route hits to `0x0066fe54`, dword writer and consumer routes to `0x0066fe58`, value samples, [UID:000287] boundary, generated-output rejections, owner rejections, and current score-cap rationale.
- [x] Required support doc details incorporated at report-level detail. Proof: `by-global/PacketTransformGlobals.md` now records the `b880584f` MCP redo, PE provenance, `.data` placement, alternate-size xrefs/direct hits, reserved-dword negative evidence, LUT writer/consumer proof, boundary/value samples, PacketTransform owner/emitter retention, and rejected Socket/PacketBuffer/no-owner/generated-type alternatives.
- [x] Optional support docs checked and left unchanged. Proof: `rg` over `by-file/PacketTransform.md` and `by-item/PacketTransformHelpers.md` found no stale live-IDA-unavailable/offline-only wording requiring correction; existing content already preserved PacketTransform placement, generated-output caveats, no-code/helper blockers, and original file/private-section uncertainty.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied. Proof: target remains `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000TG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TG`, blank emitter position, exact range `0x0066fe50-0x00670258`, and existing first-draft C++ declarations unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/global now say the earlier live-IDA-outage wording is superseded; generated byte-array and undersized IDA typing, Socket consumer-only ownership, PacketBuffer, raw data island/no-owner, and no behavior for `0x0066fe54` remain rejected/preserved.
- [x] Open questions documented with evidence-backed unresolved rationale. Proof: confidence cap now cites inferred original spellings, no-route reserved-dword intent, source-file/private-section placement, IDA type/name cleanup, and broader helper prototype/raw-helper uncertainty rather than MCP outage.
- [x] Validators run and results recorded. Proof: target validator exit code `0`, `ok: 1`; global validator exit code `0`, `ok: 1`, plus `uid_link_insert 000286` on the global page.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged. Proof: exact replacement row remains above; no `-coverage-report.md` file was edited.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; all accepted target/global implementation items were applied. Coverage application remains supervisor-owned by rule, not a B004 blocker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/000286-PacketTransformAlternateSizeAndLut-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"000286"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
