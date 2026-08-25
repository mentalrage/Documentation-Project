** TARGET-REPORT-UID:0001G9 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001G9 Screenshot Capture And Proof Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation and ordinary implementation: [UID:0001G9] `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md` remains split into exact [UID:0004WM] BMP, [UID:0004WN] PNG, and [UID:0004WO] proof-function by-memory children. UID0001G9 remains the detailed non-emitting range index over those children and its two internal padding spans after the 2026-07-24 ordinary-state drift audit.
- Current disposition: UID0001G9 is `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000ND`, `RECONSTRUCTABLE:FALSE`, with blank `EMITTER_UIDS`, blank optional position, blank CPP and H channels, and exact `Nested:5`. The three exact children alone carry the source bodies.
- Allocation and routing: validator commands `17095`, `17096`, and `17097` allocated [UID:0004WM] BMP `[0x00557aa0,0x00557e73)`, [UID:0004WN] PNG `[0x00557e80,0x00558239)`, and [UID:0004WO] proof `[0x00558240,0x00558391)` in target-first order. BMP/PNG are semantically attached to [UID:0000CB] `ScreenPane`; all three definitions route through [UID:0000ND] `ScreenshotCapture.cpp` after the corrected JPG child.
- Applied source shape and channel correction: `ScreenPane::SaveScreenshotJPG/BMP/PNG` are instance methods implemented in `NexusTK/render/ScreenshotCapture.cpp`; `SendScreenshotProofPacket(FILE *)` is a file-local `static void __stdcall` helper. `ScreenshotCapture` is a non-emitting source-family/module label, not a runtime class. Gate 1 SHA `DE516F8F1BAF24F77B1D60AB6BA208389E1BFF96C923411B0806F7D5545289C4` authorized the narrow source-channel callback. Commands `17386`, `17389`, `17391`, `17392`, `17393`, `17395`, and `17397` scoped-validated the seven accepted ordinary destinations serially. UID0001G9 remains blank in CPP/H; UID0004WM/UID0004WN/UID0004WO/UID0001G8 retain their exact definitions in CPP with blank H; UID0000VF retains its file-local declaration in CPP with blank H; and UID0000CB now has blank CPP plus its complete class declaration byte-for-text unchanged in H. Validator-owned command `17440`, refreshed `2026-07-24T22:15:48-04:00`, is the bounded current generated observation: `ScreenshotCapture.cpp` preserves one declaration and one JPG/BMP/PNG/proof definition in order with zero family empty markers, `ScreenPane.h` contains the complete class declaration once, and `ScreenPane.cpp` contains zero complete `class ScreenPane :` declarations while retaining the one validator-owned UID0000CB blank-CPP marker. Independent concurrent additions remain preserved at same-or-greater detail.
- Confidence: very strong for bytes, boundaries, ABI, callers, callees, hotkeys, image conversion, packet layout, cleanup order, ownership, and split. Exact original identifier spelling and the historical capitalization `ScreenshotCapture.cpp` versus `ScreenShot.cpp` remain inferred and keep the recommendation below final-audit scores.
- Lifecycle: after the historical initial callback and drift-reconciliation cycles, supervisor Gate 1 passed exact report SHA `9747ABACFFD7A9038DEF33E5635A4FC4D2A6DA9341BDC49525541B5098E096DD` for the focused C1G9-023 callback, and later Gate 1 passed exact SHA `DE516F8F1BAF24F77B1D60AB6BA208389E1BFF96C923411B0806F7D5545289C4` for this narrow source-channel migration. B004 incorporated the accepted proof-mask distinction under commands `17286` through `17291`, then completed the exact CPP/H disposition callback under commands `17386` through `17397`; every scoped command exited `0` with `ok:1`, and every short lease was released. Bounded current generated command `17440` confirms the post-migration source channels and unchanged screenshot/proof bodies. Supervisor Gate 2A then passed exact report SHA `57A4036FFFF29A0896A5D0F593BE609AB97BCFA81A5B049C670246E9A7F0B8E5` after independently verifying all seven ordinary destination hashes and command-17440 invariants. Supervisor Gate 2B used exact saved-IDB prestate `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, applied and mechanically verified every accepted action while preserving every no-change/protected row, saved successfully, and produced poststate SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331` at `2026-07-24T22:54:09.6318603-04:00`. B004 made no IDA mutation, edited no manual `-coverage-report.md`, and ran no report lifecycle command. Gate 2A and Gate 2B are complete; only manual supervisor coverage application if still required and supervisor-only execution/archive remain pending.

## Supporting Research

- Live IDA MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Gate 2B MCP authority: session `supervisor_current_20260724_9f6e`, exact IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`. The supervisor used the same healthy session for mutation and deterministic readback after B004's read-only 9DF4 audit.
- Exact Gate 2B pre-mutation authority: SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, 143,186,002 bytes, saved `2026-07-24T22:09:37.3164487-04:00`. Verified byte-identical backup: `E:\NTK\Resources\NexusTK\NexusTK.exe.uid0001g9.pre-gate2b.20260724_224938.i64`, SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, 143,186,002 bytes. B004's complete 20-primary-row plus five-protected-dependency-row audit was enclosed by stable before/after hashes at this exact prestate.
- Exact Gate 2B saved poststate: MCP `idb_save` returned `ok:true`; `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` became SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`. The supervisor's post-save mechanical verifier passed all 25 primary/protected rows, ten exact global-name matches, both pooled-literal interior-parent rows, and every required boundary, type, four-channel function-comment state, item-comment state, and xref total.
- Current proof-mask protected state after Gate 2B remains one item headed at `0x006232e0`, ending at `0x00623301`, named `ScreenshotProofMaskLiteral`, typed `const char[33]`, with absent regular comment and the exact repeatable comment recorded in the IDA table. Interior queries `0x006232f0` and `0x00623300` still resolve to the parent, and the three unchanged data references remain at `0x00558253`, `0x00558269`, and `0x0055825d`.
- Historical revision evidence only: UID0003CJ was first applied and saved at IDB SHA256 `BB95C8268208A62AC39955CE34A7D51495523F606500124C955CFB0D0AFCBFC7`; later complete-table audits used saved revisions `8C59555478FAD4C784B992478CA08E805AEC276D9A848BB7923FA4F8BD481ED1`, `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`, `F28C8B463F64693561E118790FD5E9D68739F85C697B9B58F391F56E1911ED99`, `EF0E6C656CE837EE350D347D93BD7967B73E556CB4582EEB80ADE241A9CACC2E`, `D99CF538F565D8D19F2BA24510FE71A2D58969E79BA4379BBDAD9C9D2A4573A8`, `48EBC47071A99F8E90D2B639724A67CCB2ABA32FD34A776CA894471AE3CD8BED`, `B6A2BD3E2D92B9E77CFB82660F87E71D3709BC2D80C777140D9762234684A138`, `9F6E2C7AA9CFB718AB146AC8F8363CC1401F8474AA63803D7FAED35FA8ADE7CF`, and `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E`. Those hashes and retired session `1ce787ed` are bounded historical research checkpoints only. The 9DF4 revision is now the exact historical UID0001G9 Gate 2B pre-mutation checkpoint; the applied/saved UID0001G9 Gate 2B poststate is 7509EC84.
- Exact target bytes: 2289 bytes for `[0x00557aa0,0x00558391)`, SHA256 `A10232950713E44B45F25D567B0F0646F44DC2EF5BC183AE5544A84966D9591E`.
- Read-only live-IDB child hash recheck on 2026-07-24: BMP `[0x00557aa0,0x00557e73)`, 979 bytes, SHA256 `44EF1F5A09AA9DCDA51587F5FBA1EC75223BD7A78708980ECA6A14BC700FEDAC`; PNG `[0x00557e80,0x00558239)`, 953 bytes, SHA256 `7E8CE02FD7894A68D7C6A1012176B9B2767DBDC18F092C0724D0202B202B44FD`; proof `[0x00558240,0x00558391)`, 337 bytes, SHA256 `CA5329647821C90BFC1D31BD0C74E6134C985784D085F772F466583FCA6E0DFE`.
- Historical pre-callback target-document checkpoint: 18,528 bytes, SHA256 `2AD6671D9D915CBF4E9BABD348CD3FF7C35669043B3D434744ADCBE29C853E0A`. Historical post-drift/pre-focused target hash was `9F078AF25957AAD6D7F70329A03357C1BC7C23A450B3E23B6B691A5EDEEF1B99`; focused command `17288` produced target hash `838AB03186C98DB750E5CB9661B0AE13A201CB22AB0C20B05F209AF01F50C18B` after adding only the accepted C1G9-023 distinction. The current target hash is `15AB14C52C31C90AB7BC4097433FA508C9EC07DFC836DB56763AE62FAF640FBB`; removing only its two validator-owned empty H-channel header lines reconstructs the focused hash exactly.
- Current ordinary-state drift audit: all affected destinations were re-read after their hashes diverged from the original callback checkpoint. The current table below proves the seven formal destinations, ScreenshotCapture class, SurfacePresentation, EventDispatcher memory/class, BrowserControlPane memory/class, ScreenPane resource strings, QueueAndSendPacket, and `g_packetSender` differ from their recorded checkpoints only by the two validator-owned empty H-channel header lines: removing exactly those lines reproduces each earlier SHA256. ScreenshotCapture file, ScreenPane file, EventDispatcher file, and LodePNG file are byte-identical to their earlier checkpoints. `by-memory/-ignored.md` has a substantive later concurrent change, but the four screenshot spans, exact counts, UID0001G9 internal/external topology, and source exclusion remain present at same-or-greater detail. UID0003CJ additions expanded literal-pool evidence. The proof child and ScreenshotCapture class/file previously carried stale three-head wording; those pages plus UID0003CJ were reconciled to the already-applied one-item `ScreenshotProofMaskLiteral` state under scoped commands `17261`, `17263`, `17264`, and `17266`. No accepted ordinary claim was lost.
- Focused C1G9-023 callback: UID0004WO, UID0000VF, UID0001G9, ScreenshotCapture class/file, and UID0003CJ were each re-read, found incomplete at different parts of the accepted distinction, updated without pruning existing behavior/history/concurrent work, scoped-validated under commands `17286` through `17291`, and re-read at the exact current hashes recorded below. The formal `char proofMask[36]` and 32-iteration loop were already correct and were not rewritten.
- Shared B002 reconciliation: current `by-class/ScreenPane.md` and `by-file/ScreenPane.md` preserve all three screenshot declarations/routes and additionally contain accepted UID0003A4 `ScreenPane::BlitSurfaceToDisplay` work. B004 did not overwrite or remove that concurrent detail; the complete ScreenPane formal later in this report is synchronized to the current superset.
- The historical B005 UID0001G8 report was used as an evidence lead, not copied as authority. Its JPG endpoint statement was rechecked and one byte of current range metadata is wrong: the return opcode is at `0x00557a95`, so the source body is half-open `[0x00557840,0x00557a96)`, followed by ten `0xcc` bytes.
- Wave2/Wave3 mentions in old screenshot documentation were ignored as stale workflow labels. Current live IDA and current by-structure rules control this recommendation.

## Target

- Target UID: `0001G9`.
- Additional target UIDs: none. UID0001G8, UID0000VF, UID0000CD, UID0000CB, and UID0000ND are support pages, not additional report targets.
- Declared-target inventory: one target, `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md`. Historically it was a source-bearing three-function aggregate with blank formal C++; it is now the validated non-emitting exact-range index with `Nested:5` and exact source-bearing children UID0004WM/UID0004WN/UID0004WO.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`, assignment-time `87/89`, report count zero.
- Current supervisor classification: implemented split screenshot workflow attached to [UID:0000ND], with exact child emitters and no empty UID0001G9/UID0000CD generated markers.
- Assigned report path: `tools/leaser/Agents/Agent-B004/research/0001G9-ScreenshotCaptureAndProof-source-quality.md`.

## Current Target State

- Historical pre-callback metadata: `87/89`, `CANONICAL_OWNER:0000ND`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ND`, blank position, blank formal C++, `Nested:0`.
- Historical pre-callback C++/emitter state: generated `auto-generated/NexusTK/render/ScreenshotCapture.cpp` contained UID0001G9 only as an Empty Emitter Marker. That state was structurally wrong because the page contained three exact functions and two internal padding spans.
- Current metadata/emitter state: UID0001G9 is `93/94`, false/non-emitting, and `Nested:5`; UID0004WM/UID0004WN/UID0004WO carry the exact BMP/PNG/proof bodies at positions `20/30/40`, UID0000VF carries the proof declaration at position `5`, and corrected UID0001G8 carries JPG at position `10`.
- Current owner state: BMP and PNG are [UID:0000CB] `ScreenPane` methods emitted through [UID:0000ND]; proof is a ScreenshotCapture file-local helper owned/emitted by [UID:0000ND].
- Historical stale claims, now corrected in the implemented docs:
  - `this+0x18` and `this+0x108` are called surface IDs. Current GrafPort/ScreenPane documentation and live code show DirectDraw surface pointers: inherited `m_ddSurface` and `ScreenPane::m_renderSurface`.
  - the optional browser call is described as a generic sync/flush. Live decompilation proves `BrowserControlPane::BlitBrowserSurfaceToRenderTarget(LPDIRECTDRAWSURFACE)` behavior.
  - the status byte is sometimes called chat suppression or `g_pMetaMan` state. The exact storage is [UID:00028L] `g_pEventMan + 0x920`; `EventMan::GetModifierState` reads that byte and screenshot code directly clears/restores it.
  - proof padding is summarized as 16 generic random bytes. The first byte is specifically `(rand() % 10) - 26`; only the following fifteen use `rand() % 255`.
  - the packet terminator is not distinguished from sent payload. `packet[49] = 0` is local-only; the send length is exactly 49.
  - the current target leaves class/free-helper shape and names unresolved even though ABI and call sites now resolve them to two `ScreenPane` methods plus one file-local `__stdcall` helper.
- Related docs checked: ScreenshotCapture by-file/by-class, ScreenPane by-file/by-class/global, JPG/BMP/PNG/proof children, proof item, UID0003CJ data page, ignored spans, GrafPort paint children, LodePNG encode front end, MD5 helpers, PacketBuffer scalar writers, Socket queue/send, EventMan, ChattingPane, BrowserControlPane, image-writer/JPEG pages, source-tree docs, manual coverage rows, current generated source, and archived UID0001G8 research.
- Current artifact status: post-channel-migration implementation report after supervisor Gate 2A and Gate 2B completion. Gate 2A passed exact report SHA `57A4036FFFF29A0896A5D0F593BE609AB97BCFA81A5B049C670246E9A7F0B8E5` and independently verified all seven ordinary destinations plus command-17440 generated invariants. Gate 2B preserved 9DF4 as the backed-up exact prestate, applied all accepted UID0001G9 function/instruction/global/alignment actions, reread all no-change/protected rows unchanged, mechanically verified all 25 primary/protected rows, and saved poststate 7509EC84. C1G9-023 remains `APPLIED_VERIFIED` across all six affected ordinary pages. UID0000CB CPP is blank and its complete declaration body remains H-only with `[[CHILDREN]]` exactly once. Manual supervisor coverage and execution/archive remain outside B004's authority and are not claimed complete.

## Executive Recommendation

The following accepted recommendation is now implemented and scoped-validated:

1. UID0001G9 is a non-emitting semantic/range index. The parent aggregate does not emit child bodies.
2. The three exact by-memory children are created:
   - `by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md`.
   - `by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md`.
   - `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md`.
3. BMP/PNG have `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ND`, and positions `20` and `30`.
4. Proof has direct owner/emitter `0000ND`, reconstructable true, and position `40`.
5. UID0001G8 has corrected half-open endpoint `0x00557a96`, canonical owner `0000CB`, emitter `0000ND`, and position `10`.
6. UID0000VF emits only the file-local forward declaration at position `5`; exact proof child UID0004WO emits the sole definition at position `40`.
7. UID0000CD `by-class/ScreenshotCapture.md` is a non-reconstructable source-family index with no emitter. It does not represent a concrete source class.
8. UID0000CB's complete `ScreenPane` class declaration contains `SaveScreenshotJPG/BMP/PNG`; this report now places that declaration in H and requires CPP to remain blank because class declarations are header output, while method definitions remain owned by their exact by-memory pages.
9. All three internal/external alignment spans are recorded through the existing [UID:0000VN] ignored-page route rather than invented as source.
10. Supervisor Gate 2B applied and verified the complete UID0001G9-specific function/instruction/global/alignment handoff below against exact 9DF4 prestate and saved exact 7509EC84 poststate. The accepted UID0003CJ proof-mask consolidation and all no-change/protected dependencies remained unchanged. B004 did not alter IDA.
11. Current UID0003CJ/B002 destination drift is additive and preserved. The applied complete ScreenPane H formal retains B002's private `BlitSurfaceToDisplay` declaration while the screenshot declaration/source route remains unchanged; the channel move did not overwrite or rewrite concurrent content.

## Supervisor Active Recheck

- The report-only phase boundaries were followed. Historical Gate 1 SHA `7F1572EED6B0A4929E5EC19651EC72CFB2603471C73DC20CB6329E5EAC549442` authorized the original ordinary callback, and Gate 1 SHA `9747ABACFFD7A9038DEF33E5635A4FC4D2A6DA9341BDC49525541B5098E096DD` authorized the focused C1G9-023 callback. IDA mutation, manual coverage edits, and lifecycle commands remained forbidden and were not performed by B004; the later IDA mutation/save was supervisor-owned Gate 2B work recorded separately below.
- The target requires split repair before source can be emitted correctly. Three understood function bodies may not remain hidden in a broad aggregate.
- Every source-bearing child is implemented and scoped-validated. No child is deferred to a vague later investigation.
- The adjacent JPG path was rechecked because it calls the proof helper and establishes source order. Its endpoint repair is included as required support work rather than treated as a reason to stop.
- The revoked-pass drift audit re-read every named destination rather than trusting callback-era hashes. It found no lost C1G9 implementation; the only stale current-state prose was merged without overwriting UID0003CJ or B002 work.

## Inference Research Guidance Check

- Direct IDA fact, documentation evidence, and inference are separated throughout this report.
- Existing docs were treated as hypotheses where they used raw names, generated source-family labels, stale surface-ID language, or old no-code blockers.
- The narrowest-owner rule changes BMP/PNG canonical ownership from ScreenshotCapture file to ScreenPane class while preserving ScreenshotCapture as the output source file.
- The aggregate rule requires exact children to emit source. UID0001G9 is therefore an index after the split, not a code object.
- The source reconstruction standard requires behaviorally exact, human-written C++03. Raw `sub_*`, `dword_*`, numeric member offsets, and decompiler return guesses are not accepted merely because symbols are absent.
- Consistent current project spellings are used: `ScreenPane`, `m_ddSurface`, `m_renderSurface`, `m_surfaceContext`, `g_pScreenPane`, `g_pEventMan`, `g_pChattingDisplayPane`, `g_activeBrowserControlPane`, `g_surfaceUsesRgb565Pixels`, `Md5StreamHex`, `PacketBufferWriteUInt8`, and `QueueAndSendPacket`.
- Wave2/Wave3 workflow references were found in support history and ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Best resolution | Status |
| --- | --- | --- | --- |
| BMP/PNG receiver | Event dispatcher loads `g_pScreenPane` into `ECX`; both callees read ScreenPane/GrafPort fields and return with plain `retn`. | `void ScreenPane::SaveScreenshotBMP()` and `void ScreenPane::SaveScreenshotPNG()`. | resolved, high probability |
| Decompiler return types | BMP is guessed `FILE *`; PNG is guessed `int`, but early exits preserve unrelated HRESULT, error-code, pointer, and `fclose` residues, while all callers ignore EAX. | Human source return is `void`; inconsistent residual EAX is not a meaningful contract. | resolved, strong inference |
| Proof ABI | One `FILE *` stack argument, no receiver read, epilogue `retn 4`. | `static void __stdcall SendScreenshotProofPacket(FILE *stream)`. | resolved, direct ABI plus inference |
| ScreenshotCapture class | No vtable, constructor, allocation, instance field, or receiver exists for a `ScreenshotCapture` object. | Treat as source-family/index only; do not emit a fake class. | resolved |
| Source file | JPG/BMP/PNG/proof are contiguous and share path/status/proof behavior; EventDispatcher, ScreenPane, MD5, LodePNG, JPEG, Browser, and Socket are callers/dependencies. | `NexusTK/render/ScreenshotCapture.cpp`. | resolved, high probability |
| Source order | Physical order is JPG, BMP, PNG, proof. Proof is called before its definition. | Forward-declare proof, then emit JPG position 10, BMP 20, PNG 30, proof 40. | resolved |
| Surface fields | `+0x18` is inherited GrafPort DirectDraw surface, `+0x20/+0x28/+0x2c..+0x50` are surface context, and `+0x108` is ScreenPane render surface. | `m_ddSurface`, `m_surfaceContext.pixelData`, `rowStridePixels`, `bounds`, `m_renderSurface`. | resolved from accepted support docs and live calls |
| Browser helper | Live body obtains the destination surface DC, BitBlts/StretchBlts the visible browser HWND, and releases the DC. | `BrowserControlPane::BlitBrowserSurfaceToRenderTarget(m_ddSurface)`. | resolved, descriptive source name |
| Wide formatting | `0x004236e0`, `0x0045ef20`, and `0x00559af0` are accepted non-emitting fixed-count MSVC/UCRT specializations. | Use caller-local `swprintf_s` expressions, not invented project helpers. | resolved |
| Event byte | `EventMan::GetModifierState` copies `this+0x920`; screenshot callers directly zero and restore the same byte. | `m_modifierState` is the best field name; retain exact direct save/clear/restore. | resolved for draft, inferred spelling |
| BMP pixel format | `g_surfaceUsesRgb565Pixels` branch converts each 565 word to BMP-compatible 555 using `(p & 0x1f) | ((p >> 1) & 0x7fe0)`. Other branch writes source words directly. | Preserve exact branch and bottom-up rows. | resolved |
| PNG pixel format | True branch takes red at bit 11 and green at bit 6; false branch takes red at bit 10 and green at bit 5; both use 5-bit channels expanded by `<<3`, blue low five bits, alpha 255. | Preserve two exact conversion loops, top-down rows. | resolved |
| Proof digest | MD5 stream helper returns a 32-character heap hex string. The fixed literal `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE` is exactly 32 characters; IDA pools those characters plus the terminating NUL as one 33-byte item `[0x006232e0,0x00623301)`. Source inference is `char proofMask[36]`, so aggregate initialization leaves three additional trailing zero-initialized bytes after the terminator, and the loop XORs only indices `0..31`. | `char *maskedDigest` and local `char proofMask[36]`; fixed 32-character key, 33-byte pooled literal item, three additional trailing zeros, 32-byte XOR. | resolved |
| Proof random block | First random byte is constrained/wrapped, later fifteen are `%255`. No semantic source name is proved. | `randomPadding[16]`; document first-byte asymmetry instead of inventing nonce semantics. | resolved |
| Packet size | 1 opcode + 13 digest + 16 random + 19 digest = 49 sent bytes; local zero follows at offset 49. | `unsigned char packet[128]`, send 49, terminator unsent. | resolved |
| Error behavior | Directory failures return; BMP output-open failure returns; PNG allocation/conversion/encode errors are unchecked; proof reopen is unchecked; BMP writes and PNG encode result are unchecked. | Preserve missing checks exactly; do not modernize. | resolved |
| JPG endpoint | Return byte at `0x00557a95`, ten CC bytes at `0x00557a96-0x00557aa0`. | Rename/support range to half-open end `0x00557a96`. | resolved |
| Aggregate versus split | Three functions plus two padding spans are independently understood. | Exact child split; UID0001G9 false/non-emitting index. | resolved |

Rejected alternatives:

- A concrete `ScreenshotCapture` class is rejected by absence of object evidence.
- Free BMP/PNG helpers taking `ScreenPane *` are weaker than direct thiscall method evidence.
- EventDispatcher ownership is rejected because it only selects hotkeys.
- ScreenPane.cpp ownership is rejected for definitions because the contiguous format/proof cluster is a dedicated feature module and current source-tree documentation already routes it to ScreenshotCapture.cpp.
- ImageWriters ownership is rejected for the workflow. It owns the project JPEG writer dependency, while LodePNG owns the PNG API.
- MD5, PacketBuffer, and Socket ownership are rejected for proof construction because they are generic dependencies.
- Keeping the aggregate emitter is rejected by current exact-range child-emission rules.
- Leaving source-bearing CPP implementation channels blank is rejected because all behavior, ABI, owner route, and source-facing names now have defensible resolutions. Target-specific H channels remain blank where declarations are centralized in UID0000CB H or the construct is file-local/non-emitting.

## Evidence Standards Used

- Live IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `decompile`, `analyze_function`, `xrefs_to`, and direct caller/callee readback.
- Raw bytes: exact full-range hash, per-function hashes, CC padding checks, predecessor return/padding, and successor start.
- ABI: ECX receiver use, stack arguments, `retn` versus `retn 4`, caller EAX use, and inconsistent residual-return evidence.
- Existing documentation: current by-* pages and accepted source-facing names/types.
- Historical research: archived UID0001G8 report, revalidated against current bytes and docs.
- Negative evidence: no concrete ScreenshotCapture object, no proof-helper receiver, no external proof consumer, no justification for aggregate source emission, and no source basis for defensive error checks.
- Confidence is below 95 because stripped original symbols, exact historical file spelling, and several identifier spellings remain inferred even though their behavior and types are strong.

## Evidence Checked

- Historical 9DF4 pre-mutation IDA MCP/manual checks; current 7509 poststate names/types/comments are recorded in the Gate 2B poststate table:
  - `sub_557AA0` exact size `0x3d3`, callers `0x004a71b6` and `0x004a7250`.
  - `sub_557E80` exact size `0x3b9`, callers `0x004a71d1` and `0x004a7296`.
  - `sub_558240` exact size `0x151`, xrefs `0x00557a78`, `0x00557e55`, and `0x0055821b`.
  - successor `sub_5583A0` starts at `0x005583a0`, size `0x2da`, and is excluded.
  - full decompilation of BMP/PNG, full proof analysis/disassembly, hotkey dispatcher analysis, BrowserControlPane blit analysis, EventMan modifier getter analysis, and exact boundary bytes.
- Historical pre-callback doc hashes were target `2AD6671D...C853E0A`, JPG `635238D2...7DF5A1`, ScreenshotCapture by-file `E04D2BD6...87EB4`, ScreenshotCapture by-class `38410910...0EB2`, proof item `F1705318...09A9`, ScreenPane by-class `AFA09AA6...623B9`, and ScreenPane by-file `16D96EDF...075B`.
- Historical original post-callback core hashes, superseded as current identity where later accepted work changed the destination:
  - target `9F078AF25957AAD6D7F70329A03357C1BC7C23A450B3E23B6B691A5EDEEF1B99`;
  - BMP UID0004WM `19DF4B04F83528004A6F35A0BA08A1BC8A5F557FDAC81E8E513F6BC704DA8A66`;
  - PNG UID0004WN `0C5AD39DF21DB02198C3E8EDE3A00F22A5D1E272DC60FFE12195A903C2F6503B`;
  - proof UID0004WO `1632EE61F018A743BDBE69B3942CD3E0ECC3B0AB2568E419F23DE6FEFE51DEBA`;
  - JPG UID0001G8 `91653D7A29178F229B54A6256B3D3B1B461A66FC0540771E02840CC5A4A7D82D`;
  - proof item `83D996E8FF087A11AC089A94798C951AE7C136E2474A7EADA6C584F4532DCE09`;
  - ScreenshotCapture class/file `39A5A5899E352EC611946B785871A25F1960972FB07B6D630F08A374FC36D61D` / `93BF4898A0BE2F31DCCD9C95F12A224D13A8B852D64B8A86C781A9DBC16ED38F`;
  - ScreenPane class/file `2BD149C7B59ACD3645E131509E673174913FA2C8B9651888464F90B2D422778A` / `174DDB0A26D9F079CFA840A88240972687748BD326B994267733C829822CAD70`.
- Historical post-focused-callback core hashes are target `838AB03186C98DB750E5CB9661B0AE13A201CB22AB0C20B05F209AF01F50C18B`; BMP `0BB6267865135DC84B1E52475593A1E06BCBE61B761575E86AEA98EBB70CE9C9`; PNG `A00FED2488B7BE94D5DEEDA9D8ED858D70A014D82240E55E1A943A38C18F7080`; proof `444E4AC30C8B5149BC9C24BBF3F1F396D69AC5DE82D29D629B5A01CB32976851`; JPG `DDF3E84B32157FB5912EC90A8D35A8D5DA73014D4EEDD56822DA102FB843E468`; proof item `23E2CE1B40A0A850080FA349F9AF6EBCAA8B418D7DCABB63EC931FC11F8EDAB8`; ScreenshotCapture class/file `DAEBBE08CBEFC58F7730591755603DC01AD40E99B0F66DEEE5A66FC941328E86` / `3FCF32F41821D747A714A50DFAD5796C0B35637E40D5169661A3AD3B1A2E5AF0`; ScreenPane class/file `9F1F86A8A3F85CEAB93208580AC4753ACB7AF3810BC229924ED7444E566CE6B1` / `8A91FC37444ADE48F06AD0C78D2A782C8C949CA30634569A1094202B86E84B70`; ignored page `3C142D38CCB8F7F318F19D94CD24D77ACE942A82C8CCB4F297D159FC5E55C426`; and UID0003CJ data page `82417DB1B51CFBBA26CDDDD9F555FA599C6E701724037A50D3C1363D31B2B175`. They are not current identities after validator-owned H-header insertion and later concurrent ignored-page work.
- Focused generated checkpoint: deferred-refresh header command `17290` produced `auto-generated/NexusTK/render/ScreenshotCapture.cpp`, SHA256 `5F59CCFF387FF0979EE39AC33DBC624CEFF71BC7547BC77F2CA8B226B47CBA32`, 10,641 bytes, 271 lines. It remains the generated observation tied directly to the C1G9-023 callback.
- Historical generated observation: validator-owned foreground command `17324`, refreshed `2026-07-24T12:27:14-04:00`, SHA256 `DE8D407A6851C28866FF6E635A71412577165F991F91F9918D4A10C3EFBAEDDF`, 10,643 bytes, 271 lines. It is retained as a provenance checkpoint, not current physical identity.
- Historical bounded pre-channel-migration generated observation: validator-owned foreground command `17367`, refreshed `2026-07-24T20:02:22-04:00`, SHA256 `48F78BF41C23DB9128E169EAEA15EC9242F0F6BFD328DD55C04AFBDB9D29C550`, 10,643 bytes, 271 lines. Read-only inspection found exactly one proof forward declaration at line 8, JPG/BMP/PNG definitions at lines 11/73/167, and one proof definition at line 251. The proof body retained the exact 32-character literal in local `char proofMask[36]` and XORed only indices `0..31`. UID0001G9 and UID0000CD each occurred zero times, Empty Emitter Marker occurred zero times, and the five accepted UID rows were UID0000VF/UID0001G8/UID0004WM/UID0004WN/UID0004WO. Current post-channel-migration command17440 is recorded in Validator Results and Changed Files; commands17400/17414/17423 are historical post-migration provenance checkpoints.

Historical pre-channel-migration artifact table, captured read-only on `2026-07-24` before commands `17386` through `17397`. `H-header-only` means removing exactly the validator-owned empty `RECONSTRUCTION_H CODE:BEGIN/END` lines reproduced the recorded prior SHA256 byte for byte; `unchanged` was a direct hash match. `Substantive concurrent` means the hash had changed for unrelated work, so the relevant C1G9 facts were re-read rather than inferred from hash normalization. Current post-callback identities are recorded in `Changed Files` below.

| Historical pre-migration artifact | Historical SHA256 | Bytes / lines | Last write | Difference from earlier report checkpoint | C1G9 readback at that checkpoint |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md` | `15AB14C52C31C90AB7BC4097433FA508C9EC07DFC836DB56763AE62FAF640FBB` | 23,428 / 185 | `2026-07-24T19:57:11.0048280-04:00` | H-header-only; stripped SHA `838AB03186C98DB750E5CB9661B0AE13A201CB22AB0C20B05F209AF01F50C18B` | exact split/index, `Nested:5`, C1G9-023, and blank CPP preserved; H body blank |
| `by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md` | `9B00EB7DC952E554F8C9F024ADE2B323315730615FD73CE545B4EBF1BE4E070A` | 11,852 / 192 | `2026-07-24T19:57:10.9913969-04:00` | H-header-only; stripped SHA `0BB6267865135DC84B1E52475593A1E06BCBE61B761575E86AEA98EBB70CE9C9` | exact BMP CPP body preserved; H body blank |
| `by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md` | `685B2614676A98154F7240361CC366B607BA40E8CC5FE4DD346C2E082CD7164B` | 11,405 / 180 | `2026-07-24T19:57:11.0173411-04:00` | H-header-only; stripped SHA `A00FED2488B7BE94D5DEEDA9D8ED858D70A014D82240E55E1A943A38C18F7080` | exact PNG CPP body preserved; H body blank |
| `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md` | `DC695B0E789E711756F5C5F9DD35AEECDE86B0986536C0DDA7BE318C0D9C7310` | 10,761 / 127 | `2026-07-24T19:57:11.0380223-04:00` | H-header-only; stripped SHA `444E4AC30C8B5149BC9C24BBF3F1F396D69AC5DE82D29D629B5A01CB32976851` | exact proof CPP body and C1G9-023 preserved; H body blank |
| `by-item/ScreenshotProofPacket_00558240.md` | `45FAEEAA21B39F0B152FC52DA72B4548B18E9F4E615E2A4B2101BBE3FDAF83C4` | 13,132 / 102 | `2026-07-24T19:56:28.4260884-04:00` | H-header-only; stripped SHA `23E2CE1B40A0A850080FA349F9AF6EBCAA8B418D7DCABB63EC931FC11F8EDAB8` | file-local forward declaration remains CPP; H body blank |
| `by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md` | `C69CC913795D36C6437F4AEF2E1E465306BAD2F2546BA2F4565CEC085F07C53F` | 24,953 / 245 | `2026-07-24T19:57:10.9743958-04:00` | H-header-only; stripped SHA `DDF3E84B32157FB5912EC90A8D35A8D5DA73014D4EEDD56822DA102FB843E468` | exact JPG CPP body/end/route preserved; H body blank |
| `by-class/ScreenPane.md` | `9538A147DA818480CEB7CA10221C6129B10DFF38FA119DE14A698F300E84CB4F` | 62,130 / 394 | `2026-07-24T19:56:22.2436999-04:00` | H-header-only; stripped SHA `9F1F86A8A3F85CEAB93208580AC4753ACB7AF3810BC229924ED7444E566CE6B1` | complete declaration still in CPP and H blank; channel migration pending |
| `by-class/ScreenshotCapture.md` | `1F08514DBC4B10BBC46144A7D9FF5EE809CB8EA45675B56DC258F9C876B7707B` | 17,438 / 109 | `2026-07-24T19:56:22.2768083-04:00` | H-header-only; stripped SHA `DAEBBE08CBEFC58F7730591755603DC01AD40E99B0F66DEEE5A66FC941328E86` | non-emitting source-family evidence preserved |
| `by-file/ScreenshotCapture.md` | `3FCF32F41821D747A714A50DFAD5796C0B35637E40D5169661A3AD3B1A2E5AF0` | 24,226 / 181 | `2026-07-24T12:10:39.9879502-04:00` | unchanged | source route/order and C1G9-023 preserved |
| `by-file/ScreenPane.md` | `8A91FC37444ADE48F06AD0C78D2A782C8C949CA30634569A1094202B86E84B70` | 56,264 / 266 | `2026-07-24T10:53:38.9140512-04:00` | unchanged | cross-file screenshot route and B002 additions preserved |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | `12D4B4889BD787015FB47EA7A76122C183F8F6F5BD9281BFE6F66F693915EC26` | 59,544 / 249 | `2026-07-24T19:57:10.8521300-04:00` | H-header-only; stripped SHA `61F033FC374CAEBEE51C633BC80B6A704813D38C1AC6C73978DDF69398FCC0DF` | screenshot child inventory preserved |
| `by-memory/-ignored.md` | `D0602720E1B4FEFE956C3B73D9A5A798DB06D50C6324113B92FA257DC9ED854D` | 1,110,314 / 5,380 | `2026-07-24T12:29:04.4913435-04:00` | substantive concurrent | exact 10/13/7/15-byte screenshot spans, source exclusion, and `Nested:5` topology remain present |
| `by-file/EventDispatcher.md` | `D699E3EA9B270CE2CCC40667A066139FF77D2A279EB3316EB5348DA5D91AF56D` | 37,240 / 189 | `2026-07-24T08:33:15.2114467-04:00` | unchanged | hotkey routing preserved |
| `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` | `0C151AC041871D6FA39B4AFF68FA788D8CAFDB676CDC2A98A99CAAF690303A8B` | 43,370 / 332 | `2026-07-24T19:56:46.1030626-04:00` | H-header-only; stripped SHA `E809D2F9CCDCF8A4167284BB981786632B329A24B5EDD3B306680D07E2DD6A33` | hotkey routing preserved |
| `by-class/EventDispatcher.md` | `BDF5872E4BD226A5832F582B61DB41A2A8AF59737863A355FDE62B4FAD44BFC6` | 30,722 / 235 | `2026-07-24T19:56:17.3705177-04:00` | H-header-only; stripped SHA `C9F97523A1C4E6B8C9771B5D0E88E78F44FB2D7F0782231B01973F3DE432ABE5` | hotkey routing preserved |
| `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | `8DBAA2C587509B2BA0701757695D2D99F8A3AFA94A261E87D909AF6A0714A8B2` | 37,790 / 282 | `2026-07-24T19:56:36.0299432-04:00` | H-header-only; stripped SHA `F268BCDA4476BBA5ECD2C458EB0F87F745DA33FE9588EAD7E1D9FCE5ABBB4D7F` | browser blit dependency preserved |
| `by-class/BrowserControlPane.md` | `352B0528AFBD981A6BBB79D09E1A42D97F86D23E333F751727545288CAB6B8C5` | 31,751 / 189 | `2026-07-24T19:56:15.2103538-04:00` | H-header-only; stripped SHA `5A29A97F8E17363C05DFEC5C5B66102D35069006B198FB46B6BBD2E0E9DFFB45` | browser blit dependency preserved |
| `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md` | `CAB75859BD86803FEB0492D35C3A58D1E0687200C4EC7AB10FCF0071D5AC7496` | 14,797 / 118 | `2026-07-24T19:57:30.9424075-04:00` | H-header-only; stripped SHA `82417DB1B51CFBBA26CDDDD9F555FA599C6E701724037A50D3C1363D31B2B175` | literal/pool/source-shape evidence preserved |
| `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` | `07F58FAB8C240719965F3E3E749742FDD2D3DE750E46E1CB8EFE30BC0D0D3E9B` | 26,231 / 163 | `2026-07-24T19:57:14.3708165-04:00` | H-header-only; stripped SHA `0852C193249C561F59624D2E9499EEAA346391C860362F7AA74E0904DA7BC31F` | 49-byte send consumer preserved |
| `by-global/g_packetSender.md` | `F314835C1E016A2A566420C1404A517E39966528522ACAD050DC3D2022AAEDF4` | 34,793 / 206 | `2026-07-24T19:56:25.0962662-04:00` | H-header-only; stripped SHA `05B95D371B95883760D721B8C283FB23A659AA918DB3B13C58F416282C53F8DE` | packet-sender ownership/type preserved |
| `by-file/LodePNG.md` | `69779C724D4B5EF9C66D7C310608F29518923D7F16C3D6E2220B3F350DEA63B1` | 20,550 / 127 | `2026-07-24T08:38:54.7998853-04:00` | unchanged | direct stock API route preserved |
| `auto-generated/NexusTK/render/ScreenshotCapture.cpp` | `48F78BF41C23DB9128E169EAEA15EC9242F0F6BFD328DD55C04AFBDB9D29C550` | 10,643 / 271 | refreshed `2026-07-24T20:02:22-04:00` | validator provenance-header-only from command17324 | declaration/JPG/BMP/PNG/proof order, uniqueness, proof-mask formal, five UID rows, and zero aggregate/class/empty markers preserved |

Historical pre-callback formal comparison was exact: the report's UID0001G9, UID0004WM, UID0004WN, UID0004WO, UID0000VF, and UID0001G8 CPP and H bodies equaled their destination channels byte-for-text-byte. For UID0000CB, the report's proposed H body equaled the destination CPP body exactly, and the proposed blank CPP equaled the destination blank H body. The completed callback moved that same declaration body between channels without declaration rewrite, pruning, or concurrent-detail loss; current post-callback comparison is recorded below.
- Failed/unavailable checks: no original PDB/source tree exists. An early historical MCP health observation did not assert auto-analysis readiness, so no research claim was accepted solely from inferred database completeness; the historical 9DF4-bounded pre-mutation reread reported `auto_analysis_ready:false` while server health remained `ok`, Hex-Rays/string cache remained ready, and the responsive session supplied the direct row-by-row evidence retained below. Supervisor Gate 2B later verified the accepted poststate mechanically after save.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1G9-001 | 0001G9 | Exact target is `[0x00557aa0,0x00558391)`, 2289 bytes, SHA256 `A10232950713E44B45F25D567B0F0646F44DC2EF5BC183AE5544A84966D9591E`. | 99 | live `get_bytes` | UID0001G9 Range/Bytes | applied | APPLIED_VERIFIED |
| C1G9-002 | 0001G9 | BMP is `[0x00557aa0,0x00557e73)`, 979 bytes, SHA256 `44EF1F5A09AA9DCDA51587F5FBA1EC75223BD7A78708980ECA6A14BC700FEDAC`. | 99 | live `get_bytes` hash recheck | target and UID0004WM | applied | APPLIED_VERIFIED |
| C1G9-003 | 0001G9 | BMP-to-PNG padding is 13 CC bytes `[0x00557e73,0x00557e80)`. | 99 | live bytes | target and ignored applied; coverage handoff | applied ordinary / handed off coverage | APPLIED_VERIFIED ordinary; supervisor coverage pending |
| C1G9-004 | 0001G9 | PNG is `[0x00557e80,0x00558239)`, 953 bytes, SHA256 `7E8CE02FD7894A68D7C6A1012176B9B2767DBDC18F092C0724D0202B202B44FD`. | 99 | live `get_bytes` hash recheck | target and UID0004WN | applied | APPLIED_VERIFIED |
| C1G9-005 | 0001G9 | PNG-to-proof padding is seven CC bytes `[0x00558239,0x00558240)`. | 99 | live bytes | target and ignored applied; coverage handoff | applied ordinary / handed off coverage | APPLIED_VERIFIED ordinary; supervisor coverage pending |
| C1G9-006 | 0001G9 | Proof is `[0x00558240,0x00558391)`, 337 bytes, SHA256 `CA5329647821C90BFC1D31BD0C74E6134C985784D085F772F466583FCA6E0DFE`. | 99 | live `get_bytes` hash recheck | target and UID0004WO | applied | APPLIED_VERIFIED |
| C1G9-007 | 0001G9 | Following padding is 15 CC bytes `[0x00558391,0x005583a0)`. | 99 | live bytes | target and ignored applied; coverage handoff | applied ordinary / handed off coverage | APPLIED_VERIFIED ordinary; supervisor coverage pending |
| C1G9-008 | 0001G9 | JPG return is at `0x00557a95`; correct half-open child end is `0x00557a96`. | 99 | live bytes | UID0001G8 path/range applied; coverage handoff | applied ordinary / handed off coverage | APPLIED_VERIFIED ordinary; supervisor coverage pending |
| C1G9-009 | 0001G9 | BMP/PNG are void ScreenPane methods, not ScreenshotCapture-object methods. | 96 | ECX callers/field use/residual EAX | UID0004WM/UID0004WN, ScreenPane, ScreenshotCapture docs | applied | APPLIED_VERIFIED |
| C1G9-010 | 0001G9 | Proof is file-local `void __stdcall(FILE *)`. | 97 | no receiver, `retn 4`, three local callers | UID0004WO/item/file | applied | APPLIED_VERIFIED |
| C1G9-011 | 0001G9 | UID0001G9 becomes a non-emitting exact-range index with managed metadata `Nested:5`, counting exactly the BMP child, 13-byte internal padding, PNG child, seven-byte internal padding, and proof child; preceding JPG padding and following successor padding remain outside UID0001G9 and outside this count. | 98 | exact partition and by-structure aggregate rule | UID0001G9 managed metadata | applied | APPLIED_VERIFIED |
| C1G9-012 | 0001G9 | UID0000CD is a non-reconstructable source-family index, not concrete class. | 94 | no class/object evidence | by-class ScreenshotCapture | applied | APPLIED_VERIFIED |
| C1G9-013 | 0001G9 | JPG/BMP/PNG canonical owner is ScreenPane; output file remains ScreenshotCapture.cpp. | 96 | narrow owner and source cluster | UID0001G8/UID0004WM/UID0004WN metadata | applied | APPLIED_VERIFIED |
| C1G9-014 | 0001G9 | CPP source order is proof declaration, JPG, BMP, PNG, proof definition; H output contains the sole complete ScreenPane declaration rather than duplicating declarations in CPP. | 98 | physical order, forward use, focused command17290 checkpoint, current command17440 CPP/H invariant re-read, separate-channel rule | positions/item/file docs/generated output and UID0000CB H | CPP order and ScreenPane CPP-to-H migration applied | APPLIED_VERIFIED |
| C1G9-015 | 0001G9 | Hotkey dispatcher uses Scroll Lock toggle plus Left Shift choice and Ctrl+Shift+3/4 with latch. | 98 | `0x004a7130` decompile/disasm | EventDispatcher and screenshot docs | applied | APPLIED_VERIFIED |
| C1G9-016 | 0001G9 | `+0x18` is `m_ddSurface`; `+0x108` is `m_renderSurface`, not IDs. | 98 | GrafPort/ScreenPane docs and calls | target/JPG/UID0004WM/UID0004WN | applied | APPLIED_VERIFIED |
| C1G9-017 | 0001G9 | Browser helper blits visible browser HWND into current DirectDraw target. | 98 | `0x0046bfd0` live analysis | target/children/Browser support | applied | APPLIED_VERIFIED |
| C1G9-018 | 0001G9 | BMP writes 14-byte file header, 40-byte info header, positive height, 16 bpp, bottom-up rows. | 99 | full BMP decompile | UID0004WM/target | applied | APPLIED_VERIFIED |
| C1G9-019 | 0001G9 | RGB565 BMP branch converts each word to 555; other branch writes row words directly. | 99 | instructions/decompile | UID0004WM | applied | APPLIED_VERIFIED |
| C1G9-020 | 0001G9 | PNG allocates `4*screenWidth*screenHeight`, converts capture bounds top-down, and ignores allocation/encode status. | 99 | full PNG decompile | UID0004WN | applied | APPLIED_VERIFIED |
| C1G9-021 | 0001G9 | PNG calls stock `lodepng_encode32_file` with converted ACP path. | 99 | call at 0x55817b/support docs | UID0004WN/LodePNG support | applied | APPLIED_VERIFIED |
| C1G9-022 | 0001G9 | Status message saves/clears/restores EventMan `+0x920` and calls ChattingPane with message id `0x8f`. | 99 | live decompile/getter | all capture docs | applied | APPLIED_VERIFIED |
| C1G9-023 | 0001G9 | Proof XORs 32 MD5 hex bytes with the exact fixed 32-character literal `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE`; IDA stores the literal plus NUL as a 33-byte pooled item, while inferred source declares `char proofMask[36]`, leaving three additional trailing zero-initialized bytes, and XORs only indices `0..31`. | 99 | proof disasm, exact pooled bytes, source-shaped stack initialization | UID0004WO, UID0000VF, UID0001G9, ScreenshotCapture class/file, UID0003CJ | applied by commands 17286-17291 | APPLIED_VERIFIED |
| C1G9-024 | 0001G9 | Proof packet is opcode 0x83, 13 masked, 16 random, 19 masked, local terminator, send length 49. | 99 | proof disasm | UID0004WO/item/network docs | applied | APPLIED_VERIFIED |
| C1G9-025 | 0001G9 | Random byte 0 uses `%10-26`; bytes 1..15 use `%255`. | 99 | proof disasm | UID0004WO/item | applied | APPLIED_VERIFIED |
| C1G9-026 | 0001G9 | Path roots and filename/status literals are exact. | 99 | refs/decompile/current data docs | target/children/resource data | applied | APPLIED_VERIFIED |
| C1G9-027 | 0001G9 | Caller-local secure formatting replaces compiler-wrapper calls in human C++. | 96 | accepted fixed-wrapper docs | all four CPP implementation bodies | applied | APPLIED_VERIFIED |
| C1G9-028 | 0001G9 | Existing UID0001G8 draft must replace surface-ID and invented suppression-helper language. | 96 | support docs/live binary | UID0001G8 formal block | applied | APPLIED_VERIFIED |
| C1G9-029 | 0001G9 | UID0000VF emits the file-local forward declaration only in CPP; UID0004WO emits the definition once in CPP; both H channels remain blank because neither source-local construct belongs in a public header. | 96 | no-duplicate source rule, current command17440 one-declaration/one-definition readback, separate-channel rule | proof item/UID0004WO CPP and H/generated output | applied | APPLIED_VERIFIED |
| C1G9-030 | 0001G9 | ScreenPane's complete class declaration, including the three public screenshot methods and preserved concurrent `BlitSurfaceToDisplay`, belongs solely in UID0000CB H; UID0000CB CPP remains blank because class-level declaration output is not an implementation definition. | 97 | receiver proof, source consistency, separate-channel rule, commands17397/17440 current CPP/H destination readback | UID0000CB CPP/H formal blocks | exact complete declaration moved unchanged from CPP to H; CPP blank | APPLIED_VERIFIED |
| C1G9-031 | 0001G9 | Target score becomes 93/94 after complete split/index rewrite. | 93 | exhaustive evidence, remaining name caps | UID0001G9 metadata | applied | APPLIED_VERIFIED |
| C1G9-032 | 0001G9 | New children score 92/94 BMP, 92/94 PNG, and 93/94 proof. | 93 | exact body/ABI/data flow | UID0004WM/UID0004WN/UID0004WO metadata | applied | APPLIED_VERIFIED |
| C1G9-033 | 0001G9 | Manual coverage rows are stale and require supervisor replacement/insertion. | 99 | current manual reports | exact coverage handoff with allocated UIDs | handed off | SUPERVISOR_COVERAGE_PENDING |
| C1G9-034 | 0001G9 | UID0001G9-specific function/instruction/global/alignment renames, types, and comments were applied exactly by supervisor Gate 2B; the three modeled target functions use only the writable function-repeatable channel while function regular and both entry/item channels remain absent, accepted UID0003CJ proof-mask consolidation remains one protected item, and all five no-action dependencies remain independently protected. | 94 | exact 9DF4 prestate and backup; itemized accepted actions; supervisor mutation/readback; mechanical verifier over all 25 primary/protected rows, ten exact global-name matches, both pooled-literal interior-parent rows, boundaries/types/comments/xrefs; saved poststate 7509EC84; catalog 0310 | applied IDA package plus unchanged protected mask/dependency state | supervisor applied, read back, and saved | APPLIED_VERIFIED; PROTECTED_ROWS_UNCHANGED_VERIFIED |
| C1G9-035 | 0001G9 | No third-party inline import belongs in this target; PNG calls the separately imported LodePNG API. | 98 | source ownership | target/file/CPP/H/LodePNG support | applied | APPLIED_VERIFIED |

Post-channel-migration ledger verification is current, not inherited from callback-era hashes. C1G9-001 through C1G9-008 were re-read from the target, exact children, corrected JPG page, and ignored-span topology; C1G9-009 through C1G9-017 were re-read from current ScreenPane/ScreenshotCapture/EventDispatcher/Browser destinations; C1G9-018 through C1G9-022 and C1G9-024 through C1G9-028 remain in the unchanged exact BMP/PNG/JPG/proof CPP formals and their expanded UID0003CJ evidence. C1G9-029 remains correct across separate channels: the source-local forward declaration and proof definition occur once in CPP and both H bodies are blank. C1G9-030 is `APPLIED_VERIFIED`: UID0000CB CPP is exactly blank and the complete declaration, including B002's private `BlitSurfaceToDisplay`, all three screenshot declarations, and `[[CHILDREN]]` exactly once, resides in H byte-for-text unchanged. C1G9-031/032 scores and metadata remain current. C1G9-035 remains current from PNG/LodePNG routing. C1G9-023 remains `APPLIED_VERIFIED` under commands `17286` through `17291`; the exact `char proofMask[36]` formal and 32-iteration XOR loop remain unchanged. Bounded command `17440` reconfirms C1G9-014, C1G9-023's generated portion, C1G9-029, and C1G9-030. C1G9-033 remains the supervisor coverage handoff. C1G9-034 is now `APPLIED_VERIFIED`: 9DF4 is retained as the backed-up exact historical prestate, all accepted actions were applied/read back, every protected/no-change row remained exact, the mechanical verifier passed, and the shared IDB was saved as 7509EC84.

## Positive Evidence Summary

- Two modeled hotkey call sites each load `g_pScreenPane` in ECX before BMP/PNG calls.
- BMP and PNG touch accepted ScreenPane/GrafPort fields and share the exact JPG feature skeleton.
- Proof has exactly three calls, one from each JPG/BMP/PNG path, and no external subsystem caller.
- Exact bytes cleanly divide into three functions and two CC spans.
- Existing source-tree and by-file docs already recognize ScreenshotCapture.cpp as the feature module.
- Accepted support pages resolve every material callee into GrafPort, BrowserControlPane, LodePNG, MD5, PacketBuffer, Socket, EventMan, ChattingPane, and CRT/header support.
- The strongest inference chain is direct: receiver ABI -> ScreenPane methods; proof stack ABI -> static stdcall helper; physical/source cohesion -> ScreenshotCapture.cpp; exact-range rule -> child split.

## IDA MCP Facts

- Exact supervisor Gate 2B authority: backed-up pre-mutation IDB SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, 143,186,002 bytes; saved poststate SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`. The prestate audit and poststate mechanical verifier together cover every function, comment channel, item, collision, instruction, xref, byte boundary, and protected dependency below.
- Function/range facts:
  - `0x00557aa0` `ScreenPane_SaveScreenshotBMP`, exact type `void __thiscall(ScreenPane *this)`, size `0x3d3`, 21 blocks, complexity 15.
  - `0x00557e80` `ScreenPane_SaveScreenshotPNG`, exact type `void __thiscall(ScreenPane *this)`, size `0x3b9`, 26 blocks, complexity 16.
  - `0x00558240` `SendScreenshotProofPacket`, exact type `void __stdcall(FILE *stream)`, size `0x151`, 10 blocks, complexity 6.
  - `0x005583a0` `sub_5583A0`, size `0x2da`, excluded successor.
- Data/padding facts:
  - target full SHA and per-child SHA values are recorded above.
  - all 13 bytes at `0x00557e73`, all seven at `0x00558239`, and all 15 at `0x00558391` are `0xcc`.
  - JPG has `c3` at `0x00557a95` and ten CC bytes starting at `0x00557a96`.
- Xref facts:
  - BMP: calls from `0x004a71b6`, `0x004a7250`.
  - PNG: calls from `0x004a71d1`, `0x004a7296`.
  - proof: calls from raw JPG `0x00557a78`, BMP `0x00557e55`, PNG `0x0055821b`.
- Hotkeys:
  - `GetKeyboardState` fills `0x0069ae18`; low bit of byte `+0x91` is Scroll Lock toggle state.
  - a toggle transition chooses BMP when VK_LSHIFT is down, PNG otherwise.
  - translated key `0x33` with Ctrl+LeftShift chooses BMP; `0x34` chooses PNG; `0x0069af20` is a one-shot latch.
- Negative IDA facts:
  - no separate ScreenshotCapture receiver/object is used.
  - proof reads no incoming ECX and has no non-screenshot caller.
  - successor `0x005583a0` has no xref to target internals and starts after 15-byte padding.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00557840,0x00557a96)` | UID0001G8, corrected path | retained `ScreenPane::SaveScreenshotJPG` | true | class 0000CB, emitter 0000ND | 91/92 | applied/validated command17099 |
| `[0x00557a96,0x00557aa0)` | UID0000VN ignored | ten-byte alignment | false | range map | 100/100 | applied/validated command17122 |
| `[0x00557aa0,0x00558391)` | UID0001G9 | range/index container | false after split | file 0000ND | 93/94 | applied/validated command17098 |
| `[0x00557aa0,0x00557e73)` | UID0004WM | `ScreenPane::SaveScreenshotBMP` | true | class 0000CB, emitter 0000ND | 92/94 | created/validated command17095 |
| `[0x00557e73,0x00557e80)` | UID0000VN ignored | 13-byte alignment | false | target index | 100/100 | applied/validated command17122 |
| `[0x00557e80,0x00558239)` | UID0004WN | `ScreenPane::SaveScreenshotPNG` | true | class 0000CB, emitter 0000ND | 92/94 | created/validated command17096 |
| `[0x00558239,0x00558240)` | UID0000VN ignored | seven-byte alignment | false | target index | 100/100 | applied/validated command17122 |
| `[0x00558240,0x00558391)` | UID0004WO | file-local proof helper | true | file 0000ND | 93/94 | created/validated command17097 |
| `[0x00558391,0x005583a0)` | UID0000VN ignored | 15-byte alignment | false | surrounding range map | 100/100 | applied/validated command17122 |
| `0x00558240` semantic item | UID0000VF | forward declaration/evidence index | true declaration only | file 0000ND | 92/94 | applied/validated command17100 |
| ScreenshotCapture class-family | UID0000CD | non-class semantic index | false | file 0000ND | 91/93 | applied/validated command17102 |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004a71b6` | dispatcher -> BMP | Scroll Lock transition with Left Shift |
| `0x004a71d1` | dispatcher -> PNG | Scroll Lock transition without Left Shift |
| `0x004a7250` | dispatcher -> BMP | Ctrl+LeftShift+`3`, latch guarded |
| `0x004a7296` | dispatcher -> PNG | Ctrl+LeftShift+`4`, latch guarded |
| `0x00557a78` | raw JPG -> proof | third real proof path despite missing function model |
| `0x00557e55` | BMP -> proof | saved BMP stream proof |
| `0x0055821b` | PNG -> proof | saved PNG stream proof |
| `0x00557cd6/0x00558015` | capture -> GrafPort::UpdateSurfaceInfo | opens active render-surface pixel context |
| `0x00557ce8/0x00558027` | capture -> browser blit | overlays visible browser content into target surface |
| `0x00557db9/0x00558158` | capture -> GrafPort::EndPaint | unlocks/clears pixel context |
| `0x0055817b` | PNG -> lodepng_encode32_file | sole product caller of stock RGBA8 API |
| `0x00558278` | proof -> Md5StreamHex | produces 32-char heap hex digest |
| `0x00558370` | proof -> Socket::QueueAndSendPacket | sends exact 49-byte opcode 0x83 payload |

## Documentation Evidence And IDA Status

- Historical pre-callback docs correctly established feature ownership, strings, broad behavior, proof layout, and dependency families.
- Those docs were stale on aggregate emission, exact JPG endpoint, DirectDraw pointer names, proof random-byte asymmetry, unsent terminator, method/free-helper closure, and fixed-wrapper source expression. The callback repaired those accepted defects in the changed destinations listed below.
- ScreenPane class layout already accepts `m_renderSurface` at `+0x108`; GrafPort accepts `m_ddSurface`, `m_surfaceContext.pixelData`, `rowStridePixels`, and `bounds`.
- LodePNG docs identify `0x00443e40` as stock `lodepng_encode32_file`; no third-party code should be duplicated in ScreenshotCapture.cpp.
- Historical pre-callback generated source had one JPG body and three empty markers. Historical callback command `17138` first proved the corrected sequence, historical post-drift command `17264` reconfirmed it, focused-callback checkpoint `17290` captured the C1G9-023 state, and historical commands `17324`/`17367`/`17423` reconfirmed it. Bounded current command `17440` has the exact proof declaration + JPG + BMP + PNG + proof-definition CPP sequence, no screenshot-family empty markers, the exact 32-character literal in local `char proofMask[36]`, and the 32-iteration XOR formal unchanged. The completed UID0000CB CPP-to-H class-declaration migration added no ScreenshotCapture.cpp definition or forward declaration.

## Ranked Ownership Analysis

### 1. ScreenPane methods in ScreenshotCapture.cpp

- Evidence for: exact ECX receiver from `g_pScreenPane`, accepted class fields, shared JPG/BMP/PNG method family, and current feature-file route.
- Evidence against: original file spelling and cross-class definition style are not symbol-proved.
- Decision: accepted. This is the narrowest semantic owner and strongest source-file reconstruction.

### 2. File-local helpers taking ScreenPane pointers

- Evidence for: could produce equivalent body behavior in the feature file.
- Evidence against: BMP/PNG machine ABI is direct thiscall and caller loads ECX, while project class docs already use instance methods for adjacent ScreenPane code.
- Decision: rejected as weaker fallback.

### 3. Concrete ScreenshotCapture class

- Evidence for: historical generated class/source-family naming only.
- Evidence against: no constructor, destructor, vtable, object allocation, global instance, receiver, or field layout.
- Decision: rejected. UID0000CD becomes a non-reconstructable index.

### Proposed new file/grouping, if applicable

- No new source file is needed. Use existing [UID:0000ND] `NexusTK/render/ScreenshotCapture.cpp`.
- Full contents in order: proof forward declaration, JPG method, BMP method, PNG method, proof helper definition.
- Exclude LodePNG implementation, JPEG implementation, MD5 implementation, EventDispatcher hotkey method, BrowserControlPane blit method, and Socket send implementation.

## Source Placement

- Source definition placement: `NexusTK/render/ScreenshotCapture.cpp`.
- Class declarations: ScreenPane public declarations supplied by UID0000CB's class/header representation.
- File-local declaration: UID0000VF emits `static void __stdcall SendScreenshotProofPacket(FILE *stream);` before capture methods.
- Includes/dependencies: ScreenPane, BrowserControlPane, ChattingPane, EventMan, Socket/packet sender, MD5 helper declarations, LodePNG public header, Windows/Shell path APIs, stdio, stdlib, string, and time. Use project/PCH equivalents when current build layout centralizes them.
- Rejected placement: ScreenPane.cpp would separate physically contiguous screenshot/proof feature code from its dedicated module; EventDispatcher.cpp owns only hotkey selection; ImageWriters/LodePNG/MD5/Socket own dependencies only.

## Dependency / Include / Declaration / Source Order

Recommended logical include set for `ScreenshotCapture.cpp`:

- Project header dependencies: `ScreenPane.h`, `BrowserControlPane.h`, `ChattingPane.h`, `EventMan.h`, `MD5.h`, `Socket.h`, and `lodepng.h`.
- Platform and runtime header dependencies: `windows.h`, `shlobj.h`, `stdio.h`, `stdlib.h`, `string.h`, and `time.h`.
- These are dependency/header names only. No standalone include-directive sample is proposed outside a destination formal metadata block.

- Do not create a second LodePNG wrapper or paste third-party code into this file.
- The forward declaration must precede JPG because JPG calls proof before the physical proof definition.
- Exact emitter positions: UID0000VF `5`; UID0001G8 `10`; BMP `20`; PNG `30`; proof child `40`.
- UID0001G9 and UID0000CD must have no emitter after the split.

## Range / Split / Padding / Reclassification Analysis

- Exact target partition:
  - BMP `0x3d3` bytes.
  - padding `0x0d` bytes.
  - PNG `0x3b9` bytes.
  - padding `0x07` bytes.
  - proof `0x151` bytes.
  - total `0x8f1` bytes, exactly the UID0001G9 range.
- Parent impact: UID0001G9 remains the detailed index and preserves all cluster-level relationships, but source is emitted only by exact children.
- Adjacent repair: UID0001G8 must end at `0x00557a96`, not `0x00557a95`; ten CC bytes follow.
- Successor exclusion: `0x005583a0` starts an unrelated ScreenPane presentation method after 15 CC bytes and must not be absorbed.
- Padding is compiler/linker alignment and non-reconstructable. It belongs in [UID:0000VN] ignored evidence, not formal C++.

## Negative Evidence Summary

- No concrete ScreenshotCapture object exists.
- No proof helper receiver exists.
- No target function is owned by EventDispatcher solely because that dispatcher calls it.
- No image-codec dependency owns screenshot path/status/proof policy.
- No packet/MD5 dependency owns the screenshot-specific 0x83 payload.
- No compiler wrapper should be emitted as a project formatting API.
- No defensive allocation, conversion, file-reopen, write, or encode checks appear in the binary; adding them would change behavior.
- No evidence supports a generic `randomNonce` protocol meaning for the 16-byte proof insertion; `randomPadding` is intentionally descriptive.
- No evidence supports leaving raw `sub_*`, `dword_*`, or member offsets in final source.

## IDA Rename / Type / Comment Recommendations

The itemized tables below preserve the exact 9DF4 pre-mutation Gate 2B prestate and accepted action package. Rows labeled `apply` describe what the supervisor subsequently applied; they are retained as historical action evidence rather than current pending work. The consolidated proof-mask row and five itemized dependency rows were protected `ALREADY_PRESENT_VERIFIED` states, and rows marked `no change` were protected audit constraints. B004 made no IDA mutation.

Exact historical pre-mutation row authority was one active session and one bounded saved-IDB observation: session `supervisor_current_20260724_9f6e`, worker PID `17444`, exact IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, health `status:ok`, `is_analyzing:false`, Hex-Rays ready, string cache ready with 2068 strings, `auto_analysis_ready:false`, and saved IDB SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C` (143,186,002 bytes; saved `2026-07-24T22:09:37.3164487-04:00`). The byte-identical supervisor backup is `E:\NTK\Resources\NexusTK\NexusTK.exe.uid0001g9.pre-gate2b.20260724_224938.i64`. B004 hashed the exact IDB immediately before the complete row audit and again after the final protected function/global read; hash, size, and write time were identical. Every apply, no-change, `ALREADY_PRESENT_VERIFIED`, and protected dependency row below was re-read item by item from that exact state with `server_health`, `idb_list`, `lookup_funcs`, `list_funcs`, `list_globals`, `inspect_items`, `get_comments`, `insn_query`, `xref_query`, and `get_bytes`. Exact-name queries returned only the accepted existing names at their pre-mutation addresses: `ScreenshotProofMaskLiteral` at `0x006232e0`, `g_pChattingDisplayPane` at `0x0067adcc`, `g_surfaceUsesRgb565Pixels` at `0x0069b3d5`, `g_screenWidth` at `0x0066da94`, `g_screenHeight` at `0x0066da98`, `g_pEventMan` at `0x0067a754`, `g_packetSender` at `0x0067a7ec`, and `EventMan__GetModifierState` at `0x004a90b0`. At `0x0067ab28`, `inspect_items` returned listing name `unk_67AB28` and attached tinfo `int` on the one-byte head, while `list_globals` returned zero matches for both `unk_67AB28` and proposed `g_activeBrowserControlPane`; the accepted action therefore renamed that existing listing head rather than an unnamed head. The proposed function names `ScreenPane_SaveScreenshotBMP`, `ScreenPane_SaveScreenshotPNG`, and `SendScreenshotProofPacket` and proposed globals `g_previousScrollLockToggleState`, `g_screenshotHotkeyLatched`, and `g_activeBrowserControlPane` had zero pre-mutation matches. All literal prestates, function and item boundaries, types, comments, instruction text, bytes, and xref counts below were re-established from 9DF4 rather than inherited. CB62, 9F6E, B6A2, 48EB, D99, EF0, and all older saved revisions are bounded historical checkpoints; 9DF4 is the exact backed-up historical pre-mutation checkpoint. Historical sessions `b001_uid00014g_gate2b_rebase_20260724`, `supervisor_gate2b_0002OT_20260723`, and `1ce787ed` remain evidence provenance only.

`UNVERIFIED_PARTIAL_FROM_REVOKED_CALLBACK`: none. Before the callback was revoked, B004 had made no ordinary-document edit or creation, acquired no lease, and run no scoped ordinary-document validator. No partial by-* artifact therefore exists for the supervisor to inspect or preserve.

### Modeled Function Gate 2B Rows

For each modeled function, `function regular` and `function repeatable` are IDA function-comment channels, while `entry regular` and `entry repeatable` are the address-item comment channels at the function entry. Empty live values are recorded as `absent`; they are not merged or inferred from one another.

| Exact function range | Exact 9DF4 pre-mutation name/signature/size | Function regular prestate | Function repeatable prestate | Entry regular prestate | Entry repeatable prestate | Pre-mutation collision result | Historical disposition | Exact supervisor Gate 2B action | Required four-channel post-action readback |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `[0x00557aa0,0x00557e73)` | `sub_557AA0`; `FILE *__thiscall(int *this)`; size `0x3d3`; exact end `0x00557e73`; no UDT/local-variable mutation requested; two pre-mutation code refs at `0x004a71b6`, `0x004a7250` | absent | absent | absent | absent | proposed `ScreenPane_SaveScreenshotBMP`: zero pre-mutation name matches | `apply` | Rename to `ScreenPane_SaveScreenshotBMP`; apply exact type `void __thiscall ScreenPane_SaveScreenshotBMP(ScreenPane *this)`; leave function regular absent; set function repeatable to exact literal `ScreenPane::SaveScreenshotBMP; writes a 16-bit bottom-up BMP from the active render surface, posts capture status, and sends screenshot proof.` through the MCP function-entry comment channel; leave entry/item regular absent and entry/item repeatable absent; leave all UDT/local-variable state unchanged | exact start/end/size and two refs preserved; sole proposed name; exact type; all UDT/local-variable state unchanged; function regular absent; function repeatable equals the literal; entry regular absent; entry repeatable absent; no expansion |
| `[0x00557e80,0x00558239)` | `sub_557E80`; `int __thiscall(int *this)`; size `0x3b9`; exact end `0x00558239`; no UDT/local-variable mutation requested; two pre-mutation code refs at `0x004a71d1`, `0x004a7296` | absent | absent | absent | absent | proposed `ScreenPane_SaveScreenshotPNG`: zero pre-mutation name matches | `apply` | Rename to `ScreenPane_SaveScreenshotPNG`; apply exact type `void __thiscall ScreenPane_SaveScreenshotPNG(ScreenPane *this)`; leave function regular absent; set function repeatable to exact literal `ScreenPane::SaveScreenshotPNG; converts the active 16-bit render surface to top-down RGBA, writes PNG, posts capture status, and sends screenshot proof.` through the MCP function-entry comment channel; leave entry/item regular absent and entry/item repeatable absent; leave all UDT/local-variable state unchanged | exact start/end/size and two refs preserved; sole proposed name; exact type; all UDT/local-variable state unchanged; function regular absent; function repeatable equals the literal; entry regular absent; entry repeatable absent; no expansion |
| `[0x00558240,0x00558391)` | `sub_558240`; `void __stdcall(FILE *Stream)`; size `0x151`; exact end `0x00558391`; no UDT/local-variable mutation requested; three pre-mutation code refs at `0x00557a78`, `0x00557e55`, `0x0055821b` | absent | absent | absent | absent | proposed `SendScreenshotProofPacket`: zero pre-mutation name matches | `apply` | Rename to `SendScreenshotProofPacket`; apply exact type `void __stdcall SendScreenshotProofPacket(FILE *stream)`; leave function regular absent; set function repeatable to exact literal `File-local screenshot proof helper; masks 32 MD5-hex bytes, builds opcode 0x83 as 13 masked plus 16 random plus 19 masked bytes, stores an unsent local terminator at byte 49, and sends exactly 49 bytes.` through the MCP function-entry comment channel; leave entry/item regular absent and entry/item repeatable absent; leave all UDT/local-variable state unchanged | exact start/end/size and three refs preserved; sole proposed name; exact type; all UDT/local-variable state unchanged; function regular absent; function repeatable equals the literal; entry regular absent; entry repeatable absent; no expansion |
| `[0x004236e0,0x00423710)` | `sub_4236E0`; `int(wchar_t *Buffer, wchar_t *Format, ...)`; size `0x30`; exact end `0x00423710`; fixed-size CRT wrapper; no UDT/local-variable mutation requested; 48 pre-mutation code refs | absent | absent | absent | absent | no rename requested | `no change` | Do not rename, retype, comment, resize, expand, or alter UDT/local-variable state; human source keeps secure formatting local to each caller | exact name/signature/start/end/size and 48 refs remain; all UDT/local-variable state unchanged; function regular absent; function repeatable absent; entry regular absent; entry repeatable absent; no expansion |
| `[0x0045ef20,0x0045ef50)` | `sub_45EF20`; `int(wchar_t *Buffer, wchar_t *Format, ...)`; size `0x30`; exact end `0x0045ef50`; fixed-size CRT wrapper; no UDT/local-variable mutation requested; five pre-mutation code refs | absent | absent | absent | absent | no rename requested | `no change` | Do not rename, retype, comment, resize, expand, or alter UDT/local-variable state; human source keeps secure formatting local to each caller | exact name/signature/start/end/size and five refs remain; all UDT/local-variable state unchanged; function regular absent; function repeatable absent; entry regular absent; entry repeatable absent; no expansion |
| `[0x00559af0,0x00559b1d)` | `sub_559AF0`; `int(wchar_t *Buffer, wchar_t *Format, ...)`; size `0x2d`; exact end `0x00559b1d`; fixed-size CRT wrapper; no UDT/local-variable mutation requested; three pre-mutation code refs | absent | absent | absent | absent | no rename requested | `no change` | Do not rename, retype, comment, resize, expand, or alter UDT/local-variable state; human source keeps secure formatting local to each caller | exact name/signature/start/end/size and three refs remain; all UDT/local-variable state unchanged; function regular absent; function repeatable absent; entry regular absent; entry repeatable absent; no expansion |

### Instruction, Data, Alignment, and Raw-Item Gate 2B Rows

These rows use only address-item comment channels. No function-comment state is implied for an instruction, storage item, alignment item, raw unmodeled start, or pooled data item.

| Exact address/range and item | Exact 9DF4 pre-mutation item state | Item regular prestate | Item repeatable prestate | Pre-mutation collision result | Historical disposition | Exact supervisor Gate 2B action | Required item-specific readback |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Instruction `[0x004a71b6,0x004a71bb)` | unnamed five-byte code item with no C tinfo/UDT/local state; exact instruction `call sub_557AA0`; containing function `sub_4A7130` `[0x004a7130,0x004a7567)` | absent | absent | no item name requested | `apply` | Set only item repeatable comment `Scroll Lock toggle with Left Shift: save BMP screenshot.`; leave item regular absent and all type/UDT/local state unchanged | exact five-byte boundary; call resolves to renamed BMP function; item regular absent; item repeatable equals literal text; no type/UDT/local change |
| Instruction `[0x004a71d1,0x004a71d6)` | five-byte code item labeled `loc_4A71D1` with no C tinfo/UDT/local state; exact instruction `call sub_557E80`; containing function `sub_4A7130` `[0x004a7130,0x004a7567)` | absent | absent | preserve existing local label; no new name requested | `apply` | Set only item repeatable comment `Scroll Lock toggle without Left Shift: save PNG screenshot.`; leave item regular absent and all type/UDT/local state unchanged | exact five-byte boundary and local label; call resolves to renamed PNG function; item regular absent; item repeatable equals literal text; no type/UDT/local change |
| Instruction `[0x004a7250,0x004a7255)` | unnamed five-byte code item with no C tinfo/UDT/local state; exact instruction `call sub_557AA0`; containing function `sub_4A7130` `[0x004a7130,0x004a7567)` | absent | absent | no item name requested | `apply` | Set only item repeatable comment `Ctrl+LeftShift+3 screenshot hotkey; latch guarded.`; leave item regular absent and all type/UDT/local state unchanged | exact five-byte boundary; call resolves to renamed BMP function; item regular absent; item repeatable equals literal text; no type/UDT/local change |
| Instruction `[0x004a7296,0x004a729b)` | unnamed five-byte code item with no C tinfo/UDT/local state; exact instruction `call sub_557E80`; containing function `sub_4A7130` `[0x004a7130,0x004a7567)` | absent | absent | no item name requested | `apply` | Set only item repeatable comment `Ctrl+LeftShift+4 screenshot hotkey; latch guarded.`; leave item regular absent and all type/UDT/local state unchanged | exact five-byte boundary; call resolves to renamed PNG function; item regular absent; item repeatable equals literal text; no type/UDT/local change |
| Storage `[0x0069af18,0x0069af1c)` | unnamed one-byte undefined head `[0x0069af18,0x0069af19)` with no C tinfo/UDT/local state; next three bytes are separate unnamed undefined one-byte items; all four bytes zero; refs `0x004a6bd6`, `0x004a7197`, `0x004a71a4` | absent at head | absent at head | proposed `g_previousScrollLockToggleState`: zero pre-mutation name matches | `apply` | Replace only the four undefined bytes with one four-byte item; rename to `g_previousScrollLockToggleState`; type as exact `int`; set item regular to `Previous low toggle bit of VK_SCROLL used to detect Scroll Lock state changes.`; leave item repeatable absent and UDT/local state absent | one exact `[0x0069af18,0x0069af1c)` item; sole proposed name; four-byte `int`; same three refs; literal item regular; item repeatable absent; no UDT/local state and no expansion |
| Storage `[0x0069af20,0x0069af21)` | unnamed one-byte undefined item with no C tinfo/UDT/local state, zero byte; refs `0x004a7245`, `0x004a7255`, `0x004a728b`, `0x004a729b`, `0x004a72b8` | absent | absent | proposed `g_screenshotHotkeyLatched`: zero pre-mutation name matches | `apply` | Define/preserve exactly one byte; rename to `g_screenshotHotkeyLatched`; type as exact `bool`; set item regular to `Latch preventing repeated Ctrl+LeftShift screenshot hotkey dispatch while held.`; leave item repeatable absent and UDT/local state absent | one exact byte; sole proposed name; `bool`; same five refs; literal item regular; item repeatable absent; no UDT/local state and no expansion |
| Storage `[0x0067ab28,0x0067ab2c)` | one-byte undefined head `[0x0067ab28,0x0067ab29)` with listing name `unk_67AB28`, attached tinfo `int`, and no UDT/local state; next three bytes are separate unnamed undefined one-byte items; all four bytes zero; 24 refs including `0x00557cdb`, `0x0055801a` | absent | absent | `inspect_items` returned exact pre-mutation listing name `unk_67AB28` at the one-byte head; `list_globals` returned zero matches for both that autogenerated listing name and proposed `g_activeBrowserControlPane`; proposed name had no collision | `apply` | Replace only the four undefined listing bytes with one four-byte item; rename existing listing head `unk_67AB28` to `g_activeBrowserControlPane`; replace attached `int` with exact `BrowserControlPane *`; set item regular to `Currently active browser pane composited into screenshots when non-null.`; leave item repeatable absent and do not create/modify any UDT or local | one exact `[0x0067ab28,0x0067ab2c)` item; sole proposed name; four-byte `BrowserControlPane *`; all 24 refs preserved; literal item regular; item repeatable absent; no UDT/local mutation and no expansion |
| Storage `[0x0067adcc,0x0067add0)` | `list_globals` returns sole user name `g_pChattingDisplayPane` at `0x0067adcc`; one-byte undefined head has attached tinfo `ChattingPane *` and no UDT/local state; next three bytes are separate undefined one-byte items; all four bytes zero; 20 refs including `0x00557dc7`, `0x00557e18`, `0x00558189`, `0x005581da` | absent | absent | exact name exists once at this address; no conflicting match | `apply` | Retain `g_pChattingDisplayPane` and exact `ChattingPane *`; replace only the four undefined listing bytes with one four-byte item; set item regular to `Active chatting display pane used for screenshot capture status messages.`; leave item repeatable absent and local/UDT state unchanged | same sole name/address; one exact `[0x0067adcc,0x0067add0)` `ChattingPane *`; all 20 refs preserved; literal item regular; item repeatable absent; no expansion or local/UDT change |
| Storage `[0x0069b3d5,0x0069b3d6)` | `list_globals` returns sole user name `g_surfaceUsesRgb565Pixels`; exact one-byte listing item has attached tinfo `bool`, no UDT/local state, zero byte, and 16 refs including `0x00557d1e`, `0x0055805a` | absent | absent | exact name exists once at this address; no conflicting match | `apply` | Retain exact name, one-byte item, and `bool`; set item regular to `True when the active 16-bit surface uses RGB565 rather than RGB555 channel layout.`; leave item repeatable absent and local/UDT state unchanged | same sole name/address; exact one-byte `bool`; all 16 refs preserved; literal item regular; item repeatable absent; no expansion or local/UDT change |
| Alignment `[0x00557e73,0x00557e80)` | one 13-byte data/alignment item; no name, C type, UDT, or local state; exactly thirteen `0xcc` bytes | absent | absent | no name requested | `apply` | Set only item repeatable comment `13-byte CC alignment between ScreenPane_SaveScreenshotBMP and ScreenPane_SaveScreenshotPNG; do not define code or data.`; leave item regular absent and all type/UDT/local state unchanged | exact 13-byte item and bytes unchanged; item regular absent; item repeatable equals literal text; no code/type/name/UDT/local creation |
| Alignment `[0x00558239,0x00558240)` | one seven-byte data/alignment item; no name, C type, UDT, or local state; exactly seven `0xcc` bytes | absent | absent | no name requested | `apply` | Set only item repeatable comment `7-byte CC alignment between ScreenPane_SaveScreenshotPNG and SendScreenshotProofPacket; do not define code or data.`; leave item regular absent and all type/UDT/local state unchanged | exact seven-byte item and bytes unchanged; item regular absent; item repeatable equals literal text; no code/type/name/UDT/local creation |
| Alignment `[0x00558391,0x005583a0)` | one 15-byte data/alignment item; no name, C type, UDT, or local state; exactly fifteen `0xcc` bytes | absent | absent | no name requested | `apply` | Set only item repeatable comment `15-byte CC alignment after SendScreenshotProofPacket and before successor 0x005583a0; do not define code or data.`; leave item regular absent and all type/UDT/local state unchanged | exact 15-byte item and bytes unchanged; item regular absent; item repeatable equals literal text; no code/type/name/UDT/local creation |
| Raw bytes `[0x00557840,0x00557a96)` | `lookup_funcs`: `Not a function`; raw start is an unnamed one-byte code item with no C tinfo/UDT/local state; return byte `0xc3` at `0x00557a95`; following item `[0x00557a96,0x00557aa0)` is ten `0xcc` bytes | absent at raw start | absent at raw start | no name requested | `no change` | Do not create a function, type, name, or comment; ordinary documentation owns the endpoint repair | raw start remains unmodeled; exact end/return/following padding preserved; item regular absent; item repeatable absent; no type/name/expansion |
| Data `[0x006232e0,0x00623301)`; interior queries `0x006232f0`, `0x00623300` | one 33-byte item headed `0x006232e0`, exact end `0x00623301`, name `ScreenshotProofMaskLiteral`, type `const char[33]`; no UDT/local state; both interiors resolve to the parent; exact bytes are the 32-character fixed literal `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE` plus its terminating NUL; refs are `0x00558253` to head, `0x00558269` to `0x006232f0`, `0x0055825d` to `0x00623300` | absent at head and both interior queries | exact parent text `Compiler-pooled local initializer for SendScreenshotProofPacket proofMask; source is a local char array, not three globals or a standalone constant object.` at head and both interior queries | exact name exists once at the parent head; no conflicting match; no rename requested | `ALREADY_PRESENT_VERIFIED`; protected/no action | Do not rename, retype, recomment, delete, resize, or split; accepted UID0003CJ state remains compiler-pooled bytes for source-local `proofMask`, not a source global. Reconstruct source as local `char proofMask[36]` initialized by the 32-character literal: pooled byte 32 is the terminator, local indices `33..35` are three additional zero-initialized bytes, and only indices `0..31` participate in XOR. | one exact 33-byte parent/name/type/comment; 32 literal characters plus NUL; interior-parent resolution and all three refs preserved; item regular absent; item repeatable equals exact text; source-shaped 36-byte local/trailing-three-zero/32-byte-XOR distinction preserved; bounded saved-IDB observation `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C` |

Protected dependencies are evidence inputs, not Gate 2B action items. They were nevertheless re-read item by item against the same stable revision so the supervisor can distinguish exact protected prestate from an unaudited grouped exclusion:

| Exact protected entity | Exact 9DF4 name/declaration/type/boundary and comment prestate | Xrefs/collision state | Historical disposition and exact no-action readback |
| --- | --- | --- | --- |
| Storage `[0x0066da94,0x0066da96)` | sole exact name `g_screenWidth`; two-byte `unsigned __int16`; bytes `00 04`; no UDT/local state; item regular absent; item repeatable absent | 98 refs; exact-name query returns only `0x0066da94`; no rename proposed | `ALREADY_PRESENT_VERIFIED`; do not rename, retype, comment, resize, or merge. Readback must remain the same exact two-byte item/name/type/comments and 98 refs. |
| Storage `[0x0066da98,0x0066da9a)` | sole exact name `g_screenHeight`; two-byte `unsigned __int16`; bytes `00 03`; no UDT/local state; item regular absent; item repeatable absent | 96 refs; exact-name query returns only `0x0066da98`; no rename proposed | `ALREADY_PRESENT_VERIFIED`; do not rename, retype, comment, resize, or merge. Readback must remain the same exact two-byte item/name/type/comments and 96 refs. |
| Storage `[0x0067a754,0x0067a758)` | sole exact name `g_pEventMan`; four-byte `EventMan *`; bytes `00 00 00 00`; no UDT/local state; item regular exact text `g_pEventMan: shared EventMan singleton used by EventMan_TranslateEventKey and event dispatch helpers.`; item repeatable absent | 210 refs; exact-name query returns only `0x0067a754`; no rename proposed | `ALREADY_PRESENT_VERIFIED`; do not rename, retype, recomment, resize, or merge. Readback must preserve the exact four-byte item/name/type/comment channels and 210 refs. |
| Storage `[0x0067a7ec,0x0067a7f0)` | sole exact name `g_packetSender`; four-byte `Socket *`; bytes `00 00 00 00`; no UDT/local state; item regular is exact two-line text `Active packet-sender Socket singleton used by UserPane.cpp retained packet helpers.\nCanonical Socket *g_packetSender singleton used by packet serializer methods.`; item repeatable absent | 489 refs; exact-name query returns only `0x0067a7ec`; no rename proposed | `ALREADY_PRESENT_VERIFIED`; do not rename, retype, recomment, resize, or merge. Readback must preserve the exact four-byte item/name/type/two-line regular comment, absent repeatable comment, and 489 refs. |
| Function `[0x004a90b0,0x004a90c2)` | sole exact name `EventMan__GetModifierState`; exact signature `void __thiscall(EventMan *, unsigned __int8 *modifierState)`; size `0x12`; no UDT/local-variable mutation requested; function regular absent; function repeatable absent; entry regular absent; entry repeatable absent | six code refs at `0x0047f391`, `0x0047f431`, `0x004ffb35`, `0x00557a1d`, `0x00557df9`, `0x005581bb`; exact function-name query returns only `0x004a90b0` | `ALREADY_PRESENT_VERIFIED`; do not rename, retype, comment, resize, or expand. Readback must preserve exact name/signature/range, all four absent comment channels, and six refs. |

### Supervisor Gate 2B Applied Poststate And Save Readback

Supervisor Gate 2B used the exact 9DF4 prestate and byte-identical backup above, applied every accepted `apply` row, reread every no-change/protected row, and saved the shared IDB. The following poststate is the deterministic result, not a new recommendation:

| Exact entity | Applied and verified poststate |
| --- | --- |
| Function `[0x00557aa0,0x00557e73)` | Sole name `ScreenPane_SaveScreenshotBMP`; exact type `void __thiscall(ScreenPane *this)`; exact size `0x3d3`; two refs preserved at `0x004a71b6`, `0x004a7250`; function regular absent; function repeatable exact text `ScreenPane::SaveScreenshotBMP; writes a 16-bit bottom-up BMP from the active render surface, posts capture status, and sends screenshot proof.`; entry regular absent; entry repeatable absent; no UDT/local mutation or range expansion. |
| Function `[0x00557e80,0x00558239)` | Sole name `ScreenPane_SaveScreenshotPNG`; exact type `void __thiscall(ScreenPane *this)`; exact size `0x3b9`; two refs preserved at `0x004a71d1`, `0x004a7296`; function regular absent; function repeatable exact text `ScreenPane::SaveScreenshotPNG; converts the active 16-bit render surface to top-down RGBA, writes PNG, posts capture status, and sends screenshot proof.`; entry regular absent; entry repeatable absent; no UDT/local mutation or range expansion. |
| Function `[0x00558240,0x00558391)` | Sole name `SendScreenshotProofPacket`; exact type `void __stdcall(FILE *stream)`; exact size `0x151`; three refs preserved at `0x00557a78`, `0x00557e55`, `0x0055821b`; function regular absent; function repeatable exact text `File-local screenshot proof helper; masks 32 MD5-hex bytes, builds opcode 0x83 as 13 masked plus 16 random plus 19 masked bytes, stores an unsent local terminator at byte 49, and sends exactly 49 bytes.`; entry regular absent; entry repeatable absent; no UDT/local mutation or range expansion. |
| Instruction `[0x004a71b6,0x004a71bb)` | Exact five-byte boundary preserved; call resolves to `ScreenPane_SaveScreenshotBMP`; regular absent; repeatable exact text `Scroll Lock toggle with Left Shift: save BMP screenshot.` |
| Instruction `[0x004a71d1,0x004a71d6)` | Exact five-byte boundary and label `loc_4A71D1` preserved; call resolves to `ScreenPane_SaveScreenshotPNG`; regular absent; repeatable exact text `Scroll Lock toggle without Left Shift: save PNG screenshot.` |
| Instruction `[0x004a7250,0x004a7255)` | Exact five-byte boundary preserved; call resolves to `ScreenPane_SaveScreenshotBMP`; regular absent; repeatable exact text `Ctrl+LeftShift+3 screenshot hotkey; latch guarded.` |
| Instruction `[0x004a7296,0x004a729b)` | Exact five-byte boundary preserved; call resolves to `ScreenPane_SaveScreenshotPNG`; regular absent; repeatable exact text `Ctrl+LeftShift+4 screenshot hotkey; latch guarded.` |
| Storage `[0x0069af18,0x0069af1c)` | One exact four-byte item named `g_previousScrollLockToggleState`, type `int`; same three refs; regular exact text `Previous low toggle bit of VK_SCROLL used to detect Scroll Lock state changes.`; repeatable absent; no UDT/local state or expansion. |
| Storage `[0x0069af20,0x0069af21)` | One exact byte named `g_screenshotHotkeyLatched`, type `bool`; same five refs; regular exact text `Latch preventing repeated Ctrl+LeftShift screenshot hotkey dispatch while held.`; repeatable absent; no UDT/local state or expansion. |
| Storage `[0x0067ab28,0x0067ab2c)` | One exact four-byte item named `g_activeBrowserControlPane`, type `BrowserControlPane *`; all 24 refs preserved; regular exact text `Currently active browser pane composited into screenshots when non-null.`; repeatable absent; no UDT/local mutation or expansion. |
| Storage `[0x0067adcc,0x0067add0)` | One exact four-byte item retaining sole name `g_pChattingDisplayPane`, type `ChattingPane *`; all 20 refs preserved; regular exact text `Active chatting display pane used for screenshot capture status messages.`; repeatable absent; no UDT/local mutation or expansion. |
| Storage `[0x0069b3d5,0x0069b3d6)` | Existing exact one-byte `bool g_surfaceUsesRgb565Pixels` and all 16 refs preserved; regular exact text `True when the active 16-bit surface uses RGB565 rather than RGB555 channel layout.`; repeatable absent; no expansion. |
| Alignment `[0x00557e73,0x00557e80)` | Exact 13-byte CC item preserved; regular absent; repeatable exact text `13-byte CC alignment between ScreenPane_SaveScreenshotBMP and ScreenPane_SaveScreenshotPNG; do not define code or data.`; no code/type/name/UDT/local creation. |
| Alignment `[0x00558239,0x00558240)` | Exact seven-byte CC item preserved; regular absent; repeatable exact text `7-byte CC alignment between ScreenPane_SaveScreenshotPNG and SendScreenshotProofPacket; do not define code or data.`; no code/type/name/UDT/local creation. |
| Alignment `[0x00558391,0x005583a0)` | Exact 15-byte CC item preserved; regular absent; repeatable exact text `15-byte CC alignment after SendScreenshotProofPacket and before successor 0x005583a0; do not define code or data.`; no code/type/name/UDT/local creation. |

Mutation totals matched the accepted package exactly: three function renames, three function types, four storage-head normalizations, five regular item comments, and ten repeatable function/instruction/alignment comments. The three fixed-size CRT wrappers, raw JPG start, consolidated proof-mask item, four protected globals, and protected `EventMan__GetModifierState` function were reread unchanged. The mechanical post-save verifier passed all 25 primary/protected rows, ten exact global-name matches, both pooled-literal interior-parent rows, exact boundaries/types, all four modeled-function comment channels, item comment channels, and xref totals. MCP `idb_save` returned `ok:true`; the saved poststate is SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`. The supervisor catalog record is `ida-recommendation-implementation-catalog.md` entry `0310`, and the exact Gate 2A/Gate 2B audit records are in `b-report-validation-audit.md`.

## First-Draft C++ Recommendation

- Eligible: yes, after the exact split and owner/emitter repairs.
- Third-party import directive: not applicable to UID0001G9. ScreenshotCapture calls the separately owned/imported LodePNG public API; no `third_party_embeds/...` directive belongs in these feature pages.
- Behavior standard: the code below intentionally preserves unchecked returns, direct state changes, local terminators, row orientation, channel truncation, and cleanup order.
- Source standard: C++03-era arrays, CRT, Win32 APIs, explicit loops, and current project naming are used; no IDA labels appear.
- Proof-mask source shape: the literal is exactly 32 characters and occupies a 33-byte IDA pooled item with its NUL. `char proofMask[36] = "w-pu6a4Es*5pA@eg+tetayAp6us6EcrE";` therefore leaves three additional trailing zero-initialized local bytes at indices `33..35`; the loop XORs only indices `0..31`. The pooled item size, inferred local array size, and XOR count are separate facts.
- Channel rule: CPP definitions/source-local declarations and H declarations are disposed independently. The six non-class destinations below have exact empty H formals with target-specific proofs. UID0000CB has exact blank CPP and one complete H class declaration. No declaration is duplicated between channels.

### Proposed UID0001G9 Container Formal Block

Destination: current [UID:0001G9] non-emitting range-index page; applied as the accepted blank formal after child allocation.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof: after the split, UID0001G9 represents only the range index and padding topology. Emitting any child body here would duplicate source and violate exact-range ownership.

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

No-header proof: UID0001G9 is a non-emitting byte-range/index container, not a translation-unit declaration owner. Its exact children and UID0000CB own all implementation and declaration output.

### Proposed BMP Child Formal Block

Destination: [UID:0004WM] `by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::SaveScreenshotBMP()
{
    wchar_t documents[MAX_PATH];
    wchar_t nexusDirectory[MAX_PATH];
    wchar_t screenshotDirectory[MAX_PATH];
    wchar_t fileName[256];
    wchar_t fullPath[MAX_PATH];
    wchar_t statusText[120];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documents) != S_OK)
        return;

    swprintf_s(nexusDirectory, L"%s\\NexusTK", documents);
    if (!g_pfnCreateDirectoryW(nexusDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(screenshotDirectory, L"%s\\NexusTK\\ScreenShots", documents);
    if (!g_pfnCreateDirectoryW(screenshotDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    __time64_t now = _time64(NULL);
    tm localTime;
    _localtime64_s(&localTime, &now);
    swprintf_s(fileName, L"TK_%04d%02d%02d%02d%02d%02d.bmp",
        localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,
        localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    swprintf_s(fullPath, L"%s\\%s", screenshotDirectory, fileName);

    FILE *output = g_pfnWideOpenFile(fullPath, L"wb");
    if (output == NULL)
        return;

    BITMAPFILEHEADER fileHeader;
    fileHeader.bfType = 0x4d42;
    fileHeader.bfSize = 54 + 2 * g_screenWidth * g_screenHeight;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = 54;
    fwrite(&fileHeader, sizeof(fileHeader), 1, output);

    BITMAPINFOHEADER infoHeader;
    memset(&infoHeader, 0, sizeof(infoHeader));
    infoHeader.biSize = sizeof(infoHeader);
    infoHeader.biWidth = g_screenWidth;
    infoHeader.biHeight = g_screenHeight;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 16;
    fwrite(&infoHeader, sizeof(infoHeader), 1, output);

    LPDIRECTDRAWSURFACE savedSurface = m_ddSurface;
    m_ddSurface = m_renderSurface;
    UpdateSurfaceInfo();
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserControlPane->BlitBrowserSurfaceToRenderTarget(m_ddSurface);

    const int width = m_surfaceContext.bounds.right - m_surfaceContext.bounds.left;
    const int height = m_surfaceContext.bounds.bottom - m_surfaceContext.bounds.top;
    unsigned short *row = static_cast<unsigned short *>(m_surfaceContext.pixelData)
        + m_surfaceContext.rowStridePixels * (height - 1);

    for (int y = 0; y < height; ++y) {
        if (g_surfaceUsesRgb565Pixels) {
            for (int x = 0; x < m_surfaceContext.rowStridePixels; ++x) {
                unsigned short pixel = row[x];
                unsigned short bmpPixel = static_cast<unsigned short>(
                    (pixel & 0x001f) | ((pixel >> 1) & 0x7fe0));
                fwrite(&bmpPixel, sizeof(bmpPixel), 1, output);
            }
        } else {
            fwrite(row, sizeof(unsigned short), width, output);
        }
        row -= m_surfaceContext.rowStridePixels;
    }

    fclose(output);
    EndPaint();
    m_ddSurface = savedSurface;

    if (g_pChattingDisplayPane != NULL) {
        swprintf_s(statusText,
            L"Screen Captured. 'MyDocuments\\NexusTK\\ScreenShots\\%s'", fileName);
        unsigned char savedModifierState;
        g_pEventMan->GetModifierState(&savedModifierState);
        g_pEventMan->m_modifierState = 0;
        g_pChattingDisplayPane->AddChattingMessage(statusText, 0x8f, 1, 0, 0, 0);
        g_pEventMan->m_modifierState = savedModifierState;
    }

    FILE *proofInput = g_pfnWideOpenFile(fullPath, L"rb");
    SendScreenshotProofPacket(proofInput);
    fclose(proofInput);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

No-header proof: UID0004WM owns the `ScreenPane::SaveScreenshotBMP` CPP definition only. Its member declaration belongs once in UID0000CB's complete ScreenPane H block; repeating it here would duplicate class output.

### Proposed PNG Child Formal Block

Destination: [UID:0004WN] `by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::SaveScreenshotPNG()
{
    wchar_t documents[MAX_PATH];
    wchar_t nexusDirectory[MAX_PATH];
    wchar_t screenshotDirectory[MAX_PATH];
    wchar_t fileName[256];
    wchar_t fullPath[MAX_PATH];
    wchar_t statusText[120];
    char encodedPath[256];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documents) != S_OK)
        return;

    swprintf_s(nexusDirectory, L"%s\\NexusTK", documents);
    if (!g_pfnCreateDirectoryW(nexusDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(screenshotDirectory, L"%s\\NexusTK\\ScreenShots", documents);
    if (!g_pfnCreateDirectoryW(screenshotDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    __time64_t now = _time64(NULL);
    tm localTime;
    _localtime64_s(&localTime, &now);
    swprintf_s(fileName, L"TK_%04d%02d%02d%02d%02d%02d.png",
        localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,
        localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    swprintf_s(fullPath, L"%s\\%s", screenshotDirectory, fileName);
    WideCharToMultiByte(CP_ACP, 0, fullPath, -1, encodedPath,
        sizeof(encodedPath), NULL, NULL);

    unsigned char *rgba = static_cast<unsigned char *>(
        malloc(4 * g_screenWidth * g_screenHeight));

    LPDIRECTDRAWSURFACE savedSurface = m_ddSurface;
    m_ddSurface = m_renderSurface;
    UpdateSurfaceInfo();
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserControlPane->BlitBrowserSurfaceToRenderTarget(m_ddSurface);

    const int width = m_surfaceContext.bounds.right - m_surfaceContext.bounds.left;
    const int height = m_surfaceContext.bounds.bottom - m_surfaceContext.bounds.top;
    const unsigned short *source =
        static_cast<const unsigned short *>(m_surfaceContext.pixelData);
    unsigned char *destination = rgba;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const unsigned short pixel = source[x];
            if (g_surfaceUsesRgb565Pixels) {
                destination[0] = static_cast<unsigned char>((pixel >> 11) << 3);
                destination[1] = static_cast<unsigned char>((pixel >> 6) << 3);
            } else {
                destination[0] = static_cast<unsigned char>((pixel >> 10) << 3);
                destination[1] = static_cast<unsigned char>((pixel >> 5) << 3);
            }
            destination[2] = static_cast<unsigned char>(pixel << 3);
            destination[3] = 0xff;
            destination += 4;
        }
        source += m_surfaceContext.rowStridePixels;
    }

    EndPaint();
    m_ddSurface = savedSurface;
    lodepng_encode32_file(encodedPath, rgba, width, height);
    free(rgba);

    if (g_pChattingDisplayPane != NULL) {
        swprintf_s(statusText,
            L"Screen Captured. 'MyDocuments\\NexusTK\\ScreenShots\\%s'", fileName);
        unsigned char savedModifierState;
        g_pEventMan->GetModifierState(&savedModifierState);
        g_pEventMan->m_modifierState = 0;
        g_pChattingDisplayPane->AddChattingMessage(statusText, 0x8f, 1, 0, 0, 0);
        g_pEventMan->m_modifierState = savedModifierState;
    }

    FILE *proofInput = g_pfnWideOpenFile(fullPath, L"rb");
    SendScreenshotProofPacket(proofInput);
    fclose(proofInput);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

No-header proof: UID0004WN owns the `ScreenPane::SaveScreenshotPNG` CPP definition only. Its member declaration belongs once in UID0000CB's complete ScreenPane H block; repeating it here would duplicate class output.

### Proposed Proof Child Formal Block

Destination: [UID:0004WO] `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall SendScreenshotProofPacket(FILE *stream)
{
    char proofMask[36] = "w-pu6a4Es*5pA@eg+tetayAp6us6EcrE";
    char *maskedDigest = Md5StreamHex(stream);

    for (int i = 0; i < 32; ++i)
        maskedDigest[i] ^= proofMask[i];

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x83, packet);
    memmove(packet + 1, maskedDigest, 13);

    packet[14] = static_cast<unsigned char>((rand() % 10) - 26);
    for (int i = 1; i < 16; ++i)
        packet[14 + i] = static_cast<unsigned char>(rand() % 255);

    memmove(packet + 30, maskedDigest + 13, 19);
    packet[49] = 0;
    g_packetSender->QueueAndSendPacket(packet, 49);
    free(maskedDigest);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

No-header proof: UID0004WO is a file-local `static` helper definition in ScreenshotCapture.cpp. It has no externally visible declaration and therefore contributes no header source.

### Proposed Proof Item Declaration Block

Destination: [UID:0000VF].

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall SendScreenshotProofPacket(FILE *stream);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

No-header proof: UID0000VF's forward declaration is intentionally file-local and must remain in CPP before the JPG/BMP/PNG callers. Moving or copying it into H would incorrectly publish an internal helper and duplicate its source-local declaration.

### Proposed UID0001G8 Replacement Formal Block

Destination: [UID:0001G8] after endpoint/path repair.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::SaveScreenshotJPG()
{
    wchar_t documents[MAX_PATH];
    wchar_t nexusDirectory[MAX_PATH];
    wchar_t screenshotDirectory[MAX_PATH];
    wchar_t fileName[256];
    wchar_t fullPath[MAX_PATH];
    wchar_t statusText[120];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documents) != S_OK)
        return;

    swprintf_s(nexusDirectory, L"%s\\NexusTK", documents);
    if (!g_pfnCreateDirectoryW(nexusDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(screenshotDirectory, L"%s\\NexusTK\\ScreenShots", documents);
    if (!g_pfnCreateDirectoryW(screenshotDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    __time64_t now = _time64(NULL);
    tm localTime;
    _localtime64_s(&localTime, &now);
    swprintf_s(fileName, L"TK_%04d%02d%02d%02d%02d%02d.jpg",
        localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,
        localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    swprintf_s(fullPath, L"%s\\%s", screenshotDirectory, fileName);

    FILE *output = g_pfnWideOpenFile(fullPath, L"wb");
    if (output == NULL)
        return;

    LPDIRECTDRAWSURFACE savedSurface = m_ddSurface;
    m_ddSurface = m_renderSurface;
    UpdateSurfaceInfo();
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserControlPane->BlitBrowserSurfaceToRenderTarget(m_ddSurface);

    WriteJpegFileFromRgb565Surface(
        static_cast<unsigned short *>(m_surfaceContext.pixelData),
        g_screenWidth, g_screenHeight, g_surfaceUsesRgb565Pixels, output);
    fclose(output);

    EndPaint();
    m_ddSurface = savedSurface;

    if (g_pChattingDisplayPane != NULL) {
        swprintf_s(statusText,
            L"Screen Captured. 'MyDocuments\\NexusTK\\ScreenShots\\%s'", fileName);
        unsigned char savedModifierState;
        g_pEventMan->GetModifierState(&savedModifierState);
        g_pEventMan->m_modifierState = 0;
        g_pChattingDisplayPane->AddChattingMessage(statusText, 0x8f, 1, 0, 0, 0);
        g_pEventMan->m_modifierState = savedModifierState;
    }

    FILE *proofInput = g_pfnWideOpenFile(fullPath, L"rb");
    SendScreenshotProofPacket(proofInput);
    fclose(proofInput);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

No-header proof: UID0001G8 owns the `ScreenPane::SaveScreenshotJPG` CPP definition only. Its member declaration belongs once in UID0000CB's complete ScreenPane H block; repeating it here would duplicate class output.

### Proposed UID0000CB ScreenPane Declaration Block

Destination: [UID:0000CB]. This is the applied complete class declaration with the three required declarations after `RestoreDirectDrawState()` and B002's accepted private `BlitSurfaceToDisplay` retained. Command17397 left CPP exactly blank and moved this declaration unchanged into H.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Blank-CPP proof: UID0000CB is the class-level declaration owner. It does not own method definitions; those remain in exact by-memory CPP children routed through their source files. Emitting the class declaration in CPP would conflate header and implementation channels.

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FunctionObject0;
class Layer;
class List;
class LObject;
class NotificationBlock;
class Region;

struct FrameUpdateContext {
    unsigned int callbackFrame;
    unsigned int currentFrame;
    bool dispatching;
};

class ScreenPane : public Pane,
                   public FrameHandler,
                   public Singleton<ScreenPane> {
public:
    ScreenPane(short screenWidth, short screenHeight, short screenBitDepth);
    virtual ~ScreenPane();

    int SetLayerFrame(int slot, Layer *layer);
    int DetachLayerFrame(Layer *layer);

    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual unsigned char HandleBrowserNotification(const NotificationBlock *block);
    virtual bool OnFrameUpdate(const FrameUpdateContext *context);

    void MarkDirtyRegion(const RectBounds *bounds);
    void StartPresentation();
    void SetActiveCursor(signed char cursorIndex, int force);
    void ShowCursor();
    void HideCursor();
    short GetScreenWidth() const;
    short GetScreenHeight() const;
    void PrepareDirectDrawPresentation();
    void RestoreDirectDrawState();
    void SaveScreenshotJPG();
    void SaveScreenshotBMP();
    void SaveScreenshotPNG();
    void EnablePresentationMode();
    void DisablePresentationMode();
    void LoadCursorResources();
    void LoadCursorResourceSlot(unsigned int cursorIndex,
                                const wchar_t *animatedCursorPath,
                                const wchar_t *staticCursorPath);
    int QueueFadeInCallback(LObject *callbackObject);
    int QueueFadeOutCallback(LObject *callbackObject);
    void SetFadeTransitionState(unsigned char state);
    bool IsFadeTransitionActive() const;
    void RestoreLostSurfaces();
    void TraversePresentationList(Region *dirtyRegion);

private:
    void RenderPresentation();
    void BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE sourceSurface,
                              RECT *sourceRect);

    LPDIRECTDRAWSURFACE m_primarySurfaceCreateResult;
    LPDIRECTDRAWSURFACE m_primarySurface;
    LPDIRECTDRAWSURFACE m_offscreenSurface;
    LPDIRECTDRAWSURFACE m_renderSurface;
    List *m_rootLayerList;
    bool m_restoreCooperativeLevelPending;
    bool m_restoreDisplayModePending;
    short m_screenWidth;
    short m_screenHeight;
    short m_screenBitDepth;
    bool m_hasPendingDirtyRegion;
    RectBounds m_pendingDirtyRegion;
    bool m_presentationModeEnabled;
    __declspec(align(4)) unsigned char m_presentationStateStorage[0x420];
    HCURSOR m_cursorHandles[12];
    short m_activeCursorIndex;
    unsigned char m_cursorStateStorage[0x16];
    short m_fadeCurrentValue;
    short m_fadePreviousValue;
    bool m_presentationDirty;
    short m_presentationJitterX;
    short m_presentationJitterY;
    int m_fadeTransitionState;
    FunctionObject0 *m_fadeCompletionCallback;
    int m_fadeStep;
    bool m_forceFullRedraw;
    bool m_browserNotificationPending;
    bool m_pointerInputActive;
};

extern ScreenPane *g_pScreenPane;

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- The exact split and metadata listed in the Executive Recommendation are applied and scoped-validated.
- Preserve UID0001G9 as the all-encompassing cluster document with byte hashes, child map, shared behavior, dependency flow, hotkeys, and rejected alternatives; do not prune its historical evidence.
- Focused-callback checkpoint command `17290` emitted exactly one body for each JPG/BMP/PNG/proof function and exactly one proof forward declaration. Bounded current command `17440` reconfirms those same CPP order/uniqueness/formal invariants; commands `17138`, `17264`, `17290`, `17324`, `17367`, `17397`, `17400`, `17414`, and `17423` are historical checkpoints rather than current generated identity.
- Separate-channel correction is `APPLIED_VERIFIED`: the six exact empty H dispositions remain blank, UID0000CB CPP is blank, and the complete ScreenPane declaration was moved unchanged into UID0000CB H. The migration added no duplicate declaration and did not alter the accepted `ScreenshotCapture.cpp` source order or bodies.
- Supervisor Gate 2A passed exact report SHA `57A4036FFFF29A0896A5D0F593BE609AB97BCFA81A5B049C670246E9A7F0B8E5`. Supervisor Gate 2B applied the exact itemized 9DF4 action package, preserved every no-change/protected row, passed the mechanical post-save verifier, and saved IDB poststate 7509EC84 under catalog entry `0310`.
- Historical `ScreenshotCapture` class output and aggregate empty-emitter behavior are superseded and absent from current generated output.
- No target remains blocked by names, ownership, range, proof layout, or first-draft C++ after this report. Remaining uncertainty is original-symbol/file-spelling confidence only and is reflected in sub-95 scores.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md`.
- Implementation status: original index rewrite applied by command `17098`; focused C1G9-023 prose applied/scoped-validated by command `17288`; source-channel rationale scoped-validated by command `17386`; current SHA256 `65B9777421F5413BED02B16870A8F1E0D961425154AD5AE933356E0412857507`. CPP and H remain exactly blank.
- Metadata: `93/94`, owner `0000ND`, reconstructable false, blank emitter/position/CPP/H, and exact `Nested:5` for three exact child pages plus two internal ignored spans.
- The exact five `Nested` entries are BMP child `[0x00557aa0,0x00557e73)`, internal 13-byte padding `[0x00557e73,0x00557e80)`, PNG child `[0x00557e80,0x00558239)`, internal seven-byte padding `[0x00558239,0x00558240)`, and proof child `[0x00558240,0x00558391)`. Preceding JPG padding `[0x00557a96,0x00557aa0)` and following successor padding `[0x00558391,0x005583a0)` are outside UID0001G9 and must not contribute to `Nested:5`.
- Generated-name rows are replaced with exact UID0004WM/UID0004WN/UID0004WO links.
- Exact whole-range and child SHA values, CC counts, hotkey table, complete BMP/PNG/proof data flow, exact error/cleanup behavior, and source-order decision are present.
- Surface-ID, `g_pMetaMan`, generic 16-random-byte, sent-terminator, and unresolved class/free-helper assumptions are preserved as superseded history rather than current claims.
- Current source routing states that code lives only in exact children.

## Recommended Support Doc Changes

| Support path | Applied implementation result |
| --- | --- |
| [UID:0004WM] `by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md` | Created first by command `17095`; command `17389` validates the retained exact BMP CPP body, explicit CPP-only/blank-H source-channel disposition, 92/94 metadata, ScreenPane owner, ScreenshotCapture emitter position20, complete behavior/formal, and UID0003CJ literal evidence. |
| [UID:0004WN] `by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md` | Created second by command `17096`; command `17391` validates the retained exact PNG CPP body, explicit CPP-only/blank-H source-channel disposition, 92/94 metadata, ScreenPane owner, ScreenshotCapture emitter position30, complete behavior/formal, and UID0003CJ literal evidence. |
| [UID:0004WO] `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md` | Created third by command `17097`; command `17392` validates the retained exact file-local CPP definition, explicit blank-H disposition, 93/94 metadata, ScreenshotCapture owner/emitter position40, ABI/layout, one-item `ScreenshotProofMaskLiteral` readback, and complete 32-character/33-byte-pool/36-byte-local/32-byte-XOR distinction. |
| `by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md` | Renamed/repaired by command `17099`; command `17395` validates owner0000CB, score91/92, emitter0000ND position10, unchanged exact CPP body, explicit blank-H disposition, and ten-byte padding. |
| `by-memory/-ignored.md` | Current drift readback preserves command `17122`'s complete alignment inventory and exact counts/topology/allocated-child evidence for all four screenshot spans; unrelated later additions account for the current file hash. |
| `by-item/ScreenshotProofPacket_00558240.md` | Command `17393` validates 92/94, owner/emitter0000ND, position5, unchanged CPP-only file-local forward declaration, explicit blank-H disposition, exact ABI/layout, sole-definition route to UID0004WO, and complete proof-mask source/storage distinction. |
| `by-class/ScreenshotCapture.md` | Focused command `17289` validates 91/93, owner0000ND, false/non-emitting source-family index, blank formal, complete module evidence, current one-item proof-mask state, and exact local-array/XOR interpretation. |
| `by-file/ScreenshotCapture.md` | Focused command `17290` validates 92/93, exact split/order/dependencies/declarations, corrected JPG end, no-duplicate routing, and complete proof-mask distinction. Bounded current generated command `17440` reconfirms the same CPP output invariants without changing this ordinary destination; commands `17367`/`17400`/`17414`/`17423` are historical. |
| `by-class/ScreenPane.md` | Command `17397` validates 93/94 with blank CPP and the exact complete declaration moved byte-for-text unchanged to H, preserving all three screenshot declarations, B002 UID0003A4's private `BlitSurfaceToDisplay`, all other declarations, and `[[CHILDREN]]` exactly once. Command17440 readback finds the complete declaration once in `ScreenPane.h` and zero complete `class ScreenPane :` declarations in `ScreenPane.cpp`; its unrelated `class ScreenPane;` forward declaration is preserved. |
| `by-file/ScreenPane.md` | Current shared-page readback preserves the cross-file screenshot method-definition route and exact children without moving definitions into ScreenPane.cpp, while retaining B002 UID0003A4 source routing and behavior. |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | Command `17120` validates corrected JPG/index/child inventory and ownership at report-level detail. |
| EventDispatcher docs | Commands `17123`, `17126`, and `17127` validate exact Scroll Lock and Ctrl+LeftShift+3/4 routing with latch semantics in file/memory/class pages. |
| BrowserControlPane docs | Commands `17131` and `17132` validate exact JPG/BMP/PNG callers as consumers of `BlitBrowserSurfaceToRenderTarget` without ownership transfer. |
| ScreenPane resource-string docs | Focused command `17291` validates exact JPG/BMP/PNG/proof child links, path/filename/status/mask literals, non-emitting source placement, the accepted one-item proof-mask readback, and the distinction between adjacent physical padding and the source local's three additional zero-initialized bytes without changing literal bytes or refs. |
| Network/LodePNG support | Commands `17134`, `17136`, and `17137` validate the exact 49-byte proof-send consumer in QueueAndSendPacket/g_packetSender and the direct stock `lodepng_encode32_file` PNG route. |

## Score And Metadata Recommendation

| Item | Historical pre-callback | Current applied | Reason |
| --- | --- | --- | --- |
| UID0001G9 | 87/89, true, owner/emitter 0000ND | 93/94, false, owner 0000ND, blank emitter/code | complete range audit and correct non-emitting container classification |
| UID0004WM BMP child | absent | 92/94, owner 0000CB, emitter 0000ND, pos20 | exact body/ABI/callers/data flow/formal code |
| UID0004WN PNG child | absent | 92/94, owner 0000CB, emitter 0000ND, pos30 | exact body/ABI/callers/data flow/formal code |
| UID0004WO proof child | absent | 93/94, owner/emitter 0000ND, pos40 | exact ABI/layout/xrefs/formal code |
| UID0001G8 | 88/89, owner/emitter 0000ND | 91/92, owner 0000CB, emitter 0000ND, pos10 | endpoint and source-shape/C++ repair |
| UID0000VF | 86/90, owner/emitter 0000ND | 92/94, same owner/emitter, pos5, declaration code | exact helper closure and no-duplicate declaration role |
| UID0000CD | 86/88, true/emits | 91/93, false/no emitter | source-family index, no concrete class |
| UID0000ND | 89/88 | 92/93 | complete source unit, order, includes, and exact child routes |
| UID0000CB | 92/93 | 93/94 applied | exact screenshot method declarations and receiver proof |

Score-improvement work completed:

- Resolved class/free-helper uncertainty through ABI and call sites.
- Resolved source placement and declaration order through physical cluster and ownership rules.
- Resolved raw field names through accepted GrafPort/ScreenPane layouts.
- Resolved return-type conflict through caller use and inconsistent EAX residues.
- Resolved proof packet types/layout/random/terminator through full disassembly.
- Resolved JPG boundary mismatch through raw bytes.
- Resolved blank-C++ blocker with complete formal blocks.
- Scores remain below 95 only because original source identifiers/file spelling and full compile/link equivalence are not proved by this documentation callback.

## Open Questions With Attempted Resolution

- Exact original filename capitalization: checked the accepted/implemented source tree, by-file docs, generated path, and physical cluster. Use `ScreenshotCapture.cpp`; preserve `ScreenShot.cpp` as historical alternate only. This does not block code.
- Exact method spelling (`JPG` versus `JPEG`): checked current project naming, existing generated block, format extension, and sibling names. Use `SaveScreenshotJPG` for consistency; keep `JPEG` as search alias only.
- Exact EventMan field spelling: live body proves byte `+0x920`; current class docs call it modifier state. Use `m_modifierState`. This is inferred spelling but high-probability human source, not a reason for raw offset code.
- Exact BrowserControlPane method spelling: live behavior and current class docs support `BlitBrowserSurfaceToRenderTarget`. Use it as descriptive source-facing name and retain address evidence.
- Exact proof helper spelling: source scope and payload role support `SendScreenshotProofPacket`; ABI is exact. No unresolved blocker remains.
- Full product compile equivalence: this callback proves scoped documentation validity and exact generated-source structure, not a full product build. A later project build remains the separate runtime/ABI equivalence check.
- No open question remains that requires postponing the split, metadata, IDA handoff, or first-draft code.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B004 inspected current manual by-memory, by-file, by-class, and by-item rows. They are stale. B004 must not edit coverage files.

`by-memory/-coverage-report.md`: replace the current UID0001G8/UID0001G9 rows and insert children/padding using the validator-allocated child UIDs below. B004 did not apply these supervisor-owned rows:

```markdown
        - [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) 0x00557840-0x00557a96 | retained ScreenPane method | ScreenPane::SaveScreenshotJPG : reconstructable : 91% : very-strong : Retained source-authored JPG screenshot method with corrected return-byte endpoint, exact ten-byte successor alignment, ScreenPane/GrafPort receiver fields, JPEG writer, caller-local secure formatting, status modifier-state save/clear/restore, proof dispatch, no direct raw-start route, source-ready C++03 body, ScreenPane canonical ownership, and ScreenshotCapture.cpp emitter route.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557a96-0x00557aa0 | padding | JPG to BMP screenshot alignment : ignored : 100% : exact : Ten `0xcc` bytes after the JPG return at 0x00557a95 and before BMP at 0x00557aa0.
        - [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md) 0x00557aa0-0x00558391 | semantic range index | ScreenshotCaptureAndProof : not_reconstructable : 93% : very-strong : Non-emitting exact index over ScreenPane BMP/PNG methods, file-local screenshot-proof helper, two internal CC spans, hotkey routes, DirectDraw capture state, image conversion, status notification, proof packet, dependencies, source order, and source-quality decisions; exact children alone emit source through ScreenshotCapture.cpp.
            - [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) 0x00557aa0-0x00557e73 | method | ScreenPane::SaveScreenshotBMP : reconstructable : 92% : very-strong : Exact void thiscall BMP screenshot method with two hotkey calls, 14/40-byte BMP headers, positive-height bottom-up 16-bit rows, RGB565-to-555 branch, GrafPort render-surface lock/unlock, browser blit, status modifier-state save/clear/restore, proof dispatch, and source-ready C++03.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557e73-0x00557e80 | padding | BMP to PNG screenshot alignment : ignored : 100% : exact : Thirteen `0xcc` bytes.
            - [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md) 0x00557e80-0x00558239 | method | ScreenPane::SaveScreenshotPNG : reconstructable : 92% : very-strong : Exact void thiscall PNG screenshot method with two hotkey calls, ACP path conversion, unchecked RGBA allocation, exact RGB555/RGB565 channel expansion, top-down row traversal, stock lodepng_encode32_file call, status modifier-state save/clear/restore, proof dispatch, and source-ready C++03.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00558239-0x00558240 | padding | PNG to screenshot-proof alignment : ignored : 100% : exact : Seven `0xcc` bytes.
            - [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) 0x00558240-0x00558391 | file-local helper | SendScreenshotProofPacket : reconstructable : 93% : very-strong : Exact static stdcall FILE-stream proof helper with JPG/BMP/PNG callers, MD5 hex masking by the fixed 32-character key stored in a 36-byte local array, opcode 0x83, 13+16+19 payload partition, asymmetric first random byte, local-only terminator, 49-byte Socket send, heap cleanup, and source-ready C++03.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00558391-0x005583a0 | padding | Screenshot proof to SurfaceDrawTilePresentation alignment : ignored : 100% : exact : Fifteen `0xcc` bytes before the successor at 0x005583a0.
```

The allocated UID/link substitutions are complete in this handoff. Supervisor must apply the rows without altering their meaning.

`by-file/-coverage-report.md`: replace UID0000ND row:

```markdown
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) : reconstructable : 92% : very-strong : Coherent ScreenshotCapture.cpp source unit with proof declaration, corrected retained JPG method, exact BMP/PNG ScreenPane method children, exact file-local proof helper, physical source order, dependency/include route, hotkey callers, DirectDraw/browser/status/image/proof behavior, no concrete ScreenshotCapture object, and duplicate aggregate/class emission removed.
```

`by-class/-coverage-report.md`: replace UID0000CD row and update UID0000CB's existing row description/score in place:

```markdown
- [UID:0000CD][ScreenshotCapture](by-class/ScreenshotCapture.md) : not_reconstructable : 91% : very-strong : Non-emitting screenshot source-family index; no concrete ScreenshotCapture object is present, while exact JPG/BMP/PNG ScreenPane methods and file-local proof helper emit through ScreenshotCapture.cpp.
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md) : reconstructable : 93% : very-strong : Root Pane/FrameHandler/Singleton<ScreenPane> controller retaining canonical singleton lifecycle, exact cursor table and dimensions, pending dirty-region state, seven existing source-ready UID0001G7 method children plus source-ready SaveScreenshotJPG/SaveScreenshotBMP/SaveScreenshotPNG declarations in deterministic source order, inherited GrafPort m_ddSurface capture switching, ScreenPane m_renderSurface ownership, DirectDraw/browser/status/proof interactions, and ScreenshotCapture.cpp routing for the three screenshot definitions without duplicate class-level bodies; retains the exact DirectDraw/presentation/callback/helper inventory and all existing caller/history evidence, exact RTTI/PMDs, old-MSVC Singleton EBO at +0xfc, binary size 0x5b4, ordinary destructor child UID0004W7, compiler-only UID00023U/UID0003CI and non-emitting UID0001G5 exclusions, source-facing OnTimer/OnFrameUpdate/HandleBrowserNotification declarations, complete compile-visible R3 through +0x5b3, the exact member table, and the evidence-backed provisional C++03 presentation-state/cursor-state storage required to preserve every later offset pending stronger semantic evidence.
```

`by-item/-coverage-report.md`: replace UID0000VF row:

```markdown
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md) : reconstructable : 92% : very-strong : ScreenshotCapture-owned proof declaration/index with exact static stdcall FILE-stream ABI, three JPG/BMP/PNG callers, MD5 mask key, opcode 0x83, 13+16+19 payload partition, asymmetric random padding, local-only terminator, 49-byte g_packetSender send, and sole-definition routing to the exact by-memory child.
```

Reason B004 must not apply: all `-coverage-report.md` files are supervisor-owned under concurrent-agent rules. Validator-allocated UIDs are now recorded exactly above so the supervisor can apply the handoff without further allocation research.

## Follow-Up Actions

Historical ordinary and focused C1G9-023 callbacks remain complete and `APPLIED_VERIFIED`; they are not repeated. Supervisor Gate 1 accepted exact channel-migration artifact SHA `DE516F8F1BAF24F77B1D60AB6BA208389E1BFF96C923411B0806F7D5545289C4`, and B004 completed that narrow callback under commands `17386` through `17397`. Supervisor Gate 2A then passed exact report SHA `57A4036FFFF29A0896A5D0F593BE609AB97BCFA81A5B049C670246E9A7F0B8E5`, and supervisor Gate 2B applied/verified/saved the full accepted IDA package. The remaining lifecycle order is exactly:

1. Fresh supervisor exact-artifact review of this post-Gate2 reconciliation, preserving the already-passed Gate 2A and Gate 2B records.
2. Supervisor-only `execute_report`/archive after that final report review.
3. Supervisor manual coverage updates after execution if still required; B004 does not edit coverage.

Later unrelated validator or IDB saves may advance shared provenance again; the exact 9DF4-to-7509 Gate 2B transaction and command-17440 Gate 2A result remain bounded verified report evidence rather than claims that shared artifacts can never advance.

No A-agent action is required. No separate future B-agent investigation is required for the blockers addressed here.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: 93/100.
- Direct behavior/boundary confidence: 99/100.
- Remaining uncertainty: original identifier spelling, exact source filename capitalization, and final whole-product compile/link equivalence. None requires raw IDA names or blank first-draft C++.

## Validator Results

- Historical ordinary callback validators all exited `0` with `ok:1`:

| Command | Scoped file/result |
| --- | --- |
| `17095` | Created/validated UID0004WM BMP child. |
| `17096` | Created/validated UID0004WN PNG child. |
| `17097` | Created/validated UID0004WO proof child. |
| `17098` | Validated UID0001G9 target index, 93/94 and exact `Nested:5`. |
| `17099` | Validated corrected/renamed UID0001G8 JPG page; validator also repaired inbound path references. |
| `17100` | Validated UID0000VF proof declaration page. |
| `17102` | Validated ScreenshotCapture class/source-family index. |
| `17105` | Validated ScreenshotCapture file/source-order page. |
| `17107` | Validated ScreenPane complete class formal and screenshot declarations. |
| `17109` | Validated ScreenPane file cross-source routing. |
| `17120` | Validated SurfacePresentation screenshot inventory. |
| `17122` | Validated `by-memory/-ignored.md` screenshot padding evidence. |
| `17123`, `17126`, `17127` | Validated EventDispatcher file/memory/class hotkey synchronization. |
| `17131`, `17132` | Validated BrowserControlPane memory/class screenshot-consumer synchronization. |
| `17133` | Validated ScreenPane resource-string child links/status semantics. |
| `17134`, `17136` | Validated QueueAndSendPacket and g_packetSender proof-consumer synchronization. |
| `17137` | Validated LodePNG direct stock API consumer closure. |
| `17138` | Revalidated `by-file/ScreenshotCapture.md` with `--wait-generated`; generated refresh completed. |

- Current post-drift merge validators all exited `0` with `ok:1`:

| Command | Scoped file/result |
| --- | --- |
| `17261` | Reconciled UID0004WO proof-mask prose to the applied one-item current IDA state while preserving exact proof metadata/formal/behavior. |
| `17263` | Reconciled the ScreenshotCapture class/source-family index to the applied one-item proof-mask state. |
| `17264` | Reconciled `by-file/ScreenshotCapture.md`, ran `--wait-generated`, and completed the then-current post-drift generated refresh. |
| `17266` | Reconciled UID0003CJ data-page current item/type/comment readback while preserving non-emitting metadata, bytes, refs, and source placement. |

- Focused C1G9-023 callback validators all exited `0` with `ok:1`, no warnings, and `generated_refresh: deferred`. Each command reported `projected_stats_update:1` and a target-specific `stats_incremental_noop:1`; B004 did not manually edit generated/projected/validator state.

| Command | Timestamp | Scoped file/result | Generated status |
| --- | --- | --- | --- |
| `17286` | `2026-07-24T12:07:53-04:00` | UID0004WO proof helper; exit `0`, `ok:1`; exact proof-mask distinction and unchanged formal validated. | deferred, command id `17286` |
| `17287` | `2026-07-24T12:08:47-04:00` | UID0000VF proof item; exit `0`, `ok:1`; declaration-only route and complete distinction validated. | deferred, command id `17287` |
| `17288` | `2026-07-24T12:09:25-04:00` | UID0001G9 aggregate; exit `0`, `ok:1`; non-emitting index and complete distinction validated. | deferred, command id `17288` |
| `17289` | `2026-07-24T12:10:03-04:00` | UID0000CD class/source-family page; exit `0`, `ok:1`; non-emitting ownership and complete distinction validated. | deferred, command id `17289` |
| `17290` | `2026-07-24T12:10:44-04:00` | UID0000ND file page; exit `0`, `ok:1`; source-local distinction and no-duplicate route validated. | deferred; focused-callback ScreenshotCapture.cpp checkpoint |
| `17291` | `2026-07-24T12:11:25-04:00` | UID0003CJ pooled-resource page; exit `0`, `ok:1`; pooled/local/alignment distinction validated. | deferred; non-emitting page did not supersede ScreenshotCapture.cpp header |

- Narrow source-channel migration callback validators all exited `0` with `ok:1`. B004 leased one ordinary file immediately before its edit, validated serially, and released that lease before touching the next file.

| Command | Timestamp | Scoped file/result | Warnings / generated status |
| --- | --- | --- | --- |
| `17386` | `2026-07-24T21:11:23-04:00` | UID0001G9 container; exact blank CPP/H disposition made explicit without code change. | no warnings shown; generated deferred |
| `17389` | `2026-07-24T21:12:55-04:00` | UID0004WM BMP; exact CPP body preserved and blank-H ownership rationale added. | no warnings shown; generated deferred |
| `17391` | `2026-07-24T21:13:35-04:00` | UID0004WN PNG; exact CPP body preserved and blank-H ownership rationale added. | no warnings shown; generated deferred |
| `17392` | `2026-07-24T21:13:58-04:00` | UID0004WO proof; exact CPP body preserved, blank-H file-local rationale added, and validator inserted the missing UID0000VF link text. | no warnings shown; one `uid_link_insert`; generated deferred |
| `17393` | `2026-07-24T21:14:23-04:00` | UID0000VF proof item; exact CPP declaration preserved and blank-H file-local rationale added. | no warnings shown; generated deferred |
| `17395` | `2026-07-24T21:14:55-04:00` | UID0001G8 JPG; exact CPP body preserved and blank-H ownership rationale added. | no warnings shown; generated deferred |
| `17397` | `2026-07-24T21:15:36-04:00` | UID0000CB ScreenPane; exact complete declaration moved byte-for-text unchanged from CPP to H, CPP blanked, and `--wait-generated` completed. | exit `0`, `ok:1`; 15 pre-existing missing-ref UID notices plus broad project generated child/emitter warnings; generated refresh completed |

- Historical generated checkpoint from command `17138`: SHA256 `EAE7D223941F927EA57A592D39AD86C84FAA0133DE3C6913696BA32F211913F4`, 10,643 bytes, 271 lines. It is retained as callback history, not current physical generated identity.
- Historical post-drift generated checkpoint from command `17264`: SHA256 `EE42A50EB0A91FE0B4FAB1862BA90B5F90B13F252215D5B971D075451ACB0E8A`, 10,643 bytes, 271 lines. It predates the focused prose callback.
- Focused C1G9-023 generated checkpoint from deferred-refresh header command `17290`: `auto-generated/NexusTK/render/ScreenshotCapture.cpp`, refreshed `2026-07-24T12:10:44-04:00`, SHA256 `5F59CCFF387FF0979EE39AC33DBC624CEFF71BC7547BC77F2CA8B226B47CBA32`, 10,641 bytes, 271 lines. This checkpoint remains tied to the accepted focused callback but is no longer current physical generated identity.
- Historical bounded observation, read-only and without invoking any validator: foreground-refresh command `17324`, refreshed `2026-07-24T12:27:14-04:00`, SHA256 `DE8D407A6851C28866FF6E635A71412577165F991F91F9918D4A10C3EFBAEDDF`, 10,643 bytes, 271 lines. It is no longer current physical generated identity.
- Historical bounded observation command `17367`, refreshed `2026-07-24T20:02:22-04:00`, SHA256 `48F78BF41C23DB9128E169EAEA15EC9242F0F6BFD328DD55C04AFBDB9D29C550`, 10,643 bytes, 271 lines, is retained as the immediate pre-channel-migration generated checkpoint.
- Bounded current generated observation is foreground command `17440`, refreshed `2026-07-24T22:15:48-04:00`. `auto-generated/NexusTK/render/ScreenshotCapture.cpp` is SHA256 `0D84A6A7E77F39E7754C74A6343CC923AEB45A180B89EC073E7DA8EC3830FA01`, 10,643 bytes, 271 lines. Exact source order remains proof declaration line 8, JPG line 11, BMP line 73, PNG line 167, and proof definition line 251. Counts remain one proof declaration, one proof definition, one JPG definition, one BMP definition, one PNG definition, zero UID0001G9 rows, zero UID0000CD rows, zero complete `class ScreenPane :` declarations, and zero Empty Emitter Markers. The proof body retains the exact 32-character literal in local `char proofMask[36]` at line 253 and `for (int i = 0; i < 32; ++i)` at line 256. Each of the five generated source blocks is byte-for-text equal to its accepted destination CPP formal after line-ending normalization.
- Current command17440 header output: `auto-generated/NexusTK/ui/core/ScreenPane.h` is SHA256 `E4AF47FA68D58FDA1284B932856A367B60EBCF06801F0DCB7A859AEB06338F57`, 3,379 bytes, 97 lines, with the complete declaration once at line 21, the three screenshot declarations once at lines 44/45/46, and private `BlitSurfaceToDisplay` once at line 62. Normalizing validator's sole line-97 `[[No Children Attached]]` fallback back to `[[CHILDREN]]` makes its 90-line declaration body byte-for-text equal to UID0000CB H; both normalized bodies have SHA256 `29F8753D18E3440981E9B692FFDF778FC8B256369A424FB72E7475D7D4130C00`. `auto-generated/NexusTK/ui/core/ScreenPane.cpp` is SHA256 `DE2825D9CC78F9924A87A5BA6A0A895F39423456C624CD29CAD80068025E17F2`, 20,515 bytes, 604 lines, with zero complete `class ScreenPane :` declarations and zero screenshot declarations/definitions. It preserves one unrelated `class ScreenPane;` forward declaration at line 535 and one validator-owned UID0000CB `Empty Emitter Marker` at line 604 because UID0000CB intentionally has blank CPP while emitting H; neither is a duplicate declaration or body, and B004 did not edit generated output.
- Current command `17440` formal/content comparison: BMP, PNG, proof, proof declaration, and JPG remain equal to the accepted CPP formals; their H bodies remain blank. UID0001G9 remains blank in both channels. UID0000CB CPP is blank and its H declaration is byte-for-text unchanged from the accepted formal with `[[CHILDREN]]` exactly once. Generated source order, body uniqueness, proof formal, and H declaration placement are `APPLIED_VERIFIED`. Commands17400/17414/17423 are historical provenance-only post-migration checkpoints. No full product compile is claimed. Later unrelated refreshes may change command/timestamp/hash without erasing the independently passed command-17440 Gate 2A checkpoint.
- Non-blocking validator output: historical callback commands, historical command `17264`, and command `17397` reported broad project-wide child-marker/emitter or stale-reference warnings unrelated to the accepted UID0001G9 channel move. Commands `17386`, `17389`, `17391`, `17392`, `17393`, and `17395` showed no warnings. Every narrow callback scope returned exit `0`, `ok:1`; no callback-scoped validator error remains.
- Supervisor Gate 2A result: `PASSED` for exact report SHA256 `57A4036FFFF29A0896A5D0F593BE609AB97BCFA81A5B049C670246E9A7F0B8E5`. The supervisor independently verified all seven current ordinary destination hashes and every command-17440 generated invariant recorded above; no ordinary repair was required.
- Supervisor Gate 2B result: `APPLIED_VERIFIED`. Prestate and verified backup were both SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, 143,186,002 bytes. All accepted apply rows were mutated/read back exactly; every no-change/protected row remained exact; the mechanical post-save verifier passed 25 primary/protected rows, ten exact global-name matches, both pooled-literal interior-parent rows, and all required boundary/type/comment/xref checks. MCP `idb_save` returned `ok:true`; saved poststate SHA256 is `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`. Catalog entry is `0310`; detailed Gate 2A/Gate 2B records are in `b-report-validation-audit.md`.

## Changed Files

- Historical command-`17095` through `17138` post-callback hashes are retained below as the original implementation checkpoint. They are explicitly superseded as current identity wherever later UID0003CJ, B002, validator, or B004 drift-reconciliation work changed a destination:

| File | SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md` | `19DF4B04F83528004A6F35A0BA08A1BC8A5F557FDAC81E8E513F6BC704DA8A66` | 10,561 / 182 |
| `by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md` | `0C5AD39DF21DB02198C3E8EDE3A00F22A5D1E272DC60FFE12195A903C2F6503B` | 10,070 / 170 |
| `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md` | `1632EE61F018A743BDBE69B3942CD3E0ECC3B0AB2568E419F23DE6FEFE51DEBA` | 7,531 / 113 |
| `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md` | `9F078AF25957AAD6D7F70329A03357C1BC7C23A450B3E23B6B691A5EDEEF1B99` | 22,368 / 181 |
| `by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md` | `91653D7A29178F229B54A6256B3D3B1B461A66FC0540771E02840CC5A4A7D82D` | 23,586 / 235 |
| `by-item/ScreenshotProofPacket_00558240.md` | `83D996E8FF087A11AC089A94798C951AE7C136E2474A7EADA6C584F4532DCE09` | 11,706 / 96 |
| `by-class/ScreenshotCapture.md` | `39A5A5899E352EC611946B785871A25F1960972FB07B6D630F08A374FC36D61D` | 14,630 / 95 |
| `by-file/ScreenshotCapture.md` | `93BF4898A0BE2F31DCCD9C95F12A224D13A8B852D64B8A86C781A9DBC16ED38F` | 21,149 / 158 |
| `by-class/ScreenPane.md` | `2BD149C7B59ACD3645E131509E673174913FA2C8B9651888464F90B2D422778A` | 58,225 / 375 |
| `by-file/ScreenPane.md` | `174DDB0A26D9F079CFA840A88240972687748BD326B994267733C829822CAD70` | 53,965 / 250 |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | `5AC7AEB28AABAD0BF9062CF1A1513540B4436ADA869D28DDC5EE4AB3258944BA` | 58,405 / 245 |
| `by-memory/-ignored.md` | `5FD7D6BBACABE9B662BB55CEF79D2A641A3F2FD47234589B168733B91698E42C` | 1,108,307 / 5,375 |
| `by-file/EventDispatcher.md` | `D699E3EA9B270CE2CCC40667A066139FF77D2A279EB3316EB5348DA5D91AF56D` | 37,240 / 189 |
| `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` | `E809D2F9CCDCF8A4167284BB981786632B329A24B5EDD3B306680D07E2DD6A33` | 43,230 / 330 |
| `by-class/EventDispatcher.md` | `C9F97523A1C4E6B8C9771B5D0E88E78F44FB2D7F0782231B01973F3DE432ABE5` | 30,582 / 233 |
| `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | `F268BCDA4476BBA5ECD2C458EB0F87F745DA33FE9588EAD7E1D9FCE5ABBB4D7F` | 37,650 / 280 |
| `by-class/BrowserControlPane.md` | `5A29A97F8E17363C05DFEC5C5B66102D35069006B198FB46B6BBD2E0E9DFFB45` | 31,611 / 187 |
| `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md` | `3F08DA58D39C1DDB163C0E42978E3CFD483ED62A6945C614F1EB8C3EC02F1776` | 5,351 / 64 |
| `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` | `0852C193249C561F59624D2E9499EEAA346391C860362F7AA74E0904DA7BC31F` | 26,091 / 161 |
| `by-global/g_packetSender.md` | `05B95D371B95883760D721B8C283FB23A659AA918DB3B13C58F416282C53F8DE` | 34,653 / 204 |
| `by-file/LodePNG.md` | `69779C724D4B5EF9C66D7C310608F29518923D7F16C3D6E2220B3F350DEA63B1` | 20,550 / 127 |

- Historical post-drift/pre-focused-callback destination checkpoint after the lease-clear reread and commands `17261`, `17263`, `17264`, and `17266`; the six C1G9-023 destinations superseded below no longer use these checkpoint hashes:

| File | Current SHA256 | Current bytes / lines |
| --- | --- | --- |
| `by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md` | `0BB6267865135DC84B1E52475593A1E06BCBE61B761575E86AEA98EBB70CE9C9` | 11,712 / 190 |
| `by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md` | `A00FED2488B7BE94D5DEEDA9D8ED858D70A014D82240E55E1A943A38C18F7080` | 11,265 / 178 |
| `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md` | `9115B4FE9C673D60E10B1DBA45718A8A046501D9BBADD43BA9AF0C9AA441FF50` | 9,685 / 123 |
| `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md` | `9F078AF25957AAD6D7F70329A03357C1BC7C23A450B3E23B6B691A5EDEEF1B99` | 22,368 / 181 |
| `by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md` | `DDF3E84B32157FB5912EC90A8D35A8D5DA73014D4EEDD56822DA102FB843E468` | 24,813 / 243 |
| `by-item/ScreenshotProofPacket_00558240.md` | `83D996E8FF087A11AC089A94798C951AE7C136E2474A7EADA6C584F4532DCE09` | 11,706 / 96 |
| `by-class/ScreenshotCapture.md` | `F2A89ABB24EB5C2A353E10D30DE5BE84B9120B9C0B2A7DF99A9B20A9D8DC8D2A` | 16,549 / 105 |
| `by-file/ScreenshotCapture.md` | `807624734DB6BD19A2E0DBBF9B5B34D4AE0EA81AE6A88D864963FD30FB8A96C8` | 23,680 / 179 |
| `by-class/ScreenPane.md` | `9F1F86A8A3F85CEAB93208580AC4753ACB7AF3810BC229924ED7444E566CE6B1` | 61,990 / 392 |
| `by-file/ScreenPane.md` | `8A91FC37444ADE48F06AD0C78D2A782C8C949CA30634569A1094202B86E84B70` | 56,264 / 266 |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | `61F033FC374CAEBEE51C633BC80B6A704813D38C1AC6C73978DDF69398FCC0DF` | 59,404 / 247 |
| `by-memory/-ignored.md` | `3C142D38CCB8F7F318F19D94CD24D77ACE942A82C8CCB4F297D159FC5E55C426` | 1,108,289 / 5,375 |
| `by-file/EventDispatcher.md` | `D699E3EA9B270CE2CCC40667A066139FF77D2A279EB3316EB5348DA5D91AF56D` | 37,240 / 189 |
| `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` | `E809D2F9CCDCF8A4167284BB981786632B329A24B5EDD3B306680D07E2DD6A33` | 43,230 / 330 |
| `by-class/EventDispatcher.md` | `C9F97523A1C4E6B8C9771B5D0E88E78F44FB2D7F0782231B01973F3DE432ABE5` | 30,582 / 233 |
| `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | `F268BCDA4476BBA5ECD2C458EB0F87F745DA33FE9588EAD7E1D9FCE5ABBB4D7F` | 37,650 / 280 |
| `by-class/BrowserControlPane.md` | `5A29A97F8E17363C05DFEC5C5B66102D35069006B198FB46B6BBD2E0E9DFFB45` | 31,611 / 187 |
| `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md` | `125F26E97B894B792EF23ADBA38843236227D5D3556DE644B7320EDCEACBF969` | 13,620 / 114 |
| `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` | `0852C193249C561F59624D2E9499EEAA346391C860362F7AA74E0904DA7BC31F` | 26,091 / 161 |
| `by-global/g_packetSender.md` | `05B95D371B95883760D721B8C283FB23A659AA918DB3B13C58F416282C53F8DE` | 34,653 / 204 |
| `by-file/LodePNG.md` | `69779C724D4B5EF9C66D7C310608F29518923D7F16C3D6E2220B3F350DEA63B1` | 20,550 / 127 |

- Historical focused C1G9-023 destination identities immediately after serial scoped validation and lease release; validator-owned H-header insertion later superseded these hashes where noted in the current table:

| File | Current SHA256 | Current bytes / lines | Validator |
| --- | --- | --- | --- |
| `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md` | `444E4AC30C8B5149BC9C24BBF3F1F396D69AC5DE82D29D629B5A01CB32976851` | 10,621 / 125 | `17286` |
| `by-item/ScreenshotProofPacket_00558240.md` | `23E2CE1B40A0A850080FA349F9AF6EBCAA8B418D7DCABB63EC931FC11F8EDAB8` | 12,992 / 100 | `17287` |
| `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md` | `838AB03186C98DB750E5CB9661B0AE13A201CB22AB0C20B05F209AF01F50C18B` | 23,288 / 183 | `17288` |
| `by-class/ScreenshotCapture.md` | `DAEBBE08CBEFC58F7730591755603DC01AD40E99B0F66DEEE5A66FC941328E86` | 17,298 / 107 | `17289` |
| `by-file/ScreenshotCapture.md` | `3FCF32F41821D747A714A50DFAD5796C0B35637E40D5169661A3AD3B1A2E5AF0` | 24,226 / 181 | `17290` |
| `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md` | `82417DB1B51CFBBA26CDDDD9F555FA599C6E701724037A50D3C1363D31B2B175` | 14,657 / 116 | `17291` |

- Focused-callback generated checkpoint: `auto-generated/NexusTK/render/ScreenshotCapture.cpp`, deferred-refresh header command `17290`, refreshed `2026-07-24T12:10:44-04:00`, SHA256 `5F59CCFF387FF0979EE39AC33DBC624CEFF71BC7547BC77F2CA8B226B47CBA32`, 10,641 bytes / 271 lines.
- Historical validator-owned generated observation: foreground-refresh command `17324`, refreshed `2026-07-24T12:27:14-04:00`, SHA256 `DE8D407A6851C28866FF6E635A71412577165F991F91F9918D4A10C3EFBAEDDF`, 10,643 bytes / 271 lines.
- Historical pre-channel-migration seven-destination identities are the `15AB.../9B00.../685B.../DC69.../45FA.../C69C.../9538...` checkpoint recorded in Supporting Research. Current post-callback identities are:

| UID / file | Current SHA256 | Bytes / lines | Current CPP/H state | Validator |
| --- | --- | --- | --- | --- |
| UID0001G9 `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md` | `65B9777421F5413BED02B16870A8F1E0D961425154AD5AE933356E0412857507` | 23,722 / 186 | CPP blank; H blank; explicit non-emitting channel rationale | `17386`, exit0/ok1 |
| UID0004WM `by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md` | `83E571D0FA4C4724BAD6679DF94B3218251232490D814CB8D4A0FB9E731D4A8D` | 12,118 / 193 | exact existing CPP definition unchanged; H blank; explicit declaration-owner rationale | `17389`, exit0/ok1 |
| UID0004WN `by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md` | `07EFC9927B33DB6B58EC9BCCC4FE4D2F46ACC1BF8EA95F776F5946B1385AE9E4` | 11,671 / 181 | exact existing CPP definition unchanged; H blank; explicit declaration-owner rationale | `17391`, exit0/ok1 |
| UID0004WO `by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md` | `99CE53659AE7494027159AF1D26D22860EAE0B4B67E5B5A017BC31C46F17FC2A` | 11,103 / 128 | exact existing file-local CPP definition unchanged; H blank; validator-normalized UID0000VF link | `17392`, exit0/ok1 |
| UID0000VF `by-item/ScreenshotProofPacket_00558240.md` | `BE0ED2E2E615EFDC3462D90A028FD759E1F0F6B13B789B47B37E302FCA20DA10` | 13,380 / 103 | exact existing file-local CPP declaration unchanged; H blank | `17393`, exit0/ok1 |
| UID0001G8 `by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md` | `6AD6CA3DED8DAC77569B25113C96D56FDFE3C69F9A50CBC74EAE6E0BD4C9B50E` | 25,219 / 246 | exact existing CPP definition unchanged; H blank | `17395`, exit0/ok1 |
| UID0000CB `by-class/ScreenPane.md` | `6044A11BCCA02CB9371808024F2E03705EDE4A629DC69B680C1C40E087B60E84` | 62,298 / 394 | CPP blank; exact complete declaration H-only; `[[CHILDREN]]` once | `17397`, exit0/ok1 |

- Gate 1 repair readback: all seven ordinary paths above were rehashed without editing after command17440. Every SHA256, byte count, line count, and modification time still matches the recorded post-callback state exactly; no ordinary destination drift occurred and no lease or validator was used for this report-only repair.

- Bounded current validator-owned generated observation: foreground-refresh command `17440`, refreshed `2026-07-24T22:15:48-04:00`. ScreenshotCapture.cpp is SHA `0D84A6A7E77F39E7754C74A6343CC923AEB45A180B89EC073E7DA8EC3830FA01`, 10,643 bytes / 271 lines; ScreenPane.cpp is SHA `DE2825D9CC78F9924A87A5BA6A0A895F39423456C624CD29CAD80068025E17F2`, 20,515 bytes / 604 lines; ScreenPane.h is SHA `E4AF47FA68D58FDA1284B932856A367B60EBCF06801F0DCB7A859AEB06338F57`, 3,379 bytes / 97 lines. Historical commands `17138`, `17264`, `17290`, `17324`, `17367`, `17400`, `17414`, and `17423` remain evidence checkpoints.

- Renamed: `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md` to the corrected half-open-end path `by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md`; validator command `17099` updated inbound links.
- Updated report: `tools/leaser/Agents/Agent-B004/research/0001G9-ScreenshotCaptureAndProof-source-quality.md`; final artifact metrics are returned to the supervisor after this text is complete.
- Validator-owned generated/readback files: current bounded observation command `17440` and current SHA/size/line metrics above; focused callback checkpoint remains command `17290`, and commands `17324`/`17367`/`17400`/`17414`/`17423` are historical. B004 did not edit generated files by hand.
- IDA mutation actor scope: B004 made none and remained read-only. Supervisor Gate 2B applied/verified the accepted package to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, preserved exact prestate backup `E:\NTK\Resources\NexusTK\NexusTK.exe.uid0001g9.pre-gate2b.20260724_224938.i64` at SHA256 9DF4/143,186,002 bytes, and saved poststate SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`.
- Supervisor Gate records: catalog entry `ida-recommendation-implementation-catalog.md` `0310`; Gate 2A and Gate 2B audit entries in `b-report-validation-audit.md`. B004 did not edit either supervisor-owned file during this reconciliation.
- Manual coverage edits: none; exact supervisor-owned payload remains in this report with allocated UIDs.
- Leases: one ordinary file at a time; every B004 lease was released immediately after its scoped validator. Current lease report contains no B004 row.
- Report execution: still not run. B004 did not run, probe, dry-run, or invoke `execute_report` or any lifecycle command; execution/archive remains supervisor-only.

## Implementation Tracking Checklist

Initial report and ordinary implementation:

- [x] Supervisor Gate 1 passed exact pre-callback SHA `7F1572EED6B0A4929E5EC19651EC72CFB2603471C73DC20CB6329E5EAC549442` before implementation.
- [x] Target UID0001G9 metadata/index rewrite applied with exact `Nested:5`, counting only BMP child `[0x00557aa0,0x00557e73)`, 13-byte internal padding `[0x00557e73,0x00557e80)`, PNG child `[0x00557e80,0x00558239)`, seven-byte internal padding `[0x00558239,0x00558240)`, and proof child `[0x00558240,0x00558391)`; preceding JPG padding `[0x00557a96,0x00557aa0)` and following successor padding `[0x00558391,0x005583a0)` remain outside UID0001G9 and outside this count.
- [x] BMP exact child created target-first as UID0004WM by command `17095`.
- [x] PNG exact child created second as UID0004WN by command `17096`.
- [x] Proof exact child created third as UID0004WO by command `17097`.
- [x] UID0001G8 endpoint/path, owner, score, evidence, and formal block repaired.
- [x] UID0000VF proof forward declaration, position, score, and exact evidence applied.
- [x] UID0000CD source-family index reclassified false/non-emitting.
- [x] UID0000CB complete class declaration retains all prior declarations, B002's private `BlitSurfaceToDisplay`, and exactly the three screenshot declarations; command17397 moved the exact declaration unchanged from CPP to H and left CPP blank.
- [x] UID0000ND source contents/order/includes/dependency documentation updated.
- [x] UID0001G6, EventDispatcher, BrowserControlPane, resource strings, network/LodePNG, and other accepted support rows synchronized at report-level detail.
- [x] Four exact padding spans recorded in `by-memory/-ignored.md` without creating code/data.
- [x] Corrected C1G9-023 proof-mask wording is `APPLIED_VERIFIED` across UID0004WO, UID0000VF, UID0001G9, ScreenshotCapture class/file, and UID0003CJ under commands `17286` through `17291`: fixed 32-character literal, 33-byte pooled item including NUL, inferred 36-byte local array with three additional trailing zero-initialized bytes, and XOR indices `0..31`. C1G9-033/034 remain supervisor handoffs.
- [x] Revoked-pass drift audit re-read all ten named destinations and historicalized superseded callback hashes; its former C1G9-023 repair handoff was subsequently completed by focused commands `17286` through `17291`, while C1G9-033/034 retain their supervisor handoff states.
- [x] Current UID0003CJ additions preserved; stale three-head/future-consolidation prose was reconciled to the applied `ScreenshotProofMaskLiteral` item without changing bytes, refs, source ownership, or emission.
- [x] Current B002 UID0003A4 ScreenPane class/file additions preserved; this report's complete ScreenPane formal was synchronized to the current superset rather than overwriting concurrent work.
- [x] Current target state and actual live evidence preserved.
- [x] Metadata/score changes applied only after supervisor acceptance.
- [x] Owner/emitter/reconstructable/position changes applied exactly.
- [x] Split/rename/new-child changes applied in target-first UID-allocation order.
- [x] Source placement, padding, declaration, include, and source-order decisions applied.
- [x] All 20 primary IDA rows plus five protected dependency rows, including apply, no-change, and `ALREADY_PRESENT_VERIFIED`, were re-read read-only from active session `supervisor_current_20260724_9f6e` against exact historical pre-mutation IDB SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`; the complete audit was enclosed by identical before/after hash, 143,186,002-byte size, and `2026-07-24T22:09:37.3164487-04:00` write time, and a byte-identical supervisor backup preserves that prestate. Names/signatures/types/widths/UDT-local-state dispositions/collisions/boundaries/xrefs/readbacks are recorded row by row, with all four modeled-function comment channels and all item comments independently read. The 9DF4 state is historical pre-mutation evidence; supervisor Gate 2B subsequently produced verified saved poststate 7509EC84.
- [x] Supervisor Gate 1 passed exact repaired artifact SHA `DE516F8F1BAF24F77B1D60AB6BA208389E1BFF96C923411B0806F7D5545289C4`, including the seven separate CPP/H dispositions and preserved full CB62 IDA-table prestate repair.
- [x] B004 narrow implementation callback preserved the six exact blank H bodies, moved the complete UID0000CB declaration unchanged from CPP to H, blanked UID0000CB CPP, validated serially under commands `17386` through `17397`, and recorded current command17440 CPP/H generated readback without declaration duplication or concurrent-detail loss.
- [x] Supervisor Gate 2A passed exact report SHA `57A4036FFFF29A0896A5D0F593BE609AB97BCFA81A5B049C670246E9A7F0B8E5` and independently verified every current ordinary destination hash and command-17440 generated invariant.
- [x] Supervisor Gate 2B applied and read back every UID0001G9 executable function/instruction/global/alignment action exactly, preserved every no-change/protected row, passed the 25-row mechanical verifier, saved poststate SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, and recorded catalog entry `0310`.
- [x] Accepted UID0003CJ proof-mask consolidation remains `ALREADY_PRESENT_VERIFIED` as one protected `const char[33]` item `[0x006232e0,0x00623301)` after supervisor Gate 2B; both interior-parent rows, all three refs, exact type/name/comment, and source-shape distinction passed mechanical post-save verification. B004 made no IDA mutation.
- [x] All seven CPP/H dispositions remain physically present and exact; UID0001G9 CPP/H are blank, the four implementation definitions and UID0000VF file-local declaration remain correctly routed in CPP with blank H, UID0000CB CPP is blank with its complete declaration in H, and current command17440 preserves their generated order and channel separation.
- [x] All seven H dispositions are callback-verified: six target-specific H bodies remain blank, UID0000CB's complete declaration is moved unchanged to H, UID0000CB CPP is blank, `[[CHILDREN]]` occurs once in the destination formal, and no declaration is duplicated.
- [x] Third-party import directive confirmed not applicable to this target; LodePNG remains a separate dependency.
- [x] Historical assumptions and negative evidence preserved, not deleted.
- [x] All ordinary source-quality open questions closed to high-probability source direction.
- [x] Scoped validators ran serially for every original callback, drift merge, focused C1G9-023 destination, and narrow channel destination; commands `17386`, `17389`, `17391`, `17392`, `17393`, `17395`, and `17397` each exited `0` with `ok:1`, and every lease was released immediately afterward.
- [x] Focused generated checkpoint command `17290` is preserved, commands `17324`, `17367`, `17400`, `17414`, and `17423` are historical, and bounded current command `17440` was read back for exact proof-declaration/JPG/BMP/PNG/proof CPP order, one-of-each uniqueness, exact 32-character literal in local `char proofMask[36]`, XOR-only indices `0..31`, complementary 33-byte pooled-item evidence, zero UID0001G9/UID0000CD screenshot-family markers, zero ScreenshotCapture Empty Emitter Markers, one complete ScreenPane declaration in H, and zero complete `class ScreenPane :` declarations in CPP. ScreenPane.cpp's unrelated forward declaration and single validator-owned UID0000CB empty-CPP marker are recorded separately and are not duplicate declarations/bodies.
- [ ] Supervisor applies exact manual coverage rows with allocated UIDs after execution if still required.

Implementation callback pass:

- [x] Historical full callback and focused C1G9-023 callback were each authorized by their exact Gate 1 artifacts; focused authorization SHA is `9747ABACFFD7A9038DEF33E5635A4FC4D2A6DA9341BDC49525541B5098E096DD`.
- [x] B004 remained read-only in IDA. Supervisor Gate 2B, not B004, applied and saved the accepted UID0001G9 action package; accepted UID0003CJ mask state and every no-change/protected row remained unchanged and verified.
- [x] One ordinary file was leased only immediately before each edit and released after its scoped validator.
- [x] Every accepted target/support detail, including focused C1G9-023 proof-mask prose, was incorporated without summarizing away evidence and re-read against current hashes while preserving B001/B002 additions.
- [x] Every created/changed UID was verified against the claim ledger and exact ranges.
- [x] Every proposed source fragment resides only in a complete formal CPP or H block; there is no illustrative/sample C++ outside formal metadata.
- [x] Channel migration callback confirms implementation definitions and UID0000VF's source-local forward declaration remain CPP-only, while the sole complete ScreenPane declaration is H-only.
- [x] No `-coverage-report.md`, generated/tracker, audit/supervisor/goal, validator-state, or lifecycle file was edited manually by B004.
- [x] Historical callback, drift, focused C1G9-023, and narrow channel-migration validator command IDs/results are recorded in this same report together with focused checkpoint `17290`, historical commands `17324`/`17367`/`17400`/`17414`/`17423`, and bounded current generated observation `17440`.
- [x] Remaining items are listed exactly and in lifecycle order: fresh supervisor exact-artifact review of this reconciliation; supervisor-only execution/archive; and C1G9-033 manual coverage after execution if still required. Gate 2A, C1G9-034 Gate 2B, accepted UID0003CJ proof-mask IDA state, C1G9-023 ordinary implementation, and the source-channel migration are complete rather than pending.
- [x] Report returned to supervisor; B004 never executes its own report.
- [ ] Supervisor-only `execute_report`/archive after final exact-artifact review; Gate 2A and Gate 2B already passed.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000017450","destination_path":"executed-b-agent-research/B004/0001G9-ScreenshotCaptureAndProof-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001G9-ScreenshotCaptureAndProof-source-quality.md","timestamp":"2026-07-24T23:12:22-04:00","uid":"0001G9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
