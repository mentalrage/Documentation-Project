** TARGET-REPORT-UID:0003VD **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003VD UserPane OnTimer Source-Quality Report

## Finalized Report / Current Recommendation

[UID:0003VD] is the complete source-authored `UserPane::OnTimer(int timerId, int arg0, int arg1)` override at `[0x005a83b0,0x005a87ad)`. The sole inbound route is the second slot of the UserPane `TimerHandler` secondary vtable at `0x0062efc4`; machine ECX is therefore the `TimerHandler` facet at complete `UserPane + 0xa4`. The repeated `this - 0xa4` expressions recover the complete object in lowered code and must not appear in source C++.

The method handles two UserPane movement-substep timer families itself: local event `20` / `0x14` (`kUserPaneMovementStep`) and inherited `FWdA` / `0x41645746` (`kLivingTimerForwardStep`). Both advance a four-times-scale movement frame, schedule the next substep when appropriate, stop movement at frame wrap, coordinate the movement-reply latches, and propagate linked-object mode. The local event moves both map and viewport coordinates by one facing offset at completion. `FWdA` instead scrolls the MapPane progressively and, at completion, warps map coordinates while retaining the current viewport position before performing the full viewport shift. `FAnD` / `0x446e4146` and every unrecognized timer delegate to `LivingObjectPane::OnTimer`.

Ordinary-document implementation is complete for C001-C105 and C222-C223: owner/emitter [UID:0000FQ] and source file [UID:0000P1] remain unchanged; the target carries the complete formal CPP and blank H channel; the single managed UserPane declaration is in the by-class formal H channel while class CPP is blank; current ordinary prose uses `OnTimer`, the size-neutral named movement fields, and the independently proved `LineInputPane *m_activeLineInputPane` / `ClearActiveLineInputPane()` contract; and the target is `94/94`. No split was required. The accepted bounded C070 callback added the literal source-facing name `UserPane::PropagateLinkedObjectMode(int mode)` to UID0003Z7's existing `0x005a9240-0x005a9249` thunk sentence without changing its range, vtable/tail evidence, owner/emitter, 91/93 score, or formal CPP/H. Scoped validator command `000000020142` passed with `ok: 1` and generated refresh disabled. The later Gate 2A repair synchronized the five affected support pages to the already-applied F2-F9 canonical IDA state through scoped commands `000000020356`-`000000020360`, and corrected C104 to the existing signed-consumed plain-`char` movement-scale contract without changing UID00027F. Supervisor Gate 2B is applied and independently verified for F1-F9/C1/T1. A bounded read-only coverage reread at SHA checkpoints `DDB43AB5...EAFAE2`, `34287BEF...7E2C1`, and `F203FD4C...0210B` reconfirms M01-M09 applied and N01-N06 exact no-ops; those whole-file identities and anchors are moving evidence, not permanent authority. Generated-currentness verification, Gate audits, and execution/archive state are supervisor-owned and authoritative only from the artifact's current path, the exact-artifact audit for that revision, and validator-owned status/history metadata.

## Supporting Research

- Target: [UID:0003VD] `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`, assignment-time SHA256 `914D596B987E90E51C8F23833530CCB10F8B9673104F3588C47BC8995A8F2240`.
- Direct owner: [UID:0000FQ] `by-class/UserPane.md`, current bounded physical SHA256 `4784B20F4C8535CDE637223AC3B5360D8B79276CF3190F14DD7C423604BCE6D8`, 111,710 bytes / 815 lines, current `94/95`. The accepted UID0003VD callback produced SHA256 `C7873624784664FFBE29D91B441AD9FB03D7FDFE2E8ED4A68211195E32D1BFB9`, 111,196 bytes / 814 lines; B008's later additive UID00035P post-IDA reconciliation advanced the shared page without removing any UID0003VD declaration, formal-H, layout, behavior, or history claim. Callback-input SHA256 `DB7867530A0DC231BC7DB350BD079858BBF88CEF8C90A2E35556DDA8AED97578`, dated pre-B008 SHA256 `7C2BCD5F65B8FD6AE8972F67BA6E1B3B3E4AD7216504BFE2319990EE75B47982`, and assignment-time SHA256 `1ECD11678A39EABED11033D82F5B2A1BD12EF2E2A9682E2A1C2EC9022F74DEEA` are history.
- Source owner: [UID:0000P1] `by-file/UserPane.md`, current bounded physical SHA256 `8A534098EC3F32D46D6DDE40AEF9E1094055BBEF7B32B350B55218954308D772`, 121,808 bytes / 510 lines, current `93/94`, proposed path `NexusTK/ui/panels/`. The accepted UID0003VD callback produced SHA256 `512BA4D0D75124D014DFE908DD6EAFE668DFF298D69F0A010227977624E4CA33`, 121,010 bytes / 508 lines; B008's later additive UID00035P post-IDA reconciliation advanced the shared page without removing the UID0003VD source route, definition ownership, generated-topology requirement, or corrected active-line-input contract. Callback-input SHA256 `54A260E46F9E452904B6D9E6ED01DF5D0656435DF333C2C1172300BBA1C7781B`, dated pre-B008 SHA256 `1FA4850B48BAC76EB16CBC90618CEE73AE5B760E14946FBF87D726C258CACE55`, and assignment-time SHA256 `4171E336C19C2D90171B272100CB824D519292A2F93789E44A999677F2C94F66` are history.
- Active-slot source evidence: B008 [UID:00035P] report identities SHA256 `56402F4CBF3C5F7ABFF958EF85369F39AB74B224347D44D7C8A0891E7DF680ED`, 96,984 bytes / 642 lines, and earlier SHA256 `74F22808566D420D2ECE695E9574085F39EC6650BDFA94D245F03AA2DBB3AB64`, 73,431 bytes / 613 lines, are dated moving research checkpoints, not durable current authority. The dependency conclusion is independently current from ordinary documents and bounded IDA evidence: [UID:00035P] constructor page SHA256 `CCF28C564A4775F0297C408A37073DB40650538475B477B7646F6601C8F253C1`, 14,716 bytes / 156 lines; [UID:00035Y] base handler page SHA256 `3CA614F2AB65ADF4CCC96BC8DD6B6544AC55DB88F9577D9D72147F17E480A69A`, 8,961 bytes / 71 lines; [UID:000364] CharInputPane handler page SHA256 `69F010C8E48EA4F9E19532D2A034FEC635BDE36642B9F714A2D795C84C14BA76`, 8,172 bytes / 101 lines; [UID:00036C] MultiLineInputPane handler page SHA256 `76250E136067ABCD3D477F9BF8735E0FDF2CC8B6941E5E8F27793D09440692D7`, 2,699 bytes / 52 lines; and [UID:0000K7] `by-file/InputPanes.md` SHA256 `77948F03FB4268780D43BB634843D556CE60093421F77ABB978B7E6354495227`, 27,985 bytes / 162 lines. Together with current [UID:0000FQ]/[UID:0000P1] ordinary pages and the dated bounded slot-focused IDA pass, these prove `LineInputPane *m_activeLineInputPane` / `ClearActiveLineInputPane()` at `UserPane+0x210`; no B008 report artifact is required as current authority. The accepted UID0003VD callback corrected UID000364 formal/prose and the InputPanes summary while preserving the disproved pending-target spelling only as dated history.
- Parent/index context: [UID:0001KL] `by-memory/0x005a2530-0x005b8395.UserPane.md`; this aggregate does not own a duplicate body.
- ABI/vtable: [UID:0002YU] `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`, current post-validator SHA256 `C814CC898DF0C0900DFAEB9AC3B861F6F6E66A184B1DCA13104BFEDCADCCBCBE`; pre-callback SHA256 `E03C307EE199F98B31B418771C1F9FAF95BC98C42171D7570F80C68758A52947` is dated history.
- Timer contract: [UID:0002R1] `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`, current post-Gate2A-repair SHA256 `3C953986231A4407CF68BF6FB9E84ACCA314DA1E428C2FA5C98AFE4E71118293`, 30,031 bytes / 329 lines. It records the applied F7 name/comment and the physical final argument as `signed __int32 arg1` while retaining the ordinary source-facing `int arg1` contract. Post-callback SHA256 `D5B9A16162DFC784BA7BE6FFA4952B9F91D5C7D6397F226837BC94912BBE5CD9` and pre-callback SHA256 `EF08B5869E4D77B5B2FD928879375994C0B45883D2191BFD93925628C31DA372` are dated history.
- Linked-object helpers: [UID:0003Z7] `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md`, current post-Gate2A-repair SHA256 `3A78A43AFE75182E3FEC0AC6D858F8847C764C2193DC1BE8F53CF27390A97986`, 12,626 bytes / 165 lines. It records the applied F2/F3/F8/F9 names, types, exact repeatable comments, physical argument rows, and B7 no-drift state while retaining raw analyzer prestates only as dated history. Post-C070-validator SHA256 `533703A9932195F9718BD4CD0283A2E91440750D75BB12DC783A871D35ABE9B1`, pre-C070 post-validator SHA256 `E34ECC95F38FD76E8C11B85B93AE9880CDD1734244E2261AF045BDE315297C8E`, and assignment-time SHA256 `23A30A208DD046B49284E9CDF33A9B7D5C36CD3BABEA6AF4362A9A26AF868B6C` are dated history.
- Direction remap: [UID:0003Z3] `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md`, current post-Gate2A-repair SHA256 `8CA64FE28E8217ED0A5F9D40A7151902BC87F4360B7667711DAD1A457D03C0E9`, 20,661 bytes / 258 lines. It records the applied F6 `RemapMovementDirectionForMapScroll` name, unsigned-byte stdcall type, exact repeatable comment, and physical argument row while preserving `sub_53A6B0`/signed-char analyzer text as dated history. Post-callback SHA256 `67A1B9364D3490555ABA3543A3E202B9E33193C61ABD33A89B5E3C50CE010CDD` and pre-callback SHA256 `342BE81E7B8D04BF7752021C9C7A1D19B57832CC18180262891BD99C354DFE0C` are dated history.
- Map movement helpers: [UID:000427] current post-Gate2A-repair SHA256 `AD2D53F19B9F1F509F0CA4CE6A48CBC13B8D83EB45450BA1E2DCD3EBEA03FF30`, 7,729 bytes / 66 lines, records the applied F4 `MapPane__ApplyMovementSubstepScroll` name/type/comment and dates `sub_5055E0`; [UID:0002QL] current post-Gate2A-repair SHA256 `C033099F6EBFEA699204996707DA90363D20D1E95A0D5DD683348C710CF1AD3B`, 13,606 bytes / 138 lines, records the applied F5 `MapPane__ScrollViewportByDirection` name/type/comment and dates `sub_5058B0`. Their post-callback SHA256 identities `1D00B3821EEAC8B67DC75753563767EAB51B7A77FFB28552B9B936A0A44DA87B` and `06A84C90FFCEFA5A4FB79517AFB3DBE89186F30FAA481B584B2959FCC85305D9`, and respective pre-callback identities `32FCB9802FDDEE743EF9EBF083E86E028E24167C6F372B8072A63EEF1250C4A7` and `716EB2C00547B187CC25E48073E86FC8026693A930BE55F31C5FD646CFE22B4E`, are dated history.
- UserPane movement support bounded-current identities are [UID:0003U7] SHA256 `66B5D738F534843D5A180809BC322880D425A5038748BE47B7272FD2FB17EE90`, [UID:0003U8] SHA256 `5DA638BEC813B5A2D0B6A15312EE0BBB838B01595586AD6352A5B5C5C2F2B91D`, [UID:0003UE] SHA256 `58BD8B61892CC9BBBBF814C87B1FCBE2D0CF08C118AE0A626012DF9C43B9A555`, [UID:0003UP] SHA256 `BF4B49512098A4A61F2DEEF663913ED4BB02F5C468719F32BED2DBD3F59E51A9`, 19,264 bytes / 236 lines, and [UID:0003UQ] SHA256 `4FD119A21891D95A0ABEBB5F33A52567CA2D56EEE047F7FA095C6CE84C1E3653`, 21,261 bytes / 244 lines. The UID0003UP/UID0003UQ SHA256 identities `4532A43BCB855DC91FD3A5D6DB0549EF50866B62821AD988C4DE0FC9F85F4A94`, 18,671 bytes / 231 lines, and `C91F143CA78EB3DD663C70DA5A7E1FC92BCB1F7606E3FE0D0F722F11416C7C4C`, 20,658 bytes / 239 lines, are dated B005 callback checkpoints; later additive edits advanced both pages while preserving every B005 movement-reply field, event-20/FWdA, ownership, source-route, and formal-C++ detail. The respective pre-callback SHA256 identities `B34DBA294CFFE7F4109826D801AE9DCC7EBA0FB56C8EE7C819359AC855ADCEF7`, `276E927576FEC402C9F03659511F24FCDF5A2557228770464D3D31456618AEC0`, `26B90E49BD30E2A8F61C9BD6EFF66EF324E29640C998FDFB40F5939447EAE75E`, `041A7C759A05A4E904855183AF29B58C1CABB780A6ACC93AF84650319204515D`, and `7724A046E319FB6DA475BCAB68EED3609139097D337A6DD5E554FF74296D176E` are earlier dated history.
- Movement scale: [UID:00027F] `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`, current post-validator SHA256 `28EACB0A88C1EA4750BA0F678FA78D7B0F9E20AE2F019A1ECA652BB2A7E5337E`; pre-callback SHA256 `0B8C6692C797A370AF78A5337268A7ACF8C4C50868C896D578E6BCD1BADA8CFF` is dated history.
- Dated generated checkpoints: validator command `000000019759`, refreshed `2026-07-29T16:10:35-04:00`, produced `auto-generated/NexusTK/ui/panels/UserPane.cpp` SHA256 `CB52AF237A4C98264584CBAE0C1A1560B5C155DC9681CD7A708237D6FCF7785A`, 92,655 bytes / 2,801 lines, and `UserPane.h` SHA256 `5BFDE2DF50A81169BCED5C0CE697227527BB81DF988B544C33CB1B5D04C1A596`, 482 bytes / 8 lines. Command `000000019752` identities `F33C5B8D...3643D` / `0576675D...0CB64` are earlier history. Commands `000000019802`, `000000019887`, and `000000019890` and their exact identities below are dated history. Command `000000019926`, refreshed `2026-07-30T10:34:57-04:00`, produced now-dated `UserPane.cpp` SHA256 `768779686E8854D3D84DC469374F247804DE302F8138DE2C535C542075D09337`, 93,043 bytes / 2,809 lines, and `UserPane.h` SHA256 `D180CE444E3C38B59429C273D57ED4628A6B25CB27E78B686A8A7C43A2E1D7BE`, 482 bytes / 8 lines. Command `000000019993`, refreshed `2026-07-30T11:58:57-04:00`, source `foreground-generated-refresh`, is dated pre-callback history: `UserPane.cpp` SHA256 `ECBAF73497F0C19C4BEC6A42615136070D1361B8309966D1292F4507EC047DE3`, 93,067 bytes / 2,810 lines; `UserPane.h` SHA256 `F1092DABAB6F93140A5519BD9478A9C706DE69F8D13A28D29690B06964899D6D`, 482 bytes / 8 lines; and generated memory SHA256 `4F54811E022C0EEED7E77BF85AFFBF36B25E7E97A41BD9E20878C148A4393C5F`, 1,420,185 bytes / 4,950 lines. Command19993 preserved the pre-implementation topology: `UserPane.cpp` contained a full generated UserPane class declaration, `OnAnimationStep`, a UID0003VD no-code block, and no `UserPane::OnTimer` definition; `UserPane.h` contained neither a complete UserPane class nor an `OnTimer` declaration.
- Command `000000020104`, refreshed `2026-07-30T15:18:49-04:00`, is a dated post-callback generated checkpoint: `UserPane.cpp` SHA256 `6A20BC8C1B8861BC7251CFC4290EDBF038391078CF3181B10F0F74AF5F0AF06E`, 87,909 bytes / 2,670 lines; `UserPane.h` SHA256 `6CAADD22492FE1D21F4A20797F05BE5102DF5676A47D0C3F324D737540ED3B16`, 11,298 bytes / 334 lines; and generated memory SHA256 `BEE343EC97DE3987E641442D6A142B7792482295E12BAA8AEFE02471A484BF12`, 1,421,254 bytes / 4,953 lines. Validator command `000000020109`, refreshed `2026-07-31T01:02:54-04:00`, source `foreground-generated-refresh`, was the then-current bounded physical generated checkpoint at that dated revision: `UserPane.cpp` SHA256 `5499F76A0CF17A88891AD2B98957E4FFCD126F02D5370ED78F318232F6B5DA2A`, 87,909 bytes / 2,670 lines; `UserPane.h` SHA256 `956B6A372C4F26E0E237E3C196586FAFDFC4A0BFD72C1C06ED1AE2F6A14E9B9F`, 11,298 bytes / 334 lines; and generated memory SHA256 `027FB7FD6E725B3433B4E3ACA0C0801CF1CC1D6F5F625C96FA5026207F4B8D9F`, 1,421,254 bytes / 4,953 lines. At that dated checkpoint command20109 preserved command20104's semantic topology exactly: one UID0003VD marker at CPP line 1297 and one `bool UserPane::OnTimer(...)` definition at line 1298, no `OnAnimationStep`, no UID0003VD no-code/empty marker, one harmless `class UserPane;` forward declaration at CPP line 2654, and the blank UID0000FQ CPP emitter marker at line 2668. H contained one forward declaration, one complete `class UserPane : public LivingObjectPane` definition at line 111, exactly one `OnTimer` declaration at line 128, and no `OnAnimationStep`; generated memory line 2452 classified UID0003VD as coded through `auto-generated/NexusTK/ui/panels/UserPane.cpp`. Dated supervisor command `000000020172` is the later valid generated checkpoint: `UserPane.cpp` SHA256 `C0F90A56764C9F6EB5B0698B2C642E6812EC5C26B137D9CA271D20B7FED1A3E0`, `UserPane.h` SHA256 `A98F4CCD8FDA2C102125D4743AC5202DBAC06519EE48E2584A594A4860492117`, and generated memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; its physical readback reconfirmed the same valid one-definition/one-declaration topology with no `OnAnimationStep`, no target no-code/empty marker, and no duplicate complete UserPane class in CPP. Command20109, command `000000020024`, and all earlier identities remain dated corroborating history. These are bounded moving artifacts; a later generated header/physical readback remains authoritative.
- Preserved earlier generated identities: command `000000019802` produced `UserPane.cpp` SHA256 `EF3F3E5962D55DDCEC661D86A79F0F09F133F23B87E4EE2F24112F346CFCEE6F`, 92,655 bytes / 2,801 lines, and `UserPane.h` SHA256 `DF240CDA2CF09309D46E6465BADDA71B5FE6A66D84CE5A7EBD7D1334A40D3BD1`, 482 bytes / 8 lines; command `000000019887` produced `UserPane.cpp` SHA256 `0F1F18A147E41E69469DDAA2FF5686CCE3DA703D0005DCC1F15DAB4F96FE1F85`, 93,043 bytes / 2,809 lines, and `UserPane.h` SHA256 `5129AD7AC52FD4580B34C29567E7C2A047FC352C0B9654720CE6B3837121495F`, 482 bytes / 8 lines; command `000000019890` produced `UserPane.cpp` SHA256 `BCE7725CED0B06D2E35B66D76AB2D40E2BFB90D40E64689F61ED9A26520C25A8`, 93,043 bytes / 2,809 lines, and `UserPane.h` SHA256 `7B07B623E104AAD9CE3126C0BF4CE650673DDDCC9B3499577C52669749444985`, 482 bytes / 8 lines. All are dated history.
- Dated tracker/report checkpoints: validator command `000000019761`, refreshed `2026-07-29T16:13:57-04:00`, produced `auto-generated/-ag-research-tracker.md` SHA256 `D0FC00F7CA525A658CFBFCE08E95ECA13B07E9120B5DDE73B401DA23BB4FDD7F`, 1,677,700 bytes / 6,632 lines; command `000000019753` / SHA `A3A148C5...DAF3` is earlier history. Command `000000019887` produced tracker SHA256 `10ABDA6320862624215BD3AD0432AA74A1CE4511BF46318E07573509C1B5921A`, 1,678,309 bytes / 6,633 lines, and generated-memory SHA256 `F7E45E12A8C487CBB3C7598E13C393DF450AE39CC4FFE6F44CB1FF52B394E79F`, 1,419,904 bytes / 4,949 lines. Command `000000019890` produced tracker SHA256 `C7C933E131C9FBEB3DA853ECA80716F679A8674306EBAB3015E9B88E78CB78B8`, 1,678,309 bytes / 6,633 lines, and generated-memory SHA256 `C963960CD17BDE5EE0CCFCBDCC55F2EBC41FC09E8CAA7C89EDB87AACCC069551`, 1,419,904 bytes / 4,949 lines. Commands `000000019891`, `000000019928`, `000000019933`, and `000000019991` produced dated tracker SHAs `C7EB6279021B1F0F3C202F923358787C08CFA1C89F30F1A39CC53942601A5CC5`, `5D7DA3EA2FFD3E3C201142EAADAF5A5C753877A84D296E911BC2F827898C378B`, `A1FA9680D296AF86A2BDBB7C6994413256035E5292ADECB4FB42E985B04958D1`, and `A4C669849606F1E765321B18E64EC1A09C89942D2D6321368E8C1CED234A8BA6`. Command `000000019926` produced dated generated-memory SHA256 `6A2DA8391DDE03DDF7949AE430E6E5A538F364C4D0F1D3FAAAB14B7A7F3CD544`, 1,419,904 bytes / 4,949 lines. Command `000000019993` produced dated generated-memory SHA256 `4F54811E022C0EEED7E77BF85AFFBF36B25E7E97A41BD9E20878C148A4393C5F` and tracker SHA256 `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`; its UID0003VD row was the pre-implementation `87/89` state. Commands `000000020024`, `000000020034`, and `000000020104` are later dated checkpoints. Command20104 produced tracker SHA256 `784D99B4A4C01C389EBBA2C057E636CC88BEADC9EF452E2FC71F3B103F9280CF`, 1,680,971 bytes / 6,637 lines. Command20109's tracker SHA256 `706757C06C971EE12553F07CBE68178BCD73153AFA74CD7375B24A369332B342`, 1,680,966 bytes / 6,637 lines, and UID0003VD line 3411 are dated tracker history; command20109's generated-memory identity is likewise dated corroborating history and was superseded for later valid generated proof by command20172 as recorded above. The bounded post-command `000000020160` moving tracker readback at `2026-07-31T02:08:05-04:00` is SHA256 `CF8C778FCA2A2F9F4D0DF55D6710B5770F8994C74E45C663EDCD9280688ACA3B`, 1,685,974 bytes / 6,658 lines; UID0003VD at line 3431 remains `94/94`, reconstructable, with `0/0/0` direct/additional/total reports and the same path. The durable claim is the target's reconstructable `94/94` source-quality state; command ID, report-registration counts, row number, whole-file hash, and later physical tracker state are moving validator-owned facts authoritative only from the then-current artifact and validator lifecycle metadata.
- Dated pre-application manual-coverage checkpoint: the bounded read-only physical reread at `2026-07-31T01:02:04.6444749-04:00` observed `by-memory/-coverage-report.md` SHA256 `C71EE2C379B28E94B8F414561D55A15F8934E3A8A6F093424004B352DA674C3D`, 2,113,445 bytes / 4,778 lines; `by-class/-coverage-report.md` SHA256 `23D53F6FBBDEE49EA028665CCD9E3100B9C9FC83AEEDF519F8F8D622D8B51303`, 272,710 bytes / 625 lines; and `by-file/-coverage-report.md` SHA256 `AFFD68360B091C992006A2329AC3D4F64110D192E0FE91943988DFA53C1428C7`, 163,270 bytes / 317 lines. At that time UID0003VD and UID000427 were absent; UID0003VB at line 3809 was immediately followed by UID0003VE at line 3810; M02/M03 still contained the disproved pending-target ObjectPane wording at by-class line 589 and by-file line 298; M04 was stale at by-memory line 2796; and M06-M09 were stale at lines 3794, 3829, 3830, and 4442. All nine literal mutations were therefore applicable. N01-N06 were exact prospective no-ops at lines 2777, 2790, 2360, 3796, 3806, and 4489. The `2026-07-30T15:18:12.4035946-04:00` SHAs `F36B0558...2B990`, `E40F0932...AA0051`, and `30112D67...9AA2B`, the `2026-07-30T13:46:46.6830719-04:00` by-memory SHA `EE94FB8B...EF1074`, immediately preceding `4243659D...11D718` checkpoint, the `82A918D0...F0C8E`, `396DAD20...D0A9E9`, and `736B2900...B6BFE` checkpoint, and every earlier physical identity/line position are dated history. The later supervisor-applied rows and commands `000000020166` through `000000020168` below supersede this snapshot.
- Dated post-application coverage lineage: the supervisor-supplied Gate 1 snapshot observed `by-memory/-coverage-report.md` SHA256 `6C2C8B453EBBB98E1C5932F6B3B300EA8167CE9620CA1386EAA9F772ADD741B7`, 2,118,546 bytes / 4,787 lines; `by-class/-coverage-report.md` SHA256 `9B8B77532BAA43613618BCB3275E9E9D6668EADA1A499F154ACAC18B3DAF5033`, 273,344 bytes / 625 lines; and `by-file/-coverage-report.md` SHA256 `E71703BB63B1E1C9A4E9CED4677F5E1C1355416655282674378DA1ADF6EA4126`, 164,309 bytes / 317 lines, with M01-M09 at `3818, 589, 298, 2799, 2362, 3802, 3838, 3839, 4451` and N01-N06 at `2780, 2793, 2363, 3804, 3814, 4498`. A later by-memory-only checkpoint SHA256 `5CDCBB4B7CBAD1516373078F0117F4062087F806F69E98574F077705AEDD53FF`, 2,119,450 bytes / 4,788 lines, shifted those by-memory anchors once. Both snapshots and command20166-20168 identities are dated history.
- Bounded coverage reread for this repair: `by-memory/-coverage-report.md` SHA256 `DDB43AB5B6B22EE411536C9A470847389C42CC3CB4EDC159D0BF509173EAFAE2`, 2,121,961 bytes / 4,790 lines; `by-class/-coverage-report.md` SHA256 `34287BEF3C9E700199102050F52BCA1C87189863E3A977C16021783D8027E2C1`, 274,255 bytes / 625 lines; and `by-file/-coverage-report.md` SHA256 `F203FD4C148CE2192868B4CBE8C1E094C50F438548977C885FF378D78F90210B`, 165,800 bytes / 318 lines. Exact M01-M09 anchors at that checkpoint are `3820, 589, 299, 2801, 2363, 3804, 3840, 3841, 4454`; exact N01-N06 anchors are `2782, 2795, 2364, 3806, 3816, 4501`. Literal reread confirmed every M row still equaled its applied payload and every N row still equaled its no-op payload. These hashes and positions are bounded moving evidence only; later physical coverage and validator metadata supersede them without invalidating the durable UID-row semantics.
- Dated pretransaction shared-IDB lineage is lifecycle-neutral: every physical IDB hash is a dated checkpoint, never durable current truth. The complete F1-F9/C1/T1 discovery pass used session `1da2b2ae` at saved SHA256 `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`; the semantic-repair pass used the same session at SHA256 `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`; and later no-drift checkpoints include `836ABCFA...CF489F` and `DAA59745...7462C17`. The pre-maintenance bounded read-only rebind used MCP session `07b29e1b` while the physical IDB matched dated SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94`, 143,194,997 bytes, saved `2026-07-30T13:20:02.4956587-04:00`; post-maintenance session `f608d7c2` reconfirmed its target-local state. The later A0 checkpoint under that session used saved IDB SHA256 `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`. The final bounded pretransaction target-local pass used the same session against saved IDB SHA256 `F7C936C072D1332D82D06A92F89F3531D97EE8D9252A2C3C6325B2580F8D7D8A`, 143,192,467 bytes, saved `2026-07-30T14:56:51.3756829-04:00`. `server_health` returned `status:ok`; bounded `lookup_funcs`, `stack_frame`, `get_comments`, `get_bytes`, `xrefs_to`, `type_inspect`, exact-name collision lookups, and ten target-local `decompile` calls preserved every then-current F1-F9/C1/protected function name, range, prototype, literal physical frame, four entry-comment channels, byte hash, xref set, vtable cell, fence, successor, TimerHandler/MapPane UDT dependency, and all nine proposed-name collision absences. The 132-row internal-comment comparison returned 132 declared, 132 nonempty, and zero mismatches. At that checkpoint `UserPane` remained size `0x13eb84` with 60 members and exact C155-C156 rows; complete `LineInputPane` size `0x108` superseded the dated A0 incomplete-type observation. The planned T1 size-neutral splits led deterministically to 68 UserPane members. No UID0003VD function, behavior, physical frame, Hex-Rays semantics, byte, xref, boundary, comment, collision, or protected dependency drift occurred before mutation. `A0D97FC5...4375971`, `4A9360D1...A2526C94`, `DAA59745...7462C17`, `DADC487F...C6A4`, `836ABCFA...CF489F`, `D7D29DEB...D08CCA`, `3892BDA8...472798D1`, and every earlier identity are dated history; the later B180/CF transaction paragraph records the applied poststate.
- The supervisor transaction supersedes that pretransaction currentness while preserving it as history: exact prestate/backup SHA256 `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`, 143,192,467 bytes; applied and independently verified F1-F9/C1/T1; exact protected hashes/xrefs/comments/frames/UDTs unchanged; one save to dated poststate SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, `2026-07-31T03:00:53.6024151-04:00`. The later saved-IDB checkpoint SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, 143,192,707 bytes, saved `2026-07-31T04:26:38.9922636-04:00`, is also dated intervening history rather than target-local current proof.
- Catalog0380 saved SHA256 `1BC3C43BCEDB92B9BF8950DA6E6DE759C3FA44B50C6A2FA0458CE129B6800CFD`, 143,195,497 bytes, at `2026-07-31T05:35:32.8233834-04:00`; the later supervisor B008 Gate 2B save produced SHA256 `5F2679A7C6BFF2CD3E91FE59BDCBD298C1A233EB7988D838C34C05508FC79A21`, 143,192,720 bytes, at `2026-07-31T05:57:03.6144571-04:00`. Both are dated history. Supervisor Gate 2B catalog0382 then advanced the physical IDB to SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`. A fresh bounded read-only target/protected reread under MCP session `f608d7c2` independently reconfirmed all F1-F9/C1 names, ranges, source-facing prototypes, literal frames, four entry-comment channels, byte hashes, xrefs, target fences, vtable cell, successor, UserPane/LineInputPane/TimerHandler/MapPane type state, the three protected functions, ten canonical-name lookups, ten bounded decompilations, and all 132 literal internal-comment addresses enumerated below. No target or dependency drift was found. This `B7CC...58277` identity is the latest dated saved checkpoint used for this Gate 1 currentness repair; like every shared IDB hash, it is not durable future truth.
- Bounded filesystem currentness reread all 17 ordinary callback destinations named in Changed Files as a current union, not as an all-but-C070 byte-identity claim. Five support destinations advanced through the explicit Gate 2A repair layer: UID0003Z7 `3A78A43A...A97986`, UID0003Z3 `8CA64FE2...03C0E9`, UID0002R1 `3C953986...118293`, UID000427 `AD2D53F1...03FF30`, and UID0002QL `C033099F...1AD3B`; their callback/C070 hashes are dated history. The target and the other unaffected nonshared destinations still match their applicable callback or later additive rows. UID0003UP is SHA256 `BF4B49512098A4A61F2DEEF663913ED4BB02F5C468719F32BED2DBD3F59E51A9`, 19,264 bytes / 236 lines, and UID0003UQ is SHA256 `4FD119A21891D95A0ABEBB5F33A52567CA2D56EEE047F7FA095C6CE84C1E3653`, 21,261 bytes / 244 lines. The later additive UID0003UP/UID0003UQ edits preserve all B005 movement-reply semantics, fields, ownership, source placement, and formal payloads; their callback-output hashes remain dated history in the table. The two shared UserPane owners first advanced additively through B007 UID000415 to class SHA `7C2BCD5F...B47982` and file SHA `1FA4850B...CE55`, then through B008 UID00035P to callback-input class SHA `DB786753...97578` and file SHA `54A260E4...781B`, through this accepted UID0003VD callback to class SHA `C7873624...1BFB9` and file SHA `512BA4D0...4CA33`, and finally through B008's later additive UID00035P post-IDA reconciliation to bounded class SHA `4784B20F...BCE6D8` and file SHA `8A534098...08D772`. Those pages preserve every UID000415 chat-history contract and every UID0003VD OnTimer/formal/layout/source claim while adding B008's catalog-0377 saved-layout provenance. Earlier hashes are history, not current-union identities.

## Target

Additional target UIDs: none. UID0003VD is the sole declared target; every other UID below is a support destination and is not claimed as additional report coverage.

| Field | Documented state | Supervisor verification invariant |
| --- | --- | --- |
| UID/path | `0003VD`, `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` | unchanged path and UID |
| Range | `[0x005a83b0,0x005a87ad)`, `0x3fd` / 1,021 bytes | unchanged, one method |
| Current IDA entity | dated pre-Gate2B state was `sub_5A83B0`, `char __thiscall(int this, int a2, int arg0a, unsigned int a4)` | applied/read back as `UserPane__OnTimer`, machine type `bool __thiscall UserPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)` |
| Source signature | ordinary docs now use `bool UserPane::OnTimer(int timerId, int arg0, int arg1)` | supervisor verifies IDA and generated topology against the same contract |
| Owner/emitter | `CANONICAL_OWNER:0000FQ`, `EMITTER_UIDS:0000FQ` | unchanged |
| Reconstructable | `TRUE` | unchanged |
| Score | `94/94` after command `000000019997` | unchanged unless later evidence requires correction |
| CPP | complete C++03 body from this report | any transition verifies the then-current generated CPP contains exactly one UID0003VD definition |
| H | blank on this child; declaration is in class UID0000FQ formal H | any transition verifies the then-current generated H contains exactly one matching declaration |

## Current Target State

The current ordinary target page has the right exact range, UserPane owner/emitter, source file, sole vtable pointer, three-byte successor fence, and separate successor. The accepted callback removed its four stale source-document claims: the method is `OnTimer`; local event `0x14` is `kUserPaneMovementStep`; movement state is expressed through the report's size-neutral named fields; and formal CPP contains the complete source body. The previous `OnAnimationStep`/unresolved-event/array-field/no-code state remains only as explicitly dated corrected history. The bounded C070 callback added the literal `UserPane::PropagateLinkedObjectMode(int mode)` spelling. The subsequent Gate 2A repair synchronized UID0003Z7, UID0003Z3, UID0002R1, UID000427, and UID0002QL to the already-applied F2-F9 names/types/comments and dated every raw analyzer prestate; C104 now matches UID00027F's existing signed-consumed plain-`char` contract. B005 did not mutate IDA; the supervisor applied and independently verified the complete F1-F9/C1/T1 Gate 2B transaction.

The target bytes are SHA256 `0260F191AA50A541D89BE148F3414DF840E88BEFBA8DABE62AF6E87C85BE8263`. First 16 bytes are `55 8B EC 8B 45 08 83 EC 08 53 56 57 8B F9 83 F8`; last 16 are `4E EA 13 00 01 5F 5E B0 01 5B 8B E5 5D C2 0C 00`. The method has 301 instructions, 48 basic blocks, cyclomatic complexity 23, 11 distinct direct callees, and one inbound data reference.

The full bounded `3892BDA8...472798D1` pass found no behavioral, byte, boundary, xref, ownership, source-placement, formal CPP/H, score, protected-comment, or UDT-neighbor drift from dated checkpoint `4EDEC155...A4B5D09F` or its predecessors. The later `D7D29DEB...D08CCA` slot-focused pass found no UID0003VD target/helper use of `+0x210` and no drift in the exact relevant constructor/handler functions or UserPane size/neighbors. The pre-maintenance rebind under session `07b29e1b` and dated saved IDB `4A9360D1...A2526C94`, followed by post-maintenance session `f608d7c2`, found no F1-F9/C1 or protected-state drift. The bounded A0 and F7 rereads are dated pretransaction history. The supervisor preflight then matched every mutable/protected function hash, range, frame, xref, entry-comment channel, all 132 internal comments, expected-name collision absence, and protected UDT dependency at dated IDB SHA256 `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`. F1-F9/C1/T1 were applied and independently read back without byte, xref, boundary, vtable, fence, successor, or protected-dependency drift, then saved at dated IDB SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, timestamp `2026-07-31T03:00:53.6024151-04:00`. The intervening `4B5F...A696A`, catalog0380 `1BC3...0CFD`, post-B008 `5F2679A7...79A21`, and all earlier hashes are dated history. The fresh post-catalog0382 reread against saved IDB `B7CC899D...58277` reconfirmed the applied poststate: `UserPane` is size `0x13eb84` with exactly 68 members; the requested size-neutral rows are present; `LineInputPane *m_activeLineInputPane +0x210`, the `+0x214` tail, complete `LineInputPane` size `0x108`, TimerHandler size 4, and MapPane size `0x910` remain exact. In the physical frames, F1/F7 `timerId` and `arg1` plus F9 `mode` render as `signed __int32`, while F1/F7 `arg0` renders as `int`; F1's local renders as `struct MapPoint`, and function prototypes retain source-facing `int`/`MapPoint` spellings. F8 retains the materialized `mode @ 0x08 / 0x4 : int` row. No target byte, xref, boundary, vtable, fence, successor, comment, frame, type, or protected-dependency drift was found. The B7CC identity is the latest dated checkpoint for this repair, not durable future authority.

Command `000000019993` is the dated pre-callback generated checkpoint that placed the full class declaration in `UserPane.cpp`, declared `OnAnimationStep`, and emitted only the target no-code comment. Commands `000000019926`, `000000019890`, `000000019887`, `000000020024`, and `000000020104` are dated history. Dated command `000000020109` proved the accepted ordinary topology: `UserPane.h` contained one complete class definition and one `OnTimer` declaration; `UserPane.cpp` contained only a harmless forward declaration, the expected blank UID0000FQ CPP emitter marker, and exactly one UID0003VD `UserPane::OnTimer` definition; neither output contained `OnAnimationStep`; and the target no-code/empty marker was absent. C070 validator command `000000020142` deliberately disabled generated refresh. Dated supervisor command20172 later reconfirmed the valid generated topology with the exact hashes recorded in Validator Results. At any transition, the then-current generated artifacts and command metadata govern topology, raw-name/adjusted-pointer absence, and duplicate-definition checks.

## Executive Recommendation

1. Reconstruct the exact method as `UserPane::OnTimer` in the UID0003VD CPP channel.
2. Move the complete current UserPane class formal from UID0000FQ CPP to UID0000FQ H, replace `OnAnimationStep` with `OnTimer`, keep UID0000FQ CPP blank, and keep the child H channel blank to prevent duplicate declarations.
3. Preserve UserPane size `0x13eb84` while replacing the touched opaque/array members with the named one-byte fields documented below.
4. Synchronize U7/U8/UE/UP/UQ and vtable/timer/helper prose so old array names and `OnAnimationStep` are historical only; C070 is complete because UID0003Z7 now gives the literal accepted `UserPane::PropagateLinkedObjectMode(int mode)` name for its already-present `0x005a9240` thunk evidence.
5. Correct UID0002QL's reversed `DirectionToTileOffset` argument order.
6. Preserve the supervisor-applied and independently verified F1-F9/C1/T1 IDA poststate, including canonical physical type spellings and F8's materialized `mode` argument row.
7. Preserve the applied M01-M09 manual rows and verified N01-N06 no-op rows; their scoped coverage validations are commands `000000020166` through `000000020168`.

## Supervisor Active Recheck

The dated pretransaction bounded read-only MCP session was post-maintenance session `f608d7c2`. During the F7 checkpoint pass, `server_health` returned `status:ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, image base `0x400000`, Hex-Rays ready, strings cache ready with 2,068 entries, and `auto_analysis_ready:false`; bounded valid calls succeeded, so the documented false flag is contextual rather than an outage.

The supervisor transaction bound its exact prestate to dated SHA256 `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`, 143,192,467 bytes, and copied it to `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B005-UID0003VD-20260731-025655.i64` with the same SHA and size. After applying and independently reading back F1-F9/C1/T1, preserving all protected entities, the supervisor saved exactly once. The dated saved poststate is SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, saved `2026-07-31T03:00:53.6024151-04:00`. F7, A0, 4A, DAA, 3892, D7D2, and every earlier physical identity are historical. No shared-IDB hash is durable current truth; the exact poststate is the transaction's bounded saved checkpoint and later lifecycle review must reread the then-current artifact.

Bounded live checks made while the physical IDB matched dated checkpoint `3892BDA8...472798D1` confirmed exact function sizes, prototypes, entry comments, all 132 protected internal comments, frames, xrefs, vtable cells, UserPane/TimerHandler/MapPane UDTs, target/helper/protected bytes, boundary bytes, and zero exact-name collisions for all nine proposed function names. The later D7D2/4A/A0/F7 passes remain detailed dated discovery and confirmation history. Transaction preflight at `B180F0...F2A07` matched every declared prestate and collision absence. The applied readback confirms all nine canonical function names, source-facing function types, frame names/types, exact function-repeatable comments, C1's sole regular-comment replacement, the 68-member size-neutral UserPane layout, all 132 internal comments, four entry-comment channels, function hashes, xref sets, boundaries, vtable cells, fences, successor, complete LineInputPane, TimerHandler, MapPane, and all protected functions. The poststate was saved once at `CF18895C...2C7F96`; later shared-IDB state must still be reread rather than inferred from this dated hash.

The fresh post-catalog0382 repair reread used healthy session `f608d7c2` against exact saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`. `server_health`, `lookup_funcs`, `func_profile`, literal `stack_frame` and `get_comments`, exact `get_bytes`/`xrefs_to`, `type_inspect`, exact-name lookups, and ten bounded `decompile` calls matched every F1-F9/C1/protected name, range, prototype, frame, comment channel, hash, caller/xref set, collision disposition, target fence, vtable cell, successor, and required type/member row. A separate batched read of all 132 literal internal-comment addresses enumerated in this report returned zero text/channel mismatches. The target is `[0x005a83b0,0x005a87ad)` SHA `0260F191...8263`; pre-boundary SHA `F5594071...4FB9`, post-boundary SHA `1956EFAF...20B3`, vtable bytes `B0 83 5A 00`, and successor `UserPane_GetActiveMovementHistoryRecordByIndex` at `0x005a87b0` are exact at this saved checkpoint. The prior `5F2679A7...79A21` reread, CF18895C transaction poststate, and 4B5F/1BC3 intervening saves are dated history only.

## Inference Research Guidance Check

- Direct binary facts and inferred source spellings are separated throughout.
- The final source contains no `sub_`, `dword_`, `byte_`, `this-0xa4`, anonymous offset dereferences, or decompiler temporaries.
- Lack of original symbols is handled by ranked human-source inference, not by retaining raw names.
- Runtime behavior takes priority; source shape then follows existing subsystem conventions and Visual C++-era C++03 style.
- Existing accepted names are retained when behavior supports them: `OnTimer`, `ScheduleBoxRotationStep`, `SyncPositionToLinkedObjects`, `PropagateLinkedObjectMode`, `ApplyMovementSubstepScroll`, `ScrollViewportByDirection`, and `RemapMovementDirectionForMapScroll`.
- Wave2/Wave3 material was not used. Any such mentions in old artifacts are stale and excluded.

## Heuristic / Inference Reanalysis And Validation

### Timer contract and adjusted receiver

`0x0062efc0` is the UserPane `TimerHandler` secondary vtable. Cell `0x0062efc4` contains the only pointer to `0x005a83b0`. `TimerHandler` is exactly four bytes with a vftable; its contract is `bool OnTimer(int timerId, int arg0, int arg1)`. The machine callback receives the secondary facet, hence complete UserPane is `ECX - 0xa4`. C++ multiple-inheritance dispatch performs this adjustment automatically. `OnAnimationStep` is rejected because it does not match the inherited virtual contract or the default delegation.

### Event `0x14`

`UserPane::InitializeWalkAnimation` and `UserPane::StartDirectionalAnimation` schedule timer ID 20 through `static_cast<TimerHandler *>(this)`, carrying direction in `arg0`. UID0003VD is the matching vtable callback, handles case 20 locally, and reschedules the same ID with the display-status byte divided by movement scale. The human constant remains the already accepted `kUserPaneMovementStep = 20`.

### Movement state

| Complete UserPane offset | Current broad storage | Source-facing decision | Exact evidence |
| --- | --- | --- | --- |
| `+0x1c4` | inherited `m_isMoving` | unchanged bool | direct tests/stores and LivingObjectPane UDT |
| `+0x1c5` | inherited `m_facing` | unchanged unsigned byte | direction-to-offset input |
| `+0x1c6` | hidden in IDA gap; documented `m_moveFrame` | signed char `m_moveFrame` | signed loads/comparisons, four-substep modulo |
| `+0x20c` | `m_userPaneBaseState[0]` | bool `m_movementTimerHandled` | constructor clears; both local timer branches set; no other direct references |
| `+0x13eaf0` | `m_movementState[0]` | unsigned byte `m_movementMode` | adjacent state byte; no direct references in current image; high-probability durable name rather than a raw offset |
| `+0x13eaf1` | `m_movementState[1]` | signed char `m_movementReplyCount` | six reply paths store word `0x0101` at `+0x13eaf1`; target pre-decrements and uses signed `>0` |
| `+0x13eaf2` | `m_movementState[2]` | bool `m_movementReplyReceived` | initialized/cleared with pending byte; target gates at frame 2 and sets after continuation restart |
| `+0x13eaf3` | `m_movementState[3]` | bool `m_movementReplyPending` | target sets when animation outruns reply; player-settings path tests/clears; reply handlers test it |
| `+0x13eaf4` | `m_movementState[4]` | bool `m_directionDelayActive` | accepted helper name; target reverses frame progression, remaps direction, and suppresses ordinary completion movement while active; seven complete-object references clear/read it |
| `+0x13eb1e` | `m_movementHistoryState[0]` | unsigned byte `m_movementReplyTimerFamily` | target stores 0 for event 20 and 1 for FWdA; reply handlers select timer family from zero/nonzero |
| `+0x13eb1f` | `m_movementHistoryState[1]` | bool `m_movementHistoryEnabled` | constructor writes word `0x0100` at `+0x13eb1e`, yielding selector 0 and byte 1 true; no separate direct consumer found |

The exact original private spellings are stripped, but the selected names encode observed roles and produce human source. The two fields without direct readers are explicitly confidence-capped; they do not justify raw array indexing in the target's final C++.

### UserPane `+0x210` active line-input slot

Fresh bounded live listing and decompiler reads against dated saved-IDB checkpoint `D7D29DEB...D08CCA` resolve the previously conflicting `+0x210` contract. There are exactly 20 relevant instructions: one non-null read, one non-null write, and eighteen zero stores. The sole non-null writer is `LineInputPane__Constructor`, whose typed receiver is `LineInputPane *this`; it stores that exact receiver. No function stores an `ObjectPane *` to the slot.

| Address(es) | Function/range | Exact access and semantic result |
| --- | --- | --- |
| `0x005a2663` | `UserPane` constructor `0x005a2530` | initializes the pointer to zero |
| `0x004f1c70`, `0x004f1e2c` | [UID:00035P] `LineInputPane__Constructor` | reads/queues the prior pointer, then stores typed constructor `this`; the only non-null read and write |
| `0x004f25fe`, `0x004f2661` | [UID:00035Y] shared LineInputPane handler | clears the slot on dismissal paths |
| `0x004f298f` | [UID:000364] CharInputPane handler | clears after deferred-delete queueing and before inherited/accept handling |
| `0x004f2d3d` | [UID:00036C] MultiLineInputPane handler | clears after deferred-delete queueing |
| `0x005ae7fe`, `0x005ae917`, `0x005ae9a0` | SpellWhoInputPane pointer-selection handler | clears the active input pane around close/selection paths |
| `0x005af11c`, `0x005af218`, `0x005af27d` | ItemWhoInputPane mouse handler | clears the active input pane around close/selection paths |
| `0x005afad9`, `0x005afc20`, `0x005afc46` | SelectObjectWithKeyboardPane mouse handler | clears the active input pane; selected `LivingObjectPane *` values remain separate locals/globals and MapPane call arguments |
| `0x005b0359`, `0x005b04a0`, `0x005b04c6` | TargetObjectWithKeyboardPane mouse handler | same active-input clear pattern; selected object state is separate |
| `0x005b1cbc` | NewSayToUserMessageInputPane key handler | clears the old active input before constructing its replacement |

The highest-probability human contract is therefore `LineInputPane *m_activeLineInputPane` with inline `ClearActiveLineInputPane()`. `m_currentLineInputPane` is a plausible stripped lexical alternative, but `active` matches the established project terminology and the replace/clear lifecycle. The dynamic/source type and semantics are direct, not heuristic: constructor `this` is the only stored non-null value, the previous same-typed pointer is queued for deferred deletion, and all consumers clear it when the active input pane closes or is replaced.

The older `ObjectPane *m_pendingTargetObject` / `ClearPendingTargetObject()` interpretation is retained only as disproved history. It arose because object-target selection handlers clear `+0x210` next to MapPane object interaction. Focused decompilation shows those handlers keep the selected object in separate locals/globals and pass it independently; `+0x210` is cleared because the selection input pane is being dismissed. The complete image supplies no `ObjectPane *` store to this field.

Bounded `search_text` returned zero `210h` hits in UID0003VD `[0x005a83b0,0x005a87ad)` and in F2-F9/C1. This correction changes only shared UserPane layout/formal/support history and manual UserPane coverage wording; it does not change UID0003VD behavior, target CPP, target score, helper contracts, or the nine function IDA actions.

### Branch differences

- Both movement cases use `4 * g_movementSubstepScale`, advance forward normally, move backward and remap direction while direction delay is active, stop at frame zero, and schedule `kLivingTimerBoxStep` through `ScheduleBoxRotationStep`.
- Both set `m_movementTimerHandled` before frame work.
- If a forward frame reaches at least two before a movement reply, scheduling pauses; at exactly two the target sets `m_movementReplyPending` and records the timer family.
- Event 20 completion adds facing offset to map and viewport coordinates, propagates mode, then synchronizes linked objects. Its continuation uses `StartDirectionalAnimation`.
- FWdA applies fractional MapPane scrolling while moving. Normal completion propagates mode, warps map coordinates while keeping viewport coordinates unchanged, applies the final substep scroll, shifts the viewport by the original direction, and synchronizes linked objects. Its continuation uses `InitializeWalkAnimation`.
- Direction-delay completion suppresses ordinary warp/scroll and continuation countdown exactly as the machine code does.

## Evidence Standards Used

| Evidence class | Use |
| --- | --- |
| Direct IDA/MCP fact | function boundaries, bytes, prototypes, comments, frames, xrefs, decompile branches, UDT sizes/members, vtable route, collision results |
| Current ordinary documentation | accepted owner/emitter, C++ conventions, helper roles, class layout, timer constants, source paths |
| Generated output | transition-sensitive lead and expected topology only; never authority over IDA/docs |
| Executed reports | searched by UID/address/name/family, then used only as leads when current evidence reconfirmed them |
| Heuristic inference | stripped private field/helper spellings and original source organization; alternatives ranked and evidence recorded |
| Negative evidence | absent callers, absent duplicate vtable routes, absent direct field readers/writers, absent embedded data/split need, zero proposed-name collisions |

## Evidence Checked

### Positive checks

- Earlier dated discovery/currentness passes against database `1da2b2ae` used `lookup_funcs`, `analyze_component`, `analyze_function`, `decompile`, `disasm`, `stack_frame`, `get_comments`, `xref_query`, `entity_query`, `type_inspect`, `search_text`, and `get_bytes`; this is historical tool provenance, not the exact `3892BDA8...472798D1` bounded-pass tool list. The `4EDEC155...A4B5D09F` and `2CCA289F...F70D7E851` bounded passes are also dated history.
- The bounded pass made while the physical IDB matched dated checkpoint `3892BDA8...472798D1` used only `idb_list`, `server_health`, `lookup_funcs`, `func_profile`, `stack_frame`, `get_comments`, `get_bytes`, `xrefs_to`, `type_inspect`, and exact proposed-name collision lookups through `lookup_funcs`; all valid calls succeeded. The internal-comment comparison returned exactly 132 declared rows, 132 actual nonempty rows, and zero mismatches. `search_text`, broad decompilation, mutation, and save were not used in this pass. The narrow additive Gate 1 repair under pre-maintenance session `07b29e1b` and dated physical SHA `4A9360D1...A2526C94` used `server_health`, one-instruction bounded `disasm`, batch `stack_frame`, and exact-name `lookup_funcs`; it returned all literal frame rows for F1-F9/C1 and the three protected functions, and all nine collision queries remained Not found. Post-maintenance session `f608d7c2` first reconfirmed that checkpoint and later performed the bounded dated A0 pass with `server_health`, bounded address/name `lookup_funcs`, `stack_frame`, `get_comments`, `get_bytes`, `xrefs_to`, and `type_inspect`. The latest bounded F7 pass under the same session used `server_health`, schema-only tool listing, bounded `lookup_funcs`, `stack_frame`, `get_comments`, `get_bytes`, `xrefs_to`, `type_inspect`, exact-name collision queries, and ten target-local `decompile` calls. Every function, physical frame, Hex-Rays argument/local inventory, entry-comment channel, byte hash, xref set, collision disposition, fence, vtable cell, successor, TimerHandler state, MapPane state, and UserPane row matched; the internal-comment reread was exactly 132/132/zero-mismatch. The only new type-library fact is complete `LineInputPane` size `0x108`, superseding the dated A0 incomplete-type observation without changing UserPane or target semantics. No mutation or save occurred.
- Exact target pointer `0x0062efc4 -> 0x005a83b0` and neighboring TimerHandler secondary-vtable layout.
- Full target decompile and relevant helper decompiles at `0x0053bf40`, `0x0053c070`, `0x00597910`, `0x005a5a90`, `0x005a36f0`, `0x005a3770`, `0x005058b0`, `0x005055e0`, `0x0053a6b0`, `0x0053b830`, `0x005a9240`, and `0x0053c290`.
- Complete-object and adjusted-facet searches for offsets `+0x13eaf1..+0x13eaf4`, `+0x13eb1e`, and their target-relative forms.
- Current by-* target, class, file, vtable, timer, movement, MapPane, global, successor, and broad-index pages.
- B007 UID000415 report and its additive UserPane class/file implementation, followed by B008 UID00035P ordinary/post-IDA work. B008 report SHAs `56402F4C...F680ED` and `74F22808...B3AB64` are both dated moving research checkpoints rather than present authority. Current ordinary evidence independently preserves the conclusion: UID00035P is SHA `CCF28C56...53C1`, UID00035Y is `3CA614F2...A69A`, UID000364 is `69F010C8...BA76`, UID00036C is `76250E13...2D7`, InputPanes is `77948F03...5227`, and current shared class/file hashes are `4784B20F...BCE6D8` and `8A534098...08D772`. Their typed constructor read/queue/store, handler clears, class/file layout rows, and the dated bounded IDA slot readback all agree on `LineInputPane *m_activeLineInputPane +0x210` / `ClearActiveLineInputPane()`; no moving B008 report identity is required. B008 callback-input UserPane hashes `DB786753...97578` and `54A260E4...781B`, followed by UID0003VD post-validator hashes `C7873624...1BFB9` and `512BA4D0...4CA33`, remain dated history. UID000415 and UID0003VD material coexist without loss.
- The `D7D29DEB...D08CCA` bounded repair pass used `server_health`, `type_query`, `lookup_funcs`, bounded `search_text`, `xrefs_to`, and focused `decompile` on the constructor and a representative target-selection handler. It found the exact 20-access inventory above, 37 constructor xrefs, 27 shared-handler xrefs, 20 CharInputPane-handler xrefs, two MultiLineInputPane-handler xrefs, and zero `+0x210` hits in UID0003VD or F2-F9/C1.
- Search terms `0003VD`, `0x005a83b0`, `sub_5A83B0`, `UserPaneHandleAnimationStep`, `OnAnimationStep`, and `UserPane OnTimer` across active and executed B reports.

### Negative checks

- No direct code caller to `0x005a83b0`; exactly one data/vtable route, which is expected for a virtual override.
- No second function, table, literal pool, exception body, or internal entry inside `[0x005a83b0,0x005a87ad)`.
- No unexpected exact-name collision exists. Each dated pretransaction query returned zero before its rename; the saved-IDB `B7CC899D...58277` exact-name reread resolves each canonical name only to its expected function address.
- No source ownership evidence for MapPane, LivingObjectPane, TimerMgr, a free helper, the broad aggregate, or a new file.
- No direct reader of complete `UserPane +0x20c`; no direct use of movement byte `+0x13eaf0`; no direct use of history byte `+0x13eb1f` beyond constructor initialization.
- No direct setter of `m_directionDelayActive` to true was found; its branch behavior is nevertheless exact and the existing accepted name is retained rather than replaced by a more speculative one.
- No `ObjectPane *` write to UserPane `+0x210` exists. The sole non-null writer stores typed `LineInputPane *this`; all other writes are zero. Selected ObjectPane/LivingObjectPane values in target-selection handlers remain separate from the cleared slot.
- No `+0x210` access occurs in UID0003VD or its F2-F9/C1 helper set, so the corrected support-layout contract cannot alter the reconstructed target control flow or score.

### Failed, unavailable, or skipped checks

- Original symbols/PDB/source names are unavailable; source spellings are inference with explicit confidence.
- `auto_analysis_ready:false` was present, but health and bounded required queries succeeded; it did not block research.
- One oversized multi-region `get_bytes` request stalled and produced no usable result; it was abandoned rather than treated as evidence. Replacement reads capped each region at 128 bytes, reconstructed every full function in address order, and reproduced all 13 exact report hashes.
- Broad decompilation was not repeated during this bounded currentness/frame repair because all function byte hashes, boundaries, prototypes, xrefs, comments, and dependent types matched the prior analyzed state. The narrow repair reread only literal frames and proposed-name collisions; the earlier full decompiles remain preserved evidence rather than a newly claimed current-pass query result.
- No IDA mutation/save, validator, lifecycle command, generated refresh, coverage edit, lease operation, or ordinary-doc edit was attempted because this is report-only.
- Third-party import analysis is not applicable; this is first-party NexusTK UI/map code.

## Claim And Incorporation Ledger

Allowed Action values and Verification state values follow the current canonical vocabulary.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0003VD | The source method is `UserPane::OnTimer`, not `OnAnimationStep` | very strong | TimerHandler vtable cell, inherited contract, and default base delegation | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Current Source Disposition - 2026-07-30` | incorporate | applied |
| C002 | 0003VD | The rejected `OnAnimationStep` spelling is retained only as a corrected historical assumption | very strong | TimerHandler contract and current source-facing decision | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Historical / Superseded Assumptions - Pre-2026-07-30` | historicalize | applied |
| C003 | 0003VD | Machine ECX is the TimerHandler facet at complete UserPane offset `+0xa4`; source uses ordinary member access | very strong | secondary vtable cell and repeated lowered `this-0xa4` recovery | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Current Behavior And Data Flow` | incorporate | applied |
| C004 | 0003VD | Timer ID 20 is `kUserPaneMovementStep` | very strong | U7 and U8 scheduling plus target rescheduling | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Current Behavior And Data Flow` | incorporate | applied |
| C005 | 0003VD | FWdA performs the documented four-substep movement, MapPane scrolling, completion warp, viewport shift, and linked-object synchronization | very strong | full target decompile and current helper contracts | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Current Behavior And Data Flow` | incorporate | applied |
| C006 | 0003VD | FAnD and every unrecognized timer delegate to `LivingObjectPane::OnTimer` | very strong | target switch and base callback route | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Current Behavior And Data Flow` | incorporate | applied |
| C007 | 0003VD | Target behavior names inherited `m_moveFrame` at complete-object offset `+0x1c6` | very strong | signed frame loads, comparisons, and modulo behavior | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C008 | 0003VD | Target behavior names `m_movementTimerHandled` at complete-object offset `+0x20c` | strong | constructor clear and both target case stores | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C009 | 0003VD | Target behavior names `m_movementMode` at complete-object offset `+0x13eaf0` | strong | movement-state position and adjacent semantics | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C010 | 0003VD | Target behavior names `m_movementReplyCount` at complete-object offset `+0x13eaf1` | very strong | signed pre-decrement and reply-handler stores | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C011 | 0003VD | Target behavior names `m_movementReplyReceived` at complete-object offset `+0x13eaf2` | very strong | exact target gates and continuation stores | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C012 | 0003VD | Target behavior names `m_movementReplyPending` at complete-object offset `+0x13eaf3` | very strong | exact target and packet-handler reads and writes | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C013 | 0003VD | Target behavior names `m_directionDelayActive` at complete-object offset `+0x13eaf4` | very strong | exact backward-frame and suppression branches | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C014 | 0003VD | Target behavior names `m_movementReplyTimerFamily` at complete-object offset `+0x13eb1e` | very strong | target stores 0 or 1 and reply-handler selector use | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C015 | 0003VD | Target behavior names `m_movementHistoryEnabled` at complete-object offset `+0x13eb1f` | strong | constructor initialization and adjacent history layout | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Field Translation` | incorporate | applied |
| C016 | 0003VD | The target range is exactly `[0x005a83b0,0x005a87ad)`, 1,021 bytes, and one method | very strong | modeled function boundary and CFG | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Binary And Boundary Evidence` | incorporate | applied |
| C017 | 0003VD | Target bytes have SHA256 `0260F191AA50A541D89BE148F3414DF840E88BEFBA8DABE62AF6E87C85BE8263` | very strong | exact target-byte reread under saved IDB `B7CC899D...58277` | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Binary And Boundary Evidence` | incorporate | applied |
| C018 | 0003VD | Pre-target `[0x005a83a4,0x005a83b0)` is twelve `0xcc` alignment bytes | very strong | exact boundary reread under saved IDB `B7CC899D...58277` | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Binary And Boundary Evidence` | incorporate | applied |
| C019 | 0003VD | Post-target `[0x005a87ad,0x005a87b0)` is three `0xcc` alignment bytes before the separate successor | very strong | exact boundary and successor reread under saved IDB `B7CC899D...58277` | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Exact Binary And Boundary Evidence` | incorporate | applied |
| C020 | 0003VD | The sole inbound target route is data xref `0x0062efc4` | very strong | exact xref reread under saved IDB `B7CC899D...58277` | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Caller And Callee Evidence` | incorporate | applied |
| C021 | 0003VD | The target callee inventory is the exact function set recorded in this report | very strong | full target decompile history plus saved-IDB `B7CC899D...58277` function-identity/callee reread | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Caller And Callee Evidence` | incorporate | applied |
| C022 | 0003VD | Canonical owner remains UID0000FQ | very strong | UserPane vtable route, receiver fields, and current source ownership | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: metadata field `CANONICAL_OWNER` | already-present | already-present |
| C023 | 0003VD | Emitter route remains UID0000FQ | very strong | class-owned declaration and child-owned method body route | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: metadata field `EMITTER_UIDS` | already-present | already-present |
| C024 | 0003VD | Reconstructable remains true | very strong | complete source-authored virtual method behavior | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: metadata field `RECONSTRUCTABLE` | already-present | already-present |
| C025 | 0003VD | Completion becomes 94 | strong | complete behavior, ABI, range, source placement, and formal source | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: metadata field `COMPLETION` | incorporate | applied |
| C026 | 0003VD | Confidence becomes 94 | strong | direct binary evidence with only stripped lexical spellings remaining | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: metadata field `CONFIDENCE` | incorporate | applied |
| C027 | 0003VD | Item Summary becomes the exact source-ready summary supplied under Recommended Target Doc Changes | very strong | resolved target behavior and source disposition | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: metadata field `Item Summary` | incorporate | applied |
| C028 | 0003VD | Formal CPP becomes the complete `UserPane::OnTimer` body in this report | very strong | full control-flow and data-flow reconstruction | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C029 | 0003VD | Formal H remains blank because UID0000FQ owns the single class declaration | very strong | no-duplicate declaration rule and emitter route | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C030 | 0003VD | Score rationale records why lexical uncertainty caps the target below 95 and why complete behavior prevents a lower score | strong | resolved blockers and explicit remaining lexical uncertainty | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Score Rationale` | incorporate | applied |
| C031 | 0003VD | The former no-current-improvement disposition is retained only as corrected history | very strong | complete formal reconstruction supersedes the old no-code conclusion | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` :: `## Historical / Superseded Assumptions - Pre-2026-07-30` | historicalize | applied |
| C032 | 0000FQ | The class integration records timer ID 20 as the UserPane movement-step event handled by `OnTimer` | very strong | U7 and U8 schedulers plus target callback | `by-class/UserPane.md` :: `## UID0003VD OnTimer Source-Quality Integration - 2026-07-30` | incorporate | applied |
| C033 | 0000FQ | The class declaration is `virtual bool OnTimer(int timerId, int arg0, int arg1);` in the complete formal header payload | very strong | inherited TimerHandler contract and declaration/header channel rule | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C034 | 0000FQ | The method inventory names UID0003VD as the UserPane TimerHandler override | very strong | vtable cell and source ownership | `by-class/UserPane.md` :: `## UID0003VD OnTimer Source-Quality Integration - 2026-07-30` | incorporate | applied |
| C035 | 0000FQ | The class header formal declares `bool m_movementTimerHandled` at the accepted source position | strong | constructor clear, target stores, and size-neutral layout | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C036 | 0000FQ | The class header formal preserves the three-byte tail after `m_movementTimerHandled` | very strong | exact fixed offsets and next pointer boundary | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C037 | 0000FQ | The class header formal preserves `LineInputPane *m_activeLineInputPane` at complete-object `+0x210` | very strong | sole non-null writer stores typed LineInputPane constructor `this`; previous value is queued and all consumers clear it | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C038 | 000364 | Replace active `ClearPendingTargetObject()`/pending-ObjectPane prose with `ClearActiveLineInputPane()` and retain the former interpretation only as disproved history | very strong | exact `0x004f298f` zero store plus constructor read/queue/typed store and no ObjectPane store | `by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C039 | 0000FQ | The class header formal declares `unsigned char m_movementMode` | strong | movement-state array offset and adjacent source role | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C040 | 0000FQ | The class header formal declares `signed char m_movementReplyCount` | very strong | signed decrement and reply-handler stores | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C041 | 0000FQ | The class header formal declares `bool m_movementReplyReceived` | very strong | target gates and reply-handler stores | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C042 | 0000FQ | The class header formal declares `bool m_movementReplyPending` | very strong | target and packet-handler read/write behavior | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C043 | 0000FQ | The class header formal declares `bool m_directionDelayActive` | very strong | seven direct reads and clears plus exact branch behavior | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C044 | 0000FQ | The class header formal declares `unsigned char m_movementReplyTimerFamily` | very strong | target stores 0 or 1 and reply handlers select the timer family | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C045 | 0000FQ | The class header formal declares `bool m_movementHistoryEnabled` | strong | constructor initialization and adjacent history-state layout | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C046 | 0000FQ | The inline class-header helper is `ClearMovementReplyState` with the exact body supplied in this report | very strong | exact two-byte clear behavior | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C047 | 0000FQ | The inline class-header helper `SetMovementReplyState` uses the named reply fields | very strong | exact word store semantics | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C048 | 0000FQ | The inline class-header helper `IsDirectionDelayActive` returns the named direction-delay field | very strong | exact one-byte reads | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C049 | 0000FQ | The inline class-header helper `SetDirectionDelayActive` writes the named direction-delay field | very strong | exact one-byte stores | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C050 | 0000FQ | The class integration preserves `sizeof(UserPane)==0x13eb84` | very strong | exact IDA UDT size | `by-class/UserPane.md` :: `## UID0003VD OnTimer Source-Quality Integration - 2026-07-30` | incorporate | applied |
| C051 | 0000FQ | The active-line-input field refinement preserves the four-byte tail at `+0x214`, `m_groupMembers +0x218`, every later offset, and `sizeof(UserPane)==0x13eb84` | very strong | exact offset arithmetic, current class layout, and unchanged IDA neighbors | `by-class/UserPane.md` :: `## UID0003VD OnTimer Source-Quality Integration - 2026-07-30` | incorporate | applied |
| C052 | 0000FQ | The class integration documents the TimerHandler facet at UserPane offset `+0xa4` | very strong | secondary vtable route and callback lowering | `by-class/UserPane.md` :: `## UID0003VD OnTimer Source-Quality Integration - 2026-07-30` | incorporate | applied |
| C053 | 0000FQ | The stale `OnAnimationStep` class spelling is retained only as superseded history | very strong | current TimerHandler contract | `by-class/UserPane.md` :: `## Historical / Superseded Assumptions - Pre-2026-07-14` | historicalize | applied |
| C054 | 0000FQ | Class completion remains 94 | strong | target synchronization does not constitute a full independent class rescore | `by-class/UserPane.md` :: metadata field `COMPLETION` | already-present | already-present |
| C055 | 0000FQ | Class confidence remains 95 | strong | target synchronization does not alter the established class confidence | `by-class/UserPane.md` :: metadata field `CONFIDENCE` | already-present | already-present |
| C056 | 0000P1 | UserPane source remains `NexusTK/ui/panels/UserPane.cpp` | very strong | current owner route and source-family placement | `by-file/UserPane.md` :: `### Status` | already-present | already-present |
| C057 | 0000P1 | The file integration records UID0003VD as the UserPane TimerHandler override definition and retains `OnAnimationStep` only as superseded history | very strong | class/child emitter routes and inherited callback contract | `by-file/UserPane.md` :: `## UID0003VD OnTimer Source Integration - 2026-07-30` | incorporate | applied |
| C058 | 0000K7 | Replace the stale InputPanes summary that calls `+0x210` a pending ObjectPane target with the active LineInputPane lifecycle and retain the old wording only as disproved history | very strong | UID00035P typed store plus UID00035Y/000364/00036C clears | `by-file/InputPanes.md` :: `## UID000364 Canonical Event Handler Completion - 2026-07-20` | incorporate | applied |
| C059 | 0000P1 | File completion remains 93 | strong | source placement was already established | `by-file/UserPane.md` :: metadata field `COMPLETION` | already-present | already-present |
| C060 | 0000P1 | File confidence remains 94 | strong | target integration does not alter source-file identity | `by-file/UserPane.md` :: metadata field `CONFIDENCE` | already-present | already-present |
| C061 | 0002YU | Vtable cell `0x0062efc4` names `UserPane::OnTimer` | very strong | exact pointer to `0x005a83b0` | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` :: `## Summary` | incorporate | applied |
| C062 | 0002YU | The vtable evidence explains that `0x0062efc4` is the TimerHandler secondary-facet route | very strong | neighboring secondary vtable layout | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` :: `## IDA Evidence` | incorporate | applied |
| C063 | 0002YU | The vtable page remains nonreconstructable compiler data | very strong | compiler-emitted table disposition | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` :: metadata field `RECONSTRUCTABLE` | already-present | already-present |
| C064 | 0002YU | The vtable page formal CPP remains blank | very strong | compiler-data no-code disposition | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` :: `RECONSTRUCTION_CPP CODE` | already-present | already-present |
| C065 | 0002YU | The vtable page formal H remains blank | very strong | compiler-data no-code disposition | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` :: `RECONSTRUCTION_H CODE` | already-present | already-present |
| C066 | 0003Z7 | `ScheduleBoxRotationStep` is a void complete-object LivingObjectPane helper | very strong | F2 body and five callers | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C067 | 0003Z7 | F2 dated pretransaction IDA state was `sub_53BF40` with analyzer type `void __thiscall(TimerHandler *this)`; current ordinary state is `LivingObjectPane__ScheduleBoxRotationStep` with the accepted type and exact repeatable comment | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020356` current destination proof | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C068 | 0003Z7 | `SyncPositionToLinkedObjects` is a void LivingObjectPane helper | very strong | F3 body and two target callers | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C069 | 0003Z7 | F3 dated pretransaction IDA state was `sub_53C070` with analyzer return `int`; current ordinary state is void `LivingObjectPane__SyncPositionToLinkedObjects` with the accepted repeatable comment | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020356` current destination proof | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C070 | 0003Z7 | `UserPane::PropagateLinkedObjectMode` is the UserPane virtual thunk at `0x005a9240` | very strong | UserPane vtable cell and tail-forwarding body; accepted callback added the literal `UserPane::PropagateLinkedObjectMode(int mode)` spelling and validator `000000020142` preserved the section's range/vtable/tail evidence | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C071 | 0003Z7 | F8 dated pretransaction IDA state was `sub_5A9240` with analyzer type `_DWORD *__thiscall(int this, int)`; current ordinary state is void `UserPane__PropagateLinkedObjectMode` with accepted comment and materialized `mode@0x8:0x4:int` | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020356` current destination proof | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C072 | 0003Z7 | `LivingObjectPane::PropagateLinkedObjectMode` is the implementation at `0x0053c290` | very strong | F9 body and LivingObjectPane vtable cell | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C073 | 0003Z7 | F9 dated pretransaction IDA state was `sub_53C290` with analyzer pointer return; current ordinary state is void `LivingObjectPane__PropagateLinkedObjectMode` with accepted comment and physical `signed __int32 mode` | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020356` current destination proof | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C074 | 0003Z7 | UID0003VD calls the linked-position and mode helpers at the exact sites listed in this report | very strong | target decompile and xrefs | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C075 | 0003Z3 | `RemapMovementDirectionForMapScroll` is an unsigned-byte stdcall free helper | very strong | exact F6 mapping and call ABI | `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C076 | 0003Z3 | F6 dated pretransaction IDA state was `sub_53A6B0` with signed-char analyzer rendering; current ordinary state is unsigned-byte stdcall `RemapMovementDirectionForMapScroll` with accepted comment | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020357` current destination proof | `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C077 | 0003Z3 | UID0003VD uses the remap helper in the exact direction-delay and MapPane branches | very strong | target call sites | `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C078 | 0002R1 | The source-facing callback spelling is `LivingObjectPane::OnTimer` | very strong | TimerHandler contract and vtable route | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C079 | 0002R1 | The older `HandleTimerMessage` spelling is retained only as corrected history | very strong | current callback contract | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` :: `## Changes` | historicalize | applied |
| C080 | 0002R1 | UID0003VD delegates FAnD and default timer IDs to the base callback | very strong | target switch call sites | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C081 | 0002R1 | F7 dated pretransaction IDA state used the final analyzer home `unsigned int delayMs`; current ordinary physical readback is `signed __int32 arg1` while source-facing `int arg1` remains unchanged | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020358` current destination proof | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C082 | 000427 | UID0003VD calls `ApplyMovementSubstepScroll` in the exact progressive and completion branches | very strong | target call sites | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` :: `## UID0003VD OnTimer Caller Synchronization - 2026-07-30` | incorporate | applied |
| C083 | 000427 | F4 dated pretransaction IDA state was `sub_5055E0` with analyzer byte return; current ordinary state is `MapPane__ApplyMovementSubstepScroll` with the accepted bool type and exact repeatable comment | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020359` current destination proof | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` :: `## UID0003VD OnTimer Caller Synchronization - 2026-07-30` | incorporate | applied |
| C084 | 000427 | The existing formal `bool ApplyMovementSubstepScroll(unsigned char direction)` body remains unchanged | very strong | current body and return semantics | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` :: `RECONSTRUCTION_CPP CODE` | already-present | already-present |
| C085 | 0002QL | The source helper is `void MapPane::ScrollViewportByDirection(unsigned char direction)` | very strong | F5 body and sole target caller | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` :: `## Behavior` | incorporate | applied |
| C086 | 0002QL | UID0003VD is the sole caller at `0x005a8597` | very strong | live xref | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` :: `## Caller Evidence` | incorporate | applied |
| C087 | 0002QL | F5 dated pretransaction IDA state was `sub_5058B0`; current ordinary state is void `MapPane__ScrollViewportByDirection` with the accepted unsigned-byte direction type and exact repeatable comment | very strong | dated `3892BDA8...472798D1` discovery, B180 matched prestate, CF18895C/B7 applied readback, and Gate2A repair command `000000020360` current destination proof | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` :: `## Live IDA Evidence` | incorporate | applied |
| C088 | 0002QL | Formal CPP uses `DirectionToTileOffset(&tileDelta, scrollDirection)` | very strong | canonical helper signature and call ABI | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C089 | 0002QL | The reversed `DirectionToTileOffset(scrollDirection, &tileDelta)` call is rejected as invalid history | very strong | canonical helper signature and call ABI | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` :: `## Changes` | reject-invalid | applied |
| C090 | 0003U7 | InitializeWalkAnimation formal CPP calls `ClearMovementReplyState` | very strong | exact two-byte clear and accepted helper rename | `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C091 | 0003U7 | InitializeWalkAnimation formal CPP uses the accepted named movement fields | very strong | exact field stores and fixed offsets | `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C092 | 0003U7 | The old `ClearMovementHistoryToken` spelling is retained only as superseded U7 history | very strong | accepted reply-state helper semantics | `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md` :: `## Historical / Superseded Assumptions - Pre-2026-07-14` | historicalize | applied |
| C093 | 0003U7 | InitializeWalkAnimation schedules the timer family continued by UID0003VD | very strong | exact scheduler arguments and target continuation | `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C094 | 0003U8 | StartDirectionalAnimation formal CPP uses the accepted named movement fields | very strong | exact field stores and fixed offsets | `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C095 | 0003U8 | StartDirectionalAnimation formal CPP calls `ClearMovementReplyState` | very strong | exact two-byte clear and accepted helper rename | `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C096 | 0003U8 | The old `ClearMovementHistoryToken` spelling is retained only as superseded U8 history | very strong | accepted reply-state helper semantics | `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` :: `## Historical / Superseded Assumptions - Pre-2026-07-14` | historicalize | applied |
| C097 | 0003U8 | StartDirectionalAnimation schedules local event 20 continued by UID0003VD | very strong | exact scheduler arguments and target continuation | `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C098 | 0003UE | WarpToPosition formal CPP uses named reply and direction-delay fields | very strong | exact direct clears | `by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C099 | 0003UE | WarpToPosition is the coordinate helper used by both UID0003VD movement families | very strong | target call sites and exact signature | `by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md` :: `## UID0003VD OnTimer Dependency Synchronization - 2026-07-30` | incorporate | applied |
| C100 | 0003UP | Movement reply packet formal CPP replaces movement-state array indexing with named fields | very strong | exact packet branches and stores | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C101 | 0003UP | Movement reply packet continuation consumes the state produced by UID0003VD | very strong | selector, pending, received, and count behavior | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` :: `## UID0003VD OnTimer State Synchronization - 2026-07-30` | incorporate | applied |
| C102 | 0003UQ | Extended movement reply formal CPP replaces movement-state array indexing with named fields | very strong | exact packet branches and stores | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C103 | 0003UQ | Extended movement reply continuation consumes the state produced by UID0003VD | very strong | selector, pending, received, and count behavior | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` :: `## UID0003VD OnTimer State Synchronization - 2026-07-30` | incorporate | applied |
| C104 | 00027F | `g_movementSubstepScale` is one signed-consumed source-facing plain `char`; `unsigned char` is rejected | very strong | exact one-byte storage and all 23 consumers use sign-extending `movsx`; explicit `signed char` is behavior-equivalent but plain `char` best matches project source style | `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` :: `## Layout` and `## Reconstruction Notes` | already-present | already-present |
| C105 | 00027F | The scale remains the divisor and four-substep multiplier used by UID0003VD | very strong | target and starter arithmetic | `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` :: `## Reconstruction Notes` | already-present | already-present |
| C106 | 0003VD | Insert the exact UID0003VD manual coverage row supplied in this report | very strong | supervisor applied the literal row; bounded `DDB43AB5...EAFAE2` reread is exact at line 3820 | `by-memory/-coverage-report.md` :: literal UID0003VD row immediately after UID0003VB | incorporate | applied |
| C107 | 0003VD | Generated `UserPane.cpp` contains exactly one UID0003VD `UserPane::OnTimer` definition after refresh | very strong | dated command20172 exact physical proof: `UserPane.cpp` SHA256 `C0F90A56764C9F6EB5B0698B2C642E6812EC5C26B137D9CA271D20B7FED1A3E0` contains exactly one UID0003VD `OnTimer` definition, corroborated by generated-memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; command20109 and command20104 are dated corroborating history | `auto-generated/NexusTK/ui/panels/UserPane.cpp` :: exact one-definition assertion | incorporate | already-present |
| C108 | 0003VD | Generated `UserPane.cpp` contains no `OnAnimationStep` spelling after refresh | very strong | dated command20172 exact physical zero-match proof in `UserPane.cpp` SHA256 `C0F90A56764C9F6EB5B0698B2C642E6812EC5C26B137D9CA271D20B7FED1A3E0`, corroborated by generated-memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; command20109 and command20104 are dated corroborating history | `auto-generated/NexusTK/ui/panels/UserPane.cpp` :: exact no-`OnAnimationStep` assertion | incorporate | already-present |
| C109 | 0003VD | Generated `UserPane.cpp` contains no UID0003VD no-code or empty-emitter marker after refresh | very strong | dated command20172 exact physical proof: the UID0003VD block in `UserPane.cpp` SHA256 `C0F90A56764C9F6EB5B0698B2C642E6812EC5C26B137D9CA271D20B7FED1A3E0` is the formal definition, not a no-code/empty marker, corroborated by generated-memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; command20109 and command20104 are dated corroborating history | `auto-generated/NexusTK/ui/panels/UserPane.cpp` :: exact no-target-marker assertion | incorporate | already-present |
| C110 | 0000FQ | Generated `UserPane.h` contains the complete UserPane header payload and exactly one `OnTimer` declaration after refresh | very strong | dated command20172 exact physical proof: `UserPane.h` SHA256 `A98F4CCD8FDA2C102125D4743AC5202DBAC06519EE48E2584A594A4860492117` contains the complete class and exactly one `OnTimer` declaration, corroborated by generated-memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; command20109 and command20104 are dated corroborating history | `auto-generated/NexusTK/ui/panels/UserPane.h` :: exact complete-header/one-declaration assertion | incorporate | already-present |
| C111 | 0000FQ | Generated `UserPane.h` contains no `OnAnimationStep` declaration | very strong | dated command20172 exact physical zero-match proof in `UserPane.h` SHA256 `A98F4CCD8FDA2C102125D4743AC5202DBAC06519EE48E2584A594A4860492117`, corroborated by generated-memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; command20109 and command20104 are dated corroborating history | `auto-generated/NexusTK/ui/panels/UserPane.h` :: exact no-`OnAnimationStep` assertion | incorporate | already-present |
| C112 | 0003VD | Shared-IDB evidence is lifecycle-neutral: `B180F0E4...F2A07` is the dated supervisor transaction prestate, `CF18895C...2C7F96` is the dated saved poststate, `4B5F...A696A`, `1BC3...0CFD`, and `5F2679A7...79A21` are dated later saves, and `B7CC899D...58277` is the exact saved checkpoint used for this report's fresh bounded reread | very strong | supervisor transaction history plus fresh saved-IDB `B7CC899D...58277` target/protected readback preserve every target/protected invariant | this report :: `## Supervisor Active Recheck` | incorporate | applied |
| C113 | 0003VD | Saved IDBs `B180F0E4...F2A07`, `CF18895C...2C7F96`, `4B5F...A696A`, `1BC3...0CFD`, `5F2679A7...79A21`, F7, A0, 4A, DAA, D7D2, 3892, and all earlier identities are dated bounded checkpoints rather than durable future truth | very strong | lifecycle-neutral shared-state rule, exact backup/save history, and fresh `B7CC899D...58277` reread | this report :: `## Supporting Research` | historicalize | applied |
| C114 | 0003Z7 | F2's dated prestate rendered `void __thiscall(TimerHandler *this)`; saved-IDB `B7CC899D...58277` readback is `void __thiscall LivingObjectPane__ScheduleBoxRotationStep(LivingObjectPane *this)` | very strong | B180/CF18895C dated transaction history plus fresh `B7CC899D...58277` readback | this report :: heading text "### IDA-F2 0x0053bf40" | incorporate | applied |
| C115 | 0002R1 | F7's dated prestate rendered `unsigned int delayMs`; saved-IDB `B7CC899D...58277` physical readback has `signed __int32 arg1`, `int arg0`, and source-facing prototype `int arg0, int arg1` | very strong | B180/CF18895C dated transaction history plus fresh `B7CC899D...58277` readback | this report :: heading text "### IDA-F7 0x0053b830" | incorporate | applied |
| C116 | 0003VD | Rename F1 to `UserPane__OnTimer` | very strong | literal prestate/collision and exact applied readback | IDA function `0x005a83b0` :: name row | incorporate | applied |
| C117 | 0003VD | Type F1 as `bool __thiscall UserPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)` | very strong | secondary-facet callback contract and exact applied readback | IDA function `0x005a83b0` :: function type row | incorporate | applied |
| C118 | 0003VD | Type F1 local `[ebp-8]` as `MapPoint offset` | very strong | applied physical row renders `struct MapPoint` while the source-facing prototype/local spelling remains `MapPoint` | IDA function `0x005a83b0` :: local row `[ebp-8]` | incorporate | applied |
| C119 | 0003VD | Rename the first F1 stack home to `timerId` | very strong | applied physical row is `signed __int32 timerId` at frame offset `0x1c` | IDA function `0x005a83b0` :: stack row `arg_0` at frame offset `0x1c` | incorporate | applied |
| C120 | 0003VD | Preserve the second F1 stack home name `arg0` | very strong | callback contract and exact frame | IDA function `0x005a83b0` :: stack row `arg0` at frame offset `0x20` | already-present | already-present |
| C121 | 0003VD | Rename the third F1 stack home to `arg1` | very strong | applied physical row is `signed __int32 arg1` at frame offset `0x24` | IDA function `0x005a83b0` :: stack row `arg_8` at frame offset `0x24` | incorporate | applied |
| C122 | 0003VD | Set the exact F1 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved target invariants | IDA function `0x005a83b0` :: function-repeatable comment row | incorporate | applied |
| C123 | 0003Z7 | Rename F2 to `LivingObjectPane__ScheduleBoxRotationStep` | very strong | literal prestate/collision and exact applied readback | IDA function `0x0053bf40` :: name row | incorporate | applied |
| C124 | 0003Z7 | Type F2 as `void __thiscall LivingObjectPane__ScheduleBoxRotationStep(LivingObjectPane *this)` | very strong | complete-object ECX and exact applied readback | IDA function `0x0053bf40` :: function type row | incorporate | applied |
| C125 | 0003Z7 | Set the exact F2 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved timer behavior | IDA function `0x0053bf40` :: function-repeatable comment row | incorporate | applied |
| C126 | 0003Z7 | Rename F3 to `LivingObjectPane__SyncPositionToLinkedObjects` | very strong | literal prestate/collision and exact applied readback | IDA function `0x0053c070` :: name row | incorporate | applied |
| C127 | 0003Z7 | Type F3 as `void __thiscall LivingObjectPane__SyncPositionToLinkedObjects(LivingObjectPane *this)` | very strong | side-effect-only body and exact applied readback | IDA function `0x0053c070` :: function type row | incorporate | applied |
| C128 | 0003Z7 | Set the exact F3 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved synchronization behavior | IDA function `0x0053c070` :: function-repeatable comment row | incorporate | applied |
| C129 | 000427 | Rename F4 to `MapPane__ApplyMovementSubstepScroll` | very strong | literal prestate/collision and exact applied readback | IDA function `0x005055e0` :: name row | incorporate | applied |
| C130 | 000427 | Type F4 as `bool __thiscall MapPane__ApplyMovementSubstepScroll(MapPane *this, unsigned __int8 direction)` | very strong | exact return/receiver behavior and applied readback | IDA function `0x005055e0` :: function type row | incorporate | applied |
| C131 | 000427 | Set the exact F4 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved substep behavior | IDA function `0x005055e0` :: function-repeatable comment row | incorporate | applied |
| C132 | 0002QL | Rename F5 to `MapPane__ScrollViewportByDirection` | very strong | literal prestate/collision and exact applied readback | IDA function `0x005058b0` :: name row | incorporate | applied |
| C133 | 0002QL | Type F5 as `void __thiscall MapPane__ScrollViewportByDirection(MapPane *this, unsigned __int8 direction)` | very strong | exact receiver/parameter behavior and applied readback | IDA function `0x005058b0` :: function type row | incorporate | applied |
| C134 | 0002QL | Rename the F5 stack argument to `direction` | very strong | exact applied frame row | IDA function `0x005058b0` :: stack argument row `arg_0` | incorporate | applied |
| C135 | 0002QL | Set the exact F5 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved refresh behavior | IDA function `0x005058b0` :: function-repeatable comment row | incorporate | applied |
| C136 | 0003Z3 | Rename F6 to `RemapMovementDirectionForMapScroll` | very strong | literal prestate/collision and exact applied readback | IDA function `0x0053a6b0` :: name row | incorporate | applied |
| C137 | 0003Z3 | Type F6 as `unsigned __int8 __stdcall RemapMovementDirectionForMapScroll(unsigned __int8 direction)` | very strong | exact mapping/byte ABI and applied readback | IDA function `0x0053a6b0` :: function type row | incorporate | applied |
| C138 | 0003Z3 | Rename the F6 stack argument to `direction` | very strong | exact applied frame row | IDA function `0x0053a6b0` :: stack argument row `arg_0` | incorporate | applied |
| C139 | 0003Z3 | Set the exact F6 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved mapping | IDA function `0x0053a6b0` :: function-repeatable comment row | incorporate | applied |
| C140 | 0002R1 | Rename F7 to `LivingObjectPane__OnTimer` | very strong | literal prestate/collision and exact applied readback | IDA function `0x0053b830` :: name row | incorporate | applied |
| C141 | 0002R1 | Type F7 as `bool __thiscall LivingObjectPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)` | very strong | secondary-facet contract and exact applied readback | IDA function `0x0053b830` :: function type row | incorporate | applied |
| C142 | 0002R1 | Normalize the F7 third stack home from `delayMs` to int `arg1` | very strong | applied physical row canonically renders `signed __int32 arg1` | IDA function `0x0053b830` :: stack row `delayMs` | incorporate | applied |
| C143 | 0002R1 | Set the exact F7 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved timer-family behavior | IDA function `0x0053b830` :: function-repeatable comment row | incorporate | applied |
| C144 | 0003Z7 | Rename F8 to `UserPane__PropagateLinkedObjectMode` | very strong | literal prestate/collision and exact applied readback | IDA function `0x005a9240` :: name row | incorporate | applied |
| C145 | 0003Z7 | Type F8 as `void __thiscall UserPane__PropagateLinkedObjectMode(UserPane *this, int mode)` | very strong | exact applied prototype materialized physical `mode @ 0x08 / 0x4 : int`; deletion correctly reported an argument member | IDA function `0x005a9240` :: function type row | incorporate | applied |
| C146 | 0003Z7 | Set the exact F8 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved thunk invariants | IDA function `0x005a9240` :: function-repeatable comment row | incorporate | applied |
| C147 | 0003Z7 | Rename F9 to `LivingObjectPane__PropagateLinkedObjectMode` | very strong | literal prestate/collision and exact applied readback | IDA function `0x0053c290` :: name row | incorporate | applied |
| C148 | 0003Z7 | Type F9 as `void __thiscall LivingObjectPane__PropagateLinkedObjectMode(LivingObjectPane *this, int mode)` | very strong | side-effect-only body and exact applied readback | IDA function `0x0053c290` :: function type row | incorporate | applied |
| C149 | 0003Z7 | Set the exact F9 function-repeatable comment supplied in the IDA handoff | very strong | exact applied comment and preserved propagation behavior | IDA function `0x0053c290` :: function-repeatable comment row | incorporate | applied |
| C150 | 0003U7 | Replace only C1's function-regular comment with the exact `ClearMovementReplyState` wording | very strong | exact applied comment; all other identity/frame/comment channels preserved | IDA function `0x005a36f0` :: function-regular comment row | incorporate | applied |
| C151 | 0000FQ | Create `signed __int8 m_moveFrame` at `+0x1c6` | very strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x1c6` | incorporate | applied |
| C152 | 0000FQ | Create opaque size `0x45` storage at `+0x1c7` | very strong | exact applied gap boundary | IDA UDT `UserPane` :: member row `+0x1c7` | incorporate | applied |
| C153 | 0000FQ | Create `bool m_movementTimerHandled` at `+0x20c` | strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x20c` | incorporate | applied |
| C154 | 0000FQ | Create three-byte opaque tail at `+0x20d` | very strong | exact applied boundary before `+0x210` | IDA UDT `UserPane` :: member row `+0x20d` | incorporate | applied |
| C155 | 0000FQ | Preserve `LineInputPane *m_activeLineInputPane` at `+0x210` through the applied size-neutral T1 splits | very strong | applied readback shows the exact typed member preserved; typed constructor read/store, eighteen exact zero stores, complete `LineInputPane` UDT size `0x108`, and no ObjectPane store support it; A0 incomplete ordinal-803 state is dated history | IDA UDT `UserPane` :: member row `+0x210` | already-present | already-present |
| C156 | 0000FQ | Preserve four-byte opaque tail `_userPaneAfterActiveLineInput` at `+0x214` through the applied T1 splits | very strong | applied readback preserves the exact boundary row before `m_groupMembers +0x218`; A0 is dated history | IDA UDT `UserPane` :: member row `+0x214` | already-present | already-present |
| C157 | 0000FQ | Create `unsigned __int8 m_movementMode` at `+0x13eaf0` | strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x13eaf0` | incorporate | applied |
| C158 | 0000FQ | Create `signed __int8 m_movementReplyCount` at `+0x13eaf1` | very strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x13eaf1` | incorporate | applied |
| C159 | 0000FQ | Create `bool m_movementReplyReceived` at `+0x13eaf2` | very strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x13eaf2` | incorporate | applied |
| C160 | 0000FQ | Create `bool m_movementReplyPending` at `+0x13eaf3` | very strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x13eaf3` | incorporate | applied |
| C161 | 0000FQ | Create `bool m_directionDelayActive` at `+0x13eaf4` | very strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x13eaf4` | incorporate | applied |
| C162 | 0000FQ | Create `unsigned __int8 m_movementReplyTimerFamily` at `+0x13eb1e` | very strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x13eb1e` | incorporate | applied |
| C163 | 0000FQ | Create `bool m_movementHistoryEnabled` at `+0x13eb1f` | strong | exact applied T1 readback | IDA UDT `UserPane` :: member row `+0x13eb1f` | incorporate | applied |
| C164 | 0000FQ | Preserve UserPane size `0x13eb84` | very strong | applied size-neutral replacement and exact readback | IDA UDT `UserPane` :: type size row | incorporate | applied |
| C165 | 0000FQ | UserPane member count becomes 68 | very strong | exact applied T1 readback; C155-C156 remained already present | IDA UDT `UserPane` :: member-count row | incorporate | applied |
| C166 | 0003VD | Preserve function name `TimerMgr_ScheduleTimer` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: name row | already-present | already-present |
| C167 | 0003VD | Preserve the exact saved-IDB `B7CC899D...58277` TimerMgr_ScheduleTimer function type | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: function type row | already-present | already-present |
| C168 | 0003VD | Preserve absent TimerMgr_ScheduleTimer address-regular comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: address-regular comment row | already-present | already-present |
| C169 | 0003VD | Preserve absent TimerMgr_ScheduleTimer address-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: address-repeatable comment row | already-present | already-present |
| C170 | 0003VD | Preserve absent TimerMgr_ScheduleTimer function-regular comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: function-regular comment row | already-present | already-present |
| C171 | 0003VD | Preserve absent TimerMgr_ScheduleTimer function-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: function-repeatable comment row | already-present | already-present |
| C172 | 0003VD | Preserve the saved-IDB `B7CC899D...58277` TimerMgr_ScheduleTimer frame | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: frame row | already-present | already-present |
| C173 | 0003VD | Preserve TimerMgr_ScheduleTimer bytes SHA `9A8CF9EB...C5B4` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: byte-hash row | already-present | already-present |
| C174 | 0003VD | Preserve all 48 TimerMgr_ScheduleTimer callers | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x00597910` :: xref row | already-present | already-present |
| C175 | 0003UE | Preserve function name `UserPane_WarpToPosition` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: name row | already-present | already-present |
| C176 | 0003UE | Preserve the exact saved-IDB `B7CC899D...58277` UserPane_WarpToPosition function type | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: function type row | already-present | already-present |
| C177 | 0003UE | Preserve absent UserPane_WarpToPosition address-regular comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: address-regular comment row | already-present | already-present |
| C178 | 0003UE | Preserve absent UserPane_WarpToPosition address-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: address-repeatable comment row | already-present | already-present |
| C179 | 0003UE | Preserve absent UserPane_WarpToPosition function-regular comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: function-regular comment row | already-present | already-present |
| C180 | 0003UE | Preserve absent UserPane_WarpToPosition function-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: function-repeatable comment row | already-present | already-present |
| C181 | 0003UE | Preserve the saved-IDB `B7CC899D...58277` UserPane_WarpToPosition frame | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: frame row | already-present | already-present |
| C182 | 0003UE | Preserve UserPane_WarpToPosition bytes SHA `320D4AD5...C75E` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: byte-hash row | already-present | already-present |
| C183 | 0003UE | Preserve all 12 UserPane_WarpToPosition callers | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a5a90` :: xref row | already-present | already-present |
| C184 | 0003U7 | Preserve function name `UserPane_InitializeWalkAnimation` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: name row | already-present | already-present |
| C185 | 0003U7 | Preserve the exact saved-IDB `B7CC899D...58277` UserPane_InitializeWalkAnimation function type | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: function type row | already-present | already-present |
| C186 | 0003U7 | Preserve absent UserPane_InitializeWalkAnimation address-regular comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: address-regular comment row | already-present | already-present |
| C187 | 0003U7 | Preserve absent UserPane_InitializeWalkAnimation address-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: address-repeatable comment row | already-present | already-present |
| C188 | 0003U7 | Preserve absent UserPane_InitializeWalkAnimation function-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: function-repeatable comment row | already-present | already-present |
| C189 | 0003U7 | Preserve the saved-IDB `B7CC899D...58277` UserPane_InitializeWalkAnimation frame | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: frame row | already-present | already-present |
| C190 | 0003U7 | Preserve UserPane_InitializeWalkAnimation bytes SHA `986286D5...C158` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: byte-hash row | already-present | already-present |
| C191 | 0003U7 | Preserve all four UserPane_InitializeWalkAnimation callers | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a36f0` :: xref row | already-present | already-present |
| C192 | 0003U8 | Preserve function name `UserPane_StartDirectionalAnimation` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: name row | already-present | already-present |
| C193 | 0003U8 | Preserve the exact saved-IDB `B7CC899D...58277` UserPane_StartDirectionalAnimation function type | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: function type row | already-present | already-present |
| C194 | 0003U8 | Preserve absent UserPane_StartDirectionalAnimation address-regular comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: address-regular comment row | already-present | already-present |
| C195 | 0003U8 | Preserve absent UserPane_StartDirectionalAnimation address-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: address-repeatable comment row | already-present | already-present |
| C196 | 0003U8 | Preserve the exact saved-IDB `B7CC899D...58277` UserPane_StartDirectionalAnimation function-regular comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: function-regular comment row | already-present | already-present |
| C197 | 0003U8 | Preserve absent UserPane_StartDirectionalAnimation function-repeatable comment | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: function-repeatable comment row | already-present | already-present |
| C198 | 0003U8 | Preserve the saved-IDB `B7CC899D...58277` UserPane_StartDirectionalAnimation frame | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: frame row | already-present | already-present |
| C199 | 0003U8 | Preserve UserPane_StartDirectionalAnimation bytes SHA `5ECA3299...010D` | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: byte-hash row | already-present | already-present |
| C200 | 0003U8 | Preserve both UserPane_StartDirectionalAnimation callers | very strong | saved-IDB `B7CC899D...58277` protected-dependency readback | IDA function `0x005a3770` :: xref row | already-present | already-present |
| C201 | 0003VD | Preserve TimerHandler size 4 | very strong | saved-IDB `B7CC899D...58277` UDT readback | IDA UDT `TimerHandler` :: type size row | already-present | already-present |
| C202 | 0003VD | Preserve TimerHandler's sole vftable member | very strong | saved-IDB `B7CC899D...58277` UDT readback | IDA UDT `TimerHandler` :: member row `+0x0` | already-present | already-present |
| C203 | 0003VD | Preserve MapPane size `0x910` | very strong | saved-IDB `B7CC899D...58277` UDT readback | IDA UDT `MapPane` :: type size row | already-present | already-present |
| C204 | 0003VD | Preserve MapPane member count 69 | very strong | saved-IDB `B7CC899D...58277` UDT readback | IDA UDT `MapPane` :: member-count row | already-present | already-present |
| C205 | 0003VD | Preserve `bool m_queuedMapStateRefresh` at MapPane `+0x39d` | very strong | saved-IDB `B7CC899D...58277` UDT readback | IDA UDT `MapPane` :: member row `+0x39d` | already-present | already-present |
| C206 | 0003VD | Preserve `unsigned __int8 m_pendingActionPoll` at MapPane `+0x39e` | very strong | saved-IDB `B7CC899D...58277` UDT readback | IDA UDT `MapPane` :: member row `+0x39e` | already-present | already-present |
| C207 | 0000FQ | Replace the manual by-class UserPane row with the literal corrected active-LineInputPane and UID0003VD `OnTimer`/formal-H integration row | very strong | exact applied row at line 589 under bounded `34287BEF...7E2C1`; coverage validator `000000020167` is dated application proof | `by-class/-coverage-report.md` :: literal UID0000FQ row | incorporate | applied |
| C208 | 0000P1 | Replace the manual by-file UserPane row with the literal corrected active-LineInputPane and UID0003VD `OnTimer`/UserPane.h integration row | very strong | exact applied row at line 299 under bounded `F203FD4C...0210B`; coverage validator `000000020168` is dated application proof | `by-file/-coverage-report.md` :: literal UID0000P1 row | incorporate | applied |
| C209 | 0003Z7 | Replace the stale manual row with `91%`, very-strong confidence, and resolved linked-helper/UID0003VD call semantics | very strong | exact applied row at line 2801 under bounded `DDB43AB5...EAFAE2` | `by-memory/-coverage-report.md` :: literal UID0003Z7 row | incorporate | applied |
| C210 | 000427 | Insert the missing manual row immediately before UID0002QL | very strong | exact applied row at line 2363 precedes UID0002QL at line 2364 under bounded `DDB43AB5...EAFAE2` | `by-memory/-coverage-report.md` :: literal UID000427 row before UID0002QL | incorporate | applied |
| C211 | 0003U7 | Replace stale movement-token wording with exact movement-reply/direction-delay and UID0003VD continuation wording | very strong | exact applied row at line 3804 under bounded `DDB43AB5...EAFAE2` | `by-memory/-coverage-report.md` :: literal UID0003U7 row | incorporate | applied |
| C212 | 0003UP | Replace raw pending-reply index/event-family wording with the accepted named reply fields | very strong | exact applied row at line 3840 under bounded `DDB43AB5...EAFAE2` | `by-memory/-coverage-report.md` :: literal UID0003UP row | incorporate | applied |
| C213 | 0003UQ | Replace raw pending-reply index/event-family wording with the accepted named reply fields | very strong | exact applied row at line 3841 under bounded `DDB43AB5...EAFAE2` | `by-memory/-coverage-report.md` :: literal UID0003UQ row | incorporate | applied |
| C214 | 0002YU | Replace the generic vtable description with exact TimerHandler `OnTimer` slot `0x0062efc4` and adjusted-facet source disposition | very strong | exact applied row at line 4454 under bounded `DDB43AB5...EAFAE2`; coverage validator `000000020166` is dated application proof | `by-memory/-coverage-report.md` :: literal UID0002YU row | incorporate | applied |
| C215 | 0003Z3 | Keep the exact manual row unchanged | very strong | bounded `DDB43AB5...EAFAE2` line 2782 states exact direction-remap behavior and no score/description field is stale | `by-memory/-coverage-report.md` :: literal UID0003Z3 row | already-present | already-present |
| C216 | 0002R1 | Keep the exact manual row unchanged | very strong | bounded `DDB43AB5...EAFAE2` line 2795 names inherited `OnTimer`, adjusted TimerHandler ABI, movement behavior, callers, and declaration integration | `by-memory/-coverage-report.md` :: literal UID0002R1 row | already-present | already-present |
| C217 | 0002QL | Keep the exact manual row unchanged | very strong | bounded `DDB43AB5...EAFAE2` line 2364 describes the source-ready method, remap, MapPoint semantics, and complete body without stale argument order | `by-memory/-coverage-report.md` :: literal UID0002QL row | already-present | already-present |
| C218 | 0003U8 | Keep the exact manual row unchanged | very strong | bounded `DDB43AB5...EAFAE2` line 3806 describes event 20 and exact directional-animation behavior without superseded helper spelling | `by-memory/-coverage-report.md` :: literal UID0003U8 row | already-present | already-present |
| C219 | 0003UE | Keep the exact manual row unchanged | very strong | bounded `DDB43AB5...EAFAE2` line 3816 retains correct complete warp behavior and contains no stale array/helper spelling | `by-memory/-coverage-report.md` :: literal UID0003UE row | already-present | already-present |
| C220 | 00027F | Keep the exact manual row unchanged | very strong | bounded `DDB43AB5...EAFAE2` line 4501 retains exact signed scale type, value, uses, route, and formal disposition | `by-memory/-coverage-report.md` :: literal UID00027F row | already-present | already-present |
| C221 | 0000FQ | Generated `UserPane.cpp` contains no duplicate complete UserPane class definition after the class formal moves to H; one harmless forward declaration may remain | very strong | dated command20172 exact physical proof: `UserPane.cpp` SHA256 `C0F90A56764C9F6EB5B0698B2C642E6812EC5C26B137D9CA271D20B7FED1A3E0` has no duplicate complete UserPane class body and preserves the legitimate CPP ownership topology, corroborated by generated-memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; command20109 and command20104 are dated corroborating history | `auto-generated/NexusTK/ui/panels/UserPane.cpp` :: exact no-duplicate-full-class assertion | incorporate | already-present |
| C222 | 0000FQ | Replace the complete current by-class H formal with the exact full declaration payload below, including the corrected active LineInputPane slot, all preserved UID000415 additions, and `[[CHILDREN]]` | very strong | formal declaration/header placement rule, typed sole non-null writer, and current complete class union | `by-class/UserPane.md` :: `RECONSTRUCTION_H CODE` | incorporate | applied |
| C223 | 0000FQ | Leave the by-class CPP formal exactly blank because the class owner contributes declarations/header source while exact child pages own out-of-class definitions | very strong | formal CPP/H placement and child emitter ownership | `by-class/UserPane.md` :: `RECONSTRUCTION_CPP CODE` | incorporate | applied |

## Positive Evidence Summary

- Exact vtable identity establishes both liveness and the secondary-base callback contract.
- Full decompilation resolves every switch branch, return, timer argument, movement store, coordinate update, map scroll, continuation path, and base delegation.
- Existing movement starter and reply handlers cross-confirm timer 20, FWdA, reply-pending byte, reply-received byte, selector byte, and continuation count.
- Existing MapPane and LivingObjectPane formal bodies resolve all eight assignment-named helper signatures.
- Exact boundary bytes prove one source method and separate successor.
- Existing UserPane class/file routes are already above gate and need no ownership invention.
- The sole non-null `UserPane+0x210` writer is the typed [UID:00035P] LineInputPane constructor; all eighteen other writes initialize or clear that pointer. Current [UID:0000FQ]/[UID:0000P1] docs independently converge on `m_activeLineInputPane`.

## IDA MCP Facts

The table below is the fresh bounded readback from MCP session `f608d7c2` while the physical saved IDB matched SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`. The `5F2679A7...79A21`, CF18895C, 4B5F, 1BC3, and earlier identities are dated history.

| Entity | Saved-IDB `B7CC899D...58277` exact name/type readback | Size/hash | Xrefs and role |
| --- | --- | --- | --- |
| `0x005a83b0` | `UserPane__OnTimer`, `bool __thiscall UserPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)` | `0x3fd`, SHA `0260F191...8263` | only `0x62efc4` data ref; UserPane TimerHandler override |
| `0x0053bf40` | `LivingObjectPane__ScheduleBoxRotationStep`, `void __thiscall LivingObjectPane__ScheduleBoxRotationStep(LivingObjectPane *this)` | `0x37`, SHA `B1837582...72AF` | five callers; complete LivingObjectPane source receiver |
| `0x0053c070` | `LivingObjectPane__SyncPositionToLinkedObjects`, `void __thiscall LivingObjectPane__SyncPositionToLinkedObjects(LivingObjectPane *this)` | `0x159`, SHA `7685E739...BB34` | only target calls `0x5a859e/0x5a876a`; side-effect-only source method |
| `0x00597910` | `TimerMgr_ScheduleTimer`, exact typed six-argument thiscall | `0xfc`, SHA `9A8CF9EB...C5B4` | 48 callers; protected no-change dependency |
| `0x005a5a90` | `UserPane_WarpToPosition`, exact bool signature | `0xe9`, SHA `320D4AD5...C75E` | 12 callers; protected no-change dependency |
| `0x005a36f0` | `UserPane_InitializeWalkAnimation`, exact unsigned-byte direction | `0x76`, SHA `986286D5...C158` | four callers; existing function comment |
| `0x005a3770` | `UserPane_StartDirectionalAnimation`, exact plain-char direction | `0xfa`, SHA `5ECA3299...010D` | two callers; existing function comment |
| `0x005058b0` | `MapPane__ScrollViewportByDirection`, `void __thiscall MapPane__ScrollViewportByDirection(MapPane *this, unsigned __int8 direction)` | `0x8e`, SHA `14E8B510...B4C` | sole target caller `0x5a8597` |
| `0x005055e0` | `MapPane__ApplyMovementSubstepScroll`, `bool __thiscall MapPane__ApplyMovementSubstepScroll(MapPane *this, unsigned __int8 direction)` | `0x65`, SHA `3781FA52...0157` | target callers `0x5a8524/0x5a8589` |
| `0x0053a6b0` | `RemapMovementDirectionForMapScroll`, `unsigned __int8 __stdcall RemapMovementDirectionForMapScroll(unsigned __int8 direction)` | `0x2b`, SHA `B0C53BAC...9B27` | six movement/map callers; free helper |
| `0x0053b830` | `LivingObjectPane__OnTimer`, `bool __thiscall LivingObjectPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)` | `0x278`, SHA `830CA1F9...1DCB` | vtable `0x620a34`; two target delegations |
| `0x005a9240` | `UserPane__PropagateLinkedObjectMode`, `void __thiscall UserPane__PropagateLinkedObjectMode(UserPane *this, int mode)` | `0x9`, SHA `235BA9DC...6214` | UserPane vtable `0x62ef88`; tail-forwards to `0x0053c290` |
| `0x0053c290` | `LivingObjectPane__PropagateLinkedObjectMode`, `void __thiscall LivingObjectPane__PropagateLinkedObjectMode(LivingObjectPane *this, int mode)` | `0xd7`, SHA `668EBEE7...FA45` | LivingObjectPane vtable `0x6209f8`; mode propagation |
| UserPane UDT slot | `signed __int8 m_moveFrame +0x1c6`; opaque `+0x1c7` size `0x45`; `bool m_movementTimerHandled +0x20c`; opaque `+0x20d` size 3; `LineInputPane *m_activeLineInputPane +0x210`; `_userPaneAfterActiveLineInput +0x214` size 4; five named movement bytes `+0x13eaf0..+0x13eaf4`; named reply-family/history bytes `+0x13eb1e..+0x13eb1f` | size `0x13eb84`, exactly 68 members | saved-IDB `B7CC899D...58277` preserves the applied size-neutral split, `m_groupMembers +0x218`, and every unrelated neighbor |
| LineInputPane UDT dependency | complete `LineInputPane`, size `0x108` | exact saved-IDB `B7CC899D...58277` protected readback; A0 incomplete ordinal-803 state is historical | preserved complete type and all members |

At the dated pretransaction state, F1-F9 entry-comment channels were blank and C1 had only its former regular function comment. The dated CF18895C transaction applied the exact accepted function-repeatable comment on F1-F9 and the exact replacement regular function comment on C1. The fresh saved-IDB `B7CC899D...58277` readback independently reconfirms those comments, every other entry-comment channel blank, and the physical frames below; each item records `name @ offset / size : type (role)`.

| Entity | Literal saved-IDB `B7CC899D...58277` frame inventory |
| --- | --- |
| F1 `0x005a83b0` | `offset @ 0x0c / 0x8 : struct MapPoint (local coordinate delta)`; `__saved_registers @ 0x14 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x18 / 0x4 : _UNKNOWN * (caller return pointer)`; `timerId @ 0x1c / 0x4 : signed __int32 (timer selector)`; `arg0 @ 0x20 / 0x4 : int (first callback payload)`; `arg1 @ 0x24 / 0x4 : signed __int32 (second callback payload)`. Register `this` has no frame member. |
| F2 `0x0053bf40` | `__return_address @ 0x08 / 0x4 : _UNKNOWN * (caller return pointer)`. Saved-register entries: none. Local entries: none. Stack-argument entries: none. Register `this` has no frame member. |
| F3 `0x0053c070` | `var_C @ 0x08 / 0x4 : _DWORD (local temporary)`; `var_8 @ 0x0c / 0x4 : _DWORD (local temporary)`; `var_4 @ 0x10 / 0x4 : _DWORD (local temporary)`; `__saved_registers @ 0x14 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x18 / 0x4 : _UNKNOWN * (caller return pointer)`. Stack-argument entries: none. Register `this` has no frame member. |
| F4 `0x005055e0` | `var_8 @ 0x0c / 0x4 : _DWORD (local temporary)`; `__saved_registers @ 0x14 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x18 / 0x4 : _UNKNOWN * (caller return pointer)`; `direction @ 0x1c / 0x1 : unsigned __int8 (movement direction in its ABI home)`. Register `this` has no frame member. |
| F5 `0x005058b0` | `outPosition @ 0x08 / 0x8 : MapPoint (local output position)`; `var_4 @ 0x10 / 0x4 : _DWORD (local temporary)`; `__saved_registers @ 0x14 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x18 / 0x4 : _UNKNOWN * (caller return pointer)`; `direction @ 0x1c / 0x1 : unsigned __int8 (movement direction in its ABI home)`. Register `this` has no frame member. |
| F6 `0x0053a6b0` | `__saved_registers @ 0x00 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x04 / 0x4 : _UNKNOWN * (caller return pointer)`; `direction @ 0x08 / 0x1 : unsigned __int8 (movement direction stack argument)`. Local entries: none. |
| F7 `0x0053b830` | `__saved_registers @ 0x08 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x0c / 0x4 : _UNKNOWN * (caller return pointer)`; `timerId @ 0x10 / 0x4 : signed __int32 (timer selector)`; `arg0 @ 0x14 / 0x4 : int (first callback payload)`; `arg1 @ 0x18 / 0x4 : signed __int32 (second callback payload)`. Local entries: none. Register `this` has no frame member. |
| F8 `0x005a9240` | `__saved_registers @ 0x00 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x04 / 0x4 : _UNKNOWN * (caller return pointer)`; `mode @ 0x08 / 0x4 : int (forwarded mode argument)`. Local entries: none. Register `this` has no frame member. The supervisor's bounded delete attempt returned `mode is argument member`, confirming this deterministic materialized row. |
| F9 `0x0053c290` | `__saved_registers @ 0x0c / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x10 / 0x4 : _UNKNOWN * (caller return pointer)`; `mode @ 0x14 / 0x4 : signed __int32 (propagated mode stack argument)`. Local entries: none. Register `this` has no frame member. |
| C1 `0x005a36f0` | `__saved_registers @ 0x08 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x0c / 0x4 : _UNKNOWN * (caller return pointer)`; `direction @ 0x10 / 0x1 : unsigned __int8 (movement direction stack argument)`. Local entries: none. Register `this` has no frame member. |
| Protected `0x00597910` | `var_24 @ 0x0c / 0x4 : _DWORD (local temporary)`; `var_20 @ 0x10 / 0x4 : _DWORD (local temporary)`; `var_1C @ 0x14 / 0x4 : _DWORD (local temporary)`; `var_18 @ 0x18 / 0x4 : _DWORD (local temporary)`; `var_14 @ 0x1c / 0x4 : _DWORD (local temporary)`; `var_10 @ 0x20 / 0x4 : _DWORD (local temporary)`; `var_4 @ 0x2c / 0x4 : _DWORD (local temporary)`; `__saved_registers @ 0x30 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x34 / 0x4 : _UNKNOWN * (caller return pointer)`; `owner @ 0x38 / 0x4 : TimerHandler * (timer owner)`; `timerId @ 0x3c / 0x4 : int (timer selector)`; `delayMs @ 0x40 / 0x4 : unsigned int (delay)`; `arg0 @ 0x44 / 0x4 : int (first payload)`; `arg1 @ 0x48 / 0x4 : int (second payload)`. Register `this` has no frame member. |
| Protected `0x005a5a90` | `point @ 0x0c / 0x8 : Point (local map point)`; `var_8 @ 0x14 / 0x8 : Point (second local point)`; `__saved_registers @ 0x1c / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x20 / 0x4 : _UNKNOWN * (caller return pointer)`; `x @ 0x24 / 0x4 : int (map x)`; `y @ 0x28 / 0x4 : int (map y)`; `viewportColumn @ 0x2c / 0x4 : int (viewport column)`; `viewportRow @ 0x30 / 0x4 : int (viewport row)`. Register `this` has no frame member. |
| Protected `0x005a3770` | `__saved_registers @ 0x08 / 0x4 : _DWORD (compiler saved-register area)`; `__return_address @ 0x0c / 0x4 : _UNKNOWN * (caller return pointer)`; `direction @ 0x10 / 0x1 : char (signed movement direction)`. Local entries: none. Register `this` has no frame member. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| F1 `[0x005a83b0,0x005a87ad)` | [UID:0003VD] `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` | complete `UserPane::OnTimer` target | true | [UID:0000FQ] UserPane | 94/94 | ordinary implementation and F1 Gate 2B applied/verified |
| F2 `[0x0053bf40,0x0053bf77)` | [UID:0003Z7] `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `LivingObjectPane::ScheduleBoxRotationStep` support function | true | [UID:00007B] LivingObjectPane | 91/93 | support synchronization and F2 Gate 2B applied/verified |
| F3 `[0x0053c070,0x0053c1c9)` | [UID:0003Z7] `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `LivingObjectPane::SyncPositionToLinkedObjects` support function | true | [UID:00007B] LivingObjectPane | 91/93 | support synchronization and F3 Gate 2B applied/verified |
| F4 `[0x005055e0,0x00505645)` | [UID:000427] `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` | `MapPane::ApplyMovementSubstepScroll` dependency | true | [UID:00007Q] MapPane | 88/91 | caller synchronization and F4 Gate 2B applied/verified |
| F5 `[0x005058b0,0x0050593e)` | [UID:0002QL] `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` | `MapPane::ScrollViewportByDirection` dependency | true | [UID:00007Q] MapPane | 87/90 | support/formal correction and F5 Gate 2B applied/verified |
| F6 `[0x0053a6b0,0x0053a6db)` | [UID:0003Z3] `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | free `RemapMovementDirectionForMapScroll` helper | true | [UID:0000KU] source helper family | 88/90 | support synchronization and F6 Gate 2B applied/verified |
| F7 `[0x0053b830,0x0053baa8)` | [UID:0002R1] `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` | inherited `LivingObjectPane::OnTimer` callback | true | [UID:00007B] LivingObjectPane | 88/89 | support synchronization and F7 Gate 2B applied/verified |
| F8 `[0x005a9240,0x005a9249)` | [UID:0003Z7] `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `UserPane::PropagateLinkedObjectMode` virtual thunk | true | [UID:0000FQ] UserPane; contained by UID0003Z7 support page | 91/93 | range/vtable/tail evidence and F8 Gate 2B applied/verified, including materialized `mode` row |
| F9 `[0x0053c290,0x0053c367)` | [UID:0003Z7] `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `LivingObjectPane::PropagateLinkedObjectMode` implementation | true | [UID:00007B] LivingObjectPane | 91/93 | support synchronization and F9 Gate 2B applied/verified |
| C1 `[0x005a36f0,0x005a3766)` | [UID:0003U7] `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md` | `UserPane::InitializeWalkAnimation` starter and protected comment target | true | [UID:0000FQ] UserPane | 92/94 | ordinary/formal synchronization and C1 comment replacement applied/verified |
| `[0x005a3770,0x005a386a)` | [UID:0003U8] `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` | directional starter and protected dependency | true | [UID:0000FQ] UserPane | 92/94 | ordinary/formal synchronization applied; protected no-change readback verified |
| `[0x005a5a90,0x005a5b79)` | [UID:0003UE] `by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md` | coordinate warp/reset dependency | true | [UID:0000FQ] UserPane | 88/90 | ordinary/formal synchronization applied; protected no-change readback verified |
| `[0x005ab090,0x005ab410)` | [UID:0003UP] `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` | movement-reply continuation | true | [UID:0000FQ] UserPane | 92/94 | named-state ordinary/formal synchronization applied |
| `[0x005ab410,0x005ab75d)` | [UID:0003UQ] `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` | extended movement-reply continuation | true | [UID:0000FQ] UserPane | 92/94 | named-state ordinary/formal synchronization applied |
| `[0x004f2920,0x004f29ca)` | [UID:000364] `by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md` | active-line-input clear consumer | true | [UID:00001P] CharInputPane | 92/94 | corrected active-slot formal/prose and disproved history applied |
| UserPane class | [UID:0000FQ] `by-class/UserPane.md` | declaration, layout, inline helpers, and emitter owner | true | [UID:0000P1] UserPane file | 94/95 | complete formal H and blank class CPP applied; no score change |
| UserPane source file | [UID:0000P1] `by-file/UserPane.md` | `UserPane.cpp` / `UserPane.h` source route | n/a file | `FILE` | 93/94 | source integration applied; no score change |
| input-pane source family | [UID:0000K7] `by-file/InputPanes.md` | active-line-input lifecycle support route | n/a file | `FILE` | 92/92 | stale pending-target summary corrected |
| `[0x0062ef0c,0x0062efcc)` | [UID:0002YU] `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` | compiler-emitted UserPane vtable and TimerHandler slot evidence | false | [UID:0000FQ] UserPane | 90/94 | route evidence synchronized; formal CPP/H remain blank |
| `[0x0066da96,0x0066da97)` | [UID:00027F] `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` | one-byte movement substep scale | true | [UID:0000L3] movement global owner | 90/93 | existing layout/arithmetic evidence remains exact |
| successor `[0x005a87b0,0x005a87d5)` | [UID:0003VE] `by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md` | separate successor after three-byte compiler fence | true | [UID:0000FQ] UserPane | 87/89 | excluded from UID0003VD target; existing owner route remains separate |

No child split exists inside UID0003VD. The three bytes `[0x005a87ad,0x005a87b0)` are compiler alignment and stay outside the target.

## Direct Xref / Caller Inventory

- Target: one data xref `0x0062efc4`; zero direct code callers. This is affirmative virtual liveness, not a reachability blocker.
- `ScheduleBoxRotationStep`: calls from MapPane create/update at `0x005060af` and target sites `0x005a845a`, `0x005a849b`, `0x005a864a`, `0x005a868b`.
- `SyncPositionToLinkedObjects`: only target sites `0x005a859e` and `0x005a876a`.
- `WarpToPosition`: twelve callers, including target `0x005a8572` and `0x005a874e`.
- `InitializeWalkAnimation`: `0x005a3424`, target `0x005a85d6`, `0x005ab143`, and `0x005ab4c1`.
- `StartDirectionalAnimation`: `0x005a3607` and target `0x005a8796`.
- `ApplyMovementSubstepScroll`: only target `0x005a8524` and `0x005a8589`.
- `ScrollViewportByDirection`: only target `0x005a8597`.
- `RemapMovementDirectionForMapScroll`: `0x005058c6`, `0x0050be3b`, and target `0x005a843a`, `0x005a8515`, `0x005a857a`, `0x005a862a`.
- Base `OnTimer`: target `0x005a83dc/0x005a83ef` plus LivingObjectPane vtable `0x00620a34`.
- UserPane mode-propagation thunk: vtable `0x0062ef88`; its only code edge is tail forwarding `0x005a9244 -> 0x0053c290`.

## Documentation Evidence And IDA Status

Historical pre-callback documentation established most dependency names and source routes but did not combine them into the target body. The accepted callback superseded that state: UID0003VD now contains the complete formal CPP, UID0000FQ owns the complete formal H declaration, UID000364 and InputPanes use the active-LineInputPane contract, and the support pages record the target's dependency behavior at report detail. UID0003Z7 supplies `ScheduleBoxRotationStep`, `SyncPositionToLinkedObjects`, the LivingObjectPane mode-propagation implementation, and the literal `UserPane::PropagateLinkedObjectMode(int mode)` name for the `0x005a9240` UserPane thunk together with its vtable/tail evidence; C070 is applied. UID0003Z3 supplies the free direction-remap helper. UID000427 and UID0002QL supply the MapPane helpers. U7/U8 establish timer 20 and field reset order. UP/UQ establish the reply-state word stores and selector use. UID0002R1 supplies FWdA/FAnD and the base callback. B008 UID00035P plus current UserPane class/file docs establish the independent active-line-input slot contract at `+0x210`; the former UID000364/InputPanes pending-ObjectPane wording is now dated disproved history.

The fresh saved-IDB `B7CC899D...58277` readback matches the accepted source-quality model: F1-F9 retain the applied names/types/comments and required frames, C1 retains the exact corrected regular function comment, and T1 retains the requested size-neutral UserPane rows at an unchanged `0x13eb84` size with 68 members. The same bounded readback found no drift in the protected functions, bytes, xrefs, comments, frames, UDT dependencies, fences, vtable cells, or successor. The detailed handoff below preserves both dated prestates and the dated CF18895C transaction result, then binds every active-state assertion to the fresh `B7CC899D...58277` checkpoint.

## Ranked Ownership Analysis

1. **UserPane member in UserPane.cpp - accepted.** Sole UserPane TimerHandler vtable route, UserPane-only extension fields, UserPane movement helpers, and class/source path all agree.
2. **LivingObjectPane member - rejected.** It supplies base state and default callback, but the target touches UserPane-only fields through complete-object recovery and has the UserPane secondary vtable cell.
3. **MapPane member - rejected.** MapPane is a dependency reached through `m_mapPane`; it never supplies target ECX or vtable ownership.
4. **TimerMgr/TimerHandler implementation - rejected.** TimerMgr schedules and TimerHandler defines the interface; neither owns the derived callback body.
5. **Free UserPane.cpp helper - rejected.** The vtable slot and adjusted member ABI require a virtual member.
6. **Broad UID0001KL aggregate or new movement file - rejected.** The exact child and current file route already isolate the source method; duplicate emission would violate range ownership.
7. **No owner/non-emitting/compiler artifact - rejected.** Complete source behavior, virtual liveness, and ordinary class method shape are direct.

## Source Placement

- Definition: exact UID0003VD CPP channel, emitted through class UID0000FQ into file UID0000P1, `NexusTK/ui/panels/UserPane.cpp`.
- Declaration: the one complete UserPane declaration in UID0000FQ's formal H block, with UID0000FQ CPP blank. The target H channel remains blank because a second declaration would duplicate the class owner.
- Shared free direction helper remains with MapPane/LivingObjectPane source-family routing already documented; UID0003VD only calls it.
- MapPane and LivingObjectPane helper definitions remain in their own exact children.
- UID0001KL remains a non-duplicating aggregate/index.

## Range / Split / Padding / Reclassification Analysis

- Target modeled function is exactly `[0x005a83b0,0x005a87ad)`, 1,021 bytes, SHA256 `0260F191AA50A541D89BE148F3414DF840E88BEFBA8DABE62AF6E87C85BE8263`.
- Pre-target `[0x005a83a4,0x005a83b0)` is twelve `0xcc` bytes. The 16-byte read at `0x005a83a0` is `18 18 16 17` followed by those twelve bytes, SHA256 `F5594071D7BED766FB3C797DAAA31ABE45BF17337F65D0936E0355FD5B9F4FB9`.
- Post-target `[0x005a87ad,0x005a87b0)` is exactly `CC CC CC`.
- Successor starts at `0x005a87b0` with `55 8B EC 0F B6 55 08...`; the 19-byte boundary read has SHA256 `1956EFAF4AAACA4B2E1ACE06C7EFC46FD4A1F06A5339873137747C46667320B3`.
- No jump table, literal data, embedded child, exception fragment, or compiler-only subrange occurs inside the target. Switch lowering stays attached to the method.
- Keep the three-byte fence ignored/alignment and UID0003VE separate. No reclassification or new UID is required.

## Negative Evidence Summary

- Zero direct callers do not imply dead code because the exact UserPane TimerHandler vtable pointer is present.
- The adjusted receiver does not imply an artificial wrapper; it is normal multiple-inheritance secondary-base dispatch.
- `OnAnimationStep` is not supported by the inherited virtual contract.
- Event 20 is not an unresolved protocol opcode, Windows message, or generic frame index; it is the timer ID scheduled by U7/U8.
- FWdA and FAnD are not UserPane-private unknown tags.
- No behavior supports a null guard for `g_pTimerMgr`, `m_mapPane`, movement scale, or the complete object; do not add hardening.
- No evidence supports clamping directions, coordinates, scale, or frame count.
- No separate helper should be invented for the duplicated branch body; keeping the two switch cases explicit best preserves source-era shape and machine behavior.

## IDA Rename / Type / Comment Recommendations

Supervisor Gate 2B is applied and independently verified. The literal prestates below were established under dated checkpoints culminating in exact transaction prestate `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`; the supervisor copied the exact 143,192,467-byte prestate to `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B005-UID0003VD-20260731-025655.i64`, applied F1-F9/C1/T1, read back every mutable and protected property, and saved exactly once. The dated saved transaction poststate is `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, saved `2026-07-31T03:00:53.6024151-04:00`; `4B5F...A696A`, `1BC3...0CFD`, and `5F2679A7...79A21` are later dated shared-IDB checkpoints. No hash is durable future authority. The fresh bounded readback under saved IDB `B7CC899D...58277` proves that F1-F9 retain the accepted names, source-facing types, frames, and function-repeatable comments; C1 retains only the accepted regular-comment replacement; and T1 remains size `0x13eb84` with exactly 68 members. That same readback proves all protected hashes/xrefs/boundaries/comments/frames/dependencies exact. Address-regular, address-repeatable, and function-regular comments are blank at `B7CC899D...58277` unless explicitly stated otherwise below.

### Literal handoff matrix with dated prestate and applied `CF18895C...2C7F96` readback

| ID | Dated pretransaction entity/type | Protected identity | Applied disposition |
| --- | --- | --- | --- |
| F1 | `[0x005a83b0,0x005a87ad)` `sub_5A83B0`; `char __thiscall(int this, int a2, int arg0a, unsigned int a4)` | SHA `0260F191AA50A541D89BE148F3414DF840E88BEFBA8DABE62AF6E87C85BE8263`; sole data xref `0x62efc4`; 48 blocks/complexity 23 | applied/read back as `UserPane__OnTimer` with accepted bool TimerHandler-facet prototype, frame, and repeatable comment |
| F2 | `[0x0053bf40,0x0053bf77)` `sub_53BF40`; `void __thiscall(TimerHandler *this)` | SHA `B18375825A3E56C58839A9AB25A05899C7B7F1EDBB37C1F48A4677A9799272AF`; five code xrefs | applied/read back as `LivingObjectPane__ScheduleBoxRotationStep` with accepted owner type and repeatable comment |
| F3 | `[0x0053c070,0x0053c1c9)` `sub_53C070`; `int __thiscall(int this)` | SHA `7685E73983BB36E5CC1F79B6DC69472629D212DAB2C62FFDB12B32F80CA6BB34`; two code xrefs | applied/read back as void `LivingObjectPane__SyncPositionToLinkedObjects` with accepted comment |
| F4 | `[0x005055e0,0x00505645)` `sub_5055E0`; `char __thiscall(_DWORD *this, char a2)` | SHA `3781FA5229FA6798D0F33DFD101E04169E01862ACBF054B054AE66B63A600157`; two code xrefs | applied/read back as bool `MapPane__ApplyMovementSubstepScroll` with typed `direction` and accepted comment |
| F5 | `[0x005058b0,0x0050593e)` `sub_5058B0`; `void __thiscall(int this, char a2)` | SHA `14E8B5105ADF4A6EE4C1180CD108F8395359E7E305EAAA3D108A8D2B237CFB4C`; sole code xref | applied/read back as `MapPane__ScrollViewportByDirection` with typed `direction` and accepted comment |
| F6 | `[0x0053a6b0,0x0053a6db)` `sub_53A6B0`; `char __stdcall(char a1)` | SHA `B0C53BAC378274B820525885BF83A4A3D1F7801A80F6BBA6BD1B5D67076C9B27`; six code xrefs | applied/read back as unsigned-byte `RemapMovementDirectionForMapScroll` with accepted comment |
| F7 | `[0x0053b830,0x0053baa8)` `sub_53B830`; `char __thiscall(int this, int a2, int arg0a, unsigned int delayMs)` | SHA `830CA1F9473DD46A43975C987053328BC460D080E0416E29F3A49F45965C1DCB`; vtable `0x620a34` plus two target calls | applied/read back as bool `LivingObjectPane__OnTimer`; physical int rows render `signed __int32` |
| F8 | `[0x005a9240,0x005a9249)` `sub_5A9240`; `_DWORD *__thiscall(int this, int a2)` | SHA `235BA9DC58191BA61E5083F047EDAE942D584F04EE04AA0A90F50E0E8EE06214`; vtable `0x62ef88` | applied/read back as void `UserPane__PropagateLinkedObjectMode`; physical `mode @ 0x08 / 0x4 : int` materialized deterministically |
| F9 | `[0x0053c290,0x0053c367)` `sub_53C290`; `_DWORD *__thiscall(int this, int a2)` | SHA `668EBEE735E1E7AAEA0EFC1D12E25CAFA312003C9DE7060F19847B8EA397FA45`; vtable `0x6209f8` plus thunk call | applied/read back as void `LivingObjectPane__PropagateLinkedObjectMode`; physical mode row renders `signed __int32` |
| C1 | `[0x005a36f0,0x005a3766)` `UserPane_InitializeWalkAnimation`; `void __thiscall(UserPane *this, unsigned __int8 direction)` | SHA `986286D5DC686EEAE3C1FB5457A811E54C091D0587EA0EC22CF54B13EF37C158`; four code xrefs | exact regular-comment replacement applied; all other properties unchanged |
| T1 | `UserPane`, size `0x13eb84`, 60 members | exact partial-B008 rows/neighbors; complete `LineInputPane` size `0x108`; `TimerHandler` size 4/one member; `MapPane` size `0x910`/69 members | size-neutral rows applied/read back; UserPane remains `0x13eb84` and now has exactly 68 members |

Interpretation lock for the detailed rows below: every literal `Prestate` and `Dated pretransaction Hex-Rays` inventory is historical evidence from the matched B180 prestate, not an active-state assertion; every `Action` was applied by the supervisor; and every `Expected readback` records the independently verified CF18895C transaction result. The fresh saved-IDB `B7CC899D...58277` table and frame inventory above independently reconfirm every applied property. In the physical frame, F1/F7 `timerId` and `arg1` plus F9 `mode` render as `signed __int32`, while F1/F7 `arg0` renders as `int`; F1's `MapPoint` local renders as `struct MapPoint`, and F8 has the additional materialized `mode @ 0x08 / 0x4 : int` argument row. Function prototypes retain the accepted source-facing `int` and `MapPoint` spellings. This additive lock preserves the complete historical prestates while making every active-state assertion mechanically checkpoint-bound.

### IDA-F1 `0x005a83b0`

- Prestate: modeled function `[0x005a83b0,0x005a87ad)` named `sub_5A83B0`; full dated pretransaction declaration `char __thiscall sub_5A83B0(int this, int a2, int arg0a, unsigned int a4)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `var_8`, offset `0x0c`, size `0x1`, type `_BYTE`, role dated pretransaction local head byte; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `arg_0`, offset `0x1c`, size `0x4`, type `_DWORD`, role first stack callback argument; `arg0`, offset `0x20`, size `0x4`, type `int`, role second stack callback argument; `arg_8`, offset `0x24`, size `0x4`, type `_DWORD`, role third stack callback argument. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays argument inventory: `this`, `ECX`, size `0x4`, type `int`, role adjusted TimerHandler-facet receiver, local-user-comment none; `a2`, `[ebp+0x08]`, size `0x4`, type `int`, role timer selector, local-user-comment none; `arg0a`, `[ebp+0x0c]`, size `0x4`, type `int`, role first callback payload, local-user-comment none; `a4`, `[ebp+0x10]`, size `0x4`, type `unsigned int`, role second callback payload under the dated pretransaction analyzer type, local-user-comment none. Dated pretransaction Hex-Rays local inventory: `v6`, `EBX`, `0x4`, `int`, branch temporary, comment none; `v7`, `EAX`, `0x4`, `int`, arithmetic temporary, comment none; `v8`, `ECX`, `0x4`, `int`, receiver temporary, comment none; `v9`, `EAX`, `0x4`, `int`, arithmetic temporary, comment none; `v10`, `ZF`, `0x1`, `bool`, condition temporary, comment none; `v11`, `EDX`, `0x4`, `int`, arithmetic temporary, comment none; `v12`, `EAX`, `0x4`, `TimerHandler *`, timer-owner temporary, comment none; `v13`, `ESI`, `0x4`, `int`, owner/address temporary, comment none; `v14`, `AL`, `0x1`, `char`, boolean/result temporary, comment none; `v15`, `EAX`, `0x4`, `_DWORD *`, object temporary, comment none; `v16`, `AL`, `0x1`, `char`, result temporary, comment none; `v17`, `AL`, `0x1`, `char`, result temporary, comment none; `v18`, `EBX`, `0x4`, `int`, branch temporary, comment none; `v19`, `EAX`, `0x4`, `int`, arithmetic temporary, comment none; `v20`, `ECX`, `0x4`, `int`, receiver temporary, comment none; `v21`, `EAX`, `0x4`, `int`, arithmetic temporary, comment none; `v22`, `ZF`, `0x1`, `bool`, condition temporary, comment none; `v23`, `EDX`, `0x4`, `int`, arithmetic temporary, comment none; `v24`, `EAX`, `0x4`, `TimerHandler *`, timer-owner temporary, comment none; `v25`, `ESI`, `0x4`, `UserPane *`, complete-owner temporary, comment none; `v26`, `BL`, `0x1`, `char`, result temporary, comment none; `v27`, `EAX`, `0x4`, `_DWORD *`, object temporary, comment none; `v28`, `AL`, `0x1`, `char`, result temporary, comment none; `v29`, `[ebp-0x20]` (rendered `[esp-0x0c]` at call sites), `0x4`, `unsigned int`, FWdA delay temporary, comment none; `v30`, `[ebp-0x20]` (same reused call slot), `0x4`, `unsigned int`, local-event delay temporary, comment none; `v31`, `[ebp-0x08]`, `0x8`, `_DWORD[2]`, map/tile delta scratch, comment none; `v32`, `[ebp+0x10]`, `0x1`, `char`, saved original direction overlapping the fourth-argument home, comment none. Bytes SHA `0260F191...8263`; xref only `0x62efc4` data; adjacent padding and successor are outside the function.
- Collision: the dated pretransaction exact `UserPane__OnTimer` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x005a83b0` and no competing function.
- Action: rename to `UserPane__OnTimer`; apply `bool __thiscall UserPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)`; replace dated pretransaction local row `var_8` with `offset`, offset `0x0c`, size `0x8`, type `MapPoint`, role local coordinate delta; replace dated pretransaction stack row `arg_0` with `timerId`, offset `0x1c`, size `0x4`, type `int`, role timer selector; preserve dated pretransaction stack row `arg0`, offset `0x20`, size `0x4`, type `int`, role first callback payload; replace dated pretransaction stack row `arg_8` with `arg1`, offset `0x24`, size `0x4`, type `int`, role second callback payload; set function-repeatable comment: `UserPane TimerHandler override entered with the UserPane+0xa4 TimerHandler facet; source is bool UserPane::OnTimer(int timerId, int arg0, int arg1). Handles local event 20 and FWdA movement substeps; forwards FAnD/default to LivingObjectPane::OnTimer. Complete UserPane = this-0xa4 in machine code.`
- Expected readback: exact name/type/function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `offset`, offset `0x0c`, size `0x8`, type `MapPoint`, role local coordinate delta; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `timerId`, offset `0x1c`, size `0x4`, type `int`, role timer selector; `arg0`, offset `0x20`, size `0x4`, type `int`, role first callback payload; `arg1`, offset `0x24`, size `0x4`, type `int`, role second callback payload. The register `this` argument has no physical stack-frame member. Expected Hex-Rays argument readback: `this`, `ECX`, `0x4`, `TimerHandler *`, adjusted facet receiver, comment none; `timerId`, `[ebp+0x08]`, `0x4`, `int`, timer selector, comment none; `arg0`, `[ebp+0x0c]`, `0x4`, `int`, first payload, comment none; `arg1`, `[ebp+0x10]`, `0x4`, `int`, second payload, comment none. Expected Hex-Rays locals: `v6` EBX/int4, `v7` EAX/int4, `v8` ECX/int4, `v9` EAX/int4, `v10` ZF/bool1, `v11` EDX/int4, `v12` EAX/TimerHandler-pointer4, `v13` ESI/int4, `v14` AL/char1, `v15` EAX/_DWORD-pointer4, `v16` AL/char1, `v17` AL/char1, `v18` EBX/int4, `v19` EAX/int4, `v20` ECX/int4, `v21` EAX/int4, `v22` ZF/bool1, `v23` EDX/int4, `v24` EAX/TimerHandler-pointer4, `v25` ESI/UserPane-pointer4, `v26` BL/char1, `v27` EAX/_DWORD-pointer4, and `v28` AL/char1, each preserving its documented expected temporary role and each with local-user-comment none; `v29`, `[ebp-0x20]`, `0x4`, `unsigned int`, FWdA delay, comment none; `v30`, `[ebp-0x20]`, `0x4`, `unsigned int`, reused local-event delay, comment none; `offset`, `[ebp-0x08]`, `0x8`, `MapPoint`, map/tile delta scratch, comment none; `v32`, `[ebp+0x10]`, `0x1`, `char`, saved original direction overlapping `arg1` home, comment none. Range, byte hash, sole vtable xref, fences, and successor remain protected.
- F1 expected Hex-Rays temporary-role expansion, independent of the dated pretransaction list: `v6` is the EBX branch temporary; `v7` is the EAX arithmetic temporary; `v8` is the ECX receiver temporary; `v9` is the EAX arithmetic temporary; `v10` is the ZF condition temporary; `v11` is the EDX arithmetic temporary; `v12` is the EAX timer-owner temporary; `v13` is the ESI owner/address temporary; `v14` is the AL boolean/result temporary; `v15` is the EAX object temporary; `v16` is the AL result temporary; `v17` is the AL result temporary; `v18` is the EBX branch temporary; `v19` is the EAX arithmetic temporary; `v20` is the ECX receiver temporary; `v21` is the EAX arithmetic temporary; `v22` is the ZF condition temporary; `v23` is the EDX arithmetic temporary; `v24` is the EAX timer-owner temporary; `v25` is the ESI complete-UserPane temporary; `v26` is the BL result temporary; `v27` is the EAX object temporary; and `v28` is the AL result temporary. Each is exactly the width/type stated in the preceding expected inventory and each has local-user-comment state none; no additional expected register temporary is omitted.

### IDA-F2 `0x0053bf40`

- Prestate: modeled function `[0x0053bf40,0x0053bf77)` named `sub_53BF40`; full dated pretransaction declaration `void __thiscall sub_53BF40(TimerHandler *this)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `__return_address`, offset `0x08`, size `0x4`, type `_UNKNOWN *`, role caller return pointer. Saved-register entries: none. Local entries: none. Stack-argument entries: none. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays arguments: `this`, `ECX`, `0x4`, `TimerHandler *`, adjusted timer-facet receiver, local-user-comment none. Dated pretransaction Hex-Rays locals: `v2`, `EDI`, `0x4`, `TimerHandler *`, preserved receiver temporary, local-user-comment none. No stack Hex-Rays arguments and no other Hex-Rays locals exist. SHA `B1837582...72AF`; five caller sites listed above; adjacent functions remain outside this range.
- Collision: the dated pretransaction exact `LivingObjectPane__ScheduleBoxRotationStep` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x0053bf40` and no competing function.
- Action: rename and type `void __thiscall LivingObjectPane__ScheduleBoxRotationStep(LivingObjectPane *this)`; function-repeatable comment: `Cancels and schedules kLivingTimerBoxStep on the TimerHandler facet at LivingObjectPane+0xa4 with one-millisecond delay.`
- Expected readback: exact declaration `void __thiscall LivingObjectPane__ScheduleBoxRotationStep(LivingObjectPane *this)` and exact function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `__return_address`, offset `0x08`, size `0x4`, type `_UNKNOWN *`, role caller return pointer. Saved-register entries: none. Local entries: none. Stack-argument entries: none. The register `this` argument has no physical stack-frame member. Expected Hex-Rays arguments: `this`, `ECX`, `0x4`, `LivingObjectPane *`, complete-owner receiver, local-user-comment none. Expected Hex-Rays locals: `v2`, `EDI`, `0x4`, `LivingObjectPane *`, preserved complete-owner temporary, local-user-comment none. No stack Hex-Rays arguments and no other Hex-Rays locals are expected. Range, byte hash, five callers, and adjacent boundaries remain protected.

### IDA-F3 `0x0053c070`

- Prestate: modeled function `[0x0053c070,0x0053c1c9)` named `sub_53C070`; full dated pretransaction declaration `int __thiscall sub_53C070(int this)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `var_C`, offset `0x08`, size `0x4`, type `_DWORD`, role local temporary; `var_8`, offset `0x0c`, size `0x4`, type `_DWORD`, role local temporary; `var_4`, offset `0x10`, size `0x4`, type `_DWORD`, role local temporary; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer. Stack-argument entries: none. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays arguments: `this`, `ECX`, `0x4`, `int`, complete-owner receiver under analyzer type, local-user-comment none. Dated pretransaction Hex-Rays locals: `v2` ECX/int4 receiver temporary; `v3` EAX/int4 arithmetic temporary; `v4` EBX/int4 loop temporary; `v5` EDX/_DWORD-pointer-pointer4 list cursor; `v6` ESI/_DWORD-pointer4 object cursor; `v7` EDX/_DWORD-pointer-pointer4 list cursor; `j` ECX/int4 loop index; `v9` ESI/_DWORD-pointer4 object cursor; `v10` EAX/int4 call result; `v11` EAX/int4 call result; `result` EAX/int4 analyzer return temporary; `i` `[ebp-0x0c]`/int4 loop index; `v14` `[ebp-0x0c]`/_DWORD-pointer-pointer4 alias of `i`; `v15` `[ebp-0x08]`/_DWORD-pointer-pointer4 list cursor; `v16` `[ebp-0x08]`/int4 alias of `v15`; `v17` `[ebp-0x04]`/int4 local temporary. Every listed Hex-Rays local has local-user-comment none. SHA `7685E739...BB34`; two target callers; adjacent functions remain outside this range.
- Collision: the dated pretransaction exact `LivingObjectPane__SyncPositionToLinkedObjects` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x0053c070` and no competing function.
- Action: rename/type `void __thiscall LivingObjectPane__SyncPositionToLinkedObjects(LivingObjectPane *this)`; function-repeatable comment: `Copies owner map position to balloon, both attached-object lists, hit bar, optional EPF damage number, and object-info panes; source return is void.`
- Expected readback: exact declaration `void __thiscall LivingObjectPane__SyncPositionToLinkedObjects(LivingObjectPane *this)` and exact function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `var_C`, offset `0x08`, size `0x4`, type `_DWORD`, role local temporary; `var_8`, offset `0x0c`, size `0x4`, type `_DWORD`, role local temporary; `var_4`, offset `0x10`, size `0x4`, type `_DWORD`, role local temporary; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer. Stack-argument entries: none. The register `this` argument has no physical stack-frame member. Expected Hex-Rays arguments: `this`, `ECX`, `0x4`, `LivingObjectPane *`, complete-owner receiver, local-user-comment none. Expected Hex-Rays locals: `v2` ECX/int4 receiver temporary; `v3` EAX/int4 arithmetic temporary; `v4` EBX/int4 loop temporary; `v5` EDX/_DWORD-pointer-pointer4 list cursor; `v6` ESI/_DWORD-pointer4 object cursor; `v7` EDX/_DWORD-pointer-pointer4 list cursor; `j` ECX/int4 loop index; `v9` ESI/_DWORD-pointer4 object cursor; `v10` EAX/int4 call result; `v11` EAX/int4 call result; `i` `[ebp-0x0c]`/int4 loop index; `v14` `[ebp-0x0c]`/_DWORD-pointer-pointer4 alias; `v15` `[ebp-0x08]`/_DWORD-pointer-pointer4 list cursor; `v16` `[ebp-0x08]`/int4 alias; `v17` `[ebp-0x04]`/int4 local temporary. Every expected local retains local-user-comment none. The dated pretransaction `result` EAX/int4 return temporary is expected to be absent because the applied function return is `void`. Range, byte hash, two callers, and adjacent boundaries remain protected.

### IDA-F4 `0x005055e0`

- Prestate: modeled function `[0x005055e0,0x00505645)` named `sub_5055E0`; full dated pretransaction declaration `char __thiscall sub_5055E0(_DWORD *this, char a2)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `var_8`, offset `0x0c`, size `0x4`, type `_DWORD`, role local temporary; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `arg_0`, offset `0x1c`, size `0x4`, type `_DWORD`, role direction stack home under the dated pretransaction incomplete analyzer type. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays arguments: `this`, `ECX`, `0x4`, `_DWORD *`, MapPane receiver under analyzer type, local-user-comment none; `a2`, `[ebp+0x08]`, `0x1`, `char`, movement direction, local-user-comment none. Dated pretransaction Hex-Rays locals: `v3`, `EAX`, `0x4`, `_DWORD *`, object/member temporary, comment none; `v4`, `ESI`, `0x4`, `int`, arithmetic temporary, comment none; `v5`, `ECX`, `0x4`, `int`, receiver temporary, comment none; `v6`, `EAX`, `0x4`, `int`, arithmetic temporary, comment none; `v7`, `EAX`, `0x4`, `int`, call result, comment none; `v9`, `[ebp-0x08]`, `0x4`, `int`, by-reference local scratch, comment none. SHA `3781FA52...0157`; target callers `0x5a8524/0x5a8589`; adjacent functions remain outside this range.
- Collision: the dated pretransaction exact `MapPane__ApplyMovementSubstepScroll` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x005055e0` and no competing function.
- Action: rename/type `bool __thiscall MapPane__ApplyMovementSubstepScroll(MapPane *this, unsigned __int8 direction)`; replace stack row `arg_0` with `direction`, offset `0x1c`, size `0x1`, type `unsigned __int8`, role movement direction; function-repeatable comment: `Applies one scaled movement substep to MapPane pixel origins and returns shifted-area invalidation result.`
- Expected readback: exact declaration `bool __thiscall MapPane__ApplyMovementSubstepScroll(MapPane *this, unsigned __int8 direction)` and exact function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `var_8`, offset `0x0c`, size `0x4`, type `_DWORD`, role local temporary; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `direction`, offset `0x1c`, size `0x1`, type `unsigned __int8`, role movement direction stack argument in its four-byte ABI home. The register `this` argument has no physical stack-frame member. Expected Hex-Rays arguments: `this`, `ECX`, `0x4`, `MapPane *`, owner receiver, comment none; `direction`, `[ebp+0x08]`, `0x1`, `unsigned __int8`, movement direction, comment none. Expected Hex-Rays locals: `v3` EAX/_DWORD-pointer4 object/member temporary; `v4` ESI/int4 arithmetic temporary; `v5` ECX/int4 receiver temporary; `v6` EAX/int4 arithmetic temporary; `v7` EAX/int4 call result; `v9` `[ebp-0x08]`/int4 by-reference scratch; each has local-user-comment none. Range, byte hash, two callers, and adjacent boundaries remain protected.

### IDA-F5 `0x005058b0`

- Prestate: modeled function `[0x005058b0,0x0050593e)` named `sub_5058B0`; full dated pretransaction declaration `void __thiscall sub_5058B0(int this, char a2)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `outPosition`, offset `0x08`, size `0x8`, type `MapPoint`, role local output position; `var_4`, offset `0x10`, size `0x4`, type `_DWORD`, role local temporary; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `arg_0`, offset `0x1c`, size `0x4`, type `_DWORD`, role direction stack home under the dated pretransaction incomplete analyzer type. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays arguments: `this`, `ECX`, `0x4`, `int`, MapPane receiver under analyzer type, local-user-comment none; `a2`, `[ebp+0x08]`, `0x1`, `char`, movement direction, local-user-comment none. Dated pretransaction Hex-Rays locals: `v3`, `AL`, `0x1`, `char`, remapped direction, comment none; `v4`, `EAX`, `0x4`, `_DWORD *`, object/member temporary, comment none; `MapPosition`, `EAX`, `0x4`, `MapPoint *`, local-player map-position pointer, comment none; `row`, `EDI`, `0x4`, `int`, map row, comment none; `column`, `ESI`, `0x4`, `int`, map column, comment none; `ViewportPosition`, `EAX`, `0x4`, `MapPoint *`, viewport-position pointer, comment none; `outPosition`, `[ebp-0x0c]`, `0x8`, `MapPoint`, local output position, comment none; `v10`, `[ebp-0x04]`, `0x4`, `_DWORD *`, saved receiver/object temporary, comment none. SHA `14E8B510...B4C`; sole target caller `0x5a8597`; adjacent functions remain outside this range.
- Collision: the dated pretransaction exact `MapPane__ScrollViewportByDirection` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x005058b0` and no competing function.
- Action: rename/type `void __thiscall MapPane__ScrollViewportByDirection(MapPane *this, unsigned __int8 direction)`; replace stack row `arg_0` with `direction`, offset `0x1c`, size `0x1`, type `unsigned __int8`, role movement direction; function-repeatable comment: `Remaps movement direction, shifts object-list pixels, reads local-player map/viewport positions, and refreshes the scrolled tile window.`
- Expected readback: exact declaration `void __thiscall MapPane__ScrollViewportByDirection(MapPane *this, unsigned __int8 direction)` and exact function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `outPosition`, offset `0x08`, size `0x8`, type `MapPoint`, role local output position; `var_4`, offset `0x10`, size `0x4`, type `_DWORD`, role local temporary; `__saved_registers`, offset `0x14`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x18`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `direction`, offset `0x1c`, size `0x1`, type `unsigned __int8`, role movement direction stack argument in its four-byte ABI home. The register `this` argument has no physical stack-frame member. Expected Hex-Rays arguments: `this`, `ECX`, `0x4`, `MapPane *`, owner receiver, comment none; `direction`, `[ebp+0x08]`, `0x1`, `unsigned __int8`, movement direction, comment none. Expected Hex-Rays locals: `v3` AL/unsigned-char1 remapped direction; `v4` EAX/_DWORD-pointer4 object/member temporary; `MapPosition` EAX/MapPoint-pointer4 map-position pointer; `row` EDI/int4 map row; `column` ESI/int4 map column; `ViewportPosition` EAX/MapPoint-pointer4 viewport pointer; `outPosition` `[ebp-0x0c]`/MapPoint8 output position; `v10` `[ebp-0x04]`/MapPane-pointer4 saved receiver; each has local-user-comment none. Range, byte hash, sole caller, and adjacent boundaries remain protected.

### IDA-F6 `0x0053a6b0`

- Prestate: modeled function `[0x0053a6b0,0x0053a6db)` named `sub_53A6B0`; full dated pretransaction declaration `char __stdcall sub_53A6B0(char a1)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `__saved_registers`, offset `0x00`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x04`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `arg_0`, offset `0x08`, size `0x1`, type `_BYTE`, role movement direction stack argument. Local entries: none. Dated pretransaction Hex-Rays arguments: `a1`, `[ebp+0x08]`, `0x1`, `char`, movement direction, local-user-comment none. Dated pretransaction Hex-Rays locals: `result`, `AL`, `0x1`, `char`, remapped direction return, local-user-comment none. SHA `B0C53BAC...9B27`; six direct callers; adjacent functions remain outside this range.
- Collision: the dated pretransaction exact `RemapMovementDirectionForMapScroll` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x0053a6b0` and no competing function.
- Action: rename/type `unsigned __int8 __stdcall RemapMovementDirectionForMapScroll(unsigned __int8 direction)`; replace stack row `arg_0` with `direction`, offset `0x08`, size `0x1`, type `unsigned __int8`, role movement direction; function-repeatable comment: `Maps movement direction 1->3, 2->0, 3->1, and all other values ->2 for map-scroll coordinates.`
- Expected readback: exact declaration `unsigned __int8 __stdcall RemapMovementDirectionForMapScroll(unsigned __int8 direction)` and exact function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `__saved_registers`, offset `0x00`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x04`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `direction`, offset `0x08`, size `0x1`, type `unsigned __int8`, role movement direction stack argument. Local entries: none. Expected Hex-Rays arguments: `direction`, `[ebp+0x08]`, `0x1`, `unsigned __int8`, movement direction, local-user-comment none. Expected Hex-Rays locals: `result`, `AL`, `0x1`, `unsigned __int8`, remapped direction return, local-user-comment none. Range, byte hash, six callers, and adjacent boundaries remain protected.

### IDA-F7 `0x0053b830`

- Prestate: modeled function `[0x0053b830,0x0053baa8)` named `sub_53B830`; full dated pretransaction declaration `char __thiscall sub_53B830(int this, int a2, int arg0a, unsigned int delayMs)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `__saved_registers`, offset `0x08`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x0c`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `arg_0`, offset `0x10`, size `0x4`, type `_DWORD`, role timer selector stack argument; `arg0`, offset `0x14`, size `0x4`, type `int`, role first callback payload; `delayMs`, offset `0x18`, size `0x4`, type `unsigned int`, role analyzer-misclassified second callback payload in the dated pretransaction state. Local entries: none. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays arguments: `this`, `ECX`, `0x4`, `int`, adjusted TimerHandler-facet receiver, comment none; `a2`, `[ebp+0x08]`, `0x4`, `int`, timer selector, comment none; `arg0a`, `[ebp+0x0c]`, `0x4`, `int`, first callback payload, comment none; `delayMs`, `[ebp+0x10]`, `0x4`, `unsigned int`, analyzer-misclassified second callback payload, comment none. Dated pretransaction Hex-Rays locals: `v5` EDI/MapPane-pointer4 map owner; `v6` AL/char1 branch result; `v7` ECX/LivingObjectPane-pointer4 owner receiver; `v9` EAX/TimerHandler-pointer4 timer owner; `v10` EAX/TimerHandler-pointer4 timer owner; `v11` EDI/int4 timer/object temporary; `v12` ZF/bool1 condition; `v13` EDX/int4 arithmetic temporary; `EntryByIndex` EAX/MonsterImageEntry-pointer4 animation entry; `Group` EAX/ImageAnimationGroup-pointer4 animation group; `v16` EAX/unsigned-int4 frame duration; `v17` EAX/TimerHandler-pointer4 timer owner; `v18` EAX/int4 arithmetic result; `v19` ESI/ObjectPane-pointer4 linked object; `frameDuration` `[ebp-0x14]` (rendered `[esp-0x0c]` at calls)/unsigned-int4 scheduled duration. Every listed local has local-user-comment none. SHA `830CA1F9...1DCB`; vtable `0x620a34` and target calls `0x5a83dc/0x5a83ef`; adjacent functions remain outside this range.
- Collision: the dated pretransaction exact `LivingObjectPane__OnTimer` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x0053b830` and no competing function.
- Action: rename/type `bool __thiscall LivingObjectPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)`; replace stack row `arg_0` with `timerId`, offset `0x10`, size `0x4`, type `int`, role timer selector; preserve `arg0`, offset `0x14`, size `0x4`, type `int`, role first callback payload; replace `delayMs` with `arg1`, offset `0x18`, size `0x4`, type `int`, role second callback payload; function-repeatable comment: `LivingObjectPane TimerHandler override entered at owner+0xa4; handles FWdA/FBSA/iDhC/FAnD/aDeR timer families and returns false for unhandled IDs.`
- Expected readback: exact declaration `bool __thiscall LivingObjectPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)` and exact function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `__saved_registers`, offset `0x08`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x0c`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `timerId`, offset `0x10`, size `0x4`, type `int`, role timer selector; `arg0`, offset `0x14`, size `0x4`, type `int`, role first callback payload; `arg1`, offset `0x18`, size `0x4`, type `int`, role second callback payload. Local entries: none. The register `this` argument has no physical stack-frame member. Expected Hex-Rays arguments: `this` ECX/TimerHandler-pointer4 adjusted facet receiver; `timerId` `[ebp+0x08]`/int4 timer selector; `arg0` `[ebp+0x0c]`/int4 first payload; `arg1` `[ebp+0x10]`/int4 second payload; each has local-user-comment none. Expected Hex-Rays locals: `v5` EDI/MapPane-pointer4 map owner; `v6` AL/char1 branch result; `v7` ECX/LivingObjectPane-pointer4 owner receiver; `v9` EAX/TimerHandler-pointer4 timer owner; `v10` EAX/TimerHandler-pointer4 timer owner; `v11` EDI/int4 timer/object temporary; `v12` ZF/bool1 condition; `v13` EDX/int4 arithmetic temporary; `EntryByIndex` EAX/MonsterImageEntry-pointer4 animation entry; `Group` EAX/ImageAnimationGroup-pointer4 animation group; `v16` EAX/unsigned-int4 frame duration; `v17` EAX/TimerHandler-pointer4 timer owner; `v18` EAX/int4 arithmetic result; `v19` ESI/ObjectPane-pointer4 linked object; `frameDuration` `[ebp-0x14]`/unsigned-int4 scheduled duration; each retains local-user-comment none. Range, byte hash, vtable cell, target callers, and adjacent boundaries remain protected.

### IDA-F8 `0x005a9240`

- Historical pretransaction prestate: modeled thunk `[0x005a9240,0x005a9249)` named `sub_5A9240`; declaration `_DWORD *__thiscall sub_5A9240(int this, int a2)`; all four entry-comment channels absent; physical frame contained only `__saved_registers @ 0x00 / 0x4 : _DWORD` and `__return_address @ 0x04 / 0x4 : _UNKNOWN *`; no local or stack-argument row was materialized. Hex-Rays exposed `this` in ECX and `a2` at `[ebp+0x08]`; no locals. SHA `235BA9DC...6214`, vtable `0x62ef88`, tail jump to `0x0053c290`, and adjacent boundaries were exact.
- Collision: the dated transaction preflight found zero exact `UserPane__PropagateLinkedObjectMode` collisions before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x005a9240` and no competing function.
- Applied supervisor action: rename/type `void __thiscall UserPane__PropagateLinkedObjectMode(UserPane *this, int mode)` and set function-repeatable comment `UserPane vtable override/thunk forwarding PropagateLinkedObjectMode(mode) to the inherited LivingObjectPane implementation.`
- Saved-IDB `B7CC899D...58277` readback: exact declaration and function-repeatable comment are present; address-regular, address-repeatable, and function-regular comments are absent. Literal physical frame is `__saved_registers @ 0x00 / 0x4 : _DWORD`, `__return_address @ 0x04 / 0x4 : _UNKNOWN *`, and materialized `mode @ 0x08 / 0x4 : int`; local entries are none and register `this` has no physical frame member. Hex-Rays arguments are `this` in ECX as `UserPane *` and `mode` at `[ebp+0x08]` as `int`, both with local-user-comment none; locals are none. The dated supervisor transaction's bounded `delete_stack` attempt returned `mode is argument member`, proving the typed row is deterministic poststate rather than removable analyzer residue. The fresh readback preserves the two compiler rows, nine-byte body/hash, vtable xref, tail target, comments, range, and adjacent boundaries.

### IDA-F9 `0x0053c290`

- Prestate: modeled function `[0x0053c290,0x0053c367)` named `sub_53C290`; full dated pretransaction declaration `_DWORD *__thiscall sub_53C290(int this, int a2)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. Literal dated pretransaction physical-frame inventory: `__saved_registers`, offset `0x0c`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x10`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `arg_0`, offset `0x14`, size `0x4`, type `_DWORD`, role propagated mode stack argument. Local entries: none. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays arguments: `this`, `ECX`, `0x4`, `int`, LivingObjectPane receiver under analyzer type, local-user-comment none; `a2`, `[ebp+0x08]`, `0x4`, `int`, propagated mode, local-user-comment none. Dated pretransaction Hex-Rays locals: `v3` ECX/int4 receiver temporary; `v4` EBX/int4 list/branch temporary; `i` EDI/_DWORD-pointer4 object cursor; `result` EAX/_DWORD-pointer4 analyzer return temporary; `v7` EBX/int4 list/branch temporary; `v8` EDI/_DWORD-pointer4 object cursor; `v9` ECX/int4 receiver temporary; `v10` ECX/int4 receiver temporary; `v11` ECX/int4 receiver temporary. Every listed local has local-user-comment none. SHA `668EBEE7...FA45`; vtable `0x6209f8` and thunk caller `0x5a9244`; adjacent functions remain outside this range.
- Collision: the dated pretransaction exact `LivingObjectPane__PropagateLinkedObjectMode` query returned zero before rename; the saved-IDB `B7CC899D...58277` lookup resolves exactly `0x0053c290` and no competing function.
- Action: rename/type `void __thiscall LivingObjectPane__PropagateLinkedObjectMode(LivingObjectPane *this, int mode)`; replace stack row `arg_0` with `mode`, offset `0x14`, size `0x4`, type `int`, role propagated mode; function-repeatable comment: `Invalidates the owner and propagates mode through balloon, attached lists, hit bar, optional EPF damage number, and object-info panes.`
- Expected readback: exact declaration `void __thiscall LivingObjectPane__PropagateLinkedObjectMode(LivingObjectPane *this, int mode)` and exact function-repeatable comment; address-regular, address-repeatable, and function-regular comments absent. Literal expected physical-frame inventory: `__saved_registers`, offset `0x0c`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x10`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `mode`, offset `0x14`, size `0x4`, type `int`, role propagated mode stack argument. Local entries: none. The register `this` argument has no physical stack-frame member. Expected Hex-Rays arguments: `this` ECX/LivingObjectPane-pointer4 owner receiver and `mode` `[ebp+0x08]`/int4 propagated mode, each with local-user-comment none. Expected Hex-Rays locals: `v3` ECX/int4 receiver temporary; `v4` EBX/int4 list/branch temporary; `i` EDI/_DWORD-pointer4 object cursor; `v7` EBX/int4 list/branch temporary; `v8` EDI/_DWORD-pointer4 object cursor; `v9` ECX/int4 receiver temporary; `v10` ECX/int4 receiver temporary; `v11` ECX/int4 receiver temporary; every listed local has local-user-comment none. The dated pretransaction `result` EAX/_DWORD-pointer4 analyzer return temporary is expected to be absent after applying the `void` return type. Range, byte hash, vtable cell, thunk caller, and adjacent boundaries remain protected.

### IDA-T1 `UserPane`

- Historical pretransaction prestate: at B180 the UDT `UserPane` was size `0x13eb84` with 60 members; the type/member readback exposed no ordinary or repeatable UDT/member comments for the listed rows. Relevant rows were `m_isMoving +0x1c4`, `m_facing +0x1c5`, `_userPaneToActiveLineInput +0x1c6 size 0x4a`, `LineInputPane *m_activeLineInputPane +0x210`, `_userPaneAfterActiveLineInput +0x214 size 4`, `m_groupMembers +0x218`; `m_movementState +0x13eaf0 size 5`, `m_preActionTickState +0x13eaf5`; `m_inputLocked +0x13eb1d`, `m_movementHistoryState +0x13eb1e size 2`, `m_deferredUserListPacket +0x13eb20`. `LineInputPane` was already complete at size `0x108`; its A0 incomplete ordinal-803 state is older history.
- Applied supervisor action: size-preservingly replaced only the three broad rows with `signed __int8 m_moveFrame +0x1c6`, opaque `+0x1c7 size 0x45`, `bool m_movementTimerHandled +0x20c`, three-byte tail `+0x20d`, the five named one-byte movement fields at `+0x13eaf0..+0x13eaf4`, and `unsigned __int8 m_movementReplyTimerFamily +0x13eb1e` plus `bool m_movementHistoryEnabled +0x13eb1f`; preserved `LineInputPane *m_activeLineInputPane +0x210`, `_userPaneAfterActiveLineInput +0x214 size 4`, complete `LineInputPane`, and all unrelated layout.
- Saved-IDB `B7CC899D...58277` readback: UserPane is size `0x13eb84` with exactly 68 members. All requested rows, names, offsets, sizes, and types are exact; all neighbors and unrelated members are unchanged; `m_activeLineInputPane +0x210`, the `+0x214` tail, and `m_groupMembers +0x218` are exact. `LineInputPane` is complete at size `0x108`, TimerHandler is size 4 with one vftable member, and MapPane is size `0x910` with 69 members including `m_queuedMapStateRefresh +0x39d` and `m_pendingActionPoll +0x39e`.

### Saved-IDB `B7CC899D...58277` internal-comment protection map

These are non-entry comments present during dated discovery/preflight passes. The supervisor transaction preflight and CF18895C transaction readback compared all 132 declared rows and found all 132 nonempty and exact. The fresh saved-IDB `B7CC899D...58277` repair pass reread all 132 literal addresses enumerated in the bullets below and found zero text/channel mismatches; it separately reconfirmed every entry-comment channel for F1-F9/C1 and the three protected functions. Gate 2B changed only the accepted F1-F9 function-repeatable channels and C1 function-regular channel; this internal map and every protected channel are exact at `B7CC899D...58277`.

- F1 regular comments: `0x5a84de arg1`, `0x5a84e0 arg0`, `0x5a84e1 delayMs`, `0x5a84e7 this`, `0x5a84ed timerId`, `0x5a84f2 owner`, `0x5a8553 viewportRow`, `0x5a8559 viewportColumn`, `0x5a8569 this`, `0x5a856b y`, `0x5a8571 x`, `0x5a85d3 direction`, `0x5a85d4 this`, `0x5a86ce arg1`, `0x5a86d0 arg0`, `0x5a86d1 delayMs`, `0x5a86d7 this`, `0x5a86dd timerId`, `0x5a86df owner`, `0x5a8725 this`, `0x5a8738 viewportRow`, `0x5a8741 viewportColumn`, `0x5a8747 y`, `0x5a874d x`, `0x5a8793 direction`, `0x5a8794 this`.
- F2 regular comments: `0x53bf44 timerId`, `0x53bf4f this`, `0x53bf56 this`, `0x53bf5e arg1`, `0x53bf60 arg0`, `0x53bf62 delayMs`, `0x53bf66 timerId`, `0x53bf6e owner`.
- F3 and F4 have no internal comments at saved IDB `B7CC899D...58277`.
- F5 regular comments: `0x5058fe this`, `0x505907 position`, `0x505918 this`, `0x50591e outPosition`.
- F6 regular comments: `0x53a6b7 switch 4 cases`, `0x53a6bc switch jump`; repeatable comments: `0x53a6c3 jumptable 0053A6BC case 1`, `0x53a6c9 jumptable 0053A6BC case 2`, `0x53a6cf jumptable 0053A6BC case 3`, `0x53a6d5 jumptable 0053A6BC default case, case 0`.
- F7 regular comments: `0x53b87d this`, `0x53b899 arg1`, `0x53b89a arg0`, `0x53b89f this`, `0x53b8a5 delayMs`, `0x53b8a8 timerId`, `0x53b8b0 owner`, `0x53b8e4 arg1`, `0x53b8e6 arg0`, `0x53b8f0 delayMs`, `0x53b8fd timerId`, `0x53b905 this`, `0x53b90b owner`, `0x53b917 this`, `0x53b919 objectPane`, `0x53b93a this`, `0x53b940 arg1`, `0x53b942 arg0`, `0x53b94a delayMs`, `0x53b94b timerId`, `0x53b950 owner`, `0x53b97c this`, `0x53b982 objectPane`, `0x53b9df this`, `0x53b9ea index`, `0x53b9f0 groupIndex`, `0x53b9f6 this`, `0x53ba03 this`, `0x53ba58 frameIndex`, `0x53ba5e arg1`, `0x53ba60 arg0`, `0x53ba6e delayMs`, `0x53ba74 this`, `0x53ba7a timerId`, `0x53ba7f owner`, `0x53ba98 objectPane`, `0x53ba99 this`.
- F8 has no internal comments at saved IDB `B7CC899D...58277`. F9 regular comments are `0x53c297 this` and `0x53c29e objectPane`.
- C1 regular comments: `0x5a36fa moving`, `0x5a3717 this`, `0x5a372c arg1`, `0x5a3731 arg0`, `0x5a373c this`, `0x5a3742 delayMs`, `0x5a3743 timerId`, `0x5a374e owner`, `0x5a3754 this`, `0x5a375a objectPane`.
- Protected `TimerMgr_ScheduleTimer` has no internal comment map at saved IDB `B7CC899D...58277`. Protected `UserPane_WarpToPosition` regular comments are `0x5a5ace x`, `0x5a5acf y`, `0x5a5ad8 point`, `0x5a5ade x`, `0x5a5ae2 y`, `0x5a5ae3 point`, `0x5a5b13 this`, `0x5a5b22 timerId`, `0x5a5b32 timerId`, `0x5a5b34 this`, `0x5a5b46 this`, `0x5a5b4c objectPane`.
- Protected `UserPane_StartDirectionalAnimation` regular comments are `0x5a37ac this`, `0x5a37b2 groupIndex`, `0x5a37bf index`, `0x5a37c5 this`, `0x5a37d3 frameIndex`, `0x5a37d4 this`, `0x5a37db this`, `0x5a37e6 this`, `0x5a37ed this`, `0x5a37f9 arg1`, `0x5a37fb arg0`, `0x5a37fc delayMs`, `0x5a37fd timerId`, `0x5a37ff owner`, `0x5a3805 moving`, `0x5a3807 this`, `0x5a380e this`, `0x5a3815 objectPane`, `0x5a3821 moving`, `0x5a3840 this`, `0x5a3846 arg1`, `0x5a3848 arg0`, `0x5a3849 delayMs`, `0x5a384a timerId`, `0x5a3852 owner`, `0x5a3858 this`, `0x5a385e objectPane`.

### IDA-C1 `0x005a36f0`

- Prestate: modeled function `[0x005a36f0,0x005a3766)` named `UserPane_InitializeWalkAnimation`; full dated pretransaction declaration `void __thiscall UserPane_InitializeWalkAnimation(UserPane *this, unsigned __int8 direction)`; address-regular comment absent; address-repeatable comment absent; function-repeatable comment absent; function-regular comment exactly `Source: UserPane::InitializeWalkAnimation(unsigned char direction). Direct writes implement ClearMovementHistoryToken and SetDirectionDelayActive(false); inherited fields are m_facing, m_moveFrame, and m_objectStatus.m_displayStatusByte. Schedules kLivingTimerForwardStep through g_pTimerMgr, then refreshes bounds through m_mapPane.` Literal dated pretransaction physical-frame inventory: `__saved_registers`, offset `0x08`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x0c`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `direction`, offset `0x10`, size `0x1`, type `unsigned __int8`, role movement direction stack argument. Local entries: none. The register `this` argument has no physical stack-frame member. Dated pretransaction Hex-Rays arguments: `this`, `ECX`, `0x4`, `UserPane *`, owner receiver, local-user-comment none; `direction`, `[ebp+0x08]`, `0x1`, `unsigned __int8`, movement direction, local-user-comment none. Dated pretransaction Hex-Rays locals: none. SHA `986286D5...C158`; four callers.
- Collision: not applicable because the saved-IDB `B7CC899D...58277` name is preserved and only one existing comment channel changed during the dated Gate 2B transaction.
- Action: preserve the name, full declaration, literal frame items, bytes, range, and four xrefs; replace only the function-regular comment with `Source: UserPane::InitializeWalkAnimation(unsigned char direction). Direct writes implement ClearMovementReplyState and SetDirectionDelayActive(false); inherited fields are m_facing, m_moveFrame, and m_objectStatus.m_displayStatusByte. Schedules kLivingTimerForwardStep through g_pTimerMgr, then refreshes bounds through m_mapPane.`
- Expected readback: exact replacement function-regular comment; address-regular, address-repeatable, and function-repeatable comments absent; exact declaration `void __thiscall UserPane_InitializeWalkAnimation(UserPane *this, unsigned __int8 direction)`. Literal expected physical-frame inventory: `__saved_registers`, offset `0x08`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x0c`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `direction`, offset `0x10`, size `0x1`, type `unsigned __int8`, role movement direction stack argument. Local entries: none. The register `this` argument has no physical stack-frame member. Expected Hex-Rays arguments: `this`, `ECX`, `0x4`, `UserPane *`, owner receiver, local-user-comment none; `direction`, `[ebp+0x08]`, `0x1`, `unsigned __int8`, movement direction, local-user-comment none. Expected Hex-Rays locals: none. Range, byte hash, four callers, and adjacent boundaries remain protected.

### Protected no-change rows

- `0x00597910` `[0x00597910,0x00597a0c)`: saved-IDB `B7CC899D...58277` name `TimerMgr_ScheduleTimer`; full declaration `void __thiscall TimerMgr_ScheduleTimer(TimerMgr *this, TimerHandler *owner, int timerId, unsigned int delayMs, int arg0, int arg1)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent; SHA `9A8CF9EB...C5B4`; 48 callers. Literal saved-IDB `B7CC899D...58277` protected-readback frame inventory: `var_24`, offset `0x0c`, size `0x4`, type `_DWORD`, role local temporary; `var_20`, offset `0x10`, size `0x4`, type `_DWORD`, role local temporary; `var_1C`, offset `0x14`, size `0x4`, type `_DWORD`, role local temporary; `var_18`, offset `0x18`, size `0x4`, type `_DWORD`, role local temporary; `var_14`, offset `0x1c`, size `0x4`, type `_DWORD`, role local temporary; `var_10`, offset `0x20`, size `0x4`, type `_DWORD`, role local temporary; `var_4`, offset `0x2c`, size `0x4`, type `_DWORD`, role local temporary; `__saved_registers`, offset `0x30`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x34`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `owner`, offset `0x38`, size `0x4`, type `TimerHandler *`, role timer owner stack argument; `timerId`, offset `0x3c`, size `0x4`, type `int`, role timer selector stack argument; `delayMs`, offset `0x40`, size `0x4`, type `unsigned int`, role delay stack argument; `arg0`, offset `0x44`, size `0x4`, type `int`, role first callback payload; `arg1`, offset `0x48`, size `0x4`, type `int`, role second callback payload. The register `this` argument has no stack-frame member. Collision: not applicable because no rename is proposed. Classification: no action; the `B7CC899D...58277` readback preserves the exact name, declaration, comments, frame items, range, bytes, 48 callers, and adjacent boundaries.
- `0x005a5a90` `[0x005a5a90,0x005a5b79)`: saved-IDB `B7CC899D...58277` name `UserPane_WarpToPosition`; full declaration `bool __thiscall UserPane_WarpToPosition(UserPane *this, int x, int y, int viewportColumn, int viewportRow)`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent; SHA `320D4AD5...C75E`; 12 callers. Literal saved-IDB `B7CC899D...58277` protected-readback frame inventory: `point`, offset `0x0c`, size `0x8`, type `Point`, role local map point; `var_8`, offset `0x14`, size `0x8`, type `Point`, role second local point; `__saved_registers`, offset `0x1c`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x20`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `x`, offset `0x24`, size `0x4`, type `int`, role map-x stack argument; `y`, offset `0x28`, size `0x4`, type `int`, role map-y stack argument; `viewportColumn`, offset `0x2c`, size `0x4`, type `int`, role viewport-column stack argument; `viewportRow`, offset `0x30`, size `0x4`, type `int`, role viewport-row stack argument. The register `this` argument has no stack-frame member. Collision: not applicable because no rename is proposed. Classification: no action; the `B7CC899D...58277` readback preserves the exact name, declaration, comments, frame items, range, bytes, 12 callers, and adjacent boundaries.
- `0x005a3770` `[0x005a3770,0x005a386a)`: saved-IDB `B7CC899D...58277` name `UserPane_StartDirectionalAnimation`; full declaration `void __thiscall UserPane_StartDirectionalAnimation(UserPane *this, char direction)`; address-regular comment absent; address-repeatable comment absent; function-repeatable comment absent; function-regular comment exactly `Source: UserPane::StartDirectionalAnimation(char direction). MonsterObject resolves MonsterImageEntry -> ImageAnimationGroup -> ImageAnimationFrame and schedules signed frameDuration; other objects use m_displayStatusByte / g_movementSubstepScale. Direction is signed plain char.`; SHA `5ECA3299...010D`; two callers. Literal saved-IDB `B7CC899D...58277` protected-readback frame inventory: `__saved_registers`, offset `0x08`, size `0x4`, type `_DWORD`, role compiler saved-register area; `__return_address`, offset `0x0c`, size `0x4`, type `_UNKNOWN *`, role caller return pointer; `direction`, offset `0x10`, size `0x1`, type `char`, role signed movement direction stack argument. Local entries: none. The register `this` argument has no stack-frame member. Collision: not applicable because no rename is proposed. Classification: no action; the `B7CC899D...58277` readback preserves the exact name, declaration, comments, frame items, range, bytes, two callers, and adjacent boundaries.
- `TimerHandler` UDT: size 4 with one vftable and no target-driven member action. Classification: no change; preserve size/member identity.
- `MapPane` UDT: saved-IDB `B7CC899D...58277` size `0x910`, 69 members, including `bool m_queuedMapStateRefresh +0x39d` and `unsigned __int8 m_pendingActionPoll +0x39e`; no target-driven member action. Classification: no change; the bounded readback preserves that size, those members, and all target-independent types.

## First-Draft C++ Recommendation

The following is the exact replacement for UID0003VD's formal CPP channel. It is C++03, preserves switch/branch behavior, and contains no IDA artifacts.

```cpp
bool UserPane::OnTimer(int timerId, int arg0, int arg1)
{
    switch (timerId)
    {
    case kUserPaneMovementStep:
        {
            int direction = arg0;
            const int movementFrameCount = 4 * g_movementSubstepScale;

            m_movementTimerHandled = true;

            if (IsDirectionDelayActive())
            {
                m_moveFrame = static_cast<signed char>(
                    (movementFrameCount + m_moveFrame - 1) %
                    movementFrameCount);
                direction = RemapMovementDirectionForMapScroll(
                    static_cast<unsigned char>(direction));
            }
            else
            {
                m_moveFrame = static_cast<signed char>(
                    (m_moveFrame + 1) % movementFrameCount);
            }

            if (m_moveFrame == 0)
            {
                m_isMoving = false;
                ScheduleBoxRotationStep();
            }
            else if (!IsDirectionDelayActive() &&
                     m_moveFrame >= 2 &&
                     !m_movementReplyReceived)
            {
                if (m_moveFrame == 2)
                {
                    m_movementReplyPending = true;
                    m_movementReplyTimerFamily = 0;
                }
            }
            else
            {
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kUserPaneMovementStep,
                    m_objectStatus.m_displayStatusByte /
                        g_movementSubstepScale,
                    direction,
                    0);
            }

            if (m_isMoving)
            {
                PropagateLinkedObjectMode(direction);
            }
            else
            {
                if (!IsDirectionDelayActive())
                {
                    MapPoint offset;
                    DirectionToTileOffset(&offset, m_facing);
                    WarpToPosition(
                        m_mapX + offset.column,
                        m_mapY + offset.row,
                        m_viewportColumn + offset.column,
                        m_viewportRow + offset.row);
                }

                PropagateLinkedObjectMode(direction);
                SyncPositionToLinkedObjects();
            }

            if (!IsDirectionDelayActive() &&
                !m_isMoving &&
                --m_movementReplyCount > 0)
            {
                StartDirectionalAnimation(
                    static_cast<char>(direction));
                m_movementReplyReceived = true;
            }

            return true;
        }

    case kLivingTimerForwardStep:
        {
            int direction = arg0;
            const unsigned char originalDirection =
                static_cast<unsigned char>(direction);
            const int movementFrameCount = 4 * g_movementSubstepScale;

            m_movementTimerHandled = true;

            if (IsDirectionDelayActive())
            {
                m_moveFrame = static_cast<signed char>(
                    (movementFrameCount + m_moveFrame - 1) %
                    movementFrameCount);
                direction = RemapMovementDirectionForMapScroll(
                    static_cast<unsigned char>(direction));
            }
            else
            {
                m_moveFrame = static_cast<signed char>(
                    (m_moveFrame + 1) % movementFrameCount);
            }

            if (m_moveFrame == 0)
            {
                m_isMoving = false;
                ScheduleBoxRotationStep();
            }
            else if (!IsDirectionDelayActive() &&
                     m_moveFrame >= 2 &&
                     !m_movementReplyReceived)
            {
                if (m_moveFrame == 2)
                {
                    m_movementReplyPending = true;
                    m_movementReplyTimerFamily = 1;
                }
            }
            else
            {
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kLivingTimerForwardStep,
                    m_objectStatus.m_displayStatusByte /
                        g_movementSubstepScale,
                    direction,
                    0);
            }

            if (m_isMoving)
            {
                PropagateLinkedObjectMode(direction);
                m_mapPane->ApplyMovementSubstepScroll(
                    RemapMovementDirectionForMapScroll(
                        static_cast<unsigned char>(direction)));
            }
            else
            {
                if (!IsDirectionDelayActive())
                {
                    PropagateLinkedObjectMode(direction);

                    MapPoint offset;
                    DirectionToTileOffset(&offset, m_facing);
                    WarpToPosition(
                        m_mapX + offset.column,
                        m_mapY + offset.row,
                        m_viewportColumn,
                        m_viewportRow);

                    m_mapPane->ApplyMovementSubstepScroll(
                        RemapMovementDirectionForMapScroll(
                            static_cast<unsigned char>(direction)));
                    m_mapPane->ScrollViewportByDirection(
                        originalDirection);
                }

                SyncPositionToLinkedObjects();
            }

            if (!IsDirectionDelayActive() &&
                !m_isMoving &&
                --m_movementReplyCount > 0)
            {
                InitializeWalkAnimation(
                    static_cast<unsigned char>(direction));
                m_movementReplyReceived = true;
            }

            return true;
        }

    case kLivingTimerFrameAnimation:
        return LivingObjectPane::OnTimer(
            kLivingTimerFrameAnimation, arg0, arg1);

    default:
        return LivingObjectPane::OnTimer(timerId, arg0, arg1);
    }
}
```

The target child H channel stays exactly blank because the declaration belongs to the single class owner. UID0000FQ's formal CPP channel must become exactly blank: the class page contributes no out-of-class definition, while its exact children continue to own and emit definitions through the `[[CHILDREN]]` marker in the header formal. The complete current class declaration, inline methods, members, guards, and declarations move to UID0000FQ's formal H channel. This is the exact complete replacement payload, preserving the later B007 UID000415 chat-history additions and every unrelated current declaration/field while applying only the accepted UID0003VD changes:

```cpp
class Event;
class LineInputPane;
class MapPane;
class ObjectPane;
class SelectObjectWithKeyboardPane;
class UserPane;
class WillBeChangedSpellPane;
struct MapPoint;
struct ServerMessageEvent;

extern UserPane *g_pUserPane;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

void ToggleTargetSelectionPane(bool alternateMode);
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer);
void ReverseTargetSelectionDirection();
extern bool g_selectObjectTargetModeActive;
extern bool g_targetObjectTargetModeActive;
extern SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane;

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void __stdcall SendDirectionPacket(unsigned char direction);
static void SendOpcode7Command(unsigned char command);
void RefreshGroupMemberMarkers(UserPane *userPane);
void ClearGroupMemberMarkers(UserPane *userPane);

struct GroupMemberRecord
{
    unsigned int memberId;
    wchar_t name[128];
    bool active;
    unsigned short faceId;
    unsigned char hairId;
    unsigned char faceColor;
    unsigned char hairColor;
    unsigned char skinColor;
    unsigned char bodyColor;
    unsigned char helmetId;
    unsigned char helmetColor;
    unsigned short faceDecorationId;
    unsigned char faceDecorationColor;
    unsigned short hairDecorationId;
    unsigned char hairDecorationColor;
    unsigned short secondFaceDecorationId;
    unsigned char secondFaceDecorationColor;
    unsigned int maximumHitPoints;
    unsigned int currentHitPoints;
    unsigned int maximumManaPoints;
    unsigned int currentManaPoints;
};

struct LocalInventorySlotRecord
{
    unsigned char active;
    unsigned char reserved001;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved005;
    wchar_t displayName[80];
    wchar_t itemMetaKey[80];
    wchar_t ownerName[80];
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;
    unsigned char quantityPromptFlag;
    unsigned char reserved1ed[3];
    unsigned int currentDurability;
    unsigned int protectionCount;
    unsigned char targetMode;
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;
    unsigned char reserved001[3];
    int inputKind;
    wchar_t displayName[80];
    wchar_t prompt[80];
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    void GetPreviousChatHistoryLine(short *historyCursor,
                                    wchar_t *destination,
                                    size_t destinationCount);
    void GetNextChatHistoryLine(short *historyCursor,
                                wchar_t *destination,
                                size_t destinationCount);
    void SaveChatHistoryLine(const wchar_t *text);

    const wchar_t *GetSpellPromptText(char spellIndex) const
    {
        return m_spellCommandSlots[spellIndex - 1].prompt;
    }

    unsigned char GetHuntersListFlag() const
    {
        return m_huntersListFlag;
    }

    void SetHuntersListFlag(unsigned char flag)
    {
        m_huntersListFlag = flag;
    }

    wchar_t *GetPartySearchSourceText()
    {
        return m_partySearchSourceText;
    }

    const wchar_t *GetPartySearchSourceText() const
    {
        return m_partySearchSourceText;
    }

    void ClearActiveLineInputPane()
    {
        m_activeLineInputPane = NULL;
    }

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    void ClearDeferredUserListPacket();
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseGroupListPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(char direction);
    void BuildInventorySlotRangeText(wchar_t *outText) const;
    void BuildSpellSlotRangeText(wchar_t *outText) const;

private:
    friend class MapPane;
    friend class WillBeChangedSpellPane;
    friend void RefreshGroupMemberMarkers(UserPane *userPane);
    friend void ClearGroupMemberMarkers(UserPane *userPane);

    bool IsGroupMember(unsigned int memberId) const;
    GroupMemberRecord *FindGroupMemberById(unsigned int memberId);
    void AdvanceMovementSendTick();

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementReplyState()
    {
        m_movementReplyReceived = false;
        m_movementReplyPending = false;
    }

    void SetMovementReplyState()
    {
        m_movementReplyCount = 1;
        m_movementReplyReceived = true;
    }

    bool IsDirectionDelayActive() const
    {
        return m_directionDelayActive;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_directionDelayActive = active;
    }

    bool m_movementTimerHandled;
    unsigned char m_userPaneBaseStateTail[3];
    LineInputPane *m_activeLineInputPane;
    unsigned char m_userPanePreGroupState[4];
    GroupMemberRecord m_groupMembers[50];
    signed char m_groupMemberCount;
    unsigned char m_huntersListFlag;
    wchar_t m_partySearchSourceText[256];
    unsigned char m_preCollectionState[2];
    int m_currentSayMode;
    unsigned char m_preCollectionCommandState[2];
    bool m_collectionPanelSoundEnabled;
    unsigned char m_postCollectionCommandState[9];
    int m_localPlayerHitRadius;
    CollectionPlayerDataView m_collectionData;
    int m_screenX;
    int m_screenY;
    unsigned int m_screenState;
    RectBounds m_screenHitBounds;
    RectBounds m_screenLowerHitBounds;
    MapPane *m_mapPane;
    unsigned char m_playerSettingsState[8];
    LocalInventorySlotRecord m_inventorySlots[52];
    SpellCommandSlotRecord m_spellCommandSlots[52];
    bool m_spellCommandSlotsReady;
    unsigned char m_preViewportState[3];
    int m_viewportColumn;
    int m_viewportRow;
    int m_viewportHalfColumns;
    int m_viewportHalfRows;
    int m_viewportRemainingColumns;
    int m_viewportRemainingRows;
    unsigned char m_movementMode;
    signed char m_movementReplyCount;
    bool m_movementReplyReceived;
    bool m_movementReplyPending;
    bool m_directionDelayActive;
    unsigned char m_preActionTickState[3];
    unsigned int m_lastActionTick;
    unsigned int m_lastMapCommandTick;
    unsigned int m_lastGroundItemCommandTick;
    List *m_chatHistory;
    List *m_outgoingWhisperRecipientHistory;
    List *m_incomingWhisperSenderHistory;
    unsigned char m_whisperHistorySource;
    unsigned char m_preMovementHistory[3];
    LocalMovementHistoryRecord *m_movementHistoryRecords;
    int m_movementHistoryCapacity;
    unsigned char m_movementHistoryWriteIndex;
    bool m_inputLocked;
    unsigned char m_movementReplyTimerFamily;
    bool m_movementHistoryEnabled;
    unsigned char *m_deferredUserListPacket;
    size_t m_deferredUserListPacketSize;
    int m_deferredUserListCount;
    unsigned int m_deferredUserListDeadline;
    bool m_deferredUserListActive;
    unsigned char m_preMovementTicks[3];
    unsigned int m_lastMovementSendTick;
    unsigned int m_lastMovementInputTick;
    unsigned char m_actionMode;
    unsigned char m_userPaneTrailingState0;
    bool m_includeAdjacentMovementTargets;
    unsigned char m_userPaneTrailingState2;
    ObjectStatusBlob m_currentAppearance;
};

typedef char GroupMemberRecordSizeMustBe300[
    sizeof(GroupMemberRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
```

`m_moveFrame` remains inherited from `LivingObjectPane`; it is not redeclared in source UserPane even though IDA's flattened UserPane UDT should expose it. The exact class CPP disposition is blank; the target CPP remains the complete out-of-class definition above; the target H remains blank; and the complete class declaration exists once in UID0000FQ H.

## Final Recommendation

UID0003VD is implemented as one UserPane `OnTimer` method with no child split. Preserve exact event constants, branch ordering, modulo arithmetic, signed countdown, no-null-guard behavior, and base delegation. The ordinary documentation and formal channels use the source-facing fields above, preserve `LineInputPane *m_activeLineInputPane` at `+0x210`, preserve complete `LineInputPane` size `0x108`, keep target H blank, retain owner/emitter `0000FQ` and source file `0000P1`, and keep the target at `94/94`. UID0000FQ carries the complete class declaration and inline source in formal H while its formal CPP remains blank; UID0003VD owns the legitimate out-of-class `UserPane::OnTimer` definition. C070 is applied in UID0003Z7. Supervisor Gate 2B applied and independently verified F1-F9 names/types/frames/function-repeatable comments, C1's sole regular-comment replacement, and T1's size-neutral 68-member UserPane layout while preserving C155-C156 and every protected dependency. The fresh saved-IDB `B7CC899D...58277` reread reconfirms that F1/F7 `timerId` and `arg1` plus F9 `mode` use canonical physical `signed __int32`, F1/F7 `arg0` remains physical `int`, F1's local uses `struct MapPoint`, and F8 has the accepted materialized `mode @ 0x08 / 0x4 : int` row. M01-M09 are applied, N01-N06 are verified no-ops, and coverage validators `000000020166` through `000000020168` are dated application proof. Bounded physical coverage SHAs `DDB43AB5...EAFAE2`, `34287BEF...7E2C1`, and `F203FD4C...0210B` reverify all fifteen exact rows at the anchors listed below; neither hashes nor positions are asserted as permanent. Generated-output topology for any acceptance or lifecycle transition is verified from the then-current generated command metadata and physical artifacts; dated command20172 evidence below records one valid checkpoint without asserting permanent currentness.

## Recommended Target Doc Changes

- Metadata: `COMPLETION:94`, `CONFIDENCE:94`; all route fields unchanged.
- Replace the formal no-improvement comment with the complete CPP body in this report; leave formal H blank.
- Item Summary: `Exact source-ready UserPane TimerHandler override; handles local event 20 and FWdA four-substep movement, adjusted UserPane+0xa4 TimerHandler ABI, movement-reply latches, coordinate warp/scroll, linked-object propagation/synchronization, FAnD/default base delegation, exact bytes/boundaries, and complete C++.`
- Replace active `OnAnimationStep`/unresolved-0x14/offset-field prose with the exact current findings.
- Preserve old conclusions in a dated historical-assumptions section explaining why vtable contract, sibling schedulers, and live field evidence supersede them.
- Preserve the exact byte SHA, complete historical prestate plus applied physical-frame/Hex-Rays inventories, xrefs, branch table, field-offset translation, caller/callee inventory, owner/source reasoning, negative evidence, and the now-reconciled IDA applied-state evidence.

## Recommended Support Doc Changes

- [UID:0000FQ] `by-class/UserPane.md`: move the complete current declaration/inline/member/type payload from formal CPP to formal H, leave formal CPP blank, replace declaration, movement helpers, touched fields, method inventory, layout table, vtable explanation, target readiness, and historical notes at report detail; preserve all unrelated class content, the later B007 UID000415 chat-history additions, B008's `LineInputPane *m_activeLineInputPane`/`ClearActiveLineInputPane()` correction, and `sizeof(UserPane)==0x13eb84`.
- [UID:0000P1] `by-file/UserPane.md`: add complete source placement/dependency/method relationship, record the `UserPane.h` declaration plus `UserPane.cpp` out-of-class definition topology, historicalize `OnAnimationStep`, preserve the later B007 UID000415 additions and B008 active-line-input section, reject pending-target wording for current source, and make no score/path change.
- [UID:000364] CharInputPane handler: replace formal `ClearPendingTargetObject()` and active pending-ObjectPane prose with `ClearActiveLineInputPane()`; preserve the old interpretation in a dated historical section with the exact typed-writer/no-ObjectPane-store rejection reason.
- [UID:0000K7] `by-file/InputPanes.md`: replace the remaining summary sentence that calls `+0x210` a pending target with the active LineInputPane replace/clear lifecycle; retain the old wording only as disproved history.
- [UID:0002YU] vtable page: change source-facing slot name at `0x62efc4` to `UserPane::OnTimer` and explain TimerHandler facet.
- [UID:0003Z7]: current F2/F3/F8/F9 IDA evidence and target caller semantics are present. C070 added the literal source-facing name `UserPane::PropagateLinkedObjectMode(int mode)` to the existing target-specific `0x005a9240` thunk sentence while preserving its vtable/tail evidence, formal bodies, range, owner, and 91/93 score unchanged.
- [UID:0003Z3]: add current F6 IDA evidence and target branch roles; no formal behavior change.
- [UID:0002R1]: reconcile current-facing callback spelling to `OnTimer`; retain `HandleTimerMessage` only as dated historical wording.
- [UID:000427]: add target caller/branch context and IDA applied state; formal body already correct.
- [UID:0002QL]: correct `DirectionToTileOffset(scrollDirection, &tileDelta)` to `DirectionToTileOffset(&tileDelta, scrollDirection)` and update target name/current IDA state.
- [UID:0003U7]/[UID:0003U8]: replace `ClearMovementHistoryToken()` with `ClearMovementReplyState()` and synchronize named fields/current IDA comments without changing behavior/scores.
- [UID:0003UE]: synchronize its direct clears of reply/direction-delay fields and target completion relationship.
- [UID:0003UP]/[UID:0003UQ]: replace movement-state array indexing with named fields while preserving every packet branch and current score.
- [UID:00027F]: no edit unless drift; its scale semantics are already complete.
- Successor UID0003VE: no edit unless current prose still calls the predecessor `OnAnimationStep`; boundaries/ownership remain separate.

## Score And Metadata Recommendation

| UID | Current | Recommended | Route/formal decision | Rationale |
| --- | --- | --- | --- | --- |
| 0003VD | 94/94 (post-callback; 87/89 historical prestate) | unchanged | owner/emitter 0000FQ unchanged; CPP complete; H blank | all behavior, ABI, fields, helpers, range, source, and formal code resolved; stripped private spellings cap both below 95 |
| 0000FQ | 94/95; current bounded SHA `4784B20F...BCE6D8`; UID0003VD post-validator SHA `C7873624...1BFB9` and callback-input SHA `DB786753...97578` historical | unchanged | one complete class declaration in formal H; formal CPP blank | later additive B008 saved-layout provenance preserves every UID0003VD declaration/layout/formal claim and does not justify exceeding current high score |
| 0000P1 | 93/94; current bounded SHA `8A534098...08D772`; UID0003VD post-validator SHA `512BA4D0...4CA33` and callback-input SHA `54A260E4...781B` historical | unchanged | source folder unchanged | later additive B008 source-route provenance preserves exact UID0003VD method placement |
| 0002YU | 90/94 | unchanged | nonreconstructable compiler data | naming sync only |
| Support children | as listed | unchanged | existing owners/formals retained | target supplies new caller/currentness evidence, not independent score audits |

The target is not recommended at 95 completion because exact original private spellings for the one-shot handled flag and two otherwise-unused state bytes are inferential. It is not lower because the chosen spellings are behaviorally explicit, all observable code is complete, and no raw names remain in emitted C++.

The dated discovery and no-drift checkpoints did not alter any score. The supervisor transaction at B180/CF18895C applied every accepted F1-F9/C1/T1 action, verified all complete frames/Hex-Rays inventories and protected functions, and preserved runtime evidence without changing the target's `94/94` rationale. The fresh saved-IDB `B7CC899D...58277` readback proves UserPane size `0x13eb84` with exactly 68 members and complete `LineInputPane` size `0x108`; those facts preserve the same score rationale and protected-dependency conclusion. M01-M09/N01-N06 likewise synchronize manual descriptions without changing any recommended score.

## Open Questions With Attempted Resolution

- **Was the method originally named `OnAnimationStep`?** No. The TimerHandler vtable slot and default base call make `OnTimer` the only contract-compatible current decision.
- **What is event `0x14`?** Resolved as `kUserPaneMovementStep`, scheduled by both UserPane animation starters with direction in `arg0`.
- **Why `this-0xa4`?** Resolved as compiler lowering from the UserPane TimerHandler secondary facet; source uses ordinary member access.
- **What do movement bytes mean?** All target-touched bytes now have high-probability source names tied to exact read/write behavior. `m_movementMode` and `m_movementHistoryEnabled` are adjacent untouched fields inferred from placement/initialization; they do not enter target behavior.
- **Are helper signatures still provisional?** No. All assignment-named callees have current source signatures, return dispositions, owner routes, caller sets, and IDA handoffs. UID0002QL's reversed formal call is explicitly corrected.
- **Does zero direct target caller make it dead?** No; the exact vtable cell is its invocation route.
- **Does target need a split?** No; bytes and control flow are one method, followed by a separate three-byte fence and successor.
- **Does the remaining lexical uncertainty block CPP?** No. The report chooses realistic source names and caps score rather than retaining reverse-engineering labels.
- **What is UserPane `+0x210`?** Resolved as `LineInputPane *m_activeLineInputPane`. The sole non-null writer stores typed constructor `this`; eighteen writes initialize/clear the slot; target-selection objects remain separate. `m_currentLineInputPane` is a plausible lexical alternative, but the established `active` spelling is the highest-probability project-consistent choice and does not affect ABI or behavior.
- **Why was pending target previously plausible?** Several target-selection handlers clear the active input pane adjacent to object interaction. Focused data flow disproves role conflation: no ObjectPane pointer enters `+0x210`, so that wording remains historical only.

No evidence, inference, source-placement, score, C++, IDA, or manual-coverage blocker is deferred to future research. C070, F1-F9/C1/T1, M01-M09, and N01-N06 are mechanically complete and verified. Generated-currentness, exact-artifact audit, and execution/archive truth are transition-specific supervisor checks governed by the artifact's then-current path and validator-owned status/history, not report-body claims of pending or completed lifecycle work.

The saved-IDB lineage through 412D, EEF0, 222D, 6470, A4A6, 87D3, 83C2, D65C, 2CCA, 4EDEC, 3892, 4A, A0, D7D2, and F7 is dated discovery/confirmation history. The supervisor transaction preflight at exact `B180F0E4...F2A07` found all nine names collision-free and every action applicable; the applied readback at dated `CF18895C...2C7F96` confirmed all names/types/comments/frames, all 132 transaction-audited internal comments, the 68-member UserPane result, complete LineInputPane, C155-C156 preservation, and every protected invariant. Later bounded checkpoints `4B5F...A696A`, `1BC3...0CFD`, and `5F2679A7...79A21` are dated history. The bounded saved-IDB `B7CC899D...58277` pass reconfirmed all 11 handoff rows, all three protected functions, all UDT dependencies, and all 132 literal internal-comment addresses enumerated in this report with zero mismatch. The target channel is complete CPP with blank target H; the owner class is complete UID0000FQ H with blank UID0000FQ CPP. Any later currentness is authoritative only from another fresh bounded readback.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The supervisor applied M01-M09 and verified N01-N06 against exact UID anchors, then ran scoped validators: by-memory command `000000020166`, by-class command `000000020167`, and by-file command `000000020168`, each exit `0` / `ok: 1`. Their dated post-application identities are `by-memory/-coverage-report.md` SHA256 `F470880A233CB61ACC3227910478A6F22147B4B65A014FCCBCD0237D7DADA3F7`, 2,115,803 bytes / 4,782 lines; `by-class/-coverage-report.md` SHA256 `9B8B77532BAA43613618BCB3275E9E9D6668EADA1A499F154ACAC18B3DAF5033`, 273,344 bytes / 625 lines; and `by-file/-coverage-report.md` SHA256 `5704439FC3EA94C4A3568B1E5712C30ADD1E77BCDA21B0808AFBDE7C3AFA223B`, 164,262 bytes / 317 lines. Their associated line positions are dated validator-checkpoint evidence, not present physical positions.

The supervisor-supplied Gate 1 snapshot observed `by-memory/-coverage-report.md` SHA256 `6C2C8B453EBBB98E1C5932F6B3B300EA8167CE9620CA1386EAA9F772ADD741B7`, 2,118,546 bytes / 4,787 lines; `by-class/-coverage-report.md` SHA256 `9B8B77532BAA43613618BCB3275E9E9D6668EADA1A499F154ACAC18B3DAF5033`, 273,344 bytes / 625 lines; and `by-file/-coverage-report.md` SHA256 `E71703BB63B1E1C9A4E9CED4677F5E1C1355416655282674378DA1ADF6EA4126`, 164,309 bytes / 317 lines. At that dated bounded snapshot M01-M09 were at `3818, 589, 298, 2799, 2362, 3802, 3838, 3839, 4451` and N01-N06 were at `2780, 2793, 2363, 3804, 3814, 4498`.

A later unrelated by-memory coverage addition advanced that moving file to dated SHA256 `5CDCBB4B7CBAD1516373078F0117F4062087F806F69E98574F077705AEDD53FF`, 2,119,450 bytes / 4,788 lines. The bounded repair reread observed by-memory SHA256 `DDB43AB5B6B22EE411536C9A470847389C42CC3CB4EDC159D0BF509173EAFAE2`, 2,121,961 bytes / 4,790 lines; by-class SHA256 `34287BEF3C9E700199102050F52BCA1C87189863E3A977C16021783D8027E2C1`, 274,255 bytes / 625 lines; and by-file SHA256 `F203FD4C148CE2192868B4CBE8C1E094C50F438548977C885FF378D78F90210B`, 165,800 bytes / 318 lines. M01-M09 were exact at `3820, 589, 299, 2801, 2363, 3804, 3840, 3841, 4454`; N01-N06 were exact at `2782, 2795, 2364, 3806, 3816, 4501`. Every row matched its applied or verified-no-op payload; no manual edit was required. These whole-file hashes and physical line positions are bounded moving evidence, not durable truth, and a later physical reread supersedes them.

Applied operation classification and exact post-application readback:

| Operation | Exact post-application row/anchor evidence | Classification |
| --- | --- | --- |
| M01 UID0003VD | Exact staged row is present at bounded by-memory line 3820 in the intended UID0003VB/UID0003VE neighborhood. | Applied and validated by command `000000020166`; `DDB43AB5...EAFAE2` anchor reverified. |
| M02 UID0000FQ | Exact staged row is present at by-class line 589 with active LineInputPane semantics, UID000415 preservation, and UID0003VD OnTimer/H placement. | Applied and validated by command `000000020167`. |
| M03 UID0000P1 | Exact staged row is present at bounded by-file line 299 with active LineInputPane semantics and UID0003VD CPP/H routing. | Applied and validated by command `000000020168`; `F203FD4C...0210B` anchor reverified. |
| M04 UID0003Z7 | Exact 91%/very-strong staged row is present at bounded by-memory line 2801. | Applied and validated by command `000000020166`; `DDB43AB5...EAFAE2` anchor reverified. |
| M05 UID000427 | Exact staged row is present at bounded by-memory line 2363 immediately before UID0002QL line 2364. | Applied and validated by command `000000020166`; `DDB43AB5...EAFAE2` anchor reverified. |
| M06 UID0003U7 | Exact staged movement-reply/direction-delay row is present at bounded by-memory line 3804. | Applied and validated by command `000000020166`; `DDB43AB5...EAFAE2` anchor reverified. |
| M07 UID0003UP | Exact staged named-field row is present at bounded by-memory line 3840. | Applied and validated by command `000000020166`; `DDB43AB5...EAFAE2` anchor reverified. |
| M08 UID0003UQ | Exact staged named-field row is present at bounded by-memory line 3841. | Applied and validated by command `000000020166`; `DDB43AB5...EAFAE2` anchor reverified. |
| M09 UID0002YU | Exact staged TimerHandler OnTimer slot/facet row is present at bounded by-memory line 4454. | Applied and validated by command `000000020166`; `DDB43AB5...EAFAE2` anchor reverified. |

### Manual mutation M01 - insert UID0003VD

Applied exact row, preserved literally for audit; bounded `DDB43AB5...EAFAE2` readback is by-memory line 3820:

```text
        - [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) 0x005a83b0-0x005a87ad | UserPane TimerHandler override | UserPaneHandleAnimationStep : reconstructable : 94% : very-strong : Exact source-ready bool UserPane::OnTimer override entered through the UserPane+0xa4 TimerHandler facet; handles local event 20 and FWdA four-substep movement, named reply/direction state, map and viewport warp/scroll, linked-object propagation/synchronization, FAnD/default base delegation, exact bytes/boundaries, and complete human C++.
```

### Manual mutation M02 - replace UID0000FQ by-class row

Applied exact replacement row, preserved literally for audit; bounded `34287BEF...7E2C1` readback is by-class line 589:

```text
- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 94% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external ProcessMovement and event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, signed plain-char StartDirectionalAnimation(char direction) with signed-short frame-duration/MonsterObject image-table and signed non-monster scaled-delay contracts, 52 exact 508-byte inventory records with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, exact player-settings semantics comprising state[0] feature/UI mode, state[2] viewport-threshold mode, state[3] direction mode, state[4] MapPane-render blindness with bounds invalidation, and state[5]/[6] chat display/send restriction levels, the distinct movement-state index-3 pending-reply flag versus index-4 direction-delay state, source-ready opcode-0x05 HandleServerEntryPacket declaration, exact EventHandler HandleKeyOrTextEvent(Event *) override, six resolved B003 target/helper declarations, preserved current B002 UID0004R9 child, int say-mode/collection-panel-sound/three-debounce/input-lock field splits, exact 0x20c base boundary, class closure before child definitions, exact records/size guards, preserved full unrelated field/record/layout/source surface, exact final-byte plus 68-byte m_currentAppearance tail used by MapPane local-player status updates, and UID0003UB's retained ExecuteHotkeyAction(short) declaration plus exact three-page 30-row Text/Spell/Item runtime behavior; the complete Config declaration exposes direct macro and compact tables; UID0003UA emits exact retained compact-shortcut source while UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; retains exact private IsGroupMember(unsigned int) const and AdvanceMovementSendTick() declarations over the existing signed group count, GroupMemberRecord table, movement tick, TimerMgr, and BowGauge state; adds exact +0x3cb1 hunters-list flag, +0x3cb2 wchar_t[256] party-search source text, two residual bytes, and four inline cross-source accessors in place of only the former opaque 0x203-byte slice; adds the public inline const GetSpellPromptText(char) accessor over the exact 52-entry SpellCommandSlotRecord table, preserving the 0x148 record, +0xa8 prompt, one-based signed index arithmetic, complete 0x13eb84 layout, and every existing UserPane declaration/field/method/history fact; exposes complete-object +0x210 as LineInputPane *m_activeLineInputPane with inline ClearActiveLineInputPane(), four-byte state on each side, all later offsets and sizeof(UserPane)==0x13eb84 preserved, with UID00035P as the sole non-null typed writer and UID00035Y/UID000364/UID00036C plus derived input-pane handlers as exact clear consumers; the earlier pending-target ObjectPane interpretation is retained only as disproved history because target-selection objects remain separate from the cleared slot; preserves the exact ClearDeferredUserListPacket declaration/source child that frees and clears only the deferred packet pointer, count, and deadline while preserving size, active state, complete layout, and the full current UserPane union; replaces SpellCommandSlotRecord reserved bytes +0x08..+0xa7 with exact wchar_t displayName[80], retains prompt[80] at +0xa8 and sizeof 0x148, and adds bounded WillBeChangedSpellPane friendship for the existing one-based private record accessor without changing any other declaration, offset, guard, score, owner, or route. UID0003ZT confirms MapPane +0x418 is source-typed UserPane * because UID0003ZS calls UserPane-only ProcessMovement twice; UserPane.h exports the complete UserPane declaration plus g_pUserPane and g_pInputBlockerPane extern contracts while their definitions remain singular. UID000415 resolves List *m_chatHistory at +0x13eb04 and the exact GetPreviousChatHistoryLine, GetNextChatHistoryLine, and SaveChatHistoryLine members at 0x005a4930, 0x005a4990, and 0x005a49e0, including signed-short cursor wrap, bounded wide copies, newest-boundary empty result, duplicate suppression, ten-line cap, canonical g_pUserPane callers, and unchanged adjacent recipient-history fields. UID0003VD adds exact virtual bool OnTimer(int timerId, int arg0, int arg1), moves the complete class/inline/member declaration from formal CPP to formal H, preserves those UID000415 chat-history declarations and field, replaces the five-byte movement array and two-byte history array with size-neutral named reply/direction/timer-family fields, retains sizeof(UserPane)==0x13eb84, and routes the sole complete OnTimer definition through the exact child into UserPane.cpp.
```

### Manual mutation M03 - replace UID0000P1 by-file row

Applied exact replacement row, preserved literally for audit; bounded `F203FD4C...0210B` readback is by-file line 299:

```text
- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 93% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, signed plain-char StartDirectionalAnimation(char direction) with signed-short MonsterObject frame-duration image-table/group/frame path, signed non-monster scaled-delay arithmetic, event-20 scheduling, branch-specific ordering, and branch-local MapPane refresh, corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior, preserved action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence, source-ready opcode-0x0f ParseInventorySlotUpdatePacket using signed one-based slots, three explicit ACP text conversions, the exact 508-byte inventory record with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, active UserStatusPane slot-count bound, exact write order, and preserved invalid-slot/always-false behavior, source-ready opcode-0x08 settings parsing with exact state indices, 2/31 offset arithmetic, packet cursor/store order, blindness invalidation, movement-state/TryStepForward order, ten ordered direct config stores, SoundManager enable/mirror order, active GeneralPurposePanel child-6 OnActivate refresh, and adjacent movement-reply index-3 versus index-4 corrections, source-ready opcode-0x05 HandleServerEntryPacket with duplicated EPF/legacy SpelledPane refresh, sender re-enable, transfer-overlay deferred deletion, object/facing/status-icon application, MapPane bounds refresh, and block/listen replay, plus exact HandleKeyOrTextEvent(Event *) entry gates/modifier and key switches/handled returns/packet order and source body, two slot-range methods, opcode-7 sender, current B002 UID0004R9 preservation, target-selection cross-TU declarations, compiler switch/vtable exclusions, retained raw/inline-equivalent history, exact source order, no UID0003V9 empty emitter or duplicate body, UID0003UB's exact source position, three-page caller route, 30-row Text/Spell/Item behavior, helper/packet dependencies, retained UID0000FQ emitter route, complete Config table declarations, exact retained UID0003UA compact-shortcut source, and exact final-byte plus 68-byte m_currentAppearance tail used by MapPane; UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; retains exact private IsGroupMember and AdvanceMovementSendTick definitions with class closure, source order, and compiler exclusions; adds typed +0x3cb1 hunters-list flag, +0x3cb2 wchar_t[256] party-search source text, two residual bytes, and inline accessors without changing the 0x13eb84 layout or any prior source union fact; exposes the inline const GetSpellPromptText(char) source accessor for cross-TU spell prompt consumers without changing the SpellCommandSlotRecord layout, object size, generated route, or any existing UserPane behavior; exact UserPane +0x210 active LineInputPane pointer and inline ClearActiveLineInputPane(), with UID00035P typed constructor publication, UID00035Y/UID000364/UID00036C and derived-handler clears, all later offsets and the complete 0x13eb84 union preserved; historical pending-target ObjectPane wording is rejected for current source because no ObjectPane pointer is ever stored in the slot. The callback adds the exact ClearDeferredUserListPacket definition in source order; it frees and clears pointer/count/deadline only, preserves size and active state, is called by UID0003TY after the transition send, and leaves the complete current UserPane union unchanged; adds exact externally linked EnsureNormalBulletinSession at 0x005a50a0-0x005a5103 with four IconsPane/UserPane callers, null guard, source new BulletinSession(1, 0, false), exact hash/padding, UserPane-local-player helper placement, and no change to UserPane class layout or any existing shared source fact. UID0003ZT commits ui/panels/UserPane.h/UserPane.cpp factoring for the complete UserPane declaration and g_pUserPane/g_pInputBlockerPane extern declarations consumed by MapPane; existing emitter pages retain the sole definitions. UID000415 keeps the exact GetPreviousChatHistoryLine, GetNextChatHistoryLine, and SaveChatHistoryLine definitions at 0x005a4930, 0x005a4990, and 0x005a49e0 in UserPane.cpp, with canonical g_pUserPane callers, m_chatHistory +0x13eb04, signed-short cursor wrap, bounded wide copies, newest-boundary empty result, duplicate suppression, ten-line cap, and unchanged adjacent recipient-history state. UID0003VD supplies the exact bool UserPane::OnTimer definition in UserPane.cpp, with local event 20 and FWdA four-substep movement, named reply/direction state, MapPane warp/scroll, linked-object propagation/synchronization, and FAnD/default base delegation, while the complete class declaration and inline members move to UserPane.h and all UID000415 chat-history declarations, definitions, field ownership, callers, and behavior remain preserved.
```

### Manual mutation M04 - replace UID0003Z7

Applied exact replacement row, preserved literally for audit; bounded `DDB43AB5...EAFAE2` readback is by-memory line 2801:

```text
        - [UID:0003Z7][0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers](by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md) 0x0053bec0-0x0053c367 | method cluster | LivingObjectPaneLinkedPositionAndModeHelpers : reconstructable : 91% : very-strong : Complete linked-position and mode source with exact LivingObjectPane::ScheduleBoxRotationStep, SyncPositionToLinkedObjects, and PropagateLinkedObjectMode contracts, the compiler-generated UserPane adjustor thunk, exact linked-pane traversal and invalidation order, current helper callers, and UID0003VD local-event/FWdA call roles.
```

### Manual mutation M05 - insert UID000427

Applied exact insertion row, preserved literally for audit; bounded `DDB43AB5...EAFAE2` readback is by-memory line 2363 immediately before UID0002QL at line 2364:

```text
        - [UID:000427][0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll](by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md) 0x005055e0-0x00505645 | MapPane member | MapPaneApplyMovementSubstepScroll : reconstructable : 88% : very-strong : Exact source-ready bool MapPane::ApplyMovementSubstepScroll(unsigned char direction) body with direction-to-tile-offset conversion, signed movement-scale division, viewport-pixel update, invalidation, complete bytes/boundaries, and UID0003VD FWdA substep callers.
```

### Manual mutation M06 - replace UID0003U7

Applied exact replacement row, preserved literally for audit; bounded `DDB43AB5...EAFAE2` readback is by-memory line 3804:

```text
        - [UID:0003U7][0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation](by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md) 0x005a36f0-0x005a3766 | UserPane member | UserPaneInitializeWalkAnimation : reconstructable : 92% : very-strong : Exact 118-byte one-block, four-call UserPane walk-animation initializer; clears movement-reply/direction-delay state through ClearMovementReplyState and SetDirectionDelayActive(false), sets moving/facing/frame state, cancels FBSA, schedules FWdA through the inherited TimerHandler using display-status byte divided by signed movement scale, refreshes MapPane object screen bounds, and supplies the continuation path consumed by UID0003VD OnTimer.
```

### Manual mutation M07 - replace UID0003UP

Applied exact replacement row, preserved literally for audit; bounded `DDB43AB5...EAFAE2` readback is by-memory line 3840:

```text
        - [UID:0003UP][0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket](by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md) 0x005ab090-0x005ab410 | UserPane member | UserPaneHandleMovementReplyPacket : reconstructable : 92% : very-strong : Exact opcode-0x0b UserPane movement-reply member with signed BE16 coordinates, capability/config gate asymmetry through direct unsigned-char Config::m_mapMovementStatusOption, authoritative and predicted correction paths, named m_movementReplyPending/m_movementReplyReceived/m_movementReplyCount state, m_movementReplyTimerFamily selection, exact event-20/FWdA timer behavior, free DirectionToTileOffset with MapPoint row/column semantics, branch-exact MapPane recenter/bounds updates, null-safe pending-timer removal, 16-byte movement-history reconciliation, one real dispatcher caller, retained UID0000FQ owner/emitter and UserPane.cpp route, and complete source-clean formal C++.
```

### Manual mutation M08 - replace UID0003UQ

Applied exact replacement row, preserved literally for audit; bounded `DDB43AB5...EAFAE2` readback is by-memory line 3841:

```text
        - [UID:0003UQ][0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket](by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md) 0x005ab410-0x005ab75d | UserPane member | UserPaneHandleExtendedMovementReplyPacket : reconstructable : 92% : very-strong : Exact opcode-0x26 extended UserPane movement-reply member with signed BE16 coordinates, capability/config gate asymmetry through direct unsigned-char Config::m_mapMovementStatusOption, distinct branch-local recenter and event-delay behavior, named m_movementReplyPending/m_movementReplyReceived/m_movementReplyCount state, m_movementReplyTimerFamily selection, exact event-20/FWdA timer paths, free DirectionToTileOffset with MapPoint row/column semantics, MapPane bounds updates, null-safe pending-timer removal, 16-byte movement-history reconciliation, one real dispatcher caller, retained UID0000FQ owner/emitter and UserPane.cpp route, and complete source-clean formal C++.
```

### Manual mutation M09 - replace UID0002YU

Applied exact replacement row, preserved literally for audit; bounded `DDB43AB5...EAFAE2` readback is by-memory line 4454:

```text
        - [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md) 0x0062ef0c-0x0062efcc | compiler vtable/RTTI data | UserPaneVtableData : ignored : 90% : very-strong : Exact UserPane vtable family with constructor/destructor references, EventHandler key/text slot 0x0062ef98, TimerHandler OnTimer slot 0x0062efc4 pointing to UID0003VD with complete-object +0xa4 facet adjustment, sibling virtual slots, compiler-generation proof, and blank no-raw-array formal disposition regenerated from the complete UserPane header declaration.
```

### Evidence-backed manual no-op dispositions

| Disposition | Exact post-application row/anchor evidence | Reason no mutation was needed |
| --- | --- | --- |
| N01 UID0003Z3 | Bounded `DDB43AB5...EAFAE2` line 2782 remains `88% : strong` with exact direction-remap behavior. | Verified no-op; no mutation was needed. |
| N02 UID0002R1 | Bounded `DDB43AB5...EAFAE2` line 2795 remains `88% : strong` with inherited `OnTimer`, adjusted TimerHandler ABI, timer-family behavior, callers, and declaration integration. | Verified no-op; no mutation was needed. |
| N03 UID0002QL | Bounded `DDB43AB5...EAFAE2` line 2364 remains `87% : very strong` with source-ready viewport-scroll, direction remap, MapPoint, ObjectList shift, and refresh behavior. | Verified no-op; it does not encode the corrected formal argument order. |
| N04 UID0003U8 | Bounded `DDB43AB5...EAFAE2` line 3806 remains `92% : very-strong` with signed direction, event 20, scaled delay, branch order, and MapPane refresh. | Verified no-op; it contains no stale helper or raw-array wording. |
| N05 UID0003UE | Bounded `DDB43AB5...EAFAE2` line 3816 remains `88% : strong` with complete movement/viewport warp behavior and twelve xrefs. | Verified no-op; named-field synchronization does not stale the row. |
| N06 UID00027F | Bounded `DDB43AB5...EAFAE2` line 4501 remains `90% : very-strong` with exact byte/value, reads, signed extension, arithmetic, route, and formal disposition. | Verified no-op; UID0003VD changes no scale claim. |

No manual tracker edit is permitted. The validator-generated research tracker updates only through validator/generated/report lifecycle handling. M01-M09 are applied, N01-N06 are verified no-ops, and commands `000000020166` through `000000020168` validate the three changed manual coverage files.

## Follow-Up Actions

1. Gate 1 passed exact pre-callback report SHA256 `E4FF23A504914BE38DF394DDB3CD3C669BC0960B3BAC2A2A1A2A643D3493614A`.
2. Same-agent ordinary implementation for C001-C105 and C222-C223 is complete; all 17 changed ordinary destinations were leased briefly, validated serially with `--no-generated-refresh`, hashed, and released. The later accepted C070 callback reacquired only UID0003Z7, inserted the literal `UserPane::PropagateLinkedObjectMode(int mode)` name, passed scoped validator `000000020142`, and immediately released the lease.
3. The later supervisor Gate 2A pass accepted 214/223 claims and identified nine synchronization defects. B005 repaired C067/C069/C071/C073 in UID0003Z7, C076 in UID0003Z3, C081 in UID0002R1, C083 in UID000427, C087 in UID0002QL, and C104 in this report. The five ordinary destinations were leased one at a time, validated serially through commands `000000020356`-`000000020360` with generated refresh disabled, hashed, and released; UID00027F required no edit because its existing page already proves signed-consumed plain `char` and rejects `unsigned char`. The next exact-artifact audit passed 28/33 Gate 1 rows and 209/223 Gate 2A claims, returning only 14 moving-coverage-currentness rows. This report-only repair reconciles C106/C208/C209-C220 plus their shared class/file context to bounded SHAs `DDB43AB5...EAFAE2`, `34287BEF...7E2C1`, and `F203FD4C...0210B`; literal rows remained exact, so no coverage or ordinary mutation was needed.
4. Supervisor Gate 2B applied and independently verified F1-F9/C1/T1 against exact B180 prestate, preserved all protected entities, and saved once at dated CF18895C poststate; the fresh saved-IDB `B7CC899D...58277` readback reconfirms that complete target/protected result without drift. The Gate 2A repairs document this already-applied state and do not alter IDA or formal CPP/H.
5. Supervisor applied M01-M09, verified N01-N06, and validated by-memory/by-class/by-file coverage with commands `000000020166`, `000000020167`, and `000000020168`.
6. Dated supervisor command20172 generated-refresh evidence records one complete UserPane header definition, blank class CPP ownership, one UID0003VD body, no old/raw names, no duplicate definition, and no target empty/no-code marker. For any later transition, generated topology is verified from the then-current generated command metadata and physical artifacts rather than inferred from this dated checkpoint.
7. Gate audits, final claim verification, and report execution/archive actions are supervisor-owned. Their state is authoritative only from the artifact's current path, the exact-artifact audit matching that revision, and validator-owned status/history metadata.

Reusable transition hard stops: any drift from the target/protected state reconfirmed at saved IDB `B7CC899D...58277`, UserPane size/member/neighbor drift, `LineInputPane` completeness/size drift, missing TimerHandler vtable cell, generated raw-name/adjusted-pointer regression, duplicate definition, or failed exact-revision validation/audit. CF18895C remains the dated transaction poststate rather than later-current authority.

## Confidence

Overall recommendation confidence is very strong (`94`). Direct binary evidence proves method identity, ABI, branch behavior, fields by offset/width, helper calls, boundaries, return behavior, and source ownership. Existing current docs prove the subsystem names and compile-visible routes. Confidence is below 95 only for stripped private lexical spellings, especially the constructor-clear/target-set flag and otherwise-unused adjacent state bytes. Those uncertainties are explicitly represented as inference and do not change runtime behavior.

## Validator Results

The accepted ordinary callback ran every scoped validator serially from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file`, the exact relative path in the table below, and `--apply --queue-timeout 240 --no-generated-refresh`. Every command exited `0` with `ok: 1`; every command explicitly skipped generated refresh and performed only validator-owned scoped application/projected-stat bookkeeping. During that dated ordinary callback, B005 ran or probed no report-lifecycle command.

| Command | Timestamp | Exact relative path | Result | Warnings / side effects |
| --- | --- | --- | --- | --- |
| `000000019997` | `2026-07-30T12:18:33-04:00` | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` | exit `0`; `ok: 1`; `94/94` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020001` | `2026-07-30T12:20:29-04:00` | `by-class/UserPane.md` | exit `0`; `ok: 1` | pre-existing `missing_ref_uid: 5`, including `0003V8` and `0003VC`; generated skipped; projected stats update/incremental no-op |
| `000000020003` | `2026-07-30T12:21:57-04:00` | `by-file/UserPane.md` | exit `0`; `ok: 1` | pre-existing `missing_ref_uid: 18`, including `0003V8`, `0003JN`, `0003VC`, and `0003J2` with 14 additional suppressed entries; generated skipped; projected stats update/incremental no-op |
| `000000020004` | `2026-07-30T12:22:24-04:00` | `by-file/InputPanes.md` | exit `0`; `ok: 1` | pre-existing `missing_ref_uid: 24`, including `00035Q`, `00035T`, `00035U`, `00035V`, `00035W`, `00035X`, `00035Z`, `000360`, `00036D`, and `00036E` with 14 additional suppressed entries; generated skipped; projected stats update/incremental no-op |
| `000000020005` | `2026-07-30T12:22:54-04:00` | `by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020006` | `2026-07-30T12:23:26-04:00` | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020007` | `2026-07-30T12:24:19-04:00` | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020008` | `2026-07-30T12:24:47-04:00` | `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020009` | `2026-07-30T12:25:27-04:00` | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` | exit `0`; `ok: 1` | pre-existing `missing_ref_uid: 3`: `0003Z8`, `0003Z9`, `0003Z8`; generated skipped; projected stats update/incremental no-op |
| `000000020010` | `2026-07-30T12:26:09-04:00` | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020011` | `2026-07-30T12:26:56-04:00` | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020012` | `2026-07-30T12:27:39-04:00` | `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020013` | `2026-07-30T12:28:11-04:00` | `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020014` | `2026-07-30T12:28:43-04:00` | `by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020015` | `2026-07-30T12:29:22-04:00` | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020016` | `2026-07-30T12:30:00-04:00` | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020017` | `2026-07-30T12:31:18-04:00` | `by-file/UserPane.md` | exit `0`; `ok: 1` | final revalidation after named-field prose synchronization; same pre-existing `missing_ref_uid: 18`; generated skipped; projected stats update/incremental no-op |
| `000000020018` | `2026-07-30T12:31:48-04:00` | `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` | exit `0`; `ok: 1` | no warnings; generated skipped; projected stats update/incremental no-op |
| `000000020142` | `2026-07-31T01:53:36-04:00` | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | exit `0`; `ok: 1` | C070-only callback; no warnings; `generated_refresh: skipped`; `projected_stats_update: 1`; `stats_incremental_noop: 1` because UID0003Z7 is absent from generated stats lists; validator-owned projected-path-completion bookkeeping only |
| `000000020166` | supervisor callback; exact timestamp validator-owned and not reproduced in this report | `by-memory/-coverage-report.md` | exit `0`; `ok: 1` | M01 and M04-M09 applied; N01-N06 verified exact; post-validation SHA256 `F470880A233CB61ACC3227910478A6F22147B4B65A014FCCBCD0237D7DADA3F7`; no generated refresh was attributed to B005 |
| `000000020167` | supervisor callback; exact timestamp validator-owned and not reproduced in this report | `by-class/-coverage-report.md` | exit `0`; `ok: 1` | M02 applied; post-validation SHA256 `9B8B77532BAA43613618BCB3275E9E9D6668EADA1A499F154ACAC18B3DAF5033`; no generated refresh was attributed to B005 |
| `000000020168` | supervisor callback; exact timestamp validator-owned and not reproduced in this report | `by-file/-coverage-report.md` | exit `0`; `ok: 1` | M03 applied; post-validation SHA256 `5704439FC3EA94C4A3568B1E5712C30ADD1E77BCDA21B0808AFBDE7C3AFA223B`; no generated refresh was attributed to B005 |
| `000000020172` | dated supervisor generated-refresh checkpoint; exact timestamp remains validator-owned | `auto-generated/NexusTK/ui/panels/UserPane.cpp`, `auto-generated/NexusTK/ui/panels/UserPane.h`, and `auto-generated/-ag-memory-coverage.md` | generated refresh completed | `UserPane.cpp` SHA256 `C0F90A56764C9F6EB5B0698B2C642E6812EC5C26B137D9CA271D20B7FED1A3E0`, 87,909 bytes / 2,670 physical lines; `UserPane.h` SHA256 `A98F4CCD8FDA2C102125D4743AC5202DBAC06519EE48E2584A594A4860492117`, 11,298 bytes / 334 physical lines; generated memory SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`; one UID0003VD `OnTimer` definition, one H declaration, no `OnAnimationStep`, and no UID0003VD empty/no-code marker |
| `000000020356` | `2026-07-31T07:32:07-04:00` | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | exit `0`; `ok: 1` | Gate2A repair for C067/C069/C071/C073; no warnings; `generated_refresh: skipped`; validator-owned projected-stat bookkeeping only |
| `000000020357` | `2026-07-31T07:32:43-04:00` | `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | exit `0`; `ok: 1` | Gate2A repair for C076; no warnings; `generated_refresh: skipped`; validator-owned projected-stat bookkeeping only |
| `000000020358` | `2026-07-31T07:33:25-04:00` | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` | exit `0`; `ok: 1` | Gate2A repair for C081; pre-existing `missing_ref_uid: 3` (`0003Z8`, `0003Z9`, `0003Z8`); `generated_refresh: skipped`; validator-owned projected-stat bookkeeping only |
| `000000020359` | `2026-07-31T07:33:57-04:00` | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` | exit `0`; `ok: 1` | Gate2A repair for C083; no warnings; `generated_refresh: skipped`; validator-owned projected-stat bookkeeping only |
| `000000020360` | `2026-07-31T07:34:23-04:00` | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` | exit `0`; `ok: 1` | Gate2A repair for C087; no warnings; `generated_refresh: skipped`; validator-owned projected-stat bookkeeping only |

For C070, `python .\leaser.py B005 lease 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md'` returned `Success` immediately before the edit. After command `000000020142` and the exact post-validator hash readback, the corresponding `unlease` command returned `Success`. The Gate2A repair likewise used one short lease per affected ordinary page, with each corresponding `unlease` returning `Success` immediately after commands `000000020356`-`000000020360`; bounded current lease-report searches found zero residual entries for all five destinations.

Command `000000019993` remains a dated pre-callback generated CPP/H, `-ag-memory-coverage`, and tracker checkpoint: `UserPane.cpp` SHA256 `ECBAF73497F0C19C4BEC6A42615136070D1361B8309966D1292F4507EC047DE3`, 93,067 bytes / 2,810 lines; `UserPane.h` SHA256 `F1092DABAB6F93140A5519BD9478A9C706DE69F8D13A28D29690B06964899D6D`, 482 bytes / 8 lines; generated memory SHA256 `4F54811E022C0EEED7E77BF85AFFBF36B25E7E97A41BD9E20878C148A4393C5F`, 1,420,185 bytes / 4,950 lines; and tracker SHA256 `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`, 1,679,725 bytes / 6,634 lines. B005 did not run command19993.

Generated evidence is read-only physical state, not an agent-run validator result. Validator command `000000020104`, refreshed `2026-07-30T15:18:49-04:00`, is dated history with `UserPane.cpp` SHA256 `6A20BC8C1B8861BC7251CFC4290EDBF038391078CF3181B10F0F74AF5F0AF06E`, `UserPane.h` SHA256 `6CAADD22492FE1D21F4A20797F05BE5102DF5676A47D0C3F324D737540ED3B16`, generated memory SHA256 `BEE343EC97DE3987E641442D6A142B7792482295E12BAA8AEFE02471A484BF12`, and tracker SHA256 `784D99B4A4C01C389EBBA2C057E636CC88BEADC9EF452E2FC71F3B103F9280CF`. Command `000000020109`, refreshed `2026-07-31T01:02:54-04:00`, is a dated matching generated checkpoint for `UserPane.cpp` SHA256 `5499F76A0CF17A88891AD2B98957E4FFCD126F02D5370ED78F318232F6B5DA2A`, 87,909 bytes / 2,670 lines; `UserPane.h` SHA256 `956B6A372C4F26E0E237E3C196586FAFDFC4A0BFD72C1C06ED1AE2F6A14E9B9F`, 11,298 bytes / 334 lines; and generated memory SHA256 `027FB7FD6E725B3433B4E3ACA0C0801CF1CC1D6F5F625C96FA5026207F4B8D9F`, 1,421,254 bytes / 4,953 lines. Command20109 tracker SHA `706757C06C971EE12553F07CBE68178BCD73153AFA74CD7375B24A369332B342`, size/line count, and row position are dated tracker history. The bounded post-command `000000020160` moving tracker readback is likewise dated evidence: SHA256 `CF8C778FCA2A2F9F4D0DF55D6710B5770F8994C74E45C663EDCD9280688ACA3B`, 1,685,974 bytes / 6,658 lines, with UID0003VD then at line 3431 as `94/94`, reconstructable, and `0/0/0`; later tracker truth is authoritative from the physical artifact and validator lifecycle metadata. Commands `000000020024` and `000000020034` and their identities remain dated history. B005 ran none of those generated-refresh commands and ran scoped C070 validator command `000000020142` with generated refresh disabled. Dated supervisor command20172 is the later generated checkpoint recorded in the table; it verifies the required topology at that revision but does not claim permanent currentness. Generated-currentness verification and report lifecycle state for any transition remain supervisor-owned and authoritative from then-current physical artifacts, exact-revision audits, and validator-owned metadata.

The pretransaction shared-IDB rebinds were read-only evidence checks, not validator commands. Pre-maintenance MCP session `07b29e1b` established that all F1-F9/C1/T1 and protected-state properties, collisions, fences, vtable cells, and bounded decompile constraints matched dated physical IDB SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94`. Post-maintenance session `f608d7c2` reconfirmed those target-local facts. Its dated A0 pass used bounded `server_health`, `lookup_funcs`, `stack_frame`, `get_comments`, `get_bytes`, `xrefs_to`, and `type_inspect`; its dated F7 pass used those bounded tools plus exact-name collision queries and ten `decompile` calls against saved IDB SHA256 `F7C936C072D1332D82D06A92F89F3531D97EE8D9252A2C3C6325B2580F8D7D8A`, 143,192,467 bytes, saved `2026-07-30T14:56:51.3756829-04:00`. At that dated F7 checkpoint every function/protected entity, physical frame, Hex-Rays inventory, entry/internal comment, byte hash, xref, boundary, vtable cell, and collision disposition matched; UserPane was then `0x13eb84`/60 members and complete `LineInputPane` size `0x108` had already superseded A0's incomplete-type observation. The supervisor transaction used exact prestate and backup SHA256 `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`, applied F1-F9/C1/T1, independently read back all mutable and protected properties, and saved once to dated SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, at `2026-07-31T03:00:53.6024151-04:00`. Intervening saved-IDB identities `4B5F...A696A`, `1BC3...0CFD`, and `5F2679A7...79A21` are also dated history. The fresh repair pass against saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`, reconfirmed all 11 handoff entities and three protected functions with exact names, types, four entry-comment channels, complete physical frames, byte hashes, xrefs, ranges, boundaries, fences, vtable cells, and successor. It also reconfirmed UserPane `0x13eb84`/68 members, complete `LineInputPane` size `0x108`, TimerHandler size 4/one member, and MapPane `0x910`/69 members; F1/F7 `timerId` and `arg1` plus F9 `mode` render physical `signed __int32`, F1/F7 `arg0` renders `int`, F1's local renders `struct MapPoint`, and F8 retains `mode@0x8:0x4:int`. All 132 literal internal-comment addresses enumerated in this report matched with zero text/channel mismatch. `A0D97FC5...4375971`, `4A9360D1...A2526C94`, `DAA59745...7462C17`, F7, B180, CF18895C, 4B5F, 1BC3, 5F, and older identities are dated checkpoints. B005 performed no IDA mutation/save during this report-only reconciliation.

## Changed Files

The accepted callback modified the following existing ordinary documents; no ordinary file was created, renamed, split, or moved. The table preserves exact pre-callback to dated post-validator callback-output identities. It is implementation history, not a claim that every listed post-validator hash remains the latest physical identity after unrelated additive work.

| Claims | Path | Pre SHA256 | Post SHA256 | Post bytes / lines | Final validator |
| --- | --- | --- | --- | --- | --- |
| C001-C031 | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` | `914D596B987E90E51C8F23833530CCB10F8B9673104F3588C47BC8995A8F2240` | `982712A99F4A269DB4E507BED8732F24C0C0EEE3FB1C401A1BCEF3B5A57C4890` | 24,131 / 341 | `000000019997` |
| C032-C037, C039-C055, C222-C223 | `by-class/UserPane.md` | `DB7867530A0DC231BC7DB350BD079858BBF88CEF8C90A2E35556DDA8AED97578` | `C7873624784664FFBE29D91B441AD9FB03D7FDFE2E8ED4A68211195E32D1BFB9` | 111,196 / 814 | `000000020001` |
| C056-C057, C059-C060 | `by-file/UserPane.md` | `54A260E46F9E452904B6D9E6ED01DF5D0656435DF333C2C1172300BBA1C7781B` | `512BA4D0D75124D014DFE908DD6EAFE668DFF298D69F0A010227977624E4CA33` | 121,010 / 508 | `000000020017` |
| C058 only | `by-file/InputPanes.md` | `59E1BE61AEF5E8B87E145F391E0EB5D38BD4AB1DAB75D4C200F1309C5FFCCE64` | `77948F03FB4268780D43BB634843D556CE60093421F77ABB978B7E6354495227` | 27,985 / 162 | `000000020004` |
| C038 only | `by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md` | `7E38D85A46E69F3C0E868E989A2DC64906DCB9ADDD9D11552C562B6E93286D61` | `69F010C8E48EA4F9E19532D2A034FEC635BDE36642B9F714A2D795C84C14BA76` | 8,172 / 101 | `000000020005` |
| C061-C065 | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` | `E03C307EE199F98B31B418771C1F9FAF95BC98C42171D7570F80C68758A52947` | `C814CC898DF0C0900DFAEB9AC3B861F6F6E66A184B1DCA13104BFEDCADCCBCBE` | 6,070 / 71 | `000000020006` |
| C066-C069, C071-C074 | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `23A30A208DD046B49284E9CDF33A9B7D5C36CD3BABEA6AF4362A9A26AF868B6C` | `E34ECC95F38FD76E8C11B85B93AE9880CDD1734244E2261AF045BDE315297C8E` | 10,652 / 165 | `000000020007` |
| C070 accepted callback | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `E34ECC95F38FD76E8C11B85B93AE9880CDD1734244E2261AF045BDE315297C8E` | `533703A9932195F9718BD4CD0283A2E91440750D75BB12DC783A871D35ABE9B1` | 10,699 / 165 | `000000020142` |
| C075-C077 | `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | `342BE81E7B8D04BF7752021C9C7A1D19B57832CC18180262891BD99C354DFE0C` | `67A1B9364D3490555ABA3543A3E202B9E33193C61ABD33A89B5E3C50CE010CDD` | 19,823 / 258 | `000000020008` |
| C078-C081 | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` | `EF08B5869E4D77B5B2FD928879375994C0B45883D2191BFD93925628C31DA372` | `D5B9A16162DFC784BA7BE6FFA4952B9F91D5C7D6397F226837BC94912BBE5CD9` | 29,328 / 329 | `000000020009` |
| C082-C084 | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` | `32FCB9802FDDEE743EF9EBF083E86E028E24167C6F372B8072A63EEF1250C4A7` | `1D00B3821EEAC8B67DC75753563767EAB51B7A77FFB28552B9B936A0A44DA87B` | 6,852 / 66 | `000000020010` |
| C085-C089 | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` | `716EB2C00547B187CC25E48073E86FC8026693A930BE55F31C5FD646CFE22B4E` | `06A84C90FFCEFA5A4FB79517AFB3DBE89186F30FAA481B584B2959FCC85305D9` | 13,036 / 138 | `000000020011` |
| C090-C093 | `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md` | `B34DBA294CFFE7F4109826D801AE9DCC7EBA0FB56C8EE7C819359AC855ADCEF7` | `66B5D738F534843D5A180809BC322880D425A5038748BE47B7272FD2FB17EE90` | 14,951 / 128 | `000000020012` |
| C094-C097 | `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` | `276E927576FEC402C9F03659511F24FCDF5A2557228770464D3D31456618AEC0` | `5DA638BEC813B5A2D0B6A15312EE0BBB838B01595586AD6352A5B5C5C2F2B91D` | 15,059 / 145 | `000000020013` |
| C098-C099 | `by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md` | `26B90E49BD30E2A8F61C9BD6EFF66EF324E29640C998FDFB40F5939447EAE75E` | `58BD8B61892CC9BBBBF814C87B1FCBE2D0CF08C118AE0A626012DF9C43B9A555` | 15,769 / 130 | `000000020014` |
| C100-C101 | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` | `041A7C759A05A4E904855183AF29B58C1CABB780A6ACC93AF84650319204515D` | `4532A43BCB855DC91FD3A5D6DB0549EF50866B62821AD988C4DE0FC9F85F4A94` | 18,671 / 231 | `000000020015` |
| C102-C103 | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` | `7724A046E319FB6DA475BCAB68EED3609139097D337A6DD5E554FF74296D176E` | `C91F143CA78EB3DD663C70DA5A7E1FC92BCB1F7606E3FE0D0F722F11416C7C4C` | 20,658 / 239 | `000000020016` |
| C104-C105 | `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` | `0B8C6692C797A370AF78A5337268A7ACF8C4C50868C896D578E6BCD1BADA8CFF` | `28EACB0A88C1EA4750BA0F678FA78D7B0F9E20AE2F019A1ECA652BB2A7E5337E` | 18,224 / 132 | `000000020018` |

Gate 2A repair layer (the callback rows above remain exact dated history):

| Claims | Path | Pre-repair SHA256 | Post-repair SHA256 | Post bytes / lines | Repair validator |
| --- | --- | --- | --- | --- | --- |
| C067, C069, C071, C073 | `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `533703A9932195F9718BD4CD0283A2E91440750D75BB12DC783A871D35ABE9B1` | `3A78A43AFE75182E3FEC0AC6D858F8847C764C2193DC1BE8F53CF27390A97986` | 12,626 / 165 | `000000020356` |
| C076 | `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | `67A1B9364D3490555ABA3543A3E202B9E33193C61ABD33A89B5E3C50CE010CDD` | `8CA64FE28E8217ED0A5F9D40A7151902BC87F4360B7667711DAD1A457D03C0E9` | 20,661 / 258 | `000000020357` |
| C081 | `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` | `D5B9A16162DFC784BA7BE6FFA4952B9F91D5C7D6397F226837BC94912BBE5CD9` | `3C953986231A4407CF68BF6FB9E84ACCA314DA1E428C2FA5C98AFE4E71118293` | 30,031 / 329 | `000000020358` |
| C083 | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` | `1D00B3821EEAC8B67DC75753563767EAB51B7A77FFB28552B9B936A0A44DA87B` | `AD2D53F19B9F1F509F0CA4CE6A48CBC13B8D83EB45450BA1E2DCD3EBEA03FF30` | 7,729 / 66 | `000000020359` |
| C087 | `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` | `06A84C90FFCEFA5A4FB79517AFB3DBE89186F30FAA481B584B2959FCC85305D9` | `C033099F6EBFEA699204996707DA90363D20D1E95A0D5DD683348C710CF1AD3B` | 13,606 / 138 | `000000020360` |

This same report was reconciled additively without pruning its 223-row ledger. C001-C105 and C222-C223 reflect completed ordinary implementation; C067/C069/C071/C073, C076, C081, C083, and C087 point to the five Gate2A-repaired destination identities above, while C104 matches UID00027F's already-present signed-consumed plain-`char` evidence and rejects unsigned. C106 and C207-C214 record the nine applied manual rows; C215-C220 record the six verified exact no-ops; commands `000000020166` through `000000020168` are dated application validation. C116-C165 record the applied F1-F9/C1/T1 transaction, while C166-C206 retain the exact protected no-change readbacks. Exact prestate/backup SHA256 is `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`; the one saved transaction poststate is dated SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, saved `2026-07-31T03:00:53.6024151-04:00`. The fresh saved-IDB `B7CC899D...58277` readback reconfirms all nine names/types/comments/frame normalizations, C1's sole regular-comment change, UserPane `0x13eb84`/68 members, F1/F7 `timerId` and `arg1` plus F9 `mode` as physical `signed __int32`, F1/F7 `arg0` as physical `int`, F1 `struct MapPoint`, and F8's materialized `mode@0x8:0x4:int` row. Catalog0383/B7 Gate2B closure remains unchanged; these ordinary repairs document that applied state without altering IDA, formal CPP/H, ownership, ranges, scores, generated topology, or manual coverage. The callback table remains exact dated implementation history. In the bounded ordinary union, UID0003Z7, UID0003Z3, UID0002R1, UID000427, and UID0002QL match the Gate2A repair table; unaffected destinations match their applicable callback or later additive identities. UID0003UP is SHA256 `BF4B49512098A4A61F2DEEF663913ED4BB02F5C468719F32BED2DBD3F59E51A9`, 19,264 bytes / 236 lines, and UID0003UQ is SHA256 `4FD119A21891D95A0ABEBB5F33A52567CA2D56EEE047F7FA095C6CE84C1E3653`, 21,261 bytes / 244 lines. Their dated B005 callback-output hashes `4532A43B...F4A94` and `C91F143C...C7C4C` remain in the table because later additive edits preserve all B005 detail rather than replacing callback history. The shared owners are bounded checkpoint identities `by-class/UserPane.md` SHA256 `4784B20F4C8535CDE637223AC3B5360D8B79276CF3190F14DD7C423604BCE6D8`, 111,710 bytes / 815 lines, and `by-file/UserPane.md` SHA256 `8A534098EC3F32D46D6DDE40AEF9E1094055BBEF7B32B350B55218954308D772`, 121,808 bytes / 510 lines; B008's additive UID00035P reconciliation preserved all UID0003VD OnTimer/formal/layout/source/history claims. Command20109 and command20172 are dated generated checkpoints; command20172 records the later exact valid topology without serving as permanent authority. Manual identities `F470880A...A3F7`, `9B8B7753...5033`, `5704439F...223B`, `6C2C8B45...741B7`, `E71703BB...4126`, and `5CDCBB4B...53FF` are dated history. The bounded repair checkpoint is by-memory `DDB43AB5B6B22EE411536C9A470847389C42CC3CB4EDC159D0BF509173EAFAE2`, 2,121,961 bytes / 4,790 lines; by-class `34287BEF3C9E700199102050F52BCA1C87189863E3A977C16021783D8027E2C1`, 274,255 bytes / 625 lines; and by-file `F203FD4C148CE2192868B4CBE8C1E094C50F438548977C885FF378D78F90210B`, 165,800 bytes / 318 lines. M01-M09 and N01-N06 exact anchors are recorded in the manual section and remain semantically exact; these moving hashes and positions are not asserted as permanent. During this coverage-currentness repair B005 edited only this same report; ordinary docs, IDA, coverage, generated/tracker, audit/catalog/goal/notes/lifecycle, and validator state were not edited. Generated-currentness checks, exact-artifact audits, and execution/archive state are supervisor-owned and authoritative only from the then-current artifact path/revision, matching audit, physical generated artifacts, and validator-owned status/history metadata.

## Implementation Tracking Checklist

Report-only Gate 1 preparation:

- [x] Read current assignment, project skill/reference/template, target, owner/file, vtable, timer, movement, MapPane, global, successor, generated, tracker, coverage, and matching executed-report leads.
- [x] Verified exact target range, target/helper bytes, fences, vtable route, callers/callees, comments, decompile constraints, UDTs, and collisions through the dated F7 pretransaction checkpoint `F7C936C0...F8D7D8A`; separately recorded every literal name/offset/size/type/role physical-frame item for F1-F9/C1 and the three protected functions plus every dated-pretransaction/expected Hex-Rays argument/local storage, width, type, role, and local-user-comment state for F1-F9/C1. Supervisor preflight at exact B180 matched all mutable/protected prestates and collision absences; independent transaction readback matched the applied F1-F9/C1/T1 state and every protection before the single CF18895C save. The fresh saved-IDB `B7CC899D...58277` pass reconfirmed all 11 handoff rows, all protected rows, all UDT dependencies, and all 132 literal internal-comment addresses without drift. Dated A0 recorded the prior incomplete LineInputPane state.
- [x] Resolved `OnTimer`, event 20, adjusted receiver, movement fields, all assignment-named helper signatures, source placement, formal CPP/H, scores, coverage payload, and IDA handoff without future-investigation placeholders; independently resolved `UserPane+0x210` as `LineInputPane *m_activeLineInputPane` / `ClearActiveLineInputPane()` and retained the disproved pending-target ObjectPane model only as dated history with its exact rejection evidence.
- [x] Supplied all 223 sequential atomic ledger rows in the current eight-column schema with canonical Action/Verification vocabulary, one literal path or exact entity, and one exact destination per row.
- [x] C112-C115 preserve the original discovery and active-slot evidence as dated history, bind transaction prestate/backup to exact B180, and bind the applied verified transaction poststate to the single dated CF18895C save. A0, 4A, DAA, F7, B180, CF18895C, 4B5F, 1BC3, 5F, and every older shared-IDB identity are bounded historical checkpoints; the fresh repair assertions are bound explicitly to saved IDB `B7CC899D...58277`, also a dated checkpoint rather than durable future authority.
- [x] C116-C154 and C157-C165 atomize every applied F1-F9/C1/T1 mutation; C155-C156 preserve the exact already-present UserPane rows. Applied readback proves complete physical-frame and Hex-Rays inventories, complete LineInputPane size `0x108`, canonical F1/F7/F9 physical spellings, F1 `struct MapPoint`, F8 `mode@0x8:0x4:int`, and deterministic 60-to-68 UserPane member-count arithmetic. C166-C206 retain every protected dependency property and exact no-change readback, including complete physical frames for `TimerMgr_ScheduleTimer`, `UserPane_WarpToPosition`, and `UserPane_StartDirectionalAnimation`.
- [x] Supplied exact formal target CPP, blank target-H proof, exact complete class H payload, blank class-CPP disposition, preserved UID000415 additions, historicalization requirements, and coherent generated CPP/H topology.
- [x] Supplied nine exact manual coverage mutation payloads/anchors and six target-specific evidence-backed no-op dispositions; the ordinary implementation map covers the 15 original destinations plus the required UID000364 and `by-file/InputPanes.md` active-slot corrections.
- [x] Historicalized command19993, command20024, command20034, command20104, and command20109; historicalized command20109's tracker SHA; retained command20160 only as a dated moving-tracker observation; and recorded dated supervisor command20172 as the later valid generated-topology checkpoint. Supervisor applied M01-M09, verified N01-N06, and validated dated post-application coverage identities `F470880A...A3F7`, `9B8B7753...5033`, and `5704439F...223B` with commands `000000020166` through `000000020168`. Gate 1 snapshots `6C2C8B45...741B7`, `E71703BB...4126`, and `5CDCBB4B...53FF` are dated. The bounded repair checkpoint `DDB43AB5...EAFAE2`, `34287BEF...7E2C1`, and `F203FD4C...0210B` reconfirms all fifteen exact rows at the current report-listed anchors; every whole-file hash and line position remains moving evidence rather than durable truth.
- [x] Third-party import directive confirmed not applicable; no `third_party_embeds/...` source is involved and no import directive belongs in formal code.
- [x] Wave2/Wave3 evidence was ignored as stale and not used.
- [x] Report body is lifecycle-neutral: C112-C115 use `this report` section destinations rather than a research/archive pathname; execution/archive truth is authoritative only from the artifact's actual location plus validator-owned status/history metadata, and exact research/archive paths appear only in the validator-owned historical footer records.

Accepted implementation callback mapping:

- [x] C001-C031 target metadata, behavior, evidence, formal channels, score rationale, and corrected history implemented; target validator `000000019997` recorded.
- [x] C032-C037, C039-C055, and C222-C223 complete UserPane H declaration, blank class CPP, individual fields, inline helper bodies, layout proof, TimerHandler-facet evidence, B007 UID000415 preservation, B008 `LineInputPane *m_activeLineInputPane` / `ClearActiveLineInputPane()` preservation, rejected pending-target history, and score no-change dispositions implemented in `by-class/UserPane.md`; class validator `000000020001` recorded.
- [x] C056-C057 and C059-C060 UserPane file route, target relationship, active-line-input integration, corrected history, and score no-change dispositions implemented in `by-file/UserPane.md` without path drift; final file validator `000000020017` recorded.
- [x] C058 corrected the stale pending-target summary in `by-file/InputPanes.md`; validator `000000020004` recorded.
- [x] C038 corrects UID000364 formal/prose to `ClearActiveLineInputPane()` while preserving the rejected pending-target interpretation as exact dated history; validator `000000020005` recorded.
- [x] C061-C065 vtable slot, facet ABI, reconstructable disposition, and blank formal channels reconciled; validator `000000020006` recorded.
- [x] C066-C069 and C071-C074 linked-position and mode helper behavior, dated raw IDA prestates, saved-IDB `B7CC899D...58277` applied readbacks, exact F2/F3/F8/F9 names/types/comments/frame facts, and target call sites reconciled; Gate2A repair validator `000000020356` supersedes dated callback/C070 validator identities for the current destination.
- [x] C070 accepted callback added the literal source-facing `UserPane::PropagateLinkedObjectMode(int mode)` name to the existing `0x005a9240` thunk sentence without changing range, vtable/tail evidence, owner, 91/93 score, or formal body; scoped validator `000000020142` exited `0` with `ok: 1`, generated refresh disabled, and post-validator SHA256 `533703A9932195F9718BD4CD0283A2E91440750D75BB12DC783A871D35ABE9B1`.
- [x] C075-C077 direction-remap behavior, dated raw IDA prestate, saved-IDB `B7CC899D...58277` applied F6 name/type/comment/readback, and target branch use reconciled; Gate2A repair validator `000000020357` supersedes the dated callback identity for the current destination.
- [x] C078-C081 base timer spelling, corrected history, target delegation, accepted F7 name/comment, and physical `signed __int32 arg1` versus source-facing `int arg1` distinction reconciled; Gate2A repair validator `000000020358` supersedes the dated callback identity for the current destination.
- [x] C082-C084 UID000427 target calls and accepted F4 name/type/comment reconciled while its existing formal body remains unchanged; Gate2A repair validator `000000020359` supersedes the dated callback identity for the current destination.
- [x] C085-C089 UID0002QL accepted F5 name/type/comment, sole caller, exact argument-order correction, dated raw prestate, and invalid-call history implemented; Gate2A repair validator `000000020360` supersedes the dated callback identity for the current destination.
- [x] C090-C093 U7 named-field, helper, formal, corrected-history, and UID0003VD continuation details implemented in `by-memory/0x005a36f0-0x005a3766.UserPaneInitializeWalkAnimation.md`; validator `000000020012` recorded.
- [x] C094-C097 U8 named-field, helper, formal, corrected-history, and UID0003VD continuation details implemented in `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md`; validator `000000020013` recorded.
- [x] C098-C099 UE named-field formal and both UID0003VD coordinate-helper call roles implemented in `by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md`; validator `000000020014` recorded.
- [x] C100-C101 UP named movement-reply fields and UID0003VD continuation implemented in `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md`; validator `000000020015` recorded.
- [x] C102-C103 UQ named movement-reply fields and UID0003VD continuation implemented in `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md`; validator `000000020016` recorded.
- [x] C104-C105 movement-scale layout and arithmetic dispositions reconciled against UID00027F: source-facing plain `char`, signed consumption proved by all 23 `movsx` reads, explicit `signed char` behavior-equivalent, and `unsigned char` rejected; UID00027F required no Gate2A edit and dated validator `000000020018` remains its scoped evidence.
- [x] Every changed ordinary path was hashed before/after; leases were acquired only immediately before edit and released immediately after scoped validation.
- [x] The original supervisor Gate 2A pass before Gate 2B and the later 214/223 Gate2A pass are retained as dated audit history; B005 closed all nine ordinary/report defects in the same five destinations plus C104. The subsequent 28/33 Gate 1 and 209/223 Gate 2A audit failed only 14 moving coverage-currentness rows; this same report now binds those rows to the bounded DDB/342/F203 checkpoint without changing IDA, formals, manual coverage, generated output, or ordinary docs.
- [x] F1 / C116-C122 applied and independently read back: exact `0x005a83b0` name/type/local/stack rows/function-repeatable comment; canonical physical `signed __int32` and `struct MapPoint`; bytes, sole vtable xref, fences, and successor preserved.
- [x] F2 / C123-C125 applied and independently read back: exact `0x0053bf40` name/type/function-repeatable comment; complete inventories, bytes, five callers, other comment channels, and boundaries preserved.
- [x] F3 / C126-C128 applied and independently read back: exact `0x0053c070` name/void type/function-repeatable comment; analyzer return temporary removed as expected; bytes, two target callers, other comment channels, and boundaries preserved.
- [x] F4 / C129-C131 applied and independently read back: exact `0x005055e0` name/type/argument/function-repeatable comment; complete inventories, bytes, two target callers, other comment channels, and boundaries preserved.
- [x] F5 / C132-C135 applied and independently read back: exact `0x005058b0` name/type, `direction` stack row, and function-repeatable comment; bytes, sole target caller, other comment channels, and boundaries preserved.
- [x] F6 / C136-C139 applied and independently read back: exact `0x0053a6b0` name/unsigned-byte type, `direction` stack row, and function-repeatable comment; bytes, six callers, jump-table comments, and boundaries preserved.
- [x] F7 / C140-C143 applied and independently read back: exact `0x0053b830` name, TimerHandler-facet callback type, normalized physical `signed __int32 arg1` row, and function-repeatable comment; bytes, vtable/target callers, other comment channels, and boundaries preserved.
- [x] F8 / C144-C146 applied and independently read back: exact `0x005a9240` thunk name/void type/function-repeatable comment and materialized `mode@0x8:0x4:int` argument row; `delete_stack` correctly returned `mode is argument member`; nine-byte body, compiler rows, vtable cell, tail target, other comment channels, and boundaries preserved.
- [x] F9 / C147-C149 applied and independently read back: exact `0x0053c290` name/void type/function-repeatable comment and canonical physical `signed __int32 mode`; analyzer return temporary removed; bytes, vtable/thunk xrefs, other comment channels, and boundaries preserved.
- [x] C1 / C150 and C184-C191 applied and independently read back: only `0x005a36f0` function-regular comment changed to the accepted `ClearMovementReplyState` text; name, type, other comment channels, complete frame, bytes, four callers, and boundaries preserved.
- [x] T1 / C151-C165 applied and independently read back: size-neutral UserPane splits added, C155-C156 and complete `LineInputPane` size `0x108` preserved, all neighbors and total size `0x13eb84` unchanged, exact member count now 68.
- [x] Protected TimerMgr / C166-C174 read back unchanged: `TimerMgr_ScheduleTimer` name/type/four comment channels/complete frame/SHA `9A8CF9EB...C5B4`/48 callers preserved.
- [x] Protected warp / C175-C183 read back unchanged: `UserPane_WarpToPosition` name/type/four comment channels/complete frame/SHA `320D4AD5...C75E`/12 callers preserved.
- [x] Protected directional starter / C192-C200 read back unchanged: `UserPane_StartDirectionalAnimation` name/type/four comment channels/complete frame/SHA `5ECA3299...010D`/two callers preserved.
- [x] Protected TimerHandler UDT / C201-C202 remains size 4 with the sole vftable member.
- [x] Protected MapPane UDT / C203-C206 remains size `0x910`, member count 69, with `m_queuedMapStateRefresh +0x39d` and `m_pendingActionPoll +0x39e`.
- [x] Same report reconciled after Gate 2B, repaired after the 214/223 Gate2A result, and repaired again after the 209/223 coverage-currentness result: five ordinary destinations state the applied F2-F9 names/types/comments, C104 matches UID00027F's signed plain-`char` evidence, all 15 coverage dispositions are exact at the bounded report checkpoint, commands `000000020356`-`000000020360` passed with generated refresh disabled, and every ordinary-file lease was released.
- [x] M01 / C106 exact UID0003VD row applied and bounded `DDB43AB5...EAFAE2` readback at by-memory line 3820 after UID0003VB and before UID0003VE.
- [x] M02 / C207 exact UID0000FQ row applied and bounded `34287BEF...7E2C1` readback at by-class line 589 with complete H/OnTimer/UID000415-preservation wording.
- [x] M03 / C208 exact UID0000P1 row applied and bounded `F203FD4C...0210B` readback at by-file line 299 with UserPane.cpp definition/UserPane.h declaration wording.
- [x] M04 / C209 exact UID0003Z7 row applied and bounded by-memory line 2801 with 91%/very-strong and resolved helper/target semantics.
- [x] M05 / C210 exact UID000427 row applied at bounded by-memory line 2363 immediately before UID0002QL at line 2364.
- [x] M06 / C211 exact UID0003U7 movement-reply/UID0003VD continuation row applied at bounded by-memory line 3804.
- [x] M07 / C212 exact UID0003UP named-reply-field row applied at bounded by-memory line 3840.
- [x] M08 / C213 exact UID0003UQ named-reply-field row applied at bounded by-memory line 3841.
- [x] M09 / C214 exact UID0002YU TimerHandler OnTimer-slot row applied at bounded by-memory line 4454.
- [x] N01 / C215 bounded `DDB43AB5...EAFAE2` readback confirms UID0003Z3 remains exact at by-memory line 2782.
- [x] N02 / C216 bounded readback confirms UID0002R1 remains exact at by-memory line 2795.
- [x] N03 / C217 bounded readback confirms UID0002QL remains exact at by-memory line 2364.
- [x] N04 / C218 bounded readback confirms UID0003U8 remains exact at by-memory line 3806.
- [x] N05 / C219 bounded readback confirms UID0003UE remains exact at by-memory line 3816.
- [x] N06 / C220 bounded readback confirms UID00027F remains exact at by-memory line 4501.
- [x] Supervisor validated the changed coverage files: by-memory command `000000020166`, by-class `000000020167`, and by-file `000000020168`, each exit `0` / `ok: 1`; exact validated SHAs are recorded above.
- [x] Dated supervisor command20172 generated-refresh evidence satisfies C107-C111/C221 at that revision: one complete UserPane definition and one `OnTimer` declaration in H, no complete UserPane class body in CPP, one UID0003VD definition, no `OnAnimationStep`, and no target no-code/empty marker.
- [ ] For any future acceptance or lifecycle transition, the supervisor verifies generated command headers and physical topology from the then-current artifacts, including absence of raw labels, adjusted-pointer artifacts, empty/no-code markers, and duplicate definitions; this is a reusable invariant, not a claim of unfinished current work.
- [x] All accepted ordinary, C070, Gate 2A, Gate 2B, protected-readback, manual-coverage, and same-report reconciliation items are applied, already present, or verified exact.
- [ ] Before any future acceptance or lifecycle transition, the supervisor performs an exact-artifact audit matching the artifact's then-current path and revision; this is a reusable invariant rather than a statement about present lifecycle status.
- [ ] Execution/archive actions remain supervisor-only; before any transition, their state is read from the current artifact path plus validator-owned status/history metadata rather than inferred from report prose.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000020173","destination_path":"executed-b-agent-research/B005/0003VD-UserPaneHandleAnimationStep-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003VD-UserPaneHandleAnimationStep-source-quality.md","timestamp":"2026-07-31T03:48:33-04:00","uid":"0003VD"} -->
<!-- {"agent":"B005","command_id":"000000020175","destination_path":"tools/leaser/Agents/Agent-B005/research/0003VD-UserPaneHandleAnimationStep-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B005/0003VD-UserPaneHandleAnimationStep-source-quality.md","timestamp":"2026-07-31T03:50:02-04:00","uid":"0003VD"} -->
<!-- {"agent":"B005","command_id":"000000020228","destination_path":"executed-b-agent-research/B005/0003VD-UserPaneHandleAnimationStep-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003VD-UserPaneHandleAnimationStep-source-quality.md","timestamp":"2026-07-31T04:47:02-04:00","uid":"0003VD"} -->
<!-- {"agent":"B005","command_id":"000000020247","destination_path":"tools/leaser/Agents/Agent-B005/research/0003VD-UserPaneHandleAnimationStep-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B005/0003VD-UserPaneHandleAnimationStep-source-quality.md","timestamp":"2026-07-31T04:57:09-04:00","uid":"0003VD"} -->
<!-- {"agent":"B005","command_id":"000000020384","destination_path":"executed-b-agent-research/B005/0003VD-UserPaneHandleAnimationStep-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003VD-UserPaneHandleAnimationStep-source-quality.md","timestamp":"2026-07-31T08:28:07-04:00","uid":"0003VD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
