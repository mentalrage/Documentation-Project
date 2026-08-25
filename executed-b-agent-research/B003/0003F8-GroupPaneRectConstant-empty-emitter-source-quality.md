# UID0003F8 GroupPane Rectangle Constant Empty-Emitter Source-Quality Report
** TARGET-REPORT-UID:0003F8 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Primary target: UID0003F8, by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md.
- Physical disposition: [0x00624bf0,0x00624c00) is one 16-byte data item named xmmword_624BF0. Bytes are 06 00 00 00 0E 00 00 00 A1 00 00 00 36 00 00 00, SHA256 A9CB5BAE7A86BEF48A98DBDFA3BFD6919991F1731C183BF87B24B99C675E03B6, decoded by RectBounds as left=6, top=14, right=161, bottom=54.
- Source disposition: compiler-pooled image of the automatic local aggregate initializer `RectBounds rowBounds = { 6, 14, 161, 54 };` in `NewGroupPane::OnPaint()`. It is not a global, static, member, array element, or separately named source object; constructor syntax is rejected because the authoritative `RectBounds` declaration has no constructor.
- Ownership/emission: the callback changed the direct owner/emitter from file UID0000JS to class UID000090 at position 76, after UID0003F2 position 75 and before the next method position 80. UID0000JS remains the transitive Group.cpp root.
- Formal source: the target CPP now contains the exact covered-by marker in Section 22 and target H remains blank. UID0004Z5 now contains the complete corrected formal CPP: six accepted `EPFTileContext::Initialize()` calls, `.bounds`, the `COMMA.EPF` lookup, one reused context, global `GroupMemberRecord`, exact partial `HumanImageRenderParams` writes, full `NewHumanImageLib` call contracts, and constructor-free `RectBounds` source. The callback also installed UID0001VF's dependency-complete nested-row H at position 10, UID000092's class H after the explicit child insertion point, and UID0000RT's extern after the class.
- Score: current ordinary metadata is target 94/94; UID0004Z5 completion 94/confidence 93; UID0001VF 92/93; UID000092 90/91; and UID0000RT 90/93. UID0000UN and UID0000TN retain 90/92 and 94/95 because their complete dependencies are consumed by include rather than duplicated; UID0000FQ, UID00050M, UID0000A1, and UID0000RW retain their accepted scores. Original local spellings, const qualifiers, and the initialized-only scratch context's intent remain inference caps.
- IDA: dated supervisor Gate 2B applied IDA-F8-01's exact address-repeatable provenance comment at 0x00624bf0 and verified IDA-F8-02/03 as exact no-change protections for the data identity, consumer function/frame/comments, vtable cell, load/store instructions, padding, and neighbors. The saved-IDB receipt and post-save attestation are recorded below; current IDA authority remains a fresh supervisor readback, not a permanent report-body hash claim.
- Closure allocation: all 90 claims are checked with evidence-backed final states. The 19 supervisor-owned rows close as 14 `APPLIED_VERIFIED` and five `NO_CHANGE_VERIFIED`. Report execution/archive state is authoritative only from the report's current path and validator-owned status/history metadata.

## Supporting Research

- Dated 2026-08-15 ordinary readback: target SHA256 549F83B7341D429E57BD358DDE16CD805563DDB29D5D86EF3205886F21839CDE; UID0004Z5 6DAB2D739B4D5F39E5E73A991391D14CA79D0BC4FD4F38935222A909547F0006; UID000090 2ED259FAD17E938302EAA214AF3806ADFEB380E57AD869061F45D3687FC9DE20; UID0000JS C9D131F21D48AABDA324E6EB8349061BD2E06E62CF7AB6A7EDBCCBC87E5D269B; UID0001HC 83E0814A7E5D28ED8E56E6D53D6E1630FE615C545AEF8734535D421381A50CF8; UID0002V2 D276C3FCF3BFD6340E26A531146269E3EF849580B8940A8883541CFC606DF9DD; UID0001VP F91373E23033563A2164F77C929437089976BA88F234A4A49AF4D3FF300DC496; UID00004I `EPFTileContext` 22900C0A31570AF51EF310C32D085D9A82806FC0DD849253C17B28C8DE67856F; UID0003EV `SharedCommaEpfResourceString` EA97D325D44A8C5616D075BE4F82A47EAA4E32CDE043EDCB3666F27A27041489.
- Applied callback ordinary readback after the final scoped validation: UID0003F8 `3FFE367F3B67A9247F766850A66EE15E0D19EAD2537E55D7FC77DF796F23B787`; UID0004Z5 `3E1F4113FD85CCB2F560A7556859E74D8D6118F14FCA845B498F98B41AA3E873`; UID000090 `F590524037371AFF7883E9A9DB67898CFA40C1C9B0E51112D67F28DC22BB3D03`; UID00005X mechanical preamble carrier `5A6585DAF8C1E2E0EB5A628A55071A8F276D06F10A82B320CA9EDF656B1B120E`; UID0000JS `38B87698D11847ED5961B12B1593C66FE2B592905314022B4DE6203CF474E845`; UID0001HC `9CE9A8B9B2A3F351F14509FD8E04414BD42FB4DBE448665D8997D9384BAA41D8`; UID0002V2 `B656CAAC737C5C3A13B8B5DF862973992331F16FCE096F36351A3B7D496926AA`; UID0003EV `2E8D80D5B99862E255E08E727F7C18CFDE32A8985238DFA15F50250D39075FB0`; UID0000FQ `A3E48A0BD653534F0AE8E6363833532BE7ABA27864281A2F90803DF746397AD9`; UID00050M `3677CD459F4CD8D5A4215684BAD6828E83B48457482E4DB469B060D64F39D53E`; UID0001VF `EFBD56398226E33719BE8A32241649954FCD95898874FA6F7709CA094CE016BF`; UID000092 `A8C98D8836F335D552C3809FE94E5E82EC3FC38BFAFB0608C10807FF6EB88867`; UID0000RT `D63E4FB983FD86F345F7C5243C6063822A59CE62848DB9B7B0A143F0DB574545`; UID0000A1 `17D1239951C201147FB3B306B537566338C05F39C238AB3AE466B22A66E85606`; UID0000RW `A41479994ECD65A3F7A4B9879DBAB20B0782BEE9FC43C84753BFE73BB8105D29`.
- Dated validator-owned readback for command 000000024431, refreshed 2026-08-15T19:57:54-04:00: Group.cpp SHA256 E20A024A85200385B2F463AA5A878F96FA232C0D2971C8EF54859E551FB3E795, 52,510 bytes / 1,432 lines; Group.h SHA256 7873C2BC4927FF0EB066673B721A24540ED4A97E3F2775051C7397F22D31920A, 1,851 bytes / 50 lines; EPFTileContext.h SHA256 DE96336BF1B08954155EC8263445473A5885C5FBF55FEEB116A899384207DF9F, 1,199 bytes / 39 lines. The EPFTileContext header exposes `RectBounds bounds;` and `void Initialize();`, has no `m_bounds`, and declares no constructor.
- That Group.cpp receipt has `NewGroupPane::OnPaint` at line 177 and `rowBounds` at line 185, but its method body has zero `.Initialize()` calls, nine invalid `.m_bounds` accesses, zero `.bounds` accesses, and zero `COMMA.EPF` occurrences. It therefore is dated defect evidence, not source authority. In that dated receipt UID0003F8 remained the target Empty Emitter Marker at line 1432.
- Dated 2026-08-15 declaration readback at validator command 000000024441: `UserPane.h` declares global `GroupMemberRecord`, not `UserPane::GroupMemberRecord`, and keeps `m_groupMembers[50]` private without `NewGroupPane` friendship; `NewHumanImageLib.h` declares the packed 0x40 `HumanImageRenderParams` with `m_*` fields and no `Reset()` but omits the `NewHumanImageLib` class and singleton extern; `RectBounds.h` declares four public edges plus geometry methods but no constructor, `Width()`, or `Height()`; `PaletteLib` and `g_pPaletteLib` are emitted in CPP while the compile-visible H channel is blank. Section 22 supplies the exact complete H assemblies, singleton split, and file-preamble CPP disposition rather than treating these contradictions as future blockers.
- Dated 2026-08-16 pre-callback dependency readback at validator command 000000024570: generated `NewHumanImageLib.h` SHA256 51D6A23E8E7DE953CFAB98D46B018AB4819523FF12C33AAFC9867FD72CF6EB7C, 2,390 bytes / 74 lines, emitted only UID00050M and no `NewHumanPartEntry`, `NewHumanLayerEntry`, `NewHumanMotionEntry`, `NewHumanCompositionDrawCommand`, or `Acc2DrwEntry` definitions. `ImageFrameTable.h` SHA256 5F8BDFC7305FD098375E179B6C059D655009A16155A6DDD21839CF722BF4CCEC, 1,024/40, already supplied complete `RectBounds`, `ArchiveMetadataTable`, and `FrameDrawRecord`; `Surface.h` SHA256 702A4E75FDD20C6C0D95675B740EA933AC91AAA213D12F87BAED780A705237CA, 3,087/102, already supplied complete 0x20 `SurfaceSpriteBlitOptions` and a pointer-only `DLPalette` declaration. UID0001VF formal H was blank at SHA256 033FDE9D4C733D2D6EC63FB66EE90C0885D20A2E0F2B40DD4676D91546EB0138. This is historical defect proof; the applied callback now defines, rather than forward-declares, all five vector element types.
- Dated read-only manual-coverage recheck at 2026-08-15T22:10:38-04:00: by-memory SHA256 4E8B2EB694A13FAFBC682DC3D38601EEF8329A1FAF66197B37F56EC7CEDB75DC, 2,244,480 bytes / 5,015 lines; by-class SHA256 9F748714DD88004E0207A9D34004F015505613DBE7208B4344144E179ABD6EFE, 279,995 bytes / 627 lines; by-type/by-struct SHA256 0EE29720F89870C2B34EC46FE506B0AC3729BC9E93CBA83C88A017D1B0089712, 59,326 bytes / 139 lines; by-global SHA256 D54D412EE6E6D486EFD645F40469D74D9BD51EFC104E31CC98896C57A9DA9603, 100,818 bytes / 219 lines; by-file SHA256 39BA7D0BACF7C554A6BF4103DA5156842364A108A0E0FAAB1984920207ECA251, 171,470 bytes / 320 lines. UID0003EV remains absent between exact UID0003EU line 4609 and UID0003EW line 4610. Section 28 supplies exact target/core rows plus dispositions for UID0000FQ, UID00050M, UID000092, UID0000RT, UID0000A1, UID0000RW, and UID0003EV.
- Archived/executed research was searched by UID, range, xmmword_624BF0, GroupPaneRectConstant, NewGroupPane, RectBounds, rowBounds, EPFTileContext, and COMMA.EPF. Historical B001 material supplied only the generic family lead; dated live IDA plus accepted type/resource documentation controlled the recommendation, while the superseded pre-callback UID0004Z5 formal CPP is retained only as historical defect evidence. Current UID0004Z5 formal CPP is the applied Section 22 body.
- Dated supervisor Gate 2A generated continuity snapshot at validator command 000000024682: Group.cpp `D47C02567E488D08F8FFFB7F7C884981C1BA2F604CA9826A6AA56BCFD8CF5410`; Group.h `5830A1BA5E04169328CCE873B83AA7E1B96139A7767BE5BB4B7D3C95E887E45B`; NewHumanImageLib.cpp `F19609E6038B8830D674986BF0B0455A30B5E89AEC25F0882E90891B3ED98D43`; NewHumanImageLib.h `3BA183447C3AB345D88363EE210AF501FB73EE3F64D7A37999A102A3911694B4`; PaletteLib.cpp `2D26CC0DB312B59884E6915252AB3B24EF670B9B75EC661505E22BAF5E7C4DDC`; PaletteLib.h `1D147A50389C0C0FF397E7FB010B4FF71FA41889FD47354CF12A3D18E3542B0C`; UserPane.h `2A0728D6E72C6BF6037A09E331D57F800742FE7B52EC684319E2AB4B59480B15`. Physical content passed the complete report contract. These hashes are a dated Gate 2A receipt; validator-owned generated authority is reread dynamically.
- Dated supervisor manual-coverage closure used commands 000000024688 through 000000024692, each exit 0 with `ok: 1`. The post-command snapshots were by-memory `F76DCEC44035F10942608245138A4C622FA0D6206083DD4E3191DA4A1433BD92`, 2,277,601 bytes / 5,070 lines; by-class `3715B24B0AB799B4840D08506F3469CEA714A9E3FF2AC97E42560B6CF18DE034`, 281,416 / 628; by-type/by-struct `CC89CD5B9689D8530F8511CDC4825CDF3CE0AEF96C917D65460E93AC5C05E7A3`, 59,994 / 140; by-global `4B6617E984E9409D44F6D1D5C26B26EAFADDE9CA19682A90885B914565C33810`, 100,825 / 219; and by-file `5A5831DDB9719031C461CD4CA0C2397C6F9E86BC791698ADC5BA235070BE024E`, 173,543 / 321. UserPane, ImageFrameTable, and Surface coverage were exact no-change. These identities are historical closure receipts, not permanent current authority.
- Dated supervisor Gate 2B used byte-preserving backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B003-UID0003F8-Gate2B-20260816-023410.i64` from pre-IDB SHA256 `6460365C357C1DC3F9EAABCF4A77B11E48760F32758D2A364E80AFE1D13BCB5C`; applied the exact IDA-F8-01 repeatable comment; protected IDA-F8-02/03 with no change; saved SHA256 `9FF6BDCB38628D90066441629ED6B47D8FFBB689DD097D2E41C7BAE40A3550BC` at `2026-08-16T06:34:32.4648784Z`; and passed post-save attestation/readback. The saved hashes are transaction receipts, while fresh runtime attestation/readback controls current IDA authority.

## Target

- UID: 0003F8.
- Path: by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md.
- Range: [0x00624bf0,0x00624c00), size 0x10.
- Assignment metadata: 85/88, owner/emitter UID0000JS, TRUE, blank position, CPP, and H.
- Historical assignment-time generated defects: NexusTK/social/Group.cpp contained one UID0003F8 Empty Emitter Marker, and the direct UID0004Z5 method dependency had zero explicit context initialization, invalid `.m_bounds` fields, an omitted COMMA lookup, incorrect local-context separation, nested `UserPane::GroupMemberRecord`, nonexistent `HumanImageRenderParams::Reset()`/unprefixed fields, shortened `NewHumanImageLib` calls, nonexistent `RectBounds` construction/size helpers, and absent compile-visible render-library declarations. The implementation callback repaired every listed defect.
- Recommended route: UID0003F8 -> UID000090 position 76 -> UID0000JS.

## Current Target State

- Current ordinary target prose resolves the exact method, typed local lowering, source name, row behavior, owner/emitter, formal route, negative evidence, historical assumptions, and safe IDA disposition at report depth. Metadata is 94/94, owner/emitter UID000090, position 76, TRUE, exact covered-by CPP, and blank H.
- Dated research-time IDA prestate was one data item [0x00624bf0,0x00624c00), name xmmword_624BF0, type absent, address-regular comment absent, address-repeatable comment absent, with function comment channels not applicable. Dated Gate 2B later applied exactly the proposed repeatable comment and protected every other target/function/neighbor field; Section 21 preserves both the accepted contract and verified result without claiming permanent current session state.
- Exact bytes occur once. There is one inbound xref at 0x0056cf78, no outbound xref, and no tested interior xref at +1, +4, +8, +0xc, or +0xf.
- Sole consumer is NewGroupPane__OnPaint, [0x0056ce50,0x0056da03), type void __thiscall(NewGroupPane *this). It loads the vector, immediately stores it to stack local bounds : RectBounds, copies the rectangle for row work, shifts left/right by five in expanded mode, and advances top/bottom by 44 per row.
- The current UID0004Z5 formal source is the accepted Section 22 method. It preserves the packed-load phase, uses constructor-free edge arithmetic and accepted `.bounds`, emits all six explicit `EPFTileContext_Initialize` calls and the `COMMA.EPF` lookup, reuses one context across non-overlapping phases, uses global `GroupMemberRecord`, performs only observed descriptor writes, passes full NewHuman arguments, and has compile-visible header declarations/friendship. The earlier defective method is retained only as dated historical evidence.

## Executive Recommendation

1. The accepted callback replaced generic/deferred prose with exact bytes, hash, layout, xrefs, pointer searches, load/store, function/frame/vtable, row behavior, source ranking, rejected alternatives, and historical context.
2. UID0003F8 now routes through UID000090 at position 76 and emits the exact covered-by CPP marker with blank H.
3. UID0004Z5 now emits the complete Section 22 body: six explicit `Initialize()` calls, accepted `.bounds`, exact `COMMA.EPF` lookup, one reused `tileContext`, global `GroupMemberRecord`, binary-exact partial descriptor writes, full NewHuman bounds/draw arguments, direct edge arithmetic, and `InitRectBounds` only where the binary calls it.
4. The support closure is applied: `NewGroupPane` friendship; UID0001VF's eight guarded internal layouts; UID000092's complete class after the explicit child insertion point; UID0000RT's extern after the class; one complete PaletteLib H plus UID0000RW-owned extern; no duplicate CPP-local class declarations; and the exact Group.cpp preamble before children through the UID00005X mechanical carrier. UID0000UN/ImageFrameTable.h and UID0000TN/Surface.h remain sole transitive dependency owners.
5. Current ordinary scores are UID0003F8 94/94, UID0001VF 92/93, UID0004Z5 94/93, UID000092 90/91, and UID0000RT 90/93; UID0000UN, UID0000TN, and the remaining support scores retain the accepted dispositions.
6. Dated supervisor closure completed manual coverage claims C-F8-039..044, C-F8-065..071, and C-F8-087..089 plus IDA claims C-F8-036..038. All 19 twins are checked with exact applied/no-change dispositions; dynamic current authority still comes from fresh supervisor readback.

## Supervisor Active Recheck

- The declaration-repair recheck used active adopted canonical session `supervisor_uid0000li_i13rollback_20260815` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; idb_list at 2026-08-15 EDT listed redirector PID 21644. These identifiers are dated evidence only.
- Schema-1 runtime attestation at 2026-08-16T01:13:44Z returned top-level `ok:true`, worker `ok:true`, and empty errors; listener PID 14320 and stateful worker PID 12492, parent 21644, are dated only. Fresh inspect-items/comments/xref/function-profile/decompilation readbacks reconfirmed the literal target/function prestates and supplied the complete descriptor-write, bounds, draw-call, and declaration reconciliation below.
- Health returned status:ok, NexusTK.exe, image base 0x00400000, Hex-Rays/string caches ready. auto_analysis_ready:false did not block any required bounded query.
- Dated 2026-08-16 pre-Gate-2B `idb_list` selected read-only session `supervisor_uid0003d9_rollback_20260815` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Bounded decompilations reconfirmed exact append strides and fields: 0x004e1040 copies two OWORDs and advances 32 for layer rows; 0x004e11b0 copies four OWORDs plus one dword and advances 68 for part rows; 0x004e0e20 zeros/copies 66-byte motion rows at exact offsets; 0x004e1800 stores two bool bytes plus one bool byte and advances 3; 0x004e21d0 constructs/appends the 80-byte command with embedded frame/options/palette. That evidence session was read-only.
- Dated Gate 2B then passed against matching prestate: IDA-F8-01 was applied exactly, IDA-F8-02/03 were no-change verified, the prechange backup and saved hashes are recorded in Supporting Research, and post-save attestation/readback passed.
- Session/PID/hash snapshots are dated transaction evidence only. Fresh supervisor runtime attestation, canonical IDB identity, and bounded target readback determine current IDA authority.

## Inference Research Guidance Check

- Lost lexical local name is inferred as rowBounds rather than preserving xmmword_624BF0 because the value becomes one mutable row rectangle and accepted method source already uses that spelling.
- Source shape follows compiler lowering: one packed image, one SIMD load, immediate typed stack store, local mutation, no address escape, no independent identity.
- `EPFTileContext` is an ordinary 0x28-byte struct with an explicit `Initialize()` method, not a class whose constructor hides initialization. Human source must call that API six times in the binary-observed order.
- One source-facing `tileContext` is deliberately reused for background, member-row, and toggle lookups because all three non-overlapping phases use the same `[ebp-0x198]` slot without another initializer. The remaining five slots are expressed as `commaFrame`, three bar contexts, and an inferred `scratchContext`; the last is initialized but never read, so its exact original spelling/intent remains a documented confidence cap rather than an omitted call.
- `COMMA.EPF` is looked up at 0x0056cf20 into initialized `commaFrame` after all six initializers and before the background lookup. No later instruction reads that context in this method, so source preserves the call and output object as observable resource/cache/output-write behavior without inventing a direct `DrawNumberString` data dependency.
- `HumanImageRenderParams` is an unconstructed packed local. The binary does not clear all 0x40 bytes and calls no reset helper: it writes `m_displayStatusByte` once before the loop, then only the exact selector/color/default fields itemized below for each row. Whole-object zeroing would change the observed write set and is rejected.
- `GroupMemberRecord` is global. Direct access to private `UserPane::m_groupMembers` requires an explicit `friend class NewGroupPane;` declaration, not a nested-type fiction or public-layout weakening.
- `RectBounds` uses C++03 aggregate initialization/direct edge arithmetic and the existing `InitRectBounds` helper only at the toggle site where the binary actually calls 0x004b7c50; nonexistent constructor/`Width()`/`Height()` calls are rejected.
- The exact 0x004e09e0 and 0x004e06a0 argument counts/order match accepted `NewHumanImageLib::CalculateBounds` and `Draw` consumers. The callback placed those declarations and `extern NewHumanImageLib *g_pNewHumanImageLib` in the compile-visible header route.
- C++03 container completeness is non-negotiable: all five `std::vector<T>` element types must be complete before `NewHumanImageLib` is declared. UID0001VF therefore emits the exact 0x44 part, 0x20 layer, packed 0x42 motion, 0x50 composition-command, and 3-byte accessory rows at H position 10; `FrameDrawRecord`/`RectBounds` and `SurfaceSpriteBlitOptions` remain single-owned by UID0000UN/ImageFrameTable.h and UID0000TN/Surface.h and are included rather than copied.
- Only genuinely pointer/reference-only names remain incomplete at the class declaration: `GrafPort *`, `Motion *`, `const NewHumanCompositionState &`, and `NewHumanCommandSideRecord *` (inside `std::deque<NewHumanCommandSideRecord *>`). A pointer is a complete C++03 element type even when its pointed-to record is incomplete; none of the five vector element types receives that exception.
- GroupPaneRectConstant remains a useful physical scanner label, not an emitted source symbol.
- Exact values and behavior are direct; only lexical spelling and position are inferred.
- No blocker is deferred. Stripped spelling is non-semantic and does not prevent human-written source.

## Heuristic / Inference Reanalysis And Validation

- Named automatic local initializer: very strong; typed local persists through the row loop.
- Unnamed temporary: compiler-plausible but inferior human source because the rectangle is repeatedly mutated.
- Function-local static: rejected; no guard, identity, escape, or repeated direct read.
- Class static/member: rejected; no member-relative access or cross-method use.
- File/global object: rejected; one pooled read does not establish source storage.
- Array/table element: rejected; no base/index computation.
- Four unrelated integers: rejected by exact RectBounds UDT, one vector copy, typed local, and edge mutations.
- Class-owned covered-by child: strongest project representation; preserves physical provenance without duplicate storage or method code.
- Explicit lifecycle calls: required. Replacing them with a constructor is contradicted by the accepted type declaration and all six direct calls.
- Shared scratch context: strongest source shape for background/rows/toggle because one physical slot is initialized once and overwritten across those phases; three separate source variables would imply extra initialization calls absent from the binary.
- COMMA lookup: retain as a direct statement before background selection. Its output's lack of a later read does not remove the call's resource/cache/output-write behavior.
- Initialized-only sixth local: preserve as `scratchContext.Initialize()`; omitting it changes the call stream, while assigning a decompiler label or an invented semantic consumer overclaims evidence.
- Descriptor initialization: preserve only observed stores. A synthetic `Reset()`, value-initialization, or member.bodyColor copy is rejected; the binary stores descriptor body/weapon/shield/mantle/neck/shoes colors as zero, sets `m_invisible` with the final zero word, and leaves the documented untouched fields indeterminate.
- API/header closure: global record spelling, private friendship, NewHuman/PaletteLib class methods and singleton externs, ImageLib/Surface/GrafPort/Region APIs, Win32 `MulDiv`, and CRT wide-string calls are all explicit dependencies; the completed ordinary callback applied them with the body and physically verified the source-ready closure.
- Nested-row header closure: forward-declared vector elements are rejected. Live loader/copy/stride evidence plus UID0001VF establish exact declarations and C++03 size guards; existing UID0000UN and UID0000TN H owners close the only by-value transitive dependencies without duplicate definitions.

## Evidence Standards Used

- Very strong: literal bytes/hashes/boundaries, unique searches, xrefs, instructions, type/frame/vtable, accepted formal source, or current metadata.
- Strong: local spelling, initialized-only scratch-context intent, class ownership, emitter position, score, and coverage wording supported by convergent evidence but not original symbols.
- Negative conclusions require bounded searches or structural contradictions.
- Live IDA and ordinary docs control; generated files are dated validator-owned readback.

## Evidence Checked

- UID0003F8 and support UIDs 0004Z5, 000090, 0000JS, 0001HC, 0002V2, 0001VP, 00004I, 0003EV, 0000FQ, 00050M, 0001VF, 0000UN, 0000TN, 000092, 0000RT, 0000A1, and 0000RW.
- Neighbor/control UIDs 0003F2, 0003F6, 0003F7, and 0003F9.
- Generated Group.cpp/Group.h and EPFTileContext.h, tracker, generated memory coverage, and manual by-memory/by-class/by-file coverage.
- MCP idb/session health/attestation, items, bytes, comments, xrefs, function profile, full frame, struct, disassembly/decompilation, scoped instruction queries, data flow, and bounded byte/pointer searches. Scoped queries proved exactly six calls to 0x00457a60, one `COMMA.EPF` operand, the exact partial descriptor-store set, the full 0x004e09e0/0x004e06a0 call arguments, and the human-image bounds/destination geometry in UID0004Z5.
- Fresh read-only MCP session `supervisor_uid0003d9_rollback_20260815` decompiled `LoadMotionTable` at 0x004e0e20 and `BuildCompositionDrawCommands` at 0x004e21d0: the former proves zero-initialized packed 66-byte motion rows and exact +0x17/+0x1b/+0x31/+0x32/+0x36/+0x3a/+0x3e fields; the latter proves 80-byte command rows with embedded initialized 40-byte frame, 32-byte options, and palette pointer. No mutation/save endpoint was called.
- Matching archived/executed reports only; stale Wave2/Wave3 material was ignored.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|
| C-F8-001 | 0003F8 | Target is [0x00624bf0,0x00624c00), size 16, SHA256 A9CB5BAE7A86BEF48A98DBDFA3BFD6919991F1731C183BF87B24B99C675E03B6. | very-strong | live item/bytes | UID0003F8 range | incorporate | applied |
| C-F8-002 | 0003F8 | IDA name xmmword_624BF0; type, AR, AP absent; FR/FP not applicable. | very-strong | live item/comments | UID0003F8 IDA state | incorporate | applied |
| C-F8-003 | 0003F8 | RectBounds decodes left=6, top=14, right=161, bottom=54. | very-strong | live struct read | UID0003F8 behavior | incorporate | applied |
| C-F8-004 | 0003F8 | Exact 16-byte sequence occurs once in the loaded image. | very-strong | byte search | UID0003F8 uniqueness | incorporate | applied |
| C-F8-005 | 0003F8 | One inbound xref at 0x0056cf78; no outbound or tested interior xrefs. | very-strong | xref inventory | UID0003F8 xrefs | incorporate | applied |
| C-F8-006 | 0003F8 | VA search finds only operand at 0x0056cf7b; RVA/raw-offset searches add no route. | very-strong | pointer searches | UID0003F8 liveness | incorporate | applied |
| C-F8-007 | 0004Z5 | Load [0x0056cf78,0x0056cf7f), bytes 0F 28 05 F0 4B 62 00, SHA 4BCCE14AA114D95AE3A8C37260C49D33130BC9852A2209FE89B19BF62447DF60. | very-strong | instruction/bytes | UID0004Z5 provenance | incorporate | applied |
| C-F8-008 | 0004Z5 | Store [0x0056cf8b,0x0056cf92) writes bounds.left; SHA 1E43E29EA20CA9929F7ED191980A599A9D1B2AC862EFFD811BD2B75FA5B6FC6B. | very-strong | disassembly/frame | UID0004Z5 local init | incorporate | applied |
| C-F8-009 | 0003F8 | RectBounds is four int fields at 0,4,8,0xc. | very-strong | UDT/UID0001VP | UID0003F8 type | incorporate | applied |
| C-F8-010 | 0004Z5 | NewGroupPane__OnPaint is [0x0056ce50,0x0056da03), SHA D3FB87AF11A14632F0BC954B387ECC83DBAC01D423426E1DECC7E55A2ABD960C, typed, 728 instructions/56 blocks/19 callees/0 code callers. | very-strong | function profile | UID0004Z5 identity | incorporate | applied |
| C-F8-011 | 0004Z5 | Vtable cell 0x00624598 uniquely routes to 0x0056ce50; SHA 0670DADBA6165B99082256465ECBD290347CC782CA53FBFEFBFC4E373C556803. | very-strong | vtable/xref | UID0004Z5 virtual route | incorporate | applied |
| C-F8-012 | 0004Z5 | Frame contains bounds : RectBounds at offset 0x1d8 and receives the packed value. | very-strong | frame/store | UID0004Z5 local model | incorporate | applied |
| C-F8-013 | 0004Z5 | Expanded mode adds 5 to X edges; loop adds 44 to Y edges; modes render 6/12 rows; one 0x28-byte tileContext slot is reused across background, row, and toggle phases. | very-strong | full method/frame | UID0004Z5 geometry/lifetimes | incorporate | applied |
| C-F8-014 | 0003F8 | Human source is `RectBounds rowBounds = { 6, 14, 161, 54 };`; current RectBounds has no constructor. | strong | lowering plus authoritative H | UID0003F8 source | incorporate | applied |
| C-F8-015 | 0003F8 | Standalone global/static/member/array/table emission is invalid. | strong | sole local use | UID0003F8 negatives | reject-invalid | reject-invalid |
| C-F8-016 | 0003F8 | Canonical owner changes UID0000JS -> UID000090. | strong | method/class route | UID0003F8 metadata | incorporate | applied |
| C-F8-017 | 0003F8 | Emitter changes to UID000090 position 76. | strong | positions 70/75/80 | UID0003F8 metadata | incorporate | applied |
| C-F8-018 | 0003F8 | Score changes 85/88 -> 94/94 only after UID0004Z5 body plus record/descriptor/NewHuman nested-row/Palette/RectBounds/include dependencies are corrected together; inferred rowBounds spelling/pooling caps confidence at 94. | strong | physical and dependency-complete declaration closure | UID0003F8 metadata | incorporate | applied |
| C-F8-019 | 0003F8 | Formal CPP is exact Section 22 covered-by marker. | very-strong | no-duplicate route | UID0003F8 CPP | incorporate | applied |
| C-F8-020 | 0003F8 | Formal H remains blank. | very-strong | no declaration | UID0003F8 H | incorporate | applied |
| C-F8-021 | 0003F8 | Prose/summary preserve complete evidence and rejected forms. | very-strong | report evidence | UID0003F8 prose | incorporate | applied |
| C-F8-022 | 0004Z5 | Replace the invalid/partial formal CPP with Section 22's declaration-compatible body: six Initialize calls, `.bounds`, COMMA lookup, reused tileContext, global GroupMemberRecord, exact partial m_* descriptor writes, full NewHuman calls, and constructor-free RectBounds geometry. | very-strong | live disassembly/frame plus authoritative headers | UID0004Z5 CPP/prose | incorporate | applied |
| C-F8-023 | 0004Z5 | Keep completion 94, owner UID000090, position 70, TRUE, and blank H; correct confidence 95 -> 93 for inferred local spellings and initialized-only scratch-context intent. | strong | exact behavior plus lexical/intention cap | UID0004Z5 metadata | incorporate | applied |
| C-F8-024 | 000090 | Add UID0003F8 position-76 child; preserve complete class and 94/95. | strong | class topology | UID000090 inventory | incorporate | applied |
| C-F8-025 | 000090 | No duplicate class/member declaration or score change. | very-strong | complete class | UID000090 H/metadata | incorporate | applied |
| C-F8-026 | 0000JS | Literal split audit closes UID0003F8 through UID000090 into Group.cpp; incorporate the corrected UID0004Z5 body and explicit UserPane/NewHuman/Palette/ImageLib/Surface/Win32/CRT include dependencies while keeping 91/88 because unrelated historical partition questions gain no new evidence. | strong | sole target route and complete dependency audit | UID0000JS topology/source | incorporate | applied |
| C-F8-027 | 0000JS | No file-level rectangle or tile-context object is emitted; source changes flow through the UID000090 class child and shared resource/type dependencies retain their own owners. | very-strong | emitter graph | UID0000JS source policy | incorporate | applied |
| C-F8-028 | 0001HC | Keep 92/94 FALSE/non-emitting; add UID0003F8 provenance and corrected UID0004Z5 initializer/resource/context-lifetime facts. | strong | physical split/full method | UID0001HC inventory | incorporate | applied |
| C-F8-029 | 0002V2 | Keep 88/92 ownerless FALSE/non-emitting, preserve the current complete island/SimpleList boundary prose, and refine UID0003F8 from direct Group-file assignment to UID000090 position 76 -> UID0000JS. | strong | current multi-owner child inventory | UID0002V2 inventory | incorporate | applied |
| C-F8-030 | 0001VP | RectBounds layout already supplies four edges, Offset, and InitRectBounds; it has no constructor, Width, or Height, so Section 22 uses aggregate/direct arithmetic without changing this page. | very-strong | authoritative H plus binary calls | UID0001VP no edit | already-present | already-present |
| C-F8-031 | 0003F6 | Existing pooled 100.0 child already proves use-site policy. | strong | current formal/prose | UID0003F6 no edit | already-present | already-present |
| C-F8-032 | 0003F2 | Existing class position-75 pooled child supplies order precedent. | strong | current metadata | UID0003F2 no edit | already-present | already-present |
| C-F8-033 | 0003F8 | UID0003F7/UID0003F9 are separate SelfLookPane items; unchanged. | very-strong | boundaries/xrefs | boundary protection | already-present | already-present |
| C-F8-034 | 0003F8 | No padding, split, merge, resize, redefinition, or reclassification. | very-strong | exact item | range analysis | already-present | already-present |
| C-F8-035 | 0003F8 | Generic GroupPane/future-C++ wording becomes superseded history. | strong | closure | target history | historicalize | applied |
| C-F8-036 | 0003F8 | Supervisor Gate 2B applied the exact IDA-F8-01 AP provenance comment and verified the saved readback. | strong | dated Gate 2B backup/save/attestation and exact target readback | Gate 2B IDA-F8-01 | incorporate | APPLIED_VERIFIED |
| C-F8-037 | 0004Z5 | Supervisor Gate 2B protected the exact function/frame, empty-inbound vtable, complete load/store code/data edges, and separately specified empty-xref padding items without change. | very-strong | dated Gate 2B literal no-change readback | Gate 2B IDA-F8-02 | already-present | NO_CHANGE_VERIFIED |
| C-F8-038 | 0003F8 | Supervisor Gate 2B rejected data rename/type/boundary/neighbor edits and verified both neighbors retained their literal states with empty outbound xrefs. | strong | dated Gate 2B target/neighbor no-change readback | Gate 2B IDA-F8-03 | reject-invalid | NO_CHANGE_VERIFIED |
| C-F8-039 | 0003F8 | Supervisor applied the exact target row to manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| C-F8-040 | 0004Z5 | Supervisor replaced stale manual by-memory source-ready wording with the six-initializer, `.bounds`, COMMA, shared-context, global-record, partial-descriptor, full-NewHuman-call, constructor-free RectBounds, and UID0003F8 closure at completion 94. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| C-F8-041 | 000090 | Supervisor preserved corrected virtuals, named pane-family topology, and class facts while adding the position-76 child to manual by-class coverage. | very-strong | dated command 000000024689 exit 0/ok:1 and by-class readback | by-class coverage | incorporate | APPLIED_VERIFIED |
| C-F8-042 | 0000JS | Supervisor preserved Group source-root detail, three GROUP.EPF uses, and retained helpers while adding UID0004Z5's complete lifecycle/resource/descriptor/API/header closure and UID0003F8 to manual by-file coverage. | very-strong | dated command 000000024692 exit 0/ok:1 and by-file readback | by-file coverage | incorporate | APPLIED_VERIFIED |
| C-F8-043 | 0001HC | Supervisor preserved all modeled bodies, dedicated paint routes, four retained raw helpers, exact roles/layout, padding, and compiler boundaries while adding UID0004Z5's complete initializer/resource/context/descriptor/API facts and UID0003F8 to manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| C-F8-044 | 0002V2 | Supervisor preserved the corrected SimpleListPane COL boundary and ownerless/non-emitting state while adding the exact UID0003F8 child to manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| C-F8-045 | 0003F8 | Callback generated readback proves the target covered-by marker and corrected UID0004Z5 body: six Initialize calls, accepted `.bounds` within the method, one COMMA lookup, one shared tileContext across non-overlapping phases, global GroupMemberRecord, no Reset or unprefixed descriptor fields, full NewHuman calls, no RectBounds constructor/Width/Height, and exact partial descriptor writes; generated NewHumanImageLib.h proves the complete nested-row/owner-order contract. | very-strong | physical generated Group.cpp/NewHumanImageLib.h readback | generated readback | incorporate | applied |
| C-F8-046 | 0003F8 | Scoped validators 24624-24628, 24630, and 24632-24642 completed with exit 0 and ok:1; dated callback generation at 24642 and fresh read-only continuity output at 24668 were physically reread. | very-strong | validator receipts plus dated and fresh physical generated rereads | Validator Results | incorporate | applied |
| C-F8-047 | 0003F8 | Fifteen ordinary by-* pages changed additively; validator-owned generated/statistics/registry side effects were not edited directly, and coverage/IDA/lifecycle state remained outside the callback. | very-strong | ordinary hashes, validator receipts, and changed-file audit | Changed Files | incorporate | applied |
| C-F8-048 | 0003F8 | Exactly 33 H2 headings, exact 90/90 twin parity, zero executable-script fences, and one terminal READY_FOR_SUPERVISOR_EXECUTE marker. | very-strong | final report self-audit | report hygiene | incorporate | applied |
| C-F8-049 | 00004I | Accepted EPFTileContext H is a 0x28-byte struct with `RectBounds bounds` and explicit `Initialize()`; it has no `m_bounds` and no constructor. | very-strong | formal H/generated header/current class docs | UID0004Z5 type dependency | already-present | already-present |
| C-F8-050 | 0004Z5 | Six explicit calls to EPFTileContext_Initialize occur at 0x0056ce8b, 0x0056cedf, 0x0056ceea, 0x0056cef5, 0x0056cf00, and 0x0056cf0b and must remain explicit source calls. | very-strong | scoped live insn query/disassembly/bytes | UID0004Z5 lifecycle | incorporate | applied |
| C-F8-051 | 0003EV | `L"COMMA.EPF"` at 0x006247f0 has three consumers; UID0004Z5's xref 0x0056cf1b feeds lookup 0x0056cf20 into initialized commaFrame before background rendering, with no later method read. | very-strong | live item/xrefs/decompilation | UID0004Z5/UID0003EV resource evidence | incorporate | applied |
| C-F8-052 | 0004Z5 | Human source uses one `tileContext` for non-overlapping background/member/toggle phases and five other initialized locals; `scratchContext` preserves the initialized-only slot, while the descriptor remains an unconstructed partially written packed local exactly as observed. | strong | full frame/write/use inventory and call order | UID0004Z5 formal CPP/source rationale | incorporate | applied |
| C-F8-053 | 0000FQ | `GroupMemberRecord` is global and `m_groupMembers[50]` is private; add `friend class NewGroupPane;` and use the global type without weakening field privacy. | very-strong | authoritative UserPane H plus direct binary field reads | UID0000FQ H/prose | incorporate | applied |
| C-F8-054 | 00050M | HumanImageRenderParams is packed 0x40 with m_* fields and no Reset; document UID0004Z5's exact partial writes, including zero body/weapon/shield/mantle/neck/shoes colors and invisible, and untouched-field set. | very-strong | authoritative H plus exact stack stores | UID00050M consumer evidence | incorporate | applied |
| C-F8-055 | 000092 | Install Section 22's complete NewHumanImageLib class declaration once at H position 20 after UID0001VF's exact position-10 complete row block; include every currently emitted child prototype, full CalculateBounds/Draw contracts, exact container members, and no standalone fragment. | strong | live profiles, exact child definitions, complete UID0001VF row layouts, accepted consumers | UID000092 formal H/API inventory | incorporate | applied |
| C-F8-056 | 0000RT | Add `extern NewHumanImageLib *g_pNewHumanImageLib;` to the NewHumanImageLib H channel while preserving the sole CPP definition. | very-strong | current global type/definition and 52 consumers | UID0000RT H | incorporate | applied |
| C-F8-057 | 0000A1 | Move the complete PaletteLib class/helper declaration block from formal CPP to formal H at position 10; UID0000A1 CPP retains only children, while UID0000RW alone owns the H extern and sole CPP definition. | very-strong | current complete class formal CPP, generated H absence, and singleton ownership | UID0000A1 CPP/H | incorporate | applied |
| C-F8-058 | 0000RW | Add `extern PaletteLib *g_pPaletteLib;` to PaletteLib H while preserving the sole CPP definition. | very-strong | current singleton type/definition and consumer set | UID0000RW H | incorporate | applied |
| C-F8-059 | 0000JS | Emit the exact eight-line Group.h/UserPane.h/NewHumanImageLib.h/PaletteLib.h/ImageLib.h/Surface.h/windows.h/wchar.h block before all Group.cpp children through the first UID00005X GroupListPane mechanical carrier; UID0004Z5 method CPP contains no includes. | strong | declaration-by-declaration compile audit, generated preamble readback, and emitter ordering | UID0000JS CPP preamble | incorporate | applied |
| C-F8-060 | 0004Z5 | NewHuman bounds/draw source uses full binary argument lists and exact memberBounds geometry; no shortened overload, Reset, member.bodyColor copy, or whole-struct clear is permitted. | very-strong | live calls 0x0056d1ba/0x0056d25a and stack writes | UID0004Z5 formal CPP/prose | incorporate | applied |
| C-F8-061 | 000092 | Formal CPP remains `#include "ImageFrameTable.h"` plus `[[CHILDREN]]`; formal H begins with an explicit `[[CHILDREN]]` insertion point followed by the one class declaration, so UID0001VF rows precede the class without a CPP-local duplicate. | very-strong | owner route, explicit child insertion point, and physical generated H order | UID000092 CPP/H ownership | incorporate | applied |
| C-F8-062 | 000092 | Physical NewHuman H order is exact: UID00050M first, UID0001VF complete nested rows at the explicit UID000092 child insertion point, UID000092 class next, and UID0000RT extern last; UID0001VF includes ImageFrameTable.h/Surface.h and UID000092 retains LObject/vector/deque dependencies. | very-strong | C++03 completeness audit and physical generated H readback | UID000092 H position/dependencies | incorporate | applied |
| C-F8-063 | 0000RT | UID0000RT remains the sole `NewHumanImageLib *g_pNewHumanImageLib = 0;` CPP definition and supplies exactly one extern immediately after UID000092's class. | very-strong | current global formal CPP/52 xrefs | UID0000RT CPP/H ownership | incorporate | applied |
| C-F8-064 | 0000RW | UID0000RW remains the sole `PaletteLib *g_pPaletteLib = 0;` CPP definition and supplies exactly one extern immediately after UID0000A1's class. | very-strong | current global formal CPP/83 xrefs | UID0000RW CPP/H ownership | incorporate | applied |
| C-F8-065 | 0000FQ | Supervisor verified manual by-class coverage needed no edit because the complete managed declaration row already covered the narrow friendship without changing score/layout/ownership/coverage conclusions. | very-strong | dated by-class closure readback and exact UserPane row comparison | by-class coverage no-change | already-present | NO_CHANGE_VERIFIED |
| C-F8-066 | 00050M | Supervisor replaced UID00050M in manual by-struct coverage with Section 28's exact row adding the NewGroupPane partial-write/no-Reset/no-whole-clear consumer while retaining 94%. | very-strong | dated command 000000024690 exit 0/ok:1 and by-struct readback | by-struct coverage | incorporate | APPLIED_VERIFIED |
| C-F8-067 | 000092 | Supervisor replaced UID000092 in manual by-class coverage with Section 28's exact dependency-complete-H/Group-consumer row at 90%. | strong | dated command 000000024689 exit 0/ok:1 and by-class readback | by-class coverage | incorporate | APPLIED_VERIFIED |
| C-F8-068 | 0000RT | Supervisor replaced UID0000RT in manual by-global coverage with Section 28's exact extern/sole-definition row at 90%. | very-strong | dated command 000000024691 exit 0/ok:1 and by-global readback | by-global coverage | incorporate | APPLIED_VERIFIED |
| C-F8-069 | 0000A1 | Supervisor replaced UID0000A1 in manual by-class coverage with Section 28's exact H relocation/CPP-children-only row at unchanged 92%. | very-strong | dated command 000000024689 exit 0/ok:1 and by-class readback | by-class coverage | incorporate | APPLIED_VERIFIED |
| C-F8-070 | 0000RW | Supervisor replaced UID0000RW in manual by-global coverage with Section 28's exact H-extern/sole-CPP-definition row at unchanged 92%. | very-strong | dated command 000000024691 exit 0/ok:1 and by-global readback | by-global coverage | incorporate | APPLIED_VERIFIED |
| C-F8-071 | 0003EV | Supervisor inserted Section 28's exact pooled COMMA.EPF row after UID0003EU and before UID0003EW in manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| C-F8-072 | 000092 | Completion/confidence changes 88/90 -> 90/91 only after UID0001VF's five complete vector elements and transitive by-value dependencies precede the complete class H; retained/non-emitting method-family spellings cap final confidence. | strong | complete class/child/layout/C++03 header audit | UID000092 metadata | incorporate | applied |
| C-F8-073 | 0000RT | Completion/confidence changes 88/92 -> 90/93 only with exact H extern plus preserved sole CPP definition. | strong | exact storage/lifecycle and declaration route | UID0000RT metadata | incorporate | applied |
| C-F8-074 | 0003F8 | Section 28 records dated file hashes, row line hashes, all requested support dispositions, and dynamic supervisor reread requirements without editing coverage. | very-strong | 2026-08-15 target plus 2026-08-16 dependency coverage rereads | coverage receipt inventory | incorporate | applied |
| C-F8-075 | 0001VF | Dated pre-callback formal H was blank and generated NewHumanImageLib.h omitted all five by-value vector element definitions; the callback historicalizes that defect by installing the complete UID0001VF H block. | very-strong | dated command 24570 baseline plus applied ordinary/generated readback | UID0001VF current state/history | historicalize | applied |
| C-F8-076 | 0001VF | Emit one complete nested-row H block at position 10 through UID000092 -> UID0000LR/NewHumanImageLib.h, after UID00050M position 5 and before UID000092 position 20. | very-strong | owner graph and declaration order | UID0001VF metadata/formal H | incorporate | applied |
| C-F8-077 | 0001VF | Define NewHumanPartEntry as exact 0x44 with partId, wchar_t name[20], drawIndexBase, descriptorBase, descriptorCount, rawRecordCount, frameDescriptors, and spriteArchive; guard sizeof 0x44. | very-strong | 68-byte loader/vector/destructor evidence | UID0001VF formal H/part layout | incorporate | applied |
| C-F8-078 | 0001VF | Define NewHumanLayerEntry as exact 0x20 with layerId, char name[20], childCount, and childIndexes; guard sizeof 0x20. | very-strong | 32-byte loader/vector/destructor evidence | UID0001VF formal H/layer layout | incorporate | applied |
| C-F8-079 | 0001VF | Define packed NewHumanMotionEntry as exact 0x42 with 23-byte prefix, motionId, name[20], two reserved bytes, direction, fallbackMotionId, frameCount, frameOffsets, and frameData; guard sizeof 0x42. | very-strong | live 0x004e0e20 offsets/66-byte copy | UID0001VF formal H/motion layout | incorporate | applied |
| C-F8-080 | 0001VF | Define NewHumanCompositionDrawCommand as exact 0x50 with partId, by-value FrameDrawRecord, by-value SurfaceSpriteBlitOptions, and DLPalette pointer; guard sizeof 0x50. | very-strong | live 0x004e21d0 plus 80-byte vector helpers | UID0001VF formal H/command layout | incorporate | applied |
| C-F8-081 | 0001VF | Define Acc2DrwEntry as exact three-byte bool enabled[3] row and guard sizeof 3. | very-strong | loader/grow/consumer stride evidence | UID0001VF formal H/accessory layout | incorporate | applied |
| C-F8-082 | 0001VF | Define packed NewHumanSequenceFrame 0x09, NewHumanSequenceFrameTable 0x10, and packed NewHumanPartFrameDescriptor 0x20 before NewHumanPartEntry so all already-emitted child bodies see complete descriptor/sequence types. | very-strong | UID00041C/000417/000437/000438 loader-consumer agreement | UID0001VF formal H/transitive internal layouts | incorporate | applied |
| C-F8-083 | 0000UN/0000TN | Include ImageFrameTable.h and Surface.h at UID0001VF position 10 so FrameDrawRecord/RectBounds and SurfaceSpriteBlitOptions remain defined once by their existing owners; do not duplicate these structs. | very-strong | current complete formal H/generated readback | UID0001VF dependency includes | incorporate | applied |
| C-F8-084 | 0001VF/000092 | Only GrafPort, Motion, NewHumanCompositionState, and NewHumanCommandSideRecord remain forward-declared; every use at class-declaration time is pointer/reference or deque-of-pointer and is C++03 legal. | very-strong | declaration-by-declaration completeness audit | UID0001VF/UID000092 C++03 rationale | incorporate | applied |
| C-F8-085 | 0001VF/000092/0000RT | Exact H insertion order is HumanImageRenderParams UID00050M position 5, nested rows UID0001VF position 10, class UID000092 position 20, and singleton extern UID0000RT position 30. | very-strong | owner/emitter dependency DAG | all four metadata/formal routes | incorporate | applied |
| C-F8-086 | 0001VF | Completion/confidence changes 87/90 -> 92/93 only with the exact complete formal H and size guards; inferred original private type/member spellings cap confidence. | strong | exact layouts plus source-name inference | UID0001VF metadata | incorporate | applied |
| C-F8-087 | 0001VF | Supervisor replaced stale manual by-struct coverage prose with Section 28's exact 92% dependency-complete H row. | very-strong | dated command 000000024690 exit 0/ok:1 and by-struct readback | by-struct coverage | incorporate | APPLIED_VERIFIED |
| C-F8-088 | 0000UN | Supervisor verified manual by-item coverage needed no edit because the 90% row already documents the sole complete ImageFrameTable.h FrameDrawRecord/RectBounds owner used by include. | very-strong | dated exact ImageFrameTable coverage-row readback | by-item coverage no-change | already-present | NO_CHANGE_VERIFIED |
| C-F8-089 | 0000TN | Supervisor verified manual by-global coverage needed no edit because the 94% row already documents the sole complete Surface.h options/callback owner used by include. | very-strong | dated by-global closure readback and exact Surface row comparison | by-global coverage no-change | already-present | NO_CHANGE_VERIFIED |
| C-F8-090 | 0001VF/000092/0000RT | Post-callback and fresh continuity generated readbacks prove one definition of every nested row, exact size guards, no vector-element forward declaration, existing dependency types defined once, class after rows, extern after class, and no duplicate class/global definition. | very-strong | physical NewHumanImageLib.h/.cpp readbacks at commands 24642 and 24668 | NewHumanImageLib.h/.cpp readback | incorporate | applied |

## Positive Evidence Summary

- Unique 16-byte item plus exact RectBounds decode establishes one rectangle.
- Sole movaps load and immediate typed local store establish compiler-pooled automatic initialization.
- Function type, vtable, full frame, and full behavior independently agree on NewGroupPane::OnPaint; the prior formal source agrees only on rowBounds and broader rendering behavior and is corrected here rather than treated as authority.
- Scoped instruction search across [0x0056ce50,0x0056da03) found exactly six calls to EPFTileContext_Initialize and one `COMMA.EPF` operand; accepted EPFTileContext H independently requires explicit `Initialize()` and `.bounds`.
- Full use inventory proves `[ebp-0x198]` is one context reused for background, each member row, and toggle, while the `COMMA.EPF` output slot is initialized/looked up and one sixth initialized slot has no later read.
- Corrected formal source places aggregate `rowBounds` immediately after the background blit, matching the 0x0056cf78/0x0056cf8b packed load/store phase, and preserves all values, six initializers, resource lookup order, expanded X shift, 44-pixel row step, and 6/12 row policy without constructor or decompiler-variable inventions.
- Live writes prove a deliberately partial `HumanImageRenderParams`: `m_displayStatusByte=0x50` once; row-specific riding/gender/composition defaults; selected IDs/colors; 0xffff absent-part IDs; zero absent-part colors and `m_invisible`; no Reset or whole-object clear. The full 9-argument bounds and 13-argument draw calls plus image-derived member rectangle independently close render behavior.
- The dated pre-callback declarations independently proved global `GroupMemberRecord`, private UserPane storage, no RectBounds constructor/size helpers, absent NewHuman class/singleton H, and CPP-only PaletteLib declaration. The applied Section 22 owner/channel fixes close those historical defects rather than hiding them behind the method body.
- Dated pre-callback generated NewHumanImageLib.cpp used all five nested rows, descriptor/sequence records, and 80-byte composition commands while NewHumanImageLib.h defined only HumanImageRenderParams. Live LoadMotionTable and BuildCompositionDrawCommands decompilations independently proved the packed 0x42 and 0x50 declarations, while accepted loader/destructor/vector evidence proved the 0x44, 0x20, and 3-byte rows. The applied generated header now contains all complete rows before the class.
- `ImageFrameTable.h` and `Surface.h` already own the complete transitive by-value `FrameDrawRecord`/`RectBounds` and `SurfaceSpriteBlitOptions` types. Including those headers at UID0001VF position 10 gives one-definition C++03 closure; copying or forward-declaring those embedded fields is rejected.
- UID0003F2/UID0003F6 are direct no-duplicate pooled-literal controls.

## IDA MCP Facts

- Target item [0x00624bf0,0x00624c00), data size 16, xmmword_624BF0, type/AR/AP absent.
- Bytes/hash: 06 00 00 00 0E 00 00 00 A1 00 00 00 36 00 00 00 / A9CB5BAE7A86BEF48A98DBDFA3BFD6919991F1731C183BF87B24B99C675E03B6.
- Struct: RectBounds {6,14,161,54}; exact pattern unique.
- One inbound data xref 0x0056cf78; no outbound/tested interior xrefs.
- VA bytes only at xref operand 0x0056cf7b; no RVA/raw-offset matches. Target RVA 0x224bf0 maps to source-file offset 0x2235f0.
- Consumer NewGroupPane__OnPaint, [0x0056ce50,0x0056da03), void __thiscall(NewGroupPane *this), body SHA D3FB87AF11A14632F0BC954B387ECC83DBAC01D423426E1DECC7E55A2ABD960C.
- Function AR/AP/FR absent; FP exactly: Renders NewGroupPane background, member rows, names, status, HP/MP bars, and numeric glyph strings.
- Vtable [0x00624598,0x0062459c), bytes 50 CE 56 00, SHA 0670DADBA6165B99082256465ECBD290347CC782CA53FBFEFBFC4E373C556803.
- Exactly six initializer calls target EPFTileContext_Initialize 0x00457a60: 0x0056ce8b -> tileContext@frame 0x180, 0x0056cedf -> outContext@0xb8, 0x0056ceea -> context@0x148, 0x0056cef5 -> context@0xf8, 0x0056cf00 -> context@0x120, and 0x0056cf0b -> context@0x90. Their exact call bytes are respectively E8 D0 AB EE FF, E8 7C AB EE FF, E8 71 AB EE FF, E8 66 AB EE FF, E8 5B AB EE FF, and E8 50 AB EE FF.
- The frame has six 0x28-byte EPFTileContext rows at offsets 0x90, 0xb8, 0xf8, 0x120, 0x148, and 0x180. The 0x180 row is read/written by the background lookup/blit, GROUPCOL row lookup/render, and INVENBUT toggle lookup/render. The 0x90 row is initialized and never read again.
- `aCommaEpf` is data [0x006247f0,0x00624804), type const wchar_t[], with exactly three xrefs: SelfLookPane 0x00567585, NewGroupPane 0x0056cf1b, and UserStatusPane2 0x005bb006. In UID0004Z5, push bytes 68 F0 47 62 00 at 0x0056cf1b feed lookup call bytes E8 CB 33 F6 FF at 0x0056cf20 with frame 0 and outContext@0xb8; that output has no later method read.
- Accepted EPFTileContext H uses `RectBounds bounds;` and `void Initialize();`; it declares no constructor and no `m_bounds` member. Dated pre-callback generated Group.cpp had zero initializers in NewGroupPane::OnPaint, invalid `.m_bounds` uses there, and no method-local COMMA lookup; those were source defects, not contrary binary evidence. The applied generated method now matches the accepted declaration and binary call stream.
- `HumanImageRenderParams` occupies `[ebp-0x2e4,ebp-0x2a4)`. The binary sets `m_displayStatusByte=0x50` at 0x0056cec1; per row it writes `m_ridingAppearanceId`, `m_gender`, `m_compositionMode`, face/hair/skin selectors/colors, absent-part IDs/colors, helmet/decorations, and the final `m_shoesColor/m_invisible` zero word. It does not call a reset helper or clear/write `m_statusKind`, paddings, `m_headgearMode`, `m_actionState`, `m_ridingDefinitionIndex`, `m_ridingPaletteFlags`, or `m_ridingYOffset`.
- At 0x0056d1ba, `CalculateBounds` receives `(&appearance,2,0,0,&imageBounds,0,1,true,0)`. The returned image rectangle produces member bounds as `rowBounds`, then top=`bottom-20`, left=`imageBounds.left+13`, right=`imageBounds.left+72`, optional vertical centering only when image height exceeds 40, and final offset `(expanded?5:0,2)`. At 0x0056d25a, `Draw` receives `(this,&memberBounds,&appearance,2,0,0,0,false,0,0.0f,1,true,0)`.
- Fresh 2026-08-16 read-only MCP in `supervisor_uid0000li_i13rollback_20260815` reconfirmed target name/type/comment state, one target xref, function type/comment/vtable route, 728 instructions/56 blocks/19 callees, and the exact decompiled write/call geometry. No mutation/save endpoint was called.

## Function / Child Inventory

| Item | UID/path | Role | Route | CPP | H | State |
|---|---|---|---|---|---|---|
| 0x00624bf0-0x00624c00 | 0003F8 | pooled local RectBounds | applied 000090 pos76 | covered-by marker | blank | current 94/94 covered-by state |
| 0x0056cf78-0x0056cf7f | 0004Z5 internal | vector load | compiler-covered | method body | none | complete |
| 0x0056cf8b-0x0056cf92 | 0004Z5 internal | local store | compiler-covered | method body | none | complete |
| six calls 0x0056ce8b..0x0056cf0b | 0004Z5 internal / 00004I dependency | explicit EPFTileContext initialization | compiler-covered | six `.Initialize()` calls in corrected method | none | all six calls are present in current generated OnPaint |
| 0x006247f0-0x00624804 and 0x0056cf1b/0x0056cf20 | 0003EV / 0004Z5 internal | shared COMMA.EPF literal and lookup | pooled non-emitter / method use | exact lookup in corrected method | none | literal protected; COMMA frame-zero lookup is present in current generated OnPaint |
| six context frame rows | 0004Z5 internal | one reused tileContext, commaFrame, three bar contexts, one initialized-only scratch context | compiler-covered locals | corrected human local lifetimes | none | exact behavior closed; lexical scratch intent inferred |
| EPFTileContext H contract | 00004I | bounds member and explicit Initialize API | 0000J4 | dependency only | existing formal H | already present; no edit |
| GroupMemberRecord/UserPane access | 0000FQ | global 0x12c record and private 50-row array | 0000P1 | direct use in method | NewGroupPane friendship present in existing H | current method uses global `GroupMemberRecord`; private access is authorized by applied friendship |
| HumanImageRenderParams | 00050M | packed 0x40 partial-write descriptor | 0000LR | direct use in method | existing H plus applied consumer facts | current method uses valid `m_*` fields and exact partial writes; no Reset call |
| NewHumanSequenceFrame | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md | packed 0x09 descriptor-frame row | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | child-method compile dependency | complete H declaration plus size guard | declaration and size guard are present in current generated H |
| NewHumanSequenceFrameTable | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md | 0x10 motion-indexed slot | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | child-method compile dependency | complete H declaration plus size guard | declaration and size guard are present in current generated H |
| NewHumanPartFrameDescriptor | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md | packed 0x20 descriptor row | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | part-entry pointer plus child-method field access | complete H declaration plus size guard | declaration and size guard are present in current generated H |
| NewHumanPartEntry | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md | 0x44 by-value vector row | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | `m_partEntries` element | complete H declaration plus size guard | applied generated H defines it once; dated pre-callback H omitted it, and the rejected pre-repair draft forward-declared it |
| NewHumanLayerEntry | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md | 0x20 by-value vector row | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | `m_layerEntries` element | complete H declaration plus size guard | applied generated H defines it once; dated pre-callback H omitted it, and the rejected pre-repair draft forward-declared it |
| NewHumanMotionEntry | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md | packed 0x42 by-value vector row | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | `m_motionEntries` element | complete H declaration plus size guard | applied generated H defines it once; dated pre-callback H omitted it, and the rejected pre-repair draft forward-declared it |
| NewHumanCompositionDrawCommand | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md, with UID0000UN/0000TN dependencies | 0x50 by-value vector row | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | `m_compositionDrawCommands` element | complete H declaration, ImageFrameTable.h/Surface.h includes, and size guard | applied generated H defines it once using the existing dependency owners; dated pre-callback H omitted it |
| Acc2DrwEntry | 0001VF / by-type/by-struct/NewHumanImageLibLayout.md | 3-byte by-value vector row | UID0001VF H position 10 -> UID000092 -> UID0000LR/NewHumanImageLib.h | `m_acc2drwEntries` element | complete H declaration plus size guard | applied generated H defines it once; dated pre-callback H omitted it, and the rejected pre-repair draft forward-declared it |
| NewHumanImageLib API/class/layout | 000092 pos20 / 0000RT pos30 after UID0001VF pos10 | complete class with every already-emitted child declaration, Group-consumed CalculateBounds/Draw entries, exact 0x60 container layout, and singleton extern | 0000LR | direct render dependency and emitted-child compile closure | applied complete Section 22 class block once after complete row declarations; CPP retains include/children and sole singleton definition | applied generated H contains rows, class, and global in physical dependency order; fragmented deltas remain rejected |
| PaletteLib API/class/layout | 0000A1/0000RW | complete 0x25c8 class declaration, helper declarations, GetPaletteByName, and singleton extern | 0000MB | direct palette dependency | applied declaration block in PaletteLib.h; UID0000A1 CPP retains children and UID0000RW CPP remains sole singleton definition | applied generated H contains one class and one UID0000RW extern; no CPP-local class duplicate |
| Group translation-unit preamble | 0000JS | exact eight includes required by Section 22 method/source dependencies | 0000JS | file-level source assembly | exact preamble present before all children through UID00005X carrier | file includes are present at file scope and absent from UID0004Z5 formal CPP |
| RectBounds API | 0001VP | four edges, Offset, InitRectBounds; no ctor/Width/Height | 0000N2 | geometry dependency | aggregate/direct arithmetic/existing helper | current method uses constructor-free `RectBounds` source and no nonexistent Width/Height API |
| 0x0056ce50-0x0056da03 | 0004Z5 | full OnPaint | 000090 pos70 | applied Section 22 corrected body | blank | current 94/93 state |
| 0x00624598-0x0062459c | 0002NL support | vtable cell | ABI support | no handwritten data | none | protected |
| 0x0056ce4b-0x0056ce50 | 0001HC | 5 CC padding | physical index | none | none | protected |
| 0x0056da03-0x0056da10 | 0001HC | 13 CC padding | physical index | none | none | protected |
| 0x00624be0-0x00624bf0 | 0003F7 | SelfLook local | existing route | existing | blank | no edit |
| 0x00624c00-0x00624c10 | 0003F9 | SelfLook local | existing route | existing | blank | no edit |
| RectBounds UDT | 0001VP | four-int layout | 0000N2 | existing | existing | no edit |
| NewGroupPane | 000090 | class owner | 0000JS | add child | preserve | 94/95 |
| Group | 0000JS | source root | project root | transitive | class H | 91/88 |
| 0x0056c4c0-0x0056e939 | 0001HC | physical split index | 0000JS | none | none | 92/94 FALSE |
| 0x00624788-0x00624c60 | 0002V2 | mixed rdata index | NONE | none | none | 88/92 FALSE |
| dated Group.cpp | generated | source readback | 0000JS | target empty marker plus declaration-incompatible UID0004Z5 body | N/A | callback repair and exhaustive generated reread |
| dated Group.h | generated | header readback | 0000JS | N/A | no target entry | unchanged |

Inventory closure: 33 explicit source/physical/support/generated rows; no target-local function, helper, global, declaration, padding child, resource/type dependency, or extra object remains unclassified.

## Direct Xref / Caller Inventory

| Item | Route | Meaning |
|---|---|---|
| 0x00624bf0 | inbound 0x0056cf78 only; no outbound | sole consumer |
| tested interior offsets | zero inbound | no field route |
| 0x0056cf78 | NewGroupPane__OnPaint | loads four edges |
| 0x0056cf8b | same function | stores local bounds |
| 0x0056d035/0x0056d03c | same function | expanded X +5 |
| 0x0056d8ea/0x0056d8f1 | same function | Y +44 each row |
| 0x00624598 | to 0x0056ce50 | virtual dispatch |
| 0x0056ce50 | 0 code callers, 1 vtable xref | live virtual method |
| 0x00457a60 | calls 0x0056ce8b/0x0056cedf/0x0056ceea/0x0056cef5/0x0056cf00/0x0056cf0b inside UID0004Z5 | six observable explicit initializers |
| 0x006247f0 | xrefs 0x00567585/0x0056cf1b/0x005bb006 | shared COMMA.EPF pool; Group use is one of three |
| 0x0056cf20 | literal/call sequence from 0x0056cf1b | frame-0 COMMA.EPF lookup into initialized outContext before background phase |
| 0x00624be0 | xref 0x005676c7 | separate predecessor |
| 0x00624c00 | xref 0x0056771f | separate successor |

## Documentation Evidence And IDA Status

- Historical assignment-time UID0004Z5 formal source contained the rowBounds expression but contradicted accepted EPFTileContext H and live binary lifecycle/resource behavior. Section 22 is now applied as the complete current formal body rather than an annotation-only change.
- UID000090 owns the method and complete class H; the physical UID0003F8 position-76 child is present.
- UID0000JS already routes Group.cpp; no new file.
- UID0001HC/UID0002V2 correctly remain non-emitting indexes and now preserve exact UID0003F8 child provenance.
- UID0001VP fixes layout independently.
- UID00004I/EPFTileContext already supplies the exact `.bounds` plus explicit `Initialize()` contract; no constructor exists to absorb the calls.
- UID0003EV already proves `COMMA.EPF` is a shared physical literal. Its Group use is now narrowed to one frame-0 lookup into an initialized context before the background phase; pooled ownership remains unchanged.
- UID0000FQ declares `GroupMemberRecord` globally and the exact fields consumed by this method; narrow NewGroupPane friendship is present for private-array access. No nested record type exists.
- UID00050M supplies the exact packed descriptor and m_* field names; it explicitly supports partial consumer writes and has no Reset API. UID0001VF now emits Section 22's complete nested rows using UID0000UN/ImageFrameTable.h and UID0000TN/Surface.h for embedded by-value dependencies. UID000092/UID0000RT emit one complete class H after the explicit child insertion point and one extern after the class. A forward-declaration-plus-container layout remains rejected under C++03.
- UID0000A1/UID0000RW preserve the complete PaletteLib declaration and singleton-definition facts. The class/helper declaration is now in PaletteLib.h, UID0000A1 CPP contains children only, UID0000RW owns the one H extern and remains the sole CPP singleton definition, and no CPP-local class duplicate remains. UID0001VP supplies RectBounds edges/Offset/InitRectBounds and disproves constructor/Width/Height use.
- Current declaration/API audit: `EPFTileContext`, `RectBounds`, `HumanImageRenderParams`, `DLPalette`, global `GroupMemberRecord`, `g_pEPFLib`/`LookupLayoutEntry`, `g_pfnBlitSprite`, GrafPort draw/text methods, Region::IntersectsRect, `g_pUserPane`, NewGroupPane fields/DrawNumberString, `MulDiv`, `wcslen`, and `swprintf_s` have the required declarations. UID0001VF's five vector elements plus descriptor/sequence internals, the UserPane friend, complete NewHuman class/global H, complete PaletteLib class/global H, CPP duplicate removal, and Group file preamble are all applied and physically present in their owner-ordered routes.

| Section 22 source name/API | Current authoritative declaration or binary contract | Disposition |
|---|---|---|
| `NewGroupPane`, `m_expanded`, `m_firstVisibleMember`, `m_groupMemberCount`, `m_toggleButtonState`, `DrawNumberString` | UID000090 complete H | exact/already present |
| `m_visibleBounds`, `m_exposedRegion`, draw/text methods | `GrafPort.h` protected fields/public methods through PanelPane inheritance | exact/already present |
| `GroupMemberRecord` and all consumed row fields | global struct in UID0000FQ/UserPane.h, exact 0x12c row | applied global spelling present |
| `g_pUserPane->m_groupMembers` | extern singleton exists; array is private | narrow `friend class NewGroupPane;` is present |
| `HumanImageRenderParams` and every `m_*` field | UID00050M/NewHumanImageLib.h packed 0x40 H | exact; partial writes only; no Reset |
| nested NewHuman row H | UID0001VF loaders/destructor/vector helpers plus live 0x004e0e20/0x004e21d0 | exact Section 22 definitions and size guards are present; no vector element remains incomplete |
| `FrameDrawRecord`/`RectBounds` | UID0000UN/ImageFrameTable.h | include existing complete owner before command row; never duplicate or forward-declare embedded value |
| `SurfaceSpriteBlitOptions`/`DLPalette *` | UID0000TN/Surface.h | include existing complete options owner; DLPalette remains pointer-only |
| `NewHumanImageLib` complete H | UID000092 plus complete UID0001VF/child method evidence and live profiles for 0x004e06a0/0x004e09e0/0x004e0d70/0x004e31f0/0x004e4140/0x004e4210 | one complete class block is present after row declarations, with every emitted method, both full Group-consumed public contracts, exact containers, and no raw IDA labels |
| `g_pNewHumanImageLib` | UID0000RT sole CPP definition and 52 consumers | one extern is present after the complete class in NewHumanImageLib.h; sole CPP definition preserved |
| `PaletteLib` complete H | accepted UID0000A1 declaration/layout/method block | complete block is present in UID0000A1 formal H; CPP-local declaration removed and children retained |
| `g_pPaletteLib` | UID0000RW sole CPP definition | one extern is present after the complete class in PaletteLib.h; sole CPP definition preserved |
| Group file preamble | UID0000JS source root and declaration-by-declaration include audit | exact eight-line Section 22 preamble is present before all Group source children; UID0004Z5 method channel contains no includes |
| `g_pEPFLib`, `LookupLayoutEntry` | ImageLib.h | exact/already present |
| `EPFTileContext::Initialize`, `.bounds` | EPFTileContext.h | exact/already present |
| `g_pfnBlitSprite` and callback signature | Surface.h | exact/already present |
| `RectBounds` fields/`Offset`, `InitRectBounds` | RectBounds.h | exact; no constructor/Width/Height |
| `Region::IntersectsRect` | Region.h through GrafPort.h | exact/already present |
| `MulDiv`, `wcslen`, `swprintf_s` | Windows and CRT headers | explicit `<windows.h>`/`<wchar.h>` includes |
- UID0003F8's historical generic/future wording is explicitly superseded by the applied target/support state.
- IDA function identity is source-useful; physical data name/type are intentionally not emitted.

## Ranked Ownership Analysis

### 1. UID000090 NewGroupPane

- For: sole consumer and accepted local source belong to its method; position-75 pooled child is precedent.
- Against: original local spelling stripped.
- Decision: direct owner/emitter; spelling uncertainty is non-semantic.

### 2. UID0000JS Group

- For: final Group.cpp root.
- Against: direct ownership bypasses exact class/method and creates a file-level pseudo-object.
- Decision: transitive root only.

### 3. UID0002V2 or standalone data

- For: physical containment.
- Against: multi-owner island, no source identity, non-emitting.
- Decision: physical parent only; standalone ownership rejected.

### Proposed new file/grouping, if applicable

- None. Existing UID0003F8 -> UID000090 -> UID0000JS route is complete.

## Source Placement

- Automatic aggregate local inside NewGroupPane::OnPaint in NexusTK/social/Group.cpp; C++03 brace initialization is the compatible source form for current RectBounds H.
- UID0004Z5 source uses a single long-lived `tileContext` for background, member-row, and toggle phases because the binary reuses one stack slot without reinitialization. Five other explicit locals model the five other initializer calls; `scratchContext` is a source-facing inferred name for the initialized-only slot, not an IDA label or omitted call.
- `commaFrame` is the frame-0 `COMMA.EPF` lookup output. The output is not later read directly by UID0004Z5, but the call remains observable resource-layout/cache/output-write behavior and cannot be optimized out of the reconstruction contract.
- The descriptor is one 0x40 automatic local with binary-exact partial writes, not value initialization. `m_displayStatusByte` is written once before iteration; per-row fields are overwritten exactly as listed. This retains the binary write stream and avoids an invented Reset API.
- Group.cpp now emits Section 22's exact file-preamble block before all children through the first UID00005X mechanical carrier: Group.h, UserPane.h, NewHumanImageLib.h, PaletteLib.h, ImageLib.h, Surface.h, windows.h, and wchar.h. UID0004Z5 begins with `void NewGroupPane::OnPaint()` and owns no include. Private group-row access is authorized narrowly through `friend class NewGroupPane;`.
- NewHumanImageLib.h source order is fixed rather than implicit: UID00050M `HumanImageRenderParams` at position 5; UID0001VF complete internal rows and their `ImageFrameTable.h`/`Surface.h` dependencies at position 10; UID000092 class at position 20; UID0000RT extern at position 30. This preserves one type owner per declaration and makes every `std::vector<T>` element complete before the class member is parsed under C++03.
- Physical child attaches to UID000090 at position 76.
- Rejected: file const, class static/member, global data module, rdata aggregate, separate file, duplicate body.
- Only residual uncertainty is lexical spelling; rowBounds is the strongest style-consistent choice.

## Range / Split / Padding / Reclassification Analysis

- Target is one exact 16-byte item with no internal padding.
- Predecessor/successor are separate 16-byte SelfLookPane items with independent xrefs.
- Existing split from UID0002V2 is correct; do not merge.
- Do not split into four scalars; one vector load and one value type control.
- Kind remains physical packed data and reconstructable source-local evidence; only route/formal representation changes.

## Negative Evidence Summary

- No duplicate occurrence, second xref, interior/outbound xref, RVA/raw-offset/extra VA route.
- No guard, escape, identity, member access, indexing, or cross-method use supports persistent source storage.
- Neighbor adjacency does not establish ownership.
- IDA data name is not source-name evidence.
- Physical parent is not source ownership.
- The dated pre-callback method source omitted six observable initializer calls and one resource lookup and contradicted every audited record/descriptor/NewHuman/RectBounds declaration; annotation-only preservation was therefore rejected. The callback replaced that source at full detail.
- No constructor exists that could lawfully replace the six calls, and no direct use proves that `commaFrame` is consumed by `DrawNumberString`; inventing either relationship is rejected.
- The initialized-only 0x90 context has no later read. Omitting its call would change the binary; assigning it a decompiler label would violate source quality. `scratchContext` is the narrow human-facing inference with an explicit confidence cap.
- `appearance.Reset()`, unprefixed descriptor fields, `UserPane::GroupMemberRecord`, shortened NewHuman overloads, member.bodyColor copying, whole-struct zeroing, RectBounds constructors, and Width/Height are all rejected by current headers and/or exact instructions.
- A standalone partial NewHumanImageLib or PaletteLib class is also rejected. Section 22 now provides both complete H assemblies, exact owner/path/insertion points, singleton externs on canonical global pages, sole CPP definitions, removal of the old CPP-local PaletteLib class, and a separate UID0000JS file-preamble CPP disposition.
- Forward declarations of `NewHumanPartEntry`, `NewHumanLayerEntry`, `NewHumanMotionEntry`, `NewHumanCompositionDrawCommand`, or `Acc2DrwEntry` are rejected because those names are `std::vector<T>` element types. Duplicating `FrameDrawRecord`, `RectBounds`, or `SurfaceSpriteBlitOptions` is also rejected because UID0000UN and UID0000TN already emit their complete declarations. Only `GrafPort`, `Motion`, `NewHumanCompositionState`, and `NewHumanCommandSideRecord` remain incomplete, and all class-header uses are pointer/reference or pointer-container uses permitted by C++03.
- Stripped spelling does not justify an IDA/decompiler label in source.

## IDA Rename / Type / Comment Recommendations

The accepted structured handoff and dated supervisor Gate 2B result are retained together. Gate 2B matched every literal precondition, applied only IDA-F8-01, protected IDA-F8-02/03 without change, saved once, and passed post-save attestation/readback. No embedded transaction program is provided; fresh runtime authority remains dynamic.

### IDA-F8-01

- Classification: apply; final disposition `APPLIED_VERIFIED`.
- Dated accepted prestate: data entity head/range [0x00624bf0,0x00624c00), size 16, name exactly xmmword_624BF0, type absent; AR absent; AP absent; FR not applicable; FP not applicable; bytes exactly 06 00 00 00 0E 00 00 00 A1 00 00 00 36 00 00 00; SHA256 A9CB5BAE7A86BEF48A98DBDFA3BFD6919991F1731C183BF87B24B99C675E03B6; inbound xrefs exactly {0x0056cf78}; outbound xrefs empty; interior xrefs at 0x00624bf1, 0x00624bf4, 0x00624bf8, 0x00624bfc, and 0x00624bff empty. Consumer function head/range [0x0056ce50,0x0056da03), size 0xbb3, name exactly NewGroupPane__OnPaint, type exactly void __thiscall(NewGroupPane *this); AR absent; AP absent; FR absent; FP exactly Renders NewGroupPane background, member rows, names, status, HP/MP bars, and numeric glyph strings.; body SHA256 D3FB87AF11A14632F0BC954B387ECC83DBAC01D423426E1DECC7E55A2ABD960C; direct code callers empty; inbound data xrefs exactly {0x00624598}.
- Applied public endpoint: set_address_repeatable_comments with fields database:"<fresh runtime-attested session ID>", items:{addr:"0x00624bf0",comment:"Packed int32 RectBounds {left=6, top=14, right=161, bottom=54}; sole movaps load at 0x0056cf78 seeds NewGroupPane::OnPaint rowBounds, advanced by 44 pixels per row; source is a use-site local initializer, not a standalone object."}.
- Complete achieved readback: target entity remained [0x00624bf0,0x00624c00), size 16, name xmmword_624BF0, type absent, AR absent, FR not applicable, FP not applicable, with exact bytes/hash/xrefs above; AP became exactly Packed int32 RectBounds {left=6, top=14, right=161, bottom=54}; sole movaps load at 0x0056cf78 seeds NewGroupPane::OnPaint rowBounds, advanced by 44 pixels per row; source is a use-site local initializer, not a standalone object. Consumer remained [0x0056ce50,0x0056da03), size 0xbb3, name NewGroupPane__OnPaint, type void __thiscall(NewGroupPane *this), AR absent, AP absent, FR absent, FP exactly Renders NewGroupPane background, member rows, names, status, HP/MP bars, and numeric glyph strings., with the exact body hash, empty direct caller set, and inbound data xref set {0x00624598}.
- Fail-closed contract: any prestate mismatch, non-AP delta, or failed exact readback required rollback. No stop condition occurred; no rename/type/redefine/split/merge/resize/patch action was taken.

### IDA-F8-02

- Classification: no change recommended; final disposition `NO_CHANGE_VERIFIED`.
- Function prestate: [0x0056ce50,0x0056da03), size0xbb3, NewGroupPane__OnPaint, void __thiscall(NewGroupPane *this), AR/AP/FR absent, FP exactly Renders NewGroupPane background, member rows, names, status, HP/MP bars, and numeric glyph strings.; SHA D3FB87AF11A14632F0BC954B387ECC83DBAC01D423426E1DECC7E55A2ABD960C; code callers empty; inbound {0x00624598}.
- Source-dependency protection prestate: exact EPFTileContext_Initialize call heads/bytes are 0x0056ce8b `E8 D0 AB EE FF`, 0x0056cedf `E8 7C AB EE FF`, 0x0056ceea `E8 71 AB EE FF`, 0x0056cef5 `E8 66 AB EE FF`, 0x0056cf00 `E8 5B AB EE FF`, and 0x0056cf0b `E8 50 AB EE FF`; each outbound code edge is 0x00457a60. Literal item [0x006247f0,0x00624804), size 20, name exactly aCommaEpf, type exactly const wchar_t[], value `COMMA.EPF`, inbound data xrefs exactly {0x00567585,0x0056cf1b,0x005bb006}; at 0x0056cf1b bytes are `68 F0 47 62 00`, followed by lookup call [0x0056cf20,0x0056cf25) bytes `E8 CB 33 F6 FF`. These are protected evidence, not mutation targets.
- Full frame: var_300@0x18/4/_DWORD; var_2E4@0x34/4/char[4]; var_2E0@0x38/2/_WORD; var_2DE@0x3a/1/_BYTE; var_2DC@0x3c/4/_DWORD; var_2D8@0x40/2/_WORD; var_2D6@0x42/1/_BYTE; var_2D4@0x44/2/_WORD; var_2D2@0x46/2/_WORD; var_2D0@0x48/2/_WORD; var_2CE@0x4a/4/_DWORD; var_2CA@0x4e/4/_DWORD; var_2C6@0x52/2/_WORD; var_2C3@0x55/2/_WORD; var_2BC@0x5c/1/_BYTE; var_2BA@0x5e/2/_WORD; var_2B2@0x66/1/_BYTE; var_2B1@0x67/1/_BYTE; var_2B0@0x68/1/_BYTE; var_2AF@0x69/2/_WORD; var_2AD@0x6b/1/_BYTE; var_2AC@0x6c/1/_BYTE; var_2AB@0x6d/1/_BYTE; var_2AA@0x6e/1/_BYTE; var_2A9@0x6f/1/_BYTE; var_2A8@0x70/2/_WORD; var_2A6@0x72/1/_BYTE; palette@0x78/4/DLPalette *; var_29C@0x7c/4/ResourceLayoutTable *; var_298@0x80/4/GrafPort *; var_294@0x84/4/_DWORD; var_290@0x88/4/_DWORD; var_28B@0x8d/1/_BYTE; var_28A@0x8e/1/_BYTE; var_289@0x8f/1/_BYTE; var_288@0x90/0x28/EPFTileContext; outContext@0xb8/0x28/EPFTileContext; var_238@0xe0/2/_WORD; var_228@0xf0/4/_DWORD; var_224@0xf4/4/_DWORD; var_220@0xf8/0x28/EPFTileContext; var_1F8@0x120/0x28/EPFTileContext; var_1D0@0x148/0x28/EPFTileContext; var_1A8@0x170/4/_DWORD; var_1A4@0x174/4/_DWORD; var_19C@0x17c/4/_DWORD; tileContext@0x180/0x28/EPFTileContext; sourceBounds@0x1a8/0x10/RectBounds; var_160@0x1b8/0x10/RectBounds; destinationBounds@0x1c8/0x10/RectBounds; bounds@0x1d8/0x10/struct RectBounds; var_130@0x1e8/0x10/RectBounds; var_120@0x1f8/0x10/RectBounds; Buffer@0x208/2/wchar_t; var_10@0x308/4/_DWORD; var_C@0x30c/4/_DWORD; var_4@0x314/4/_DWORD; __saved_registers@0x318/4/_DWORD; __return_address@0x31c/4/_UNKNOWN *; arg_4@0x324/4/_DWORD.
- Vtable item prestate: [0x00624598,0x0062459c), size 4, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes exactly 50 CE 56 00, SHA256 0670DADBA6165B99082256465ECBD290347CC782CA53FBFEFBFC4E373C556803; inbound code xrefs empty; inbound data xrefs empty; outbound code xrefs empty; outbound data xrefs exactly {0x0056ce50}.
- Load item prestate: [0x0056cf78,0x0056cf7f), size 7, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes exactly 0F 28 05 F0 4B 62 00, SHA256 4BCCE14AA114D95AE3A8C37260C49D33130BC9852A2209FE89B19BF62447DF60; inbound code xrefs exactly {0x0056cf76}; inbound data xrefs empty; outbound code xrefs exactly {0x0056cf7f}; outbound data xrefs exactly {0x00624bf0}.
- Store item prestate: [0x0056cf8b,0x0056cf92), size 7, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes exactly 0F 11 85 C0 FE FF FF, SHA256 1E43E29EA20CA9929F7ED191980A599A9D1B2AC862EFFD811BD2B75FA5B6FC6B; inbound code xrefs exactly {0x0056cf87}; inbound data xrefs empty; outbound code xrefs exactly {0x0056cf92}; outbound data xrefs exactly {0xff0000000000d42d}, IDA's stack-frame operand target for the local store.
- Predecessor padding prestate: [0x0056ce4b,0x0056ce50), size 5, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes exactly CC CC CC CC CC, SHA256 992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329; inbound code/data xrefs empty; outbound code/data xrefs empty.
- Successor padding prestate: [0x0056da03,0x0056da10), size 13, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes exactly thirteen CC bytes, SHA256 0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE; inbound code/data xrefs empty; outbound code/data xrefs empty.
- Public endpoint/exact value: no endpoint call. Dated `NO_CHANGE_VERIFIED` poststate was: function [0x0056ce50,0x0056da03), NewGroupPane__OnPaint, void __thiscall(NewGroupPane *this), AR/AP/FR absent, exact FP/body SHA/caller/inbound-data state and all frame rows above; all six initializer call heads/bytes/0x00457a60 outbound edges and the exact COMMA literal/xref/push/lookup-call state above remained byte-for-byte unchanged; vtable [0x00624598,0x0062459c), absent name/type/AR/AP, FR/FP not applicable, exact four bytes/hash, empty inbound code/data, empty outbound code, outbound data {0x0056ce50}; load [0x0056cf78,0x0056cf7f), absent name/type/AR/AP, FR/FP not applicable, exact bytes/hash, inbound code {0x0056cf76}, inbound data empty, outbound code {0x0056cf7f}, outbound data {0x00624bf0}; store [0x0056cf8b,0x0056cf92), absent name/type/AR/AP, FR/FP not applicable, exact bytes/hash, inbound code {0x0056cf87}, inbound data empty, outbound code {0x0056cf92}, outbound data {0xff0000000000d42d}; predecessor padding [0x0056ce4b,0x0056ce50), absent name/type/AR/AP, FR/FP not applicable, exact five CC bytes/hash and empty inbound/outbound code/data sets; successor padding [0x0056da03,0x0056da10), absent name/type/AR/AP, FR/FP not applicable, exact thirteen CC bytes/hash and empty inbound/outbound code/data sets.

### IDA-F8-03

- Classification: no change recommended; final disposition `NO_CHANGE_VERIFIED`.
- Dated accepted prestate: target [0x00624bf0,0x00624c00), size 16, name xmmword_624BF0, type absent, AR absent, AP absent before IDA-F8-01, FR not applicable, FP not applicable, bytes/hash 06 00 00 00 0E 00 00 00 A1 00 00 00 36 00 00 00 / A9CB5BAE7A86BEF48A98DBDFA3BFD6919991F1731C183BF87B24B99C675E03B6, inbound xrefs exactly {0x0056cf78}, outbound xrefs empty. Predecessor [0x00624be0,0x00624bf0), size 16, name xmmword_624BE0, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes 07 00 00 00 3F 00 00 00 79 00 00 00 07 00 00 00, SHA256 62D841EDBEF7683E8C6BE13B7B19809D75CB4A7CFA1B3245B5BCC1E1260B30B4, inbound xrefs exactly {0x005676c7}, outbound xrefs empty. Successor [0x00624c00,0x00624c10), size 16, name xmmword_624C00, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes 0A 00 00 00 0A 00 00 00 0A 00 00 00 3E 00 00 00, SHA256 D27BB1CCAFDCBBC3D04DFBF386071F81F4CBE211A09438B9E49FD503ADBDFF3C, inbound xrefs exactly {0x0056771f}, outbound xrefs empty.
- Collision searches for NewGroupPane_InitialMemberRowBounds, NewGroupPane_MemberRowBounds, and NewGroupPane_RowBounds were empty. This is negative evidence, not permission to invent a physical object.
- Public endpoint/exact value: no endpoint call. Literal achieved target poststate after IDA-F8-01 was [0x00624bf0,0x00624c00), size 16, name xmmword_624BF0, type absent, AR absent, AP exactly IDA-F8-01's proposed text, FR not applicable, FP not applicable, exact target bytes/hash, inbound xrefs {0x0056cf78}, outbound xrefs empty. Literal achieved predecessor poststate was [0x00624be0,0x00624bf0), size 16, name xmmword_624BE0, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes 07 00 00 00 3F 00 00 00 79 00 00 00 07 00 00 00, SHA256 62D841EDBEF7683E8C6BE13B7B19809D75CB4A7CFA1B3245B5BCC1E1260B30B4, inbound xrefs {0x005676c7}, outbound xrefs empty. Literal achieved successor poststate was [0x00624c00,0x00624c10), size 16, name xmmword_624C00, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes 0A 00 00 00 0A 00 00 00 0A 00 00 00 3E 00 00 00, SHA256 D27BB1CCAFDCBBC3D04DFBF386071F81F4CBE211A09438B9E49FD503ADBDFF3C, inbound xrefs {0x0056771f}, outbound xrefs empty. No other field differed.
- Supporting type declaration: none; RectBounds exists, and assigning it to a pool item would falsely imply a source object.
- Dated persistence receipt: byte-preserving backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B003-UID0003F8-Gate2B-20260816-023410.i64`; pre-IDB SHA256 `6460365C357C1DC3F9EAABCF4A77B11E48760F32758D2A364E80AFE1D13BCB5C`; saved IDB SHA256 `9FF6BDCB38628D90066441629ED6B47D8FFBB689DD097D2E41C7BAE40A3550BC` at `2026-08-16T06:34:32.4648784Z`; post-save runtime attestation and complete bounded readback passed.

## First-Draft C++ Recommendation

- Exact target RECONSTRUCTION_CPP CODE:

~~~cpp
// Covered by NewGroupPane::OnPaint() local rowBounds initializer:
// RectBounds rowBounds = { 6, 14, 161, 54 };
~~~

- Exact target RECONSTRUCTION_H CODE:

~~~cpp
~~~

- Exact UID0000JS file-preamble RECONSTRUCTION_CPP CODE, emitted by the Group file root before its class/method children and not owned by UID0004Z5:

~~~cpp
#include "Group.h"
#include "../ui/panels/UserPane.h"
#include "../render/NewHumanImageLib.h"
#include "../render/PaletteLib.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include <windows.h>
#include <wchar.h>
~~~

- Exact replacement UID0004Z5 RECONSTRUCTION_CPP CODE; this formal channel starts at the method definition and contains no file-level include/preamble material:

~~~cpp
void NewGroupPane::OnPaint()
{
    EPFTileContext tileContext;
    EPFTileContext commaFrame;
    EPFTileContext barFill;
    EPFTileContext barLeftCap;
    EPFTileContext barRightCap;
    EPFTileContext scratchContext;
    RectBounds imageBounds;
    RectBounds sourceBounds;
    RectBounds destinationBounds;
    wchar_t percentText[128];
    HumanImageRenderParams appearance;

    tileContext.Initialize();
    appearance.m_displayStatusByte = 0x50;
    DLPalette *inventoryPalette = g_pPaletteLib->GetPaletteByName(L"ITEMINV.PAL");
    commaFrame.Initialize();
    barLeftCap.Initialize();
    barRightCap.Initialize();
    barFill.Initialize();
    scratchContext.Initialize();

    g_pEPFLib->LookupLayoutEntry(L"COMMA.EPF", 0, &commaFrame);
    g_pEPFLib->LookupLayoutEntry(
        m_expanded ? L"ITEMINVE.EPF" : L"GROUP.EPF",
        m_expanded ? 3 : 0, &tileContext);
    g_pfnBlitSprite(this, &tileContext, &tileContext.bounds,
                    &m_visibleBounds, 0, inventoryPalette, 0);

    RectBounds rowBounds = { 6, 14, 161, 54 };
    SetDrawMode(1);
    SetTextBackColor(0);
    const int visibleRows = m_expanded ? 12 : 6;
    int firstMember = m_groupMemberCount - 6;
    if (m_firstVisibleMember + 6 <= m_groupMemberCount)
        firstMember = m_firstVisibleMember;
    if (firstMember < 0)
        firstMember = 0;
    const int lastMember = firstMember + visibleRows < m_groupMemberCount
        ? firstMember + visibleRows : m_groupMemberCount;
    if (m_expanded)
        rowBounds.Offset(5, 0);

    for (int memberIndex = firstMember;
         memberIndex < lastMember;
         ++memberIndex, rowBounds.Offset(0, 44))
    {
        GroupMemberRecord &member =
            g_pUserPane->m_groupMembers[memberIndex];

        g_pEPFLib->LookupLayoutEntry(L"GROUPCOL.EPF", 0, &tileContext);
        RenderTileFrame(&tileContext, &tileContext.bounds, &rowBounds,
                        0, L"GROUPCOL.PAL", 0);

        appearance.m_ridingAppearanceId = 0;
        appearance.m_gender = 0;
        appearance.m_compositionMode = 0;
        appearance.m_faceId = member.faceId;
        appearance.m_hairId = member.hairId;
        appearance.m_faceColor = member.faceColor;
        appearance.m_hairColor = member.hairColor;
        appearance.m_skinColor = member.skinColor;
        appearance.m_bodyId = 0xffff;
        appearance.m_weaponId = 0xffff;
        appearance.m_bodyColor = 0;
        appearance.m_weaponColor = 0;
        appearance.m_shieldOrArrowId = 0xffff;
        appearance.m_shieldOrArrowColor = 0;
        appearance.m_helmetId = member.helmetId;
        appearance.m_helmetColor = member.helmetColor;
        appearance.m_mantleId = 0xffff;
        appearance.m_neckId = 0xffff;
        appearance.m_mantleColor = 0;
        appearance.m_neckColor = 0;
        appearance.m_shoesId = 0xffff;
        appearance.m_coatId = 0xffff;
        appearance.m_shoesColor = 0;
        appearance.m_invisible = 0;
        appearance.m_faceDecorationId = member.faceDecorationId;
        appearance.m_faceDecorationColor = member.faceDecorationColor;
        appearance.m_hairDecorationId = member.hairDecorationId;
        appearance.m_hairDecorationColor = member.hairDecorationColor;
        appearance.m_secondFaceDecorationId = member.secondFaceDecorationId;
        appearance.m_secondFaceDecorationColor = member.secondFaceDecorationColor;
        appearance.m_fullBodyId = 0xffff;

        g_pNewHumanImageLib->CalculateBounds(
            &appearance, 2, 0, 0, &imageBounds, 0, 1, true, 0);

        RectBounds memberBounds = rowBounds;
        memberBounds.top = memberBounds.bottom - 20;
        memberBounds.left = imageBounds.left + 13;
        memberBounds.right = imageBounds.left + 72;
        const int imageHeight = imageBounds.bottom - imageBounds.top;
        if (imageHeight > 40)
            memberBounds.Offset(0, -(imageHeight - 40) / 2);
        memberBounds.Offset(m_expanded ? 5 : 0, 2);

        g_pNewHumanImageLib->Draw(
            this, &memberBounds, &appearance, 2, 0, 0, 0,
            false, 0, 0.0f, 1, true, 0);

        RectBounds nameBounds = {
            rowBounds.left + 62, rowBounds.top + 6,
            rowBounds.left + 162, rowBounds.top + 20
        };
        const unsigned char nameColor = member.active ? 0x0c : 0x8f;
        SetTextColor(nameColor);
        nameBounds.Offset(-1, -2);
        DrawTextInRect(member.name, wcslen(member.name), &nameBounds);
        nameBounds.Offset(1, 0);
        DrawTextInRect(member.name, wcslen(member.name), &nameBounds);
        SetTextColor(0x8f);

        if (member.currentHitPoints != 0)
        {
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 0, &barFill);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 1, &barLeftCap);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 2, &barRightCap);

            RectBounds fullBar = {
                rowBounds.left + 64, rowBounds.top + 20,
                rowBounds.left + 149, rowBounds.top + 34
            };
            RectBounds fillBounds = fullBar;
            fillBounds.right = fullBar.right
                - (fullBar.right - fullBar.left) / 2 - 4;
            if (member.maximumHitPoints != 0)
            {
                if (member.currentHitPoints < member.maximumHitPoints)
                {
                    fillBounds.left = fillBounds.right - MulDiv(
                        fillBounds.right - fillBounds.left,
                        member.currentHitPoints,
                        member.maximumHitPoints);
                }

                sourceBounds = barFill.bounds;
                sourceBounds.left += fillBounds.left - fillBounds.right;
                RectBounds leftCapBounds = fillBounds;
                leftCapBounds.left = fillBounds.left - 3;
                leftCapBounds.right = fillBounds.left;
                RectBounds rightCapBounds = fillBounds;
                rightCapBounds.left = fillBounds.right;
                rightCapBounds.right = fillBounds.right + 3;
                RenderTileFrame(&barLeftCap, &barLeftCap.bounds,
                                &leftCapBounds, 1, L"BAR.PAL", 0);
                RenderTileFrame(&barFill, &sourceBounds, &fillBounds,
                                0, L"BAR.PAL", 0);
                RenderTileFrame(&barRightCap, &barRightCap.bounds,
                                &rightCapBounds, 1, L"BAR.PAL", 0);
            }
            else
            {
                fillBounds.left = fillBounds.right;
            }

            if (m_exposedRegion.IntersectsRect(&fillBounds))
            {
                fillBounds.Offset(-2, 3);
                swprintf_s(percentText, 128, L"%d%%",
                    static_cast<unsigned int>(
                        static_cast<double>(member.currentHitPoints) /
                        static_cast<double>(member.maximumHitPoints) * 100.0));
                fillBounds.left = fillBounds.right - 9 * wcslen(percentText);
                DrawNumberString(percentText, fillBounds.left,
                                 fillBounds.top, 2);
            }

            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 3, &barFill);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 4, &barLeftCap);
            g_pEPFLib->LookupLayoutEntry(L"BAR.EPF", 5, &barRightCap);

            fillBounds = fullBar;
            fillBounds.left = fullBar.left
                + (fullBar.right - fullBar.left) / 2 + 4;
            if (member.maximumManaPoints != 0)
            {
                if (member.currentManaPoints < member.maximumManaPoints)
                {
                    fillBounds.left = fillBounds.right - MulDiv(
                        fillBounds.right - fillBounds.left,
                        member.currentManaPoints,
                        member.maximumManaPoints);
                }

                sourceBounds = barFill.bounds;
                sourceBounds.left += fillBounds.left - fillBounds.right;
                RectBounds leftCapBounds = fillBounds;
                leftCapBounds.left = fillBounds.left - 3;
                leftCapBounds.right = fillBounds.left;
                RectBounds rightCapBounds = fillBounds;
                rightCapBounds.left = fillBounds.right;
                rightCapBounds.right = fillBounds.right + 3;
                RenderTileFrame(&barLeftCap, &barLeftCap.bounds,
                                &leftCapBounds, 1, L"BAR.PAL", 0);
                RenderTileFrame(&barFill, &sourceBounds, &fillBounds,
                                0, L"BAR.PAL", 0);
                RenderTileFrame(&barRightCap, &barRightCap.bounds,
                                &rightCapBounds, 1, L"BAR.PAL", 0);
            }
            else
            {
                fillBounds.left = fillBounds.right;
            }

            if (m_exposedRegion.IntersectsRect(&fillBounds))
            {
                fillBounds.Offset(-2, 3);
                swprintf_s(percentText, 128, L"%d%%",
                    static_cast<unsigned int>(
                        static_cast<double>(member.currentManaPoints) /
                        static_cast<double>(member.maximumManaPoints) * 100.0));
                fillBounds.left = fillBounds.right - 9 * wcslen(percentText);
                DrawNumberString(percentText, fillBounds.left,
                                 fillBounds.top, 2);
            }
        }
    }

    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF",
        7 * m_toggleButtonState + (m_expanded ? 3 : 4), &tileContext);
    RectBounds toggleBounds;
    InitRectBounds(&toggleBounds, 168, 37, 185, 54);
    if (m_expanded)
        toggleBounds.Offset(5, 0);
    RenderTileFrame(&tileContext, &tileContext.bounds, &toggleBounds,
                    0, L"invenbut.pal", 0);
}
~~~

- UID0004Z5 H remains blank because UID000090 owns `virtual void OnPaint();`. UID000090 owns the target marker once. No rectangle storage definition, static, accessor, constructor, or duplicate body is introduced.
- Exact supporting H dispositions required in the same callback. Each block is owned by the named UID and inserted into the named generated header; no fragment is emitted as a standalone class and no class declaration remains in a CPP channel.

~~~cpp
// UID0000FQ UserPane private section:
friend class NewGroupPane;

// UID0001VF, NexusTK/render/NewHumanImageLib.h, H position 10.
// UID00050M HumanImageRenderParams is position 5.
#include "ImageFrameTable.h"
#include "Surface.h"

#pragma pack(push, 1)
struct NewHumanSequenceFrame
{
    int recordIndex;
    unsigned char flags;
    int value;
};
#pragma pack(pop)

struct NewHumanSequenceFrameTable
{
    int motionIndex;
    int frameBase;
    int frameCount;
    NewHumanSequenceFrame *frames;
};

#pragma pack(push, 1)
struct NewHumanPartFrameDescriptor
{
    int descriptorId;
    int frameBase;
    int drawIndexBase;
    int rawRecordCount;
    unsigned char primaryFrameCount;
    unsigned short *primaryFrameData;
    unsigned char secondaryFrameCount;
    unsigned short *secondaryFrameData;
    unsigned short sequenceCount;
    NewHumanSequenceFrameTable *sequenceFrames;
};
#pragma pack(pop)

struct NewHumanPartEntry
{
    int partId;
    wchar_t name[20];
    int drawIndexBase;
    int descriptorBase;
    int descriptorCount;
    int rawRecordCount;
    NewHumanPartFrameDescriptor *frameDescriptors;
    ArchiveMetadataTable *spriteArchive;
};

struct NewHumanLayerEntry
{
    int layerId;
    char name[20];
    int childCount;
    int *childIndexes;
};

#pragma pack(push, 1)
struct NewHumanMotionEntry
{
    unsigned char reservedPrefix[0x17];
    int motionId;
    char name[20];
    unsigned char reservedAfterName[2];
    unsigned char direction;
    int fallbackMotionId;
    int frameCount;
    unsigned short *frameOffsets;
    unsigned char *frameData;
};
#pragma pack(pop)

struct NewHumanCompositionDrawCommand
{
    int partId;
    FrameDrawRecord frame;
    SurfaceSpriteBlitOptions options;
    DLPalette *palette;
};

struct Acc2DrwEntry
{
    bool enabled[3];
};

typedef char NewHumanSequenceFrameSizeMustBe9[
    (sizeof(NewHumanSequenceFrame) == 0x09) ? 1 : -1];
typedef char NewHumanSequenceFrameTableSizeMustBe16[
    (sizeof(NewHumanSequenceFrameTable) == 0x10) ? 1 : -1];
typedef char NewHumanPartFrameDescriptorSizeMustBe32[
    (sizeof(NewHumanPartFrameDescriptor) == 0x20) ? 1 : -1];
typedef char NewHumanPartEntrySizeMustBe68[
    (sizeof(NewHumanPartEntry) == 0x44) ? 1 : -1];
typedef char NewHumanLayerEntrySizeMustBe32[
    (sizeof(NewHumanLayerEntry) == 0x20) ? 1 : -1];
typedef char NewHumanMotionEntrySizeMustBe66[
    (sizeof(NewHumanMotionEntry) == 0x42) ? 1 : -1];
typedef char NewHumanCompositionDrawCommandSizeMustBe80[
    (sizeof(NewHumanCompositionDrawCommand) == 0x50) ? 1 : -1];
typedef char Acc2DrwEntrySizeMustBe3[
    (sizeof(Acc2DrwEntry) == 0x03) ? 1 : -1];

// UID000092, NexusTK/render/NewHumanImageLib.h, H position 20.
// This class follows the complete UID0001VF row block above.
#include "../util/LObject.h"
#include <deque>
#include <vector>

class GrafPort;
class Motion;
struct NewHumanCompositionState;
struct NewHumanCommandSideRecord;

class NewHumanImageLib : public LObject
{
public:
    NewHumanImageLib();
    virtual ~NewHumanImageLib();

    void CalculateBounds(const HumanImageRenderParams *appearance,
                         unsigned char direction,
                         Motion *motion,
                         int frameIndex,
                         RectBounds *imageBounds,
                         RectBounds *secondaryBounds,
                         int renderMode,
                         bool moving,
                         int rotationStep);
    void Draw(GrafPort *target,
              const RectBounds *bounds,
              const HumanImageRenderParams *appearance,
              unsigned char direction,
              Motion *motion,
              unsigned int effectState,
              int frameIndex,
              bool useMapLightOverlay,
              FrameDrawRecord *translatedClipRecord,
              float translatedClipOffset,
              int renderMode,
              bool moving,
              int rotationStep);

private:
    void LoadPartFrameDrawRecord(int partIndex,
                                 unsigned short descriptorIndex,
                                 int motionIndex,
                                 int frameIndex,
                                 FrameDrawRecord *outRecord);
    void LoadMotionTable(const wchar_t *tableName);
    void LoadLayerTable(const wchar_t *tableName);
    void LoadPartTable(const wchar_t *tableName);
    void LoadPartSpriteDescriptors();
    void LoadAcc2DrwTable(const wchar_t *tableName);
    int CalculateCompositionBounds(const int *drawOrder,
                                   const NewHumanCompositionState &state,
                                   int sequence,
                                   int frame,
                                   RectBounds *bounds,
                                   RectBounds *projectedBounds,
                                   char direction);
    void ResolveCompositionPartRect(NewHumanPartEntry *part,
                                    unsigned short descriptorIndex,
                                    int motionIndex,
                                    int frameIndex,
                                    int yOffset,
                                    int xOffset,
                                    RectBounds *outBounds);
    void ResolveCompositionPartFrame(NewHumanPartEntry *part,
                                     unsigned short descriptorIndex,
                                     int motionIndex,
                                     int frameIndex,
                                     int yOffset,
                                     int xOffset,
                                     FrameDrawRecord *outRecord);

    std::vector<NewHumanPartEntry> m_partEntries;
    std::vector<NewHumanLayerEntry> m_layerEntries;
    std::vector<NewHumanMotionEntry> m_motionEntries;
    std::vector<NewHumanCompositionDrawCommand> m_compositionDrawCommands;
    std::deque<NewHumanCommandSideRecord *> m_loadedPartList;
    std::vector<Acc2DrwEntry> m_acc2drwEntries;
    std::vector<unsigned long> m_hairColorEntries;
};

// UID0000RT, NexusTK/render/NewHumanImageLib.h, H position 30:
extern NewHumanImageLib *g_pNewHumanImageLib;

// UID0000A1, NexusTK/render/PaletteLib.h. Move this entire existing
// declaration block from formal CPP to formal H at class position 10.
#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/List.h"
#include "Palette.h"

struct PaletteLibLoadedEntry
{
    wchar_t *name;
    DLPalette *palette;
};

void __stdcall ApplyPaletteEntryMovesToCollection(List *palettes);

class PaletteLib : public LObject, public Singleton<PaletteLib>
{
public:
    PaletteLib();
    virtual ~PaletteLib();

    int GetScreenPaletteMode() const;
    void SetScreenPaletteMode(int mode);
    DLPalette *GetCurrentPalette();
    DLPalette *GetTextPalette();
    DLPalette *GetPaletteByName(const wchar_t *paletteName);
    DLPalette *GetSlotPalette(int slot, int paletteIndex, int superPaletteIndex);
    void ResetScreenPaletteSlots();
    bool SetPaletteFilterActive(bool active);
    float GetPaletteFilterWeight() const;
    void UpdatePaletteFilterTables(float weight);

private:
    int FindLoadedPaletteIndexByName(const wchar_t *paletteName) const;
    int LoadNamedPalette(const wchar_t *paletteName);
    List *LoadPaletteList(const wchar_t *paletteName);
    void LoadPaletteSet(int slot, const wchar_t *paletteName);

    int m_screenPaletteMode;
    List *m_loadedPalettes;
    DLPalette m_basePalette;
    DLPalette m_filteredBasePalette;
    DLPalette m_textPalette;
    List *m_sourcePaletteSets[25];
    List *m_runtimePaletteSets[25];
    bool m_useFilteredPalettes;
    float m_paletteFilterWeight;
    DLPalette m_superPalettes[7];
    DLPalette m_filteredSuperPalettes[7];
};

// UID0000RW, NexusTK/render/PaletteLib.h, immediately after the class:
extern PaletteLib *g_pPaletteLib;
~~~

- Exact post-relocation CPP ownership: UID0000A1 formal CPP retains only `[[CHILDREN]]`; the complete class/helper declaration above exists once in UID0000A1 formal H. UID0000RW remains the sole CPP storage definition `PaletteLib *g_pPaletteLib = 0;`; no class declaration or duplicate extern is left in CPP. UID0001VF emits the internal NewHuman row declarations only through H position 10. UID000092 formal CPP retains `#include "ImageFrameTable.h"` plus `[[CHILDREN]]`; its complete class declaration exists once at H position 20, and UID0000RT remains the sole CPP definition `NewHumanImageLib *g_pNewHumanImageLib = 0;` with the one position-30 H extern above.
- The NewHuman block is dependency-complete C++03 source assembly: UID00050M position 5, UID0001VF position 10, UID000092 position 20, and UID0000RT position 30. Every vector element is complete before the class definition; `FrameDrawRecord`/`RectBounds` and `SurfaceSpriteBlitOptions` come from their sole existing header owners; only pointer/reference-only `GrafPort`, `Motion`, `NewHumanCompositionState`, and `NewHumanCommandSideRecord` remain forward-declared. Raw, retained, or not-yet-emitting method-family entries remain documented on UID000092 and are not fabricated as extra declarations in this bounded callback.

- The first `tileContext.Initialize()` precedes the one-time descriptor status write and inventory-palette lookup; the remaining five calls follow the lookup in exact binary order. `commaFrame` receives the exact frame-0 `COMMA.EPF` lookup. `scratchContext` preserves the initialized-only sixth slot. One `tileContext` is reused across the three non-overlapping draw phases, matching physical slot reuse without decompiler-shaped local aliases. Aggregate `rowBounds` is declared after the background blit, where the binary performs the packed load/store.
- The descriptor is intentionally not value-initialized. The listed writes exactly cover observed stack stores; `m_displayStatusByte` is written once, `m_bodyColor` is zero rather than copied from `GroupMemberRecord`, and untouched bytes remain untouched. Bounds and draw calls use all observed arguments, and member geometry follows the image bounds exactly.
- Comments in the target covered-by marker preserve physical provenance. `rowBounds`, `commaFrame`, and `scratchContext` are ordinary source-facing inferred names; their lexical uncertainty is scored rather than replaced with IDA labels.

## Final Recommendation

- The accepted ordinary target/support recommendations and all dated supervisor-owned manual-coverage/IDA actions are applied or no-change verified exactly; current external authority remains dynamic.
- Owner/emitter is UID000090 position 76; UID0000JS remains source root.
- UID0001HC/UID0002V2 remain non-emitting indexes.
- UID0004Z5 contains the exact corrected Section 22 source; UID0001VF contains the exact nested-row H, UID000092 contains the class H after its explicit child insertion point, UID0000RT contains the extern, Palette class/helper declarations are in H while UID0000RW owns its extern, and the Group preamble occurs before children through UID00005X. UID0000UN/UID0000TN remain sole dependency owners; UID000090 OnPaint declaration, RectBounds/EPFTileContext layouts, UID0003EV pooled ownership, and target neighbors are preserved.
- No in-scope future research remains. `rowBounds`, `commaFrame`, `scratchContext`, method parameter names, and const qualifiers are strongest human-source inferences; only lexical/detail uncertainty remains a confidence cap, not deferred investigation.

## Recommended Target Doc Changes

- Applied metadata is 94/94, owner/emitter 000090, position 76, TRUE.
- Applied formal channels are exact Section 22 CPP and blank H.
- Item Summary: Compiler-pooled source-local RectBounds aggregate initializer [6,14,161,54]; sole movaps load at 0x0056cf78 seeds NewGroupPane::OnPaint rowBounds, which advances 44 pixels per row; represented through UID000090 position 76 as a covered-by marker with no standalone object or H declaration; owning method source is corrected to the accepted EPFTileContext lifecycle, global GroupMemberRecord, partial HumanImageRenderParams, full NewHuman calls, constructor-free RectBounds geometry, exact COMMA lookup, and observed context reuse.
- Incorporate all bytes/hash/layout/xref/search/load/store/function/frame/vtable/behavior/source/range/negative/IDA facts.
- Preserve old generic/deferred conclusion only as explicitly superseded history.

## Recommended Support Doc Changes

| Path | Applied incorporation | Metadata/formal |
|---|---|---|
| by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md | formal CPP replaced with exact Section 22 body; UID0003F8 provenance and lifecycle/resource reuse, global row type, exact partial descriptor writes, full NewHuman calls, member bounds, constructor-free RectBounds, and declaration dependencies incorporated | completion 94, confidence 93, pos70, blank H |
| by-class/NewGroupPane.md | position-76 pooled-local child added after UID0003F2; corrected OnPaint source/declaration dependency incorporated | retained 94/95 and complete H/topology |
| by-file/Group.md | class route/local closure and corrected OnPaint behavior incorporated; exact preamble emitted before children through UID00005X mechanical carrier; no-named-object policy preserved | retained 91/88 |
| by-memory/0x0056c4c0-0x0056e939.GroupPanes.md | exact target provenance and corrected OnPaint context/resource/descriptor/API inventory incorporated | retained 92/94 FALSE/non-emitting |
| by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md | complete split inventory and 0x00624c60 SimpleListPane COL boundary preserved; UID0003F8 route refined to UID000090 position 76 -> UID0000JS | retained 88/92 NONE/FALSE/non-emitting |
| by-memory/0x006247f0-0x00624804.SharedCommaEpfResourceString.md | exact NewGroupPane frame-0 lookup phase/output and no-later-read fact incorporated; three-owner pooled-literal disposition preserved | retained 85/88 NONE/FALSE/non-emitting |
| by-class/UserPane.md | global GroupMemberRecord/private array preserved; narrow `friend class NewGroupPane;` added for the binary direct read path | retained 94/95; H delta only |
| by-type/by-struct/HumanImageRenderParams.md | exact NewGroupPane partial-write consumer, zero/0xffff defaults, untouched fields, and no-Reset/no-whole-clear evidence incorporated | retained 94/95 and existing packed H |
| by-type/by-struct/NewHumanImageLibLayout.md | exact complete sequence/descriptor/part/layer/motion/composition-command/accessory H installed with ImageFrameTable.h/Surface.h dependencies and all eight C++03 size guards; blank-H defect historicalized and owner order/forward-declaration legality documented | applied 92/93; owner/emitter remain UID000092 |
| by-item/EPFArchiveMetadataTable.md | no edit; preserve sole ImageFrameTable.h ownership for complete RectBounds/ArchiveMetadataTable/FrameDrawRecord dependencies | keep 90/92 and complete H |
| by-global/SurfaceRenderCallbackTable.md | no edit; preserve sole Surface.h ownership for complete SurfaceSpriteBlitOptions and pointer-only DLPalette dependency | keep 94/95 and complete H |
| by-class/NewHumanImageLib.md | complete class declaration installed once after the explicit child insertion point containing UID0001VF rows, with every emitted child prototype, full CalculateBounds/Draw contracts, exact containers, and Group consumer evidence; formal CPP retains include plus children only | applied 90/91; no incomplete vector element or partial class |
| by-global/g_pNewHumanImageLib.md | one compile-visible extern installed after the complete class; sole CPP definition and all consumer facts preserved | applied 90/93 for closed H/CPP route |
| by-class/PaletteLib.md | complete class/helper declaration moved from formal CPP to formal H at position 10; formal CPP retains only children; extern remains owned by UID0000RW | retained 92/93; complete H, no partial class |
| by-global/g_pPaletteLib.md | compile-visible extern added to PaletteLib H; sole CPP definition preserved | retained 92/94 |
| UID0001VP, UID00004I, UID0003F6, UID0003F2, UID0003F7, UID0003F9 | no edit; preserve current support/control/type facts; UID0001VP specifically disproves ctor/Width/Height use | already present |

## Score And Metadata Recommendation

| Page | Assignment-time | Applied/current | Reason |
|---|---|---|---|
| 0003F8 | 85/88, 0000JS direct, blank | 94/94, 000090 pos76, CPP marker, blank H | physical route plus same-callback body/declaration closure are complete; inferred rowBounds spelling/pooling caps confidence |
| 0004Z5 | 94/95 pos70, 000090, TRUE | 94/93 pos70, 000090, TRUE | exact behavior and declaration compatibility follow the full CPP/H/include repair; original local/parameter spellings, const qualifiers, and scratch intent do not justify 95 confidence |
| 000090 | 94/95, 0000JS, TRUE | unchanged 94/95 | exact class H/topology already complete; add one no-object child route and corrected method-child source |
| 0000JS | 91/88, FILE | unchanged 91/88 | target route is conclusively Group.cpp; broad historical translation-unit partition is separately scored and unaffected |
| 0001HC | 92/94, 0000JS, FALSE/non-emitting | unchanged 92/94 | exact physical function split remains complete and non-emitting |
| 0002V2 | 88/92, NONE/FALSE/non-emitting | unchanged 88/92 | current mixed-island inventory already gives exact child boundaries; add current UID0003F8 disposition |
| 0001VP | 85/88, 0000N2, TRUE | unchanged 85/88 | layout is sufficient and this pass produces no new struct declaration evidence |
| 0003F6 | completion 94, confidence 96, 0000JS, TRUE | unchanged completion 94 / confidence 96 | separate executed scale-literal child; used only as a source-placement control |
| 0003F2 | 94/95, 000090, TRUE | unchanged 94/95 | separate executed position-75 literal child; used only as ordering precedent |
| 0003F7 | 90/92, 0000NL, TRUE | unchanged 90/92 | byte-distinct predecessor with independent SelfLookPane route |
| 0003F9 | 90/92, 0000NL, TRUE | unchanged 90/92 | byte-distinct successor with independent SelfLookPane route |
| 00004I | 88/90, 0000J4, TRUE | unchanged 88/90 | accepted H already supplies exact bounds member and explicit lifecycle API; no constructor is invented |
| 0003EV | 85/88, NONE/FALSE/non-emitting | unchanged 85/88 | three-owner pooled literal remains non-emitting; exact Group lookup phase is added as support evidence |
| 0000FQ | 94/95, 0000P1, TRUE | unchanged 94/95 | exact record/layout already complete; narrow friendship closes one direct consumer |
| 00050M | 94/95, 0000LR, TRUE | unchanged 94/95 | packed layout stays exact; add one binary-exact partial-write consumer |
| 0001VF | 87/90, 000092, TRUE, blank H/position | 92/93, 000092, TRUE, complete H position 10 | exact five vector elements, descriptor/sequence internals, transitive existing-header dependencies, and C++03 size guards close the dated pre-callback generated-header blocker; inferred original private names cap confidence |
| 0000UN | 90/92, 0000K1, TRUE, complete H | unchanged 90/92 | existing ImageFrameTable.h remains sole complete FrameDrawRecord/RectBounds owner; include use adds no new evidence |
| 0000TN | 94/95, 0000OC, TRUE, complete H | unchanged 94/95 | existing Surface.h remains sole complete SurfaceSpriteBlitOptions owner; include use adds no new evidence |
| 000092 | 88/90, 0000LR, TRUE, blank H/position | 90/91, 0000LR, TRUE, complete formal H position 20 | coherent class declaration follows complete UID0001VF rows and covers all currently emitted child bodies, direct public consumers, exact 0x60 layout/container fields, and singleton route; retained/non-emitting method-family spellings still cap final confidence |
| 0000RT | 88/92, 0000LR, TRUE, blank H/position | 90/93, 0000LR, TRUE, extern H position 30 | exact extern after the complete class plus preserved sole CPP definition closes declaration/definition route without changing storage identity |
| 0000A1 | 92/93, 0000MB, TRUE | unchanged 92/93 | existing complete declaration is relocated to its correct H channel; no behavioral inference changes |
| 0000RW | 92/94, 0000MB, TRUE | unchanged 92/94 | extern declaration adds no new storage/lifecycle classification |

- Not lower: exact physical/source/route closure.
- Not higher: original local spelling/compiler pooling remain inferred; target is physical evidence, not independent authored storage.
- Literal broader-split audit: current UID0000JS names `NexusTK/social/Group.cpp` as the accepted source root and separately records speculative `GroupPane.cpp`, `GroupChatInput.cpp`, `ScrollCollectionPane`, and `CommandInputPanes` candidates. UID0003F8 has exactly one use in UID0004Z5 `NewGroupPane::OnPaint`; UID0004Z5 is owned by UID000090, and UID000090 already routes through UID0000JS. No UID0003F8 xref, declaration, callback, or dependency reaches any alternate candidate. The in-scope placement question is therefore closed as UID0003F8 -> UID000090 -> UID0000JS -> Group.cpp, with no split action. The historical partition of unrelated chat/input families is explicitly outside this target/support callback and already represented by UID0000JS's unchanged 91/88 score; it is not an unexplored UID0003F8 blocker.

## Open Questions With Attempted Resolution

| Question | Resolution | Impact |
|---|---|---|
| Consumer? | NewGroupPane::OnPaint by xref/type/vtable/source | closed |
| Field meaning? | RectBounds edges by UDT/store/mutations | closed |
| Standalone object? | no, by unique sole local route/no escape | closed |
| Source name? | rowBounds by role/current style | lexical score cap only |
| Owner/emitter? | 000090 pos76 -> 0000JS | closed |
| H code? | blank, no declaration | closed |
| Split/type/rename? | none; preserve physical item | closed |
| Empty emitter? | exact covered-by marker | closed and applied; exact covered-by marker present |
| EPFTileContext construction? | no constructor; six explicit `Initialize()` calls retained exactly | closed by accepted H and scoped live call search |
| Which contexts? | tileContext reused for background/rows/toggle; commaFrame, barLeftCap, barRightCap, barFill, and initialized-only scratchContext occupy the five other slots | behavior closed; scratch lexical intent caps UID0004Z5 confidence at 93 |
| COMMA.EPF phase/use? | frame-0 lookup at 0x0056cf20 into initialized commaFrame after all six initializers and before background; no later direct read | exact call/output side effect retained; no invented DrawNumberString dependency |
| Group member type/access? | global GroupMemberRecord; private array receives narrow NewGroupPane friendship | closed by authoritative H and direct reads |
| Descriptor initialization? | no Reset/whole clear; one pre-loop status write plus exact per-row partial m_* stores, including zero absent colors/invisible and 0xffff absent IDs | closed by stack-write inventory |
| NewHuman calls? | full 9-argument CalculateBounds and 13-argument Draw contracts with exact memberBounds geometry | closed by 0x0056d1ba/0x0056d25a and accepted consumers |
| RectBounds APIs? | aggregate/direct edges/Offset plus actual toggle-site InitRectBounds; no ctor/Width/Height | closed by authoritative H and instruction calls |
| Header/global closure? | exact UID00050M pos5 -> UID0001VF pos10 -> UID000092 pos20 -> UID0000RT pos30 NewHuman H, complete five vector elements and transitive existing-owner dependencies, complete Palette H, sole CPP definitions, Palette CPP-declaration removal, and separate UID0000JS file-preamble include block | closed and implemented; owner-ordered H/global/preamble route physically verified |
| Are vector elements complete under C++03? | yes; UID0001VF now installs exact 0x44/0x20/0x42/0x50/0x03 declarations and guards, and physical generated H readback proves the dependency order | closed and implemented |
| Which names may remain forward-declared? | only GrafPort, Motion, NewHumanCompositionState, and NewHumanCommandSideRecord because class-header use is exclusively pointer/reference or deque-of-pointer | C++03 legality closed |
| Broader file split? | sole consumer/owner chain resolves this child to Group.cpp; alternate chat/input/pane candidates have zero target route and are outside the exact target/support callback | closed; unchanged UID0000JS score justified |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Dated read-only coverage receipt at 2026-08-15T22:10:38-04:00: by-memory SHA256 4E8B2EB694A13FAFBC682DC3D38601EEF8329A1FAF66197B37F56EC7CEDB75DC, 2,244,480 bytes / 5,015 lines; by-class SHA256 9F748714DD88004E0207A9D34004F015505613DBE7208B4344144E179ABD6EFE, 279,995 bytes / 627 lines; by-type/by-struct SHA256 0EE29720F89870C2B34EC46FE506B0AC3729BC9E93CBA83C88A017D1B0089712, 59,326 bytes / 139 lines; by-global SHA256 D54D412EE6E6D486EFD645F40469D74D9BD51EFC104E31CC98896C57A9DA9603, 100,818 bytes / 219 lines; by-file SHA256 39BA7D0BACF7C554A6BF4103DA5156842364A108A0E0FAAB1984920207ECA251, 171,470 bytes / 320 lines. These are dated drafting receipts, not permanent current authority.
- Historical dependency-closure coverage readback at 2026-08-16T00:06:08-04:00: by-type/by-struct SHA256 91F0C70B78FEDD7475C47DF90A0A08C337CF13F340BD4D15ACA3D54A88EBBBB4, 59,754 bytes / 140 lines; by-item SHA256 BFB11E79A010D9BA764245DF386CADD779B78ED9C41226A93DC85C653F429CA1, 29,377/87; by-class SHA256 EBAEFAF2697643968A1CD7122C9A5DE9DCAA61F298D6AB3F6D5AFECCD7DB766E, 281,096/628; by-global SHA256 D54D412EE6E6D486EFD645F40469D74D9BD51EFC104E31CC98896C57A9DA9603, 100,818/219. These were row-selection receipts before supervisor closure.
- Historical pre-closure continuity at 2026-08-16T01:42:23-04:00: by-memory `AA23C646B3D531F70642D20054E67CD59B466B265E928A83B04DD4E94DF4DF70`, 2,275,465 bytes / 5,068 lines; by-class `EBAEFAF2697643968A1CD7122C9A5DE9DCAA61F298D6AB3F6D5AFECCD7DB766E`, 281,096/628; by-type/by-struct `91F0C70B78FEDD7475C47DF90A0A08C337CF13F340BD4D15ACA3D54A88EBBBB4`, 59,754/140; by-global `D54D412EE6E6D486EFD645F40469D74D9BD51EFC104E31CC98896C57A9DA9603`, 100,818/219; by-file `AAC0C842C626CD28D2815479B78D4D31C282E67E2FDA7E8B9A786E23CFA74CCA`, 173,436/321; by-item `BFB11E79A010D9BA764245DF386CADD779B78ED9C41226A93DC85C653F429CA1`, 29,377/87. At that snapshot UID0003F8 was absent and the listed rows were stale; commands 000000024688..000000024692 superseded that state.

| Dated supervisor closure | Command | Disposition | Post-command receipt |
|---|---|---|---|
| by-memory/-coverage-report.md | 000000024688 | C-F8-039/040/043/044/071 `APPLIED_VERIFIED` | exit 0, ok:1; SHA256 F76DCEC44035F10942608245138A4C622FA0D6206083DD4E3191DA4A1433BD92; 2,277,601 bytes / 5,070 lines |
| by-class/-coverage-report.md | 000000024689 | C-F8-041/067/069 `APPLIED_VERIFIED`; C-F8-065 `NO_CHANGE_VERIFIED` | exit 0, ok:1; SHA256 3715B24B0AB799B4840D08506F3469CEA714A9E3FF2AC97E42560B6CF18DE034; 281,416 bytes / 628 lines |
| by-type/by-struct/-coverage-report.md | 000000024690 | C-F8-066/087 `APPLIED_VERIFIED` | exit 0, ok:1; SHA256 CC89CD5B9689D8530F8511CDC4825CDF3CE0AEF96C917D65460E93AC5C05E7A3; 59,994 bytes / 140 lines |
| by-global/-coverage-report.md | 000000024691 | C-F8-068/070 `APPLIED_VERIFIED`; C-F8-089 `NO_CHANGE_VERIFIED` | exit 0, ok:1; SHA256 4B6617E984E9409D44F6D1D5C26B26EAFADDE9CA19682A90885B914565C33810; 100,825 bytes / 219 lines |
| by-file/-coverage-report.md | 000000024692 | C-F8-042 `APPLIED_VERIFIED` | exit 0, ok:1; SHA256 5A5831DDB9719031C461CD4CA0C2397C6F9E86BC791698ADC5BA235070BE024E; 173,543 bytes / 321 lines |
| by-item ImageFrameTable row | read-only row comparison | C-F8-088 `NO_CHANGE_VERIFIED` | exact no-change; no coverage-file edit required |

- The following payloads are retained as exact historical applied/no-change text. Their dated command receipts prove closure; fresh supervisor reread controls later mutable coverage identity.
- Applied under command 000000024688 after UID0003F7 and before UID0003F9:

    - [UID:0003F8][0x00624bf0-0x00624c00.GroupPaneRectConstant](by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md) 0x00624bf0-0x00624c00 | source-local packed constant | GroupPaneRectConstant : reconstructable : 94% : very-strong : Exact unique [6,14,161,54] RectBounds image, sole 0x0056cf78 NewGroupPane::OnPaint movaps load, immediate typed stack-local store, 44-pixel row stepping, UID000090 position-76 covered-by route, and C++03 aggregate rowBounds reconstruction with no standalone object or H declaration; owning method source is corrected to the accepted EPFTileContext lifecycle, global GroupMemberRecord, partial HumanImageRenderParams, full NewHuman calls/member geometry, constructor-free RectBounds APIs, COMMA lookup, observed context reuse, and compile-visible dependency closure.

- Applied under command 000000024688 for UID0004Z5:

    - [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md) 0x0056ce50-0x0056da03 | virtual method | NewGroupPane::OnPaint : reconstructable : 94% : strong : Exact 2,995-byte primary paint override with completion-ready formal CPP covering normal/expanded backgrounds, six/12 member rows, global GroupMemberRecord access, binary-exact partial HumanImageRenderParams writes, full NewHuman bounds/draw calls and member geometry, names, HP/MP bars/numeric overlays, clipping and toggle rendering; six explicit EPFTileContext Initialize calls; accepted `.bounds`; frame-0 COMMA.EPF lookup; one reused tileContext; initialized-only scratch local; constructor-free RectBounds geometry; and direct UID0003F2/UID0003F8 source-use reconstruction, with complete NewHuman/Palette H ownership, singleton extern/definition separation, UID0000JS file-preamble closure, and no standalone pooled object.

- Applied under command 000000024689 for UID000090:

- [UID:000090][NewGroupPane](by-class/NewGroupPane.md) : reconstructable : 94% : very-strong : Group-owned main group-management pane with exact PanelPane inheritance and 0x110 layout, complete source-ready H, corrected UpdateRenderRegion and SetBounds slots, complete constructor/destructor/render/input/packet/scroll/layer/toggle inventory, resolved retained row/toggle geometry, hit-test, member-status and corrected OnPaint source role, exact twenty-one-method split plus UID0003F2 position-75 covered-by resource-literal child and UID0003F8 position-76 covered-by rowBounds child, three-facet vtable ABI, Group.cpp route, and class child-emitter topology.

- Applied under command 000000024692 for UID0000JS:

- [UID:0000JS][Group](by-file/Group.md) : reconstructable : 91% : very-strong : Group/social source root covering GroupListPane, GroupPane/GroupPane2, fully resolved NewGroupPane and ScrollNewGroupPane families, exact packet/layout/render/input/scroll behavior, GroupMemberMarkers, shared scrollbar constants, retained helper/source-lowering evidence, exact pooled GROUP.EPF/UID0003F2 routing, UID0003F6 inline scale, UID0003F8 aggregate rowBounds through UID000090 position 76, and corrected NewGroupPane::OnPaint lifecycle/resource/global-record/partial-descriptor/full-NewHuman-call/constructor-free geometry source with explicit compile-visible dependencies, without named pooled objects, handwritten compiler vtables, or broad-range duplication.

- Applied under command 000000024688 for UID0001HC:

    - [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md) : non-reconstructable : 92% : very-strong : Non-emitting physical split index over GroupPane, GroupPane2, and NewGroupPane; live IDA resolves every modeled body, dedicated paint routes, retained raw helpers, exact roles/layout, pooled resources, twenty-one NewGroupPane child ranges, UID0003F6 inline scale, UID0003F8 aggregate rowBounds [6,14,161,54] and 44-pixel stepping, and NewGroupPane::OnPaint's six initializers, COMMA lookup, `.bounds`, shared context, global row type, exact partial descriptor writes, full NewHuman calls, and member geometry, plus every padding/compiler boundary without conflating the aggregate with source C++.

- Applied under command 000000024688 for UID0002V2:

        - [UID:0002V2][0x00624788-0x00624c60.LookGroupCollectionResourceStringData](by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md) 0x00624788-0x00624c60 | resource-string-data | LookGroupCollectionResourceStringData : not-reconstructable : 88% : very-strong : Exact multi-owner resource/constant island ends before the SimpleListPane primary complete-object-locator pointer at 0x00624c60; no-owner/non-emitting disposition is unchanged, and the exact child inventory includes shared UID0003EV COMMA.EPF with its Group frame-0 lookup, UID0003F7/UID0003F9 SelfLook rectangles, UID0003F6 NewGroupPane scale, and UID0003F8 NewGroupPane local rowBounds [6,14,161,54] through UID000090 position 76.

- Applied under command 000000024688 for UID0003EV after the then-current UID0003EU row and before UID0003EW; the dated pre-closure receipt had shown UID0003EV absent:

            - [UID:0003EV][0x006247f0-0x00624804.SharedCommaEpfResourceString](by-memory/0x006247f0-0x00624804.SharedCommaEpfResourceString.md) 0x006247f0-0x00624804 | pooled shared resource literal | SharedCommaEpfResourceString : not-reconstructable : 85% : strong : Exact L"COMMA.EPF" UTF-16 item at 0x006247f0 with three direct consumers in SelfLookPane, NewGroupPane, and UserStatus2Pane; NewGroupPane::OnPaint pushes the literal at 0x0056cf1b and performs the frame-0 lookup at 0x0056cf20 into an explicitly initialized EPFTileContext before background rendering, with no later direct read of that output; pooled ownerless/non-emitting disposition and blank formal source remain unchanged.

- UID0000FQ manual by-class coverage disposition is `NO_CHANGE_VERIFIED`. At the dated drafting receipt its exact row was line 591, 4,934 characters, UTF-8 line SHA256 64BDC331D87D13F5A95D62626AED53CCE44F8A1919A25A0A0178D56445636F12, anchored by `- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 94% : very-strong :`. Supervisor closure confirmed that row already described the complete managed H and extensive consumer/layout history; the narrow `friend class NewGroupPane;` access grant changed neither behavior, layout, ownership, score, nor coverage summary.

- Exact UID0000FQ no-change row quoted verbatim from that dated receipt:

- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 94% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external ProcessMovement and event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, signed plain-char StartDirectionalAnimation(char direction) with signed-short frame-duration/MonsterObject image-table and signed non-monster scaled-delay contracts, 52 exact 508-byte inventory records with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, exact player-settings semantics comprising state[0] feature/UI mode, state[2] viewport-threshold mode, state[3] direction mode, state[4] MapPane-render blindness with bounds invalidation, and state[5]/[6] chat display/send restriction levels, the distinct movement-state index-3 pending-reply flag versus index-4 direction-delay state, source-ready opcode-0x05 HandleServerEntryPacket declaration, exact EventHandler HandleKeyOrTextEvent(Event *) override, six resolved B003 target/helper declarations, preserved current B002 UID0004R9 child, int say-mode/collection-panel-sound/three-debounce/input-lock field splits, exact 0x20c base boundary, class closure before child definitions, exact records/size guards, preserved full unrelated field/record/layout/source surface, exact final-byte plus 68-byte m_currentAppearance tail used by MapPane local-player status updates, and UID0003UB's retained ExecuteHotkeyAction(short) declaration plus exact three-page 30-row Text/Spell/Item runtime behavior; the complete Config declaration exposes direct macro and compact tables; UID0003UA emits exact retained compact-shortcut source while UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; retains exact private IsGroupMember(unsigned int) const and AdvanceMovementSendTick() declarations over the existing signed group count, GroupMemberRecord table, movement tick, TimerMgr, and BowGauge state; adds exact +0x3cb1 hunters-list flag, +0x3cb2 wchar_t[256] party-search source text, two residual bytes, and four inline cross-source accessors in place of only the former opaque 0x203-byte slice; adds the public inline const GetSpellPromptText(char) accessor over the exact 52-entry SpellCommandSlotRecord table, preserving the 0x148 record, +0xa8 prompt, one-based signed index arithmetic, complete 0x13eb84 layout, and every existing UserPane declaration/field/method/history fact; exposes complete-object +0x210 as LineInputPane *m_activeLineInputPane with inline ClearActiveLineInputPane(), four-byte state on each side, all later offsets and sizeof(UserPane)==0x13eb84 preserved, with UID00035P as the sole non-null typed writer and UID00035Y/UID000364/UID00036C plus derived input-pane handlers as exact clear consumers; the earlier pending-target ObjectPane interpretation is retained only as disproved history because target-selection objects remain separate from the cleared slot; preserves the exact ClearDeferredUserListPacket declaration/source child that frees and clears only the deferred packet pointer, packet tick, and defer-until tick while preserving size, skip-next state, complete layout, and the full current UserPane union; replaces SpellCommandSlotRecord reserved bytes +0x08..+0xa7 with exact wchar_t displayName[80], retains prompt[80] at +0xa8 and sizeof 0x148, and adds bounded WillBeChangedSpellPane friendship for the existing one-based private record accessor without changing any other declaration, offset, guard, score, owner, or route. UID0003ZT confirms MapPane +0x418 is source-typed UserPane * because UID0003ZS calls UserPane-only ProcessMovement twice; UserPane.h exports the complete UserPane declaration plus g_pUserPane and g_pInputBlockerPane extern contracts while their definitions remain singular. UID000415 resolves List *m_chatHistory at +0x13eb04 and the exact GetPreviousChatHistoryLine, GetNextChatHistoryLine, and SaveChatHistoryLine members at 0x005a4930, 0x005a4990, and 0x005a49e0, including signed-short cursor wrap, bounded wide copies, newest-boundary empty result, duplicate suppression, ten-line cap, canonical g_pUserPane callers, and unchanged adjacent recipient-history fields. UID0003VD adds exact virtual bool OnTimer(int timerId, int arg0, int arg1), moves the complete class/inline/member declaration from formal CPP to formal H, preserves those UID000415 chat-history declarations and field, replaces the five-byte movement array and two-byte history array with size-neutral named reply/direction state, retains sizeof(UserPane)==0x13eb84, and routes the sole complete OnTimer definition through the exact child into UserPane.cpp.

- Applied under command 000000024690 for UID00050M in by-type/by-struct coverage:

- [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) : reconstructable : 94% : very-strong : Exact packed 0x40 NewHumanImageLib render descriptor and ObjectStatusBlob prefix with every member, alias, padding byte, riding field, color byte, and final invisible flag mapped through +0x3f; four consecutive 0x10-byte copies at 0x004e21d0 prove size, selector and NewHuman draw/bounds consumers prove offsets, a period-compatible size guard closes ABI, formal H emits through UID0000LR NewHumanImageLib.h, and NewGroupPane::OnPaint independently proves binary-exact partial initialization through the declared m_* fields with no Reset call, no whole-object clear, zero colors for absent equipment, 0xffff absent IDs, and untouched fields preserved.

- Applied under command 000000024690 for UID0001VF in by-type/by-struct coverage:

- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) : reconstructable : 92% : very-strong : Exact dependency-complete NewHumanImageLib H layout emitted at position 10 after HumanImageRenderParams and before the class: 0x44 NewHumanPartEntry, 0x20 NewHumanLayerEntry, packed 0x42 NewHumanMotionEntry, 0x50 NewHumanCompositionDrawCommand, three-byte Acc2DrwEntry, packed 0x20 descriptor, inline 0x10 sequence table, packed 0x09 sequence frame, and C++03 size guards; ImageFrameTable.h remains the sole FrameDrawRecord/RectBounds owner and Surface.h remains the sole SurfaceSpriteBlitOptions owner, while only pointer/reference-only types remain forward-declared. Constructor/destructor/loaders/vector helpers and live BuildComposition evidence agree on every width/offset; inferred original private names remain the confidence cap.

- UID0000UN by-item coverage is `NO_CHANGE_VERIFIED`: the exact ImageFrameTable row remained the sole complete ImageFrameTable.h declaration owner consumed by include. Dated drafting-row SHA256 D52718FADE48A57885C85FF881950686A19C221149F2FD3841D61E8E090BECE3.
- UID0000TN by-global coverage is `NO_CHANGE_VERIFIED`: the exact Surface row remained the sole complete Surface.h options/callback owner consumed by include. Dated drafting-row SHA256 923FFBC2DF4508DD79DAC40B1833257C5FADEAAFF05CFDD1946D58469CD54505.

- Applied under command 000000024689 for UID000092 in by-class coverage:

- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) : reconstructable : 90% : very-strong : Singleton new-human composition/render class with exact 0x60 LObject layout, constructor/destructor/resource/vector method families, complete NewHumanImageLib.h class declaration at position 20 after UID00050M position 5 and UID0001VF's dependency-complete position-10 nested rows, declarations for every currently emitted exact child plus full CalculateBounds and Draw public contracts, C++03-complete std::vector elements, pointer-only command-side deque, one position-30 g_pNewHumanImageLib extern, source-ready lifecycle/loaders, typed 80-byte composition-draw commands, exact ResolveCompositionPartRect/ResolveCompositionPartFrame contracts, and Group rendering as a full-argument consumer; formal CPP retains ImageFrameTable.h plus child emission only, while the sole singleton definition remains on UID0000RT.

- Applied under command 000000024691 for UID0000RT in by-global coverage:

- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) : reconstructable : 90% : very-strong : NewHumanImageLib singleton pointer at 0x0067a760 with exact saved name/type, constructor publish, destructor and cleanup-helper clears, zeroed storage bytes, 52 xrefs, shutdown access, representative render/look/profile consumers, old-human singleton separation, exact storage evidence UID0001OV, one compile-visible extern immediately after the complete UID000092 class declaration in NewHumanImageLib.h, and one preserved zero-initialized CPP definition through UID0000LR.

- Applied under command 000000024689 for UID0000A1 in by-class coverage:

- [UID:0000A1][PaletteLib](by-class/PaletteLib.md) : reconstructable : 92% : very-strong : Complete 0x25c8 LObject plus Singleton<PaletteLib> declaration with +0x04 empty-base PMD/EBO, exact mode/list/three embedded palette/25-pair bank/filter/seven-pair super-palette layout, natural bool-to-float alignment, constructor/destructor/source-versus-compiler lifetime, text-palette accessor semantics, full public/private method declarations including GetPaletteByName, helper declarations, and one external g_pPaletteLib declaration; the entire declaration block is emitted once in PaletteLib.h at UID0000A1 position 10, formal CPP retains children only, and the sole singleton storage definition remains UID0000RW.

- Applied under command 000000024691 for UID0000RW in by-global coverage:

- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) : reconstructable : 92% : very-strong : Sole source definition for PaletteLib *g_pPaletteLib at exact storage UID00028T/0x0067a7e0, with zero initializer, complete 83-xref inventory, RTTI-proven LObject and Singleton<PaletteLib> inheritance, +0x04 PMD publication/clear lifetime, 0x25c8 complete object layout, constructor/destructor/EH/scalar/vtable/compiler split, focused UID0000MB PaletteLib.cpp ownership, one compile-visible extern immediately after the complete PaletteLib.h class declaration, and duplicate-storage/declaration rejection.

- Row-specific dated drafting anchors were: UID0001VF row SHA256 018FCD29ECD1A19B7E0E040D5AC22A868F321CBB8E9B9B38571DD8E31EF281EE; UID00050M row SHA256 E21A2898C2777F067A18E7EA2D53CFC85474D96037C53963D8694DC458682A8B; UID000092 962A9510A156D47C11FFECDA51A432DA5B344FDCF618B14B6A1023D80AAFF5ED; UID0000RT C3768BA5BF9F7A57793A4DA3B62BC404EE9C069A9C4F7D6CA81410FF99770131; UID0000A1 B9EA01F376E660E37A6D76BE1FF53A94661E24DA972692D89ED967F25D0F2EBE; UID0000RW B063334A846E0DC14FCDF23D1B5FA18AC594B1CA7763A187E6E3D06A28A5919A. UID0003EU/UID0003EW neighbor line hashes were 5030B4D61C946D99DC3FC2531D5B99AF87E75C44FC4D105CFB44A2EA4BF4E0C8 and 67EE0B7971D6F70D9E6EAF3892A90874391722DC8C8B412094B6BEFDFAD53688. These hashes identify historical source rows used to construct the applied payloads.
- Dated supervisor commands 000000024688..000000024692 applied or no-change verified every Section 28 payload. Generated tracker/coverage authority remains validator-owned and is reread dynamically.

## Follow-Up Actions

- The ordinary callback is complete: all target/support changes listed in Section 25 were applied, scoped-validated, and physically checked in Group.cpp/.h, NewHumanImageLib.cpp/.h, PaletteLib.cpp/.h, and UserPane.h.
- Dated supervisor closure applied or no-change verified manual coverage claims C-F8-039..044, C-F8-065..071, and C-F8-087..089. Section 28 retains exact payloads, no-change dispositions, command receipts, and dynamic-authority wording.
- Dated Gate 2B applied IDA claim C-F8-036 and no-change verified C-F8-037/038. Section 21 retains the accepted contracts, backup/save identity, and achieved readbacks.
- Report execution/archive state is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Confidence

- Range/layout/xref/load/store/function/vtable/neighbor: very strong.
- Local/no-object source disposition: very strong.
- Class/position/score: strong.
- rowBounds spelling: strong inference.
- Six explicit initializers, accepted `.bounds`, COMMA lookup, and stack-slot reuse: very strong.
- Global GroupMemberRecord, partial descriptor writes, absent Reset, full NewHuman call order, member rectangle geometry, and RectBounds API constraints: very strong.
- Complete PaletteLib H relocation/singleton split: very strong because the exact accepted declaration block was moved to H, the sole CPP definition was preserved, and the generated channel split was physically verified. Complete NewHuman H ownership: strong because exact five-vector-element layouts, descriptor/sequence support, current existing-owner by-value dependencies, emitted child definitions, exact 0x60 layout, live profiles, and accepted public consumers converge, while some private lexical spellings remain inferred.
- `commaFrame`/`scratchContext`/parameter spellings, const qualifiers, and initialized-only intent: strong inference; this caps UID0004Z5 confidence at 93 but blocks neither behaviorally exact source nor callback.

## Validator Results

- Dated pre-callback command 000000024431 (2026-08-15T19:57:54-04:00) remains historical defect evidence: Group.cpp SHA E20A024A85200385B2F463AA5A878F96FA232C0D2971C8EF54859E551FB3E795, 52,510/1,432; Group.h SHA 7873C2BC4927FF0EB066673B721A24540ED4A97E3F2775051C7397F22D31920A, 1,851/50; EPFTileContext.h SHA DE96336BF1B08954155EC8263445473A5885C5FBF55FEEB116A899384207DF9F, 1,199/39.
- Exact callback working directory for every command below: `E:\NTK\GhidraBridge\source-3\project-documentation`. Every command exited 0 with `ok: 1`, completed foreground generated refresh because `--wait-generated` was supplied, and produced validator-owned registry/statistics/autogen side effects; none directly edited generated files.

| Command ID / timestamp | Exact scoped command | Command-specific result and diagnostics |
|---|---|---|
| 000000024624 / 2026-08-16T01:01:43-04:00 | `python .\tools\validator.py --mode file --file by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md --apply --queue-timeout 240 --wait-generated` | target accepted at 94/94 with UID000090 position 76 and covered-by CPP; no target-specific warning/error |
| 000000024625 / 2026-08-16T01:04:37-04:00 | `python .\tools\validator.py --mode file --file by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md --apply --queue-timeout 240 --wait-generated` | corrected OnPaint CPP accepted at 94/93; no target-specific warning/error |
| 000000024626 / 2026-08-16T01:05:47-04:00 | `python .\tools\validator.py --mode file --file by-class/GroupListPane.md --apply --queue-timeout 240 --wait-generated` | eight-line Group.cpp preamble carrier accepted; no target-specific warning/error |
| 000000024627 / 2026-08-16T01:06:54-04:00 | `python .\tools\validator.py --mode file --file by-class/NewGroupPane.md --apply --queue-timeout 240 --wait-generated` | position-76 child/support closure accepted; no target-specific warning/error |
| 000000024628 / 2026-08-16T01:08:13-04:00 | `python .\tools\validator.py --mode file --file by-file/Group.md --apply --queue-timeout 240 --wait-generated` | first owning-file refresh accepted; later command 24642 is the definitive callback snapshot |
| 000000024630 / 2026-08-16T01:12:09-04:00 | `python .\tools\validator.py --mode file --file by-memory/0x0056c4c0-0x0056e939.GroupPanes.md --apply --queue-timeout 240 --wait-generated` | aggregate evidence accepted; no target-specific warning/error |
| 000000024632 / 2026-08-16T01:13:42-04:00 | `python .\tools\validator.py --mode file --file by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md --apply --queue-timeout 240 --wait-generated` | route refinement accepted; validator normalized/inserted UID links for existing UID0003F7 and UID0003F9 references |
| 000000024633 / 2026-08-16T01:14:19-04:00 | `python .\tools\validator.py --mode file --file by-memory/0x006247f0-0x00624804.SharedCommaEpfResourceString.md --apply --queue-timeout 240 --wait-generated` | COMMA lookup evidence accepted; no target-specific warning/error |
| 000000024634 / 2026-08-16T01:16:18-04:00 | `python .\tools\validator.py --mode file --file by-class/UserPane.md --apply --queue-timeout 240 --wait-generated` | friendship/global-record detail accepted; existing unrelated missing-reference diagnostics for UID0003V8 and UID0003VC remained |
| 000000024635 / 2026-08-16T01:16:54-04:00 | `python .\tools\validator.py --mode file --file by-type/by-struct/HumanImageRenderParams.md --apply --queue-timeout 240 --wait-generated` | exact partial-write/no-Reset consumer accepted; no target-specific warning/error |
| 000000024636 / 2026-08-16T01:20:39-04:00 | `python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240 --wait-generated` | complete eight-layout H and size guards accepted at 92/93; no target-specific warning/error |
| 000000024637 / 2026-08-16T01:21:21-04:00 | `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | initial complete class-H validation passed; physical order exposed the need for an explicit child insertion marker |
| 000000024638 / 2026-08-16T01:22:14-04:00 | `python .\tools\validator.py --mode file --file by-global/g_pNewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | H extern/sole CPP definition route accepted at 90/93; no target-specific warning/error |
| 000000024639 / 2026-08-16T01:23:40-04:00 | `python .\tools\validator.py --mode file --file by-class/PaletteLib.md --apply --queue-timeout 240 --wait-generated` | class/helper H relocation accepted; existing unrelated missing-reference diagnostic for UID0003MT remained |
| 000000024640 / 2026-08-16T01:24:16-04:00 | `python .\tools\validator.py --mode file --file by-global/g_pPaletteLib.md --apply --queue-timeout 240 --wait-generated` | H extern/sole CPP definition route accepted; no target-specific warning/error |
| 000000024641 / 2026-08-16T01:25:40-04:00 | `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | explicit H `[[CHILDREN]]` insertion point accepted; generated rows-before-class order verified |
| 000000024642 / 2026-08-16T01:26:49-04:00 | `python .\tools\validator.py --mode file --file by-file/Group.md --apply --queue-timeout 240 --wait-generated` | definitive owning-file refresh accepted; complete callback generated readback below passed |

- Dated command-24642 generated identities: Group.cpp `99F6ABDEEC53D37650EE2BF3EA932C875BD02AC02F8DD86B6759109BCE542C6A`, 54,295 bytes / 1,486 lines; Group.h `BF4E00E4538FD658A8F5BD125F00A45BE3EDBC6DAFE17C432309B9AAD9412653`, 1,851/50; NewHumanImageLib.cpp `F3825BBC180A9633D784DFFA7E75B382260FDC1FF17CB8E06D947E8531C50B3F`, 43,908/1,107; NewHumanImageLib.h `67D05E1980101B6BEE91D3712FD501DDD022C4B267A6AA818FEAC358BA5EE523`, 8,440/260; PaletteLib.cpp `7783CB53E3C1DB2D22BAAEC918AB3D7A6343BB7FDFA7E9A0B027A3294FD4F443`, 3,633/97; PaletteLib.h `711AAF78B884FB9454BBD4E3257648E6C8F6BC85C95DE30C9227D4EBE70D9DCF`, 1,951/58; UserPane.h `B868F30236990911613605783F1AE84A15F9EBC976DED05B9695C1277147AD97`, 11,646/349.
- Physical generated readback passed the complete contract. Group.cpp has the exact eight-line preamble before children, one target covered-by marker, no target empty marker, and one corrected NewGroupPane::OnPaint with six Initialize calls, method-local `.bounds`, one COMMA frame-zero lookup, one reused tileContext across non-overlapping phases, global GroupMemberRecord, exact partial descriptor writes, no Reset/unprefixed descriptor fields, full NewHuman calls, and no RectBounds constructor/Width/Height. Two unrelated older GroupPane/GroupPane2 `.m_bounds` uses remain outside this method. NewHumanImageLib.h order is UID00050M, UID0001VF rows, UID000092 class, UID0000RT extern; every required row/guard occurs once, pointer-only forward declarations remain legal, and no class/global duplicates occur. PaletteLib.h has one complete class plus the UID0000RW extern; PaletteLib.cpp preserves the sole global definition and contains no class declaration. UserPane.h contains the NewGroupPane forward/friend declarations.
- Fresh read-only continuity at validator command 000000024668, refreshed 2026-08-16T01:38:06-04:00, preserved every size/line count and source invariant while advancing metadata-line hashes: Group.cpp `88BBAC039B6405761AF527C4B18A939375651F2D5E92D46653658DB547ADA3CB`; Group.h `18D21DBE48DFC38221E217A7B77361A3C23F976941F84919B519790755F33035`; NewHumanImageLib.cpp `596B17263D2E8EC0C2F9475BB1831D85BBDA0A9093ABAA2B54DE9B04AC75D4CF`; NewHumanImageLib.h `5FC6435ECC1A4346509F297F59ABDEACAC6BF0F1B98E1B4712D0E1AC6F423518`; PaletteLib.cpp `ECAF65FE509379ADF4069D576FBAF2714BE9254F05F3B8A774E8AFA8EF631475`; PaletteLib.h `321D08C130640C00D7DC41D1237519FD3B7B714FEE899C2D1A43CF83D2BD5773`; UserPane.h `40264E53FF11722B85472947E4D58F7B9137983616D6DFEBC93922434CE8461C`. This is a dated continuity receipt, not permanent authority.
- Dated supervisor Gate 2A generated readback at validator command 000000024682 passed the report contract: Group.cpp `D47C02567E488D08F8FFFB7F7C884981C1BA2F604CA9826A6AA56BCFD8CF5410`; Group.h `5830A1BA5E04169328CCE873B83AA7E1B96139A7767BE5BB4B7D3C95E887E45B`; NewHumanImageLib.cpp `F19609E6038B8830D674986BF0B0455A30B5E89AEC25F0882E90891B3ED98D43`; NewHumanImageLib.h `3BA183447C3AB345D88363EE210AF501FB73EE3F64D7A37999A102A3911694B4`; PaletteLib.cpp `2D26CC0DB312B59884E6915252AB3B24EF670B9B75EC661505E22BAF5E7C4DDC`; PaletteLib.h `1D147A50389C0C0FF397E7FB010B4FF71FA41889FD47354CF12A3D18E3542B0C`; UserPane.h `2A0728D6E72C6BF6037A09E331D57F800742FE7B52EC684319E2AB4B59480B15`.
- Dated supervisor manual-coverage validation receipts: command 000000024688 by-memory, 000000024689 by-class, 000000024690 by-type/by-struct, 000000024691 by-global, and 000000024692 by-file each exited 0 with `ok: 1`. Exact post-command hashes/sizes/lines and claim dispositions are recorded in Section 28. UserPane, ImageFrameTable, and Surface coverage were exact no-change.
- Generated and coverage authority are mutable validator outputs. Commands 24642/24668/24682 and 24688..24692 are historical callback/continuity/closure receipts; a fresh supervisor reread controls after coherent later refreshes.

## Changed Files

- Modified ordinary by-* pages: UID0003F8, UID0004Z5, UID00005X, UID000090, UID0000JS, UID0001HC, UID0002V2, UID0003EV, UID0000FQ, UID00050M, UID0001VF, UID000092, UID0000RT, UID0000A1, and UID0000RW at the exact applied hashes in Supporting Research.
- Modified additively after those ordinary callbacks: this same report, preserving all accepted research and formal source while reconciling receipts and twins.
- Lease receipts: every ordinary destination was leased for its bounded edit/validation batch and released. Fourteen leases preceded their edits; the UID0001HC/GroupPanes lease was acquired immediately after a premature local patch and before validation, with no conflicting owner, then released. Current lease state contains no B003/UID0003F8 entry.
- Validator-owned generated, registry, statistics, and auto-generated report side effects occurred through the scoped commands above; generated files were never edited directly. Dated supervisor closure later applied/verified the five manual coverage files and the IDA-F8 transaction outside B003's write scope. This reconciliation edits only this report and does not mutate those authorities, shared audit/catalog, goal/notes, or lifecycle state.
- Report execution/archive state is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.
- Report hygiene: no executable automation package; exactly one terminal workflow-control marker follows the checklist.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|---|
| [x] | C-F8-001 | 0003F8 | Target is [0x00624bf0,0x00624c00), size 16, SHA256 A9CB5BAE7A86BEF48A98DBDFA3BFD6919991F1731C183BF87B24B99C675E03B6. | very-strong | live item/bytes | UID0003F8 range | incorporate | applied |
| [x] | C-F8-002 | 0003F8 | IDA name xmmword_624BF0; type, AR, AP absent; FR/FP not applicable. | very-strong | live item/comments | UID0003F8 IDA state | incorporate | applied |
| [x] | C-F8-003 | 0003F8 | RectBounds decodes left=6, top=14, right=161, bottom=54. | very-strong | live struct read | UID0003F8 behavior | incorporate | applied |
| [x] | C-F8-004 | 0003F8 | Exact 16-byte sequence occurs once in the loaded image. | very-strong | byte search | UID0003F8 uniqueness | incorporate | applied |
| [x] | C-F8-005 | 0003F8 | One inbound xref at 0x0056cf78; no outbound or tested interior xrefs. | very-strong | xref inventory | UID0003F8 xrefs | incorporate | applied |
| [x] | C-F8-006 | 0003F8 | VA search finds only operand at 0x0056cf7b; RVA/raw-offset searches add no route. | very-strong | pointer searches | UID0003F8 liveness | incorporate | applied |
| [x] | C-F8-007 | 0004Z5 | Load [0x0056cf78,0x0056cf7f), bytes 0F 28 05 F0 4B 62 00, SHA 4BCCE14AA114D95AE3A8C37260C49D33130BC9852A2209FE89B19BF62447DF60. | very-strong | instruction/bytes | UID0004Z5 provenance | incorporate | applied |
| [x] | C-F8-008 | 0004Z5 | Store [0x0056cf8b,0x0056cf92) writes bounds.left; SHA 1E43E29EA20CA9929F7ED191980A599A9D1B2AC862EFFD811BD2B75FA5B6FC6B. | very-strong | disassembly/frame | UID0004Z5 local init | incorporate | applied |
| [x] | C-F8-009 | 0003F8 | RectBounds is four int fields at 0,4,8,0xc. | very-strong | UDT/UID0001VP | UID0003F8 type | incorporate | applied |
| [x] | C-F8-010 | 0004Z5 | NewGroupPane__OnPaint is [0x0056ce50,0x0056da03), SHA D3FB87AF11A14632F0BC954B387ECC83DBAC01D423426E1DECC7E55A2ABD960C, typed, 728 instructions/56 blocks/19 callees/0 code callers. | very-strong | function profile | UID0004Z5 identity | incorporate | applied |
| [x] | C-F8-011 | 0004Z5 | Vtable cell 0x00624598 uniquely routes to 0x0056ce50; SHA 0670DADBA6165B99082256465ECBD290347CC782CA53FBFEFBFC4E373C556803. | very-strong | vtable/xref | UID0004Z5 virtual route | incorporate | applied |
| [x] | C-F8-012 | 0004Z5 | Frame contains bounds : RectBounds at offset 0x1d8 and receives the packed value. | very-strong | frame/store | UID0004Z5 local model | incorporate | applied |
| [x] | C-F8-013 | 0004Z5 | Expanded mode adds 5 to X edges; loop adds 44 to Y edges; modes render 6/12 rows; one 0x28-byte tileContext slot is reused across background, row, and toggle phases. | very-strong | full method/frame | UID0004Z5 geometry/lifetimes | incorporate | applied |
| [x] | C-F8-014 | 0003F8 | Human source is `RectBounds rowBounds = { 6, 14, 161, 54 };`; current RectBounds has no constructor. | strong | lowering plus authoritative H | UID0003F8 source | incorporate | applied |
| [x] | C-F8-015 | 0003F8 | Standalone global/static/member/array/table emission is invalid. | strong | sole local use | UID0003F8 negatives | reject-invalid | reject-invalid |
| [x] | C-F8-016 | 0003F8 | Canonical owner changes UID0000JS -> UID000090. | strong | method/class route | UID0003F8 metadata | incorporate | applied |
| [x] | C-F8-017 | 0003F8 | Emitter changes to UID000090 position 76. | strong | positions 70/75/80 | UID0003F8 metadata | incorporate | applied |
| [x] | C-F8-018 | 0003F8 | Score changes 85/88 -> 94/94 only after UID0004Z5 body plus record/descriptor/NewHuman nested-row/Palette/RectBounds/include dependencies are corrected together; inferred rowBounds spelling/pooling caps confidence at 94. | strong | physical and dependency-complete declaration closure | UID0003F8 metadata | incorporate | applied |
| [x] | C-F8-019 | 0003F8 | Formal CPP is exact Section 22 covered-by marker. | very-strong | no-duplicate route | UID0003F8 CPP | incorporate | applied |
| [x] | C-F8-020 | 0003F8 | Formal H remains blank. | very-strong | no declaration | UID0003F8 H | incorporate | applied |
| [x] | C-F8-021 | 0003F8 | Prose/summary preserve complete evidence and rejected forms. | very-strong | report evidence | UID0003F8 prose | incorporate | applied |
| [x] | C-F8-022 | 0004Z5 | Replace the invalid/partial formal CPP with Section 22's declaration-compatible body: six Initialize calls, `.bounds`, COMMA lookup, reused tileContext, global GroupMemberRecord, exact partial m_* descriptor writes, full NewHuman calls, and constructor-free RectBounds geometry. | very-strong | live disassembly/frame plus authoritative headers | UID0004Z5 CPP/prose | incorporate | applied |
| [x] | C-F8-023 | 0004Z5 | Keep completion 94, owner UID000090, position 70, TRUE, and blank H; correct confidence 95 -> 93 for inferred local spellings and initialized-only scratch-context intent. | strong | exact behavior plus lexical/intention cap | UID0004Z5 metadata | incorporate | applied |
| [x] | C-F8-024 | 000090 | Add UID0003F8 position-76 child; preserve complete class and 94/95. | strong | class topology | UID000090 inventory | incorporate | applied |
| [x] | C-F8-025 | 000090 | No duplicate class/member declaration or score change. | very-strong | complete class | UID000090 H/metadata | incorporate | applied |
| [x] | C-F8-026 | 0000JS | Literal split audit closes UID0003F8 through UID000090 into Group.cpp; incorporate the corrected UID0004Z5 body and explicit UserPane/NewHuman/Palette/ImageLib/Surface/Win32/CRT include dependencies while keeping 91/88 because unrelated historical partition questions gain no new evidence. | strong | sole target route and complete dependency audit | UID0000JS topology/source | incorporate | applied |
| [x] | C-F8-027 | 0000JS | No file-level rectangle or tile-context object is emitted; source changes flow through the UID000090 class child and shared resource/type dependencies retain their own owners. | very-strong | emitter graph | UID0000JS source policy | incorporate | applied |
| [x] | C-F8-028 | 0001HC | Keep 92/94 FALSE/non-emitting; add UID0003F8 provenance and corrected UID0004Z5 initializer/resource/context-lifetime facts. | strong | physical split/full method | UID0001HC inventory | incorporate | applied |
| [x] | C-F8-029 | 0002V2 | Keep 88/92 ownerless FALSE/non-emitting, preserve the current complete island/SimpleList boundary prose, and refine UID0003F8 from direct Group-file assignment to UID000090 position 76 -> UID0000JS. | strong | current multi-owner child inventory | UID0002V2 inventory | incorporate | applied |
| [x] | C-F8-030 | 0001VP | RectBounds layout already supplies four edges, Offset, and InitRectBounds; it has no constructor, Width, or Height, so Section 22 uses aggregate/direct arithmetic without changing this page. | very-strong | authoritative H plus binary calls | UID0001VP no edit | already-present | already-present |
| [x] | C-F8-031 | 0003F6 | Existing pooled 100.0 child already proves use-site policy. | strong | current formal/prose | UID0003F6 no edit | already-present | already-present |
| [x] | C-F8-032 | 0003F2 | Existing class position-75 pooled child supplies order precedent. | strong | current metadata | UID0003F2 no edit | already-present | already-present |
| [x] | C-F8-033 | 0003F8 | UID0003F7/UID0003F9 are separate SelfLookPane items; unchanged. | very-strong | boundaries/xrefs | boundary protection | already-present | already-present |
| [x] | C-F8-034 | 0003F8 | No padding, split, merge, resize, redefinition, or reclassification. | very-strong | exact item | range analysis | already-present | already-present |
| [x] | C-F8-035 | 0003F8 | Generic GroupPane/future-C++ wording becomes superseded history. | strong | closure | target history | historicalize | applied |
| [x] | C-F8-036 | 0003F8 | Supervisor Gate 2B applied the exact IDA-F8-01 AP provenance comment and verified the saved readback. | strong | dated Gate 2B backup/save/attestation and exact target readback | Gate 2B IDA-F8-01 | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-037 | 0004Z5 | Supervisor Gate 2B protected the exact function/frame, empty-inbound vtable, complete load/store code/data edges, and separately specified empty-xref padding items without change. | very-strong | dated Gate 2B literal no-change readback | Gate 2B IDA-F8-02 | already-present | NO_CHANGE_VERIFIED |
| [x] | C-F8-038 | 0003F8 | Supervisor Gate 2B rejected data rename/type/boundary/neighbor edits and verified both neighbors retained their literal states with empty outbound xrefs. | strong | dated Gate 2B target/neighbor no-change readback | Gate 2B IDA-F8-03 | reject-invalid | NO_CHANGE_VERIFIED |
| [x] | C-F8-039 | 0003F8 | Supervisor applied the exact target row to manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-040 | 0004Z5 | Supervisor replaced stale manual by-memory source-ready wording with the six-initializer, `.bounds`, COMMA, shared-context, global-record, partial-descriptor, full-NewHuman-call, constructor-free RectBounds, and UID0003F8 closure at completion 94. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-041 | 000090 | Supervisor preserved corrected virtuals, named pane-family topology, and class facts while adding the position-76 child to manual by-class coverage. | very-strong | dated command 000000024689 exit 0/ok:1 and by-class readback | by-class coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-042 | 0000JS | Supervisor preserved Group source-root detail, three GROUP.EPF uses, and retained helpers while adding UID0004Z5's complete lifecycle/resource/descriptor/API/header closure and UID0003F8 to manual by-file coverage. | very-strong | dated command 000000024692 exit 0/ok:1 and by-file readback | by-file coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-043 | 0001HC | Supervisor preserved all modeled bodies, dedicated paint routes, four retained raw helpers, exact roles/layout, padding, and compiler boundaries while adding UID0004Z5's complete initializer/resource/context/descriptor/API facts and UID0003F8 to manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-044 | 0002V2 | Supervisor preserved the corrected SimpleListPane COL boundary and ownerless/non-emitting state while adding the exact UID0003F8 child to manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-045 | 0003F8 | Callback generated readback proves the target covered-by marker and corrected UID0004Z5 body: six Initialize calls, accepted `.bounds` within the method, one COMMA lookup, one shared tileContext across non-overlapping phases, global GroupMemberRecord, no Reset or unprefixed descriptor fields, full NewHuman calls, no RectBounds constructor/Width/Height, and exact partial descriptor writes; generated NewHumanImageLib.h proves the complete nested-row/owner-order contract. | very-strong | physical generated Group.cpp/NewHumanImageLib.h readback | generated readback | incorporate | applied |
| [x] | C-F8-046 | 0003F8 | Scoped validators 24624-24628, 24630, and 24632-24642 completed with exit 0 and ok:1; dated callback generation at 24642 and fresh read-only continuity output at 24668 were physically reread. | very-strong | validator receipts plus dated and fresh physical generated rereads | Validator Results | incorporate | applied |
| [x] | C-F8-047 | 0003F8 | Fifteen ordinary by-* pages changed additively; validator-owned generated/statistics/registry side effects were not edited directly, and coverage/IDA/lifecycle state remained outside the callback. | very-strong | ordinary hashes, validator receipts, and changed-file audit | Changed Files | incorporate | applied |
| [x] | C-F8-048 | 0003F8 | Exactly 33 H2 headings, exact 90/90 twin parity, zero executable-script fences, and one terminal READY_FOR_SUPERVISOR_EXECUTE marker. | very-strong | final report self-audit | report hygiene | incorporate | applied |
| [x] | C-F8-049 | 00004I | Accepted EPFTileContext H is a 0x28-byte struct with `RectBounds bounds` and explicit `Initialize()`; it has no `m_bounds` and no constructor. | very-strong | formal H/generated header/current class docs | UID0004Z5 type dependency | already-present | already-present |
| [x] | C-F8-050 | 0004Z5 | Six explicit calls to EPFTileContext_Initialize occur at 0x0056ce8b, 0x0056cedf, 0x0056ceea, 0x0056cef5, 0x0056cf00, and 0x0056cf0b and must remain explicit source calls. | very-strong | scoped live insn query/disassembly/bytes | UID0004Z5 lifecycle | incorporate | applied |
| [x] | C-F8-051 | 0003EV | `L"COMMA.EPF"` at 0x006247f0 has three consumers; UID0004Z5's xref 0x0056cf1b feeds lookup 0x0056cf20 into initialized commaFrame before background rendering, with no later method read. | very-strong | live item/xrefs/decompilation | UID0004Z5/UID0003EV resource evidence | incorporate | applied |
| [x] | C-F8-052 | 0004Z5 | Human source uses one `tileContext` for non-overlapping background/member/toggle phases and five other initialized locals; `scratchContext` preserves the initialized-only slot, while the descriptor remains an unconstructed partially written packed local exactly as observed. | strong | full frame/write/use inventory and call order | UID0004Z5 formal CPP/source rationale | incorporate | applied |
| [x] | C-F8-053 | 0000FQ | `GroupMemberRecord` is global and `m_groupMembers[50]` is private; add `friend class NewGroupPane;` and use the global type without weakening field privacy. | very-strong | authoritative UserPane H plus direct binary field reads | UID0000FQ H/prose | incorporate | applied |
| [x] | C-F8-054 | 00050M | HumanImageRenderParams is packed 0x40 with m_* fields and no Reset; document UID0004Z5's exact partial writes, including zero body/weapon/shield/mantle/neck/shoes colors and invisible, and untouched-field set. | very-strong | authoritative H plus exact stack stores | UID00050M consumer evidence | incorporate | applied |
| [x] | C-F8-055 | 000092 | Install Section 22's complete NewHumanImageLib class declaration once at H position 20 after UID0001VF's exact position-10 complete row block; include every currently emitted child prototype, full CalculateBounds/Draw contracts, exact container members, and no standalone fragment. | strong | live profiles, exact child definitions, complete UID0001VF row layouts, accepted consumers | UID000092 formal H/API inventory | incorporate | applied |
| [x] | C-F8-056 | 0000RT | Add `extern NewHumanImageLib *g_pNewHumanImageLib;` to the NewHumanImageLib H channel while preserving the sole CPP definition. | very-strong | current global type/definition and 52 consumers | UID0000RT H | incorporate | applied |
| [x] | C-F8-057 | 0000A1 | Move the complete PaletteLib class/helper declaration block from formal CPP to formal H at position 10; UID0000A1 CPP retains only children, while UID0000RW alone owns the H extern and sole CPP definition. | very-strong | current complete class formal CPP, generated H absence, and singleton ownership | UID0000A1 CPP/H | incorporate | applied |
| [x] | C-F8-058 | 0000RW | Add `extern PaletteLib *g_pPaletteLib;` to PaletteLib H while preserving the sole CPP definition. | very-strong | current singleton type/definition and consumer set | UID0000RW H | incorporate | applied |
| [x] | C-F8-059 | 0000JS | Emit the exact eight-line Group.h/UserPane.h/NewHumanImageLib.h/PaletteLib.h/ImageLib.h/Surface.h/windows.h/wchar.h block before all Group.cpp children through the first UID00005X GroupListPane mechanical carrier; UID0004Z5 method CPP contains no includes. | strong | declaration-by-declaration compile audit, generated preamble readback, and emitter ordering | UID0000JS CPP preamble | incorporate | applied |
| [x] | C-F8-060 | 0004Z5 | NewHuman bounds/draw source uses full binary argument lists and exact memberBounds geometry; no shortened overload, Reset, member.bodyColor copy, or whole-struct clear is permitted. | very-strong | live calls 0x0056d1ba/0x0056d25a and stack writes | UID0004Z5 formal CPP/prose | incorporate | applied |
| [x] | C-F8-061 | 000092 | Formal CPP remains `#include "ImageFrameTable.h"` plus `[[CHILDREN]]`; formal H begins with an explicit `[[CHILDREN]]` insertion point followed by the one class declaration, so UID0001VF rows precede the class without a CPP-local duplicate. | very-strong | owner route, explicit child insertion point, and physical generated H order | UID000092 CPP/H ownership | incorporate | applied |
| [x] | C-F8-062 | 000092 | Physical NewHuman H order is exact: UID00050M first, UID0001VF complete nested rows at the explicit UID000092 child insertion point, UID000092 class next, and UID0000RT extern last; UID0001VF includes ImageFrameTable.h/Surface.h and UID000092 retains LObject/vector/deque dependencies. | very-strong | C++03 completeness audit and physical generated H readback | UID000092 H position/dependencies | incorporate | applied |
| [x] | C-F8-063 | 0000RT | UID0000RT remains the sole `NewHumanImageLib *g_pNewHumanImageLib = 0;` CPP definition and supplies exactly one extern immediately after UID000092's class. | very-strong | current global formal CPP/52 xrefs | UID0000RT CPP/H ownership | incorporate | applied |
| [x] | C-F8-064 | 0000RW | UID0000RW remains the sole `PaletteLib *g_pPaletteLib = 0;` CPP definition and supplies exactly one extern immediately after UID0000A1's class. | very-strong | current global formal CPP/83 xrefs | UID0000RW CPP/H ownership | incorporate | applied |
| [x] | C-F8-065 | 0000FQ | Supervisor verified manual by-class coverage needed no edit because the complete managed declaration row already covered the narrow friendship without changing score/layout/ownership/coverage conclusions. | very-strong | dated by-class closure readback and exact UserPane row comparison | by-class coverage no-change | already-present | NO_CHANGE_VERIFIED |
| [x] | C-F8-066 | 00050M | Supervisor replaced UID00050M in manual by-struct coverage with Section 28's exact row adding the NewGroupPane partial-write/no-Reset/no-whole-clear consumer while retaining 94%. | very-strong | dated command 000000024690 exit 0/ok:1 and by-struct readback | by-struct coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-067 | 000092 | Supervisor replaced UID000092 in manual by-class coverage with Section 28's exact dependency-complete-H/Group-consumer row at 90%. | strong | dated command 000000024689 exit 0/ok:1 and by-class readback | by-class coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-068 | 0000RT | Supervisor replaced UID0000RT in manual by-global coverage with Section 28's exact extern/sole-definition row at 90%. | very-strong | dated command 000000024691 exit 0/ok:1 and by-global readback | by-global coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-069 | 0000A1 | Supervisor replaced UID0000A1 in manual by-class coverage with Section 28's exact H relocation/CPP-children-only row at unchanged 92%. | very-strong | dated command 000000024689 exit 0/ok:1 and by-class readback | by-class coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-070 | 0000RW | Supervisor replaced UID0000RW in manual by-global coverage with Section 28's exact H-extern/sole-CPP-definition row at unchanged 92%. | very-strong | dated command 000000024691 exit 0/ok:1 and by-global readback | by-global coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-071 | 0003EV | Supervisor inserted Section 28's exact pooled COMMA.EPF row after UID0003EU and before UID0003EW in manual by-memory coverage. | very-strong | dated command 000000024688 exit 0/ok:1 and by-memory readback | by-memory coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-072 | 000092 | Completion/confidence changes 88/90 -> 90/91 only after UID0001VF's five complete vector elements and transitive by-value dependencies precede the complete class H; retained/non-emitting method-family spellings cap final confidence. | strong | complete class/child/layout/C++03 header audit | UID000092 metadata | incorporate | applied |
| [x] | C-F8-073 | 0000RT | Completion/confidence changes 88/92 -> 90/93 only with exact H extern plus preserved sole CPP definition. | strong | exact storage/lifecycle and declaration route | UID0000RT metadata | incorporate | applied |
| [x] | C-F8-074 | 0003F8 | Section 28 records dated file hashes, row line hashes, all requested support dispositions, and dynamic supervisor reread requirements without editing coverage. | very-strong | 2026-08-15 target plus 2026-08-16 dependency coverage rereads | coverage receipt inventory | incorporate | applied |
| [x] | C-F8-075 | 0001VF | Dated pre-callback formal H was blank and generated NewHumanImageLib.h omitted all five by-value vector element definitions; the callback historicalizes that defect by installing the complete UID0001VF H block. | very-strong | dated command 24570 baseline plus applied ordinary/generated readback | UID0001VF current state/history | historicalize | applied |
| [x] | C-F8-076 | 0001VF | Emit one complete nested-row H block at position 10 through UID000092 -> UID0000LR/NewHumanImageLib.h, after UID00050M position 5 and before UID000092 position 20. | very-strong | owner graph and declaration order | UID0001VF metadata/formal H | incorporate | applied |
| [x] | C-F8-077 | 0001VF | Define NewHumanPartEntry as exact 0x44 with partId, wchar_t name[20], drawIndexBase, descriptorBase, descriptorCount, rawRecordCount, frameDescriptors, and spriteArchive; guard sizeof 0x44. | very-strong | 68-byte loader/vector/destructor evidence | UID0001VF formal H/part layout | incorporate | applied |
| [x] | C-F8-078 | 0001VF | Define NewHumanLayerEntry as exact 0x20 with layerId, char name[20], childCount, and childIndexes; guard sizeof 0x20. | very-strong | 32-byte loader/vector/destructor evidence | UID0001VF formal H/layer layout | incorporate | applied |
| [x] | C-F8-079 | 0001VF | Define packed NewHumanMotionEntry as exact 0x42 with 23-byte prefix, motionId, name[20], two reserved bytes, direction, fallbackMotionId, frameCount, frameOffsets, and frameData; guard sizeof 0x42. | very-strong | live 0x004e0e20 offsets/66-byte copy | UID0001VF formal H/motion layout | incorporate | applied |
| [x] | C-F8-080 | 0001VF | Define NewHumanCompositionDrawCommand as exact 0x50 with partId, by-value FrameDrawRecord, by-value SurfaceSpriteBlitOptions, and DLPalette pointer; guard sizeof 0x50. | very-strong | live 0x004e21d0 plus 80-byte vector helpers | UID0001VF formal H/command layout | incorporate | applied |
| [x] | C-F8-081 | 0001VF | Define Acc2DrwEntry as exact three-byte bool enabled[3] row and guard sizeof 3. | very-strong | loader/grow/consumer stride evidence | UID0001VF formal H/accessory layout | incorporate | applied |
| [x] | C-F8-082 | 0001VF | Define packed NewHumanSequenceFrame 0x09, NewHumanSequenceFrameTable 0x10, and packed NewHumanPartFrameDescriptor 0x20 before NewHumanPartEntry so all already-emitted child bodies see complete descriptor/sequence types. | very-strong | UID00041C/000417/000437/000438 loader-consumer agreement | UID0001VF formal H/transitive internal layouts | incorporate | applied |
| [x] | C-F8-083 | 0000UN/0000TN | Include ImageFrameTable.h and Surface.h at UID0001VF position 10 so FrameDrawRecord/RectBounds and SurfaceSpriteBlitOptions remain defined once by their existing owners; do not duplicate these structs. | very-strong | current complete formal H/generated readback | UID0001VF dependency includes | incorporate | applied |
| [x] | C-F8-084 | 0001VF/000092 | Only GrafPort, Motion, NewHumanCompositionState, and NewHumanCommandSideRecord remain forward-declared; every use at class-declaration time is pointer/reference or deque-of-pointer and is C++03 legal. | very-strong | declaration-by-declaration completeness audit | UID0001VF/UID000092 C++03 rationale | incorporate | applied |
| [x] | C-F8-085 | 0001VF/000092/0000RT | Exact H insertion order is HumanImageRenderParams UID00050M position 5, nested rows UID0001VF position 10, class UID000092 position 20, and singleton extern UID0000RT position 30. | very-strong | owner/emitter dependency DAG | all four metadata/formal routes | incorporate | applied |
| [x] | C-F8-086 | 0001VF | Completion/confidence changes 87/90 -> 92/93 only with the exact complete formal H and size guards; inferred original private type/member spellings cap confidence. | strong | exact layouts plus source-name inference | UID0001VF metadata | incorporate | applied |
| [x] | C-F8-087 | 0001VF | Supervisor replaced stale manual by-struct coverage prose with Section 28's exact 92% dependency-complete H row. | very-strong | dated command 000000024690 exit 0/ok:1 and by-struct readback | by-struct coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-F8-088 | 0000UN | Supervisor verified manual by-item coverage needed no edit because the 90% row already documents the sole complete ImageFrameTable.h FrameDrawRecord/RectBounds owner used by include. | very-strong | dated exact ImageFrameTable coverage-row readback | by-item coverage no-change | already-present | NO_CHANGE_VERIFIED |
| [x] | C-F8-089 | 0000TN | Supervisor verified manual by-global coverage needed no edit because the 94% row already documents the sole complete Surface.h options/callback owner used by include. | very-strong | dated by-global closure readback and exact Surface row comparison | by-global coverage no-change | already-present | NO_CHANGE_VERIFIED |
| [x] | C-F8-090 | 0001VF/000092/0000RT | Post-callback and fresh continuity generated readbacks prove one definition of every nested row, exact size guards, no vector-element forward declaration, existing dependency types defined once, class after rows, extern after class, and no duplicate class/global definition. | very-strong | physical NewHumanImageLib.h/.cpp readbacks at commands 24642 and 24668 | NewHumanImageLib.h/.cpp readback | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000024694","destination_path":"executed-b-agent-research/B003/0003F8-GroupPaneRectConstant-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003F8-GroupPaneRectConstant-empty-emitter-source-quality.md","timestamp":"2026-08-16T03:06:28-04:00","uid":"0003F8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
