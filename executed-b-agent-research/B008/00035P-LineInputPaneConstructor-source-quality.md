** TARGET-REPORT-UID:00035P **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 00035P LineInputPane Constructor Source Quality Research


## Finalized Report / Current Recommendation

[UID:00035P] is a complete source-authored `LineInputPane::LineInputPane(const wchar_t *promptText)` body at `[0x004f1c00,0x004f2009)`, not a range marker, compiler helper, or no-code duplicate. Promote the target from `86/90` to `92/94`, preserve owner/emitter [UID:000077], preserve `RECONSTRUCTABLE:TRUE`, keep the emitter position blank, place the exact constructor body in the target `RECONSTRUCTION_CPP` block, and keep the target `RECONSTRUCTION_H` block blank because the declaration belongs to [UID:000077][LineInputPane](by-class/LineInputPane.md).

The accepted source shape uses the existing `LineInputPane`, `TextBoxPane`, `TextEditPane`, `Pane`, `BlackHole`, `EventDispatcher`, `UserPane`, and `ChattingVarietyPane` abstractions. It does not reproduce vtable stores, SEH state, security-cookie logic, raw `sub_` labels, or `dword_`/`unk_` globals. Exact execution behavior remains visible: two asset-layout branches, optional prompt creation, one editable child, exact dimensions/colors/limits, exact parent/child registration order, deferred deletion of the prior active line input in the current-layout branch, active-line-input publication, and chat-variety refresh.

Gate 1 passed for exact pre-callback report SHA256 `BAE985B92E29861C1C152361A2C8AE212F42FF3B9CCC69ED905446C78E1F7533`; a later fresh Gate 1 also passed exact pre-coverage SHA256 `69597557502A72FB4EC70E8A412C344D25EB0CE2052B611E6425C9570D96ED68`. The accepted ordinary C001-C047 implementation callback is physically complete and supervisor Gate 2A independently verified it. Historical supervisor Gate 2B catalog entry 0377 applied/saved/read back A00-A09, and the post-IDA callback reconciled that transaction into the report and the actually stale whitelisted ordinary docs. Supervisor commands `000000020163`-`000000020165` subsequently applied and read back C050-C061/M01-M12. Supervisor command `000000020172` then completed the generated refresh after manual coverage, and command `000000020175` later advanced the moving research tracker. This report edit requires fresh Gate 1, fresh Gate 2B currentness verification, and independent supervisor verification of the current generated topology; report execution/archive remains supervisor-owned, and this report makes no current Gate 2B, topology-verification, or execution/archive claim.

## Supporting Research

- Current target: [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md), SHA256 `CCF28C564A4775F0297C408A37073DB40650538475B477B7646F6601C8F253C1`, 14,716 bytes, 156 lines after post-IDA reconciliation.
- Direct class/file route: [UID:000077][LineInputPane](by-class/LineInputPane.md), SHA256 `0461110E9DB289438C8BEC924FB4C949C83FB356426A098098FB226AFC41DF35`, and [UID:0000K7][InputPanes](by-file/InputPanes.md), SHA256 `77948F03FB4268780D43BB634843D556CE60093421F77ABB978B7E6354495227`.
- Split index: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md), SHA256 `4610045843940790FD0A56972351B4BA85545AFDA526B68901084F56B8684316`.
- Related exact children: [UID:00018Y][LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md), SHA256 `3B957F9BE7B4B432E4F969D43DA1C398E5CE316843223FEFBF60B8C564AF6366`, and [UID:00035Y][LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md), SHA256 `3CA614F2AB65ADF4CCC96BC8DD6B6544AC55DB88F9577D9D72147F17E480A69A`.
- Constructor dependencies: [UID:0002RV][TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md), [UID:0002ZY][TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md), [UID:00016C][GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), and [UID:0000Z1][BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md).
- Global dependencies: [UID:00028J][g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md), [UID:00028K][g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md), [UID:000296][g_pEventDispatcher](by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md), [UID:0002X6][g_pChattingVarietyPane](by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md), [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md), and `g_pUserPane` at `0x0067a748`.
- Duplicate search covered exact UID, exact address, exact title, constructor name, root reports, central executed reports, archived/older reports, and SpecialReports. No report researches and implements UID00035P at this specificity. The B001 UID00018X report is family split/index work; B008 UID000414 uses this constructor only as support evidence.
- Stale Wave2/Wave3 planning language found in older support documentation was ignored as instructed; it is not evidence for source ownership or current implementation state.

## Target

- UID: `00035P`
- Path: `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md`
- Exact range: `[0x004f1c00,0x004f2009)`
- Current bounded target-local IDA name at dated CF188 checkpoint: `LineInputPane__Constructor`; fresh Gate 2B must still reread it against the then-current saved IDB.
- Current bounded target-local IDA type at dated CF188 checkpoint: `LineInputPane *__thiscall(LineInputPane *this, const wchar_t *promptText)`; fresh Gate 2B must still reread it against the then-current saved IDB.
- Historical pre-callback score: `86/90`
- Current/recommended score: `92/94`
- Recommended score: `92/94`
- Owner/emitter: [UID:000077][LineInputPane](by-class/LineInputPane.md)
- Source root: [UID:0000K7][InputPanes](by-file/InputPanes.md), `NexusTK/ui/dialogs/InputPanes.cpp`
- Assignment/preparation checkpoint: command `000000019910` tracker row at line 1673, zero direct reports and zero additional reports; this is a dated predecessor to the final currentness observation below.

## Current Target State

The target has correct bounds, identity, prototype, one useful function comment, 37 incoming code xrefs, a correct owner/emitter route, accepted formal C++, synchronized blocker history, and a saved source-facing IDA type/helper/global state. The ordinary callback added the two constructor-initialized integer fields at `+0x100` and `+0x104` after `m_promptTextPane` at `+0xf8` and `m_textEditPane` at `+0xfc`; catalog entry 0377 then applied the incomplete `TextBoxPane`, exact five-member `0x108` `LineInputPane`, and bounded `UserPane +0x210 LineInputPane *m_activeLineInputPane` split without moving the tail. Current command20172 generated CPP/H output contains exactly one UID00035P `92/94` constructor body, no UID00035P empty marker, and one `LineInputPane` declaration with all four fields. The still-empty UID00035Y sibling marker is separate and does not invalidate the target topology. Command20172 completed the refresh; the remaining generated task is independent supervisor verification of this current topology, not another refresh.

Generated observations are moving-artifact checkpoints, not lifecycle authority. Commands `000000019890`, `000000019900`, `000000019911`, `000000019926`, `000000019933`, `000000019993`, `000000020024`, `000000020034`, `000000020104`, `000000020109`, `000000020124`, `000000020149`, `000000020160`, and `000000020170` and their hashes are dated historical research/currentness checkpoints. The bounded current readback observed command20172 CPP/H/generated-memory state and the later command20175 tracker state without editing any generated artifact. Every tracker identity is explicitly moving and may be superseded by a later validator command:

- `auto-generated/NexusTK/ui/dialogs/InputPanes.cpp`: command `000000020172`, refreshed `2026-07-31T03:46:57-04:00`, SHA256 `9B54F97612FDC42132B44B33FA71066DEF1BD65B6ADF077943E28308D214E599`, 8,533 bytes, 258 lines; UID000077 is `93/94` at line 83, exactly one UID00035P `92/94` marker at line 84 precedes the sole constructor at line 85, the exact four-field initializer list is present, the UID00035P empty marker is absent, and the separate UID00035Y empty sibling marker remains at line 258. Historical command `000000020109`, refreshed `2026-07-31T01:02:54-04:00`, had SHA256 `EC8B1F90F69272322ED7EACDE5A696558178DAD35B38303A4DEDBB7000B1409A`, 8,533 bytes/258 lines, with the same topology. Historical command `000000020104` had SHA256 `B6FBFEEA7613E8202C4B46CDD2FB3C4C0022293FA67170E98ECF7AA4BB4E7359`; historical command `000000020024` had SHA256 `9F5E6CE07D06DD4C976421F9F2D1A9E4D04D6DC7A47DD60D0D6D6C7BA8D9AEAD`; command `000000019993` had SHA256 `BD07F4A844DE0DA2065DA093796D02A3E1D487C62A9BA98E8DAE41229F0F1FF7`; command `000000019926` had SHA256 `0D25BC79F1CBC9A795575B71B1762C959B0A0D1B1BC610894C340F56E5062F62`, 6,251 bytes/192 lines, with the pre-callback `86/90` empty marker and no constructor body; command `000000019890` had SHA256 `0B528A6B7AF86858A87FF6E50AEA4DA5B71CFFC377C0E5176931AD19594C5E4F`.
- `auto-generated/NexusTK/ui/dialogs/InputPanes.h`: command `000000020172`, refreshed `2026-07-31T03:46:57-04:00`, SHA256 `8FD90D87EBE32D1AB745BAAACA1B7EE4B4CA32394129A2D7C820A13BF9F41378`, 1,237 bytes, 38 lines; the single UID000077 `93/94` `LineInputPane` declaration at line 7 has `m_promptTextPane`, `m_textEditPane`, `m_deferredSubmitPending`, and `m_deferSubmitUntilNextEvent` exactly once at lines 34-37. Historical command `000000020109`, refreshed `2026-07-31T01:02:54-04:00`, had SHA256 `E4406EFC6E46BC934B9B05FE3042E5381E89716F1A4738D24873A1F718BBD867`, 1,237 bytes/38 lines, with the same declaration topology. Historical command `000000020104` had SHA256 `7B01A9EAAB7890E65DBE4EFA16B22869941AE0891B090786B348AC91EF8105E8`; historical command `000000020024` had SHA256 `BBBE116AAB96E78C7F0AD675F4178DD5745CCD66D4233E9DFF1174468F379BD3`; command `000000019993` had SHA256 `4A1B98BD6B2C6BA5A57B8AC116C289AA71DAA45E14EA773720150F5B62BAB105`; command `000000019926` had SHA256 `33FE0F5D452871C365A3506AC1C8CFD4124E97FBC965772ED198397574EE2895`, 1,167 bytes/36 lines, and omitted the two integer fields; command `000000019890` had SHA256 `1040A35E122FF4FA1EB7536991896ADF14CA6E9EF4CCB878DC53EEC2016576CB`.
- `auto-generated/-ag-memory-coverage.md`: command `000000020172`, refreshed `2026-07-31T03:46:57-04:00`, SHA256 `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770`, 1,427,432 bytes, 4,974 lines; UID00035P remains at line 1259, is `coded`, routes to `InputPanes.cpp`, reports target CPP present and target H absent, and has no empty-emitter condition. Historical command `000000020109`, refreshed `2026-07-31T01:02:54-04:00`, had SHA256 `027FB7FD6E725B3433B4E3ACA0C0801CF1CC1D6F5F625C96FA5026207F4B8D9F`, 1,421,254 bytes/4,953 lines, with the same target disposition. Historical command `000000020104` had SHA256 `BEE343EC97DE3987E641442D6A142B7792482295E12BA8AEFE02471A484BF12`; historical command `000000020024` had SHA256 `3B54DA2FED76D4EDA0853E154DCBA94DF56697D73D00E8A16985FC9CD15B3EDA`; command `000000019993` had SHA256 `4F54811E022C0EEED7E77BF85AFFBF36B25E7E97A41BD9E20878C148A4393C5F`; command `000000019926` had SHA256 `6A2DA8391DDE03DDF7949AE430E6E5A538F364C4D0F1D3FAAAB14B7A7F3CD544`, 1,419,904 bytes/4,949 lines, and reported no target CPP or H; command `000000019900` had SHA256 `6B7107669461CB4387E93B6D97D170AC44C43DD4FFC40D6139EE68E0F78C8089`.
- `auto-generated/-ag-research-tracker.md`: moving command `000000020175`, refreshed `2026-07-31T03:50:02-04:00`, SHA256 `8D25FA8A0D5AA888FB02A0514D50C92D82B945F747D4FCEF35720BBD84B2C1C1`, 1,686,231 bytes, 6,658 lines; UID00035P is at line 3167 at `92/94`, reconstructable, with direct/additional/family counts `0/0/0`. This is only the latest report-time observation and is supersedable by later validator commands; report execution/archive state remains supervisor-owned and authoritative only from the actual report path plus validator-owned status/history metadata. Historical command `000000020170`, refreshed `2026-07-31T03:27:44-04:00`, had SHA256 `00D887EBC65C350398AD736D743FA3804635E2C338CF0A77D14FD9B5345608E0`, 1,686,230 bytes/6,658 lines, and placed the same UID00035P row at line 3168. Historical command `000000020160`, refreshed `2026-07-31T02:08:05-04:00`, had SHA256 `CF8C778FCA2A2F9F4D0DF55D6710B5770F8994C74E45C663EDCD9280688ACA3B`, 1,685,974 bytes/6,658 lines, and the same UID00035P row at line 3168. Historical command `000000020149`, refreshed `2026-07-31T01:57:57-04:00`, had SHA256 `A826E7CE46E00CD7F227DB0FA89135D60E9C562994CC0CD09BEF7C101B3EBE5F`, 1,686,081 bytes/6,658 lines, and the same UID00035P `92/94`, reconstructable, `0/0/0` row at line 3168. Historical command `000000020124` had SHA256 `4FCB30D3059001BB48F1E3E1D6FD344D9DF6714FB98A37574A3E54167D582A69`, 1,684,017 bytes/6,650 lines, and placed that row at line 3162. Historical command `000000020109` had SHA256 `706757C06C971EE12553F07CBE68178BCD73153AFA74CD7375B24A369332B342`, 1,680,966 bytes/6,637 lines, and placed it at line 3153. Historical command `000000020104` had SHA256 `784D99B4A4C01C389EBBA2C057E636CC88BEADC9EF452E2FC71F3B103F9280CF`; historical command `000000020034` had SHA256 `C50515CD081E5C78870048F3FEBFC21858016DE01F9408E43865F85CF2EFA529`; command `000000019993` had SHA256 `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`, 1,679,725 bytes/6,634 lines, and placed UID00035P at line 3153 with the same score/report counts; command `000000019933` had SHA256 `A1FA9680D296AF86A2BDBB7C6994413256035E5292ADECB4FB42E985B04958D1`, 1,679,360 bytes/6,633 lines, and still reported pre-callback `86/90` at line 1673. Command `000000019928` with SHA256 `5D7DA3EA2FFD3E3C201142EAADAF5A5C753877A84D296E911BC2F827898C378B`, plus commands `000000019910` and `000000019911`, are dated historical checkpoints.

## Executive Recommendation

The constructor body, exact trailing integer fields, and `UserPane+0x210` active `LineInputPane *` source correction are now physically implemented in ordinary documentation. The constructor and related key handler prove the slot lifecycle: the current-layout constructor first queues the previous value for deferred deletion, then publishes `this`; dismissal clears the same slot. Catalog entry 0377 synchronizes the corresponding IDA class layouts without changing source ownership.

The four raw helpers encountered by the target are not acceptable unresolved blockers. Their best source-facing identities are:

1. `LineInputPane::HandleKeyOrTextEvent(Event *event)` at `0x004f25a0`.
2. `EventDispatcher::ArmTextInputGuardTimer()` at `0x004a6fa0`.
3. `BlackHole::QueuePaneForDeferredDeletion(Pane *pane)` at `0x00469180`.
4. `GrafPort::GetTextWidth(const wchar_t *text, int charCount)` at `0x004ba9a0`.

The globals at `0x0067ab30` and `0x0067add8` have exact source pages and source-facing roles. Catalog entry 0377 materialized each as one four-byte data item with canonical name, exact pointer type, exact regular/repeatable comments, unchanged zero bytes, unchanged 86/18 start xrefs, zero interior xrefs, and protected neighbors. Their earlier four-one-byte/blank-comment state remains dated pre-Gate-2B evidence only.

## Supervisor Active Recheck

On 2026-07-30 after the IDA barrier release, B008 performed earlier bounded read-only MCP passes against former active session `1da2b2ae`; that session is now historical rather than current authority. The earlier saved-IDB checkpoints SHA256 `4EDEC1553CDF85F5EDE5F40475BACA27EE26B3538E22313CED616FE3A4B5D09F`, 143,194,010 bytes, last write `2026-07-30T09:56:01.8527844-04:00`; SHA256 `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`, 143,194,020 bytes, saved `2026-07-30T14:38:13.8949946Z`; SHA256 `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`, 143,194,156 bytes, saved `2026-07-30T15:35:19.0223971Z`; SHA256 `836ABCFA986AF47A3CAC9EC1D46A31BE6B9B29DA83B6BCA797E7817F2CCF489F`, 143,194,721 bytes, saved `2026-07-30T12:01:56.5937670-04:00`; SHA256 `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, 143,192,050 bytes, saved `2026-07-30T12:33:26.5781084-04:00`; and SHA256 `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, 143,192,163 bytes, saved `2026-07-30T12:47:29.2294093-04:00`, are retained as dated history and are not current.

Historical pre-Gate-2B session `07b29e1b` and saved IDB SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94` supplied the literal prestates and now serve as the exact backup checkpoint at `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B008-UID00035P-20260730_141932.i64`. Supervisor catalog entry 0377 was applied and verified at saved IDB SHA256 `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`; this is immutable UID00035P action-time evidence, not the moving current shared-IDB identity. Historical bounded checkpoint `F7C936C072D1332D82D06A92F89F3531D97EE8D9252A2C3C6325B2580F8D7D8A`, 143,192,467 bytes, saved `2026-07-30T14:56:51.3756829-04:00`, and the later supervisor-referenced `9F8...` identity are dated evidence only. Historical B180 SHA256 `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`, 143,192,467 bytes, saved `2026-07-31T02:40:36.4157748-04:00`, is likewise a superseded physical checkpoint rather than current authority.

The mandatory current bounded reread used live session `f608d7c2` against physical saved IDB SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, last write `2026-07-31T03:00:53.6024151-04:00`. `idb_list` returned exactly one active worker session, and `server_health` returned status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. B008 used only bounded `type_query`/`type_inspect`, exact-name function/global queries, `lookup_funcs`, `func_profile`, `stack_frame`, `decompile`, `inspect_items`, `get_comments`, `get_bytes`, and exact-address `xref_query` calls. The reread covered A00-A09 and every P00-P04 entity item by item; it found no target/action/protected-state drift. CF188 is a dated latest checkpoint and does not waive the supervisor's fresh Gate 2B reread against whatever saved IDB is authoritative at closure time.

The CF188 item-by-item reread reconfirmed the catalog-0377 action poststate and all P00-P04 protected constraints. `TextBoxPane` is ordinal 961, incomplete/no-layout, zero members; `LineInputPane` ordinal 803 remains exactly `0x108` with `_paneBase[0xf8]` plus the four source fields; `UserPane` ordinal 637 remains `0x13eb84` and now has 68 catalog members after unrelated accepted work, while the exact target slice still has `LineInputPane *m_activeLineInputPane` at `+0x210`, four bytes at `+0x214`, and `m_groupMembers` at `+0x218`. A03-A07 retain canonical names/prototypes/comments and exact frames; their current Hex-Rays argument/local inventories are recorded in their rows. The target byte SHA remains `36A98D99...A561`, all 48 regular internal address comments remain exact, every corresponding repeatable comment remains absent, 37 incoming xrefs remain, and the seven-byte successor padding is still `CC CC CC CC CC CC CC`. A08/A09 remain one typed/commented size-four data item each; exact global queries still resolve `g_pEventDispatcher` and `g_pChattingVarietyPane`, while blank `inspect_items.name` values remain a tool-projection discrepancy. Exact-address xref totals remain 86/18 at their starts and zero at interiors. Protected singleton neighbors, one-byte heads, RTTI pointer cells/descriptors/vtables, compiler wrappers/thunks/destructors, SEH code, cookie, and security helper all match the literal rows below. The historical controlled unsaved stack-offset experiment remains discarded; CF188 records no direct stack edit.

## Inference Research Guidance Check

The report follows `inference_research` principles now incorporated into `ntk-b-agent-workflow`: positive and negative evidence are separated; exact binary facts are distinguished from source-facing inference; alternate names, owners, and source shapes are ranked; compiler lowering is excluded from authored C++; every unresolved raw name receives a best supported human name; and score caps are tied to specific remaining lexical uncertainty rather than deferred investigation.

The final goal is exact runtime behavior plus plausible original human-written source. Therefore uncertain original spellings are inferred consistently with existing project vocabulary instead of retaining `sub_4F25A0`, `dword_67AB30`, `unk_69B368`, or synthetic offset expressions in final C++.

## Heuristic / Inference Reanalysis And Validation

| Question | Positive evidence | Negative evidence / rejected alternative | Best resolution |
| --- | --- | --- | --- |
| Constructor owner | Three LineInputPane vtable writes, `this+0xf8/+0xfc/+0x100/+0x104`, 37 base/derived callers, and exact class route. | No evidence for a file-static factory or derived-pane owner. | `LineInputPane::LineInputPane` in `InputPanes.cpp`. |
| `+0x100` | Initialized to zero; handler sets it on deferred Enter and clears it on the next event. | It is not a pointer, timer id, or layout field. | `int m_deferredSubmitPending`. |
| `+0x104` | Initialized to zero; handler tests it to select two-step deferred submit versus immediate submit. | It is not an opaque pad because live behavior reads it. | `int m_deferSubmitUntilNextEvent`. |
| `UserPane+0x210` | Constructor reads/queues/stores `LineInputPane *`; handler clears it. | `ObjectPane *m_pendingTargetObject` conflicts with both writers and consumers. | `LineInputPane *m_activeLineInputPane` and `ClearActiveLineInputPane()`. |
| Asset-mode flag | Existing source global and hundreds of UI consumers select EPF/current versus legacy geometry/assets. | `g_useLargeInputPaneLayout` is a narrow consumer-biased alias. | `g_useEpfAssets`. |
| `0x004ba9a0` | Receiver is this pane/GrafPort facet; body walks UTF-16 glyphs; existing GrafPort child emits exact method. | `MeasureTextWidth` is stale and raw `sub_4BA9A0` is not source. | `GrafPort::GetTextWidth(text, count)`. |
| `0x004a6fa0` | Sets dispatcher byte `+0x28`, schedules timer id 0 after 10 ms, and is called from both constructor branches. | Generic `arg1`, timer callback, and mouse-specific names do not fit. | `EventDispatcher::ArmTextInputGuardTimer()`. |
| Chat virtual call | EPF branch invokes the compact ChattingVarietyPane secondary forwarder after publishing the active line input. Existing docs consistently call the effect a refresh. | Exact original lexical spelling is not symbol-proven; raw vslot syntax is not human source. | `g_pChattingVarietyPane->Refresh()` as best project-consistent inference. |
| Duplicate branch shape | The binary contains two substantial layout branches with branch-specific constants and EPF-only state publication. | Over-normalizing into a data table would obscure the original likely branch structure and call ordering. | Preserve two explicit branches in first-draft C++. |

## Evidence Standards Used

- Exact: saved-IDB item boundaries, function extents, bytes, xrefs, types, comments, stack records, decompilation behavior, and ordinary-document metadata.
- Strong inference: class/member/global/helper names selected from stable role, existing project vocabulary, caller behavior, and neighboring source families.
- Historical only: superseded raw aliases and earlier generated/manual coverage snapshots.
- Rejected: caller-biased ownership, monolithic aggregate emission, output hardening absent from the binary, compiler-generated vtable/SEH/cookie source, and Wave2/Wave3 planning references.

## Evidence Checked

- `lookup_funcs` reconfirmed exact current function ranges/names: A03 `LineInputPane__Constructor` `[0x004f1c00,0x004f2009)` size `0x409`; A04 `LineInputPane__HandleKeyOrTextEvent` `[0x004f25a0,0x004f2754)` size `0x1b4`; A05 `EventDispatcher__ArmTextInputGuardTimer` `[0x004a6fa0,0x004a6fb2)` size `0x12`; A06 `BlackHole__QueuePaneForDeferredDeletion` `[0x00469180,0x004691fa)` size `0x7a`; and A07 `GrafPort__GetTextWidth` `[0x004ba9a0,0x004baa67)` size `0xc7`. Raw `sub_*` identities are dated prestates only.
- `get_bytes` reconfirmed target prologue `55 8b ec 6a ff 68 c4 0c 60 00 64 a1 00 00 00 00` and seven `cc` bytes at `[0x004f2009,0x004f2010)`.
- `xrefs_to` reconfirmed complete, non-truncated incoming-reference sets of 37 for A03, 27 for A04, 2 for A05, 83 for A06, and 117 for A07.
- `type_query` reconfirmed incomplete/no-layout `TextBoxPane`; exact size-`0x108` five-member `LineInputPane` ordinal 803; and exact size-`0x13eb84` `UserPane` ordinal 637 with `_userPaneToActiveLineInput[0x4a] +0x1c6`, `LineInputPane *m_activeLineInputPane +0x210`, `_userPaneAfterActiveLineInput[4] +0x214`, and unchanged `m_groupMembers +0x218`/tail.
- `inspect_items` reconfirmed `0x0067ab30` and `0x0067add8` as one size-four typed/commented data item each with zero bytes, 86/18 start xrefs, and zero interior xrefs; its `name` projection is blank at both addresses, while bounded canonical `entity_query`/global-name queries independently return `g_pEventDispatcher` and `g_pChattingVarietyPane`. The same projection split occurs at protected neighbor heads `0x0067ab2c` and `0x0067addc`; it is not evidence that the canonical names are absent.
- `get_comments` reconfirmed all four function-entry channels independently for every A03-A07 row: A03 address regular/repeatable absent, function regular exact constructor sentence, function repeatable absent; A04/A06/A07 address regular/repeatable absent and exact function regular/repeatable comments; A05 address regular/repeatable absent after stale `arg1` removal and exact function regular/repeatable comments. A separate bounded open-interval comment read found 48 current regular internal address comments in A03 and zero repeatable internal comments; the prior empty-internal-comment assertion is retained only as disproved historical presentation.
- `stack_frame` reconfirmed the complete current per-function inventories in A03-A07. A04 has `event +0x10/4 Event *`; A05 has only `__return_address +0x0/4 _UNKNOWN *`; A06 has `pane +0x10/4 Pane *`; A07 presents `text +0x40/4 const wchar_t *` and retains historical `outAdvance +0x44/2 __int16` while its canonical prototype uses `int charCount`. The discarded unsaved stack experiment is not durable state.
- Full target decompilation was checked before the barrier and reconciled after release with the bounded identity/type/byte/comment/xref readback; the final currentness pass used only bounded target-local reads.
- Current ordinary target/support docs, all M01-M12 manual coverage rows and anchors, command20172 generated source/header/memory coverage, command20175 research tracker, active goals/reports, and current leases were read from disk. The current generated headers identify command20172 as `foreground-generated-refresh` at `2026-07-31T03:46:57-04:00`; the tracker header identifies command20175 as `deferred-generated-refresh` at `2026-07-31T03:50:02-04:00`. Current moving-artifact identities are recorded in their dedicated sections, while command20109/20170 and older hashes remain explicitly historical.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 00035P | Exact range is `[0x004f1c00,0x004f2009)` with seven-byte successor padding. | exact | MCP function/bytes | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Status | incorporate | applied |
| C002 | 00035P | Source identity is `LineInputPane::LineInputPane(const wchar_t *promptText)`. | very strong | vtables, fields, callers, current prototype | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Summary | incorporate | applied |
| C003 | 00035P | The target has exactly 37 incoming code xrefs. | exact | bounded `xrefs_to` | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Caller Inventory | incorporate | applied |
| C004 | 00035P | Two explicit EPF/current and legacy branches preserve exact geometry and limits. | exact | decompile/control flow | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Behavior | incorporate | applied |
| C005 | 00035P | EPF/current bounds are `(100,733,693,745)` and edit width is `593-promptWidth`. | exact | decompile/constants | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Behavior | incorporate | applied |
| C006 | 00035P | Legacy bounds are `(14,456,422,468)` and edit width is `408-promptWidth`. | exact | decompile/constants | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Behavior | incorporate | applied |
| C007 | 00035P | Prompt width is `GetTextWidth(promptText,wcslen(promptText))+1`. | exact/strong name | call sequence and GrafPort child | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Prompt Construction | incorporate | applied |
| C008 | 00035P | Optional prompt child is a 0x174-byte TextBoxPane with height 12, color 128, and mode background 0/143. | exact | allocation/call arguments | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Prompt Construction | incorporate | applied |
| C009 | 00035P | Edit child is a 0x174-byte TextEditPane with flags 0x100, one line, and length 80/50. | exact | allocation/call arguments | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Edit Construction | incorporate | applied |
| C010 | 00035P | Constructor attaches self to g_pBackPane, then optional prompt and edit children, then sets pane order. | exact | decompile/call order | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Registration Order | incorporate | applied |
| C011 | 00035P | EPF branch queues prior active line input, publishes this, and refreshes ChattingVarietyPane. | exact/strong names | decompile/global docs | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Active Input Lifecycle | incorporate | applied |
| C012 | 00035P | Both branches arm the EventDispatcher text-input guard timer. | exact/strong name | two calls to 0x4a6fa0 | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / Registration Order | incorporate | applied |
| C013 | 00035P | Formal CPP is the exact source-facing constructor in this report. | very strong | all target evidence | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / RECONSTRUCTION_CPP | incorporate | applied |
| C014 | 00035P | Target H stays blank because class UID000077 owns the declaration. | exact routing | owner/emitter rules | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / RECONSTRUCTION_H | already-present | already-present |
| C015 | 00035P | Score becomes 92/94; owner/emitter and reconstructable state remain unchanged. | strong | blocker closure and code readiness | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` / metadata and Score Rationale | incorporate | applied |
| C016 | 000077 | Add integer field `m_deferredSubmitPending` at complete-object +0x100. | very strong | constructor/handler reads/writes | `by-class/LineInputPane.md` / RECONSTRUCTION_H | incorporate | applied |
| C017 | 000077 | Add integer field `m_deferSubmitUntilNextEvent` at complete-object +0x104. | very strong | constructor/handler branch | `by-class/LineInputPane.md` / RECONSTRUCTION_H | incorporate | applied |
| C018 | 000077 | Document exact class size 0x108 and field offset rationale. | very strong | Pane base and four trailing fields | `by-class/LineInputPane.md` / Class Layout | incorporate | applied |
| C019 | 000077 | Raise class score from 91/93 to 93/94. | strong | layout and constructor code closure | `by-class/LineInputPane.md` / metadata and Score Rationale | incorporate | applied |
| C020 | 0000K7 | Record constructor source and exact class/layout dependency under InputPanes.cpp. | very strong | source family and emitter route | `by-file/InputPanes.md` / Source Reconstruction State | incorporate | applied |
| C021 | 0000K7 | Raise InputPanes from 91/88 to 92/92. | strong | exact constructor and layout resolved | `by-file/InputPanes.md` / metadata and Score Rationale | incorporate | applied |
| C022 | 00018X | Replace stale reconstructable/gate prose; aggregate remains 90/92 false/non-emitting. | exact | current metadata/children | `by-memory/0x004f1c00-0x004f3017.InputPaneBases.md` / Item Summary | reject-stale | applied |
| C023 | 00018X | Add UID00035P 92/94 constructor status to child inventory. | strong | accepted target recommendation | `by-memory/0x004f1c00-0x004f3017.InputPaneBases.md` / Boundary Notes | incorporate | applied |
| C024 | 00035Y | Replace raw +0x100/+0x104 expressions with the two resolved member names. | very strong | constructor/handler correlation | `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` / Behavior | incorporate | applied |
| C025 | 00035Y | Name the method `HandleKeyOrTextEvent(Event *event)` and preserve physical secondary-facet note. | very strong | vtable/caller/receiver evidence | `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` / Summary | incorporate | applied |
| C026 | 00035Y | Preserve 88/90 until a child-specific formal-code pass is accepted. | strong | behavior known; child code outside target | `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` / Score Rationale | already-present | already-present |
| C027 | 00018Y | Replace `MeasureTextWidth` with `GetTextWidth`. | very strong | existing GrafPort formal method | `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md` / RECONSTRUCTION_CPP | incorporate | applied |
| C028 | 00018Y | Replace `g_useLargeInputPaneLayout` with `g_useEpfAssets`. | very strong | sole source global/consumer evidence | `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md` / RECONSTRUCTION_CPP | incorporate | applied |
| C029 | 00018Y | Replace attachment aliases with g_pBackPane and rootPaneLayerContext route. | strong | global/layer docs and call operands | `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md` / RECONSTRUCTION_CPP | incorporate | applied |
| C030 | 0000FQ | Replace stale `ObjectPane *m_pendingTargetObject` at +0x210 with `LineInputPane *m_activeLineInputPane`. | very strong | constructor read/write plus handler clear | `by-class/UserPane.md` / RECONSTRUCTION_H | incorporate | applied |
| C031 | 0000FQ | Replace `ClearPendingTargetObject` with `ClearActiveLineInputPane`. | very strong | exact slot semantics | `by-class/UserPane.md` / RECONSTRUCTION_H | incorporate | applied |
| C032 | 0000FQ | Split the opaque +0x1c6 span without moving +0x218 or total size 0x13eb84. | exact | catalog-0377 action plus dated F7 bounded IDA type/layout readback; fresh Gate 2B reread required | `by-class/UserPane.md` / Layout Evidence | incorporate | applied |
| C033 | 0000P1 | Correct the source-file narrative for +0x210 and its constructor/dismissal callers. | very strong | same binary evidence | `by-file/UserPane.md` / LineInputPane Active Slot | incorporate | applied |
| C034 | 000141 | Add the source-facing `ArmTextInputGuardTimer` helper role at 0x004a6fa0. | very strong | exact 18-byte body/callers | `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` / Function Inventory | incorporate | applied |
| C035 | 00004M | Add method declaration/field role for the text-input guard. | strong | helper and route behavior | `by-class/EventDispatcher.md` / Source Reconstruction State | incorporate | applied |
| C036 | 0000J7 | Record the helper as EventDispatcher.cpp ownership. | strong | receiver/global/source family | `by-file/EventDispatcher.md` / Proposed Original Placement | incorporate | applied |
| C037 | 000296 | Record exact saved IDA materialization/name/type/comments and protected readback while preserving the sole formal global. | exact/strong name | catalog0377 and live item/global docs | `by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md` / IDA State And Supervisor Handoff | incorporate | applied |
| C038 | 0000Z1 | Record saved canonical BlackHole helper name/type/comments/frame and historicalize its raw prestate. | very strong | catalog0377, exact body, existing formal CPP | `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md` / IDA Status And Supervisor Handoff | incorporate | applied |
| C039 | 00016C | Record saved canonical `GrafPort__GetTextWidth` name/type/comments and literal retained physical frame. | very strong | catalog0377, exact body, existing formal CPP | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` / IDA Status And Supervisor Handoff | incorporate | applied |
| C040 | 0002X6 | Record exact saved singleton materialization/name/type/comments and protected readback. | exact/strong name | catalog0377, live items, semantic global | `by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md` / Evidence | incorporate | applied |
| C041 | 0002X5 | Record constructor as a direct singleton consumer. | exact | target decompile | `by-global/g_pChattingVarietyPane.md` / Evidence | incorporate | applied |
| C042 | 00001Y | Add source-facing no-argument `Refresh()` dependency, explicitly inferred. | strong | vslot/forwarder/current subsystem terms | `by-class/ChattingVarietyPane.md` / existing `RECONSTRUCTION_CPP` class declaration | incorporate | applied |
| C043 | 0000I5 | Record the constructor publish/refresh route without changing Chatting ownership. | strong | singleton/caller/source root | `by-file/Chatting.md` / LineInputPane Consumer | incorporate | applied |
| C044 | 0002FE | Historicalize Wave2/Wave3 prose and retain compiler-forwarder/no-code disposition. | exact | 10-byte adjustor body and current instruction | `by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md` / Compiler Artifact Disposition | historicalize | applied |
| C045 | 0000T6 | Preserve 0x0069b368 as shared rootPaneLayerContext; no independent IDA action. | strong | startup/layer consumers | `by-global/MainUiLayerSlots.md` / Consumer Evidence | already-present | already-present |
| C046 | 00028J | Preserve g_pBackPane owner/type/definition and add constructor consumer only. | exact | target call operands | `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` / Evidence | already-present | already-present |
| C047 | 00028K | Preserve BlackHole singleton storage and add prior-pane queue consumer. | exact | target branch | `by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md` / Evidence | incorporate | applied |
| C048 | 00035P | Command20172 refreshed generated CPP with one coded constructor and no target empty marker; command20109/20104/20024 remain dated historical topology checkpoints. | exact current readback | command20172 emitter topology and historical command20109/20104/20024 comparison | `auto-generated/NexusTK/ui/dialogs/InputPanes.cpp` / supervisor verification only | already-present | already-present |
| C049 | 000077 | Command20172 refreshed generated H with the two new integer fields once; command20109/20104/20024 remain dated historical topology checkpoints. | exact current readback | command20172 class H topology and historical command20109/20104/20024 comparison | `auto-generated/NexusTK/ui/dialogs/InputPanes.h` / supervisor verification only | already-present | already-present |
| C050 | 00035P | Manual by-memory coverage now contains the exact new reconstructable 92% constructor row. | exact supervisor readback | command20163 applied payload; current F470 physical readback row 2044 | `by-memory/-coverage-report.md` / UID00035P row | not-applicable | applied |
| C051 | 00018X | Manual by-memory aggregate row is now non-reconstructable 90% with split-index authority. | exact supervisor readback | command20163 applied payload; current F470 physical readback row 2043 | `by-memory/-coverage-report.md` / UID00018X row | not-applicable | applied |
| C052 | 00018Y | Manual by-memory prompt row is synchronized to reconstructable 88%. | exact supervisor readback | command20163 applied payload; current F470 physical readback row 2045 | `by-memory/-coverage-report.md` / UID00018Y row | not-applicable | applied |
| C053 | 00035Y | Manual by-memory coverage now contains the exact new reconstructable 88% handler row. | exact supervisor readback | command20163 applied payload; current F470 physical readback row 2046 | `by-memory/-coverage-report.md` / UID00035Y row | not-applicable | applied |
| C054 | 000296 | Manual by-memory dispatcher-global row is synchronized to reconstructable 88%. | exact supervisor readback | command20163 applied payload; current F470 physical readback row 4588 | `by-memory/-coverage-report.md` / UID000296 row | not-applicable | applied |
| C055 | 000141 | Manual by-memory dispatcher aggregate row is synchronized to reconstructable 87%. | exact supervisor readback | command20163 applied payload; current F470 physical readback row 1373 | `by-memory/-coverage-report.md` / UID000141 row | not-applicable | applied |
| C056 | 0000Z1 | Manual by-memory queue-helper row is synchronized to reconstructable 88%. | exact supervisor readback | command20163 applied payload; current F470 physical readback row 581 | `by-memory/-coverage-report.md` / UID0000Z1 row | not-applicable | applied |
| C057 | 000077 | Manual by-class LineInputPane row is synchronized to reconstructable 93%. | exact supervisor readback | command20164 applied payload; current 9B8B physical readback row 283 | `by-class/-coverage-report.md` / UID000077 row | not-applicable | applied |
| C058 | 00004M | Manual by-class EventDispatcher row is synchronized to reconstructable 89%. | exact supervisor readback | command20164 applied payload; current 9B8B physical readback row 191 | `by-class/-coverage-report.md` / UID00004M row | not-applicable | applied |
| C059 | 0000FQ | Manual by-class UserPane text now records the exact +0x210 active `LineInputPane *` role and clear helper. | exact supervisor readback | command20164 applied payload; current 9B8B physical readback row 589 | `by-class/-coverage-report.md` / UID0000FQ row | not-applicable | applied |
| C060 | 0000K7 | Manual by-file InputPanes row is synchronized to reconstructable 92%. | exact supervisor readback | command20165 applied payload; current 570443 physical readback row 124 | `by-file/-coverage-report.md` / UID0000K7 row | not-applicable | applied |
| C061 | 0000P1 | Manual by-file UserPane text now records the exact +0x210 active `LineInputPane *` role and clear helper. | exact supervisor readback | command20165 applied payload; current 570443 physical readback row 298 | `by-file/-coverage-report.md` / UID0000P1 row | not-applicable | applied |

## Positive Evidence Summary

- Exact current function identity, prototype, size, body, and 37-call fanout.
- Exact constructor-owned vtable stores and stable LineInputPane class route.
- Exact fields and branch-specific reads/writes across constructor and key handler.
- Exact TextBoxPane/TextEditPane allocation sizes and constructor arguments.
- Exact geometry, colors, text limits, line limit, attachment order, and global interactions.
- Existing human source names for most dependencies, including `g_useEpfAssets`, `g_pBackPane`, `g_pApplicationCleanupQueue`, `g_pUserPane`, `GetTextWidth`, and both child classes.
- Stable source placement under `NexusTK/ui/dialogs/InputPanes.cpp` and `InputPanes.h`.

## IDA MCP Facts

Current bounded shared-IDB observation: active session `f608d7c2`, SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, 143,192,665 bytes, saved `2026-07-31T03:00:53.6024151-04:00`. Exact item-by-item `type_query`/`type_inspect`, function lookup/profile/frame/decompile/comment, item/comment/byte, exact-address xref, and exact global-name calls reread A00-A09 and all 36 P00-P04 protected rows and found no action-state or protected-state drift. CF188 is a dated bounded checkpoint rather than permanent authority; fresh Gate 2B must reread every A00-A09 and protected row against the then-current saved IDB before closure. Historical B180 SHA256 `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`, 143,192,467 bytes, saved `2026-07-31T02:40:36.4157748-04:00`, historical F7 SHA256 `F7C936C072D1332D82D06A92F89F3531D97EE8D9252A2C3C6325B2580F8D7D8A`, 143,192,467 bytes, saved `2026-07-30T14:56:51.3756829-04:00`, and supervisor-referenced `9F8...` are superseded dated checkpoints. Catalog-0377 action-time save `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`, remains immutable transaction history. Exact prestate/backup `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94` and session `07b29e1b`, plus saved checkpoints `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, `836ABCFA986AF47A3CAC9EC1D46A31BE6B9B29DA83B6BCA797E7817F2CCF489F`, `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`, `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`, `4EDEC1553CDF85F5EDE5F40475BACA27EE26B3538E22313CED616FE3A4B5D09F`, and former session `1da2b2ae` are dated historical evidence only.

- Target: `LineInputPane__Constructor`, size `0x409`, exact current prototype, regular address comment absent at the function entry, repeatable address comment absent at the function entry, function regular comment present, function repeatable comment absent; the open function interval contains 48 current regular address comments and zero repeatable internal comments.
- Successor: one seven-byte `0xcc` item at `[0x004f2009,0x004f2010)`.
- A03-A07 retain exact ranges, declarations, complete frame inventories, four independent comment-channel states, collision history, and xref counts in the atomic table. Current helpers are `LineInputPane__HandleKeyOrTextEvent`, `EventDispatcher__ArmTextInputGuardTimer`, `BlackHole__QueuePaneForDeferredDeletion`, and `GrafPort__GetTextWidth`; their raw `sub_*` identities are historical prestates only.
- `0x0067ab30` and `0x0067add8` are each one size-four typed/commented data item with zero bytes, unchanged start xrefs, zero interior xrefs, and protected neighbors. Canonical name queries resolve `g_pEventDispatcher` and `g_pChattingVarietyPane`; blank `inspect_items.name` values are a current tool-projection fact, not saved-name loss.
- `g_pUserPane` remains a protected one-item typed global; `unk_69B368` remains a protected shared Layer pointer record.
- `TextBoxPane` exists incomplete/no-layout; `LineInputPane` ordinal 803 is exact size `0x108` with five members; `UserPane` has the bounded active-line-input split through `+0x218` with total size/tail preserved.

## Function / Child Inventory

| Range | Source role | Disposition |
| --- | --- | --- |
| `0x004f1c00-0x004f2009` | `LineInputPane::LineInputPane` | Target, emit exact CPP. |
| `0x004f2009-0x004f2010` | Alignment | Preserve, no source. |
| `0x004f2010-0x004f2092` | Shared LineInputPane cleanup/destructor body | Existing sibling, do not merge. |
| `0x004f20a0-0x004f22f4` | `LineInputPane::SetPromptText` | Existing UID00018Y sibling. |
| `0x004f25a0-0x004f2754` | `LineInputPane::HandleKeyOrTextEvent` | Existing UID00035Y sibling and field/type support. |
| `0x004a6fa0-0x004a6fb2` | `EventDispatcher::ArmTextInputGuardTimer` | EventDispatcher support; supervisor IDA handoff. |
| `0x00469180-0x004691fa` | `BlackHole::QueuePaneForDeferredDeletion` | Existing source-ready support. |
| `0x004ba9a0-0x004baa67` | `GrafPort::GetTextWidth(text,count)` | Existing source-ready support. |
| `0x0058dce0-0x0058e132` | `TextEditPane::TextEditPane` | Existing exact constructor dependency. |
| `0x00595390-0x005954b3` | `TextBoxPane::TextBoxPane` | Existing exact constructor dependency. |

## Direct Xref / Caller Inventory

The 37 exact incoming code xrefs are:

`0x004f27cc`, `0x004f28cc`, `0x004f2a8c`, `0x004f2bac`, `0x004f2c9d`, `0x005a3f2e`, `0x005a45db`, `0x005a4689`, `0x005a5224`, `0x005a52b6`, `0x005a5412`, `0x005a55c0`, `0x005a5690`, `0x005a5762`, `0x005a6301`, `0x005a66bf`, `0x005a9a61`, `0x005aa403`, `0x005adf6c`, `0x005ae2cd`, `0x005aec8d`, `0x005af61c`, `0x005aff1c`, `0x005b15b1`, `0x005b19d1`, `0x005b1f00`, `0x005b2310`, `0x005b349f`, `0x005b34ff`, `0x005b3ced`, `0x005b419b`, `0x005b422f`, `0x005b541a`, `0x005b6b05`, `0x005b6bd0`, `0x005b6c9a`, and `0x005b711a`.

The first five are derived input-pane constructors. The remaining callers are concrete UserPane command/prompt, say/chat, spell/item, social, and dialog routes. This fanout proves reusable base ownership and rejects ownership by any single feature caller.

## Documentation Evidence And IDA Status

The ordinary target now contains the accepted source-ready constructor CPP, UID000077 now declares both live trailing integer fields after the two child pointers, UID0000K7 owns the complete family route, and UID00018X now has the corrected false/non-emitting split-index summary. Those ordinary-document callback results are physically complete and independently verified. Supervisor commands `000000020163`-`000000020165` also applied and read back all twelve exact manual coverage operations C050-C061/M01-M12. Existing TextBoxPane, TextEditPane, BlackHole, and GrafPort documents carry source-ready abstractions, so the target uses normal C++ without inventing stand-ins.

The historical catalog-0377 saved IDA state is source-complete for the bounded UID00035P transaction: target identity/type/comment, incomplete `TextBoxPane`, exact `LineInputPane` and `UserPane` layouts, four canonical helper identities/prototypes/comments, and two materialized singleton slots are present. Remaining lexical uncertainty belongs to source-name confidence, not an unresolved IDA blocker. Manual coverage is supervisor-applied/read back and command20172 completed the generated refresh after that coverage. Fresh Gate 2B currentness verification, independent supervisor verification of the command20172 generated topology, and lifecycle execution remain external supervisor steps rather than source-research gaps.

## Ranked Ownership Analysis

1. [UID:000077][LineInputPane] -> [UID:0000K7][InputPanes]: decisive. Receiver, vtables, fields, derived callers, neighboring methods, and existing source tree all agree.
2. UserPane.cpp: consumer and owner of `m_activeLineInputPane`, not owner of constructor.
3. Chatting.cpp: consumer through singleton refresh only.
4. EventDispatcher.cpp, BlackHole.cpp, GrafPort.cpp, TextBoxPane.cpp, TextEditPane.cpp: dependency owners only.
5. UID00018X aggregate: index/split authority only; false/non-emitting and cannot own source.

## Source Placement

Place the constructor in `NexusTK/ui/dialogs/InputPanes.cpp` through the existing target -> class UID000077 -> file UID0000K7 emitter route. Keep the class declaration in `InputPanes.h`. Do not fold dependency methods or globals into this file. Cross-source use should be expressed through normal declarations/includes, not duplicate definitions or raw forward bodies.

## Range / Split / Padding / Reclassification Analysis

The target exactly fills `[0x004f1c00,0x004f2009)`. Seven `0xcc` bytes occupy `[0x004f2009,0x004f2010)`, then the shared cleanup body begins. No target split is required. The broad UID00018X page remains a false/non-emitting split index. Compiler EH cleanup targets near `0x00600c90`, constructor vtable stores, operator-new wrappers, and security-cookie logic are lowering dependencies, not source children and not reasons to extend this target.

## Negative Evidence Summary

- No direct/additional report already covers UID00035P.
- No evidence supports a caller-owned or Chatting/UserPane-owned constructor.
- No evidence supports leaving `UserPane+0x210` typed as ObjectPane after the constructor/handler correlation.
- No evidence supports monolithic UID00018X emission.
- No evidence supports raw `sub_`, `dword_`, `unk_`, vslot, or stack-temporary names in final C++.
- No evidence supports safety guards, allocation-failure handling, null singleton guards, or branch unification absent from the executable.
- No evidence supports hand-authored vtable stores, SEH state, cookies, or deleting-destructor wrappers.

## IDA Rename / Type / Comment Recommendations

Each row remains atomic. `Prestate` preserves the literal historical state accepted before Gate 2B, `Canonical classification` records the catalog-0377 disposition, and the final column records the exact dated CF188 bounded poststate/protected readback. Historical F7, 9F8, and B180 observations are retained above, but no residual word `current` in A00-A09 or P00-P04 refers to them. Every entity and protected dependency must still be reread item by item against the then-current authority before fresh Gate 2B closure.

| ID | Entity | Prestate | Canonical classification | Exact supervisor action | Expected readback / protected constraint |
| --- | --- | --- | --- | --- | --- |
| A00 | Type `TextBoxPane` | Historical pre-Gate-2B type query: absent. | already present | Supervisor catalog entry 0377 created incomplete `TextBoxPane`; no layout was guessed. | CF188 readback: ordinal 961, declaration `TextBoxPane`, incomplete/no-layout (`size` sentinel `0xffffffffffffffff`), zero members; no fabricated size or fields. |
| A01 | Type `LineInputPane` ordinal 803 | Historical pre-Gate-2B state: incomplete/no-layout, size unknown, zero members. | already present | Supervisor catalog entry 0377 defined size `0x108`: `_paneBase[0xf8]` at +0, `TextBoxPane *m_promptTextPane` +f8, `TextEditPane *m_textEditPane` +fc, `int m_deferredSubmitPending` +100, `int m_deferSubmitUntilNextEvent` +104. | CF188 readback: declaration `LineInputPane`, size `0x108`, exactly five members with those offsets/sizes/types; no target layout drift. |
| A02 | Type `UserPane` ordinal 637 | Historical pre-Gate-2B state: size `0x13eb84`; `_userPaneToGroupMembers` +1c6 size0x52; `m_groupMembers` +218. | already present | Supervisor catalog entry 0377 replaced only the then-opaque span with `_userPaneToActiveLineInput[0x4a]` +1c6, `LineInputPane *m_activeLineInputPane` +210, `_userPaneAfterActiveLineInput[4]` +214. | CF188 readback: declaration `UserPane`, size `0x13eb84`, 68 current catalog members after unrelated accepted work. The protected target slice is exact: current earlier members now end with `m_userPaneBaseStateTail[3]` at +20d; `LineInputPane *m_activeLineInputPane` +210/4; `_userPaneAfterActiveLineInput[4]` +214/4; `GroupMemberRecord m_groupMembers[50]` +218/0x3a98. Every later member/tail and the final `m_currentAppearance` endpoint remain within the unchanged total size. |
| A03 | Function `[0x004f1c00,0x004f2009)` | Current name `LineInputPane__Constructor`; full declaration `LineInputPane *__thiscall LineInputPane__Constructor(LineInputPane *this, const wchar_t *promptText)`. Complete frame: `var_3C` offset `0x10` size `0x4` type `Pane *`; `Block` `0x14`/`0x4`/`void *`; `var_34` `0x18`/`0x4`/`_DWORD`; `bounds` `0x1c`/`0x10`/`struct RectBounds`; `var_20` `0x2c`/`0x1`/`_BYTE`; `var_10` `0x3c`/`0x4`/`_DWORD`; `var_C` `0x40`/`0x4`/`_DWORD`; `var_4` `0x48`/`0x4`/`_DWORD`; `__saved_registers` `0x4c`/`0x4`/`_DWORD`; `__return_address` `0x50`/`0x4`/`_UNKNOWN *`; `promptText` `0x54`/`0x4`/`const wchar_t *`; `arg_4` `0x58`/`0x4`/`_DWORD`. Function-entry address regular: absent. Function-entry address repeatable: absent. Function regular: `Constructs the shared line-input pane, its optional prompt label, and its editable text child, then registers the active input pane.` Function repeatable: absent. Open-interval comments: 48 current regular address comments enumerated immediately after A09; zero repeatable internal comments. The former empty-internal-comment assertion is disproved historical presentation. Collision: no rename proposed; exact current name resolves uniquely at `0x004f1c00`. | already present | No mutation: preserve exact current name, declaration, complete frame, all four entry comment channels, all 48 regular internal address comments, bytes/range, and xrefs. | CF188 readback: same unique name/declaration/frame/entry comments; Hex-Rays arguments `LineInputPane *this`, `const wchar_t *promptText`; locals `v3`, `v4`, `v5`, `v6`, `v7`, `v8`, `v9`, `m_promptTextPane`, `v11`, `v12`, `v13`, `v14`, `v15`, `v16`, `v17`, `v18`, `RectBounds bounds`, `v21[16]`, and `v22`; exact 48 regular internal comments and zero repeatable internal comments over `[0x004f1c00,0x004f2009)`; byte SHA `36A98D99F3530A76FAF60618D4F29F7598E9973FDF81B036C16B500D2970A561`; all 37 incoming xrefs and seven-byte successor padding unchanged. |
| A04 | Function `[0x004f25a0,0x004f2754)` | Historical pre-Gate-2B name `sub_4F25A0`; declaration `char __thiscall sub_4F25A0(TimerHandler *this, _BYTE *)`. Complete frame: `__saved_registers` offset `0x8` size `0x4` type `_DWORD`; `__return_address` `0xc`/`0x4`/`_UNKNOWN *`; `arg_0` `0x10`/`0x4`/`_DWORD`; no other modeled locals/arguments. Address regular: absent. Address repeatable: absent. Function regular: absent. Function repeatable: absent. Proposed-name collision: `LineInputPane__HandleKeyOrTextEvent` NOT_FOUND. Older checkpoint `4EDEC155...` presented `_DWORD *this`; accepted prestate used `TimerHandler *this`. | already present | Supervisor catalog entry 0377 renamed `LineInputPane__HandleKeyOrTextEvent`; applied `bool __thiscall(EventHandler *this, Event *event)`; function regular `Handles LineInputPane Enter, Escape, Tab, deferred-submit, owner-notify, and edit-child forwarding behavior.`; function repeatable `bool LineInputPane::HandleKeyOrTextEvent(Event *event);`; address regular/repeatable remain absent. | CF188 readback: canonical unique name/declaration/comments; frame `__saved_registers +0x8/4 _DWORD`, `__return_address +0xc/4 _UNKNOWN *`, `event +0x10/4 Event *`; Hex-Rays arguments `EventHandler *this`, `Event *event` and locals `v3`, `v4`, `v5`, `v7`, `v8`; secondary-facet ABI, exact bytes, all 27 xrefs, internal comments, and range unchanged. |
| A05 | Function `[0x004a6fa0,0x004a6fb2)` | Historical pre-Gate-2B name `sub_4A6FA0`; declaration `void __thiscall sub_4A6FA0(TimerHandler *this)`. Complete frame: `__return_address` offset `0x0` size `0x4` type `_UNKNOWN *`; no other modeled locals/arguments. Address regular: exact `arg1`. Address repeatable: absent. Function regular: absent. Function repeatable: absent. Proposed-name collision: `EventDispatcher__ArmTextInputGuardTimer` NOT_FOUND. | already present | Supervisor catalog entry 0377 renamed `EventDispatcher__ArmTextInputGuardTimer`; applied `void __thiscall(EventDispatcher *this)`; cleared stale address regular `arg1`; left address repeatable absent; function regular `Arms the short text-input guard by setting the dispatcher guard flag and scheduling timer id 0 after 10 ms.`; function repeatable `void EventDispatcher::ArmTextInputGuardTimer();`. | CF188 readback: canonical unique name/declaration; address regular/repeatable absent; exact function comments; sole `__return_address +0x0/4 _UNKNOWN *` frame record; Hex-Rays argument `EventDispatcher *this`, no locals; exact bytes and both xrefs unchanged. |
| A06 | Function `[0x00469180,0x004691fa)` | Historical pre-Gate-2B name `sub_469180`; declaration `void __thiscall sub_469180(_DWORD *this, TimerHandler *)`. Complete frame: `__saved_registers` offset `0x8` size `0x4` type `_DWORD`; `__return_address` `0xc`/`0x4`/`_UNKNOWN *`; `arg_0` `0x10`/`0x4`/`_DWORD`; no other modeled locals/arguments. Address regular/repeatable: absent. Function regular/repeatable: absent. Proposed-name collision: `BlackHole__QueuePaneForDeferredDeletion` NOT_FOUND. | already present | Supervisor catalog entry 0377 renamed `BlackHole__QueuePaneForDeferredDeletion`; applied `void __thiscall(BlackHole *this, Pane *pane)`; function regular `Detaches a pane, unregisters input and timers, and queues it once for deferred deletion.`; function repeatable `void BlackHole::QueuePaneForDeferredDeletion(Pane *pane);`; address regular/repeatable remain absent. | CF188 readback: canonical unique name/declaration/comments; frame `__saved_registers +0x8/4 _DWORD`, `__return_address +0xc/4 _UNKNOWN *`, `pane +0x10/4 Pane *`; Hex-Rays arguments `BlackHole *this`, `Pane *pane` and locals `v2`, `v4`, `v5`, `v6`; internal `this`/`owner` comments, exact bytes, all 83 xrefs, and list semantics unchanged. |
| A07 | Function `[0x004ba9a0,0x004baa67)` | Historical pre-Gate-2B name `sub_4BA9A0`; declaration `__int16 __thiscall sub_4BA9A0(__int16 *this, int, __int16)`. Complete frame: `var_28` offset `0x10` size `0x10` type `_DWORD[4]`; `var_18` `0x20`/`0x4`/`FontImageLib *`; `var_14` `0x24`/`0x4`/`_DWORD`; `var_10` `0x28`/`0x4`/`_DWORD`; `var_C` `0x2c`/`0x4`/`_DWORD`; `var_4` `0x34`/`0x4`/`_DWORD`; `__saved_registers` `0x38`/`0x4`/`_DWORD`; `__return_address` `0x3c`/`0x4`/`_UNKNOWN *`; `arg_0` `0x40`/`0x4`/`_DWORD`; `outAdvance` `0x44`/`0x2`/`__int16`; no other modeled locals/arguments. Address regular/repeatable and function regular/repeatable: absent. Proposed-name collision: `GrafPort__GetTextWidth` NOT_FOUND. | already present | Supervisor catalog entry 0377 renamed `GrafPort__GetTextWidth`; applied `short __thiscall(GrafPort *this, const wchar_t *text, int charCount)`; function regular `Measures a UTF-16 text span by summing FontImageLib glyph advances for the active GrafPort font.`; function repeatable `short GrafPort::GetTextWidth(const wchar_t *text, int charCount) const;`; address regular/repeatable remain absent. | CF188 readback: canonical unique name/declaration/comments; every frame record retained; physical arguments remain `text +0x40/4 const wchar_t *` and historical `outAdvance +0x44/2 __int16` while the prototype carries `int charCount`; Hex-Rays arguments `GrafPort *this`, `const wchar_t *text`, `int charCount` and locals `v3`, `v4`, `v5`, `i`, `v8[4]`, `v9`, `v10`, `v11`, `v12`; exact bytes, all 117 xrefs, and aggregate neighbors unchanged. No direct stack edit was saved. |
| A08 | Global 0x0067ab30 | Historical pre-Gate-2B state: four one-byte non-data items; first type `EventDispatcher *`; global query resolved `g_pEventDispatcher` while item-level name was blank; regular/repeatable absent; zero bytes. | already present | Supervisor catalog entry 0377 materialized `[0x67ab30,0x67ab34)`, saved name `g_pEventDispatcher`, type `EventDispatcher *`, regular `Process-wide EventDispatcher singleton pointer used by UI event routing and text-input guard scheduling.`, repeatable `EventDispatcher *g_pEventDispatcher;`. | CF188 readback: one four-byte data item with exact type/comments; exact global-name query uniquely resolves `g_pEventDispatcher` at `0x67ab30` while `inspect_items.name` is blank as a tool-projection fact; bytes `00 00 00 00`, 86 start xrefs, zero interior xrefs. Protected predecessor `[0x67ab2c,0x67ab30)` is four one-byte non-data heads and successor `0x67ab34` remains one protected head typed `ExceptionHandler *`. |
| A09 | Global 0x0067add8 | Historical pre-Gate-2B state: four one-byte non-data items; first type `ChattingVarietyPane *`; global query resolved `g_pChattingVarietyPane` while item-level name was blank; regular/repeatable absent; zero bytes. | already present | Supervisor catalog entry 0377 materialized `[0x67add8,0x67addc)`, saved name `g_pChattingVarietyPane`, type `ChattingVarietyPane *`, regular `Active ChattingVarietyPane singleton pointer used by chat-mode selection and bounds invalidation.`, repeatable `ChattingVarietyPane *g_pChattingVarietyPane;`. | CF188 readback: one four-byte data item with exact type/comments; exact global-name query uniquely resolves `g_pChattingVarietyPane` at `0x67add8` while `inspect_items.name` is blank as a tool-projection fact; bytes `00 00 00 00`, 18 start xrefs, zero interior xrefs. Protected predecessor `[0x67add4,0x67add8)` and successor `[0x67addc,0x67ade0)` each comprise four one-byte non-data heads. |

A03 current regular internal address-comment inventory, recorded exactly from the bounded read-only open-interval query; every corresponding repeatable comment is absent:

- `0x004f1c33 layerPane`; `0x004f1d3a useThousandsSeparator`; `0x004f1d44 useDefaultAlignment`; `0x004f1d4b legacyAssetMode`; `0x004f1d4c editorFlags`; `0x004f1d51 hasVerticalScrollbar`; `0x004f1d53 hasHorizontalScrollbar`; `0x004f1d55 textBackColor`.
- `0x004f1d57 textColor`; `0x004f1d5c textAreaHeight`; `0x004f1d5e textAreaWidth`; `0x004f1d5f viewportHeight`; `0x004f1d61 viewportWidth`; `0x004f1d62 this`; `0x004f1d8d bottom`; `0x004f1d92 right`.
- `0x004f1d97 top`; `0x004f1d9f left`; `0x004f1da1 bounds`; `0x004f1db3 this`; `0x004f1db5 layer`; `0x004f1db6 previousPane`; `0x004f1dbc order`; `0x004f1dbe bounds`.
- `0x004f1efa useThousandsSeparator`; `0x004f1f04 useDefaultAlignment`; `0x004f1f0b legacyAssetMode`; `0x004f1f0c editorFlags`; `0x004f1f11 hasVerticalScrollbar`; `0x004f1f13 hasHorizontalScrollbar`; `0x004f1f15 textBackColor`; `0x004f1f1a textColor`.
- `0x004f1f1f textAreaHeight`; `0x004f1f21 textAreaWidth`; `0x004f1f22 viewportHeight`; `0x004f1f24 viewportWidth`; `0x004f1f25 this`; `0x004f1f50 bottom`; `0x004f1f55 right`; `0x004f1f5a top`.
- `0x004f1f62 left`; `0x004f1f64 bounds`; `0x004f1f76 this`; `0x004f1f78 layer`; `0x004f1f79 previousPane`; `0x004f1f7f order`; `0x004f1f81 bounds`; `0x004f1ffc StackCookie`.

Protected read-only dependencies are atomized below. Data entities use address-comment channels; their function-comment channels are explicitly not applicable. Function entities state the complete modeled frame/local inventory available in the accepted evidence. No row authorizes a new IDA action.

| ID | Exact entity / range | Literal saved state, declaration, and frame/local inventory | Address regular | Address repeatable | Function regular | Function repeatable | Collision / protected readback |
| --- | --- | --- | --- | --- | --- | --- | --- |
| P00 | `0x0067a748-0x0067a74c` `g_pUserPane` | One size-4 data item; name `g_pUserPane`; type `UserPane *`; bytes `00 00 00 00`; 505 direct refs; UserPane lifetime/clear ownership. | `Active complete UserPane singleton used by packet and group-state routes.` | absent | N/A: data item | N/A: data item | No action and no collision. Exact item/name/type/comment/xref/byte state is protected. |
| P01 | `0x0069b368-0x0069b369` shared root-layer context | One size-1 non-data item; name `unk_69B368`; type `Layer *`; source-facing role `rootPaneLayerContext`; no independent source/global action. | absent | absent | N/A: data item | N/A: data item | No action and no collision. Preserve the one-byte analysis head and surrounding loader-zero root-layer storage; do not materialize or rename it in this transaction. |
| P02-01 | Target `[0x004f1c00,0x004f2009)` | Exact size `0x409`; byte SHA256 `36A98D99F3530A76FAF60618D4F29F7598E9973FDF81B036C16B500D2970A561`; first 16 bytes `55 8B EC 6A FF 68 C4 0C 60 00 64 A1 00 00 00 00`; 37 incoming refs. Complete modeled frame/local inventory is the A03 row. The current open interval contains the 48 exact regular address comments enumerated above and zero repeatable internal comments; the former empty-set assertion is disproved historical presentation. | absent at function start; 48 exact internal regular comments listed above | absent at function start and at every internal comment address | `Constructs the shared line-input pane, its optional prompt label, and its editable text child, then registers the active input pane.` | absent | A03 already has the sole current function identity. Preserve all bytes, range, frame records, xrefs, and the complete 48-entry regular internal-comment inventory. |
| P02-02 | Successor `[0x004f2009,0x004f2010)` | Exact seven alignment bytes `CC CC CC CC CC CC CC`; non-function, non-source padding. | absent | absent | N/A: padding | N/A: padding | No action. Preserve the exact target/successor boundary and all seven bytes. |
| P03-01 | `0x0067a740-0x0067a744` | CF188: one size-4 data item named `g_pBackPane`, type `BackPane *`, bytes `00 00 00 00`, 106 refs; exact global query resolves only `g_pBackPane`; catalog0134 supplied the saved source identity/type. | `Process-wide BackPane parent/context pointer (source-facing g_pBackPane).` | absent | N/A: data item | N/A: data item | No action/collision. Preserve exact item, source identity/type, 106 refs, bytes, comments, and neighbors. |
| P03-02 | `0x0067a748-0x0067a74c` | Exact `g_pUserPane` record is independently specified by P00. | exact P00 regular text | absent | N/A: data item | N/A: data item | Cross-reference only; no duplicate action. |
| P03-03 | `0x0067a74c-0x0067a750` | CF188: one size-4 data item named `g_pApplicationCleanupQueue`, type `BlackHole *`, bytes `00 00 00 00`, 72 refs; exact global query resolves only `g_pApplicationCleanupQueue`; exact deferred-deletion singleton role. | `BlackHole deferred-deletion queue singleton pointer (source-facing g_pApplicationCleanupQueue).` | absent | N/A: data item | N/A: data item | No action/collision. Preserve the singleton item/type/bytes/72 refs, comments, and predecessor/successor boundaries. |
| P03-04 | `0x0067a750-0x0067a754` | CF188: one size-4 data item named `g_pLanguageMan`, type `LanguageMan *`, bytes `00 00 00 00`, 192 refs; exact global query resolves only `g_pLanguageMan`; catalog0245 materialized the canonical identity/type. | `Sole externally linked LanguageMan singleton pointer. Canonical source identity is g_pLanguageMan; historical dword_67A750, DAT_0067a750, and g_pStringTable aliases are rejected.` | absent | N/A: data item | N/A: data item | No action/collision. Preserve the item, 192 refs, bytes, exact comments, and `g_pEventMan` successor. |
| P03-05 | `0x0067ab2c-0x0067ab30` | Four independent one-byte non-data heads at `0x67ab2c`, `0x67ab2d`, `0x67ab2e`, and `0x67ab2f`; first head type `ChangeMan *`, three interior types blank; canonical name query resolves `g_pChangeMan` while item projection is blank; bytes `00 00 00 00`; 11 start refs. | absent | absent | N/A: data heads | N/A: data heads | No action/collision. Preserve all four one-byte heads, blank comments, first-head type, canonical query identity, 11 refs, bytes, and the `g_pEventDispatcher` successor boundary. |
| P03-06 | `0x0067ab30-0x0067ab34` | One size-4 data item, type `EventDispatcher *`, bytes `00 00 00 00`, 86 start refs and zero interior refs; canonical name query resolves `g_pEventDispatcher` while `inspect_items.name` is blank. | `Process-wide EventDispatcher singleton pointer used by UI event routing and text-input guard scheduling.` | `EventDispatcher *g_pEventDispatcher;` | N/A: data item | N/A: data item | A08 is already present; preserve exact item/type/comments/xrefs, canonical query identity, projection discrepancy, and both neighbors. |
| P03-07 | `0x0067ab34-0x0067ab35` protected successor head | One size-1 non-data item named `unk_67AB34`, type `ExceptionHandler *`; separate from the EventDispatcher slot. | absent | absent | N/A: data item | N/A: data item | No action/collision. Do not merge, rename, retype, or comment this neighbor. |
| P03-08 | `0x0067add4-0x0067add8` | Four independent one-byte non-data heads at `0x67add4`, `0x67add5`, `0x67add6`, and `0x67add7`; first head type `ChattingModifyHeightPane *`, three interior types blank; canonical name query resolves `g_pChattingModifyHeightPane`; loader-zero bytes `00 00 00 00`; seven start refs. | absent | absent | N/A: data heads | N/A: data heads | No action/collision. Preserve all four heads, blank comments, first-head type, canonical query identity, bytes/refs, and both singleton neighbors. |
| P03-09 | `0x0067add8-0x0067addc` | One size-4 data item, type `ChattingVarietyPane *`, loader-zero bytes `00 00 00 00`, 18 start refs and zero interior refs; canonical name query resolves `g_pChattingVarietyPane` while `inspect_items.name` is blank. | `Active ChattingVarietyPane singleton pointer used by chat-mode selection and bounds invalidation.` | `ChattingVarietyPane *g_pChattingVarietyPane;` | N/A: data item | N/A: data item | A09 is already present; preserve exact item/type/comments/xrefs, canonical query identity, projection discrepancy, and both neighbors. |
| P03-10 | `0x0067addc-0x0067ade0` | Four independent one-byte non-data heads at `0x67addc`, `0x67addd`, `0x67adde`, and `0x67addf`; first head type `ChattingVarietySelectPane *`, three interior types blank; canonical name query resolves `g_pChattingVarietySelectPane` while item projection is blank; loader-zero bytes `00 00 00 00`; seven start refs. | absent | absent | N/A: data heads | N/A: data heads | No action/collision. Preserve all four heads, blank comments, first-head type, canonical query identity, bytes/refs, and the `g_pChattingVarietyPane` predecessor. |
| P04-R01 | `0x0061ca54-0x0061ca58` LineInputPane primary RTTI locator pointer cell | CF188: unnamed size-4 data pointer; bytes `AC 99 64 00`; zero xrefs; points to size-4 descriptor head `0x006499ac` named `??_R4LineInputPane@@6B@`. Pointer-cell comments are absent/absent; descriptor comments are regular `signature`, repeatable absent. The pointer cell itself is not the named descriptor. | absent | absent | N/A: RTTI data | N/A: RTTI data | No action/collision. Preserve the unnamed pointer cell, descriptor name/location/comments, bytes, zero refs, and Layer/LineInputPane boundary. |
| P04-V01 | `0x0061ca58-0x0061caa4` LineInputPane primary vtable | Named table `??_7LineInputPane@@6B@`; exact primary view regenerated from the class declaration; constructor stores table base at `0x004f1c3d`. | absent | absent | N/A: vtable data | N/A: vtable data | No action/collision. Preserve every slot/dword and compiler-only disposition. |
| P04-R02 | `0x0061caa4-0x0061caa8` LineInputPane secondary RTTI locator pointer cell | CF188: unnamed size-4 data pointer; bytes `08 9A 64 00`; zero xrefs; points to size-4 descriptor head `0x00649a08` named `??_R4LineInputPane@@6B@_0`. Pointer-cell comments are absent/absent; descriptor comments are regular `signature`, repeatable absent. The pointer cell itself is not the named descriptor. | absent | absent | N/A: RTTI data | N/A: RTTI data | No action/collision. Preserve the unnamed pointer cell, descriptor name/location/comments, bytes, zero refs, and boundary. |
| P04-V02 | `0x0061caa8-0x0061cad4` LineInputPane secondary vtable | Named table `??_7LineInputPane@@6B@_0`; exact secondary view; constructor stores table base at `0x004f1c43`. | absent | absent | N/A: vtable data | N/A: vtable data | No action/collision. Preserve every slot/dword and compiler-only disposition. |
| P04-R03 | `0x0061cad4-0x0061cad8` LineInputPane tertiary RTTI locator pointer cell | CF188: unnamed size-4 data pointer; bytes `1C 9A 64 00`; zero xrefs; points to size-4 descriptor head `0x00649a1c` named `??_R4LineInputPane@@6B@_1`. Pointer-cell comments are absent/absent; descriptor comments are regular `signature`, repeatable absent. The pointer cell itself is not the named descriptor. | absent | absent | N/A: RTTI data | N/A: RTTI data | No action/collision. Preserve the unnamed pointer cell, descriptor name/location/comments, bytes, zero refs, and boundary. |
| P04-V03 | `0x0061cad8-0x0061cae0` LineInputPane tertiary vtable | Named table `??_7LineInputPane@@6B@_1`; exact tertiary view; constructor stores table base at `0x004f1c4d`. | absent | absent | N/A: vtable data | N/A: vtable data | No action/collision. Preserve every slot/dword and the NumberInputPane successor boundary. |
| P04-W01 | `[0x004f4aa0,0x004f4ab4)` allocation wrapper | CF188 IDA identity `sub_4F4AA0`, exact size `0x14`; literal saved declaration `void *__cdecl sub_4F4AA0(size_t pExceptionObject)`. Complete physical frame: `__saved_registers +0x0/4 _DWORD`; `__return_address +0x4/4 _UNKNOWN *`; `pExceptionObject +0x8/4 int`. Hex-Rays argument is `size_t pExceptionObject`; sole local is `MemoryMan *MemoryMan`. The physical frame type mismatch is analysis presentation; source-facing role is a global MemoryMan-backed allocation wrapper and handwritten C++ uses ordinary `new`/semantic size without requesting an IDA change. | absent | absent | absent | absent | No target-local rename/type/comment action; preserve the literal declaration/frame, Hex-Rays inventory, wrapper, two-callee route, 1,785 refs, and padding. |
| P04-F01 | `[0x004f24f0,0x004f257a)` hit-test forwarder | CF188 IDA identity `sub_4F24F0`, size `0x8a`; saved declaration `int __thiscall sub_4F24F0(__int16 *this, int)`. Complete physical frame: `var_4 +0x0/4 _DWORD`; `__saved_registers +0x4/4 _DWORD`; `__return_address +0x8/4 _UNKNOWN *`; `arg_0 +0xc/4 _DWORD`. Hex-Rays arguments are `__int16 *this`, `int a2`; locals are `v3`, `v4`, `v5`, `v6`, `result`, and stack local `v8`. | absent | absent | absent | absent | No action/collision. Preserve exact declaration/frame/Hex-Rays inventory, 45 vtable refs, bytes, range, and source-facing `HitTestEditChild` inference without forcing an IDA rename. |
| P04-F02 | `[0x004f2580,0x004f2598)` active-child forwarder | CF188 IDA identity `sub_4F2580`, size `0x18`; declaration `int __thiscall sub_4F2580(_DWORD *this)`. Complete physical frame: `__saved_registers +0x0/4 _DWORD`; `__return_address +0x4/4 _UNKNOWN *`; no modeled locals or stack arguments. Hex-Rays has sole register argument `_DWORD *this` and no locals. | absent | absent | absent | absent | No action/collision. Preserve exact bytes/range, declaration/frame/Hex-Rays inventory, and all 49 vtable refs; source-facing role remains `GetActiveChild`. |
| P04-F03 | `[0x004f2760,0x004f2783)` text-edit forwarder | CF188 IDA identity `sub_4F2760`, size `0x23`; declaration `int __thiscall sub_4F2760(_DWORD *this)`. Complete physical frame: `__saved_registers +0x0/4 _DWORD`; `__return_address +0x4/4 _UNKNOWN *`; no modeled locals or stack arguments. Hex-Rays has sole register argument `_DWORD *this` and no locals. | absent | absent | absent | absent | No action/collision. Preserve exact bytes/range, declaration/frame/Hex-Rays inventory, and all 45 vtable refs; source-facing role remains `ForwardTextEditEvent`. |
| P04-F04 | `[0x004f2790,0x004f2791)` no-op virtual | CF188 IDA identity `nullsub_38`, size `0x1`; declaration `void nullsub_38(void)`; complete physical frame is the sole `__return_address +0x0/4 _UNKNOWN *` record. Hex-Rays has no arguments and no locals. | absent | absent | absent | absent | Intentionally retained compiler/analysis identity; preserve the sole `C3` return byte, declaration/frame/Hex-Rays presentation, and all 49 vtable refs. |
| P04-D01 | `[0x004f2dd0,0x004f2e59)` complete destructor | CF188 IDA identity `sub_4F2DD0`, size `0x89`; saved profile declaration `void __thiscall sub_4F2DD0(_DWORD *this)`. Complete physical frame: `var_C +0x8/4 _DWORD`; `var_4 +0x10/4 _DWORD`; `__saved_registers +0x14/4 _DWORD`; `__return_address +0x18/4 _UNKNOWN *`; `this` register-passed. Current Hex-Rays presentation refines the argument to `Pane *this` and has sole local `Pane *v2`; this is decompiler presentation, not a saved prototype action. | absent | absent | absent | absent | No action/collision. Preserve saved declaration/frame, Hex-Rays presentation, vtable stores, two child-release checks, inherited cleanup tail, all 39 refs, and source-facing complete-destructor disposition. |
| P04-T01 | `[0x004f2e59,0x004f2e64)` secondary adjustor thunk | CF188 identity `sub_4F2E59`, size `0x0b`; declaration `_DWORD *__thiscall sub_4F2E59(_DWORD *this, char)`. Complete physical frame contains only `__return_address +0x0/4 _UNKNOWN *`; Hex-Rays arguments are `_DWORD *this`, `char a2`, with no locals. Subtracts `0xa0`, tail-jumps `0x004f2ea0`. | absent | absent | absent | absent | Intentionally retained compiler thunk; preserve five secondary-vtable refs, prototype/frame/Hex-Rays presentation, and exact body. |
| P04-T02 | `[0x004f2e64,0x004f2e6f)` tertiary adjustor thunk | CF188 identity `sub_4F2E64`, size `0x0b`; declaration `_DWORD *__thiscall sub_4F2E64(_DWORD *this, char)`. Complete physical frame contains only `__return_address +0x0/4 _UNKNOWN *`; Hex-Rays arguments are `_DWORD *this`, `char a2`, with no locals. Subtracts `0xa4`, tail-jumps `0x004f2ea0`. | absent | absent | absent | absent | Intentionally retained compiler thunk; preserve five tertiary-vtable refs, prototype/frame/Hex-Rays presentation, and exact body. |
| P04-T03 | `[0x004f2e6f,0x004f2e7a)` CharInputPane secondary adjustor | CF188 identity `sub_4F2E6F`, size `0x0b`; declaration `_DWORD *__thiscall sub_4F2E6F(_DWORD *this, char)`. Complete physical frame contains only `__return_address +0x0/4 _UNKNOWN *`; Hex-Rays arguments are `_DWORD *this`, `char a2`, with no locals. Subtracts `0xa0`, tail-jumps `0x004f2f70`. | absent | absent | absent | absent | Intentionally retained compiler thunk; preserve sole secondary-vtable ref, prototype/frame/Hex-Rays presentation, and exact body. |
| P04-T04 | `[0x004f2e7a,0x004f2e85)` CharInputPane tertiary adjustor | CF188 identity `sub_4F2E7A`, size `0x0b`; declaration `_DWORD *__thiscall sub_4F2E7A(_DWORD *this, char)`. Complete physical frame contains only `__return_address +0x0/4 _UNKNOWN *`; Hex-Rays arguments are `_DWORD *this`, `char a2`, with no locals. Subtracts `0xa4`, tail-jumps `0x004f2f70`. | absent | absent | absent | absent | Intentionally retained compiler thunk; preserve sole tertiary-vtable ref, prototype/frame/Hex-Rays presentation, and exact body. |
| P04-T05 | `[0x004f2e85,0x004f2e90)` ConfirmInputPane secondary adjustor | CF188 identity `sub_4F2E85`, size `0x0b`; declaration `_DWORD *__thiscall sub_4F2E85(_DWORD *this, char)`. Complete physical frame contains only `__return_address +0x0/4 _UNKNOWN *`; Hex-Rays arguments are `_DWORD *this`, `char a2`, with no locals. Subtracts `0xa0`, tail-jumps `0x004f2fb0`. | absent | absent | absent | absent | Intentionally retained compiler thunk; preserve sole secondary-vtable ref, prototype/frame/Hex-Rays presentation, and exact body. |
| P04-T06 | `[0x004f2e90,0x004f2e9b)` ConfirmInputPane tertiary adjustor | CF188 identity `sub_4F2E90`, size `0x0b`; declaration `_DWORD *__thiscall sub_4F2E90(_DWORD *this, char)`. Complete physical frame contains only `__return_address +0x0/4 _UNKNOWN *`; Hex-Rays arguments are `_DWORD *this`, `char a2`, with no locals. Subtracts `0xa4`, tail-jumps `0x004f2fb0`. | absent | absent | absent | absent | Intentionally retained compiler thunk; preserve sole tertiary-vtable ref, prototype/frame/Hex-Rays presentation, exact body, and `0x004f2e9b-0x004f2ea0` padding. |
| P04-D02 | `[0x004f2ea0,0x004f2f63)` scalar deleting destructor | CF188 IDA identity `sub_4F2EA0`, size `0xc3`; saved profile declaration `_DWORD *__thiscall sub_4F2EA0(_DWORD *Block, char)`. Complete physical frame: `var_C +0x8/4 _DWORD`; `var_4 +0x10/4 _DWORD`; `__saved_registers +0x14/4 _DWORD`; `__return_address +0x18/4 _UNKNOWN *`; `arg_0 +0x1c/4 _DWORD`. Current Hex-Rays presentation is `Pane *__thiscall sub_4F2EA0(Pane *Block, char a2)` with sole local `Pane *v3`; this is decompiler presentation, not a saved prototype action. | absent | absent | absent | absent | Intentionally compiler-lowered scalar wrapper; preserve five primary-vtable refs, exact saved prototype/frame, Hex-Rays presentation, adjustor tails, child cleanup, delete-flag test, and range/padding. |
| P04-E01 | Code at `0x00600cc4` `SEH_4F1C00` | Current code label `SEH_4F1C00`, first bytes `8B 54 24 08`, one xref; begins a compiler handler fragment leading to `___CxxFrameHandler3`. It is not a descriptor pointer and no unsupported source-body range is inferred. | absent | absent | N/A: code label, no modeled source function | N/A: code label, no modeled source function | No action/collision. Preserve code identity, bytes, one xref, blank address comments, cleanup relation, and compiler-only disposition. |
| P04-E02 | `0x00672f24-0x00672f28` `___security_cookie` | One size-4 data item; name `___security_cookie`; type `uintptr_t`; bytes `4E E6 40 BB`; 2,897 refs; read at `0x004f1c14` and XORed with `EBP`. | absent | absent | N/A: compiler data | N/A: compiler data | No action/collision. Preserve address/name/type/bytes/comments and every non-target consumer. |
| P04-E03 | `[0x005c772f,0x005c7740)` `@__security_check_cookie@4` | CF188 compiler/runtime helper, size `0x11`; saved profile declaration `void __fastcall @__security_check_cookie@4(uintptr_t StackCookie)`; complete physical frame contains only `__return_address +0x0/4 _UNKNOWN *`. Hex-Rays presents `void __fastcall __security_check_cookie(uintptr_t StackCookie)` with no locals; called at `0x004f1ffe`; 4,321 xrefs. | absent | absent | absent | absent | No action/collision. Preserve exact helper identity, saved prototype/frame, Hex-Rays presentation, blank four comment channels, ABI, bytes, and all shared callers; emit no handwritten LineInputPane source body. |

## First-Draft C++ Recommendation

Exact target `RECONSTRUCTION_CPP` payload:

```cpp
LineInputPane::LineInputPane(const wchar_t *promptText)
    : Pane(1),
      m_promptTextPane(NULL),
      m_textEditPane(NULL),
      m_deferredSubmitPending(0),
      m_deferSubmitUntilNextEvent(0)
{
    RectBounds paneBounds;
    RectBounds childBounds;
    short promptWidth = 0;

    if (g_useEpfAssets) {
        if (g_pUserPane->m_activeLineInputPane != NULL) {
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(
                g_pUserPane->m_activeLineInputPane);
        }

        if (promptText != NULL) {
            promptWidth = GetTextWidth(promptText, (int)wcslen(promptText)) + 1;
            m_promptTextPane = new TextBoxPane(
                promptWidth, 12, false, 128, 0, promptText);
        }

        const int editWidth = 593 - promptWidth;
        m_textEditPane = new TextEditPane(
            editWidth, 12, editWidth, 12, 128, 0,
            false, false, 0x100, IsLegacyAssetMode(), true, false);
        m_textEditPane->SetMaxLength(80);
        m_textEditPane->SetMaxLines(1);
        InitRectBounds(&paneBounds, 100, 733, 693, 745);
    } else {
        if (promptText != NULL) {
            promptWidth = GetTextWidth(promptText, (int)wcslen(promptText)) + 1;
            m_promptTextPane = new TextBoxPane(
                promptWidth, 12, false, 128, 143, promptText);
        }

        const int editWidth = 408 - promptWidth;
        m_textEditPane = new TextEditPane(
            editWidth, 12, editWidth, 12, 128, 143,
            false, false, 0x100, IsLegacyAssetMode(), true, false);
        m_textEditPane->SetMaxLength(50);
        m_textEditPane->SetMaxLines(1);
        InitRectBounds(&paneBounds, 14, 456, 422, 468);
    }

    AddToLayer(&paneBounds, 0, g_pBackPane, rootPaneLayerContext);

    if (m_promptTextPane != NULL) {
        m_promptTextPane->GetBounds(&childBounds);
        m_promptTextPane->AddToLayer(
            &childBounds, 0, this, rootPaneLayerContext);
    }

    m_textEditPane->GetBounds(&childBounds);
    childBounds.left = promptWidth;
    m_textEditPane->AddToLayer(
        &childBounds, 0, this, rootPaneLayerContext);

    SetPaneOrder(0, g_pBackPane);
    g_pEventDispatcher->ArmTextInputGuardTimer();

    if (g_useEpfAssets) {
        g_pUserPane->m_activeLineInputPane = this;
        g_pChattingVarietyPane->Refresh();
    }
}
```

The target H payload remains blank. The exact replacement H payload belongs in UID000077:

```cpp
class Event;
class TextBoxPane;
class TextEditPane;
struct InputKeyEvent;
struct RectBounds;

class LineInputPane : public Pane
{
public:
    LineInputPane(const wchar_t *promptText);
    virtual ~LineInputPane();

    void SetPromptText(const wchar_t *promptText);
    void CopyText(wchar_t *buffer, short maxChars) const;
    short TextLength() const;

    virtual void UpdateChildLayout();
    virtual void AttachChildren();
    virtual void ShowChildren();
    virtual bool HitTestEditChild(int x, int y);
    virtual Pane *GetActiveChild();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool ForwardTextEditEvent(InputKeyEvent *event);
    virtual void OnNoOpInputPaneSlot();

protected:
    TextBoxPane *m_promptTextPane;
    TextEditPane *m_textEditPane;
    int m_deferredSubmitPending;
    int m_deferSubmitUntilNextEvent;
};
```

The method/global names are source-facing inferences, but none is left raw. `Refresh()` is the least speculative project-consistent name for the exact no-argument ChattingVarietyPane forwarder; its lexical spelling remains the target's minor confidence cap.

## Final Recommendation

The accepted ordinary implementation is physically complete for C001-C047 and supervisor Gate 2A verified it. Historical catalog entry 0377 applied/read back/saved A00-A09, but this changed report still requires a fresh supervisor Gate 1 followed by fresh supervisor Gate 2B currentness verification; it makes no current Gate 2B closure claim. Supervisor commands `000000020163`-`000000020165` applied and read back C050-C061/M01-M12 exactly, with generated refresh disabled; supervisor command `000000020172` subsequently completed the generated refresh. The target is source-ready at `92/94`; remaining uncertainty is lexical, not behavioral or structural. A03-A07 preserve their literal historical prestates and dated F7 bounded readbacks, including A07's permitted physical `outAdvance` retention. The later bounded CF188 item-by-item reread found no drift across A00-A09 or the 36 protected rows, but CF188 remains a dated report-time checkpoint and does not replace the required fresh supervisor Gate 2B reread against the then-current authority. Current manual coverage identities are by-memory `F470880A...A3F7`, by-class `9B8B7753...5033`, and by-file `5704439F...223B`; the command-20163/20164/20165 `94484372...507A6`/`458D5DD6...2103C`/`8AE99524...D82B` identities and the earlier C71/23D/AFFD states are historical operation checkpoints. After the fresh Gate 1 pass, the supervisor must perform fresh Gate 2B verification and independently verify the current command20172 topology before any lifecycle action; no additional generated refresh is asserted as pending.

## Recommended Target Doc Changes

1. Raise metadata to `92/94`; preserve owner/emitter/reconstructable/blank position.
2. Replace blank formal CPP with the exact constructor payload above; keep H blank.
3. Add exact caller list, branch constants, allocation/child construction, active-slot lifecycle, timer/chat interactions, range/padding, source-placement, and compiler-artifact exclusions.
4. Replace stale raw-helper and unresolved-field blocker text with the resolved names/types and IDA handoff.
5. Preserve all valid historical research; label disproved `ObjectPane+0x210`, raw helper names, and empty-emitter state historical rather than deleting them.

## Recommended Support Doc Changes

- UID000077: add the two fields, exact size rationale, score `93/94`, and constructor implementation state.
- UID0000K7: add constructor source route and score `92/92`.
- UID00018X: keep false/non-emitting `90/92`; correct stale summary/inventory.
- UID00035Y: adopt member names and canonical handler identity while keeping `88/90`.
- UID00018Y: harmonize `GetTextWidth`, `g_useEpfAssets`, `g_pBackPane`, and root layer names.
- UID0000FQ/UID0000P1: correct `+0x210` to active `LineInputPane *` without changing total size or later offsets.
- EventDispatcher aggregate/class/file and UID000296: incorporate timer-helper and singleton-IDB state.
- UID0000Z1 and UID00016C: incorporate supervisor IDA synchronization evidence without changing accepted source bodies.
- Chat singleton physical/semantic/class/file/forwarder docs: incorporate the materialized IDA state, constructor consumer, inferred `Refresh()`, and compiler-forwarder/Wave history disposition.
- MainUiLayerSlots, g_pBackPane, and cleanup-queue docs: preserve ownership and add consumer evidence only where useful.

## Score And Metadata Recommendation

| UID | Current | Recommended | Metadata disposition |
| --- | --- | --- | --- |
| 00035P | 92/94 | 92/94 | Historical pre-callback `86/90`; owner/emitter UID000077, true, blank position, CPP populated, H blank. |
| 000077 | 93/94 | 93/94 | Historical pre-callback `91/93`; owner/emitter UID0000K7 and class H now contains both trailing fields. |
| 0000K7 | 92/92 | 92/92 | Historical pre-callback `91/88`; existing `NexusTK/ui/dialogs/` route unchanged. |
| 00018X | 90/92 | 90/92 | False/non-emitting; stale summary only. |
| 00035Y | 88/90 | 88/90 | Names/fields improved; formal body remains separate. |
| 00018Y | 88/91 | 88/91 | Formal names harmonized; behavior/score unchanged. |
| 0000FQ | 94/95 | 94/95 | Bounded field correction; total layout unchanged. |
| 0000P1 | 93/94 | 93/94 | Source narrative correction only. |
| 000141 | 87/91 | 87/91 | Helper inventory improvement only. |
| 00004M | 89/91 | 89/91 | Helper declaration/detail only. |
| 0000J7 | 92/89 | 92/89 | File ownership detail only. |
| 000296 | 88/90 | 88/90 | Formal already present; IDA state sync only. |
| 0000Z1 | 88/93 | 88/93 | Formal already present; IDA state sync only. |
| 00016C | 88/90 | 88/90 | Formal already present; IDA state sync only. |
| 0002X6/0002X5/00001Y/0000I5 | current | unchanged | Consumer/IDA/Refresh detail only. |

Why not higher: exact original local variable spelling, `Refresh()` lexical spelling, some general Pane attachment API spelling, and include ordering remain inferred. Why not lower: all behavior, boundaries, callers, layout fields, globals, ownership, source placement, child construction signatures, compiler exclusions, and formal target code are resolved.

## Open Questions With Attempted Resolution

1. Exact prompt-width helper spelling: resolved to existing `GrafPort::GetTextWidth` formal source, rejecting stale `MeasureTextWidth`.
2. Exact asset flag spelling: resolved to project source `g_useEpfAssets`, rejecting narrow `g_useLargeInputPaneLayout`.
3. `+0x100/+0x104` roles: resolved by constructor plus handler state machine.
4. `UserPane+0x210`: resolved to active `LineInputPane *` by read/queue/store/clear behavior; prior ObjectPane role is disproved.
5. EventDispatcher helper: resolved to text-input guard timer by field set, timer id/delay, and routing consumers.
6. Chat virtual: behavior is exact refresh/invalidation; `Refresh()` selected as the best existing style-consistent name. Exact original spelling remains a calibrated lexical uncertainty, not deferred investigation.
7. `TextBoxPane` IDA type: resolved by catalog entry 0377 as an incomplete/no-layout type with zero members. This deliberately avoids guessing its layout while allowing exact pointer typing in `LineInputPane`.
8. Branch duplication: retained because binary ordering and EPF-only side effects favor explicit source branches.
9. Final source file: resolved to InputPanes.cpp by class/file/physical cluster evidence.
10. Aggregate treatment: resolved false/non-emitting split index; no monolithic C++.
11. Padding/range: resolved exact target end and seven-byte alignment.
12. Compiler artifacts: resolved as non-source lowering and protected no-change.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current physical supervisor-owned coverage identities at the bounded report-time reread, with commands `000000020163`-`000000020165` retained as the provenance of the UID00035P coverage operations:

- `by-memory/-coverage-report.md`: SHA256 `F470880A233CB61ACC3227910478A6F22147B4B65A014FCCBCD0237D7DADA3F7`, 2,115,803 bytes, 4,782 lines. Durable/current report-time anchors are UID0000Z1 line 581, UID000141 line 1373, UID00018X/UID00035P/UID00018Y/UID00035Y lines 2043-2046, and UID000296 line 4588.
- `by-class/-coverage-report.md`: SHA256 `9B8B77532BAA43613618BCB3275E9E9D6668EADA1A499F154ACAC18B3DAF5033`, 273,344 bytes, 625 lines. Durable/current report-time anchors are UID00004M line 191, UID000077 line 283, and UID0000FQ line 589.
- `by-file/-coverage-report.md`: SHA256 `5704439FC3EA94C4A3568B1E5712C30ADD1E77BCDA21B0808AFBDE7C3AFA223B`, 164,262 bytes, 317 lines. Durable/current report-time anchors are UID0000K7 line 124 and UID0000P1 line 298.
- `by-type/by-vtable/-coverage-report.md`: SHA256 `60C76DFFEA9586C7754BDC403490408C6FB337742BF09742AE7A914A13602D74`, 67,710 bytes, 146 lines. Its current UID0001XS `InputPaneBaseVtableFamily` row remains at line 69 and already carries the accepted `88%` compiler-only family disposition; no UID00035P-specific vtable coverage operation is valid or required.

The immediate command-`20163`/`20164`/`20165` poststates were by-memory SHA256 `9448437255BE1E5BBDA3DDF7FC23162F01B19ECBC4C1C7C44B4BD28B5FC507A6`, 2,114,112 bytes/4,780 lines; by-class SHA256 `458D5DD68D1BF1DA1401114E03872CB007C54D822D6BFA08DC1335B21672103C`, 272,216/625; and by-file SHA256 `8AE9952442F95BB5B39A4C875670428EA599A3AB1F42B527DD274427D95BD82B`, 163,198/317. They are dated historical operation checkpoints, not current whole-container identities. The exact command-`20163`/`20164`/`20165` operation prestates were by-memory SHA256 `C71EE2C379B28E94B8F414561D55A15F8934E3A8A6F093424004B352DA674C3D`, 2,113,445 bytes/4,778 lines; by-class SHA256 `23D53F6FBBDEE49EA028665CCD9E3100B9C9FC83AEEDF519F8F8D622D8B51303`, 272,710/625; and by-file SHA256 `AFFD68360B091C992006A2329AC3D4F64110D192E0FE91943988DFA53C1428C7`, 163,270/317. They are dated historical operation prestates, not current identities. The immediately preceding by-memory SHA256 `F36B0558336DF3932CF7C0A7CB479F351A4B218D97D9FE6177B58B726372B990`, 2,113,111 bytes/4,778 lines, by-class SHA256 `E40F0932FFFC57025D9DBD409960FDAF7EFAE0C6FDE30C217E9BE34E9EAA0051`, 272,450/625, and by-file SHA256 `30112D670004B173A97FECDAC14ECB2A2C3D6BA49AF290C320185C9D5729AA2B`, 163,115/317, are earlier dated historical checkpoints. Additional dated checkpoints remain: by-memory SHA256 `EE94FB8B1607EB47FF348AFB9CBCBB554D5DCA52D74C16E3FA4C8BA8E6EF1074`, 2,109,808 bytes/4,771 lines; SHA256 `4243659D1F4FEF5379525B7C8045D895F133FA707A72F35F4B1F959D2911D718`; SHA256 `82A918D06B56759FB52713751D1BD4E171379BBC4239229C5616168CB49F0C8E`, 2,108,263/4,769; by-class SHA256 `396DAD20C73A2A54EAF045320B17ECA1FF877B02D36FF4CE204D4BA0D8D0A9E9`, 272,277/625; by-file SHA256 `736B2900338FDFE34C44CD18CF9DF0C7791820D28D42DAB7B5E9DD0691EB6BFE`, 162,964/317; by-vtable SHA256 `D68E24B090F48570D17727658EE3020292D544C0866DFE1D1CB784EECB6E9571`, 67,386/146; by-memory SHA256 `C5E4E81C9EBC12C6A0A73D187100657F9406043C2B826C1519B8A21BED62BAC5`, 2,107,677/4,768; by-class SHA256 `64862329F2FCE0B5AEF01B349E0D5A5D2F09F0B319C8A9EB173521F5F385BC03`, 272,272/625; by-memory SHA256 `22BB0BB3366ED1A445E99E03D6CED32D1F263E12940D400AEA68D1D19EC705F2`, 2,101,781/4,754; by-class SHA256 `EE896367FAA8DF9113167918E06166EE932342C986E0BA7A5FA32C674CD74565`, 272,165/625; and by-file SHA256 `21886E924A4062AB4A82892CB36754634CB933B41683810A8D185553123A24E2`, 162,812/317.

Supervisor-applied/read-back operations; exact payloads are retained so the transaction remains auditable:

Historical exact replacement prestates consumed by command `000000020163` under `C71EE2C3...74C3D` (literal row text):

````text
M01 line 2043:     - [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) 0x004f1c00-0x004f3017 | class-cluster | InputPaneBases : reconstructable : 82% : strong : Live IDA now documents the early LineInputPane lifecycle/prompt sequence, detailed `0x004f2320-0x004f2790` middle-band map, key-handler Enter/Escape/Tab behavior, text-edit forwarder, shared text-helper caller fanout, adjustor-thunk split, and the corrected gate leaving it unassigned because the child is `82/90` and InputPanes is `88/84`.
M03 line 2044:     - [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) 0x004f20a0-0x004f22f4 | method | LineInputPaneSetPromptText : reconstructable : 84% : strong : Live IDA confirmed shared LineInputPane prompt-text/layout method formerly named SpellPromptTextHelper, exact 0x254 bounds, LineInputPane parent attach, 58 direct call sites across spell/item/say-chat/command/user-pane prompts, prompt TextBoxPane child creation/update at this+0xf8, companion child resize at this+0xfc, byte_66DA97 layout branch, TextBoxPane/operator-new/text-width/rectangle/text-control callees, and final C++ blank pending field/virtual/helper names.
M05 line 4584:     - [UID:000296][0x0067ab30-0x0067ab34.g_pEventDispatcher](by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md) 0x0067ab30-0x0067ab34 | global pointer | g_pEventDispatcher : reconstructable : 86% : strong : EventDispatcher singleton pointer now attached to `EventDispatcher.cpp`; existing file/class/aggregate pages, idle scheduler reference, and application cleanup/message-loop consumers confirm owner and lifecycle use while final declaration spelling remains deferred.
M06 line 1373:     - [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) 0x004a6a80-0x004a82a9 | class-aggregate | EventDispatcher : reconstructable : 82% : strong : attached EventDispatcher aggregate with helper children, singleton/vtable/layout evidence, padding boundaries, and final helper-name caveats
M07 line 581:         - [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) 0x00469180-0x004691fa | class method | BlackHoleQueuePaneForDeferredDeletion : reconstructable : 86% : strong : IDA-verified pane detach/event unregister/timer cleanup helper with inherited List dedup/append queueing and 83 direct callsites.
````

- M01 command `000000020163` replaced the historical line 2043 prestate above with the following exact payload; current readback is by-memory line 2043:
`    - [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) 0x004f1c00-0x004f3017 | class-cluster split index | InputPaneBases : not_reconstructable : 90% : very-strong : Non-emitting split/index authority for exact input-pane children; UID00035P now owns the source-ready LineInputPane constructor, UID00018Y owns SetPromptText, UID00035Y owns HandleKeyOrTextEvent, and compiler adjustors remain separate.`
- M02 command `000000020163` inserted the following exact formerly absent UID00035P payload after UID00018X and before UID00018Y; current readback is by-memory line 2044:
`        - [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) 0x004f1c00-0x004f2009 | constructor | LineInputPaneConstructor : reconstructable : 92% : very-strong : Exact shared LineInputPane constructor with 37 callers, two asset-layout branches, prompt/TextEditPane child construction, active UserPane slot lifecycle, dispatcher guard timer, chat refresh, exact padding, and source-ready human C++ under InputPanes.cpp.`
- M03 command `000000020163` replaced the historical line 2044 prestate above with the following exact payload; current readback is by-memory line 2045:
`    - [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) 0x004f20a0-0x004f22f4 | method | LineInputPaneSetPromptText : reconstructable : 88% : very-strong : Shared LineInputPane prompt update with exact 0x254 bounds, 58 callers, prompt child create/update, paired edit-child resize, GetTextWidth, g_useEpfAssets, g_pBackPane/root-layer attachment, and first-draft source C++.`
- M04 command `000000020163` inserted the following exact formerly absent UID00035Y payload after UID00018Y and before UID000364; current readback is by-memory line 2046:
`        - [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md) 0x004f25a0-0x004f2754 | method | LineInputPaneHandleKeyOrTextEvent : reconstructable : 88% : very-strong : Exact Enter/Escape/Tab, deferred-submit, active-slot clear, owner-notify, deletion-queue, and edit-child forwarding behavior with resolved +0x100/+0x104 member roles.`
- M05 command `000000020163` replaced the historical line 4584 prestate above with the following exact payload; the immediate command poststate was later shifted by unrelated rows and the current report-time readback is by-memory line 4588:
`    - [UID:000296][0x0067ab30-0x0067ab34.g_pEventDispatcher](by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md) 0x0067ab30-0x0067ab34 | global pointer | g_pEventDispatcher : reconstructable : 88% : very-strong : EventDispatcher-owned singleton definition with broad routing/lifecycle references, exact source formal, and supervisor-applied saved IDA name/type/comments including the LineInputPane text-input guard consumer.`
- M06 command `000000020163` replaced the historical line 1373 prestate above with the following exact payload; current readback remains by-memory line 1373:
`    - [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) 0x004a6a80-0x004a82a9 | class-aggregate | EventDispatcher : reconstructable : 87% : very-strong : Attached EventDispatcher aggregate with helper children, singleton/vtable/layout evidence, padding boundaries, accepted child source routes, and resolved ArmTextInputGuardTimer behavior; narrower children remain the source emitters.`
- M07 command `000000020163` replaced the historical line 581 prestate above with the following exact payload; current readback remains by-memory line 581:
`        - [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) 0x00469180-0x004691fa | class method | BlackHoleQueuePaneForDeferredDeletion : reconstructable : 88% : very-strong : Exact pane detach, event unregister, timer cleanup, deduplicated queue append, broad caller fanout, source-ready C++, and supervisor-applied saved IDA name/type/comments.`
- M08 command `000000020164` replaced UID000077 with the following exact payload; current readback remains by-class line 283:
`- [UID:000077][LineInputPane](by-class/LineInputPane.md) : reconstructable : 93% : very-strong : Complete reusable one-line prompt base with exact 0x108 layout, prompt/edit child pointers, deferred-submit fields at +0x100/+0x104, source-ready constructor, cleanup/prompt/text/layout/child methods, canonical HandleKeyOrTextEvent contract, compiler-thunk separation, and InputPanes ownership.`
- M09 command `000000020164` replaced the exact historical by-class line 589 substring `exposes complete-object +0x210 as ObjectPane *m_pendingTargetObject with inline ClearPendingTargetObject()` with `exposes complete-object +0x210 as LineInputPane *m_activeLineInputPane with inline ClearActiveLineInputPane()`; current readback contains the replacement once at line 589.
- M10 command `000000020164` replaced UID00004M with the following exact payload; current readback remains by-class line 191:
`- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) : reconstructable : 89% : very-strong : UI event-routing singleton with exact constructor/dispatch/route evidence, handler containers, text-input guard field and ArmTextInputGuardTimer helper, accepted source/header graph, child emitters, and compiler-only destructor/vtable distinctions.`
- M11 command `000000020165` replaced UID0000K7 with the following exact payload; current readback remains by-file line 124:
`- [UID:0000K7][InputPanes](by-file/InputPanes.md) : reconstructable : 92% : very-strong : Reusable typed input-pane family with source-ready LineInputPane constructor, exact 0x108 LineInputPane layout, canonical Event-based handlers, corrected prompt/text-helper names, exact child ranges, compiler-thunk separation, and complete InputPanes.cpp/InputPanes.h route.`
- M12 command `000000020165` replaced the exact historical by-file line 298 substring `exact UserPane +0x210 pending-target ObjectPane pointer and inline ClearPendingTargetObject()` with `exact UserPane +0x210 active LineInputPane pointer and inline ClearActiveLineInputPane()`; current readback contains the replacement once at line 298.

No manual tracker edit was authorized or performed. Commands `000000020163`-`000000020165` explicitly disabled generated refresh; supervisor command `000000020172` subsequently completed that refresh, and command `000000020175` later refreshed the moving tracker. Independent supervisor verification of the current command20172 topology remains a separate step.

## Follow-Up Actions

1. Historical completed step: supervisor Gate 1 accepted exact pre-callback SHA256 `BAE985B92E29861C1C152361A2C8AE212F42FF3B9CCC69ED905446C78E1F7533`.
2. Historical completed step: B008 applied C001-C047 under short leases and serial scoped no-generated-refresh validators, then released every lease.
3. Historical completed step: supervisor independently verified ordinary implementation claim by claim under Gate 2A.
4. Historical completed step: supervisor applied/read back/saved A00-A09 in one controlled Gate 2B transaction with backup and catalog entry 0377; an unsaved frame experiment was discarded before the clean save.
5. Historical completed step: B008 reconciled the accepted post-IDA facts into this report and the actually stale whitelisted ordinary docs under short leases and scoped validators.
6. Historical completed step: supervisor commands `000000020163`-`000000020165` applied and read back C050-C061/M01-M12 exactly against the historical `C71EE2C3...74C3D`/`23D53F6F...B51303`/`AFFD6836...428C7` prestates; each scoped validator exited 0/ok 1 with generated refresh disabled.
7. Fresh supervisor Gate 2B currentness verification remains required after this report edit; catalog entry 0377 remains historical action evidence rather than a current closure claim.
8. Historical completed step: supervisor command `000000020172` completed the generated refresh that commands `000000020163`-`000000020165` skipped.
9. Supervisor independent current-topology verification remains required against command20172 CPP/H/generated-memory output and the then-current moving tracker; this is verification, not another refresh request.
10. Report execution/archive/postarchive state is supervisor-owned and authoritative only from the actual report path plus validator-owned status/history metadata; this report makes no completion-state claim.

## Confidence

`92/94` is justified. Binary behavior, class role, callers, ranges, child signatures, fields, global interactions, source route, and C++ topology are very strong. The remaining uncertainty is confined to original lexical choices for a few inferred method/member names and final include ordering. Those uncertainties do not justify raw labels or blank source.

## Validator Results

Every changed ordinary destination was validated serially from `E:\NTK\GhidraBridge\source-3\project-documentation` with exact command form `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --no-generated-refresh`. Every ordinary command exited `0`, reported `ok:1`, and explicitly reported `generated_refresh: skipped` because `--no-generated-refresh` was present. B008 invoked no coverage validator, generated refresh, lifecycle command, dry run, or `execute_report` probe. The supervisor later validated the three manual coverage files through commands `000000020163`-`000000020165`; those commands also exited 0/ok 1 with generated refresh disabled.

| Command | Timestamp | File | Result and warning disposition |
| --- | --- | --- | --- |
| `000000019934` | `2026-07-30T11:03:55-04:00` | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` | exit 0, ok 1; metadata `92/94`; three UID-link insertions were validator-owned reference normalization, not defects. |
| `000000019936` | `2026-07-30T11:04:50-04:00` | `by-class/LineInputPane.md` | exit 0, ok 1; metadata `93/94`; ten `missing_ref_uid` warnings are pre-existing split-child registry omissions, not callback defects. |
| `000000019938` | `2026-07-30T11:05:34-04:00` | `by-file/InputPanes.md` | exit 0, ok 1; metadata `92/92`; 24 pre-existing `missing_ref_uid` family warnings and one reference-index add; no malformed callback link. |
| `000000019940` | `2026-07-30T11:06:17-04:00` | `by-memory/0x004f1c00-0x004f3017.InputPaneBases.md` | exit 0, ok 1; 24 pre-existing `missing_ref_uid` family warnings and one reference-index add; false/non-emitting `90/92` preserved. |
| `000000019943` | `2026-07-30T11:07:07-04:00` | `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` | exit 0, ok 1; no warning defect; `88/90` preserved. |
| `000000019947` | `2026-07-30T11:09:12-04:00` | `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md` | exit 0, ok 1; no warning defect; formal-name synchronization accepted. |
| `000000019950` | `2026-07-30T11:10:37-04:00` | `by-class/UserPane.md` | exit 0, ok 1; five pre-existing missing-reference warnings for unrelated split children; UID00035P/UID00035Y reference additions accepted. |
| `000000019953` | `2026-07-30T11:11:24-04:00` | `by-file/UserPane.md` | exit 0, ok 1; 18 pre-existing missing-reference warnings for unrelated family children; UID00035P/UID00035Y reference additions accepted. |
| `000000019955` | `2026-07-30T11:12:34-04:00` | `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` | exit 0, ok 1; no warning defect; UID00035P reference added. |
| `000000019957` | `2026-07-30T11:13:27-04:00` | `by-class/EventDispatcher.md` | exit 0, ok 1; no warning defect; source helper/field role retained. |
| `000000019958` | `2026-07-30T11:14:27-04:00` | `by-file/EventDispatcher.md` | exit 0, ok 1; no warning defect; EventDispatcher.cpp ownership detail retained. |
| `000000019960` | `2026-07-30T11:15:10-04:00` | `by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md` | exit 0, ok 1; no warning defect; supervisor-only IDA handoff documented without mutation. |
| `000000019962` | `2026-07-30T11:15:59-04:00` | `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md` | exit 0, ok 1; no warning defect; source/IDA synchronization evidence retained. |
| `000000019963` | `2026-07-30T11:16:40-04:00` | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` | exit 0, ok 1; no warning defect; `GetTextWidth` source/IDA synchronization evidence retained. |
| `000000019964` | `2026-07-30T11:19:36-04:00` | `by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md` | exit 0, ok 1; validator normalized the UID00035P link and added its reference index; no warning defect. |
| `000000019965` | `2026-07-30T11:20:10-04:00` | `by-global/g_pChattingVarietyPane.md` | exit 0, ok 1; two UID-link normalizations and one reference-index add; no warning defect. |
| `000000019967` | `2026-07-30T11:21:12-04:00` | `by-class/ChattingVarietyPane.md` | exit 0, ok 1; formal registry hash updated for inferred `Refresh()` declaration; two UID-link normalizations; no warning defect. |
| `000000019969` | `2026-07-30T11:21:50-04:00` | `by-file/Chatting.md` | exit 0, ok 1; UID00035P reference-index add; no warning defect. |
| `000000019970` | `2026-07-30T11:22:44-04:00` | `by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md` | exit 0, ok 1; UID00035P link normalized/indexed; compiler-only/no-code state preserved. |
| `000000019971` | `2026-07-30T11:23:35-04:00` | `by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md` | exit 0, ok 1; UID00035P/UID0000Z1 links normalized and constructor reference indexed; no warning defect. |
| `000000020074` | `2026-07-30T14:43:16-04:00` | `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` | exit 0, ok 1; post-IDA target evidence accepted; no warning defect; generated refresh skipped. |
| `000000020075` | `2026-07-30T14:43:50-04:00` | `by-class/LineInputPane.md` | exit 0, ok 1; exact saved type/layout evidence accepted; ten pre-existing split-child `missing_ref_uid` warnings; generated refresh skipped. |
| `000000020076` | `2026-07-30T14:44:31-04:00` | `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` | exit 0, ok 1; canonical helper/frame poststate accepted; no warning defect; generated refresh skipped. |
| `000000020077` | `2026-07-30T14:45:07-04:00` | `by-class/UserPane.md` | exit 0, ok 1; exact bounded `+0x210` saved-layout evidence accepted; five pre-existing unrelated `missing_ref_uid` warnings; generated refresh skipped. |
| `000000020078` | `2026-07-30T14:45:39-04:00` | `by-file/UserPane.md` | exit 0, ok 1; source-file/saved-layout synchronization accepted; 18 pre-existing unrelated `missing_ref_uid` warnings; generated refresh skipped. |
| `000000020079` | `2026-07-30T14:46:17-04:00` | `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` | exit 0, ok 1; saved helper identity/comment/frame evidence accepted; no warning defect; generated refresh skipped. |
| `000000020080` | `2026-07-30T14:46:48-04:00` | `by-class/EventDispatcher.md` | exit 0, ok 1; saved helper source contract accepted; no warning defect; generated refresh skipped. |
| `000000020081` | `2026-07-30T14:47:19-04:00` | `by-file/EventDispatcher.md` | exit 0, ok 1; EventDispatcher.cpp saved-helper state accepted; no warning defect; generated refresh skipped. |
| `000000020082` | `2026-07-30T14:47:56-04:00` | `by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md` | exit 0, ok 1; one-item saved global poststate accepted; no warning defect; generated refresh skipped. |
| `000000020083` | `2026-07-30T14:48:42-04:00` | `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md` | exit 0, ok 1; canonical helper and `pane` frame readback accepted; no warning defect; generated refresh skipped. |
| `000000020084` | `2026-07-30T14:49:23-04:00` | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` | exit 0, ok 1; canonical helper plus retained physical `outAdvance` readback accepted; no warning defect; generated refresh skipped. |
| `000000020085` | `2026-07-30T14:50:00-04:00` | `by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md` | exit 0, ok 1; one-item saved global poststate accepted; no warning defect; generated refresh skipped. |
| `000000020086` | `2026-07-30T14:50:30-04:00` | `by-global/g_pChattingVarietyPane.md` | exit 0, ok 1; semantic/physical saved-state link accepted; no warning defect; generated refresh skipped. |
| `000000020163` | artifact write `2026-07-31T02:28:51-04:00`; exact command timestamp not exposed in callback | `by-memory/-coverage-report.md` | exit 0, ok 1; C050-C056/M01-M07 applied exactly; UID00035P and UID00035Y inserted at lines 2044/2046; bounded pre-existing missing-UID warnings only; generated refresh disabled. |
| `000000020164` | artifact write `2026-07-31T02:29:05-04:00`; exact command timestamp not exposed in callback | `by-class/-coverage-report.md` | exit 0, ok 1; C057-C059/M08-M10 applied exactly at lines 283/589/191; no callback defect reported; generated refresh disabled. |
| `000000020165` | `2026-07-31T02:29:30-04:00` validator command-state timestamp | `by-file/-coverage-report.md` | exit 0, ok 1; C060-C061/M11-M12 applied exactly at lines 124/298; no callback defect reported; generated refresh disabled. |

Each ordinary validator also reported the expected validator-owned projected-stat/reference maintenance. B008 did not manually edit any tool-owned surface or invoke the three supervisor coverage validators.

## Changed Files

Current physical readback after the original ordinary callback and bounded post-IDA reconciliation validators:

| Ordinary path | SHA256 | Bytes | Lines | Accepted rows |
| --- | --- | ---: | ---: | --- |
| `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md` | `CCF28C564A4775F0297C408A37073DB40650538475B477B7646F6601C8F253C1` | 14,716 | 156 | C001-C015 plus A00-A03/P readback |
| `by-class/LineInputPane.md` | `0461110E9DB289438C8BEC924FB4C949C83FB356426A098098FB226AFC41DF35` | 20,257 | 158 | C016-C019 plus A00-A01 readback |
| `by-file/InputPanes.md` | `77948F03FB4268780D43BB634843D556CE60093421F77ABB978B7E6354495227` | 27,985 | 162 | C020-C021 |
| `by-memory/0x004f1c00-0x004f3017.InputPaneBases.md` | `4610045843940790FD0A56972351B4BA85545AFDA526B68901084F56B8684316` | 18,241 | 103 | C022-C023 |
| `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` | `3CA614F2AB65ADF4CCC96BC8DD6B6544AC55DB88F9577D9D72147F17E480A69A` | 8,961 | 71 | C024-C026 plus A04 readback |
| `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md` | `3B957F9BE7B4B432E4F969D43DA1C398E5CE316843223FEFBF60B8C564AF6366` | 14,168 | 168 | C027-C029 |
| `by-class/UserPane.md` | `4784B20F4C8535CDE637223AC3B5360D8B79276CF3190F14DD7C423604BCE6D8` | 111,710 | 815 | C030-C032 plus A02 readback |
| `by-file/UserPane.md` | `8A534098EC3F32D46D6DDE40AEF9E1094055BBEF7B32B350B55218954308D772` | 121,808 | 510 | C033 plus A02 source-file readback |
| `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` | `B9212776BEA1C7DDCF911EAC85A624832BAE1FAF9A2AD0FBB180383E168BE504` | 45,096 | 338 | C034 plus A05 readback |
| `by-class/EventDispatcher.md` | `3D387ADBD4D49C95421A12BEB74B82152063E0026070D919D319ADDEBF35A1B4` | 33,811 | 247 | C035 plus A05 readback |
| `by-file/EventDispatcher.md` | `FA3D915B248F1558EC0B11C1989221A366F609F6A5F61087A96B7ADB0A68F240` | 39,838 | 199 | C036 plus A05 readback |
| `by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md` | `404929729092CC68A7F8DAE3CF6296D3017F8D0D85A180CC23510ED1F61E309D` | 7,751 | 80 | C037 plus A08 readback |
| `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md` | `C0BC8F6E19C31611696461D986FCC776B3228E399487B78D872DB5904C8D3099` | 10,201 | 94 | C038 plus A06 readback |
| `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` | `3E23E510EDD2318C08C0CEA6B0A4F108038F37A64D2B328E17012393528DE519` | 26,940 | 280 | C039 plus A07 readback |
| `by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md` | `367D69993BA78E6AE93F4B3E776307DC6C4DF65A3A3C3BF62E2F825BE5B83CC4` | 10,494 | 84 | C040 plus A09 readback |
| `by-global/g_pChattingVarietyPane.md` | `11569E25A2056737286F43B660F69C2E33E7C801D5D490E282FCD436A9181059` | 8,432 | 61 | C041 plus A09 semantic readback |
| `by-class/ChattingVarietyPane.md` | `356945596D97B29B13D324492E5C3958003B3DC7FEB032ABAB9BF54EA70E3A5C` | 21,753 | 133 | C042 |
| `by-file/Chatting.md` | `6D46EFD11BB7D7EF76DEFBA432E2619E074A272BB19A30AFB8DCE5FE75C4BA28` | 156,919 | 507 | C043 |
| `by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md` | `5A022CDABB0C6BA8AF3DB25E14659B2097241946D91BE767EDB0ABB2BBFC8971` | 8,752 | 88 | C044 |
| `by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md` | `378D0CE78382EDE17F3B5A3B95C8271B14D4FF66532195578FB572B1801C3B77` | 8,729 | 84 | C047 |

Already-present/no-edit readback: C045 `by-global/MainUiLayerSlots.md` SHA256 `DFA4B0EA026C57DB7406C9B68663C551E859850EB48D71DFD3D2D5484D53CDE3`; C046 `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` SHA256 `0550F00D0D286C3872C95FAD51123C51E55AED50DAD444D59A8363D1BA0AC00C`. C047 was changed because the exact prior-pane constructor consumer was absent despite the singleton/service evidence already being present.

Supervisor-changed read-only coverage surfaces, not B008-changed files:

| Coverage path | Current SHA256 | Bytes | Lines | Supervisor command and accepted rows |
| --- | --- | ---: | ---: | --- |
| `by-memory/-coverage-report.md` | `F470880A233CB61ACC3227910478A6F22147B4B65A014FCCBCD0237D7DADA3F7` | 2,115,803 | 4,782 | current physical container; `000000020163` supplied C050-C056/M01-M07; UID0000Z1/UID000141 at lines 581/1373, UID00018X-UID00035Y at lines 2043-2046, UID000296 at line 4588 |
| `by-class/-coverage-report.md` | `9B8B77532BAA43613618BCB3275E9E9D6668EADA1A499F154ACAC18B3DAF5033` | 273,344 | 625 | current physical container; `000000020164` supplied C057-C059/M08-M10 at lines 283/589/191 |
| `by-file/-coverage-report.md` | `5704439FC3EA94C4A3568B1E5712C30ADD1E77BCDA21B0808AFBDE7C3AFA223B` | 164,262 | 317 | current physical container; `000000020165` supplied C060-C061/M11-M12 at lines 124/298 |
| `by-type/by-vtable/-coverage-report.md` | `60C76DFFEA9586C7754BDC403490408C6FB337742BF09742AE7A914A13602D74` | 67,710 | 146 | no operation; UID0001XS remains correct at line 69 |

Current read-only generated/tracker surfaces, not B008-changed files:

| Generated/tracker path | Current command | Current SHA256 | Bytes | Lines | Current disposition |
| --- | --- | --- | ---: | ---: | --- |
| `auto-generated/NexusTK/ui/dialogs/InputPanes.cpp` | `000000020172` | `9B54F97612FDC42132B44B33FA71066DEF1BD65B6ADF077943E28308D214E599` | 8,533 | 258 | refresh complete; one UID00035P `92/94` marker and constructor, no target empty marker, separate UID00035Y empty sibling |
| `auto-generated/NexusTK/ui/dialogs/InputPanes.h` | `000000020172` | `8FD90D87EBE32D1AB745BAAACA1B7EE4B4CA32394129A2D7C820A13BF9F41378` | 1,237 | 38 | refresh complete; one UID000077 declaration with all four LineInputPane fields |
| `auto-generated/-ag-memory-coverage.md` | `000000020172` | `7695173A6F5BCA9BBC957D4C7E4BD4572FD03888E182602668740159D3356770` | 1,427,432 | 4,974 | refresh complete; UID00035P line 1259 remains coded, CPP yes/H no, no empty-emitter condition |
| `auto-generated/-ag-research-tracker.md` | `000000020175` | `8D25FA8A0D5AA888FB02A0514D50C92D82B945F747D4FCEF35720BBD84B2C1C1` | 1,686,231 | 6,658 | moving tracker observation; UID00035P line 3167 remains `92/94`, reconstructable, `0/0/0` |

The `94484372...507A6`/`458D5DD6...2103C`/`8AE99524...D82B` identities are dated command-20163/20164/20165 poststates, while `C71EE2C3...74C3D`/`23D53F6F...B51303`/`AFFD6836...428C7` are their exact historical operation prestates; `F36B0558...B990`/`E40F0932...0051`/`30112D67...A2B`, by-memory `EE94FB8B...F1074`, and `4243659D...D718` are still earlier dated checkpoints. Command20109 generated CPP/H/memory identities `EC8B1F90...409A`, `E4406EFC...D867`, and `027FB7FD...B8D9F` are dated historical pre-command20172 checkpoints. Command20170 tracker `00D887EB...608E0` is a dated historical predecessor to current moving command20175 `8D25FA8A...2C1C1`; command20160 tracker `CF8C778F...ACA3B`, command20149 tracker `A826E7CE...EBE5F`, command20124 tracker `4FCB30D3...2A69`, command20109 tracker `706757C0...B342`, command20104, and commands20024/20034 plus their hashes are older dated historical checkpoints.

The same report was updated with physical readback, ledger states, validator records, ordinary and supervisor-owned coverage hashes, and checklist results. Exact prestate/backup `4A9360D1...26C94` and session `07b29e1b` are dated history; `A0D97FC5...4375971` is the immutable catalog-0377 action-time save. Historical read-only session `f608d7c2` observed physical saved IDB checkpoint `F7C936C0...F8D7D8A`; that bounded readback corrected the 48-comment target inventory, protected neighbor itemization, RTTI pointer-cell locations, compiler-helper frames, EH code-label classification, and tool-projection facts now recorded in P00-P04. F7, the supervisor-referenced 9F8 identity, and B180 `B180F0E4...F2A07` are dated bounded evidence. A later bounded read-only pass on the same active session against saved checkpoint CF188 `CF18895C...2C7F96`, 143,192,665 bytes, saved `2026-07-31T03:00:53.6024151-04:00`, reread every A00-A09 and all 36 protected rows and found no drift; CF188 is itself a dated report-time checkpoint, so fresh Gate 2B must still reread every entity against the then-current authority. The 20 ordinary paths above were all rehashed; 13 actually stale destinations were reconciled and validated in commands20074-20086, while the other seven remained byte-identical and required no post-IDA edit. Supervisor commands `000000020163`-`000000020165`, not B008, edited and validated the three manual coverage files; the physical current containers subsequently advanced without changing the accepted M01-M12 rows. No generated/tracker file, IDA database, supervisor audit/catalog, goal/notes, validator lifecycle/state, or report lifecycle artifact was edited by B008. Every ordinary-file and report lease used by B008 was released immediately after the corresponding edit/validation work.

## Implementation Tracking Checklist

- [x] Report target/provenance block is exact and declares only UID00035P.
- [x] Duplicate/direct/additional/family-report search completed.
- [x] Current target/support ordinary docs and hashes inventoried.
- [x] Supervisor command20172 generated refresh is complete; current CPP/H/memory artifacts were read exactly at `9B54F976...E599`, `8FD90D87...1378`, and `7695173A...6770`, while command20109 generated identities are dated history.
- [x] The independently advanced, explicitly moving command20175 research tracker was read exactly at `8D25FA8A...2C1C1`, 1,686,231 bytes/6,658 lines, with UID00035P at line 3167; command20170/20160/20149/20124/20109 tracker observations, command20104, commands20024/20034, command19993, command19926/19933, and command19890/19900/19910/19911/19928 observations are dated history, not current lifecycle authority.
- [x] Bounded live MCP health, target, helper, type, item, comment, stack, byte, xref, range, and collision checks were completed on active session `f608d7c2` against dated physical saved checkpoint CF188 `CF18895C...2C7F96`; A03-A07 each record that exact bounded range/name/full declaration/complete frame/four-entry-comment readback independently, A03 enumerates all 48 regular internal comments, A08/A09 preserve the canonical-query versus blank-item-projection distinction, and P00-P04 contain the corrected protected state. `A0D97FC5...4375971` is the immutable catalog-0377 action checkpoint; B180 `B180F0E4...F2A07`, F7, supervisor-referenced 9F8, `4A9360D1...26C94`, session `07b29e1b`, `DAA59745...C17`, `DADC487F...C6A4`, session `1da2b2ae`, and earlier checkpoints are dated history. CF188 is a report-time checkpoint, not permanent authority; the unchecked fresh Gate 2B row below requires item-by-item A00-A09/protected-dependency reread against the then-current authority.
- [x] All 20 callback-touched ordinary destinations were rehashed after the dated F7 bounded IDB check and remain byte-for-byte identical to the `Changed Files` table; the later CF188 target/protected no-drift reread did not change those ordinary-file hashes and does not assert permanent IDB authority.
- [x] Every behavior/ownership/type/name/range/source/C++ blocker investigated.
- [x] Claim ledger is contiguous C001-C061 with one literal destination per row.
- [x] IDA ledger is atomic A00-A09; each row preserves literal historical prestate, catalog-0377 canonical classification, exact applied supervisor action, and dated CF188 bounded no-drift readback while retaining F7 as earlier audit history. A03-A07 independently enumerate range/name/full declaration, every frame item with offset/size/type, address regular/repeatable and function regular/repeatable channels, collision history, exact saved frame disposition, and CF188 Hex-Rays argument/local inventory; A03 separately records all 48 regular internal comments unchanged at CF188. Fresh Gate 2B must reread all A/P rows against the then-current authority.
- [x] Protected dependencies P00-P04 are separately enumerated with corrected one-byte neighbor heads, RTTI pointer-cell/descriptor distinctions, exact compiler-helper prototypes/frames/comments/xrefs, EH code-label classification, security-cookie state, and projection discrepancies.
- [x] Formal target CPP and blank target H disposition are explicit.
- [x] Score/metadata recommendations are explicit and calibrated.
- [x] Manual coverage operations M01-M12 preserve their exact historical prestate rows, exact replacement/insert/substitution payloads, and command ownership; commands `000000020163`-`000000020165` applied and read them back, and the rows remain physically exact under current container hashes `F470880A...A3F7`, `9B8B7753...5033`, and `5704439F...223B`. UID00035P/UID00035Y are at by-memory lines 2044/2046; M05 UID000296 shifted from historical line 4584 through the command-time line 4586 to current report-time line 4588; all other current anchors are recorded above. `94484372...507A6`, `458D5DD6...2103C`, `8AE99524...D82B`, `C71EE2C3...74C3D`, `23D53F6F...B51303`, `AFFD6836...428C7`, `F36B0558...B990`, and `EE94FB8B...F1074` are retained only as dated historical checkpoints/prestates.
- [x] Current by-vtable coverage `60C76DFF...D74` was read separately; UID0001XS remains correct at line 69 and requires no additional coverage operation.
- [x] Supervisor Gate 1 accepted exact pre-callback SHA256 `BAE985B92E29861C1C152361A2C8AE212F42FF3B9CCC69ED905446C78E1F7533`.
- [x] B008 ordinary implementation callback authorized for C001-C047.
- [x] C001-C015 applied/read back in `by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md`; C014 was already present.
- [x] C016-C019 applied/read back in `by-class/LineInputPane.md`.
- [x] C020-C021 applied/read back in `by-file/InputPanes.md`.
- [x] C022-C023 applied/read back in `by-memory/0x004f1c00-0x004f3017.InputPaneBases.md`.
- [x] C024-C026 applied/read back in `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md`; C026 was already present.
- [x] C027-C029 applied/read back in `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md`.
- [x] C030-C032 applied/read back in `by-class/UserPane.md`.
- [x] C033 applied/read back in `by-file/UserPane.md`.
- [x] C034 applied/read back in `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`.
- [x] C035 applied/read back in `by-class/EventDispatcher.md`.
- [x] C036 applied/read back in `by-file/EventDispatcher.md`.
- [x] C037 applied/read back in `by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md`.
- [x] C038 applied/read back in `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md`.
- [x] C039 applied/read back in `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`.
- [x] C040 applied/read back in `by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md`.
- [x] C041 applied/read back in `by-global/g_pChattingVarietyPane.md`.
- [x] C042 applied/read back in `by-class/ChattingVarietyPane.md`.
- [x] C043 applied/read back in `by-file/Chatting.md`.
- [x] C044 applied/read back in `by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md`.
- [x] C045 confirmed already present in `by-global/MainUiLayerSlots.md`; no edit or validator required.
- [x] C046 confirmed already present in `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`; no edit or validator required.
- [x] C047 applied/read back in `by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md` after inspection found the exact prior-pane constructor consumer absent.
- [x] Every ordinary target/support change was applied under a short lease and every lease was released immediately after validation.
- [x] Twenty original serial scoped ordinary validators plus thirteen post-IDA reconciliation validators completed with exit 0/ok 1 and generated refresh disabled; pre-existing missing-reference warnings are dispositioned above.
- [x] Supervisor independently verified ordinary implementation under Gate 2A.
- [x] Historical supervisor Gate 2B transaction A00-A09 was independently validated, applied/confirmed, read back, backed up, saved, and cataloged as entry 0377; this remains action evidence and does not claim fresh post-report-edit Gate 2B closure.
- [x] B008 post-IDA reconciliation authorized and completed in this same report and the actually stale whitelisted ordinary docs.
- [x] Supervisor-only M01-M07/C050-C056 applied to `by-memory/-coverage-report.md`, validated by command `000000020163`, and remain exact under current physical SHA `F470880A...A3F7`.
- [x] Supervisor-only M08-M10/C057-C059 applied to `by-class/-coverage-report.md`, validated by command `000000020164`, and remain exact under current physical SHA `9B8B7753...5033`.
- [x] Supervisor-only M11-M12/C060-C061 applied to `by-file/-coverage-report.md`, validated by command `000000020165`, and remain exact under current physical SHA `5704439F...223B`.
- [ ] Fresh supervisor Gate 2B currentness verification completed for this exact changed report.
- [ ] Supervisor independent current generated-topology verification completed against command20172 CPP/H/generated-memory output and the then-current moving tracker; the command20172 refresh itself is already complete.
- Report execution/archive/postarchive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata; this report makes no completion-state claim.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000020194","destination_path":"executed-b-agent-research/B008/00035P-LineInputPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/00035P-LineInputPaneConstructor-source-quality.md","timestamp":"2026-07-31T04:17:50-04:00","uid":"00035P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
