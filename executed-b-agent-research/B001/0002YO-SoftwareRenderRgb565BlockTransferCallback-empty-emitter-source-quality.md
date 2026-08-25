# UID0002YO SoftwareRenderRgb565BlockTransferCallback Empty-Emitter Source Quality
** TARGET-REPORT-UID:0002YO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current supervisor receipts record Gate 1, Gate 2A, and Gate 2B as passed for [UID:0002YO]. The dated post-callback documentation state remains `94/95` with `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OC` preserved.
- The target `RECONSTRUCTION_CPP CODE` channel now contains the exact file-local RGB565 transfer callback from Section 22. The target H channel remains deliberately blank because the shared `SurfaceTransferPixelsProc` typedef and `g_pfnTransferPixels` extern already belong to [UID:0000TN].
- Treat the third argument as one signed ordinal `fadeStep`, not 25 unrelated named render modes. Clamp it to `0..24`; step 0 preserves pixels, steps 1 through 23 apply the exact RGB565 attenuation sequence, and step 24 clears `pixelCount * 2` bytes.
- Preserve the exact half-open body `[0x004c4790,0x004c5fde)`. Keep `[0x004c5fde,0x004c5fe0)` alignment, `[0x004c5fe0,0x004c6044)` compiler jump-table data, and `[0x004c6044,0x004c6050)` padding outside the source body.
- The target and nine affected Surface support pages now carry the accepted detail. The callback has no internal geometric clipping: the two ScreenPane consumers already supply the selected mutable 16-bit buffer and exact pixel count.
- Supervisor Gate 2B applied and verified the target function name, exact source ABI/frame, and one repeatable semantic comment. It separately verified no change to `jpt_4C47BD`, `SurfaceTransferPixelsProc`, `g_pfnTransferPixels`, storage, xrefs, comments, and surrounding boundaries.
- Current supervisor readbacks also verify all ten Section 28 coverage rows and the generated Surface CPP/H state. All 44 claims are incorporated or already present and independently verified.
- Report lifecycle execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Supporting Research

This report closes the target's previously stated blockers rather than carrying them forward:

- The decompiler-shaped `__m128i *` return is rejected by both live consumers, which ignore EAX, and by step 24, whose tail jump merely leaks `_memset`'s implementation return. The source callback is `void`.
- `arg_0` is mutable `unsigned short *pixels`, `arg_4` is `unsigned int pixelCount`, and `arg_8` is signed `int fadeStep`.
- The 25 branches are a monotone fade continuum. `ScreenPane::m_fadeStep` is a typed `int` at `+0x5ac`; `ScreenPane_BeginFadeIn` writes 24 and `ScreenPane_BeginFadeOut` writes 0.
- The compiler's SIMD blocks, packed-dword remainder loops, scalar odd tails, aligned literals, and local jump table are generated forms of ordinary scalar RGB565 expressions. They are not separate handwritten helpers or tables.
- Source ownership is `NexusTK/render/Surface.cpp`, not ScreenPane and not SoftwareBlend16. ScreenPane consumes the callback; SoftwareBlend16 is arithmetic context; Surface initializes and owns the provider family.

Evidence gathered on 2026-08-14 used disk-backed sessions `supervisor-uid0000MQ-postsave-retry-20260814` and `supervisor-uid0000KZ-rollback2-20260814`. Those session identities and their results are dated, non-authoritative evidence snapshots only. Both then resolved to database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, NexusTK.exe MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`; then-health was `status:ok`, Hex-Rays and strings ready, and `auto_analysis_ready:false` was contextual because all bounded IDB-backed queries succeeded. The snapshots reconfirmed the exact five-row target frame, blank target/slot comments, 100-byte `jpt_4C47BD` item, twelve-byte padding item, `BlendRgb565Pixel` successor type, and the slot's `SurfaceTransferPixelsProc` type projection. The final supervisor Gate 2B authority, applied state, save identity, and post-save readback are recorded in `Current Target State` and Section 21 without replacing this literal prestate evidence.

## Target

- Primary UID: `0002YO`.
- Additional target UIDs: none.
- Path: `by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md`.
- Dated 2026-08-14 assignment-queue snapshot: explicit by-memory priority over the then-generated `Not-Covered Files - Reconstructable` row, tracker `87/90` and combined `88.5`; a same-day post-callback ordinary-target snapshot records `94/95`. Queue and tracker identities are historical context, not permanent assignment state.
- Historical repair-scope receipt: the 2026-08-14 instruction limited this revision to the existing report and its inert removed-prose companion. Report lifecycle and any later assignment state remain external and supervisor-owned.
- Exact source body: `[0x004c4790,0x004c5fde)`, 6222 bytes.
- Dated 2026-08-14 IDA evidence snapshot: `sub_4C4790`, 1816 instructions, 214 basic blocks, cyclomatic complexity 142.
- Implemented source identity: `static void __cdecl SoftwareRenderRgb565BlockTransferCallback(unsigned short *pixels, unsigned int pixelCount, int fadeStep)`.
- Source destination: `NexusTK/render/Surface.cpp` through owner/emitter [UID:0000OC].
- No additional report target UID is declared. Support UIDs remain independently owned support destinations.

## Current Target State

- Dated 2026-08-14 post-callback metadata snapshot: `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`.
- Formal CPP contains the complete accepted file-local callback. Formal H remains blank by the accepted shared-header/file-local-provider disposition.
- Current supervisor generated readback verifies C0002YO-043 as `ALREADY_PRESENT_VERIFIED`: `auto-generated/NexusTK/render/Surface.cpp` is SHA256 `EAC64DA9AF8C43CB405637AB03E8A051395CC4C44D05EEB51C34B6CECB01E415`, 77,412 bytes and 2,307 lines; `Surface.h` is SHA256 `B45708EB0D7EF5267119C8852A47C2C033A20F0D892694F4B0225BD420E82693`, 3,085 bytes and 102 lines. Both carry command `000000023596` and timestamp `2026-08-14T17:14:43-04:00`; CPP has one target body and no target empty marker, while H has no duplicate declaration.
- The dated 2026-08-14 ordinary-document snapshot showed the target summary/status, exact behavior, history, score rationale, owner/emitter route, and formal source synchronized after physical reread.
- Dated 2026-08-14 initial IDA prestate: type `__m128i *__cdecl(__m128i *, unsigned int, int)` with stack rows `__saved_registers@+0x4/_DWORD`, `__return_address@+0x8/_UNKNOWN *`, `arg_0@+0xc/_DWORD`, `arg_4@+0x10/_DWORD`, and `arg_8@+0x14/_DWORD`; all four target comment channels were absent. This literal prestate remains historical evidence.
- Final supervisor Gate 2B readback passed at `0x004c4790`: name `SoftwareRenderRgb565BlockTransferCallback`; normalized type `void __cdecl(unsigned __int16 *pixels, unsigned int pixelCount, int fadeStep)`; complete frame `__saved_registers,+0x4,0x4,_DWORD`, `__return_address,+0x8,0x4,_UNKNOWN *`, `pixels,+0xc,0x4,unsigned __int16 *`, `pixelCount,+0x10,0x4,unsigned int`, `fadeStep,+0x14,0x4,int`; zero locals; address-repeatable comment `RGB565 in-place ScreenPane fade transfer: clamps fadeStep to 0..24, preserves step 0, applies exact packed attenuation to pixelCount pixels, and clears step 24 to black.`; address regular, function regular, and function repeatable remain blank; function range and inbound refs `0x005587e7` and `0x00558f0a` remain unchanged.
- Gate 2B no-change readback also passed for I04 and I05. `jpt_4C47BD` remains a 100-byte data item at `[0x004c5fe0,0x004c6044)` with SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`, regular comment `jump table for switch statement`, blank repeatable comment, and one inbound ref at `0x004c47bd`. `g_pfnTransferPixels` remains at `0x0069b40c` with type `SurfaceTransferPixelsProc`, four zero bytes, blank address comments, and five unchanged inbound refs; its one-byte physical item-head projection remains a protected caveat rather than authority for storage width.
- Supervisor backup/save receipt: canonical prestate SHA256 `D9948E150E83CAD90A9E689D162AFE654A5287344BA1DABF6DD350128926FF98`, 143,207,852 bytes; verified backup `E:\NTK\Resources\NexusTK\supervisor-backups\NexusTK.exe.pre-0002YO-20260814T172748243.i64`; saved canonical SHA256 `F89D5FC89C7FC3AF6A44581AE9DF0990414B88A35C3554AD10C36F6B9341BCE0`, 143,207,861 bytes, last-write `2026-08-14T17:28:43.4566027-04:00`; post-save readback passed.
- Supervisor coverage readback verifies all ten current Section 28 rows, including the two no-replacement rows, as exact. C0002YO-026 through C0002YO-032 and C0002YO-044 are `ALREADY_PRESENT_VERIFIED`; scoped commands `000000023597` through `000000023600` all exited 0 with `ok:1`.
- Dated 2026-08-14 post-correction target-document receipt: SHA256 `45229C261E8469CA5A8031A3DC56F82EEB8E930CDE5064C41F0FA02F95601CA9`, 24,413 bytes, and 363 physical lines after scoped validator command `000000023589` and physical reread. The earlier command `000000023418` receipt remains historical evidence in `Evidence Checked`; neither identity is permanent current state.
- Dated 2026-08-14 Gate 2A C012 support-document receipt: UID0002V6 changed from SHA256 `3EE4219203CEF32EFF54B04855A9A85037EFC0909998101726FB7DB513B99B76`, 31,369 bytes, and 247 lines to SHA256 `0CC9026CA9CE41D3EDA6A04A3E7D663ADDE97D4D4022A18C6FC0FC3E457C1589`, 31,623 bytes, and 247 lines after scoped validator command `000000023596` and physical reread. The correction removes a nonexistent separate mode argument and row/stride traversal while preserving the constant pool's valid research and metadata; these identities are dated receipts rather than permanent current state.

## Executive Recommendation

Implement one exact source callback, retain its established Surface route, and synchronize support pages that still describe UID0002YO as incomplete. The source should expose the semantic RGB565 fade arithmetic and let the compiler recover its own SIMD scheduling. It must not reproduce `__m128i`, `loc_*`, `jpt_*`, raw `sub_*`, or literal-pool storage as source artifacts.

The body can be expressed with one C++03-compatible expansion macro over packed pairs plus one odd tail. This is behaviorally exact for every pixel count, including zero and odd counts, and is a credible mid-2000s source shape for the compiler output. Step 24 uses `memset(pixels, 0, pixelCount * sizeof(*pixels))`; no integer widening beyond the observed 32-bit byte-count arithmetic is introduced.

## Supervisor Active Recheck

The prestate rows in this section remain dated 2026-08-14 evidence snapshots. Final supervisor receipts now establish Gate 2B, current coverage, and coherent generated verification as passed.

| Check | Exact result |
| --- | --- |
| Historical assignment context | A 2026-08-14 instruction required same-report repair to the literal 33-section Gate 1 standard and limited that revision to report artifacts; this row does not assert a permanent active assignment |
| Split disposition | No split repair is required; the one source-bearing function body and all compiler-covered alignment/table/padding material are exhaustively inventoried below |
| Dated disk-backed session snapshots | 2026-08-14 evidence used `supervisor-uid0000MQ-postsave-retry-20260814`, `supervisor-uid0000KZ-rollback2-20260814`, and `supervisor-uid0000IW-recovery-20260814`; each then resolved to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; none is present-tense authority |
| Dated health snapshot | `status:ok`; Hex-Rays ready; strings ready; required bounded queries succeeded on 2026-08-14 |
| Dated prestate function identity | `sub_4C4790`, `[0x004c4790,0x004c5fde)`, size `0x184e`, 1816 instructions, 214 blocks |
| Entry clamp | signed negative becomes 0 via `test/cmovns`; values greater than 24 become 24 via `cmp/cmovg` |
| Switch | 25 entries, ordinal 0 through 24, local table at `[0x004c5fe0,0x004c6044)` |
| Incoming target refs | data refs `0x005587e7` in `InitializeSurfaceRenderCallbacks` and `0x00558f0a` in `sub_558840`; no ordinary code caller |
| Shared slot | `0x0069b40c`, then-recorded authoritative name `g_pfnTransferPixels`, then-recorded type `SurfaceTransferPixelsProc`, five refs |
| Consumers | `0x005571e6` in `ScreenPane_RenderPresentation`; `0x005584a4` in `sub_5583A0`; each pushes pixels, count, fade step and ignores return |
| Fade field | then-recorded `ScreenPane` UDT size `0x5b4`; `int m_fadeStep` at `+0x5ac` |
| Endpoint writes | `ScreenPane_BeginFadeIn` stores 24 at `+0x5ac`; `ScreenPane_BeginFadeOut` stores 0 |
| Clear | case 24 at `0x004c5fc5` computes `pixelCount * 2`, value 0, and tail-jumps to `_memset` at `0x004c5fd9` |
| Boundaries | body hash and exact alignment/table/padding hashes in Sections 13 and 19; successor `BlendRgb565Pixel` starts at `0x004c6050` |
| Final Gate 2B result | Passed: I01/C021, I02/C022, and I03/C023 are `APPLIED_VERIFIED`; I04/C024 and I05/C025 are `NO_CHANGE_VERIFIED`; post-save readback passed |
| Canonical save receipt | Prestate SHA256 `D9948E150E83CAD90A9E689D162AFE654A5287344BA1DABF6DD350128926FF98`, 143,207,852 bytes; saved SHA256 `F89D5FC89C7FC3AF6A44581AE9DF0990414B88A35C3554AD10C36F6B9341BCE0`, 143,207,861 bytes; last-write `2026-08-14T17:28:43.4566027-04:00` |
| Final coverage result | All ten current Section 28 rows match exactly; C026-C032 and C044 are `ALREADY_PRESENT_VERIFIED`; commands `000000023597`-`000000023600` passed |
| Final generated result | C043 is `ALREADY_PRESENT_VERIFIED` from Surface.cpp/Surface.h command `000000023596` readback with one target body, no empty marker, and no duplicate H declaration |

## Inference Research Guidance Check

- Project purpose and output standard applied: exact runtime behavior is primary, while source shape must look like plausible human-written late-1990s/mid-2000s C++, not decompiler output.
- Heuristic work was not limited to naming. ABI, return semantics, ordinal meaning, loop structure, clipping disposition, constant-source disposition, source linkage, CPP/H split, owner/emitter route, and score blockers were all reanalyzed.
- Unknown original lexical spellings were resolved with the current project-wide Surface conventions rather than left as `sub_4C4790`, `arg_*`, or `dword_69B40C`.
- Consistency is subordinate to exact behavior and human-source plausibility. Here the established names `SoftwareRenderRgb565...Callback`, `SurfaceTransferPixelsProc`, `g_pfnTransferPixels`, and `m_fadeStep` also provide consistent evidence.
- Wave2/Wave3 references, if encountered in historical material, are stale and provide no authority for this report.
- Third-party import handling is not applicable. This is project-owned NexusTK render code, not source under `third_party_embeds/`.

## Heuristic / Inference Reanalysis And Validation

### ABI and return

The physical call sequence is cdecl: each consumer pushes three 4-byte arguments and performs caller cleanup `add esp, 0xc`. The first argument is the current 16-bit surface pixel pointer; the second is width-times-height or the active-surface pixel count; the third is `m_fadeStep`. Both consumers ignore EAX. All ordinary cases return without establishing a meaningful pointer, while case 24 tail-jumps to `_memset`; therefore the decompiler's pointer return is path residue, not a source contract.

### Fade semantics

The signed clamp, one `ScreenPane` field, transition endpoints 24 and 0, ordered bit-shift deltas, full-intensity no-op at 0, and black clear at 24 jointly reject 25 independently named effects. The most probable source was one numeric fade progression. `fadeStep` is stronger than `mode` because the established UDT field is already `m_fadeStep` and both transition helpers assign the endpoints.

### Loop and stride semantics

- `pixelCount >> 1` determines packed 32-bit pair count.
- Most cases vectorize 16 pairs per 64-byte iteration, then process remaining dword pairs, then test `pixelCount & 1` for one 16-bit tail.
- Case 9 uses a smaller four-pair/16-byte SIMD chunk but the same pair and scalar expressions; source need not preserve the compiler's scheduling choice.
- Every ordinary transform advances exactly two bytes per pixel. There is no separate row stride argument and no internal rectangle/clipping operation.
- A zero `pixelCount` performs no write in all cases. A negative fade step takes case 0; a value above 24 takes case 24.

### Exact RGB565 formula continuum

Let `s1=(value>>4)&0x0841`, `s2=(value>>3)&0x18c3`, `s4=(value>>2)&0x39c7`, and `s8=(value>>1)&0x7bcf` per 16-bit pixel. Packed-dword masks repeat the same halfword in both halves.

| Step | Jump target | Exact per-pixel result |
| ---: | --- | --- |
| 0 | `0x004c558a` | `value` / no write |
| 1 | `0x004c47c4` | `value - s1` |
| 2 | `0x004c489a` | `value + s1 - s2` |
| 3 | `0x004c49d4` | `value - s2` |
| 4 | `0x004c4aaa` | `value - s1 - s2` |
| 5 | `0x004c4be4` | `value + s1 - s4` |
| 6 | `0x004c4d24` | `value - s4` |
| 7 | `0x004c4dfa` | `value - s1 - s4` |
| 8 | `0x004c4f34` | `value - s2 - s4` |
| 9 | `0x004c5059` | `value - s1 - s2 - s4` |
| 10 | `0x004c514e` | `value + s1 - 2*s4` |
| 11 | `0x004c5298` | `value + s1 - s8` |
| 12 | `0x004c53d2` | `s1 + s8` |
| 13 | `0x004c54ea` | `s8`; optimized as `(value & 0xf79e) >> 1` |
| 14 | `0x004c558f` | `s8 - s1` |
| 15 | `0x004c569f` | `2*s4 - s1` |
| 16 | `0x004c57c5` | `s1 + s2 + s4` |
| 17 | `0x004c5946` | `s2 + s4` |
| 18 | `0x004c5a5c` | `s1 + s4` |
| 19 | `0x004c5b6e` | `s4`; optimized as `(value & 0xe71c) >> 2` |
| 20 | `0x004c5c25` | `s4 - s1` |
| 21 | `0x004c5d3c` | `s1 + s2` |
| 22 | `0x004c5e4e` | `s2`; optimized as `(value & 0xc618) >> 3` |
| 23 | `0x004c5f05` | `s1`; optimized as `(value & 0x8410) >> 4` |
| 24 | `0x004c5fc5` | zero `pixelCount * 2` bytes |

### Constants and compiler materialization

The aligned splats at `0x0061aa30` through `0x0061aaa0` encode RGB565 equal-channel levels 1, 3, 7, 15, 16, 24, 28, and 30. Direct references from this target are exact and internal to the case bodies. There is no base-address lookup, index, sequential walker, mutable alias, or separately reusable table API. The source expressions in Section 22 cover these constants; no standalone data object should be emitted.

## Evidence Standards Used

- Direct live IDA facts outrank decompiler guesses and stale prose.
- ABI conclusions require both call-site stack behavior and return-use analysis.
- Source names require semantic role, established project convention, and collision checks; exact original spelling is not pretended proven.
- Source placement requires provider registration, sibling-family placement, and owner/emitter consistency, not caller proximity.
- Compiler-generated data is covered by source expressions only when xrefs and access topology show no independent runtime identity.
- Scores reflect resolved behavior, range, ABI, ownership, source channel, and exact formal code; IDA mutation itself is not required for documentation/source confidence.

## Evidence Checked

- Dated 2026-08-14 snapshots of the target, aggregate, Surface file, constant pool, semantic global, physical callback table, initializer, two consumer, and ScreenPane docs.
- Dated 2026-08-14 read-only generated snapshots of `NexusTK/render/Surface.cpp` and `Surface.h`.
- Dated 2026-08-14 manual-coverage row snapshots for every target/support page whose description was stale under this result.
- Dated 2026-08-14 MCP evidence from `server_health`, `entity_query`, `type_inspect`, `stack_frame`, `get_comments`, `get_bytes`, `xref_query`, `disasm`, function/CFG analysis, constant xrefs, initializer refs, consumer call sequences, transition endpoint functions, and boundary items.
- Existing accepted UID0002YJ report only as a structural/source-family control. UID0002YO formulas were independently checked against its own case bodies and constants.
- Dated 2026-08-14 proposed-name collision snapshot: no function named `SoftwareRenderRgb565BlockTransferCallback` was returned.
- A dated 2026-08-14 B001 read-only snapshot used session `supervisor-uid0000IW-recovery-20260814`: then-health `status:ok`, exact IDB path, Hex-Rays/strings ready, `auto_analysis_ready:false` contextual only, and bounded function/profile/frame/comment/item/xref/type/byte queries all succeeded. It reconfirmed the raw name/prototype, five stack rows, blank target comments, two target refs, five slot refs, 100-byte jump table, twelve-byte padding, successor, shared type/global, and `ScreenPane::m_fadeStep +0x5ac`. The session identity is non-authoritative historical evidence; the supervisor must dynamically re-establish Gate 2B authority with fresh health/session, canonical IDB identity, and bounded target queries.
- A dated 2026-08-14 Gate 2B prestate repair used read-only session `supervisor-uid0000KZ-gate2b-20260814`; then-health was `status:ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, Hex-Rays/strings ready, and bounded raw-byte reads succeeded. MCP returned exactly 6,222 bytes for `[0x004c4790,0x004c5fde)` and 100 bytes for `[0x004c5fe0,0x004c6044)`. Direct hashing of those returned arrays and an independent .NET SHA256 check at PE file offsets `0xC3B90` and `0xC53E0` agreed on body SHA256 `32E806F7A4558FE114ECFF11ABFDF067ECFEAA5EEC4A27055CDF3A08908E7327` and jump-table SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`. This session identity is a non-authoritative dated snapshot; Gate 2B remains paused for fresh Gate 1 and Gate 2A on the repaired artifact.
- Matching-report search terms were `0002YO`, `0x004c4790`, `sub_4C4790`, `SoftwareRenderRgb565BlockTransferCallback`, `SoftwareRenderRgb565Callbacks`, and `SurfaceTransferPixelsProc` across active, archived, and executed B-report folders. The only target-specific report match was this report; the older UID00016L aggregate report is support-family context, not competing target research.
- No required bounded MCP check failed in the dated 2026-08-14 evidence passes. A full 1,816-instruction transcript was intentionally not duplicated because the profile, boundaries, items, xrefs, types, stack frame, comments, and targeted raw bytes revalidated every recommendation-sensitive fact. The previously recorded body SHA256 `31549525D0CF2B313BA50ED66D415B6773FD4332452FF0DCD1FE1D13EED24080` and jump-table SHA256 `971C6E6B25A15DC7A8971528A669C1A59E685A9189DEF7DB879CA8BAFC7A01BD` were extraction errors corrected by the fresh raw-byte recomputation above, not evidence of changed binary content; the preserved per-case disassembly remains the behavior basis.

Historical pre-callback support-document receipts read on 2026-08-14; hashes, sizes, and line counts are dated observations rather than permanent current identities:

| Path | SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md` | `17FDC93B5559A59375FA6FF036887C3B5B8FF91F8A31AB4A4D1A5CBB6663C35A` | 50,980 / 294 |
| `by-file/Surface.md` | `C7E6AFD00B89B7C9D34E583B6560993DCB6D3F8A71C136F241D7034F7C495955` | 142,346 / 614 |
| `by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md` | `E75AC0911CFAC55A3077E04317B5B7129EC1E35DB8E0AC10A22E323DD17E2C18` | 29,375 / 237 |
| `by-global/SurfaceRenderCallbackTable.md` | `4776DB935D75F2C01AD673DE9CF81DDFEC4E3784AD776735E8DFCD34959CACD5` | 94,822 / 561 |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | `4E63568215B41E93F0D076B37DBB70DE4A22EC8D79E279C3FCEAFE98BC18199B` | 78,679 / 417 |
| `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md` | `CC7DC015E9A71BF88BE7BFD6566D74F00BD78C6A8F9E63B304F4BB15BD47785A` | 28,970 / 241 |
| `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md` | `94F34178F0FA81ACAEFC35F48AD6643D168C62042EBC0B6E97966DEC5C04167F` | 9,239 / 97 |
| `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md` | `79E75AF8A786849F34A9E7C87E9874108C2E26E60F51553422DAC2F642372ABA` | 20,652 / 169 |
| `by-class/ScreenPane.md` | `CA6F3C2CB4A5DA2EE00A987E168196BDBBE1DAD7CD3CDC0C40C1924B79146A97` | 69,528 / 441 |

Historical post-callback ordinary-document readback from 2026-08-14; the supervisor rereads current documents dynamically rather than treating these hashes as permanent authority:

| Path | SHA256 | Bytes / lines | Scoped validator |
| --- | --- | --- | --- |
| `by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md` | `A8224A965E7093CD3E4DA8E223D127431ED87981428F31E2D94388D3D9B31B62` | 22,856 / 357 | `000000023418`, `2026-08-14T04:23:38-04:00`, exit 0, `ok:1` |
| `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md` | `3760920140E6D223EE45B826F9E57D4427CE92FB346BAF4BAF7BE41255FF558A` | 53,365 / 308 | `000000023427`, `2026-08-14T04:25:34-04:00`, exit 0, `ok:1` |
| `by-file/Surface.md` | `5EFC71B47B170DB5ACB121BFB0BA53F217C37164C4F2C1720BF416F82B74E5D0` | 143,638 / 621 | `000000023430`, `2026-08-14T04:26:52-04:00`, exit 0, `ok:1` |
| `by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md` | `0CC9026CA9CE41D3EDA6A04A3E7D663ADDE97D4D4022A18C6FC0FC3E457C1589` | 31,623 / 247 | `000000023596`, `2026-08-14T17:14:43-04:00`, exit 0, `ok:1`; the earlier pre-correction receipt was SHA256 `3EE4219203CEF32EFF54B04855A9A85037EFC0909998101726FB7DB513B99B76` under command `000000023439` |
| `by-global/SurfaceRenderCallbackTable.md` | `9835A9E4F6BBF133191441DD709F8340A32873785EA575E93519D34F5F0C2FB3` | 96,342 / 567 | `000000023457`, `2026-08-14T04:31:14-04:00`, exit 0, `ok:1` |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | `320986D1D1A53D3B2E421405FF8731BB3A628F515223B8298EAAE40ED7851F47` | 79,973 / 423 | `000000023464`, `2026-08-14T04:33:00-04:00`, exit 0, `ok:1` |
| `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md` | `331C739B6CBB1478E52A1DB3AB8359BD4499CBEFE02B1FE64B9521001C587280` | 30,052 / 247 | `000000023469`, `2026-08-14T04:34:06-04:00`, exit 0, `ok:1` |
| `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md` | `F3BABA6DAAD2CC09EB18BDFE58FA1E2CB548F9E48440B2B29D4CFE3ACA3969C9` | 10,424 / 102 | `000000023472`, `2026-08-14T04:35:26-04:00`, exit 0, `ok:1` |
| `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md` | `26FFD36B1F26A5EBBE88FF4CFCEB51706E89A52D1AEF5CE373050BF3D8FCE97F` | 21,948 / 175 | `000000023474`, `2026-08-14T04:37:05-04:00`, exit 0, `ok:1` |
| `by-class/ScreenPane.md` | command-time post-validation `8934BC0D2C6E7635EEA86F97B7FE3A58D7685C4A7144BDF1A64E177733FEEBD6`; final concurrent reread `89A14DC1EB6CA33F0DD2670B0FB6002FF897CD23BDDF3A425F19444A279FF473` | command-time 70,745 / 446; final 71,385 / 463 | `000000023476`, `2026-08-14T04:38:18-04:00`, exit 0, `ok:1`; B003's later header-route closure is preserved and all UID0002YO content remains intact |

Dated Gate 2A C012 correction readback: UID0002V6 lines 118, 220, and 226 now state the three-argument slot contract (`pixels`, `pixelCount`, signed ordinal `fadeStep`), packed-pair/odd-tail linear in-place behavior, and no separate mode/source-row/destination-row/stride input. Scoped command `000000023596` returned exit 0 and `ok:1`; the physical reread produced SHA256 `0CC9026CA9CE41D3EDA6A04A3E7D663ADDE97D4D4022A18C6FC0FC3E457C1589`, 31,623 bytes, and 247 lines.

Dated Gate 2B prestate-repair target receipt: `by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md` at SHA256 `45229C261E8469CA5A8031A3DC56F82EEB8E930CDE5064C41F0FA02F95601CA9`, 24,413 bytes, and 363 lines after scoped validator command `000000023589` at `2026-08-14T16:21:56-04:00`, exit 0, `ok:1`.

Final supervisor receipts reconciled on 2026-08-14:

| Scope | Verified result |
| --- | --- |
| Gate 2B | I01-I03 applied and verified; I04-I05 no-change verified; collision-safe backup, canonical save, and post-save readback passed |
| Coverage | All ten current rows match Section 28 exactly; by-memory `000000023597` at `2026-08-14T17:30:42-04:00`, by-file `000000023598` at `2026-08-14T17:30:45-04:00`, by-global `000000023599` at `2026-08-14T17:30:48-04:00`, and by-class `000000023600` at `2026-08-14T17:31:01-04:00` each exited 0 with `ok:1` |
| Generated | C043 current Surface.cpp/Surface.h readback under command `000000023596` at `2026-08-14T17:14:43-04:00` passed with one target CPP body, no target empty marker, and no duplicate H declaration |

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | ---: | --- | --- | --- | --- |
| C0002YO-001 | 0002YO | Replace the stale below-85 summary/status with the source-ready exact RGB565 fade-transfer identity, range, ABI, 25-step behavior, and Surface route. | 98 | Dated 2026-08-14 target extent, entry clamp, callers, initializer refs, and pre-callback target text. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / metadata, Item Summary, Status | incorporate | applied |
| C0002YO-002 | 0002YO | Document the exact cdecl void ABI `unsigned short *pixels, unsigned int pixelCount, int fadeStep` and reject the decompiler pointer return. | 98 | Two caller stack sequences and ignored EAX; case-24 `_memset` tail jump. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / ABI and Evidence | incorporate | applied |
| C0002YO-003 | 0002YO | Incorporate all 25 exact RGB565 fade formulas, signed clamp, pair loop, odd tail, zero-count behavior, no internal clipping, and case-24 clear. | 97 | Independent per-case disassembly, jump table, constant xrefs, and ScreenPane endpoint writes. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Behavior and Formula Inventory | incorporate | applied |
| C0002YO-004 | 0002YO | Preserve body `[0x004c4790,0x004c5fde)` with corrected SHA256 `32E806F7A4558FE114ECFF11ABFDF067ECFEAA5EEC4A27055CDF3A08908E7327`, two-byte alignment, 25-entry jump table with corrected SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`, twelve-byte padding, and successor boundary without emitting compiler data. | 99 | Fresh canonical read-only MCP bytes and independent .NET SHA256; prior hash values corrected as extraction errors; exact item/xref inventory and `BlendRgb565Pixel` successor. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Range and Boundary Evidence | incorporate | applied |
| C0002YO-005 | 0002YO | Incorporate two target refs, five slot refs, two return-ignoring consumers, registration paths, `m_fadeStep +0x5ac`, and endpoint writers. | 98 | Dated 2026-08-14 xref queries, caller disassembly, ScreenPane type, and transition disassembly. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Xrefs, Callers, Fields | incorporate | applied |
| C0002YO-006 | 0002YO | Preserve owner/emitter UID0000OC and source placement in `NexusTK/render/Surface.cpp`; reject ScreenPane and SoftwareBlend16 ownership. | 97 | Provider family, initializer, semantic global, consumers, and sibling callback placement. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Ownership and Source Placement | incorporate | applied |
| C0002YO-007 | 0002YO | Insert the complete Section 22 file-local behaviorally exact RGB565 callback into formal CPP. | 96 | Exact case formulas, ABI, loop equivalence, source-family style, and pre-callback generated empty marker. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C0002YO-008 | 0002YO | Keep formal H blank because the provider is file-local and UID0000TN already owns the shared typedef and extern. | 98 | Existing Surface.h and UID0000TN formal H; provider registration and linkage. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / RECONSTRUCTION_H CODE | already-present | already-present |
| C0002YO-009 | 0002YO | Raise metadata from 87/90 to 94/95 while preserving canonical owner, reconstructable state, and emitter route. | 96 | All evidence-recorded blockers closed; exact formal source supplied; residual lexical/compiler-scheduling uncertainty. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / metadata and Score Rationale | incorporate | applied |
| C0002YO-010 | 00016L | Mark UID0002YO source-ready in the non-emitting RGB565 family inventory and remove its stale dedicated-pass blocker without changing aggregate route or score. | 97 | Exact child closure and dated 2026-08-14 pre-callback aggregate row. | by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md / Item Summary, inventory, split backlog | incorporate | applied |
| C0002YO-011 | 0000OC | Replace the stale no-active-marker target row and add exact source-ready slot-11 RGB565 closure while preserving Surface 90/89. | 97 | Pre-callback generated empty marker, initializer, source placement, and exact callback closure. | by-file/Surface.md / callback inventory and slot-11 source closure | incorporate | applied |
| C0002YO-012 | 0002V6 | Correct the UID0002YO constant-pool consumer closure to the exact slot-11 contract: only `pixels`, `pixelCount`, and signed ordinal `fadeStep`; linear in-place packed-pair/odd-tail traversal; no separate mode, source/destination row, or stride inputs; preserve compiler-covered no-table emission and 92/94. | 98 | UID0002YO ABI, caller-selected buffer, and exact packed-pair/odd-tail body; physically reread UID0002V6 lines 118, 220, and 226 after scoped validation. | by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md / consumer closure and score rationale | incorporate | applied |
| C0002YO-013 | 0000TN | Add exact RGB565 provider behavior to semantic slot 11 while preserving existing typedef/global formals and 94/95. | 98 | Dated 2026-08-14 typed-global snapshot, provider refs, consumers, and complete formulas. | by-global/SurfaceRenderCallbackTable.md / slot 11 behavior | incorporate | applied |
| C0002YO-014 | 0001PI | Add exact RGB565 provider behavior to physical slot 11 while preserving covered-by-only CPP, blank H, and 92/94. | 98 | Physical storage, five xrefs, paired providers, and complete formulas. | by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md / slot 11 liveness | incorporate | applied |
| C0002YO-015 | 00039V | Mark both slot-11 providers source-ready and add RGB565 endpoint/formula behavior without changing authoritative initializer CPP or 91/93. | 98 | Existing exact assignment body and dated 2026-08-14 target-ref snapshot. | by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md / slot 11 selection contract | incorporate | applied |
| C0002YO-016 | 00039P | Replace paired-provider-only wording with exact RGB565 0..24 behavior while preserving ScreenPane route, blank formal body, and 90/93. | 97 | Exact call arguments, ignored return, target formulas, and field type. | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md / slot-11 fade-transfer call | incorporate | applied |
| C0002YO-017 | 00039T | Add exact RGB565 provider behavior to the retained presentation helper dependency without changing its independent reachability/source-placement state or 86/88. | 96 | Exact call contract and target closure; helper's separate zero-inbound evidence. | by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md / direct block-transfer path | incorporate | applied |
| C0002YO-018 | 0000CB | Extend the existing `m_fadeStep` relation to both exact providers without changing class layout, formals, owner, or 93/94. | 98 | Dated 2026-08-14 UDT-member snapshot and endpoint/caller evidence. | by-class/ScreenPane.md / fade-transfer relation and field rationale | incorporate | applied |
| C0002YO-019 | 0002YO | Preserve corrected history and mark prior below-85, unresolved-mode, pointer-return, standalone-table, and no-active-marker assumptions as superseded with reasons. | 96 | Dated 2026-08-14 documentation, IDA, and generated-state snapshots. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Historical Assumptions and Changes | historicalize | applied |
| C0002YO-020 | 0000TN | Preserve existing `SurfaceTransferPixelsProc` and `g_pfnTransferPixels` CPP/H definitions exactly; do not duplicate or recreate them for UID0002YO. | 99 | Dated 2026-08-14 UID0000TN formal and generated Surface.cpp/Surface.h snapshots. | by-global/SurfaceRenderCallbackTable.md / formal CPP and H | already-present | already-present |
| C0002YO-021 | 0002YO | Supervisor Gate 2B applied and verified the rename from `sub_4C4790` to `SoftwareRenderRgb565BlockTransferCallback` with protected range/body/xrefs. | 97 | Final post-save name readback and preserved literal prestate in Section 21 I01. | IDA function 0x004c4790 / name | incorporate | APPLIED_VERIFIED |
| C0002YO-022 | 0002YO | Supervisor Gate 2B applied and verified the exact void cdecl mutable-pixel/count/fadeStep type, complete five-row frame, and zero locals. | 98 | Final post-save normalized type/frame readback and Section 21 I02. | IDA function 0x004c4790 / function type and stack frame | incorporate | APPLIED_VERIFIED |
| C0002YO-023 | 0002YO | Supervisor Gate 2B applied and verified only the exact repeatable function-entry semantic comment; the other three comment channels remain blank. | 96 | Final post-save four-channel comment readback and preserved literal prestate in Section 21 I03. | IDA function 0x004c4790 / repeatable address comment | incorporate | APPLIED_VERIFIED |
| C0002YO-024 | 0002YO | Supervisor Gate 2B verified no change to `jpt_4C47BD` at `[0x004c5fe0,0x004c6044)`, its regular comment, 25 entries, corrected SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`, and inbound ref. | 99 | Final no-change item/comment/xref readback plus canonical 100-byte hash. | IDA data 0x004c5fe0 / jump table | already-present | NO_CHANGE_VERIFIED |
| C0002YO-025 | 0000TN | Supervisor Gate 2B verified no change to `g_pfnTransferPixels` at 0x0069b40c, type `SurfaceTransferPixelsProc`, four zero bytes, five inbound refs, and blank address comments. | 99 | Final no-change global/type/byte/xref/comment readback with one-byte item-head projection caveat preserved. | IDA global 0x0069b40c / slot 11 | already-present | NO_CHANGE_VERIFIED |
| C0002YO-026 | 0002YO | Supervisor coverage readback verified the current 94-percent source-ready UID0002YO by-memory row exactly matches Section 28. | 99 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID0002YO row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-027 | 00016L | Supervisor coverage readback verified the current aggregate row includes UID0002YO among source-ready children and preserves 90 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID00016L row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-028 | 0002V6 | Supervisor coverage readback verified the current constants row credits both exact transfer consumers and preserves 92 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID0002V6 row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-029 | 0001PI | Supervisor coverage readback verified the current physical callback-table row includes exact source-ready RGB565 behavior and preserves 92 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID0001PI row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-030 | 0000OC | Supervisor coverage readback verified the current Surface row includes source-ready UID0002YO and preserves 90 percent exactly as Section 28. | 98 | Current exact row comparison and by-file command `000000023598`, exit 0, `ok:1`. | by-file/-coverage-report.md / UID0000OC row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-031 | 0000TN | Supervisor coverage readback verified the current semantic callback-table row includes exact RGB565 body closure and preserves 94 percent exactly as Section 28. | 98 | Current exact row comparison and by-global command `000000023599`, exit 0, `ok:1`. | by-global/-coverage-report.md / UID0000TN row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-032 | 00039V | Supervisor coverage readback verified the current initializer row identifies both slot-11 providers as source-ready and preserves 91 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID00039V row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-044 | 0000CB | Supervisor coverage readback verified the current ScreenPane row names both source-ready slot-11 providers in its `m_fadeStep +0x5ac` relation exactly as Section 28. | 98 | Current exact row comparison and by-class command `000000023600`, exit 0, `ok:1`. | by-class/-coverage-report.md / UID0000CB row | already-present | ALREADY_PRESENT_VERIFIED |
| C0002YO-033 | 0002YO | Run scoped file validation after target callback implementation and record command ID, timestamp, exit code, ok count, side effects, and reread hash. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / validator receipt | incorporate | applied |
| C0002YO-034 | 00016L | Run scoped file validation after aggregate synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md / validator receipt | incorporate | applied |
| C0002YO-035 | 0000OC | Run scoped file validation after Surface synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-file/Surface.md / validator receipt | incorporate | applied |
| C0002YO-036 | 0002V6 | Run scoped file validation after constant-pool synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md / validator receipt | incorporate | applied |
| C0002YO-037 | 0000TN | Run scoped file validation after semantic callback-table synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-global/SurfaceRenderCallbackTable.md / validator receipt | incorporate | applied |
| C0002YO-038 | 0001PI | Run scoped file validation after physical callback-table synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md / validator receipt | incorporate | applied |
| C0002YO-039 | 00039V | Run scoped file validation after initializer synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md / validator receipt | incorporate | applied |
| C0002YO-040 | 00039P | Run scoped file validation after first consumer synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md / validator receipt | incorporate | applied |
| C0002YO-041 | 00039T | Run scoped file validation after second consumer synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md / validator receipt | incorporate | applied |
| C0002YO-042 | 0000CB | Run scoped file validation after ScreenPane synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-class/ScreenPane.md / validator receipt | incorporate | applied |
| C0002YO-043 | 0002YO | Supervisor generated readback verified UID0002YO has no empty marker, its CPP body appears once in Surface.cpp, its H emits no duplicate declaration, and existing UID0000TN declarations remain single. | 99 | Current Surface.cpp/Surface.h hashes, sizes, line counts, and command `000000023596` receipt. | auto-generated/NexusTK/render/Surface.cpp and Surface.h / read-only generated verification | already-present | ALREADY_PRESENT_VERIFIED |

## Positive Evidence Summary

- Exact function extent, body bytes, jump table, padding, and successor are closed.
- Exact signed clamp and all 25 case targets are closed.
- Every case's scalar semantics is closed; packed-pair and odd-tail equivalence is explicit.
- Both initializer routes and all five shared-slot references are closed.
- Both direct consumers agree on mutable pixel pointer, pixel count, signed fade step, cdecl cleanup, and ignored return.
- `ScreenPane` provides an already typed `m_fadeStep` field and exact 24/0 endpoint writers.
- Existing Surface naming, typedef, global, initializer, source path, and sibling callback conventions support the now-implemented identity and placement.
- The constant pool has no independent source identity and is already routed as compiler-covered callback materialization.

## IDA MCP Facts

The exact values below are dated 2026-08-14 non-authoritative evidence snapshots. They support the semantic handoff but do not replace the supervisor's fresh Gate 2B authority check.

| Fact | Exact value |
| --- | --- |
| Module | `NexusTK.exe`, image base `0x00400000`, 32-bit |
| Target | `sub_4C4790`, `[0x004c4790,0x004c5fde)`, `0x184e` bytes |
| Function complexity | 1816 instructions, 214 basic blocks, cyclomatic 142 |
| Dated prototype | `__m128i *__cdecl(__m128i *, unsigned int, int)` |
| Dated stack | five rows exactly as recorded in Section 4; zero locals |
| Body SHA256 | `32E806F7A4558FE114ECFF11ABFDF067ECFEAA5EEC4A27055CDF3A08908E7327` over exactly 6,222 raw bytes |
| First 32 bytes | `55 8b ec 8b 45 10 33 c9 85 c0 53 8b 5d 0c 0f 49 c8 b8 18 00 00 00 3b c8 57 0f 4f c8 8b fb 8b 45` |
| Final 32 bytes from 0x004c5fbe | `5f 66 89 08 5b 5d c3 5e 8d 0c 1b c7 45 0c 00 00 00 00 5f 5b 89 4d 10 89 45 08 5d e9 d2 40 10 00` |
| Alignment | `[0x004c5fde,0x004c5fe0)` bytes `66 90`, SHA256 `88174BA925C5691BFF5CF2698A670490725C2F586FD946282B314EA52D9C24CE` |
| Jump table | `[0x004c5fe0,0x004c6044)`, 100 bytes, `jpt_4C47BD`, SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43` |
| Hash correction | Prior body value `31549525D0CF2B313BA50ED66D415B6773FD4332452FF0DCD1FE1D13EED24080` and prior jump-table value `971C6E6B25A15DC7A8971528A669C1A59E685A9189DEF7DB879CA8BAFC7A01BD` were extraction errors; fresh canonical MCP bytes and independent .NET SHA256 produced the corrected values above without any range or byte-content change |
| Padding | `[0x004c6044,0x004c6050)`, twelve `cc`, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` |
| Successor | `BlendRgb565Pixel` at `0x004c6050` |
| Target comments | all four target-entry channels blank |
| Jump-table comment | regular `jump table for switch statement`; repeatable blank |
| Proposed-name collision | zero function rows returned in the dated snapshot |
| Shared typedef | `SurfaceTransferPixelsProc` exists as a 4-byte pointer type |
| Shared slot | `g_pfnTransferPixels` at `0x0069b40c`, then-recorded type `SurfaceTransferPixelsProc`, bytes `00 00 00 00` |

Direct constant-reference sites from this function are grouped exactly as follows:

- `0x0061aa30`: `0x4c47d7, 0x4c48ad, 0x4c4abd, 0x4c4bf7, 0x4c4e0d, 0x4c5068, 0x4c516d, 0x4c52ab, 0x4c53e5, 0x4c55ae, 0x4c56be, 0x4c57d8, 0x4c5a6f, 0x4c5c44, 0x4c5d4f`.
- `0x0061aa40`: `0x4c48b9, 0x4c49e7, 0x4c4ac9, 0x4c4f47, 0x4c5074, 0x4c57e4, 0x4c5959, 0x4c5d5b`.
- `0x0061aa50`: `0x4c4c03, 0x4c4d37, 0x4c4e19, 0x4c4f53, 0x4c50bd, 0x4c5161, 0x4c56b2, 0x4c5826, 0x4c5857, 0x4c5889, 0x4c58bb, 0x4c5965, 0x4c5a7b, 0x4c5c38`.
- `0x0061aa60`: `0x4c52b7, 0x4c53f1, 0x4c55a2`.
- `0x0061aa70`: `0x4c5f18`; `0x0061aa80`: `0x4c5e61`; `0x0061aa90`: `0x4c5b81`; `0x0061aaa0`: `0x4c54f9`.
- The only external code tail is `0x004c5fd9 -> _memset` at `0x005ca0b0`.

## Function / Child Inventory

| Range/entity | Classification | Source disposition |
| --- | --- | --- |
| `[0x004c4790,0x004c5fde)` | One source-authored RGB565 block-transfer/fade callback | Emit one file-local CPP definition in UID0002YO |
| `[0x004c5fde,0x004c5fe0)` | compiler alignment `66 90` | No separate source or child |
| `[0x004c5fe0,0x004c6044)` | 25-entry local switch table | Covered by source `switch`; preserve IDA item, no emitted data |
| `[0x004c6044,0x004c6050)` | compiler padding, twelve `cc` | No source |
| `0x004c6050` successor | independent `BlendRgb565Pixel` | Remains owned by UID00016M; not included in target CPP |
| `0x0061aa30..0x0061aaa0` splats | compiler-materialized RGB565 constants | Covered by scalar expressions; no target child/table declaration |
| `0x0069b40c` slot | shared callback global | Existing UID0000TN declaration/definition only; no duplicate target storage |

There are no source-authored helper children inside the target body. Case labels, vector blocks, pair loops, and odd tails are control-flow/compiler expansions of the one callback.

## Direct Xref / Caller Inventory

### Target address

| Ref | Function | Role |
| --- | --- | --- |
| `0x005587e7 -> 0x004c4790` | `InitializeSurfaceRenderCallbacks` | RGB565 provider assignment source |
| `0x00558f0a -> 0x004c4790` | `sub_558840` | inline/alternate RGB565 provider assignment source |

There is no ordinary direct code caller. The apparent `0x004c4791` flow edge is the function's own entry fallthrough, not a caller.

### Shared slot `0x0069b40c`

| Ref | Function | Role |
| --- | --- | --- |
| `0x005571e6` | `ScreenPane_RenderPresentation` | indirect call; active pixels, width-times-height count, `m_fadeStep`; return ignored |
| `0x005584a4` | `sub_5583A0` / SurfaceDrawTilePresentation | indirect call; active pixels, active count, `m_fadeStep`; return ignored |
| `0x005587a9` | `InitializeSurfaceRenderCallbacks` | slot store route |
| `0x00558bee` | `sub_558840` | compat provider store |
| `0x00558f0a` | `sub_558840` | RGB565 provider store |

## Documentation Evidence And IDA Status

- Target and support docs already converge on UID0000OC Surface ownership, exact target extent, shared slot, initializer refs, consumers, constant family, and case-24 clear.
- UID0000TN already contains the exact source-visible callback typedef/global and generated output confirms a single declaration/definition set.
- The initializer's existing formal CPP already assigns both exact provider names; UID0002YO is the missing definition, not a missing registration.
- In the dated 2026-08-14 IDA snapshot, support-quality names (`g_pfnTransferPixels`, `ScreenPane`, `m_fadeStep`, RGB565 constant names) were present while the target function remained raw and mistyped. The report proposes only evidence-supported closure and protects prior correct work.
- The dated 2026-08-14 support-document snapshot required no metadata reduction. Only UID0002YO's score changed; all support score recommendations preserved their then-recorded values.

## Ranked Ownership Analysis

| Rank | Candidate | Result |
| ---: | --- | --- |
| 1 | [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp` | Accepted. It owns the callback family, shared globals, initializer, sibling source-ready providers, and generated route. |
| 2 | [UID:0000CB] `ScreenPane` | Rejected as source owner. ScreenPane owns `m_fadeStep` and both consumers, but it does not register or define the pixel-format provider family. |
| 3 | `SoftwareBlend16` | Rejected as direct owner. It provides arithmetic context only; target registration and sibling placement are Surface-owned. |
| 4 | [UID:00016L] RGB565 aggregate | Rejected as emitter. It is a non-reconstructable index; exact child pages own source bodies. |
| 5 | [UID:0002V6] mask constants | Rejected as owner/emitter. The pool is compiler materialization with no independent source identity. |

## Source Placement

- CPP path: `NexusTK/render/Surface.cpp`, file-local `static` provider near sibling software callback definitions and before `InitializeSurfaceRenderCallbacks` uses it.
- H path: deliberately no UID0002YO declaration. `Surface.h` already receives the shared `SurfaceTransferPixelsProc` typedef and `extern g_pfnTransferPixels` from UID0000TN.
- Emitter order: UID0002YO remains a child of UID0000OC. Its exact placement should precede initializer use; no duplicate class or physical-table body is allowed.
- Linkage: `static` is the best evidence-backed human-source choice because the address is taken only within the Surface source family and no external direct symbol consumer exists.

## Range / Split / Padding / Reclassification Analysis

- No split is required inside `[0x004c4790,0x004c5fde)`. All 25 branches share one entry clamp, one ABI, one slot, one pixel buffer/count contract, and one fade continuum.
- The exclusive endpoint `0x004c5fde` is exact. Case 24's terminal jump occupies bytes through `0x004c5fdd`; `0x004c5fde` begins `66 90` alignment.
- The 100-byte table begins at `0x004c5fe0` and contains exactly 25 little-endian dword targets, all inside the body.
- Fresh canonical raw-byte reads establish body SHA256 `32E806F7A4558FE114ECFF11ABFDF067ECFEAA5EEC4A27055CDF3A08908E7327` and jump-table SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`. The prior values `31549525D0CF2B313BA50ED66D415B6773FD4332452FF0DCD1FE1D13EED24080` and `971C6E6B25A15DC7A8971528A669C1A59E685A9189DEF7DB879CA8BAFC7A01BD` were corrected extraction errors; the ranges, sizes, entries, and split disposition did not change.
- The twelve `cc` bytes after the table separate it from `BlendRgb565Pixel` at `0x004c6050`.
- UID0002V6 constant blocks remain source-covered compiler data. Reclassifying them as a handwritten array would introduce an unsupported runtime identity.
- No separate child is needed for `_memset`; source case 24 calls ordinary CRT `memset`.

## Negative Evidence Summary

- No ordinary direct callers of `0x004c4790`.
- No use of the target return value; no coherent pointer-return contract.
- No rectangle, width, height, row stride, source stride, or clipping arguments inside the callback.
- No field access by the callback itself; `m_fadeStep` is supplied by consumers.
- No independent lookup/walker/address identity for the aligned fade constants.
- No evidence for 25 semantic enum names; one signed ordinal field and endpoint progression contradict that model.
- No external provider declaration requirement; target address-taking is confined to Surface initialization.
- No target-specific third-party source, import directive, resource, RTTI, vtable, exception object, or dynamic allocation.
- No reason to change UID0000TN's existing type/global names or duplicate their formals.

## IDA Rename / Type / Comment Recommendations

These rows preserve the dated literal prestates and semantic recommendations while recording the final supervisor Gate 2B outcomes. Gate 2B passed: I01-I03 are `APPLIED_VERIFIED`, and I04-I05 are `NO_CHANGE_VERIFIED`. This report contains no endpoint invocation, transaction procedure, or process-handling instructions. [Removed operational prose is preserved only in the inert companion](0002YO-SoftwareRenderRgb565BlockTransferCallback-empty-emitter-source-quality-removed.md).

| ID | Exact entity | Dated literal pre-state (2026-08-14 snapshot) | Semantic action / verified outcome | Evidence / confidence | Safety constraint | Final readback | Classification |
| --- | --- | --- | --- | --- | --- | --- | --- |
| I01 / C0002YO-021 | Function `[0x004c4790,0x004c5fde)` | Name `sub_4C4790`; type `__m128i *__cdecl(__m128i *, unsigned int, int)`; frame `__saved_registers,+0x4,0x4,_DWORD`; `__return_address,+0x8,0x4,_UNKNOWN *`; `arg_0,+0xc,0x4,_DWORD`; `arg_4,+0x10,0x4,_DWORD`; `arg_8,+0x14,0x4,_DWORD`; zero locals; address regular absent; address repeatable absent; function regular absent; function repeatable absent | Applied and verified rename to `SoftwareRenderRgb565BlockTransferCallback` | Two provider assignments, typed slot semantics, sibling naming, zero collision; 97 | No overwrite or generated suffix; preserve range/body/xrefs and separately tracked type/frame/comments | Name `SoftwareRenderRgb565BlockTransferCallback`; range `[0x004c4790,0x004c5fde)` and inbound refs `0x005587e7`, `0x00558f0a` unchanged | APPLIED_VERIFIED |
| I02 / C0002YO-022 | Function `0x004c4790` | Name `sub_4C4790`; prototype `__m128i *__cdecl(__m128i *, unsigned int, int)`; frame `__saved_registers,+0x4,0x4,_DWORD`; `__return_address,+0x8,0x4,_UNKNOWN *`; `arg_0,+0xc,0x4,_DWORD`; `arg_4,+0x10,0x4,_DWORD`; `arg_8,+0x14,0x4,_DWORD`; zero locals; address regular absent; address repeatable absent; function regular absent; function repeatable absent | Applied and verified type `void __cdecl SoftwareRenderRgb565BlockTransferCallback(unsigned short *pixels, unsigned int pixelCount, int fadeStep)` | Two cdecl consumers ignore return; clear tail return is incidental; shared ABI and field type agree; 98 | Preserve saved-register/return rows, zero locals, range/body/xrefs/comments/table/padding/successor/slot; reject materially different normalization | Name `SoftwareRenderRgb565BlockTransferCallback`; normalized type `void __cdecl(unsigned __int16 *pixels, unsigned int pixelCount, int fadeStep)`; complete frame `__saved_registers,+0x4,0x4,_DWORD`; `__return_address,+0x8,0x4,_UNKNOWN *`; `pixels,+0xc,0x4,unsigned __int16 *`; `pixelCount,+0x10,0x4,unsigned int`; `fadeStep,+0x14,0x4,int`; zero locals | APPLIED_VERIFIED |
| I03 / C0002YO-023 | Address `0x004c4790` | Name `sub_4C4790`; prototype `__m128i *__cdecl(__m128i *, unsigned int, int)`; frame `__saved_registers,+0x4,0x4,_DWORD`; `__return_address,+0x8,0x4,_UNKNOWN *`; `arg_0,+0xc,0x4,_DWORD`; `arg_4,+0x10,0x4,_DWORD`; `arg_8,+0x14,0x4,_DWORD`; zero locals; address regular absent; address repeatable absent; function regular absent; function repeatable absent | Applied and verified the address-repeatable comment at `0x004c4790` as exact text `RGB565 in-place ScreenPane fade transfer: clamps fadeStep to 0..24, preserves step 0, applies exact packed attenuation to pixelCount pixels, and clears step 24 to black.` | Clamp, formulas, consumers, and clear evidence; 96 | Preserve address regular, function regular, and function repeatable channels, body, range, and xrefs | Address repeatable equals the exact semantic text; address regular, function regular, and function repeatable remain absent; I01/I02 name, type, frame, and zero-local readbacks remain exact | APPLIED_VERIFIED |
| I04 / C0002YO-024 | Data `[0x004c5fe0,0x004c6044)` | `jpt_4C47BD`; data; 100 bytes; SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`; regular comment `jump table for switch statement`; repeatable absent; one inbound ref at `0x004c47bd`; 25 ordered targets | No change verified | Fresh canonical MCP bytes, independent .NET SHA256, exact item, xref, and target inventory; 99 | Protect name/kind/range/comments/bytes/xrefs | Exact prestate remains: `jpt_4C47BD`, 100-byte data item, corrected SHA256, regular comment, blank repeatable comment, one inbound ref, and 25 targets | NO_CHANGE_VERIFIED |
| I05 / C0002YO-025 | Global `0x0069b40c` | Authoritative name `g_pfnTransferPixels`; type `SurfaceTransferPixelsProc`; four zero bytes; address regular absent; address repeatable absent; five refs | No change verified | Typed semantic owner, initializer and two consumers; 99 | Do not recreate from one-byte item-head projection; protect name/type/storage/comments/xrefs | Exact authoritative state remains: `g_pfnTransferPixels`, type `SurfaceTransferPixelsProc`, four zero bytes, blank address comments, and five inbound refs; one-byte physical item-head projection caveat preserved | NO_CHANGE_VERIFIED |

## First-Draft C++ Recommendation

- Eligible for formal draft C++: yes. Behavior, ABI, ownership, linkage, all cases, pair/odd-tail handling, no-clipping disposition, and CPP/H destinations are closed.
- Target CPP payload: insert the exact block below into UID0002YO's formal CPP channel.
- Target H payload: remain blank. Do not repeat UID0000TN's existing typedef/extern.
- The macro is a plausible period source shape for one repeated case family and allows the compiler to choose its own SSE scheduling. It contains no IDA labels, intrinsics, raw addresses, or compiler-generated names.

```cpp
#define APPLY_RGB565_FADE(pairExpression, pixelExpression)                 \
    do {                                                                  \
        unsigned int *pair = reinterpret_cast<unsigned int *>(pixels);    \
        unsigned int pairCount = pixelCount >> 1;                         \
        while (pairCount-- != 0) {                                        \
            const unsigned int value = *pair;                             \
            *pair++ = (pairExpression);                                   \
        }                                                                 \
        if ((pixelCount & 1) != 0) {                                      \
            unsigned short *lastPixel =                                   \
                reinterpret_cast<unsigned short *>(pair);                 \
            const unsigned int value = *lastPixel;                        \
            *lastPixel = static_cast<unsigned short>(pixelExpression);    \
        }                                                                 \
    } while (0)

static void __cdecl SoftwareRenderRgb565BlockTransferCallback(
    unsigned short *pixels,
    unsigned int pixelCount,
    int fadeStep)
{
    if (fadeStep < 0) {
        fadeStep = 0;
    } else if (fadeStep > 24) {
        fadeStep = 24;
    }

    switch (fadeStep) {
    case 0:
        return;
    case 1:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u),
            value - ((value >> 4) & 0x0841u));
        break;
    case 2:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                ((value >> 3) & 0x18c318c3u),
            value + ((value >> 4) & 0x0841u) -
                ((value >> 3) & 0x18c3u));
        break;
    case 3:
        APPLY_RGB565_FADE(
            value - ((value >> 3) & 0x18c318c3u),
            value - ((value >> 3) & 0x18c3u));
        break;
    case 4:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u) -
                ((value >> 3) & 0x18c318c3u),
            value - ((value >> 4) & 0x0841u) -
                ((value >> 3) & 0x18c3u));
        break;
    case 5:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                ((value >> 2) & 0x39c739c7u),
            value + ((value >> 4) & 0x0841u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 6:
        APPLY_RGB565_FADE(
            value - ((value >> 2) & 0x39c739c7u),
            value - ((value >> 2) & 0x39c7u));
        break;
    case 7:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u) -
                ((value >> 2) & 0x39c739c7u),
            value - ((value >> 4) & 0x0841u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 8:
        APPLY_RGB565_FADE(
            value - ((value >> 3) & 0x18c318c3u) -
                ((value >> 2) & 0x39c739c7u),
            value - ((value >> 3) & 0x18c3u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 9:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u) -
                ((value >> 3) & 0x18c318c3u) -
                ((value >> 2) & 0x39c739c7u),
            value - ((value >> 4) & 0x0841u) -
                ((value >> 3) & 0x18c3u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 10:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                2u * ((value >> 2) & 0x39c739c7u),
            value + ((value >> 4) & 0x0841u) -
                2u * ((value >> 2) & 0x39c7u));
        break;
    case 11:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                ((value >> 1) & 0x7bcf7bcfu),
            value + ((value >> 4) & 0x0841u) -
                ((value >> 1) & 0x7bcfu));
        break;
    case 12:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 1) & 0x7bcf7bcfu),
            ((value >> 4) & 0x0841u) +
                ((value >> 1) & 0x7bcfu));
        break;
    case 13:
        APPLY_RGB565_FADE(
            (value & 0xf79ef79eu) >> 1,
            (value & 0xf79eu) >> 1);
        break;
    case 14:
        APPLY_RGB565_FADE(
            ((value >> 1) & 0x7bcf7bcfu) -
                ((value >> 4) & 0x08410841u),
            ((value >> 1) & 0x7bcfu) -
                ((value >> 4) & 0x0841u));
        break;
    case 15:
        APPLY_RGB565_FADE(
            2u * ((value >> 2) & 0x39c739c7u) -
                ((value >> 4) & 0x08410841u),
            2u * ((value >> 2) & 0x39c7u) -
                ((value >> 4) & 0x0841u));
        break;
    case 16:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 3) & 0x18c318c3u) +
                ((value >> 2) & 0x39c739c7u),
            ((value >> 4) & 0x0841u) +
                ((value >> 3) & 0x18c3u) +
                ((value >> 2) & 0x39c7u));
        break;
    case 17:
        APPLY_RGB565_FADE(
            ((value >> 3) & 0x18c318c3u) +
                ((value >> 2) & 0x39c739c7u),
            ((value >> 3) & 0x18c3u) +
                ((value >> 2) & 0x39c7u));
        break;
    case 18:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 2) & 0x39c739c7u),
            ((value >> 4) & 0x0841u) +
                ((value >> 2) & 0x39c7u));
        break;
    case 19:
        APPLY_RGB565_FADE(
            (value & 0xe71ce71cu) >> 2,
            (value & 0xe71cu) >> 2);
        break;
    case 20:
        APPLY_RGB565_FADE(
            ((value >> 2) & 0x39c739c7u) -
                ((value >> 4) & 0x08410841u),
            ((value >> 2) & 0x39c7u) -
                ((value >> 4) & 0x0841u));
        break;
    case 21:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 3) & 0x18c318c3u),
            ((value >> 4) & 0x0841u) +
                ((value >> 3) & 0x18c3u));
        break;
    case 22:
        APPLY_RGB565_FADE(
            (value & 0xc618c618u) >> 3,
            (value & 0xc618u) >> 3);
        break;
    case 23:
        APPLY_RGB565_FADE(
            (value & 0x84108410u) >> 4,
            (value & 0x8410u) >> 4);
        break;
    case 24:
        memset(pixels, 0, pixelCount * sizeof(*pixels));
        break;
    }
}

#undef APPLY_RGB565_FADE
```

- Exact behavior rationale: each packed expression repeats the corresponding 16-bit mask in both halfwords, and the odd-tail expression is the independently observed scalar form. Clamp, no-op, clear, and 32-bit byte-count arithmetic match the executable.
- Human-source rationale: a file-local cdecl callback, numeric switch, one expansion macro, integer masks, and ordinary `memset` are credible period C++ and explain compiler vectorization without copying reverse-engineering artifacts.
- Naming rationale: the dated 2026-08-14 Surface-source snapshot uses `SoftwareRenderRgb565...Callback`, `Surface...Proc`, `g_pfn...`, and lower-camel parameters. `fadeStep` is backed by the recorded class field rather than a guessed generic `mode`.
- Include rationale: `memset` is already available in the Surface source context; do not add a target-private third-party import or duplicate callback typedef.

## Final Recommendation

All 44 claims are now checked and truthfully reconciled. Ordinary implementation C0002YO-001 through C0002YO-020 and scoped validation C0002YO-033 through C0002YO-042 remain applied and physically reread; supervisor Gate 2B C0002YO-021 through C0002YO-025 passed; current coverage C0002YO-026 through C0002YO-032 and C0002YO-044 is already present and verified; coherent generated verification C0002YO-043 is already present and verified. Report lifecycle truth remains external to this report body.

No behavior, naming, type, source-placement, owner, split, constant, formal CPP/H, or evidence-backed research blocker remains. Residual uncertainty is limited to stripped original lexical spelling and exact compiler unrolling/vector scheduling; neither justifies raw names or blank source.

## Recommended Target Doc Changes

1. Completed: target metadata is `94/95`; route flags are preserved.
2. Completed: the Item Summary is source-ready and covers ABI, 25 fade steps, pair/odd-tail behavior, case-24 clear, caller/initializer/field evidence, boundaries, owner/emitter, formal CPP, and blank H.
3. Completed in the dated 2026-08-14 documentation snapshot: stale Assignment Decision and Score Rationale blockers were replaced with exact closure.
4. Completed: exact ABI, clamp, formula inventory, pair/SIMD/scalar equivalence, no-clipping disposition, xrefs/callers, `m_fadeStep`, source placement, constants, boundary hashes, and rejected alternatives are incorporated.
5. Completed: Section 22's exact source is in formal CPP; formal H is empty under the file-local/shared-header rationale.
6. Completed: prior range/xref/history evidence remains, with superseded assertions historicalized and corrected rather than deleted.

## Recommended Support Doc Changes

- Completed UID00016L: inventory and split backlog mark UID0002YO source-ready; aggregate remains 90/92, non-reconstructable, no owner/emitter/formals.
- Completed UID0000OC Surface: source-ready RGB565 slot-11 behavior replaces stale marker wording; 90/89 is preserved.
- Completed UID0002V6: UID0002YO independently closes the RGB565 transfer consumer with only `pixels`, `pixelCount`, and signed ordinal `fadeStep`, using packed-pair/odd-tail linear in-place traversal and no separate mode or row/stride inputs; 92/94 and compiler-covered no-table emission are preserved.
- Completed UID0000TN: complete RGB565 provider semantics are present at slot 11; 94/95 and all existing formal CPP/H remain exact and unduplicated.
- Completed UID0001PI: complete RGB565 provider semantics are present at physical slot 11; 92/94, covered-by-only CPP, and blank H are preserved.
- Completed UID00039V: both slot-11 providers are source-ready with exact RGB565 endpoint/formula behavior; existing initializer CPP and 91/93 are preserved.
- Completed UID00039P: exact RGB565 provider behavior extends the exact call contract; 90/93 and blank method formals are preserved.
- Completed UID00039T: exact RGB565 provider behavior is documented without claiming its independent retained-helper reachability/source-placement issue is solved; 86/88 is preserved.
- Completed UID0000CB: the `m_fadeStep` section now covers both exact providers; the exact 0x5b4 layout, formals, owner/emitter, and 93/94 are preserved.
- Do not alter SoftwareBlend16, BlendRgb565Pixel, ignored jump-table ownership, or unrelated callback siblings.

## Score And Metadata Recommendation

- Target pre-callback: `87/90`, owner/emitter UID0000OC, reconstructable true, blank CPP/H.
- Dated 2026-08-14 post-callback target snapshot: `94/95`, same owner/emitter/reconstructable state, exact CPP populated, H deliberately blank.
- Completion rationale: exact body/range, ABI, all 25 formulas, clamp, loops, zero/odd counts, no-clipping disposition, clear, constants, initializer, callers, field, boundaries, owner, source placement, formal code, support plan, IDA handoff, and manual coverage are closed.
- Confidence rationale: dated 2026-08-14 IDA, typed-support, generated, and independent-documentation snapshots agree. Confidence remains below 100 only because original stripped lexical spellings and exact pre-optimization macro/unrolling choices cannot be proven byte-for-byte as source text.
- Reason not lower: no functional or routing blocker remains in the research record, and every old score cap received an evidence-backed resolution rather than a future-work label.
- Reason not above 95: final code is substantially exact but still an inferred human-source reconstruction; exact original spelling and compiler scheduling are unavailable.
- Support metadata remains: UID00016L 90/92; UID0000OC 90/89; UID0002V6 92/94; UID0000TN 94/95; UID0001PI 92/94; UID00039V 91/93; UID00039P 90/93; UID00039T 86/88; UID0000CB 93/94.

## Open Questions With Attempted Resolution

- Are the branches 25 named modes? Resolved negatively. They are one ordinal fade progression, proved by clamp, monotone arithmetic, `m_fadeStep`, and 24/0 endpoint writers.
- Is the source return `__m128i *`? Resolved negatively as `void` by both ignored-return consumers and the inconsistent `_memset` tail artifact.
- Is the pixel argument SIMD-typed? Resolved negatively as mutable `unsigned short *`; callers and scalar tails operate 16-bit RGB565 storage.
- Does the callback clip? Resolved negatively. It receives only pointer/count/step; callers establish the active region/count.
- Must SIMD intrinsics or aligned arrays appear in source? Resolved negatively. Pair/scalar formulas produce the observed compiler vectorization and literal materialization.
- Should case 9's smaller SIMD chunk change source? Resolved negatively. Its scalar/pair formula is identical; chunk size is an optimization artifact.
- Should the provider be public in Surface.h? Resolved negatively. It is file-local; shared ABI/global declarations already exist under UID0000TN.
- Should UID0002V6 emit a constant table? Resolved negatively through complete xref/access-topology analysis.
- What exact original function and parameter spellings existed? Not symbol-proven, but not a blocker. The chosen names are the highest-probability established Surface conventions and contain no IDA residue.
- Questions remaining unresolved: none that block behavior, ownership, source placement, score, formal CPP/H, support incorporation, or the supervisor-owned semantic IDA handoff.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The B agent did not edit these files. The exact text below is the preserved semantic handoff; final supervisor readback verified all ten current rows, including both no-replacement rows, match this section exactly.

Dated 2026-08-14 read-only manual-row snapshot. Line numbers are non-authoritative navigation receipts, not permanent identities:

| Page UID | Manual file / then-line (2026-08-14 snapshot) | Disposition |
| --- | --- | --- |
| 0002YO | `by-memory/-coverage-report.md:1673` | Current row exactly matches the UID0002YO text below; C0002YO-026 is `ALREADY_PRESENT_VERIFIED`. |
| 00016L | `by-memory/-coverage-report.md:1651` | Current row exactly matches the UID00016L text below; C0002YO-027 is `ALREADY_PRESENT_VERIFIED`. |
| 0002V6 | `by-memory/-coverage-report.md:4388` | Current row exactly matches the UID0002V6 text below; C0002YO-028 is `ALREADY_PRESENT_VERIFIED`. |
| 0001PI | `by-memory/-coverage-report.md:4827` | Current row exactly matches the UID0001PI text below; C0002YO-029 is `ALREADY_PRESENT_VERIFIED`. |
| 00039V | `by-memory/-coverage-report.md:3276` | Current row exactly matches the UID00039V text below; C0002YO-032 is `ALREADY_PRESENT_VERIFIED`. |
| 00039P | `by-memory/-coverage-report.md:3257` | Current no-replacement row is verified exact. It records the mutable-buffer/count/`m_fadeStep` call, ignored return, correct score/route, and independent retained-helper body blocker. |
| 00039T | `by-memory/-coverage-report.md:3275` | Current no-replacement row is verified exact. It records the slot contract, score/route, and independent zero-inbound/incomplete-helper blocker. |
| 0000OC | `by-file/-coverage-report.md:276` | Current row exactly matches the UID0000OC text below; C0002YO-030 is `ALREADY_PRESENT_VERIFIED`. |
| 0000TN | `by-global/-coverage-report.md:200` | Current row exactly matches the UID0000TN text below; C0002YO-031 is `ALREADY_PRESENT_VERIFIED`. |
| 0000CB | `by-class/-coverage-report.md:469` | Current row exactly matches the UID0000CB text below; C0002YO-044 is `ALREADY_PRESENT_VERIFIED`. |

`by-memory/-coverage-report.md`, verified exact current UID0002YO row:

        - [UID:0002YO][0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback](by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md) 0x004c4790-0x004c5fde | function | SoftwareRenderRgb565BlockTransferCallback : reconstructable : 94% : very-strong : Source-ready Surface slot-11 RGB565 in-place fade-transfer callback with exact cdecl void mutable-pixel/count/fadeStep ABI, signed 0..24 clamp, complete 25-step attenuation formulas, packed-pair and odd-tail equivalence, zero-count no-write behavior, no internal clipping, step-0 no-op, step-24 pixelCount-times-two clear, two initializer refs, five shared-slot refs, two return-ignoring ScreenPane consumers, exact body/alignment/jump-table/padding boundaries, owner/emitter UID0000OC, complete formal CPP, and deliberately blank H.

`by-memory/-coverage-report.md`, verified exact current UID00016L row:

    - [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) 0x004c0770-0x004c5fde | function-family | SoftwareRenderRgb565Callbacks : not reconstructable : 90% : very-strong : Non-emitting RGB565 callback-family index over twelve exact Surface-owned source children; UID0002PI pixel, UID0002TF RLE fill, UID0002TG scaled RLE tint, UID0002TH alpha lookup, UID0002TI bitmask, UID0002YK rectangle fill, and UID0002YO 25-step block-transfer fade callbacks are source-ready on exact child pages, while the aggregate remains blank and all unrelated child dispositions are preserved.

`by-memory/-coverage-report.md`, verified exact current UID0002V6 row:

        - [UID:0002V6][0x0061a920-0x0061aac0.SoftwareRenderMaskConstants](by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md) 0x0061a920-0x0061aac0 | read-only-render-constant-data | SoftwareRenderMaskConstants : reconstructable : 92% : very-strong : Exact 416-byte, 26-block aligned compiler literal pool for Surface compat/RGB555 and RGB565 callbacks: all bytes/hash, 142 direct xrefs, 0x0061aa00 family split, masks, fixed-point blend weights, fade deltas, and neighboring boundaries are closed; UID0002YJ and UID0002YO now provide the exact RGB555 and RGB565 25-formula transfer-consumer closures, and callback source covers emission without a standalone table.

`by-memory/-coverage-report.md`, verified exact current UID0001PI row:

    - [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) 0x0069b3e0-0x0069b410 | function-pointer table | SurfaceRenderCallbackTable : reconstructable : 92% : very-strong : Twelve declaration-ordered zero-initialized Surface render callback globals with exact physical storage, initializer, and dispatch evidence; semantic UID0000TN emits the single Surface.h/Surface.cpp declaration-definition set, and slot 11 has exact SurfaceTransferPixelsProc/g_pfnTransferPixels mutable-pixel/count/fadeStep semantics with source-ready RGB555 and RGB565 25-step providers, two ScreenPane consumers, and no duplicate physical storage or provider body on this page.

`by-memory/-coverage-report.md`, verified exact current UID00039V row:

        - [UID:00039V][0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks](by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md) 0x00558690-0x0055883d | function | InitializeSurfaceRenderCallbacks : reconstructable : 91% : very-strong : Source-ready Surface callback initializer with exact display-format selection and typed slot-11 SurfaceTransferPixelsProc assignment to source-ready RGB555 compat and RGB565 25-step fade-transfer providers; existing formal initializer C++ remains authoritative.

`by-file/-coverage-report.md`, verified exact current UID0000OC row:

- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 90% : strong : Generated root NexusTK/render/Surface.cpp plus Surface.h callback declarations owns callback typedefs/definitions, initializer selection, pixel-format/lookup globals, software callback families, and true Surface helpers; slot 11 has exact SurfaceTransferPixelsProc/g_pfnTransferPixels declarations, two ScreenPane consumers, and source-ready RGB555 and RGB565 25-step fade-transfer providers UID0002YJ and UID0002YO with exact endpoint, pair, odd-tail, clear, and no-clipping semantics; unrelated callback-family and broader source-unit work remains independently bounded.

`by-global/-coverage-report.md`, verified exact current UID0000TN row:

- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) : reconstructable : 94% : very-strong : Semantic/source owner for twelve fixed Surface render callback globals; Surface.h owns typed declarations/externs and Surface.cpp owns single definitions, including exact slot-11 SurfaceTransferPixelsProc g_pfnTransferPixels with mutable 16-bit buffer/count/fadeStep ABI, source-ready RGB555 and RGB565 25-step providers, and two ScreenPane consumers; physical UID0001PI retains exactly one non-emitting covered-by CPP comment and no physical data declaration, definition, or provider body, preventing duplicate storage.

`by-class/-coverage-report.md`, verified exact current UID0000CB row:

- [UID:0000CB][ScreenPane](by-class/ScreenPane.md) : reconstructable : 93% : very-strong : Root Pane/FrameHandler/Singleton<ScreenPane> controller retaining canonical singleton lifecycle, exact cursor table and dimensions, pending dirty-region state, seven existing source-ready UID0001G7 method children plus source-ready SaveScreenshotJPG/SaveScreenshotBMP/SaveScreenshotPNG declarations in deterministic source order, inherited GrafPort m_ddSurface capture switching, ScreenPane m_renderSurface ownership, DirectDraw/browser/status/proof interactions, and ScreenshotCapture.cpp routing for the three screenshot definitions without duplicate class-level bodies; retains exact private ScreenPane::BlitSurfaceToDisplay with four callers, exclusive/windowed DirectDraw, GDI copy/stretch, RGB565-to-32-bit conversion, one-shot lost-surface recovery limited to converted DrawType-1 Blt and exclusive BltFast, and unchanged ignored ordinary-windowed Blt failure, plus the exact DirectDraw/presentation/callback/helper inventory and all existing caller/history evidence, exact RTTI/PMDs, old-MSVC Singleton EBO at +0xfc, binary size 0x5b4, ordinary destructor child UID0004W7, compiler-only UID00023U/UID0003CI and non-emitting UID0001G5 exclusions, source-facing OnTimer/OnFrameUpdate/HandleBrowserNotification declarations, complete compile-visible R3 through +0x5b3, the exact member table, and the evidence-backed provisional C++03 presentation-state/cursor-state storage required to preserve every later offset pending stronger semantic evidence; includes retained BeginFadeIn/BeginFadeOut declarations and exact UID0003A0 callback, Region traversal, FrameHandler scheduling, and 2/24 versus 3/0 endpoint contracts; adds the exact m_fadeStep +0x5ac relation to source-ready UID0002YJ and UID0002YO and Surface slot-11 transition consumption without changing class layout or ownership.

Generated research tracker text remains validator-owned and was not edited manually. The final supervisor coverage verification used the current manual rows and scoped commands recorded under `Validator Results`.

## Follow-Up Actions

- No research, ordinary-document, coverage, generated, or IDA verification action remains open in this report: Gate 1, Gate 2A, Gate 2B, all ten current coverage rows, and coherent generated C0002YO-043 readback are recorded as passed.
- B001 has no further authorized ordinary-document, manual-coverage, generated, IDA, validator, audit, or lifecycle action through this report. Report execution/archive state remains supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Confidence

- Overall report confidence: `95/100`.
- Behavior: `97/100`; every step, loop class, endpoint, and tail is directly evidenced.
- ABI: `98/100`; two consumers, caller cleanup, return use, and the dated shared-typedef snapshot agree.
- Ownership/source placement: `97/100`; provider registration and sibling-family routing are direct.
- Source spelling/shape: `92/100`; chosen names and macro shape are high-probability human source but stripped original tokens cannot be proved.
- Range/compiler-data disposition: `99/100`; exact bytes, hashes, table entries, padding, and successor are closed.

## Validator Results

- The table below preserves dated 2026-08-14 historical validator receipts for the ordinary-document callback. Command IDs, timestamps, hashes, and reported side effects are non-authoritative snapshots, not present-tense instructions or lifecycle state.

| Claim | Command ID / timestamp | Result | Target-specific diagnostics and validator-owned side effects |
| --- | --- | --- | --- |
| C0002YO-033 | `000000023418` / `2026-08-14T04:23:38-04:00` | exit 0; `ok:1` | target metadata/reference/registry/projected-stat updates; deferred generated refresh later completed with generated Surface CPP/report/tracker updates |
| C0002YO-034 | `000000023427` / `2026-08-14T04:25:34-04:00` | exit 0; `ok:1` | projected stats update and incremental-stat no-op; asynchronous generated metadata/report refresh completed |
| C0002YO-035 | `000000023430` / `2026-08-14T04:26:52-04:00` | exit 0; `ok:1` | twelve pre-existing missing UID00039R/UID0003XE references; projected-stat update; asynchronous generated Surface metadata/header refresh completed |
| C0002YO-036 | `000000023439` / `2026-08-14T04:29:08-04:00` | exit 0; `ok:1` | projected-stat update; target absent from generated completion queue, so incremental-stat no-op |
| C0002YO-037 | `000000023457` / `2026-08-14T04:31:14-04:00` | exit 0; `ok:1` | three pre-existing missing UID0003XE references; projected-stat update; incremental-stat no-op |
| C0002YO-038 | `000000023464` / `2026-08-14T04:33:00-04:00` | exit 0; `ok:1` | three pre-existing missing UID0003XE references; projected-stat update; incremental-stat no-op |
| C0002YO-039 | `000000023469` / `2026-08-14T04:34:06-04:00` | exit 0; `ok:1` | projected-stat update; incremental-stat no-op; a later same-day generated Surface.cpp/Surface.h snapshot carried command receipt `000000023511` |
| C0002YO-040 | `000000023472` / `2026-08-14T04:35:26-04:00` | exit 0; `ok:1` | UID0002YO reference-index addition; projected-stat update; incremental-stat no-op |
| C0002YO-041 | `000000023474` / `2026-08-14T04:37:05-04:00` | exit 0; `ok:1` | three pre-existing missing UID00039U references; UID0002YO reference-index addition; target stats-row and projected-stat updates |
| C0002YO-042 | `000000023476` / `2026-08-14T04:38:18-04:00` | exit 0; `ok:1` | ten pre-existing missing UID00039R/UID0003A2 references; UID0002YO reference-index addition; projected-stat update; incremental-stat no-op |
| Gate 2B prestate hash correction | `000000023589` / `2026-08-14T16:21:56-04:00` | exit 0; `ok:1` | corrected target body/jump-table extraction hashes; projected-stat update; target absent from generated stats lists; generated refresh deferred under the same command receipt |
| C0002YO-012 Gate 2A correction | `000000023596` / `2026-08-14T17:14:43-04:00` | exit 0; `ok:1` | corrected UID0002V6 slot-11 ABI and linear in-place traversal statements; projected-stat update; target absent from generated stats lists; generated refresh deferred under the same command receipt |
| C0002YO-026/C027/C028/C029/C032 coverage verification | `000000023597` / `2026-08-14T17:30:42-04:00` | exit 0; `ok:1` | current by-memory rows match Section 28; UID00039P and UID00039T no-replacement rows also match exactly |
| C0002YO-030 coverage verification | `000000023598` / `2026-08-14T17:30:45-04:00` | exit 0; `ok:1` | current by-file UID0000OC row matches Section 28 exactly |
| C0002YO-031 coverage verification | `000000023599` / `2026-08-14T17:30:48-04:00` | exit 0; `ok:1` | current by-global UID0000TN row matches Section 28 exactly |
| C0002YO-044 coverage verification | `000000023600` / `2026-08-14T17:31:01-04:00` | exit 0; `ok:1` | current by-class UID0000CB row matches Section 28 exactly |
| C0002YO-043 generated verification | `000000023596` / `2026-08-14T17:14:43-04:00` | readback passed | Surface.cpp `EAC64DA9AF8C43CB405637AB03E8A051395CC4C44D05EEB51C34B6CECB01E415`, 77,412 bytes/2,307 lines; Surface.h `B45708EB0D7EF5267119C8852A47C2C033A20F0D892694F4B0225BD420E82693`, 3,085 bytes/102 lines; one target body, no empty marker, no duplicate H declaration |

- In the dated 2026-08-14 callback and repair history, B001 performed no `execute_report`, report status/probe, full validator lifecycle command, manual coverage edit, manual generated edit, IDA mutation/save, or supervisor audit/lifecycle action. The only post-callback repair validators were scoped target command `000000023589` and scoped UID0002V6 command `000000023596`; validator-owned projected-stat and deferred-generated side effects are receipts rather than claimed manual edits.
- Supervisor Gate 2B was not a validator operation. Its separate verified backup/save receipt is canonical prestate SHA256 `D9948E150E83CAD90A9E689D162AFE654A5287344BA1DABF6DD350128926FF98`, backup `E:\NTK\Resources\NexusTK\supervisor-backups\NexusTK.exe.pre-0002YO-20260814T172748243.i64`, and saved canonical SHA256 `F89D5FC89C7FC3AF6A44581AE9DF0990414B88A35C3554AD10C36F6B9341BCE0`; post-save readback passed.

## Changed Files

- Historical implementation-callback changes, preserved as dated 2026-08-14 evidence: target UID0002YO, aggregate UID00016L, Surface UID0000OC, constants UID0002V6, semantic callback table UID0000TN, physical callback table UID0001PI, initializer UID00039V, consumers UID00039P and UID00039T, and ScreenPane UID0000CB. Exact hashes, sizes, line counts, and command receipts in `Evidence Checked` are historical snapshots; the supervisor rereads authoritative documents dynamically.
- A dated 2026-08-14 receipt records that `by-class/ScreenPane.md` received a concurrent B003 header-route closure after C0002YO-042 and was then reread at SHA256 `89A14DC1EB6CA33F0DD2670B0FB6002FF897CD23BDDF3A425F19444A279FF473`; that hash is not permanent current identity.
- Report revision history: a report-only repair preserved the valid research, 44-row ledger/checklist, and formal C++, recast volatile identities as dated snapshots, retained only semantic IDA rows, and moved removed operational prose verbatim to the [inert non-authoritative companion](0002YO-SoftwareRenderRgb565BlockTransferCallback-empty-emitter-source-quality-removed.md). This statement records artifact history, not lifecycle status.
- The dated Gate 2B prestate hash repair directly edited this report and `by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md`; the target reread after scoped command `000000023589` was SHA256 `45229C261E8469CA5A8031A3DC56F82EEB8E930CDE5064C41F0FA02F95601CA9`, 24,413 bytes, and 363 lines. The inert companion was not changed.
- The dated Gate 2A C012 repair edited only this report and UID0002V6. The support destination changed from SHA256 `3EE4219203CEF32EFF54B04855A9A85037EFC0909998101726FB7DB513B99B76`, 31,369 bytes, and 247 lines to SHA256 `0CC9026CA9CE41D3EDA6A04A3E7D663ADDE97D4D4022A18C6FC0FC3E457C1589`, 31,623 bytes, and 247 lines after scoped command `000000023596` and physical reread; every other UID0002V6 detail was preserved.
- These repairs did not edit manual coverage, generated source/report, tracker, audit ledger, lifecycle, IDA database, goal, notes, or any ordinary documentation beyond the two explicitly named by-memory pages in their respective repair cycles. Validator-owned projected-stat and deferred-generated side effects from the scoped commands are disclosed above as dated receipts.
- This final reconciliation edited only this report. It records supervisor-applied Gate 2B IDA/save results, supervisor-verified current coverage rows, and read-only generated verification without B001 editing any by-* document, coverage file, generated file, IDA database, audit/catalog, validator lifecycle state, goal, notes, or companion.
- The `-removed.md` companion is an inert archive only: it is not a B report, supplies no evidence or gate credit, must never be executed, and must never be submitted to `execute_report`.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| [x] | C0002YO-001 | 0002YO | Replace the stale below-85 summary/status with the source-ready exact RGB565 fade-transfer identity, range, ABI, 25-step behavior, and Surface route. | 98 | Dated 2026-08-14 target extent, entry clamp, callers, initializer refs, and pre-callback target text. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / metadata, Item Summary, Status | incorporate | applied |
| [x] | C0002YO-002 | 0002YO | Document the exact cdecl void ABI `unsigned short *pixels, unsigned int pixelCount, int fadeStep` and reject the decompiler pointer return. | 98 | Two caller stack sequences and ignored EAX; case-24 `_memset` tail jump. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / ABI and Evidence | incorporate | applied |
| [x] | C0002YO-003 | 0002YO | Incorporate all 25 exact RGB565 fade formulas, signed clamp, pair loop, odd tail, zero-count behavior, no internal clipping, and case-24 clear. | 97 | Independent per-case disassembly, jump table, constant xrefs, and ScreenPane endpoint writes. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Behavior and Formula Inventory | incorporate | applied |
| [x] | C0002YO-004 | 0002YO | Preserve body `[0x004c4790,0x004c5fde)` with corrected SHA256 `32E806F7A4558FE114ECFF11ABFDF067ECFEAA5EEC4A27055CDF3A08908E7327`, two-byte alignment, 25-entry jump table with corrected SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`, twelve-byte padding, and successor boundary without emitting compiler data. | 99 | Fresh canonical read-only MCP bytes and independent .NET SHA256; prior hash values corrected as extraction errors; exact item/xref inventory and `BlendRgb565Pixel` successor. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Range and Boundary Evidence | incorporate | applied |
| [x] | C0002YO-005 | 0002YO | Incorporate two target refs, five slot refs, two return-ignoring consumers, registration paths, `m_fadeStep +0x5ac`, and endpoint writers. | 98 | Dated 2026-08-14 xref queries, caller disassembly, ScreenPane type, and transition disassembly. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Xrefs, Callers, Fields | incorporate | applied |
| [x] | C0002YO-006 | 0002YO | Preserve owner/emitter UID0000OC and source placement in `NexusTK/render/Surface.cpp`; reject ScreenPane and SoftwareBlend16 ownership. | 97 | Provider family, initializer, semantic global, consumers, and sibling callback placement. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Ownership and Source Placement | incorporate | applied |
| [x] | C0002YO-007 | 0002YO | Insert the complete Section 22 file-local behaviorally exact RGB565 callback into formal CPP. | 96 | Exact case formulas, ABI, loop equivalence, source-family style, and pre-callback generated empty marker. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C0002YO-008 | 0002YO | Keep formal H blank because the provider is file-local and UID0000TN already owns the shared typedef and extern. | 98 | Existing Surface.h and UID0000TN formal H; provider registration and linkage. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / RECONSTRUCTION_H CODE | already-present | already-present |
| [x] | C0002YO-009 | 0002YO | Raise metadata from 87/90 to 94/95 while preserving canonical owner, reconstructable state, and emitter route. | 96 | All evidence-recorded blockers closed; exact formal source supplied; residual lexical/compiler-scheduling uncertainty. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / metadata and Score Rationale | incorporate | applied |
| [x] | C0002YO-010 | 00016L | Mark UID0002YO source-ready in the non-emitting RGB565 family inventory and remove its stale dedicated-pass blocker without changing aggregate route or score. | 97 | Exact child closure and dated 2026-08-14 pre-callback aggregate row. | by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md / Item Summary, inventory, split backlog | incorporate | applied |
| [x] | C0002YO-011 | 0000OC | Replace the stale no-active-marker target row and add exact source-ready slot-11 RGB565 closure while preserving Surface 90/89. | 97 | Pre-callback generated empty marker, initializer, source placement, and exact callback closure. | by-file/Surface.md / callback inventory and slot-11 source closure | incorporate | applied |
| [x] | C0002YO-012 | 0002V6 | Correct the UID0002YO constant-pool consumer closure to the exact slot-11 contract: only `pixels`, `pixelCount`, and signed ordinal `fadeStep`; linear in-place packed-pair/odd-tail traversal; no separate mode, source/destination row, or stride inputs; preserve compiler-covered no-table emission and 92/94. | 98 | UID0002YO ABI, caller-selected buffer, and exact packed-pair/odd-tail body; physically reread UID0002V6 lines 118, 220, and 226 after scoped validation. | by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md / consumer closure and score rationale | incorporate | applied |
| [x] | C0002YO-013 | 0000TN | Add exact RGB565 provider behavior to semantic slot 11 while preserving existing typedef/global formals and 94/95. | 98 | Dated 2026-08-14 typed-global snapshot, provider refs, consumers, and complete formulas. | by-global/SurfaceRenderCallbackTable.md / slot 11 behavior | incorporate | applied |
| [x] | C0002YO-014 | 0001PI | Add exact RGB565 provider behavior to physical slot 11 while preserving covered-by-only CPP, blank H, and 92/94. | 98 | Physical storage, five xrefs, paired providers, and complete formulas. | by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md / slot 11 liveness | incorporate | applied |
| [x] | C0002YO-015 | 00039V | Mark both slot-11 providers source-ready and add RGB565 endpoint/formula behavior without changing authoritative initializer CPP or 91/93. | 98 | Existing exact assignment body and dated 2026-08-14 target-ref snapshot. | by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md / slot 11 selection contract | incorporate | applied |
| [x] | C0002YO-016 | 00039P | Replace paired-provider-only wording with exact RGB565 0..24 behavior while preserving ScreenPane route, blank formal body, and 90/93. | 97 | Exact call arguments, ignored return, target formulas, and field type. | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md / slot-11 fade-transfer call | incorporate | applied |
| [x] | C0002YO-017 | 00039T | Add exact RGB565 provider behavior to the retained presentation helper dependency without changing its independent reachability/source-placement state or 86/88. | 96 | Exact call contract and target closure; helper's separate zero-inbound evidence. | by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md / direct block-transfer path | incorporate | applied |
| [x] | C0002YO-018 | 0000CB | Extend the existing `m_fadeStep` relation to both exact providers without changing class layout, formals, owner, or 93/94. | 98 | Dated 2026-08-14 UDT-member snapshot and endpoint/caller evidence. | by-class/ScreenPane.md / fade-transfer relation and field rationale | incorporate | applied |
| [x] | C0002YO-019 | 0002YO | Preserve corrected history and mark prior below-85, unresolved-mode, pointer-return, standalone-table, and no-active-marker assumptions as superseded with reasons. | 96 | Dated 2026-08-14 documentation, IDA, and generated-state snapshots. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / Historical Assumptions and Changes | historicalize | applied |
| [x] | C0002YO-020 | 0000TN | Preserve existing `SurfaceTransferPixelsProc` and `g_pfnTransferPixels` CPP/H definitions exactly; do not duplicate or recreate them for UID0002YO. | 99 | Dated 2026-08-14 UID0000TN formal and generated Surface.cpp/Surface.h snapshots. | by-global/SurfaceRenderCallbackTable.md / formal CPP and H | already-present | already-present |
| [x] | C0002YO-021 | 0002YO | Supervisor Gate 2B applied and verified the rename from `sub_4C4790` to `SoftwareRenderRgb565BlockTransferCallback` with protected range/body/xrefs. | 97 | Final post-save name readback and preserved literal prestate in Section 21 I01. | IDA function 0x004c4790 / name | incorporate | APPLIED_VERIFIED |
| [x] | C0002YO-022 | 0002YO | Supervisor Gate 2B applied and verified the exact void cdecl mutable-pixel/count/fadeStep type, complete five-row frame, and zero locals. | 98 | Final post-save normalized type/frame readback and Section 21 I02. | IDA function 0x004c4790 / function type and stack frame | incorporate | APPLIED_VERIFIED |
| [x] | C0002YO-023 | 0002YO | Supervisor Gate 2B applied and verified only the exact repeatable function-entry semantic comment; the other three comment channels remain blank. | 96 | Final post-save four-channel comment readback and preserved literal prestate in Section 21 I03. | IDA function 0x004c4790 / repeatable address comment | incorporate | APPLIED_VERIFIED |
| [x] | C0002YO-024 | 0002YO | Supervisor Gate 2B verified no change to `jpt_4C47BD` at `[0x004c5fe0,0x004c6044)`, its regular comment, 25 entries, corrected SHA256 `2CB3D7205A724188602A7ADB2F94ACA0A81D1CE4A1FD1886FC4190571BC59B43`, and inbound ref. | 99 | Final no-change item/comment/xref readback plus canonical 100-byte hash. | IDA data 0x004c5fe0 / jump table | already-present | NO_CHANGE_VERIFIED |
| [x] | C0002YO-025 | 0000TN | Supervisor Gate 2B verified no change to `g_pfnTransferPixels` at 0x0069b40c, type `SurfaceTransferPixelsProc`, four zero bytes, five inbound refs, and blank address comments. | 99 | Final no-change global/type/byte/xref/comment readback with one-byte item-head projection caveat preserved. | IDA global 0x0069b40c / slot 11 | already-present | NO_CHANGE_VERIFIED |
| [x] | C0002YO-026 | 0002YO | Supervisor coverage readback verified the current 94-percent source-ready UID0002YO by-memory row exactly matches Section 28. | 99 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID0002YO row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-027 | 00016L | Supervisor coverage readback verified the current aggregate row includes UID0002YO among source-ready children and preserves 90 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID00016L row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-028 | 0002V6 | Supervisor coverage readback verified the current constants row credits both exact transfer consumers and preserves 92 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID0002V6 row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-029 | 0001PI | Supervisor coverage readback verified the current physical callback-table row includes exact source-ready RGB565 behavior and preserves 92 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID0001PI row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-030 | 0000OC | Supervisor coverage readback verified the current Surface row includes source-ready UID0002YO and preserves 90 percent exactly as Section 28. | 98 | Current exact row comparison and by-file command `000000023598`, exit 0, `ok:1`. | by-file/-coverage-report.md / UID0000OC row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-031 | 0000TN | Supervisor coverage readback verified the current semantic callback-table row includes exact RGB565 body closure and preserves 94 percent exactly as Section 28. | 98 | Current exact row comparison and by-global command `000000023599`, exit 0, `ok:1`. | by-global/-coverage-report.md / UID0000TN row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-032 | 00039V | Supervisor coverage readback verified the current initializer row identifies both slot-11 providers as source-ready and preserves 91 percent exactly as Section 28. | 98 | Current exact row comparison and by-memory command `000000023597`, exit 0, `ok:1`. | by-memory/-coverage-report.md / UID00039V row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-044 | 0000CB | Supervisor coverage readback verified the current ScreenPane row names both source-ready slot-11 providers in its `m_fadeStep +0x5ac` relation exactly as Section 28. | 98 | Current exact row comparison and by-class command `000000023600`, exit 0, `ok:1`. | by-class/-coverage-report.md / UID0000CB row | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0002YO-033 | 0002YO | Run scoped file validation after target callback implementation and record command ID, timestamp, exit code, ok count, side effects, and reread hash. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md / validator receipt | incorporate | applied |
| [x] | C0002YO-034 | 00016L | Run scoped file validation after aggregate synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md / validator receipt | incorporate | applied |
| [x] | C0002YO-035 | 0000OC | Run scoped file validation after Surface synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-file/Surface.md / validator receipt | incorporate | applied |
| [x] | C0002YO-036 | 0002V6 | Run scoped file validation after constant-pool synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md / validator receipt | incorporate | applied |
| [x] | C0002YO-037 | 0000TN | Run scoped file validation after semantic callback-table synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-global/SurfaceRenderCallbackTable.md / validator receipt | incorporate | applied |
| [x] | C0002YO-038 | 0001PI | Run scoped file validation after physical callback-table synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md / validator receipt | incorporate | applied |
| [x] | C0002YO-039 | 00039V | Run scoped file validation after initializer synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md / validator receipt | incorporate | applied |
| [x] | C0002YO-040 | 00039P | Run scoped file validation after first consumer synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md / validator receipt | incorporate | applied |
| [x] | C0002YO-041 | 00039T | Run scoped file validation after second consumer synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md / validator receipt | incorporate | applied |
| [x] | C0002YO-042 | 0000CB | Run scoped file validation after ScreenPane synchronization and record full receipt/readback. | 99 | Dated 2026-08-14 historical validator receipt. | by-class/ScreenPane.md / validator receipt | incorporate | applied |
| [x] | C0002YO-043 | 0002YO | Supervisor generated readback verified UID0002YO has no empty marker, its CPP body appears once in Surface.cpp, its H emits no duplicate declaration, and existing UID0000TN declarations remain single. | 99 | Current Surface.cpp/Surface.h hashes, sizes, line counts, and command `000000023596` receipt. | auto-generated/NexusTK/render/Surface.cpp and Surface.h / read-only generated verification | already-present | ALREADY_PRESENT_VERIFIED |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000023601","destination_path":"executed-b-agent-research/B001/0002YO-SoftwareRenderRgb565BlockTransferCallback-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002YO-SoftwareRenderRgb565BlockTransferCallback-empty-emitter-source-quality.md","timestamp":"2026-08-14T17:45:20-04:00","uid":"0002YO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
