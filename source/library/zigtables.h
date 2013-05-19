/* OneJoker RNG library <http://lcrocker.github.io/onejoker/randlib>
 *
 * To the extent possibile under law, Lee Daniel Crocker has waived all
 * copyright and related or neighboring rights to this work.
 * <http://creativecommons.org/publicdomain/zero/1.0/>
 *
 * Lookup tables for ziggurat.c
 */

/* x values for exponential
 */
static double zex[] = {
    8.6971174701310497137, 7.697117470131049714, 6.9410336293772123601,
    6.4783784938325698538, 6.1441646657724730491, 5.8821443157953997963,
    5.6664101674540337371, 5.4828906275260628694, 5.323090505754398613,
    5.1814872813015010391, 5.0542884899813047117, 4.9387770859012514838,
    4.832939741025112588, 4.7352429966017412526, 4.6444918854200854872,
    4.5597370617073515513, 4.4802117465284221949, 4.4052876934735729804,
    4.3344436803172730116, 4.2672424802773661873, 4.2033137137351843802,
    4.142340865664051125, 4.0840513104082974638, 4.0282085446479365105,
    3.9746060666737884793, 3.9230625001354895925, 3.8734176703995089982,
    3.8255294185223367372, 3.7792709924116678991, 3.734528894039797535,
    3.6912010902374189453, 3.6491955157608538478, 3.6084288131289096339,
    3.568825265648337405, 3.5303158891293438632, 3.4928376547740601813,
    3.4563328211327607624, 3.4207483572511205323, 3.3860354424603017886,
    3.3521490309001100106, 3.3190474709707487166, 3.2866921715990692095,
    3.2550473085704501812, 3.2240795652862645207, 3.1937579032122407483,
    3.1640533580259734579, 3.1349388580844407393, 3.106389062339824666,
    3.0783802152540905188, 3.0508900166154554479, 3.0238975044556767712,
    2.9973829495161306948, 2.9713277599210896472, 2.9457143948950456386,
    2.9205262865127406647, 2.8957477686001416838, 2.8713640120155362592,
    2.8473609656351888266, 2.8237253024500354905, 2.8004443702507381944,
    2.7775061464397572041, 2.754899196562345365, 2.7326126361947007411,
    2.7106360958679293685, 2.6889596887418041593, 2.6675739807732670816,
    2.6464699631518093905, 2.6256390267977886122, 2.6050729387408355373,
    2.584763820214140691, 2.5647041263169053686, 2.5448866271118700928,
    2.5253043900378279427, 2.5059507635285939648, 2.4868193617402096807,
    2.4679040502973649846, 2.4491989329782498907, 2.4306983392644199087,
    2.4123968126888708336, 2.3942890999214583287, 2.3763701405361408194,
    2.3586350574093374601, 2.3410791477030346875, 2.3236978743901964559,
    2.3064868582835798692, 2.2894418705322694265, 2.2725588255531546951,
    2.2558337743672190441, 2.239262898312908711, 2.2228425031110364012,
    2.2065690132576635755, 2.1904389667232199234, 2.1744490099377744673,
    2.158595893043885678, 2.1428764653998416425, 2.1272876713173679736,
    2.1118265460190418108, 2.0964902118017147636, 2.0812758743932248695,
    2.0661808194905755036, 2.0512024094685848641, 2.0363380802487695916,
    2.0215853383189260769, 2.0069417578945183144, 1.9924049782135764991,
    1.9779727009573602295, 1.96364268778954804, 1.9494127580071845658,
    1.9352807862970511134, 1.9212447005915276767, 1.9073024800183871196,
    1.8934521529393077331, 1.8796917950722108461, 1.8660195276928275961,
    1.852433515911175166, 1.838931967018879398, 1.8255131289035192212,
    1.8121752885263901412, 1.7989167704602903934, 1.7857359354841254046,
    1.7726311792313049959, 1.7596009308890742368, 1.7466436519460739351,
    1.7337578349855711926, 1.7209420025219350428, 1.7081947058780575683,
    1.6955145241015377061, 1.6829000629175537544, 1.6703499537164519163,
    1.6578628525741725324, 1.6454374393037234056, 1.6330724165359912047,
    1.6207665088282577216, 1.6085184617988580768, 1.5963270412864831348,
    1.5841910325326886694, 1.572109239386229481, 1.5600804835278879161,
    1.5481036037145133069, 1.5361774550410318943, 1.524300908219226005,
    1.5124728488721167573, 1.5006921768428164935, 1.4889578055167456003,
    1.4772686611561334578, 1.465623682245745041, 1.4540218188487932263,
    1.4424620319720121876, 1.4309432929388794104, 1.4194645827699828254,
    1.4080248915695353509, 1.396623217917041711, 1.3852585682631217188,
    1.3739299563284902176, 1.3626364025050864741, 1.3513769332583349176,
    1.3401505805295045843, 1.328956381137116322, 1.317793376176324548,
    1.3066606104151739482, 1.2955571316866007209, 1.284481990275012545,
    1.2734342382962410994, 1.2624129290696153433, 1.2514171164808525098,
    1.2404458543344064543, 1.2294981956938491599, 1.218573192208790307,
    1.2076698934267612829, 1.1967873460884031665, 1.1859245934042023556,
    1.1750806743109117686, 1.1642546227056790396, 1.1534454666557748055,
    1.1426522275816728928, 1.1318739194110786732, 1.1211095477013306083,
    1.1103581087274114281, 1.0996185885325976575, 1.0888899619385472597,
    1.0781711915113727023, 1.0674612264799681529, 1.0567590016025518414,
    1.0460634359770445502, 1.0353734317905289495, 1.0246878730026178051,
    1.0140056239570971073, 1.0033255279156973716, 0.99264640550727647003,
    0.98196705308506317908, 0.9712862409839039789, 0.96060271166866709911,
    0.94991517776407659934, 0.93922231995526297945, 0.92852278474721113992,
    0.91781518207004493908, 0.90709808271569100593, 0.89637001558989068999,
    0.88562946476175228046, 0.87487486629102585345, 0.86410460481100519505,
    0.8533170098423740638, 0.84251035181036928327, 0.83168283773427388386,
    0.82083260655441252283, 0.80995772405741906613, 0.79905617735548788102,
    0.7881258688694932497, 0.77716460975913043929, 0.76617011273543541321,
    0.755139984181982898, 0.74407171550050873964, 0.73296267358436604908,
    0.72181009030875689904, 0.71061105090965570406, 0.69936248110323266166,
    0.68806113277374858606, 0.67670356802952337904, 0.66528614139267855397,
    0.65380497984766565345, 0.64225596042453703441, 0.63063468493349100105,
    0.6189364513948767817, 0.60715622162030085129, 0.59528858429150359375,
    0.58332771274877027777, 0.57126731653258903906, 0.55910058551154127643,
    0.54682012516331112541, 0.53441788123716615377, 0.52188505159213564096,
    0.5092119824436549531, 0.49638804551867159745, 0.48340149165346224772,
    0.47023927508216945328, 0.45688684093142071269, 0.44332786607355296295,
    0.42954394022541129579, 0.4155141696003570009, 0.40121467889627836218,
    0.38661797794112021557, 0.37169214532991786107, 0.35639976025839443709,
    0.34069648106484979662, 0.32452911701691008535, 0.30783295467493287294,
    0.29052795549123115154, 0.2725131854784654791, 0.25365836338591284418,
    0.23379048305967553604, 0.21267151063096745247, 0.18995868962243277755,
    0.16512762256418831776, 0.13730498094001380396, 0.10483850756582017887,
    0.063852163815003479795, 0.0
};

/* Pre-computed ratios for exponential
 */
static double zer[] = {
    0.88501937527757322315, 0.90177052075821256646, 0.93334492234895648175,
    0.94841088269568240232, 0.95735460160488214522, 0.96332389401564794965,
    0.96761273284061825033, 0.97085476756194793382, 0.97339830605926748321,
    0.97545129720201760965, 0.97714586250685494754, 0.97857013122169995758,
    0.97978523431731244291, 0.98083496216629568475, 0.98175154014612558145,
    0.98255923223144103083, 0.98327667144016004362, 0.98391841394121540198,
    0.98449600340983371029, 0.98501871716040225915, 0.98549410007825681792,
    0.98592835376274391442, 0.98632662483499058958, 0.98669322171877949232,
    0.98703177983587341272, 0.98734538903362716596, 0.98763669297965664296,
    0.98790796748635727645, 0.98816118281496425088, 0.98839805366842159428,
    0.98862007962999835132, 0.98882857811923941418, 0.98902471143770977078,
    0.98920950910943585719, 0.98938388644747406264, 0.9895486600725905216,
    0.98970456095429549497, 0.98985224542540928153, 0.98999230452957993051,
    0.99012527198992911348, 0.9902516310312921525, 0.99037182024466170117,
    0.99048623864770000644, 0.99059525006749282065, 0.9906991869495208639,
    0.99079835367893510725, 0.99089302948572942344, 0.99098347099360533731,
    0.99106991446267269463, 0.99115257776820051634, 0.99123166215108905076,
    0.99130735377031248132, 0.99137982508307187569, 0.99144923607463227479,
    0.99151573535666209942, 0.99157946115023927449, 0.99164054216744931542,
    0.99169909840360521477, 0.991755241850509557, 0.9918090771398086322,
    0.99186070212431763087, 0.99191020840419332457, 0.99195768180396955199,
    0.99200320280572942268, 0.99204684694304818612, 0.99208868515978697177,
    0.99212878413733734344, 0.99216720659349913184, 0.99220401155581030378,
    0.99223925461183009323, 0.99227298813859882086, 0.99230526151325430379,
    0.99233612130657086089, 0.99236561146099868828, 0.99239377345461543011,
    0.99242064645225520033, 0.99244626744495063174, 0.99247067137870859805,
    0.99249389127353822523, 0.99251595833355908504, 0.99253690204893666613,
    0.99255675029032014778, 0.99257552939639311939, 0.99259326425509028774,
    0.99260997837898160645, 0.99262569397527895577, 0.99264043201087889486,
    0.99265421227281757159, 0.99266705342448014474, 0.99267897305787664018,
    0.99268998774226866742, 0.99270011306940654903, 0.99270936369561388199,
    0.99271775338093610965, 0.99272529502555111647, 0.99273200070362296916,
    0.99273788169476454566, 0.992742948513260762, 0.99274721093519129078,
    0.99275067802357993929, 0.99275335815168711331, 0.99275525902455193323,
    0.99275638769888150738, 0.99275675060137652215, 0.99275635354557461009,
    0.99275520174728584083, 0.99275329983868808803, 0.99275065188114390651,
    0.99274726137679485925, 0.99274313127898392202, 0.99273826400155162383,
    0.99273266142704691927, 0.9927263249138894008, 0.9927192553025153154,
    0.99271145292053592274, 0.99270291758693299593, 0.99269364861531269634,
    0.99268364481623562971, 0.99267290449863759008, 0.99266142547035230134,
    0.9926492050377443556, 0.99263624000445750366, 0.99262252666928046027,
    0.99260806082312942702, 0.99259283774514359437, 0.99257685219788694341,
    0.99256009842164671356, 0.992542570127815917, 0.99252426049134424949,
    0.9925051621422386532, 0.99248526715609161447, 0.99246456704361201005,
    0.99244305273912993222, 0.99242071458804340781, 0.99239754233317125807,
    0.99237352509997250653, 0.992348651380588707, 0.99232290901666131184,
    0.99229628518087170557, 0.99226876635714676457, 0.99224033831946774117,
    0.99221098610921487815, 0.99218069401097440438, 0.99214944552672840653,
    0.9921172233483414757, 0.9920840093282509478, 0.99204978444825994377,
    0.99201452878632421911, 0.99197822148121499262, 0.99194084069493037888,
    0.99190236357271772854, 0.99186276620055800678, 0.99182202355995122925,
    0.9917801094798288321, 0.9917369965854045742, 0.99169265624376004031,
    0.99164705850594390561, 0.99160017204534569257, 0.99155196409208464281,
    0.99150240036313236283, 0.99145144498786388765, 0.99139906042870552096,
    0.99134520739651900987, 0.99128984476033002267, 0.99123292945097421252,
    0.99117441635819602465, 0.9911142582206934526, 0.99105240550855573627,
    0.9909888062974900312, 0.99092340613417681374, 0.99085614789203159694,
    0.99078697161658171392, 0.99071581435959068158, 0.99064261000097808515,
    0.99056728905748899635, 0.9904897784769624896, 0.99041000141693252331,
    0.99032787700616479146, 0.99024332008758839488, 0.99015624094091935125,
    0.99006654498309178836, 0.98997413244440954112, 0.98987889801810280251,
    0.98978073048071800815, 0.98967951228048027815, 0.98957511909044188767,
    0.98946741932286204573, 0.98935627360084652832, 0.98924153418280321643,
    0.9891230443347329172, 0.98900063764476415994, 0.9888741372736444407,
    0.98874335513410511499, 0.98860809099110689831, 0.98846813147392895831,
    0.98832324898986467644, 0.98817320052790500562, 0.98801772633919467079,
    0.98785654847919995905, 0.98768936919438494126, 0.98751586913370220133,
    0.98733570536230022905, 0.9871485091514549879, 0.98695388351475390803,
    0.9867514004558826368, 0.98654059788784931841, 0.98632097617695795107,
    0.98609199425710273312, 0.98585306525074193479, 0.98560355152190424106,
    0.9853427590733868607, 0.98506993118442882803, 0.98478424116596510889,
    0.98448478408730644783, 0.98417056729975742898, 0.98384049954802209734,
    0.98349337841764148377, 0.98312787581408658547, 0.98274252110380838571,
    0.98233568146602446885, 0.98190553890171098684, 0.98145006321710966932,
    0.9809669801349925135, 0.98045373347714954605, 0.9799074400914829864,
    0.97932483584681762848, 0.97870221056073021791, 0.9780353291224077055,
    0.97731933527054995139, 0.9765486334102121063, 0.97571674239409914511,
    0.97481611319623189948, 0.97383789963829646353, 0.97277166744713224923,
    0.97160502140444236452, 0.97032312239453845673, 0.96890805450552309192,
    0.96733798498544314752, 0.96558603352123481254, 0.96361872652487953493,
    0.96139384751146912149, 0.95885738974131470549, 0.95593914209661768602,
    0.95254613726150479984, 0.94855265223826670268, 0.94378444893278060796,
    0.937992989410241444, 0.93081134015791474587, 0.92167464907904278639,
    0.9096670995657363037, 0.89320233377216899655, 0.86928175221886724143,
    0.83150825287659360571, 0.76354482443446336729, 0.60905258284905982519,
    0.0
};

/* x values for normal
 */
static double znx[] = {
    3.7130862467403632611, 3.4426198558966521215, 3.2230849845786185446,
    3.0832288582142137009, 2.9786962526450169606, 2.894344007018670621,
    2.8231253505459664379, 2.7611693723841538514, 2.7061135731187223371,
    2.6564064112581924999, 2.6109722484286132035, 2.5690336259216391328,
    2.530009672385466617, 2.4934545220919507609, 2.4590181774083500943,
    2.426420645530211593, 2.3954342780074673425, 2.3658713701139875435,
    2.3375752413355307354, 2.3104136836950021558, 2.2842740596736568056,
    2.2590595738653295251, 2.2346863955870569803, 2.2110814088747278106,
    2.1881804320720206093, 2.1659267937448407377, 2.1442701823562613517,
    2.1231657086697899595, 2.1025731351849988838, 2.0824562379877246441,
    2.0627822745039633575, 2.0435215366506694976, 2.0246469733729338782,
    2.0061338699589668403, 1.9879595741230607243, 1.9701032608497132242,
    1.9525457295488889058, 1.9352692282919002011, 1.9182573008597320303,
    1.901494653100317614, 1.884967035702869238, 1.8686611409895420085,
    1.8525645117230870617, 1.8366654602533840447, 1.820952996591005074,
    1.8054167642140487419, 1.7900469825946189862, 1.7748343955807692457,
    1.7597702248942318749, 1.7448461281083765085, 1.730054160558243535,
    1.7153867407081165482, 1.7008366185643009437, 1.6863968467734863258,
    1.6720607540918522072, 1.6578219209482075462, 1.6436741568569826489,
    1.6296114794646783962, 1.6156280950371329644, 1.6017183802152770587,
    1.5878768648844007018, 1.5740982160167497219, 1.560377222359840687,
    1.5467087798535034608, 1.5330878776675560787, 1.5195095847593707806,
    1.5059690368565502602, 1.492461423774615408, 1.4789819769830978546,
    1.4655259573357946276, 1.4520886428822164926, 1.4386653166774613138,
    1.4252512545068615734, 1.4118417124397602509, 1.3984319141236063517,
    1.3850170377251486449, 1.3715922024197322698, 1.3581524543224228739,
    1.3446927517457130432, 1.3312079496576765017, 1.317692783201342991,
    1.304141850120421539, 1.2905495919178731508, 1.2769102735516997175,
    1.263217961446028231, 1.2494664995643337479, 1.2356494832544811749,
    1.2217602305309625678, 1.2077917504067576028, 1.1937367078237721994,
    1.1795873846544607035, 1.1653356361550469083, 1.1509728421389760651,
    1.1364898520030755352, 1.1218769225722540661, 1.107123647523535398,
    1.0922188768965537614, 1.0771506248819376573, 1.0619059636836193998,
    1.0464709007525802629, 1.0308302360564555907, 1.0149673952392994716,
    0.99886423348064351302, 0.9825008035027603848, 0.96585507938813059488,
    0.94890262549791195379, 0.93161619660135381054, 0.91396525100880177642,
    0.89591535256623852892, 0.8774274290977156914, 0.85845684317805086352,
    0.8389522142812074557, 0.81885390668331772329, 0.79809206062627480451,
    0.77658398787614838596, 0.75423066443451007144, 0.73091191062188128148,
    0.70647961131360803454, 0.68074791864590421661, 0.65347863871504238699,
    0.62435859730908822108, 0.59296294244197797909, 0.55869217837551797136,
    0.52065603872514491755, 0.47743783725378787676, 0.42654798630330512484,
    0.36287143102841830415, 0.27232086470466385052, 0.0
};

/* Pre-computed ratios for normal
 */
static double znr[] = {
    0.92715860260958181763, 0.93623028957379485899, 0.956607992952848114,
    0.96609638454482378182, 0.9716814879827228456, 0.97539385218204825123,
    0.97805411716846690107, 0.98006069464044027742, 0.98163153152391764393,
    0.98289638112714098915, 0.98393754566628795104, 0.98480987047330970686,
    0.98555137923285125088, 0.98618930308193093947, 0.98674367998674404194,
    0.9872295978111523053, 0.98765864371028774187, 0.98803987015697581976,
    0.98838045631206706231, 0.98868617156926601572, 0.98896170724281238292,
    0.98921091831298225181, 0.98943700254364859626, 0.98964263517806788673,
    0.98983007159692604951, 0.99000122651830924918, 0.99015773578342611405,
    0.9903010050507584845, 0.99043224853365007142, 0.99055252008427691251,
    0.99066273833581128486, 0.99076370718917353983, 0.99085613262092532711,
    0.99094063656067087373, 0.99101776841653111997, 0.99108801469967026672,
    0.99115180710211574778, 0.99120952930813498646, 0.99126152276240436174,
    0.99130809157390966144, 0.9913495066998627571, 0.99138600952662233809,
    0.99141781494296510896, 0.99144511398378924208, 0.99146807610847637624,
    0.9914868511669544202, 0.9915015710974247416, 0.99151235139230665771,
    0.9915192923628695019, 0.99152248022800196768, 0.99152198804840063999,
    0.99151787652397891773, 0.99151019466937193336, 0.99149898037993680154,
    0.99148426089853522655, 0.9914660531915677985, 0.99144436424114937456,
    0.99141919125892576301, 0.9913905218257941904, 0.99135833396067041176,
    0.99132259612041511686, 0.99128326713206628011, 0.99124029605759963584,
    0.99119362199053561586, 0.99114317378280797019, 0.99108886969938738575,
    0.99103061699719294571, 0.99096831142380457471, 0.99090183663038849498,
    0.99083106349204072443, 0.99075584932741328021, 0.99067603700798253193,
    0.99059145394561253121, 0.99050191094511520062, 0.99040720090626308752,
    0.9903070973571081206, 0.99020135279742820565, 0.99008969682757387834,
    0.98997183403381163366, 0.98984744159632687741, 0.98971616658019529107,
    0.98957762286265615242, 0.98943138764167584182, 0.98927699746076394118,
    0.98911394367290903761, 0.98894166725184683589, 0.98875955284103969076,
    0.98856692190894572783, 0.98836302485237875218, 0.98814703185670963013,
    0.98791802228065655914, 0.98767497228226882633, 0.98741674033855982336,
    0.98714205023030691868, 0.98684947096077868659, 0.98653739294583644163,
    0.98620399964388891583, 0.98584723357516580721, 0.98546475539369152058,
    0.98505389429856431938, 0.98461158757057708462, 0.98413430634896473056,
    0.9836179638539432928, 0.9830578010162583822, 0.98244824275194781359,
    0.98178271570543127158, 0.98105341485372970808, 0.98025100142194637854,
    0.97936420732654433113, 0.97837931059532429175, 0.97727942988416717567,
    0.976043560937365852, 0.97464523782864197461, 0.97305063687358484504,
    0.97121583268440595237, 0.96908272904799993076, 0.96657285378276907485,
    0.96357758630874139076, 0.95994217656206138767, 0.95543841882389008324,
    0.94971534787472807344, 0.94220420600767401835, 0.9319193267373656742,
    0.9169927970543101827, 0.89341051969571562459, 0.85071654932252244876,
    0.75046102122968457378, 0.0
};
