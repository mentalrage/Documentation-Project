** TARGET-REPORT-UID:0003RM **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003RM UserLookPane OnDraw Source-Quality Research

## Finalized Report / Current Recommendation
- The prior accepted OnDraw callback is complete. UID0003RM was UID-preservingly renamed from the behavior-only title `UserLookPaneRenderUserLook` to source-facing `UserLookPaneOnDraw`; it preserves exact range `[0x005a0640,0x005a157d)`, owner/emitter UID0000FP, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`, is now `93/94`, and contains Destination 1 byte-for-byte as complete `void UserLookPane::OnDraw()` source.
- The 3,901-byte function is live through primary UserLookPane vtable slot `+0x44`. It is ordinary source-authored rendering logic: one mode-selected background draw, complete mode-0 text/status/action rendering, fourteen mode-1 equipment-image branches, mode-2 portrait/fallback behavior, an intentionally empty mode-3 body, and a common previous/next navigation tail.
- UID0003RP `GetActionButtonRect` and UID0003RQ `HitTestActionButton` are complete `92/94` source helpers. The first owns the exact mode-dependent four-button geometry; the second is the human source factorization whose inlined binary copy scans ids 0 through 3 and uses vertical-first `PointInRect(y,x,...)`.
- UID0000FP and all directly affected support now use typed `m_nextButtonFrame`/`m_previousButtonFrame`; historical `m_hoverActionIndex`/`m_pressedActionIndex` labels are retained only as explicitly superseded evidence. Render reads and mouse writes independently prove normal/hover/pressed frame values 0/1/2. `m_portraitFallbackFrame` remains a bounded source-facing name: its only render use is an observed, result-unused `NATION.EPF` lookup after portrait drawing, so `nation frame` is a semantic gloss rather than stronger proof of original spelling.
- Preserve every odd observed behavior: the ignored mode-1 `GetVersionMajor` result, unknown-mode initialized-context blit with the EPF library pointer in the palette slot before returning, three independent length scans for each drawn text string, direct-fill button ordering, mode-2 options record with only byte-zero mode set, result-unused `NATION.EPF` lookup, and mode-3 common-tail draws using invalid `(-1,-1,-1,-1)` rectangles.
- Compiler-owned security-cookie lowering, switch tables, vtables/RTTI, alignment, and incidental final-call EAX values remain non-handwritten output. Physical resource pages remain blank because exact string literals belong at use sites.
- The additive source-closure callback is complete without changing the accepted OnDraw body. UID0003RN now emits complete `bool UserLookPane::OnMouseEvent(Event *event)` at `93/94`; UID0003RV/UID0003RW now emit the sole file-local packet-helper definitions at `91/93`. UID0003RR `ShowMoreInfoView`, UID0003RS `ShowProfileView`, and UID0003RU `ShowLegendView` now emit complete `92/93` member methods. RO key handling and RT Bio switching were rechecked read-only as complete `92/93` source. UID0001HB and bounded LegendPane/ScrollablePane support now use inherited `m_verticalScrollBarOffset`; all prior OnDraw work remains implemented and unchanged.

## Supporting Research
- Evidence was collected on 2026-07-19 through streamable MCP endpoint `http://127.0.0.1:13337/mcp`. Fresh HTTP MCP session `60604da9-3024-4581-8ed9-a3a7eeeb1963` returned one active adopted NexusTK IDB database `9b0396a3`, worker PID 15732. `server_health(database=9b0396a3)` returned `status:ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and a ready 2,067-entry string cache. These are evidence-collection-time observations and do not assert future MCP availability.
- Every IDB-backed call used `database:'9b0396a3'`. Fresh bounded lookup, bytes, decompile, disassembly totals, function-component analysis, xref, resource, and helper probes returned real NexusTK data after initialization. No fallback-only result is used.
- For this Gate 1 repair, fresh streamable MCP client sessions `bc7a23b2-4e85-401c-b816-fa1610cda0d4` and `4343503c-9668-4c04-a2f0-67e71bb915c9` independently rediscovered the same adopted database `9b0396a3`; `server_health` again returned `ok` with auto-analysis, Hex-Rays, and the 2,067-entry string cache ready. Every UID0003RN/RV/RW call used that database explicitly. These are evidence-collection observations, not present/future availability claims.
- The direct-view follow-through used fresh streamable MCP client session `9d48a658-872d-4825-b3e0-c63058eec069` against database `9b0396a3`. A bounded `server_health` call at collection time returned `status:ok`, image base `0x00400000`, and analysis/Hex-Rays/string cache ready. Fresh valid-schema `get_bytes`, function, component, decompile, disassembly, xref, global, vtable/sibling, and caller probes covered RR/RS/RU plus RO/RT and every direct view-transition edge from RN. An earlier malformed client request omitted the required `regions` key and returned an argument error; the corrected bounded call immediately returned real bytes and is the evidence used here. No outage or fallback conclusion is inferred from the malformed request.
- Exact report-search terms were `UID0003RM`, `0003RM`, `0x005a0640`, `0x005a157d`, `UserLookPaneRenderUserLook`, `UserLookPaneOnDraw`, `UserLookPane::OnDraw`, `sub_5A0640`, `UID0003RP`, `0x005a1a70`, `GetActionButtonRect`, `UID0003RQ`, `0x005a1b70`, `HitTestActionButton`, `USERLOOK.EPF`, `USERLOOK.PAL`, `PFLOOK.EPF`, `PFLOOK.PAL`, `FACE.EPF`, `NATION.EPF`, `INVENBUT.EPF`, `STATBUT.EPF`, `m_hoverActionIndex`, `m_pressedActionIndex`, `m_portraitFallbackFrame`, `g_pfnBlitSprite`, and `SurfaceSpriteBlitOptions`.
- Repair search terms additionally included `UID0003RN`, `0x005a1580`, `0x005a1985`, `UserLookPaneHandleMouseEvent`, `OnMouseEvent`, `UID0003RV`, `0x005a2190`, `0x005a2272`, `UID0003RW`, `0x005a2280`, `0x005a22da`, opcode `0x2e`, opcode `0x4a`, `QueueAndSendPacket`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `g_pSimpleHelpPane`, `SimpleHelpPane`, and `WideCharToMultiByte`.
- Direct-view repair terms additionally included `UID0003RR`, `UID0003RS`, `UID0003RT`, `UID0003RU`, `0x005a1cd0`, `0x005a1dee`, `0x005a1df0`, `0x005a1f16`, `0x005a1f20`, `0x005a1fe3`, `0x005a1ff0`, `0x005a2188`, `ShowMoreInfoView`, `ShowProfileView`, `ShowBioView`, `ShowLegendView`, `GetScrollPosition`, `GetScrollMax`, `ApplyScrollPosition`, `m_displayMode`, `m_verticalScrollBarOffset`, `g_useEpfAssets`, and `g_mainUiLayerSlots.rootPaneLayerContext`.
- Central executed root searched: `executed-b-agent-research`. Relevant artifacts opened and classified:
  - `B001/0001KK-userlookpane-profile-source-split-audit.md`: authoritative exact child boundaries, owner/emitter route, vtable refs, caller inventory, and padding baseline; it intentionally left the target/helper bodies unresolved.
  - `B001/0003RT-UserLookPaneShowBioView-source-quality.md`: accepted four-mode map and direct mode-2 PFLOOK portrait/fallback relationship; it treated UID0003RM as support and did not reconstruct this target.
  - `B001/0002V2-LookGroupCollectionResourceStringData.md`: pooled resource-island split and exact shared `STATBUT.EPF` source-use evidence.
  - `B002/0003F4-SharedStatButtonEpfResourceString-current-goal2-pass.md` and `B002/0003F4-SharedStatButtonEpfResourceString-current-no-owner-multi-emitter-recheck.md`: accepted no-owner/two-emitter disposition for `STATBUT.EPF`; no renderer body.
  - `B003/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md`, `current-no-owner-research.md`, and `fresh-no-owner-pass.md`: independent pooled-literal confirmation; no target source.
  - `B005/0003RK-UserLookPaneParseLookPacket-source-quality.md`: current `0xddc` layout, packet-produced fields, OnActivate source, local pane declarations, and historical render-support snapshot. Current target analysis supersedes only its render/helper blank-body and two frame-field label assumptions.
  - `B005/0003HT-ItemObjectPaneClearOutputRects-source-quality.md`: exact fourteen target call sites for `ItemObjImageLib::GetItemGlyphBounds` and current singleton-qualified member ownership.
  - `B014/0002GP-ApplicationGetVersionMajor-source-quality.md`: exact getter body and seven callers, including the target's ignored mode-1 call.
- Evidence-time active roots searched: `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`. No exact target report existed. The report-only recheck then found B001 assigned UID0001NM, B003 UID0003SC, B004 UID00030C, and B005 UID000478; those observations are historical coordination evidence, not assertions about their later lifecycle state. Callback-time destination/lease rereads found no UserLookPane collision.
- B003 UID0001LM is not active work. It is centrally executed at `executed-b-agent-research/B003/0001LM-SpellFourArgsInputPaneConstructor-source-quality.md`, SHA256 `305F6889DB426A27AAA0334C4FC46E279B5314065768EC6CC2857A7FD0DC3814`, with validator execution command `000000014766`; it remains historical support only and has no UserLookPane destination.
- Legacy executed roots checked under per-agent `research/executed`: absent. Archived root `tools/leaser/Agents/Older-Research`: no direct target match. Central invalidated/special report paths produced no direct target artifact. Search hits in older Application, shared-resource, parser, and view reports are support references, not direct-report substitutes.
- Evidence-time initial lease preflight found no UserLookPane/UID0003RM lease and no B002 lease; its then-observed unrelated B004 `by-memory/-ignored.md` row is historical. Intermediate repair reads observed transient B001 UserStatusPane and B005 TextBoxPane/ignored leases, and the later two-pass repair observation found unrelated B001/B005 leases only; those are historical coordination snapshots. Prior bounded reads through the post-command-14864/14866 read at `2026-07-20T02:51:08-04:00`, including hashes `EA2FA43F...AAC4`, `09DC1099...D0B8E`, `762CD28A...69C9`, and `2069068C...850C`, are retained as historical snapshots. At the historical command-14869 bounded read `2026-07-20T02:56:22-04:00`, `tools/leaser/Agents/current_leases.md` had SHA256 `EA2FA43FFE5ADAEE941CD801C5EA2E206A3D9B9D7FFC692F685134199392AAC4`, 166 bytes / 8 lines, no active rows, and therefore no B002, UserLookPane, UID0003RM, or accepted-destination lease. These bounded observations do not assert later lease state.
- The repair reread the executed B004 SelfLookPane2 event-handler report `executed-b-agent-research/B004/0003RD-SelfLookPane2HandleEvent-source-quality.md`, SHA256 `D44B9F29B00CD240D6223E976FAD9FD4F6B63C09478246D585958E20E2A72D46`. Its accepted treatment of raw no-xref packet ranges as source-live file-local helpers when a virtual handler contains behavior-identical inlined copies is directly analogous evidence, not a substitute for the fresh UID0003RN/RV/RW analysis recorded here.

## Target
- Target UID: `0003RM`.
- Evidence-time path: `by-memory/0x005a0640-0x005a157d.UserLookPaneRenderUserLook.md`.
- Applied UID-preserving path: `by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md`; the former ordinary path no longer exists.
- Report path: `tools/leaser/Agents/Agent-B002/research/0003RM-UserLookPaneRenderUserLook-source-quality.md`.
- Exact range: `[0x005a0640,0x005a157d)`, `0xf3d` / 3,901 bytes.
- Evidence-time target SHA256: `AF955B5D668A67722A9536DA6FE98188A6BF3F36AF70707B51976216286B63D3`, 6,766 bytes / 61 lines.
- Evidence-time metadata: `86/90`, owner/emitter UID0000FP, reconstructable true, blank optional position, blank formal C++, `Nested:0`.
- Applied metadata: `93/94`, same owner/emitter/reconstructable/position/nesting, complete Destination 1 formal body.

## Current Target State
- Evidence-time/pre-callback target, class, helper, generated, and tracker states were blank/stale as documented below and in the historical snapshots. Those facts are superseded current-state history, not present callback truth.
- At the historical command-14869 bounded read `2026-07-20T02:56:22-04:00`, UID0003RM was `by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md`, SHA256 `89085690310536982AF9C4A01E6C3CEBF67AF080E127F9E4C94B6EAD57A8EF6B`, 38,213 bytes / 702 lines, `93/94`, owner/emitter UID0000FP, true, blank position, `Nested:0`, with Destination 1 byte-equal to this report.
- At that read, UID0000FP was SHA256 `2532A7BD5B2D21AE82CBCF40EA7D09DEB23F7007554C4946E139FD00822D6D67`, 35,228 bytes / 334 lines, `92/94`, with the complete Destination 2 declaration closed before `[[CHILDREN]]`. UID0003RI was `92/94`, position 10, SHA256 `6EA83AE23D274848E7A78FF9AAD76FF750A0C8533CDDFE6F914B30DFA182F33A`, and had Destination 3 byte-equal. UID0003RP/UID0003RQ were `92/94`, SHA256 `025BF9539A4DC77DA4B7B5C8959A03326DC66DBED0C82356E41BBBDE596FA128` / `60C1308F1D6E0564F82709D154195B43A91A20048235A90122DE050165F14619`, with Destinations 4/5 byte-equal.
- At that historical read, UID0003RN remained `86/90` and blank at SHA256 `894F5885F79362D63F0BD9C2DC5E7AFDE17F1FCA9FFD6B305884F3E263C3B469`; its prose recorded exact next/previous ButtonFrame writes without reconstructing the separate mouse body. That pre-callback state is superseded. Current UID0003RN is `by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md`, `93/94`, owner/emitter UID0000FP, true, blank optional position, `Nested:0`, SHA256 `83F96098E69B57708AB62B545F8D6CDB4FEF82880244CD03D95BE505051A8D53`, with Destination 15 byte-equal. Current UID0001KK is `90/93` false/non-emitting at SHA256 `7C22B6761778D52158A8C718424AC47A43CE9992600F6698ADC42C829FC53F4E`; UID0000P0 remains prose-only `92/93` at SHA256 `A6F944CE5D030FAF109C86F353F9C9104EF0FCEF248CE0214484C6F2D56FA01D`.
- Evidence-time reads found UID0003RV at `UserLookPaneRawWideTextPacketSender`, SHA256 `446EDF22...83A7`, and UID0003RW at `UserLookPaneRawOpcode4aPacketSender`, SHA256 `EE4E81BF...4E32`; both were `85/88` with blank source. Those states are historical. Current UID0003RV is `by-memory/0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket.md`, `91/93`, position 80, SHA256 `142593CCBA6C1832B8EC22E0F9498298119A096FDB09382E1A51A35A9FAAC208`; current UID0003RW is `by-memory/0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket.md`, `91/93`, position 90, SHA256 `594E6A5A4004E0F4E6B064AC5999F27166E834AF862C8E6152AF28DF790E5271`. Both retain owner/emitter UID0000P0, true, `Nested:0`, and byte-equal Destinations 16/17; all three old ordinary paths are absent.
- Evidence-time direct-view reads found UID0003RR/RS/RU at `86/90` with blank formal C++; their exact hashes and metrics remain historical above. Current UID0003RR is `92/93`, SHA256 `EDFA8EBD74E1AA83AAF84A7B1F26255F547376A68DDDD72FF4E00E8327286D24`; UID0003RS is `92/93`, SHA256 `8BBF02BF25FBA0B80C4CD4A4D7993E55EB4614E6FD0FCE4BE1433D5B1A1C5BAF`; UID0003RU is `92/93`, SHA256 `0DDCC1177FE50EB5704F5FD86A4B6C6172BD0CDC51D1298019EC935ACBA05D96`. All retain owner/emitter UID0000FP, true, blank optional position, `Nested:0`, and byte-equal Destinations 21-23.
- UID0003RO and UID0003RT were reread after callback at current SHA256 `48F09DFB7DC39B7C2010DD0C5F36561CABBD9C52B981A82296C0DC947A9E1355` and `681A3A24658D0EEDFFC2C5821F610799D7EB51AF0D366CE218A20C15F2C9B30A`; both remain complete `92/93` source. RN calls only RR/RS/RT/RU for view transitions, and all four now emit exactly once, so no direct source-bearing view helper remains blank.
- The direct UID0003RU store at LegendPane `+0x104` and ScrollablePane constructor/layout/recompute evidence identify inherited `m_verticalScrollBarOffset`. The bounded synchronization is applied with unchanged scores/routes: UID0001HB `88/91`, SHA256 `7FD703ADA8243DAF24FF0833F42CBDC5FE66A4B65FF2350551D125DB7C2F037C`; UID000074 `91/93`, `56180AE67CC858AD6D44654199F050EC56F7F11431955ECFF79DB5F92CEC99C7`; UID0000KM `90/92`, `55EEE05FB1AB8D1BD6CBA28EDD27E012F65D5DB7F7647FB1399CB3D7553AE9A6`; UID0001GL `88/90`, `97254D76FA619A8FEA34AF3F8F6300B8DFA95DB17F79FE65BB517261FCAD2B88`; UID0000CF `89/90`, `302AF44562FB3BD07DB81B7BBF69BA4B03E7DF68562A6BA87269E6CCC0D8AB04`; and UID0000NF `90/87`, `8B26B10F28B14294D6A3659AA74B4AF45BD547FD219E15ACA0A6738C5346C869`. UID0001HB Destination 24 is byte-equal, generated LegendPane uses the token once, and `m_displayMode` remains only labeled history in ordinary prose.
- At that read, UID00038X/UID00026V/UID00038R/UID00038Q were respectively `90/93`, `89/93`, `90/93`, `89/93`, with SHA256 `C26A56B5C761CFB6D006946C9BC19274D56729041B00DBEA4A9102DE6FB1DC11`, `674932BFEC86B31BB7757FA6353A16C2522692A2E31C8DA2ED6375C84CC32CF6`, `FCA9BA49189BD9B069AACBEDBE97F6D6C6683077CBC020AAF234B3245B2A34B4`, and `D005F812471A7EEDA23C24A36287E725F2653835E98152CE611D09525ECEB2B6`. All had blank direct C++ with exact declaration/use-site/compiler dispositions.
- At that read, ApplicationGetVersionMajor remained `88/92` with unchanged body and SHA256 `C685570E707F2E38F68D2DC9A4AE52F4C1464A27CC2729FCA71B2F7AE8113129`; all target links used the full UID0003RM OnDraw path and the ignored-result behavior was explicit. Verify-only UID0003F4 was unchanged at SHA256 `3299C358688B362E85BF8D5139199272EBF2808FCDE4AD75073BA213720A0A82`.
- Historical callback/readback commands `000000014831`, `000000014846`, `000000014857`, `000000014859`, and `000000014864`, with their exact hashes/timestamps retained in Validator Results, are historical implementation/readback provenance. At the historical command-14869 bounded read `2026-07-20T02:56:22-04:00`, the read-only generated file had validator command `000000014869`, refreshed `2026-07-20T02:54:30-04:00`, SHA256 `7FAE3F8796DC504271FEA91EDBA01C6F2C3FFDD05808AABF590CE04345BF4D88`, with the same 48,543 bytes / 1,296 lines and semantics: one complete UserLookPane class and constructor; exactly one OnActivate, OnDraw, HandleKeyOrTextEvent, GetActionButtonRect, HitTestActionButton, and ShowBioView; exactly one constructor and input override for each local MoreInfoPane/ProfilePane; one `g_pMoreInfoPane` definition plus its expected extern/use; one next/previous ButtonFrame declaration pair; zero UID0003RM/UID0003RP/UID0003RQ Empty Emitter Markers; zero stale `m_hoverActionIndex`/`m_pressedActionIndex` tokens; and zero handwritten vtable/RTTI/cookie/switch-table/adjustor/scalar-wrapper source. This observation does not claim command 14869 remains latest after that read.
- Callback-final generated state was independently read after the required LegendPane refresh at validator command `000000014932`, refreshed `2026-07-20T04:59:05-04:00`. `auto-generated/NexusTK/ui/panels/UserLookPane.cpp` is SHA256 `F7F27A1CFCE3C4E04DC65BA100813338FF47C19C98A396888E66576205A5A69D`, 57,758 bytes / 1,591 lines. It contains exactly one complete UserLookPane class, constructor, OnActivate, OnDraw, OnMouseEvent, HandleKeyOrTextEvent, GetActionButtonRect, HitTestActionButton, ShowMoreInfoView, ShowProfileView, ShowBioView, ShowLegendView, each local pane source body, and `g_pMoreInfoPane` definition; exactly one declaration plus one definition for each file-local packet helper; zero RN/RR/RS/RU/RV/RW Empty Emitter Markers; zero stale frame tokens; and no handwritten vtable/RTTI/cookie/range-check/switch-table/adjustor/scalar-wrapper source. `LegendPane.cpp` is SHA256 `506146403E636D7453D0B3A1DF9A3266238E978D2A9E417B43847ECB5543B0A7`, 1,651 bytes / 51 lines, with one constructor, one `m_verticalScrollBarOffset = 63`, zero `m_displayMode`, and no duplicate constructor. The command-14932 tracker snapshot was callback-time history: SHA256 `3E42FD5FC88373BAF85D1EA7C1835731CB0C7430CAE2B99025ECB195ADDBFB35`, 1,519,589 bytes / 6,165 lines. At B002's bounded final read, the independently generated tracker had advanced externally to command `000000014962`, refreshed `2026-07-20T05:21:12-04:00`, SHA256 `15BD40D4347E0777408F04F3010C6D9611163D268F9518E6BBE55FEC08D74BB0`, 1,519,767 bytes / 6,166 lines. Its current rows retain RV/RW at lines 3015/3016 as `91/93`, RR/RS/RU at 3087/3088/3089 as `92/93`, and RM/RN at 3286/3287 as `93/94`, all on their accepted paths. This later tracker observation is read-only, time-bounded external state and does not alter command 14932 generated-source proof.
- Historical pre-B004 manual snapshots were by-memory `960EA5627C7944BA8B7622695A39D50F44B5305DB3CDCF3862C85A19B106E6C6`, by-class `03B11FDE7ED18F7C1FA607D37157D33034FF155BED5F12EA674A062181C0A694`, and by-file `4E6E3BB3E5EB52E45458EF6244893C32D56B7C3EECB0A466994FEF8B285CADE7`. They are superseded mutable evidence and are not presented as current.
- Manual coverage is read-only and supervisor-owned. Target validator `000000014818` automatically propagated only the UID0003RM path in by-memory, producing intermediate SHA `674D856B...`; unrelated UID0001NM and WorldMap supervisor work advanced earlier epochs without changing any UserLook row's stale title/score/body. At the command-14869 final read `2026-07-20T02:56:22-04:00`, manual hashes/metrics remained exactly the command-14859 values: by-memory `648C96BC0CF3AC950310399BBB69ADDCF9D955035B314F6C57FF263A6CF9690E` (1,815,581 bytes / 4,327 lines), by-class `CF71F86225D5A027627EE50C49236C7C0A1863DD622C6845F1698B2C059C864C` (235,871 / 623), by-file `22316E877291B68B3D0AA99ECD5CB1C6457E0EBB71B7FEC4E222CE5E1665297B` (134,565 / 316), by-global `B1D9DE82100DEFA76A964C097A808F0DAC6781CF4D51F6D670000F21B6AC3357` (90,593 / 213), by-item `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6` (28,963 / 87), and by-type/by-vtable `249233F6B031CFC104ED0C9CD5678BFDE873E03FBBD9092AD788675032030749` (65,481 / 142). B002 made no manual coverage edit, and these hashes are observations at that read rather than claims of indefinite authority.
- Exact command-14869 final-read anchors remain UID0001KK line 3428, UID0003RI 3429, verify-only UID0003RK 3430, UID0003RM 3431, UID0003RN 3432, UID0003RP 3434, UID0003RQ 3435, UID00026V 3997, UID00038R 3998, and insertion anchor UID00038T 4000 in by-memory; UID0000FP line 586 in by-class; UID0000P0 line 296 in by-file; and UID00038Q line 81 in by-type/by-vtable. The rows are byte-for-byte unchanged from command-14859 readback, retain their pre-recommendation names/scores/content, and UID00038X remains absent; the exact proposed replacement/addition text below therefore remains valid without loss. No UserLookPane/UID0003RM-family match exists in by-global or by-item at this read, so the handoff correctly proposes no row there. Later unrelated movement of anchors does not alter the UID-keyed handoff.
- The old ordinary hashes and tracker commands through `000000014859` are retained as evidence-time/pre-callback or intermediate historical epochs. Supervisor autogen command 14864 and subsequent deferred tracker command 14866 are also historical external epochs: command 14866 had SHA256 `BF15229ECE587E7A1FC4C20B85B7D82918DC55D7201258CD1AEE0451970FE57A`, 1,517,734 bytes / 6,158 lines. At the command-14869 final read `2026-07-20T02:56:22-04:00`, `auto-generated/-ag-research-tracker.md` had command `000000014869`, refreshed `2026-07-20T02:54:30-04:00`, SHA256 `99DA1361EFA6104024F8486AC4FB456AA63A9B577AEDDA443C9BC2071B21E30B`, 1,517,958 bytes / 6,159 lines. UID0003RM was line 3284 on the full UserLookPaneOnDraw path as `93/94`, reconstructable true, `Nested:0`, with zero direct reports. Related rows were UID0000FP 811, UID0000P0 1157 (plus generated-file summary line 61), UID0003RN 1575, UID00038S/UID00038T 2469/2470, UID00026V 2690, UID00038R/UID00038X 2895/2896, UID0003RP/UID0003RQ 3237/3238, UID0003RI 3890, UID0003RT 3994, UID0003RO 3999, UID0003RK 4002, UID0003F4 4191, UID0002V2 5567, UID0001KK 5580, and UID00038Q 5876, each retaining the report's accepted ordinary score/path/disposition or its already-executed support state. This read-only volatile observation is not a lifecycle assertion and does not claim command 14869 remains latest later.
- The command-14869 bounded final artifact recheck at `2026-07-20T02:56:22-04:00` confirms all 13 Changed Files ordinary hashes still equal the callback hashes recorded below, the former target path remains absent, and `UserLookPane.cpp` is command `000000014869`, SHA256 `7FAE3F8796DC504271FEA91EDBA01C6F2C3FFDD05808AABF590CE04345BF4D88`, 48,543 bytes / 1,296 lines with every structural assertion unchanged from historical commands 14831, 14846, 14857, 14859, and 14864. Manual hashes at that same read remained by-memory `648C96BC...690E`, by-class `CF71F862...864C`, by-file `22316E87...297B`, by-type/by-vtable `249233F6...49`, by-global `B1D9DE82...3357`, and by-item `66C86AAF...9EA6`; direct row reread confirms the exact pending handoff text and anchors remain no-loss for that observed epoch.
- Historical report-only repair read at `2026-07-20T03:34:22-04:00`: all twelve directly rechecked ordinary hashes remained exactly those recorded under Changed Files plus UID0003RV `446EDF22` and UID0003RW `EE4E81BF`; generated UserLookPane.cpp was command `000000014869`, SHA256 `7FAE3F8796DC504271FEA91EDBA01C6F2C3FFDD05808AABF590CE04345BF4D88`, 48,543 bytes / 1,296 lines, with one UID0003RN Empty Emitter Marker, zero OnMouseEvent/name-helper/target-helper definitions, and one each prior OnDraw/rectangle/hit-test definition. Tracker command `000000014875`, refreshed `2026-07-20T03:32:44-04:00`, had SHA256 `B1F08C79B36A238BDDA5EECB32D468CD8D75E2C6AA749E43A8ED20D089E02C93`, 1,518,196 bytes / 6,160 lines. This epoch is retained as historical and does not compete with the command-14880 read below.
- Historical pre-callback bounded read at `2026-07-20T04:00:18-04:00`: external generated `UserLookPane.cpp` was command `000000014880`, refreshed `2026-07-20T03:40:21-04:00`, SHA256 `B2576234DBAEC903286F4CEBE25D167AD92CFB18D23A41599C9B6C978CDA0664`, 48,543 bytes / 1,296 lines. It had one UID each for RM/RN/RR/RS/RT/RU, exactly one OnDraw and ShowBioView definition, exactly one Empty Emitter Marker each for RN/RR/RS/RU, zero OnMouseEvent/ShowMoreInfoView/ShowProfileView/ShowLegendView/name-helper/target-helper definitions, and unchanged prior no-duplicate/no-handwritten-ABI semantics. Tracker command `000000014880`, same refresh time, SHA256 `92903C4718F86FBD079CB30D2BCBB53DAF2E693096EFC8F0F62A6D16C6E18DBB`, 1,518,198 bytes / 6,160 lines, recorded RN/RR/RS/RU at `86/90`, RM at `93/94`, and RT/RO at `92/93`; RV/RW were absent. These superseded facts are retained only as time-bounded pre-callback history.
- Historical pre-callback stability pass at `2026-07-20T04:15:57-04:00` rehashed command-14880 generated/tracker to the same hashes/metrics, rehashed RR/RS/RT/RU and all six LegendPane/ScrollablePane support destinations byte-equal to the then-current snapshots, and read the lease ledger twice at the same empty state. This is retained as bounded history and does not compete with callback-final command 14932.

## Executive Recommendation
- Applied exactly: the target is UID-preservingly named `UserLookPaneOnDraw` and emits one complete `void UserLookPane::OnDraw()` definition through UID0000FP/UID0000P0.
- Applied exactly: UID0003RP and UID0003RQ emit the complete geometry and hit-test source bodies; no blank-body blocker remains.
- Applied by this callback: UID0003RN emits the complete secondary-facet `OnMouseEvent` body and calls two source-live file-local packet helpers. UID0003RV/UID0003RW emit those helpers once in the same file. UID0003RR/RS/RU emit complete `ShowMoreInfoView`, `ShowProfileView`, and `ShowLegendView` member definitions, including every EPF/legacy asymmetry; UID0003RO and UID0003RT remain complete verify-only source. This closes every directly called blank source-bearing method rather than moving the deferral one call deeper.
- Applied exactly: the complete class block retains every accepted field/method, adds the four bounded enum surfaces, uses only the two proven next/previous frame fields, and declares vertical-first `HitTestActionButton(y,x)`.
- Applied exactly: the constructor changed only the two frame initializers to `ButtonFrame_Normal`, preserving all accepted construction and initialization statements.
- Retained exactly: UID0001KK is non-emitting and resource/read-only/vtable pages are declaration-generated or use-site-only. No broad parent body, standalone string global, manual vtable, or image-library source copy exists.

## Supervisor Active Recheck
- B002's accepted OnDraw implementation and the additive RN/RR/RS/RU/RV/RW source-closure callback are complete. C01-C50 now have legal terminal states: 42 `applied`, two `already-present`, and six `excluded-with-reason`; zero remain `proposed` or `blocked`.
- B002 edited only the ordinary destinations listed under Changed Files and this report. Manual coverage, generated output, tracker, stats, audit, supervisor, goal, validator-owned state, IDA, and lifecycle files were not manually edited; validator-generated side effects are recorded separately.
- Manual coverage application, Gate 2 decision, execution, movement, and archive state remain supervisor/validator-owned. The exact no-loss handoff remains pending external application and is not falsely claimed as B002 work.
- All prior managed blocks remain preserved, and Destinations 15-17/21-24 compare byte-for-byte equal between this report and their ordinary destinations. Scoped validators 14885-14929 and waited refreshes 14930/14932 passed. Final generated command 14932 proves the complete one-definition/no-target-marker/no-handwritten-ABI union. The final lease read contains no B002 row; every callback lease was released immediately after its scoped validator.

## Inference Research Guidance Check
- Direct evidence: bytes, hashes, ranges, function models, instruction/CFG counts, branches, calls, vtable cells, field displacements, constants, resource code units, and padding.
- Strong inference: source method/private field/enum names and the physical source filename. Names are accepted only when multiple current consumers converge or project sibling vocabulary provides a stronger period-plausible form.
- Source reconstruction preserves runtime behavior rather than decompiler shape. Repeated text scans and repeated item branches remain repeated; no modern lambda, container, exception abstraction, or speculative render helper is invented.
- Binary return residue does not override source API evidence. Primary vtable placement and the current complete class establish `void OnDraw`; UID0003RP's discarded `InitRectBounds` EAX similarly remains a void helper.
- Data storage and source emission are separated. Physical UTF-16 literals and vtable bytes regenerate from source declarations/use sites and therefore remain non-emitting documentation.

## Heuristic / Inference Reanalysis And Validation
- Liveness: UID0003RM has no code caller because it is virtual. The sole xref is data cell `0x0062ed10`, primary UserLookPane vtable relative `+0x44`; adjacent `+0x48` is UID0003RK `OnActivate`. This is strong live dispatch, not dead code.
- ABI: target receives only `this`, has plain `ret`, and leaves branch-dependent EAX residue. The existing class declaration and sibling paint API establish `virtual void OnDraw()`. `RenderUserLook` is a behavior title, not a source method.
- Mode background: modes 0/1/3 load USERLOOK frames 0/1/3 and `USERLOOK.PAL`; mode 2 loads PFLOOK frame 0 and `PFLOOK.PAL`. Mode 1 first calls `Application::GetVersionMajor()` and discards the return. Unknown modes leave the initialized tile empty and pass `g_pEPFLib` through the palette slot, then return after the background callback.
- Mode 0 text: header center is clamped at x 3 for the dark pass and x 2 for the light pass; target name centers at 118/117 with foreground color 143 only when highlighted, otherwise 10. Three identity lines center at x 106/105 and y pairs 45/44, 66/65, 87/86. Each string is scanned separately for width and for both draw calls. Text background is reset to zero only after identity line 1, exactly where observed.
- Mode 0 status: HumanObject uses NewHuman bounds and overlay bounds with direction 2, baseline bottom 187 and left 54, then exact overlay/image corrections before draw. MonsterObject uses selector 7/frame 0, centers the full computed image at `(78,131)`, and renders without an overlay. Other status kinds skip the character image.
- Mode 0 actions: exchange id 1 uses state byte `+0xb84`, frames 8/3; group id 0 uses `+0xb85`, frames 7/2. State `0xff` sets draw color 143, sets inherited `m_drawMode` to 0, and invokes the direct fill callback. The direct fill precedes the common navigation tail.
- Mode 1 equipment: fourteen independent nonzero-id branches use singleton member calls `g_pItemObjImageLib->GetItemGlyphBounds` and `DrawItemImage`. Exact centers are body `(92,92)`, left hand `(150,92)`, right hand `(34,92)`, head `(92,36)`, face accessory 1 `(36,36)`, head accessory 2 `(150,36)`, right accessory `(147,146)`, left accessory `(34,146)`, left sub-accessory `(34,198)`, right sub-accessory `(150,198)`, necklace `(92,146)`, foot `(34,250)`, coat `(92,250)`, and mantle `(92,198)`. Each uses its matching palette byte and signed `/ -2` centering.
- Mode 2 portrait: rectangle `(70,48,118,104)` and palette slot `(13,0,0)` are exact. Nonzero portrait payload uses the stored `m_portraitImage`. Zero payload loads FACE frame `(m_statusEncoding != 0)`, writes only byte-zero `SurfaceSpriteBlitOptions::mode = 4` without value-initializing the remaining 31 bytes, and blits in mode 1 with null palette. It then performs an unused `NATION.EPF` lookup using `m_portraitFallbackFrame`.
- Mode 3 intentionally performs no mode body, then reaches common navigation. Because UID0003RP returns invalid rectangles for mode 3, both common renders receive `(-1,-1,-1,-1)`. Normalizing this to an early return would change observed behavior.
- Common navigation: Next id 3 uses INVENBUT frame `7*m_nextButtonFrame+6`; Previous id 2 uses frame `7*m_previousButtonFrame+5`; both use `INVENBUT.PAL`. Mouse writes prove each field is a visual frame state, not an action index: hover writes 1, press writes 2, and clear/release writes 0.
- UID0003RP: signed-short action id, caller-owned RectBounds, `ret 8`, 74 instructions, 15 blocks, complexity 11, six calls. Group and Exchange exist only in mode 0; Previous exists in modes 1/2; Next exists in modes 0/1/2; all other combinations produce four `-1` values.
- UID0003RQ: two integer arguments, signed-short return, 108 instructions, 19 blocks, complexity 12, two mouse callers. Its binary contains an optimized/inlined copy of UID0003RP's switch, then calls `PointInRect`; human source should call `GetActionButtonRect` in a four-id loop and return first hit or `-1`.
- Coordinate order: accepted RectGeometry and Event evidence defines `PointInRect(int y,int x,const RectBounds*)`. UID0003RQ forwards its first argument first, so the current class labels `int x,int y` are reversed. Destination 2 and Destination 5 use `int y,int x` without changing ABI.
- `SurfaceSpriteBlitOptions`: current shared declarations prove a 32-byte complete source type with byte-zero member `mode`; other fields are mode-dependent. The target writes only `mode=4`. Value-initializing the record, inventing a raw 32-byte local, or fabricating all fields would change source shape or exceed evidence.
- UID0003RN liveness/ABI: zero code callers are expected for a virtual. Data cell `0x0062ed20` in the secondary UserLookPane table points to `0x005a1580`; machine `this` is the EventHandler facet at complete-object `+0xa0`, while source is ordinary `virtual bool OnMouseEvent(Event *event)` and contains no explicit receiver adjustment. The function ends `ret 4`; Hex-Rays' `char __thiscall(int,int)` is only a pseudo-type.
- UID0003RN cursor behavior is exact: outside `m_bounds` sets both navigation frames to Normal and returns false without invalidation. Inside, Next/Previous rectangles are tested in that order. A hit writes Hover/Normal or Normal/Hover, invalidates `m_bounds`, and returns true. Inside neither rectangle, both-already-Normal returns true without invalidation; otherwise both reset to Normal, the bounds invalidate, and true returns.
- UID0003RN left-button behavior preserves the observed odd shared gate. Action ids Group and Exchange both test `m_exchangeActionState != 0xff`; Group sends the six-byte opcode-`0x4a`/subtype-zero/object-id packet, while Exchange sends the opcode-`0x2e` converted target-name packet. Each case returns true even when disabled, and the name case also returns true for an empty string.
- Previous transitions are Legend to Bio, Bio to Profile, and Profile to MoreInfo only when `g_useEpfAssets == 1`; Next transitions are MoreInfo to Profile, Profile to Bio, and Bio to Legend. Previous writes Next Normal/Previous Pressed; Next writes Next Pressed/Previous Normal; both invalidate and return true even where no transition occurs.
- UID0003RN right-button behavior first hit-tests, then deletes `g_pSimpleHelpPane` before checking the action id. Group/Exchange create `SimpleHelpPane` from localized ids 200/201 with `(text,this,x,y,5000)` and return true; every other id returns false after deleting the prior pane. Allocation guards, the 252-byte allocation, singleton clear, EH, and cleanup are compiler/class lowering, not handwritten handler statements.
- UID0003RV and UID0003RW are source-live despite zero start xrefs. UID0003RN contains behavior-identical optimized copies of both packet sequences, and each raw range has a normal prologue, one stack argument, `ret 4`, stack locals, exact source boundary, and compiler-only cookie/range-check tail. The highest-probability original shape is two file-local `static void __stdcall` helpers later in UserLookPane.cpp, not members and not dead code.
- UID0003RV obtains `MemoryMan *` before testing `targetName[0]`, uses no null-input or conversion-failure branch, narrows `wcslen` to signed short for `WideCharToMultiByte(CP_ACP,...)`, stores the converted count in one packet byte, copies exactly that count, writes a local terminator outside the sent length, and sends `textLength+2`. UID0003RW uses a 16-byte local, writes `0x4a`, zero subtype, big-endian object id, explicitly zeroes byte 6, and sends exactly six bytes. Neither helper checks `g_packetSender`.
- UID0003RR `ShowMoreInfoView` is a 286-byte, 88-instruction, four-block/complexity-2 member. It stores mode 0. Both asset branches remove/unregister ProfilePane then LegendPane; the legacy branch additionally removes/unregisters MoreInfoPane. EPF/current bounds are `(7,205,182,266)`, legacy bounds `(17,192,174,251)`. Common code resets MoreInfoPane axis 0 from its observed current position to zero, attaches it through `g_mainUiLayerSlots.rootPaneLayerContext`, orders it against `this`, and invalidates `m_bounds`. The branch asymmetry, exact teardown order, no null guards, and no source return are preserved.
- UID0003RS `ShowProfileView` is a 294-byte, 90-instruction, four-block/complexity-2 member. It stores mode 1. Both branches remove/unregister ProfilePane, MoreInfoPane, and LegendPane in that exact order. EPF/current mode performs no reattachment before owner invalidation. Legacy mode constructs `(17,192,174,251)` but deliberately resets and reattaches `m_moreInfoPane`, not `m_profilePane`. That counterintuitive child choice is repeated direct machine evidence and is not normalized to the method name.
- UID0003RU `ShowLegendView` is a 408-byte, 121-instruction, four-block/complexity-2 member. It stores mode 3 and removes/unregisters MoreInfoPane then ProfilePane; it does not remove/unregister LegendPane before reattachment. EPF/current mode uses `(7,15,182,265)`, resets LegendPane axis 0, stores decimal 49 at inherited `+0x104`, attaches/orders it, then reads maximum first and current position second before scrolling current-to-maximum. Legacy mode uses `(17,36,174,251)`, resets and attaches/orders LegendPane, and omits both the `+0x104` store and max-scroll pass. Both branches finally invalidate `m_bounds`.
- Fresh base/sibling analysis rejects the existing `m_displayMode` placeholder for `+0x104`. ScrollablePane constructor/layout/recompute and selected-child helper evidence fixes `+0x100/+0x104/+0x108` as `m_horizontalScrollBarOffset`/`m_verticalScrollBarOffset`/`m_scrollBarInset`; UID0001HB's constructor write of 63 and UID0003RU's write of 49 are two source uses of the inherited vertical offset. Current accepted ScrollableControlPane source already accesses this field directly through a ScrollablePane pointer, so `m_legendPane->m_verticalScrollBarOffset = 49` is compile-valid project style rather than an invented setter.
- UID0003RO was freshly rechecked as 207 bytes, 71 instructions, 18 blocks, complexity 9, with direct view calls only to RR/RS/RT/RU. UID0003RT was freshly rechecked as 195 bytes, 63 instructions, one block, with the accepted complete Bio body and three callers. RN's complete direct-call inventory contains no other blank source-bearing view transition.
- Score blockers are closed: exact OnDraw, mouse, RR/RS/RU ranges/bodies, both virtual names/routes, all render modes, all mouse/view branches, Event layout, button/view fields, packet formats, helper signatures, global/root-layer context, inherited scroll field identity, ownership/file route, raw-helper liveness, and compiler boundaries are resolved. Remaining uncertainty is only stripped original spelling for private display strings, packet-helper tokens, `m_portraitFallbackFrame`, and some enum labels; it caps confidence without blocking source.

## Evidence Standards Used
- Primary: live MCP IDB facts and local PE bytes from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Secondary: ordinary documentation, read-only generated output, manual coverage rows, and executed sibling/support reports, each identified by its evidence-time or bounded-final-read epoch rather than treated as indefinitely current.
- Exact binary evidence outranks stale prose. Current accepted class/type contracts outrank Hex-Rays pseudo-types where the ABI is consistent.
- Inference is accepted only when it yields human-shaped period-plausible source without adding behavior. Rejected alternatives remain documented rather than silently removed.

## Evidence Checked
- Fresh MCP checks: `idb_list`, `server_health`, `lookup_funcs` for target/rectangle/mouse/hit-test/view helpers, bounded `get_bytes` at all source/tail boundaries, `analyze_component` for target/rectangle/mouse/hit-test/RR/RS/RU/RO/RT, complete target/mouse/rectangle/hit-test/view decompiles, paginated disassembly totals, xrefs, vtable bytes, globals, ScrollablePane/LegendPane field consumers, and direct bounded analysis of both raw packet-helper ranges.
- Local PE extraction: `.text` target raw offset `0x0019fa40`; target bytes/hash, helper bytes/hashes, and following padding/table bytes were computed independently and agree with MCP boundary bytes.
- Current docs opened: UID0003RM, UID0003RP, UID0003RQ, UID0003RN, UID0003RR, UID0003RS, UID0003RT, UID0003RU, UID0003RV, UID0003RW, UID0003RI, UID0003RK, UID0003RO, UID0001KK, UID00026V, UID00038R, UID00038X, UID0000FP, UID0000P0, UID00038Q, MoreInfoPane, ProfilePane, LegendPane class/constructor/file, ScrollablePane class/core/file, Application/GetVersionMajor, ItemObjImageLib, ObjectStatusBlob, NewHumanImageLib, MonsterImageLib, EPFLib, PaletteLib, GrafPort, RectGeometry, Event/by-file Event, PacketBuffer scalar writers, QueueAndSendPacket, MemoryMan/MemmoveWrapper, LanguageMan, SimpleHelpPane, global pointers, and shared STATBUT resource pages.
- Generated files opened and counted after the callback: final external command `000000014932` produced UserLookPane SHA `F7F27A1C...A69D` and LegendPane SHA `50614640...B0A7`; exact metrics and all one-definition/no-target-marker/no-stale-token assertions are recorded in Current Target State and Validator Results. The tracker was independently reread at command `000000014962`; command 14932 is retained as callback-time tracker history, and command 14880 plus all earlier epochs remain labeled history.
- Manual rows opened after the callback: UID0001KK, UID0003RI, UID0003RK, UID0003RM-RU, UID0001HB, UID0001GL, UID00026V, UID00038R, UID0000FP, UID000074, UID0000CF, UID0000P0, UID0000KM, UID0000NF, and UID00038Q. UID0003RV/RW/UID00038X still have no by-memory row, so their exact supervisor-owned additions remain required; current anchors and hashes are recorded below.
- Historical lease preflights through hash `2069068C...850C`, command-14869 hash `EA2FA43F...AAC4`, and the later `DA3A7A26...D98A` snapshot remain evidence-time history. Final callback read of `tools/leaser/Agents/Agent-B002/current_leases.md` contains no B002 row; every ordinary lease listed in Validator Results was released immediately after validation. No lease is held at return.
- Exact old-report roots, terms, matching paths, and findings are recorded under Supporting Research. There is no direct exact-range report.

## Claim And Incorporation Ledger
| ID | Claim | Confidence | Evidence | Destination / operation | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0003RM preserves exact range/UID/owner/emitter/TRUE/blank position/Nested 0, renames to UserLookPaneOnDraw, and becomes `93/94`. | very strong | Vtable/current metadata/full body | D1 applied at `by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md`, SHA `89085690`; old path absent | incorporate | applied |
| C02 | Target is 3,901 bytes with SHA256 `7838C2B5B07A811FE20282A537BDD01692FF9B5ADD38AB4DAA24A03B3AC9C373`. | very strong | MCP/local PE byte equality | D1 exact evidence retained in target SHA `89085690` | incorporate | applied |
| C03 | Target has 1,356 instructions, 97 blocks, complexity 46, 25 unique callees, no code caller, and one vtable data xref. | very strong | MCP disassembly/component/xref | D1 inventory retained; final generated command 14932 emits one definition | incorporate | applied |
| C04 | Source ABI/name is `virtual void OnDraw()`, not RenderUserLook or int-return pseudo-code. | very strong | Current class, primary +0x44, ignored EAX | D1/D2/D9-D11 current hashes `89085690`/`F8ACDD6C`/`674932BF`/`FCA9BA49`/`D005F812`; old names historical only | reject-stale | excluded-with-reason |
| C05 | Preserve all four background modes and the unknown-mode initialized-context blit/return. | very strong | Complete decompile/disassembly | D1 byte-equal formal; historical generated hashes through command 14864 and bounded command-14869 generated `7FAE3F87` have equal semantics | incorporate | applied |
| C06 | Preserve exact five-string width/color/position/draw order and repeated scans. | very strong | Full target body | D1 byte-equal formal at `89085690` | incorporate | applied |
| C07 | Preserve exact HumanObject NewHuman bounds/overlay/draw path. | very strong | Calls/field offsets/arithmetic | D1 applied; image support reread same-or-greater | incorporate | applied |
| C08 | Preserve exact MonsterObject selector/frame/centering/draw path. | very strong | Calls/field offsets/arithmetic | D1 applied; image support reread same-or-greater | incorporate | applied |
| C09 | Preserve all fourteen independent equipment id/palette branches and centers. | very strong | Fourteen repeated call groups | D1 applied with singleton member calls; item support unchanged | incorporate | applied |
| C10 | Preserve exchange/group disabled fill and enabled frame behavior. | very strong | Exact action branches | D1/D2/D4 hashes `89085690`/`2532A7BD`/`025BF953` | incorporate | applied |
| C11 | Rename +0xdd0/+0xdd4 to next/previous ButtonFrame state and reject hover-action/pressed-action labels. | very strong | Render reads plus mouse writes | D2/D3/D6/D7 plus current UID0003RN `83F96098`; command-14932 stale-token count zero | reject-stale | excluded-with-reason |
| C12 | Preserve mode-2 portrait, FACE fallback, partial options init, and unused NATION lookup. | very strong | Complete target body | D1/D2/D8 hashes `89085690`/`2532A7BD`/`C26A56B5` | incorporate | applied |
| C13 | Preserve ignored mode-1 Application getter result. | very strong | Call at `0x005a069a`; EAX overwritten | D1 plus Application support SHA `C685570E` | incorporate | applied |
| C14 | Preserve common INVENBUT next/previous frames and mode-3 invalid-rectangle tail. | very strong | Target/helper decompiles | D1/D4 byte-equal at `89085690`/`025BF953` | incorporate | applied |
| C15 | UID0003RP is complete `void` signed-short const geometry source at `92/94`. | very strong | 221 bytes/74 instructions/ret8/six calls | D4 byte-equal, current SHA `689EFF32`; generated once | incorporate | applied |
| C16 | UID0003RQ is complete first-hit-or-minus-one source at `92/94`; binary switch is inlined UID0003RP logic. | very strong | 319 bytes/108 instructions/two calls | D5 byte-equal, current SHA `65E7837C`; generated once | incorporate | applied |
| C17 | Hit-test argument order is y then x; current x/y labels are stale. | very strong | PointInRect canonical ABI and forwarded args | D2/D5/D6 current; generated signature `(int y, int x)` once | reject-stale | excluded-with-reason |
| C18 | UID0000FP becomes `92/94` with complete no-loss class, four enums, corrected fields and helper signature. | very strong | Current layout plus target/mouse/helper evidence | D2 byte-equal, SHA `2532A7BD`, closing brace before `[[CHILDREN]]` | incorporate | applied |
| C19 | UID0003RI retains `92/94`/position 10/body and changes only the two frame initializers to typed normal values. | very strong | Current constructor and corrected fields | D3 byte-equal, SHA `6EA83AE2`; old initializers rejected as stale | reject-stale | excluded-with-reason |
| C20 | UID0001KK is `90/93`, retains semantic owner UID0000P0 with FALSE/blank emitter/position/formal, and exact children alone emit. | very strong | Existing split and source route | D6 blank parity plus D18 RN/RR/RS/RT/RU/RV/RW extension applied at SHA `7C22B676`; no aggregate source | incorporate | applied |
| C21 | UID0000P0 is `92/93` prose-only and records the applied OnDraw/geometry source/dependency/compiler route without by-file reconstruction metadata. | very strong | Current file/source union | D7/D19 applied at SHA `A6F944CE`, with no reconstruction metadata | incorporate | applied |
| C22 | UID00038X becomes `90/93`, remains file-owned/use-site-only/blank, and records exact literal/xref roles. | very strong | Literal bytes and target uses | D8 blank parity and complete prose, SHA `C26A56B5` | incorporate | applied |
| C23 | UID00026V/UID00038R/UID00038Q gain exact primary +0x44 OnDraw and resource/source-cause detail without handwritten ABI data. | very strong | Vtable cells/current split | D9-D11 hashes `674932BF`/`FCA9BA49`/`D005F812`; generated ABI tokens zero | incorporate | applied |
| C24 | UID0003RN is UID-preservingly renamed to `UserLookPaneOnMouseEvent`, becomes complete `bool UserLookPane::OnMouseEvent(Event *event)` at `93/94`, and retains owner/emitter UID0000FP, true, blank position, and `Nested:0`; its old behavior title and `86/90` blank scope exclusion are historical. | very strong | Fresh 1,029-byte mouse decompile/disassembly/vtable/Event/source analysis | D15 applied byte-for-byte at `by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md`, SHA `83F96098`, validator 14885; old path absent | incorporate | applied |
| C25 | Shared STATBUT UID0003F4 remains `89/92`, owner NONE, emitters UID0000NL/UID0000P0, blank; target supplies two use sites only. | very strong | Ten-xref executed reports/current page | Verify-only D12 unchanged SHA `3299C358` | already-present | already-present |
| C26 | GrafPort/Surface options/RectBounds/ObjectStatus/image/palette/global pages already provide same-or-greater APIs and remain verify-only. | strong | Current declarations and sibling source | D13 reread; no concrete drift and no edit | already-present | already-present |
| C27 | No target split, new UID child, standalone resource global, raw options array, manual vtable, or compiler body is warranted; existing UID0003RV/RW are source-live file-local helpers rather than new children. | very strong | Exact ranges/CFG/raw-helper source shape | Rejected alternatives retained; D16/D17 use existing UIDs and preserve compiler/data exclusions | reject-invalid | excluded-with-reason |
| C28 | Preserve historical OnDraw/geometry split/parser/view/resource provenance while labeling the prior callback's target/helper blank-body and stale field assumptions superseded. | very strong | Current Changes/report history | D1-D24 Changes/history retained in final destination hashes; RN/RR/RS/RU/RV/RW blank history and Legend alias are explicitly historical | historicalize | applied |
| C29 | Callback-time B001-B005 work and leases were disjoint; callback still required serial destination reread/rebase. | very strong | Goals/report/lease preflight | Serial reread/lease/validate/release completed for every changed page; final B002 lease count zero | incorporate | applied |
| C30 | Exact manual coverage changes are supervisor-owned; callbacks used scoped validation per ordinary edit plus authorized waited refreshes and exact generated assertions. | very strong | Workflow/current rows/emission | Commands 14818-14932 recorded; final generated SHA `F7F27A1C`, exact handoff retained, manual edits zero | incorporate | applied |
| C31 | UID0003RN is exactly `[0x005a1580,0x005a1985)`, 1,029 bytes, SHA256 `F81AB1BB340326AA1E40ED79AF5A18B2308506B14561D3C544AD340A137F02D1`, 302 instructions, 57 blocks, complexity 27, 18 unique callees. | very strong | Fresh MCP bytes/component/disassembly | D15 evidence/body applied at SHA `83F96098`; validator 14885 | incorporate | applied |
| C32 | UID0003RN is live at secondary EventHandler vtable cell `0x0062ed20`; source signature is `virtual bool OnMouseEvent(Event *event)` with implicit compiler receiver adjustment. | very strong | Vtable bytes, ret4, current class/EventHandler declarations | D15 plus current class/file/aggregate union; generated command 14932 emits one ordinary definition | incorporate | applied |
| C33 | Cursor-move handling preserves outside-false/no-invalidate, ordered Next/Previous tests, exact Hover/Normal writes, inside-neither fast path, reset/invalidate behavior, and y/x Event payload order. | very strong | Complete mouse CFG and direct stores/calls | D15 applied byte-for-byte at SHA `83F96098`; Event support reread same-or-greater | incorporate | applied |
| C34 | Left Group/Exchange actions both deliberately gate on `m_exchangeActionState`; Group sends opcode `0x4a` plus target id and Exchange sends opcode `0x2e` plus target name, with exact always-true case returns. | very strong | Direct field loads, switch cases, inlined packet sequences | D15 calls the sole D16/D17 definitions; generated command 14932 proves one each | incorporate | applied |
| C35 | Previous/Next cases preserve exact view transition graph, `g_useEpfAssets == 1` gate, pressed/normal frame writes, invalidation, and no-transition true return. | very strong | Complete case CFG and existing view methods | D15 plus RR/RS/RT/RU generated once under command 14932 | incorporate | applied |
| C36 | Right click deletes the old SimpleHelpPane before id filtering, uses localized ids 200/201 and constructor `(text,this,x,y,5000)`, and returns false for other ids after deletion. | very strong | Complete right-click branch, current SimpleHelpPane/LanguageMan contracts | D15 applied; dependencies reread same-or-greater and unchanged | incorporate | applied |
| C37 | UID0003RV exact `[0x005a2190,0x005a2272)` is source-live file-local `SendUserLookNameCommandPacket`, `91/93`, owner/emitter UID0000P0, true, position 80, `Nested:0`. | very strong | 226-byte SHA `6AFA7683`, 72 instructions, normal prologue/ret4, RN inlined copy | UID-preserving rename and D16 applied at SHA `142593CC`; validator 14891; old path absent | incorporate | applied |
| C38 | UID0003RW exact `[0x005a2280,0x005a22da)` is source-live file-local `SendUserLookTargetActionPacket`, `91/93`, owner/emitter UID0000P0, true, position 90, `Nested:0`. | very strong | 90-byte SHA `0A8E5FA2`, 31 instructions, normal prologue/ret4, RN inlined copy | UID-preserving rename and D17 applied at SHA `594E6A5A`; validator 14892; old path absent | incorporate | applied |
| C39 | Both raw helpers preserve exact packet buffers, writer argument order, CP_ACP conversion/length narrowing/memmove/NUL behavior, queue lengths, and compiler-only cookie/range-check boundaries. | very strong | Full raw-range disassembly plus current PacketBuffer/MemoryMan/Socket APIs | D16/D17 and D18/D19 prose applied; generated command 14932 has one declaration and one definition for each helper, no compiler tail source | incorporate | applied |
| C40 | The callback validates UID0003RN/RR/RS/RU/RV/RW and bounded support serially, then wait-generates UserLookPane.cpp with one OnMouseEvent, one definition for each of four view methods and two packet helpers, no six target Empty Emitter Markers, and no duplicate/ABI source; manual rows remain supervisor-owned. | very strong | Workflow/current generated/manual state | Scoped commands 14885-14929 and waited commands 14930/14932 all exit 0/ok 1; final UserLook SHA `F7F27A1C`, Legend SHA `50614640`; exact handoff preserved | incorporate | applied |
| C41 | UID0003RR exact `[0x005a1cd0,0x005a1dee)` is a 286-byte ordinary `void UserLookPane::ShowMoreInfoView()` with SHA256 `1719900423EE89F242AE58BDE4CE8E4FC256F684EB3E70674F5545EA1F85D4BC`, 88 instructions, four blocks, complexity 2, three callers, and two trailing `0xcc` bytes. | very strong | Fresh bytes/component/disassembly/xrefs | D21 applied byte-for-byte at SHA `EDFA8EBD`; validator 14886 | incorporate | applied |
| C42 | RR preserves mode 0, exact EPF/legacy child teardown asymmetry and bounds, current-to-zero MoreInfo scroll, root-layer attach/order, final owner invalidation, and no null/return source. | very strong | Complete decompile/disassembly and current pane contracts | D21 plus class/file/aggregate prose applied; generated once under command 14932 | incorporate | applied |
| C43 | UID0003RS exact `[0x005a1df0,0x005a1f16)` is a 294-byte ordinary `void UserLookPane::ShowProfileView()` with SHA256 `38B560DAAB29FDB3F0F6918FA7372E4815D9DE19C8628654438CF95CDE45F5CA`, 90 instructions, four blocks, complexity 2, three input callers, and ten trailing `0xcc` bytes. | very strong | Fresh bytes/component/disassembly/xrefs | D22 applied byte-for-byte at SHA `8BBF02BF`; validator 14887 | incorporate | applied |
| C44 | RS preserves mode 1, duplicate three-child teardown in both branches, no EPF/current reattach, and the odd legacy reattachment/reset of MoreInfoPane rather than ProfilePane before owner invalidation. | very strong | Complete branch/body analysis | D22 and no-normalization prose applied; generated once under command 14932 | incorporate | applied |
| C45 | UID0003RU exact `[0x005a1ff0,0x005a2188)` is a 408-byte ordinary `void UserLookPane::ShowLegendView()` with SHA256 `AA1F03805ECB6322C59611F41DF10B757287A91D86ACE2DD9F0EBDBA671B0FAB`, 121 instructions, four blocks, complexity 2, two input callers, and eight trailing `0xcc` bytes. | very strong | Fresh bytes/component/disassembly/xrefs | D23 applied byte-for-byte at SHA `0DDCC117`; validator 14888 | incorporate | applied |
| C46 | RU preserves mode 3, MoreInfo/Profile teardown without Legend teardown, exact EPF/legacy bounds, EPF-only vertical offset 49, attach/order, maximum/current read order and current-to-max scroll, legacy omission of that pass, and final invalidation. | very strong | Complete decompile/disassembly and pane helper contracts | D23 plus class/file/aggregate support applied; final UserLook/Legend generation exact | incorporate | applied |
| C47 | RO and RT are already complete `92/93` source; RN's direct transition inventory is exactly RR/RS/RT/RU, so no other directly called blank source-bearing view helper remains. | very strong | Fresh RO/RT components/decompiles and RN call inventory | RO/RT verify-only at current SHAs `48F09DFB`/`681A3A24`; D21-D23 close remaining direct methods | incorporate | applied |
| C48 | LegendPane `+0x104` is inherited `m_verticalScrollBarOffset`, not `m_displayMode`; constructor value 63 and RU value 49 are exact source writes, while `+0x100/+0x108` remain horizontal offset/inset. | very strong | Fresh Legend constructor plus ScrollablePane constructor/layout/recompute and accepted external access style | D23/D24 plus UID0001HB/UID000074/UID0000KM/UID0001GL/UID0000CF/UID0000NF synchronized; final Legend source has one accepted token and zero stale tokens | reject-stale | excluded-with-reason |
| C49 | RR/RS/RU each become `92/93` with unchanged UID/range/owner/emitter/TRUE/blank position/Nested 0; support scores/routes remain unchanged and source emits only through exact member children. | very strong | Complete bodies and current metadata/ownership union | D21-D24, class/file/aggregate, current destination hashes, and exact pending manual rows reconciled | incorporate | applied |
| C50 | The expanded callback preserves all prior terminal work, validates the six new source-bearing children plus bounded field support under serial leases, wait-generates once, and proves exactly one RN/RR/RS/RT/RU/RV/RW source union with zero target markers or duplicate/ABI source. | very strong | Workflow and final command-14932 readback | All accepted callback rows complete; generated SHA `F7F27A1C`, seven new formal parity checks true, exact coverage handoff pending supervisor action, zero B002 leases | incorporate | applied |

## Positive Evidence Summary
- Target full-range local/MCP bytes are identical and both function boundaries are modeled exactly.
- Primary vtable cell `0x0062ed10` provides a unique live dispatch route; no competing owner or body exists.
- Complete decompilation closes every target branch, repeated item block, literal, helper call, and common tail.
- Packet parser, constructor, view methods, mouse writes, class layout, image libraries, and sibling SelfLook source independently converge on field types and helper semantics.
- Rectangle and hit-test helpers have complete small bodies, exact call inventories, and a natural source-level factorization.
- UID0003RN has a unique secondary-vtable route and a complete 57-block body. Event payload offsets, button fields, geometry/hit helpers, all view transitions, packet formats, help-pane construction, globals, and return paths are independently source-closed.
- UID0003RV/UID0003RW have exact raw boundaries and normal source function ABIs; behavior-identical copies in UID0003RN prove source liveness despite absent start xrefs.
- UID0003RR/RS/RU have complete small four-block bodies, exact callers, exact teardown/layout/scroll branches, clean padded boundaries, and natural member-method source. Fresh RO/RT verification proves these three were the only remaining blank direct transition callees.
- The independent LegendPane constructor and ScrollablePane field/layout family converge on inherited `m_verticalScrollBarOffset` at `+0x104`; values 63 and 49 are compatible per-instance view offsets rather than a generic display mode.
- Current source APIs supply every compile-directed dependency; only stripped private spellings and the shared options record's irrelevant bytes remain intentionally opaque.

## IDA MCP Facts
- Active evidence database: `9b0396a3`; module `NexusTK.exe`; image base `0x00400000`; worker PID 15732; health ready at collection time.
- `lookup_funcs`: target `sub_5A0640`, size `0xf3d`; rectangle helper `sub_5A1A70`, size `0xdd`; mouse `sub_5A1580`, size `0x405`; hit-test `sub_5A1B70`, size `0x13f`; RR `sub_5A1CD0`, size `0x11e`; RS `sub_5A1DF0`, size `0x126`; RT `sub_5A1F20`, size `0xc3`; RU `sub_5A1FF0`, size `0x198`.
- Target start bytes: `55 8b ec 81 ec a0 00 00 00 a1 24 2f 67 00 33 c5`; final 16 bytes: `4d fc 5f 5e 33 cd 5b e8 b6 61 02 00 8b e5 5d c3`.
- Rectangle start bytes: `55 8b ec 0f bf 45 08 53 40 56 57 83 f8 04 0f 87`.
- UID0003RN start bytes are `55 8b ec 6a ff 68 0f a3 60 00 64 a1 00 00 00 00`; exact range SHA256 is `F81AB1BB340326AA1E40ED79AF5A18B2308506B14561D3C544AD340A137F02D1`. Its secondary vtable cell is `0x0062ed20`; surrounding table bytes are `d5 23 5a 00 80 15 5a 00 a0 19 5a 00 d0 4d 54 00 e0 4d 54 00 f0 4d 54 00`.
- Target component: 97 blocks, complexity 46. Rectangle: 15/11. Hit-test: 19/12. UID0003RN: 302 instructions, 57 blocks, complexity 27, 18 unique callees, zero code callers, and one vtable data route.
- UID0003RN ends at `0x005a1985`; `[0x005a1985,0x005a1988)` is a three-byte NOP, `[0x005a1988,0x005a1998)` is a four-dword compiler switch table targeting `0x005a1789`, `0x005a16b1`, `0x005a17d9`, and `0x005a1833`, and `[0x005a1998,0x005a19a0)` is eight-byte alignment.
- UID0003RV is 226 bytes with SHA256 `6AFA768369904AE83FCF7096230ADF0E77ECCC8945B564A7768B674BC08622D1`, 72 instructions, one stack argument, `ret 4`, and exact range-check/cookie boundaries. UID0003RW is 90 bytes with SHA256 `0A8E5FA2475FDD30EE624584368672E8B34B1A36E7FA6E94EFA3759355C5FBEC`, 31 instructions, one stack argument, `ret 4`, and cookie-only compiler lowering.
- RR/RS/RU start bytes are identically `55 8b ec 83 ec 14 a1 24 2f 67 00 33 c5 89 45 fc`, consistent with local RectBounds plus compiler cookie. RR final bytes are `8b 4d fc 5f 33 cd 5e e8 45 59 02 00 8b e5 5d c3`; RS final bytes are `8b 4d fc 5f 33 cd 5e e8 1d 58 02 00 8b e5 5d c3`; RU final bytes are `20 8b 4d fc 33 cd 5e e8 ab 55 02 00 8b e5 5d c3`. RR/RS/RU hashes are respectively `1719900423EE89F242AE58BDE4CE8E4FC256F684EB3E70674F5545EA1F85D4BC`, `38B560DAAB29FDB3F0F6918FA7372E4815D9DE19C8628654438CF95CDE45F5CA`, and `AA1F03805ECB6322C59611F41DF10B757287A91D86ACE2DD9F0EBDBA671B0FAB`.
- Components: RR 88 instructions/four blocks/complexity 2; RS 90/four/2; RU 121/four/2; RO 71/18/9; RT 63/one/1. RR has three callers, RS three, RU two; all are from parser/mouse/key family routes documented below.
- Target unique callees are EPFTileContext Initialize; Application GetVersionMajor; EPFLib lookup; PaletteLib name/slot lookup; GrafPort move/color/background/text-width/text-draw/tile-frame helpers; Rect initialization/offset; NewHuman bounds/overlay/draw; Monster bounds/draw; Item glyph/draw; rectangle helper; direct sprite/fill callbacks; and security-cookie check.

## Function / Child Inventory
| UID / range | Current state | Recommended source disposition |
| --- | --- | --- |
| UID0003RI `[0x0059f260,0x0059f4fd)` | Applied `92/94`, complete constructor, position 10, SHA `6EA83AE2` | Body/score/position retained; two frame-field initializers synchronized to typed normal values. |
| UID0003RK `[0x0059f610,0x005a0626)` | `92/93`, complete `OnActivate` | Verify-only; accepted packet/layout source remains unchanged. |
| UID0003RL `[0x005a0630,0x005a0631)` | null stub | Compiler/source no-op context; unchanged. |
| UID0003RM `[0x005a0640,0x005a157d)` | Applied OnDraw path, `93/94`, complete D1, SHA `89085690` | UID-preserving rename and complete OnDraw source are current. |
| padding `[0x005a157d,0x005a1580)` | three `0xcc` bytes | Alignment outside target; no source. |
| UID0003RN `[0x005a1580,0x005a1985)` | Applied `UserLookPaneOnMouseEvent`, `93/94`, complete D15, SHA `83F96098` | UID-preserving rename/body/metadata complete; owner/emitter/TRUE/blank position/Nested 0 retained. |
| mouse tail `[0x005a1985,0x005a19a0)` | NOP, four-dword switch table, alignment | Compiler lowering outside mouse child; no source child. |
| UID0003RO `[0x005a19a0,0x005a1a6f)` | `92/93`, complete key body | Verify-only. |
| UID0003RP `[0x005a1a70,0x005a1b4d)` | Applied `92/94`, complete D4, current SHA `689EFF32` | Complete geometry source emits once. |
| helper tail `[0x005a1b4d,0x005a1b70)` | 3-byte NOP, 20-byte switch table, 12-byte alignment | Compiler inlining/table support; no source child. |
| UID0003RQ `[0x005a1b70,0x005a1caf)` | Applied `92/94`, complete D5, current SHA `65E7837C` | Complete y/x hit-test source emits once. |
| padding `[0x005a1caf,0x005a1cc0)` | 17 `0xcc` bytes | Alignment outside helper; no source. |
| UID0003RR `[0x005a1cd0,0x005a1dee)` | Applied `92/93`, complete `ShowMoreInfoView` D21, SHA `EDFA8EBD` | Owner/emitter/TRUE/blank position/Nested 0 retained; emits once. |
| padding `[0x005a1dee,0x005a1df0)` | two `0xcc` bytes | Alignment outside RR; no source. |
| UID0003RS `[0x005a1df0,0x005a1f16)` | Applied `92/93`, complete `ShowProfileView` D22, SHA `8BBF02BF` | Owner/emitter/TRUE/blank position/Nested 0 retained; emits once. |
| padding `[0x005a1f16,0x005a1f20)` | ten `0xcc` bytes | Alignment outside RS; no source. |
| UID0003RT `[0x005a1f20,0x005a1fe3)` | Current `92/93`, complete ShowBioView, SHA `681A3A24` | Verify-only; exact body/source disposition retained. |
| padding `[0x005a1fe3,0x005a1ff0)` | thirteen `0xcc` bytes | Alignment outside RT; no source. |
| UID0003RU `[0x005a1ff0,0x005a2188)` | Applied `92/93`, complete `ShowLegendView` D23, SHA `0DDCC117` | Owner/emitter/TRUE/blank position/Nested 0 retained; emits once. |
| padding `[0x005a2188,0x005a2190)` | eight `0xcc` bytes | Alignment outside RU; no source. |
| UID0003RV `[0x005a2190,0x005a2272)` | Applied `UserLookPaneSendNameCommandPacket`, `91/93`, position 80, complete D16, SHA `142593CC` | File owner/emitter UID0000P0 retained; sole file-local static definition. |
| UID0003RW `[0x005a2280,0x005a22da)` | Applied `UserLookPaneSendTargetActionPacket`, `91/93`, position 90, complete D17, SHA `594E6A5A` | File owner/emitter UID0000P0 retained; sole file-local static definition. |
| UID0003S3/UID0003S4 | adjustor/scalar destructor glue | Compiler-generated; no handwritten ABI source. |

## Direct Xref / Caller Inventory
- UID0003RM: zero direct code callers; one data xref at primary vtable cell `0x0062ed10`. No secondary/tertiary slot, raw pointer, duplicate body, callback table, or source-level direct call was found.
- UID0003RP: six calls, four from UID0003RM at `0x005a0c36`, `0x005a0ca1`, `0x005a14ff`, and `0x005a154b`, plus two from UID0003RN at `0x005a18c6` and `0x005a18d6`.
- UID0003RQ: two calls from UID0003RN. Its geometry switch is an optimized source-level reuse of UID0003RP, not an independent table owner.
- UID0003RN: zero code callers and one secondary-vtable data route at `0x0062ed20`. Direct callees are `PointInRect`, UID0003RP, UID0003RQ, four view helpers, GetMemoryMan/MemmoveWrapper, PacketBuffer byte/dword writers, QueueAndSendPacket, WideCharToMultiByte, LanguageMan string lookup, operator new, SimpleHelpPane construction, and compiler security/range-check helpers.
- UID0003RR calls originate at parser/OnActivate `0x005a05ff`, mouse `0x005a180a`, and key `0x005a1a00`. UID0003RS calls originate at mouse `0x005a17f4` and `0x005a183f`, plus key `0x005a1a2a`. UID0003RU calls originate at mouse `0x005a185b` and key `0x005a1a5a`. UID0003RT retains its accepted two mouse plus one key caller set.
- RR/RS/RU direct callees are only Pane remove/unregister/add/order/invalidate operations, RectBounds initialization, ScrollablePane current/max/apply helpers as branch-required, and the compiler cookie check. No allocation, parsing, packet send, exception source, cleanup object, or hidden view helper occurs.
- UID0003RV/UID0003RW: zero direct start xrefs and zero raw pointer matches do not make them dead. Their complete packet bodies are behavior-identical to optimized copies inside live UID0003RN; each has a normal standalone stack-argument function ABI and exact padded boundary.
- Application GetVersionMajor target call at `0x005a069a` is real but its return is overwritten; it remains an exact observed side-effect-free call.
- Fourteen ItemObjImageLib glyph/draw call pairs occur from `0x005a0d28` through `0x005a13ad`; none transfers method ownership to ItemObjImageLib.

## Documentation Evidence And IDA Status
- Evidence-time/pre-callback UID0003RM prose had correct owner/range/mode-2 evidence but a blank-body/out-of-scope conclusion. Historical command 14869 confirmed UID0003RM as the `93/94` OnDraw page with complete D1; bounded command 14880 independently reconfirms the same one-definition result while remaining explicitly time-scoped.
- Evidence-time UID0000FP/UID0003RI used stale frame names while otherwise providing accepted no-loss layout/constructor baselines. The bounded final read found UID0000FP at `92/94` with the complete class/enums/helpers at `2532A7BD`, and UID0003RI at `92/94`, position 10, with typed normal frame initializers at `6EA83AE2`.
- Evidence-time UID0003RP/UID0003RQ were `86/90` blank pages with directionally correct role prose. The bounded final read found complete `92/94` source at `025BF953`/`60C1308F`, with exact geometry, y/x order, callers, and inlining disposition.
- Evidence-time UID0003RN was the prior callback's `UserLookPaneHandleMouseEvent` `86/90` blank support page at `894F5885`. Current UID0003RN is `UserLookPaneOnMouseEvent` `93/94` at SHA `83F96098`, with complete D15 and all Event ABI, 57-block behavior, switch-table tail, button/view/packet/help, global, dependency, and compiler-boundary evidence applied.
- Evidence-time UID0003RV/RW were `85/88` blank raw-helper pages at `446EDF22`/`EE4E81BF`. Current UID0003RV/RW are UID-preservingly renamed `91/93` source emitters at SHAs `142593CC`/`594E6A5A`; D16/D17 are the sole file-local definitions, and the no-xref liveness deferral is historical.
- Evidence-time UID0003RR/RS/RU were `86/90` reconstructable blank pages at `4B5EA0B9`/`ADA3DE3E`/`C91354F2`. Current pages are complete `92/93` source at SHAs `EDFA8EBD`/`8BBF02BF`/`0DDCC117`, preserving all bodies, callers, field/global/helper types, and boundaries. UID0003RO and UID0003RT remain independently complete `92/93` read-only source.
- Evidence-time LegendPane class/file/constructor text used placeholder `m_displayMode` for `+0x104`. Current D24 and bounded UID000074/UID0000KM/UID0001GL/UID0000CF/UID0000NF support use inherited `m_verticalScrollBarOffset`, preserve all constructor/layout/caller facts, and retain the old alias only as labeled history.
- Evidence-time UID00026V/UID00038R/UID00038Q identified a generic render slot at primary `+0x44`. The bounded final read found the pages at `89/93`, `90/93`, `89/93`, identifying exact `void OnDraw()` declaration cause while retaining blank raw ABI data.
- Evidence-time UID00038X decoded `USERLOOK.PAL`, `PFLOOK.EPF`, and `NATION.EPF` but lacked use-site closure. The bounded final read found UID00038X at `90/93`, SHA `C26A56B5`, with exact UTF-16/use roles and blank direct C++; its exact manual coverage addition remained supervisor-owned and pending at that read.
- Evidence-time ApplicationGetVersionMajor links ended at stale partial range `0x005a06e1`. The bounded final read found SHA `C685570E` linked to full UID0003RM OnDraw with the ignored return recorded; getter body and score remained unchanged.

## Ranked Ownership Analysis
1. UID0000FP UserLookPane is the semantic and declaration owner for UID0003RM/RN/RP/RQ/RR/RS/RT/RU: exact `this` offsets fit its `0xddc` layout, primary and secondary vtable dispatch select virtual bodies, direct class calls select ordinary view helpers, and all pane state/member helpers are class-local.
2. UID0000P0 UserLookPane file is the sole file emitter route: constructor, OnActivate, render/input/view methods, two file-local packet helpers, local pane classes, and one MoreInfo global form one source family. UID0003RV/RW are file-owned static helpers because their ABIs use one explicit stack argument and no member receiver.
3. UID0001KK is a useful semantic range/index but cannot emit without duplicating exact children; retain owner semantics and false/non-emitting metadata.
4. Image, palette, EPF, RectGeometry, GrafPort, ObjectStatus, Application, and Event pages own dependencies only. Calls do not transfer render/helper ownership.
5. Physical vtable/resource data regenerates from declarations/use-site literals; it is evidence/support, not a canonical handwritten source owner.
- Rejected owners: GeneralPurposePanel is constructor composition only; ProfilePane/MoreInfoPane/LegendPane are child panes; ItemObjImageLib/NewHumanImageLib/MonsterImageLib render dependencies; Application is one ignored getter callee; shared STATBUT has no sole owner.

## Source Placement
- Original-style placement is the existing `NexusTK/ui/panels/UserLookPane.cpp` route under UID0000P0. UID0000FP emits the complete declaration first; UID0003RI remains constructor position 10; blank positions on UID0003RM/RN/RP/RQ preserve the existing address/source-order convention among UserLookPane member children. UID0003RV/RW use deterministic file-emitter positions 80/90 after the view methods.
- D15 places exact file-static helper prototypes immediately before `UserLookPane::OnMouseEvent`, making its calls compile-visible without adding non-member declarations to the class. D16/D17 provide the sole later matching `static void __stdcall` definitions. No by-file reconstruction metadata is introduced.
- D21-D23 are ordinary qualified UserLookPane member definitions in existing binary/source order RR, RS, RT, RU. D24 belongs to the separate LegendPane.cpp route and changes only the accepted inherited field spelling in the existing constructor body; no LegendPane body is duplicated into UserLookPane.cpp.
- Target literals remain in `OnDraw`. No standalone USERLOOK/PFLOOK/NATION/INVENBUT/STATBUT global is introduced.
- `SurfaceSpriteBlitOptions` comes from the existing complete render header. UserLookPane source owns only one local and the observed write to `mode`; it does not define or duplicate the shared type.
- Renaming the documentation target to OnDraw must propagate existing exact links while preserving UID0003RM and historical behavior-title wording in Changes/history.

## Range / Split / Padding / Reclassification Analysis
- Target range is exact and contiguous. No internal address is independently called, referenced by data, modeled as another function, or separated by padding. All 97 blocks belong to one source method.
- Predecessor parser ends `0x005a0626`; `0x005a0630-0x005a0631` is a separate null stub; target begins at `0x005a0640`. Three `0xcc` bytes after target precede mouse at `0x005a1580`.
- UID0003RP ends at `0x005a1b4d`; `[0x005a1b4d,0x005a1b70)` is compiler-owned NOP/switch-table/alignment. UID0003RQ ends at `0x005a1caf`; 17 alignment bytes precede the next view helper.
- UID0003RN ends before its three-byte NOP, four-entry switch table, and eight-byte alignment tail. These bytes are compiler lowering of its source switch and do not warrant a source child or handwritten table.
- UID0003RV has eight `0xcc` bytes before it and fourteen after it; UID0003RW begins at `0x005a2280`, ends at `0x005a22da`, and has six alignment bytes after it. Each exact range is one source helper; their cookie/range-check cold code remains compiler-owned inside the generated function.
- RR ends cleanly at `0x005a1dee`, followed by two `0xcc`; RS ends at `0x005a1f16`, followed by ten `0xcc`; RT ends at `0x005a1fe3`, followed by thirteen `0xcc`; RU ends at `0x005a2188`, followed by eight `0xcc`. Each modeled range is one ordinary source method with no internal split, tail table, cold fragment, or shared-byte ownership.
- No split/merge or new UID is warranted. The earlier callback's reclassification covered UID0003RM/RP/RQ; this repair source-promotes existing exact UID0003RN/RR/RS/RU/RV/RW without transferring bytes or ownership, while RT/RO remain complete and UID0001HB receives only a no-range-change field-token correction.
- Hit-test's duplicated switch does not justify a second source geometry body: compiler inlining explains it and human source calls UID0003RP.

## Negative Evidence Summary
- No code caller, second vtable slot, duplicate target body, callback registration, raw-start route, in-range data island, source exception/catch, allocation, cleanup, or null guard exists.
- No evidence supports `RenderUserLook` as original source spelling once the existing vtable declaration and slot are considered.
- No evidence supports hover-action/pressed-action semantics for `+0xdd0/+0xdd4`; the target reads them only as animation-frame multipliers and mouse writes them independently as next/previous visual state.
- No evidence supports reversing hit-test coordinates to x/y; canonical RectGeometry and Event contracts are y/x.
- No evidence supports skipping unknown modes before background blit, skipping mode-3 common navigation, consuming the NATION lookup result, value-initializing portrait options, collapsing repeated text scans, looping over equipment records, or removing the ignored version call.
- No manual vtable/RTTI/cookie/table/padding source and no standalone resource storage should be emitted.
- UID0003RN has no Event null guard, base-handler forward, catch block, packet failure branch, action-state normalization, help-pane preservation for non-help clicks, or cleanup beyond source-visible `delete`. Adding any would change behavior.
- UID0003RV/RW have no direct start xrefs, but the live inlined copies disprove a dead-code conclusion. No evidence supports member methods, a second packet owner, modern string/container wrappers, Unicode code page substitution, omitted local NUL writes, or removal of the explicit six-byte packet terminator.
- RR/RS/RU have no null guards, base forwards, explicit return values, exception source, allocation/free, packet work, or text mutation. No evidence supports collapsing the branch-specific repeated teardown, replacing RS's legacy MoreInfoPane attachment with ProfilePane, removing RU's EPF-only value-49 store/max-scroll pass, adding a LegendPane pre-detach, or normalizing any bounds.
- No evidence supports `m_displayMode` at LegendPane/ScrollablePane `+0x104`; its only basis was an older unresolved placeholder. Independent base layout and two exact writes support `m_verticalScrollBarOffset`. The old alias remains historical, not an accepted competing source name.

## IDA Rename / Type / Comment Recommendations
- Rename function `sub_5A0640` to `UserLookPane__OnDraw`; document source signature `void UserLookPane::OnDraw()` and primary vtable `+0x44`.
- Rename `sub_5A1A70` to `UserLookPane__GetActionButtonRect`; type as const member with signed-short action id and RectBounds output.
- Rename `sub_5A1B70` to `UserLookPane__HitTestActionButton`; type as const member returning signed short over `(int y,int x)`.
- Rename `sub_5A1580` to `UserLookPane__OnMouseEvent`; type as `bool __thiscall UserLookPane::OnMouseEvent(Event *event)` at source level and comment the compiler's secondary-facet receiver adjustment.
- Rename raw UID0003RV to file-local `SendUserLookNameCommandPacket` and raw UID0003RW to file-local `SendUserLookTargetActionPacket`; type each `static void __stdcall` with respectively `const wchar_t *` and `unsigned int` explicit parameters. These neutral names preserve proven wire shape without overclaiming protocol semantics.
- Rename `sub_5A1CD0`, `sub_5A1DF0`, and `sub_5A1FF0` to `UserLookPane__ShowMoreInfoView`, `UserLookPane__ShowProfileView`, and `UserLookPane__ShowLegendView`; type each as a no-argument `void __thiscall` member. Retain already accepted `sub_5A1F20` as `UserLookPane__ShowBioView` and RO as `UserLookPane__HandleKeyOrTextEvent`.
- Rename LegendPane/ScrollablePane field `+0x104` from historical placeholder `m_displayMode` to inherited `m_verticalScrollBarOffset`; preserve `+0x100` `m_horizontalScrollBarOffset` and `+0x108` `m_scrollBarInset`.
- Type Event payload reads as `event->m_type`, `event->m_payload.m_pointer.m_y`, and `.m_x`; retain current event constants 0/1/4 for cursor move/left down/right down.
- Type `+0xdd0/+0xdd4` as ButtonFrame-sized integers and name `m_nextButtonFrame`/`m_previousButtonFrame`.
- Retain `m_portraitFallbackFrame` with a comment that the target uses it as the frame for a result-unused NATION.EPF lookup. Do not assert a stronger original token.
- Comment the target's unknown-mode blit, mode-2 partial options initialization, mode-3 invalid common tail, and helper-table compiler disposition so future decompilation does not normalize them away.
- No IDA mutation was authorized or performed during research or callback.

## First-Draft C++ Recommendation
### Destination 1 - UID0003RM renamed target exact managed block
Target path after UID-preserving rename: `by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserLookPane::OnDraw()
{
    EPFTileContext tileContext;
    RectBounds imageBounds;
    RectBounds overlayBounds;
    RectBounds destinationBounds;
    RectBounds buttonBounds;

    tileContext.Initialize();
    void *backgroundPalette = g_pEPFLib;

    switch (m_viewMode)
    {
    case ViewMode_MoreInfo:
        g_pEPFLib->LookupLayoutEntry(L"USERLOOK.EPF", 0, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"USERLOOK.PAL");
        break;

    case ViewMode_Profile:
        (void)g_pApplication->GetVersionMajor();
        g_pEPFLib->LookupLayoutEntry(L"USERLOOK.EPF", 1, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"USERLOOK.PAL");
        break;

    case ViewMode_Bio:
        g_pEPFLib->LookupLayoutEntry(L"PFLOOK.EPF", 0, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"PFLOOK.PAL");
        break;

    case ViewMode_Legend:
        g_pEPFLib->LookupLayoutEntry(L"USERLOOK.EPF", 3, &tileContext);
        backgroundPalette =
            g_pPaletteLib->GetPaletteByName(L"USERLOOK.PAL");
        break;
    }

    g_pfnBlitSprite(this,
                     &tileContext,
                     &tileContext.bounds,
                     &m_bounds,
                     0,
                     backgroundPalette,
                     NULL);

    switch (m_viewMode)
    {
    case ViewMode_MoreInfo:
    {
        const int headerLength = static_cast<int>(wcslen(m_headerText));
        const int headerHalfWidth = GetTextWidth(m_headerText,
                                                 headerLength) / -2;
        const int headerShadowX = 35 + headerHalfWidth;
        SetTextColor(128);
        MoveTo(headerShadowX > 3 ? headerShadowX : 3, 25);
        DrawWideText(m_headerText,
                     static_cast<int>(wcslen(m_headerText)));
        SetTextColor(143);
        MoveTo(headerShadowX > 3 ? 34 + headerHalfWidth : 2, 24);
        DrawWideText(m_headerText,
                     static_cast<int>(wcslen(m_headerText)));

        const int targetNameLength =
            static_cast<int>(wcslen(m_targetUserName));
        const int targetNameHalfWidth =
            GetTextWidth(m_targetUserName, targetNameLength) / -2;
        SetTextColor(128);
        MoveTo(118 + targetNameHalfWidth, 25);
        DrawWideText(m_targetUserName,
                     static_cast<int>(wcslen(m_targetUserName)));
        SetTextColor(m_targetNameHighlighted ? 143 : 10);
        MoveTo(117 + targetNameHalfWidth, 24);
        DrawWideText(m_targetUserName,
                     static_cast<int>(wcslen(m_targetUserName)));

        const int line1Length = static_cast<int>(wcslen(m_identityLine1));
        const int line1HalfWidth =
            GetTextWidth(m_identityLine1, line1Length) / -2;
        SetTextColor(128);
        MoveTo(106 + line1HalfWidth, 45);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        SetTextColor(143);
        MoveTo(105 + line1HalfWidth, 44);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        SetTextBackColor(0);

        const int line2Length = static_cast<int>(wcslen(m_identityLine2));
        const int line2HalfWidth =
            GetTextWidth(m_identityLine2, line2Length) / -2;
        SetTextColor(128);
        MoveTo(106 + line2HalfWidth, 66);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        SetTextColor(143);
        MoveTo(105 + line2HalfWidth, 65);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));

        const int line3Length = static_cast<int>(wcslen(m_identityLine3));
        const int line3HalfWidth =
            GetTextWidth(m_identityLine3, line3Length) / -2;
        SetTextColor(128);
        MoveTo(106 + line3HalfWidth, 87);
        DrawWideText(m_identityLine3,
                     static_cast<int>(wcslen(m_identityLine3)));
        SetTextColor(143);
        MoveTo(105 + line3HalfWidth, 86);
        DrawWideText(m_identityLine3,
                     static_cast<int>(wcslen(m_identityLine3)));

        if (m_status.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            g_pNewHumanImageLib->CalculateBounds(&m_status,
                                                 2,
                                                 0,
                                                 0,
                                                 &imageBounds,
                                                 0,
                                                 0,
                                                 1,
                                                 0);
            g_pNewHumanImageLib->ComputeOverlayBounds(&m_status,
                                                      2,
                                                      0,
                                                      0,
                                                      &overlayBounds,
                                                      0,
                                                      1);

            destinationBounds.bottom = 187;
            destinationBounds.top =
                187 - (imageBounds.bottom - imageBounds.top);
            destinationBounds.left = 54;
            destinationBounds.right =
                54 + (imageBounds.right - imageBounds.left);
            OffsetRect(&destinationBounds, overlayBounds.left, 0);
            destinationBounds.left +=
                imageBounds.left - overlayBounds.left;
            destinationBounds.right +=
                imageBounds.right - overlayBounds.right;

            g_pNewHumanImageLib->Draw(this,
                                      &destinationBounds,
                                      &m_status,
                                      2,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0.0f,
                                      0,
                                      1,
                                      0);
        }
        else if (m_status.m_statusKind == ObjectStatusBlob::MonsterObject)
        {
            g_pMonsterImageLib->ComputeRenderBounds(&m_status,
                                                    7,
                                                    0,
                                                    &imageBounds,
                                                    NULL);
            const int width = imageBounds.right - imageBounds.left;
            const int height = imageBounds.bottom - imageBounds.top;
            const int halfWidth = width / -2;
            const int halfHeight = height / -2;
            destinationBounds.left = 78 + halfWidth;
            destinationBounds.right = 78 + width + halfWidth;
            destinationBounds.top = 131 + halfHeight;
            destinationBounds.bottom = 131 + height + halfHeight;

            g_pMonsterImageLib->RenderMonsterImage(this,
                                                   &destinationBounds,
                                                   &m_status,
                                                   7,
                                                   0,
                                                   0,
                                                   0,
                                                   NULL,
                                                   0.0f);
        }

        GetActionButtonRect(ActionButton_Exchange, &buttonBounds);
        if (m_exchangeActionState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_exchangeActionState ? 8 : 3,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetActionButtonRect(ActionButton_Group, &buttonBounds);
        if (m_groupActionState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_groupActionState ? 7 : 2,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }
        break;
    }

    case ViewMode_Profile:
    {
        if (m_bodyId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_bodyId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 92 + halfHeight;
            destinationBounds.bottom =
                92 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_bodyId),
                                              m_bodyPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_leftHandId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_leftHandId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 150 + halfWidth;
            destinationBounds.right =
                150 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 92 + halfHeight;
            destinationBounds.bottom =
                92 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_leftHandId),
                                              m_leftHandPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_rightHandId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_rightHandId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 92 + halfHeight;
            destinationBounds.bottom =
                92 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_rightHandId),
                                              m_rightHandPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_headId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_headId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 36 + halfHeight;
            destinationBounds.bottom =
                36 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_headId),
                                              m_headPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_faceAccessory1Id != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_faceAccessory1Id,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 36 + halfWidth;
            destinationBounds.right =
                36 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 36 + halfHeight;
            destinationBounds.bottom =
                36 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_faceAccessory1Id),
                m_faceAccessory1Palette,
                NULL,
                0.0f);
        }

        if (m_headAccessory2Id != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_headAccessory2Id,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 150 + halfWidth;
            destinationBounds.right =
                150 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 36 + halfHeight;
            destinationBounds.bottom =
                36 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_headAccessory2Id),
                m_headAccessory2Palette,
                NULL,
                0.0f);
        }

        if (m_rightAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_rightAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 147 + halfWidth;
            destinationBounds.right =
                147 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 146 + halfHeight;
            destinationBounds.bottom =
                146 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightAccessoryId),
                m_rightAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_leftAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_leftAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 146 + halfHeight;
            destinationBounds.bottom =
                146 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_leftAccessoryId),
                m_leftAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_leftSubAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_leftSubAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 198 + halfHeight;
            destinationBounds.bottom =
                198 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_leftSubAccessoryId),
                m_leftSubAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_rightSubAccessoryId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_rightSubAccessoryId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 150 + halfWidth;
            destinationBounds.right =
                150 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 198 + halfHeight;
            destinationBounds.bottom =
                198 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightSubAccessoryId),
                m_rightSubAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_necklaceId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_necklaceId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 146 + halfHeight;
            destinationBounds.bottom =
                146 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_necklaceId),
                                              m_necklacePalette,
                                              NULL,
                                              0.0f);
        }

        if (m_footId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_footId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 34 + halfWidth;
            destinationBounds.right =
                34 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 250 + halfHeight;
            destinationBounds.bottom =
                250 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_footId),
                                              m_footPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_coatId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_coatId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 250 + halfHeight;
            destinationBounds.bottom =
                250 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_coatId),
                                              m_coatPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_mantleId != 0)
        {
            g_pItemObjImageLib->GetItemGlyphBounds(m_mantleId,
                                                   &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 198 + halfHeight;
            destinationBounds.bottom =
                198 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_mantleId),
                                              m_mantlePalette,
                                              NULL,
                                              0.0f);
        }
        break;
    }

    case ViewMode_Bio:
    {
        RectBounds portraitBounds;
        InitRectBounds(&portraitBounds, 70, 48, 118, 104);
        void *portraitPalette =
            g_pPaletteLib->GetSlotPalette(13, 0, 0);

        if (m_portraitPayloadLength != 0)
        {
            g_pfnBlitSprite(this,
                             &m_portraitImage,
                             &m_portraitImage.bounds,
                             &portraitBounds,
                             0,
                             portraitPalette,
                             NULL);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"FACE.EPF",
                                         m_statusEncoding != 0,
                                         &tileContext);
            SurfaceSpriteBlitOptions portraitOptions;
            portraitOptions.mode = 4;
            g_pfnBlitSprite(this,
                             &tileContext,
                             &tileContext.bounds,
                             &portraitBounds,
                             1,
                             NULL,
                             &portraitOptions);
        }

        g_pEPFLib->LookupLayoutEntry(L"NATION.EPF",
                                     m_portraitFallbackFrame,
                                     &tileContext);
        break;
    }

    case ViewMode_Legend:
        break;

    default:
        return;
    }

    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF",
                                 7 * m_nextButtonFrame + 6,
                                 &tileContext);
    GetActionButtonRect(ActionButton_Next, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);

    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF",
                                 7 * m_previousButtonFrame + 5,
                                 &tileContext);
    GetActionButtonRect(ActionButton_Previous, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID0000FP complete class exact managed block
Path: `by-class/UserLookPane.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class MoreInfoPane;
class ProfilePane;
class LegendPane;

extern MoreInfoPane *g_pMoreInfoPane;

class UserLookPane : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_MoreInfo = 0,
        ViewMode_Profile = 1,
        ViewMode_Bio = 2,
        ViewMode_Legend = 3
    };

    enum ActionButtonId
    {
        ActionButton_Group = 0,
        ActionButton_Exchange = 1,
        ActionButton_Previous = 2,
        ActionButton_Next = 3
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    enum ButtonFrame
    {
        ButtonFrame_Normal = 0,
        ButtonFrame_Hover = 1,
        ButtonFrame_Pressed = 2
    };

    UserLookPane();
    virtual ~UserLookPane();

    virtual void OnDraw();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool OnMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

    void GetActionButtonRect(short actionId, RectBounds *bounds) const;
    short HitTestActionButton(int y, int x) const;
    void ShowMoreInfoView();
    void ShowProfileView();
    void ShowBioView();
    void ShowLegendView();

private:
    MoreInfoPane *m_moreInfoPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_identityLine3[256];
    wchar_t m_headerText[128];
    wchar_t m_targetUserName[128];
    wchar_t m_moreInfoText[256];
    ObjectStatusBlob m_status;
    unsigned short m_bodyId;
    unsigned char m_bodyPalette;
    unsigned char m_bodyPadding;
    unsigned short m_leftHandId;
    unsigned char m_leftHandPalette;
    unsigned char m_leftHandPadding;
    unsigned short m_rightHandId;
    unsigned char m_rightHandPalette;
    unsigned char m_rightHandPadding;
    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned char m_headPadding;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned char m_rightAccessoryPadding;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned char m_leftAccessoryPadding;
    unsigned short m_faceAccessory1Id;
    unsigned short m_headAccessory2Id;
    unsigned char m_faceAccessory1Palette;
    unsigned char m_headAccessory2Palette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;
    unsigned short m_necklaceId;
    unsigned char m_necklacePalette;
    unsigned char m_necklacePadding;
    unsigned short m_footId;
    unsigned char m_footPalette;
    unsigned char m_footPadding;
    unsigned short m_coatId;
    unsigned char m_coatPalette;
    unsigned char m_coatPadding;
    unsigned short m_mantleId;
    unsigned char m_mantlePalette;
    unsigned char m_trailingProfileState;
    unsigned char m_targetNameHighlighted;
    unsigned char m_paddingB7D[3];
    unsigned int m_targetObjectId;
    unsigned char m_exchangeActionState;
    unsigned char m_groupActionState;
    unsigned char m_portraitFallbackFrame;
    unsigned char m_moreInfoLength;
    unsigned short m_portraitPayloadLength;
    unsigned char m_paddingB8A[2];
    _AUTOBUF<unsigned char> m_portraitBuffer;
    unsigned char m_profileTextLength;
    unsigned char m_paddingB99;
    wchar_t m_profileText[256];
    unsigned char m_paddingD9A[2];
    EPFTileContext m_portraitImage;
    int m_viewMode;
    unsigned char m_statusEncoding;
    unsigned char m_paddingDC9[7];
    ButtonFrame m_nextButtonFrame;
    ButtonFrame m_previousButtonFrame;
    unsigned short m_serverProfileValue;
    unsigned char m_paddingDDA[2];
};

typedef char UserLookPaneSizeMustBeDDC[
    (sizeof(UserLookPane) == 0xddc) ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID0003RI constructor synchronized exact managed block
Path: `by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserLookPane::UserLookPane()
{
    m_status.m_displayStatusByte = 0x50;
    m_portraitImage.Initialize();

    m_moreInfoPane = new MoreInfoPane;
    g_pMoreInfoPane = m_moreInfoPane;
    m_moreInfoPane->SetMode(1);
    m_moreInfoPane->SetEditActiveState(false, false);

    m_profilePane = new ProfilePane;
    m_profilePane->SetMode(1);
    m_profilePane->SetEditActiveState(false, false);

    m_legendPane = new LegendPane;
    m_legendPane->SetMode(1);
    m_moreInfoPane->SetEditActiveState(false, false);

    m_status.m_statusKind = ObjectStatusBlob::HumanObject;
    m_status.m_appearanceId = 0;
    m_status.m_bodyId = 0;
    m_status.m_weaponId = 0;
    m_status.m_bodyColor = 0;
    m_status.m_shieldOrArrowId = 0;
    m_status.m_fullBodyId = 0;

    m_headId = 0;
    m_rightAccessoryId = 0;
    m_leftAccessoryId = 0;
    m_status.m_compositionMode = 0;

    m_identityLine2[0] = 0;
    m_identityLine1[0] = 0;
    m_headerText[0] = 0;
    m_targetUserName[0] = 0;

    m_targetObjectId = 0;
    m_portraitFallbackFrame = 0;
    m_exchangeActionState = 0xff;
    m_groupActionState = 0xff;
    m_viewMode = ViewMode_Profile;
    m_profileText[0] = 0;
    m_nextButtonFrame = ButtonFrame_Normal;
    m_previousButtonFrame = ButtonFrame_Normal;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - UID0003RP exact managed block
Path: `by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserLookPane::GetActionButtonRect(
    short actionId,
    RectBounds *bounds) const
{
    int left = -1;
    int top = -1;
    int right = -1;
    int bottom = -1;

    switch (actionId)
    {
    case ActionButton_Group:
        if (m_viewMode == ViewMode_MoreInfo)
        {
            left = 146;
            top = 112;
            right = 182;
            bottom = 148;
        }
        break;

    case ActionButton_Exchange:
        if (m_viewMode == ViewMode_MoreInfo)
        {
            left = 146;
            top = 148;
            right = 182;
            bottom = 184;
        }
        break;

    case ActionButton_Previous:
        if (m_viewMode == ViewMode_Profile ||
            m_viewMode == ViewMode_Bio)
        {
            left = 149;
            top = 268;
            right = 167;
            bottom = 286;
        }
        break;

    case ActionButton_Next:
        if (m_viewMode == ViewMode_MoreInfo ||
            m_viewMode == ViewMode_Profile ||
            m_viewMode == ViewMode_Bio)
        {
            left = 169;
            top = 268;
            right = 187;
            bottom = 286;
        }
        break;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - UID0003RQ exact managed block
Path: `by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short UserLookPane::HitTestActionButton(int y, int x) const
{
    RectBounds bounds;

    for (short actionId = ActionButton_Group;
         actionId <= ActionButton_Next;
         ++actionId)
    {
        GetActionButtonRect(actionId, &bounds);
        if (PointInRect(y, x, &bounds))
            return actionId;
    }

    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - UID0001KK retained non-emitting aggregate block
Path: `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - UID0000P0 prose-only file route
Path: `by-file/UserLookPane.md`. This destination must not gain reconstruction metadata or a managed block. It records the full OnDraw/helper/literal/header/compiler route and preserves all current local pane, packet, view, singleton, and history content.

### Destination 8 - UID00038X retained blank resource-data block
Path: `by-memory/0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

The additive D15-D17 and D21-D24 blocks are placed here so all fourteen literal managed blocks remain contiguous; accepted prose-only D9-D14 follows unchanged in destination identity, then D18-D20 records the support union.

### Destination 15 - UID0003RN complete mouse-handler managed block
UID-preserving target path: `by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md`. Applied metadata is `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000FP`, `EMITTER_UIDS:0000FP`, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall SendUserLookNameCommandPacket(
    const wchar_t *targetName);
static void __stdcall SendUserLookTargetActionPacket(
    unsigned int targetObjectId);

bool UserLookPane::OnMouseEvent(Event *event)
{
    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;

    switch (event->m_type)
    {
    case kEventCursorMove:
    {
        if (!PointInRect(y, x, &m_bounds))
        {
            m_nextButtonFrame = ButtonFrame_Normal;
            m_previousButtonFrame = ButtonFrame_Normal;
            return false;
        }

        RectBounds nextBounds;
        RectBounds previousBounds;
        GetActionButtonRect(ActionButton_Next, &nextBounds);
        GetActionButtonRect(ActionButton_Previous, &previousBounds);

        if (PointInRect(y, x, &nextBounds))
        {
            m_nextButtonFrame = ButtonFrame_Hover;
            m_previousButtonFrame = ButtonFrame_Normal;
            InvalidateRect(&m_bounds);
            return true;
        }

        if (PointInRect(y, x, &previousBounds))
        {
            m_nextButtonFrame = ButtonFrame_Normal;
            m_previousButtonFrame = ButtonFrame_Hover;
            InvalidateRect(&m_bounds);
            return true;
        }

        if (m_nextButtonFrame == ButtonFrame_Normal &&
            m_previousButtonFrame == ButtonFrame_Normal)
        {
            return true;
        }

        m_nextButtonFrame = ButtonFrame_Normal;
        m_previousButtonFrame = ButtonFrame_Normal;
        InvalidateRect(&m_bounds);
        return true;
    }

    case kEventLeftButtonDown:
        switch (HitTestActionButton(y, x))
        {
        case ActionButton_Group:
            if (m_exchangeActionState != ButtonVisualState_Disabled)
                SendUserLookTargetActionPacket(m_targetObjectId);
            return true;

        case ActionButton_Exchange:
            if (m_exchangeActionState != ButtonVisualState_Disabled)
                SendUserLookNameCommandPacket(m_targetUserName);
            return true;

        case ActionButton_Previous:
            if (m_viewMode == ViewMode_Legend)
                ShowBioView();
            else if (m_viewMode == ViewMode_Bio)
                ShowProfileView();
            else if (m_viewMode == ViewMode_Profile &&
                     g_useEpfAssets == 1)
                ShowMoreInfoView();

            m_nextButtonFrame = ButtonFrame_Normal;
            m_previousButtonFrame = ButtonFrame_Pressed;
            InvalidateRect(&m_bounds);
            return true;

        case ActionButton_Next:
            if (m_viewMode == ViewMode_MoreInfo)
                ShowProfileView();
            else if (m_viewMode == ViewMode_Profile)
                ShowBioView();
            else if (m_viewMode == ViewMode_Bio)
                ShowLegendView();

            m_nextButtonFrame = ButtonFrame_Pressed;
            m_previousButtonFrame = ButtonFrame_Normal;
            InvalidateRect(&m_bounds);
            return true;

        default:
            return false;
        }

    case kEventRightButtonDown:
    {
        const short actionId = HitTestActionButton(y, x);
        delete g_pSimpleHelpPane;

        switch (actionId)
        {
        case ActionButton_Group:
            new SimpleHelpPane(
                g_pLanguageMan->GetLocalizedString(200),
                this, x, y, 5000);
            return true;

        case ActionButton_Exchange:
            new SimpleHelpPane(
                g_pLanguageMan->GetLocalizedString(201),
                this, x, y, 5000);
            return true;

        default:
            return false;
        }
    }

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 21 - UID0003RR complete MoreInfo view managed block
Path: `by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md`. Applied metadata is `COMPLETION:92`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000FP`, `EMITTER_UIDS:0000FP`, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserLookPane::ShowMoreInfoView()
{
    m_viewMode = ViewMode_MoreInfo;

    RectBounds moreInfoBounds;
    if (g_useEpfAssets == 1)
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();
        InitRectBounds(&moreInfoBounds, 7, 205, 182, 266);
    }
    else
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        InitRectBounds(&moreInfoBounds, 17, 192, 174, 251);
    }

    const unsigned short currentPosition =
        m_moreInfoPane->GetScrollPosition(0);
    m_moreInfoPane->ApplyScrollPosition(0, currentPosition, 0);
    m_moreInfoPane->AddToLayer(
        &moreInfoBounds,
        0,
        this,
        g_mainUiLayerSlots.rootPaneLayerContext);
    m_moreInfoPane->SetPaneOrder(0, this);
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 22 - UID0003RS complete Profile view managed block
Path: `by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md`. Applied metadata is `COMPLETION:92`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000FP`, `EMITTER_UIDS:0000FP`, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserLookPane::ShowProfileView()
{
    m_viewMode = ViewMode_Profile;

    if (g_useEpfAssets == 1)
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();
    }
    else
    {
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_legendPane->RemoveFromLayer();
        m_legendPane->UnregisterEventHandler();

        RectBounds profileViewBounds;
        InitRectBounds(&profileViewBounds, 17, 192, 174, 251);
        const unsigned short currentPosition =
            m_moreInfoPane->GetScrollPosition(0);
        m_moreInfoPane->ApplyScrollPosition(0, currentPosition, 0);
        m_moreInfoPane->AddToLayer(
            &profileViewBounds,
            0,
            this,
            g_mainUiLayerSlots.rootPaneLayerContext);
        m_moreInfoPane->SetPaneOrder(0, this);
    }

    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 23 - UID0003RU complete Legend view managed block
Path: `by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md`. Applied metadata is `COMPLETION:92`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000FP`, `EMITTER_UIDS:0000FP`, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserLookPane::ShowLegendView()
{
    m_viewMode = ViewMode_Legend;

    RectBounds legendBounds;
    if (g_useEpfAssets == 1)
    {
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        InitRectBounds(&legendBounds, 7, 15, 182, 265);

        const unsigned short currentPosition =
            m_legendPane->GetScrollPosition(0);
        m_legendPane->ApplyScrollPosition(0, currentPosition, 0);
        m_legendPane->m_verticalScrollBarOffset = 49;
        m_legendPane->AddToLayer(
            &legendBounds,
            0,
            this,
            g_mainUiLayerSlots.rootPaneLayerContext);
        m_legendPane->SetPaneOrder(0, this);

        const unsigned short maximumPosition =
            m_legendPane->GetScrollMax(0);
        const unsigned short currentPositionAfterAttach =
            m_legendPane->GetScrollPosition(0);
        m_legendPane->ApplyScrollPosition(
            0, currentPositionAfterAttach, maximumPosition);
    }
    else
    {
        m_moreInfoPane->RemoveFromLayer();
        m_moreInfoPane->UnregisterEventHandler();
        m_profilePane->RemoveFromLayer();
        m_profilePane->UnregisterEventHandler();
        InitRectBounds(&legendBounds, 17, 36, 174, 251);

        const unsigned short currentPosition =
            m_legendPane->GetScrollPosition(0);
        m_legendPane->ApplyScrollPosition(0, currentPosition, 0);
        m_legendPane->AddToLayer(
            &legendBounds,
            0,
            this,
            g_mainUiLayerSlots.rootPaneLayerContext);
        m_legendPane->SetPaneOrder(0, this);
    }

    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 24 - UID0001HB inherited vertical-offset field synchronization managed block
Path: `by-memory/0x0056c400-0x0056c493.LegendPane.md`. Preserve `88/91`, owner/emitter UID000074, true, blank optional position, and `Nested:0`; change only the stale source-facing field token while preserving the complete constructor.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LegendPane::LegendPane()
    : TextEditPane(g_useEpfAssets ? 175 : 145,
                   g_useEpfAssets ? 229 : 180,
                   g_useEpfAssets ? 160 : 145,
                   g_useEpfAssets ? 229 : 180,
                   128,
                   0,
                   false,
                   true,
                   6,
                   static_cast<unsigned short>(IsLegacyAssetMode()),
                   true,
                   0)
{
    m_verticalScrollBarOffset = 63;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 16 - UID0003RV file-local name-packet helper managed block
UID-preserving target path: `by-memory/0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket.md`. Applied metadata is `COMPLETION:91`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000P0`, `EMITTER_UIDS:0000P0`, `RECONSTRUCTABLE:TRUE`, position 80, and `Nested:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall SendUserLookNameCommandPacket(
    const wchar_t *targetName)
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (targetName[0] == L'\0')
        return;

    unsigned char packet[300];
    char convertedText[256];

    PacketBufferWriteUInt8(0x2e, packet);

    const short sourceLength =
        static_cast<short>(wcslen(targetName));
    const unsigned int textLength =
        static_cast<unsigned int>(
            WideCharToMultiByte(
                CP_ACP, 0,
                targetName, sourceLength,
                convertedText, 256,
                NULL, NULL));

    convertedText[textLength] = '\0';
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(textLength),
        packet + 1);
    memoryMan->MemmoveWrapper(
        packet + 2, convertedText, textLength);

    const unsigned int packetLength = textLength + 2;
    packet[packetLength] = '\0';
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 17 - UID0003RW file-local target-action packet helper managed block
UID-preserving target path: `by-memory/0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket.md`. Applied metadata is `COMPLETION:91`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000P0`, `EMITTER_UIDS:0000P0`, `RECONSTRUCTABLE:TRUE`, position 90, and `Nested:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall SendUserLookTargetActionPacket(
    unsigned int targetObjectId)
{
    unsigned char packet[16];
    PacketBufferWriteUInt8(0x4a, packet);
    PacketBufferWriteUInt8(0, packet + 1);
    PacketBufferWriteUInt32BE(targetObjectId, packet + 2);
    packet[6] = 0;
    g_packetSender->QueueAndSendPacket(packet, 6);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destinations 9-12 - vtable/read-only/shared-resource prose and no-code state
- D9 UID00026V UserLookReadOnlyData: retain blank data C++, add exact primary `+0x44 -> UID0003RM OnDraw`, secondary EventHandler `+0x04 -> UID0003RN OnMouseEvent`, source helpers, resource-use closure, and source-generated disposition.
- D10 UID00038R UserLookPaneVtableData: retain blank compiler-data C++, add exact primary `+0x44` OnDraw and secondary `+0x04` OnMouseEvent roles and declaration-cause evidence.
- D11 UID00038Q UserLookPaneFamilyVtables: retain blank type/layout C++, add the primary OnDraw and secondary OnMouseEvent slots while preserving complete secondary/local-pane tables.
- D12 UID0003F4 SharedStatButtonEpfResourceString: verify-only at `89/92`, owner NONE, emitters UID0000NL/UID0000P0, blank direct C++; add no source duplicate.

### Destinations 13-14 and 18-20 - dependency and stale-link support
- D13 verify-only: GrafPort, SurfaceSpriteBlitOptions, RectBounds/RectGeometry, ObjectStatusBlob, EPFTileContext, Application, EPFLib, PaletteLib, ItemObjImageLib, NewHumanImageLib, MonsterImageLib, and unrelated global-pointer pages remain unchanged unless callback reread proves a concrete contradiction.
- D14 bounded prose/link sync: UID0003RP/UID0003RQ cross-links, ApplicationGetVersionMajor's stale partial-range target link, and any validator-propagated exact old target-path links retain the accepted OnDraw/frame/coordinate/full-range correction.
- D18 UID0001KK aggregate and D19 UID0000P0 file prose: add UID0003RN complete mouse source, complete RR/RS/RU views around existing RT, plus UID0003RV/RW file-local definitions, positions, packet/view/helper/dependency/compiler boundaries; parent remains false/non-emitting and by-file remains prose-only with no reconstruction metadata.
- D20 bounded verify/sync support is complete: UID0000FP already declared `OnMouseEvent` and all four view methods, so its class formal remains unchanged while current evidence and the last stale frame-label sentence were synchronized; Event/by-file Event retain exact type and y-at-`+0x08`/x-at-`+0x0c`; MoreInfoPane/ProfilePane, packet writers, QueueAndSendPacket, MemoryMan, LanguageMan, SimpleHelpPane, globals, UID0003RO/RT, and vtable/read-only pages were verified same-or-greater and unchanged. LegendPane/ScrollablePane received only the directly stale inherited-field prose/formal correction. No duplicate definition or unrelated change was introduced.

## Final Recommendation
- Destinations 1-24 are implemented or verified exactly. The source-bearing inventory has one OnDraw, one OnMouseEvent, two geometry helpers, all four view transitions, and two file-local packet helpers under the complete UserLookPane class/file route. LegendPane retains its separate source route, inherited vertical-offset field use is synchronized, and no parent/resource/vtable duplicate source is introduced.
- Applied scores are `93/94` for UID0003RM/RN, `92/94` for UID0003RP/RQ and UID0000FP, `92/93` for UID0003RR/RS/RT/RU and UID0000P0, `91/93` for UID0003RV/RW, `90/93` for UID0001KK/UID00038X/UID00038R, and `89/93` for UID00026V/UID00038Q. Bounded LegendPane/ScrollablePane support scores remain unchanged.
- Historical behavior-title, blank-body, action-index, and x/y assumptions remain documented as superseded rather than deleted.

## Recommended Target Doc Changes
- Applied UID-preserving rename to `by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md`.
- Applied metadata `93/94`, owner/emitter UID0000FP, true, blank position, `Nested:0`.
- Installed Destination 1 byte-for-byte and added complete range/hash/mapping/instruction/CFG/vtable/caller/callee/mode/text/status/equipment/portrait/action/resource/compiler/negative evidence.
- Replaced the pre-callback out-of-scope/blank recommendation with source-ready truth while retaining it as labeled historical provenance.

## Recommended Support Doc Changes
- Applied UID0000FP `92/94`, exact Destination 2 class, retained complete layout, four enums, corrected frame fields, y/x hit-test declaration, and full target/helper evidence.
- Applied UID0003RI field-name-only Destination 3 synchronization while preserving `92/94`, position 10, and every constructor fact.
- Applied UID0003RP/UID0003RQ `92/94`, complete Destinations 4/5, and all matrix/call/range/hash/instruction/CFG/table/inlining evidence.
- The prior UID0003RN support-only `86/90`/blank sync remains valid historical callback evidence but is superseded. The UID-preserving `UserLookPaneOnMouseEvent` rename, `93/94`, complete Destination 15, exact Event/vtable/branch/button/view/packet/help/compiler evidence, and unchanged owner/emitter/TRUE/blank position/Nested 0 are applied.
- UID0003RV/RW are UID-preservingly renamed, `91/93`, positions 80/90, with complete Destinations 16/17. Both remain file-owned/emitted by UID0000P0 and are the sole file-local packet-helper definitions.
- UID0003RR/RS/RU are `92/93` with unchanged UID/range/owner/emitter/TRUE/blank position/Nested 0 and complete Destinations 21-23. Every EPF/legacy branch asymmetry, child teardown, bounds, scroll sequence, root-layer attach/order, and final invalidation is preserved. UID0003RO/RT remain verify-only complete `92/93` source.
- D24 is applied as a no-loss field-name correction to UID0001HB: its `88/91` body/metadata is preserved and historical `m_displayMode = 63` is replaced by inherited `m_verticalScrollBarOffset = 63`. UID000074/UID0000KM and UID0001GL/UID0000CF/UID0000NF now make `+0x104` unambiguously the vertical scrollbar offset while preserving all other evidence and scores.
- Preserve UID00008Q MoreInfoPane and UID0000AV ProfilePane at complete `90/92` with unchanged class formals/ownership. Add only exact RR/RS use prose where current text omits branch-specific teardown/attachment: RR activates MoreInfoPane; RS legacy mode counterintuitively reattaches MoreInfoPane after removing all three children. Neither method transfers ownership or changes the local pane class bodies.
- Applied UID0001KK `90/93`, semantic owner UID0000P0, FALSE/blank emitter/position/formal, complete child inventory, and no duplicate parent source.
- Applied UID0000P0 `92/93` prose-only D19 source-order/helper/view/dependency update with no by-file reconstruction metadata.
- Applied UID00038X `90/93`, file-owned/reconstructable but blank direct source with exact literal/use evidence.
- Applied UID00026V `89/93`, UID00038R `90/93`, and UID00038Q `89/93` with exact OnDraw declaration-cause and no handwritten ABI data.
- Applied ApplicationGetVersionMajor full-range OnDraw link/ignored-result correction while preserving getter body/score.
- Verified UID0003F4 and render D13 dependencies same-or-greater. D20 limits Event, packet, MemoryMan, LanguageMan, SimpleHelpPane, pane/global/view, LegendPane/ScrollablePane, and vtable support to exact no-loss prose/declaration synchronization only where callback reread proves stale RN/RR/RS/RU/RV/RW or `m_displayMode` disposition.

## Score And Metadata Recommendation
| UID | Evidence-time | Applied/current | Owner/emitter/reconstructable/position/nesting | Rationale |
| --- | ---: | ---: | --- | --- |
| 0003RM | 86/90 | 93/94 | 0000FP/0000FP/TRUE/blank/0 | Complete 3,901-byte body, unique vtable route, exact dependencies and source shape. |
| 0003RP | 86/90 | 92/94 | 0000FP/0000FP/TRUE/blank/0 | Complete matrix/body and six calls; only lexical labels inferred. |
| 0003RQ | 86/90 | 92/94 | 0000FP/0000FP/TRUE/blank/0 | Complete first-hit body, coordinate order, callers, and inlining proof. |
| 0003RN | 86/90 blank | applied 93/94 | 0000FP/0000FP/TRUE/blank/0 | Complete 1,029-byte virtual mouse body, unique secondary-vtable route, Event/button/view/packet/help behavior, and source/compiler closure. |
| 0003RR | 86/90 blank | applied 92/93 | 0000FP/0000FP/TRUE/blank/0 | Complete 286-byte MoreInfo branch/teardown/layout/scroll body and three callers. |
| 0003RS | 86/90 blank | applied 92/93 | 0000FP/0000FP/TRUE/blank/0 | Complete 294-byte Profile-mode body, exact branch duplication, and legacy MoreInfoPane oddity. |
| 0003RT | 92/93 | 92/93 verify-only | 0000FP/0000FP/TRUE/blank/0 | Freshly revalidated complete Bio body and three callers. |
| 0003RU | 86/90 blank | applied 92/93 | 0000FP/0000FP/TRUE/blank/0 | Complete 408-byte Legend branch/scroll/offset/max body and two callers. |
| 0003RV | 85/88 blank | applied 91/93 | 0000P0/0000P0/TRUE/80/0 | Exact 226-byte file-local name-packet helper, live inlined copy, complete CP_ACP serialization source. |
| 0003RW | 85/88 blank | applied 91/93 | 0000P0/0000P0/TRUE/90/0 | Exact 90-byte file-local target-action helper, live inlined copy, complete six-byte packet source. |
| 0000FP | 91/93 | 92/94 | 0000P0/0000P0/TRUE/0 | Complete no-loss layout plus resolved method/enum/frame/helper declaration surface. |
| 0003RI | 92/94 | 92/94 | 0000FP/0000FP/TRUE/10/4 | Same complete constructor; names synchronized only. |
| 0001KK | 89/92 | 90/93 | 0000P0/blank/FALSE/blank/0 | More exact children complete; retains file-family semantic ownership while remaining a non-emitting index. |
| 0000P0 | 91/92 | 92/93 | FILE/NONE/TRUE/blank | Source family now has complete paint and geometry route; prose-only file page. |
| 00038X | 85/90 | 90/93 | 0000P0/0000P0/TRUE/blank/0 | Exact literal bytes/uses resolved; direct storage stays source-generated. |
| 00026V | 86/91 | 89/93 | 0000P0/0000P0/TRUE/blank/-4 | Exact split, primary OnDraw route, and resource tail closed. |
| 00038R | 88/92 | 90/93 | 00038Q/00038Q/TRUE/blank/4 | Primary/secondary/tertiary slots complete; raw data remains compiler-generated. |
| 00038Q | 87/91 | 89/93 | 0000P0/0000P0/TRUE/blank | Complete source-local vtable family including primary OnDraw. |
| 0001HB | 88/91 | 88/91 applied field sync | 000074/000074/TRUE/blank/0 | Complete constructor unchanged except accepted inherited `m_verticalScrollBarOffset` token replaces stale placeholder. |
| 000074 | 91/93 | 91/93 applied prose sync | 0000KM/0000KM/TRUE/blank | Complete LegendPane declaration/route unchanged; inherited field spelling source-closed. |
| 0000CF | 89/90 | 89/90 applied prose sync | 0000NF/0000NF/TRUE/blank | Existing ScrollablePane route and `+0x100/+0x104/+0x108` field roles retained. |
| 00008Q | 90/92 | 90/92 verify-only | 0000P0/0000P0/TRUE/blank | Complete MoreInfoPane class unchanged; RR activation and RS legacy reuse are exact consumer evidence only. |
| 0000AV | 90/92 | 90/92 verify-only | 0000P0/0000P0/TRUE/blank | Complete ProfilePane class unchanged; RR/RS teardown and RT activation roles are source-closed. |
- Exact original private labels and historical filenames remain confidence caps; no behavior/type/ownership/body or callback implementation blocker remains. Manual coverage and lifecycle actions remain external.

## Open Questions With Attempted Resolution
- Original method name? Resolved to `OnDraw` by the current complete class and primary vtable slot; behavior title rejected for source.
- Split target? Rejected after full CFG/xref/range review.
- What are `+0xdd0/+0xdd4`? Resolved as next/previous ButtonFrame values by independent render reads and mouse writes.
- Hit-test coordinate order? Resolved y/x by canonical PointInRect ABI and direct forwarding.
- Is `m_portraitFallbackFrame` actually nation id/frame? Exact use is NATION frame selector, but no lexical symbol distinguishes `nation` from `portrait fallback`; retain the current name with precise semantic comment and confidence cap.
- Should options be zeroed? No. Binary writes only byte zero before use; source sets `mode=4` and leaves remaining shared fields untouched.
- Why call GetVersionMajor? Return is demonstrably ignored. Preserve the call; no stronger semantic purpose is inferred.
- Should mode 3 return before buttons? No. Binary reaches common tail with invalid rectangles.
- Should unknown mode return before blit? No. Binary blits initialized context with EPF pointer in palette position first.
- Do physical resource pages emit globals? No; use-site literals and declarations regenerate them.
- Is UID0003RN ordinary source despite secondary-facet `this`? Yes. The current class declares `virtual bool OnMouseEvent(Event*)`; vtable cell `0x0062ed20`, `ret 4`, and complete-object `+0xa0` establish compiler adjustment around one ordinary source override.
- Are both action-state checks a decompiler mistake? No. Both Group and Exchange branches load `m_exchangeActionState`; preserve this observed oddity instead of substituting `m_groupActionState` for Group.
- Are UID0003RV/RW dead because they have no direct xrefs? No. Each has a standalone source ABI and UID0003RN contains a behavior-identical inlined copy, matching an accepted historical compiler-inlining pattern. They are file-local source helpers, not members or compiler stubs.
- Should right-click retain the old help pane on a non-help action? No. The delete occurs before action-id filtering, so the source draft deletes first and may return false without replacement.
- Should packet conversion use a modern string or include the local NUL in send length? No. Preserve CP_ACP, 256-byte converted storage, narrowed one-byte length, exact memmove count, local terminator at `packet[length+2]`, and send length `length+2`.
- Why does ShowProfileView legacy mode reattach MoreInfoPane? Fresh disassembly and decompilation both load `this+0xf8` for current-position, apply, add, and order after removing all three children. Preserve the observed MoreInfoPane operation; method naming does not license substituting ProfilePane.
- Should ShowLegendView detach LegendPane before reattaching it? No. Both branches remove only MoreInfoPane and ProfilePane. Adding LegendPane teardown would change call order and side effects.
- What is LegendPane `+0x104`? Resolved to inherited `m_verticalScrollBarOffset`, not `m_displayMode`, by ScrollablePane's exact three-field layout plus independent writes of 63 in UID0001HB and 49 in UID0003RU. The accepted direct field access style is already emitted by ScrollableControlPane.
- Are RO/RT or any other RN view callees still blank? No. Fresh call inventory is exactly RR/RS/RT/RU; RO and RT are complete `92/93`, and D21-D23 close the remaining three blank methods.
- Were other agents colliding during callback? No. Every destination was reread before and after its short B002 lease; no UserLookPane collision occurred. This is callback-time coordination evidence rather than a claim about future agent assignments.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
Read-only comparison after final generated command `000000014932` proves the exact UserLook and bounded LegendPane/ScrollablePane manual updates remain supervisor-owned and required. All earlier manual epochs remain historical. Validator commands 14885, 14891, and 14892 automatically propagated only UID-preserving path changes where registered; B002 did not manually edit coverage. Final-read manual hashes are by-memory `228744FC93E00791CB815C6F295915AB62976A863F6BF2F67DF8E983E07876BD` (1,816,586 bytes / 4,329 lines), by-class `3EDA3E462CE2CF6EE75794DEB015268955BEAFC5923A0830919457E3775DDC4F` (235,909 / 623), by-file `D5E287F87CC283084EF3DA1DBA48DAFEAFA24F7C60C42A79929587E594932BF2` (134,575 / 316), by-global `B1D9DE82100DEFA76A964C097A808F0DAC6781CF4D51F6D670000F21B6AC3357` (90,593 / 213), by-item `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6` (28,963 / 87), and by-type/by-vtable `249233F6B031CFC104ED0C9CD5678BFDE873E03FBBD9092AD788675032030749` (65,481 / 142). Existing anchors are UID0001KK 3430, UID0003RI 3431, UID0003RK 3432, UID0003RM 3433, UID0003RN 3434, UID0003RP 3436, UID0003RQ 3437, UID0003RR 3438, UID0003RS 3439, UID0003RT 3440, UID0003RU 3441, UID0003RX 3442, UID0001GL 2973, UID0001HB 3029, UID00026V 3999, UID00038R 4000, UID00038T 4002, UID000074 280, UID00008Q 337, UID0000AV 413, UID0000CF 469, UID0000FP 586, UID0000KM 139, UID0000NF 240, UID0000P0 296, and UID00038Q 81; UID0003RV/RW/UID00038X remain absent. UID00008Q/UID0000AV rows remain exact, so no replacement is proposed for them. These hashes and anchors are bounded callback-final evidence, not assertions about later unrelated validator activity.

The command-14932 row-by-row comparison establishes the current pre-coverage anchors. The exact handoff has sixteen by-memory changes: replace UID0001KK, UID0003RI, UID0003RM, UID0003RN, UID0003RP, UID0003RQ, UID0003RR, UID0003RS, UID0003RU, UID0001GL, UID0001HB, UID00026V, and UID00038R; add UID0003RV and UID0003RW in address order after UID0003RU and before UID0003RX; and add UID00038X immediately after UID00038T. UID0003RK, UID0003RO, and UID0003RT remain verify-only and are intentionally not replaced. By-class replacements are UID0000FP, UID000074, and UID0000CF; by-file replacements are UID0000P0, UID0000KM, and UID0000NF; the by-vtable replacement remains UID00038Q. By-global and by-item contain no affected row, so no addition/deletion is proposed there. The exact pending rows below are UID-keyed and remain valid even if later unrelated validator activity shifts line anchors; external application state after this bounded read is supervisor/validator-owned.

`by-memory/-coverage-report.md`: replace UID0001KK and affected existing child/support/data rows in place; insert UID0003RV/UID0003RW after UID0003RU in address order and insert UID00038X immediately after UID00038T.

    - [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) 0x0059f260-0x005a2523 | class-method aggregate | UserLookPaneAndProfilePanes : not_reconstructable : 90% : very-strong : Non-emitting UserLookPane.cpp semantic split index over exact constructor/destructor/OnActivate/OnDraw/mouse/key/geometry/view/local-pane children; preserves complete UID0003RI constructor and UID0003RK packet source, source-ready UID0003RM OnDraw, UID0003RN OnMouseEvent, UID0003RP/UID0003RQ geometry, and file-local UID0003RV/UID0003RW packet helpers; corrected next/previous ButtonFrame state, exact resource/vtable/compiler boundaries, and blank aggregate C++ because exact children alone emit source.
        - [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) 0x0059f260-0x0059f4fd | constructor | UserLookPaneConstructor : reconstructable : 92% : very-strong : Complete source-ready UserLookPane constructor with exact 669-byte range/hash, sole GeneralPurposePanel caller and 0xddc allocation, PanelPane/AUTOBUF/EPFTileContext setup, three child creations, one m_moreInfoPane/g_pMoreInfoPane mirror, exact status/string/action/view initialization, typed normal next/previous ButtonFrame state, repeated final MoreInfo state call, EH/compiler exclusions, and deterministic position 10.
        - [UID:0003RM][0x005a0640-0x005a157d.UserLookPaneOnDraw](by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md) 0x005a0640-0x005a157d | virtual method | UserLookPaneOnDraw : reconstructable : 93% : very-strong : Complete primary-vtable +0x44 UserLookPane::OnDraw with exact 3,901-byte/hash/1,356-instruction/97-block body, four mode backgrounds, repeated text work, human/monster status, fourteen equipment images, portrait/fallback/NATION behavior, action and navigation states, odd unknown/mode-3 tails, complete source C++, and compiler-only cookie exclusion.
        - [UID:0003RN][0x005a1580-0x005a1985.UserLookPaneOnMouseEvent](by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md) 0x005a1580-0x005a1985 | virtual method | UserLookPaneOnMouseEvent : reconstructable : 93% : very-strong : Complete secondary-vtable +0x04 bool UserLookPane::OnMouseEvent(Event*) with exact 1,029-byte/hash/302-instruction/57-block body, y/x Event payload, cursor hover/reset/invalidation paths, shared exchange-state oddity, exact view transitions, opcode 0x2e/0x4a helper calls, destructive right-click help replacement, no-base/no-null behavior, compiler switch/EH/cookie exclusions, and destination-ready source.
        - [UID:0003RP][0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect](by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md) 0x005a1a70-0x005a1b4d | method | UserLookPaneGetActionButtonRect : reconstructable : 92% : very-strong : Complete const signed-short action rectangle helper with exact 221-byte/hash/74-instruction/15-block body, six render/mouse calls, Group/Exchange/Previous/Next mode matrix, invalid -1 rectangle behavior, source C++, and compiler-only following switch table.
        - [UID:0003RQ][0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton](by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md) 0x005a1b70-0x005a1caf | method | UserLookPaneHitTestActionButton : reconstructable : 92% : very-strong : Complete const signed-short y/x action hit test with exact 319-byte/hash/108-instruction/19-block body, two mouse callers, source-level GetActionButtonRect loop over ids 0-3, canonical PointInRect(y,x), first-hit or -1 result, and inlined binary geometry-switch disposition.
        - [UID:0003RR][0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView](by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md) 0x005a1cd0-0x005a1dee | method | UserLookPaneShowMoreInfoView : reconstructable : 92% : very-strong : Complete 286-byte/88-instruction/four-block mode-0 MoreInfo view source with three callers, exact EPF/legacy ProfilePane/LegendPane/MoreInfoPane teardown asymmetry, bounds (7,205,182,266)/(17,192,174,251), current-to-zero scroll reset, root-layer attach/order, owner invalidation, clean padding, and compiler-cookie exclusion.
        - [UID:0003RS][0x005a1df0-0x005a1f16.UserLookPaneShowProfileView](by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md) 0x005a1df0-0x005a1f16 | method | UserLookPaneShowProfileView : reconstructable : 92% : very-strong : Complete 294-byte/90-instruction/four-block mode-1 source with three input callers, exact duplicate three-child teardown, EPF no-reattach path, legacy bounds (17,192,174,251), deliberately preserved MoreInfoPane reset/reattach oddity, owner invalidation, clean padding, and compiler-cookie exclusion.
        - [UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) 0x005a1ff0-0x005a2188 | method | UserLookPaneShowLegendView : reconstructable : 92% : very-strong : Complete 408-byte/121-instruction/four-block mode-3 source with two callers, exact MoreInfo/Profile teardown without Legend teardown, EPF/legacy bounds (7,15,182,265)/(17,36,174,251), current-to-zero attach/order, EPF-only inherited vertical-offset 49 and current-to-maximum pass, owner invalidation, clean padding, and compiler-cookie exclusion.
        - [UID:0003RV][0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket](by-memory/0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket.md) 0x005a2190-0x005a2272 | file-local helper | UserLookPaneSendNameCommandPacket : reconstructable : 91% : very-strong : Source-live static __stdcall name-command packet helper with exact 226-byte/hash/72-instruction range, behavior-identical UID0003RN inlined copy, empty-name return, CP_ACP conversion into 256 bytes, opcode 0x2e, narrowed one-byte length, MemoryMan memmove, local NUL, exact send length, compiler range/cookie exclusions, and deterministic position 80.
        - [UID:0003RW][0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket](by-memory/0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket.md) 0x005a2280-0x005a22da | file-local helper | UserLookPaneSendTargetActionPacket : reconstructable : 91% : very-strong : Source-live static __stdcall target-action packet helper with exact 90-byte/hash/31-instruction range, behavior-identical UID0003RN inlined copy, 16-byte local packet, opcode 0x4a, zero subtype, big-endian target id, explicit byte-six zero, six-byte send, compiler-cookie exclusion, and deterministic position 90.
    - [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md) 0x0062eccc-0x0062ef0c | vtable/string-data | UserLookReadOnlyData : reconstructable : 89% : very-strong : UserLookPane.cpp read-only island with exact UserLook/MoreInfo/Profile vtables, primary +0x44 OnDraw and +0x48 OnActivate, secondary +0x04 OnMouseEvent and +0x08 key routes, exact USERLOOK/PFLOOK/NATION resource tail, split ownership, and blank data C++ because declarations/use-site literals regenerate storage.
        - [UID:00038R][0x0062eccc-0x0062ed58.UserLookPaneVtableData](by-memory/0x0062eccc-0x0062ed58.UserLookPaneVtableData.md) 0x0062eccc-0x0062ed58 | vtable-data | UserLookPaneVtableData : reconstructable : 90% : very-strong : Exact UserLookPane primary/secondary/tertiary vtable data; primary +0x44 is UID0003RM void OnDraw and +0x48 OnActivate, secondary +0x04 is UID0003RN bool OnMouseEvent and +0x08 is key handling, complete-object +0xa0 is proven, and raw tables remain compiler-generated.
        - [UID:00038X][0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData](by-memory/0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData.md) 0x0062eebc-0x0062ef0c | resource-string data | UserLookPaneResourceStringData : reconstructable : 90% : very-strong : Exact UTF-16 USERLOOK.PAL, PFLOOK.EPF, and NATION.EPF tail with target use-site/xref roles, physical boundary after ProfilePane vtables, file ownership, and blank direct C++ because literals emit at UserLookPane OnDraw use sites.
    - [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) 0x0055e660-0x0055f44f | method cluster | ScrollablePaneCore : reconstructable : 88% : very-strong : Complete ScrollablePane source/evidence cluster with exact constructor/destructor/layout/input/update/helper boundaries, selected-child GetScrollMax/GetScrollPosition and ApplyScrollPosition contracts, source-facing +0x100 horizontal offset/+0x104 vertical offset/+0x108 inset fields, viewport recompute use, wrapper/vtable/compiler exclusions, and inherited LegendPane/UserLookPane consumers.
    - [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md) 0x0056c400-0x0056c493 | constructor | LegendPane : reconstructable : 88% : very-strong : Complete source-ready LegendPane constructor with exact 147-byte range/hash/callers, legacy/current TextEditPane geometry and arguments, three compiler vtable stores, inherited m_verticalScrollBarOffset value 63, separate input children/source order, and compiler/padding exclusions; historical m_displayMode placeholder is superseded.

`by-class/-coverage-report.md`: replace UID0000FP, UID000074, and UID0000CF.

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md) : reconstructable : 92% : very-strong : Complete 0xddc PanelPane-derived remote-look declaration with source-ready constructor, OnDraw, OnActivate, OnMouseEvent, key, action rectangle and y/x hit-test helpers; exact four-view/action/ButtonFrame enums; three child panes; g_pMoreInfoPane declaration; full ObjectStatus/equipment/portrait/profile/action state; typed next/previous frame fields; implicit padding; and compiler/file-helper/lexical exclusions.
- [UID:000074][LegendPane](by-class/LegendPane.md) : reconstructable : 91% : very-strong : Complete TextEditPane-derived LegendPane declaration with source-ready constructor, protected bool HandleKeyOrTextEvent and OnMouseEvent overrides, class closure before child definitions, inherited m_verticalScrollBarOffset at +0x104 used by constructor/UserLook view source, exact vtable/source route, shared look-panel consumers, and historical m_displayMode placeholder explicitly superseded.
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) : reconstructable : 89% : very-strong : Complete ScrollablePane source route and declaration evidence with selected-child scroll helpers, exact virtual metric contracts, horizontal/vertical children, +0x100 m_horizontalScrollBarOffset, +0x104 m_verticalScrollBarOffset, +0x108 m_scrollBarInset, viewport/layout consumers, derived-family use, and compiler/vtable exclusions.

`by-file/-coverage-report.md`: replace UID0000P0, UID0000KM, and UID0000NF.

- [UID:0000P0][UserLookPane](by-file/UserLookPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/UserLookPane.cpp source grouping with complete UserLookPane constructor, OnActivate, OnDraw, OnMouseEvent, key, GetActionButtonRect, HitTestActionButton and view source plus file-local name-command and target-action packet helpers; one MoreInfo global; local MoreInfo/Profile source; exact render/mouse/packet/help behavior, next/previous ButtonFrame state, resource/type/header dependencies, vtable/compiler exclusions, and shared LegendPane/STATBUT ownership preserved.
- [UID:0000KM][LegendPane](by-file/LegendPane.md) : reconstructable : 90% : very-strong : NexusTK/ui/panels/LegendPane.cpp source root with complete LegendPane declaration, source-ready constructor, bool HandleKeyOrTextEvent and OnMouseEvent false overrides, exact three-view vtable/source order, inherited m_verticalScrollBarOffset value 63, shared self-look/user-look consumers including value-49 UserLook setup, and compiler/vtable exclusions; historical m_displayMode is superseded.
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md) : reconstructable : 90% : strong : ScrollPane/ScrollWidget/ScrollablePane source family with complete ownership/routes, selected-child and virtual scroll contracts, exact +0x100 horizontal offset/+0x104 vertical offset/+0x108 inset layout, constructor/wrapper/viewport consumers, derived-pane dependencies, and raw-helper/vtable/compiler boundaries.

`by-type/by-vtable/-coverage-report.md`: replace UID00038Q.

- [UID:00038Q][UserLookPaneFamilyVtables](by-type/by-vtable/UserLookPaneFamilyVtables.md) : reconstructable : 89% : very-strong : Source-local UserLookPane.cpp vtable layout for UserLookPane, MoreInfoPane, and ProfilePane; exact groups span 0x0062eccc-0x0062eebc, primary +0x44 is void UserLookPane::OnDraw and +0x48 OnActivate, UserLookPane secondary +0x04 is bool OnMouseEvent and +0x08 is bool HandleKeyOrTextEvent, local primary +0x60 methods are bool OnMouseEvent, complete-object +0xa0 evidence is preserved, and no raw table source is handwritten.

No tracker/generated row is manually edited. UID0003F4 and verify-only dependency rows remain unchanged.

## Follow-Up Actions
- The prior UID0003RM/RP/RQ/class/file implementation, scoped validators, lease releases, final waited generation, and seven-block parity remain complete and unchanged.
- D15-D24 are applied under short serial leases with complete ordinary validation, byte-equal formal proof, and final waited UserLookPane/LegendPane generation. No accepted callback implementation remains pending.
- The sixteen-row by-memory plus three class, three file, and one vtable manual handoff is supervisor-owned and remains unapplied at the bounded final read; B002 did not manually edit coverage. Gate decisions, manual-row application, and all report execution/move/archive lifecycle state are external.
- No technical, source, declaration, type, ownership, or liveness blocker remains. Exact private lexical spellings remain confidence caps only.

## Confidence
- Completion recommendation: UID0003RM/RN 93, UID0003RP/RQ/RR/RS/RT/RU 92, UID0003RV/RW 91, class/file/support scores as tabulated.
- Confidence recommendation: UID0003RM/RN/RP/RQ/class 94; UID0003RR/RS/RT/RU/RV/RW, file/aggregate/resource/vtable support 93; bounded LegendPane/ScrollablePane scores remain as currently accepted.
- Very strong: exact bytes, boundaries, vtable route, CFG/calls, branches, coordinates, fields, resource values, mode/action/helper behavior, owner/emitter, and source placement.
- Strong: source-era private labels and enum tokens. These are bounded lexical inferences and do not alter layout or behavior.

## Validator Results
- Scoped validators, each exit `0` and `ok:1`: target rename/D1 `000000014818` at `2026-07-20T00:50:45-04:00`; UID0000FP/D2 `000000014819` at `2026-07-20T00:52:03-04:00`; UID0003RI/D3 `000000014820` at `2026-07-20T00:52:52-04:00`; UID0003RP/D4 `000000014821` at `2026-07-20T00:53:45-04:00`; UID0003RQ/D5 `000000014822` at `2026-07-20T00:54:40-04:00`; UID0003RN support `000000014823` at `2026-07-20T00:56:27-04:00`; UID0001KK/D6 `000000014824` at `2026-07-20T00:58:56-04:00`; UID0000P0/D7 `000000014825` at `2026-07-20T01:00:27-04:00`; UID00038X/D8 `000000014826` at `2026-07-20T01:01:37-04:00`; UID00026V/D9 `000000014827` at `2026-07-20T01:02:34-04:00`; UID00038R/D10 `000000014828` at `2026-07-20T01:03:17-04:00`; UID00038Q/D11 `000000014829` at `2026-07-20T01:03:54-04:00`; Application/D14 `000000014830` at `2026-07-20T01:04:42-04:00`.
- Target rename command `000000014818` preserved UID0003RM, updated old-to-new ordinary references, propagated the by-memory coverage path as an automatic validator-owned side effect, and reported 26 pre-existing missing-reference warnings for unregistered sibling UIDs. Commands `000000014819`, `000000014824`, and `000000014825` reported respectively 7, 7, and 8 pre-existing missing-reference warnings for the same unregistered sibling pages; no warning was target-specific. Command `000000014826` inserted the required metadata header separator and rebuilt the previously absent UID00038X registry mapping. Other scoped validators had no target-specific warning.
- Additive source-closure scoped validators, each exit `0` and `ok:1`: UID0003RN rename/D15 command `000000014885` at `2026-07-20T04:39:33-04:00`; UID0003RR/D21 `000000014886` at `2026-07-20T04:40:33-04:00`; UID0003RS/D22 `000000014887` at `2026-07-20T04:41:45-04:00`; UID0003RU/D23 `000000014888` at `2026-07-20T04:42:38-04:00`; UID0003RV rename/D16 `000000014891` at `2026-07-20T04:44:26-04:00`; UID0003RW rename/D17 `000000014892` at `2026-07-20T04:45:23-04:00`; UID0001KK/D18 `000000014895` at `2026-07-20T04:46:52-04:00`; UID0000P0/D19 `000000014900` at `2026-07-20T04:48:02-04:00`; UID0000FP/D20 `000000014905` at `2026-07-20T04:50:09-04:00` plus bounded stale-prose correction `000000014929` at `2026-07-20T04:58:09-04:00`; UID0001HB/D24 `000000014910` at `2026-07-20T04:51:06-04:00`; UID000074 `000000014914` at `2026-07-20T04:52:12-04:00`; UID0000KM `000000014917` at `2026-07-20T04:52:50-04:00`; UID0001GL `000000014922` at `2026-07-20T04:55:33-04:00`; UID0000CF `000000014925` at `2026-07-20T04:56:42-04:00`; and UID0000NF `000000014926` at `2026-07-20T04:57:22-04:00`. Every command deferred generated refresh and its lease was released immediately afterward.
- Command 14885 performed the UID-preserving RN path update and propagated registered references; it reported 26 pre-existing unregistered-sibling missing-reference warnings. Commands 14891/14892 rebuilt validator mappings for the previously unregistered RV/RW paths and reported no warnings. Commands 14895/14900/14905/14929 reported respectively 5/6/7/7 pre-existing unregistered-sibling warnings; all other additive scoped validators had no warning. Validator-owned reference/registry/projected-stat and registered path-propagation side effects are recorded as tool effects, not manual restricted-file edits.
- Every scoped command deferred generated refresh and updated validator-owned registry/reference/projected-stat state as reported. These are tool side effects, not manual B002 edits. The accidental help invocation command `000000014815` performed no scoped validation or project change and is excluded from implementation proof.
- Historical callback target `--wait-generated` command `000000014831`, timestamp `2026-07-20T01:05:46-04:00`, exit `0`, `ok:1`, completed the authorized callback refresh. Its global warnings were unrelated pre-existing inventory diagnostics: 13 child fallback inserts, 85 children-marker-missing rows, and 142 emitter-has-no-code rows; none named UID0003RM/RP/RQ as an empty marker after refresh.
- Historical callback/readback commands `14831`, `14846`, `14857`, `14859`, `14864`, `14869`, `14875`, and pre-additive command `14880` retain their exact historical metrics and semantics above. Authorized waited UserLookPane command `000000014930`, timestamp `2026-07-20T04:58:26-04:00`, exit `0`, `ok:1`, completed after all UserLook ordinary pages; required waited LegendPane command `000000014932`, timestamp `2026-07-20T04:59:05-04:00`, exit `0`, `ok:1`, then established the bounded final generated epoch. Both reported only project-wide pre-existing diagnostics: 13 child fallback inserts, 86 children-marker-missing rows, and 140 emitter-has-no-code rows; none is a target callback defect.
- Final command-14932 UserLookPane.cpp is SHA256 `F7F27A1CFCE3C4E04DC65BA100813338FF47C19C98A396888E66576205A5A69D`, 57,758 bytes / 1,591 lines, with all exact one-definition/no-target-marker/no-stale-frame/no-handwritten-ABI assertions in Current Target State. LegendPane.cpp is SHA256 `506146403E636D7453D0B3A1DF9A3266238E978D2A9E417B43847ECB5543B0A7`, 1,651 bytes / 51 lines, with one constructor, one accepted vertical-offset token, and zero stale alias. The later read-only tracker snapshot is command `000000014962`, refreshed `2026-07-20T05:21:12-04:00`, SHA256 `15BD40D4347E0777408F04F3010C6D9611163D268F9518E6BBE55FEC08D74BB0`, 1,519,767 bytes / 6,166 lines; its accepted UID0003RM/RN/RR/RS/RU/RV/RW rows and scores are unchanged from the callback result. Command-14932 tracker SHA `3E42FD5F...FB35` remains labeled callback-time history.
- All previously implemented managed blocks remain preserved. Each of the seven additive managed blocks D15-D17/D21-D24 compares byte-for-byte equal between this report and its ordinary destination. B002 ran only the authorized scoped/waited validators; it made no manual coverage/generated/tracker/audit/supervisor/validator-state edit, IDA mutation, report lifecycle command, or report execution.

## Changed Files
- Renamed/changed ordinary target: `by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md`, SHA `89085690310536982AF9C4A01E6C3CEBF67AF080E127F9E4C94B6EAD57A8EF6B`; former ordinary path absent.
- Prior callback changed ordinary support: `by-class/UserLookPane.md` `2532A7BD5B2D21AE82CBCF40EA7D09DEB23F7007554C4946E139FD00822D6D67`; constructor `6EA83AE23D274848E7A78FF9AAD76FF750A0C8533CDDFE6F914B30DFA182F33A`; UID0003RP `025BF9539A4DC77DA4B7B5C8959A03326DC66DBED0C82356E41BBBDE596FA128`; UID0003RQ `60C1308F1D6E0564F82709D154195B43A91A20048235A90122DE050165F14619`; UID0003RN support-only state `894F5885F79362D63F0BD9C2DC5E7AFDE17F1FCA9FFD6B305884F3E263C3B469`.
- Changed ordinary support: UID0001KK `B89B455EE846786EBCC6991F6FA4CE8CC47D23DEBEEE24F876187C1278F41480`; by-file UID0000P0 `0B28E409AAAD7525F767EC3A13294EFAC6C992638E5B4A60E5D9DD2018F798D4`; UID00038X `C26A56B5C761CFB6D006946C9BC19274D56729041B00DBEA4A9102DE6FB1DC11`; UID00026V `674932BFEC86B31BB7757FA6353A16C2522692A2E31C8DA2ED6375C84CC32CF6`; UID00038R `FCA9BA49189BD9B069AACBEDBE97F6D6C6683077CBC020AAF234B3245B2A34B4`; UID00038Q `D005F812471A7EEDA23C24A36287E725F2653835E98152CE611D09525ECEB2B6`; ApplicationGetVersionMajor `C685570E707F2E38F68D2DC9A4AE52F4C1464A27CC2729FCA71B2F7AE8113129`.
- Additive callback source-bearing destinations: UID0003RN `by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md` SHA `83F96098E69B57708AB62B545F8D6CDB4FEF82880244CD03D95BE505051A8D53`; UID0003RR `EDFA8EBD74E1AA83AAF84A7B1F26255F547376A68DDDD72FF4E00E8327286D24`; UID0003RS `8BBF02BF25FBA0B80C4CD4A4D7993E55EB4614E6FD0FCE4BE1433D5B1A1C5BAF`; UID0003RU `0DDCC1177FE50EB5704F5FD86A4B6C6172BD0CDC51D1298019EC935ACBA05D96`; UID0003RV `by-memory/0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket.md` SHA `142593CCBA6C1832B8EC22E0F9498298119A096FDB09382E1A51A35A9FAAC208`; and UID0003RW `by-memory/0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket.md` SHA `594E6A5A4004E0F4E6B064AC5999F27166E834AF862C8E6152AF28DF790E5271`. The three former ordinary paths are absent.
- Additive callback UserLook support: UID0001KK aggregate SHA `7C22B6761778D52158A8C718424AC47A43CE9992600F6698ADC42C829FC53F4E`; by-file UID0000P0 SHA `A6F944CE5D030FAF109C86F353F9C9104EF0FCEF248CE0214484C6F2D56FA01D`; by-class UID0000FP SHA `F8ACDD6CC9883F6D71C0C554F54CF04B06125A0B4621FFD488A88A411CF10D26`. The class hash includes the bounded correction of the last stale hover/pressed constructor-prose token; its complete managed declaration remains unchanged.
- Additive callback LegendPane/ScrollablePane support: UID0001HB SHA `7FD703ADA8243DAF24FF0833F42CBDC5FE66A4B65FF2350551D125DB7C2F037C`; UID000074 `56180AE67CC858AD6D44654199F050EC56F7F11431955ECFF79DB5F92CEC99C7`; UID0000KM `55EEE05FB1AB8D1BD6CBA28EDD27E012F65D5DB7F7647FB1399CB3D7553AE9A6`; UID0001GL `97254D76FA619A8FEA34AF3F8F6300B8DFA95DB17F79FE65BB517261FCAD2B88`; UID0000CF `302AF44562FB3BD07DB81B7BBF69BA4B03E7DF68562A6BA87269E6CCC0D8AB04`; UID0000NF `8B26B10F28B14294D6A3659AA74B4AF45BD547FD219E15ACA0A6738C5346C869`.
- Prior ordinary implementation remains current: UID0003RM `89085690310536982AF9C4A01E6C3CEBF67AF080E127F9E4C94B6EAD57A8EF6B`; UID0003RI `6EA83AE23D274848E7A78FF9AAD76FF750A0C8533CDDFE6F914B30DFA182F33A`; UID0003RP `689EFF32BBECAA0D0AEC7F47977DB5E3976CC31F7D177EDED6DF6592594FD0DA`; UID0003RQ `65E7837C95613BA99F9CF4771E07329C2C9269E753F761E45ABE9618FB2F2C21`; UID00038X `C26A56B5C761CFB6D006946C9BC19274D56729041B00DBEA4A9102DE6FB1DC11`; UID00026V `674932BFEC86B31BB7757FA6353A16C2522692A2E31C8DA2ED6375C84CC32CF6`; UID00038R `FCA9BA49189BD9B069AACBEDBE97F6D6C6683077CBC020AAF234B3245B2A34B4`; UID00038Q `D005F812471A7EEDA23C24A36287E725F2653835E98152CE611D09525ECEB2B6`. RP/RQ hash drift is validator-owned reference propagation only; their accepted formal bodies remain byte-equal.
- Verify-only RO/RT are SHA `48F09DFB7DC39B7C2010DD0C5F36561CABBD9C52B981A82296C0DC947A9E1355` / `681A3A24658D0EEDFFC2C5821F610799D7EB51AF0D366CE218A20C15F2C9B30A`; UID0003F4 and other D13/D20 dependencies remain unchanged unless explicitly listed above.
- Validator-owned side effects include reference/registry/projected-stat updates, registered path propagation, and commands 14930/14932 generated/tracker refresh; later tracker command 14962 is unrelated external validator activity observed read-only. B002 made no manual edit to restricted files. One ordinary destination was leased at a time and released after its validator. Bounded final lease read SHA256 `43CCD663B5D0A5B4BA949A5E1CE1C804D79819E21F4ECEFF53B48288123CC6B1`, 291 bytes / seven lines, contained one unrelated B003 lease on `by-class/DropAllInputPane.md` and zero B002 rows; final B002 lease count is zero.

## Implementation Tracking Checklist
- [x] Confirm exact report provenance, required headings, one terminal marker, legal ledger Action values, and legal terminal applied/already-present/excluded-with-reason verification states.
- [x] Re-read target/support, generated output, tracker, manual rows, and leases after callback; generated command 14932, later read-only tracker command 14962, current manual anchors, and zero-B002 lease proof are recorded as bounded final-read evidence.
- [x] Preserve UID0003RM UID/range/owner/emitter/TRUE/blank position/Nested 0.
- [x] UID-preserving rename target path/title to UserLookPaneOnDraw and propagate all exact old links.
- [x] Apply target `93/94` metadata and Destination 1 byte-for-byte.
- [x] Preserve target hash/mapping/instruction/CFG/vtable/caller/callee evidence.
- [x] Preserve all four background modes and unknown-mode pre-return blit.
- [x] Preserve exact text scans/colors/positions/draw order.
- [x] Preserve HumanObject NewHuman geometry/options/call order.
- [x] Preserve MonsterObject geometry/options/call order.
- [x] Preserve all fourteen equipment branches, matching palettes, centers, and zero-id skips.
- [x] Preserve mode-0 Exchange/Group fill/frame behavior and order.
- [x] Preserve mode-2 stored portrait/FACE fallback/options/NATION behavior.
- [x] Preserve mode-3 invalid-rectangle common navigation tail.
- [x] Preserve ignored mode-1 Application getter call.
- [x] Apply UID0000FP `92/94` and exact complete Destination 2 before `[[CHILDREN]]`.
- [x] Preserve every unrelated UID0000FP field/method/layout/history fact without loss.
- [x] Replace only stale frame fields with ButtonFrame next/previous names and exact offsets.
- [x] Correct HitTestActionButton declaration to y/x order.
- [x] Apply UID0003RI exact Destination 3 while preserving `92/94`, position 10, and all accepted body detail.
- [x] Apply UID0003RP `92/94`, exact Destination 4, full matrix/range/hash/calls/table proof.
- [x] Apply UID0003RQ `92/94`, exact Destination 5, y/x/order/inlining proof.
- [x] Preserve the historical callback fact that UID0003RN was support-synchronized but left blank; mark that scope-based disposition superseded by this additive repair.
- [x] Apply UID0001KK `90/93`, semantic owner UID0000P0, FALSE/blank emitter/position/formal, exact-child-only source route.
- [x] Apply UID0000P0 `92/93` prose with no by-file reconstruction metadata/block.
- [x] Apply UID00038X `90/93`, exact literal/xref/use-site detail, blank formal.
- [x] Apply UID00026V `89/93` read-only split/OnDraw/resource/no-code detail.
- [x] Apply UID00038R `90/93` exact primary OnDraw slot/no-manual-vtable detail.
- [x] Apply UID00038Q `89/93` exact primary/secondary/local-pane vtable type detail.
- [x] Verify UID0003F4 remains `89/92`, owner NONE, emitters UID0000NL/UID0000P0, blank source.
- [x] Correct ApplicationGetVersionMajor stale partial-range link to full UID0003RM OnDraw target.
- [x] Reread all exact old target links after validator-aware rename propagation; remaining old names are historical only.
- [x] Verify GrafPort/Surface options/RectBounds/ObjectStatus/image/palette/global/Event support remains same-or-greater.
- [x] Preserve `SurfaceSpriteBlitOptions` partial initialization and do not invent a raw record/full layout.
- [x] Preserve resource literals at use sites; emit no standalone string globals.
- [x] Preserve compiler ownership of cookie, vtables/RTTI, switch tables, alignment, and EAX residue.
- [x] Preserve historical blank-body/title/field/coordinate assumptions as explicitly superseded.
- [x] Lease only one ordinary destination immediately before edit; reread after lease.
- [x] Run one scoped validator for each changed ordinary page and record command id/timestamp/exit/ok/warnings/side effects.
- [x] Release each ordinary lease immediately after its scoped validator.
- [x] Run final authorized UID0003RM `--wait-generated` refresh as historical callback command `000000014831`.
- [x] Verify callback-generated UserLookPane.cpp has one complete class and one constructor; final command 14932 proves the expanded implemented structure.
- [x] Verify exactly one OnDraw, GetActionButtonRect, and HitTestActionButton definition in source order.
- [x] Verify zero UID0003RM/UID0003RP/UID0003RQ Empty Emitter Markers and no duplicate source.
- [x] Verify one next/previous ButtonFrame field pair and zero stale hoverActionIndex/pressedActionIndex tokens.
- [x] Verify all existing accepted OnActivate/key/ShowBio/local-pane/global source remains once and unchanged.
- [x] Verify no handwritten raw vtable/RTTI/cookie/switch-table/adjustor/scalar-wrapper source.
- [x] Preserve terminal C01-C30 proof and terminalize C31-C50 without altering accepted claim history.
- [x] Record exact destination/generated hashes, validators, changed files, lease history, unresolved/excluded items, historical epochs through command 14880, command-14932 generated/callback-time tracker proof, and the later time-bounded command-14962 tracker snapshot in this same report.
- [x] Keep the exact supervisor-owned manual coverage handoff no-loss against the current final-read union and make no manual coverage edit.
- [x] Check every accepted callback row only after direct ordinary/generated proof.
- [x] Keep supervisor Gate 2, coverage application, execution, move, archive, and lifecycle actions external and never run/probe them.
- [x] Callback: reread UID0003RN and acquire only its short ordinary lease.
- [x] Callback: UID-preservingly rename UID0003RN to UserLookPaneOnMouseEvent, apply `93/94`, unchanged owner/emitter/TRUE/blank position/Nested 0, and Destination 15 byte-for-byte.
- [x] Callback: preserve exact mouse range/hash/instruction/CFG/vtable/Event/caller/callee evidence and all compiler-tail distinctions.
- [x] Callback: preserve cursor outside/hit/inside-neither/reset return and invalidation behavior exactly.
- [x] Callback: preserve both left action cases' shared `m_exchangeActionState` gate and always-true case returns.
- [x] Callback: preserve exact Previous/Next view graph, `g_useEpfAssets` gate, frame writes, and invalidation.
- [x] Callback: preserve delete-before-filter right-click help behavior, resource ids 200/201, constructor arguments, and false default.
- [x] Callback: scoped-validate UID0003RN, record command metadata/warnings/side effects, and release immediately.
- [x] Callback: reread UID0003RR, acquire only its short ordinary lease, preserve hash/path/current history, apply `92/93` and Destination 21 byte-for-byte.
- [x] Callback: preserve UID0003RR exact 286-byte/hash/88-instruction/four-block/three-caller/padding evidence.
- [x] Callback: preserve RR mode-0 EPF/legacy teardown asymmetry, exact bounds, MoreInfo current-to-zero reset, root attach/order, invalidation, and no-null/no-return behavior.
- [x] Callback: scoped-validate UID0003RR, record command metadata/warnings/side effects, and release immediately.
- [x] Callback: reread UID0003RS, acquire only its short ordinary lease, preserve hash/path/current history, apply `92/93` and Destination 22 byte-for-byte.
- [x] Callback: preserve UID0003RS exact 294-byte/hash/90-instruction/four-block/three-caller/padding evidence.
- [x] Callback: preserve RS duplicate three-child teardown, EPF no-reattach branch, legacy bounds and exact MoreInfoPane reset/attach/order oddity, final invalidation, and no normalization.
- [x] Callback: scoped-validate UID0003RS, record command metadata/warnings/side effects, and release immediately.
- [x] Callback: reread UID0003RU, acquire only its short ordinary lease, preserve hash/path/current history, apply `92/93` and Destination 23 byte-for-byte.
- [x] Callback: preserve UID0003RU exact 408-byte/hash/121-instruction/four-block/two-caller/padding evidence.
- [x] Callback: preserve RU exact MoreInfo/Profile teardown without Legend teardown, both bounds, current-to-zero reset, EPF-only vertical offset 49, attach/order, max/current read order, current-to-max pass, legacy omission, and final invalidation.
- [x] Callback: scoped-validate UID0003RU, record command metadata/warnings/side effects, and release immediately.
- [x] Callback: reread UID0003RO/RT and prove both complete `92/93` bodies remain unchanged and RN has no other blank direct source-bearing view callee.
- [x] Callback: UID-preservingly rename UID0003RV to UserLookPaneSendNameCommandPacket, apply `91/93`, owner/emitter UID0000P0, position 80, and Destination 16.
- [x] Callback: preserve UID0003RV exact CP_ACP/length/narrowing/memmove/NUL/send semantics and compiler-only range/cookie handling.
- [x] Callback: scoped-validate UID0003RV, replace propagated old links without loss, and release immediately.
- [x] Callback: UID-preservingly rename UID0003RW to UserLookPaneSendTargetActionPacket, apply `91/93`, owner/emitter UID0000P0, position 90, and Destination 17.
- [x] Callback: preserve UID0003RW exact 16-byte local/opcode/subtype/big-endian id/explicit zero/six-byte send semantics and cookie exclusion.
- [x] Callback: scoped-validate UID0003RW, replace propagated old links without loss, and release immediately.
- [x] Callback: apply D18 aggregate and D19 by-file prose for RN/RR/RS/RT/RU/RV/RW without aggregate source or by-file reconstruction metadata.
- [x] Callback: reread UID0001HB under a short lease, preserve `88/91` and every constructor fact, replace only `m_displayMode = 63` with Destination 24 `m_verticalScrollBarOffset = 63`, validate, and release.
- [x] Callback: reread/rebase UID000074 and UID0000KM under separate short leases; preserve scores/source union and historicalize only the stale `m_displayMode` interpretation.
- [x] Callback: reread/rebase UID0001GL, UID0000CF, and UID0000NF under separate short leases; preserve all source/layout/helper detail and synchronize the exact inherited `+0x104` use without loss.
- [x] Callback: reread/rebase UID0000FP and D20 Event/pane/scroll/packet/MemoryMan/LanguageMan/SimpleHelpPane/global/view/vtable support; edit only concrete stale RN/RR/RS/RU/RV/RW or field-name dispositions.
- [x] Callback: scoped-validate every changed support page under one-file leases and release each immediately.
- [x] Callback: run one final authorized UID0003RN `--wait-generated` UserLookPane refresh after all ordinary validators pass and the required waited LegendPane refresh through the scoped support route.
- [x] Callback: verify one complete class/constructor/OnActivate/OnDraw/OnMouseEvent/key/geometry/RR/RS/RT/RU/local-pane/global source union plus one UID0003RV and one UID0003RW definition.
- [x] Callback: verify zero UID0003RN/RR/RS/RU/RV/RW Empty Emitter Markers, no duplicate packet/view helper, and no handwritten vtable/RTTI/cookie/range-check/switch-table/adjustor/scalar-wrapper source.
- [x] Callback: verify generated LegendPane constructor uses `m_verticalScrollBarOffset = 63` exactly once and has zero `m_displayMode` token or duplicate constructor.
- [x] Callback: update C24/C31-C50 to legal terminal states, preserve all prior claim proofs, record all changed hashes/validators/generated proof, and keep zero leases.
- [x] Callback: preserve every exact pending manual-row proof only in the report handoff; do not edit coverage and prove all 23 proposed placements remain no-loss against the current union.
- [ ] Supervisor-only: apply and validate the repaired exact sixteen-memory/three-class/three-file/one-vtable manual coverage handoff; B002 must not edit coverage.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000015062","destination_path":"executed-b-agent-research/B002/0003RM-UserLookPaneRenderUserLook-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003RM-UserLookPaneRenderUserLook-source-quality.md","timestamp":"2026-07-20T05:52:28-04:00","uid":"0003RM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
