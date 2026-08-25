*** UID:0000OP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TextMenuDialogs

## Accepted UID0000OP Whole-File Reconstruction

This section is the current source-quality authority incorporated from the accepted B002 report. TextMenuDialogs is first-party NexusTK source with inline formal CPP/H, not a third-party import. It owns 28 authored bodies; `MerchantDialogPane::SendMenuRequestPacket` is the one inventoried external support method and remains owned by MerchantDialogPane.

### Current Target State

- Metadata: `COMPLETION:94`, `CONFIDENCE:94`, path `NexusTK/ui/dialogs/`, `CANONICAL_OWNER:FILE`.
- Accepted child route: UID000238 position `0`, UID0000ES position `10`, UID0000ET position `20`, UID0000ER position `30`, their exact method pages, UID00031Y, and UID0003IP; UID0001BN is non-emitting. UID0004H8 is external support owned/emitted/parented by UID000083/UID0000L9/UID000083 and is excluded from UID0000OP-authored source.
- Current prose/formal state uses accepted method identities, treats raw `0x0051f310` as the external ArgumentedMenuMenuItemList constructor, contains no executable operational examples, and carries complete CPP/H expectations.
- Complete 99-row inventory: 28 UID0000OP-authored bodies (13 factory, 5 text, 6 list, 4 input); 1 external MerchantDialogPane support method; 9 compiler destructor items; 10 vtable/creator records; 7 source types/layouts; 11 resource literals; 1 jump table; 26 alignment spans; 6 excluded boundary groups.
- Current ordinary source uses the sole inherited `MerchantDialogPane::m_menuObjectId +0x270`/`SendMenuRequestPacket()` contract across all seven caller families, complete TextMenu/TextInput/list declarations, accepted virtual identities, source order `0/10/20/30`, and separate ItemMenuDialogs/SpellMenuDialogs/ArgumentedMenuDialogs family headers. Generated acceptance is established by the waited validation and physical readback recorded below.
- Lifecycle authority remains external as stated in Section 1.

### Historical Pre-Callback Generated State

- Dated command 25804 generated CPP defects: no include preamble; all three modeled TextInput definitions absent; no local reader implementation; stale virtual names; declarations in CPP; factory misplaced after list; UID0004H8 emitted under the wrong class/file; empty UID0000ES/UID00031Y markers.
- Dated command 25804 generated H defects: incomplete TextMenuDialog; phantom three-argument reply; impossible `m_itemIds[128]`; memberless public reader; no TextInput class; no factory/creator declarations; MerchantDialogPane omitted the shared identifier/request method; no size guards.
- Dated command 25850 preserved those defects and additionally found no `ItemMenuDialogs.h` or `SpellMenuDialogs.h`, a CPP-local ClientItem declaration with duplicate `m_menuObjectId`, an Argumented H duplicate `m_ownerId`, and old `TextMenuDialog::SendMenuRequestPacket(argument)` calls. These observations are superseded by the current accepted ordinary/formal/generated state and are retained only as provenance.

### Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence/classification |
| --- | --- | --- |
| File boundary | One practical TextMenuDialogs TU; base/item/spell/argumented families separate. | adjacency, calls, existing route, generated pair; high-confidence inference |
| Shared request method | `0x00517ec0` is `MerchantDialogPane::SendMenuRequestPacket`, not TextMenuDialog-only. | exact seven-family caller set; every caller derives MerchantDialogPane and supplies the common dword at +0x270 |
| Zero-xref factory wrappers | Retained source wrappers; keep and rename. | complete bodies/uniform setup; inferred liveness |
| Raw bounds helpers | Local `InitDlgMerc1Bounds`, `InitDlgMerc2Bounds`, `InitCenteredMerchantDialogBounds`; IDA comments only. | prologue/return/constants; descriptive |
| `0x51f310` | Raw ArgumentedMenuMenuItemList constructor `[51f310,51f37a)`, external. | ListPane ctor, +14c/+150/+154/+158, three vptr stores, `retn 10h` |
| Dialog slots | `OnControlCommand`, `UpdateActionButton`. | accepted DialogPane +48/+4c slots |
| List slots | `OnItemActivated`, `DrawListEntry`. | accepted ListPane +7c/+80 slots |
| Text layout | inherited MerchantDialogPane id@270, reply@274, reserved[3], count@278, flag@279, StringBase@27c, six ids@280; size 28c. | allocation/all bodies/destructor |
| Input layout | inherited MerchantDialogPane id@270, reserved dword@274, reply@278, option@27a, flag@27c, StringBase@280; size 284. | allocation/all bodies/destructor |
| Wide string | `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t> >`, not 24-byte SSO. | one-pointer helpers/destructor and preserved compiler names |
| List layout | 202-byte row; fields +14c/+150/+154; size 158. | ctor/append/reply/draw/allocation |
| Raw replies | Retained source, not dead. | exact nested inline behavior in active vtable handlers |
| Destructors | Ordinary source only; wrappers/thunks covered. | vtable-only routes, delete flags, inherited cleanup |
| Creator | Empty `MerchantDialogCreator : public LObject`; compiler data covered. | two stack stores feeding dispatcher |
| Protocol | BE integers, opcode 39/43, and `CP_ACP` conversions. | packet and Win32 call order |
| Resources | Eleven use-site literals, no standalone owned objects. | exact string xrefs |
| Jump table | `[517771,5177a0)` compiler switch table, not padding/source data. | eleven text addresses and switch |
| Generated state | Accepted formal docs and child routes generate the reconstructed target/support pairs; dated defects are historical. | current scoped validation plus dated command 25804 provenance |
| Operational script | Delete commands; retain placement history. | safety boundary |

Rejected alternatives: giant merchant/item/spell/argumented source, separate list TU, PacketBuffer/Socket ownership, raw vtable arrays, 128 ids, public reader, SSO SimpleUString, forced raw function definitions, and generated-file edits.

### Evidence Standards Used

- Highest weight: live canonical IDB reads, exact disassembly/decompilation, executable bytes/SHA256, xrefs, vtable routes, allocations, offsets, and packet order.
- Corroboration: current docs/formal channels, accepted base headers, generated physical readback, matching executed reports, and dated tracker/manual rows.
- Negative evidence: zero start/all-head/pointer routes, absent UDTs/comments, no duplicate report, external boundaries, and no addressable resource objects.
- Binary behavior controls. Missing symbols are replaced with project-consistent early-2000s descriptive source names.
- `auto_analysis_ready:false` was context only: health `ok`, Hex-Rays ready, bounded queries successful.

### Evidence Checked

- Live MCP: `idb_list`, `server_health`, `inspect_items`, `stack_frame`, `get_comments`, `xref_query`, `insn_query`, bounded bytes, and decompilation.
- Dated session evidence: primary bounded reads used `supervisor_uid0000hf_postdiscard_20260818`; final bounded recheck used `supervisor_uid0000hf_framefail_repair_20260818`, health `ok`, Hex-Rays ready, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x400000`. Session identities are dated evidence only and not permanent authority.
- Dated 2026-08-18 Gate 1 repair readback used live session `supervisor_uid0000im_postsaveverify_20260818_0305`, health `ok`, Hex-Rays ready, image base `0x400000`. `inspect_items`, `get_comments`, `stack_frame`, `xref_query`, and bounded bytes reconfirmed `sub_520D50` size `0x48` ending at data `0x00520d98`, `sub_520DA0` size `0x48` ending at data `0x00520de8`, and `sub_520DF0` size `0x3b` ending at data `0x00520e2b`; all three retained absent comment channels, their literal three-row frames, and the P02 inbound sets. This session identity is dated evidence only.
- Searches covered code `517450-51a520`, destructors, vtables, creator, literals, all target/support UIDs, generated pair, central reports, and target script text.
- Final current-session decompilation rechecked factory wrappers `5179e0/517a80/517b10/517ba0/517c30`: each allocates exactly `0x278` and calls its corresponding item/spell/argumented constructor. Constructor reads at `51a520/51b880/51ca40/51db40/51e9a0` each store packet dword `payload+1` at object `+0x270` and the family byte at `+0x274`, confirming the inherited-base and one-byte-derived layout used by C028.
- Negative checks covered 22 rename collisions (zero each), raw routes, UDTs, standalone resource ownership, duplicate declarations, stubs/TODO/placeholders, and external candidates.
- Intentionally skipped as unauthorized: mutations, validators, refresh, coverage edits, and lifecycle actions.

### Positive Evidence Summary

- Factory, three text classes, and retained replies form a closed source family through constructors, vtables, shared helpers, inline copies, and packet/resource vocabulary.
- Object sizes/offsets agree across allocation, construction, serialization, drawing, list access, and destruction.
- Nine text vtable views and three scalar wrappers align exactly with constructor stores and inherited slots.
- Factory constants, resources, opcodes, controls, and code-page behavior are stable across direct and inlined bodies.
- Current generated output implements the accepted formal child routes, method identities, layouts, source order, and corrected MerchantDialogPane support route.

### Current Generated Acceptance Receipt

- Commands through `000000026794`, including the successful command-26289, naming, six-empty-emitter, and four-claim callback sets, are dated history and are not permanent current authority. The UID0000OP Gate 2A ordinary/generated repair used scoped commands `000000027102`-`000000027109` for the seven changed by-* documents and final owning-file command `000000027111` at `2026-08-22T21:50:31-04:00` with `--wait-generated`; every B002 command exited `0`/`ok:1`, and command 27111 reported `generated_refresh:completed`.
- The command-27111 physical identities were: `TextMenuDialogs.cpp/.h` 22,776/3,222 bytes, SHA256 `66B6156BE7C746E8BE275E5840133EB93648E29E2BCF5F08AD41B8027215EABB` / `7DB708CF5441F22EC8488F737FE1A0DF1530EBB9BA63358E421BCFFFB4191F70`; `MerchantDialogPane.cpp/.h` 2,755/769 bytes, SHA256 `72E6A99A61D9F688F8657732ED5DCFC5DB3A30DE23620DBD3814E765AF6DF00B` / `7A7FD3420E6400BD757AA8C09089CBED2F62E2AE2D079011C90BBEB49BEF4FF9`.
- The same receipt gave `ItemMenuDialogs.cpp/.h` 19,464/4,026 bytes, SHA256 `A86F4550773F0A4D4D35E3626E3DC6088B9C71B9D8059797429C20DBB6A569AC` / `9CC2947EFF7C1230E8F68491B9EA53343CCEF65A003CC450FCEE8A1DBDDB2315`; `SpellMenuDialogs.cpp/.h` 10,133/3,884 bytes, SHA256 `F1CA1A56CF3856BB5A19BC56C1842DA585E04A9B4A775A55DF0EB8032BAB081A` / `28599D498A93BAB3C84AC27F0FD27B1C3B637D0F916E430ECDC7436692C7E8F5`; and `ArgumentedMenuDialogs.cpp/.h` 13,353/3,100 bytes, SHA256 `D6A9A7F575355F138BB6D78DB335D7433669A7D260B3EDF728F200B1C0038E88` / `EB0153B38960003184AAE6B69D87C6D3196BFCA03E55A42B6BBBB5C188BC6362`.
- Semantic readback found zero `m_dialogId`, zero stub/TODO/placeholder/raw-IDA-label tokens, and zero empty emitter markers in all ten files. Text/Input, Server/Client Item, Server/Client Spell, and Argumented constructors all assign inherited `m_menuObjectId`; all seven command paths use the inherited no-argument request method; only MerchantDialogPane H declares the base field/method and only MerchantDialogPane CPP defines `MerchantDialogPane::SendMenuRequestPacket()`. Argumented CPP contains exactly one nonempty source block each for UIDs `0003VK`, `0003VM`, `0003VN`, and `0003VO`, and Argumented H contains their matching `OnItemSelected`, `OnItemActivated`, `OnMouseEvent`, and `DrawListEntry` declarations.
- Command 27111 and every earlier fixed receipt are dated callback evidence. The supervisor must freshly reread all ten physical files, headers, sizes, hashes, and semantic counts at each later Gate 2A/2B where generated output matters.

### IDA MCP Facts

- Modeled UID0000OP-authored starts/sizes: `517450/321,5177a0/8a,517830/8a,5178c0/8a,517950/8a,5179e0/9e,517a80/88,517b10/88,517ba0/88,517c30/88,517f30/ee7,518e20/2e2,519110/fc,519210/2a1,5194c0/51,519520/61,519590/58,5195f0/12d,519840/b,519850/81,5198e0/996,51a280/155,51a3e0/37`. External modeled support method: `517ec0/66`, owned by MerchantDialogPane.
- Raw authored ranges: `[517cc0,517ce0)`, `[517ce0,517d00)`, `[517d00,517d23)`, `[519720,51983a)`, `[51a420,51a51c)`.
- Corrected raw SHA256: `EF4A262E5461A51445999484F9FD041702A13B7F9374BF34FC7FBE5A80136BFE`, `8B688949FB8D28522A6B1486AA2AEE180AE3BFC4888797E004B4D39A21778E0D`, `E150775B2478F04CF3532B1E10F1B52EF1B17A6A939C7C04C23043237FEB1D2F`, `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`, `0178A271A9088C87DA9EFBFF60F81AD248E5C2C16F1C3A4B804B85C3768D75DC`.
- Switch table `[517771,5177a0)`, 47 bytes, SHA256 `679413E166A7EABC5AB5D83BDF4F11CA1F65CB9024359FA8187057E639284231`.
- Vtable bases/stores: dialog `61ecac/61ed0c/61ed3c` from `517fa0/517fa6/517fb0`; list `61ed48/61edd0/61ee00` from `519560/519566/519570`; input `61ee0c/61ee6c/61ee9c` from `519950/519956/519960`.
- Creator `61e8dc-61e8ec`: COL `64b524`, slots `514e60,4f4b10,41b6c0`; vtable `61e8e0` stores at `507ddc,51034b`.
- No stable text-class UDT exists; no UDT mutation is recommended.
- All rename-start AR/AP/FR/FP channels are absent except exact FR at `519110` and `5195f0`; raw `519720` has exact AP. Destructor thunk AR is `Block`; other channels absent.

### Function / Child Inventory

Each row is independently complete. `O/E/P` means direct canonical owner, direct emitter, and direct source parent. `D25850` is the dated command-25850 physical generated readback, not permanent current authority.

| ID | Exact identity / range | O/E/P | Historical pre-callback -> accepted current score and metadata | CPP/H/compiler and generated disposition | Destination / claim |
| --- | --- | --- | --- | --- | --- |
| I001 | `CreateMerchantMenuDialog [0x00517450,0x00517771)`, SHA256 `8D67E064781985BAF5B98F9AABBB28436546494853374A7C0F1A1D58AFDCD224` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; reconstructable true; emitter position blank -> `0` | CPP in UID000238; H through UID0000OP; D25850 target composition defective, callback emits accepted source | UID000238 / C015 |
| I002 | `CreateTextMenuDialog [0x005177a0,0x0051782a)`, SHA256 `65CFAB594C55EF8946C6CAC8A475615A1FC5ECD507BE926AAF75928D75461693` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; H through UID0000OP; D25850 source present in defective composition, callback preserves/repairs | UID000238 / C016 |
| I003 | `CreateTextMenuDialogWithExtraString [0x00517830,0x005178ba)`, SHA256 `080D81474B9293654A9EA4C29FF63537FCE6AF1A016B8D0A0231C9D95002CAA7` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; H through UID0000OP; D25850 source present in defective composition, callback preserves/repairs | UID000238 / C017 |
| I004 | `CreateTextInputMenuDialog [0x005178c0,0x0051794a)`, SHA256 `FB41BF30E1CCCF0AE2BB6867366CA1A71156BD27FC5DA5E48F36106D7C22460C` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; H through UID0000OP; D25850 source present but TextInput definitions absent, callback repairs | UID000238 / C018 |
| I005 | `CreateTextInputMenuDialogWithExtraString [0x00517950,0x005179da)`, SHA256 `DFCB76022E8C2F49E66990E083F9A21E3F4C4104FFA2DC2D973225FB59098D27` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; H through UID0000OP; D25850 source present but TextInput definitions absent, callback repairs | UID000238 / C019 |
| I006 | `CreateServerItemMenuDialog [0x005179e0,0x00517a7e)`, SHA256 `FB43351D1FD5E170B3E3636BDF4C536C2E3CC8D9A76CC6018A3ABA2C70C7B874` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; no direct H declaration; D25850 source present, callback inlines the nonphysical server bounds operation | UID000238 / C020 |
| I007 | `CreateClientItemMenuDialog [0x00517a80,0x00517b08)`, SHA256 `1F55190F365FFBB548437DF78CA9342550B879C22CD45C8C6B624E5780ECF9CB` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; no direct H declaration; D25850 source present, callback preserves/repairs | UID000238 / C021 |
| I008 | `CreateServerSpellMenuDialog [0x00517b10,0x00517b98)`, SHA256 `D216EA02E6D4FE73DC89A0848004559E6777C2EBAE95383E2495EF141FC04FA0` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; no direct H declaration; D25850 source present, callback preserves/repairs | UID000238 / C022 |
| I009 | `CreateClientSpellMenuDialog [0x00517ba0,0x00517c28)`, SHA256 `C15FFF0E8B1D9079B36173584285C518CC3C43748E5D1854C06C47A6AAAF123B` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; no direct H declaration; D25850 source present, callback preserves/repairs | UID000238 / C023 |
| I010 | `CreateArgumentedMenuDialog [0x00517c30,0x00517cb8)`, SHA256 `3C86DF53D0FD6D746504281B82BC838BF668A07F21F86FB653C1A5B365F8B62F` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | CPP in UID000238; no direct H declaration; D25850 source present, callback preserves/repairs | UID000238 / C024 |
| I011 | raw `InitDlgMerc1Bounds [0x00517cc0,0x00517ce0)`, SHA256 `EF4A262E5461A51445999484F9FD041702A13B7F9374BF34FC7FBE5A80136BFE` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | namespace-local CPP; no H; D25850 helper source present; IDA remains raw with AP only | UID000238 / C025 |
| I012 | raw `InitDlgMerc2Bounds [0x00517ce0,0x00517d00)`, SHA256 `8B688949FB8D28522A6B1486AA2AEE180AE3BFC4888797E004B4D39A21778E0D` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | namespace-local CPP; no H; D25850 helper source present; IDA remains raw with AP only | UID000238 / C026 |
| I013 | raw `InitCenteredMerchantDialogBounds [0x00517d00,0x00517d23)`, SHA256 `E150775B2478F04CF3532B1E10F1B52EF1B17A6A939C7C04C23043237FEB1D2F` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position blank -> `0` | namespace-local CPP; no H; D25850 helper source present; IDA remains raw with AP only | UID000238 / C027 |
| I014 | `MerchantDialogPane::SendMenuRequestPacket [0x00517ec0,0x00517f26)`, SHA256 `14A50CC09956CDF5005C574BC476CB18A6D12C67D89E2D4247F3011C922B445D` | accepted current O/E/P `000083/0000L9/000083`; dated pre-callback `0000ES/0000OP/0000ES` is superseded because this inherited shared-base method serves all seven MerchantDialogPane-derived families and now emits through MerchantDialogPane CPP/H | UID0004H8 `91/93 -> 94/94`; true; emitter position remains blank | CPP/H under MerchantDialogPane support, excluded from UID0000OP source; D25850 emitted wrong class/file, and the accepted callback moved it to the base route | UID0004H8 / C028 |
| I015 | `TextMenuDialog` constructor `[0x00517f30,0x00518e17)`, SHA256 `AD46EB670E3749E68C35F92FD211D04FE39B2410604C2C2E19D3BBC0B9033E7F` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004H9 `88/90 -> 94/94`; true; position follows class `10` | child CPP; H in UID0000ES; D25850 body present but composition/layout stale, callback repairs | UID0004H9 / C029 |
| I016 | `TextMenuDialog::OnPaint [0x00518e20,0x00519102)`, SHA256 `ABAE29159C70F5FDDD00B3486578765822A82767596F8047FAFE07EF8295D053` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004HA `89/91 -> 94/94`; true; position follows class `10` | child CPP; declaration in UID0000ES H; D25850 body present, callback preserves resources and repairs topology | UID0004HA / C030 |
| I017 | retained `TextMenuDialog::SendMenuReply(unsigned short) [0x00519110,0x0051920c)`, SHA256 `1E9E70C505E2A76AB0DB1D26C6B30126009A9F96116B54B72831042FC7BB73A9` | O `0000ES`; E `0000ES`; P `0000ES` | UID0004HB `93/94 -> 94/94`; true; position follows class `10` | child CPP and one H declaration; D25850 body present with stale topology/call spelling, callback repairs | UID0004HB / C031 |
| I018 | `TextMenuDialog::OnControlCommand [0x00519210,0x005194b1)`, SHA256 `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004HC `91/93 -> 94/94`; true; position follows class `10` | child CPP; declaration in UID0000ES H; D25850 old source name, callback renames/preserves body | UID0004HC / C032 |
| I019 | `TextMenuDialog::UpdateActionButton [0x005194c0,0x00519511)`, SHA256 `202D588F86F5B635DE0AAE3BD2A65622C491201870FEE0E2F2A3D32976412394` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004HD `91/92 -> 94/94`; true; position follows class `10` | child CPP; declaration in UID0000ES H; D25850 old source name, callback renames/preserves body | UID0004HD / C033 |
| I020 | `TextMenuItemList` constructor `[0x00519520,0x00519581)`, SHA256 `0D6A1E631E7D8E5E6B9A16FAAB0AB03D894BD15B2662FEF5EEBF73C2D315085B` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 source present, callback preserves/repairs private type order | UID0000ET / C034 |
| I021 | `TextMenuItemList::AddTextEntry [0x00519590,0x005195e8)`, SHA256 `EF5C430022AF8A12D745CB0EF67D7C07DF8B461E00312CBBBC0DFC4DB9CA33F5` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 source present, callback preserves exact row storage | UID0000ET / C035 |
| I022 | retained `TextMenuItemList::SendSelectedTextMenuReply [0x005195f0,0x0051971d)`, SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A` | O `0000ET`; E `0000ET`; P `0000ET` | UID0004HE stays `93/94`; true; position follows class `20` | child CPP; no H; D25850 retained body present, callback changes only caller spelling as specified | UID0004HE / C036 |
| I023 | raw retained `TextMenuItemList::SendTextMenuReply [0x00519720,0x0051983a)`, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A` | O `0000ET`; E `0000ET`; P `0000ET` | UID0004HF stays `93/94`; true; position follows class `20` | child CPP; no H; D25850 retained body present; IDA remains raw with already-present AP | UID0004HF / C037 |
| I024 | `TextMenuItemList::OnItemActivated [0x00519840,0x0051984b)`, SHA256 `F2C071C8204BCC00E278617B3B90AB449ECC07B06E405ED3D5D305B6C0B4C98F` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 old inherited name, callback repairs | UID0000ET / C038 |
| I025 | `TextMenuItemList::DrawListEntry [0x00519850,0x005198d1)`, SHA256 `717048638DECF81230979B110517B11C2E3883CF0D5AE40705B28287ABC0BBB6` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 old inherited name, callback repairs | UID0000ET / C039 |
| I026 | `TextInputMenuDialog` constructor `[0x005198e0,0x0051a276)`, SHA256 `5B359AF02028C9613F544FB5ACA93BDD8820D7BD51F535AF82BFF00414180E28` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position blank -> `30` | UID0000ER CPP/H; D25850 definition and class H absent, callback emits both | UID0000ER / C040 |
| I027 | `TextInputMenuDialog::OnControlCommand [0x0051a280,0x0051a3d5)`, SHA256 `B8BB3FCC44E551653FFE8AC012505494F38E33B79F8C9561C20F57475156892E` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position blank -> `30` | UID0000ER CPP/H; D25850 definition absent, callback emits exact handler | UID0000ER / C041 |
| I028 | `TextInputMenuDialog::UpdateActionButton [0x0051a3e0,0x0051a417)`, SHA256 `BF50AA0FDAFBD41C49B1C55F45807F906FD1FC605DB8318DC5B66AF90516B168` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position blank -> `30` | UID0000ER CPP/H; D25850 definition absent, callback emits exact handler | UID0000ER / C042 |
| I029 | raw retained `TextInputMenuDialog::SendInputReply [0x0051a420,0x0051a51c)`, SHA256 `0178A271A9088C87DA9EFBFF60F81AD248E5C2C16F1C3A4B804B85C3768D75DC` | O `0000ER`; E `0000ER`; P `0000ER` | UID000239 `90/89 -> 93/94`; true; position follows class `30` | child CPP; no H; D25850 body present outside complete class route; callback preserves and routes it; IDA AP only | UID000239 / C043 |
| I030 | input secondary destructor thunk `[0x00520b29,0x00520b34)`, SHA256 `8FD2B5F5BF9DF4F5E24587CACD40EEED00A4C85C57F80173D2B3B71714F91694` | O `NONE`; E blank; P source class `0000ER` | UID00037C stays `88/92`; reconstructable false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037C / C044 |
| I031 | input tertiary destructor thunk `[0x00520b34,0x00520b3f)`, SHA256 `D267B2786C78A89F16DA16144481A0B7990D0C316E802A1496A36967FFDA7DCC` | O `NONE`; E blank; P source class `0000ER` | UID00037C stays `88/92`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037C / C044 |
| I032 | text secondary destructor thunk `[0x00520b3f,0x00520b4a)`, SHA256 `08992D1F5DB5575F6A25B6BF519ECC352B7B48F1428305B320D40D900D61F24F` | O `NONE`; E blank; P source class `0000ES` | UID00037E stays `85/92`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037E / C044 |
| I033 | text tertiary destructor thunk `[0x00520b4a,0x00520b55)`, SHA256 `1B75EEF56F526A9395C3CE3930965DA690186C11A2EA33C1BA2687351F66D96F` | O `NONE`; E blank; P source class `0000ES` | UID00037E stays `85/92`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037E / C044 |
| I034 | list secondary destructor thunk `[0x00520b55,0x00520b60)`, SHA256 `56674953779648B99BD6DA7AA40E5F33269C1584A1770129DDB5B9AD5241B4F1` | O `NONE`; E blank; P source class `0000ET` | UID00037G stays `88/92`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037G / C044 |
| I035 | list tertiary destructor thunk `[0x00520b60,0x00520b6b)`, SHA256 `6260A0933A6DEDE7C5E3675A10B1B2EF8DFEA317A9F4F0E6775995A6B71D991D` | O `NONE`; E blank; P source class `0000ET` | UID00037G stays `88/92`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037G / C044 |
| I036 | input scalar deleting destructor `[0x00520d50,0x00520d98)`, SHA256 `8E10766B898AD94D5CFDBBA533FB80158B57141324118AB36F6005FBEB1FFD2E` | O `NONE`; E blank; P source class `0000ER` | UID00037D stays `88/92`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037D / C044 |
| I037 | text scalar deleting destructor `[0x00520da0,0x00520de8)`, SHA256 `0F3F788F1B80250FDE7DA653ED4B2C7D0ED39E4A173AE5AF9E12C02D80736B78` | O `NONE`; E blank; P source class `0000ES` | UID00037F stays `85/92`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037F / C044 |
| I038 | list scalar deleting destructor `[0x00520df0,0x00520e2b)`, SHA256 `CFC60E36897DC9E4C12D0D2F0F585A1C3FADC8D7D5AE6BBCCB3B188A145DDE82` | O `NONE`; E blank; P source class `0000ET` | UID00037H stays `86/91`; false | compiler-covered no-code; formal CPP/H blank; D25850 compiler output exists, preserve | UID00037H / C044 |
| I039 | TextMenuDialog primary vtable view at `0x0061ecac` | O `0000OP`; E `0000OP`; P `0000ES` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 vtable present but marker empty, callback fills marker | UID00031Y / C045 |
| I040 | TextMenuDialog secondary vtable view at `0x0061ed0c` | O `0000OP`; E `0000OP`; P `0000ES` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I041 | TextMenuDialog tertiary vtable view at `0x0061ed3c` | O `0000OP`; E `0000OP`; P `0000ES` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I042 | TextMenuItemList primary vtable view at `0x0061ed48` | O `0000OP`; E `0000OP`; P `0000ET` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I043 | TextMenuItemList secondary vtable view at `0x0061edd0` | O `0000OP`; E `0000OP`; P `0000ET` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I044 | TextMenuItemList tertiary vtable view at `0x0061ee00` | O `0000OP`; E `0000OP`; P `0000ET` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I045 | TextInputMenuDialog primary vtable view at `0x0061ee0c` | O `0000OP`; E `0000OP`; P `0000ER` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I046 | TextInputMenuDialog secondary vtable view at `0x0061ee6c` | O `0000OP`; E `0000OP`; P `0000ER` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I047 | TextInputMenuDialog tertiary vtable view at `0x0061ee9c` | O `0000OP`; E `0000OP`; P `0000ER` | UID00031Y `87/91 -> 93/94`; true | compiler-covered marker CPP; H blank; D25850 present/empty marker, callback fills | UID00031Y / C045 |
| I048 | MerchantDialogCreator COL/vtable record `[0x0061e8dc,0x0061e8ec)` | O `0000OP`; E `0000OP`; P creator type under `0000ES` | UID0003IP `88/93 -> 93/94`; true | compiler-covered marker CPP; declaration in UID0000ES H; D25850 record present but creator route incomplete, callback repairs | UID0003IP / C046 |
| I049 | source enum `MerchantMenuDialogSubtype` | O `0000OP`; E `0000OP`; P `000238` | UID000238 `90/93 -> 94/94`; true; position `0` | CPP only in UID000238; no separate H declaration; D25850 enum present, callback preserves exact values | UID000238 / C008,C015-C024 |
| I050 | namespace-local `TextMenuPayloadReader` | O `0000OP`; E `0000OP`; P `0000ES` | UID0000ES `86/86 -> 94/94`; true; position `10` | CPP only; D25850 public/memberless reader defect, callback emits local implementation | UID0000ES / C009,C014 |
| I051 | empty LObject-derived `MerchantDialogCreator` | O `0000OP`; E `0000OP`; P `0000ES` | UID0000ES `86/86 -> 94/94`; true; position `10` | H declaration; compiler record covered by I048; D25850 declaration absent, callback emits | UID0000ES / C008,C046 |
| I052 | public `TextMenuDialog`, size `0x28c` | O `0000OP`; E `0000OP`; P `0000ES` | UID0000ES `86/86 -> 94/94`; true; position `10` | H plus child CPP; D25850 H incomplete/CPP declarations stale, callback replaces | UID0000ES / C009 |
| I053 | private `TextMenuItemListEntry`, size `0x202` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position `20` | CPP only; D25850 representation incomplete, callback emits before list class | UID0000ET / C011 |
| I054 | private `TextMenuItemList`, size `0x158` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position `20` | CPP only; D25850 source exists with stale inherited labels, callback repairs | UID0000ET / C011 |
| I055 | public `TextInputMenuDialog`, size `0x284` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position `30` | H plus CPP; D25850 class and definitions absent, callback emits complete pair | UID0000ER / C010 |
| I056 | pooled wide literal `DLGMERC1.EPF` at `0x0061f804` | O `0000OP`; E `0000OP`; P use sites I015 plus external item/spell constructors | no independent UID/score; target UID0000OP `90/86 -> 94/94`; use-site literal, no object | CPP use-site literal; no H/object; D25850 literal references present, callback preserves | UID0000OP / C013 |
| I057 | pooled wide literal `DLGMERC1.EPD` at `0x0061f820` | O `0000OP`; E `0000OP`; P use sites I015 plus external item/spell constructors | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 references present, callback preserves | UID0000OP / C013 |
| I058 | pooled wide literal `DLGMERC2.EPF` at `0x0061f8cc` | O `0000OP`; E `0000OP`; P I026 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 references present, callback preserves | UID0000OP / C013 |
| I059 | pooled wide literal `DLGMERC2.EPD` at `0x0061f8e8` | O `0000OP`; E `0000OP`; P I026 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 references present, callback preserves | UID0000OP / C013 |
| I060 | pooled wide literal `MERTOP.EPD` at `0x0061f83c` | O `0000OP`; E `0000OP`; P I016 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 reference present, callback preserves | UID0000OP / C013 |
| I061 | pooled wide literal `MERMID.EPD` at `0x0061f854` | O `0000OP`; E `0000OP`; P I016 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 reference present, callback preserves | UID0000OP / C013 |
| I062 | pooled wide literal `MERBTOP.EPD` at `0x0061f86c` | O `0000OP`; E `0000OP`; P I016 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 reference present, callback preserves | UID0000OP / C013 |
| I063 | pooled wide literal `MERBUT.EPD` at `0x0061f884` | O `0000OP`; E `0000OP`; P I016 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 reference present, callback preserves | UID0000OP / C013 |
| I064 | pooled wide literal `MERBBOT.EPD` at `0x0061f89c` | O `0000OP`; E `0000OP`; P I016 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 reference present, callback preserves | UID0000OP / C013 |
| I065 | pooled wide literal `MERBOT.EPD` at `0x0061f8b4` | O `0000OP`; E `0000OP`; P I016 | no independent UID/score; target `90/86 -> 94/94`; use-site literal | CPP use-site literal; no H/object; D25850 reference present, callback preserves | UID0000OP / C013 |
| I066 | pooled wide literal `NP` at `0x0061484c` | O `0000OP`; E `0000OP`; P in-scope use sites I015/I016/I026; 57 external uses | no independent UID/score; target `90/86 -> 94/94`; shared use-site literal | CPP use-site literal; no H/object; D25850 references present, callback preserves | UID0000OP / C013 |
| I067 | switch jump table `[0x00517771,0x005177a0)`, 47 bytes, SHA256 `679413E166A7EABC5AB5D83BDF4F11CA1F65CB9024359FA8187057E639284231` | O `0000OP`; E `0000OP` compiler; P I001 | no independent score; parent UID000238 `90/93 -> 94/94` | compiler-emitted from source switch; no handwritten CPP/H object; D25850 table exists, preserve | UID000238 / C004 |
| I068 | CC alignment `[0x0051782a,0x00517830)` | O `0000OP`; E none; P I002/I003 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I069 | CC alignment `[0x005178ba,0x005178c0)` | O `0000OP`; E none; P I003/I004 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I070 | CC alignment `[0x0051794a,0x00517950)` | O `0000OP`; E none; P I004/I005 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I071 | CC alignment `[0x005179da,0x005179e0)` | O `0000OP`; E none; P I005/I006 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I072 | CC alignment `[0x00517a7e,0x00517a80)` | O `0000OP`; E none; P I006/I007 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I073 | CC alignment `[0x00517b08,0x00517b10)` | O `0000OP`; E none; P I007/I008 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I074 | CC alignment `[0x00517b98,0x00517ba0)` | O `0000OP`; E none; P I008/I009 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I075 | CC alignment `[0x00517c28,0x00517c30)` | O `0000OP`; E none; P I009/I010 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I076 | CC alignment `[0x00517cb8,0x00517cc0)` | O `0000OP`; E none; P I010/I011 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I077 | CC alignment `[0x00517d23,0x00517d30)` | O `0000OP`; E none; P I013/I094 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I078 | CC alignment `[0x00517f26,0x00517f30)` | O `0000OP`; E none; P I014/I015 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I079 | CC alignment `[0x00518e17,0x00518e20)` | O `0000OP`; E none; P I015/I016 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I080 | CC alignment `[0x00519102,0x00519110)` | O `0000OP`; E none; P I016/I017 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I081 | CC alignment `[0x0051920c,0x00519210)` | O `0000OP`; E none; P I017/I018 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I082 | CC alignment `[0x005194b1,0x005194c0)` | O `0000OP`; E none; P I018/I019 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I083 | CC alignment `[0x00519511,0x00519520)` | O `0000OP`; E none; P I019/I020 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I084 | CC alignment `[0x00519581,0x00519590)` | O `0000OP`; E none; P I020/I021 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I085 | CC alignment `[0x005195e8,0x005195f0)` | O `0000OP`; E none; P I021/I022 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I086 | CC alignment `[0x0051971d,0x00519720)` | O `0000OP`; E none; P I022/I023 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I087 | CC alignment `[0x0051983a,0x00519840)` | O `0000OP`; E none; P I023/I024 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I088 | CC alignment `[0x0051984b,0x00519850)` | O `0000OP`; E none; P I024/I025 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I089 | CC alignment `[0x005198d1,0x005198e0)` | O `0000OP`; E none; P I025/I026 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I090 | CC alignment `[0x0051a276,0x0051a280)` | O `0000OP`; E none; P I026/I027 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I091 | CC alignment `[0x0051a3d5,0x0051a3e0)` | O `0000OP`; E none; P I027/I028 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I092 | CC alignment `[0x0051a417,0x0051a420)` | O `0000OP`; E none; P I028/I029 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I093 | CC alignment `[0x0051a51c,0x0051a520)` | O `0000OP`; E none; P I029/I095 boundary | no UID/score; target `90/86 -> 94/94` | no-code compiler alignment; no generated source entity | UID0000OP / C004 |
| I094 | external MerchantDialogPane body set `[0x00517d30,0x00517ec0)`; I014 is separately inventoried | O/E/P `0000L9/0000L9/000083` | UID0000L9 `90/90 -> 94/94`; UID000083 `92/94 -> 94/94`; true | external MerchantDialogPane CPP/H; D25850 base incomplete, exact support callback repairs; excluded from target source | UID0000L9/000083 / C003,C028 |
| I095 | external item/spell constructor set `[0x0051a520,0x0051c46d)` UID0000KF and `[0x0051ca40,0x0051e63d)` UID0000O2 | O `FILE` for each unit; E `0000KF` and `0000O2`; P ItemMenuDialogs and SpellMenuDialogs | UID0000KF stays `88/89`; UID0000O2 stays `90/91`; file metadata unchanged | external CPP/H; D25850 dependent headers absent and shared call stale, exact C028 support repair only | UID0000KF/0000O2 / C003,C028 |
| I096 | external ArgumentedMenuDialogs set `[0x0051e9a0,0x0051fc8d)`, including constructor `[0x0051f310,0x0051f37a)` | O `FILE`; E `0000HI`; P ArgumentedMenuDialogs UID0000HI | UID0000HI stays `91/93`; file metadata unchanged | external CPP/H; D25850 duplicate owner field/shared call stale, exact C005/C028 repair; no target source | UID0000HI / C003,C005,C028 |
| I097 | external ArgumentedItemInputDialogs set `[0x0051fc90,0x00520539)` | O `FILE`; E `0000HH`; P ArgumentedItemInputDialogs UID0000HH | UID0000HH stays `93/94`; file metadata unchanged | external CPP/H; D25850 physically outside target and preserved; no target source | UID0000HH / C003 |
| I098 | exact non-target compiler-neighbor set inside `[0x00520abb,0x00520e2b)`: `[0x00520abb,0x00520b29)`, `[0x00520b6b,0x00520d50)`, `[0x00520d98,0x00520da0)`, `[0x00520de8,0x00520df0)` | O `NONE`; E blank; P mixed compiler aggregate UID0001BX | UID0001BX stays `90/92`; reconstructable false; owner/emitter remain `NONE`/blank | compiler-generated external child thunks/wrappers plus their bounded padding; formal CPP/H blank at aggregate and no target generated entity; D25850 bytes remain compiler products of external source classes | UID0001BX / C003,C044 |
| I099 | immediate external vtable successor `ServerItemMenuDialog` primary view at `0x0061eea8` | O `0000KF`; E `0000KF`; P class UID0000CZ | UID0000KF stays `88/89`; UID0000CZ stays `88/89`; reconstructable source classes remain with ItemMenuDialogs | compiler-emitted external data; no target CPP/H object; D25850 successor exists and is preserved; exact physical item replaces the former generic dependency row | UID0000KF/0000CZ / C003,C028 |

- Reconciled total: 99 explicit rows = 28 UID0000OP-authored bodies + 1 external MerchantDialogPane support method + 9 compiler destructor items + 10 vtable/creator records + 7 types/layouts + 11 literals + 1 jump table + 26 alignments + 6 exact bounded exclusions.
- `InitServerItemMenuBounds` was a report-draft convenience wrapper with no physical body, source UID, xrefs, range, or independent ownership. It is removed from formal CPP; its `InitDlgMerc1Bounds` call and `right = left + 425` / `bottom = top + 354` assignments are inlined at the two existing server-item factory sites. It therefore adds neither a 100th inventory row nor a new claim.

### Direct Xref / Caller Inventory

The inventory IDs below are exact twins of Section 14. Inbound code and data are always stated separately. Outgoing sets contain direct call targets; an explicit `none` means the item's bounded instructions contain no call instruction. Tail-adjustor/compiler and non-code rows state their negative-call disposition rather than inheriting an aggregate assertion.

| ID | Exact inbound code set/count | Exact inbound data set/count | Exact outgoing call disposition |
| --- | --- | --- | --- |
| I001 | `{507df4,51035f}` / 2 | `{}` / 0 | targets `{575470,4b7c50,4f4aa0,517f30,5198e0,51a520,51b880,51ca40,51db40,51e9a0,5c772f}` |
| I002 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,517f30,5c772f}` |
| I003 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,517f30,5c772f}` |
| I004 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,5198e0,5c772f}` |
| I005 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,5198e0,5c772f}` |
| I006 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,51a520,5c772f}` |
| I007 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,51b880,5c772f}` |
| I008 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,51ca40,5c772f}` |
| I009 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,51db40,5c772f}` |
| I010 | `{}` / 0 | `{}` / 0 | targets `{4b7c50,4f4aa0,51e9a0,5c772f}` |
| I011 | `{}` / 0 | `{}` / 0 | call `517cd4 -> 4b7c50` only |
| I012 | `{}` / 0 | `{}` / 0 | call `517cf4 -> 4b7c50` only |
| I013 | `{}` / 0 | `{}` / 0 | call `517d17 -> 4b7c50` only |
| I014 | `{519362,51a2b1,51aced,51c34d,51d55d,51e51d,51f1ad}` / 7 | `{}` / 0 | targets `{575380,5753f0,574bb0,49dad0,5c772f}` |
| I015 | `{5174df,51752d,517809,517899}` / 4 | `{}` / 0 | targets `{5c7740,49d8a0,582a80,516030,575470,5754c0,4d1f30,575480,516220,60d120,575a90,582bb0,582b30,4f4aa0,519520,4b7c50,4991f0,49dc10,495bf0,520540,499030,5cd657,4f3c50,4985a0,49fc00,49dd80,49ddd0,544bd0,4b7e10,519590,49db60,5446b0,49dfd0,49e190,5c772f,495450,5c7655}` |
| I016 | `{}` / 0 | `{61ecf0}` / 1 | targets `{457a60,4b9660,4d02f0,543d70,4b7c50,4b7e10,5c772f}`; data dependencies `69b3e8,69b3fc` are not calls |
| I017 | `{}` / 0 | `{}` / 0 | targets `{516030,575650,5756d0,575670,584540,5757d0,574bb0,5c772f,5c7655}` |
| I018 | `{}` / 0 | `{61ecf4}` / 1 | targets `{516030,575650,5756d0,575670,584540,5757d0,574bb0,5c772f,517ec0,4f3dc0,575380,5753f0,5753a0,49dad0,5c7655}` |
| I019 | `{}` / 0 | `{61ecf8}` / 1 | target `{4f3e20}` |
| I020 | `{51814d,5186d4}` / 2 | `{}` / 0 | target `{4f3a50}` |
| I021 | `{5189ed}` / 1 | `{}` / 0 | targets `{5cd657,4f3c50,5c772f}` |
| I022 | `{}` / 0 | `{}` / 0 | targets `{4f3dc0,516030,575380,5753f0,5753a0,584540,5757d0,574bb0,5c772f,5c7655}` |
| I023 | `{}` / 0 | `{}` / 0 | calls `519736->516030,51974e->575380,519771->575380,519792->5753f0,5197b4->5753a0,5197ef->584540,5197f5->5757d0,519820->574bb0,51982a->5c772f,519835->5c7655` |
| I024 | `{}` / 0 | `{61edc4}` / 1 | none; the bounded body contains no call instruction |
| I025 | `{}` / 0 | `{61edc8}` / 1 | targets `{4f3f00,4b9660,4b9680,4b9690,4b9600,4bab70}` |
| I026 | `{51757b,5175c9,517929,5179b9}` / 4 | `{}` / 0 | targets `{5c7740,49d8a0,582a80,516030,575470,5754c0,4d1f30,575480,516220,60d120,575a90,582bb0,582b30,4b7c50,4f4aa0,4991f0,49dc10,495bf0,520540,499030,498920,49fc00,49dd80,49ddd0,544bd0,49db60,5446b0,49dfd0,49e190,5c772f,5c7655}` |
| I027 | `{}` / 0 | `{61ee54}` / 1 | targets `{517ec0,5c772f,498c10,516030,575650,5756d0,575670,584540,5757d0,575850,574bb0,49dad0}` |
| I028 | `{}` / 0 | `{61ee58}` / 1 | target `{498c60}` |
| I029 | `{}` / 0 | `{}` / 0 | calls `51a43a->516030,51a459->575650,51a474->575650,51a48d->5756d0,51a4a8->575670,51a4cd->584540,51a4d3->5757d0,51a4ea->575850,51a505->574bb0,51a511->5c772f` |
| I030 | `{}` / 0 | `{61ee6c}` / 1 | none; compiler adjustor/tail route contains no call instruction |
| I031 | `{}` / 0 | `{61ee9c}` / 1 | none; compiler adjustor/tail route contains no call instruction |
| I032 | `{}` / 0 | `{61ed0c}` / 1 | none; compiler adjustor/tail route contains no call instruction |
| I033 | `{}` / 0 | `{61ed3c}` / 1 | none; compiler adjustor/tail route contains no call instruction |
| I034 | `{}` / 0 | `{61edd0}` / 1 | none; compiler adjustor/tail route contains no call instruction |
| I035 | `{}` / 0 | `{61ee00}` / 1 | none; compiler adjustor/tail route contains no call instruction |
| I036 | `{520b2f,520b3a}` / 2 | `{61ee0c}` / 1 | targets `{582b30,49d9f0,4f4ac0,41b6a0}` |
| I037 | `{520b45,520b50}` / 2 | `{61ecac}` / 1 | targets `{582b30,49d9f0,4f4ac0,41b6a0}` |
| I038 | `{520b5b,520b66}` / 2 | `{61ed48}` / 1 | targets `{4f3b60,4f4ac0,41b6a0}` |
| I039 | `{}` / 0 | `{517fa0}` / 1 | vtable data; no instructions or outgoing calls |
| I040 | `{}` / 0 | `{517fa6}` / 1 | vtable data; no instructions or outgoing calls |
| I041 | `{}` / 0 | `{517fb0}` / 1 | vtable data; no instructions or outgoing calls |
| I042 | `{}` / 0 | `{519560}` / 1 | vtable data; no instructions or outgoing calls |
| I043 | `{}` / 0 | `{519566}` / 1 | vtable data; no instructions or outgoing calls |
| I044 | `{}` / 0 | `{519570}` / 1 | vtable data; no instructions or outgoing calls |
| I045 | `{}` / 0 | `{519950}` / 1 | vtable data; no instructions or outgoing calls |
| I046 | `{}` / 0 | `{519956}` / 1 | vtable data; no instructions or outgoing calls |
| I047 | `{}` / 0 | `{519960}` / 1 | vtable data; no instructions or outgoing calls |
| I048 | `{}` / 0 | COL `61e8dc` `{}` / 0; vtable `61e8e0` `{507ddc,51034b}` / 2 | compiler data; no instructions or outgoing calls |
| I049 | not an address entity | not an address entity | enum type; no instruction body or calls |
| I050 | not an address entity | not an address entity | namespace-local parser type; no independent instruction body or calls |
| I051 | not an address entity | not an address entity | source class; its compiler record is I048; no independent instruction body |
| I052 | not an address entity | not an address entity | source class; code call closure is I015-I019 |
| I053 | not an address entity | not an address entity | source row type; no independent instruction body |
| I054 | not an address entity | not an address entity | source class; code call closure is I020-I025 |
| I055 | not an address entity | not an address entity | source class; code call closure is I026-I029 |
| I056 | `{}` / 0 | global `{5181c7,51854d,51bb44,51bdf4,51cd48,51cfce,51dd9b,51e027}` / 8; in-scope `{5181c7,51854d}` / 2 | pooled literal data; no outgoing calls |
| I057 | `{}` / 0 | global `{518759,518abc,51c073,51c2fb,51d288,51d50b,51e23b,51e4c4}` / 8; in-scope `{518759,518abc}` / 2 | pooled literal data; no outgoing calls |
| I058 | `{}` / 0 | `{519b2e,519dcd}` / 2, both in-scope | pooled literal data; no outgoing calls |
| I059 | `{}` / 0 | `{519fd1,51a267}` / 2, both in-scope | pooled literal data; no outgoing calls |
| I060 | `{}` / 0 | `{518ec4}` / 1 | pooled literal data; no outgoing calls |
| I061 | `{}` / 0 | `{518ed6}` / 1 | pooled literal data; no outgoing calls |
| I062 | `{}` / 0 | `{518ee8}` / 1 | pooled literal data; no outgoing calls |
| I063 | `{}` / 0 | `{518efd}` / 1 | pooled literal data; no outgoing calls |
| I064 | `{}` / 0 | `{518f12}` / 1 | pooled literal data; no outgoing calls |
| I065 | `{}` / 0 | `{518f27}` / 1 | pooled literal data; no outgoing calls |
| I066 | `{}` / 0 | global `{4726d5,473606,475de0,476ef0,478586,4785d2,47861e,479a0b,47bed4,47d501,4959ed,495a1b,495f20,498306,49835c,4983b1,49f2af,49f662,49f6d2,49f736,49f7a2,49f7f6,49f844,49f892,49f8e8,4ae70c,4fe127,4ffb65,50028a,51680d,518749,518f37,519fc1,51c063,51d278,51e22b,52fcc3,5308eb,53e72e,53eb4d,53f5b2,53fb76,54d677,54d6b3,54e3fa,54e436,54f3d6,54f419,5505e7,55062a,5517d9,551cec,552bbc,552bff,5740b2,587ef7,58bc2b,58c68f,58d307,58d7ed}` / 60; in-scope `{518749,518f37,519fc1}` / 3 | pooled literal data; no outgoing calls |
| I067 | data table; inbound references are internal switch dispatch from I001, not callable entry xrefs | data table | compiler switch data; no instructions or outgoing calls |
| I068 | none | none | six CC bytes; no instruction or call |
| I069 | none | none | six CC bytes; no instruction or call |
| I070 | none | none | six CC bytes; no instruction or call |
| I071 | none | none | six CC bytes; no instruction or call |
| I072 | none | none | two CC bytes; no instruction or call |
| I073 | none | none | eight CC bytes; no instruction or call |
| I074 | none | none | eight CC bytes; no instruction or call |
| I075 | none | none | eight CC bytes; no instruction or call |
| I076 | none | none | eight CC bytes; no instruction or call |
| I077 | none | none | thirteen CC bytes; no instruction or call |
| I078 | none | none | ten CC bytes; no instruction or call |
| I079 | none | none | nine CC bytes; no instruction or call |
| I080 | none | none | fourteen CC bytes; no instruction or call |
| I081 | none | none | four CC bytes; no instruction or call |
| I082 | none | none | fifteen CC bytes; no instruction or call |
| I083 | none | none | fifteen CC bytes; no instruction or call |
| I084 | none | none | fifteen CC bytes; no instruction or call |
| I085 | none | none | eight CC bytes; no instruction or call |
| I086 | none | none | three CC bytes; no instruction or call |
| I087 | none | none | six CC bytes; no instruction or call |
| I088 | none | none | five CC bytes; no instruction or call |
| I089 | none | none | fifteen CC bytes; no instruction or call |
| I090 | none | none | ten CC bytes; no instruction or call |
| I091 | none | none | eleven CC bytes; no instruction or call |
| I092 | none | none | nine CC bytes; no instruction or call |
| I093 | none | none | four CC bytes; no instruction or call |
| I094 | external range; no UID0000OP inbound set asserted | external range | call closure belongs to MerchantDialogPane; I014 is the only separately accepted cross-owner function |
| I095 | external exact item/spell ranges; no UID0000OP inbound set asserted | external ranges | call closure belongs to ItemMenuDialogs/SpellMenuDialogs; only C028's shared-base call sites are in support scope |
| I096 | external exact argumented range; no UID0000OP inbound set asserted | external range | call closure belongs to ArgumentedMenuDialogs; `51f310` is an external constructor, not target code |
| I097 | external exact argumented-input range; no UID0000OP inbound set asserted | external range | call closure belongs to ArgumentedItemInputDialogs |
| I098 | mixed external compiler set; no UID0000OP inbound set is asserted | exact per-child xrefs remain owned by UID0001BX's external child pages | no UID0000OP outgoing-call claim; the bounded set contains no accepted target entity and its compiler call/tail routes remain external |
| I099 | `{}` / 0 | `{51a596}` / 1 | external ServerItemMenuDialog vtable data; no instructions or outgoing calls |

This closes every Section 14 item: I001-I038 have literal call sets or negative-call dispositions; I039-I067 are data/type/resource entities with exact use/no-call status; I068-I093 are individually bounded non-instruction spans; and I094-I099 are exact external/bounded exclusions rather than hidden target items. The complete external callee identities are carried item-by-item in I001-I029; they are dependencies, not a synthetic inventory child.

### Documentation Evidence And IDA Status

- Current pages preserve the complete packet behavior, retained-helper evidence, destructor policy, ownership, raw `51f310` external-constructor classification, exact TextMenu/TextInput/base layouts, accepted virtual identities, shared-method ownership, aggregate order, and vtable/creator compiler dispositions.
- Current formal/generated routes are complete for the target and the Merchant/item/spell/argumented support families; older incomplete pages and empty-marker observations are confined to historical sections.
- IDA names are raw for 21 modeled UID0000OP functions plus external MerchantDialogPane support at `517ec0`; two retained UID0000OP helpers are named/commented; five retained raw bodies deliberately lack function objects.
- Generated command 25804 is dated lead evidence only. Manual coverage remains supervisor-owned.

### Ranked Ownership Analysis

#### 1. UID0000OP TextMenuDialogs.cpp/.h

- Evidence for: contiguous factory/text islands, cross-class calls, common protocol/resources, established route, generated pair, exact children.
- Evidence against: factory and compiler artifacts are physically separated.
- Decision: selected; linker order does not imply separate authored files.

#### 2. Separate factory and class-per-file modules

- Evidence for: physical boundaries and child routing.
- Evidence against: tool-shaped fragmentation, duplicated includes, obscured private list relation.
- Decision: rejected.

#### 3. Broad MerchantMenuDialogs.cpp

- Evidence for: shared base/resources and binary adjacency.
- Evidence against: distinct protocols/vtables/layouts and accepted file owners.
- Decision: rejected.

#### Accepted file/grouping

- Reuse `NexusTK/ui/dialogs/TextMenuDialogs.cpp/.h`; contents are 28 authored bodies, local enum/parser/list layout, three dialog classes, and compiler-covered artifacts.
- Keep the common request method in `MerchantDialogPane.cpp/.h`; reject all other MerchantDialogPane, item/spell/argumented bodies, generic packet helpers, and `51f310` from UID0000OP ownership.

### Source Placement

- UID000238 position 0: include TextMenuDialogs.h and external concrete dialog headers; emit enum/helpers/factory/wrappers.
- UID0000ES position 10: CPP local reader + `[[CHILDREN]]`; H creator/factories/TextMenuDialog/size guard, inheriting the base-owned dialog id/request method.
- UID0000ET position 20: CPP-only private row/class/six methods; H blank.
- UID0000ER position 30: CPP constructor/handlers + `[[CHILDREN]]`; H complete declaration/guard.
- UID0004H8 is owned/emitted through MerchantDialogPane source/H before UID0000OP composition. UID00031Y/UID0003IP use covered-by CPP comments with H blank. UID0001BN remains non-emitting.
- Rejected: `ui/menu/`, network ownership, class-per-file artifacts, direct generated edits.

### Range / Split / Padding / Reclassification Analysis

- Factory `[517450,517d23)`; `[517771,5177a0)` switch table; raw helpers `[517cc0,517ce0)`, `[517ce0,517d00)`, `[517d00,517d23)`.
- External MerchantDialogPane support method `[517ec0,517f26)` precedes UID0000OP-owned text/list/input `[517f30,51a51c)`; all CC spans are individually inventoried.
- `[517d30,517f26)` is MerchantDialogPane source, `51a520+` is item-menu source, and `51f310` belongs to ArgumentedMenuDialogs.
- Destructor wrappers and vtables are compiler code/data. Text vtables end at successor ServerItemMenuDialog `61eea8`; creator record is `[61e8dc,61e8ec)`.
- Scalar deleting destructor ranges are exactly `[0x00520d50,0x00520d98)`, `[0x00520da0,0x00520de8)`, and `[0x00520df0,0x00520e2b)`; the exclusive successors are data/padding and are not part of the body hashes.
- No new child is required; changes are documentation/source-channel repairs.

### Negative Evidence Summary

- Zero xrefs do not establish dead source where complete bodies and inline counterparts exist.
- Resource strings are use-site literals, not owned objects.
- No UDT is safe to mutate. No source should handwrite thunks/wrappers/vtables/RTTI.
- No evidence supports 128 ids, public reader, duplicate menu type, phantom overload, list TU, PacketBuffer ownership, or forced raw functions.
- `51f310` is a complete external constructor, not padding.
- Report-only exclusion evidence for `[0x0051f140,0x0051f158)`: current IDA has no function object, no xref to the start, and no ArgumentedMenuMenuDialog vtable slot. It is therefore not modeled as a callable source method; this reverse-engineering rationale belongs only in report prose, never in formal emitted C++.

## Historical Superseded Research (Through 2026-08-15)

> The material below is retained as dated provenance. Where it conflicts with the accepted whole-file reconstruction above, the accepted section controls; old TextMenu-only ownership, provisional file folding, virtual labels, generated-completeness claims, and the former `0x0051f310` non-function conclusion are superseded.

- Confidence: strong for the text-menu classes as a source owner; B010 resolves the `TextInputMenuDialog` field/control/reply-helper route, while argumented-menu classes are now treated as the separate [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) owner bucket with only final physical file folding still provisional.
- Proposed module folder: `ui/dialogs/`
- Candidate file: `ui/dialogs/TextMenuDialogs.cpp`; adjacent but separately owned candidates are [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) and [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- Current validator-generated module pair: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` and `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.h`; the earlier class-per-file outputs `class_MerchantDialogPane.cpp`, `class_TextMenuDialog.cpp`, `class_TextInputMenuDialog.cpp`, `class_TextMenuItemList.cpp`, `class_ArgumentedMenuMenuDialog.cpp`, and `class_ArgumentedMenuMenuItemList.cpp` are superseded historical leads.
- Evidence basis: current by-* ownership/source documents, exact child reports, validator-generated output, and targeted IDA MCP checks. Old Wave3/simroot material is retained only as historical lead evidence where later passes have not superseded it.
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Hypothesis

The original client likely kept server-driven NPC/merchant menu dialogs near each other, rather than as five one-class files. `TextMenuDialog`, `TextInputMenuDialog`, and `TextMenuItemList` share the merchant/NPC packet-dialog shape, response opcode `0x39`, [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)/`DialogPane` control setup, and `DLGMERC1`/`DLGMERC2` asset family.

`ArgumentedMenuMenuDialog` and `ArgumentedMenuMenuItemList` are the item-argument variant of the same feature area. They parse item entries with quantity, argument id, price, percent metadata, item image data, and display a `DLGMERC3.EPF` dialog. Their buy/confirm action opens `ArgumentedItemConfirmInputDialogPane` at `0x005200d0`, now covered by [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), so the final split may be:

```text
ui/dialogs/MerchantDialogPane.cpp
ui/dialogs/TextMenuDialogs.cpp
ui/dialogs/ArgumentedMenuDialogs.cpp
ui/dialogs/ArgumentedItemInputDialogs.cpp
```

A compact late-1999/early-2000s project could also have kept the argumented classes in the same text-menu dialog source file.

IDA confirms the dialog/list vtable family from `0x0061ec10` through `0x0061f57c`. Current generated metadata reports `vtable_count: 0` for the checked menu-dialog classes, so do not use generated vtable absence as source-layout evidence.

B001-008 ownership split: use this file as the direct owner for `TextMenuDialog`, `TextMenuItemList`, and `TextInputMenuDialog`. Keep `ArgumentedMenuMenuDialog` and `ArgumentedMenuMenuItemList` with [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) for assignment and coverage, while preserving this page's historical note that a final source migration could physically fold the argumented code into a broader text/menu dialog source.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `MerchantDialogPane` | `0x00517d30-0x00517ebf` | `class_MerchantDialogPane.cpp` plus omitted shared virtual | Shared `DialogPane` base and action-string virtual used by text, item, spell, and argumented merchant menu dialogs. |
| `MenuDialogFactoryHelpers` | [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) | omitted/dispatcher helper code | Packet subtype dispatcher and one-variant wrappers that allocate text, item, spell, and argumented menu dialogs. |
| `MerchantDialogCreator` vtable record | [UID:0003IP][0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData](by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md) | source-declared/generated-binary helper vtable | Stack creator/functor used by map/session wrapper paths before dispatching into `MenuDialogFactoryHelpers`. |
| `TextMenuDialog` | `0x00517f30-0x00519510`, destructor island `0x00520b3f-0x00520de7` | `NexusTK/ui/dialogs/TextMenuDialogs.cpp` | Server-driven NPC/merchant text menu dialog; parses menu packets, builds simple or scrollable layouts, and sends opcode `0x39` selection replies. Its direct source children are [UID:0004H9][0x00517f30-0x00518e17.TextMenuDialogConstructor](by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md), [UID:0004HA][0x00518e20-0x00519102.TextMenuDialogOnPaint](by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md), retained source-emitting [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md), [UID:0004HC][0x00519210-0x005194b1.TextMenuDialogOnDialogAction](by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md) `OnControlCommand`, and [UID:0004HD][0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons](by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md) `UpdateActionButton`. The preceding [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md) is the inherited `MerchantDialogPane::SendMenuRequestPacket()` dependency owned by [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) and emitted through [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md), not a TextMenuDialog child. |
| `TextMenuItemList` | `0x00519520-0x005198d0`, destructor support thunks `0x00520b55-0x00520b6b` plus scalar wrapper `0x00520df0-0x00520e2b` | `class_TextMenuItemList.cpp` | Private list pane for scrollable text-menu rows; destructor support is compiler-generated no-body vtable glue. [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md) is retained wrapper `SendSelectedTextMenuReply()` at 93/94 and source-calls private [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md) `SendTextMenuReply(unsigned short itemId)` at 93/94; both emit through UID0000ET. |
| `TextInputMenuDialog` | `0x005198e0-0x0051a416`, destructor island `0x00520b29-0x00520d97` | `class_TextInputMenuDialog.cpp` | Merchant/NPC dialog with inherited `m_menuObjectId +0x270` plus source-ready fields `m_replyType`/`m_selectedOptionId`/`m_hasExtraString`/`m_extraString`, child edit control id `6`, submit/cancel/close control ids, and opcode `0x39` text-input reply handling. |
| [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) | `0x0051a420-0x0051a51c` | retained raw helper | TextInputMenuDialog-owned `SendInputReply(const wchar_t *)` serializer for opcode `0x39`; optional stored text uses `PacketBufferAppendAnsiString8`, caller wide input uses `PacketBufferAppendWideStringAsAnsi8`, and the helper remains no-direct-xref/no-IDA-function capped. |
| [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) | `0x0051e9a0-0x0051fc8c`, destructor island `0x00520abb-0x00520c16` | separate owner bucket | Adjacent argumented menu dialog/list family; related to text menus but not assigned to this file under the current split. |
| [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) | `0x0051fc90-0x00520538` | separate owner bucket | Adjacent quantity/confirm input dialog flow; documented separately. |

`TextInputMenuDialog` destructor glue in this module is non-emitting compiler output: secondary/tertiary thunks at `0x00520b29` and `0x00520b34` adjust inherited subobject views by `0xa0` and `0xa4`, then tail-jump to the primary scalar deleting wrapper at `0x00520d50`. The source file should carry the ordinary `TextInputMenuDialog::~TextInputMenuDialog()` declaration/definition if needed, not source methods named after those wrappers or raw IDA `sub_520B29`/`sub_520B34` symbols.

B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) source-quality implementation keeps the shared factory in `TextMenuDialogs.cpp` and now supplies formal first-draft C++. The source-facing dispatcher is `void CreateMerchantMenuDialog(const unsigned char *packet)` with `MerchantMenuDialogSubtype` cases, `RectBounds` initialized through `InitRectBounds`, retained wrapper helpers such as `CreateTextMenuDialog` / `CreateClientSpellMenuDialog`, and no dispatcher calls to those wrappers because live component analysis found no internal call edges. Item, spell, and argumented dialog constructors are consumer targets reached through subtypes `4`, `5`, `6`, `8`, and `10`; ownership of those concrete classes remains with their own by-file pages.

B010 source-quality reanalysis keeps `TextInputMenuDialog` and [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) in this file bucket. The constructor/action/update bodies live in [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md), the vtable stores are in the text-menu family, the cancel path uses inherited `MerchantDialogPane::SendMenuRequestPacket()`, and the raw reply helper reads `TextInputMenuDialog` fields before sending through shared packet infrastructure. Do not move the helper to PacketBuffer, TextEditControlPane, sockets/network, or a generic packet-sender source file; those are callees/support layers, while the opcode and payload shape are dialog-specific.

For final source reconstruction, model the class-level declaration on [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md), keep exact method bodies on exact by-memory pages, and keep destructor wrappers/thunks non-emitting. `TextInputMenuDialog::OnControlCommand` documents the observed inline submit path: fetch edit control id `6`, read wide text, serialize opcode `0x39`, append optional stored text, append typed input through the wide-to-ANSI writer, send, and close. [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) remains the retained raw `SendInputReply(const wchar_t *)` serializer: optional stored text is still ANSI-appended, while caller input is wide text converted through `PacketBufferAppendWideStringAsAnsi8`. Do not claim it as the direct submit-button callee without future route evidence.

`TextMenuDialog` destructor glue follows the same no-code policy. [UID:00037E][0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks](by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md) contains two `0x0b`-byte secondary/tertiary adjustor thunks (`this -= 0xa0` and `this -= 0xa4`) that tail-jump to [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md). The source file owns only the ordinary `TextMenuDialog::~TextMenuDialog()` shape: release the provisional `+0x27c` text/string/LObject-backed member and let normal base destructors run. Do not emit raw thunk/scalar-wrapper methods, explicit adjusted-this code, source-authored `operator delete`, or guarded-size helper calls.

`TextMenuItemList` destructor support is also compiler output, not handwritten source. [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) uses the current last-byte-style filename, but the actual half-open byte coverage is `0x00520b55-0x00520b6b`: `0x00520b55-0x00520b60` is the secondary vtable slot `0x0061edd0[0]` thunk, and `0x00520b60-0x00520b6b` is the tertiary vtable slot `0x0061ee00[0]` thunk. Both have no ordinary callers and forward to [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md), while primary vtable slot `0x0061ed48[0]` points directly to that scalar wrapper. Source reconstruction should carry only the ordinary `TextMenuItemList` destructor/class layout; do not emit raw thunk/scalar-wrapper methods, compiler-generated names, adjusted-this code, source-authored delete wrapper calls, or guarded-size helper calls.

B012 source-quality reanalysis keeps `TextMenuItemList` in this source bucket as a private/helper class for `TextMenuDialog`. The class is constructed only by `TextMenuDialog` at `0x0051814d` and `0x005186d4`, with object size `0x158`, row size `0x202`, `m_menuType` copied from `TextMenuDialog +0x274`, `m_menuId` copied from `TextMenuDialog +0x270`, and non-owning `m_ownerDialog` pointing back to the owner. The source-facing row payload is `unsigned short itemId` plus `wchar_t label[256]`; decompiler `label[257]` is rejected because the first two row bytes are the id and `_wcscpy_s(..., 0x100, ...)` copies into a 256-character label buffer. The standard large-list branch calls `TextMenuItemList::AddTextEntry`, while the high-resolution/EPF branch directly appends the same row shape through `ListPane::AddEntry`; both paths support the same class ownership. Accepted inherited-slot override `TextMenuItemList::OnItemActivated` at `0x00519840` loads `m_ownerDialog` and tailcalls `DialogPane::ActivateFocusedControl`, while `DrawListEntry` renders the wide label through inherited GrafPort-style helpers.

B005/B006 resolve the adjacent list serializers as retained nested source methods. UID0004HE `SendSelectedTextMenuReply()` reads inherited selection, calls `GetItem`, and delegates `entry->itemId` to private UID0004HF `SendTextMenuReply(unsigned short itemId)`. UID0004HF's exact 282-byte body `[0x00519720,0x0051983a)`, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`, emits opcode `0x39`, menu type/id, explicit item id, optional owner text, guarded non-sent terminator, and sends through `g_packetSender`. UID0004HE's retained body SHA256 is `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; both retained starts have zero direct routes. Exact nine-stage alignment with the live transitive inline region `[0x0051938f,0x00519492)`, SHA256 `23788D4E9028044606F1B0BBF9C19F80E34F4EEBF966B09B474A57ED4813734C`, inside UID0004HC body SHA256 `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860` resolves source liveness and factoring. UID0000ES supplies narrow friendship for the direct owner-string fields.

B009 UID0001BN split/container callback records UID0001BN as the reviewed non-emitting aggregate for `0x00517ec0-0x0051a417`. UID0004H8 at the aggregate's leading boundary is the external inherited `MerchantDialogPane::SendMenuRequestPacket()` child owned by UID000083/UID0000L9. The direct `TextMenuDialog` method bodies live on exact children [UID:0004H9][0x00517f30-0x00518e17.TextMenuDialogConstructor](by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md), [UID:0004HA][0x00518e20-0x00519102.TextMenuDialogOnPaint](by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md), [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md), [UID:0004HC][0x00519210-0x005194b1.TextMenuDialogOnDialogAction](by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md) `OnControlCommand`, and [UID:0004HD][0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons](by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md) `UpdateActionButton`. Session `60724697` correctly found zero direct xrefs to UID0004HB, UID0004HE, and UID0004HF; its blanket blank-C++ inference is historical. UID0004HB emits as retained TextMenuDialog helper, while UID0004HE and UID0004HF emit as the selected-row wrapper/private explicit-id helper pair through UID0000ET. The target-wide blank-C++ rationale remains valid for UID0001BN itself because it spans multiple classes and helper islands; source output belongs to exact children/support pages rather than to the aggregate.

Current `TextMenuDialog` source order is constructor, `OnPaint`, retained private `SendMenuReply(unsigned short optionIndex)` [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md), `OnControlCommand`, and `UpdateActionButton`; inherited `MerchantDialogPane::SendMenuRequestPacket()` is emitted separately before this family by UID000083/UID0000L9. Current `TextMenuItemList` source order is constructor, `AddTextEntry`, retained `SendSelectedTextMenuReply()` [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md), private retained `SendTextMenuReply(unsigned short itemId)` [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md), `OnItemActivated`, and `DrawListEntry`. UID0000ET owns both declarations, UID0000ES owns `friend class TextMenuItemList`, and UID0004HC calls the wrapper before closing. Expected generated readback is exactly one declaration and definition for each list method, a compact UID0004HE guard/GetItem/helper-call body, one UID0004HF definition after UID0004HE and before `OnItemActivated`, unchanged TextMenuDialogs.h, and no empty emitter marker for either helper.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `MerchantDialogPane`: raw constructor-shaped code at `0x00517d30-0x00517d71` and IDA-modeled [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md); the virtual is referenced from merchant/text/item/spell/argumented-menu vtables.
- `MenuDialogFactoryHelpers`: [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) maps subtype bytes to `TextMenuDialog`, `TextInputMenuDialog`, item-menu, spell-menu, and argumented-menu constructors before the concrete class islands.
- `TextMenuDialog`: `0x00517ec0`, `0x00517f30`, `0x00518e20`, `0x00519210`, `0x005194c0`, thunks `0x00520b3f`/`0x00520b4a`, and destructor `0x00520da0`.
- `TextInputMenuDialog`: `0x005198e0`, `0x0051a280`, `0x0051a3e0`, thunks `0x00520b29`/`0x00520b34`, and destructor `0x00520d50`.
- `TextInputMenuDialogReplyPacketHelper`: [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) is raw code with no IDA function object, but it serializes the text-input opcode `0x39` reply shape.
- `TextMenuItemList`: `0x00519520`, `0x00519590`, `0x00519840`, `0x00519850`, thunks `0x00520b55`/`0x00520b60`, and destructor `0x00520df0`.
- `ArgumentedMenuMenuDialog`: `0x0051e9a0`, `0x0051f160`, and `0x0051f250`.
- `ArgumentedMenuMenuItemList`: `0x0051f290`, `0x0051f5b0`, `0x0051f710`, `0x0051f720`, `0x0051f840`, thunks `0x00520abb`/`0x00520ac6`, and destructor `0x00520bb0`.
- IDA reports no function at Wave3's listed `ArgumentedMenuMenuItemList` method `0x0051f310`; this is tracked in [wave3_data_issues](../wave3_data_issues.md).

## Ownership Notes

- Keep these classes under `ui/dialogs/`, not `ui/menu/`. They are modal packet-driven dialogs, while `ui/menu/` currently covers reusable popup menu controls and right-click/menu-button panes.
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) is a shared base for text, item, spell, and argumented menu dialogs. Keep it adjacent to these modules even if final migration folds the tiny base into a broader menu-dialog source.
- The inherited `MerchantDialogPane::SendMenuRequestPacket()` helper is used by all seven text/input/item/spell/argumented merchant-dialog families. UID000083 owns the declaration and UID0004H8 body, and UID0000L9 emits them in `NexusTK/ui/dialogs/MerchantDialogPane.cpp/.h`; derived families reuse the shared base method without duplicate definitions.
- `TextInputMenuDialog` ordinary destructor ownership stays in this source bucket through [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md). The exact scalar wrapper and adjustor thunks remain [UID:00037D][0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor](by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md) and [UID:00037C][0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks](by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md), both non-reconstructable compiler output.
- `TextInputMenuDialogReplyPacketHelper` stays with [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md). It is not a PacketBuffer, TextEditControlPane, socket, or generic network helper despite using those callees.
- `TextMenuItemList` and `ArgumentedMenuMenuItemList` should migrate with their owning dialogs. Their constructors are only meaningful with owner/context fields passed by the dialog constructors.
- `ArgumentedItemConfirmInputDialogPane`, `ArgumentedItemQuantityInputDialogPane`, and their purchase helpers are documented in [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md). They should stay adjacent to this module, but their final source file may be a split `ArgumentedItemInputDialogs.cpp`.
- C001 2026-06-12 split [UID:0002SS][0x0061e8dc-0x0061e8fc.DialogCreatorVtableData](by-memory/0x0061e8dc-0x0061e8fc.DialogCreatorVtableData.md): [UID:0003IP][0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData](by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md) routes here because live IDA shows stack vtable stores in `sub_507C90` and `sub_510320`, and `sub_510320` calls the menu-dialog factory dispatcher `0x00517450`.

## Historical Placement Alternatives

The dated migration discussion considered `ui/dialogs/TextMenuDialogs.cpp`, a separate `ArgumentedMenuDialogs.cpp`, and adjacent `MerchantDialogPane.cpp`. The accepted disposition keeps TextMenuDialogs, MerchantDialogPane, item/spell menu, ArgumentedMenuDialogs, and ArgumentedItemInputDialogs as separate owner modules. The obsolete executable migration examples were removed; no migration command is authoritative source evidence.

## Cross-References

- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:00031Y][TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md)
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0003IP][0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData](by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)

## Changes

- 2026-08-22 B002 UID0000OP implementation callback:
  - Reconciled every accepted ordinary/formal caller family to sole inherited `MerchantDialogPane::m_menuObjectId +0x270`, preserving base-only field/method ownership, complete declarations, exact layouts, packet behavior, source order, raw helpers, and distinct list-local identifiers.
  - Restored the justified post-callback target evaluation to `94/94`; all report-specified support scores remain at their exact accepted dispositions without an increase beyond recommendation.
- 2026-08-21 B002 Gate 2A repair:
  - Reconciled active metadata and child/source routing to accepted `94/94`, positions `0/10/20/30`, external UID0004H8 ownership, accepted virtual identities, and current generated completeness.
  - Moved command-25804/25850 defects into explicit historical provenance, retained the full 99-row technical inventory, and made the accepted ordinary/formal/generated state authoritative for C006, C007, and C051.
- 2026-08-15 B006 accepted UID0004HF implementation callback:
  - Preserved metadata `90/86` and the owning-file route.
  - Updated TextMenuItemList inventory, packet/factoring evidence, source order, expected generated CPP/H readback, and aggregate history for the retained UID0004HE wrapper/private UID0004HF helper pair.
  - Historicalized the prior independent no-route/no-code conclusion without deleting exact zero-route evidence.
- 2026-08-14 B005 accepted UID0004HE source-quality callback:
  - Preserved score `90/86` and updated the file inventory to classify UID0004HE as retained `TextMenuItemList::SendSelectedTextMenuReply()` at 93/94 through UID0000ET; at that dated stage UID0004HF remained independently unresolved, a conclusion superseded by the 2026-08-15 callback above.
  - Added exact target/inline/handler hashes, zero-route history, vtable-routed active source liveness, packet behavior, class friendship, source order, and generated CPP/H expectations.
  - Historicalized the blanket no-route/no-emission conclusion only for UID0004HE; retained B009's exact split and negative route evidence and made no UID0004HF change.
- 2026-08-13 B006 accepted UID0004HB source-quality callback:
  - Added UID0004HB's retained private overload to the exact `TextMenuDialog` source order between `OnPaint` and `OnDialogAction`.
  - Recorded target score/emitter 93/94 and UID0000ES, the class-owned one-index declaration, the target-owned definition, the UID0004HC inline call relationship, and exact post-refresh generated expectations.
  - Preserved UID0001BN aggregate non-emission and UID0004HE/UID0004HF no-route dispositions; historicalized only the blanket B009 conclusion that UID0004HB must remain blank because its direct xrefs are zero.
- 2026-07-04 B009 accepted UID0001BN split/container callback:
  - Recorded UID0001BN as a reviewed non-emitting split/container under this source root.
  - Added exact child inventory for `TextMenuDialog` source-emitting children [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md), [UID:0004H9][0x00517f30-0x00518e17.TextMenuDialogConstructor](by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md), [UID:0004HA][0x00518e20-0x00519102.TextMenuDialogOnPaint](by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md), [UID:0004HC][0x00519210-0x005194b1.TextMenuDialogOnDialogAction](by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md), and [UID:0004HD][0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons](by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md), plus raw no-route children [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md), [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md), and [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md).
  - Preserved existing [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md), [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md), [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md), [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md), and vtable support as already-present.
- 2026-06-25 B010 accepted [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) implementation sync:
  - Score unchanged at `90/86`.
  - Updated the Proposed Contents/source-placement text from retained raw `SendInputReply(const char *)` to retained raw `SendInputReply(const wchar_t *)`.
  - Preserved the accepted source route through `TextInputMenuDialog` and this file bucket, kept PacketBuffer/TextEditControlPane/socket/network ownership rejected, and corrected only the caller-text helper to `PacketBufferAppendWideStringAsAnsi8` while leaving optional stored text on `PacketBufferAppendAnsiString8`.
- 2026-06-28 B010 accepted [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) implementation sync:
  - Score unchanged at `90/86`.
  - Recorded that `MenuDialogFactoryHelpers` now emits formal first-draft C++ through this file root, with `CreateMerchantMenuDialog`, retained wrapper helpers, `MerchantMenuDialogSubtype`, and `RectBounds`/`InitRectBounds`.
  - Preserved ownership separation: item, spell, and argumented constructors are subtype targets/consumers, while the shared packet factory remains owned by `TextMenuDialogs.cpp`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `90` and confidence to `82`.
  - Evidence: document covers dialog-family hypothesis, proposed contents, factory helpers, text/input/argumented menu classes, IDA/vtable evidence, ownership notes, migration caveats, split alternatives, and cross-references; confidence is capped by final argumented-menu split and unresolved generated method caveats.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/` so reviewed child memory pages can attach to this parent without autogen path errors.
- 2026-06-10 B001-008 ownership-gate refresh:
  - Changed confidence to `86`.
  - Summary/evidence: live IDA MCP reconfirmed text-menu vtable views and constructor stores for `TextMenuDialog`, `TextMenuItemList`, and `TextInputMenuDialog`; the new split child [TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md) is assigned here. Argumented-menu classes are now explicitly routed to [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), so the previous confidence cap from argumented split ambiguity no longer blocks this text-menu owner bucket.
- 2026-06-12 Agent-C001 Batch C001-017:
  - Score remains `90/86`.
  - Summary/evidence: linked the exact [UID:0003IP][0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData](by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md) child after live IDA proved its stack creator paths feed the `0x00517450` menu-dialog factory dispatcher. The sibling `PursuitMessageDialogCreator` record routes to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), so the old combined vtable page stays an unparented split index.
- 2026-06-21 Rule 26 incorporation:
  - Score unchanged at `90/86`.
  - Added TextInputMenuDialog destructor-glue source policy: `0x00520b29`/`0x00520b34` and `0x00520d50` are compiler output regenerated from the class destructor/inheritance layout, while the source file owns only the ordinary destructor declaration/definition and related class layout.
- 2026-06-21 B008 Rule 26 source-routing sync:
  - Score unchanged at `90/86`.
  - Added TextMenuDialog destructor-glue source policy: `0x00520b3f`/`0x00520b4a` and `0x00520da0` are compiler output regenerated from the class destructor/inheritance layout, while the source file owns only the ordinary destructor declaration/definition and class/member layout.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Score unchanged at `90/86`.
  - Integrated the `TextInputMenuDialog` source-ready class route, resolved field/control names, retained raw `SendInputReply(const char *)` helper ownership as then understood, rejected PacketBuffer/TextEditControlPane/socket/network ownership, and recorded the observed inline submit-packet path versus adjacent raw helper distinction. The 2026-06-25 [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) pass supersedes only the stale `const char *` caller-argument type/callee attribution.
- 2026-06-21 B010 Rule 26 source-routing sync:
  - Score unchanged at `90/86`.
  - Added TextMenuItemList destructor-glue source policy: [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) `0x00520b55-0x00520b6b` thunks and [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md) `0x00520df0-0x00520e2b` scalar wrapper are compiler output regenerated from the `TextMenuItemList` destructor/inheritance layout, while this source bucket owns only the ordinary class destructor/declaration shape.
- 2026-06-21 B012 Rule 26 source-quality incorporation:
  - Score remains `90/86`.
  - Integrated the `TextMenuItemList` source route and first-draft class policy: private helper class in `TextMenuDialogs.cpp`, row payload `0x202` (`unsigned short itemId` plus `wchar_t label[256]`), context mirrors `m_menuType`/`m_menuId`/`m_ownerDialog`, standard `AddTextEntry` and high-resolution direct `ListPane::AddEntry` append paths, owner-dialog selection forwarder, list-row drawing behavior, no-route raw opcode `0x39` reply serializers, and non-emitting destructor glue.
