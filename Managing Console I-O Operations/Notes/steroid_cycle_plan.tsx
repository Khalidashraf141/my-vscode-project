import React from 'react';

export default function CycleProtocol() {
  const printChart = () => {
    window.print();
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-slate-900 via-slate-800 to-slate-900 p-8">
      <style>{`
        @media print {
          .no-print { display: none; }
          body { print-color-adjust: exact; -webkit-print-color-adjust: exact; }
          .bg-gradient-to-br { background: white !important; }
        }
      `}</style>
      
      <div className="max-w-5xl mx-auto">
        <button 
          onClick={printChart}
          className="no-print mb-6 bg-blue-600 text-white px-8 py-3 rounded-lg hover:bg-blue-700 shadow-lg transition-all"
        >
          📄 Print / Save as PDF
        </button>

        <div className="bg-white rounded-2xl shadow-2xl overflow-hidden">
          {/* Header */}
          <div className="bg-gradient-to-r from-slate-800 to-slate-700 text-white p-8 text-center">
            <h1 className="text-4xl font-bold mb-2">CYCLE PROTOCOL</h1>
            <p className="text-slate-300 text-lg">Comprehensive Supplement & Training Plan</p>
          </div>

          <div className="p-8 space-y-8">
            {/* Anabolic Cycle */}
            <div className="border-l-4 border-red-600 pl-6">
              <h2 className="text-2xl font-bold text-slate-800 mb-4 flex items-center">
                <span className="bg-red-600 text-white px-3 py-1 rounded mr-3">💉</span>
                Anabolic Cycle
              </h2>
              <div className="bg-red-50 rounded-lg p-6 space-y-3">
                <div className="flex justify-between items-center border-b border-red-200 pb-3">
                  <span className="font-semibold text-slate-700">Testosterone Propionate</span>
                  <span className="text-slate-600">100mg Monday + 100mg Thursday</span>
                </div>
                <div className="flex justify-between items-center border-b border-red-200 pb-3">
                  <span className="font-semibold text-slate-700">Anavar</span>
                  <span className="text-slate-600">20mg (morning) + 10mg (evening)</span>
                </div>
                <div className="flex justify-between items-center border-b border-red-200 pb-3">
                  <span className="font-semibold text-slate-700">Masteron</span>
                  <span className="text-slate-600">100mg Monday + 100mg Thursday</span>
                </div>
                <div className="flex justify-between items-center border-b border-red-200 pb-3">
                  <span className="font-semibold text-slate-700">Stanozolol (Stana)</span>
                  <span className="text-slate-600">50mg daily</span>
                </div>
                <div className="flex justify-between items-center">
                  <span className="font-semibold text-slate-700">T3 (Thyroid)</span>
                  <span className="text-slate-600">50mcg (empty stomach)</span>
                </div>
              </div>
            </div>

            {/* Support & Protection */}
            <div className="border-l-4 border-green-600 pl-6">
              <h2 className="text-2xl font-bold text-slate-800 mb-4 flex items-center">
                <span className="bg-green-600 text-white px-3 py-1 rounded mr-3">🛡️</span>
                Organ Support & Protection
              </h2>
              <div className="bg-green-50 rounded-lg p-6 space-y-3">
                <div className="flex justify-between items-center border-b border-green-200 pb-3">
                  <span className="font-semibold text-slate-700">TUDCA (Liver Support)</span>
                  <span className="text-slate-600">1 capsule morning + 1 capsule evening</span>
                </div>
                <div className="flex justify-between items-center border-b border-green-200 pb-3">
                  <span className="font-semibold text-slate-700">Cystone (Kidney Support)</span>
                  <span className="text-slate-600">1 tablet daily (any time)</span>
                </div>
                <div className="flex justify-between items-center">
                  <span className="font-semibold text-slate-700">Abana (Heart Support)</span>
                  <span className="text-slate-600">1 tablet daily (any time)</span>
                </div>
              </div>
            </div>

            {/* Vitamins & Minerals */}
            <div className="border-l-4 border-blue-600 pl-6">
              <h2 className="text-2xl font-bold text-slate-800 mb-4 flex items-center">
                <span className="bg-blue-600 text-white px-3 py-1 rounded mr-3">💊</span>
                Vitamins & Minerals
              </h2>
              <div className="bg-blue-50 rounded-lg p-6 space-y-3">
                <div className="flex justify-between items-center border-b border-blue-200 pb-3">
                  <span className="font-semibold text-slate-700">Vitamin C</span>
                  <span className="text-slate-600">1000mg post-workout + 1000mg dinner</span>
                </div>
                <div className="flex justify-between items-center border-b border-blue-200 pb-3">
                  <span className="font-semibold text-slate-700">Vitamin E</span>
                  <span className="text-slate-600">800 IU post-workout</span>
                </div>
                <div className="flex justify-between items-center border-b border-blue-200 pb-3">
                  <span className="font-semibold text-slate-700">Zinc</span>
                  <span className="text-slate-600">25mg post-workout</span>
                </div>
                <div className="flex justify-between items-center border-b border-blue-200 pb-3">
                  <span className="font-semibold text-slate-700">Selenium</span>
                  <span className="text-slate-600">200mcg daily</span>
                </div>
                <div className="flex justify-between items-center border-b border-blue-200 pb-3">
                  <span className="font-semibold text-slate-700">Omega-3</span>
                  <span className="text-slate-600">1 capsule (breakfast, lunch, dinner)</span>
                </div>
                <div className="flex justify-between items-center">
                  <span className="font-semibold text-slate-700">B Complex</span>
                  <span className="text-slate-600">1 tablet pre-workout (breakfast)</span>
                </div>
              </div>
            </div>

            {/* Diet Plan */}
            <div className="border-l-4 border-orange-600 pl-6">
              <h2 className="text-2xl font-bold text-slate-800 mb-4 flex items-center">
                <span className="bg-orange-600 text-white px-3 py-1 rounded mr-3">🍽️</span>
                Nutrition Protocol
              </h2>
              <div className="bg-orange-50 rounded-lg p-6 space-y-4">
                <div className="bg-white rounded-lg p-4 shadow-sm">
                  <div className="font-bold text-orange-700 mb-2">Pre-Workout</div>
                  <div className="text-slate-600">1 cup oats</div>
                </div>
                <div className="bg-white rounded-lg p-4 shadow-sm">
                  <div className="font-bold text-orange-700 mb-2">Post-Workout</div>
                  <div className="text-slate-600">1 scoop protein + 1 banana</div>
                </div>
                <div className="bg-white rounded-lg p-4 shadow-sm">
                  <div className="font-bold text-orange-700 mb-2">Lunch</div>
                  <div className="text-slate-600">2 roti + vegetable + mixed salad + 1 whole egg + 2 egg whites</div>
                </div>
                <div className="bg-white rounded-lg p-4 shadow-sm">
                  <div className="font-bold text-orange-700 mb-2">Snack</div>
                  <div className="text-slate-600">1 apple</div>
                </div>
                <div className="bg-white rounded-lg p-4 shadow-sm">
                  <div className="font-bold text-orange-700 mb-2">Dinner</div>
                  <div className="text-slate-600">100g rice + dal + 100g chicken</div>
                </div>
                <div className="bg-white rounded-lg p-4 shadow-sm">
                  <div className="font-bold text-orange-700 mb-2">Throughout Day</div>
                  <div className="text-slate-600">Green tea</div>
                </div>
              </div>
            </div>

            {/* Training Split */}
            <div className="border-l-4 border-purple-600 pl-6">
              <h2 className="text-2xl font-bold text-slate-800 mb-4 flex items-center">
                <span className="bg-purple-600 text-white px-3 py-1 rounded mr-3">🏋️</span>
                Training Split
              </h2>
              <div className="bg-purple-50 rounded-lg p-6">
                <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                  <div className="bg-white rounded-lg p-4 shadow-sm">
                    <div className="font-bold text-purple-700">Monday</div>
                    <div className="text-slate-600">Back & Triceps</div>
                  </div>
                  <div className="bg-white rounded-lg p-4 shadow-sm">
                    <div className="font-bold text-purple-700">Tuesday</div>
                    <div className="text-slate-600">Chest & Biceps</div>
                  </div>
                  <div className="bg-white rounded-lg p-4 shadow-sm">
                    <div className="font-bold text-purple-700">Wednesday</div>
                    <div className="text-slate-600">Quads & Shoulder</div>
                  </div>
                  <div className="bg-white rounded-lg p-4 shadow-sm">
                    <div className="font-bold text-purple-700">Thursday</div>
                    <div className="text-slate-600">Chest & Abs</div>
                  </div>
                  <div className="bg-white rounded-lg p-4 shadow-sm">
                    <div className="font-bold text-purple-700">Friday</div>
                    <div className="text-slate-600">Back & Biceps</div>
                  </div>
                  <div className="bg-white rounded-lg p-4 shadow-sm">
                    <div className="font-bold text-purple-700">Saturday</div>
                    <div className="text-slate-600">Hamstring & Abs</div>
                  </div>
                </div>
                <div className="mt-4 bg-white rounded-lg p-4 shadow-sm">
                  <div className="font-bold text-purple-700">Sunday</div>
                  <div className="text-slate-600">Walk early morning in sun (active recovery)</div>
                </div>
                <div className="mt-4 p-4 bg-purple-700 text-white rounded-lg text-center font-semibold">
                  Daily: 10 min cardio post-workout
                </div>
              </div>
            </div>

            {/* Blood Work Reminder */}
            <div className="border-l-4 border-yellow-600 pl-6">
              <h2 className="text-2xl font-bold text-slate-800 mb-4 flex items-center">
                <span className="bg-yellow-600 text-white px-3 py-1 rounded mr-3">🩺</span>
                Mandatory Blood Work
              </h2>
              <div className="bg-yellow-50 rounded-lg p-6 space-y-4">
                <div className="bg-white rounded-lg p-6 shadow-sm border-2 border-red-500">
                  <div className="flex items-center mb-3">
                    <span className="text-2xl mr-3">⚠️</span>
                    <div className="font-bold text-red-700 text-xl">MANDATORY - After 21 Days</div>
                  </div>
                  <div className="space-y-2 ml-10">
                    <div className="flex items-center text-slate-700">
                      <span className="mr-2">✓</span>
                      <span className="font-semibold">Estrogen Levels</span>
                    </div>
                    <div className="flex items-center text-slate-700">
                      <span className="mr-2">✓</span>
                      <span className="font-semibold">LFT (Liver Function Test)</span>
                    </div>
                    <div className="flex items-center text-slate-700">
                      <span className="mr-2">✓</span>
                      <span className="font-semibold">KFT (Kidney Function Test)</span>
                    </div>
                    <div className="flex items-center text-slate-700">
                      <span className="mr-2">✓</span>
                      <span className="font-semibold">Lipid Profile</span>
                    </div>
                  </div>
                  <div className="text-sm text-slate-600 mt-4 ml-10 italic">
                    Essential for monitoring organ health and hormonal balance
                  </div>
                </div>
              </div>
            </div>
          </div>

          {/* Footer */}
          <div className="bg-gradient-to-r from-slate-800 to-slate-700 p-6 text-center text-white">
            <p className="font-bold text-lg mb-2">⚠️ MANDATORY BLOOD WORK - AFTER 21 DAYS</p>
            <p className="text-slate-300">Estrogen • LFT • KFT • Lipid Profile</p>
            <p className="text-sm text-slate-400 mt-3">Stay consistent • Track progress • Prioritize recovery • Monitor health markers</p>
          </div>
        </div>
      </div>
    </div>
  );
}