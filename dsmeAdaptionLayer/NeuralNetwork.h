/*
 * openDSME
 *
 * Implementation of the Deterministic & Synchronous Multi-channel Extension (DSME)
 * introduced in the IEEE 802.15.4e-2012 standard
 *
 * Authors: Florian Meier <florian.meier@tuhh.de>
 *          Maximilian Koestler <maximilian.koestler@tuhh.de>
 *          Sandrina Backhauss <sandrina.backhauss@tuhh.de>
 *
 * Based on
 *          DSME Implementation for the INET Framework
 *          Tobias Luebkert <tobias.luebkert@tuhh.de>
 *
 * Copyright (c) 2015, Institute of Telematics, Hamburg University of Technology
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include "./quicknet/Math.h"
#include "./quicknet/Network.h"

namespace dsme {

template<typename T>
class NeuralNetwork {
public:
    NeuralNetwork();
    ~NeuralNetwork() = default;

    quicknet::Vector<T>& feedForward(quicknet::Vector<T>& input) {
        return this->network.feedForward(input);
    }

private:
    quicknet::Network<T> network;
};

/***IMPLEMENTATION***/

typedef quicknet::Layer<float> layer_t;
typedef quicknet::Vector<float> vector_t;
typedef quicknet::Matrix<float> matrix_t;

/******** Layer 0 ********/
static const float l0_weights_array[560] {
    0.27923527,-0.00551843,0.65213555,-0.14468746,0.11129745,0.94589096,0.16722395,0.65351033,-0.24575587,-0.66507721,0.98196459,-0.80147594,-0.41458577,-0.40232736,1.19651890,-0.52964097,0.37024394,-0.54954553,0.10932662,-0.98619694,3.53992224,0.63186824,3.38577104,-1.26424146,1.48978639,0.04507395,0.59550488,0.27895650,
    0.75646710,0.05634737,-1.60701418,-0.54432869,0.35476270,0.01073925,0.69214475,0.59904462,0.75446719,0.39990291,0.54945403,-0.13269646,0.65981662,0.03338003,0.26029602,-0.31487891,-4.90297699,0.45535457,-1.15270519,0.33937418,0.69145036,0.14394213,0.85191137,0.04545935,0.53396511,-0.83981276,0.27305573,0.58868575,
    0.12832941,0.00211794,1.98060465,0.09490481,-1.36423826,-0.47218925,-0.32143074,0.24090528,0.87294543,0.25545645,-0.92312682,0.40086114,-0.02762298,-0.20742708,-0.00576367,0.04340570,1.05442595,0.05956635,-2.92281628,-1.05576396,-1.54400098,-0.23506247,-0.18868358,0.28871912,-1.61824989,0.61281615,0.47058511,0.45496249,
    -1.14029741,-0.05919704,0.84935027,0.33738226,1.04707587,0.13858834,0.63837379,0.24947530,1.40132308,-0.12078837,2.36104012,-0.31500760,-0.03101236,-0.60775805,1.24231374,-1.37482190,1.47643578,-0.11585756,3.73486543,-0.28972247,4.25562429,0.12327653,1.14986598,1.94102609,-0.05164322,-0.37838382,-1.03796303,-0.39365372,
    -0.48352394,-0.31913912,1.17050600,0.88719010,0.57097876,0.03421571,1.71586514,-0.27497244,-0.58199662,-0.27391687,-0.18396051,0.37104177,-0.32767257,-0.02741728,-1.14978206,-0.62218302,-0.95173413,0.05799104,-0.23990427,1.84318793,2.53542924,0.80059451,3.27132654,0.76719564,1.14944577,1.13996899,-0.21576175,-0.11638131,
    -0.10067645,0.00267538,-1.19258976,-0.21743275,1.47609448,0.10112475,-2.42409873,0.27919334,1.48631251,-0.22882800,0.28264770,0.10648397,0.72369182,0.33261454,-0.11104037,0.92746127,-0.64352739,-0.24701028,-1.65077841,-0.56076008,-0.68116391,0.46009067,1.34672785,0.24246056,1.37845516,1.35728538,-0.31544310,0.82226706,
    0.54934454,-0.03354745,-0.53633547,-0.64562023,1.67128134,-0.58381182,-0.73176789,-0.66841817,-1.11594951,-0.15746991,-0.55643618,-0.61788547,0.25344643,0.28938034,-0.15560974,-1.37428880,0.12233084,-0.80628085,-0.27315378,0.31555700,1.81497371,-0.21578485,0.21142234,0.10422514,0.41008040,-2.20311809,-0.75685942,-0.14358591,
    0.47912192,0.00939231,0.01360262,-0.74686354,0.26500532,-0.62891346,-1.00143337,-0.09048594,-1.45752597,0.49517184,0.76136428,0.28151819,-0.23382701,-0.35262355,0.59400284,0.65256613,0.46852911,0.80285966,0.55057192,-0.33850053,-0.87930179,-0.91884339,-1.21260870,1.04225802,1.64972496,1.59521484,0.36344802,0.59681755,
    1.58622837,1.36300397,0.69184709,-0.17075412,1.22145319,0.02966010,-0.55837792,-1.42621863,0.10229088,0.05706933,1.00366282,-0.44670099,-0.04676341,-0.47819388,2.33005214,0.99345601,2.25424051,-2.06159043,0.17699462,-1.30910146,1.68589807,-2.10500073,0.25935370,3.52455783,0.68661886,-2.56386375,1.20453858,0.98910701,
    -0.78726304,-0.07721378,-0.00715551,-0.48349708,-1.68044627,-0.46548697,2.11151528,-0.23522238,-0.31529254,-0.51461232,-1.07316422,-0.16715197,0.21105573,-0.20931619,-0.87299567,-0.48367685,0.65345913,-1.77636337,-0.82701629,0.48343232,4.01587152,1.06952333,0.87353176,0.01173456,-0.67830676,-0.14435434,-1.14161515,0.24335988,
    2.29826689,0.04465362,0.67407537,-0.13354109,0.65576065,-0.53346175,1.87134314,-0.08497401,3.34558630,-0.34752151,2.19018793,0.45118010,1.02022314,-2.48475599,0.01355402,0.03153365,1.24447453,-0.82176012,0.82963413,-0.55787766,1.27407277,-0.65459919,1.37844038,-0.26691058,1.04522073,-0.12846535,0.18958779,0.07110562,
    0.15512945,-0.00100083,1.70094049,0.47111353,-0.72998178,0.07992364,3.88052726,-0.60705072,-0.08954518,-0.72402298,-0.24481085,0.17826860,-0.16205861,0.19928400,0.11786475,-1.02435565,2.25509048,-0.45858976,1.82674348,-2.95925188,-0.83620131,-0.98455989,-0.52666312,1.70336437,0.16545358,-0.81988484,-0.33721015,0.51271266,
    0.79692483,-0.23043443,-0.24099398,-1.61527562,-0.37807050,-0.54424381,-0.26852763,-0.24868372,1.20813179,0.63710850,0.12671384,0.01781430,0.02293472,-0.52003801,-0.88623089,0.10053004,-0.68503582,0.47660708,-0.97308755,0.18476278,-0.91115648,0.10687070,-0.99882108,0.27113980,-0.47140804,-0.77382910,-1.29256082,-2.27206373,
    0.02283512,0.00925080,-0.80336756,1.17173374,0.05617549,1.37555957,1.99181771,-0.54634982,-0.30207771,-0.19832821,0.27111727,-0.41732481,3.26753736,-0.48752168,-0.03132210,-0.47662887,1.45817578,0.45294145,-0.42984024,0.18170960,0.67706078,0.91485143,0.82154131,-0.35242477,0.30294204,2.09382391,-1.51502049,-0.07020527,
    -0.72579998,-0.02179353,-0.06010121,-0.31607202,0.60628748,-0.70758188,0.76532692,-0.25037518,-1.64781833,-0.61072600,1.06567216,0.14544655,-0.53389114,-0.09010390,-1.62842822,0.91431117,-2.15600061,0.52502269,-0.27338937,-1.22600770,-0.46055955,0.22754754,-0.50618488,-1.09444869,0.35818231,0.25970134,-1.24492025,0.33181790,
    1.23223543,-0.13183461,0.18234405,-0.57210940,0.27115041,-0.54123008,0.55400229,-0.44087949,-0.75350845,0.07688162,-0.00984312,-0.41218096,0.53949201,0.37847906,-2.12007260,0.49119377,-0.68738675,-0.59353518,-0.19221951,0.96577901,-0.30588654,0.11173727,-0.17576925,-2.13700986,-0.72088963,0.21902955,-0.21019782,-0.79396588,
    -0.96099687,-0.17961402,-0.81291384,0.12202872,-1.02529132,0.14964457,-1.36968708,-0.80507809,-0.58355194,-0.21188751,-0.20845069,-0.47575924,0.33771047,-0.66061980,-1.01657963,0.39045641,0.37662354,0.26047546,0.14938191,-0.24436526,0.26965094,0.30399051,1.47273314,-0.30512089,2.45737839,-1.10924482,0.42404801,0.13025299,
    1.65820622,-0.02594075,-0.88815457,-0.47719508,-1.47908199,1.12944353,-2.52549052,-0.13151202,-3.55474377,0.69002736,-0.46909168,0.22943817,0.49396688,-0.10046453,0.97034454,-0.37632579,-0.50050586,-0.43259537,-1.06754661,-0.23999842,-0.98782325,-0.18265925,-0.01281887,-0.22142857,0.19902602,0.93732673,-2.67540312,0.66286725,
    1.00440419,0.01671374,0.12098565,-0.00903339,-0.45997283,0.35646698,-0.07441798,-0.23719695,1.16922176,1.00163925,0.84513909,0.22030084,0.82026672,-0.23469208,-0.56358117,1.55905783,-0.99278432,0.21161602,-0.97179919,-0.11531270,-1.08442914,0.48407027,-0.50101095,0.73658437,-0.82190812,-1.18416190,-0.66348326,-1.67480218,
    -0.09925631,0.13714723,0.04652894,0.22513856,0.39288953,0.16549817,-0.33155623,0.25588727,-0.87894160,0.41225228,-0.70794845,-1.34785986,-0.26990050,-0.08497897,0.85164869,-0.80520988,0.80506808,-0.43445840,0.60837173,0.08476696,1.04422319,-0.08645260,0.24322633,0.24977370,0.39359489,0.60781741,-1.26476681,-0.75217080,
};
static float l0_bias_array[20] {
    0.56771421,-0.62156773,-0.50269133,-0.59069139,1.10580885,-0.03582549,-0.19854677,0.58063614,0.34246612,-0.11184772,-0.41024637,-0.60240775,-1.54411077,0.68638074,0.05402479,-1.61450684,0.96887141,0.36780092,-1.28613949,-0.07788524
};
static float l0_output_array[20];

static matrix_t l0_weights{20,28,l0_weights_array};
static vector_t l0_bias{20,l0_bias_array};
static vector_t l0_output{20,l0_output_array};

/******** Layer 1 ********/
static const float l1_weights_array[400] {
    1.12516367,-1.21677935,-0.87255770,1.21213007,-0.48239326,0.14912395,-0.28814232,0.68827164,0.09484948,0.76738214,1.31952846,0.55015314,-0.98159754,-0.68779165,-0.50063270,-0.47928771,0.25858343,0.44695380,-0.60609454,1.87966824,
    -1.83766794,-0.32834053,1.16437125,-1.39727151,-0.54751784,0.29422420,-0.35375157,0.04510302,-0.28414994,-0.04447657,-0.97516155,1.00335085,-0.28558490,0.30158010,1.81973493,-0.29712483,-0.74341851,0.15720552,0.31955102,-0.95700878,
    -0.36799496,0.41231734,0.35461238,-0.83246344,0.14323202,0.88169175,0.00580356,0.65810323,-1.10315144,0.69002831,0.35849935,0.31081256,1.16851735,-0.52164638,0.12575264,2.06433630,-0.40728629,-0.42687890,2.04288507,-0.52883607,
    0.28248069,-0.91071886,0.49153605,0.20730823,0.80698305,-0.12057061,0.12060203,-0.45520070,1.77934706,0.78238803,0.83989733,0.36787587,-1.55522537,1.60826027,-0.08903537,-1.38969469,-0.22914463,-0.13892139,-0.94345117,-1.15219772,
    0.99475247,-1.09868240,-0.82032460,-0.48975101,0.61778104,-1.39853776,-0.09533525,0.61674362,0.15046321,0.73206037,-1.03635001,-0.73586565,-1.25554895,1.07386780,0.50111395,1.03017271,0.11652116,0.60579777,-1.08225822,-0.20098308,
    0.57375133,0.57774067,1.44320869,1.06016743,-0.08036782,-0.59547842,0.58238667,-0.77672869,0.75567472,-1.19777429,0.58107412,0.43092522,-1.50383675,-0.10940135,0.71708322,-0.63319665,0.26328883,-0.69220239,-1.33073151,0.38148028,
    0.01524941,0.30997458,0.04652190,-0.32813543,-0.52926278,-0.03806794,0.83158886,0.52521253,0.22429174,-0.01582285,-0.98798907,-0.54323930,2.38771915,0.32781810,-0.04629142,1.62609935,-1.08919251,0.87501144,1.34921610,-0.72287554,
    0.26967612,-0.00050019,0.35217756,0.84561086,0.00858715,-0.09689192,-0.36843213,-0.73135430,0.76059246,-0.08339857,0.91425812,0.22088180,-2.07860756,0.45369726,0.04405194,-0.93548256,1.71943033,0.30358720,-1.75597167,0.25728011,
    -1.12053430,1.74140954,1.87020600,-1.09277987,-0.04528205,-0.63092244,0.38180512,-0.15177828,-0.36860055,-1.43070662,-0.28783497,-0.53026211,0.34404168,-0.88657862,0.30127826,-0.25459850,-0.41077521,-0.68849623,-0.62279367,-0.49667376,
    -0.82746571,2.07386017,0.49261674,-0.05955999,0.45270848,-0.38325521,0.16095237,-0.55745751,0.02766195,-0.55361885,-1.35001028,-0.16474280,2.15007257,-0.97885031,0.62219930,0.42086938,-0.60305709,0.25073034,1.53444231,-0.15170380,
    -0.26713479,-1.75938225,0.08057096,-0.39712071,0.77688497,-0.02867543,0.24341352,-0.57388371,1.22821772,0.91902304,0.61234546,0.04957611,-1.34736907,0.35688150,-0.75184917,0.24493566,1.28216434,-1.47300446,0.26610538,-0.09986503,
    -0.33820024,0.54827148,-0.20237978,0.09750664,-0.10861187,-0.14228788,0.38176346,0.48077509,-0.14069574,0.59338856,-1.12289584,-0.56780916,-0.60432369,-1.54970551,0.71453750,0.37651119,0.18653105,1.13256860,0.78357309,0.16017300,
    1.09905565,-0.41572502,-1.77114189,1.06772184,-1.60191417,0.26763201,0.22540693,-0.25181338,0.79982138,0.41802430,0.85629153,1.74692392,-0.76094848,-0.28651416,0.37872493,-0.77377075,1.25244915,0.73527223,-1.57835460,-1.30002809,
    -0.44794333,0.98180109,-0.23664370,0.63131452,-0.13566931,0.51239622,0.66986549,-1.13006663,0.95777506,-1.61761153,0.44308290,-0.24448192,1.39139080,-0.52645570,0.12815416,-0.16539165,0.54972923,0.86880618,1.66349030,0.40531147,
    -1.00141668,-0.32690665,0.25111079,-0.64662170,-0.69594306,-1.41108203,1.21317458,-0.43836561,-0.58538014,-0.44860807,1.00700510,1.18396199,-1.78729391,1.00264788,0.55733454,-0.22570689,-0.39059687,-0.18164496,-0.34512505,0.08825799,
    0.13913102,0.98242134,-1.08354807,-1.46929359,-0.08865426,0.40548795,-0.35081398,-0.17966826,-0.79060531,0.31685320,-0.50396854,-0.86749387,-0.47383401,0.15022400,0.22993974,-0.98176366,-0.02446875,-0.06273508,0.23627421,-1.13300920,
    -0.73633796,0.32879636,-0.11516622,0.48256788,1.40714657,-0.27648300,1.03609109,2.07060790,-0.51375544,1.11937165,0.13203977,0.04390279,0.00292697,0.66486835,-0.08057799,-0.66839778,1.63696635,-0.70723140,-1.19556093,-0.18803062,
    -1.48850393,1.92554533,1.38606393,0.38633841,-0.46837708,0.56490016,0.35493618,-0.02971557,0.40916237,-0.93026429,0.31037122,-0.70233756,0.14989595,-0.56901187,1.80316901,1.27143037,0.79670167,1.30557966,0.92812181,1.17941868,
    0.32102251,-0.56326139,-0.83119202,0.60559893,0.87421489,-0.84421659,-0.18421334,0.58637023,-1.54800701,1.54605711,-0.30424696,0.17945468,-1.62065792,1.64319074,-1.89151585,-0.39511940,0.83720201,0.45691660,-1.46696734,-0.14218417,
    0.50369722,0.42680147,-0.25283948,-1.03857923,0.27870741,0.98032963,-0.13108103,0.60903120,0.31359577,-0.56842637,-1.02168655,-0.79348481,1.24728024,-0.25183740,-0.58704090,0.54970741,-0.37846324,0.30014572,1.95748341,-0.56329882,
};
static float l1_bias_array[20] {
    -0.04823275,-0.33603066,-0.24502242,0.89220423,0.75165230,0.02723828,-0.36843476,0.09272261,-0.69751734,-0.03940856,0.01176414,-0.33833221,-0.23250847,-0.35598403,-0.67503601,-0.26339936,1.01649702,-0.70385659,0.52510625,1.24187267
};
static float l1_output_array[20];

static matrix_t l1_weights{20,20,l1_weights_array};
static vector_t l1_bias{20,l1_bias_array};
static vector_t l1_output{20,l1_output_array};

/******** Layer 2 ********/
static const float l2_weights_array[80] {
    0.55957878,0.76922965,-1.04183400,1.43124807,0.46579531,-0.50137055,0.95046186,-1.42249203,0.62529266,0.30431485,0.52217925,-1.64084935,0.52097297,0.03287458,0.06092045,0.17464247,-1.41741168,-0.39451873,-1.47484696,-0.01153634,
    2.06491184,-0.56514955,3.54788280,-0.16258964,1.06454504,-3.93329763,2.61347485,-3.81252170,0.32570717,-1.13119578,1.52421892,-1.38444233,2.74283504,-1.91701603,-1.73823154,-1.28078604,0.78803837,0.10407548,2.96060133,2.60031700,
    -1.86454570,-0.51454324,2.04190969,1.94737291,2.91824889,1.12020361,3.38569856,-1.58423519,-1.55041409,2.86285996,-1.16255689,-1.80138373,0.43363705,0.38030067,-0.74561542,-1.21945798,1.82296348,-1.76274502,-0.49084774,2.29645038,
    0.50871819,-1.83595955,2.83301926,1.36467600,0.78554547,1.57468033,4.53343582,-4.86695719,-1.23204136,-0.70990950,0.74913669,-1.84008956,-2.72074676,-0.85518718,0.03364783,-1.26742387,2.00483704,-1.88600540,0.18675032,3.30967951,
};
static float l2_bias_array[4] {
    0.68612492,0.99590439,2.05772805,1.67812669
};
static float l2_output_array[4];

static matrix_t l2_weights{4,20,l2_weights_array};
static vector_t l2_bias{4,l2_bias_array};
static vector_t l2_output{4,l2_output_array};

/******** Network ********/
static layer_t layers[3] {
    {l0_weights, l0_bias, l0_output, quicknet::quick_tanh},
    {l1_weights, l1_bias, l1_output, quicknet::quick_tanh},
    {l2_weights, l2_bias, l2_output, quicknet::quick_linear},
};

template<typename T>
NeuralNetwork<T>::NeuralNetwork() : network{3, layers} {
}


} /* namespace dsme */
#endif /* NEURALNETWORK_H_ */
